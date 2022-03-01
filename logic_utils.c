/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:42:10 by apulido-          #+#    #+#             */
/*   Updated: 2022/02/17 17:52:13 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_lst_tolowest(t_list **lst)
{
	int lowest;
	t_list *aux;

	lowest = 0;
	if (lst != NULL)
	{
		aux = *lst;
		lowest = (*lst)->n;
		while (aux != NULL)
		{
			if(aux->n < lowest)
				lowest = aux->n;
			aux = aux->next;
		}
	}
	while((*lst)->n != lowest)
		rotate_ra(lst);
}

char *full_num_string(t_list **lst)
{
	int i;
	t_list *aux;
	char *nums;
	i = 0;
	aux = *lst;
	nums = malloc(ft_lstsize(*lst) * sizeof(int));
	if (!nums)
		error_msg();
	while(aux->next != NULL)
	{
		nums[i] = aux->n;
		aux = aux->next;
		i++;
		printf("%c", nums[i]);
	}
	return(nums);
}