#include<bits/stdc++.h>
using namespace std;

int n;
vector<tuple<string,int,int,int>> v;
 
bool cmp(tuple<string,int,int,int> a, tuple<string,int,int,int> b){
    string a1,b1;
    a1[0] = tolower(a1[0]);
    b1[0] = tolower(b1[0]);
    int a2,a3,a4;
    int b2,b3,b4;
    tie(a1,a2,a3,a4) = a;
    tie(b1,b2,b3,b4) = b;
    if(a2 != b2) return a2 > b2;
    else if(a2 == b2 && a3 == b3 && a4 == b4) return a1 < b1;
    else if(a2 == b2 && a3 == b3) return a4 > b4;
    else if(a2 == b2) return a3 < b3; 
    
}

void init_vector(){
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        int a,b,c;
        //s: 이름, a:국어, b: 영어, c: 수학
        cin >> s >> a >> b >> c;
        v.push_back({s,a,b,c});
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    init_vector();    
    sort(v.begin(), v.end(),cmp);
    for(int i =0; i< v.size(); i++){
        string v1; int v2,v3,v4;
        tie(v1,v2,v3,v4) = v[i];

        cout << v1 << '\n';
    }
}
