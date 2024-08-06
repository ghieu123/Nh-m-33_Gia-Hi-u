#include <iostream>

using namespace std;

// Hàm tính số Fibonacci thứ n
int fibonacci(int n) {
    if (n <= 2) return 1;
    int a = 1, b = 1, c;
    for (int i = 3; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Hàm đệ quy tìm số Fibonacci lớn nhất nhưng nhỏ hơn n
int largestFibonacciRecursive(int n, int a = 1, int b = 1) {
    if (b >= n) return a;
    return largestFibonacciRecursive(n, b, a + b);
}

// Hàm khử đệ quy tìm số Fibonacci lớn nhất nhưng nhỏ hơn n
int largestFibonacciIterative(int n) {
    if (n <= 1) return 0; // không có số Fibonacci nào nhỏ hơn 1
    int a = 1, b = 1;
    while (b < n) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int resultRecursive = largestFibonacciRecursive(n);
    int resultIterative = largestFibonacciIterative(n);

    cout << "So Fibonacci lon nhat nho hon " << n << " (de quy): " << resultRecursive << endl;
    cout << "So Fibonacci lon nhat nho hon " << n << " (khu de quy): " << resultIterative << endl;

    return 0;
}

