#include<iostream>
#include<string>
#include<set> 
using namespace std;

set<string> s;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin >> a;
    for(int i=0; i < a.length(); i++){
        for(int j=0; j < a.length(); j++){
            s.insert(a.substr(i,j));
        }
    }
    cout << s.size();
}