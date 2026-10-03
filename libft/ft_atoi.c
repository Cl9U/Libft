#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *nptr)
{
	long	r;
	int		sign;
	long	digit;

	r = 0;
	sign = 1;
	while (is_space(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		digit = *nptr - '0';
		if (sign == 1 && r > (LONG_MAX - digit) / 10)
			return ((int)LONG_MAX);
		else if (sign == -1 && r > (LONG_MAX - digit) / 10)
			return ((int)(-LONG_MAX - 1));
		r = r * 10 + digit;
		nptr++;
	}
	return ((int)(r * sign));
}
