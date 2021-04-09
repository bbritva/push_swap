#include "../main.h"

int 	is_int(char *str)
{
	int			i;
	long long	num;
	int			sign;
	
	num = 0;
	i = 0;
	sign = 1;
	if (!str || !ft_strchr("-1234567890", str[i]))
		return (0);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && num <= INT32_MAX)
	{
		if (ft_isdigit(str[i]))
			num = num * 10 + str[i] - '0';
		else
			return (0);
		i++;
	}
	num *= sign;
	if (num > INT32_MAX || num < INT32_MIN)
		return (0);
	return (1);
}

// 2147483647