#include "GeneratorUniformityTest.cpp"

class KolmogorovSmirnovTest: public GeneratorUniformityTest {
    private:
    double a;
    double dPlus;
    double dMinus;
    double d;
    double da;

    public:
    KolmogorovSmirnovTest(size_t n, RandomGenerator* generator, double a): GeneratorUniformityTest(n, generator) {
        this->a = a;
        calculateD();
        calculateDa();
    }

    void print() {
        printf("D+ = %.3f   D- = %.3f\n", dPlus, dMinus);
        if(this->d > this->da)
            printf("D = %.3f > Da = %.3f \nLa hipotesis nula es rechazada\n", this->d, this->da);
        else
            printf("D = %.3f <= Da = %.3f \nLa hipotesis nula es aceptada. La muestra proviene de la distribucion uniforme\n", this->d, this->da);
    }

    private:
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
