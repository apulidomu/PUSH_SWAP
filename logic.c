/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:13:01 by apulido-          #+#    #+#             */
/*   Updated: 2022/02/03 16:38:35 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void logic_size_3(t_list **a);
void logic_size_4(t_list **a, t_list **b);

void chose_logic(t_list **a, t_list **b)
{
	int size;

	size = ft_lstsize(*a);
	if (size == 2)
		swap_sa(a);
	if(size == 3)
		logic_size_3(a);
	if(size == 4)
		logic_size_4(a, b);
}

void logic_size_3(t_list **a)
{
	while((*a)->n > ft_lstlast(*a)->n)
		rotate_ra(a);
	if((*a)->n > (*a)->next->n)
		swap_sa(a);
}

void logic_size_4(t_list **a, t_list **b)
{

	push_pb(a, b);
	logic_size_3(a);
	push_pa(a, b);
	
}

