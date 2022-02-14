/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:30:52 by apulido-          #+#    #+#             */
/*   Updated: 2022/02/14 14:28:15 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_rra(t_list **a)
{
	t_list *aux;
	t_list *last;

	if(ft_lstsize(*a) > 1)
	{
		aux = *a;
		last = ft_lstlast(*a);
		while(aux->next->next)
			aux = aux->next;
		aux->next = NULL;
		ft_lstadd_front(a, last);
		write(1, "rra\n", 4);
	}
}

void reverse_rotate_rrb(t_list **b)
{
	t_list *aux;
	t_list *last;

	if(ft_lstsize(*b) > 1)
	{
		aux = *b;
		last = ft_lstlast(*b);
		while(aux->next->next)
			aux = aux->next;
		aux->next = NULL;
		ft_lstadd_front(b, last);
		write(1, "rrb\n", 4);
	}
}

void reverse_rotate_rrr(t_list **a, t_list **b)
{
	t_list *aux;
	t_list *last;

	t_list *aux2;
	t_list *last2;

	if(ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1)
	{
		aux = *a;
		last = ft_lstlast(*a);
		while(aux->next->next)
			aux = aux->next;
		aux->next = NULL;
		ft_lstadd_front(a, last);
	

		aux2 = *b;
		last2 = ft_lstlast(*b);
		while(aux2->next->next)
			aux2 = aux2->next;
		aux2->next = NULL;
		ft_lstadd_front(b, last2);
		write(1, "rrr\n", 4);
	}
}