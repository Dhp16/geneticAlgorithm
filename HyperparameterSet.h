#ifndef HYPERPARAMETERSET_H
#define HYPERPARAMETERSET_H

#include <utility>
#include <random>

class HyperparameterSet
{
  public:
    HyperparameterSet(const unsigned int length, const std::pair<unsigned int, 
    unsigned int> populationRange, std::pair<unsigned int, unsigned int> 
    tournamentSizeRange, const std::pair<double, double> uniformRateRange,
                      const std::pair<double, double> mutationRateRange);

    HyperparameterSet(const unsigned int length, const unsigned int populationSize,
                      const unsigned int tournamentSize, 
                      const double uniformRate, const double mutationRate, 
                      const bool elitism);

    ~HyperparameterSet(){};

    void print();

  private:
    void generateRandomMemberVariablesWithinRanges(
        const std::pair<unsigned int, unsigned int> populationRange,
        const std::pair<unsigned int, unsigned int> tournamentSizeRange,
        const std::pair<double, double> uniformRateRange,
        const std::pair<double, double> mutationRateRange);

    unsigned int _length;

    unsigned int _populationSize;
    unsigned int _tournamentSize;

    double _mutationRate;
    double _uniformRate;
    bool _elitism;

    std::random_device _rd; 
};

#endif // HYPERPARAMETERSET_H