//    A large part of this code is a replica from that shared here:
//    http://www.theprojectspot.com/tutorial-post/creating-a-genetic-algorithm-for-beginners/3
//    except that this is c++ and the one above is Java.    
//    I was looking for a starting point to learn about GAs
//    All credit to: Lee from theprojectspot.com whom I thank for very clear introductory code 
//    for genetic algorithms


#include <iostream>
#include <ctime>
#include <fstream>

#include "Individual.h"
#include "Population.h"
#include "FitnessCalculation.h"
#include "Algorithm.h"

const int GLOBAL_LOGLEVEL = 1;

inline double rand01()
{
    return ((double)rand() / (RAND_MAX));
}

bool tester(){
    int length = 150;
    int populationSize = 30;

    FitnessCalculation::generateASolution(15);
    Population population(populationSize, length);

    return true;
}

void realRun() {
    int length = 150;
    int populationSize = 30;

    // initialise file writing for fitness plot:
    std::ofstream myFile;
    myFile.open("Fitness.txt");

    FitnessCalculation::generateASolution(length);
    if(GLOBAL_LOGLEVEL > 1) {
        std::cout << "Generated Solution: " << std::endl;
        FitnessCalculation::printSolution();
    }

    Population newPopulation(populationSize, length);
    if(GLOBAL_LOGLEVEL > 0) {
        std::cout << "First population: size: " << populationSize << "  length: " << length << std::endl;
        if(GLOBAL_LOGLEVEL > 1) newPopulation.print();
        std::cout << "First population max fitness: " << newPopulation.getFittestIndividual().getFitness() << "\n" << std::endl;
    }
    myFile << newPopulation.getFittestIndividual().getFitness() << std::endl;

    int generationCount = 0;

    Algorithm algo(length);
    
    while(newPopulation.getFittestIndividual().getFitness() < FitnessCalculation::getMaxFitness()) {
       generationCount++;
       if(GLOBAL_LOGLEVEL > 0) std::cout <<"\n======== Population " << generationCount << " ========" << std::endl;
       newPopulation = algo.evolvePopulation(newPopulation);
       if(GLOBAL_LOGLEVEL > 1) newPopulation.print();
       if(GLOBAL_LOGLEVEL > 0) std::cout << "max fitness: " << newPopulation.getFittestIndividual().getFitness() << std::endl;
       myFile << newPopulation.getFittestIndividual().getFitness() << std::endl;
    }
    myFile.close();

    if(GLOBAL_LOGLEVEL > 0)std::cout <<"\n\n======= SUCCESS =======" << std::endl;
    if(GLOBAL_LOGLEVEL > 0)std::cout <<"Generations required: " << generationCount << std::endl;
    if(GLOBAL_LOGLEVEL > 1){
        std::cout << "Solution found:   ";
        newPopulation.getFittestIndividual().print();
        std::cout << "Initial solution: ";
        FitnessCalculation::printSolution();
    }

    std::cout << "\n\n\n" << std::endl;
}

int main()
{
    //tester();
    realRun();

    return 0;
}