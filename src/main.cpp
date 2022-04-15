#include <iostream>

#include "MidSquareGenerator.cpp"
#include "LinearCongruentialGenerator.cpp"

int main() {
    MidSquareGenerator midSquare;
    midSquare.setSeed(3708);

    LinearCongruentialGenerator lcg(8121 ,28411, 134456);

    for (int i = 0; i < 10; i++){
        //lcg.printCurrentSeed();
        std::cout << lcg.next() << std::endl;
    }
}
