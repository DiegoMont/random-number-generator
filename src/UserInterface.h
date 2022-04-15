#include "RandomGenerator.cpp"
#include "MidSquareGenerator.cpp"
#include "LinearCongruentialGenerator.cpp"
#include "MixedCongruentialGenerator.cpp"
#include "MultiplicativeCongruentialGenerator.cpp"
#include "LecuyerGenerator.cpp"

namespace UserInterface {
    void startApp();

    void selectGenerationMethod();

    void printGenerationMethodsMenu();

    void startGeneratingNumbers(int selectedGenerator);

    MidSquareGenerator* createMidSquaresGenerator();

    LinearCongruentialGenerator* createLinearCongruential();

    MixedCongruentialGenerator* createMixedCongruential();

    MultiplicativeCongruentialGenerator* createMultiplicativeCongruential();

    LecuyerGenerator* createLecuyerGenerator();

    void gotoGeneratorMenu(RandomGenerator* generator);

    void printGeneratorMenu();
}
