#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;  // Пример модуля

// Функция для вычисления факториала по модулю
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

// Функция для вычисления обратного факториала по модулю
long long modInverse(long long a, int mod) {
    long long result = 1;
    int exponent = mod - 2; // По теореме Ферма
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        exponent /= 2;
    }
    return result;
}

// Функция для вычисления обратного факториала
long long inverseFactorial(int n) {
    return modInverse(factorial(n), MOD);
}

int main() {
    int n = 5;
    std::cout << "Factorial: " << factorial(n) << std::endl;
    std::cout << "Inverse Factorial: " << inverseFactorial(n) << std::endl;
    return 0;
}
