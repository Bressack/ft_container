#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

# include "node.hpp"
# include "tree_iterator.hpp"
# include "../shared/color.hpp"
# include "../shared/utils.hpp"
# include "../shared/reverse_iterator.hpp"
# include "../shared/pair.hpp"

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
class avl_tree
{
  public:

    typedef Key                                     key_type;
    typedef T                                       mapped_type;
    typedef Compare                                 key_compare;
    typedef Alloc                                   allocator_type;
    typedef ft::pair<key_type, mapped_type>         value_type;
    typedef ft::tree_iterator<value_type>           iterator;
    typedef ft::const_tree_iterator<value_type>     const_iterator;
    typedef ft::reverse_iterator<iterator>          reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

    typedef ft::node<value_type>                    node_type;
    typedef ft::node<value_type>*                   node_pointer;

    typedef size_t                                  size_type;

    typedef typename allocator_type::template rebind<node_type>::other	node_alloc_type;

    class value_compare : public std::binary_function<value_type, value_type, bool>
    {
      protected:
        Compare comp;
      public:
        value_compare (Compare c) : comp(c) {}
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;
        bool operator() (const value_type& x, const value_type& y) const
        { return comp(x.first, y.first); }
    };

    avl_tree() : _end(NULL), _root(NULL), _size(0)
    {
      _end = node_alloc_type().allocate(1);
      node_alloc_type().construct(_end, node_type());
      update_end();
    };

    avl_tree(const avl_tree &x) : _end(NULL), _root(NULL), _size(0)
    {
      if (this != &x)
      {
        _end = node_alloc_type().allocate(1);

        node_alloc_type().construct(_end, node_type());
        if (x.root() != NULL)
          copy_node(x.root());
        _size = x.size();
        update_end();
      }
    };

    avl_tree& operator= (const avl_tree &x)
    {
      if (this != &x)
      {
        clear_tree();
        if (x.root() != NULL)
          copy_node(x.root());
        _size = x.size();
        update_end();
      }
      return(*this);
    };

    virtual ~avl_tree()
    {
      clear_tree();
      node_alloc_type().destroy(_end);
      node_alloc_type().deallocate(_end, 1);
    };

  private :

    node_pointer    _end;
    node_pointer    _root;
    int             _size;

    void clear_node (node_pointer node)
    {
      if (node != NULL)
      {
        clear_node(node->_left);
        clear_node(node->_right);
        delete node;
        node = NULL;
      }
    };

    void clear_tree ()
    {
      if (_size > 0)
      {
        clear_node(_root->_left);
        clear_node(_root->_right);
        delete _root;
        _root = NULL;
        _size = 0;
      }
    };

    void update_end ()
    {
      if (_root)
      {
        if (_end)
        {
          _end->_left = _root;
          _end->_right = _root;
        }
        _root->_parent = _end;
      }
    };

    void copy_node (node_pointer node)
    {
      if (node != NULL)
      {
        add(node->_value);
        copy_node(node->_left);
        copy_node(node->_right);
      }
    };

    int depth (const node_pointer node) const
    {
      if (node == NULL)
        return (0);

      int left_depth = depth(node->_left);
      int right_depth = depth(node->_right);
      if (left_depth > right_depth)
        return (left_depth + 1);
      else
        return (right_depth + 1);
    };

    // - - - - - - - below : search_tree specific - - - - - - - - - - - - - -

    node_pointer maximum (node_pointer node) const
    {
      if (node)
      {
        while (node->_right != NULL)
          node = node->_right;
      }
      return (node);
    };

    node_pointer minimum (node_pointer node) const
    {
      if (node)
      {
        while (node->_left != NULL)
          node = node->_left;
      }
      return (node);
    };

    node_pointer find_key (const key_type& k) const
    {
      node_pointer node = _root;
      while (node != NULL && !(node->_value.first == k))
      {
        if (key_comp()(k, node->_value.first))
          node = node->_left;
        else
          node = node->_right;
      }
      return (node);
    };

    node_pointer find_future_parent (const value_type &value) const
    {
      if (_size == 0)
        return NULL;

      node_pointer  parent = _root;
      int           parent_found = 0;

      while (!parent_found)
      {
        if (value_comp()(value, parent->_value) && parent->_left != NULL)
          parent = parent->_left;
        else if (value_comp()(parent->_value, value) && parent->_right != NULL)
          parent = parent->_right;
        else
          parent_found = 1;
      }
      return (parent);
    };

    int simple_add (const value_type &value)
    {
      if (count(value.first))
        return (0);

      node_pointer parent = find_future_parent(value);
      node_pointer new_node = new ft::node<value_type>(value, parent);

      if (new_node == NULL)
        return (0);

      if (parent == NULL)
        _root = new_node;
      else if (value_comp()(value, parent->_value))
        parent->_left = new_node;
      else
        parent->_right = new_node;
      ++_size;
      return (1);
    };

    int simple_remove(const key_type &k)
    {
      node_pointer node = find_key(k);
      if (node == NULL)
        return (0);

      node_pointer successor = maximum(node->_left);

      if (successor == NULL) // si pas de node left
      {
        if (node == _root)
          _root = node->_right;
        else if (node->_parent->_left == node)
          node->_parent->_left = node->_right;
        else
          node->_parent->_right = node->_right;
        if (node->_right != NULL)
          node->_right->_parent = node->_parent;
      }
      else // si node left
      {
        node->_value = successor->_value;
        if (successor->_parent->_left == successor)
          successor->_parent->_left = successor->_left;
        else
          successor->_parent->_right = successor->_left;
        if (successor->_left != NULL)
          successor->_left->_parent = successor->_parent;
        node = successor;
      }
      delete node;
      _size -= 1;
      return (1);
    };

    // - - - - - - - below : avl_tree specific - - - - - - - - - - - - - -

    int balance(node_pointer node)
    {
      if (node == NULL)
        return (0);
      return (depth(node->_right) - depth(node->_left));
    }

    void balance_tree (node_pointer node)
    {
      if (node == NULL)
        return;

      int balance_root = balance(node);
      if (balance_root == 2) // trop a droite
      {
        if (balance(node->_right) == -1) // et trop a gauche => rd + rg
          rotate_right(node->_right);
        rotate_left(node);
      }
      else if (balance_root == -2) // si trop a gauche
      {
        if (balance(node->_left) == 1) // et trop a droite => rg + rd
          rotate_left(node->_left);
        rotate_right(node);
      }
      balance_tree(node->_parent);
      update_end();
    };

    void rotate_left(node_pointer node)
    {
      if (node == NULL)
        return;

      node_pointer right = node->_right;

      if (node->_parent != NULL) // node->parent === node->right : je remonte node->right
      {
        if (node->_parent->_right == node)
          node->_parent->_right = right;
        else
          node->_parent->_left = right;
      }
      right->_parent = node->_parent;

      if (right->_left != NULL) // node === node->right->left : je deplace la branche du dessous (et vide la gauche du nouveau sous-parent)
        right->_left->_parent = node;
      node->_right = right->_left;

      node->_parent = right; // node->parent === right : je descends le node initial sous le nouveau sous-parent
      right->_left = node;
      if (node == _root)
        _root = right;
    };

    void rotate_right(node_pointer node)
    {
      if (node == NULL)
        return;

      node_pointer left = node->_left;

      if (node->_parent != NULL) // node->parent === node->left
      {
        if (node->_parent->_left == node)
          node->_parent->_left = left;
        else
          node->_parent->_right = left;
      }
      left->_parent = node->_parent;

      if (left->_right != NULL) // node === node->left->right
        left->_right->_parent = node;
      node->_left = left->_right;

      node->_parent = left; // node->parent === left
      left->_right = node;
      if (node == _root)
        _root = left;
    };

    int add (const value_type &value)
    {
      if (simple_add(value) == 0)
        return (0);
      balance_tree(find_key(value.first));
      return (1);
    };

    int remove_key (const key_type & k)
    {
      node_pointer parent = find_key(k);
      if (parent)
        parent = parent->_parent;

      if (simple_remove(k) == 0)
        return (0);
      balance_tree(parent);
      return (1);
    };

    // - - - - - - - below : public - - - - - - - - - - - - - -
    // - - - - - - - below : public - - - - - - - - - - - - - -
    // - - - - - - - below : public - - - - - - - - - - - - - -

  public :

    inline node_pointer root() const
    {
      return (_root);
    }
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // - - - - - - - below : public in map stl container - - - - - - - - - -
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    bool empty() const
    {
      return (size() == 0);
    };
    size_type size() const
    {
      return (_size);
    };
    size_type max_size() const
    {
      return (allocator_type().max_size());
    };

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    iterator begin ()
    {
      if (size() == 0)
        return (end());
      return (iterator(minimum(_root)));
    };

    const_iterator begin () const
    {
      if (size() == 0)
        return (end());
      return (const_iterator(minimum(_root)));
    };

    iterator end ()
    {
      return (iterator(_end));
    };

    const_iterator end () const
    {
      return (const_iterator(_end));
    };

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    reverse_iterator rbegin ()
    {
      return (reverse_iterator(_end));
    };

    const_reverse_iterator rbegin () const
    {
      return (const_reverse_iterator(_end));
    };

    reverse_iterator rend ()
    {
      return (reverse_iterator(begin()));
    };

    const_reverse_iterator rend () const
    {
      return (const_reverse_iterator(begin()));
    };

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    ft::pair<iterator,bool> insert (const value_type& val)
    {
      bool added = add(val);
      ft::pair<iterator,bool> ret = ft::make_pair(iterator(find_key(val.first)), added);
      return (ret);
    };

    iterator insert (iterator position, const value_type& val)
    {
      (void)position;
      return (insert(val).first);
    };

    template <class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
      while (first != last)
      {
        insert(*first);
        ++first;
      }
    };

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    iterator find (const key_type& k)
    {
      node_pointer found = find_key(k);
      if (found == NULL)
        return (_end);
      return (iterator(found));
    };

    const_iterator find (const key_type& k) const
    {
      node_pointer found = find_key(k);
      if (found == NULL)
        return (_end);
      return (const_iterator(found));
    };

    size_type count (const key_type& k) const
    {
      const_iterator it = find(k);
      return (it != _end);
    };

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // int remove_key (const key_type &k)

    void erase (iterator position)
    {
      remove_key((*position).first); // check w/ stld
    };
    size_type erase (const key_type& k)
    {
      return (remove_key(k));
    };
    void erase (iterator first, iterator last)
    {
      while (first != last)
      {
        erase(first++);
      }
    };

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    void swap (avl_tree& x)
    {
      if (this == &x)
        return;
      ft::ft_swap(_end, x._end);
      ft::ft_swap(_root, x._root);
      ft::ft_swap(_size, x._size);
    };

    void clear ()
    {
      clear_tree();
    };


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    key_compare key_comp() const
    {
      return (key_compare());
    };

    value_compare value_comp() const
    {
      return (value_compare(key_compare()));
    };

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    mapped_type& operator[] (const key_type& k)
    {
      node_pointer node = find_key(k);
      if (node != NULL)
        return (node->_value.second);
      ft::pair<iterator,bool> insert_ret = insert(ft::make_pair(k, mapped_type()));
      return ((*insert_ret.first).second);
    };
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    iterator lower_bound (const key_type& k) // 1st not to go before
    {
      iterator  it = begin();
      iterator  it_end = end();

      for (; it != it_end; it++)
      {
        if (key_comp()(it->first, k) == false)
          return (it);
      }
      return (it);
    };

    const_iterator lower_bound (const key_type& k) const
    {
      const_iterator  it = begin();
      const_iterator  it_end = end();

      for (; it != it_end; it++)
      {
        if (key_comp()(it->first, k) == false)
          return (it);
      }
      return (it);
    };

    iterator upper_bound (const key_type& k) // 1st to go after
    {
      iterator  it = begin();
      iterator  it_end = end();

      for (; it != it_end; it++)
      {
        if (key_comp()(k, it->first) == true)
          return (it);
      }
      return (it);
    };

    const_iterator upper_bound (const key_type& k) const
    {
      const_iterator  it = begin();
      const_iterator  it_end = end();

      for (; it != it_end; it++)
      {
        if (key_comp()(k, it->first) == true)
          return (it);
      }
      return (it);
    };

    ft::pair<iterator,iterator> equal_range (const key_type& k) // in between
    {
      return (ft::make_pair(lower_bound(k), upper_bound(k)));
    };

    ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
    {
      return (ft::make_pair(lower_bound(k), upper_bound(k)));
    };

    allocator_type get_allocator() const
    {
      return (allocator_type());
    };

}; // tree

#endif
