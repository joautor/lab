#ifndef utility_logger_h
#define utility_logger_h

#include <stdio.h>


#define ERR_HELPER(x, ...)       fprintf(stderr, "** [ERROR] ** %s::%s " x "\n", __FILE__, __func__, __VA_ARGS__)
#define LOG_ERR(...)             ERR_HELPER(__VA_ARGS__, "")

#define INFO_HELPER(x, ...)      fprintf(stdout, "[INFO] %s::%s " x "\n", __FILE__, __func__, __VA_ARGS__)
#define LOG_INFO(...)            INFO_HELPER(__VA_ARGS__, "")

#define WRN_HELPER(x, ...)       fprintf(stdout, "[WARNING] %s::%s " x "\n", __FILE__, __func__, __VA_ARGS__)
#define LOG_WRN(...)             WRN_HELPER(__VA_ARGS__, "")

#define DBG_HELPER(x, ...)       fprintf(stdout, "[DEBUG] %s::%s " x "\n", __FILE__, __func__, __VA_ARGS__)
#define LOG_DBG(...)             DBG_HELPER(__VA_ARGS__, "");


#endif // utility_logger_h

