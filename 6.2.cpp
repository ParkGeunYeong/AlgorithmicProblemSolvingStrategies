#include <iostream>
#include <vector>
using namespace std;

//코드 6.1 1~n 까지의 합 for VS recursion
int sum(int n) {
	int ret = 0;
	for (int i = 1; i <= n; ++i)
	{
		ret += i;
	}
	return ret;
}

int recursiveSum(int n) {
	if (n == 1) return 1; //더이상 쪼개지지 않을 때, 기저사례
	return n + recursiveSum(n - 1); //쪼개서 처리
}

//예제 중첩 반복문을 대체하기 - 0부터 차례대로 쓰여진 n개의 원소에서 m개 뽑기
//for 문으로 했을 때 ( m을 3이라고 가정 ) --> m에 따라서 for문의 수가 증가
void useFor(int n){
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				cout << i << j << k << '\n';
			}
		}
	}
}
//재귀함수를 사용하기 - 각 for문을 조각으로 나눈다.
void printPicked(vector<int>& picked) {
	for (int i : picked)
		cout << i;
	cout << '\n';
}
void useRecursive(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		printPicked(picked);
		return;
	}
	int nextFirst = picked.empty() ? 0 : picked.back() + 1;
	for (; nextFirst < n; ++nextFirst) {
		picked.push_back(nextFirst);
		useRecursive(n, picked, toPick - 1);
		picked.pop_back();
	}
}
// 보글게임
int canGoR[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int canGoC[] = { 1, 0, -1, 1, -1, 1, 0, -1 };
bool hasWord(int r, int c, string word) {

}

int main() {
	vector<int> picked;
	useRecursive(8, picked, 3);
	useFor(8);

	return 0;
}