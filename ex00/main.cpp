/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:45:07 by nfernand          #+#    #+#             */
/*   Updated: 2022/06/06 12:32:15 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <time.h>
#include <random>
#include <exception>

#include "easyfind.hpp"

#include "colours.h"

using	std::endl;
using	std::cout;
using	std::vector;
using	std::deque;

int	main()
{
	srand(time(0));
	cout << CYAN "[Trying vector container]" RESET << endl;
	{
		vector<int> vector_container;
		int	num_found;
		int	num_to_find;

		cout << MAGENTA "Filling vector with random numbers..." RESET << endl;
		for (int i = 0; i < 10; i++)
			vector_container.push_back(rand() % 50);

		for (int i = 0; i < 10; i++)
			cout << MAGENTA "<" << vector_container[i] << ">" RESET << endl;
		
		num_to_find = rand() % 50;
		cout << "Num to find: " MAGENTA "<" << num_to_find << ">" RESET <<endl;
	
		try
		{
			num_found = easyfind(vector_container, num_to_find);
			cout << GREEN "NUM FOUND: "<< num_found << RESET << endl;
		}
		catch(NumNotFoundException &exception)
		{
			cout << "Exception caught: " RED "<" << exception.what() << ">" RESET << endl;
			cout << MAGENTA "Returning to main..." RESET << endl;
		}
	}
	cout << CYAN "[Trying deque container]" RESET << endl;
	{
		deque<int> deque_container;
		int	num_found;
		int	num_to_find;

		cout << MAGENTA "Filling vector with random numbers..." RESET << endl;
		for (int i = 0; i < 10; i++)
			deque_container.push_back(rand() % 50);

		for (int i = 0; i < 10; i++)
			cout << MAGENTA "<" << deque_container[i] << ">" RESET << endl;
		
		num_to_find = rand() % 50;
		cout << "Num to find: " MAGENTA "<" << num_to_find << ">" RESET <<endl;
	
		try
		{
			num_found = easyfind(deque_container, num_to_find);
			cout << GREEN "NUM FOUND: "<< num_found << RESET << endl;
		}
		catch(NumNotFoundException &exception)
		{
			cout << "Exception caught: " RED "<" << exception.what() << ">" RESET << endl;
			cout << MAGENTA "Returning to main..." RESET << endl;
		}
	}
}
