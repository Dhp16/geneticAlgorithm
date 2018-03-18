#include "Algorithm.h"

#include <ctime>
#include <iostream>


#include "Individual.h"
#include "Population.h"

inline double rand01(){
    return ((double) rand() / (RAND_MAX));
}


Algorithm::Algorithm(unsigned int length): _length(length)
{}

Population Algorithm::evolvePopulation(Population population) {

    if(elitism) {
        // would write function to save the fittest individual
    }

    Population newPopulation;
    for(unsigned int i = 0; i < population.size(); ++i) {
        Individual individual1 = tournamentSelection(population);
        Individual individual2 = tournamentSelection(population);
        Individual newIndividual = crossover(individual1, individual2);
        newPopulation.addIndividual(newIndividual);
    }

    return newPopulation;
}

// selects best from a random subset of the population
Individual Algorithm::tournamentSelection(Population population) {

    Population tournament(_tournamentSize, _length);
    for(unsigned int i = 0; i < _tournamentSize; ++i) {
        int randomIndex = (rand() % static_cast<int>(population.size() + 1));
        tournament.addIndividual(population.getIndividual(randomIndex));
    }

    return tournament.getFittestIndividual();
}

Individual Algorithm::crossover(Individual individual1, Individual individual2) {
    Individual newIndividual;
    for(unsigned int i = 0; i < _length; ++i) {
        if(rand01() <= _uniformRate) {
            newIndividual.setGene(i, individual1[i]);
        }
        else {
            newIndividual.setGene(i, individual2[i]);
        }
    }
    return newIndividual; 
}

void Algorithm::mutate(Individual& individual) {
    for(unsigned int i = 0; i < individual.size(); ++i) {
        // get random double 
        if(rand01() < _mutationRate) {
            individual.setGene(i, rand() % 2);
        }
    }
}