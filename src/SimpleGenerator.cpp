#ifndef SIMPL_GEN
#define SIMPL_GEN

#include <stdio.h>

#include "RandomGenerator.cpp"

class SimpleGenerator: public RandomGenerator {
    public:
    SimpleGenerator(long m): RandomGenerator(m) {}

    void printCurrentSeed() {
        printf("x: %ld\n", this->x);
    };

    void setSeed(long newSeed) {
        this->x = newSeed;
    }

    double next() {
        setNextX();
        return 1.0 * this->x / (this->m);
    }

    long getX() {
        return this->x;
    }

    protected:
    virtual void setNextX() = 0;
};

#endif
