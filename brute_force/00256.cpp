#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	char format[20], fn[20];
	int N, R, i,j, can,a,b, half;
	vector<int> p[4];
	for (i = 0; i < 4; i++) {
		R = pow(10, (i + 1) * 2);
		half = pow(10, i + 1);
		for (j = 0; j < R; j++) {
			can = 1;
			a = j / half;
			b = j % half;
			if ((a + b)*(a + b) == j)
				p[i].push_back(j);
		}
	}
	while (~scanf("%d", &N)) {
		sprintf(fn, "%dd\n", N);
		strcpy(format, "%0");
		strcat(format, fn);
		N = N / 2 - 1;		
		for (int& v : p[N])
			printf(format, v);
	}
	return 0;
}
