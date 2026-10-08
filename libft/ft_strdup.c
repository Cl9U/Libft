#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = malloc((len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, len + 1);
	return (str);
}
