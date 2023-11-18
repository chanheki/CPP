#pragma once

#include <algorithm>
#include <iostream>


template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw std::runtime_error("404 Not found");
	return iter;
}

template <typename T>
void print(T const &t) {
  std::cout << t << std::endl;
}
