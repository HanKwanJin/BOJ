//셀프 넘버
#include<bits/stdc++.h>
using namespace std;

bool arr[10001];
int d(int n){
    
    int ns = to_string(n).size();
    int ret = n;
    for(int i=0; i<ns; i++)
    {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

void self_num(){
    arr[1] = false;
    for(int i=1; i<= 10000; i++){
        int num = d(i);
        if(num <= 10000){
            arr[num] = true;
        }
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    self_num();
    for(int i=1; i<= 10000; i++){
        if(!arr[i]){
            cout << i << '\n';
        }
    }
}