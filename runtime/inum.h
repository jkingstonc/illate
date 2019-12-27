//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_INUM_H
#define ILLATE_INUM_H

#include "item.h"

class Iuint8 : public Item{
public:
    ItemType type(){ return NUMBER; }
};

class Iint8 : public Item{
public:
    ItemType type(){ return NUMBER; }
};

class Iuint16 : public Item{
public:
    ItemType type(){ return NUMBER; }
};

class Iint16 : public Item{
public:
    ItemType type(){ return NUMBER; }
};

class Iuint32 : public Item{
public:
    ItemType type(){ return NUMBER; }
};

class Iint32 : public Item{
public:
    ItemType type(){ return NUMBER; }
};

class Ifloat32 : public Item{
public:
    ItemType type(){ return NUMBER; }
};

class Ifloat64 : public Item{
public:
    ItemType type(){ return NUMBER; }
};

class Ifloat128 : public Item{
public:
    ItemType type(){ return NUMBER; }
};

#endif //ILLATE_INUM_H
