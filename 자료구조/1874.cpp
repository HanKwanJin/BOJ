#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int d[100001];
int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    stack<int> st;    
    vector<char> v;
    cin >> n;
    int cnt = 1;
    for(int i=0; i < n; i++){
        int x;
        cin >> x;
        while(cnt <= x){
            st.push(cnt);
            cnt++;
            v.push_back('+');
        }

        if(st.top() == x){
            st.pop();
            v.push_back('-');
        }else{
            cout << "NO";
            return 0;
        }
    }
    for(char c : v){
        cout << c << '\n';
    }
}