/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:51:19 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/12 11:51:20 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	return (NULL);
}
