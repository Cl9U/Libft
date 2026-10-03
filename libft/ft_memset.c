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
