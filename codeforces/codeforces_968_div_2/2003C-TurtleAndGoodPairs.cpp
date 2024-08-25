/*
Problem Link: https://codeforces.com/contest/2003/problem/C
Created By mahdich02 on 2024-08-25
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
    vector<int> count(26,0);
    string s;
    cin >>s;
    for(char c : s ) count[c-'a']++;
    vector<char> ans(n,'A');
    int pos=0;
    while(pos<n){
        for(int i=0;i<26 && pos<n;i++) {
            if(count[i]) {
                count[i]--;
                ans[pos]='a'+i;
                pos++;
            }
        }

    }
    for(char c: ans) cout<<c;
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
