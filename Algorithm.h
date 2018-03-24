#ifndef ALGORITHM_H
#define ALGORITHM_H


class Individual;
class Population;
class HyperparameterSet;

class Algorithm
{
    public:
      Algorithm(const unsigned int length,
      const HyperparameterSet& hyperParameters);

      void evolvePopulation(Population &population);

    private:
      Individual tournamentSelection(const Population &population) const;
      Individual crossover(const Individual &individual1, const Individual &individual2) const;
      void mutate(Individual &individual);

      unsigned int _length;
      double _uniformRate;
      double _mutationRate;
      int _tournamentSize;
      double _elitism;
};


#endif // ALGORITHM_H