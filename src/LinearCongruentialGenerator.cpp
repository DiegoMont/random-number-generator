#include "SimpleGenerator.cpp"

class LinearCongruentialGenerator: public SimpleGenerator {
    protected:
    long a;
    long c;

    public:
    LinearCongruentialGenerator(long a, long c, long m): SimpleGenerator(m) {
        this->a = a;
        this->c = c;
    }

    private:
    void setNextX() {
        this->x = (this->a * this->x + this->c) % m;
    }
};
