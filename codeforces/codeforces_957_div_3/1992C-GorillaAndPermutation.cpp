/*
Problem Link: https://codeforces.com/contest/957/problem/C
Created By mahdich02 on 2024-07-24
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
    int n,m,k;
    cin>>n>>m>>k;
    int a= min(m+1,k);
    for(int i=n;i>=a;i--) cout<<i<<" ";
    for(int i=1;i<a;i++) cout<<i<<" ";
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
