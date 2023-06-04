/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:37:06 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/04 02:19:11 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

int main( void ) {
	{
	std::cout << "only an integer part" << std::endl;
	Point a(0, 0);
	Point b(5, 9);
	Point c(8, 3);

	std::cout << bsp(a, b, c, Point(3, 3)) << std::endl;
	std::cout << bsp(a, b, c, Point(5, 4)) << std::endl;
	std::cout << bsp(a, b, c, Point(0, 9)) << std::endl;
	std::cout << bsp(a, b, c, Point(0, 0)) << std::endl;
	std::cout << result(a, b, c, Point(5, 9)) << std::endl;
	std::cout << result(a, b, c, Point(8, 3)) << std::endl;
	std::cout << result(a, b, c, Point(5, 3)) << std::endl;
	}
	std::cout << "---" << std::endl;
	{
	std::cout << "float part" << std::endl;
	Point a(1.5f, 1.5f);
	Point b(4.5f, 7.5f);
	Point c(6.5f, 2.5f);

	std::cout << bsp(a, b, c, Point(3, 3)) << std::endl;
	std::cout << bsp(a, b, c, Point(4.5f, 3.2f)) << std::endl;
	std::cout << bsp(a, b, c, Point(0, 9)) << std::endl;
	std::cout << bsp(a, b, c, Point(1.5f, 1.5f)) << std::endl;
	std::cout << result(a, b, c, Point(5, 9)) << std::endl;
	std::cout << result(a, b, c, Point(8, 3)) << std::endl;
	std::cout << result(a, b, c, Point(5.5f, 3.5f)) << std::endl;
	}
	std::cout << "---" << std::endl;
	{
	std::cout << "line point" << std::endl;
	Point a(0, 0);
	Point b(0, 4);
	Point c(4, 0);

	std::cout << bsp(a, b, c, Point(0, 0)) << std::endl;
	std::cout << bsp(a, b, c, Point(0, 3)) << std::endl;
	std::cout << bsp(a, b, c, Point(3, 0)) << std::endl;
	std::cout << bsp(a, b, c, Point(0, 4)) << std::endl;
	std::cout << result(a, b, c, Point(0, 4)) << std::endl;
	std::cout << result(a, b, c, Point(4, 0)) << std::endl;
	std::cout << result(a, b, c, Point(0, 0)) << std::endl;
	}

	return 0;
}