/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:35:49 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/06/06 14:44:02 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <set>
#include <exception>

class	Span
{
	public:
		Span();
		Span(size_t N);
		Span(Span const &tocopy);
		~Span();

		Span	&operator=(Span const &tocopy);
		
		void	addNumber(int num);
		template <typename Iterator>
		void	addNumber(Iterator start, Iterator end);
		
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		void	printSpan(void) const;

		class	SpanFull : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class	SpanEmpty : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	private:

		size_t				_span_length;
		std::multiset<int>	_multiset; 

		//Multiset is already presorted and can hold duplicates unlike set
};

#include "Span.ipp"

#endif
