#include <iostream>
#include <cstring>
using namespace std;
bool board[20][20];
int Lblock[4][2][2] = {
	{{1,0},{1,1}},
	{{1,0},{0,1}},
	{{1,0},{1,-1}},
	{{0,1},{1,1}}
};


bool setBlock(int witchBlock, int y, int x, int h, int w) {
	int check1_y = Lblock[witchBlock][0][0] + y;
	int check1_x = Lblock[witchBlock][0][1] + x;
	int check2_y = Lblock[witchBlock][1][0] + y;
	int check2_x = Lblock[witchBlock][1][1] + x;
	bool check_range = check1_y < 0 || check2_y < 0 || check1_y >= h || check2_y >= h ||
		check1_x < 0 || check2_x < 0 || check1_x >= w || check2_x >= w;
	if (check_range) return false;

	if (board[check1_y][check1_x] == false && board[check2_y][check2_x] == false){
		board[y][x] = board[check1_y][check1_x] = board[check2_y][check2_x] = true;
		return true;
	}	
	else return false;
}

void rsetBlock(int witchBlock, int y, int x) {
	int check1_y = Lblock[witchBlock][0][0] + y;
	int check1_x = Lblock[witchBlock][0][1] + x;
	int check2_y = Lblock[witchBlock][1][0] + y;
	int check2_x = Lblock[witchBlock][1][1] + x;
	board[y][x] = board[check1_y][check1_x] = board[check2_y][check2_x] = false;
}

int covering(int h, int w) {
	bool allFilled = true;
	pair<int, int> fillHere;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (board[i][j] == false) {
				fillHere.first = i;
				fillHere.second = j;
				allFilled = false;
				break;
			}
		}
		if (allFilled == false) break;
	}
	if (allFilled) return 1;
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		if (setBlock(i, fillHere.first, fillHere.second, h, w)) {
			ret += covering(h, w);
			rsetBlock(i, fillHere.first, fillHere.second);
		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		int h, w, cnt = 0;
		cin >> h >> w;
		char input;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> input;
				if (input == '#') board[i][j] = true;
				else cnt++;
			}
		}
		if (cnt % 3 != 0) {
			memset(board, false, sizeof(board));
			cout << 0 << endl;
			continue;
		}
		cout << covering(h, w) << endl;
		memset(board, false, sizeof(board));
	}
	return 0;
}