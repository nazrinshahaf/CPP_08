/* **************************************************************************** */ 
/*                                                                              */ 
/*                                                         :::      ::::::::    */ 
/*    Array.ipp                                          :+:      :+:    :+:    */ 
/*                                                     +:+ +:+         +:+      */ 
/*    By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+         */ 
/*                                                 +#+#+#+#+#+   +#+            */ 
/*    Created: 2022/06/06 16:23:37 by nazrinsha         #+#    #+#              */ 
/*    Updated: 2022/06/06 16:23:37 by nazrinsha        ###   ########.fr        */ 
/*                                                                              */ 
/* **************************************************************************** */ 

template <typename T>
MutantStack<T>::MutantStack() : stack<T>()
{
	if (this->_print_init)
		cout << GREEN "MutantStack Default Constructor called" RESET << endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	if (this->_print_init)
		cout << RED "MutantStack Destructor called" RESET << endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &tocopy) : stack<T>(tocopy)
{
	if (this->_print_init)
		cout << GREEN "MutantStack Copy Constructor called" RESET << endl;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack const &tocopy)
{
	if (this->_print_init)
		cout << GREEN "MutantStack Copy Assingment Operator called" RESET << endl;
	stack<T>() = tocopy;
	return (*this);
}

//c is a private member object of std::stack
template <typename T>
typename MutantStack<T>::template stack<T>::container_type::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::template stack<T>::container_type::iterator 	MutantStack<T>::end(void)
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::template stack<T>::container_type::const_iterator 	MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::template stack<T>::container_type::const_iterator 	MutantStack<T>::end(void) const
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::template stack<T>::container_type::reverse_iterator 	MutantStack<T>::rbegin(void)
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::template stack<T>::container_type::reverse_iterator 	MutantStack<T>::rend(void)
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::template stack<T>::container_type::const_reverse_iterator 	MutantStack<T>::rbegin(void) const
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::template stack<T>::container_type::const_reverse_iterator 	MutantStack<T>::rend(void) const 
{
	return (this->c.rend());
}
