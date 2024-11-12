#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const ll N = 1e5+10;

vector<ll>g[N];
bool vis[N];

void dfs(ll vertex)
{
    cout<<"Vertex : "<<vertex<<endl;
    vis[vertex] = true;     //visited naki nah
    for( ll child : g[vertex])
    {
        cout<<"Parent : "<<vertex<<" Child : "<<child<<endl;
        if(vis[child]) continue;    //child ki visited naki
        dfs(child);
    }
}

int main()
{
    ll n, m;
    cin >> n >> m ;
    for (ll i = 0 ; i < 9 ; i++) 
    {
        ll v1, v2;
        cin >> v1 >> v2 ;
        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }
    dfs(1);
   
}


// input
// 6 9
// 1 3
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 4 6
// 5 6