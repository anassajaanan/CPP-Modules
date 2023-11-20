


#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					fixedPointValue;
	static const	int	fractionalBits = 8;
public:

	Fixed();
	Fixed(const int intNumber);
	Fixed(const float floatNumber);
	Fixed(const Fixed &fixed);
	~Fixed();

	float	toFloat(void) const;
	int		toInt(void) const;

	Fixed			&operator=(const Fixed	&fixed);
};

std::ostream&	operator<<(std::ostream& os, const Fixed &fixed);


#endif /* FIXED_HPP */