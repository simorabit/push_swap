/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:43:53 by mal-mora          #+#    #+#             */
/*   Updated: 2024/02/27 20:43:55 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	is_whitespace(char c)
{
	return (c == 32 || (9 <= c && c <= 13));
}

static	int	handle_overflow(int sign)
{
	if (sign == -1)
		return (0);
	else if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;
	long	result;

	sign = 1;
	res = 0;
	result = 0;
	while ((*str && is_whitespace(*str)))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			(sign *= -1);
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result = res * 10 + (*str - 48);
		if (res > result)
			return (handle_overflow(sign));
		str++;
		res = result;
	}
	return (result * sign);
}
