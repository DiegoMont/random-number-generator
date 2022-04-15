#include <iostream>

#include "MidSquareGenerator.cpp"

int main() {
    MidSquareGenerator midSquare;
    midSquare.setSeed(3708);

    for (int i = 0; i < 10; i++){
        midSquare.printCurrentSeed();
        std::cout << midSquare.next() << std::endl;
    }
}
