#include<iostream>
#include<string>
using namespace std;

int d[26];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		d[s[0] - 'a']++;
	}
	bool chk = false;
	for(int i=0; i<26; i++){
		if(d[i] >=5){
			cout << (char)(i+'a');
			//string ret = i + 'a'; 하면 아스키코드가 바로 문자로 바뀜  
			chk = true;
		}
	}
	if(!chk) cout << "PREDAJA";
	return 0;
}
