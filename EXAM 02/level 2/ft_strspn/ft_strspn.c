/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:45:07 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/15 15:53:23 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int i = 0;
	int j = 0;

	while (s[i] == accept[j])
	{
		i++;
		j++;
	}
	if (accept[j] != s[i])
		return j;
	return 0;
}
