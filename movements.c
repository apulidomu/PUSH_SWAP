/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:24:42 by apulido-          #+#    #+#             */
/*   Updated: 2022/01/18 15:35:59 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_sa(t_list **a)
{
	int size;
	t_list *aux;

	size = ft_lstsize(*a);
	if(size > 1)
	{
		aux = *a; 
		*a = (*a)->next;
		aux->next = (*a)->next;
		(*a)->next = aux;
		write(1, "sa\n", 3);
	}
}

void swap_sb(t_list **b)
{
	int size;
	t_list *aux;

	size = ft_lstsize(*b);
	if(size > 1)
	{
		aux = *b; 
		*b = (*b)->next;
		aux->next = (*b)->next;
		(*b)->next = aux;
		write(1, "sb\n", 3);
	}
}

void swap_ss(t_list **a, t_list **b)
{
	t_list *aux;
	t_list *aux2;
	
	if(ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1)
	{
		aux = *a; 
		*a = (*a)->next;
		aux->next = (*a)->next;
		(*a)->next = aux;
		aux2 = *b; 
		*b = (*b)->next;
		aux2->next = (*b)->next;
		(*b)->next = aux2;
		write(1, "ss\n", 3);
	}
}

void push_pa(t_list **a, t_list **b)
{
	t_list *aux;

	if(ft_lstsize(*a) > 0)
	{
		aux = *a;
		*a = (*a)->next;
		ft_lstadd_front(b, aux);
		write(1, "pa\n", 3);
	}
}

void push_pb(t_list **a, t_list **b)
{
	t_list *aux;

	if(ft_lstsize(*a) > 0)
	{
		aux = *a;
		*a = (*a)->next;
		ft_lstadd_front(b, aux);
		write(1, "pb\n", 3);
	}
}
