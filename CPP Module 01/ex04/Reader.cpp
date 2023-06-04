/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:03:56 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/03 22:13:38 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Reader::Reader(Validator& validator) : validator(validator),
	readFile(validator.getFilename()),
	writeFile((validator.getFilename() + ".replace").c_str())
	{}

Reader::~Reader(void){}

std::string Reader::read() {
	std::string line;
	std::string content;

	while (std::getline(readFile, line)) {
		this->validator.openFileValidator(readFile);
		content += line;
		if (!readFile.eof())
			content += "\n";
	}
	readFile.close();
	return content;
}