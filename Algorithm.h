#ifndef ALGORITHM_H
#define ALGORITHM_H


class Individual;
class Population;

class Algorithm
{

    public:
      Algorithm(const unsigned int length, const double uniformRate,
                const double mutationRate, const int tournamentSize,
                const bool elitism);

      void evolvePopulation(Population &population);

      Individual tournamentSelection(const Population &population);

      Individual crossover(const Individual &individual1, const Individual &individual2);
      void mutate(Individual &individual);

    private:
    
        unsigned int _length;
        double _uniformRate;
        double _mutationRate;
        int _tournamentSize;
        bool _elitism;
};


#endif // ALGORITHM_H