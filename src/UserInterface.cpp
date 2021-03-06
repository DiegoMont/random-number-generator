#include <stdio.h>

#include "UserInterface.h"

void UserInterface::startApp() {
    puts("SIMULADOR DE NUMEROS RANDOM");
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
    puts("Elige un metodo para generar los numeros aleatorios:");
    puts("1. Centros Cuadrados");
    puts("2. Lineal Congruencial");
    puts("3. Congruencial Mixto");
    puts("4. Congruencial Multiplicativo");
    puts("5. Generador de L'ecuyer");
    puts("6. Salir");
    printf("Ingresa una opcion: ");
}

void UserInterface::startGeneratingNumbers(int selectedGenerator) {
    RandomGenerator* generator;
    if(selectedGenerator == 1)
        generator = UserInterface::createMidSquaresGenerator();
    else if(selectedGenerator == 2)
        generator = UserInterface::createLinearCongruential();
    else if(selectedGenerator == 3)
        generator = UserInterface::createMixedCongruential();
    else if(selectedGenerator == 4)
        generator = UserInterface::createMultiplicativeCongruential();
    else if(selectedGenerator == 5)
        generator = UserInterface::createLecuyerGenerator();
    gotoGeneratorMenu(generator);
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
    if(option != 1) {
        printf("Ingrese el valor de a: ");
        scanf("%ld", &a);
        printf("Ingrese el valor de c: ");
        scanf("%ld", &c);
        printf("Ingrese el valor de m: ");
        scanf("%ld", &m);
    } else {
        a = 8121;
        c = 28411;
        m = 134456;
    }
    LinearCongruentialGenerator* lcg = new LinearCongruentialGenerator(a, c, m);
    return lcg;
}

MixedCongruentialGenerator* UserInterface::createMixedCongruential() {
    long a, c, m;
    MixedCongruentialGenerator* mg;
    bool validValues;
    do {
        validValues = true;
        puts("Ingresa los valores de a, c y m");
        printf("a: ");
        scanf("%ld", &a);
        printf("c: ");
        scanf("%ld", &c);
        printf("m: ");
        scanf("%ld", &m);
        try {
            mg = new MixedCongruentialGenerator(a, c, m);
        } catch(int e) {
            validValues = false;
            puts("Estos valores no pasan la prueba de Hull-Dobel");
        }
    } while (!validValues);
    return mg;
}

MultiplicativeCongruentialGenerator* UserInterface::createMultiplicativeCongruential() {
    long a, m;
    MultiplicativeCongruentialGenerator* mcg;
    bool validValues;
    do {
        validValues = true;
        puts("Ingresa los valores de a y m");
        printf("a: ");
        scanf("%ld", &a);
        printf("m: ");
        scanf("%ld", &m);
        try {
            mcg = new MultiplicativeCongruentialGenerator(a, m);
        } catch(int e) {
            validValues = false;
            puts("Valores incorrectos m > a");
        }
    } while (!validValues);
    return mcg;
}

LecuyerGenerator* UserInterface::createLecuyerGenerator() {
    LecuyerGenerator* lg = new LecuyerGenerator();
    return lg;
}

void UserInterface::gotoGeneratorMenu(RandomGenerator* generator) {
    int option = -1;
    while(option != 4) {
        UserInterface::printGeneratorMenu();
        scanf("%d", &option);
        if(option == 1)
            printf("\n%f\n\n", generator->next());
        else if(option == 2)
            UserInterface::chooseSeed(generator);
        else if(option == 3)
            UserInterface::evaluateGenerator(generator);
    }
}

void UserInterface::printGeneratorMenu() {
    puts("Elige una accion para el generador");
    puts("1. Siguiente numero aleatorio");
    puts("2. Establecer semilla");
    puts("3. Evaluar");
    puts("4. Salir");
    printf("Ingresa una opcion: ");
}

void UserInterface::chooseSeed(RandomGenerator* generator) {
    long newSeed;
    printf("Ingrese el valor de la nueva semilla: ");
    scanf("%ld", &newSeed);
    SimpleGenerator* simpleGenerator = dynamic_cast<SimpleGenerator*> (generator);
    if(simpleGenerator != nullptr)
        simpleGenerator->setSeed(newSeed);
}

void UserInterface::evaluateGenerator(RandomGenerator* generator) {
    size_t n;
    double aKS;
    enum ChiSquareSignificance aCS;
    printf("Cuantos numeros quiere generar para hacer la prueba [N]: ");
    scanf("%ld", &n);
    int option = -1;
    do {
        UserInterface::printSignificanceOptions();
        scanf("%d", &option);
    } while(option > 5 || option < 1 );
    double availableSignificances[] = {0.1, 0.05, 0.025, 0.01, 0.001};
    option--;
    aKS = availableSignificances[option];
    aCS = (enum ChiSquareSignificance) option;
    puts("\nKolmogorov-Smirnov");
    KolmogorovSmirnovTest test(n, generator, aKS);
    test.print();
    puts("\nChi Cuadrada");
    ChiSquaredTest test2(n, generator, aCS);
    test2.print();
    puts("");
}

void UserInterface::printSignificanceOptions() {
    puts("Valores de significancia disponibles");
    puts("1. 0.1");
    puts("2. 0.05");
    puts("3. 0.025");
    puts("4. 0.01");
    puts("5. 0.001");
    printf("Ingrese una opcion: ");
}
