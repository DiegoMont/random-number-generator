#include <iostream>

#include "MidSquareGenerator.cpp"
#include "LinearCongruentialGenerator.cpp"
#include "MixedCongruentialGenerator.cpp"
#include "MultiplicativeCongruentialGenerator.cpp"
#include "LecuyerGenerator.cpp"

int main() {
    MidSquareGenerator midSquare;
    midSquare.setSeed(3708);

    LinearCongruentialGenerator lcg(8121 ,28411, 134456);

    MixedCongruentialGenerator mg(5, 7, 8);

    MultiplicativeCongruentialGenerator mcg(75, 0b10000000000000000 + 1);

    LecuyerGenerator lg;

    for (int i = 0; i < 10; i++){
        //lg.printCurrentSeed();
        std::cout << lg.next() << std::endl;
    }
}
