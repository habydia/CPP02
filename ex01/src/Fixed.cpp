#include "Fixed.hpp"

// default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}
// copy constructor
Fixed::Fixed(const Fixed &other)
{
	this->fixedPointValue = other.fixedPointValue;
	std::cout << "Copy constructor called" << std::endl;
}

// const constructor for int convert int to fixed point
Fixed::Fixed(const int intValue)
{
	this->fixedPointValue = intValue << fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}
// const constructor for float convert float to fixed point
Fixed::Fixed(const float floatValue)
{
	this->fixedPointValue = roundf(floatValue * (1 << fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}
// COPY assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->fixedPointValue = other.fixedPointValue;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}
// destructor

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointValue / (1 << fractionalBits));
}
int Fixed::toInt(void) const
{
	return (this->fixedPointValue >> fractionalBits);
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}