#include <stdio.h>
#include <stdlib.h>

typedef struct elempar {
    int p,r;
} Elempar;

typedef struct data {
    int n;
    Elempar c[];
} Data;

int randomgen (int also, int felso)
{
    return (rand() % (felso - also + 1)) + also;
}

Elempar *createRandom (int n)
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

void printdata (Data d)
{
    printf("{ ");
    for (int i=0; i<d.n-1; i++)
        printf("(%d, %d), ", d.c[i].p, d.c[i].r);
    printf("(%d, %d) } \n", d.c[d.n].p, d.c[d.n].r);
}

Data natural_join (Elempar *a, Elempar *b, int n)
{
    //Elempar *c;
    //c = (Elempar*) malloc(n*n * sizeof(Elempar));
    //int k = 0;

    Data data;
    //data = (Data*) malloc(n*n * sizeof(Data));
    data.n = 0;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (b[i].r == a[j].p)
            {
                /*
                c[k].p = b[i].p;
                c[k].r = a[j].r;
                k++;
                */

                data.c[n].p = b[i].p;
                data.c[n].r = a[j].r;

                printf("(%d,%d) o (%d,%d) -> (%d,%d)\n", b[i].p, b[i].r, a[j].p, a[j].r, data.c[n].p, data.c[n].r );

                data.n++;
            }

    return data;
}

int main()
{
    int n = 5;

    Data c;
    //c = (Data*) malloc(n*n * sizeof(Data));

    Elempar *a[n], *b[n];
    *a = createRandom(n);
    *b = createRandom(n);

    print(*a,n);
    print(*b,n);

    c = natural_join(*a,*b,n);
    //printdata(c);

    free(*a);
    free(*b);
    //free(c);

    return 0;
}
