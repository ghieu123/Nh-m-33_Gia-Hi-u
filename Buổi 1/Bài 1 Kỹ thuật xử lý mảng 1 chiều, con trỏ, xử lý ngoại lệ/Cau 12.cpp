#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Phân số
struct PhanSo {
    int tu;  // Tử số
    int mau; // Mẫu số
};

// Hàm nhập một phân số
void nhapPhanSo(PhanSo& ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    do {
        cout << "Nhap mau so (khac 0): ";
        cin >> ps.mau;
        if (ps.mau == 0) {
            cout << "Mau so phai khac 0. Vui long nhap lai." << endl;
        }
    } while (ps.mau == 0);
}

// Hàm xuất một phân số
void xuatPhanSo(const PhanSo& ps) {
    cout << ps.tu << "/" << ps.mau;
}

// Hàm nhập mảng phân số
void nhapMangPhanSo(PhanSo*& a, int& n) {
    cout << "Nhap so luong phan so: ";
    cin >> n;
    a = new PhanSo[n];
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ":" << endl;
        nhapPhanSo(a[i]);
    }
}

// Hàm xuất mảng phân số
void xuatMangPhanSo(PhanSo* a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Phan so thu " << i + 1 << ": ";
        xuatPhanSo(a[i]);
        cout << endl;
    }
}

// Hàm xuất các phân số có mẫu > tử
void xuatPhanSoMauLonHonTu(PhanSo* a, int n) {
    cout << "Cac phan so co mau > tu: ";
    for (int i = 0; i < n; ++i) {
        if (a[i].mau > a[i].tu) {
            xuatPhanSo(a[i]);
            cout << " ";
        }
    }
    cout << endl;
}

// Hàm đếm các phân số có mẫu và tử đều chẵn
int demPhanSoMauTuChan(PhanSo* a, int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].tu % 2 == 0 && a[i].mau % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Hàm tìm ước chung lớn nhất (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm rút gọn phân số
void rutGonPhanSo(PhanSo& ps) {
    int ucln = gcd(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
}

// Hàm tính tích các phân số trong mảng
PhanSo tinhTich(PhanSo* a, int n) {
    PhanSo tich = { 1, 1 };
    for (int i = 0; i < n; ++i) {
        tich.tu *= a[i].tu;
        tich.mau *= a[i].mau;
        rutGonPhanSo(tich);
    }
    return tich;
}

// Hàm tìm phân số lớn nhất
PhanSo timPhanSoLonNhat(PhanSo* a, int n) {
    PhanSo max = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i].tu * max.mau > max.tu * a[i].mau) {
            max = a[i];
        }
    }
    return max;
}

// Hàm tìm phân số nhỏ nhất
PhanSo timPhanSoNhoNhat(PhanSo* a, int n) {
    PhanSo min = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i].tu * min.mau < min.tu * a[i].mau) {
            min = a[i];
        }
    }
    return min;
}

// Hàm xóa phần tử tại vị trí k
void xoaPhanTu(PhanSo*& a, int& n, int k) {
    if (k < 0 || k >= n) {
        cout << "Vi tri k khong hop le!" << endl;
        return;
    }
    for (int i = k; i < n - 1; ++i) {
        a[i] = a[i + 1];
    }
    n--;
}

// Hàm thêm phần tử x tại vị trí k
void themPhanTu(PhanSo*& a, int& n, PhanSo x, int k) {
    if (k < 0 || k > n) {
        cout << "Vi tri k khong hop le!" << endl;
        return;
    }
    PhanSo* b = new PhanSo[n + 1];
    for (int i = 0; i < k; ++i) {
        b[i] = a[i];
    }
    b[k] = x;
    for (int i = k; i < n; ++i) {
        b[i + 1] = a[i];
    }
    delete[] a;
    a = b;
    n++;
}

int main() {
    int n;
    PhanSo* a;

    // Nhập mảng phân số
    nhapMangPhanSo(a, n);

    // Xuất mảng phân số
    xuatMangPhanSo(a, n);

    // Xuất các phân số có mẫu > tử
    xuatPhanSoMauLonHonTu(a, n);

    // Đếm số phân số có mẫu và tử chẵn
    int count = demPhanSoMauTuChan(a, n);
    cout << "So phan so co mau va tu chan: " << count << endl;

    // Tính tích các phân số trong mảng
    PhanSo tich = tinhTich(a, n);
    cout << "Tich cac phan so trong mang: ";
    xuatPhanSo(tich);
    cout << endl;

    // Tìm phân số lớn nhất
    PhanSo max = timPhanSoLonNhat(a, n);
    cout << "Phan so lon nhat: ";
    xuatPhanSo(max);
    cout << endl;

    // Tìm phân số nhỏ nhất
    PhanSo min = timPhanSoNhoNhat(a, n);
    cout << "Phan so nho nhat: ";
    xuatPhanSo(min);
    cout << endl;

    // Xóa phần tử tại vị trí k
    int k;
    cout << "Nhap vi tri k can xoa: ";
    cin >> k;
    xoaPhanTu(a, n, k);
    cout << "Mang sau khi xoa phan tu tai vi tri " << k << ": ";
    xuatMangPhanSo(a, n);

    // Thêm phần tử x tại vị trí k
    PhanSo x;
    cout << "Nhap phan so can them:" << endl;
    nhapPhanSo(x);
    cout << "Nhap vi tri k can them: ";
    cin >> k;
    themPhanTu(a, n, x, k);
    cout << "Mang sau khi them phan tu: ";
    xuatMangPhanSo(a, n);

    delete[] a; // Giải phóng bộ nhớ đã cấp phát
    return 0;
}

