#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo;  // Memoization to store calculated values

// Hàm đệ quy tính giá trị của A_n
int A_recursive(int n) {
    if (memo.find(n) != memo.end()) return memo[n];  // Kiểm tra nếu giá trị đã được tính toán

    if (n == 1) return memo[n] = 1;  // Trường hợp cơ bản

    if (n % 2 == 0) {
        int k = n / 2;
        memo[n] = k + A_recursive(k) + 2;
    }
    else {
        int k = n / 2;
        memo[n] = k * k + A_recursive(k) * A_recursive(k + 1) + 1;
    }

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

    int result = A_recursive(n);
    cout << "Gia tri A(" << n << ") la: " << result << endl;

    return 0;
}
