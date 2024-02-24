#ifdef __WIN32__

#ifdef BUILD_LIB
#define DLL_EXPORT __declspec(dllexport)
#else   
#define DLL_EXPORT __declspec(dllimport)
#endif

#else

#define DLL_EXPORT

#endif