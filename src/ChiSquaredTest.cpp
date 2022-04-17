#include "GeneratorUniformityTest.cpp"

#include <iostream>

class ChiSquaredTest: public GeneratorUniformityTest {
    size_t k;
    double classSize;
    size_t* categories;
    double X0;
    double Xv;

    public:
    ChiSquaredTest(size_t n, RandomGenerator* generator, double a): GeneratorUniformityTest(n, generator, a) {
        setK();
        std::cout << k << std::endl;
        setClassSize();
        countCategories();
        setX0();
        setXv();
    }

    void print() {}
    
    private:
    void setK() {
        this->k = (size_t)ceil(1 + 3.322 * log10(this->n));
    }

    void setClassSize() {
        double smallestNum = this->r[0];
        double biggestNum = this->r[this->n-1];
        double range = biggestNum - smallestNum;
        this->classSize = range / this->k;
    }

    void countCategories() {
        categories = new size_t[this->k];
        size_t currentClass = 0;
        double currentClassMax = this->r[0] + this->classSize;
        for(size_t i = 0; i < this->n; i++) {
            double ri = this->r[i];
            if(ri > currentClassMax) {
                currentClass++;
                currentClassMax += this->classSize;
            }
            categories[currentClass]++;
        }
    }

    void setX0() {
        X0 = 0;
        double expected = (double) n / k;
        for (size_t i = 0; i < this->k; i++) {
            size_t observations = categories[i];
            double localQi2 = observations - expected;
            localQi2 *= localQi2;
            localQi2 /= expected;
            X0 += localQi2;
        }
        printf("%lf\n", X0);
    }

    void setXv() {
        size_t degreesOfFreedom = k - 1 - 1;
    }

};
