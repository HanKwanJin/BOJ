#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<cmath>
#include<stack>
using namespace std;

int n,team;
int A,B, asum, bsum;
string time, pr;

vector<int> split(string input, string delimiter){
	vector<int> ret;
	long long pos = 0;
	string token = "";
	while((pos = input.find(delimiter)) != string::npos){
		token = input.substr(0, pos);
		ret.push_back(stoi(token));
		input.erase(0, pos+delimiter.length());
	}
	ret.push_back(stoi(input));
	return ret;
} 

int changeTime(string t){ //분, 초 이므로 초로 바꿈 
	vector<int> v = split(t, ":");
	return v[0] * 60 + v[1];
}

void go(int& sum, string s){
	sum += (changeTime(s) - changeTime(pr));
}

string print(int a){
	string h = "00" + to_string(a / 60);
	string m = "00" + to_string(a % 60);
	return h.substr(h.size() - 2, 2) + ":" + m.substr(m.size() - 2, 2);
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while(n--){
		cin >> team >> time;
		if(A > B) go(asum, time);
		else if(A < B) go(bsum, time);
		team == 1 ? A++ : B++;
		pr = time;
	}
	if(A>B) go(asum, "48:00");
	else if(A<B) go(bsum, "48:00");
	cout << print(asum) << '\n';
	cout << print(bsum) << '\n';
	return 0;
}
