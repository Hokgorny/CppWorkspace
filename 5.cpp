#include <bits/stdc++.h>

using namespace std;

int n, m, s;

void bfs(vector<vector<int>> &lst, vector<int> &ss){
  int cnt = 0;
  vector<pair<int, int>> arrivals;
  queue<pair<int, int>> q;
  q.push({0, 1});

  if (find(ss.begin(), ss.end(), 1) != ss.end()){
    cout << "Yes";
    return;
  }

  while(!q.empty()){
    int limit = q.front().first;
    int now = q.front().second;
    q.pop();

    if (lst[now].size() == 0) arrivals.push_back({limit, now});
    else {
      for (int i=0; i<lst[now].size(); i++){
        int newlimit = limit;
        int next = lst[now][i];
        if (find(ss.begin(), ss.end(), next) != ss.end()){
          newlimit++;
        }
        q.push({newlimit, next});
      }
    }
  }
  sort(arrivals.begin(), arrivals.end());
  if(arrivals[0].first == 0) cout << "yes";
  else cout << "Yes";
}

int main(void){
  ios_base::sync_with_stdio(false); // scanf 사용시 아래 두 문장 삭제
  cin.tie(nullptr);

  cin >> n >> m;
  vector<vector<int>> lst(n + 1, vector<int> ());
  for (int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    lst[u].push_back(v);
  }
  cin >> s;
  vector<int> ss(s);
  for (int i=0; i<s; i++){
    int w;
    cin >> w;
    ss.push_back(w);
  }
  bfs(lst, ss);
}