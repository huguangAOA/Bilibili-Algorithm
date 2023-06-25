#include<stdio.h>
int main()
{
    int i, n, r = 1;
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        r = (r + 1) * 2;
    }
    printf("%d", r);
    return 0;
}