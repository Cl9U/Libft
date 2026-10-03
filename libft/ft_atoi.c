#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *str)
{
	long	r;
	int		sign;
	long	digit;

	r = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (sign == 1 && r > (LONG_MAX - digit) / 10)
			return ((int)LONG_MAX);
		else if (sign == -1 && r > (LONG_MAX - digit) / 10)
			return ((int)(-LONG_MAX - 1));
		r = r * 10 + digit;
		str++;
	}
	return ((int)(r * sign));
}
