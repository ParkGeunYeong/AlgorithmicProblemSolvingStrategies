#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> fence;

int maxFence(int left, int right) {
	if (left == right) return fence[left];
	int mid = (left + right) / 2;
	int maxRect = max(maxFence(left, mid) , maxFence(mid + 1, right));

	int s_left = mid, s_right = mid + 1;
	int hight = min(fence[s_left], fence[s_right]);
	maxRect = max(maxRect, hight * 2);


	while (left < s_left || s_right < right) {
		if (s_right < right && (s_left == left || fence[s_left - 1] < fence[s_right + 1])) {
			++s_right;
			hight = min(hight, fence[s_right]);
		}
		else {
			--s_left;
			hight = min(hight, fence[s_left]);
		}
		maxRect = max(maxRect, (s_right - s_left + 1) * hight);
	}
	return maxRect;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c, n;
	cin >> c;
	while (c--) {
		cin >> n;
		int num;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			fence.push_back(num);
		}
		cout << maxFence(0, n-1)  << endl;
		vector<int>().swap(fence);
	}
	return 0;
}