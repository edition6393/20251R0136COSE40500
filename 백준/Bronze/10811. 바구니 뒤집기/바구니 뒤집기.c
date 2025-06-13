#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int* arr = malloc(sizeof(int) * (n + 1));
    int* temp = malloc(sizeof(int) * (n + 1));
    for (size_t i = 0; i < n + 1; i++)
        arr[i] = i;

    
    for (size_t i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        for(int i = 0; i <= b - a; i++)
            temp[b - i] = arr[a + i];
        for(int i = 0; i <= b - a; i++)
            arr[i + a] = temp[a + i];
    }
    for (size_t i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    
    free(arr);

    return 0;
}