/*
Problem Link: https://codeforces.com/contest/1996/problem/C
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
    int n,q;
    cin>>n>>q;
    string a,b;
    cin>>a>>b;
    vector<vector<int>> A(27,vector<int>(n+1,0));
    for(int i=1;i<=n;i++) {
        // cout<<"i"<<i<<endl;
        for(int j=0;j<26;j++) {
            if(a[i-1]-'a' == j) A[j][i] = A[j][i-1]+1;
            else A[j][i] = A[j][i-1];
            // cout<<char(j+'a')<<A[j][i]<<endl;
        }
    }

    vector<vector<int>> B(27,vector<int>(n+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=0;j<26;j++) {
            if(b[i-1]-'a' == j) B[j][i] = B[j][i-1]+1;
            else B[j][i] = B[j][i-1];
        }
    }
    while(q--) {
        int l,r;
        cin>>l>>r;
        int ans=0;
        int N = r-l+1;
        for(int i=0;i<26;i++) {
            int occA = A[i][r]-A[i][l-1];
            int occB= B[i][r]-B[i][l-1];
            // cout<<occA<<" "<<occB<<endl;
            ans+= min(occA,occB);
        }
        cout<<(N-ans)<<"\n";
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
