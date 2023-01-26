#include <stdio.h>

int main() {
	int c;
	scanf("%d", &c);

	int ret = 0;

	for(int i = 0; i < c; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		if(a + b + c >= 2) ret++;
	}

	printf("%d", ret);
}