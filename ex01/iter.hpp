#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>


/*
1st param -> address of an array
2nd param -> the length of the array (passed as const value)
3rd param -> function
*/

/*
fの引数が、以下のどちらの場合でもありえる：
void function(T const& value);
void function(T& value);
*/
template <typename T, typename F>
void iter(T *array, int size, F f)
{
	for (int i = 0 ; i < size; i++)
		f(array[i]);
}

#endif
