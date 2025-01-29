/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:54:01 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/21 01:01:38 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void putsttrr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	int len = 0;

	if (ac == 3)
	{
		while (av[1][len])
			len++;
		while (av[2][i])
		{
			if (av[2][i] == av[1][j])
				j++;
			if (j == len)
			{
				putsttrr(av[1]);
				break ;
			}
			i++;
		}
		
	}
	write(1, "\n", 1);
	return 0;
}