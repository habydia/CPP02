#include "Fixed.hpp"

// default constructor
Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
// int constructor
Fixed::Fixed(int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = intValue << fractionalBits;
}

// float constructor
Fixed::Fixed(float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(floatValue * (1 << fractionalBits));
}

// copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointValue = other.getRawBits();
}
// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// getter
int Fixed::getRawBits(void) const
{
	return (this->fixedPointValue);
}
// setter
void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->fixedPointValue = other.getRawBits();
	}
	return (*this);
}
bool Fixed::operator>(const Fixed &other) const
{
	if (this->fixedPointValue > other.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator<(const Fixed &other) const
{
	if (this->fixedPointValue < other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (this->fixedPointValue >= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->fixedPointValue <= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->fixedPointValue == other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->fixedPointValue != other.getRawBits())
		return (true);
	return (false);
}

// arithmetic overloads
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->fixedPointValue + other.fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->fixedPointValue - other.fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long long temp = (long long)this->fixedPointValue * other.fixedPointValue;
	result.setRawBits((int)(temp >> fractionalBits));
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	long long temp = (long long)this->fixedPointValue << fractionalBits;
	result.setRawBits((int)(temp / other.fixedPointValue));
	return result;
}

// increment / decrement overloads for fixed point values
Fixed &Fixed::operator++()
{
	this->fixedPointValue++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	this->fixedPointValue++;
	return (temp);
}
Fixed &Fixed::operator--()
{
	this->fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	this->fixedPointValue--;
	return (temp);
}

// member funtions for min / max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointValue / (1 << fractionalBits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
