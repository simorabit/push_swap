/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:00:51 by mal-mora          #+#    #+#             */
/*   Updated: 2024/03/09 13:18:46 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_chunks(t_stack **a, int chunks)
{
    t_stack *stk;

    stk = *a;
    while (stk)
    {
        if (stk->index < chunks)
            return (0);
        stk = stk->next;
    }
    return (1);
}

int get_index(t_stack **b,t_stack *max)
{
    t_stack *tmp;
    int     i;
    
    i = 0;
    tmp = *b;
    while (tmp)
    {
        if (tmp->val == max->val)
            return (i);
        tmp = tmp->next;
        i++;
    }
    return (i);
}
t_stack *get_max(t_stack **b)
{
    t_stack *max;
    t_stack *tmp;

    tmp = *b;
    max = tmp;
    while (tmp)
    {
        if (tmp->val > max->val)
            max = tmp;
        tmp = tmp->next;
    }
    return (max);
}

int get_chunks(t_stack *a)
{
    int len;
    
    len = ft_lstsize(a);
    if (len >= 200)
        return (len / 9);
    else
        return (len / 5);
}