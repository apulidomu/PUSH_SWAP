/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:29:58 by apulido-          #+#    #+#             */
/*   Updated: 2022/02/03 16:40:40 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *full_a(char *input, t_list **a)
{
	int num;

	num = ft_atoi(input);
	printf("INT : %d  ", num);
	if (!a)
		*a = ft_newlst(num);
	else
	{
		ft_lstadd_back(a, ft_newlst(num));
		check_repeat(*a, num);
	}
	return *(a);
}

void ft_lstiter(t_list *lst, char *titulo)
{
	if (lst != NULL)
	{
		printf("\n%s\n", titulo);
		while (lst != NULL)
		{
			printf("%d\n", (lst)->n);
			lst = lst->next;
		}
	}
}