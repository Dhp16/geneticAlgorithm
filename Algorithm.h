#ifndef ALGORITHM_H
#define ALGORITHM_H


class Individual;
class Population;

class Algorithm
{

    public:
        Algorithm(unsigned int length);

        Population evolvePopulation(const Population& population);
        
        Individual tournamentSelection(const Population& population);

        Individual crossover(const Individual& individual1, const Individual& individual2);
        void mutate(Individual& individual);

    private:
    
        unsigned int _length;
        double _uniformRate = 0.5;
        double _mutationRate = 0.002;
        int _tournamentSize = 15;
        bool elitism = false;
};


#endif // ALGORITHM_H