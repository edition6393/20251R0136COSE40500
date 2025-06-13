#include <stdio.h>
#include <stdlib.h>

void star(char **, int size, int x, int y);

int main(void)
{
	int i, j, n;
	scanf("%d", &n);
	char **a = malloc(n * sizeof(char *));
	for(i=0; i<n; i++)
	{
		a[i] = malloc(n * sizeof(char));
	}
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			a[i][j] = '*';

	star(a, n, 0, 0);
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
		
	for(i=0; i<n; i++)
	{
		free(a[i]);
	}
	free(a);
	return 0;
}

void star(char **a, int size, int x, int y)
{
	int i, j;
	for (i = size/3 + size * x ; i<2*size/3 + size * x; i++)
		for (j = size/3 + size * y; j<2*size/3 + size * y; j++)
			a[i][j] = ' ';
	if(size != 3)
	{
		for (i = 0; i<3; i++)
			for (j = 0; j<3; j++)
				star(a, size/3, x*3+i, y*3+j);	
	}
			
}