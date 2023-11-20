#include "Fixed.hpp"
#include <ostream>



Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixedPointValue = 0;
}

Fixed::Fixed(const int intNumber)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = (intNumber * (1 << fractionalBits));
}

Fixed::Fixed(const float floatNumber)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPointValue = static_cast<int>(roundf(floatNumber * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	float	floatValue;

	floatValue = fixedPointValue * 1.0 / (1 << fractionalBits);
	return (floatValue);
}

int		Fixed::toInt(void) const
{
	return (static_cast<int>(fixedPointValue * 1.0 / (1 << fractionalBits)));
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointValue = fixed.fixedPointValue;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}