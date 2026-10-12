/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:50:30 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/12 11:50:31 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dst;
	size_t			i;

	i = 0;
	dst = (unsigned char *)s;
	while (i < n)
		dst[i++] = (unsigned char)c;
	return (s);
}
