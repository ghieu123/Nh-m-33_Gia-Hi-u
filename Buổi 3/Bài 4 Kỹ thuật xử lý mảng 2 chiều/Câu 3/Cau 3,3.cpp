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

// 3. Đếm số phần tử có chứa chữ số 2
int count_elements_with_2(const vector<vector<int>>& matrix) {
    int count = 0;
    for (const auto& row : matrix) {
        for (int num : row) {
            string num_str = to_string(num);
            count += count_if(num_str.begin(), num_str.end(), [](char c) { return c == '2'; });
        }
    }
    return count;
}


int main() {
    // Đếm số phần tử có chứa chữ số 2
    cout << "Dem so phan tu co chua chu so '2': " << count_elements_with_2(matrix) << endl;

    return 0;
}