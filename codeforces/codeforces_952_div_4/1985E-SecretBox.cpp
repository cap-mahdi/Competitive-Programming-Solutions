/*
Problem Link: https://codeforces.com/contest/1985/problem/E
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
    int X,Y,Z,k;
    cin >> X >>Y >> Z >>k; int ans =0;
    vector<int> x,y,z;
    for(int i=1;i<=X;i++) {
        if(k%i==0) x.push_back(i);
    }for(int i=1;i<=Y;i++) {
        if(k%i==0) y.push_back(i);
    }for(int i=1;i<=Z;i++) {
        if(k%i==0) z.push_back(i);
    }

    for(int i : x) {
        for(int j : y) {
            int prod = i*j;
            if(prod>k) continue;
            int indice = lower_bound(z.begin(),z.end(),k/prod)-z.begin();

            int  m = *(z.begin()+indice);
            // cout<<i<<" "<<j<<" "<<m<<endl;
            if(m * i *j !=k) continue;
            // cout<<"yes"<<endl;
            int loc = (X-i+1)*(Z-m+1)*(Y-j+1);
            ans=max(loc,ans);

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
