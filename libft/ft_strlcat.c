/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:50:55 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/14 13:16:33 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = 0;
	while (dst[dlen] && dlen < dsize)
		dlen++;
	slen = ft_strlen(src);
	if (dlen >= dsize)
		return (dsize + slen);
	i = 0;
	while (src[i] && dlen + i + 1 < dsize)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
