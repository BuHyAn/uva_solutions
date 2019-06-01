#include <cstdio>
#include <vector>
#include <algorithm>
int main() {
	freopen("input.txt", "r", stdin);
	std::vector<int> V, C;
	int N, i, A[15], B[15], used = 0;
	while (1) {
		scanf("%d", &N);
		if (!N) break;
		if (used)
			puts("");
		std::vector<std::vector<int>> A;
		V.clear(); C.clear();
		V.resize(N); C.resize(N);
		for (i = 0; i < N; i++) {
			scanf("%d", &V[i]);
			if (i < N - 6) C[i] = 0;
			else C[i] = 1;
		}
		do {
			std::vector<int> T;
			for (i = 0; i < N; i++)
				if (C[i]) T.push_back(V[i]);
			A.push_back(T);
		} while (std::next_permutation(C.begin(), C.end()));
		std::sort(A.begin(), A.end());
		for (auto X = A.begin(); X != A.end(); X++) {
			for (auto k = X->begin(); k != X->end(); k++) {
				printf("%d", *k);
				if (k != X->end() - 1) printf(" ");
			}
			printf("\n");
		}
		used = 1;
	}
	return 0;
}