/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_circular_db_lst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:03:04 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/15 15:15:14 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cir_dlst	*ft_assign(t_cir_dlst **new)
{
	*new = (t_cir_dlst *)malloc(sizeof(t_cir_dlst));
	return (*new);
}

void	ft_print_first_elt_of_dcl(t_cir_dlst *lst)
{
	char	*num;

	num = ft_itoa(lst->id);
	ft_putstr_fd("id	", 1);
	ft_putendl_fd("num", 1);
	ft_putstr_fd(num, 1);
	ft_putstr_fd(" ", 1);
	free (num);
	num = ft_itoa(lst->data);
	ft_putendl_fd(num, 1);
	free (num);
}

void	ft_cer_dlstprint(t_cir_dlst *lst)
{
	char		*num;
	t_cir_dlst	*tmp;

	if (lst == NULL)
		return ;
	ft_print_first_elt_of_dcl(lst);
	tmp = lst->next;
	while (tmp != lst)
	{
		num = ft_itoa(tmp->id);
		ft_putstr_fd(num, 1);
		ft_putstr_fd(" ", 1);
		free (num);
		num = ft_itoa(tmp->data);
		ft_putendl_fd(num, 1);
		free (num);
		num = NULL;
		tmp = tmp->next;
	}
}
