
template<typename T>
	T max(T x, T y)
	{
		return (x > y) ? x : y;
	}

template<typename T, int size>
	T array_sum(T (&ptr_arr)[size])
	{
		T result = 0;

		for(int i = 0; i < size; ++i)
		{
			result += ptr_arr[i];
		}

		return result;
	}

template<typename T, int size>
	T max(T (&ptr_add)[size])
	{
		T result {};

		if(size > 0)
		{
			for(int i = 0; i < size; ++i)
			{
				if(ptr_add[i] > result)
				{
					result = ptr_add[i];
				}
			}
		}

		return result;

	}

template<typename T, int size>
	std::pair<T,T> min_max(T (&ptr_arr)[size])
	{
		std::pair<T, T> result {};

		if(size > 0)
		{
			result.first = ptr_arr[0];
			result.second = ptr_arr[0];

			for(int i = 0; i < size; ++i)
			{
				if(ptr_arr[i] < result.first)
				{
					result.first = ptr_arr[i];
				}
				if(ptr_arr[i] > result.second)
				{
					result.second = ptr_arr[i];
				}
				
			}
		}

		return result;
	}

template<int size> char const * max(char const * (&ptr_arr)[size])
{
	char const * result = "";


	for(int i = 0; i < size; ++i)
	{
		if(strcmp(ptr_arr[i], result) > 0)
		{
			result = ptr_arr[i];
		}
	}

	return result;
}
