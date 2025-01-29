/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:09:32 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/22 00:11:51 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list *tmp = begin_list;
	int cc = 0;
	
	while (tmp)
	{
		cc++;
		tmp = tmp->next;
	}
	return cc;
}
