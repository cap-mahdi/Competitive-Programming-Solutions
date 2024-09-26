/*
Problem Link: https://codeforces.com/contest/2014/problem/E
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

const int N = 2e5 + 5;
vector<pair<int, int>> gr[N];

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> horse(n + 5, 0);

    for (int i = 0;i < n;i++) gr[i].clear();

    for (int i = 0;i < h;i++) {
        int v;
        cin >> v;
        v--;
        horse[v] = 1;
    }

    for (int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        gr[u].push_back({ v,w });
        gr[v].push_back({ u,w });
    }



    set<pair<pair<int, int>, int>> s;
    vector<vector<int>> dis(n + 5, vector<int>(2 + 2, INT64_MAX));
    vector<vector<bool>> vis(n + 5, vector<bool>(2 + 2, false));

    dis[0][horse[0]] = 0;
    dis[0][0] = 0;
    s.insert({ { 0,horse[0] },0 });
    s.insert({ { 0,0},0 });

    while (!s.empty()) {
        auto top = *s.begin();
        s.erase(s.begin());

        int curr = top.first.first;
        bool haveHorse = top.first.second;
        int node = top.second;
        vis[node][haveHorse] = true;

        for (auto c : gr[node]) {
            int weight = c.second;
            int child = c.first;
            if (vis[child][haveHorse]) continue;
            int newDitance = 0;
            if (haveHorse)
                newDitance = curr + weight / 2;
            else newDitance = curr + weight;
            if (dis[child][haveHorse] <= newDitance) continue;

            if (dis[child][haveHorse] != INT64_MAX) {
                if (s.find({ { dis[child][haveHorse],haveHorse }, child
                    }) != s.end())
                    s.erase(s.find({ { dis[child][haveHorse],haveHorse }, child
                        }));
            }

            dis[child][haveHorse] = newDitance;
            s.insert({ { dis[child][haveHorse],horse[child] || haveHorse }, child
                });
            // cout << "append " << dis[child][haveHorse] << " " << horse[child] << " " << child << endl;
        }
    }



    set<pair<pair<int, int>, int>> s2;
    vector<vector<int>> dis2(n + 5, vector<int>(2 + 1, INT64_MAX));
    vector<vector<bool>> vis2(n + 5, vector<bool>(2 + 1, false));
    dis2[n - 1][horse[n - 1]] = 0;
    dis2[n - 1][0] = 0;
    s2.insert({ { 0,horse[n - 1] },n - 1 });
    s2.insert({ { 0,0 },n - 1 });

    while (!s2.empty()) {
        auto top = *s2.begin();
        s2.erase(s2.begin());
        int curr = top.first.first;
        bool haveHorse = top.first.second;
        int node = top.second;
        vis2[node][haveHorse] = true;
        for (auto c : gr[node]) {
            int weight = c.second;
            int child = c.first;
            if (vis2[child][haveHorse]) continue;

            int newDitance = 0;
            if (haveHorse)
                newDitance = curr + weight / 2;
            else newDitance = curr + weight;
            if (dis2[child][haveHorse] <= newDitance) continue;
            if (dis2[child][haveHorse] != INT64_MAX) if (s2.find({ { dis2[child][haveHorse],haveHorse }, child
                }) != s2.end())s2.erase(s2.find({ { dis2[child][haveHorse],haveHorse }, child
                    }));
            dis2[child][haveHorse] = newDitance;
            s2.insert({ { dis2[child][haveHorse],horse[child] || haveHorse }, child
                });
        }
    }

    // for (auto v : dis) cout << v[0] << " AA " << v[1] << endl;
    // for (auto v : dis2) cout << v[0] << " AA " << v[1] << endl;

    int ans = -1;
    for (int i = 0;i < n;i++) {
        if (dis[i][0] == INT64_MAX && dis[i][1] == INT64_MAX) continue;
        if (dis2[i][0] == INT64_MAX && dis2[i][1] == INT64_MAX) continue;

        int to1 = INT64_MAX;
        if (dis[i][0] == INT64_MAX) to1 = dis[i][1];
        else if (dis[i][1] == INT64_MAX)to1 = dis[i][0];
        else to1 = min(dis[i][0], dis[i][1]);

        int to2 = INT64_MAX;
        if (dis2[i][0] == INT64_MAX) to2 = dis2[i][1];
        else if (dis2[i][1] == INT64_MAX)to2 = dis2[i][0];
        else to2 = min(dis2[i][0], dis2[i][1]);

        // cout << "node " << i << " 1=" << to1 << " last=" << to2 << endl;
        if (ans == -1) ans = max(to2, to1);
        else ans = min(ans, max(to2, to1));
    }
    cout << ans << "\n";

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