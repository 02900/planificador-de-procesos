#include <stdio.h>

int main (int argc, char** argv) 
{
	int a;
	char b;
	int c;
	float d;
	char e[20];

	FILE* fp = fopen ("filename", "r");

	while (fscanf(fp, "%d %c %d %f %s", &a, &b, &c, &d, e) != EOF)
		printf("%d %c %d %f %s\n", a, b, c, d, e);


	fclose (fp);
	return 0;
}