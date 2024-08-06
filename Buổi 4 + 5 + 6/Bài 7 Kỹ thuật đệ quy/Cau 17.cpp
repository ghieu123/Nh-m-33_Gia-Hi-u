#include <iostream>

using namespace std;

// Hàm đệ quy tính giá trị của X_n
int X_recursive(int n) {
    if (n == 1 || n == 2) return 1;  // Trường hợp cơ bản
    return X_recursive(n - 1) + (n - 1) * X_recursive(n - 2);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n phai la so nguyen duong." << endl;
        return 1;
    }

    int result = X_recursive(n);
    cout << "Gia tri X(" << n << ") la: " << result << endl;

    return 0;
}

