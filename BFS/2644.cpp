//촌수계산
//x가 부모 y 가 자식
#include<bits/stdc++.h>
using namespace std;
vector<int> v[101];
bool vst[101];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x,y, m;
    cin >> n;
    cin >> x >> y;
    cin >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(x);
    vst[x] = 1;
    int ret = 0;
    bool chk = 0;
    while(!q.empty()){
        int qs = q.size();
        for(int i=0; i<qs; i++){
            int cur = q.front(); q.pop();
            if(cur == y){
                cout << ret;
                return 0;
            }
            for(int j = 0;j < v[cur].size(); j++){
                int t = v[cur][j];
                if(!vst[t]){
                    vst[t] = 1;
                    q.push(t);
                }
            }

        }
        ret++;
    }
    cout << -1;
    return 0;
}