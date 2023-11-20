#include "Fixed.hpp"
#include <cmath>
#include <ostream>



Fixed::Fixed()
{
	fixedPointValue = 0;
}

Fixed::Fixed( const int intNumber )
{
	fixedPointValue = (intNumber * (1 << fractionalBits));
}

Fixed::Fixed( const float floatNumber )
{
	fixedPointValue = roundf(floatNumber * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	fixedPointValue = fixed.fixedPointValue;
}

Fixed::~Fixed()
{

}

int	Fixed::toInt() const
{
	return (static_cast<int>(fixedPointValue * 1.0 / (1 << fractionalBits)));
}

float	Fixed::toFloat() const
{
	return (fixedPointValue * 1.0 / (1 << fractionalBits));
}

int	Fixed::getFixedPointValue(void) const
{
	return (fixedPointValue);
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	fixedPointValue = fixed.fixedPointValue;
	return (*this);
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->fixedPointValue < fixed.fixedPointValue);
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->fixedPointValue > fixed.fixedPointValue);
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->fixedPointValue <= fixed.fixedPointValue);
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->fixedPointValue >= fixed.fixedPointValue);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->fixedPointValue == fixed.fixedPointValue);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->fixedPointValue != fixed.fixedPointValue);
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	Fixed	obj;

	obj.fixedPointValue = this->fixedPointValue + fixed.fixedPointValue;
	return (obj);
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
	Fixed	obj;

	obj.fixedPointValue = this->fixedPointValue - fixed.fixedPointValue;
	return (obj);
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	Fixed	obj;

	obj.fixedPointValue = this->fixedPointValue * fixed.fixedPointValue / (1 << fractionalBits);
	return (obj);
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	Fixed	obj;

	obj.fixedPointValue = this->fixedPointValue / fixed.fixedPointValue * (1 << fractionalBits);
	return (obj);
}

Fixed	Fixed::operator++()
{
	Fixed	obj;

	obj.fixedPointValue = ++this->fixedPointValue;
	return (obj);
}

Fixed	Fixed::operator++(int)
{
	Fixed	obj;

	obj.fixedPointValue = this->fixedPointValue++;
	return (obj);
}

Fixed	Fixed::operator--()
{
	Fixed	obj;

	obj.fixedPointValue = --this->fixedPointValue;
	return (obj);
}

Fixed	Fixed::operator--(int)
{
	Fixed	obj;

	obj.fixedPointValue = this->fixedPointValue--;
	return (obj);
}

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.getFixedPointValue() < fixed2.getFixedPointValue())
		return (fixed1);
	else
	 	return (fixed2);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.getFixedPointValue() > fixed2.getFixedPointValue())
		return (fixed1);
	else
	 	return (fixed2);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}