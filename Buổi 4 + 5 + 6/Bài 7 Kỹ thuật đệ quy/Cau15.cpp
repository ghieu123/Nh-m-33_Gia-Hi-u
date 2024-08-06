#include <iostream>
#include <vector>

using namespace std;

// Hàm tính giá trị của A_n
int calculate_A_n(int n) {
    if (n == 1) return 1;

    vector<int> A(n + 1, 0);
    A[1] = 1;

    int sum = A[1]; // Tổng của các phần tử từ A1 đến A(n-1)
    for (int i = 2; i <= n; ++i) {
        A[i] = i * sum;
        sum += A[i];
    }

    return A[n];
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n phai la so nguyen duong." << endl;
        return 1;
    }

    int result = calculate_A_n(n);
    cout << "Gia tri cua A_" << n << " la: " << result << endl;

    return 0;
}
