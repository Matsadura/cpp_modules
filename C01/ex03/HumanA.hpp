#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon;

	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA();

		Weapon const& getWeapon( void ) const;
		void	attack( void );
};