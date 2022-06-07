#pragma once

# include "../others/color.hpp"
# include "../others/utils.hpp"
# include "../others/reverse_iterator.hpp"
# include "../others/pair.hpp"
# include "display_tree.hpp"
# include "node.hpp"
# include <iostream>
# include <vector>

namespace ft
{
    template < class K, class T >
    class tree
    {
        /* ***************************************************************** *\
        |                       INNER TYPES DEFINITION                        |
        \* ***************************************************************** */

        public:
            typedef K                                       key_type;
            typedef T                                       mapped_type;
            typedef ft::pair<key_type, mapped_type>         value_type;
            typedef ft::node<value_type>                    node_type;
            typedef ft::node<value_type>*                   node_pointer;

        // inner attribute
        private:
            // DEVTOOL - display_tree.hpp
            ft::displaytree<node_type>     _dt;

            node_pointer    _end;
            node_pointer    _root;
            int             _size;

        /* ***************************************************************** *\
        |                      CONSTRUCTOR / DESTRUCTOR                       |
        \* ***************************************************************** */

        public:
            tree() : _end(NULL), _root(NULL), _size(0) {}
            virtual ~tree() { /*clear_tree();*/ }


        /* ***************************************************************** *\
        |                         METHODS DECLARATION                         |
        \* ***************************************************************** */


            // allocations
            node_pointer        allocate_node(const value_type & value, node_pointer parent = NULL);
            void                deallocate_node(node_pointer node);

            // modifiers
            void                insert(const value_type & value);
            void                insert(const key_type & key, const mapped_type & value);

            void                remove(const value_type & value);
            void                remove(const key_type & key);

            void                clear_node(node_pointer node);
            void                clear_tree(void);

            // accessors
            node_pointer        search(const value_type & value) const;
            node_pointer        search(const key_type & key) const;

            node_pointer        minimum (node_pointer node) const;
            node_pointer        maximum (node_pointer node) const;

            node_pointer        prev_value (node_pointer node) const;
            node_pointer        next_value (node_pointer node) const;

        private:
            node_pointer        find_future_parent (const node_pointer & node) const;
            void                right_rotate (node_pointer node);
            void                left_rotate (node_pointer node);
            void                balance_tree (const node_pointer node);
            int                 get_node_depth (node_pointer node);
            int                 get_node_depth_diff (node_pointer node);

        // DEVTOOLS
        public:
            void            display(void)
            {
                _dt.tree_draw(_root);
            }
            void            tree_to_vector(std::vector<node_pointer> & v, node_pointer node)
            {
                if (!node)
                    return ;
                v.push_back(node);
                tree_to_vector(v, node->left);
                tree_to_vector(v, node->right);
            }
            bool            is_tree_legal(void)
            {
                bool islegal = true;
                std::vector<node_pointer> v;
                typename std::vector<node_pointer>::iterator it;
                int     depths[7] = { 0 };

                tree_to_vector(v, _root);
                it = v.begin();
                while (it != v.end())
                {
                    if (search((*it)->value) == NULL)
                    {
                        islegal = false;
                        std::cout << "unreachable node -> " << (*it)->value.first << std::endl;
                    }
                    int d = get_node_depth_diff(*it);
                         if (d <  -2) depths[0] += 1;
                    else if (d == -2) depths[1] += 1;
                    else if (d == -1) depths[2] += 1;
                    else if (d ==  0) depths[3] += 1;
                    else if (d ==  1) depths[4] += 1;
                    else if (d ==  2) depths[5] += 1;
                    else if (d >   2) depths[6] += 1;
                    it++;
                }
                std::cout << "[ <2 ][ -2 ][ -1 ][  0 ][ +1 ][ +2 ][ >2 ]" << std::endl;
                std::cout << "["  << std::setw(4) << depths[0]
                          << "][" << std::setw(4) << depths[1]
                          << "][" << std::setw(4) << depths[2]
                          << "][" << std::setw(4) << depths[3]
                          << "][" << std::setw(4) << depths[4]
                          << "][" << std::setw(4) << depths[5]
                          << "][" << std::setw(4) << depths[6]
                          << "]" << std::endl;
                return (islegal);
            }

        /* ***************************************************************** *\
        |                         METHODS DEFINITION                          |
        \* ***************************************************************** */
    }
}