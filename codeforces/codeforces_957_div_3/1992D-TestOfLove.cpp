/*
Problem Link: https://codeforces.com/contest/957/problem/D
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
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    n=s.size();
    s= "L"+s+"L";
    vector<int> logs;
    for(int i=0;i<=n+1;i++) {
        if(s[i]=='L') {
            logs.push_back(i);
        }
    }
    int i=0;
    while(i<=n) {
        if(s[i]=='L') {
            int longuestJump = i+m;
            if(longuestJump>=1+n) {
                i=1+n;
                break;
            }
            int nextMaximumLogIndex = lower_bound(logs.begin(),logs.end(),longuestJump) - logs.begin();
            int nextMaximumLog = logs[nextMaximumLogIndex];
            if(nextMaximumLog<=longuestJump) {
                i=nextMaximumLog;
                continue;
            }
            nextMaximumLogIndex--;
            nextMaximumLog = logs[nextMaximumLogIndex];
            if(nextMaximumLog<=longuestJump && nextMaximumLog>i) {
                i=nextMaximumLog;
                continue;
            }
            if(s[longuestJump]=='C') {
                break;
            }
            i=longuestJump;
        }else {
            if(s[i+1]=='C') break;
            if(!k) break;
            i++;
            k--;
        }

    }
    if(i==n+1) cout<<"YES";
    else cout<<"NO";
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
