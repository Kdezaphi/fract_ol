/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 12:58:58 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/02/11 12:58:59 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dup_join(char *dst, char *src)
{
	char	*tmp;

	tmp = ft_strdup(dst);
	free(dst);
	dst = ft_strjoin(tmp, src);
	free(src);
	free(tmp);
	return (dst);
}
