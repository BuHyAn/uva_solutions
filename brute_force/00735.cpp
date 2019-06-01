#include <cstdio>
#include <cstring>
int main() {
	freopen("input.txt", "r", stdin);
	int x, i,j,k,a,b,c, com_cnt, per_cnt, q,w,e, used[61][61][61];
	while (1) {
		scanf("%d", &x);
		if (x <= 0) break;
		memset(used, 0, sizeof used);
		com_cnt = per_cnt = 0;
		for (i = 0; i < 22; i++) {
			for (a = 1; a <= (!i || i == 21 ? 1 : 3); a++) {
				q = a * (i == 21 ? 50 : i);
				for (j = 0; j < 22; j++) {
					for (b = 1; b <= (!j || j == 21 ? 1 : 3); b++) {
						w = b * (j == 21 ? 50 : j);
						for (k = 0; k < 22; k++) {
							for (c = 1; c <= (!k || k == 21 ? 1 : 3); c++) {
								e = c * (k == 21 ? 50 : k);
								if (x == q + w + e && !used[q][w][e]) {
									used[q][w][e] = 1;
									per_cnt += 1;
									if (q <= w && w <= e)
										com_cnt += 1;
								}
							}
						}
					}
				}
			}
		}
		if (com_cnt) {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", x, com_cnt);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", x, per_cnt);
		}
		else printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", x);
		
		puts("**********************************************************************");
	}
	printf("END OF OUTPUT");
	return 0;
}