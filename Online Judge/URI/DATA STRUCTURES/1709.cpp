#include <cstdio>

int main()
{
    int n, p, t;

    while(scanf("%d", &n) == 1)
    {
        p = 2; t = 1;

        while(p != 1)
        {
            if(p <= n/2)
                p = p + p;
            else
                p = p - (n-p+1);
            t++;
        }

        printf("%d\n", t);
    }

    return 0;
}
