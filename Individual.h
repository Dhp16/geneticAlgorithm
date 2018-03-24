#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>
#include <ctime>

class Individual {

  public:
    Individual();
    Individual(const unsigned int length);
    Individual(unsigned int length, const bool generate);
    ~Individual();

    bool getGene(const unsigned int index) const;
    void setGene(const unsigned int index, const bool geneValue);
    int getFitness() const;
    std::vector<bool> getChromosome() const;
    unsigned int size() const;
    void print() const;
    void flip(const unsigned int index);

    bool operator[](unsigned int x) const{
      return _chromosome[x];
    }
    bool operator<(Individual& j) { 
      return (this->getFitness()<j.getFitness());
    }

  private:
    const static int _geneLength = 15;
    std::vector<bool> _chromosome;
};


#endif