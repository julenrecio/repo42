/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:10:24 by azahino-          #+#    #+#             */
/*   Updated: 2026/06/26 12:11:45 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_adaptive_strat(double disorder)
{
	if (disorder >= 0 && disorder < 0.2)
		ft_printf(2, "[bench] strategy: Adaptive / O(n2)\n");
	else if (disorder >= 0.2 && disorder < 0.5)
		ft_printf(2, "[bench] strategy: Adaptive / O(n√n)\n");
	else if (disorder >= 0.5 && disorder <= 1)
		ft_printf(2, "[bench] strategy: Adaptive / O(n log n)\n");
	else
		ft_printf(2, "[bench] disorder not between 0 and 1\n");
}

void	ft_bench(double disorder, t_mode mode, t_cll *a)
{
	ft_printf(2, "[bench] disorder: %f%%\n", disorder * 100);
	if (mode == SIMPLE)
		ft_printf(2, "[bench] strategy: Simple / O(n2)\n");
	else if (mode == MEDIUM)
		ft_printf(2, "[bench] strategy: Medium / O(n√n)\n");
	else if (mode == COMPLEX)
		ft_printf(2, "[bench] strategy: Complex / O(n log n)\n");
	else
		print_adaptive_strat(disorder);
	ft_printf(2, "[bench] total-ops: %d\n", a->moves[11]);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", a->moves[6],
		a->moves[7], a->moves[8], a->moves[9], a->moves[10]);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		a->moves[0], a->moves[1], a->moves[2], a->moves[3],
		a->moves[4], a->moves[5]);
}
