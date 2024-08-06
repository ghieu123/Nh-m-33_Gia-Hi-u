#include <iostream>
#include <vector>

using namespace std;

// Hàm đệ quy có memoization tính giá trị của x_n
int x_recursive(int n, vector<int>& memo) {
    // Nếu giá trị đã được tính toán, trả về giá trị đó
    if (memo[n] != -1) return memo[n];

    // Trường hợp cơ bản
    if (n == 0) return memo[n] = 1;
    if (n == 1) return memo[n] = 2;

    // Tính giá trị của x_n
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (n - i) * x_recursive(i, memo);
    }
    return memo[n] = sum;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n < 0) {
        cout << "n phai la so nguyen khong am." << endl;
        return 1;
    }

    // Khởi tạo mảng memo để lưu trữ các giá trị đã tính
    vector<int> memo(n + 1, -1);

    int result = x_recursive(n, memo);
    cout << "Gia tri x(" << n << ") la: " << result << endl;

    return 0;
}
