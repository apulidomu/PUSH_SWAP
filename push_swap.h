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

char	*ft_substr(char const *s, unsigned int start, size_t len);
int	    ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int     input_control(char *input);
void    select_num_space(char *argv);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **list, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_newlst(int n);
int	    ft_lstsize(t_list *lst);
static int	is_space(char cr);
int check_space(char *argv);
void select_num_nospace(char *argv);


# endif