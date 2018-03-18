#include "Algorithm.h"

#include <ctime>
#include <iostream>


#include "Individual.h"
#include "Population.h"

Algorithm::Algorithm(unsigned int length): _length(length)
{}

Population Algorithm::evolvePopulation(Population population) {

    if(elitism) {
        // would write function to save the fittest individual
    }

    Population newPopulation;
    for(unsigned int i = 0; i < population.size(); ++i) {

    }


    return newPopulation;
}

// check the way tournament works
Individual Algorithm::tournamentSelection(Population population) {

    Individual newIndividual;

    Population tournament(_tournamentSize, _length);
    for(unsigned int i = 0; i < _tournamentSize; ++i) {

    }

    return newIndividual;
}

Individual Algorithm::crossover(Individual individual1, Individual individual2) {
    
    Individual newIndividual;

    return newIndividual; 
}

void Algorithm::mutate(Individual& individual) {
    for(unsigned int i = 0; i < individual.size(); ++i) {
        // get random double 
        if(((double) rand() / (RAND_MAX)) < _mutationRate) {
            individual.setGene(i, rand() % 2);
        }
    }
}