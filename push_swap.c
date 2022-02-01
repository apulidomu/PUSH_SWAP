/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:18:10 by apulido-          #+#    #+#             */
/*   Updated: 2022/02/01 16:06:45 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int 	i;
    int 	x;
    int 	control;
	t_list 	*a;
	t_list 	*b;
	
	a = 0;
	b = 0;
    control = 0;
    i = 1;
    x = 0;
    if(argc > 1)
    {   
    	control = input_control(argv);
		if(control != 0)
		{
			error_msg();
			return (0);
		}
        while(argv[i])
        {
            if(check_space(argv[i]) == 1)
                select_num_space(argv[i], &a);
            else
                select_num_nospace(argv[i], &a);
            i++;
        }
    }
	check_order(a);
	ft_lstiter(a);
	ft_lstiter(a);
}

void check_order(t_list *lst)
{
	int control;

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

