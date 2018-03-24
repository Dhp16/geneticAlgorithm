#ifndef HYPERPARAMETERSET_H
#define HYPERPARAMETERSET_H

#include <utility>
#include <random>
#include <fstream>

class HyperparameterSet
{
  public:
    HyperparameterSet(const unsigned int length, const std::pair<unsigned int, 
    unsigned int> populationRange, std::pair<unsigned int, unsigned int> 
    tournamentSizeRange, const std::pair<double, double> uniformRateRange,
                      const std::pair<double, double> mutationRateRange,
                      const std::pair<double, double> elitismRange);

    HyperparameterSet(const unsigned int length, const unsigned int populationSize,
                      const unsigned int tournamentSize, 
                      const double uniformRate, const double mutationRate, 
                      const double elitism);

    ~HyperparameterSet(){};

    unsigned int getPopulationSize() const;
    unsigned int getTournamentSize() const;
    double getMutationRate() const;
    double getUniformRate() const;
    double getElitism() const;
    void print() const;
    void writeToFile(std::ofstream& file) const;

  private:
    void generateRandomMemberVariablesWithinRanges(
        const std::pair<unsigned int, unsigned int> populationRange,
        const std::pair<unsigned int, unsigned int> tournamentSizeRange,
        const std::pair<double, double> uniformRateRange,
        const std::pair<double, double> mutationRateRange, 
        const std::pair<double, double> elitismRange);

    unsigned int _length;

    unsigned int _populationSize;
    unsigned int _tournamentSize;

    double _mutationRate;
    double _uniformRate;
    double _elitism;

    std::random_device _rd; 
};

#endif // HYPERPARAMETERSET_H