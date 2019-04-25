#include <vector>
#include <algorithm>
using namespace std;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution {
public:
	int solution(vector<int> len, int cost, int wv) {
		int ans = 0;
		sort(len.begin(), len.end());
		int maxLen = len.back();

		for (int i = 0; i < len.size(); i++) //자르지 않았을 때 최대값
		{
			int first = len[i];
			int cnt = 0;
			for (int j = i; j < len.size(); j++)
			{
				if (first == len[j]) cnt++;
				else {
					i = j;
					ans = max(ans, wv*cnt*first);
					break;
				}
			}
		}
		for (int L = 1; L <= maxLen; L++) //모든 경우의 수를 다 잘라보며 이익의 최대값 찾기
		{
			int allK = 0;
			int allCost = 0;
			for (int i : len) {
				if(i >= L){
				allK += i / L;
				allCost += i / L;
				}
				if (i%L == 0) allCost--; //남는게 나오지 않았을 때
			}
			ans = max(ans, allK * wv * L - allCost * cost);
		}
		return ans;
	}
};