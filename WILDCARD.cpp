#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> ans;
vector<string> ww;
vector<int> star;
string w;


void divide(string w) {
	string temp = "";
	for(int i = 0 ; i < w.size() ; i++){
		if (w[i] != '*') temp += string(1,w[i]);
		else {
			star.push_back(i);
			if (i != 0) ww.push_back(temp);
			temp = "";
		}
	}
}

bool solve(string name) {
	bool ret = false;
	int wwindex = 0;

	if (name[0] != ww[0][0] && star[0] != 0) return false;
	if (name[name.size() - 1] != ww[ww.size()-1][ww[ww.size() - 1].size()-1] && star[star.size() - 1] != w.size() - 1) return false;
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] == ww[wwindex][0]) {
			bool allmatch = true;
			for (int j = 0; j < ww[wwindex].size(); j++)
			{
				if (name[i + j] != ww[wwindex][j]) {
					if (ww[wwindex][j] == '?') continue;
					allmatch = false;
					break;
				}
			}
			if (allmatch) {
				i += ww[wwindex].size();
				wwindex++;
				if (wwindex == ww.size()) {
					ret = true;
				}
			}
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c, n;	
	cin >> c;
	while (c--) {
		cin >> w >> n;
		divide(w);
		string name;
		for (int i = 0; i < n; i++)
		{
			cin >> name;
			if (solve(name)) ans.push_back(name);
		}
		for (string i : ans) cout << i << endl;
		vector<string>().swap(ans);
		w = "";
	}
	return 0;
}