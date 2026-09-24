#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int INF = 1e9;

    vector<int> dp(n + 1, INF);

    dp[0] = 0;

    for (int number = 1; number <= n; number++) {
        int current = number;

        while (current > 0) {
            int digit = current % 10;
            current /= 10;

            if (digit != 0) {
                dp[number] = min(dp[number], dp[number - digit] + 1);
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}