#ifndef MateriaSource_HPP
# define MateriaSource_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	_inventory[4];


public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const& type);
};

#endif