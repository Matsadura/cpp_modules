/**
 * Zombie.hpp
 * Header file for the Zombie class.
 * This class represents a Zombie with personal details.
 * It includes methods to get and set Zombie's name, and announce when
 * 		it spawns.
 */
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

/**
 * Contact: class to represent a zombie with a name.
 * @Methods: getZombieName, setZombiName, announce.
 * @Attributes: _name.
 */
class Zombie
{
	public:
		Zombie( void );
		~Zombie( void );

		void	announce( void );
		void	setZombieName( std::string name );

		std::string	getZombieName( void ) const;

	private:
		std::string _name;

};

Zombie* zombieHorde( int n, std::string name );

#endif /* ZOMBIE_HPP */