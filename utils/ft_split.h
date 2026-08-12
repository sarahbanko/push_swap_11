/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PersonA <persona@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 00:00:00 by PersonA           #+#    #+#             */
/*   Updated: 2026/07/19 00:00:00 by PersonA          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
void	ft_free_split(char **split);
void	ft_putnbr_fd(int n, int fd);

#endif
