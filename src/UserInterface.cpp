#include <stdio.h>

#include "UserInterface.h"

void UserInterface::startApp() {
    puts("SIMULADOR DE NÚMEROS RANDOM");
    puts("###########################\n");
    UserInterface::selectGenerationMethod();
}

void UserInterface::selectGenerationMethod() {
    int option = 0;
    while(option != 6) {
        UserInterface::printGenerationMethodsMenu();
        scanf("%d", &option);
        bool isValidOption = option > 0 && option < 6;
        if(isValidOption) {
            UserInterface::startGeneratingNumbers(option);
        }
    }
}

void UserInterface::printGenerationMethodsMenu() {
    puts("Elige un método para generar los números aleatorios:");
    puts("1. Centros Cuadrados");
    puts("2. Lineal Congruencial");
    puts("3. Congruencial Mixto");
    puts("4. Congruencial Multiplicativo");
    puts("5. Generador de L'ecuyer");
    puts("6. Salir");
    printf("Ingres una opción: ");
}

void UserInterface::startGeneratingNumbers(int selectedGenerator) {
    RandomGenerator* generator;
    if(selectedGenerator == 1)
        generator = UserInterface::createMidSquaresGenerator();
    else if(selectedGenerator == 2)
        generator = UserInterface::createLinearCongruential();
}

MidSquareGenerator* UserInterface::createMidSquaresGenerator() {
    MidSquareGenerator* gen = new MidSquareGenerator();
    return gen;
}

LinearCongruentialGenerator* UserInterface::createLinearCongruential() {
    int option;
    printf("Ingresa [1] para usar los valores predefinidos (a=8121, c=28411, m=134456): ");
    scanf("%d", &option);
    long a, c, m;
    if(option != 'n') {
        a = 8121;
        c = 28411;
        m = 134456;
    } else {
        a = 8121;
        c = 28411;
        m = 134456;
    }
    LinearCongruentialGenerator* lcg = new LinearCongruentialGenerator(a, c, m);
    return lcg;
}
