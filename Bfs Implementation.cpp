#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100];// kontar sate konta connected 
bool vis[100];// visited chake korar jonno 

void bfs(int s)
{
    queue<int> q;
    
    q.push(s);
    vis[s] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for(int v : adj[u])
        {
            if(!vis[v])
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
    cin >> n >> e;

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(0);

    return 0;
}
