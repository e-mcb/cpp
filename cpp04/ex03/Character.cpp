#include "Character.hpp"

Character::Character(const std::string& name) : _name(name), _trashCount(0)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	for (int i = 0; i < 10 < ++i)
		_trash[i] == NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; ++i)
		{
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}


Character::~Character() {
	for (int i = 0; i < 4; ++i)
		delete _inventory[i];
	for (int i = 0; i < _trashCount; ++i)
		delete _trash[i];
}


std::string const& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i) 
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
}


void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	if (_trashCount < 10)
	{
		_trash[_trashCount++] = _inventory[idx];
	}
	else
	{
		delete _trash[0];
		for (int i = 1; i < 10; ++i)
		{
			_trash[i - 1] = _trash[i];
		}
		_trash[9] = _inventory[idx];
	}
	_inventory[idx] = NULL;
}


void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}
