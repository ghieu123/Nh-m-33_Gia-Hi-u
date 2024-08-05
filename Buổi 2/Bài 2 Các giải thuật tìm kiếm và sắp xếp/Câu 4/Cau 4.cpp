#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Sử dụng std::gcd thay vì std::__gcd
#include <cmath>

using namespace std;

struct MixedNumber {
    int whole; // phần nguyên
    int numerator; // tử số
    int denominator; // mẫu số
};

// 1. Tìm hỗn số x trong mảng b theo giải thuật Linear Search
int linearSearch(const vector<MixedNumber>& b, const MixedNumber& x) {
    for (size_t i = 0; i < b.size(); ++i) {
        if (b[i].whole == x.whole && b[i].numerator == x.numerator && b[i].denominator == x.denominator) {
            return i;
        }
    }
    return -1;
}

// 2. Sắp xếp b sao cho các phần tử có phần nguyên chẵn lên đầu, phần tử có phần nguyên lẻ ở cuối mảng
void sortMixedNumbers(vector<MixedNumber>& b) {
    stable_partition(b.begin(), b.end(), [](const MixedNumber& x) {
        return x.whole % 2 == 0;
        });
}

// Helper function to compare two MixedNumbers
bool mixedNumberLessThan(const MixedNumber& a, const MixedNumber& b) {
    double valA = a.whole + static_cast<double>(a.numerator) / a.denominator;
    double valB = b.whole + static_cast<double>(b.numerator) / b.denominator;
    return valA < valB;
}

// 3. Tìm hỗn số x theo giải thuật binary search trong mảng b đã được sắp xếp tăng/giảm
int binarySearch(const vector<MixedNumber>& b, const MixedNumber& x) {
    int left = 0, right = b.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        double midValue = b[mid].whole + static_cast<double>(b[mid].numerator) / b[mid].denominator;
        double xValue = x.whole + static_cast<double>(x.numerator) / x.denominator;

        if (midValue == xValue) {
            return mid;
        }
        else if (midValue < xValue) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// 4. Chia mảng b thành 2 mảng s1 và s2, với s1 chứa các phần nguyên, s2 chứa phân số
void splitMixedNumbers(const vector<MixedNumber>& b, vector<int>& s1, vector<pair<int, int>>& s2) {
    for (const auto& num : b) {
        s1.push_back(num.whole);
        s2.emplace_back(num.numerator, num.denominator);
    }
}

// 5. Xóa phần tử thứ k trong mảng b
void deleteElementAt(vector<MixedNumber>& b, int k) {
    if (k >= 0 && k < b.size()) {
        b.erase(b.begin() + k);
    }
}

// 6. Thêm hỗn số x vào mảng b tại vị trí k
void insertElementAt(vector<MixedNumber>& b, const MixedNumber& x, int k) {
    if (k >= 0 && k <= b.size()) {
        b.insert(b.begin() + k, x);
    }
}

// 7. Tạo mảng c chứa các phần tử là phân số được đổi từ các phần tử hỗn số của mảng b
vector<pair<int, int>> convertToFractions(const vector<MixedNumber>& b) {
    vector<pair<int, int>> c;
    for (const auto& num : b) {
        int numerator = num.whole * num.denominator + num.numerator;
        c.emplace_back(numerator, num.denominator);
    }
    return c;
}



// 9. Tìm phần tử lớn nhất/nhỏ nhất của b
MixedNumber findMaxMixedNumber(const vector<MixedNumber>& b) {
    return *max_element(b.begin(), b.end(), mixedNumberLessThan);
}

MixedNumber findMinMixedNumber(const vector<MixedNumber>& b) {
    return *min_element(b.begin(), b.end(), mixedNumberLessThan);
}

// 10. Xuất vị trí phần tử có phần nguyên chẵn của b
void printEvenWholeIndices(const vector<MixedNumber>& b) {
    for (size_t i = 0; i < b.size(); ++i) {
        if (b[i].whole % 2 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// 11. Xuất vị trí của phần tử lớn nhất/nhỏ nhất của b
int findMaxElementIndex(const vector<MixedNumber>& b) {
    auto maxElement = max_element(b.begin(), b.end(), mixedNumberLessThan);
    return distance(b.begin(), maxElement);
}

int findMinElementIndex(const vector<MixedNumber>& b) {
    auto minElement = min_element(b.begin(), b.end(), mixedNumberLessThan);
    return distance(b.begin(), minElement);
}

int main() {
    vector<MixedNumber> b = { {1, 2, 3}, {2, 1, 3}, {1, 1, 2}, {0, 3, 4} };
    MixedNumber x = { 1, 1, 2 };

    // 1. Tìm hỗn số x trong mảng b theo giải thuật Linear Search
    int index = linearSearch(b, x);
    cout << "1: Tim x trong mang b: " << index << endl;

    // 2. Sắp xếp b sao cho các phần tử có phần nguyên chẵn lên đầu, phần tử có phần nguyên lẻ ở cuối mảng
    sortMixedNumbers(b);
    cout << "2: Sap xep cac pt co phan nguyen chan len dau(le o cuoi man:" << endl;
    for (const auto& num : b) {
        cout << "{" << num.whole << ", " << num.numerator << ", " << num.denominator << "} ";
    }
    cout << endl;

    // 3. Tìm hỗn số x theo giải thuật binary search trong mảng b đã được sắp xếp tăng/giảm
    sort(b.begin(), b.end(), mixedNumberLessThan);
    index = binarySearch(b, x);
    cout << "3: Tim ho so x theo thuat toan binary search  : " << index << endl;

    // 4. Chia mảng b thành 2 mảng s1 và s2, với s1 chứa các phần nguyên, s2 chứa phân số
    vector<int> s1;
    vector<pair<int, int>> s2;
    splitMixedNumbers(b, s1, s2);
    cout << "4: s1 Phan nguyen: ";
    for (int whole : s1) {
        cout << whole << " ";
    }
    cout << "\n4: s2 Phan so: ";
    for (const auto& frac : s2) {
        cout << "{" << frac.first << ", " << frac.second << "} ";
    }
    cout << endl;

    // 5. Xóa phần tử thứ k trong mảng b
    int k = 2;
    deleteElementAt(b, k);
    cout << "5: Mang sau khi xoa " << k << ": ";
    for (const auto& num : b) {
        cout << "{" << num.whole << ", " << num.numerator << ", " << num.denominator << "} ";
    }
    cout << endl;

    // 6. Thêm hỗn số x vào mảng b tại vị trí k
    insertElementAt(b, x, k);
    cout << "6: Them hon so vao mang tai vi tri k " << k << ": ";
    for (const auto& num : b) {
        cout << "{" << num.whole << ", " << num.numerator << ", " << num.denominator << "} ";
    }
    cout << endl;

    // 7. Tạo mảng c chứa các phần tử là phân số được đổi từ các phần tử hỗn số của mảng b
    vector<pair<int, int>> c = convertToFractions(b);
    cout << "7: Phan so da chuyen doi: ";
    for (const auto& frac : c) {
        cout << "{" << frac.first << ", " << frac.second << "} ";
    }
    cout << endl;


    // 9. Tìm phần tử lớn nhất/nhỏ nhất của b
    MixedNumber maxElement = findMaxMixedNumber(b);
    MixedNumber minElement = findMinMixedNumber(b);
    cout << "9: Phan tu lon nhat: {" << maxElement.whole << ", " << maxElement.numerator << ", " << maxElement.denominator << "}" << endl;
    cout << "9: Phan tu nho nhat: {" << minElement.whole << ", " << minElement.numerator << ", " << minElement.denominator << "}" << endl;

    // 10. Xuất vị trí phần tử có phần nguyên chẵn của b
    cout << "10: Xuat vi tri phan tu co phan nguyen chan: ";
    printEvenWholeIndices(b);

    // 11. Xuất vị trí của phần tử lớn nhất/nhỏ nhất của b
    int maxIndex = findMaxElementIndex(b);
    int minIndex = findMinElementIndex(b);
    cout << "11: Vi tri cac phan tu lon nhat: " << maxIndex << endl;
    cout << "11: Vi tri cac phan tu nho nhat: " << minIndex << endl;

    return 0;
}
