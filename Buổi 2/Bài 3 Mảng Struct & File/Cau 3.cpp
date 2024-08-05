#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <conio.h>

using namespace std;

struct KhachHang {
    string hoTen;
    string soDienThoai;
    int soVeNguoiLon;
    int soVeTreEm;
    string tenPhim;
    string phongChieu;
    string xuatChieu;
    int tienPhaiTra;
};

vector<KhachHang> dskh;

void docDanhSachKhachHang(const string& filename, vector<KhachHang>& dskh) {
    ifstream file(filename);
    if (file.is_open()) {
        KhachHang kh;
        while (file >> kh.hoTen >> kh.soDienThoai >> kh.soVeNguoiLon >> kh.soVeTreEm
            >> kh.tenPhim >> kh.phongChieu >> kh.xuatChieu) {
            kh.tienPhaiTra = kh.soVeNguoiLon * 40000 + kh.soVeTreEm * 20000;
            dskh.push_back(kh);
        }
        file.close();
    }
    else {
        cerr << "Khong the mo file " << filename << endl;
    }
}

void xuatDanhSachKhachHang(const vector<KhachHang>& dskh) {
    for (const auto& kh : dskh) {
        cout << "Ho Ten: " << kh.hoTen << endl;
        cout << "So Dien Thoai: " << kh.soDienThoai << endl;
        cout << "So Ve Nguoi Lon: " << kh.soVeNguoiLon << endl;
        cout << "So Ve Tre Em: " << kh.soVeTreEm << endl;
        cout << "Ten Phim: " << kh.tenPhim << endl;
        cout << "Phong Chieu: " << kh.phongChieu << endl;
        cout << "Xuat Chieu: " << kh.xuatChieu << endl;
        cout << "Tien Phai Tra: " << kh.tienPhaiTra << endl;
        cout << "-----------------------" << endl;
    }
}

int tinhTongDoanhThu(const vector<KhachHang>& dskh) {
    int tongDoanhThu = 0;
    for (const auto& kh : dskh) {
        tongDoanhThu += kh.tienPhaiTra;
    }
    return tongDoanhThu;
}

void tinhDoanhThuTungPhim(const vector<KhachHang>& dskh) {
    map<string, int> doanhThuPhim;
    for (const auto& kh : dskh) {
        doanhThuPhim[kh.tenPhim] += kh.tienPhaiTra;
    }
    for (const auto& phim : doanhThuPhim) {
        cout << "Phim: " << phim.first << " - Doanh thu: " << phim.second << endl;
    }
}

void xuatThongTinKhachHangTheoPhongVaXuatChieu(const vector<KhachHang>& dskh, const string& phong, const string& xuat) {
    for (const auto& kh : dskh) {
        if (kh.phongChieu == phong && kh.xuatChieu == xuat) {
            cout << "Ho Ten: " << kh.hoTen << endl;
            cout << "So Dien Thoai: " << kh.soDienThoai << endl;
            cout << "So Ve Nguoi Lon: " << kh.soVeNguoiLon << endl;
            cout << "So Ve Tre Em: " << kh.soVeTreEm << endl;
            cout << "Ten Phim: " << kh.tenPhim << endl;
            cout << "Tien Phai Tra: " << kh.tienPhaiTra << endl;
            cout << "-----------------------" << endl;
        }
    }
}

// Bubble sort
void bubbleSort(vector<KhachHang>& dskh) {
    bool swapped;
    for (size_t i = 0; i < dskh.size() - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < dskh.size() - i - 1; j++) {
            if (dskh[j].tienPhaiTra > dskh[j + 1].tienPhaiTra) {
                swap(dskh[j], dskh[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Selection sort
void selectionSort(vector<KhachHang>& dskh) {
    for (size_t i = 0; i < dskh.size() - 1; i++) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < dskh.size(); j++) {
            if (dskh[j].tienPhaiTra < dskh[minIdx].tienPhaiTra) {
                minIdx = j;
            }
        }
        swap(dskh[i], dskh[minIdx]);
    }
}

// Insertion sort
void insertionSort(vector<KhachHang>& dskh) {
    for (size_t i = 1; i < dskh.size(); i++) {
        KhachHang key = dskh[i];
        int j = i - 1;
        while (j >= 0 && dskh[j].tienPhaiTra > key.tienPhaiTra) {
            dskh[j + 1] = dskh[j];
            j--;
        }
        dskh[j + 1] = key;
    }
}

void sapXepTheoHoTen(vector<KhachHang>& dskh) {
    sort(dskh.begin(), dskh.end(), [](const KhachHang& a, const KhachHang& b) {
        return a.hoTen < b.hoTen;
        });
}

bool binarySearchKhachHang(const vector<KhachHang>& dskh, const string& ten) {
    int left = 0;
    int right = dskh.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (dskh[mid].hoTen == ten) {
            return true;
        }
        if (dskh[mid].hoTen < ten) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    // Đọc danh sách khách hàng từ file
    docDanhSachKhachHang("dskh.txt", dskh);

    // Xuất danh sách khách hàng
    xuatDanhSachKhachHang(dskh);

    // Tính và xuất tổng doanh thu
    int tongDoanhThu = tinhTongDoanhThu(dskh);
    cout << "Tong Doanh Thu: " << tongDoanhThu << endl;

    // Tính và xuất doanh thu từng phim
    tinhDoanhThuTungPhim(dskh);

    // Nhập phòng chiếu và xuất chiếu từ bàn phím
    string phong, xuat;
    cout << "Nhap phong chieu: ";
    cin >> phong;
    cout << "Nhap xuat chieu: ";
    cin >> xuat;

    // Xuất thông tin khách hàng theo phòng và xuất chiếu
    xuatThongTinKhachHangTheoPhongVaXuatChieu(dskh, phong, xuat);

    // Sắp xếp danh sách khách hàng theo số tiền phải trả tăng dần bằng Bubble sort
    bubbleSort(dskh);
    cout << "Danh sach khach hang sau khi sap xep Bubble Sort: " << endl;
    xuatDanhSachKhachHang(dskh);

    // Sắp xếp danh sách khách hàng theo số tiền phải trả tăng dần bằng Selection sort
    selectionSort(dskh);
    cout << "Danh sach khach hang sau khi sap xep Selection Sort: " << endl;
    xuatDanhSachKhachHang(dskh);

    // Sắp xếp danh sách khách hàng theo số tiền phải trả tăng dần bằng Insertion sort
    insertionSort(dskh);
    cout << "Danh sach khach hang sau khi sap xep Insertion Sort: " << endl;
    xuatDanhSachKhachHang(dskh);

    // Sắp xếp danh sách khách hàng theo họ tên
    sapXepTheoHoTen(dskh);
    cout << "Danh sach khach hang sau khi sap xep theo ho ten: " << endl;
    xuatDanhSachKhachHang(dskh);

    // Tìm kiếm khách hàng có họ tên "Nguyen Van An"
    string hoTenCanTim = "Nguyen Van An";
    bool timThay = binarySearchKhachHang(dskh, hoTenCanTim);
    if (timThay) {
        cout << "Tim thay khach hang " << hoTenCanTim << endl;
    }
    else {
        cout << "Khong tim thay khach hang " << hoTenCanTim << endl;
    }

    _getch();

    return 0;
}

