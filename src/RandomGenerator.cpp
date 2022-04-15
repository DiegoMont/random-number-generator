#include <chrono>

class RandomGenerator {
    protected:
    long x;
    long m;

    public:
    RandomGenerator(long m) {
        this->m = m;
        setSeed();
    }

    virtual double next() = 0;

    virtual void printCurrentSeed() = 0;

    void setSeed() {
        this->x = getTimeSeed();
    };

    protected:
    long getTimeSeed() {
        using namespace std::chrono;
        long seed;
        do {
            auto currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
            seed = (long int) (currentTime % m);
        } while(seed == 0);
        return seed;
    }

};
