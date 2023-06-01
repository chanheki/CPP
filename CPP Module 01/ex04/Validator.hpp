/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:42:26 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/01 16:14:46 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_HPP
# define VALIDATOR_HPP

#include "main.hpp"

class Validator
{
private:
	std::string filename;
	std::string s1;
	std::string s2;
public:
	Validator(void);
	~Validator(void);
	void argValidator(int argc, char **argv);
	void openFileValidator(std::ifstream &file);
	void failFileValidator(std::ifstream &file);
	void writeFileValidator(std::ofstream &file);
	std::string getFilename(void);
	std::string getS1(void);
	std::string getS2(void);
};

#endif