/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:53:51 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/16 19:54:04 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	l;

	if (!s1)
		return (NULL);
	l = ft_strlen(s1);
	str = (char *)malloc(l + 1);
	if (str)
		ft_strlcpy(str, s1, l + 1);
	return (str);
}
