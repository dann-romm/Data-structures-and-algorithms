#ifndef DEBUG_HPP
# define DEBUG_HPP

// # define debug(name, value) log_variable<int>(name, value)
// # define debug(value) log_variable<int>(value)

template<typename T> void debug(const std::string& name="(something)", const T& value = nullptr)
{
	std::cout << name << " = [" << value << "]" << std::endl;
}

// template<typename T, typename U> void debug_iter(const std::string& name="(something)", T<U> object)
// {
// 	std::cout << name << std::endl;
// 	for (T<U>::iterator it = object.begin(); it != object.end(); it++)
// 		std::cout << *it;
// 	std::cout << std::endl;
// }

// #define DEBUG_VALUE_OF(variable) { _debugLog.value_of(#variable, variable, false); }

// class log
// {
// 	template<class T> void value_of(const std::string& name, 
// 				const T& value, const bool outputTypeInformation);
// 	};

// template<class T> void log::value_of(const std::string& name, 
// 			const T& value, const bool outputTypeInformation)
// {
// 	write_indentation();

// 	*stream << name;
// #ifdef DEBUG_LOG_ENABLE_TYPE_OUTPUT
// 	if (outputTypeInformation)
// 	{
// 		*stream << "(" << typeid(value).name() << ")";
// 	}
// #endif
// 	*stream << "=[" << value << "]" << std::endl;
// 	stream->flush();
// }


#endif // DEBUG_HPP
