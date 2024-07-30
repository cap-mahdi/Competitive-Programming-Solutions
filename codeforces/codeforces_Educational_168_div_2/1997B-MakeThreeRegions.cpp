/*
Problem Link: https://codeforces.com/contest/1997/problem/B
Created By mahdich02 on 2024-07-30
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
    char a[2][n];
    for(int i=0;i<n;i++) cin>>a[0][i];
    for(int i=0;i<n;i++) cin>>a[1][i];

    int ans=0;
    for(int j=0;j<2;j++)
        for(int i=1;i<n-1;i++) {
            if(a[j][i]=='.' && a[1-j][i]!='x') {
                if(a[j][i-1]=='.' && a[j][i+1]=='.' && a[1-j][i-1]=='x' && a[1-j][i+1]=='x') ans++;
            }
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
