//
// Created by james on 29/12/2019.
//

#include "icontainer.h"

items::Icontainer::Icontainer() {
}

items::ItemType items::Icontainer::type(){
    return items::ItemType::CONTAINER;
}
std::string items::Icontainer::to_string_native(){
    return std::string("Container");
}

void items::Icontainer::null_grow(int index){
    // If the index is greater than the container size, pad with INil's
    while(index >= this->keys.size()){
        this->keys.push_back(std::make_shared<items::Inill>());
        this->values.push_back(std::make_shared<items::Inill>());
    }
}

std::shared_ptr<items::Item> items::Icontainer::get(int by_index){}
std::shared_ptr<items::Item> items::Icontainer::get(std::shared_ptr<Item> by_reference){}
std::shared_ptr<items::Item> items::Icontainer::get(Item by_value){}

void items::Icontainer::raw_set(int index, std::shared_ptr<items::Item> key, std::shared_ptr<items::Item> value){
    this->keys.at(index) = key;
    this->values.at(index) = value;
}
void items::Icontainer::set(int by_index, std::shared_ptr<items::Item> new_value){
    this->null_grow(by_index);
    this->values.at(by_index) = new_value;
}
void items::Icontainer::set(std::shared_ptr<items::Item> by_reference, std::shared_ptr<items::Item> new_value){
    // Compare the pointer values rather than the raw values
    for(int i = 0; i<this->keys.size(); i++){
        if(this->keys.at(i) == by_reference)
            this->values.at(i) = new_value;
    }
}
void items::Icontainer::set(items::Item by_value, std::shared_ptr<items::Item> new_value){
    for(int i = 0; i<this->keys.size(); i++){
        // Compare the raw values rather than the pointer values
        if(*(this->keys.at(i)) == *new_value)
            this->values.at(i) = new_value;
    }
}

std::shared_ptr<items::Item> items::Icontainer::put(int by_index, std::shared_ptr<items::Item> new_value){}
std::shared_ptr<items::Item> items::Icontainer::put(std::shared_ptr<items::Item> by_reference, std::shared_ptr<items::Item> new_value){}
std::shared_ptr<items::Item> items::Icontainer::put(items::Item by_value, std::shared_ptr<items::Item> new_value){}