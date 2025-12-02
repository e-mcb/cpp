#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete(_inventory[i]);
}

void	MateriaSource::learnMateria(AMateria* learnt)
{
	if (_inventory[3])
	{
		delete(_inventory[0]);
		_inventory[0] = NULL;
		for (int i = 0; i < 4; ++i)
		{
			_inventory[i - 1] = _inventory[i];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = learnt;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (0);
}

