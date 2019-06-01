#include<cstdio>
int main() {
	freopen("input.txt", "r", stdin);
	char M[10000][21];
	int C, D, L[10000], H[10000], i, cnt, ai, Q, P;
	scanf("%d", &C);
	while (C--) {
		scanf("%d\n", &D);
		for (i = 0; i < D; i++) scanf("%s%d%d\n", M[i], &L[i], &H[i]);
		scanf("%d", &Q);
		while (Q--) {
			scanf("%d", &P);
			cnt = 0;
			for (i = 0; cnt < 2 && i < D; i++) if (L[i] <= P && P <= H[i]) {
				cnt += 1;
				ai = i;
			}
			printf(cnt != 1 ? "UNDETERMINED" : M[ai]);
			if (Q) puts("");
		}
		if (C) puts("");
	}
	return 0;
}
