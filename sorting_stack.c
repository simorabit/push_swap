/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:59:48 by mal-mora          #+#    #+#             */
/*   Updated: 2024/03/09 15:12:43 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_from_b(t_stack **a, t_stack **b)
{
    int     indx;
    int     size;

    while (*b)
    {
        size = ft_lstsize(*b);
        indx = get_index(b, get_max(b));
        if (indx >= (size / 2))
        {
            while (size > indx)
            {
                rrb(b);
                indx++;
            }
        }
        else
        {
            while (indx--)
                rb(b);
        }
        pa(a, b);
        // if(size >= 2 && (*a)->val > (*a)->next->index)
        //     sa(a);
    }
}

int    sorting(t_stack **a, t_stack **b)
{
    int chunks;
    int x;
    int size;

    size = ft_lstsize(*a);
    if(size <= 5)
       return handel_min_size(a, b, size);
    x = get_chunks(*a);
    chunks = x;
    while (*a)
    {
        if ((*a)->index < chunks)
        {
            if ((*a)->index >= chunks - (x / 2))
            {
                if ((*a)->index >= chunks )
                    (pb(a, b), rr(a, b));
                else
                    (pb(a, b), rb(b));
            }
            else
                pb(a, b);
        }
        else
            ra(a);
        if (check_chunks(a, chunks))
            chunks += x;
    }
    return (0);
}
