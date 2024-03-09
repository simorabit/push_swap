/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:51:55 by mal-mora          #+#    #+#             */
/*   Updated: 2024/03/09 11:55:06 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
int my_abs(int n)
{
	if(n < 0)
		return (n * -1);
	return (n);
}
static int	count_digit_len(long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}
static	char	*if_is_negative(long *nb, int *neg, int counter)
{
	char	*str;

	*nb = -(*nb);
	str = (char *)malloc((counter + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	*neg = 1;
	return (str);
}

static	char	*if_is_positive(char *str, long *nb, int neg, int *counter)
{
	(*counter)--;
	str[*counter + neg] = '0' + (*nb % 10);
	*nb = *nb / 10;
	return (str);
}

char	*ft_itoa(int n)
{
	int		counter;
	char	*str;
	int		neg;
	long	nb;

	nb = n;
	counter = count_digit_len(nb);
	neg = 0;
	if (nb < 0)
		str = if_is_negative(&nb, &neg, counter);
	else
		str = (char *)malloc((counter + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[counter + neg] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nb > 0)
		str = if_is_positive(str, &nb, neg, &counter);
	if (neg)
		str[0] = '-';
	return (str);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
