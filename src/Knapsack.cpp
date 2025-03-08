
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int knapsack(int i, int w, const vector<int>& weights, const vector<int>& values) {
    if (i == 0 || w == 0) {
        return 0;
    }
    if (dp[i][w] != -1) {
        return dp[i][w];
    }
    if (weights[i - 1] > w) {
        return dp[i][w] = knapsack(i - 1, w, weights, values);
    }
    else {
        return dp[i][w] = max(knapsack(i - 1, w, weights, values), values[i - 1] + knapsack(i - 1, w - weights[i - 1], weights, values));
    }
}
int main() {
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for (int i = 0; i < N; i++) cin >> w[i];
    for (int j = 0; j < N; j++) cin >> v[j];
    dp.assign(N + 1, vector<int>(W + 1, -1));
    cout << "Giá trị lớn nhất có thể đạt được: " << knapsack(N, W, w, v) << endl;
    return 0;
}
