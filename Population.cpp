#include "Population.h"

Population::Population()
{

}

Population::Population(unsigned int size, unsigned int length)
{
    for(unsigned int i = 0; i < size; ++i) {
        Individual newIndividual(length);
        newIndividual.getFitness();
        _individuals.push_back(newIndividual);
    }
}

Individual Population::getFittestIndividual()
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

Individual Population::getIndividual(const unsigned int index) {
    return _individuals[index];
}

int Population::size() const {
    return _individuals.size();
}

void Population::addIndividual(const Individual& individual){
    _individuals.push_back(individual);
}
