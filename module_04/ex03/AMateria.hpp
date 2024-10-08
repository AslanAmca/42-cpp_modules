/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:48:15 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/31 23:14:15 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

// Forward Declaration (İleri bildirim) yöntemi
// ICharacter sınıfının var olduğunu bildiriyoruz.
class ICharacter;

class AMateria
{
protected:
	std::string type;

public:
	// Orthodox Canonical Class Form
	AMateria(void);
	virtual ~AMateria(void);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);

	// Subject
	AMateria(std::string const &type);
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
