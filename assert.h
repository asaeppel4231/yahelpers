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

    #define ASSERT(cond) \
        do{ \
            if(!(cond)){ \
                LOG_DEBUG("ASSERT " #cond " failed !!!"); \
            } \
        } \
        while(0) 

#else

    #define ASSERT(cond) /* Empty stub macro*/

#endif

#endif