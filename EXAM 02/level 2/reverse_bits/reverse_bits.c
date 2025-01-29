/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:16:33 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/20 23:39:41 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char res = 0x0;
	int i = 0;
	while (i < 8)
	{
		res = res << 1;
		res = res | (octet & 1);
		octet = octet >> 1;
		i++;
	}
	return (res);
}

