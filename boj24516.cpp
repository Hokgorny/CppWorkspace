#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  cin >> n;

  for (int i=0; i<n; i++){
    cout << 1 + 4 * i << " ";
  }

  return 0;
}