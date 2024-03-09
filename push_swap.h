/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:20:16 by mal-mora          #+#    #+#             */
/*   Updated: 2024/03/09 13:19:07 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct s_stack
{
    int val;
    struct s_stack *next;
    int index;
}   t_stack;

int     ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int     is_duplicated(t_stack *stack, int nbr);
int     isnumber(char *num);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_itoa(int n);
void	mfree(char **str);
void	ft_putstr_fd(char *str, int fd);

//algo_utils
int     check_chunks(t_stack **a, int chunks);
int     get_index(t_stack **b, t_stack *max);
t_stack *get_max(t_stack **b);
int     get_chunks(t_stack *a);
int my_abs(int n);

void    stack_init(t_stack **a, char **nums);
t_stack	*ft_lstnew(int content);
t_stack *ft_lstlast(t_stack *stak);
int     ft_lstsize(t_stack *lst);
void	ft_lstadd_front(t_stack **stack, t_stack *new);


void    rotate(t_stack **stack);
void    reverse_rotate(t_stack **stack);
void    swap(t_stack **stack);
void    push(t_stack **stack_a, t_stack **stack_b);

void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    sb(t_stack **b);
void    sa(t_stack **a);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

void push_from_b(t_stack **a, t_stack **b);
int    sorting(t_stack **a, t_stack **b);

void sort_three(t_stack **a);
void sort_four(t_stack **a, t_stack **b);
void sort_five(t_stack **a, t_stack **b,t_stack *max);
int handel_min_size(t_stack **a, t_stack **b, int size);