/*
Problem Link: https://codeforces.com/contest/1985/problem/D
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
    int m,n;
    cin>>n>>m;
    int I=0;
    int J=0;
    int r=0;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        int start=-1;
        int end=-1;
        for(int j=0;j<m;j++){
            if(s[j]=='#') {
                if(start==-1) start=j;
                if(j==m-1 || s[j+1]=='.') end=j;
            }
        }
        // cout<<"ss"<<start<<" "<<end<<endl;
        // cout<<"loc"<<end-start+1<<endl;
        if(end-start+1 > r && start!=-1) {
            // cout<<start<<" "<<end<<endl;
            r= end-start+1;
            I=i;
            J= (start+end)/2;
        }


    }
    cout<<I+1<<" "<<J+1<<"\n";
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
