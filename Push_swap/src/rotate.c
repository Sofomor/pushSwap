/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:47:15 by imorina           #+#    #+#             */
/*   Updated: 2022/07/10 20:47:17 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void    rotate(t_bucket *n)
{
    int i;
    int tmp;

    i = 0;
    tmp = n->nb[0];
    while (i++ < n->current_size - 1)
        n->nb[i - 1] = n->nb[i];
    n->nb[n->current_size - 1] = tmp;
}

void    ra(t_stacks *all)
{
    rotate(all->stack_a);
    ft_printf("ra\n");
}

void    rb(t_stacks *all)
{
    rotate(all->stack_b);
    ft_printf("rb\n");
}

void    rr(t_stacks *all)
{
    rotate(all->stack_a);
    rotate(all->stack_b);
    ft_printf("rr\n");
}

// prend le premier nombre et le met tout en bas