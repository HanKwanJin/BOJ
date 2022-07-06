#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		getline(cin, s);
		stack<char> st;
		bool chk = true;
		if(s == ".") break;
		for(auto c: s){
			if(c == '(' || c == '[') st.push(c);
			else if(c == ')'){
				if(st.empty() || st.top() != '('){
					chk = false;
					break;
				}else{
					st.pop();
				}
			}else if(c == ']'){
				if(st.empty() || st.top() != '['){
					chk = false;
					break;
				}else{
					st.pop();
				}
			}
		}
		if(!st.empty()){
			chk = false;
		}
		if(chk){
			cout << "yes\n";
		}else{
			cout << "no\n";
		}
	}
	
	return 0;
}
