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


//2 Hàm tính tổng các phần tử có chữ số đầu là chữ số lẻ
int sumElementsWithOddLeadingDigit(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        int leadingDigit = abs(num);
        while (leadingDigit >= 10) {
            leadingDigit /= 10;
        }
        if (leadingDigit % 2 != 0) {
            sum += num;
        }
    }
    return sum;
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
    // 2. Tính tổng các phần tử có chữ số đầu là chữ số lẻ
    int sum = sumElementsWithOddLeadingDigit(arr);
    cout << "Tong cac phan tu co chu so dau la le: " << sum << endl;

    _getch();
    return 0;
};