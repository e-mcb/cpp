#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <sstream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void	setName(std::string name);

		void	announce(void) const;

	private:
		std::string	_name;
};

#endif