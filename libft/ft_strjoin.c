/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:27:07 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/03 18:00:44 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*stringjoin;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	stringjoin = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!stringjoin)
		return (NULL);
	ft_strlcpy(stringjoin, s1, len_s1 + 1);
	ft_strlcat(stringjoin, s2, len_s1 + len_s2 + 1);
	return (stringjoin);
}
