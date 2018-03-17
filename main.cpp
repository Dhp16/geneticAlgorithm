//    This is pretty much an exact replica of the code which can be found:
//    http://www.theprojectspot.com/tutorial-post/creating-a-genetic-algorithm-for-beginners/3
//    except that this is c++ and the one above if Java.    
//    I was looking for a starting point to learn about GAs, please visit the above page for information
//    All credit to: Lee from theprojectspot.com


#include <iostream>
#include "Individual.h"
#include "Population.h"
#include "FitnessCalculation.h"

bool tester(){

    int length = 15;
    int populationSize = 20;

    FitnessCalculation::generateASolution(15);
    Individual individual(true);
    Population population(populationSize, length);

    return true;
}

int main()
{
    std::cout <<" Hello world!" << std::endl;
    tester();
    return 0;
}