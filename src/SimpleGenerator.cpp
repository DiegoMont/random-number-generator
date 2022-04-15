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
        return 1.0 * this->x / (this->m - 1);
    }

    protected:
    virtual void setNextX() = 0;
};
