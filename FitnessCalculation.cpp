#include "FitnessCalculation.h"

#include <ctime>
#include <iostream>

#include "Individual.h"

std::vector<bool> FitnessCalculation::_solution;

void FitnessCalculation::setSolution(const std::vector<bool>& solution)
{
    _solution = solution;
} 

int FitnessCalculation::getFitness(Individual individual)
{
    int fitness = 0;
    for(unsigned int i = 0; i < individual.size(); ++i) {
        if(_solution[i] == individual[i]) {
            fitness++;
        }
    }
    return fitness;
}
int FitnessCalculation::getMaxFitness() {
    return _solution.size();
}

void FitnessCalculation::generateASolution(const unsigned int length) {
    _solution.resize(length);
    srand(time(0));
    for (unsigned int i = 0; i < length; ++i) {
        _solution[i] = rand() % 2;
    }
}