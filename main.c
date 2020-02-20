#include <stdio.h>
#include <stdlib.h>

typedef struct elempar {
    int p,r;
} Elempar;

int randomgen (int also, int felso)
{
    return (rand() % (felso - also + 1)) + also;
}

Elempar *create (int n)
{
    Elempar *a;
    a = (Elempar*) malloc(n * sizeof(Elempar));

    for (int i=0; i<n; i++)
    {
        a[i].p = randomgen(1,9);
        a[i].r = randomgen(1,9);

        // ellenorizni kell, hogy ne legyenek azonos elemek
        for (int j=0; j<i; j++)
            while ( (a[i].p == a[j].p) && (a[i].r == a[j].r) )
            {
                a[i].p = randomgen(1,9);
                a[i].r = randomgen(1,9);
            }
    }

    return a;
}

void print (Elempar *h, int n)
{
    printf("{ ");
    for (int i=0; i<n-1; i++)
        printf("(%d, %d), ", h[i].p, h[i].r);
    printf("(%d, %d) } \n", h[n-1].p, h[n-1].r);
}

int main()
{
    int n = 5;
    Elempar *a[n], *b[n];
    *a = create(n);
    *b = create(n);

    print(*a,n);
    print(*b,n);

    return 0;
}
