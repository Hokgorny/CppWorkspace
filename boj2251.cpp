#include <bits/stdc++.h>

using namespace std;

int a, b, c;
bool visited[201][201][201];
vector<int> ans;

void bfs(){
  queue<tuple<int, int, int>> q;
  q.push({0, 0, c});
  visited[0][0][c] = true;
  ans.push_back(c);

  while(!q.empty()){
    int nowa = get<0>(q.front());
    int nowb = get<1>(q.front());
    int nowc = get<2>(q.front());
    q.pop();

    for (int i=0; i<6; i++){
      int nexta = nowa;
      int nextb = nowb;
      int nextc = nowc;
      if (i == 0){
        // a -> b
        if (nowa - (b - nowb) >= 0){ // a 물이 더 많다
          nexta = nowa - (b - nowb);
          nextb = b;
        }
        else {
          nexta = 0;
          nextb = nowb + nowa;
        }
      } else if (i == 1){
        // a -> c
        if (nowa - (c - nowc) >= 0){ // a 물이 더 많다
          nexta = nowa - (c - nowc);
          nextc = c;
        }
        else {
          nexta = 0;
          nextc = nowc + nowa;
        }
      } else if (i == 2){
        // b -> a
        if (nowb - (a - nowa) >= 0){ // b 물이 더 많다
          nextb = nowb - (a - nowa);
          nexta = a;
        }
        else {
          nextb = 0;
          nexta = nowa + nowb;
        }
      } else if (i == 3){
        // b -> c
        if (nowb - (c - nowc) >= 0){ // b 물이 더 많다
          nextb = nowb - (c - nowc);
          nextc = c;
        }
        else {
          nextb = 0;
          nextc = nowc + nowb;
        }
      } else if (i == 4){
        // c -> a
        if (nowc - (a - nowa) >= 0){ // c 물이 더 많다
          nextc = nowc - (a - nowa);
          nexta = a;
        }
        else {
          nextc = 0;
          nexta = nowa + nowc;
        }
      } else if (i == 5){
        // c -> b
        if (nowc - (b - nowb) >= 0){ // c 물이 더 많다
          nextc = nowc - (b - nowb);
          nextb = b;
        }
        else {
          nextc = 0;
          nextb = nowb + nowc;
        }
      }
      if (visited[nexta][nextb][nextc]) continue;
      if (nexta == 0) ans.push_back(nextc);
      if (!visited[nexta][nextb][nextc]){
        q.push({nexta, nextb, nextc});
        visited[nexta][nextb][nextc] = true;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  cin >> a >> b >> c;
  bfs();
  sort(ans.begin(), ans.end());
  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << ' ';
  }
}