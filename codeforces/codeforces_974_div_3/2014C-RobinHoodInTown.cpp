/*
Problem Link: https://codeforces.com/contest/2014/problem/C
Created By mahdich02 on 2024-09-26
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

void no() {
    cout << "NO" << "\n";
}
void yes() {
    cout << "YES" << "\n";
}

void solve() {
    int n;
    cin >> n;
    vector<double> a(n);
    double sum = 0;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    if (n <= 2) {
        cout << -1 << "\n";
        return;
    }
    int middle = a[n / 2];
    // cout << "mid " << middle << endl;
    int x = ceil(2 * n * middle - sum);
    cout << max(x + 1, 0LL) << "\n";

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}