#ifndef __ITER_HPP__
#define __ITER_HPP__

template <typename arrayType, typename functionType>
void iter(arrayType array, unsigned int size, functionType function)
{
	for (unsigned int idx = 0; idx < size; idx++)
		function(array[idx]);
}

#endif
