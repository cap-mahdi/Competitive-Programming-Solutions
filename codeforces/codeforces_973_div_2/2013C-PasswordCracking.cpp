/*
Problem Link: https://codeforces.com/contest/2013/problem/C
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
    int n = 0;
    cin >> n;
    string s;
    bool endd = false;

    while (s.size() < n) {
        string temp = s;
        if (endd) {
            string temp1 = temp + "0";
            cout << "? " << temp1 << endl;
            cout.flush();
            int val;
            cin >> val;
            if (!val) temp1 = temp + "1";
            s = temp1;
            continue;
        }
        int val;

        cout << "? 0" << s << endl;
        cout.flush();
        cin >> val;
        if (val) {
            s = "0" + s;
            continue;
        }

        cout << "? 1" << s << endl;
        cout.flush();
        cin >> val;
        if (val) {
            s = "1" + s;
            continue;
        }

        endd = true;
        cout << "? " << s << "0" << endl;
        cout.flush();
        cin >> val;

        if (val) s = s + "0";
        else s = s + "1";
    }

    cout << "! " << s << endl;

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #else
    //     // online submission
    // #endif


    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}