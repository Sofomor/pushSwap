/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:23:25 by imorina           #+#    #+#             */
/*   Updated: 2022/07/06 17:16:28 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pushswap.h"

void	is_args_nb(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j][i])
	{
		if (argv[j][i] < 48 || argv[j][i] > 57)
		{
			if (argv[j][i] != ' ' && argv[j][i] != '-' && argv[j][i] != '+')
				handle_error("erreur");
		}
		i++;
	}
	i = 0;
}

int	is_args_sorted(t_stacks *all)
{
	
	int	i;

	i = 0;
	while (i < (all->stack_a->current_size - 1))
	{
		if (all->stack_a->nb[i] > all->stack_a->nb[i + 1])
			return (0);
		i++;
	}
	return (1);
}
/*
int	is_min_max(t_stacks *all)
{

}
*/
void	handle_error(void *str)
{
	ft_printf("Error : %s\n", str);
	exit(EXIT_FAILURE);
}
