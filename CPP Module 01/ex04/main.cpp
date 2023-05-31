/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 03:29:02 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/01 03:53:41 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void leaks(void)
{
	system("leaks SedIsForLosers");
}

int main(int argc, char **argv)
{
	Validator		validator;
	std::string		line;

	validator.argValidator(argc, argv);
	Reader reader(validator);
	while (std::getline(reader.readFile, line))
	{
		int	index = line.find(validator.getS1());
		while (index != -1)
		{
			line.insert(index, validator.getS2());
			line.erase(index + validator.getS2().length(), validator.getS1().length());
			index = line.find(validator.getS1(), index + validator.getS2().length());
		}
		reader.writeFile << line << std::endl;
	}
	reader.readFile.close();
	reader.writeFile.close();
	atexit(leaks);
	return (0);
}