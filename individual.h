#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

class Invdividual {

  public:
    Individual();
    Individual(const bool isRandom);
    ~Individual();

    void setGeneLength();

  private:
    static int _geneLength = 15;
    


};


#endif