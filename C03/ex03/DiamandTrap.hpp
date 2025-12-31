#ifndef DIAMANDTRAP_HPP
# define DIAMANDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamandTrap: public FragTrap, public ScavTrap
{
	private:
		std::string _name;
	public:
		DiamandTrap( void );
		DiamandTrap( const std::string& name );
		DiamandTrap( const DiamandTrap& other );
		DiamandTrap& operator=( const DiamandTrap& other );
		~DiamandTrap( void );
		void	attack( const std::string &target );
		void	whoAmI( void );
};

#endif /* DIAMANDTRAP_HPP */