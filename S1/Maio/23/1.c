#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE *fp;
	char ch;

	fp = fopen("test.txt", "w");

	int i = 1000;
	while (i--) {
		scanf("%c", ch);
		putc(ch, fp);
	}

	if (fp == NULL) {
		printf("Nao foi possivel criar o arquivo\n");
		exit(1);
	}
	fclose(fp);

	return 0;
}
