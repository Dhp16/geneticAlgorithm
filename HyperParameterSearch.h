#include "HyperparameterSet.h"

#include <utility>

const int GLOBAL_LOGLEVEL = 1;

inline double rand01()
{
    return ((double)rand() / (RAND_MAX));
}

void run(const unsigned int length, const unsigned int populationSize, 
const double uniformRate, const double mutationRate, const int tournamentSize,
const bool elitism) {
    // initialise file writing for fitness plot:
    std::ofstream myFile;
    myFile.open("Fitness.txt");

    FitnessCalculation::generateASolution(length);
    if(GLOBAL_LOGLEVEL > 2) {
        std::cout << "Generated Solution: " << std::endl;
        FitnessCalculation::printSolution();
    }

    Population newPopulation(populationSize, length);
    if(GLOBAL_LOGLEVEL > 1) {
        std::cout << "First population: size: " << populationSize << "  length: " << length << std::endl;
        if(GLOBAL_LOGLEVEL > 2) newPopulation.print();
        std::cout << "First population max fitness: " << newPopulation.getFittestIndividual().getFitness() << "\n" << std::endl;
    }
    myFile << newPopulation.getFittestIndividual().getFitness() << std::endl;

    int generationCount = 0;

    Algorithm algo(length, uniformRate, mutationRate, tournamentSize, elitism);
    
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


    std::cout << "\n\n\n" << std::endl;
}

double timedRun(const unsigned int length, const unsigned int populationSize, const double 
uniformRate, const double mutationRate, const unsigned int tournamentSize, const bool elitism) {

    clock_t start = clock();
    run(length, populationSize, uniformRate, mutationRate, tournamentSize, elitism);
    clock_t end = clock();
    double elapsedTime = double(end - start) / CLOCKS_PER_SEC;
    if(GLOBAL_LOGLEVEL > 0) std::cout << "Elapsed time: " << elapsedTime << std::endl;
    return elapsedTime;
}

void randomSearch(const unsigned int length) {
    std::pair<unsigned int, unsigned int> populationSizeRange(
        std::pair<unsigned int, unsigned int>(10, 50));
    std::pair<unsigned int, unsigned int> tournamentSizeRange(
        std::pair<unsigned int, unsigned int>(4, 20));
    std::pair<double,double> uniformRateRange(std::pair<
    double,double>(0.3, 0.7));    
    std::pair<double,double> mutationRateRange(std::pair<
    double, double>(0.0005,0.005));

    for(unsigned int i = 0; i < 10; ++i) {
        HyperparameterSet set1(length, populationSizeRange,
        tournamentSizeRange, uniformRateRange, mutationRateRange);
        set1.print();
    }
}
