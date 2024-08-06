#include <iostream>
#include <vector>

using namespace std;

// Hàm đệ quy trực tiếp để tính Yn
int Y_recursive(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    return Y_recursive(n - 1) + 2 * Y_recursive(n - 2) + 3 * Y_recursive(n - 3);
}

// Hàm đệ quy có memoization để tính Yn
int Y_memoization(int n, vector<int>& memo) {
    if (memo[n] != -1) return memo[n];
    if (n == 1) return memo[n] = 1;
    if (n == 2) return memo[n] = 2;
    if (n == 3) return memo[n] = 3;
    memo[n] = Y_memoization(n - 1, memo) + 2 * Y_memoization(n - 2, memo) + 3 * Y_memoization(n - 3, memo);
    return memo[n];
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n phai la so nguyen duong." << endl;
        return 1;
    }

    // Đệ quy trực tiếp
    int result_recursive = Y_recursive(n);
    cout << "Gia tri Y(" << n << ") (de quy): " << result_recursive << endl;

    // Đệ quy có memoization
    vector<int> memo(n + 1, -1);
    int result_memoization = Y_memoization(n, memo);
    cout << "Gia tri Y(" << n << ") (memoization): " << result_memoization << endl;

    return 0;
}
