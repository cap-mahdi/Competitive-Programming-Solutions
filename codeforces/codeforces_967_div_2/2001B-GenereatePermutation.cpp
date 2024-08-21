/*
Problem Link: https://codeforces.com/contest/2001/problem/B
Created By mahdich02 on 2024-08-21
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
    if(n==1)cout<<1;
    else if(n%2==0) cout<<-1;
    else {
        vector<int> a(n);
        int mid=n/2;
        for(int i=mid-1;i>=0;i--) a[i]= mid-i;
        int last = mid+1;
        a[mid]=n;
        for(int i=mid+1;i<n;i++) {a[i]=last;last++;}
        for(int val : a )cout<<val<<" ";

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
