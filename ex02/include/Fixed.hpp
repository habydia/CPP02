#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# include <ostream>
# include <string>

class Fixed
{
  private:
	int fixedPointValue;
	static const int fractionalBits = 8;

  public:
	// constructors
	Fixed();
	Fixed(float floatValue);
	Fixed(const Fixed &other);
	Fixed(int intValue);
	// destructor
	~Fixed();

	// getter and setter
	int getRawBits(void) const;
	void setRawBits(int const raw);

	// comparators overload
	Fixed &operator=(const Fixed &other);
	bool operator>(const Fixed &other);
	bool operator<(const Fixed &other);
	bool operator>=(const Fixed &other);
	bool operator<=(const Fixed &other);
	bool operator==(const Fixed &other);
	bool operator!=(const Fixed &other);

	// // arithmetic overloads
	Fixed &operator+(const Fixed &other);
	Fixed &operator-(const Fixed &other);
	Fixed &operator*(const Fixed &other);
	Fixed &operator/(const Fixed &other);
	// // increment / decrement overloads for fixed point values
	Fixed &operator++();   // prefix
	Fixed operator++(int); // postfix
	Fixed &operator--();   // prefix
	Fixed operator--(int); // postfix

	// member funtions for min / max
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	// toFloat
	float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP