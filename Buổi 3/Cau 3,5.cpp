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

// 5. Sắp xếp các dòng có chỉ số lẻ tăng dần, chỉ số chẵn giảm dần
vector<vector<int>> sort_rows(vector<vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (i % 2 == 0) {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
        }
        else {
            sort(matrix[i].begin(), matrix[i].end());
        }
    }
    return matrix;
}


int main() {
    // Sắp xếp các dòng
    auto sorted_rows = sort_rows(matrix);
    cout << "Sap xep lai cac dong:" << endl;
    for (const auto& row : sorted_rows) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}