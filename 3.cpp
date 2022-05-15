#include <bits/stdc++.h>

using namespace std;

int n, ccnt = 0, nccnt = 0;
char s[100001];

int main(void){
  ios_base::sync_with_stdio(false); // scanf 사용시 아래 두 문장 삭제
  cin.tie(nullptr);

  cin >> n;
  for (int i=0; i<n; i++){
    char c;
    cin >> c;
    if (c == 'C') ccnt++;
    else nccnt++;
  }
  if (nccnt == 0) cout << ccnt;
  else{
    cout << ceil((double) ccnt / (double) (nccnt + 1));
  }
}