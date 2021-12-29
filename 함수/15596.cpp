//정수 N개의 합
#include <vector>
#include <numeric>
using namespace std;
//accumulate함수는 numberic을 선언 하면 사용할 수 있다.
//처음과 두번째 인자는 어디서 어디까지 더할건지를 정한다.
//세번째 인자는 ans 변수의 초기값을 정해준다.
//long long 형 변수에 선언할때는 LL를 붙여주어야한다.
long long sum(vector<int> &a) {
	long long ans = accumulate(a.begin(), a.end(), 0LL);
	return ans;
}
