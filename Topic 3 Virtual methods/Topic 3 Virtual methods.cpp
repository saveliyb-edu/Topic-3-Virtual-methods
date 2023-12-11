#include <iostream>

#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "FamilyPets.h"


int main() {
	setlocale(LC_ALL, "ru");

	Cat cat;
	Cat* pCat = &cat;

	Dog dog;
	Dog* pDog = &dog;

	Pet* pPet = nullptr;

	int m_countMaxTemp, nMax;

	cat.voice();
	cat.name();

	dog.voice();
	dog.name();

	pCat->voice();
	pCat->name();

	pDog->voice();
	pDog->name();

	std::cout << std::endl;

	pPet = &cat;
	pPet->voice();
	pPet->name();

	pPet = pDog;
	(*pPet).voice();
	pPet->name();

	//std::cout << "Введите максимальное число питомцев в семье: ";
	//std::cin >> m_countMaxTemp;
	//if (std::cin.fail() || m_countMaxTemp != static_cast<int>(m_countMaxTemp) || m_countMaxTemp < 0) {
	//	throw std::invalid_argument("Ошибка: Ожидается целое положительное число");
	//}
	//std::cout << std::endl;
	//nMax = static_cast<int>(m_countMaxTemp);

	std::cout << "Максимальное количество питомцев в семье 2" << std::endl;
	nMax = 2;

	FamilyPets family(nMax);
	std::cout << "Есть ли Cat в family? ";
	isInFamilyPet(family, cat);
	std::cout << std::endl;

	std::cout << "Есть ли Dog в family? ";
	isInFamilyPet(family, dog);
	std::cout << std::endl;

	family += cat;
	std::cout << "Дабавили Cat в family" << std::endl;

	std::cout << "Есть ли Cat в family? ";
	isInFamilyPet(family, cat);

	family += dog;
	std::cout << "Дабавили Dog в family" << std::endl;

	std::cout << "Есть ли Dog в family? ";
	isInFamilyPet(family, dog);

	std::cout << "пытаемся добавить еще один Dog в family" << std::endl;
	family += dog;

	std::cout << std::endl;
	family.voice();

	return 0;
}
