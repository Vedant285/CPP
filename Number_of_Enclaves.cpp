#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& Enclave, int i, int j, int n, int m,vector<vector<int>>& vis)
{
    vis[i][j] == 1;
    int arr[] = {-1, 0, 1, 0};
    int arr2[] = {0, -1, 0, 1};
    for (int k = 0; k < 4; k++)
    {
        int newr = i + arr[k];
        int newc = j + arr2[k];
        if (newr >= 0 && newc >= 0 && newr < n && newc < m && Enclave[newr][newc] == 1 && !vis[newr][newc])
        {
            dfs(Enclave, newr, newc, n, m,vis);
        }
    }
}

int Count_Enclave(vector<vector<int>>& Enclave)
{
    int n = Enclave.size();
    int m = Enclave[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Enclave[i][j] == 1 && !vis[i][j] && (i * j == 0 || i == n - 1 || j == m - 1))
            {
                dfs(Enclave, i, j, n, m,vis);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Enclave[i][j] == 1 && !vis[i][j])
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    int row, col;
    cout << "Enter Row And Column of  zero Indexed Graph" << endl;
    cin >> row >> col;
    vector<vector<int>>Enclave(row,vector<int>(col));
    cout << "Enter Elements (0,1 only)" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            cin >> Enclave[i][j];
        }
    }
    cout << Count_Enclave(Enclave);
}
