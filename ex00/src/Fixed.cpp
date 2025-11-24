#include "Fixed.hpp"

// default constructor
Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
// copy constructor
Fixed::Fixed(const Fixed &other)
{
	this->fixedPointValue = other.fixedPointValue;
	std::cout << "Copy constructor called" << std::endl;
}

// destructor
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

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->fixedPointValue = other.getRawBits();
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}
