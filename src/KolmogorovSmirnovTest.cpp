#include "RandomGenerator.cpp"

#include <cmath>
#include <stdlib.h>
#include <queue>

class KolmogorovSmirnovTest {
    private:
    double* r;
    size_t n;
    double dPlus;
    double dMinus;
    double d;

    public:
    KolmogorovSmirnovTest(size_t n, RandomGenerator* generator) {
        this->n = n;
        generateAndSortR(generator);
        calculateD();
    }

    private:
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

    void calculateD() {
        int i = 1;
        this->dPlus = 0;
        this->dMinus = 0;
        for (size_t j = 0; j < this->n; j++) {
            double Ri = this->r[j];
            double auxD;
            auxD = std::abs(i/this->n - Ri);
            this->dPlus = (auxD > this->dPlus ? auxD: this->dPlus);
            auxD = std::abs(Ri - (i-1)/this->n);
            this->dMinus = (auxD > this->dMinus ? auxD: this->dMinus);
            i++;
        }
        this->d = std::max(this->dPlus, this->dMinus);
    }
};
