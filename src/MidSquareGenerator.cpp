#include "SimpleGenerator.cpp"

class MidSquareGenerator: public SimpleGenerator {
    public:
    MidSquareGenerator(): SimpleGenerator(10000) {}

    private:
    void setNextX() {
        long square = this->x * this->x;
        long rightDigitsRemoved = square / 100;
        this->x = rightDigitsRemoved % this->m;
    }
};
