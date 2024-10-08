/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:48:15 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/31 18:32:53 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	// Orthodox Canonical Class Form
	Cure(void);
	virtual ~Cure(void);
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);

	// Subject
	AMateria *clone(void) const;
	void use(ICharacter &target);
};

#endif
