#include <iostream>
#include <vector>

using namespace std;

// Hàm tính giá trị U(n) bằng đệ quy
int U_recursive(int n, vector<int>& memo) {
    if (n < 6) return n;
    if (memo[n] != -1) return memo[n]; // Trả về giá trị đã lưu nếu đã tính toán
    memo[n] = U_recursive(n - 5, memo) + U_recursive(n - 4, memo) +
        U_recursive(n - 3, memo) + U_recursive(n - 2, memo) +
        U_recursive(n - 1, memo);
    return memo[n];
}

// Hàm tính giá trị U(n) bằng khử đệ quy
int U_iterative(int n) {
    if (n < 6) return n;
    vector<int> U(n + 1);
    for (int i = 0; i < 6; ++i) {
        U[i] = i;
    }
    for (int i = 6; i <= n; ++i) {
        U[i] = U[i - 5] + U[i - 4] + U[i - 3] + U[i - 2] + U[i - 1];
    }
    return U[n];
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    // Đệ quy
    vector<int> memo(n + 1, -1);
    int result_recursive = U_recursive(n, memo);
    cout << "Gia tri U(n) (de quy): " << result_recursive << endl;

    // Khử đệ quy
    int result_iterative = U_iterative(n);
    cout << "Gia tri U(n) (khu de quy): " << result_iterative << endl;

    return 0;
}
