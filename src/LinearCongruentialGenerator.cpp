#ifndef LINEAR_CONG
#define LINEAR_CONG

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
        long long int bigResult = (1ll * this->a * this->x + this->c) % m;
        this->x = (long int) bigResult;
    }
};

#endif
