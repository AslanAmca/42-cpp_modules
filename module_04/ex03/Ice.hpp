/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:48:15 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/31 19:21:51 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	// Orthodox Canonical Class Form
	Ice(void);
	virtual ~Ice(void);
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);

	// Subject
	AMateria *clone(void) const;
	void use(ICharacter &target);
};

#endif
