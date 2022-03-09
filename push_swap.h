/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:30:09 by apulido-          #+#    #+#             */
/*   Updated: 2022/03/09 13:28:45 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
    int n;
    int size;
    struct s_list *next;

}t_list;

char		*ft_substr(char const *s, unsigned int start, size_t len);
int	    	ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
int     	input_control(char **input);
void    	select_num_space(char *argv, t_list **a);
void 		error_msg();
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_front(t_list **list, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_newlst(int n);
int	    	ft_lstsize(t_list *lst);
t_list		*full_a(char *input, t_list **a);
void 		ft_lstiter(t_list *lst, char *titulo);
//static int	is_space(char cr);
int 		check_space(char *argv);
void 		select_num_nospace(char *argv, t_list **a);
void 		check_order(t_list *lst);
int			check_order_logic(t_list *lst);
void 		check_repeat(t_list *a, int num);
int         check_order_reverse(t_list **lst);

char		*full_num_string(t_list **lst);
void		chose_logic(t_list **a, t_list **b);
int			*select_3lowest_nums(t_list **a);

void 		move_lst_tolowest(t_list **lst);

void 		swap_sa(t_list **a);
void 		swap_sb(t_list **b);
void 		swap_ss(t_list **a, t_list **b);
void 		push_pa(t_list **a, t_list **b);
void 		push_pb(t_list **a, t_list **b);
void 		rotate_ra(t_list **a);
void 		rotate_rb(t_list **b);
void 		rotate_rr(t_list **a, t_list **b);
void 		reverse_rotate_rra(t_list **a);
void 		reverse_rotate_rrb(t_list **b);
void 		reverse_rotate_rrr(t_list **a, t_list **b);


# endif