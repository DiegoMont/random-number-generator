#include "RandomGenerator.cpp"

#include <cmath>
#include <stdlib.h>
#include <queue>

class KolmogorovSmirnovTest {
    private:
    double* r;
    size_t n;
    double a;
    double dPlus;
    double dMinus;
    double d;
    double da;

    public:
    KolmogorovSmirnovTest(size_t n, RandomGenerator* generator, double a) {
        this->a = a;
        this->n = n;
        generateAndSortR(generator);
        calculateD();
        calculateDa();
    }

    void print() {
        if(this->d > this->da)
            printf("D = %.3f > Da = %.3f \nLa hipótesis nula es rechazada\n", this->d, this->da);
        else
            printf("D = %.3f <= Da = %.3f \nLa hipótesis nula es aceptada. La muestra proviene de la distribución uniforme\n", this->d, this->da);
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
        double i = 1;
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

    void calculateDa() {
        this->da = c(this->a) / sqrt(this->n);
    }

    double c(double a) {
        return sqrt(-log(a/2)/2);
    }
};
