//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_ITEM_H
#define ILLATE_ITEM_H

#include <string>
#include <memory>

namespace items{

    class Inill;
    class Ibool;
    class Ibyte;
    class Iint;
    class Idouble;
    class Istring;

    enum class ItemType{
        NIL,
        CHAIN,

        BOOLEAN,
        NUMBER,
        STRING,

        CONTAINER,

        FUNCTION,
        CLASS,
        OBJECT,

        CORE,
    };

    class Item{
    public:
        ItemType type();

        std::string to_string_native();
        bool to_bool_native();
        std::uint8_t to_byte_native();
        int to_int_native();
        double to_double_native();

        std::shared_ptr<Istring> to_string();
        std::shared_ptr<Ibool> to_bool();
        std::shared_ptr<Ibyte> to_byte();
        std::shared_ptr<Iint> to_int();
        std::shared_ptr<Idouble> to_double();

        std::shared_ptr<Item> neg();
        std::shared_ptr<Item> add(Item right);
        std::shared_ptr<Item> add(int right);
        std::shared_ptr<Item> add(double right);
        std::shared_ptr<Item> sub(Item right);
        std::shared_ptr<Item> sub(int right);
        std::shared_ptr<Item> sub(double right);
        std::shared_ptr<Item> mul(Item right);
        std::shared_ptr<Item> mul(int right);
        std::shared_ptr<Item> mul(double right);
        std::shared_ptr<Item> div(Item right);
        std::shared_ptr<Item> div(int right);
        std::shared_ptr<Item> div(double right);
        std::shared_ptr<Item> mod(Item right);
        std::shared_ptr<Item> mod(int right);
        std::shared_ptr<Item> mod(double right);
        std::shared_ptr<Item> rem(Item right);
        std::shared_ptr<Item> rem(int right);
        std::shared_ptr<Item> rem(double right);

        // Every Item is callable, it can be called with any amount of arguments
        std::shared_ptr<Item> call();
        // Here arg1 can be a single item or an item chain
        std::shared_ptr<Item> call(std::shared_ptr<Item> arg1);
        std::shared_ptr<Item> call(std::shared_ptr<Item> arg1, std::shared_ptr<Item> arg2);
        std::shared_ptr<Item> call(std::shared_ptr<Item> arg1, std::shared_ptr<Item> arg2, std::shared_ptr<Item> arg3);

        static std::string item_type_str[10];

    private:
    };
}

#endif //ILLATE_ITEM_H
