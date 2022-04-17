#include "GeneratorUniformityTest.cpp"
#include "ChiSquareSignificance.cpp"


class ChiSquaredTest: public GeneratorUniformityTest {
    size_t k;
    double classSize;
    size_t* categories;
    double X0;
    double Xv;
    enum ChiSquareSignificance a;

    public:
    ChiSquaredTest(size_t n, RandomGenerator* generator, enum ChiSquareSignificance a): GeneratorUniformityTest(n, generator) {
        this->a = a;
        setK();
        setClassSize();
        countCategories();
        setX0();
        setXv();
    }

    void print() {
        if(X0 < Xv)
            printf("X0 = %.3f < Xva = %.3f\nLa muestra proviene de la distribucion uniforme\n", X0, Xv);
        else
            printf("X0 = %.3f >= Xva = %.3f\nLa hipotesis nula es rechazada\n", X0, Xv);
    }
    
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
    }

    void setXv() {
        size_t degreesOfFreedom = k - 1 - 1;
        double dot1[] = {2.706, 4.605, 5.251, 7.779, 9.236, 10.645, 12.017, 13.362, 14.684, 15.987, 17.275, 18.549, 19.812, 21.064, 22.307};
        double dot05[] = {3.841, 5.991, 7.815, 9.488, 11.07, 12.592, 14.067, 15.507, 16.919, 18.307, 19.675, 21.026, 22.362, 23.685, 24.996};
        double dot025[] = {5.024, 7.378, 9.348, 11.143, 12.833, 14.449, 16.013, 17.535, 19.023, 20.483, 21.92, 23.337, 24.736, 26.119, 27.488};
        double dot01[] = {6.635, 9.21, 11.345, 13.277, 15.086, 16.812, 18.475, 20.09, 21.666, 23.209, 24.725, 26.217, 27.688, 29.141, 30.578};
        double dot001[] = {10.828, 13.816, 16.266, 18.467, 20.515, 22.458, 24.322, 26.125, 27.877, 29.588, 31.264, 32.91, 34.528, 36.123, 37.697};
        double* significances[5] = {dot1, dot05, dot025, dot01, dot001};
        Xv = dot05[degreesOfFreedom-1];
    }

};
