#ifndef ALGORITHM_H
#define ALGORITHM_H


class Individual;
class Population;

class Algorithm
{

    public:
        Algorithm(unsigned int length);

        Population evolvePopulation(Population population);
        
        Individual tournamentSelection(Population population);

        Individual crossover(Individual individual1, Individual individual2);
        void mutate(Individual& individual);

    private:
    
        unsigned int _length;
        double _uniformRate = 0.5;
        double _mutationRate = 0.015;
        int _tournamentSize = 5;
        bool elitism = false;
};


#endif // ALGORITHM_H