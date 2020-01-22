/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 04:43:59 by pcarolei          #+#    #+#             */
/*   Updated: 2019/09/29 19:22:06 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddl(t_list **root, t_list *new)
{
	t_list	*ptr;

	if (!root)
		return ;
	if (!*root)
	{
		*root = new;
		return ;
	}
	ptr = *root;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}
