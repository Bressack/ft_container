#pragma once

namespace ft {
    template < typename T >
    class py_iterator
    {
        protected:
            typedef ft::node<T>*        node_pointer;

        private:
            node_pointer                _ptr;
        public:
            py_iterator(container_begin) : _ptr(NULL) {
            
            }
            ~py_iterator() {

            }

            py_iterator&    operator=(const py_iterator& it)
    }
}


drawer -> vector: [ vector , vector , ... , vector ]

23
[b] | 0x1 -> [b][ ][e] 21
[ ] | 0x2 -> [b][ ][ ][ ][e] 17
[ ] | 0x3 -> [b][ ][ ][ ][ ][ ][ ][ ][e] 9
[ ] | 0x4 -> [b][ ][ ][ ][ ][ ][ ][ ][ ][X][ ][ ][ ][ ][ ][ ][e]
[ ] | 0x5 -> [b][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][X][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][e]
[e]