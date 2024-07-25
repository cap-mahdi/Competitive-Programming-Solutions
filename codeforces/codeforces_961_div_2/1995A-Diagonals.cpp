/*
Problem Link: https://codeforces.com/contest/1995/problem/A
Created By mahdich02 on 2024-07-25
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
    int n,k;
    cin>>n>>k;
    int ans=0;
    vector<int> diag = {n};
    for(int i=n-1;i>=1;i--) {
        diag.push_back(i);
        diag.push_back(i);
    }
    int i=0;
    while(k>0) {
        k-=diag[i];
        i++;
        ans++;
    }
    cout<<ans<<"\n";
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
