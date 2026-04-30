/** @file assert.h
 *  @author asaeppel4231
 *  @copyright (c) 2026 asaeppel4231
 *  @version 0.1
 *  @brief Assertion utilities for the ya ecosystem
 *
 * This header provides lightweight assertion helpers used throughout the ya ecosystem.
 * Assertions help detect incorrect assumptions and unexpected states during runtime.
 *
 * When NDEBUG is defined, all assertions are disabled.
 */
#ifndef ASSERT_H
#define ASSERT_H

#include "log.h"

#ifndef NDEBUG

/** @brief Print timestamp of the assert and abort on error */
#define ASSERT_DEFAULT 0

/** @brief Specifies whether the assert will abort on error */
#define ASSERT_NO_ABORT 1

/** @brief Specifies whether the assert will print a timestamp on error */
#define ASSERT_NO_TIMESTAMP 2

#include <stdlib.h> /* for abort() */
#include <time.h>

/** @brief Prints a debug message if the condition cond is failed
 *  @param cond The condition which is checked
 *  @param opts The option flags
 *  @see ASSERT_DEFAULT
 *  @see ASSERT_NO_ABORT
 *  @see ASSERT_NO_TIMESTAMP
 */
#define ASSERT(cond, opts)                                      \
    do {                                                        \
        if (!(cond)) {                                          \
            if((opts) & ASSERT_NO_TIMESTAMP){                   \
                LOG_DEBUG("ASSERT " #cond " failed !!!");       \
            }                                                   \
            else{                                               \
                time_t assert_time = time(NULL);                \
                LOG_DEBUG("[% ld ] ASSERT " #cond " failed !!!"); \
            }                                                   \
            if(!((opts) & ASSERT_NO_ABORT)){                    \
                abort();                                        \
            }                                                   \
        }                                                       \
    } while (0)

#else

#define ASSERT_DEFAULT 0
#define ASSERT_NO_ABORT 0
#define ASSERT_NO_TIMESTAMP 0

#define ASSERT(cond, opts) /* Empty stub macro*/

#endif

#endif