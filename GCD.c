#include <stdio.h>
int main()
{
    int n1, n2, i, gcd;

    printf("Enter integer 1:\n");
    scanf("%d", &n1);
    printf("Enter integer 2:\n");
    scanf("%d", &n2);

    for(i=1; i <= n1 && i <= n2; ++i)
    {
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }

    printf("GCD of %d and %d is:\n%d", n1, n2, gcd);

    return 0;
}
