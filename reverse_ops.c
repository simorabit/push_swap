/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:29:52 by mal-mora          #+#    #+#             */
/*   Updated: 2024/03/07 11:06:39 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *tmp;
    
    if (!*stack)
        return ;
    last = ft_lstlast(*stack);
    last->next = *stack;
    *stack = last;
    tmp = *stack;
    while (tmp)
    {
        if (tmp->next == last)
            tmp->next = NULL;
        tmp = tmp->next;
    }
}

void rra(t_stack **a)
{
    reverse_rotate(a);
    ft_putstr_fd("rra\n", 1);
}

void rrb(t_stack **b)
{
    reverse_rotate(b);
    ft_putstr_fd("rrb\n", 1);
}

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_putstr_fd("rrr\n", 1);
}