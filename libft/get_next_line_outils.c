/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_outils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:03:45 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/16 12:14:20 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_tmp(char *tmp, char **line, char **rest, char *buf)
{
	char	*tp;

	*tmp = '\0';
	*line = ft_strdup(*rest);
	if (!*line)
		return (-1);
	tp = *rest;
	*rest = ft_strdup(tmp + 1);
	if (!*rest)
		return (-1);
	free(tp);
	free(buf);
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if ((char)c == '\0')
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}
