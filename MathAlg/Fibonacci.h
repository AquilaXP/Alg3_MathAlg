#pragma once

#include <cmath>

#include "FastPow.h"

// рекурсивно
size_t fibA( size_t n )
{
    if( n == 0 )
        return 0;
    if( n == 1 )
        return 1;

    return fibA( n - 1 ) + fibA( n - 2 );
}

// итерационно
size_t fibB( size_t n )
{
    if( n == 0 )
        return 0;

    size_t Fn_2 = 0;
    size_t Fn_1 = 1;
    size_t Fn = 1;

    for( size_t i = 2; i < n; ++i )
    {
        Fn_2 = Fn_1;
        Fn_1 = Fn;
        Fn = Fn_2 + Fn_1;
    }

    return Fn;
}

// по формуле золотого сечения
size_t fibC( size_t n )
{
    const double fi = ( 1.0 + std::sqrt( 5.0 ) ) / 2.0;
    
    return size_t(std::floor( std::pow( fi, n ) / std::sqrt( 5.0 ) + 0.5 ));
}

/*
 |00 01|
 |10 11|
*/
struct uMat2x2
{
    uMat2x2( size_t a = 1 )
    {
        v[0][0] = a;
        v[0][1] = 0;
        v[1][0] = 0;
        v[1][1] = a;
    }

    uMat2x2 operator *=( const uMat2x2& rhs )
    {
        size_t new_v[2][2] = { 0,0,0,0 };
        for( size_t i = 0; i < 2; ++i )
        {
            for( size_t j = 0; j < 2; ++j )
            {
                for( size_t k = 0; k < 2; ++k )
                    new_v[i][j] += v[i][k] * rhs.v[k][j];
            }
        }
        memcpy( v, new_v, sizeof new_v );
        return *this;
    }

    size_t v[2][2];
};

// через умножение матриц
size_t fibD( size_t n )
{
    if( n == 0 )
        return 0;
    if( n == 1 )
        return 1;
    uMat2x2 m;
    m.v[0][0] = 1;
    m.v[0][1] = 1;
    m.v[1][0] = 1;
    m.v[1][1] = 0;

    m = FastPowC( m, n - 1 );

    return m.v[0][0];
}
