/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smondesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:47:44 by smondesi          #+#    #+#             */
/*   Updated: 2019/01/18 16:56:57 by smondesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int             ft_factorial(int nb)
{
	int a;

	a = 0;
	if (nb == 0)
		return (1);
	if (nb <= 12 && nb >= 0)
		return (nb * ft_factorial(nb - 1));
	else
		return (0);
}
