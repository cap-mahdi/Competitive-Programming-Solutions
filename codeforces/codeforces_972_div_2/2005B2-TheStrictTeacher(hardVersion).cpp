/*
Problem Link: https://codeforces.com/contest/2005/problem/B2
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

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a;
    for (int i = 0;i < m;i++) {
        int b;
        cin >> b;
        a.push_back(b);
    }
    sort(a.begin(), a.end());
    while (q--) {

        int x;
        cin >> x;
        int index = lower_bound(a.begin(), a.end(), x) - a.begin();
        if (index == 0) {
            cout << a[index] - 1 << "\n";
            continue;
        }
        if (index == m) {
            cout << n - a[index - 1] << "\n";
            continue;
        }
        int mid = (a[index] + a[index - 1]) / 2;
        cout << min(a[index] - mid, mid - a[index - 1]) << "\n";


    }

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
    while (t--) {
        solve();
    }
    return 0;
}