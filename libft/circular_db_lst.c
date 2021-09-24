/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_db_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:12:12 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/15 15:06:02 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cir_dlst	*ft_cer_dlstnew(int data, int id)
{
	t_cir_dlst	*new;

	new = (t_cir_dlst *)malloc(sizeof(t_cir_dlst));
	if (!new)
		return (NULL);
	new->id = id;
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_cer_dlstadd_back(t_cir_dlst **head, t_cir_dlst *new)
{
	if (head && new)
	{
		if (!*head)
		{
			*head = new;
			(*head)->next = *head;
			(*head)->prev = *head;
		}
		else
		{
			new->next = *head;
			new->prev = (*head)->prev;
			(*head)->prev->next = new;
			(*head)->prev = new;
		}
	}
}

void	ft_cer_dlstclear(t_cir_dlst **lst)
{
	t_cir_dlst	*tmp;
	t_cir_dlst	*l;

	if (lst && *lst)
	{
		(*lst)->prev->next = NULL;
		(*lst)->prev = NULL;
		l = (*lst);
		while (l)
		{
			tmp = l;
			l = l->next;
			free(tmp);
			tmp = NULL;
		}
		*lst = NULL;
	}
}

void	ft_cer_dlstdelone(t_cir_dlst *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst);
		lst = NULL;
	}
}

int	ft_cer_dlst_size(t_cir_dlst *head)
{
	t_cir_dlst	*tmp;
	int			len;

	if (!head)
		return (0);
	tmp = head->next;
	len = 1;
	while (tmp != head)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
