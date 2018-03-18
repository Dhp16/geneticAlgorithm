#include "Individual.h"
#include "FitnessCalculation.h"

#include <iostream> 

Individual::Individual(): _fitness(0)
{   


}
Individual::Individual(const unsigned int length): _fitness(0)
{
    _chromosome.resize(length);
}

Individual::Individual(unsigned int length, const bool generate): _fitness(0)
{
    _chromosome.resize(length);
    for(unsigned int i = 0; i < length; ++i){
        _chromosome[i] = rand() % 2; 
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
    return FitnessCalculation::getFitness(_chromosome);
}

std::vector<bool> Individual::getChromosome() const
{
    return _chromosome;
}

unsigned int Individual::size() const{
    return _chromosome.size();
}

void Individual::print() const {
    for(unsigned int i = 0; i < _chromosome.size(); ++i) {
        std::cout <<_chromosome[i];
    }
    std::cout << std::endl;
}

void Individual::flip(const unsigned int index) {
    _chromosome[index] = !_chromosome[index];
}
