/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:04:06 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/04 09:38:51 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char const *set)
{
	int		first_index;
	int		last_index;
	int		size;
	char	*trimmed_string;

	if (!s1 || !set || *s1 == '\0')
		return (ft_strdup(""));
	first_index = 0;
	while (s1[first_index] != '\0' && ft_strchr(set, s1[first_index]))
		first_index++;
	last_index = ft_strlen(s1) - 1;
	while (last_index >= 0 && ft_strrchr(set, s1[last_index]))
		last_index--;
	if (first_index > last_index)
		return (ft_strdup(""));
	size = last_index - first_index + 2;
	trimmed_string = malloc(size * sizeof(char));
	if (!trimmed_string)
		return (NULL);
	ft_memcpy(trimmed_string, &s1[first_index], size - 1);
	trimmed_string[size - 1] = '\0';
	return (trimmed_string);
}
