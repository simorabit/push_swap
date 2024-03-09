/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:33:46 by mal-mora          #+#    #+#             */
/*   Updated: 2024/03/09 13:53:44 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_input(int argc, char *arv[], t_stack **a)
{
    int i;
    char **nums;
    i = 1;
    while (i < argc)
    {
        nums = ft_split(arv[i++], 32);
        stack_init(a, nums);
        mfree(nums);
    }
}
int main(int argc, char *arv[])
{
    t_stack *a;
    t_stack *b;
    a = NULL;
    b = NULL;
    if (argc < 2)
        (ft_putstr_fd("ERROR", 1), exit(0));
    check_input(argc, arv, &a);
    
    if(!sorting(&a, &b))
        push_from_b(&a, &b);
    // while (a)
    // {
    //     printf("%d ", a->val);
    //     printf("  %d \n", a->index);
    //     a = a->next;
    // }
    // printf("===================\n");
    // while (b)
    // {
    //     printf("%d ", b->val);
    //     printf("  %d \n", b->index);
    //     b = b->next;
    // }
}
