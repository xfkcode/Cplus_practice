# include<iostream>
using namespace std;

int main()
{
	int n = 4;
	int m = 8;
	//¿ª±Ù¿Õ¼ä
	int** pp = new int*[n];
	for (int i = 0;i < n;i++) {
		pp[i] = new int[m];
		for (int j = 0;j < m;j++) {
			pp[i][j] = 1;
		}
	}
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			cout << pp[i][j] << " ";
		}
		cout << endl;
	}
	//ÊÍ·Å
	for (int i = 0;i < n;++i) {
		delete[] pp[i];
	}
	delete[] pp;
	return 0;
}