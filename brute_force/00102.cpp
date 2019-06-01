#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	const char* bin = "BGC";
	int i, j, A[9], idx[3], ans, sum, aidx[3], can;
	while (1) {
		if (!(~scanf("%d", &A[0])))
			break;
		for (i = 1; i < 9; i++) scanf("%d", &A[i]);
		for (i = 0; i < 3; i++) aidx[i] = idx[i] = i;
		ans = 1e9;
		do {
			sum = 0;
			for (i = 0; i < 3; i++) for (j = 0; j < 3; j++)
				if (idx[i] != j) sum += A[i * 3 + j];
			if (ans > sum) {
				ans = sum;
				for (i = 0; i < 3; i++) aidx[i] = idx[i];
			}
			else if (ans == sum) {
				for (i = 0; i < 3; i++) printf("%c", bin[aidx[i]]);
				puts("");
				for (i = 0; i < 3; i++) printf("%c", bin[idx[i]]);
				puts("");
				can = 0;
				for (i = 0; i < 3; i++) if (bin[aidx[i]] != bin[idx[i]]) {
					can = bin[aidx[i]] > bin[idx[i]];
					break;
				}
				if(can)
					for (i = 0; i < 3; i++) aidx[i] = idx[i];
			}
		} while (next_permutation(idx, idx + 3));
		for (i = 0; i < 3; i++) printf("%c", bin[aidx[i]]);
		printf(" %d\n", ans);
	}
	return 0;
}
