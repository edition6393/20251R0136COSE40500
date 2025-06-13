#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 1000000
//arr[N+1] = {0, 0, }
int main(void)
{
	int length, i = 0, count = 0;
	char m[201] = {0};
	scanf("%s", m);
	while(m[i] != 0)
	{
		switch(m[i])
		{
			case 'c':
				if (m[i+1] == '=' || m[i+1] == '-')
					i += 2;
				else
					i++;
				break;
			case 'd':
				if (m[i+1] == 'z' && m[i+2] == '=')
					i += 3;
				else if (m[i+1] == '-')
					i += 2;
				else
					i++;
				break;
			case 'l':
				if (m[i+1] == 'j')
					i += 2;
				else
					i++;
				break;
			case 'n':
				if (m[i+1] == 'j')
					i += 2;
				else
					i++;
				break;
			case 's':
				if (m[i+1] == '=')
					i += 2;
				else
					i++;
				break;
			case 'z':
				if (m[i+1] == '=')
					i += 2;
				else
					i++;
				break;
			default:
				i++;
				break;
		}
		count++;
	}
	
	printf("%d", count);
	return 0;
}