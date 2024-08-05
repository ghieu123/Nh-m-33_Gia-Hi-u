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

// 2. Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận
int tim_phan_tu_lon_nhat(const vector<vector<int>>& matrix) {
    vector<int> border_elements;
    for (size_t j = 0; j < matrix[0].size(); ++j) {
        border_elements.push_back(matrix[0][j]);
        border_elements.push_back(matrix[matrix.size() - 1][j]);
    }
    for (size_t i = 1; i < matrix.size() - 1; ++i) {
        border_elements.push_back(matrix[i][0]);
        border_elements.push_back(matrix[i][matrix[0].size() - 1]);
    }
    return *max_element(border_elements.begin(), border_elements.end());
}

int main() {
    // Tìm phần tử lớn nhất trên biên
    cout << "Tim phan tu lon nhat: " << tim_phan_tu_lon_nhat(matrix) << endl;

    return 0;
}