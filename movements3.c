/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:30:52 by apulido-          #+#    #+#             */
/*   Updated: 2022/01/11 18:39:03 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_rra(t_list **a)
{
	t_list *aux;

	if(ft_lstsize(*a) > 1)
	{
		aux = ft_lstlast(*a);
		ft_lstadd_front(a, aux);
		aux->next = NULL;
		write(1, "rra\n", 4);
	}
}