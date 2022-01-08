//LCS
#include<bits/stdc++.h>
using namespace std;
string a,b;
int d[1001][1001]; //d[a][b]
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    cin >> b;
    int az = a.size();
    int bz = b.size();
    for(int i=1; i<= az; i++){
        for(int j=1; j<=bz; j++){
            if(a[i-1] == b[j-1]){
                d[i][j] = d[i-1][j-1] + 1;
            }else{
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }

    cout << d[az][bz]; 
     
}