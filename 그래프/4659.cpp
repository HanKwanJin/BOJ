#include<iostream>
#include<string>
using namespace std;
string s;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while(1){
		cin >> s;
		if(s == "end") break;
		bool aeiou = false;
		bool fail = false;
		bool eeoo = false;
		int n = 0; //모음 
		int m = 0; //자음 
		for(int i=0; i< s.length(); i++){
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
				aeiou = true;
				n++;
				m = 0;
				if(n >= 3){
					fail = true;
					break;
				}
			}else{
				m++;
				n = 0;
				if(m >= 3){
					fail = true;
					break;
				}
			}
			
			if(i < s.length() - 1){
				if(s[i] == s[i+1]){
					if((s[i] == 'e' && s[i+1] == 'e') || (s[i] == 'o' && s[i+1] =='o')) continue;
					else{
						eeoo = true;
						break;
					}
				}
			}
		}
		if(!aeiou || fail || eeoo){
			cout << "<" << s << "> " << "is not " << "acceptable." << '\n';
		}else if(aeiou && !fail && !eeoo){
			cout << "<" << s << "> " << "is " << "acceptable." << '\n';
		}
	}
	return 0;
}
