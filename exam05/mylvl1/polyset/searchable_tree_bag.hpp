#pragma once
#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public searchable_bag, public tree_bag{
    public :
        searchable_tree_bag() = default;
        ~searchable_tree_bag() = default;
        searchable_tree_bag(const searchable_tree_bag &oth) : tree_bag(oth) {}
        searchable_tree_bag &operator=(const searchable_tree_bag &oth) {
            if (this != &oth) {
                tree_bag::operator=(oth);
            }
            return *this;
        }
        bool has(int val) const {
            node *curr = tree;
            while (curr)
            {
                if (curr->value == val)
                    return true;
                if (val > curr->value)
                    curr = curr->r;
                else 
                    curr = curr->l;
            }
            return false;
        }
} ;