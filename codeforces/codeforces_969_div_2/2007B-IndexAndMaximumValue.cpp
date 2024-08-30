/*
Problem Link: https://codeforces.com/contest/2007/problem/B
Created By mahdich02 on 2024-08-30
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
    int n,m;
    cin >> n>>m;
    vector<int> a(n);
    int ans=0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans=max(ans,a[i]);
    }
    while(m--) {
        char op;
        int l,r;
        cin>>op>>l>>r;
        if(ans>=l && ans<=r) {
            if(op=='+') ans++;
            else ans--;
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
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
