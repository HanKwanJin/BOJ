#include<iostream>
#include<stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    int ret = 0;
    stack<int> st;
    cin >> k;
    while(k--){
        int x;
        cin >> x;
        if(x == 0){
            st.pop();
            continue;
        }
        st.push(x);
    }
    while(!st.empty()){
        ret += st.top();
        st.pop();
    }
    cout << ret;
    return 0;
}