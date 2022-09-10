#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
int t,n,x;
string cmd,arr;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		deque<int> a;
		cin >> cmd >> n >> arr;
		x = 0;
		for(char c: arr){
			if(c == '[' || c == ']') continue;
			if(c >= '0' && c <= '9') x = x*10 + c-'0';
			else{
				if(x > 0) a.push_back(x);
				x = 0;
			}
		}
		if(x > 0) a.push_back(x);
		
		bool error = false, rev = false;
		for(char c: cmd){
			if(c == 'R') rev = !rev;
			else{
				if(a.empty()){
					error = true;
					break;
				}
				if(rev) a.pop_back();
				else a.pop_front();
			}
		}
		if(error){
			cout << "error" << '\n';
			continue;
		}
		if(rev) reverse(a.begin(), a.end());
		cout << "[";
		for(int i=0; i<a.size(); i++){
			cout << a[i];
			if(i != a.size() - 1) cout << ",";
		}
		cout << "]\n";
	}
	return 0;
}
