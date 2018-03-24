#include "HyperparameterSet.h"

#include <ctime>
#include <iostream>

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
  _tournamentSize(tournamentSize),  _uniformRate(uniformRate),
   _mutationRate(mutationRate)
{}

unsigned int HyperparameterSet::getPopulationSize() const
{
    return _populationSize;
}
unsigned int HyperparameterSet::getTournamentSize() const
{
    return _tournamentSize;
}
double HyperparameterSet::getMutationRate() const
{
    return _mutationRate;
}
double HyperparameterSet::getUniformRate() const
{
    return _uniformRate;
}
bool HyperparameterSet::getElitism() const
{
    return _elitism;
}

void 
HyperparameterSet::print() const {
    std::cout << "population size: " << _populationSize << std::endl;
    std::cout << "tournament size: " << _tournamentSize << std::endl;
    std::cout << "uniform size: " << _uniformRate << std::endl;
    std::cout << "mutation size: " << _mutationRate << std::endl;
}

void
HyperparameterSet::writeToFile(std::ofstream& file) const {
    file << _populationSize << " " << _tournamentSize << " " << _uniformRate << " " << _mutationRate << " " << _elitism << " ";
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

    double tournamentSizeMax = tournamentSizeRange.second;
    if(tournamentSizeRange.second > _populationSize) {
        tournamentSizeMax =  _populationSize - 1;
    }
    std::uniform_int_distribution<int> tournamentSizeDistribution(
        tournamentSizeRange.first, tournamentSizeMax);
    _tournamentSize = tournamentSizeDistribution(rng);

    std::uniform_real_distribution<double> uniformRateDistribution(
        uniformRateRange.first, uniformRateRange.second);
    _uniformRate = uniformRateDistribution(rng);

    std::uniform_real_distribution<double> mutationRateDistribution(
        mutationRateRange.first, mutationRateRange.second);
    _mutationRate = mutationRateDistribution(rng);

    std::uniform_int_distribution<int> elitismDistribution(0,1);
    _elitism = elitismDistribution(rng);
}



// need to find a way of setting the range for each of the components