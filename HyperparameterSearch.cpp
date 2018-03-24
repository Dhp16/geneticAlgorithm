#include "HyperparameterSearch.h"

#include <iostream>
#include <fstream>

#include "HyperparameterSet.h"
#include "FitnessCalculation.h"
#include "Algorithm.h"
#include "Population.h"

const int GLOBAL_LOGLEVEL = 1;

inline double rand01()
{
    return ((double)rand() / (RAND_MAX));
}

unsigned int run(const unsigned int length, const HyperparameterSet& hyperParameters) {
    // initialise file writing for fitness plot:
    
    std::ofstream myFile;
    myFile.open("results/Fitness.txt");

    FitnessCalculation::generateASolution(length);
    if(GLOBAL_LOGLEVEL > 2) {
        std::cout << "Generated Solution: " << std::endl;
        FitnessCalculation::printSolution();
    }

    Population newPopulation(hyperParameters.getPopulationSize(), length);
    if(GLOBAL_LOGLEVEL > 1) {
        std::cout << "First population: size: " << hyperParameters.getPopulationSize() << "  length: " << length << std::endl;
        if(GLOBAL_LOGLEVEL > 2) newPopulation.print();
        std::cout << "First population max fitness: " << newPopulation.getFittestIndividual().getFitness() << "\n" << std::endl;
    }
    myFile << newPopulation.getFittestIndividual().getFitness() << std::endl;

    int generationCount = 0;

    Algorithm algo(length, hyperParameters);

    while(newPopulation.getFittestIndividual().getFitness() < FitnessCalculation::getMaxFitness()) {
       generationCount++;
       algo.evolvePopulation(newPopulation);

       if(GLOBAL_LOGLEVEL > 1) std::cout <<"\n======== Population " << generationCount << " ========" << std::endl;
       if(GLOBAL_LOGLEVEL > 2) newPopulation.print();
       if(GLOBAL_LOGLEVEL > 1) std::cout << "max fitness: " << newPopulation.getFittestIndividual().getFitness() << std::endl;
       myFile << newPopulation.getFittestIndividual().getFitness() << std::endl;

    }
    myFile.close();

    if(GLOBAL_LOGLEVEL > 1)std::cout <<"\n\n======= SUCCESS =======" << std::endl;
    if(GLOBAL_LOGLEVEL > 1)std::cout <<"Generations required: " << generationCount << std::endl;
    if(GLOBAL_LOGLEVEL > 2){
        std::cout << "Solution found:   ";
        newPopulation.getFittestIndividual().print();
        std::cout << "Initial solution: ";
        FitnessCalculation::printSolution();
    }
    if(GLOBAL_LOGLEVEL > 1)std::cout << "\n\n\n" << std::endl;

    return generationCount;
}

double timedRun(const unsigned int length, const HyperparameterSet& hyperParameters, unsigned int& generationsRequired) {

    clock_t start = clock();
    generationsRequired = run(length, hyperParameters);
    clock_t end = clock();
    double elapsedTime = double(end - start) / CLOCKS_PER_SEC;
    if(GLOBAL_LOGLEVEL > 0) std::cout << "Elapsed time: " << elapsedTime << std::endl;
    return elapsedTime;
}

void randomSearch(const unsigned int length, const unsigned int iterations) {
    std::pair<unsigned int, unsigned int> populationSizeRange(
        std::pair<unsigned int, unsigned int>(5, 100));
    std::pair<unsigned int, unsigned int> tournamentSizeRange(
        std::pair<unsigned int, unsigned int>(2, 40));
    std::pair<double,double> uniformRateRange(std::pair<
    double,double>(0.2, 0.8));    
    std::pair<double,double> mutationRateRange(std::pair<
    double, double>(0.0005,0.005));
    std::pair<double,double> elitismRange(std::pair<
    double, double>(1,30));

    std::ofstream parametersFile;
    parametersFile.open("results/hyperparametersTested.txt");
    parametersFile << length << std::endl;
    
    unsigned int generationsRequired;
    HyperparameterSet bestParameters(length, populationSizeRange,
        tournamentSizeRange, uniformRateRange, mutationRateRange, elitismRange);
    double minimumTime = timedRun(length, bestParameters, generationsRequired);
    bestParameters.writeToFile(parametersFile);
    parametersFile << generationsRequired << " " << minimumTime << std::endl;

    for(unsigned int i = 1; i < iterations; ++i) {
        std::cout << "i: " << i << " ";
        HyperparameterSet testParameters(length, populationSizeRange,
        tournamentSizeRange, uniformRateRange, mutationRateRange, elitismRange);
        double elapsedTime = timedRun(length, testParameters, generationsRequired);   
        if(elapsedTime < minimumTime) {
            //bestParameters = testParameters;
            minimumTime = elapsedTime;
        }
        testParameters.writeToFile(parametersFile);
        parametersFile << generationsRequired << " " << elapsedTime << std::endl;
    }
    parametersFile.close();

    std::cout <<"Fastest operation: " << minimumTime << std::endl;
}
