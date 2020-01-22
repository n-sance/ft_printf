/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:46:32 by pcarolei          #+#    #+#             */
/*   Updated: 2019/08/19 11:53:20 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_node_copy(t_list *node)
{
	t_list	*node_copy;

	node_copy = (t_list *)malloc(sizeof(t_list));
	if (!node || !node_copy)
		return (NULL);
	node_copy->content_size = node->content_size;
	node_copy->content = malloc(node_copy->content_size);
	ft_memcpy(node_copy->content, node->content, node->content_size);
	return (node_copy);
}

t_list			*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*ptr;

	new_lst = ft_lstnew(NULL, 0);
	ptr = (t_list *)malloc(sizeof(ptr));
	new_lst->next = ptr;
	if (!new_lst || !ptr)
		return (NULL);
	ptr = new_lst;
	while (lst)
	{
		if (f(lst) != NULL)
		{
			if (ft_node_copy(f(lst)) != NULL)
			{
				ptr->next = ft_node_copy(f(lst));
				ptr = ptr->next;
			}
			else
				return (NULL);
		}
		lst = lst->next;
	}
	return (new_lst->next);
}
