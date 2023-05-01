/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:16:50 by imorina           #+#    #+#             */
/*   Updated: 2022/07/10 23:16:51 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void    reverse_rotate(t_bucket *n)
{
    int i;
    int tmp;

    i = n->current_size - 1;
    tmp = n->nb[n->current_size - 1];
    while (i)
    {
        i--;
        n->nb[i + 1] = n->nb[i];
    }
    n->nb[0] = tmp;
}

// 1. 1 2 3
// 2. 1 2 3 (tmp = 3)
// 3. tant i < 2

// tmp = 3
// i = 1
// current_size - 1 = 2

// 5 = [0]      || 3 = [0]
// 5 = [1]      || 1 = [1]
// 1 = [2]      || 2 = [2]
// 2 = [3]
// 3 = [4]
// 4 = tmp 

void    rra(t_stacks *all)
{
    reverse_rotate(all->stack_a);
    ft_printf("rra\n");
}

void    rrb(t_stacks *all)
{
    reverse_rotate(all->stack_b);
    ft_printf("rrb\n");
}

void    rrr(t_stacks *all)
{
    reverse_rotate(all->stack_a);
    reverse_rotate(all->stack_b);
    ft_printf("rrr\n");
}

// 