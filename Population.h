#ifndef POPULATION_H
#define POPULATION_H

#include "Individual.h"
#include <vector>

class Population
{
    public:
        Population();
        Population(const unsigned int size, unsigned int length);

        Individual getFittestIndividual() const;
        int size() const;
        void addIndividual(const Individual& individual);
        Individual getIndividual(const unsigned int index) const;
        void print() const;
        void setIndividual(const unsigned int index, const Individual& newIndividual);

    private:
        std::vector<Individual> _individuals;        
};

#endif
