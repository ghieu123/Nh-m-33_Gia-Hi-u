#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <string>
#include <conio.h>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm liệt kê số nguyên tố nhỏ hơn n
void listPrimesLessThanN(int n) {
    vector<int> primes;
    for (int i = 2; i < n; ++i) {
        if (isPrime(i)) primes.push_back(i);
    }
    if (primes.empty()) {
        cout << "Khong co so nguyen to nao nho hon  " << n << endl;
    }
    else {
        cout << "So nguyen to nho hon n " << n << ": ";
        for (int prime : primes) {
            cout << prime << " ";
        }
        cout << endl;
    }
}


//6 Hàm tìm số nhỏ thứ 2 trong mảng
int findSecondSmallest(vector<int>& arr) {
    if (arr.size() < 2) throw runtime_error("Mang phai co it nhat 2 phan tu.");

    int first = INT_MAX, second = INT_MAX;
    for (int num : arr) {
        if (num < first) {
            second = first;
            first = num;
        }
        else if (num > first && num < second) {
            second = num;
        }
    }
    if (second == INT_MAX) throw runtime_error("Khong co phan tu nho thu 2.");
    return second;
}

int main() {
    vector<int> arr;
    int n;

    // Nhập số nguyên n
    cout << "Nhap so n: ";
    cin >> n;

    // Nhập mảng
    cout << "Nhap so phan tu trong mang: ";
    int size;
    cin >> size;
    arr.resize(size);
    cout << "Nhap cac phan tu cua mang: ";
    for (int& num : arr) {
        cin >> num;
    }

    // 1. Liệt kê số nguyên tố nhỏ hơn n
    listPrimesLessThanN(n);
    // 6. Tìm số nhỏ thứ 2 trong mảng
    try {
        int secondSmallest = findSecondSmallest(arr);
        cout << "Tim so nho thu 2 trong mang: " << secondSmallest << endl;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    _getch();
    return 0;
};