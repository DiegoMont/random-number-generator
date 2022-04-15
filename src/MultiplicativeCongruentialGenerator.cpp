#ifndef MULT_CONG
#define MULT_CONG

#include "LinearCongruentialGenerator.cpp"

class MultiplicativeCongruentialGenerator: public LinearCongruentialGenerator {

    public:
    MultiplicativeCongruentialGenerator(long a, long m): LinearCongruentialGenerator(a, 0, m) {
        if(a >= m)
            throw 500;
        {
            this->x = getTimeSeed();
            this->x %= a;
        } while(this->x == 0);
    }

};

#endif
