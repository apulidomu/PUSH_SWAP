/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:18:10 by apulido-          #+#    #+#             */
/*   Updated: 2022/01/19 17:21:31 by apulido-         ###   ########.fr       */
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
	ft_lstiter(a);
	push_pb(&a, &b);
	push_pb(&a, &b);
	ft_lstiter(a);
	ft_lstiter(b);
	reverse_rotate_rrr(&a, &b);
	ft_lstiter(a);
	ft_lstiter(b);
}

