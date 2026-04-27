/** @file log.h
 *  @author asaeppel4231
 *  @copyright (c) 2026 asaeppel4231
 *  @version 0.1
 *  @brief Logging utilities for the ya ecosystem
 *
 * This file provides enhanced logging capabilities to support debugging,
 * troubleshooting and the detection of race conditions within the ya ecosystem.
 * It offers lightweight, dependency‑free macros that help track function calls,
 * parameters and return values during development.
 */
#ifndef HELPERS_H
#define HELPERS_H

#define GENERAL_DEBUG 1

#ifdef NDEBUG

#undef GENERAL_DEBUG
#define GENERAL_DEBUG 0

#endif

#if GENERAL_DEBUG == 1

// NOTE: Requires C99
#include <stdarg.h>
#include <stdio.h>

#include "logconstants.h"

/** @brief Takes a parameter and convert it to a string
 */
#define STRINGIFY(x) #x

#define TOSTRING(x) STRINGIFY(x)

/** @defgroup macros_logging Logging macros
 *  @brief Macros for debugging and tracing.
 *  @{
 */

/** @brief Prints a debug message.
 * @param formatted_string The string which specifies what is outputted
 */
#define LOG_DEBUG(formatted_string, ...)                                                    \
    do {                                                                                    \
        printf("\e[0;32m" DEBUG "( " __FILE__ ": " TOSTRING(__LINE__) " )"                  \
                                                                      "\e[0m"               \
                                                                      " " formatted_string, \
               ##__VA_ARGS__);                                                              \
    } while (0)

/** @brief Prints a function call.
 * @param fn_name The name of the function that was called.
 */
#define LOG_FUNCTION_CALL(fn_name) LOG_DEBUG(#fn_name " was called.\n");

/** @brief Prints a return to a function.
 * @param fn_name The name of the function were the program is now.
 */
#define LOG_FUNCTION_BACK(fn_name) LOG_DEBUG("Back in " #fn_name "\n");

/** @brief Specifies that the given parameter is a pointer
 * @see LOG_PARAMETER
 */
#define TYPE_CALL_ADDRESS 0

/** @brief Specifies that the given parameter is a value
 * @see LOG_PARAMETER
 */
#define TYPE_CALL_VALUE 1

/** @brief Alias for ::TYPE_CALL_ADDRESS
 */
#define TCA TYPE_CALL_ADDRESS

/** @brief Alias for ::TYPE_CALL_VALUE
 */
#define TCV TYPE_CALL_VALUE

/** @brief Prints a parameter of a function
 * @param ordinal_number The number of the parameter (e.g. 1st, 2nd, ...)
 * @param type The type of the parameter (e.g. int, char, double, ...)
 * @param type_call Specifies whether the parameter is a pointer or a value
 * @param fmt Makes additional information possible
 * @see TCA
 * @see TCV
 * @see TYPE_CALL_ADDRESS
 * @see TYPE_CALL_VALUE
 */
#define LOG_PARAMETER(ordinal_number, type, type_call, fmt, ...)           \
    LOG_DEBUG(#ordinal_number " parameter (type: " #type ") with %s " fmt, \
              (type_call == TYPE_CALL_ADDRESS ? "address" : "value"), ##__VA_ARGS__)

/** @brief Prints the value or address that a function will return
 * @param type The type of the return value (e.g. int, char, double, ...)
 * @param type_call Specifies whether the return value is a pointer or a value
 * @param fmt Makes additional information possible
 * @see TCA
 * @see TCV
 * @see TYPE_CALL_ADDRESS
 * @see TYPE_CALL_VALUE
 */
#define LOG_RETURN(type, type_call, fmt, ...)                                                                \
    LOG_DEBUG("Returning (type: " #type ") %s " fmt, (type_call == TYPE_CALL_ADDRESS ? "address" : "value"), \
              ##__VA_ARGS__)

/** @}
 */

#else

#define LOG_DEBUG(formated_string, ...)                              /* Empty stub macro*/
#define LOG_FUNCTION_CALL(fn_name)                                   /* Empty stub macro*/
#define LOG_FUNCTION_BACK(fn_name)                                   /* Empty stub macro*/
#define LOG_PARAMETER(ordinal_number, type_str, type_call, fmt, ...) /* Empty stub macro*/
#define LOG_RETURN(type_str, type_call, fmt, ...)                    /* Empty stub macro*/

#define TCA 0
#define TCV 0

#define TYPE_CALL_ADDRESS 0
#define TYPE_CALL_VALUE 0

#endif

#endif