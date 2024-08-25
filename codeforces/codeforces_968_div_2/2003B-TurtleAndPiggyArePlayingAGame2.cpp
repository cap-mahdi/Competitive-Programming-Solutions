/*
Problem Link: https://codeforces.com/contest/2003/problem/B
Created By mahdich02 on 2024-08-25
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define pp pair<int,int>
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
    priority_queue<pp,vector<pp>,greater<pp>> p,t;
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        t.push({-a,i});
        p.push({a,i});
    }
    int turn =0;
    vector<bool> vis(n,false);

    while(turn!=n-1) {
        if(turn%2==0) {
            while(vis[p.top().second]) p.pop();
            vis[p.top().second]=true;
            p.pop();
        }else {
            while(vis[t.top().second]) t.pop();
            vis[t.top().second]=true;
            t.pop();
        }
        turn++;
    }
    while(vis[p.top().second]) p.pop();
    cout<<p.top().first<<"\n";
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
