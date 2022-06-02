#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string p, pre, suf;
	int n;
	cin >> n;
	cin >> p;
	int pos = p.find('*');
	pre = p.substr(0, pos);
	suf = p.substr(pos+1);
	while(n--){
		string s;
		cin >> s;
		if(pre.size() + suf.size() > s.size()){
			cout << "NE" << '\n';
		}else{
			if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())){
				cout << "DA" << '\n';
			}else{
				cout << "NE" << '\n';
			}
		}
	}
	return 0;
}
