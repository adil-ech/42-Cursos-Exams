/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:53:46 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/15 16:25:38 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ifdupp(char *s,	char c, int pos)
{
	int i = 0;

	while (i < pos)
	{
		if (s[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	int len;

	if (ac == 3)
	{
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j])
				{
					if (ifdupp(av[1], av[1][i], i) == 0)
					{
						write(1, &av[1][i], 1);
						break;
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
