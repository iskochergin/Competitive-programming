#include <iostream>

long long power(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long base = 2, exp = 10;
    int mod = 1e9 + 7;
    std::cout << "2^10 mod 1e9+7 = " << power(base, exp, mod) << std::endl;
    return 0;
}
