#include <iostream>
#include <vector>
using namespace std;
int Clock[16];
int Min = 987654321;
vector<vector<int>> Switch = 
{
	vector<int> {0, 1, 2},
	vector<int> {3, 7, 9, 11},
	vector<int> {4, 10, 14, 15},
	vector<int> {0, 4, 5, 6, 7},
	vector<int> {6, 7, 8, 10, 12},
	vector<int> {0, 2, 14, 15},
	vector<int> {3, 14, 15},
	vector<int> {4, 5, 7, 14, 15},
	vector<int> {1, 2, 3, 4, 5},
	vector<int> {3, 4, 5, 9, 13}
};

void pushButton(int i) {
	for (auto j : Switch[i]) {
		if (Clock[j] == 12) Clock[j] = 3;
		else Clock[j] += 3;
	}
}
bool ifAll12() {
	for (int i : Clock) if (i != 12) return false;
	return true;
}

int MinPushSwitch(int push, int index) {

	if (ifAll12()) {
		if (push < Min) {
			Min = push;
		}
		return 0;
	}

	index++;
	if (index == Switch.size()) return 0;

	for (int i = 0; i < 4; i++)
	{
		push += i;
		MinPushSwitch(push, index);
		pushButton(index);
		push -= i;
	}

	return Min == 987654321 ? -1 : Min;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		for (int i = 0; i < 16; i++)
		{
			cin >> Clock[i];
		}
		Min = 987654321;
		cout << MinPushSwitch(0, -1) << endl;
	}
	return 0;
}