/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 main.cpp											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: nazrinshahaf <marvin@42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2022/06/06 13:14:22 by nazrinsha		   #+#	  #+#			  */
/*	 Updated: 2022/06/06 14:01:43 by nazrinsha		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include <random>
#include <vector>
#include <set>

#include "Span.hpp"

#include "colours.h"

using	std::cout;
using	std::endl;
using	std::vector;
using	std::multiset;

int	main()
{
	srand(time(0));

	cout << CYAN "[Trying span with 100 numbers]" RESET << endl;
	{
		int		len = 100;
		Span	*span = new Span(len);
		
		for (int i = 0; i < len; i++)
			span->addNumber(rand() % 10000);

		cout << MAGENTA "Printing Span..." RESET << endl;
		span->printSpan();
		cout << "Longest span: " BLUE "<" << span->longestSpan() << ">" RESET << endl;
		cout << "Shortest span: " BLUE "<" << span->shortestSpan() << ">" RESET << endl;

		delete span;
	}
	cout << endl;

	cout << CYAN "[Trying span with 10 numbers using multiset iterator and vector iterator]" RESET << endl;
	{
		int						len = 10;
		multiset<int>			set;
		Span	*span = new Span(len);
		
		cout << CYAN "[Trying with multiset iterator]" RESET << endl;
		for (int i = 0; i < len; i++)
			set.insert(rand() % 10000);

		cout << MAGENTA "Printing Set..." RESET << endl;
		for (multiset<int>::iterator i = set.begin(); i != set.end(); i++)
			cout << MAGENTA "<" << *i << ">" RESET << endl;

		cout << endl;
		cout << MAGENTA "Adding numbers into Span using iterators..." RESET << endl;
		span->addNumber(set.begin(), set.end());

		cout << endl;
		cout << MAGENTA "Printing Span..." RESET << endl;
		span->printSpan();
		cout << "Longest span: " BLUE "<" << span->longestSpan() << ">" RESET << endl;
		cout << "Shortest span: " BLUE "<" << span->shortestSpan() << ">" RESET << endl;

		delete span;

		vector<int>			vec;
		Span	*span2 = new Span(len);
		
		cout << CYAN "[Trying with vector iterator]" RESET << endl;
		for (int i = 0; i < len; i++)
			vec.push_back(rand() % 10000);

		cout << MAGENTA "Printing Set..." RESET << endl;
		for (vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
			cout << MAGENTA "<" << *i << ">" RESET << endl;

		cout << endl;
		cout << MAGENTA "Adding numbers into Span using iterators..." RESET << endl;
		span2->addNumber(vec.begin(), vec.end());

		cout << endl;
		cout << MAGENTA "Printing Span..." RESET << endl;
		span2->printSpan();
		cout << "Longest span2: " BLUE "<" << span2->longestSpan() << ">" RESET << endl;
		cout << "Shortest span2: " BLUE "<" << span2->shortestSpan() << ">" RESET << endl;

		delete span2;

	}
	cout << endl;

	cout << CYAN "[Trying to add past max limit]" RESET << endl;
	{
		int		len = 10;
		Span	*span = new Span(len);
		
		cout << CYAN "[Trying with normal fill]" RESET << endl;
		cout << MAGENTA "Filling Span with 10 numbers..." RESET << endl;
		for (int i = 0; i < len; i++)
			span->addNumber(rand() % 10000);
		span->printSpan();
		cout << MAGENTA "Adding one more number to span..." RESET << endl;
		try
		{
			span->addNumber(rand() % 10000);
		}
		catch (Span::SpanFull &exception)
		{
			cout << "Exception caught: " RED "<" << exception.what() << ">" RESET << endl;
		}

		delete span;

		Span			*span2 = new Span(len);
		multiset<int>	set;

		cout << CYAN "[Trying with iterator fill]" RESET << endl;
		cout << MAGENTA "Filling Multiset with 10 numbers..." RESET << endl;
		for (int i = 0; i < 1; i++)
			set.insert(rand() % 10000);

		cout << endl;
		cout << MAGENTA "Printing Multiset..." RESET << endl;
		for (multiset<int>::iterator i = set.begin(); i != set.end(); i++)
			cout << MAGENTA "<" << *i << ">" RESET << endl;

		cout << endl;
		cout << MAGENTA "Filling Span with 10 numbers..." RESET << endl;
		for (int i = 0; i < len; i++)
			span2->addNumber(rand() % 10000);
		span2->printSpan();

		cout << endl;
		cout << MAGENTA "Adding one number into Span using iterators..." RESET << endl;
		try
		{
			span2->addNumber(set.begin(), set.end());
		}
		catch (Span::SpanFull &exception)
		{
			cout << "Exception caught: " RED "<" << exception.what() << ">" RESET << endl;
		}

		delete span2;
	}
	cout << endl;

	cout << CYAN "[Trying to get Span with no numbers and one number]" RESET << endl;
	{
		int		len = 10;
		Span	*span = new Span(len);
		
		try
		{
			cout << "Longest span: " BLUE "<";
			cout << span->longestSpan() << ">" RESET << endl;
		}
		catch (Span::SpanEmpty &exception)
		{
			cout << endl << RESET "Exception caught: " RED "<" << exception.what() << ">" RESET << endl;
		}
		try
		{
			cout << "Shortest span: " BLUE "<";
			cout << span->shortestSpan() << ">" RESET << endl;
		}
		catch (Span::SpanEmpty &exception)
		{
			cout << endl << RESET "Exception caught: " RED "<" << exception.what() << ">" RESET << endl;
		}

		cout << MAGENTA "Adding one number to span..." RESET << endl;
		span->addNumber(rand() % 10000);
		span->printSpan();
		try
		{
			cout << "Longest span: " BLUE "<";
			cout << span->longestSpan() << ">" RESET << endl;
		}
		catch (Span::SpanEmpty &exception)
		{
			cout << endl << RESET "Exception caught: " RED "<" << exception.what() << ">" RESET << endl;
		}
		try
		{
			cout << "Shortest span: " BLUE "<";
			cout << span->shortestSpan() << ">" RESET << endl;
		}
		catch (Span::SpanEmpty &exception)
		{
			cout << endl << RESET "Exception caught: " RED "<" << exception.what() << ">" RESET << endl;
		}

		delete span;
	}
	cout << endl;

	cout << CYAN "[Trying span with 10000 numbers]" RESET << endl;
	{
		int		len = 10000;
		Span	*span = new Span(len);
		
		for (int i = 0; i < len; i++)
			span->addNumber(rand() % 100000);

		cout << MAGENTA "Printing Span..." RESET << endl;
		span->printSpan();
		cout << "Longest span: " BLUE "<" << span->longestSpan() << ">" RESET << endl;
		cout << "Shortest span: " BLUE "<" << span->shortestSpan() << ">" RESET << endl;

		delete span;
	}
	cout << endl;


	cout << CYAN "[Trying PDF main.cpp]" RESET << endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
}
