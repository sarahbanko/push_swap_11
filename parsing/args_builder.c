/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:32:24 by adrperei          #+#    #+#             */
/*   Updated: 2026/08/10 14:05:43 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	args_total_len(int argc, char **argv)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = 1;
	while (i < argc) 
	{
		j = 0;
		while (argv[i][j]) 
			j++; 
		total += j + 1; 
		i++;
	}
	return (total); 
}

static char	*join_args(int argc, char **argv)
{
	char	*joined;
	int	i;
	int	j;
	int	pos;

	joined = (char *)malloc(args_total_len(argc, argv) + 1);
	if (!joined)
		return (NULL);
	pos = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j]) 
			joined[pos++] = argv[i][j++]; 
		if (i < argc - 1) 
			joined[pos++] = ' '; 
		i++;
	}
	joined[pos] = '\0'; 
	return (joined); 
                         
}

static char	**build_dst(char **split, int count, char **argv, int *out_argc)
{
	char	**dst; 
	int	j;

	
	dst = (char **)malloc(sizeof(char *) * (count + 2));
	if (!dst)
		return (NULL);
	dst[0] = argv[0]; 
	j = 0;            
	while (j < count)
	{
		dst[j + 1] = split[j]; 
		j++;
	}
	dst[count + 1] = NULL; 
	*out_argc = count + 1; 
	return (dst);          
	
	
}

char	**build_args(int argc, char **argv, int *out_argc)
{
	char	*joined;
	char	**split;
	char	**dst;
	int	i;

	joined = join_args(argc, argv);
	if (!joined)
		return (NULL);
	split = ft_split(joined, ' ');
	free(joined);
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
		i++;
	if ( i == 0 && argc > 1)
	{
		ft_free_split(split);
		write(2, "Error\n", 6);
		return (NULL);
	}
	dst = build_dst(split, i, argv, out_argc);
	free(split);
	return (dst);
}
