/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:31:08 by mal-mora          #+#    #+#             */
/*   Updated: 2024/03/06 15:33:44 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack)
{
    t_stack *a;
    t_stack *b;
    
    if (!stack)
        return;
    a = *stack;
    b = (*stack)->next;
    a->next = b->next;
    b->next = a;
    *stack = b;
}

void sa(t_stack **a)
{
    swap(a);
    ft_putstr_fd("sa\n", 1);
}

void sb(t_stack **b)
{
    swap(b);
    ft_putstr_fd("sb\n", 1);
}