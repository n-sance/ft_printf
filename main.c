#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char **argv)
{

/*
    printf("%015.8f\n", 0.);
    ft_printf("%015.8f\n\n\n", 0.); //неправильное количество нулей в последнем столбце


    printf("%f|%-f|%+f|% f|%#f|%0f\n", -0., -0., -0., -0., -0., -0.);
    ft_printf("%f|%-f|%+f|% f|%#f|%0f\n\n\n", -0., -0., -0., -0., -0., -0.); //неправильная обработка символов + - и пробел перед флагом f

    printf("%5f|%-5f|%+5f|% 5f|%#5f|%05f\n", -0., -0., -0., -0., -0., -0.);
    ft_printf("%5f|%-5f|%+5f|% 5f|%#5f|%05f\n\n\n", -0., -0., -0., -0., -0., -0.); //тоже самое. должно игнорироваться все знаки после доллара и перед флагом, как я понимаю

    printf("%05f\n", INFINITY);
    ft_printf("%05f\n\n\n", INFINITY); //странные нули перед началом inf







   //////////////////////////////////////////////////////////////////////////////////////////////////
   // Похоже на мой косяк. Исследую ////////////////////////////////////////////////////////////////
   ///////////////////////////////////////////////////////////////////////////////////////////////////
    ft_printf("%.3f\n\n\n", 999.99999);

    printf("{%*3d}"\n, 5, 0);
    printf("{%*3d}", 5, 0);*/
    ///////////////////////////////////////////////////////////////////////////////////////////////
    //ft_printf("%f|%-f|%+f|% f|%#f|%0f\n", -0., -0., -0., -0., -0., -0.);
   // printf("%f|%-f|%+f|% f|%#f|%0f\n", -0., -0., -0., -0., -0., -0.);
    //ft_printf("%f|%-f|%+f|% f|%#f|%0f", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX);
   // printf("%15.f|%15.1f|%15.2f|%15.5f|%15.12f\n\n\n", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999);
    ft_printf("%15.f|%15.1f|%15.2f|%15.5f|%15.12f", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999);
    //printf("%f|%-f|%+f|% f|%#f|%0f", 0., 0., 0., 0., 0., 0.);
    return(0);
}

//"%#.5hho", ULLONG_MAX - 00037
//"%#.5o", 0U - 00000
//"%#o", UINT_MAX - 037777777777
//"%#o", 0U - 0
