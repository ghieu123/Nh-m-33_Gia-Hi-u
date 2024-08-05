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
    {89, 76, 13, 90}
};


// 10. Tìm giá trị xuất hiện nhiều nhất trong ma trận
int most_frequent_value(const vector<vector<int>>& matrix) {
    unordered_map<int, int> count_map;
    for (const auto& row : matrix) {
        for (int num : row) {
            count_map[num]++;
        }
    }
    return max_element(count_map.begin(), count_map.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        })->first;
}



int main() {
    //10 Tìm giá trị xuất hiện nhiều nhất trong ma trận
    cout << "Gia tri xuat hien nhieu nhat: " << most_frequent_value(matrix) << endl;

    return 0;
}