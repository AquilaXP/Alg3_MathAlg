#pragma once

#include <vector>
#include <bitset>
#include <cstdint>

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

std::vector<size_t> gprimes;
bool primeB2( size_t n )
{
    if( n % 2 == 0 )
        return false;

    for( auto& p : gprimes )
    {
        if( n % p == 0 )
            return false;
    }

    return true;
}


size_t countPrimeB( size_t n )
{
    size_t c = 1;
    gprimes.clear();
    gprimes.push_back( 2 );
    for( size_t i = 3; i <= n; ++i )
    {
        if( primeB2( i ) )
        {
            gprimes.push_back( i );
            ++c;
        }
    }
    return c;
}

// С - решето Эратосфена
void updatePrimes( std::vector<bool>& primes, size_t n )
{
    if( primes.size() < n )
        primes.resize( n + 1 );
    std::fill( std::begin( primes ), std::end( primes ), true );

    primes[0] = false;
    primes[1] = false;

    for( size_t i = 2; i <= n; ++i )
    {
        if( primes[i] == true )
            for( size_t k = i * i; k <= n; k += i )
                primes[k] = false;
    }
}

size_t countPrimeС( size_t n )
{
    std::vector<bool> primes;
    updatePrimes( primes, n );
    size_t c = 0;
    int i = 0;
    for( auto& p : primes )
    {
        if( p == true )
        {
            ++c;
        }
        ++i;
    }
    return c;
}
