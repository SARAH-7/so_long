/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:05:51 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/04 09:22:08 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*r;

	if (size != 0 && count > UINT32_MAX / size)
		return (NULL);
	r = malloc(count * size);
	if (r == NULL)
		return (NULL);
	ft_bzero(r, count * size);
	return (r);
}

// int main() 
// {
//     size_t count = SIZE_MIN;
//     size_t size = 1; // Set a smaller size
//     char *tst = ft_calloc(count, size);

//     if (tst == NULL) {
//         printf("Memory allocation failed, returned NULL as expected.\n");
//     } else {
//         printf("Memory allocation succeeded, unexpected result!\n");
//         free(tst);
//     }

//     return 0;
// }