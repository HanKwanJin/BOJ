//카드 정렬하기
#include<bits/stdc++.h>
using namespace std;

int n;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--){
        int x;
        cin >> x;
        pq.push(x);
    }

    int ret = 0;
    while(pq.size() >= 2){ // 두개 이상 있어야 비교가 가능함
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a+b);
        ret += a+b;
    } 
    cout << ret;
}