#include<iostream>
#include<stack>
#include<utility>
#include<vector>
#include<cstring>
using namespace std;
int n;
stack<int> st;
vector<int> v;
int d[1000004];
int ret[1000004];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	memset(ret, -1, sizeof(ret));
	for(int i=0; i<n; i++){
		cin >> d[i];
		v.push_back(d[i]);
		while(!st.empty() && d[st.top()] < d[i]){
			ret[st.top()] = d[i];
			st.pop();
		}
		st.push(i);
	}
	for(int i =0; i<n; i++){
		cout << ret[i] << ' ';
	}
	return 0;
}
