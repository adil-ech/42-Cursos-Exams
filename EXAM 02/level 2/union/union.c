/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:24:02 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/21 00:49:49 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int alrseen(char *str, char c, int len)
{
	int i = 0;
	
	while (i < len)
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}
int main(int ac, char **av)
{
	int i = 0;
	int len;

	if (ac == 3)
	{
		while (av[1][i])
		{
			if (alrseen(av[1], av[1][i], i) == 0)
			{
				write(1, &av[1][i], 1);
			}
			i++;
		}
		len = i;
		i = 0;
		while (av[2][i])
		{
			if (alrseen(av[2], av[2][i], i) == 0 && alrseen(av[1], av[2][i], len) == 0)
			{
				write(1, &av[2][i], 1);
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return 0;
}
