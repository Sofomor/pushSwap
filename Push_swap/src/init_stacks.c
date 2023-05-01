/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:20:05 by imorina           #+#    #+#             */
/*   Updated: 2022/07/17 20:40:16 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	init_stacks(t_stacks *all)
{
	all->stack_a->nb = malloc(sizeof(int) * all->max_size);
	all->stack_b->nb = malloc(sizeof(int) * all->max_size);
	if (!all->stack_a->nb)
		handle_error("Malloc fail");
}
// all->stack_a/b->nb = reserve la memoire dynamique pour les nombres
// entres en parametre

void	init_struct(t_stacks *all, int size)
{
	all->stack_a = malloc(sizeof(t_bucket));
    all->stack_b = malloc(sizeof(t_bucket));
    if (!all->stack_a || !all->stack_b)
        handle_error("Malloc fail");
    all->max_size = size;
    all->stack_a->current_size = size;
	all->stack_b->current_size = 0;
	
	init_stacks(all);
}
// all->stack_a/b = reserve memoire dynamiquement pour 
// les tableaux de int
