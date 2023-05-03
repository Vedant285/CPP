#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    vector<int> bellman_ford(int v, vector<vector<int>> &edges, int s)
    {
        vector<int> dist(v, 1e8);
        dist[s] = 0;
        for (int i = 0; i < v - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v])
            {
                return {-1};
            }
        }
        return dist;
    }
};
int main()
{
    int v;
    cout << "enter no. of edges" << endl;
    cin >> v;
    vector<vector<int>> edges(v, vector<int>(3));
    cout << "Enter the value of u,v,w" << endl;
    for (int i = 0; i < v; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    int s = 0;
    solution obj;
    vector<int> dist = obj.bellman_ford(v, edges, s);
    for (int i = 0; i < v; i++)
    {
        cout << dist[i] << '\t';
    }
}