#ifndef STRING_EXPORT_H
#define STRING_EXPORT_H


#ifdef WIN
#ifdef STRING_EXPORTS
#define STRING_EXPORT __declspec(dllexport)
#else
#define STRING_EXPORT __declspec(dllimport)
#endif
#ifdef __INTELLISENSE__
#define __VA_OPT__(X)
#endif
#else
#define STRING_EXPORT __attribute__((visibility("default")))
#endif
#endif