/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:53:49 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/06/02 15:22:19 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Iterator>
void	Span::addNumber(Iterator start, Iterator end)
{
	this->_multiset.insert(start, end);
}
