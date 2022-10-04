#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<utility>
#include<queue>
#define num first
#define dir second
using namespace std;
int t,k,n,d,ret;
bool vst[1040];
vector<string> v;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    for(int i=0; i<t; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    cin >> k;
    queue<pair<int,int>> q; //돌릴 톱니바퀴, 방향
    vector<pair<int,int>> vv; //돌릴 순서,방향
    while(k--){
        cin >> n >> d;
        n--; //톱니바퀴 인덱스
        vv.clear();
        memset(vst, 0, sizeof(vst));
        q.push({n,d});
        vv.push_back({n,d});
        vst[n] = 1;
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            int next = cur.num + 1;
            int prev = cur.num - 1;
            //여기서 out of bound 에러남
            if(!vst[next] && next >= 0 && next < t){
                if(v[next][6] != v[cur.num][2]){
                    q.push({next, -cur.dir});
                    vv.push_back({next, -cur.dir});
                    vst[next] = 1;
                }
            }
            if(!vst[prev] && prev >= 0 && prev < t){
                if(v[prev][2] != v[cur.num][6] ){
                    q.push({prev, -cur.dir});
                    vv.push_back({prev, -cur.dir});
                    vst[prev] = 1;
                }
            }
        }
        //vv에 있는 만큼 돌려야함
        for(int i=0; i<vv.size(); i++){
            string s = v[vv[i].num];
            if(vv[i].dir == 1){
                rotate(s.rbegin(), s.rbegin()+1, s.rend());
                v[vv[i].num] = s;
            }else if(vv[i].dir == -1){
                rotate(s.begin(), s.begin()+1, s.end());
                v[vv[i].num] = s;
            }
        }
    }

    for(int i=0; i<t; i++){
        ret += v[i][0] - '0';
    }
    cout << ret << '\n';
    return 0;
}