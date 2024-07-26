/*
Problem Link: https://codeforces.com/contest/1996/problem/E
Created By mahdich02 on 2024-07-26
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
    string s;
    cin>>s;
    int n =s.size();
    map<int,int> count;
    int ans=0;
    const int MOD = 1e9+7;
    int acc=0;
    count[0]=1;
    for(int i=0;i<n;i++) {
        acc+= (s[i]=='1' ? 1 : -1);
        // cout<<"i "<<i<<endl;
        // cout<<"acc"<<acc<<" "<<count[acc]<<endl;
        // cout<<"will appearn in "<<count[acc]*(n-i)<<endl;
        ans+= (count[acc]*(n-i));
        count[acc]+=(i+2);
        count[acc]%=MOD;
        ans%=MOD;
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
