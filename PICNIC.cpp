#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool isFriend[10][10];
bool isChosen[10];

int linkFriend(int n) {
	int ans = 0;
	int makefriend;
	bool isFin = true;
	for (int i = 0; i < n; i++) {
		if (isChosen[i] == false) {
			isFin = false;
			makefriend = i;
			break;
		}
	}
	if (isFin) return 1;
	for (int i = makefriend + 1; i < n; i++)
	{
		if (!isChosen[i] && isFriend[i][makefriend]) {
			isChosen[i] = isChosen[makefriend] = true;
			ans += linkFriend(n);
			isChosen[i] = isChosen[makefriend] = false;
		}
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c, n, m;

	cin >> c;
	while (c--) {
		cin >> n >> m;
		int s1, s2;
		for (int i = 0; i < m; i++)
		{
			cin >> s1 >> s2;
			isFriend[s1][s2] = isFriend[s2][s1] = true;
		}
		cout << linkFriend(n) << '\n';
		memset(isFriend, false, sizeof(isFriend));
		memset(isChosen, false, sizeof(isChosen));
	}

	return 0;
}