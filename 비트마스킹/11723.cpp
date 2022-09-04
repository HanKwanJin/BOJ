#include<iostream>
#include<set>
#include<string>
using namespace std;
string c;
int n;
int k;
int x;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while(n--){
		cin >> c;
		if(c == "add"){
			cin >> x;
			if(!(k & (1 << x))){
				k |= (1 << x);
			}
		}else if(c == "remove"){
			cin >> x;
			if((k & (1 << x))){
				k &= ~(1 << x);
			}
		}else if(c == "check"){
			cin >> x;
			if(k & (1 << x)){
				cout << 1 << '\n';
			}else{
				cout << 0 << '\n';
			}
		}else if(c == "toggle"){
			cin >> x;
			k ^= (1 << x);
		}else if(c == "all"){
			k = (1 << 21) - 1;
		}else if(c == "empty"){
			k = 0;
		}
	}
	return 0;
}
