#include<iostream>
#include<string>
using namespace std;

int d[200001][26];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    d[0][s[0]-'a']++;
    for(int i=1; i<s.length(); i++){
        for(int j=0; j<26; j++){
            d[i][j] = d[i-1][j];
        }
        int cur = s[i] - 'a';
        d[i][cur]++;
    }
    int n;
    cin >> n;
    while(n--){
        char a;
        int st, en;
        cin >> a >> st >> en;
        int p1 = st > 0 ? d[st-1][a-'a'] : 0;
        int p2 = d[en][a-'a'];
        cout << p2 - p1 << '\n';
    }
    return 0;
}