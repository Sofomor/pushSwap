/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:47:10 by imorina           #+#    #+#             */
/*   Updated: 2022/07/10 20:47:12 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void    push(t_bucket *a, t_bucket *b)
{
    int  i;

  //  if (b->current_size >= a->max_size;
  //      return ;

  // j'agrandis la stack_b, en decrementant je change la valeur
  // de chaque nombre par le nombre qu'il y a avant
    i = b->current_size;
    while (i > 0)
    {
        i--;
        b->nb[i + 1] = b->nb[i];
    }
    b->current_size += 1;
    b->nb[0] = a->nb[0];
    // je rapetisse la stack_a, en incrementant je change la valeur
    // de chaque nombre par le nombre qu'il y a apres
    i = 0;
    while (i < a->current_size)
    {
        a->nb[i] = a->nb[i + 1];
        i++;
    }
    a->current_size -= 1;
}

//Prend le premier élément au sommet de b et le met sur a.
//Ne fait rien si b est vide
void    pa(t_stacks *all)
{
    push(all->stack_b, all->stack_a);
    ft_printf("pa\n");
}

// push a
// mettre le nb[0] de la stack b dans la stack a
void    pb(t_stacks *all)
{
    push(all->stack_a, all->stack_b);
    ft_printf("pb\n");
}

//pa
//stack a
//1. changer la current_size de a de +1
//2. decaler les nombres de + 1 vers le bas
//3. le stack_a[0] est egal au stack_b[0]

//stack_b
//1. index de b[0] prendra la valeur de l'index + 1
//2. current_size va changer de - 1