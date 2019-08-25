#pragma once

#include <bitset>

// Итеративный
template< class T >
T FastPowA( T a, size_t n )
{
    T res = 1;
    for( size_t i = 0; i < n; ++i )
        res *= a;
    return res;
}

// Через степень двойки с домножением
template< class T >
T FastPowB( T a, size_t n )
{
    if( n == 0 )
        return 1;
    T res = a;
    size_t j = 1;
    for( ;j * 2 <= n; j *= 2 )
    {
        res *= res;
    }
    for( ; j < n; ++j )
        res *= a;

    return res;
}

// Через воичное разложение показателя степени
template< class T >
T FastPowC( T a, size_t n )
{
    T p = T(1);
    while( n > 1 )
    {
        if( n % 2 == 1 )
            p *= a;
        a *= a;
        n /= 2;
    }
    if( n > 0 )
        p *= a;

    return p;
}

// Чтение битов числа
template< class T >
T FastPowC2( T a, size_t n )
{
    T p = T(1);
    std::bitset<sizeof( size_t ) * 8> bits( n );
    size_t n1 = 0;
    while( n > 1 )
    {
        if( bits[n1++] )
            p *= a;
        a *= a;
        n /= 2;
    }
    if( bits[n1] )
        p *= a;

    return p;
}
