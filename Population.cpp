#include "Population.h"

#include <iostream>
#include <algorithm>

Population::Population()
{

}

Population::Population(unsigned int size, unsigned int length)
{
    for(int i = 0; i < size; ++i) {
        long int k = i;
        time_t seededTime = time(&k);
        Individual newIndividual(length, true);
        newIndividual.getFitness();
        _individuals.push_back(newIndividual);
    }
}

Individual Population::getFittestIndividual() const
{
    int indexForStrongestIndividual; 
    int maxFitness = 0;
    for(unsigned int i = 0; i < _individuals.size(); ++i) {
        int fitness = _individuals[i].getFitness();
        if(fitness > maxFitness) {
            maxFitness = fitness;
            indexForStrongestIndividual = i;
        }
    }
    return _individuals[indexForStrongestIndividual];
}

std::vector<Individual> Population::getPercentFittest(const double percentFittest) 
{
    int nFittest = int(percentFittest/100*this->size());
    if(nFittest < 1) {
        nFittest = 1;
    }
    std::vector<Individual> fittestIndividuals = _individuals;
    std::sort(fittestIndividuals.begin(), fittestIndividuals.end());
    int nToErase = this->size() - nFittest;
    fittestIndividuals.erase(fittestIndividuals.begin(), fittestIndividuals.begin() + nToErase);
    return fittestIndividuals;
}


Individual Population::getIndividual(const unsigned int index) const {
    return _individuals[index];
}

int Population::size() const {
    return _individuals.size();
}

void Population::addIndividual(const Individual& individual){
    _individuals.push_back(individual);
}
void Population::addIndividuals(const std::vector<Individual>& individuals){
    for(unsigned int i = 0; i < individuals.size(); ++i) {
        _individuals.push_back(individuals[i]);
    }
}

void Population::print() const
{
    for(unsigned int i = 0; i < _individuals.size(); ++i) {
        _individuals[i].print();
    }
    std::cout << std::endl;
}

void Population::setIndividual(const unsigned int index, const Individual& newIndividual) {
    _individuals[index] = newIndividual;
}