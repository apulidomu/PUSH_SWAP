/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:39:52 by alex              #+#    #+#             */
/*   Updated: 2021/12/14 15:49:46 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    int x;
    int control;
	t_list *a;
	t_list *b;
	
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
			write(1, "Error\n", 7);
			return (0);
		}
        while(argv[i])
        {
            
            if(check_space(argv[i]) == 1)
            {
                select_num_space(argv[i], &a);
            }
            else
            {
                select_num_nospace(argv[i], &a);
            }
            i++;
        }

    }
	ft_lstiter(a);
}

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
			validate = 1;
		printf("INPUT: %s\n", input[i]);
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
				if(input[i][j] == '-')
					validate = 0;
        	}
			printf("CHAR INPUT: %c, %d  ", input[i][j], validate);
        	j++;
    	}
		i++;
	}
	printf("VALOR VALIDATE: %d\n", validate);	
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
        if(argv[i] == 32)
        {
            num = ft_substr(argv, (i - s), s);
			*a = full_a(num, a);
            //printf("NUM = %s:\n", num);
            s = 0;
            i++;
        }
        s++;
        i++;
    }
    i = ft_strlen(argv);
    s = 0;
    while(0 <= i && control == 0)
    {
        if(argv[i] == 32)
        {
            num = ft_substr(argv, (i + 1), s);
            control = 1;
			*a = full_a(num, a);
            //printf("NUM = %s:\n", num);
        }
        s++;
        i--;
    }
  
}

void select_num_nospace(char *argv, t_list **a)
{
	*a = full_a(argv, a);
    //printf("NUM = %s:\n", argv);
}

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