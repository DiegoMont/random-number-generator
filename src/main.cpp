#include <iostream>

#include "UserInterface.cpp"

#include "KolmogorovSmirnovTest.cpp"

int main() {
    LinearCongruentialGenerator lcg(8121 ,28411, 134456);
    LecuyerGenerator lg;
    KolmogorovSmirnovTest test((size_t)500, &lcg, 0.2);
    test.print();
    //UserInterface::startApp();
    /* MidSquareGenerator midSquare;
    midSquare.setSeed(3708);

    LinearCongruentialGenerator lcg(8121 ,28411, 134456);

    MixedCongruentialGenerator mg(5, 7, 8);

    MultiplicativeCongruentialGenerator mcg(75, 0b10000000000000001);

    LecuyerGenerator lg;

    for (int i = 0; i < 10; i++){
        //lg.printCurrentSeed();
        std::cout << lg.next() << std::endl;
    } */
}
