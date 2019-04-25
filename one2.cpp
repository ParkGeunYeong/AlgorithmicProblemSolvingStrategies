#include <vector>
#include <algorithm>
using namespace std;

//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
class Solution {
public:
	int solution(vector<int> len, int cost, int wv) {
		int ans = 0;
		sort(len.begin(), len.end());
		int maxLen = len.back();

		for (int i = 0; i < len.size(); i++) //�ڸ��� �ʾ��� �� �ִ밪
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
		for (int L = 1; L <= maxLen; L++) //��� ����� ���� �� �߶󺸸� ������ �ִ밪 ã��
		{
			int allK = 0;
			int allCost = 0;
			for (int i : len) {
				if(i >= L){
				allK += i / L;
				allCost += i / L;
				}
				if (i%L == 0) allCost--; //���°� ������ �ʾ��� ��
			}
			ans = max(ans, allK * wv * L - allCost * cost);
		}
		return ans;
	}
};