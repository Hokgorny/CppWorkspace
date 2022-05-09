#include <iostream> //2022 05 07
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int x, vector<bool> &visited, vector<vector<int>> &g){
    visited[x] = true;
    cout << x << ' ';

    for (int i=0; i<g[x].size(); i++){
        if (!visited[g[x][i]]) dfs(g[x][i], visited, g);
    }
}

void bfs(int x, vector<bool> &visited, vector<vector<int>> &g){
    queue<int> q;
    q.push(x);
    visited[x] = true;
    cout << x << ' ';

    while (!q.empty()){
        int y = q.front();
        q.pop();

        for (int i=0; i<g[y].size(); i++){
            if (!visited[g[y][i]]){
                q.push(g[y][i]);
                visited[g[y][i]] = true;
                cout << g[y][i] << ' ';
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);

    int n, m, v;
    cin >> n >> m >> v;
    vector<bool> visited(n + 1, false);
    vector<vector<int>> g(10000, vector<int>(0, 0));
    for (int i=1; i<=m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    for (int i=1; i<=n; i++){
        sort(g[i].begin(), g[i].end());
    }
    vector<bool> visited2 = visited;
    vector<vector<int>> g2 = g;

    dfs(v, visited, g);
    cout << '\n';
    bfs(v, visited2, g2);

    return 0;
}