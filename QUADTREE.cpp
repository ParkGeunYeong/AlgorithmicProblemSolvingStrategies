#include <iostream>
#include <string>

using namespace std;
string reverseTree(string::iterator& index) {
	char ch = *index;
	++index;
	if (ch != 'x') {
		return string(1,ch);
	}
	string ul = reverseTree(index);
	string ur = reverseTree(index);
	string dl = reverseTree(index);
	string dr = reverseTree(index);
	return string(1, 'x') +dl + dr + ul + ur;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c;
	string quadTree;
	string::iterator index;
	cin >> c;
	while (c--) {
		cin >> quadTree;
		index = quadTree.begin();
		cout << reverseTree(index) << endl;
	}
	return 0;
}