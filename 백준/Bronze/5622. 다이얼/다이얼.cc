#include <iostream>
#include <cstring>

int second[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

int main(void)
{
	int sum = 0;
	char phonenum[100];
    std::cin >> phonenum;
    int length = strlen(phonenum);
	for (int i = 0; i<length; i++)
	{
		sum += (second[phonenum[i]-'A']+1);
	}
    std::cout << sum;
    return 0;
}