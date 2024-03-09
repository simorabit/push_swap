/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:13:47 by mal-mora          #+#    #+#             */
/*   Updated: 2024/03/08 19:08:38 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_lstlast(t_stack *stak)
{
    while (stak)
    {
        if (!stak->next)
            return (stak);
        stak = stak->next;
    }
    return (stak);
}
t_stack	*ft_lstnew(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->val = content;
    stack->index = 0;
	stack->next = NULL;
	return (stack);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		if (new->val > temp->val)
			new->index++;
		else
			temp->index++;
		temp = temp->next;
	}
	if (*stack != NULL)
	{
		new->next = *stack;
		*stack = new;
	}
	else
		*stack = new;
}

void    ft_lstadd_back(t_stack **stack, t_stack *new)
{
    t_stack *last;
    t_stack	*temp;
    
	if (!stack)
        return ;
	temp = *stack;
    while (temp)
	{
		if (new->val > temp->val)
			new->index++;
		else
			temp->index++;
		temp = temp->next;
	}
    if (*stack)
    {
        last = ft_lstlast(*stack);
        last->next = new;
    }
    else
        *stack = new;
}

void    stack_init(t_stack **a, char **nums)
{
    int i;
    int nbr;

    i = 0;
    if (!nums[i])
    {
        printf("Error\n");
        return ;
    } 
    while (nums[i])
    {
        if (isnumber(nums[i]))
        {
            nbr = ft_atoi(nums[i]);
            if (ft_strcmp(ft_itoa(nbr), nums[i]))
                printf("Error\n"); 
            if (is_duplicated(*a, nbr))
                printf("Error\n");
            else
                ft_lstadd_back(a, ft_lstnew(nbr));
        }
        else
            printf("Error\n");
        i++;
    }
}
