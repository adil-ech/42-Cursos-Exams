/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:46:02 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/21 21:00:12 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int isspacee(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return 1;
	return 0;
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
		int flag = 0;
		while (isspacee(av[1][i]))
            i++;
        while (av[1][i])
        {
        	if (isspacee(av[1][i]) == 1)
				flag = 1;
            if (isspacee(av[1][i]) == 0)
			{
				if (flag)
                	write(1, " ", 1);
				flag = 0;
                write(1, &av[1][i], 1);
			}
			i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
