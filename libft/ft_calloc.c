/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:07:30 by                   #+#    #+#             */
/*   Updated: 2021/10/13 18:09:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;
	char	*str;

	i = 0;
	s = malloc((count * size));
	if (!s)
		return (0);
	str = s;
	while (i < (count * size))
	{
		*(str + i) = 0;
		i++;
	}
	return (s);
}