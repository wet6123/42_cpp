#include "Fixed.hpp"

const int Fixed::fraction_bits = 8;

Fixed::Fixed(void)
: number(0)
{
}

Fixed::Fixed(const int number)
{
	this->number = number << this->fraction_bits;
}

Fixed::Fixed(const float number)
{
	this->number = roundf(number * (1 << this->fraction_bits));
}

Fixed::Fixed(const Fixed& obj)
{
	this->number = obj.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	if (this != &obj)
		this->number = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
}

int		Fixed::getRawBits(void) const
{
	return (this->number);
}

void	Fixed::setRawBits(int const raw)
{
	this->number = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << this->fraction_bits));
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->fraction_bits);
}

bool Fixed::operator>(const Fixed& fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	// fraction bit shift 발생
	// return ( Fixed(this->getRawBits() + obj.getRawBits()) );
	Fixed tmp(*this);
	tmp.setRawBits(this->getRawBits() + obj.getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed tmp(*this);
	tmp.setRawBits(this->getRawBits() - obj.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed tmp(*this);
	tmp.setRawBits((this->getRawBits() * obj.getRawBits()) >> this->fraction_bits);
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	Fixed tmp(*this);
	tmp.setRawBits((this->getRawBits() << this->fraction_bits) / obj.getRawBits());
	return (tmp);
}

Fixed&	Fixed::operator++(void)
{
	this->number++;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed result(*this);
	this->number++;
	return (result);
}

Fixed&	Fixed::operator--(void)
{
	this->number--;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed result(*this);
	this->number--;
	return (result);
}

Fixed&	Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1 <= obj2)
		return obj1;
	else
		return obj2;
}

const Fixed&	Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1 <= obj2)
		return obj1;
	else
		return obj2;
}

Fixed&	Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1 >= obj2)
		return obj1;
	else
		return obj2;
}

const Fixed&	Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1 >= obj2)
		return obj1;
	else
		return obj2;
}

std::ostream& operator<<(std::ostream& output_stream, const Fixed& fixed)
{
	output_stream << fixed.toFloat();
	return (output_stream);
}