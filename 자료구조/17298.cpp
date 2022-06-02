#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int arr[1000001];
int ret[1000001];
stack<int> st;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	for(int i=n-1; i>=0; i--){
		while(!st.empty() && st.top() <= arr[i]){
			st.pop();				
		}
		if(st.empty()) ret[i] = -1;
		else ret[i] = st.top();
		
		st.push(arr[i]);
	}
	for(int i=0; i<n; i++){
		cout << ret[i] << " ";
	}
	return 0;
}
