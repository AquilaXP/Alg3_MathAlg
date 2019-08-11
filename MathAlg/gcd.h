#pragma once

#include <utility>

size_t gcd_A( size_t a, size_t b )
{
    if( a == 0 )
        return b;
    if( b == 0 )
        return a;

    while( a != b )
        if( a > b )
            a = a - b;
        else
            b = b - a;
    return b;
}

size_t gcd_B( size_t a, size_t b )
{
    if( a == 0 )
        return b;
    if( b == 0 )
        return a;

    while( b )
    {
        a %= b;
        std::swap( a, b );
    }

    return a;
}

size_t gcd_BR( size_t a, size_t b )
{
    if( b == 0 )
        return a;
    return gcd_BR( b, a % b );
}

size_t gcd_C( size_t a, size_t b )
{
    size_t shift = 0;
    if( a == 0 )
        return b;
    if( b == 0 )
        return a;

    for( shift = 0; ( ( a | b ) & 1 ) == 0; ++shift )
    {
        a >>= 1;
        b >>= 1;
    }
    while( ( a & 1 ) == 0 )
    {
        a >>= 1;
        do
        {
            while( ( b & 1 ) == 0 )
                b >>= 1;

            if( a > b )
            {
                std::swap( a, b );
            }
            b = b - a;
        } while( b != 0 );
    }

    return a << shift;
}