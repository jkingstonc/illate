//
// Created by james on 29/12/2019.
//

#ifndef ILLATE_IDOUBLE_H
#define ILLATE_IDOUBLE_H

#include "inum.h"

namespace items{
    class Idouble : public Inum{
    public:
        Idouble(double val);
        friend bool operator== (Idouble & lhs, Idouble & rhs ){
            return lhs.val == rhs.val;
        }
        std::string to_string_native();
        bool to_bool_native();
        std::uint8_t to_byte_native();
        int to_int_native();
        double to_double_native();

        static std::shared_ptr<Idouble> to_item(double val){
            return std::make_shared<Idouble>(val);
        }
        const double val;
    };
};

#endif //ILLATE_IDOUBLE_H
