#include "iter.hpp"
#include <iostream>

int print(int &value)
{
    std::cout << value << std::endl;
    return value;
}

// void print(std::string &value)
// {
//     std::cout << value << std::endl;
// }

// int main()
// {
//     int int_arr[] = {1, 2, 3, 4, 5};
//     std::string str_arr[] = {"Hello", "42", "World", "!!"};

//     ::iter(int_arr, (sizeof(int_arr)/sizeof(int)), print);
//     ::iter(str_arr, (sizeof(str_arr)/sizeof(std::string)), print);
// }

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void qprint( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print );
  iter( tab2, 5, qprint<Awesome> );

  return 0;
}