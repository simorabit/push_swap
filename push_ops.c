/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:26:35 by mal-mora          #+#    #+#             */
/*   Updated: 2024/03/08 19:27:52 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *a;
    
    a = *stack_a;
    if (!a)
        return ;
    *stack_a = (*stack_a)->next;
    if(*stack_b == NULL)
    {
        *stack_b = a;
        a->next = NULL;
    }
    else
    {
        a->next = *stack_b;
        *stack_b = a;
    }
}

void pa(t_stack **a, t_stack **b)
{
    push(b, a);
    ft_putstr_fd("pa\n", 1);
}

void pb(t_stack **a, t_stack **b)
{
    push(a, b);
    ft_putstr_fd("pb\n", 1);

}