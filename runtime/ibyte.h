//
// Created by james on 04/01/2020.
//

#ifndef ILLATE_IBYTE_H
#define ILLATE_IBYTE_H

namespace items {
    class Ibyte {
        friend bool operator== (Ibyte & lhs, Ibyte & rhs ){
            return lhs.val == rhs.val;
        }
        const uint8_t val;
    };
};

#endif //ILLATE_IBYTE_H