#include <iostream>
#include <chrono>  // For timing

class CustomMatrix {
public:
    unsigned long long m[2][2];

    CustomMatrix() {
        m[0][0] = 1; m[0][1] = 0;
        m[1][0] = 0; m[1][1] = 1;
    }

    CustomMatrix(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d) {
        m[0][0] = a; m[0][1] = b;
        m[1][0] = c; m[1][1] = d;
    }

    CustomMatrix operator*(const CustomMatrix& other) const {
        CustomMatrix result;
        result.m[0][0] = m[0][0]*other.m[0][0] + m[0][1]*other.m[1][0];
        result.m[0][1] = m[0][0]*other.m[0][1] + m[0][1]*other.m[1][1];
        result.m[1][0] = m[1][0]*other.m[0][0] + m[1][1]*other.m[1][0];
        result.m[1][1] = m[1][0]*other.m[0][1] + m[1][1]*other.m[1][1];
        return result;
    }
};

// Linear Fibonacci
unsigned long long fibonacci_linear(int n) {
    if (n == 0) return 0;
    CustomMatrix base(1, 1, 1, 0);
    CustomMatrix result;

    for (int i = 0; i < n; ++i) {
        result = result * base;
    }

    return result.m[1][0];
}

// Fast Exponentiation
CustomMatrix fastExponentiation(CustomMatrix base, int n) {
    CustomMatrix result;

    while (n > 0) {
        if (n % 2 == 1)
            result = result * base;
        base = base * base;
        n /= 2;
    }

    return result;
}

// Log Fibonacci
unsigned long long fibonacci_log(int n) {
    if (n == 0) return 0;
    CustomMatrix base(1, 1, 1, 0);
    CustomMatrix result = fastExponentiation(base, n);
    return result.m[1][0];
}

// MAIN PROGRAM
int main() {
    const int N = 50;

    std::cout << "*** Fibonacci Sequence with n equals to: " << N << " ***\n";
    
    // LINEAR
    auto start_linear = std::chrono::high_resolution_clock::now();

    std::cout << "Linear Time O(n)\n";
    std::cout << "F(" << N << ") = " << fibonacci_linear(N) << '\n';

    auto end_linear = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed_linear = end_linear - start_linear;
    std::cout << "Linear time elapsed: " << elapsed_linear.count() << " ms\n\n";
    
    // LOGARITHMIC
    auto start_log = std::chrono::high_resolution_clock::now();

    std::cout << "Logarithmic Time O(log n)\n";
    std::cout << "F(" << N << ") = " << fibonacci_log(N) << '\n';


    auto end_log = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed_log = end_log - start_log;
    std::cout << "Logarithmic time elapsed: " << elapsed_log.count() << " ms\n\n";


    return 0;
}
