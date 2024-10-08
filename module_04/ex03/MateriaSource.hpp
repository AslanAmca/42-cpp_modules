/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:01:02 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/31 22:29:01 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *materias[4];

public:
	// Orthodox Canonical Class Form
	MateriaSource(void);
	virtual ~MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);

	// Subject
	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};

#endif
