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

// 4. Xuất các phần tử cực tiểu của ma trận
vector<int> local_minima(const vector<vector<int>>& matrix) {
    vector<int> minima;
    int rows = matrix.size();
    int cols = matrix[0].size();

    auto is_local_minima = [&](int i, int j) {
        int current = matrix[i][j];
        vector<int> neighbors;
        if (i > 0) neighbors.push_back(matrix[i - 1][j]);
        if (i < rows - 1) neighbors.push_back(matrix[i + 1][j]);
        if (j > 0) neighbors.push_back(matrix[i][j - 1]);
        if (j < cols - 1) neighbors.push_back(matrix[i][j + 1]);
        return all_of(neighbors.begin(), neighbors.end(), [current](int neighbor) { return current < neighbor; });
        };

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (is_local_minima(i, j)) {
                minima.push_back(matrix[i][j]);
            }
        }
    }
    return minima;
}


int main() {
    // Xuất các phần tử cực tiểu
    auto minima = local_minima(matrix);
    cout << "Xuat cac phan tu cuc tieu: ";
    for (int num : minima) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}