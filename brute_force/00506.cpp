#include<cstdio>
#include<cassert>
#include<cstring>
const int MAX_P = 60;
int il[MAX_P], ol[MAX_P], P, topping, omit;
bool back(int p) {
	if (p == 16) {
		omit = (1 << 16) - topping - 1;
		bool can = 1;
		for (int i = 0; can && i < P; i++)
			can &= ((il[i] & topping) > 0) || ((ol[i] & omit) > 0);
		return can;
	}
	if (back(p + 1)) return 1;

	topping |= 1 << (15 - p);
	if (back(p + 1)) return 1;
	topping ^= 1 << (15 - p);
	return 0;
}
int main() {
	freopen("input.txt", "r", stdin);
	char li[40];
	int i, r, L;
	while(1){
		P = 0;
		while ((r = scanf("%s", li)) > 0) {
			//assert(f == '.' || f == ';' || f == '+' || f == '-');
			//puts(li);
			if (strcmp(li, ".") == 0) break;
			ol[P] = il[P] = 0;
			L = strlen(li);
			for (i = 0; i < L; i += 2) {
				if(li[i] == '+' || li[i] == '-')
					(li[i] == '+' ? il[P] : ol[P]) |= (1 << (li[i + 1] - 'A'));
			}
			P++;
		}
		if (r < 0) break;
		topping = 0;
		if (back(0)) {
			printf("Toppings: ");
			for (i = 0; i < 16; i++) if (topping & (1 << i))
				printf("%c", i + 'A');
		}
		else printf("No pizza can satisfy these requests.");
		puts("");
	}
	
	return 0;
}