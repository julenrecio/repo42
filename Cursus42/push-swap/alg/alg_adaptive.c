/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_adaptive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:04:20 by azahino-          #+#    #+#             */
/*   Updated: 2026/06/27 19:27:10 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	how_many_chunks(t_cll *a)
{
	int	size;

	size = a->size;
	if (size >= 500)
		return (9);
	else if ((size >= 100) && (size < 500))
		return (4);
	else
		return ((int)ft_square_root(size));
}

void	alg_adaptive(double disorder, t_cll *stack_a, t_cll *stack_b)
{
	if (disorder >= 0 && disorder < 0.2)
		alg_simple(stack_a, stack_b);
	else if (disorder >= 0.2 && disorder < 0.5)
		alg_medium(stack_a, stack_b,
			how_many_chunks(stack_a), stack_a->size);
	else if (disorder >= 0.5 && disorder <= 1)
		alg_complex(stack_a, stack_b);
}
