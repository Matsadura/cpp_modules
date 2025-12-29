#include "Fixed.hpp"

int main( void )
{
    std::cout << "--- SUBJECT TESTS ---" << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << std::endl;


    std::cout << "--- ARITHMETIC TESTS ---" << std::endl;
    Fixed c(10);
    Fixed d(20);

    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "c + d = " << (c + d) << std::endl;
    std::cout << "d - c = " << (d - c) << std::endl;
    std::cout << "c * d = " << (c * d) << std::endl;
    std::cout << "d / c = " << (d / c) << std::endl;
    std::cout << std::endl;

    Fixed h(10.5f);
    Fixed i(20);

    std::cout << "\nh = " << h << ", i = " << i << std::endl;
    std::cout << "h + i = " << (h + i) << std::endl;
    std::cout << "i - h = " << (i - h) << std::endl;
    std::cout << "h * i = " << (h * i) << std::endl;
    std::cout << "i / h = " << (i / h) << std::endl;
    std::cout << std::endl;


    std::cout << "--- COMPARISON TESTS ---" << std::endl;
    std::cout << std::boolalpha;

    std::cout << "c < d:  " << (c < d) << std::endl;
    std::cout << "c > d:  " << (c > d) << std::endl;
    std::cout << "c <= c: " << (c <= c) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;
    std::cout << "c == c: " << (c == c) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;
    std::cout << std::endl;


    std::cout << "--- DECREMENT TESTS ---" << std::endl;
    Fixed e(1);

    std::cout << "Original e: " << e << std::endl;
    std::cout << "Pre-decrement (--e): " << --e << std::endl;
    std::cout << "Current e: " << e << std::endl;
    std::cout << "Post-decrement (e--): " << e-- << std::endl;
    std::cout << "Final e: " << e << std::endl;
    std::cout << std::endl;


    std::cout << "--- MIN/MAX TESTS ---" << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
    std::cout << "Max(c, d): " << Fixed::max(c, d) << std::endl;
    std::cout << "Min(c, d): " << Fixed::min(c, d) << std::endl;

    Fixed const f(42);
    Fixed const g(24);
	std::cout << "\nf: " << f << ", g: " << g << std::endl;
    std::cout << "Const Max(f, g): " << Fixed::max(f, g) << std::endl;
    std::cout << "Const Min(f, g): " << Fixed::min(f, g) << std::endl;

    return 0;
}