/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:03:56 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/01 03:48:14 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Reader::Reader(Validator& validator) : validator(validator),
	readFile(validator.getFilename()),
	writeFile((validator.getFilename() + ".replace").c_str())
	{}

Reader::~Reader(void){}

std::string Reader::read() {
	std::ifstream file(this->validator.getFilename().c_str());
	std::string line;
	std::string content;

	while (std::getline(file, line)) {
		this->validator.openFileValidator(file);
		content += line;
		if (!file.eof())
			content += "\n";
	}
	file.close();
	return content;
}