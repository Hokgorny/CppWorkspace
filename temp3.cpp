#include <bits/stdc++.h>
using namespace std;

int N, M, L, R, A[1010][1010], Si, Sj;
int ID[1010][1010], C;
pair<int,int> D[1010101];
vector<int> G[1010101][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> L >> R;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            char c; cin >> c; 
            A[i][j] = c - '0';
            if(A[i][j] == 2) tie(Si,Sj) = tie(i,j), A[i][j] = 0;
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(ID[i][j] || A[i][j]) continue;
            ID[i][j] = ++C;
            for(int k=i+1; k<=N; k++) if(!A[k][j]) ID[k][j] = C; else break;
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(ID[i][j-1] && ID[i][j] != ID[i][j-1]) G[ID[i][j]][0].push_back(ID[i][j-1]);
            if(ID[i][j+1] && ID[i][j] != ID[i][j+1]) G[ID[i][j]][1].push_back(ID[i][j+1]);
        }
    }
    int S = ID[Si][Sj];

    memset(D, -1, sizeof D);
    queue<int> Q; Q.push(S); D[S] = {0, 0};
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        for(auto i : G[v][0]){
            if(D[v].first < L && D[i].first == -1){
                D[i] = D[v]; D[i].first += 1;
                Q.push(i);
            }
        }
        for(auto i : G[v][1]){
            if(D[v].second < R && D[i].second == -1){
                D[i] = D[v]; D[i].second += 1;
                Q.push(i);
            }
        }
    }
    int cnt = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(ID[i][j] && D[ID[i][j]].first != -1) cnt++;
        }
    }
    cout << cnt;
}