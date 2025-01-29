/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:23:48 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/14 16:24:00 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putchhr(char c)
{
    write(1, &c, 1);
}
void miniputnbr(int nb)
{
    if (nb >= 10)
    {
        miniputnbr(nb / 10);
        miniputnbr(nb % 10);
    }
    else
        putchhr(nb + '0');
}
int main()
{
    int i = 1;

    while (i < 101)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
        miniputnbr(i);
        write(1, "\n", 1);
        i++;
    }
}
