#ifndef COMB_CONG
#define COMB_CONG

#include "RandomGenerator.cpp"
#include "SimpleGenerator.cpp"

class CombinedLinearCongruential: public RandomGenerator {

    protected:
    SimpleGenerator** generators;
    size_t numGenerators;

    public:
    CombinedLinearCongruential(long m1): RandomGenerator(m1){}

    void printCurrentSeed() {
        for(size_t i = 0; i < this->numGenerators; i++)
            generators[i]->printCurrentSeed();
    };

    double next() {
        long long x = 0;
        for(size_t i = 0; i < this->numGenerators; i++) {
            generators[i]->next();
            if(i & 1)
                x -= generators[i]->getX();
            else
                x += generators[i]->getX();
        }
        x %= this->m;
        if(x < 0) 
            x = this->m + x;
        return 1.0 * x / (this->m - 1);
    }

};

#endif
