//    This is a close replica of the code which can be found:
//    http://www.theprojectspot.com/tutorial-post/creating-a-genetic-algorithm-for-beginners/3
//    except that this is c++ and the one above is Java.    
//    I was looking for a starting point to learn about GAs, please visit the above page for information
//    All credit to: Lee from theprojectspot.com


#include <iostream>
#include <ctime>

#include "Individual.h"
#include "Population.h"
#include "FitnessCalculation.h"
#include "Algorithm.h"


inline double rand01()
{
    return ((double)rand() / (RAND_MAX));
}


bool tester(){

    int length = 15;
    int populationSize = 20;

    FitnessCalculation::generateASolution(15);
    Population population(populationSize, length);

    return true;
}

void realRun() {
    int length = 5;
    int populationSize = 10;

    FitnessCalculation::generateASolution(length);
    FitnessCalculation::printSolution();

    Population newPopulation(populationSize, length);
    std::cout <<"First population: " << std::endl;
    newPopulation.print();
    std::cout <<"First population max fitness: " << newPopulation.getFittestIndividual().getFitness() << std::endl;

    int generationCount = 0;
    Algorithm algo(length);
    // std::cout << "maxFitness: "<< FitnessCalculation::getMaxFitness() << std::endl;
    // newPopulation = algo.evolvePopulation(newPopulation);
    
    while(newPopulation.getFittestIndividual().getFitness() < FitnessCalculation::getMaxFitness()) {
       generationCount++;
       newPopulation = algo.evolvePopulation(newPopulation);
       newPopulation.print();
       std::cout << newPopulation.getFittestIndividual().getFitness() << std::endl;
    }
    // not getting any better 
}

int main()
{
    //tester();
    realRun();

    return 0;
}