// #include<iostream>
// #include<stack>
// #include<string>
// #include<algorithm>
// using namespace std;
// string a,b,ret;
// stack<char> st;
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
    
//     cin >> a >> b;
//     for(int i=0; i<a.size(); i++){
//         st.push(a[i]);
//         if(st.size() >= b.size() && st.top() == b[b.size()-1]){
//             string tmp = "";
//             for(auto e: b){
//                 tmp += st.top();
//                 st.pop();
//             }
//             reverse(tmp.begin(), tmp.end());
//             if(tmp != b){
//                 for(auto e: tmp){
//                     st.push(e);
//                 }
//             }
//         }
//     }
//     if(st.empty()){
//         cout << "FRULA";
//         return 0;
//     }
//     while(!st.empty()){
//         ret += st.top();
//         st.pop();
//     }
//     reverse(ret.begin(), ret.end());
//     cout << ret;
//     return 0;
// }

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a,b,ret;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    for(int i=0; i<a.size(); i++){
        ret += a[i];
        if(ret.size()>=b.size() && ret.substr(ret.size()-b.size(), b.size()) == b){
            ret.erase(ret.size()-b.size(), b.size());
        }
    }
    if(ret != "") cout << ret;
    else cout << "FRULA";
    return 0;
}