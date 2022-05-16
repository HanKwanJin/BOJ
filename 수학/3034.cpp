#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,w,h;
    cin >> n >> w >> h;
    for(int i=0; i<n; i++){
        int x; 
        cin >> x;
        if(x <= sqrt(pow(w,2) + pow(h,2))){
            cout << "DA" << '\n';
        }else{
            cout << "NE" << '\n';
        }
    }
    return 0;
}