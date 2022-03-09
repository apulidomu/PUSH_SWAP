/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:13:01 by apulido-          #+#    #+#             */
/*   Updated: 2022/03/09 16:16:48 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void logic_size_3(t_list **a);
void logic_size_4(t_list **a, t_list **b);
void logic_size_5(t_list **a, t_list **b);
void move_to_b(t_list **a, t_list **b, int *lowest);
t_list **move_from_up(int num, t_list **a, t_list **b);
t_list **move_from_down(int num, t_list **a, t_list **b);
int len_size(int *nums);



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
void logic_size_3_reverse(t_list **a, t_list **b)
{
	// if((*b)->n < (*b)->next->n && (*b)->n < (*b)->next->next->n)
	// 	rotate_rb(b);
	// else if((*b)->n < (*b)->next->n)
	// 	swap_sb(b);
	if((*b)->n < (*b)->next->n)
	{
		swap_sb(b);
		push_pa(a, b);
		if((*b)->n < (*b)->next->n)
		{
			swap_sb(b);
			push_pb(a, b);
			if((*b)->n < (*b)->next->n)
				swap_sb;
		}
		else
			push_pb(a, b);
	}
	else if(check_order_reverse(b) != 0)
	{
		push_pa(a, b);
		if((*b)->n < (*b)->next->n)
		{
			swap_sb(b);
			push_pb(a, b);
			if((*b)->n < (*b)->next->n)
				swap_sb(b);
		}
		
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
	int i;
	int *nums;

	i = 0;
	if(ft_lstsize(*a) > 1)
	{

	while(ft_lstsize(*a) > 1)
	{
		nums = select_3lowest_nums(a);
		move_to_b(a, b, nums); 
		logic_size_3_reverse(a, b);
		free(nums);
		i++;
	}
	}
	while(ft_lstsize(*b) > 0)
	{
		push_pa(a, b);
	}
	
}

int *select_3lowest_nums(t_list **a)
{
	int *lowest;
	t_list *aux;
	int i;
	int j;
	int auxint;
	int auxint2;

	auxint = 0;
	auxint2 = 0;
	i = 0;
	j = 0;
	aux = *a;
	
	if(ft_lstsize(*a) <= 3)
	{
		lowest = (int*)malloc(ft_lstsize(*a) * sizeof(int));
		if(!lowest)
			return (NULL);
		while(aux != NULL)
		{
			lowest[j] = aux->n;
			aux = aux->next;
			j++;
		}
	}
	else
	{
		lowest = (int*)malloc(3 * sizeof(int));
		if(!lowest)
			return (NULL);
		lowest[0] = aux->n;
		lowest[1] = aux->next->n;
		lowest[2] = aux->next->next->n;
		// while(i < 3)
		// // {
		// // 	printf("N%d = %d ///////",i, lowest[i]);
		// // 	i++;
		// // }
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
						if(auxint2 < lowest[2])
						{
							lowest[2] = auxint2;
						}
					}
				else if(auxint < lowest[2])
				{
					lowest[2] = auxint;
				}
			}
			else if(aux->n < lowest[1])
			{
				auxint = lowest[1];
				lowest[1] = aux->n;
				if(auxint < lowest[2] && auxint != lowest[1])
					lowest[2] = auxint;
			}
			else if(aux->n < lowest[2])
			{
				lowest[2] = aux->n;
			}
			aux = aux->next;
		}
	}
	// while(i < 3)
	// {
	// 	printf("N%d = %d ///////",i, lowest[i]);
	// 	i++;
	// }
	return (lowest);
}

void move_to_b(t_list **a, t_list **b, int *lowest)
{
	int mid;
	t_list *aux;
	int contador;
	int num;
	int x;

	x = 0;
	contador = 0;
	aux = *a;
	mid = ft_lstsize(aux)/2;
	printf("MEDIO: %d", mid);
	if(len_size(lowest) < 3)
	{
		while(x <= len_size(lowest))
		{
			push_pb(a, b);
			x++;
		}
			
	}
	else
	{
		while(contador != 3)
		{
			rotate_ra(a);
			if((*a)->n == lowest[0] || (*a)->n == lowest[1] || (*a)->n == lowest[2])
			{
				push_pb(a, b);
				contador++;
			}
		}
	}
	
	
	

	
	// if(ft_lstsize(*b) < 3)
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
	// 	else
	// 	{
	// 		aux = aux->next;
	// 		position++;
	// 		move_to_b(a, b, lowest);
	// 	}
	// }
}
int len_size(int *nums)
	{
		int i;
		
		i = 0;
		while(nums[i])
		{
			write(1, "|",1);
			i++;
		}
		return (i);
	}

t_list **move_from_up(int num, t_list **a, t_list **b)
{
	int aux;

	aux = (*a)->n;
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