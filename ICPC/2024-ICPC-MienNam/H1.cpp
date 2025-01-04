#include <iostream>
using namespace std;

// Extended Euclidean Algorithm to find the modular inverse
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Function to find the modular inverse of a number a mod M
long long mod_inverse(long long a, long long M) {
    long long x, y;
    long long g = extended_gcd(a, M, x, y);
    if (g != 1) {
        // If gcd(a, M) != 1, inverse doesn't exist
        return -1;
    } else {
        // Ensure x is positive
        return (x % M + M) % M;
    }
}

// Function to compute the sum of squares from 1^2 to n^2 mod M
long long sum_of_squares_mod(long long n, long long M) {
    if (n == 0) return 0;  // Special case for n = 0
    // Using the formula: (n * (n + 1) * (2n + 1)) / 6 % M
    long long sum = n % M;
    sum = (sum * (n + 1) % M) % M;
    sum = (sum * (2 * n + 1) % M) % M;

    // Modular inverse of 6 mod M
    long long inv_6 = mod_inverse(6, M);
    if (inv_6 == -1) {
        // If inverse doesn't exist, return an error
        cout << "Modular inverse of 6 does not exist under mod " << M << endl;
        return -1;
    }

    sum = (sum * inv_6) % M;
    return sum;
}

// Function to compute sum from l^2 to r^2 mod M
long long sum_range_squares_mod(long long l, long long r, long long M) {
    long long sum_r = sum_of_squares_mod(r, M);
    long long sum_l_minus_1 = sum_of_squares_mod(l - 1, M);
    return (sum_r - sum_l_minus_1 + M) % M;  // Ensure non-negative result
}

int main() {
    long long l, r, M;
    cin >> l >> r >> M;
    cout << sum_range_squares_mod(l, r, M) << endl;
    return 0;
}
