/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:14:27 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/20 22:39:18 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	int i = 1;
	int here = 0;;

	if (len == 0)
		return 0;
	while (i < len)
	{
		if (tab[i] > tab[here])
			here = i;
		i++;
	}
	return tab[here];
}
