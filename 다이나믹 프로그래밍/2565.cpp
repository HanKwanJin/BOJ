//전깃줄
#include<bits/stdc++.h>
using namespace std;

int n;
struct line
{
    int left;
    int right;
};
int dp[101];
line l[101];
bool cmp(line a, line b){
    if(a.left < b.left) return true;
    return false;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> l[i].left >> l[i].right;
    }
    int mx = 0;
    sort(l+1, l+n+1, cmp);
    for(int i=1; i <= n; i++){
        dp[i] = 1;
        for(int j=1; j<i; j++)
        {
            if(l[i].right > l[j].right){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        mx = max(mx, dp[i]); 
    }
    cout << n - mx << '\n';
    return 0;
}