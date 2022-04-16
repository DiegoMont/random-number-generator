#ifndef GEN_TESTER
#define GEN_TESTER

#include "RandomGenerator.cpp"

#include <cmath>
#include <stdio.h>
#include <queue>

class GeneratorUniformityTest {
    protected:
    double* r;
    size_t n;
    double a;
    
    public:

    GeneratorUniformityTest(size_t n, RandomGenerator* generator, double a) {
        this->n = n;
        this->a = a;
        generateAndSortR(generator);
    }
    virtual void print() = 0;

    protected:
    void generateAndSortR(RandomGenerator* generator) {
        using namespace std;
        priority_queue<double, vector<double>, greater<double>> q;
        for (size_t i = 0; i < this->n; i++)
            q.push(generator->next());
        this->r = new double[this->n];
        for (size_t i = 0; i < this->n; i++) {
            this->r[i] = q.top();
            q.pop();
        }
    }
};

#endif
