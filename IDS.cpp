#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
const ll N = 1e5+10;

vector<ll> g[N];
bool vis[N];

bool dls(ll vertex, ll target, ll limit, ll depth = 0) {
    if (vertex == target) return true;
    if (depth == limit) return false;

    vis[vertex] = true;

    for (ll child : g[vertex]) {
        if (!vis[child]) {
            if (dls(child, target, limit, depth + 1)) {
                return true;
            }
        }
    }
    
    vis[vertex] = false; // Unmark for other paths
    return false;
}

bool ids(ll src, ll target, ll max_depth) {
    for (ll limit = 0; limit <= max_depth; ++limit) {
        fill(vis, vis + N, false);
        if (dls(src, target, limit)) {
            cout << "Found target " << target << " at depth limit: " << limit << endl;
            return true;
        }
    }
    return false;
}

int main() {
    ll n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    cout << "Enter edges (v1 v2):" << endl;
    for (ll i = 0; i < m; i++) {
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    ll target;
    cout << "Enter target node to find: ";
    cin >> target;

    ll max_depth;
    cout << "Enter maximum depth for IDS: ";
    cin >> max_depth;

    if (ids(1, target, max_depth)) {
        cout << "Target found within depth limit." << endl;
    } else {
        cout << "Target not found within depth limit." << endl;
    }

    return 0;
}