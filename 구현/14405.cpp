#include<iostream>
#include<string>
using namespace std;
string s;
string tmp;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i=0; i<s.size(); i++){
		tmp += s[i];
		if(tmp == "pi"){
			tmp = "";
		}else if(tmp == "ka"){
			tmp = "";
		}else if(tmp == "chu"){
			tmp = "";
		}
	}
	if(tmp == ""){
		cout <<  "YES";
	}else{
		cout << "NO";
	}
	return 0;
}
