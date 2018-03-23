#include "HyperparameterSet.h"

#include <ctime>
#include <iostream>

inline double rand01()
{
    return ((double)rand() / (RAND_MAX));
}

HyperparameterSet::HyperparameterSet(const unsigned int length, 
                  const std::pair < unsigned int, unsigned int> populationRange, 
                  const std::pair<unsigned int, unsigned int> tournamentSizeRange,
                  const std::pair<double, double> uniformRateRange,
                  const std::pair<double, double> mutationRateRange): _length(length)
{
    generateRandomMemberVariablesWithinRanges(populationRange, tournamentSizeRange,
    uniformRateRange, mutationRateRange);
}

HyperparameterSet::HyperparameterSet(const unsigned int length, const unsigned
 int populationSize, const unsigned int tournamentSize, 
 const double uniformRate, const double mutationRate,
  bool elitism): _length(length), _populationSize(populationSize),
  _uniformRate(uniformRate), _mutationRate(mutationRate)
{}

void 
HyperparameterSet::print() {
    std::cout << "population size: " << _populationSize << std::endl;
    std::cout << "tournament size: " << _tournamentSize << std::endl;
    std::cout << "uniform size: " << _uniformRate << std::endl;
    std::cout << "mutation size: " << _mutationRate << std::endl;
}

void
HyperparameterSet::generateRandomMemberVariablesWithinRanges(
const std::pair < unsigned int, unsigned int> populationRange, 
const std::pair < unsigned int, unsigned int> tournamentSizeRange, 
const std::pair <double, double> uniformRateRange,
const std::pair <double, double> mutationRateRange)
{       
    std::mt19937 rng(_rd());      

    std::uniform_int_distribution<int> populationDistribution(
        populationRange.first, populationRange.second);
    _populationSize = populationDistribution(rng);

    std::uniform_int_distribution<int> tournamentSizeDistribution(
        tournamentSizeRange.first, tournamentSizeRange.second);
    _tournamentSize = tournamentSizeDistribution(rng);

    std::uniform_real_distribution<double> uniformRateDistribution(
        uniformRateRange.first, uniformRateRange.second);
    _uniformRate = uniformRateDistribution(rng);

    std::uniform_real_distribution<double> mutationRateDistribution(
        mutationRateRange.first, mutationRateRange.second);
    _mutationRate = mutationRateDistribution(rng);

    _elitism = rand01();
}



// need to find a way of setting the range for each of the components