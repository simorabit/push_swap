/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:27:28 by mal-mora          #+#    #+#             */
/*   Updated: 2024/02/27 21:34:20 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	count_words(char *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

static char	*ft_word(char *s, char c, char **arr, int ind)
{
	int		i;
	char	*output;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	output = (char *)malloc(sizeof(char) * (i + 1));
	if (!output)
	{
		while (j < ind)
			free(arr[j++]);
		return (NULL);
	}
	i = 0;
	while (s[i] && s[i] != c)
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	array = (char **)malloc((count_words((char *)s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			array[j] = ft_word((char *)s, c, array, j);
			if (array[j] == NULL)
				free(array);
			j++;
		}
		while (*s && *s != c)
			s++;
	}
	array[j] = 0;
	return (array);
}
