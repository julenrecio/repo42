/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:19:44 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/06 13:23:16 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	get_donlges(t_simulation *sim, t_coder *coder)
{
	int	left_dongle_index;
	int	right_dongle_index;
	int	temp;
	
	left_dongle_index = coder->id;
	right_dongle_index = (coder->id + 1) % sim->number_of_coders;
	if (left_dongle_index > right_dongle_index)
	{
		temp = left_dongle_index;
		left_dongle_index = right_dongle_index;
		right_dongle_index = temp;
	}
	adquire_dongle(&sim->dongles[left_dongle_index]);
	adquire_dongle(&sim->dongles[right_dongle_index]);
}

void	adquire_dongle(t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->mutex);
	while(!dongle->available)
		pthread_cond_wait(&dongle->cond, &dongle->mutex);
	dongle->available = false;
	pthread_mutex_unlock(&dongle->mutex);
}

void	release_dongle(t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->mutex);
	dongle->available = true;
	pthread_cond_signal(&dongle->cond);
	pthread_mutex_unlock(&dongle->mutex);
}
