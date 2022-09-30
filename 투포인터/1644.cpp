#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int chk[4000001];
int n,ret;
int l,r;
vector<int> v;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=2; i<=n; i++){
        if(chk[i]) continue;
        for(int j=2*i; j <= n; j += i){
            chk[j] = 1; //소수 아닌 것들 체크해줌
        }
    }
    for(int i=2; i<=n; i++){
        if(!chk[i]) v.push_back(i);
    }
    int sum = 0;
    while(1){
        if(sum >= n) sum -= v[l++];
        else if(r == v.size()) break;
        else sum += v[r++];
        if(sum == n) ret++;
    }
    cout << ret << '\n';
}