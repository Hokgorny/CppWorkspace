#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int x, int m, bool *visited, vector<vector<int>> &g){
    visited[x] = true;
    cout << x << endl;

    cout << "plz" << endl;

    for (int i=0; i<m; i++){ //vector g 의 원소 출력
        for (int j=0; j<2; j++){
            cout << g[i][j] << endl;
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);

    int n, m, v;
    cin >> n >> m >> v;
    
    vector<vector<int>> g(m, vector<int>(2,0));
    for (int i=0; i<m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        g[i][0] = t1;
        g[i][1] = t2;
    }
    sort(g.begin(), g.end());

    bool visited(n+1);

    dfs(1, m, &visited, g);

    return 0;
}