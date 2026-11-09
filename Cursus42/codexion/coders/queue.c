/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:02:09 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/09 17:50:43 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_request	*queue_get_first(t_request **queue)
{
	return (queue);
}

t_request	*queue_pop(t_request **queue)
{
	t_request	*request;

	if (!*queue)
		return (NULL);
	request = *queue;
	*queue = request->next;
	request->next = NULL;
	return (request);
}

void	queue_insert(t_request **queue, t_request *request, char *scheduler)
{
	t_request	*current;

	if (!*queue || has_priority(request, *queue, scheduler))
	{
		request->next = *queue;
		*queue = request;
		return ;
	}
	current = *queue;
	while (current->next && !has_priority(request, current->next, scheduler))
		current = current->next;
	request->next = current->next;
	current->next = request;
}

bool	has_priority(t_request *a, t_request *b, char *scheduler)
{
	if (strcmp(scheduler, "fifo") == 0)
		return (a->request_time < b->request_time);
	if (a->deadline != b->deadline)
		return (a->deadline < b->deadline);
	return (a->request_time < b->request_time);
}
