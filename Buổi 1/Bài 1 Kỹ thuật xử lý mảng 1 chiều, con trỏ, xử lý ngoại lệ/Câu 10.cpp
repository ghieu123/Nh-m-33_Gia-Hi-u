#include <iostream>
#include <cstring> // Để sử dụng các hàm xử lý chuỗi
using namespace std;

// Hàm chuyển đổi một ký tự thành chữ hoa
void toUpperCase(char& c) {
    if (c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
}

// Hàm chuyển chuỗi về chữ hoa
void convertToUpper(char* str) {
    while (*str) {
        toUpperCase(*str);
        str++;
    }
}

// Hàm chuyển ký tự đầu mỗi từ về chữ hoa
void capitalizeWords(char* str) {
    bool newWord = true; // Biến kiểm tra bắt đầu từ mới

    while (*str) {
        if (*str == ' ') {
            newWord = true; // Ký tự khoảng trắng, từ mới sẽ bắt đầu
        }
        else if (newWord) {
            toUpperCase(*str); // Chuyển ký tự đầu từ về chữ hoa
            newWord = false;
        }
        str++;
    }
}

int main() {
    // Nhập chuỗi
    char st[100];
    cout << "Nhap chuoi: ";
    cin.getline(st, 100); // Nhập chuỗi có khoảng trắng

    // Con trỏ trỏ đến chuỗi
    char* p = st;

    // a. Xuất giá trị từng ký tự của st thông qua con trỏ trỏ đến chuỗi
    cout << "Cac ky tu cua chuoi:" << endl;
    while (*p) {
        cout << *p << " ";
        p++;
    }
    cout << endl;

    // Chuyển con trỏ về đầu chuỗi
    p = st;

    // b. Chuyển các ký tự của chuỗi về dạng chữ hoa
    convertToUpper(p);
    cout << "Chuoi sau khi chuyen tat ca ky tu ve chu hoa: " << p << endl;

    // Chuyển con trỏ về đầu chuỗi
    p = st;

    // c. Chuyển các ký tự đầu mỗi từ về dạng chữ hoa
    capitalizeWords(p);
    cout << "Chuoi sau khi chuyen ky tu dau moi tu ve chu hoa: " << p << endl;

    return 0;
}
