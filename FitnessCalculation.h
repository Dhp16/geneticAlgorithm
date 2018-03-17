#ifndef FITNESSCALCULATION_H
#define FITNESSCALCULATION_H

#include <vector>

class Individual;

class FitnessCalculation
{
  public:
    static void setSolution(const std::vector<bool> &solution);
    static int getFitness(Individual individual);
    static int getMaxFitness();
    static void generateASolution(const unsigned int length);

  private:
    static std::vector<bool> _solution;
};

#endif