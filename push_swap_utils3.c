/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:07:16 by apulido-          #+#    #+#             */
/*   Updated: 2022/02/14 15:16:37 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_space(char *argv)
{
    int i;

    i = 0;
    while(argv[i])
    {
        if(argv[i] == 32)
            return (1);
        i++;
    }
    return(0);
}

void check_repeat(t_list *a, int num)
{
	int control;

	control = 0;
	if(a != NULL)
	{
		while(a->next != NULL)
		{
			if(a->n == num)
			{
				control = 1;
			}
			a = a->next;
		}
		if(control == 1)
			error_msg();
	}
}

void check_order(t_list *lst)
{
	int control;
	ft_lstiter(lst, "LISTA check: ");
	control = 0;
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			if(lst->n < lst->next->n)
				control = 1;
			else
			{
				control = 0;
				break;
			}
			//printf(" %d,NUMERO: %d", control, lst->n);
			lst = lst->next;
		}
	}
	if(control == 1)
		exit(-1);
}

int check_order_logic(t_list *lst)
{
	int control;
	ft_lstiter(lst, "LISTA check: ");
	control = 0;
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			if(lst->n < lst->next->n)
				control = 1;
			else
			{
				control = 0;
				break;
			}
			//printf(" %d,NUMERO: %d", control, lst->n);
			lst = lst->next;
		}
	}
	return (control);
}

