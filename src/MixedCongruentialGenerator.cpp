#include <vector>

#include "LinearCongruentialGenerator.cpp"

class MixedCongruentialGenerator: public LinearCongruentialGenerator {

    public:
    MixedCongruentialGenerator(long a, long c, long m): LinearCongruentialGenerator(a, c, m) {
        if(!passesHullDobellTest(a, c, m))
            throw 500;
    }

    protected:
    bool passesHullDobellTest(long a, long c, long m) {
        bool areRelativePrimes = gcd(c, m) == 1;
        bool aDivisibleByMFactors = testADivisibility();
        bool aAndMDivisibleByFour = ((a-1) % 4 == 0) && (m % 4 == 0);
        return areRelativePrimes && aAndMDivisibleByFour && aDivisibleByMFactors;
    }

    private:
    long gcd(long a, long b) {
        if(a == 0)
            return b;
        else
            return gcd(b % a, a);
    }

    bool testADivisibility() {
        std::vector<long>* mFactors = getPrimeFactors(this->m);
        bool isDivisible;
        for(long factor: *mFactors) {
            isDivisible = (a-1) % factor == 0;
            if(!isDivisible)
                break;
        }
        delete mFactors;
        return isDivisible;
    }

    std::vector<long>* getPrimeFactors(long limit) {
        std::vector<long>* primeFactors = new std::vector<long>();
        bool* numbers = new bool[limit+1];
        for (size_t i = 0; i < sizeof(numbers); i++)
            numbers[i] = true;
        for (long p = 2; p * p <= limit; p++){
            if(numbers[p]) {
                for(long i = p * p; i <= limit; i += p)
                    numbers[i] = false;
                if(limit % p == 0) {
                    primeFactors->push_back(p);
                    limit /= p;
                }
            }
        }
        delete[] numbers;
        return primeFactors;
    }
};
