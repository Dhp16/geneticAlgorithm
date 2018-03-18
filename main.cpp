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
    std::cout <<"First population: size: " << populationSize <<"  length: " << length << std::endl;
    newPopulation.print();
    std::cout <<"First population max fitness: " << newPopulation.getFittestIndividual().getFitness()<< "\n" << std::endl;

    int generationCount = 0;

    // initialise algorithm
    Algorithm algo(length);
    
    while(newPopulation.getFittestIndividual().getFitness() < FitnessCalculation::getMaxFitness()) {
       generationCount++;
       std::cout <<"\n======== Population " << generationCount << "========" << std::endl;
       newPopulation = algo.evolvePopulation(newPopulation);
       newPopulation.print();
       std::cout << "max fitness: " << newPopulation.getFittestIndividual().getFitness() << std::endl;
    }
    std::cout <<"\n\n======= SUCCESS =======" << std::endl;
    std::cout <<"Generations required: " << generationCount << std::endl;
    std::cout <<"Solution found:   ";
    newPopulation.getFittestIndividual().print();
    std::cout <<"Initial solution: "; 
    FitnessCalculation::printSolution();
    
}

int main()
{
    //tester();
    realRun();

    return 0;
}