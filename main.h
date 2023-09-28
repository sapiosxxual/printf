#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
int _putchar(char c);
int _printf(const char *format, ...);
int _print_str(char *str);
int _print_int(int n);
int _print_binary(unsigned int n);
int print_unsgnd(unsigned int n);
int print_octal(unsigned int n);
int print_hex(char format, unsigned int n);
int print_S(char *str);
int print_pointer(unsigned int n);
#endif
