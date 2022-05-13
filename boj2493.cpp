#include <bits/stdc++.h>

using namespace std;

int n, h;
stack<pair<int, int>> s; // 높이, 좌표

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> n;
  for (int i=1; i<=n; i++){ // i는 인덱스
    cin >> h; // h는 높이
    while(!s.empty()){ 
      if(s.top().first > h){ // 스택 요소 중에서 높이가 더 높은게 있다면
        cout << s.top().second << ' '; // 그것의 인덱스를 출력하고
        break; // while 빠져나가서 pop안되도록 한다.
      }
      s.pop(); // 지금 들어온 요소보다 작은 높이이고, 큰 것을 만나기 전이므로 삭제
    }
    if (s.empty()) cout << "0 ";
    s.push({h, i});
  }
}