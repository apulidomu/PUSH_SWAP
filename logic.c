/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:13:01 by apulido-          #+#    #+#             */
/*   Updated: 2022/03/01 17:39:28 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void logic_size_3(t_list **a);
void logic_size_4(t_list **a, t_list **b);
void logic_size_5(t_list **a, t_list **b);
void move_to_b(t_list **a, t_list **b, int *lowest);
t_list **move_from_up(int num, t_list **a, t_list **b);
t_list **move_from_down(int num, t_list **a, t_list **b);



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
	if(size >= 5)
		logic_size_5(a, b);
}

void logic_size_3(t_list **a)
{
	int control;

	control = 0;
	while((*a)->n > ft_lstlast(*a)->n)
		rotate_ra(a);
	if((*a)->n > (*a)->next->n)
		swap_sa(a);
	control = check_order_logic(*a);
	if((*a)->n < ft_lstlast(*a)->n && (*a)->n < (*a)->next->n && control == 0)
	{
		swap_sa(a);
		rotate_ra(a);
	}
}

void logic_size_4(t_list **a, t_list **b)
{
	move_lst_tolowest(a);
	push_pb(a, b);
	logic_size_3(a);
	push_pa(a, b);
}

void logic_size_5(t_list **a, t_list **b)
{
	int *nums;

	nums = select_3lowest_nums(a);
	move_to_b(a, b, nums); 
	
}

int *select_3lowest_nums(t_list **a)
{
	int *lowest;
	t_list *aux;
	int i;
	int auxint;
	int auxint2;

	auxint = 0;
	auxint2 = 0;
	i = 0;
	aux = *a;
	lowest = (int*)malloc(3 * sizeof(int));
	if(!lowest)
		return (NULL);
	lowest[0] = aux->n;
	lowest[1] = aux->next->n;
	lowest[2] = aux->next->next->n;
	
	aux = aux->next->next->next;
	while(aux != NULL)
	{
		if(aux->n < lowest[0])
		{
			auxint = lowest[0];
			lowest[0] = aux->n;
			if(auxint < lowest[1])
				{
					auxint2 = lowest[1];
					lowest[1] = auxint;
				}
			if(auxint2 < lowest[2])
				lowest[2] = auxint2;
		}
		else if(aux->n < lowest[1] && aux->n != lowest[0])
		{
			auxint = lowest[1];
			lowest[1] = aux->n;
			if(auxint < lowest[2])
				lowest[2] = auxint;
		}
		else if(aux->n < lowest[2] && aux->n != lowest[1] && aux->n != lowest[0])
		{
			lowest[2] = aux->n;
		}
		aux = aux->next;
	}
	i = 0;
	while(i < 3)
	{
		printf("N%d = %d ///////",i, lowest[i]);
		i++;
	}
	return (lowest);
}

void move_to_b(t_list **a, t_list **b, int *lowest)
{
	int mid;
	t_list *aux;
	int position;
	int num;

	position = 0;
	aux = *a;
	mid = ft_lstsize(aux)/2;
	printf("MEDIO: %d", mid);
	// while(ft_lstsize(*b) != 3  && aux != NULL)
	// {
	// 	aux = *a;
	// 	position = 0;
	// 	if(aux->n == lowest[0] || aux->n == lowest[1] || aux->n == lowest[2])
	// 	{
	// 		num = aux->n;
	// 		if(position > mid)
	// 			a = move_from_up(num, a, b);
	// 		if(position <= mid)
	// 			a = move_from_down(num, a, b);
	// 	}
	// 	aux = aux->next;
	// 	position++;
	// }
}

t_list **move_from_up(int num, t_list **a, t_list **b)
{
	int aux;

	aux = (*a)->n;
	printf("NUM = %d", num );
	while((*a)->n != num)
	{
		rotate_ra(a);
	}
	push_pb(a, b);
	return(a);
}
t_list **move_from_down(int num, t_list **a, t_list **b)
{
	int aux;

	aux = (*a)->n;
	printf("NUM = %d", num );
	while((*a)->n != num)
	{
		reverse_rotate_rra(a);
	}
	push_pb(a, b);
	return(a);
}