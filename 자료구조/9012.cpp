#include<iostream>
#include<string>
#include<stack>
using namespace std;
int t;
bool chk(string ps){
	stack<char> st;
	for(int i=0; i<ps.size(); i++){
		if(st.empty()) st.push(ps[i]);
		else if(st.top() == '(' && ps[i] == ')') st.pop();
		else{
			st.push(ps[i]);
		}
	}
	if(st.empty()) return true;
	return false;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(chk(s)){
			cout << "YES" << '\n';
		}else{
			cout << "NO" << '\n';
		}
	}
	return 0;
}
