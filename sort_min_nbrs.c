/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:32:28 by mal-mora          #+#    #+#             */
/*   Updated: 2024/03/09 11:32:42 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **a)
{
    t_stack *max;

    max = get_max(a);
    if(*a == max)
        ra(a);
    else if((*a)->next == max)
        rra(a); 
    if((*a)->val > (*a)->next->val)
        sa(a);
}

void sort_four(t_stack **a, t_stack **b)
{
    t_stack *max;

    max = get_max(a);
    while (*a)
    {
        if((*a)->val == max->val)
        {
            pb(a, b);
            break;
        }
        else
            ra(a);
    }
    sort_three(a);
    pa(a, b);
    ra(a);
}
void sort_five(t_stack **a, t_stack **b,t_stack *max)
{
    while (*a)
    {
        if((*a)->val == max->val)
        {
            pb(a, b);
            break;
        }
        else
            ra(a);
    }
    sort_four(a, b);
    pa(a, b);
    ra(a);
}
int handel_min_size(t_stack **a, t_stack **b, int size)
{
    t_stack *max;

    max = get_max(a);
    if(size == 2)
    {
        if ((*a)->val > (*a)->next->val)
            sa(a);
    }
    else if (size == 3)
        sort_three(a);
    else if (size == 4)
        sort_four(a, b);
    else if (size == 5)
        sort_five(a, b, max);
    return 1;
}