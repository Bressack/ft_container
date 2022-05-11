#pragma once

namespace ft
{
    template < class K, class V >
    class node
    {
        public:
            node *      _parent;
            node *      _left;
            node *      _right;
            K           _key;
            V           _value;
            char        _depth;

            // (1) default
            node()
            : _key(), _value(), _parent(NULL), _left(NULL), _right(NULL), _depth(0)
            {};
            // (2) fill
            node(const K & key, const V & value)
            : _key(key), _value(value), _parent(NULL), _left(NULL), _right(NULL), _depth(0)
            {};
            // (3) fill and link to parent
            node(const K & key, const V & value, node<K,V> * parent)
            : _key(key), _value(value), _parent(parent), _left(NULL), _right(NULL), _depth(0)
            {};
    };
}