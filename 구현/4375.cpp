#include<iostream>
#include<string>
typedef long long ll;
using namespace std;

ll n;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin >> n){
		ll cnt = 1;
		ll k = 1;
		while(true){
			if(cnt % n == 0){
				cout << k << '\n';
				break;
			}else{
				cnt = (cnt * 10) + 1;
				cnt %= n;
				k++;
			}
		}
	}
	return 0;
}
