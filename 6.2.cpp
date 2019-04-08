#include <iostream>
#include <vector>
using namespace std;

//�ڵ� 6.1 1~n ������ �� for VS recursion
int sum(int n) {
	int ret = 0;
	for (int i = 1; i <= n; ++i)
	{
		ret += i;
	}
	return ret;
}

int recursiveSum(int n) {
	if (n == 1) return 1; //���̻� �ɰ����� ���� ��, �������
	return n + recursiveSum(n - 1); //�ɰ��� ó��
}

//���� ��ø �ݺ����� ��ü�ϱ� - 0���� ���ʴ�� ������ n���� ���ҿ��� m�� �̱�
//for ������ ���� �� ( m�� 3�̶�� ���� ) --> m�� ���� for���� ���� ����
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
//����Լ��� ����ϱ� - �� for���� �������� ������.
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
// ���۰���
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