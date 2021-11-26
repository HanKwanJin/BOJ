#include<bits/stdc++.h>
using namespace std;

int arr[200001];
int n;
int L;
bool chk(){
    double sum =0;
    for(int i=n-1; i > 0; i--){
        sum += arr[i];
        int min = (arr[i-1] -L);
        int max = (arr[i-1] +L);
        if(min < (sum/(n-i)) && (sum/(n-i)) < max) continue;
        else return false;
    }
    return true;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L;
    
    for(int i=0; i < n; i++){
        cin >> arr[i];
    }

    if(chk()){
        cout << "stable";
        return 0;
    }else{
        cout << "unstable";
        return 0;
    }
    

}