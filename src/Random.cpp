#include <chrono>

#include "RandomGeneratorMethod.cpp"

class Random {
    int x;
    int(*generatorMethod)(int);
    int m;

    public:
    Random() {
        setSeed();
        useMidSquareMethod();
    }

    double next() {
        this->x = generatorMethod(this->x);
        return (1.0 * this->x) / this->m;
    }

    void useMidSquareMethod() {
        m = 9999;
        generatorMethod = RandomGeneratorMethod::midSquare;
    }

    double getX() {
        return this->x;
    }

    void setSeed() {
        using namespace std::chrono;
        do {
            auto currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
            this->x = (int) currentTime % 10000;
        } while(this->x == 0);
    }

};
