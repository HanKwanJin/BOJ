#include<iostream>
#include<string>
using namespace std;
int cnt[200], flag;
char mid;
string ret;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	for(auto c: s){
		cnt[c]++;
	}
	for(int i = 'Z'; i >= 'A'; i--){
		if(cnt[i]){
			if(cnt[i] & 1){ //홀수확인 
				flag++;
				mid = char(i);
				cnt[i]--;
			}
			if(flag == 2) break;
			for(int j=0; j< cnt[i]; j+= 2){
				ret = char(i) + ret;
				ret += char(i); //앞뒤에 문자를 넣어줌 
			}
		}
	}
	if(mid) ret.insert(ret.begin() + ret.size() / 2, mid);
	if(flag == 2) cout << "I'm Sorry Hansoo";
	else cout << ret; 
	return 0;
}
