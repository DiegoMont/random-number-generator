#include <chrono>

class Random {
    int x;

    public:
    Random() {
        setSeed();
    }

    void setSeed() {
        using namespace std::chrono;
        do {
            auto currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
            this->x = (int) currentTime % 10000;
        } while(this->x == 0);
    }
};
