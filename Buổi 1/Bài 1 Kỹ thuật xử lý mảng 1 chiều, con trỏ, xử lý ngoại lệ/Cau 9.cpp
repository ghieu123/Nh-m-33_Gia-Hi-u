#include <iostream>
using namespace std;

int main() {
    // Nhập hai số thực a và b
    float a, b;
    cout << "Nhap so a: ";
    cin >> a;
    cout << "Nhap so b: ";
    cin >> b;

    // Tạo hai con trỏ pa và pb trỏ đến a và b
    float* pa = &a;
    float* pb = &b;

    // Xuất giá trị các con trỏ pa, pb
    cout << "Gia tri cua con tro pa: " << pa << endl;
    cout << "Gia tri cua con tro pb: " << pb << endl;

    // Khai báo các biến để lưu kết quả
    float sum, diff, product, quotient;

    // Tính toán các giá trị tổng, hiệu, tích, thương
    sum = *pa + *pb;
    diff = *pa - *pb;
    product = *pa * *pb;
    quotient = (*pb != 0) ? (*pa / *pb) : 0; // Kiểm tra chia cho 0

    // In kết quả và địa chỉ các ô nhớ chứa các giá trị đó
    cout << "Tong: " << sum << ", dia chi: " << &sum << endl;
    cout << "Hieu: " << diff << ", dia chi: " << &diff << endl;
    cout << "Tich: " << product << ", dia chi: " << &product << endl;
    cout << "Thuong: " << quotient << ", dia chi: " << &quotient << endl;

    return 0;
}
