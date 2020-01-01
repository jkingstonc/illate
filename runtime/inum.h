//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_INUM_H
#define ILLATE_INUM_H

#include "item.h"

namespace items{
    class Inum : public items::Item{
    public:
        Inum();
        items::ItemType type();
    private:
    };
};

#endif //ILLATE_INUM_H