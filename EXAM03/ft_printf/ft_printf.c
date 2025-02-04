/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:07:18 by adechaji          #+#    #+#             */
/*   Updated: 2025/02/04 16:07:26 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void   putstring(char *str, int *len)
{
    if (!str)
        str = "(null)";
    while (*str)
        *len += write(1, str++, 1);
}

void    puthexnum(long long int num, int base, int *len)
{
    if (num < 0)
    {
        num *= -1;
        *len += write(1, "-", 1);
    }
    if (num >= base)
        puthexnum((num / base), base, len);
    *len += write(1, &("0123456789abcdef"[num % base]), 1);
}

int ft_printf(const char *frt, ...)
{
    int len = 0;

    va_list ptr;
    va_start(ptr, frt);

    while (*frt)
    {
        if ((*frt == '%') && (((*(frt + 1) == 's')) || (*(frt + 1) == 'd') || (*(frt + 1) == 'x')))
        {
            frt++;
            if (*frt == 's')
                putstring(va_arg(ptr, char *), &len);
            else if (*frt == 'd')
                puthexnum((long long int)va_arg(ptr, int), 10, &len);
            else if (*frt == 'x')
                puthexnum((long long int)va_arg(ptr, unsigned int), 16, &len);
        }
        else
            len += write(1, frt, 1);
        frt++;
    }
    return (va_end(ptr), len);
}
