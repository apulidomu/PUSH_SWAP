/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:39:52 by alex              #+#    #+#             */
/*   Updated: 2021/11/16 16:25:07 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    int x;
    int control;
    t_list a;
    t_list b;

    control = 0;
    i = 1;
    x = 0;
    if(argc > 1)
    {   
       
        while(argv[i] && control == 0)
        {
            control = input_control(argv[i]);
            if(check_space(argv[i]) == 1)
            {
                select_num_space(argv[i]);
            }
            else
            {
                select_num_nospace(argv[i]);
            }
            i++;
        }

    }
}

int input_control(char *input)
{
    int i;
    int validate;

    i = 0;
    validate = 0;
    if(!input[i])
    {
        validate = 1;
    }
    while(input[i])
    {
        if(input[i] != 32 && input[i] < '0' && input[i] > '9')
        {
            validate = 1;
        }
        i++;
    }
    return (validate);
}

void select_num_space(char *argv)
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
            printf("NUM = %s:\n", num);
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
            printf("NUM = %s:\n", num);
        }
        s++;
        i--;
    }
  
}

void select_num_nospace(char *argv)
{
        printf("NUM = %s:\n", argv);
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