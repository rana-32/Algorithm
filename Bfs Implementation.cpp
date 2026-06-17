#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[256];
bool vis[256];

void bfs(char s)
{
    queue<char> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty())
    {
        char u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;   // node + edge input

    for (int i = 0; i < e; i++)
    {
        char u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    char start;
    cin >> start;   // start node

    bfs(start);

    return 0;
}
