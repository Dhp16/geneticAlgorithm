#ifndef POPULATION_H
#define POPULATION_H

#include "Individual.h"
#include <vector>

class Population
{
    public:
        Population();
        Population(const unsigned int size, unsigned int length);

        Individual getFittestIndividual();
        int size() const;

    private:
        std::vector<Individual> _individuals;        
};

#endif
