#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;

int n,m;
map<string, int> dogam;
vector<string> pocketmon;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        dogam.insert({s, i+1});
        pocketmon.push_back(s);
    }
    for(int i=0; i<m; i++){
        char s[21];
        cin >> s;
        if(atoi(s)){
            cout << pocketmon[atoi(s) - 1] << '\n';
        }else{
            cout << dogam[(string)s] << '\n';
        }
    }
}