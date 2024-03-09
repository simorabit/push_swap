/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:27:40 by mal-mora          #+#    #+#             */
/*   Updated: 2024/03/09 13:46:12 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *last;

    if (!*stack)
        return ;
    last = ft_lstlast(*stack);
    last->next = *stack;
    *stack = (*stack)->next;
    last->next->next = NULL;
}

void ra(t_stack **a)
{
    rotate(a);
    ft_putstr_fd("ra\n", 1);
}

void rb(t_stack **b)
{
    rotate(b);
    ft_putstr_fd("rb\n", 1);
}

void rr(t_stack **a, t_stack **b)
{
    rotate(b);
    rotate(a);
    ft_putstr_fd("rr\n", 1);
}