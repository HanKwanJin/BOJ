#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int ret;
void func(vector<int> &v){
    while(!(v[0] >= v[2] && v[1] >= v[5])){
        int tmp = v[0];
        v.erase(v.begin());
        v.push_back(tmp);
    }
    ret = v[0] * v[5] + v[2] * v[3];
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<6; i++){
        int dir, d;
        cin >> dir >> d;
        v.push_back(d);
    }
    func(v);
    cout << ret * n;
    return 0;
}