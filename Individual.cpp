#include "Individual.h"
//#include "FitnessCalculation.h"

#include <ctime>

#include <iostream> 


Individual::Individual(): _fitness(0)
{   


}

Individual::Individual(unsigned int length): _fitness(0)
{
    _chromosome.resize(length);
    srand(time(0));
    for(unsigned int i = 0; i < length; ++i){
        _chromosome[i] = rand() % 2; 
        std::cout << _chromosome[i];
    }
}

Individual::~Individual()
{   


}

bool Individual::getGene(const unsigned int index) const
{   
    if(index < _geneLength) {
        return _chromosome[index];
    }
    throw "ERROR";
}

void Individual::setGene(const unsigned int index, const bool geneValue)
{
    _chromosome[index] = geneValue;
}

int Individual::getFitness() { 
    if(_fitness == 0) {
        //_fitness = FitnessCalculation::getFitness(this);
        int l;
    }
    _fitness = 5;
    return _fitness;
}

std::vector<bool> Individual::getChromosome() const
{
    return _chromosome;
}

unsigned int Individual::size() const{
    return _chromosome.size();
}