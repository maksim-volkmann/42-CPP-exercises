/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:04:30 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/19 14:06:59 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	std::cout << "-----------------------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << "-----------------------------" << std::endl;

	ICharacter* rick = new Character("Rick");
	std::cout << "My name is: " << rick->getName() << std::endl;

	IMateriaSource* materiaSrc = new MateriaSource();

	materiaSrc->learnMateria(new Ice());
	materiaSrc->learnMateria(new Cure());
	materiaSrc->learnMateria(new Ice());
	materiaSrc->learnMateria(new Ice());
	materiaSrc->learnMateria(new Ice());

	AMateria* ice1 = materiaSrc->createMateria("ice");
	AMateria* cure1 = materiaSrc->createMateria("cure");
	AMateria* ice2 = materiaSrc->createMateria("ice");

	ICharacter* morty = new Character("Morty");

	rick->equip(ice1);
	rick->equip(ice1);
	rick->equip(cure1);
	rick->equip(cure1);
	rick->equip(ice2);
	rick->use(0, *morty);
	rick->unequip(0);
	rick->use(0, *morty);
	rick->use(3, *morty);
	rick->use(1, *morty);
	rick->unequip(1);
	rick->use(1, *morty);


	delete rick;
	delete morty;
	delete materiaSrc;

	std::cout << "-----------------------------" << std::endl;
	return 0;
}
