//
// Created by james-laptop on 05/01/2020.
//

#ifndef ILLATE_DEBUG_H
#define ILLATE_DEBUG_H

#include <iostream>

// By default debugging is enabled
#ifndef R_DEBUG_ENABLED
    #define R_DEBUG_ENABLED
#endif


#define R_DEBUG(...) {std::cout << "Runtime Debug: " << __VA_ARGS__ << std::endl;}

#define R_ERROR(...) {std::cout << "Runtime Error: " << __VA_ARGS__ << std::endl;}

// Used when during runtime we encounter a critical issue, if the assertion fails then the vm will break
#define R_ASSERT(err, ...) { if(!err) { R_ERROR("Assertion Failed: " << __VA_ARGS__); }}

#endif //ILLATE_DEBUG_H
