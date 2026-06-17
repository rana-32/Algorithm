#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> adj[256];
bool vis[256];

void dfs(char s)
{
    stack<char> st;
    st.push(s);

    while(!st.empty())
    {
        char u = st.top();
        st.pop();

        if(vis[u]) continue;

        vis[u] = true;
        cout << u << " ";

        for(int v : adj[u])
        {
            if(!vis[v])
            {
                st.push(v);
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
        char a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs('a');

    return 0;
}
