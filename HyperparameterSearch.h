#include <utility>

class HyperparameterSet;

inline double rand01();
unsigned int run(const unsigned int length, const HyperparameterSet& hyperParameters);
double timedRun(const unsigned int length, const HyperparameterSet& hyperParameters);
void randomSearch(const unsigned int length, const unsigned int iterations);
