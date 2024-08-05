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

// 6. Sắp xếp các cột có chỉ số lẻ giảm dần, chỉ số chẵn tăng dần
vector<vector<int>> sort_columns(vector<vector<int>>& matrix) {
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();
    for (size_t j = 0; j < cols; ++j) {
        vector<int> col(rows);
        for (size_t i = 0; i < rows; ++i) {
            col[i] = matrix[i][j];
        }
        if (j % 2 == 0) {
            sort(col.begin(), col.end());
        }
        else {
            sort(col.begin(), col.end(), greater<int>());
        }
        for (size_t i = 0; i < rows; ++i) {
            matrix[i][j] = col[i];
        }
    }
    return matrix;
}


int main() {
    // Sắp xếp các cột
    auto sorted_cols = sort_columns(matrix);
    cout << "Sap xep lai cac cot:" << endl;
    for (const auto& row : sorted_cols) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}