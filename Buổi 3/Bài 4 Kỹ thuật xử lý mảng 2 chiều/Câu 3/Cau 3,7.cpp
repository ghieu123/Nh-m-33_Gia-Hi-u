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


// 7. Sắp xếp ma trận theo dạng ziczag: các giá trị giảm dần theo cột và dòng
vector<vector<int>> sort_zigzag(vector<vector<int>>& matrix) {
    vector<int> elements;
    for (const auto& row : matrix) {
        for (int num : row) {
            elements.push_back(num);
        }
    }
    sort(elements.begin(), elements.end(), greater<int>());

    size_t index = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            matrix[i][j] = elements[index++];
        }
    }
    return matrix;
}



int main() {
    auto sorted_zigzag = sort_zigzag(matrix);
    cout << "Ma tran theo dang ziczag:" << endl;
    for (const auto& row : sorted_zigzag) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}