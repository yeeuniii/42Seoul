#ifndef __ITER_HPP__
#define __ITER_HPP__

template <typename arrayType, typename functionType>
void iter(arrayType* arrayAddress, unsigned int size, functionType function)
{
	arrayType	array = *arrayAddress;

	for (unsigned int idx = 0; idx < size; idx++)
		function(array[idx]);
}

#endif
