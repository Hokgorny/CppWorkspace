#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
vector<string> lst(100001);

int main(void){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  cin >> n;
  for (int i=0; i<n; i++){
    string s;
    cin >> s;
    if (s == "ENTER") lst.clear();
    else if (find(lst.begin(), lst.end(), s) == lst.end()){
      cnt++;
      lst.push_back(s);
    }
  }
  cout << cnt;
}