/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:30:00 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/12 12:00:00 by adrperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	len;

	len = ft_strlen(s);
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	ft_memcpy(c, s, len);
	c[len] = '\0';
	return (c);
}
