﻿#include <iostream>
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


//5 Hàm tìm dãy con giảm dài nhất
vector<int> longestDecreasingSubsequence(const vector<int>& arr) {
    if (arr.empty()) return {};

    vector<int> lds;
    vector<int> temp;

    for (int i = 0; i < arr.size(); ++i) {
        if (temp.empty() || arr[i] < temp.back()) {
            temp.push_back(arr[i]);
        }
        else {
            if (temp.size() > lds.size()) {
                lds = temp;
            }
            temp.clear();
            temp.push_back(arr[i]);
        }
    }
    if (temp.size() > lds.size()) {
        lds = temp;
    }

    return lds;
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
    // 5. Tìm dãy con giảm dài nhất
    vector<int> lds = longestDecreasingSubsequence(arr);
    cout << "Tim day con giam dai nhat: ";
    for (int num : lds) {
        cout << num << " ";
    }
    cout << endl;

    _getch();
    return 0;
};