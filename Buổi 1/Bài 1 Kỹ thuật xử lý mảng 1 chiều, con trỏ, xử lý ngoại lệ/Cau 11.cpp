#include <iostream>
#include <cstdlib> // Để sử dụng rand()
#include <ctime>   // Để sử dụng time()
using namespace std;

// Hàm nhập mảng 1 chiều số nguyên
void nhapM1C_SoNguyen(int*& a, int& n) {
    n = 10;
    a = new int[n]; // Cấp phát mảng với 10 phần tử
    srand(time(0)); // Đặt seed cho hàm rand
    for (int i = 0; i < n; i++) {
        *(a + i) = rand() % 100;
    }
}

// Hàm xuất mảng 1 chiều số nguyên
void xuatM1C_SoNguyen(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %p", i, *(a + i), (a + i));
    }
    cout << endl;
}

// Hàm xuất các số cực tiểu trong mảng
void xuatCucTieu(int* a, int n) {
    cout << "Cac so cuc tieu trong mang: ";
    if (n > 1 && a[0] < a[1]) {
        cout << a[0] << " ";
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            cout << a[i] << " ";
        }
    }
    if (n > 1 && a[n - 1] < a[n - 2]) {
        cout << a[n - 1] << " ";
    }
    cout << endl;
}

// Hàm xóa phần tử tại vị trí k
void xoaPhanTu(int*& a, int& n, int k) {
    if (k < 0 || k >= n) {
        cout << "Vi tri k khong hop le!" << endl;
        return;
    }
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
}

// Hàm thêm phần tử x tại vị trí k
void themPhanTu(int*& a, int& n, int x, int k) {
    if (k < 0 || k > n) {
        cout << "Vi tri k khong hop le!" << endl;
        return;
    }
    int* b = new int[n + 1];
    for (int i = 0; i < k; i++) {
        b[i] = a[i];
    }
    b[k] = x;
    for (int i = k; i < n; i++) {
        b[i + 1] = a[i];
    }
    delete[] a;
    a = b;
    n++;
}

// Hàm chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
void chuyenChanLe(int*& a, int n) {
    int* b = new int[n];
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            b[index++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            b[index++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
    delete[] b;
}

// Hàm kiểm tra mảng có chứa chẵn lẻ xen kẽ không
bool kiemTraXenKe(int* a, int n) {
    for (int i = 1; i < n; i++) {
        if ((a[i] % 2 == 0 && a[i - 1] % 2 == 0) || (a[i] % 2 != 0 && a[i - 1] % 2 != 0)) {
            return false;
        }
    }
    return true;
}

int main() {
    int* a, n = 0;
    nhapM1C_SoNguyen(a, n);
    xuatM1C_SoNguyen(a, n);

    cout << endl;

    // Xuất các số cực tiểu
    xuatCucTieu(a, n);

    // Xóa phần tử tại vị trí k
    int k = 3;
    xoaPhanTu(a, n, k);
    cout << "Mang sau khi xoa phan tu tai vi tri " << k << ": ";
    xuatM1C_SoNguyen(a, n);

    // Thêm phần tử x tại vị trí k
    int x = 50;
    k = 2;
    themPhanTu(a, n, x, k);
    cout << "Mang sau khi them phan tu " << x << " tai vi tri " << k << ": ";
    xuatM1C_SoNguyen(a, n);

    // Chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
    chuyenChanLe(a, n);
    cout << "Mang sau khi chuyen so chan len dau va so le xuong cuoi: ";
    xuatM1C_SoNguyen(a, n);

    // Kiểm tra mảng có chứa chẵn lẻ xen kẽ không
    bool xenKe = kiemTraXenKe(a, n);
    cout << "Mang co chua chan le xen ke: " << (xenKe ? "Co" : "Khong") << endl;

    delete[] a; // Giải phóng bộ nhớ đã cấp phát
    return 0;
}
