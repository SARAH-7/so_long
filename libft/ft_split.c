/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:01:46 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/04 17:17:45 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordcount(const char *s, char c)
{
	int	num_of_words;
	int	i;

	i = 0;
	num_of_words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			num_of_words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (num_of_words);
}

void	free_word(char **str)
{
	int	i;

	i = 0;
	if (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*copy_str(const char *s, int numberofletters, char **trgh)
{
	int		j;
	char	*split;

	split = malloc((numberofletters + 1) * sizeof(char));
	if (!split)
		return (free_word(trgh), NULL);
	j = 0;
	while (j < numberofletters)
	{
		split[j] = *(s - numberofletters + j);
		j++;
	}
	split[j] = '\0';
	return (split);
}

char	**ft_split(const char *s, char c)
{
	int		num_of_letters;
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	split = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		num_of_letters = 0;
		while (*s && *s != c)
		{
			num_of_letters++;
			s++;
		}
		if (num_of_letters > 0)
			split[i++] = copy_str (s, num_of_letters, split);
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}
