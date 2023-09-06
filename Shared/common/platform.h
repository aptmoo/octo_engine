/**
 * @file platform.h
 * @brief Platform detection and some minor platform-dependent functionality.
 * @version 0.1
 * @date 2023-08-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef __linux__    
#define PLATFORM_LINUX
#define PLATFORM_NAME "linux"

#elif _WIN32
#define PLATFORM_WIN32
#define PLATFORM_NAME "windows x86"
#error "Windows is not yet supported"

#elif _WIN64
#define PLATFORM_WIN64
#undef PLATFORM_NAME
#define PLATFORM_NAME "windows x86-64"
#error "Windows is not yet supported"

#endif /* #ifndef __linux__*/

#endif