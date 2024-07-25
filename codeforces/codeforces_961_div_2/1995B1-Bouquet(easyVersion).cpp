/*
Problem Link: https://codeforces.com/contest/1995/problem/B1
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
    int n,m;
    cin >> n>>m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int ans=0;
    int current = 0;
    int i=-1;
    int j =0;
    while(i<n) {

        while(i+1<n && current+a[i+1]<=m && a[i+1]<=a[j]+1) {
            i++;
            current+=a[i];
        }

        ans=max(ans,current);
        i++;
        if(i>=n) break;
        current+=a[i];

        while(j<n && (current>m || a[i]>a[j]+1)) {
            current-=a[j];
            j++;
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
