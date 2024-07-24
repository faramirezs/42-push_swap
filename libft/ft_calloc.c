/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:57:52 by alramire          #+#    #+#             */
/*   Updated: 2024/07/24 13:47:51 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = malloc(size * count);
	if (tmp == NULL)
		return (NULL);
	while (i < size * count)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
/* int	main(void)
{

	printf("=========Test 1 with zero======\n\n\n");
	size_t	c;
	size_t	s;

	c = 0;
	s = 0;

	printf("Pointer address with ft %p\n", ft_calloc(c, s));
	printf("Pointer address with std %p\n", calloc(c, s));

	printf("=========Test 2 with overflow======\n\n\n");
	size_t	co;
	size_t	si;

	co = 1;
	si = SIZE_MAX;

	printf("Pointer address with ft %s\n", ft_calloc(co, si));
	printf("Pointer address with std %s\n", calloc(co, si));

	return (0);
} */
