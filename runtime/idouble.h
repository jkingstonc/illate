//
// Created by james on 29/12/2019.
//

#ifndef ILLATE_IDOUBLE_H
#define ILLATE_IDOUBLE_H

#include "inum.h"

class Idouble : public Inum{
public:
    Idouble(double val);
    std::string to_string_native();

    static std::shared_ptr<Idouble> to_item(double val){
        return std::make_shared<Idouble>(val);
    }
private:
    const double val;
};

#endif //ILLATE_IDOUBLE_H
