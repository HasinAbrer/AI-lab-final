#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
const ll N = 1e5+10;

vector<ll> g[N];
bool vis[N];

// Depth-Limited Search function
void dls(ll vertex, ll limit, ll depth = 0)
{
    cout << "Vertex: " << vertex << " at Depth: " << depth << endl;
    vis[vertex] = true;
    
    // Stop recursion if we reach the depth limit
    if (depth == limit) return;

    for (ll child : g[vertex])
    {
        cout << "Parent: " << vertex << " Child: " << child << endl;
        if (vis[child]) continue;
        dls(child, limit, depth + 1);  // Increment depth in recursive call
    }
}

int main()
{
    ll n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    cout << "Enter edges (v1 v2):" << endl;
    for (ll i = 0; i < m; i++) 
    {
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
    ll depth_limit;
    cout << "Enter depth limit: ";
    cin >> depth_limit;

    // Initialize visited array to false
    fill(vis, vis + N, false);

    // Call Depth-Limited Search starting from vertex 1
    dls(1, depth_limit);
    
    return 0;
}