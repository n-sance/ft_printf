#include <stdio.h>
#include <limits.h>

int main()
{
    int a;
    int i = 1;
    //printf("o: %o\n", 922337);
    //printf("ho: %ho\n", 922337);
    a = printf("%2147483649f", 1.0);
    i++;
    printf("\n%d\n", a);

    void *p;
    p = (int *)p;
    return (0);
}