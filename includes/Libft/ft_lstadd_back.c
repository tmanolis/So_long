/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:06:15 by tmanolis          #+#    #+#             */
/*   Updated: 2021/06/28 14:33:41 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_node;

	last_node = ft_lstlast(*alst);
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
			last_node->next = new;
	}
}
