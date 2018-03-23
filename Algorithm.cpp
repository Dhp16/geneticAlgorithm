#include "Algorithm.h"

#include <ctime>
#include <iostream>

#include "Individual.h"
#include "Population.h"

inline double rand01()
{
    return ((double)rand() / (RAND_MAX));
}

Algorithm::Algorithm(const unsigned int length,const double uniformRate, 
                     const double mutationRate, const int tournamentSize,
                     const bool elitism) : 
                     _length(length), _uniformRate(uniformRate),
                    _mutationRate(mutationRate), _tournamentSize(tournamentSize)
{}

void Algorithm::evolvePopulation(Population& population)
{
    // breeding phase
    Population newPopulation;

    int offset = 0;
    if (_elitism) {
        newPopulation.addIndividual(population.getFittestIndividual());
        offset++;
    }

    for (unsigned int i = offset; i < population.size(); ++i) {
        Individual individual1 = tournamentSelection(population);
        Individual individual2 = tournamentSelection(population);
        Individual newIndividual = crossover(individual1, individual2);
        newPopulation.addIndividual(newIndividual); 
    }

    // mutation phase
    for(unsigned int i = 0; i < population.size(); ++i) {
        Individual newIndividual = newPopulation.getIndividual(i);
        mutate(newIndividual);
        newPopulation.setIndividual(i, newIndividual); 
    }
    
    population = newPopulation;
}

// selects best from a random subset of the population
Individual Algorithm::tournamentSelection(const Population& population)
{
    Population tournament(_tournamentSize, _length);
    for (unsigned int i = 0; i < _tournamentSize; ++i)
    {
        int randomIndex = (rand() % static_cast<int>(population.size()));
        tournament.addIndividual(population.getIndividual(randomIndex));
    }

    return tournament.getFittestIndividual();
}

Individual Algorithm::crossover(const Individual& individual1, const Individual& individual2)
{
    Individual newIndividual(_length);
    for (unsigned int i = 0; i < _length; ++i)
    {
        if (rand01() <= _uniformRate)
        {
            newIndividual.setGene(i, individual1[i]);
        }
        else
        {
            newIndividual.setGene(i, individual2[i]);
        }
    }
    return newIndividual;
}

void Algorithm::mutate(Individual &individual)
{
    for (unsigned int i = 0; i < individual.size(); ++i)
    {
        if (rand01() < _mutationRate)
        {
            individual.flip(i);
        }
    }
}