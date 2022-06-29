#include<iostream>
#include<string>
using namespace std;


int n;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while(n--){
		int d[2][26]{0};
		for(int i=0; i<2;i++){
			string s;
			cin >> s;
		
			for(int j=0; j<s.length(); j++){
				d[i][s[j] - 'a']++;
			}
		}
		bool chk = false;
		for(int i=0; i<26; i++){
			if(d[0][i] != d[1][i]){
				chk = true;
				break;
			}
		}
		if(!chk){
			cout << "Possible\n";
		}else{
			cout << "Impossible\n";
		}
	}
	return 0;
}
