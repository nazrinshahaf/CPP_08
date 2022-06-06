/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:40:39 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/06/06 14:38:28 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <iostream>

#include "Span.hpp"

#include "colours.h"

using	std::cout;
using	std::endl;
using	std::multiset;

Span::Span()
{
	cout << GREEN "Span Default Constructor called" RESET << endl;
	this->_span_length = 0;
}

Span::Span(size_t N)
{
	cout << GREEN "Span Assignment Constructor called" RESET << endl;
	this->_span_length = N;
}

Span::~Span()
{
	cout << RED "Span Destructor called" RESET << endl;
}

Span::Span(Span const &tocopy)
{
	cout << GREEN "Span Copy Constructor called" RESET << endl;
	this->_span_length = tocopy._span_length;
	this->_multiset = tocopy._multiset;
	/*
	 * can also copy using std::copy
	 * */
}

Span	&Span::operator=(Span const &tocopy)
{
	cout << GREEN "Span Assignment Operator called" RESET << endl;
	this->_span_length = tocopy._span_length;
	this->_multiset = tocopy._multiset;
	return (*this);
}

void	Span::addNumber(int num)
{
	if (this->_multiset.size() == _span_length)
		throw SpanFull();
	this->_multiset.insert(num);
}

int		Span::shortestSpan(void) const
{
	multiset<int>::iterator	start;
	multiset<int>::iterator next;
	int						diff;

	if (this->_multiset.size() <= 1 || this->_multiset.empty())
		throw SpanEmpty();
	start = this->_multiset.begin();
	next = ++this->_multiset.begin();
	diff = *next - *start;
	if (diff == 0)
		return (diff);
	while (next != this->_multiset.end())
	{
		if (*next - *start < diff)
			diff = *next - *start;
		//cout << "diff: " << *next - *start << endl;
		if (diff == 0)
			return (diff);
		start++;
		next++;
	}
	return (diff);
}

int		Span::longestSpan(void) const
{
	int		start;
	int		end;

	if (this->_multiset.size() <= 1 || this->_multiset.empty())
		throw SpanEmpty();
	start = *(this->_multiset.begin());
	end = *(this->_multiset.rbegin());
	return (end - start);
}

void	Span::printSpan(void) const
{
	for (multiset<int>::iterator i = this->_multiset.begin(); i != this->_multiset.end(); i++)
		cout << MAGENTA "<" << *i << ">" RESET << endl;
}

/*
 * EXCEPTIONS
 * */

const char *Span::SpanFull::what(void) const throw()
{
	return ("Span is full");
}

const char *Span::SpanEmpty::what(void) const throw()
{
	return ("Span does not have enough numbers");
}
