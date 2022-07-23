#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int k;
bool num[14];
char v[14];
vector<string> a;
void func(int n, int cnt, string ret){ //n은 다음에 올 숫자 
	if(cnt - 1 == k){
		a.push_back(ret);
		return;
	}
	if(cnt == 0){
		for(int i=0; i<=9; i++){
			if(!num[i]){
				num[i] = 1;
				func(i, cnt+1, ret + to_string(i));
				num[i] = 0;
			}
		}
	}else if(v[cnt] == '<'){
		for(int i=n + 1; i<=9; i++){
			if(!num[i]){
				num[i] = 1;
				func(i, cnt+1, ret + to_string(i));
				num[i] = 0;
			}
		}
	}else if(v[cnt] == '>'){
		for(int i=n - 1; i>=0; i--){
			if(!num[i]){
				num[i] = 1;
				func(i, cnt+1, ret + to_string(i));
				num[i] = 0;
			}
		}
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k;
	for(int i=1; i<=k; i++){
		cin >> v[i];
	}
	func(0,0, "");
	sort(a.begin(), a.end());
	cout << a[a.size() -1] << '\n' << a[0];
	return 0;
}
