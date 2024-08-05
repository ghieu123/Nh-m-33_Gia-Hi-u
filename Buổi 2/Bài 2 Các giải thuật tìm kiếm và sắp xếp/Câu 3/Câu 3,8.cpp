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


//8 Hàm sắp xếp mảng: các phần tử chẵn tăng dần, các phần tử lẻ giữ nguyên vị trí
void sortEvenAscendingRetainOddPositions(vector<int>& arr) {
    vector<int> evens;
    for (int num : arr) {
        if (num % 2 == 0) {
            evens.push_back(num);
        }
    }
    sort(evens.begin(), evens.end());

    int evenIndex = 0;
    for (int& num : arr) {
        if (num % 2 == 0) {
            num = evens[evenIndex++];
        }
    }
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
    // 8. Sắp xếp mảng: các phần tử chẵn tăng dần, các phần tử lẻ giữ nguyên vị trí
    vector<int> sortedEvenRetainOdd = arr;
    sortEvenAscendingRetainOddPositions(sortedEvenRetainOdd);
    cout << "Mang duoc sap xep(Chan tang dan, phan tu le giu nguyen): ";
    for (int num : sortedEvenRetainOdd) {
        cout << num << " ";
    }
    cout << endl;

    _getch();
    return 0;
};