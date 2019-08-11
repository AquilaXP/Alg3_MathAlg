#define BOOST_TEST_MODULE test_mathalg

#include <boost/test/included/unit_test.hpp>

#include "gcd.h"
#include "FastPow.h"
#include "Fibonacci.h"
#include "Prime.h"

template< class Func >
void testEuclideanAlg( Func ef )
{
    /// num1, num2 и результат
    static const std::vector< std::tuple< size_t, size_t, size_t > > cases =
    {
        { 1, 1, 1 },
        { 0, 0, 0 },
        { 100, 10, 10 },
        { 10, 100, 10 },
        { 600, 45, 15 },
        { 45, 600, 15 },
        { 31, 7, 1 }
    };

    for( auto& c : cases )
    {
        BOOST_CHECK_BITWISE_EQUAL( ef( std::get<0>( c ), std::get<1>( c ) ), std::get<2>( c ) );
    }
}


BOOST_AUTO_TEST_SUITE( test_EuclideanAlg )

BOOST_AUTO_TEST_CASE( test_EuclideanAlgA )
{
    testEuclideanAlg( gcd_A );
}
BOOST_AUTO_TEST_CASE( test_EuclideanAlgB )
{
    testEuclideanAlg( gcd_B );
}

BOOST_AUTO_TEST_CASE( test_EuclideanAlgBR )
{
    testEuclideanAlg( gcd_BR );
}

BOOST_AUTO_TEST_CASE( test_EuclideanAlgC )
{
    //testEuclideanAlg( gcd_C );
}

BOOST_AUTO_TEST_SUITE_END()


template< class Func >
void testFastPow( Func fastPow )
{
    /// num1, num2 и результат
    static const std::vector< std::tuple< size_t, size_t, size_t > > cases =
    {
        { 1, 1, 1 },
        { 0, 0, 1 },
        { 2, 10, 1024 },
        { 2, 3, 8 }
    };

    for( auto& c : cases )
    {
        BOOST_CHECK_EQUAL( fastPow( std::get<0>( c ), std::get<1>( c ) ), std::get<2>( c ) );
    }
}

BOOST_AUTO_TEST_SUITE( test_FastPow )

BOOST_AUTO_TEST_CASE( test_FastPowA )
{
    testFastPow( FastPowA<size_t> );
}
BOOST_AUTO_TEST_CASE( test_FastPowB )
{
    testFastPow( FastPowB<size_t> );
}

BOOST_AUTO_TEST_CASE( test_FastPowC )
{
    testFastPow( FastPowC<size_t> );
}

BOOST_AUTO_TEST_CASE( test_FastPowC2 )
{
    testFastPow( FastPowC2<size_t> );
}

BOOST_AUTO_TEST_SUITE_END()

template< class Func >
void testPrime( Func countPrime )
{
    /// num1, num2 и результат
    static const std::vector< size_t > primes1000 =
    {
        2   ,3   ,5   ,7   ,11  ,13  ,17  ,19  ,23  ,29  ,31  ,37 ,
        41  ,43  ,47  ,53  ,59  ,61  ,67  ,71  ,73  ,79  ,83  ,89 ,
        97  ,101 ,103 ,107 ,109 ,113 ,127 ,131 ,137 ,139 ,149 ,151,
        157 ,163 ,167 ,173 ,179 ,181 ,191 ,193 ,197 ,199 ,211 ,223,
        227 ,229 ,233 ,239 ,241 ,251 ,257 ,263 ,269 ,271 ,277 ,281,
        283 ,293 ,307 ,311 ,313 ,317 ,331 ,337 ,347 ,349 ,353 ,359,
        367 ,373 ,379 ,383 ,389 ,397 ,401 ,409 ,419 ,421 ,431 ,433,
        439 ,443 ,449 ,457 ,461 ,463 ,467 ,479 ,487 ,491 ,499 ,503,
        509 ,521 ,523 ,541 ,547 ,557 ,563 ,569 ,571 ,577 ,587 ,593,
        599 ,601 ,607 ,613 ,617 ,619 ,631 ,641 ,643 ,647 ,653 ,659,
        661 ,673 ,677 ,683 ,691 ,701 ,709 ,719 ,727 ,733 ,739 ,743,
        751 ,757 ,761 ,769 ,773 ,787 ,797 ,809 ,811 ,821 ,823 ,827,
        829 ,839 ,853 ,857 ,859 ,863 ,877 ,881 ,883 ,887 ,907 ,911,
        919 ,929 ,937 ,941 ,947 ,953 ,967 ,971 ,977 ,983 ,991 ,997
    };

    BOOST_CHECK_EQUAL( countPrime( 1000 ), primes1000.size() );
}

BOOST_AUTO_TEST_SUITE( test_testPrime )

BOOST_AUTO_TEST_CASE( test_testPrimeA )
{
    testPrime( countPrimeA );
}
BOOST_AUTO_TEST_CASE( test_testPrimeB )
{
    testPrime( countPrimeB );
}
BOOST_AUTO_TEST_CASE( test_testPrimeC )
{
    testPrime( countPrimeС );
}

BOOST_AUTO_TEST_SUITE_END()



template< class Func >
void testFibonacci( Func fibonacci )
{
    /// num1, num2 и результат
    static const std::vector< size_t > fibonaccies =
    {
        0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,
        1597,2584,4181,6765,10946,17711,28657,46368,75025,
        121393,196418,317811,514229,832040,1346269,2178309,
        3524578,5702887,9227465,14930352,24157817,39088169,
        63245986,102334155/*,165580141,267914296,433494437,701408733,
        1134903170,1836311903,2971215073*/
    };

    for( size_t i = 3; i < fibonaccies.size(); ++i )
        BOOST_CHECK_EQUAL( fibonacci( i ), fibonaccies[i] );
}

BOOST_AUTO_TEST_SUITE( test_testFib )

BOOST_AUTO_TEST_CASE( test_testFibA )
{
    testFibonacci( fibA );
}
BOOST_AUTO_TEST_CASE( test_testFibB )
{
    testFibonacci( fibB );
}
BOOST_AUTO_TEST_CASE( test_testFibC )
{
    testFibonacci( fibC );
}

BOOST_AUTO_TEST_CASE( test_testFibD )
{
    testFibonacci( fibD );
}

BOOST_AUTO_TEST_SUITE_END()
