/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:12:57 by mal-mora          #+#    #+#             */
/*   Updated: 2024/03/07 12:26:45 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isnumber(char *num)
{
    int i;

    i = 0;
    if (num[i] == '-' || num[i] == '+')
		if (!(num[++i] >= '0' && num[i] <= '9'))
			return (0);
    while (num[i])
    {
        if (!(num[i] >= '0' && num[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int is_duplicated(t_stack *stack, int nbr)
{
    while (stack)
    {
        if (stack->val == nbr)
            return (1);
        stack = (stack)->next;
    }
    return (0);
}
