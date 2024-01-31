#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int print_char(va_list args);
int print_str(va_list args);
int print_percent(void);
int print_int(va_list args);
int _printf(const char *format, ...);

#endif /* MAIN_H */

