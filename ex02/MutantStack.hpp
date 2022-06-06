/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:05:03 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/06/06 18:12:41 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

#include "colours.h"

using	std::stack;
using	std::cout;
using	std::endl;

template <typename T>
class	MutantStack : public stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack<T> const &tocopy);
		virtual ~MutantStack();

		MutantStack<T>	&operator=(MutantStack const &tocopy);
		
		typedef typename MutantStack<T>::template stack<T>::container_type::iterator				iterator;
		typename MutantStack<T>::template stack<T>::container_type::iterator						begin(void);
		typename MutantStack<T>::template stack<T>::container_type::iterator 						end(void);

		typedef typename MutantStack<T>::template stack<T>::container_type::const_iterator 			const_iterator;
		typename MutantStack<T>::template stack<T>::container_type::const_iterator 					begin(void) const;
		typename MutantStack<T>::template stack<T>::container_type::const_iterator 					end(void) const;

		typedef typename MutantStack<T>::template stack<T>::container_type::reverse_iterator		reverse_iterator;
		typename MutantStack<T>::template stack<T>::container_type::reverse_iterator 				rbegin(void);
		typename MutantStack<T>::template stack<T>::container_type::reverse_iterator 				rend(void);

		typedef typename MutantStack<T>::template stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
		typename MutantStack<T>::template stack<T>::container_type::const_reverse_iterator			rbegin(void) const;
		typename MutantStack<T>::template stack<T>::container_type::const_reverse_iterator			rend(void) const;

	private:
		static const bool	_print_init = true;
};

#include "MutantStack.ipp"

#endif
