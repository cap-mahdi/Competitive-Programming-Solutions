/*
Problem Link: https://codeforces.com/contest/2001/problem/C
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

vector<int> par;
vector<bool> vis;

void ask(int a,int b) {
    if(par[b]!=-1) return;
    cout<<"? "<<a<<" "<<b<<endl;
    cout.flush();
    int x;
    cin>>x;
    if(a==x) {
        par[b]=a;
        return;
    };
    ask(a,x);
    ask(x,b);
}

void solve() {
    int n;
    cin >> n;
    par.clear();
    vis.clear();
    par.resize(n+1,-1);
    vis.resize(n,false);

    for(int node=2;node<=n;node++) {
        if(par[node]==-1)
            ask(1,node);
    }
    cout<<"!";
    for(int node=2;node<=n;node++) {
        cout<<" "<<par[node]<<" "<<node;
    }
    cout<<endl;

}

int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);





    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
