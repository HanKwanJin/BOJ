#include<iostream> 
#include<string>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; 
	getline(cin, s);
	//65 ~ 90 대문자  97 ~ 122 소문자 
	for(int i=0; i<s.length(); i++){
		if(s[i] >= 65 && s[i] <= 90){
			if(s[i] + 13 > 90) s[i] += 13 - 26;
			else s[i] += 13;
		}else if(s[i] >= 97 && s[i] <= 122){
			if(s[i] + 13 > 122) s[i] += 13 - 26;
			else s[i] += 13;
		}
		cout << s[i];
	}
	return 0;
}
