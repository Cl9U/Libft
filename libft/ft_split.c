/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:02:07 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/12 17:07:38 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	in_word;
	size_t	count;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (count);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	*ft_free_all(char **strs, size_t n)
{
	while (n--)
		free(strs[n]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;

	if (!s)
		return (NULL);
	strs = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			strs[i] = ft_substr(s, 0, ft_wordlen(s, c));
			if (!strs[i])
				return (ft_free_all(strs, i));
			s += ft_strlen(strs[i]);
			i++;
		}
		else
			s++;
	}
	strs[i] = NULL;
	return (strs);
}

int main()
{
	char **str;
	str = ft_split("helloShelloShello", 'S');
	int i = 0;
	while (i < 3)
		printf("%s\n", str[i++]);
}