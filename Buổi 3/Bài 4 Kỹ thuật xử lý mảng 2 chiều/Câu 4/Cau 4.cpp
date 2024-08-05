#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>

using namespace std;

// Hàm xuất ma trận
void xuatMaTran(const vector<vector<int>>& a) {
    for (const auto& row : a) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 1. Sắp xếp đường chéo phụ tăng dần/giảm dần
void sapXepDuongCheoPhu(vector<vector<int>>& a, bool tangDan = true) {
    int n = a.size();
    vector<int> duongCheoPhu;
    for (int i = 0; i < n; ++i) {
        duongCheoPhu.push_back(a[i][n - 1 - i]);
    }
    if (tangDan) {
        sort(duongCheoPhu.begin(), duongCheoPhu.end());
    }
    else {
        sort(duongCheoPhu.rbegin(), duongCheoPhu.rend());
    }
    for (int i = 0; i < n; ++i) {
        a[i][n - 1 - i] = duongCheoPhu[i];
    }
}

// 2. Sắp xếp ma trận theo dòng chẵn giảm dần, dòng lẻ tăng dần
void sapXepDongLeTangDanDongChanGiamDan(vector<vector<int>>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            sort(a[i].begin(), a[i].end(), greater<int>());
        }
        else {
            sort(a[i].begin(), a[i].end());
        }
    }
}

// 3. Sắp xếp ma trận theo cột chẵn tăng dần, cột lẻ giảm dần
void sapXepCotChanTangDanCotLeGiamDan(vector<vector<int>>& a) {
    int n = a.size();
    for (int j = 0; j < n; ++j) {
        vector<int> cot(n);
        for (int i = 0; i < n; ++i) {
            cot[i] = a[i][j];
        }
        if (j % 2 == 0) {
            sort(cot.begin(), cot.end());
        }
        else {
            sort(cot.rbegin(), cot.rend());
        }
        for (int i = 0; i < n; ++i) {
            a[i][j] = cot[i];
        }
    }
}

// 4. Sắp xếp các đường chéo chính và các đường chéo song song với đường chéo chính tăng dần
void sapXepDuongCheoChinhVaSongSong(vector<vector<int>>& a) {
    int n = a.size();
    for (int k = 0; k < n; ++k) {
        vector<int> duongCheo;
        for (int i = 0; i <= k; ++i) {
            duongCheo.push_back(a[i][k - i]);
        }
        sort(duongCheo.begin(), duongCheo.end());
        for (int i = 0; i <= k; ++i) {
            a[i][k - i] = duongCheo[i];
        }
    }
    for (int k = 1; k < n; ++k) {
        vector<int> duongCheo;
        for (int i = 0; i < n - k; ++i) {
            duongCheo.push_back(a[k + i][n - 1 - i]);
        }
        sort(duongCheo.begin(), duongCheo.end());
        for (int i = 0; i < n - k; ++i) {
            a[k + i][n - 1 - i] = duongCheo[i];
        }
    }
}

// 5. Di chuyển các phần tử chẵn lên đầu, lẻ xuống cuối
void diChuyenChanLe(vector<vector<int>>& a) {
    int n = a.size();
    vector<int> chan, le;
    for (const auto& row : a) {
        for (int elem : row) {
            if (elem % 2 == 0) {
                chan.push_back(elem);
            }
            else {
                le.push_back(elem);
            }
        }
    }
    int chanIndex = 0, leIndex = 0;
    for (auto& row : a) {
        for (int& elem : row) {
            if (chanIndex < chan.size()) {
                elem = chan[chanIndex++];
            }
            else {
                elem = le[leIndex++];
            }
        }
    }
}

// 6. Kiểm tra đối xứng qua đường chéo chính
bool kiemTraDoiXungQuaDuongCheoChinh(const vector<vector<int>>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] != a[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> a = {
        {5, 8, 1, 2},
        {4, 7, 6, 3},
        {9, 5, 2, 1},
        {3, 4, 7, 6}
    };

    cout << "Ma tran ban dau:\n";
    xuatMaTran(a);

    // 1. Sắp xếp đường chéo phụ tăng dần
    sapXepDuongCheoPhu(a, true);
    cout << "1: Ma tran sau khi sap xep duong cheo phu tang dan:\n";
    xuatMaTran(a);

    // 2. Sắp xếp ma trận theo dòng lẻ tăng dần, dòng chẵn giảm dần
    sapXepDongLeTangDanDongChanGiamDan(a);
    cout << "2: Ma tran sau khi sap xep dong le tang dan, dong chan giam dan:\n";
    xuatMaTran(a);

    // 3. Sắp xếp ma trận theo cột chẵn tăng dần, cột lẻ giảm dần
    sapXepCotChanTangDanCotLeGiamDan(a);
    cout << "3: Ma tran sau khi sap xep cot chan tang dan, cot le giam dan:\n";
    xuatMaTran(a);

    // 4. Sắp xếp các đường chéo chính và các đường chéo song song với đường chéo chính tăng dần
    sapXepDuongCheoChinhVaSongSong(a);
    cout << "4: Ma tran sau khi sap xep cac duong cheo chinh va song song tang dan:\n";
    xuatMaTran(a);

    // 5. Di chuyển các phần tử chẵn lên đầu, lẻ xuống cuối
    diChuyenChanLe(a);
    cout << "5: Ma tran sau khi di chuyen cac phan tu chan len dau, le xuong cuoi:\n";
    xuatMaTran(a);

    // 6. Kiểm tra đối xứng qua đường chéo chính
    bool doiXung = kiemTraDoiXungQuaDuongCheoChinh(a);
    cout << "6: Ma tran " << (doiXung ? "doi xung" : "khong doi xung") << " qua duong cheo chinh.\n";

    _getch();
    return 0;
}

