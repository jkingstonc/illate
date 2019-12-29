//
// Created by james on 29/12/2019.
//

#ifndef ILLATE_IINT_H
#define ILLATE_IINT_H

#include "inum.h"

class Iint : public Inum{
public:
    Iint(int val);
    std::string to_string_native();

    static std::shared_ptr<Iint> to_item(int val){
        return std::make_shared<Iint>(val);
    }
private:
    const int val;
};

#endif //ILLATE_IINT_H
