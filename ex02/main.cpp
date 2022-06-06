/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:32:06 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/06/06 18:27:03 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <random>
#include <time.h>
#include <stack>
#include <deque>
#include <list>

#include "MutantStack.hpp"

#include "colours.h"

using	std::endl;
using	std::cout;

int	main()
{
	cout << CYAN "[Testing all iterators]" RESET << endl;
	{
		int					len = 10;
		MutantStack<int>	*ms = new MutantStack<int>();

		srand(time(0));
		cout << MAGENTA "Filling MutantStack with random numbers..." RESET << endl;
		for (int i = 0; i < len; i++)
			ms->push(rand() % 100);
	
		cout << endl;
		cout << CYAN "[Printing with iterators]" RESET << endl;
		cout << MAGENTA "Printing MutantStack (with iterators forward way).." RESET << endl;
		for (MutantStack<int>::iterator i = ms->begin(); i != ms->end(); i++)
			cout << MAGENTA "[" << *i << "]" RESET << endl;

		cout << endl;
		cout << MAGENTA "Printing MutantStack (with const iterators forward way).." RESET << endl;
		for (MutantStack<int>::const_iterator i = ms->begin(); i != ms->end(); i++)
			cout << MAGENTA "[" << *i << "]" RESET << endl;

		cout << endl;
		cout << MAGENTA "Printing MutantStack (with iterators reverse way).." RESET << endl;
		for (MutantStack<int>::reverse_iterator i = ms->rbegin(); i != ms->rend(); i++)
			cout << MAGENTA "[" << *i << "]" RESET << endl;

		cout << endl;
		cout << MAGENTA "Printing MutantStack (with const reverse iterators reverse way).." RESET << endl;
		for (MutantStack<int>::const_reverse_iterator i = ms->rbegin(); i != ms->rend(); i++)
			cout << MAGENTA "[" << *i << "]" RESET << endl;

		cout << endl;
		cout << CYAN "[Modyfying values with iterators]" RESET << endl;
		cout << MAGENTA "Modyfying MutantStack (with iterators forward way).." RESET << endl;
		for (MutantStack<int>::iterator i = ms->begin(); i != ms->end(); i++)
		{
			cout << MAGENTA "[" << *i << "]" RESET " -> ";
			*i = rand() % 100;
			cout << MAGENTA "[" << *i << "]" RESET << endl;

		}
 
		cout << endl;
		cout << MAGENTA "Modyfying MutantStack (with iterators revesre way).." RESET << endl;
		for (MutantStack<int>::reverse_iterator i = ms->rbegin(); i != ms->rend(); i++)
		{
			cout << MAGENTA "[" << *i << "]" RESET " -> ";
			*i = rand() % 100;
			cout << MAGENTA "[" << *i << "]" RESET << endl;

		}

		// BOTH OF THESE SHOULD NOT WORK IF UNCOMMENTED (ATTEMPTING TO MODYING CONST VALUE)
		//cout << MAGENTA "Attemptying to Modify MutantStack (with const iterators forward way).." RESET << endl;
		//for (MutantStack<int>::const_iterator i = ms->begin(); i != ms->end(); i++)
		//{
		//	cout << MAGENTA "[" << *i << "]" RESET " -> ";
		//	*i = rand() % 100;
		//	cout << MAGENTA "[" << *i << "]" RESET << endl;
		//}
		
		//cout << MAGENTA "Attemptying to Modify MutantStack (with const iterators reverse way).." RESET << endl;
		//for (MutantStack<int>::const_reverse_iterator i = ms->rbegin(); i != ms->rend(); i++)
		//{
		//	cout << MAGENTA "[" << *i << "]" RESET " -> ";
		//	*i = rand() % 100;
		//	cout << MAGENTA "[" << *i << "]" RESET << endl;
		//}

		cout << endl;
		cout << MAGENTA "Printing final MutantStack..." RESET << endl;
		for (MutantStack<int>::iterator i = ms->begin(); i != ms->end(); i++)
			cout << MAGENTA "[" << *i << "]" RESET << endl;

		cout << endl;
		cout << "*(MutantStack->begin())		= " BLUE "<" <<  *ms->begin() << ">" RESET << endl;
		cout << "*(MutantStack->rbegin())	= " BLUE "<" <<  *ms->rbegin() << ">" RESET << endl;

		delete ms;
	}
	cout << endl << endl;

	cout << CYAN "[Comparing MutantStack with List]" RESET << endl;
	{
		int					len = 10;
		MutantStack<int>	*ms = new MutantStack<int>();
	
		cout << CYAN "==================== MUTANT STACK ====================" RESET << endl;

		srand(time(0));
		cout << MAGENTA "Filling MutantStack with random numbers..." RESET << endl;
		for (int i = 0; i < len; i++)
			ms->push(rand() % 100);
	
		cout << MAGENTA "Printing MutantStack (with iterators).." RESET << endl;
		for (MutantStack<int>::iterator i = ms->begin(); i != ms->end(); i++)
			cout << MAGENTA "[" << *i << "]" RESET << endl;

		cout << endl;
		cout << "*(MutantStack->begin())		= " BLUE "<" <<  *ms->begin() << ">" RESET << endl;
		cout << "*(MutantStack->rbegin())	= " BLUE "<" <<  *ms->rbegin() << ">" RESET << endl;
		cout << endl;

		srand(time(0));
		std::list<int>			*ls = new std::list<int>();

		cout << CYAN "======================== LIST ========================" RESET << endl;
		srand(time(0));
		for (int i = 0; i < len; i++)
			ls->push_back(rand() % 100);
	
		cout << MAGENTA "Printing List (with iterators).." RESET << endl;
		for (std::list<int>::iterator i = ls->begin(); i != ls->end(); i++)
			cout << MAGENTA "[" << *i << "]" RESET << endl;

		cout << endl;
		cout << "*(List->begin())		= " BLUE "<" <<  *(ls->begin()) << ">" RESET << endl;
		cout << "*(List->rbegin())		= " BLUE "<" <<  *(ls->rbegin()) << ">" RESET << endl;
	
		delete ls;
		delete ms;
	}

	//cout << CYAN "[Testing PDF main.cpp]" RESET << endl;
	//{
	//	MutantStack<int> mstack;

	//	mstack.push(5);
	//	mstack.push(17);
	//	std::cout << mstack.top() << std::endl;
	//	mstack.pop();
	//	std::cout << mstack.size() << std::endl;
	//	mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
	//	MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
	//	++it;
	//	--it;

	//	while (it != ite) {
	//	    std::cout << *it << std::endl;
	//	++it; }
	//	std::stack<int> s(mstack);
	//	return 0;
	//}
}
