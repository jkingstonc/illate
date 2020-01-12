//
// Created by james on 29/12/2019.
//

#ifndef ILLATE_IINT_H
#define ILLATE_IINT_H

#include "inum.h"

namespace items{
    class Iint : public Inum{
    public:
        Iint(int val);
        friend bool operator== (Iint & lhs, Iint & rhs ){
            return lhs.val == rhs.val;
        }
        std::string to_string_native();
        bool to_bool_native();
        std::uint8_t to_byte_native();
        int to_int_native();
        double to_double_native();

        std::shared_ptr<items::Ibool> to_bool();
        std::shared_ptr<items::Ibyte> to_byte();
        std::shared_ptr<Iint> to_int();
        std::shared_ptr<items::Idouble> to_double();

        std::shared_ptr<items::Item> neg();
        std::shared_ptr<items::Item> add(Item right);
        std::shared_ptr<items::Item> add(int right);
        std::shared_ptr<items::Item> add(double right);
        std::shared_ptr<items::Item> sub(Item right);
        std::shared_ptr<items::Item> sub(int right);
        std::shared_ptr<items::Item> sub(double right);
        std::shared_ptr<items::Item> mul(Item right);
        std::shared_ptr<items::Item> mul(int right);
        std::shared_ptr<items::Item> mul(double right);
        std::shared_ptr<items::Item> div(Item right);
        std::shared_ptr<items::Item> div(int right);
        std::shared_ptr<items::Item> div(double right);
        std::shared_ptr<items::Item> mod(Item right);
        std::shared_ptr<items::Item> mod(int right);
        std::shared_ptr<items::Item> mod(double right);
        std::shared_ptr<items::Item> rem(Item right);
        std::shared_ptr<items::Item> rem(int right);
        std::shared_ptr<items::Item> rem(double right);

        static std::shared_ptr<Iint> to_item(int val){
            return std::make_shared<Iint>(val);
        }
        const int val;
    };
};

#endif //ILLATE_IINT_H
