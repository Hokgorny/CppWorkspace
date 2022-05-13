#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<int> ans;
vector<int> lst(500001, 0);

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> n;
  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
    lst[a] = i;
  }

  for (int i=v.size()-1; i>=0; i--){
    int x = v[i];
    if (lst[x] > 0) ans.push_back(lst[x]);
    for (int j=i-1; j>=0; j--){
      if (v[j] >= x){
        ans.push_back(j + 1);
        break;
      }
      if (j == 0 && v[j] < x) ans.push_back(0);
    }
  }
  ans.push_back(0);
  for (int i=ans.size()-1; i>=0; i--){
    cout << ans[i] << ' ';
  }
}