#include<bits/stdc++.h>
using namespace std;

int p;

vector<int> v[9] = {
    {0,1,3}, {0,1,2,4}, {1,2,5},
    {0,3,4,6}, {1,3,4,5,7}, {2,4,5,8},
    {3,6,7}, {4,6,7,8}, {5,7,8}
};

//set find 함수-> 인자가 존재 할 경우 인자가 위치한 iter 리턴, 없으면 end() iter 리턴
int fun(string a){
    queue<pair<string,int>> q;
    set<string> s;

    //init
    q.push({".........",1});
    s.insert(".........");
    while(!q.empty()){
        string cur = q.front().first;
        int d = q.front().second;
        q.pop(); 
        for(int i=0; i< 9; i++){
            string nx = cur;
            for(int j=0; j<v[i].size(); j++){
                if(nx[v[i][j]] == '*'){
                    nx[v[i][j]] = '.';
                }else{
                    nx[v[i][j]] = '*';
                }
            }
            if(nx == a) return d;
            //이미 존재하면 continue
            if(s.find(nx) != s.end()) continue;
            q.push({nx,d+1}); 
            s.insert(nx);
            
        }
        
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> p;
    //흰색 0 , 검은색 1
    while(p--){
        string a;
        for(int i=0; i<3; i++){
            string s;
            cin >> s;
            for(int j=0; j<3; j++){
                if(s[j] == '.') a += '.';
                else a += '*';
            }
        }
        //처음부터 전부 흰색
        if(a == "........."){
            cout << 0 << '\n';
        }else{
            cout << fun(a) << '\n';
        }
    }
}
