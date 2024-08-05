#include <iostream>
#include <vector>
#include <stdexcept>  // Thư viện cho ngoại lệ chuẩn

using namespace std;

void divideArrays(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) {
        throw invalid_argument("Kich thuoc cua 2 mang khong bang nhau.");
    }

    for (size_t i = 0; i < a.size(); ++i) {
        if (b[i] == 0) {
            cout << "Phep chia " << a[i] << " / " << b[i] << " khong hop le (chia cho 0)" << endl;
        }
        else {
            cout << "Ket qua cua Phep chia" << a[i] << " / " << b[i] << " = " << static_cast<double>(a[i]) / b[i] << endl;
        }
    }
}

int main() {
    vector<int> a, b;
    int n, temp;

    cout << "Nhap so luong cua phan tu mang a va b: ";
    cin >> n;

    cout << "Nhap cac phan tu cua mang a: ";
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        a.push_back(temp);
    }

    cout << "Nhap cac phan tu cua mang b: ";
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        b.push_back(temp);
    }

    try {
        divideArrays(a, b);
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
