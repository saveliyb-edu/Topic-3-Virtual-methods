#pragma once
#include "Pet.h"

class Cat : public Pet {
public:
	virtual void voice() const override;
	virtual void name() const override;
};

