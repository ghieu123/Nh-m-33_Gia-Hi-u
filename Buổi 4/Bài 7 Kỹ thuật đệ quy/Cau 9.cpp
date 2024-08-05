#include <iostream>
#include <cmath>

// Biểu thức 1: Đệ quy
double S1_recursive(int n) {
    if (n == 1)
        return 1.0 / (1 * 2 * 3);
    return 1.0 / (n * (n + 1) * (n + 2)) + S1_recursive(n - 1);
}

// Biểu thức 1: Khử đệ quy
double S1_iterative(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / (i * (i + 1) * (i + 2));
    }
    return sum;
}

// Biểu thức 2: Đệ quy
int S2_recursive(int n) {
    if (n == 1)
        return 1;
    return n * n + S2_recursive(n - 1);
}

// Biểu thức 2: Khử đệ quy
int S2_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i * i;
    }
    return sum;
}

// Hàm tính tổng của 1 đến n
int sum_first_n_numbers(int n) {
    if (n == 1)
        return 1;
    return n + sum_first_n_numbers(n - 1);
}

// Biểu thức 3: Đệ quy
int S3_recursive(int n) {
    if (n == 1)
        return 1;
    return sum_first_n_numbers(n) + S3_recursive(n - 1);
}

// Biểu thức 3: Khử đệ quy
int S3_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i * (i + 1) / 2;
    }
    return sum;
}

// Hàm tính giai thừa
double factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Biểu thức 4: Đệ quy
double S4_recursive(int n) {
    if (n == 1)
        return -(1 + 2) / factorial(2);
    return pow(-1, n) * ((2 * n - 1) + 2 * n) / factorial(2 * n) + S4_recursive(n - 1);
}

// Biểu thức 4: Khử đệ quy
double S4_iterative(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += pow(-1, i) * ((2 * i - 1) + 2 * i) / factorial(2 * i);
    }
    return sum;
}

int main() {
    int n;
    std::cout << "Nhap so nguyen duong n: ";
    std::cin >> n;

    std::cout << "S1 (de quy): " << S1_recursive(n) << std::endl;
    std::cout << "S1 (khu de quy): " << S1_iterative(n) << std::endl;

    std::cout << "S2 (de quy): " << S2_recursive(n) << std::endl;
    std::cout << "S2 (khu de quy): " << S2_iterative(n) << std::endl;

    std::cout << "S3 (de quy): " << S3_recursive(n) << std::endl;
    std::cout << "S3 (khu de quy): " << S3_iterative(n) << std::endl;

    std::cout << "S4 (de quy): " << S4_recursive(n) << std::endl;
    std::cout << "S4 (khu de quy): " << S4_iterative(n) << std::endl;

    return 0;
}
