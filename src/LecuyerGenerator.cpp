#include "CombinedLinearCongruential.cpp"
#include "MultiplicativeCongruentialGenerator.cpp"

class LecuyerGenerator: public CombinedLinearCongruential {
    public:
    LecuyerGenerator(): CombinedLinearCongruential(2147483563) {
        MultiplicativeCongruentialGenerator* g1 = new MultiplicativeCongruentialGenerator(40014, this->m);
        MultiplicativeCongruentialGenerator* g2 = new MultiplicativeCongruentialGenerator(40692, 2147483399);
        this->numGenerators = 2;
        this->generators = new SimpleGenerator*[this->numGenerators];
        generators[0] = g1;
        generators[1] = g2;
    }
};
