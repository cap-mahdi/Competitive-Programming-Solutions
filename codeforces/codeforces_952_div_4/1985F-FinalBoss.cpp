/*
Problem Link: https://codeforces.com/contest/1985/problem/F
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
    int h,n;
    cin >>h>> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int m=1,M=1;
    while(true) {
        int attack = 0;
        for(int i=0;i<n && h>attack;i++) {
            attack+= ((M-1)/b[i]+1)*a[i];
        }
        if(attack>=h) {
            break;
        }else {
            M*=2;
        }
    }

    while(m!=M) {
        int half = (m+M)/2;
        int attack = 0;
        for(int i=0;i<n && h>attack;i++) {
            // cout<<"add to attack "<<((half-1)/b[i]+1)*a[i]<<endl;
            attack+= ((half-1)/b[i]+1)*a[i];
        }
        // cout<<"attack "<<attack<<endl;
        // cout<<"half"<<half<<endl;
        if(attack>=h) {
            M=half;
        }else {
            m=half+1;
        }
    }
    cout<<m<<"\n";

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
