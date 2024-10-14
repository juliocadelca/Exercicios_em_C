#include <stdio.h>
#include <stdlib.h>
int fatorial (int n) {
	int i, f = 1;
	for (i = 1; i <= n; i++) {
		f = f * i;
	}
	return f;
}
int main() {
	int x, y;
	printf("Digite um valor inteiro: ");
	scanf("%d", &x);
	if(x > 0) {
		printf("X eh positivo\n");
		y = fatorial(x);
		printf("Fatorial de x eh %d\n");
		} else {
			if(x < 0) {
				printf("X eh negativo\n");
			} else {
				printf("X eh zero\n");
			}
		}
		printf("Fim do programa\n");
		system("pause");
		return 0;
}