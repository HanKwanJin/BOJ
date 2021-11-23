#include<bits/stdc++.h>
using namespace std;

int n,c;
int cnt;
vector<int> ans;
map<int,int> order; //순서 저장
map<int,int> m; //key -> num, value -> cnt
vector<pair<int,int>> v;
//빈도가 높은 순으로 + 빈도가 높다면 먼저 들어온 순서대로

bool cmp(pair<int,int> a, pair<int,int> b){
    //빈도가 같다면
    if(a.first == b.first) return order[a.second] < order[b.second];
    //빈도가 같지 않다면 빈도가 높은 순으로 정렬
    return a.first > b.first;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    
    for(int i=0; i< n; i++){ 
        int num;
        cin >> num;
        m[num]++;
        if(order[num] == 0) order[num] = i+1;
    }

    for(auto i=m.begin(); i != m.end(); i++){
        v.push_back({i->second, i->first}); //1. cnt 2. key
    }

    sort(v.begin(), v.end(), cmp);


    for(int i=0; i< v.size(); i++){
        for(int j=0; j< v[i].first; j++){
            ans.push_back(v[i].second);
        }
    }

    for(int i=0; i<n; i++){
        cout <<ans[i] << ' ';
    }


}
