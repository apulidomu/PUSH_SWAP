/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:39:52 by alex              #+#    #+#             */
/*   Updated: 2022/02/14 14:23:35 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int input_control(char **input)
{
    int i;
    int validate;
	int	j;

	j = 0;
    i = 1;
    validate = 0;
    while(input[i])
    {
        if(!input[i])
		{
			validate = 1;
			error_msg();
		}
		//printf("INPUT: %s\n", input[i]);
		i++;
    }
	i = 1;
    while(input[i])
	{	
		j = 0;
		while(input[i][j])
    	{
        	if(input[i][j] != 32 && (input[i][j] < '0' || input[i][j] > '9'))
        	{
            	validate = 1;
				if(input[i][j] == '-' || input[i][j] == '+')
				{		
					validate = 0;
					if(input[i][j + 1] == '-' || input[i][j + 1] == '+')
						{
							validate = 1;
							error_msg();
						}
				}
        	}
			//printf("CHAR INPUT: %c, %d  ", input[i][j], validate);
        	j++;
    	}
		i++;
	}
	//printf("VALOR VALIDATE: %d\n", validate);	
    return (validate);
}

void select_num_space(char *argv, t_list **a)
{
    int     i;
    int     s;
    char    *num;
    int control;
	
    control = 0;
    s = 0;
    i = 0;
    while(argv[i] == 32)
        i++;
    while(argv[i])
    {
        if(argv[i] == 32 && argv[i - 1] > '0' && argv[i - 1] < '9')
        {
            num = ft_substr(argv, (i - s), s);
			*a = full_a(num, a);
            s = 0;
            i++;
        }
        s++;
        i++;
    }
	
	if(argv[i] == '\0' && argv[i - 1] > '0' && argv[i - 1] < '9')
	{
		//printf("HOLA HOLAAAAA");
		num = ft_substr(argv, (i - s), s);
		*a = full_a(num, a);
	}

}

void select_num_nospace(char *argv, t_list **a)
{
	*a = full_a(argv, a);
    //printf("NUM = %s:\n", argv);
}