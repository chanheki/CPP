/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:52:28 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/01 16:14:39 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Validator::Validator(void)
{
    this->filename = "";
    this->s1 = "";
    this->s2 = "";
}

Validator::~Validator(void){}

void Validator::argValidator(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./SedIsForLosers <filename> <string1> <string2>" << std::endl;
        exit(1);
    }
    this->filename = argv[1];
    this->s1 = argv[2];
    this->s2 = argv[3];
}

void Validator::openFileValidator(std::ifstream &file)
{
    file.open(this->filename);
    if (!file)
    {
        std::cerr << "Failed to open the input file." << std::endl;
        exit(1);
    }
}

void Validator::failFileValidator(std::ifstream &file)
{
    file.fail();
    if (!file)
    {
        std::cerr << "Failed to open the input file." << std::endl;
        exit(1);
    }
}

void Validator::writeFileValidator(std::ofstream &file)
{
    file.open(this->filename + ".replace");
    if (!file)
    {
        std::cerr << "Failed to open the output file." << std::endl;
        exit(1);
    }
}

std::string Validator::getFilename(void)
{
    return this->filename;
}

std::string Validator::getS1(void)
{
    return this->s1;
}

std::string Validator::getS2(void)
{
    return this->s2;
}
