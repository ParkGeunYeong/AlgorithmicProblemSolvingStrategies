#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution {
public:
	int solution(int n, vector<int> v, vector<int> ex) { // 동점일 때 투표를 한 횟수 > 회원 번호 작은 순
		vector<int> voted(n, 0);
		int maxVoted = 0;
		vector<int> vote(n, 0);
		vector<int> ansList1;
		int maxVoterInansList1 = 0;
		vector<int> ansList2;
		for (int i = 0; i < v.size(); i++)
		{
			vote[v[i]]++;
			voted[ex[i]]++;
		}
		for (int i = 0; i < n; i++)
		{
			maxVoted = max(maxVoted, voted[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (maxVoted == voted[i]) ansList1.push_back(i);
		}
		for (int i : ansList1)
		{
			maxVoterInansList1 = max(maxVoterInansList1, vote[i]);
		}
		for (int i : ansList1) {
			if (maxVoterInansList1 == vote[i]) ansList2.push_back(i);
		}
		sort(ansList2.begin(), ansList2.end());
		return ansList2.size() == 0 ? 0 : ansList2[0];
	}
};
int main() {
	int n = 5;
	vector<int> v = { 0,1,2,2,3,4 };
	vector<int> ex = { 2,2,0,1,1,1 };
	Solution s;
	cout << s.solution(n,v,ex);

	return 0;
}