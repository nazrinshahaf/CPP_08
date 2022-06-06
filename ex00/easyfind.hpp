/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:24:05 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/06/05 16:33:31 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <exception>

using	std::vector;

class	NumNotFoundException : public std::exception
{
	public:
		virtual const char *what(void) const throw()
		{
			return ("Num Not Found");
		}
};

template <typename Container>
int	easyfind(Container container, int to_compare)
{
	typename Container::iterator	num;

	num = std::find(container.begin(), container.end(), to_compare);
	if (num == container.end())
		throw NumNotFoundException();
	return (*num);
}

#endif
