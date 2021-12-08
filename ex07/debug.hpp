#ifndef DEBUG_HPP
# define DEBUG_HPP

#include <stdio.h>

#ifndef DEBUG_ENABLED
#define DEBUG_ENABLED true
#endif

#if DEBUG_ENABLED

#define DEBUG(x) {\
	std::cout << __FILE__ << " " << __FUNCTION__ << " (line " << __LINE__ << "):\t" << #x << " = " << x << std::endl;\
}

#else
#define DEBUG(x)
#endif


#endif // DEBUG_HPP
