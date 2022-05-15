#include <bits/stdc++.h>

using namespace std;

int n, m;
int npoint[1001], ppoint[1001], cpoint[1001];

int main(void){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  cin >> n >> m;
  for (int i=0; i<n; i++){
    cin >> npoint[i];
  }
  for (int i=0; i<m; i++){
    cin >> ppoint[i];
  }

  int c = max(n, m);
  for (int i=0; i<c; i++){
    cpoint[i] = (npoint[i] - ppoint[i]);
  }
  int mm = *min_element(cpoint, cpoint + c);;

  if (mm > 0) cout << 0;
  else cout << -mm;
}