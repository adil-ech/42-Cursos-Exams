/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:24:01 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/14 16:35:01 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int issppace(char c)
{
    if (c == 32 || c >= 9 && c <= 13)
    {
        return 1;
    }
    return 0;
}
int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i] && issppace(av[1][i]))
            i++;
        while (av[1][i] && !issppace(av[1][i]))
        {
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
