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

void run(const unsigned int length, const HyperparameterSet& hyperParameters) {
    // initialise file writing for fitness plot:
    
    std::ofstream myFile;
    myFile.open("Fitness.txt");

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
}

double timedRun(const unsigned int length, const HyperparameterSet& hyperParameters) {

    clock_t start = clock();
    run(length, hyperParameters);
    clock_t end = clock();
    double elapsedTime = double(end - start) / CLOCKS_PER_SEC;
    if(GLOBAL_LOGLEVEL > 0) std::cout << "Elapsed time: " << elapsedTime << std::endl;
    return elapsedTime;
}

void randomSearch(const unsigned int length, const unsigned int iterations) {
    std::pair<unsigned int, unsigned int> populationSizeRange(
        std::pair<unsigned int, unsigned int>(10, 50));
    std::pair<unsigned int, unsigned int> tournamentSizeRange(
        std::pair<unsigned int, unsigned int>(4, 20));
    std::pair<double,double> uniformRateRange(std::pair<
    double,double>(0.3, 0.7));    
    std::pair<double,double> mutationRateRange(std::pair<
    double, double>(0.0005,0.005));





    HyperparameterSet bestParameters(length, populationSizeRange,
        tournamentSizeRange, uniformRateRange, mutationRateRange);
    double minimumTime = timedRun(length, bestParameters);    

    for(unsigned int i = 1; i < iterations; ++i) {
        HyperparameterSet testParameters(length, populationSizeRange,
        tournamentSizeRange, uniformRateRange, mutationRateRange);
        double elapsedTime = timedRun(length, testParameters);   
        if(elapsedTime < minimumTime) {
            //bestParameters = testParameters;
            minimumTime = elapsedTime;
        }     
    }
    std::cout <<"Fastest operation: " << minimumTime << std::endl;
}
