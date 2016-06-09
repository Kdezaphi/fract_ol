/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:58:40 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/05 11:58:43 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_nb_words(const char *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (s)
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			while (s[i] && s[i] != c)
			{
				if (i == 0 || s[i - 1] == c)
					nb++;
				i++;
			}
		}
	}
	return (nb);
}

int		ft_nb_char(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_nb_words(s, c) + 1));
	if (tab && s)
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			tab[j] = malloc(ft_nb_char(&s[i], c) + 1);
			if (tab[j])
			{
				k = 0;
				while (s[i] && s[i] != c)
					tab[j][k++] = s[i++];
				if (tab[j][0])
					tab[j++][k] = '\0';
			}
		}
	tab[j] = NULL;
	return (tab);
}
