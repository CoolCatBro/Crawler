#pragma  once

//MACROS


//S_ISDIR  (for windows)
#ifndef S_ISDIR
#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#endif

//S_IWUSR (for windows)
#ifndef S_IWUSR
#define S_IWUSR S_IWRITE
#endif

//S_ISWR
#ifndef S_ISWR
#define S_ISWR(mode) (((mode) & S_IWUSR) == S_IWUSR)
#endif 

//VARIABLES

#include <string>
using std::string;

extern  string SEED_URL;
extern int MAX_DEPTH;