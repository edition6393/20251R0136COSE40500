#include <iostream>
#define DIGIT_LENGTH 8

bool IsRightTitle(int series_title)
{
    int list[DIGIT_LENGTH] = {};
    for(int i = 0; i < DIGIT_LENGTH; i++)
    {
        list[i] = series_title % 10;
        series_title = (int)(series_title / 10);
    }

    for(int i = 0; i < DIGIT_LENGTH - 2; i++)
    {
        if(list[i] == 6 && list[i+1] == 6 && list[i+2] == 6)
            return true;
    }
    return false;
}

int main()
{
    int N, count = 0;
    int series_title = 0;
    std::cin >> N;
    while(count < N)
    {
        count += IsRightTitle(series_title);
        series_title++;
    }
    series_title--;

    std::cout << series_title << std::endl;
    return 0;
}