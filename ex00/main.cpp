/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:45:07 by nfernand          #+#    #+#             */
/*   Updated: 2022/06/03 16:31:00 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <random>

#include "colours.h"

using	std::endl;
using	std::cout;
using	std::vector;

template <template <typename, typename> class Container, typename Element, typename Allocator>
void	easyfind(Container<Element, Allocator> &container, int to_compare)
{
	(void)container;
	(void)to_compare;

	//std::vector<int>::iterator	test;
	Container<Element, Allocator>::iterator	test;
}

//template<typename Container, typename Datatype>
//template<typename Datatype, template <typename, typename> class Container>
//void	easyfind(Container &container, int to_compare)
//{
//	//std::vector<int>::iterator	number_found;
//	Container<Datatype, std::vector<Datatype>>	test;
//	//Container	test;
//
//	(void)to_compare;
//	(void)container;
//	//(void)number_found;
//
//	for (int i = 0; i < 10; i++)
//		test.push_back(rand() % 50);
//	
//	for (int i = 0; i < 10; i++)
//		cout << MAGENTA "<" << test[i] << ">" RESET << endl;
//
////	for (int i = 0; i < 10; i++)
////		cout << MAGENTA "<" << container[i] << ">" RESET << endl;
////	cout << endl;
////
////	cout << "looking for number :" << to_compare << endl;
////	(void)to_compare;
////	number_found = std::find(container.begin(), container.end(), 9);
////	if (number_found != container.end())
////		cout << "NUMBER FOOUND" << endl;
////	else
////		cout << "NUMBER NOT FOOUND" << endl;
//}
//template <typename Container>
//void easyfind(Container const &container, int to_compare)
//{
//	std::sort(container);
//	(void)to_compare;
//}

int	main()
{
	vector<int> vector_container;

	srand(time(0));
	for (int i = 0; i < 10; i++)
		vector_container.push_back(rand() % 50);

	easyfind(vector_container, rand() % 50);
}
