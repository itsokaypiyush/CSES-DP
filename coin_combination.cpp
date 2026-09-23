#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    const int MOD = 1e9 + 7;

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int sum = 1; sum <= x; sum++) {
        for (int coin : coins) {
            if (sum >= coin) {
                dp[sum] += dp[sum - coin];
                dp[sum] %= MOD;
            }
        }
    }

    cout << dp[x] << endl;

    return 0;
}