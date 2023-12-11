#pragma once
#include "Pet.h"
#include <iostream>

class FamilyPets {
private:
	int m_countMax;
	int m_count;
	Pet** m_pet;
public:
	FamilyPets(int countMax);
	~FamilyPets();

	void voice() const;
	void name() const;

	FamilyPets operator+=(Pet& pet);

	friend bool isInFamilyPet(FamilyPets& family, const Pet& pet);
	friend std::ostream& operator<<(std::ostream& out, const FamilyPets& family);
};

