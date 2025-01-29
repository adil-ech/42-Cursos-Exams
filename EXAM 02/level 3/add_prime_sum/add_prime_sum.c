/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:01:25 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/21 20:37:27 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libc.h>

int miniatoi(char *s)
{
	int i = 0;
	int res = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return res;
}

int is_prime(int num)
{
	int i = 2;

	if (num <= 1)
		return 0;
	while (i * i <= num)
	{
		if (num % i == 0)
			return 0;
		i++;
	}
	return 1;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void miniputnbr(int n)
{
	if (n >= 10)
	{
		miniputnbr(n / 10);
		miniputnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
int main(int ac, char **av)
{
	if (ac == 2)
	{
		int num = miniatoi(av[1]);
		int sum = 0;
		while (num > 0)
		{
			if (is_prime(num))
				sum += num;
			num--;
		}
		miniputnbr(sum);
		write(1, "\n", 1);
		return 0;
	}
	write(1, "0\n", 2);
	return 0;
}

