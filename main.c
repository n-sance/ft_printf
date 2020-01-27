#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int a = 0;
    int *ptr;
    ptr = &a;
    int i = 1;
    //printf("{%f}{%lf}{%Lf}\n\n", 1.42, 1.42, 1.42l);
    //ft_printf("%Lf   %Lf", 1.42, 8.4444);

    //printf("%.0p, %.p", (void *)0, (void *)0);
    //ft_printf("%.0p, %.p", (void *)0, (void *)0);

    //ft_printf("{%*3d}", 5, 0);

    //ft_printf("%*.*d", 0, 3, 0);

    //ft_printf("%*d", 5, 42);

    //ft_printf("%.p, %.0p", 0, 0);
    ft_printf("%f|%-f|%+f|% f|%#f|%0f\n\n\n\n", 0., 0., 0., 0., 0., 0.);
    printf("%f|%-f|%+f|% f|%#f|%0f", 0., 0., 0., 0., 0., 0.);


    return(0);
}

//"%#.5hho", ULLONG_MAX - 00037
//"%#.5o", 0U - 00000
//"%#o", UINT_MAX - 037777777777
//"%#o", 0U - 0
