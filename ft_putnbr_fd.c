/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:44:25 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/11 18:00:58 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	temp;

	if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
    } else if (n < 0)
    {
        write(fd, &"-", 1);
        ft_putnbr_fd(-n, fd);
    }
    else if (n > 9)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
    else
    {
		temp = n + '0';
        write(fd, &temp, 1);
    }
}
