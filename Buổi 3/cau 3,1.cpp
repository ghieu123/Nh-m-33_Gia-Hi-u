#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<vector<int>> matrix = {
    {13, 27, 35, 42},
    {56, 22, 91, 18},
    {45, 33, 55, 67},
    {89, 76, 23, 90}
};

// 1. Xuất các cột chỉ chứa số lẻ
vector<vector<int>> cac_cot_chua_so_le(const vector<vector<int>>& matrix) {
    vector<vector<int>> result;
    for (size_t j = 0; j < matrix[0].size(); ++j) {
        bool all_odd = true;
        for (size_t i = 0; i < matrix.size(); ++i) {
            if (matrix[i][j] % 2 == 0) {
                all_odd = false;
                break;
            }
        }
        if (all_odd) {
            vector<int> col;
            for (size_t i = 0; i < matrix.size(); ++i) {
                col.push_back(matrix[i][j]);
            }
            result.push_back(col);
        }
    }
    return result;
}

int main() {
    // In kết quả của hàm odd_columns
    auto odd_cols = cac_cot_chua_so_le(matrix);
    cout << "Cac cot chua so le:" << endl;
    for (const auto& col : odd_cols) {
        for (int num : col) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}