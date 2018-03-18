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
    FitnessCalculation::printSolution();

    Population newPopulation(populationSize, length);
    std::cout <<"First population: size: " << populationSize <<"  length: " << length << std::endl;
    newPopulation.print();
    std::cout <<"First population max fitness: " << newPopulation.getFittestIndividual().getFitness()<< "\n" << std::endl;
    myFile << newPopulation.getFittestIndividual().getFitness() << std::endl;

    int generationCount = 0;

    // initialise algorithm
    Algorithm algo(length);
    
    while(newPopulation.getFittestIndividual().getFitness() < FitnessCalculation::getMaxFitness()) {
       generationCount++;
       std::cout <<"\n======== Population " << generationCount << " ========" << std::endl;
       newPopulation = algo.evolvePopulation(newPopulation);
       newPopulation.print();
       std::cout << "max fitness: " << newPopulation.getFittestIndividual().getFitness() << std::endl;
       myFile << newPopulation.getFittestIndividual().getFitness() << std::endl;
    }
    myFile.close();

    std::cout <<"\n\n======= SUCCESS =======" << std::endl;
    std::cout <<"Generations required: " << generationCount << std::endl;
    std::cout <<"Solution found:   ";
    newPopulation.getFittestIndividual().print();
    std::cout <<"Initial solution: "; 
    FitnessCalculation::printSolution();

    std::cout << "\n\n\n" << std::endl;
}

int main()
{
    //tester();
    realRun();

    return 0;
}