#include "Fixed.hpp"

/**
 * Constructor
 */
Fixed::Fixed( void )
{
	std::cout << "Default Constructor called\n" ;

	this->_fixed_point = 0;
}

/**
 * Copy Constructor
 * @other: another Fixed object
 */
Fixed::Fixed( const Fixed& other)
{
	std::cout << "Copy Constructor called\n" ;
	*this = other;
	return ;
}
/**
 * Int Constructor
 * @value: integer value to convert
 */
Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called\n" ;
	this->_fixed_point = value << this->_fractional_bits;
}

/**
 * Float Constructor
 * @value: float value to convert
 */
Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called\n" ;
	this->_fixed_point = roundf(value * 256);
}

/**
 * Copy Assignment Operator
 * @other: another Fixed object
 * Return: reference to the current object
 */
Fixed& Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignement operator called\n" ;
	
	if (this != &other)
		this->_fixed_point = other.getRawBits();
	return (*this);
}

/**
 * Destructor
 */
Fixed::~Fixed( void )
{
	std::cout << "Destructor called\n" ;	
}

/**
 * Getter for the raw fixed-point value
 * Return: the raw fixed-point value
 */
int	Fixed::getRawBits( void ) const
{
	return (this->_fixed_point);
}

/**
 * Setter for the raw fixed-point value
 * @raw: the raw fixed-point value to set
 */
void Fixed::setRawBits( int const raw )
{
	this->_fixed_point = raw;
}

/**
 * Convert to float
 * Return: the float representation of the fixed-point value
 */
float Fixed::toFloat( void ) const
{
	return ((float)this->_fixed_point / 256);
}

/**
 * Convert to int
 * Return: the integer representation of the fixed-point value
 */
int Fixed::toInt( void ) const
{
	return (this->_fixed_point >> this->_fractional_bits);
}

/**
 * Overload of the insertion operator for Fixed class
 * @os: output stream
 * @fixed: Fixed object to output
 * Return: reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}