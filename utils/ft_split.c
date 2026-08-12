/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:38:33 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/10 12:39:32 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	*free_shelf(char **shelf, size_t placed)
{
	size_t	i;

	i = 0;
	while (i < placed)
		free(shelf[i++]);
	free(shelf);
	return (NULL);
}

static char	**fill_shelf(char **shelf, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (j < count)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		shelf[j] = ft_substr(s, start, i - start);
		if (!shelf[j])
			return (free_shelf(shelf, j));
		j++;
	}
	return (shelf);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**shelf;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	shelf = (char **)malloc(sizeof(char *) * (count + 1));
	if (!shelf)
		return (NULL);
	shelf[count] = NULL;
	return (fill_shelf(shelf, s, c, count));
}
