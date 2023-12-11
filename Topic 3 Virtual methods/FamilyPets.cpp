#include "FamilyPets.h"
#include <exception>


FamilyPets::FamilyPets(int countMax) {
	try {
		m_pet = new Pet*[countMax];
		m_countMax = countMax;
		m_count = 0;
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
}

FamilyPets::~FamilyPets() {
}

void FamilyPets::voice() const {
	for (int i = 0; i < m_count; i++) {
		m_pet[i]->voice();
	}
}

void FamilyPets::name() const {
	for (int i = 0; i < m_count; i++) {
		m_pet[i]->name();
	}
}

FamilyPets FamilyPets::operator+=(Pet& pet) {
	if (m_count < m_countMax) {
		m_pet[m_count] = &pet;
		m_count++;
	}
	else {
		std::cerr << "Ошибка!, Вы уже доавили максимальное количество элементов" << std::endl;
	}
	return *this;
}

bool isInFamilyPet(FamilyPets& family, const Pet& pet) {
	for (int i = 0; i < family.m_count; i++) {
		if (family.m_pet[i] == &pet) {
			std::cout << typeid(pet).name() << std::endl;
			return true;
		}
	}
	std::cout << "Такого типа нет";
	return false;
}
 
std::ostream& operator<<(std::ostream& out, const FamilyPets& family) {
	for (int i = 0; i < family.m_count; i++) {
		family.m_pet[i]->voice();
		std::cout << " ";
		family.m_pet[i]->name();
	}
	return out;
}