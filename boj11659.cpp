#include <bits/stdc++.h>

using namespace std;

int n, m, x, a, b;
int sum[100001] = {};

int main(void){
  freopen("input.txt", "r", stdin);

  scanf("%d %d\n", &n, &m);

  for (int i=1; i<=n; i++){
    scanf("%d", &x);
    sum[i] = sum[i - 1] + x;
  }

  for (int i=0; i<m; i++){
    scanf("%d %d", &a, &b);
    printf("%d\n", sum[b] - sum[a - 1]);
  }
}