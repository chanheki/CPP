/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:02:59 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/01 03:48:23 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_HPP
# define READER_HPP

#include "main.hpp"

class Reader
{
private:
    Validator& validator;

public:
    Reader(Validator& validator);
    ~Reader();
    std::string read();
    std::ifstream readFile;
    std::ofstream writeFile;
};

#endif