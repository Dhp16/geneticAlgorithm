#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>

class Individual {

  public:
    Individual();
    Individual(const bool isRandom);
    ~Individual();

    bool getGene(const unsigned int index) const;
    void setGene(const unsigned int index, const bool geneValue);
    int getFitness();

  private:
    const static int _geneLength = 15;
    std::vector<bool> _chromosome;

    int _fitness;

};


#endif