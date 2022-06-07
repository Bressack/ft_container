#pragma once

#include "../others/color.hpp"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

#include <iostream>
#include <fstream>

# define NULL_STR_DOT "(null)"

namespace ft
{
    template < class T >
    class displaytree
    {
        private:
            std::string     fname;

        public:
            typedef T           node_type;

            displaytree(std::string fname) { this->fname = fname; };
            displaytree() { this->fname = std::string("tree"); };
            ~displaytree() {};

        private:
            int             get_node_depth (node_type *node)
            {
                if (node == NULL)
                    return (0);

                int left_depth = get_node_depth(node->left);
                int right_depth = get_node_depth(node->right);
                return 1 + ((left_depth > right_depth) ? left_depth : right_depth);
            }

            int             get_node_depth_diff (node_type *node)
            {
                return (get_node_depth(node->right) - get_node_depth(node->left));
            }

            std::string get_value(node_type *n)
            {
                static const std::string null_str = std::string(NULL_STR_DOT);

                if (n)
                    return (std::to_string(n->value.first) + std::string(" [") + std::to_string(get_node_depth_diff(n)) + std::string("]"));
                return (null_str);
            }

            void	bst_print_dot_aux(node_type *node, std::ofstream & stream, int deep)
            {
                static int i = 0;

                if (node->left)
                {
                    stream  << std::string("    \"") << get_value(node).c_str()
                            << std::string("\" -> \"")
                            << get_value(node->left).c_str() << "\";\n";
                }
                else
                {
                    i++;
                    stream  << std::string("    null" + std::to_string(i) + " [shape=point];\n")
                            << std::string("    \"") << get_value(node).c_str()
                            << std::string("\" -> \"") << std::string("null" + std::to_string(i)) << "\"\n";
                }

                if (node->right)
                {
                    stream  << std::string("    \"") << get_value(node).c_str()
                            << std::string("\" -> \"")
                            << get_value(node->right).c_str() << "\";\n";
                }
                else
                {
                    i++;
                    stream  << std::string("    null" + std::to_string(i) + " [shape=point];\n")
                            << std::string("    \"") << get_value(node).c_str()
                            << std::string("\" -> \"") << std::string("null" + std::to_string(i)) << "\"\n";
                }

                if (node->left)
                    bst_print_dot_aux(node->left, stream, deep * 10 + 1);
                if (node->right)
                    bst_print_dot_aux(node->right, stream, deep * 10 + 2);
            }

            void	bst_print_dot(node_type *tree, std::ofstream & stream)
            {
                stream << "digraph BST {\n" << "    node [fontname=\"Arial\"];\n";
                if (!tree)
                    stream << "\n";
                else if (!tree->right && !tree->left)
                    stream << std::string("    \"[ ") << get_value(tree).c_str() << " ]_(0)\";\n";
                else
                    bst_print_dot_aux(tree, stream, 0);
                stream << "}\n";
            }

        public:

            void	tree_draw(node_type *node)
            {
                // int		stream;
                std::ofstream    stream;

                remove(std::string(this->fname + std::string(".dot")).c_str());
                remove(std::string(this->fname + std::string(".png")).c_str());
                stream.open (std::string(this->fname + std::string(".dot")).c_str());
                if (!stream)
                {
                    std::cout << C_G_MAGENTA << "warning:" << C_G_WHITE
                        << "displaytree exception: could not open stream" << C_RES << std::endl;
                    return ;
                }
                bst_print_dot(node, stream);
                stream.close();
            }

    };
}

// #endif
