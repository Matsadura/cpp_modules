#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

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

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif /* ZOMBIE_HPP */