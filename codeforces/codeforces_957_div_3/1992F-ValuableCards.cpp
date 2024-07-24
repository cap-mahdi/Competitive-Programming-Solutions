/*
Problem Link: https://codeforces.com/contest/1992/problem/F
Created By mahdich02 on 2024-07-24
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

void no()
{
    cout << "NO" << "\n";
}

void yes()
{
    cout << "YES" << "\n";
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    set<int> s = {1};
    vector<int> divisors = {1};
    for (int i = 0; i < n; i++)
    {
        if (x % a[i])
            continue;
        if (s.find(x / a[i]) != s.end())
        {
            ans++;
            divisors = {1, a[i]};
            s = {1, a[i]};
            continue;
        }
        int N = divisors.size();
        for (int j = 0; j < N; j++)
        {
            int val = divisors[j] * a[i];
            if (x % val)
                continue;
            if (s.find(val) != s.end())
                continue;
            divisors.push_back((val));
            s.insert(val);
        }
    }
    cout << ans + 1 << "\n";
}

int32_t main()
{
    // fast I/O
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
    while (t--)
    {
        solve();
    }
    return 0;
}
