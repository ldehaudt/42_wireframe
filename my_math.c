/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 01:13:17 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/07 01:13:22 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			signof(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

int			abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
