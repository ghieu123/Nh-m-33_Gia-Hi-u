#include <iostream>

using namespace std;

// Hàm tính giá trị phần tử thứ n của cấp số nhân bằng đệ quy
double geometric_sequence_recursive(double a, double q, int n) {
    if (n == 1) return a;
    return q * geometric_sequence_recursive(a, q, n - 1);
}

// Hàm tính giá trị phần tử thứ n của cấp số nhân bằng khử đệ quy
double geometric_sequence_iterative(double a, double q, int n) {
    double result = a;
    for (int i = 1; i < n; ++i) {
        result *= q;
    }
    return result;
}

int main() {
    double a, q;
    int n;

    cout << "Nhap gia tri a (so hang dau tien): ";
    cin >> a;
    cout << "Nhap gia tri q (cong boi): ";
    cin >> q;
    cout << "Nhap n (so thu tu cua phan tu): ";
    cin >> n;

    // Đệ quy
    double result_recursive = geometric_sequence_recursive(a, q, n);
    cout << "Gia tri phan tu thu " << n << " (de quy): " << result_recursive << endl;

    // Khử đệ quy
    double result_iterative = geometric_sequence_iterative(a, q, n);
    cout << "Gia tri phan tu thu " << n << " (khu de quy): " << result_iterative << endl;

    return 0;
}

