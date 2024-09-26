/*
Problem Link: https://codeforces.com/contest/2014/problem/D
Created By mahdich02 on 2024-09-26
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
    int n, d, k;
    cin >> n >> d >> k;
    d--;
    vector<int> a(n + 2, 0);
    vector<int> b(n + 2, 0);
    vector<pair<int, int>>c;
    a[0] = 0;
    for (int i = 0;i < k;i++) {
        int l, r;
        cin >> l >> r;
        c.push_back({ l,1 });
        c.push_back({ r ,-1 });
    }
    sort(c.begin(), c.end());


    // for (auto val : c) cout << val.first << " " << val.second << endl;
    int mom = 1;
    int distinct = 0;
    int currIndex = 0;
    for (int i = 1;i <= d;i++) {
        while (currIndex < c.size() && c[currIndex].first == i) {
            if (c[currIndex].second == 1) distinct++;
            currIndex++;
        }
    }

    int curr = INT_MAX;
    int currIndex2 = 0;
    for (int endd = d + 1;endd <= n;endd++) {
        while (currIndex < c.size() && c[currIndex].first == endd) {
            if (c[currIndex].second == 1) distinct++;
            currIndex++;
        }
        // cout << endd - d << " " << endd << " " << distinct << endl;

        if (curr > distinct) {
            curr = distinct;
            mom = endd - d;
        }
        while (currIndex2 < c.size() && c[currIndex2].first == endd - d) {
            if (c[currIndex2].second == -1) distinct--;
            currIndex2++;
        }
    }


    int brother = 1;
    distinct = 0;
    currIndex = 0;
    for (int i = 1;i <= d;i++) {
        while (currIndex < c.size() && c[currIndex].first == i) {
            if (c[currIndex].second == 1) distinct++;
            currIndex++;
        }
    }

    curr = 0;
    currIndex2 = 0;
    for (int endd = d + 1;endd <= n;endd++) {
        while (currIndex < c.size() && c[currIndex].first == endd) {
            if (c[currIndex].second == 1) distinct++;
            currIndex++;
        }

        if (curr < distinct) {
            curr = distinct;
            brother = endd - d;
        }
        while (currIndex2 < c.size() && c[currIndex2].first == endd - d) {
            if (c[currIndex2].second == -1) distinct--;
            currIndex2++;
        }
    }
    cout << brother << " " << mom << endl;




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