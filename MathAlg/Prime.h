#pragma once

#include <bitset>

#include "FactorArray.h"
#include "VectorArray.h"

// A - подсчет число делителей
bool primeA( size_t n )
{
    size_t c = 0;
    for( size_t i = 1; i <= n; ++i )
    {
        if( n % i == 0 )
            c++;
    }

    return c == 2;
}

size_t countPrimeA( size_t n )
{
    size_t c = 0;
    for( size_t i = 2; i <= n; ++i )
        if( primeA( i ) )
            ++c;
    return c;
}

// B - оптимизация А
bool primeB( size_t n )
{
    if( n % 2 == 0 )
        return false;

    size_t c = 0;
    for( size_t i = 3; i * i <= n; i += 2 )
    {
        if( n % i == 0 )
            return false;
    }

    return true;
}

FactorArray<size_t> gprimes;
// B2 - оптимизация с использованием массива предыдущих простых чисел
bool primeB2( size_t n )
{
    if( n % 2 == 0 )
        return false;

    for( size_t i = 0; i < gprimes.size(); ++i )
    {
        if( n % gprimes.get(i) == 0 )
            return false;
    }

    return true;
}

size_t countPrimeB( size_t n )
{
    size_t c = 1;
    gprimes.clear();
    gprimes.add( 2 );
    for( size_t i = 3; i <= n; ++i )
    {
        if( primeB2( i ) )
        {
            gprimes.add( i );
            ++c;
        }
    }
    return c;
}

// С - решето Эратосфена
void updatePrimes( VectorArray<bool>& primes, size_t n )
{
    primes.clear();
    for( size_t i = 0; i <= n; ++i )
        primes.add( true );
    
    primes.get( 0 ) = false;
    primes.get( 1 ) = false;

    for( size_t i = 2; i <= n; ++i )
    {
        if( primes.get(i) == true )
            for( size_t k = i * i; k <= n; k += i )
                primes.get(k) = false;
    }
}

size_t countPrimeC( size_t n )
{
    VectorArray<bool> primes( n + 1 );
    updatePrimes( primes, n );
    size_t c = 0;
    int i = 0;
    for( size_t i = 0; i < primes.size(); ++i )
    {
        if( primes.get(i) == true )
        {
            ++c;
        }
    }
    return c;
}

// D - решето Эратосфена
void updatePrimes( VectorArray< std::bitset<32> >& primes, size_t n )
{
    primes.clear();
    for( size_t i = 0; i <= n; ++i )
        primes.add( std::bitset<32>( 0xFFFFFFFF ) );

    primes.get( 0 )[0] = false;
    primes.get( 0 )[1] = false;

    for( size_t i = 2; i <= n; ++i )
    {
        size_t index1 = i / 32;
        size_t index2 = i % 32;
        if( primes.get( index1 )[index2] == true )
            for( size_t k = i * i; k <= n; k += i )
            {
                size_t kindex1 = k / 32;
                size_t kindex2 = k % 32;
                primes.get( kindex1 )[kindex2] = false;
            }
    }
}

size_t countPrimeD( size_t n )
{
    VectorArray< std::bitset<32> > primes( n / 32 + ( ( n % 32 > 0 ) ? 1 : 0 ) );
    updatePrimes( primes, n );
    size_t c = 0;
    int i = 0;
    for( size_t i = 0; i < n; ++i )
    {
        size_t index1 = i / 32;
        size_t index2 = i % 32;
        if( primes.get( index1 )[index2] == true )
        {
            ++c;
        }
    }
    return c;
}