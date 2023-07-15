#include "logger.h"
#include "utstring.h"

void ut_strcpy(char* s, char* t)
{
    LOG_DBG("");
    while((*t++ = *s++) != '\0');
}

void ut_strncpy(char* s, char* t, size_t n)
{
    //LOG_WRN("Not yet implemented!");
    LOG_DBG();
    for(size_t i = 0; i < n; ++i) {
        t[i] = s[i];
    }
}
