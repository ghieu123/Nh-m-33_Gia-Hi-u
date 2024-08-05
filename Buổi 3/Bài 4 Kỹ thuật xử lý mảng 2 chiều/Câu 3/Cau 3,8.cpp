#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<vector<int>> matrix = {
    {13, 27, 35, 42},
    {56, 22, 92, 18},
    {45, 33, 55, 67},
    {89, 76, 23, 90}
};


// 8. Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
vector<int> even_rows(const vector<vector<int>>& matrix) {
    vector<int> result;
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (all_of(matrix[i].begin(), matrix[i].end(), [](int x) { return x % 2 == 0; })) {
            result.push_back(i);
        }
    }
    return result;
}



int main() {
    // Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
    auto even_row_indices = even_rows(matrix);
    cout << "Cac dong chua gia tri chan: ";
    for (int idx : even_row_indices) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}