#include <bits/stdc++.h>

using namespace std;

int x;
int goal_depth = INT_MAX;
bool visited[10000000] = {};
queue<pair<int, int>> q;

int bfs(int n){
  q.push({n, 0});

  while(!q.empty()){
    int pos = q.front().first;
    int depth = q.front().second;
    q.pop();
    visited[pos] = true;

    if (pos == 1 && depth < goal_depth){
      goal_depth = depth;
    }
    else if (visited[1] && depth > goal_depth){
      return goal_depth;
    }
    else {
      for (double i : {(double) pos / (double) 3, (double) pos / (double) 2, (double) pos - 1}){
        if ((int) i != i) continue;
        else if (!visited[(int) i]) q.push({(int) i, depth + 1});
      }
    }
  }
  return goal_depth;
}

int main(void){
  cin >> x;
  cout << bfs(x);
}