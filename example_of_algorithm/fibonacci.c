#include <stdio.h>

int fibo(int n)
{
    if ( n == 0 ) return 0;
    if ( n == 1 ) return 1;
    return (fibo( n - 1 ) + fibo( n - 2 ));
}

int fibo_iter(int n)
{
    if ( n == 0 ) return 0;
    if ( n == 1 ) return 1;

    int p = 1;
    int pp = 0;
    int result = 0;

    for (int i = 2; i <= n; i++)
    {
        result = p + pp;
        pp = p;
        p = result;
    }

    return result;
}

int main(void)
{
    int n = 5;
    int result1 = fibo(n);
    int result2 = fibo_iter(n);

    printf("%d\n", result1);
    printf("%d\n", result2);

    return 0;
}