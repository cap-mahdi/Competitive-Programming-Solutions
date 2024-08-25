/*
Problem Link: https://codeforces.com/contest/2003/problem/D1
Created By mahdich02 on 2024-08-25
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
    int n, m;
    cin >> n >> m;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        set<int> a;
        for (int j = 0; j < l; j++) {
            int b;
            cin >> b;
            a.insert(b);
        }
        int nx = 0;
        bool can = true;
        int loc = 0;
        while (!a.empty()) {
            int val = *a.begin();
            if (val != nx) {
                if (can) {
                    can = false;
                } else {
                    break;
                }
            }else {
                a.erase(a.begin());
            }
            loc = nx+1;

            nx++;

        }
        mx = max(loc+can, mx);
    }

    int toMulitply = min(m,mx);
    int rest = 0;
    if(mx+1<=m) {
        rest= (m+mx+1)*(m-mx)/2;
    }
    cout<< (toMulitply+1)*mx + rest <<"\n";
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
