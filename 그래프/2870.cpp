#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n;
vector<string> ret;
string s, tmp; 

bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}

void func(){
	if(tmp.size()){
		while(true){
			if(tmp.size() && tmp.front() == '0') tmp.erase(tmp.begin());
			else break;
		}
		if(tmp.size() == 0) tmp = "0";
		ret.push_back(tmp);
		tmp = "";
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while(n--){
		cin >> s;
		for(int i=0; i<s.size(); i++){
			if(s[i] >= '0' && s[i] <= '9') tmp += s[i];
			else{
				func();
			}
		}
		func();
	}
	sort(ret.begin(), ret.end(), cmp);
	for(auto e: ret){
		cout << e << '\n';
	}
	return 0;
}
