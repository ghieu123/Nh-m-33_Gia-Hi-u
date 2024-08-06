#include <iostream>
#include <vector>

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

// Hàm tìm các số Fibonacci thuộc đoạn [m, n]
vector<int> fibonacci_in_range(int m, int n) {
    vector<int> result;
    int i = 1;
    int fib = fibonacci(i);
    while (fib <= n) {
        if (fib >= m) {
            result.push_back(fib);
        }
        ++i;
        fib = fibonacci(i);
    }
    return result;
}

// Hàm xuất các số Fibonacci thuộc đoạn [m, n]
void print_fibonacci_in_range(int m, int n) {
    vector<int> fibs = fibonacci_in_range(m, n);
    if (fibs.empty()) {
        cout << "Khong co so Fibonacci nao thuoc doan [" << m << ", " << n << "]." << endl;
    }
    else {
        cout << "Cac so Fibonacci thuoc doan [" << m << ", " << n << "]: ";
        for (int fib : fibs) {
            cout << fib << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;

    print_fibonacci_in_range(m, n);

    return 0;
}

