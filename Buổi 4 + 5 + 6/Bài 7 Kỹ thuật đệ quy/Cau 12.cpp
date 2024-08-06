#include <iostream>
#include <vector>

using namespace std;

// Hàm tính số hạng thứ n của dãy x và y bằng đệ quy
pair<int, int> calculate_recursive(int n, vector<int>& x, vector<int>& y) {
    if (n == 0) {
        x[n] = 1;
        y[n] = 0;
        return { x[n], y[n] };
    }
    if (x[n] != -1 && y[n] != -1) {
        return { x[n], y[n] };
    }
    auto prev = calculate_recursive(n - 1, x, y);
    x[n] = prev.first + prev.second;
    y[n] = 3 * prev.first + 2 * prev.second;
    return { x[n], y[n] };
}

// Hàm tính số hạng thứ n của dãy x và y bằng khử đệ quy
pair<int, int> calculate_iterative(int n) {
    int x_prev = 1, y_prev = 0;
    if (n == 0) return { x_prev, y_prev };
    int x_curr, y_curr;
    for (int i = 1; i <= n; ++i) {
        x_curr = x_prev + y_prev;
        y_curr = 3 * x_prev + 2 * y_prev;
        x_prev = x_curr;
        y_prev = y_curr;
    }
    return { x_curr, y_curr };
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    // Đệ quy
    vector<int> x(n + 1, -1), y(n + 1, -1);
    auto result_recursive = calculate_recursive(n, x, y);
    cout << "Ket qua de quy: x_" << n << " = " << result_recursive.first
        << ", y_" << n << " = " << result_recursive.second << endl;

    // Khử đệ quy
    auto result_iterative = calculate_iterative(n);
    cout << "Ket qua khu de quy: x_" << n << " = " << result_iterative.first
        << ", y_" << n << " = " << result_iterative.second << endl;

    return 0;
}

