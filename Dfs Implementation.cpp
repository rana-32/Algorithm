#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100]; // kontar sate konta connected
bool vis[100]; // visited check korar jonno

void dfs(int u)
{
    vis[u] = true; // node visit mark

    cout << u << " "; // node print

    for(int v : adj[u]) // u er sob connected node e jabo
    {
        if(!vis[v]) // jodi age visit na hoy
        {
            dfs(v); // recursive call
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    return 0;
}
