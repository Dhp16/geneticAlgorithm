#include "FitnessCalculation.h"

#include <ctime>
#include <iostream>

#include "Individual.h"

std::vector<bool> FitnessCalculation::_solution;

void FitnessCalculation::setSolution(const std::vector<bool>& solution)
{
    _solution = solution;
} 

void FitnessCalculation::printSolution()
{
    std::cout <<"Solution: " << std::endl;
    for(unsigned int i = 0; i < _solution.size(); ++i) {
        std::cout << _solution[i];
    }
    std::cout << std::endl;
}

int FitnessCalculation::getFitness(const std::vector<bool>& individual)
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