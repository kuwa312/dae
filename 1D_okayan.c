#include <stdio.h>

int main(void)
{
    int n;
    int max = 2000000;

    scanf("%d", &n);
    int a[200000];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int b = a[j] - a[i];
            
            if(b > max)
            {
                max = b;
            }
        }
    }

    printf("%d\n", max);

    return 0;
}