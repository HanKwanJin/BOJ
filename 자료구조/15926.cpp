#include<iostream>
#include<string>
#include<stack>
using namespace std;
int n;
int ans;
stack<char> st;
stack<int> ret;
string s;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> s;
	ret.push(0);
	for(int i=1; i<=n; i++){
		if(s[i-1] == '('){
			st.push('(');
			ret.push(i);
		}
		if(st.empty() && s[i-1] == ')'){
			ret.push(i);
		}
		if(!st.empty()){
			if(st.top() == '(' && s[i-1] == ')'){
				st.pop();
				ret.pop();
				ans = max(ans, i - ret.top());
			}
		}
	}
	cout << ans;
	return 0;
}
