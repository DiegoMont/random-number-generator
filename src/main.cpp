#include <iostream>

#include "MidSquareGenerator.cpp"
#include "LinearCongruentialGenerator.cpp"
#include "MixedCongruentialGenerator.cpp"

int main() {
    MidSquareGenerator midSquare;
    midSquare.setSeed(3708);

    LinearCongruentialGenerator lcg(8121 ,28411, 134456);

    MixedCongruentialGenerator mcg(5, 7, 8);

    for (int i = 0; i < 10; i++){
        //lcg.printCurrentSeed();
        std::cout << mcg.next() << std::endl;
    }
}
