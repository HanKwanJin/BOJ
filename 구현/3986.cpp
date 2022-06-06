#include<iostream>
#include<string>
#include<stack>
using namespace std;
int n;
int cnt;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	while(n--){
		string s;
		stack<char> st;
		cin >> s;
		if(s.length() % 2 == 1) continue; //���̰� Ȧ���� 2���� �ȵ�
		for(int i=0; i<s.length(); i++){
			if(i == 0){
				st.push(s[i]);
				continue;
			}
			if(!st.empty() && st.top() == s[i]){
				st.pop();
			}else{
				st.push(s[i]);
			}
		}
		if(st.empty()) cnt++;
	}
	cout << cnt;
	return 0;
}
