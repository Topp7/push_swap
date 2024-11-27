/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:05:19 by stopp             #+#    #+#             */
/*   Updated: 2023/10/13 17:13:29 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	const char	*temp;

	temp = s;
	while (*temp != '\0')
	{
		if (*temp == (unsigned char)c)
			return ((char *)temp);
		temp++;
	}
	if (*temp == '\0' && (unsigned char)c == '\0')
		return ((char *)temp);
	else
		return (NULL);
}

// int	main(void)
// {
// 	const char	s[] = "01234a56789";

// 	printf("strchr %c\n", *strchr(s, '\0'));
// 	printf("ft_strchr %c\n", *ft_strchr(s, '\0'));
// 	return (0);
// }
