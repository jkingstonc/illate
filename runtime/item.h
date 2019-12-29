//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_ITEM_H
#define ILLATE_ITEM_H

#include <string>
#include <memory>

namespace Items{
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
        virtual std::string to_string_native();

        /**
         * Every Item is callable, it can be called with any amount of arguments
         * */
        virtual void call();
        // Here arg1 can be a single item or an item chain
        virtual void call(std::shared_ptr<Item> arg1);
        virtual void call(std::shared_ptr<Item> arg1, std::shared_ptr<Item> arg2);
        virtual void call(std::shared_ptr<Item> arg1, std::shared_ptr<Item> arg2, std::shared_ptr<Item> arg3);

        static std::string item_type_str[10];

    private:
    };
}

#endif //ILLATE_ITEM_H
