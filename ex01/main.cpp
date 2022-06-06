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

#include "Span.hpp"

#include "colours.h"

using	std::cout;
using	std::endl;

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

	cout << CYAN "[Trying to add past max limit]" RESET << endl;
	{
		int		len = 10;
		Span	*span = new Span(len);
		
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

//	cout << CYAN "[Trying span with 10000 numbers]" RESET << endl;
//	{
//		int		len = 10000;
//		Span	*span = new Span(len);
//		
//		for (int i = 0; i < len; i++)
//			span->addNumber(rand() % 100000);
//
//		cout << MAGENTA "Printing Span..." RESET << endl;
//		span->printSpan();
//		cout << "Longest span: " BLUE "<" << span->longestSpan() << ">" RESET << endl;
//		cout << "Shortest span: " BLUE "<" << span->shortestSpan() << ">" RESET << endl;
//
//		delete span;
//	}
//	cout << endl;
//
//
//	cout << CYAN "[Trying PDF main.cpp]" RESET << endl;
//	{
//		Span sp = Span(5);
//
//		sp.addNumber(6);
//		sp.addNumber(3);
//		sp.addNumber(17);
//		sp.addNumber(9);
//		sp.addNumber(11);
//		std::cout << sp.shortestSpan() << std::endl;
//		std::cout << sp.longestSpan() << std::endl;
//	}
}
