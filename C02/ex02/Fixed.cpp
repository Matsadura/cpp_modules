#include "Fixed.hpp"

/**
 * Constructor
 */
Fixed::Fixed( void )
{
	this->_fixed_point = 0;
}

/**
 * Copy Constructor
 * @other: another Fixed object
 */
Fixed::Fixed( const Fixed& other)
{
	*this = other;
	return ;
}

/**
 * Int Constructor
 * @value: integer value to convert
 */
Fixed::Fixed( const int value )
{
	this->_fixed_point = value << this->_fractional_bits;
}

/**
 * Float Constructor
 * @value: float value to convert
 */
Fixed::Fixed( const float value )
{
	this->_fixed_point = roundf(value * 256);
}

/**
 * Copy Assignment Operator
 * @other: another Fixed object
 * Return: reference to the current object
 */
Fixed& Fixed::operator=( const Fixed& other )
{
	if (this != &other)
		this->_fixed_point = other.getRawBits();
	return (*this);
}

/**
 * Greater than Operator
 * @other: another Fixed object
 * Return: boolean result of the comparison
 */
bool Fixed::operator>( const Fixed& other ) const
{
	return (this->_fixed_point > other.getRawBits());
}

/**
 * Less than Operator
 * @other: another Fixed object
 * Return: reference to the current object after operation
 */
bool Fixed::operator<( const Fixed& other ) const
{
	return (this->_fixed_point < other.getRawBits());
}

/**
 * Greater than or equal Operator
 * @other: another Fixed object
 * Return: boolean result of the comparison
 */
bool Fixed::operator>=( const Fixed& other ) const
{
	return (this->_fixed_point >= other.getRawBits());
}

/**
 * Less than or equal Operator
 * @other: another Fixed object
 * Return: boolean result of the comparison
 */
bool Fixed::operator<=( const Fixed& other ) const
{
	return (this->_fixed_point <= other.getRawBits());
}

/**
 * Equality Operator
 * @other: another Fixed object
 * Return: boolean result of the comparison
 */
bool Fixed::operator==( const Fixed& other ) const
{
	return (this->_fixed_point == other.getRawBits());
}

/**
 * Inequality Operator
 * @other: another Fixed object
 * Return: boolean result of the comparison
 */
bool Fixed::operator!=( const Fixed& other ) const
{
	return (this->_fixed_point != other.getRawBits());
}

/**
 * Addition Operator
 * @other: another Fixed object
 * Return: reference to the current object after operation
 */
Fixed Fixed::operator+( const Fixed& other ) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

/**
 * Subtraction Operator
 * @other: another Fixed object
 * Return: reference to the current object after operation
 */
Fixed Fixed::operator-( const Fixed& other ) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

/**
 * Multiplication Operator
 * @other: another Fixed object
 * Return: reference to the current object after operation
 */
Fixed Fixed::operator*( const Fixed& other ) const
{
	Fixed result;

	result.setRawBits((this->getRawBits() * other.getRawBits())>> this->_fractional_bits);
	return (result);
}

/**
 * Division Operator
 * @other: another Fixed object
 * Return: reference to the current object after operation
 */
Fixed Fixed::operator/( const Fixed& other) const
{
	Fixed result;

	result.setRawBits((this->getRawBits() << this->_fractional_bits) / other.getRawBits());
	return (result);
}

/**
 * Pre-increment Operator
 * Return: reference to the current object after operation
 */
Fixed& Fixed::operator++( void )
{
	++this->_fixed_point;
	return (*this);
}

/**
 * Post-increment Operator
 * Return: reference to the current object before operation
 */
Fixed Fixed::operator++( int )
{
	Fixed tmp = *this;

	++(*this);
	return (tmp);
}

/**
 * Pre-decrement Operator
 * Return: reference to the current object after operation
 */
Fixed& Fixed::operator--( void )
{
	--this->_fixed_point;
	return (*this);
}

/**
 * Post-decrement Operator
 * Return: reference to the current object before operation
 */
Fixed Fixed::operator--( int )
{
	Fixed tmp = *this;

	--(*this);
	return (tmp);
}

/**
 * Static method to get the minimum of two Fixed objects
 * @a: first Fixed object
 * @b: second Fixed object
 * Return: reference to the minimum Fixed object
 */
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return(b);
	return (a);
}

/**
 * Static method to get the minimum of two const Fixed objects
 * @a: first const Fixed object
 * @b: second const Fixed object
 * Return: reference to the minimum const Fixed object
 */
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return(b);
	return (a);	
}

/**
 * Static method to get the maximum of two Fixed objects
 * @a: first Fixed object
 * @b: second Fixed object
 * Return: reference to the maximum Fixed object
 */
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return(b);
	return (a);
}

/**
 * Static method to get the maximum of two const Fixed objects
 * @a: first const Fixed object
 * @b: second const Fixed object
 * Return: reference to the maximum const Fixed object
 */
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return(b);
	return (a);	
}

/**
 * Destructor
 */
Fixed::~Fixed( void )
{	
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