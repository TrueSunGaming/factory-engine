#ifdef __WIN32__

#ifdef BUILD_LIB
#define LIB_API __declspec(dllexport)
#else
#define LIB_API __declspec(dllimport)
#endif

#define LIB_CALL __cdecl

#else
#define LIB_API
#define LIB_CALL

#endif