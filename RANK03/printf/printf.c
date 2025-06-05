#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>


void    ft_putchar(char c, int *count)
{
    write(1, &c, 1);
    (*count)++;
}

void    ft_putstr(char *str, int *count)
{
    int i = 0;
    if (!str)
        str = "(null)";
    while(str[i])
    {
        ft_putchar(str[i], count);
        i++;
    }
}

void ft_putnbr(int n, int *count)
{
    if (n == -2147483648)
    {
        ft_putstr("-2147483648", count);
        return;
    }
    if ( n < 0)
    {
        ft_putchar('-', count);
        n = -n;
    }
    if ( n >= 10)
        ft_putnbr(n / 10, count);
    ft_putchar(n % 10 + '0', count);
}

void ft_hex(unsigned n, int *count)
{
    char *hex = "0123456789abcdef";

    if (n >= 16)
        ft_hex(n / 16, count);
    ft_putchar(hex[n % 16], count);
}


int ft_printf(const char *format,...)
{
    va_list args;
    va_start(args, format);

    int i = 0;
    int count = 0;
    while(format[i])
    {
        if (format[i] == '%' && format[i + 1] )
        {
            i++;
            if (format[i] == 's')
                ft_putstr(va_arg(args,char *), &count);
            else if (format[i] == 'd')
                ft_putnbr(va_arg(args, int), &count);
            else if (format[i] == 'x')
                ft_hex(va_arg(args, unsigned int), &count);
            else 
                ft_putchar(format[i],&count);
        }
        else
            ft_putchar(format[i], &count);
        i++;
    }
    va_end(args);
    return count;
}

// int main()
// {
//     ft_printf("hola soy %s\n", "vica");
//     printf("hola soy %s\n","vica");
//     ft_printf("hola soy %d\n", 92334);
//     printf("hola soy %d\n", 92334);
//     ft_printf("hola , el hexadecima de %d es %x\n", 42,42);
//     printf("hola , el hexadecima de %d es %x\n", 42,42);
    
//     printf("_______________________________");

//     int a = 456789;
//     char *vra = "hola eres hermoso";
//     long int q = -2147483647;

//     ft_printf("hola soy %s\n", vra);
//     printf("hola soy %s\n", vra);
//     ft_printf("hola soy %d\n", q);
//     printf("hola soy %d\n", q);
//     ft_printf("hola , el hexadecima de %d es %x\n", a, a);
//     printf("hola , el hexadecima de %d es %x\n", a , a);
    
//     return 0;

// }
