#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для слияния двух отсортированных векторов
void mergeVectors(vector<int>& left, vector<int>& right, vector<int>& result) {
    result.clear();
    merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(result));
}

// Строим Merge Sort Tree
void buildTree(vector<int>& arr, vector<vector<int>>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = {arr[start]}; // Лист дерева
    } else {
        int mid = (start + end) / 2;
        buildTree(arr, tree, 2*node + 1, start, mid);  // Левое поддерево
        buildTree(arr, tree, 2*node + 2, mid + 1, end);  // Правое поддерево

        // Слияние результатов левого и правого поддеревьев
        mergeVectors(tree[2*node + 1], tree[2*node + 2], tree[node]);
    }
}

// Функция для запроса диапазона на отрезке [L, R]
vector<int> query(vector<vector<int>>& tree, int node, int start, int end, int L, int R) {
    if (R < start || L > end) {
        return {};  // Если диапазоны не пересекаются
    }
    if (L <= start && end <= R) {
        return tree[node];  // Если запрос полностью лежит в диапазоне
    }

    int mid = (start + end) / 2;
    vector<int> left = query(tree, 2*node + 1, start, mid, L, R);  // Левое поддерево
    vector<int> right = query(tree, 2*node + 2, mid + 1, end, L, R);  // Правое поддерево

    // Слияние результатов запроса
    vector<int> result;
    mergeVectors(left, right, result);
    return result;
}

// Пример использования
int main() {
    vector<int> arr = {1, 5, 2, 4, 3, 6, 7};
    int n = arr.size();

    // Строим дерево
    vector<vector<int>> tree(4 * n);  // Дерево размера 4n
    buildTree(arr, tree, 0, 0, n - 1);

    // Запрос на диапазон
    int L = 1, R = 5;  // Запрос на диапазон [1, 5]
    vector<int> result = query(tree, 0, 0, n - 1, L, R);

    // Вывод результата
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
