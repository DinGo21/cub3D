/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:43:21 by disantam          #+#    #+#             */
/*   Updated: 2024/06/06 12:23:01 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTS_H
# define FT_LISTS_H

# include "libft.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * Creates a new node. The 'content' member is initialized using the
 * `content` parameter. The 'next' member is initialized with NULL.
 *
 * @param content
*/
t_list	*ft_lstnew(void *content);

/**
 * Adds the `new` node to the beggining of `lst` list.
 * 
 * @param lst
 * @param new
*/
void	ft_lstadd_front(t_list **lst, t_list *newlst);

/*Computes the number of nodes inside a list.*/
int		ft_lstsize(t_list *lst);

/*Returns the last node of a list*/
t_list	*ft_lstlast(t_list *lst);

/**
 * Adds the `new` node to the end of `lst` list.
 * 
 * @param lst
 * @param new 
*/
void	ft_lstadd_back(t_list **lst, t_list *newlst);

/**
 * Takes as parameter a `lst` node and frees the memory of the
 * content and the node itself by utilizing the `del` function 
 * given as parameter.
 * 
 * @param lst
 * @param del
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * Deletes and frees the given `lst` node and all consecutive nodes
 * with the use of `del`. The given pointer will be replaced by NULL.
 * 
 * @param lst
 * @param del
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * Iterates the `lst` list and applies `f` function into the content of
 * each node.
 * 
 * @param lst
 * @param f
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Iterates the `lst` list and applies `f` function into the content of
 * each node. Creates a new list resulting from the succesive application 
 * of `f` on each node. Eliminates the content of a node with the use of 
 * `del` when necessary.
 * 
 * @param lst
 * @param f
 * @param del
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
