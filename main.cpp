#include "lin.hpp"
#include "win.hpp"

int main()
{
    #ifdef DEBUG
    return Format();
    #else
        #ifdef LINUX
		return Format();
	#else
		#ifdef WINDOWS
			return FormatWindows();
		#endif
	#endif
#endif
}
