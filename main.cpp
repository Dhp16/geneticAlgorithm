//    A large part of this code is a replica from that shared here:
//    http://www.theprojectspot.com/tutorial-post/creating-a-genetic-algorithm-for-beginners/3
//    except that this is c++ and the one above is Java.    
//    I was looking for a starting point to learn about GAs
//    All credit to: Lee from theprojectspot.com whom I thank for very clear introductory code 
//    for genetic algorithms


#include <iostream>
#include <ctime>
#include <fstream>
#include <map>

#include "Individual.h"
#include "Population.h"
#include "FitnessCalculation.h"
#include "Algorithm.h"
#include "HyperparameterSearch.h"

void SetupAndRun()
{
    unsigned int length = 100;
    randomSearch(length, 100);
}

int main()
{
    SetupAndRun();
    return 0;
}