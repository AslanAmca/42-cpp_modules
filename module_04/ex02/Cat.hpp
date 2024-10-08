/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:06:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/30 19:13:23 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain *brain;

public:
	Cat(void);
	virtual ~Cat(void);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);

	void makeSound(void) const;
	Brain* getBrain(void) const;
};

#endif
