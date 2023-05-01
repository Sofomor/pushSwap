/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:53:28 by imorina           #+#    #+#             */
/*   Updated: 2022/07/10 20:53:32 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void    swap(t_bucket *n)
{
    int tmp;

    if (n->current_size < 2)
        return ;
    tmp = n->nb[0];
    n->nb[0] = n->nb[1];
    n->nb[1] = tmp;
}

void    sa(t_stacks *all)
{
   swap(all->stack_a);
   ft_printf("sa\n");
}

void    sb(t_stacks *all)
{
    swap(all->stack_b);
    ft_printf("sb\n");
}

void    ss(t_stacks *all)
{
    swap(all->stack_a);
    swap(all->stack_b);
    ft_printf("ss\n");
}