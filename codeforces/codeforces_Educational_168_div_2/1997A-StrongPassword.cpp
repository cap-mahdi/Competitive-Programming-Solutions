/*
Problem Link: https://codeforces.com/contest/1997/problem/A
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
    string s;
    cin>>s;
    vector<int> a(26,0);
    for(char c : s) a[c-'a']=1;
    char c;
    for(int i=0;i<26;i++) {
        if(!a[i]) {
            c=(char)(i+'a');
            break;
        }
    }
    int pos=s.length();
    for(int i=1;i<s.length();i++) {
        if(s[i]==s[i-1]) {
            pos=i;break;
        }
    }
    for(int i=0;i<pos;i++) cout<<s[i];
    cout<<c;
    for(int i=pos;i<s.length();i++) cout<<s[i];
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
