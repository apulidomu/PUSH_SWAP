/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:15:13 by apulido-          #+#    #+#             */
/*   Updated: 2022/01/11 18:29:42 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_ra(t_list **a)
{
	t_list *aux;

	if(ft_lstsize(*a) > 1)
	{
		aux = *a;
		ft_lstadd_back(a, aux);
		*a = (*a)->next;
		aux->next = NULL;
		write(1, "ra\n", 3);
	}
}

void rotate_rb(t_list **b)
{
	t_list *aux;

	if(ft_lstsize(*b) > 1)
	{
		aux = *b;
		ft_lstadd_back(b, aux);
		*b = (*b)->next;
		aux->next = NULL;
		write(1, "rb\n", 3);
	}
}

void rotate_rr(t_list **a, t_list **b)
{
	if(ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1)
	{
		rotate_ra(a);
		rotate_rb(b);
		write(1, "rr\n", 3);
	}
}