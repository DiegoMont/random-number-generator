#include <iostream>

#include "Random.cpp"

int main() {
    Random r;
    for (int i = 0; i < 10; i++){
        //std::cout << r.getX() << std::endl;
        std::cout << r.next() << std::endl;
    }
}
