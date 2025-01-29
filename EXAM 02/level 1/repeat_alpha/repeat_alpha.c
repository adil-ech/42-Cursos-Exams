/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:03:29 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/14 18:56:56 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int countmepls(char c)
{
	int res = 0;

	if (c >= 'a' && c <= 'z')
		res = c - 'a';
	else if (c >= 'A' && c <= 'Z')
		res = c - 'A';
	return res;
}

int main(int ac, char **av)
{
    int i = 0;
    int r = 0;

    if (ac == 2)
	{
		while (av[1][i])
		{
			r = countmepls(av[1][i]);
			while (r >= 0)
			{
				write(1, &av[1][i], 1);
				r--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
