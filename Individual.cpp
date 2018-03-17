#include "Individual.h"
//#include "FitnessCalculation.h"

#include <ctime>

#include <iostream> 


Individual::Individual(): _fitness(0)
{   


}

Individual::Individual(const bool isRandom): _fitness(0)
{
    _chromosome.resize(_geneLength);
    srand(time(0));
    for(unsigned int i = 0; i < _geneLength; ++i){
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
        //_fitness = FitnessCalculation(this);
        int l;
    }
    return _fitness;
}