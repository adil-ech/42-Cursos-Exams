/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:33:41 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/15 10:51:57 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i = 0;
	int res;

	if (ac == 4)
	{
		int	n1 = atoi(av[1]);
		int	n2 = atoi(av[3]);
		if (av[2][0] == '+')
			return (printf("%d\n", res = n1 + n2), 0);
		else if (av[2][0] == '-')
			return (printf("%d\n", res = n1 - n2), 0);
		else if (av[2][0] == '*')
			return (printf("%d\n", res = n1 * n2), 0);
		else if (av[2][0] == '/')
			return (printf("%d\n", res = n1 / n2), 0);
		else if (av[2][0] == '%')
			return (printf("%d\n", res = n1 % n2), 0);
	}
	printf("\n");
	return 0;
}