#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n, m, tmp, ml,u,v;
const int SIZE = 100004;
vector<vector<int>> vv;
int depth[SIZE];
int ac[SIZE][17];

void getTree(int cur, int p){
    depth[cur] = depth[p] + 1;
    ac[cur][0] = p;
    for(int i=1; i<=ml; i++){
        tmp = ac[cur][i-1];
        ac[cur][i] = ac[tmp][i-1];
    }
    int len = vv[cur].size();
    for(int i=0; i<len; i++){
        int c = vv[cur][i];
        if(c != p) getTree(c, cur);
    }
}
int find_LCA(int a, int b){
    for(int i=ml; i>=0; i--){
        if(depth[a] <= depth[ac[b][i]]) b = ac[b][i];
    }
    if(a == b) return a;
    for(int i=ml; i>=0; i--){
        if(ac[a][i] != ac[b][i]) a = ac[a][i], b = ac[b][i];
    }
    return ac[a][0];
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vv = vector<vector<int>>(n+1);
    for(int i=1; i<n; i++){
        cin >> u >> v;
        vv[u].push_back(v);
        vv[v].push_back(u);
    }
    ml = (int)floor(log2(SIZE));
    depth[0] = -1;
    getTree(1,0);
    cin >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        if(depth[a] > depth[b]) swap(a,b);
        cout << find_LCA(a,b) << '\n';
    }
    return 0;
}