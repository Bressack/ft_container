#include <vector>
#include <stack>
#include <map>
#include <list>
#include <deque>
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"

template <typename T>
void print_stack_inf(T s)
{
	std::cout << "-----------" << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "size"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << "size  : " << s.size() << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "empty"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << "empty : " << s.empty() << std::endl;
	if (!s.empty())
	{
		std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "top"
				  << "  --------------------------" << C_RES << std::endl;
		std::cout << "top   : " << s.top() << std::endl;
		s.top() -= 5;
		std::cout << "top   : " << s.top() << std::endl;
	}
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "push"
			  << "  --------------------------" << C_RES << std::endl;
	s.push(8);
	s.push(16);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "pop"
			  << "  --------------------------" << C_RES << std::endl;
	s.pop();
	std::cout << "size  : " << s.size() << std::endl;
	std::cout << "-----------" << std::endl;
}

template <typename T>
void print_vector(T *v)
{
	typename T::iterator it = (*v).begin();
	typename T::const_iterator itend = (*v).end();

	std::cout << ORANGE;
	for (; it != itend; it++)
		std::cout << "[" << *it << "]";
	std::cout << C_RES << std::endl;
}

template <typename T>
void rprint_vector(T *v)
{
	typename T::reverse_iterator it = (*v).rbegin();
	typename T::const_reverse_iterator itend = (*v).rend();

	std::cout << ORANGE;
	for (; it != itend; it++)
		std::cout << "[" << *it << "]";
	std::cout << C_RES << std::endl;
}

template <typename T>
void print_vector_inf_ptr(T *v)
{
	std::cout << "-----------" << std::endl;
	print_vector(v);
	rprint_vector(v);
	std::cout << "size      : " << (*v).size() << std::endl;
	std::cout << "max_size  : " << (*v).max_size() << std::endl;
	std::cout << "empty  : " << (*v).empty() << std::endl;
	std::cout << "capacity  : " << (*v).capacity() << std::endl;
	if ((*v).size())
	{
		std::cout << "front     : " << (*v).front() << std::endl;
		std::cout << "back      : " << (*v).back() << std::endl;
	}
	std::cout << "-----------" << std::endl;
}

template <class T, class U, class Compare, class Alloc>
void print_map(NS::map<T, U, Compare, Alloc> map)
{
	typename NS::map<T, U, Compare, Alloc>::iterator it = map.begin();
	typename NS::map<T, U, Compare, Alloc>::const_iterator it_end = map.end();
	std::cout << "-------------------- MAP --------------------" << std::endl;
	std::cout << "size     : " << map.size() << std::endl;
	// std::cout << "max_size : " << map.max_size() << std::endl;
	std::cout << "empty    : " << map.empty() << std::endl;
	for (; it != it_end; it++)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "-------------------- END --------------------" << std::endl;
}

template <class T, class U, class Compare, class Alloc>
void rprint_map(NS::map<T, U, Compare, Alloc> map)
{
	typename NS::map<T, U, Compare, Alloc>::reverse_iterator it = map.rbegin();
	typename NS::map<T, U, Compare, Alloc>::const_reverse_iterator it_end = map.rend();
	std::cout << "-------------------- MAP --------------------" << std::endl;
	std::cout << "size     : " << map.size() << std::endl;
	// std::cout << "max_size : " << map.max_size() << std::endl;
	std::cout << "empty    : " << map.empty() << std::endl;
	for (; it != it_end; it++)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "-------------------- END --------------------" << std::endl;
}

void test_stack(void)
{
	std::cerr << TEST_COLOUR << "___ TEST STARTS ___ test_stack" << C_RES << std::endl;
	std::deque<int> mydeque(3, 100);			 // deque with 3 elements
	std::list<std::string> mylist(8, "example"); // deque with 3 elements
	ft::vector<int> myvector(2, 200);			 // vector with 2 elements
	ft::vector<int> myvector2(3, 200);			 // vector with 2 elements
	ft::vector<int> myvector_const(3, 200);		 // vector with 2 elements

	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "BASICS INT"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor empty"
			  << "  --------------------------" << C_RES << std::endl;
	NS::stack<int, std::deque<int> > first; // empty stack
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor deque"
			  << "  --------------------------" << C_RES << std::endl;
	NS::stack<int, std::deque<int> > second(mydeque); // stack initialized to copy of deque

	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "BASICS VECTOR<INT>"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	NS::stack<int, ft::vector<int> > third; // empty stack using vector
	NS::stack<int, ft::vector<int> > fourth(myvector);
	NS::stack<int, ft::vector<int> > fifth(myvector2);

	print_stack_inf(first);
	print_stack_inf(second);
	print_stack_inf(third);
	print_stack_inf(fourth);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "BASICS <LIST>"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	NS::stack<std::string, std::list<std::string> > stack_list(mylist); // empty stack using vector
	std::cout << "size  : " << stack_list.size() << std::endl;
	stack_list.pop();
	std::cout << "size  : " << stack_list.size() << std::endl;
	stack_list.push("pushed");
	std::cout << "size  : " << stack_list.size() << std::endl;
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "const stack"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	const NS::stack<int, ft::vector<int> > sixth(myvector_const);
	print_stack_inf(sixth);

	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "RELATIONAL OPERATORS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "=="
			  << "  --------------------------" << C_RES << std::endl;

	std::cout << (first == second);
	std::cout << (second == second);
	std::cout << (fourth == third);
	std::cout << (fourth == sixth);
	std::cout << (third == third) << std::endl;

	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "!="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first != second);
	std::cout << (second != second);
	std::cout << (fourth != third);
	std::cout << (fourth != sixth);
	std::cout << (third != third) << std::endl;

	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "<"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first < second);
	std::cout << (second < second);
	std::cout << (fourth < third);
	std::cout << (fourth < fifth);
	std::cout << (fourth < sixth);
	std::cout << (third < third) << std::endl;

	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "<="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first <= second);
	std::cout << (second <= second);
	std::cout << (fourth <= third);
	std::cout << (fourth <= sixth);
	std::cout << (third <= third) << std::endl;

	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << ">"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first > second);
	std::cout << (second > second);
	std::cout << (fourth > third);
	std::cout << (fourth > sixth);
	std::cout << (third > third) << std::endl;

	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << ">="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first >= second);
	std::cout << (second >= second);
	std::cout << (fourth >= third);
	std::cout << (fourth >= sixth);
	std::cout << (third >= third) << std::endl;
}

void test_stack_with_stl_containers(void)
{
	std::cerr << TEST_COLOUR << "___ TEST STARTS ___ test_stack_with_stl_containers_stl" << C_RES << std::endl;
	std::deque<int> mydeque(3, 100);		 // deque with 3 elements
	std::vector<int> myvector(2, 200);		 // vector with 2 elements
	std::vector<int> myvector2(3, 200);		 // vector with 2 elements
	std::vector<int> myvector_const(3, 200); // vector with 2 elements

	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "BASICS INT"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor empty"
			  << "  --------------------------" << C_RES << std::endl;
	NS::stack<int, std::deque<int> > first; // empty stack
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor deque"
			  << "  --------------------------" << C_RES << std::endl;
	NS::stack<int, std::deque<int> > second(mydeque); // stack initialized to copy of deque

	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "BASICS VECTOR<INT>"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	NS::stack<int, std::vector<int> > third; // empty stack using vector
	NS::stack<int, std::vector<int> > fourth(myvector);
	NS::stack<int, std::vector<int> > fifth(myvector2);

	print_stack_inf(first);
	print_stack_inf(second);
	print_stack_inf(third);
	print_stack_inf(fourth);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "const stack"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	const NS::stack<int, std::vector<int> > sixth(myvector_const);
	print_stack_inf(sixth);

	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "RELATIONAL OPERATORS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "=="
			  << "  --------------------------" << C_RES << std::endl;

	std::cout << (first == second);
	std::cout << (second == second);
	std::cout << (fourth == third);
	std::cout << (fourth == sixth);
	std::cout << (third == third) << std::endl;

	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "!="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first != second);
	std::cout << (second != second);
	std::cout << (fourth != third);
	std::cout << (fourth != sixth);
	std::cout << (third != third) << std::endl;

	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "<"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first < second);
	std::cout << (second < second);
	std::cout << (fourth < third);
	std::cout << (fourth < fifth);
	std::cout << (fourth < sixth);
	std::cout << (third < third) << std::endl;

	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "<="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first <= second);
	std::cout << (second <= second);
	std::cout << (fourth <= third);
	std::cout << (fourth <= sixth);
	std::cout << (third <= third) << std::endl;

	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << ">"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first > second);
	std::cout << (second > second);
	std::cout << (fourth > third);
	std::cout << (fourth > sixth);
	std::cout << (third > third) << std::endl;

	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << ">="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first >= second);
	std::cout << (second >= second);
	std::cout << (fourth >= third);
	std::cout << (fourth >= sixth);
	std::cout << (third >= third) << std::endl;
}

void test_vector_str(void)
{
	std::cerr << TEST_COLOUR << "___ TEST STARTS ___ test_vector_str" << C_RES << std::endl;
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "BASICS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor 1/4"
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<std::string> first; // empty
	print_vector_inf_ptr(&first);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor 2/4"
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<std::string> second(4, "hundred"); // n, val (fill)
	print_vector_inf_ptr(&second);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor 3/4"
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<std::string> fifth(second.begin() + 1, second.end()); // range
	print_vector_inf_ptr(&fifth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor 4/4"
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<std::string> third(second); // copy
	print_vector_inf_ptr(&third);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "MODIFIERS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "push_back"
			  << "  --------------------------" << C_RES << std::endl;
	std::string strs[8] = {"zero", "one", "two", "three", "four", "five", "six", "seven"};
	for (int i = 0; i < 8; i++)
		first.push_back(strs[i]);
	NS::vector<std::string>::iterator it1 = first.begin() + 2;
	NS::vector<std::string>::iterator it2 = first.begin() + 4;
	print_vector_inf_ptr(&first);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "erase 1/2"
			  << "  --------------------------" << C_RES << std::endl;
	first.erase(it1, it2);
	print_vector_inf_ptr(&first);
	first.erase(first.begin(), first.begin() + 1);
	print_vector_inf_ptr(&first);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "erase 2/2"
			  << "  --------------------------" << C_RES << std::endl;
	first.erase(first.begin() + 3);
	print_vector_inf_ptr(&first);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "pop_back"
			  << "  --------------------------" << C_RES << std::endl;
	for (int i = 3; i < 6; i++)
		second.push_back(strs[i]);
	print_vector_inf_ptr(&second);
	second.pop_back();
	print_vector_inf_ptr(&second);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "swap"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << SKY_BLUE << "------------- "
			  << "AVANT SWAP"
			  << " -------------" << C_RES << std::endl;
	print_vector_inf_ptr(&first);
	print_vector_inf_ptr(&second);
	first.swap(second);
	std::cout << SKY_BLUE << "------------- "
			  << "APRES SWAP"
			  << " -------------" << C_RES << std::endl;
	print_vector_inf_ptr(&first);
	print_vector_inf_ptr(&second);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "assign 1/2"
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<std::string> fourth;
	fourth.assign(6, "twelve"); // n, val
	print_vector_inf_ptr(&fourth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "assign 2/2"
			  << "  --------------------------" << C_RES << std::endl;
	fourth.assign(first.begin() + 2, first.begin() + 6); // range
	print_vector_inf_ptr(&fourth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "insert 1/3"
			  << "  --------------------------" << C_RES << std::endl;
	print_vector_inf_ptr(&fourth);
	fourth.insert(fourth.begin() + 2, "ninety-nine"); // pos, val
	print_vector_inf_ptr(&fourth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "insert 2/3"
			  << "  --------------------------" << C_RES << std::endl;
	fourth.insert(fourth.begin() + 3, 3, "eight"); // pos, n, val
	print_vector_inf_ptr(&fourth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "insert 3/3"
			  << "  --------------------------" << C_RES << std::endl;
	fourth.insert(fourth.begin() + 3, first.begin() + 2, first.begin() + 5); // range
	print_vector_inf_ptr(&fourth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "clear"
			  << "  --------------------------" << C_RES << std::endl;
	first.clear();
	print_vector_inf_ptr(&first);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "swap after clear"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << SKY_BLUE << "------------- "
			  << "AVANT SWAP"
			  << " -------------" << C_RES << std::endl;
	print_vector_inf_ptr(&first);
	print_vector_inf_ptr(&second);
	first.swap(second);
	std::cout << SKY_BLUE << "------------- "
			  << "APRES SWAP"
			  << " -------------" << C_RES << std::endl;
	print_vector_inf_ptr(&first);
	print_vector_inf_ptr(&second);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ELEMENT ACCESS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "at"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << first.at(0) << std::endl;
	std::cout << first.at(2) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "[]"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << first[0] << std::endl;
	std::cout << first[2] << std::endl;
	// std::cout << first[9] << std::endl;   // valgrind
	// std::cout << first[90] << std::endl;  // valgrind
	// std::cout << first[-1] << std::endl;  // valgrind
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "front"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << first.front() << std::endl;
	std::cout << second.front() << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "back"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << first.back() << std::endl;
	// std::cout << second.back() << std::endl;  // valgrind
	// std::cout << first.at(9) << std::endl; // exception	return (0);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ALLOCATOR"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "get_allocator"
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<std::string> myvector;
	std::string *p;
	unsigned int i;
	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);
	// construct values in-place on the array:
	for (i = 0; i < 5; i++)
		myvector.get_allocator().construct(&p[i], strs[i]);
	std::cout << "The allocated array contains:";
	for (i = 0; i < 5; i++)
		std::cout << ' ' << p[i];
	std::cout << '\n';
	// destroy and deallocate:
	for (i = 0; i < 5; i++)
		myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p, 5);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "CAPACITY"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "max_size"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << first.max_size() << std::endl;
	std::cout << second.max_size() << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "empty"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << first.empty() << std::endl;
	std::cout << second.empty() << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "resize"
			  << "  --------------------------" << C_RES << std::endl;
	print_vector_inf_ptr(&fourth);
	fourth.resize(15);
	print_vector_inf_ptr(&fourth);
	fourth.resize(6);
	print_vector_inf_ptr(&fourth);
	fourth.resize(0);
	print_vector_inf_ptr(&fourth);
	fourth.resize(8);
	print_vector_inf_ptr(&fourth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "reserve"
			  << "  --------------------------" << C_RES << std::endl;
	print_vector_inf_ptr(&first);
	first.reserve(13);
	print_vector_inf_ptr(&first);
	first.reserve(79);
	print_vector_inf_ptr(&first);
	first.reserve(80);
	print_vector_inf_ptr(&first);
	first.reserve(81);
	print_vector_inf_ptr(&first);
	first.reserve(45);
	print_vector_inf_ptr(&first);
	first.reserve(0);
	print_vector_inf_ptr(&first);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ITERATORS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "begin"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << *(first.begin()) << " ";
	std::cout << *(first.begin() + 2) << " ";
	// std::cout << *(first.begin() + 8) << " ";           // valgrind
	// std::cout << *(first.begin() - 1) << std::endl;     // valgrind
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "end"
			  << "  --------------------------" << C_RES << std::endl;
	// std::cout << *(first.end()) << " ";         // valgrind
	// std::cout << *(first.end() + 2) << " ";     // valgrind
	// std::cout << *(first.end() + 8) << " ";     // valgrind
	std::cout << *(first.end() - 1) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "rbegin"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << *(first.rbegin()) << " ";
	std::cout << *(first.rbegin() + 2) << " ";
	// std::cout << *(first.rbegin() + 8) << " ";          // valgrind
	// std::cout << *(first.rbegin() - 1) << std::endl;    // valgrind
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "rend"
			  << "  --------------------------" << C_RES << std::endl;
	// std::cout << *(first.rend()) << " ";                // valgrind
	// std::cout << *(first.rend() + 2) << " ";            // valgrind
	// std::cout << *(first.rend() + 8) << " ";            // valgrind
	std::cout << *(first.rend() - 1) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "all reverse"
			  << "  --------------------------" << C_RES << std::endl;
	{
		NS::vector<std::string> myvector(5);
		NS::vector<std::string>::reverse_iterator rit = myvector.rbegin();
		int i = 0;
		for (rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
			*rit = strs[++i];
		std::cout << "myvector contains:";
		for (NS::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "const reverse"
			  << "  --------------------------" << C_RES << std::endl;
	print_vector(&first);
	rprint_vector(&first);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "const iterators"
			  << "  --------------------------" << C_RES << std::endl;
	{
		NS::vector<std::string>::const_iterator ci = first.begin();
		NS::vector<std::string>::iterator ni = first.begin();
		for (; ci < first.end(); ci++)
		{
			// *ci += 1;
			std::cout << *ci << " ";
		}
		std::cout << std::endl;
		for (; ni < first.end(); ni++)
		{
			*ni += "1";
			std::cout << *ni << " ";
		}
		std::cout << std::endl;
	}
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "NON-MEMBER"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "swap"
			  << "  --------------------------" << C_RES << std::endl;
	{
		NS::vector<std::string> foo(3, "hundred");
		NS::vector<std::string> bar(5, "thousand");

		foo.swap(bar);

		std::cout << "foo contains:";
		for (NS::vector<std::string>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "bar contains:";
		for (NS::vector<std::string>::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "relational =="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first == second) << " ";
	std::cout << (second == second) << " ";
	std::cout << (second == first) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "relational !="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first != second) << " ";
	std::cout << (second != second) << " ";
	std::cout << (second != first) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "relational <"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first < second) << " ";
	std::cout << (second < second) << " ";
	std::cout << (second < first) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "relational <="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first <= second) << " ";
	std::cout << (second <= second) << " ";
	std::cout << (second <= first) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "relational >"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first > second) << " ";
	std::cout << (second > second) << " ";
	std::cout << (second > first) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "relational >="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first >= second) << " ";
	std::cout << (second >= second) << " ";
	std::cout << (second >= first) << std::endl;
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ITERATORS SWAP"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	NS::vector<std::string> *first_ptr = &first;
	NS::vector<std::string> &first_ref = first;
	print_vector(&first);
	NS::vector<std::string>::iterator it_test = first.begin();
	std::cout << "-------------------- AVANT SWAP --------------------" << std::endl;
	std::cerr << "Adress (first_ptr) : " << first_ptr << std::endl;
	std::cerr << "Adress (first_ref) : " << &first_ref << std::endl;
	std::cerr << "Adress : " << &(*it_test) << std::endl;
	std::cout << "Value : " << *it_test << std::endl;
	first.swap(fifth);
	std::cout << "-------------------- APRES SWAP --------------------" << std::endl;
	std::cerr << "Adress (first_ptr) : " << first_ptr << std::endl;
	std::cerr << "Adress (first_ref) : " << &first_ref << std::endl;
	std::cerr << "Adress : " << &(*it_test) << std::endl;
	std::cout << "Value : " << *it_test << std::endl;
	print_vector(&first);
	first.swap(fifth);
	std::cout << "-------------------- APRES SWAP AGAIN --------------------" << std::endl;
	std::cerr << "Adress (first_ptr) : " << first_ptr << std::endl;
	std::cerr << "Adress (first_ref) : " << &first_ref << std::endl;
	std::cerr << "Adress : " << &(*it_test) << std::endl;
	std::cout << "Value : " << *it_test << std::endl;
	print_vector(&first);
	print_vector(&first);
}

void test_vector(void)
{
	std::cerr << TEST_COLOUR << "___ TEST STARTS ___ test_vector" << C_RES << std::endl;
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "BASICS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor 1/4"
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<int> first; // empty
	print_vector_inf_ptr(&first);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor 2/4 (fill)"
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<int> second(4, 100); // n, val (fill)
	print_vector_inf_ptr(&second);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor 3/4 (range)"
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<int> fifth(second.begin() + 1, second.end()); // range
	print_vector_inf_ptr(&fifth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor 4/4 (copy)"
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<int> third(second); // copy
	print_vector_inf_ptr(&third);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "operator="
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<int> deep_copy; // copy
	deep_copy = fifth;
	std::cerr << "Address deep copy : " << C_RES << &deep_copy << std::endl;
	std::cerr << "Address deep copy : " << C_RES << &fifth << std::endl;
	print_vector_inf_ptr(&deep_copy);

	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "MODIFIERS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "push_back"
			  << "  --------------------------" << C_RES << std::endl;
	for (int i = 0; i < 8; i++)
		first.push_back(i);
	NS::vector<int>::iterator it1 = first.begin() + 2;
	NS::vector<int>::iterator it2 = first.begin() + 4;
	print_vector_inf_ptr(&first);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "erase 1/2"
			  << "  --------------------------" << C_RES << std::endl;
	first.erase(it1, it2);
	print_vector_inf_ptr(&first);
	first.erase(first.begin(), first.begin() + 1);
	print_vector_inf_ptr(&first);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "erase 2/2"
			  << "  --------------------------" << C_RES << std::endl;
	first.erase(first.begin() + 3);
	print_vector_inf_ptr(&first);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "pop_back"
			  << "  --------------------------" << C_RES << std::endl;
	for (int i = 3; i < 6; i++)
		second.push_back(i);
	print_vector_inf_ptr(&second);
	second.pop_back();
	print_vector_inf_ptr(&second);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "swap"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << SKY_BLUE << "------------- "
			  << "AVANT SWAP"
			  << " -------------" << C_RES << std::endl;
	print_vector_inf_ptr(&first);
	print_vector_inf_ptr(&second);
	first.swap(second);
	std::cout << SKY_BLUE << "------------- "
			  << "APRES SWAP"
			  << " -------------" << C_RES << std::endl;
	print_vector_inf_ptr(&first);
	print_vector_inf_ptr(&second);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "assign 1/2"
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<int> fourth;
	fourth.assign(6, 12); // n, val
	print_vector_inf_ptr(&fourth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "assign 2/2"
			  << "  --------------------------" << C_RES << std::endl;
	fourth.assign(first.begin() + 2, first.begin() + 6); // range
	print_vector_inf_ptr(&fourth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "insert 1/3"
			  << "  --------------------------" << C_RES << std::endl;
	print_vector_inf_ptr(&fourth);
	fourth.insert(fourth.begin() + 2, 99); // pos, val
	print_vector_inf_ptr(&fourth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "insert 2/3"
			  << "  --------------------------" << C_RES << std::endl;
	fourth.insert(fourth.begin() + 3, 3, 8); // pos, n, val
											 // fourth.insert(fourth.begin() + 3, -9, 8); // exception
	print_vector_inf_ptr(&fourth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "insert 3/3"
			  << "  --------------------------" << C_RES << std::endl;
	fourth.insert(fourth.begin() + 3, first.begin() + 2, first.begin() + 5); // range
	print_vector_inf_ptr(&fourth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "clear"
			  << "  --------------------------" << C_RES << std::endl;
	first.clear();
	print_vector_inf_ptr(&first);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "swap after clear"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << SKY_BLUE << "------------- "
			  << "AVANT SWAP"
			  << " -------------" << C_RES << std::endl;
	print_vector_inf_ptr(&first);
	print_vector_inf_ptr(&second);
	first.swap(second);
	std::cout << SKY_BLUE << "------------- "
			  << "APRES SWAP"
			  << " -------------" << C_RES << std::endl;
	print_vector_inf_ptr(&first);
	print_vector_inf_ptr(&second);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ELEMENT ACCESS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "at"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << first.at(0) << std::endl;
	std::cout << first.at(2) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "[]"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << first[0] << std::endl;
	std::cout << first[2] << std::endl;
	// std::cout << first[9] << std::endl;   // valgrind
	// std::cout << first[90] << std::endl;  // valgrind
	// std::cout << first[-1] << std::endl;  // valgrind
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "front"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << first.front() << std::endl;
	std::cout << second.front() << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "back"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << first.back() << std::endl;
	// std::cout << second.back() << std::endl;  // valgrind
	// std::cout << first.at(9) << std::endl; // exception	return (0);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ALLOCATOR"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "get_allocator"
			  << "  --------------------------" << C_RES << std::endl;
	NS::vector<int> myvector;
	int *p;
	unsigned int i;
	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);
	// construct values in-place on the array:
	for (i = 0; i < 5; i++)
		myvector.get_allocator().construct(&p[i], i);
	std::cout << "The allocated array contains:";
	for (i = 0; i < 5; i++)
		std::cout << ' ' << p[i];
	std::cout << '\n';
	// destroy and deallocate:
	for (i = 0; i < 5; i++)
		myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p, 5);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "CAPACITY"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "max_size"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << first.max_size() << std::endl;
	std::cout << second.max_size() << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "empty"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << first.empty() << std::endl;
	std::cout << second.empty() << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "resize"
			  << "  --------------------------" << C_RES << std::endl;
	print_vector_inf_ptr(&fourth);
	fourth.resize(15);
	print_vector_inf_ptr(&fourth);
	fourth.resize(6);
	print_vector_inf_ptr(&fourth);
	fourth.resize(0);
	print_vector_inf_ptr(&fourth);
	fourth.resize(8);
	print_vector_inf_ptr(&fourth);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "reserve"
			  << "  --------------------------" << C_RES << std::endl;
	print_vector_inf_ptr(&first);
	first.reserve(13);
	print_vector_inf_ptr(&first);
	first.reserve(79);
	print_vector_inf_ptr(&first);
	first.reserve(80);
	print_vector_inf_ptr(&first);
	first.reserve(81);
	print_vector_inf_ptr(&first);
	first.reserve(45);
	print_vector_inf_ptr(&first);
	first.reserve(0);
	print_vector_inf_ptr(&first);
	// first.reserve(first.max_size() + 1); // 'length_error' exception
	// print_vector_inf_ptr(&first);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ITERATORS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "begin"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << *(first.begin()) << " ";
	std::cout << *(first.begin() + 2) << " ";
	// std::cout << *(first.begin() + 8) << " ";           // valgrind
	// std::cout << *(first.begin() - 1) << std::endl;     // valgrind
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "end"
			  << "  --------------------------" << C_RES << std::endl;
	// std::cout << *(first.end()) << " ";         // valgrind
	// std::cout << *(first.end() + 2) << " ";     // valgrind
	// std::cout << *(first.end() + 8) << " ";     // valgrind
	std::cout << *(first.end() - 1) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "rbegin"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << *(first.rbegin()) << " ";
	std::cout << *(first.rbegin() + 2) << " ";
	// std::cout << *(first.rbegin() + 8) << " ";          // valgrind
	// std::cout << *(first.rbegin() - 1) << std::endl;    // valgrind
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "rend"
			  << "  --------------------------" << C_RES << std::endl;
	// std::cout << *(first.rend()) << " ";                // valgrind
	// std::cout << *(first.rend() + 2) << " ";            // valgrind
	// std::cout << *(first.rend() + 8) << " ";            // valgrind
	std::cout << *(first.rend() - 1) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "all reverse"
			  << "  --------------------------" << C_RES << std::endl;
	{
		NS::vector<int> myvector(5); // 5 default-constructed ints
		NS::vector<int>::reverse_iterator rit = myvector.rbegin();
		int i = 0;
		for (rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
			*rit = ++i;
		std::cout << "myvector contains:";
		for (NS::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "const reverse"
			  << "  --------------------------" << C_RES << std::endl;
	print_vector(&first);
	rprint_vector(&first);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "const iterators"
			  << "  --------------------------" << C_RES << std::endl;
	{
		NS::vector<int>::const_iterator ci = first.begin();
		NS::vector<int>::iterator ni = first.begin();
		for (; ci < first.end(); ci++)
		{
			// *ci += 1;
			std::cout << *ci << " ";
		}
		std::cout << std::endl;
		for (; ni < first.end(); ni++)
		{
			*ni += 1;
			std::cout << *ni << " ";
		}
		std::cout << std::endl;
	}
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "NON-MEMBER"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "swap"
			  << "  --------------------------" << C_RES << std::endl;
	{
		NS::vector<int> foo(3, 100); // three ints with a value of 100
		NS::vector<int> bar(5, 200); // five ints with a value of 200
		NS::vector<int>::iterator it = foo.begin();
		print_vector(&foo);
		std::cout << "*it : " << *it << std::endl;
		foo.swap(bar);
		print_vector(&foo);
		std::cout << "*it : " << *it << std::endl;
		std::cout << "foo contains:";
		for (NS::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "bar contains:";
		for (NS::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "relational =="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first == second) << " ";
	std::cout << (second == second) << " ";
	std::cout << (second == first) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "relational !="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first != second) << " ";
	std::cout << (second != second) << " ";
	std::cout << (second != first) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "relational <"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first < second) << " ";
	std::cout << (second < second) << " ";
	std::cout << (second < first) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "relational <="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first <= second) << " ";
	std::cout << (second <= second) << " ";
	std::cout << (second <= first) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "relational >"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first > second) << " ";
	std::cout << (second > second) << " ";
	std::cout << (second > first) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "relational >="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (first >= second) << " ";
	std::cout << (second >= second) << " ";
	std::cout << (second >= first) << std::endl;
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ITERATORS SWAP"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	NS::vector<int> *first_ptr = &first;
	NS::vector<int> &first_ref = first;
	print_vector(&first);
	NS::vector<int>::iterator it_test = first.begin();
	std::cout << "-------------------- AVANT SWAP --------------------" << std::endl;
	std::cerr << "Adress (first_ptr) : " << first_ptr << std::endl;
	std::cerr << "Adress (first_ref) : " << &first_ref << std::endl;
	std::cerr << "Adress : " << &(*it_test) << std::endl;
	std::cout << "Value : " << *it_test << std::endl;
	first.swap(fifth);
	std::cout << "-------------------- APRES SWAP --------------------" << std::endl;
	std::cerr << "Adress (first_ptr) : " << first_ptr << std::endl;
	std::cerr << "Adress (first_ref) : " << &first_ref << std::endl;
	std::cerr << "Adress : " << &(*it_test) << std::endl;
	std::cout << "Value : " << *it_test << std::endl;
	print_vector(&first);
	first.swap(fifth);
	std::cout << "-------------------- APRES SWAP AGAIN --------------------" << std::endl;
	std::cerr << "Adress (first_ptr) : " << first_ptr << std::endl;
	std::cerr << "Adress (first_ref) : " << &first_ref << std::endl;
	std::cerr << "Adress : " << &(*it_test) << std::endl;
	std::cout << "Value : " << *it_test << std::endl;
	print_vector(&first);
}

void test_map(void)
{
	std::cerr << TEST_COLOUR << "___ TEST STARTS ___ test_map" << C_RES << std::endl;
	typedef NS::map<int, std::string, std::less<int>, std::allocator<NS::pair<const int, std::string> > > map_type;
	typedef NS::map<int, std::string, std::greater<int>, std::allocator<NS::pair<const int, std::string> > > map_type_greater;

	std::cout << "______ make_pair ______" << std::endl;
	NS::pair<int, std::string> pair1 = NS::make_pair(1, "one");
	NS::pair<int, std::string> pair1bis = NS::make_pair(1, "one_bis");
	NS::pair<int, std::string> pair2 = NS::make_pair(2, "two");
	NS::pair<int, std::string> pair3 = NS::make_pair(3, "three");
	NS::pair<int, std::string> pair4 = NS::make_pair(4, "four");
	NS::pair<int, std::string> pair5 = NS::make_pair(5, "five");
	NS::pair<int, std::string> pair6 = NS::make_pair(6, "six");
	NS::pair<int, std::string> pair7 = NS::make_pair(9, "nine");
	NS::pair<int, std::string> pair11 = NS::make_pair(11, "eleven");
	NS::pair<int, std::string> pair34 = NS::make_pair(34, "thirty_four");
	NS::pair<int, std::string> pair99 = NS::make_pair(99, "ninety_nine");

	map_type map_full;
	map_full.insert(pair1);
	map_full.insert(pair2);
	map_full.insert(pair3);
	map_full.insert(pair4);
	map_full.insert(pair5);
	map_full.insert(pair6);
	map_full.insert(pair7);
	map_full.insert(pair11);
	map_full.insert(pair34);
	map_full.insert(pair99);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "BASICS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor 1/3"
			  << "  --------------------------" << C_RES << std::endl;
	map_type map_1;
	std::cout << "____ map_1 ____" << std::endl;
	std::cout << "add second (bool) : " << map_1.insert(pair1).second << std::endl;
	std::cout << "add second (bool) : " << map_1.insert(pair1).second << std::endl;
	std::cout << "add second (bool) : " << map_1.insert(pair1bis).second << std::endl;
	std::cout << "add second (bool) : " << map_1.insert(pair2).second << std::endl;
	std::cout << "add second (bool) : " << map_1.insert(pair3).second << std::endl;
	std::cout << "add second (bool) : " << map_1.insert(pair4).second << std::endl;
	std::cout << "add second (bool) : " << map_1.insert(pair5).second << std::endl;
	std::cout << "first->first (key) : " << map_1.insert(pair6).first->first << std::endl; // should compile when iterator is done
	std::cout << "first->first (key) : " << map_1.insert(pair3).first->first << std::endl; // should compile when iterator is done
	print_map(map_1);
	std::cout << "erase (key) : " << map_1.erase(pair2.first) << std::endl;
	print_map(map_1);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor 2/3"
			  << "  --------------------------" << C_RES << std::endl;
	map_type map_cpy(map_1);
	print_map(map_cpy);
	std::cout << "erase (key) : " << map_cpy.erase(pair1.first) << std::endl;
	print_map(map_1);
	print_map(map_cpy);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "constructor 3/3"
			  << "  --------------------------" << C_RES << std::endl;
	map_type map_range(map_1.begin(), --map_1.end());
	print_map(map_range);
	map_type_greater map_range_greater(map_1.begin(), --map_1.end());
	print_map(map_range_greater);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "operator="
			  << "  --------------------------" << C_RES << std::endl;
	map_type map_eq;
	map_eq = map_range;
	map_eq.clear();
	print_map(map_eq);
	print_map(map_1);
	std::cout << "map_1 size : " << map_1.size() << std::endl;
	std::cout << "map_eq size : " << map_eq.size() << std::endl;

	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "MODIFIERS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	{
		NS::map<char, int> mymap;
		NS::map<char, int>::iterator it2 = mymap.begin();
		NS::map<char, int>::const_iterator it_end = mymap.end();
		NS::map<char, int>::reverse_iterator rit = mymap.rbegin();
		NS::map<char, int>::const_reverse_iterator rit_end = mymap.rend();
		for (; it2 != it_end; it2++)
			std::cout << YELLOW << it2->first << " => " << it2->second << C_RES << std::endl;
		std::cout << YELLOW << "- - - - -" << C_RES << std::endl;
		for (; rit != rit_end; rit++)
			std::cout << YELLOW << rit->first << " => " << rit->second << C_RES << std::endl;
		std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "insert 1/3"
				  << "  --------------------------" << C_RES << std::endl;
		mymap.insert(NS::pair<char, int>('a', 100));
		NS::map<char, int>::iterator it_begin = mymap.begin();
		std::cout << PINK << "it_begin : " << it_begin->first << C_RES << std::endl;
		mymap.insert(NS::pair<char, int>('z', 200));
		std::cout << PINK << "it_begin : " << it_begin->first << C_RES << std::endl;

		NS::pair<NS::map<char, int>::iterator, bool> ret;
		ret = mymap.insert(NS::pair<char, int>('z', 500));
		if (ret.second == false)
		{
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}
		for (; it2 != it_end; it2++)
			std::cout << YELLOW << it2->first << " => " << it2->second << C_RES << std::endl;
		std::cout << YELLOW << "- - - - -" << C_RES << std::endl;
		for (; rit != rit_end; rit++)
			std::cout << YELLOW << rit->first << " => " << rit->second << C_RES << std::endl;
		std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "insert 2/3"
				  << "  --------------------------" << C_RES << std::endl;
		NS::map<char, int>::iterator it = mymap.begin();
		mymap.insert(it, NS::pair<char, int>('b', 300)); // max efficiency inserting
		mymap.insert(it, NS::pair<char, int>('c', 400)); // no max efficiency inserting

		std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "insert 3/3"
				  << "  --------------------------" << C_RES << std::endl;
		NS::map<char, int> anothermap;
		anothermap.insert(mymap.begin(), mymap.find('c'));
		print_map(mymap);
		print_map(anothermap);
	}

	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "erase 1/3"
			  << "  --------------------------" << C_RES << std::endl;
	map_type::iterator it = map_1.begin();
	std::cout << (*it).first << " : " << (*it).second << std::endl;
	map_1.erase(0);
	print_map(map_1);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "erase 2/3"
			  << "  --------------------------" << C_RES << std::endl;
	map_1.erase(map_1.begin());
	// map_1.erase(map_1.end()); // segfault w/ std
	// map_1.erase(map_type::iterator(NULL)); // segfault w/ std
	print_map(map_1);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "erase 3/3"
			  << "  --------------------------" << C_RES << std::endl;
	map_1.erase(map_1.find(4), map_1.find(5));
	print_map(map_1);
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "clear"
			  << "  --------------------------" << C_RES << std::endl;
	map_1.clear();
	map_type map_2;
	map_2.insert(pair3);
	map_2.insert(pair2);
	map_2.insert(pair1);
	map_2.insert(pair4);
	map_type::iterator it2 = map_2.begin();
	map_type::const_iterator it_end = map_2.end();
	map_type::reverse_iterator rit = map_2.rbegin();
	map_type::const_reverse_iterator rit_end = map_2.rend();
	for (; it2 != it_end; it2++)
		std::cout << YELLOW << it2->first << " => " << it2->second << C_RES << std::endl;
	std::cout << YELLOW << "- - - - -" << C_RES << std::endl;
	for (; rit != rit_end; rit++)
		std::cout << YELLOW << rit->first << " => " << rit->second << C_RES << std::endl;
	std::cout << "map_2 size : " << map_2.size() << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "swap"
			  << "  --------------------------" << C_RES << std::endl;
	print_map(map_1);
	print_map(map_2);
	std::cout << SKY_BLUE << "------  " << std::left << std::setw(SW) << "swap 1  ------" << C_RES << std::endl;
	map_1.swap(map_2);
	print_map(map_1);
	print_map(map_2);

	for (; it2 != it_end; it2++)
		std::cout << YELLOW << it2->first << " => " << it2->second << C_RES << std::endl;
	std::cout << YELLOW << "- - - - -" << C_RES << std::endl;
	for (; rit != rit_end; rit++)
		std::cout << YELLOW << rit->first << " => " << rit->second << C_RES << std::endl;
	std::cout << SKY_BLUE << "------  " << std::left << std::setw(SW) << "swap 2  ------" << C_RES << std::endl;
	map_1.swap(map_2);
	print_map(map_1);
	print_map(map_2);
	std::cout << SKY_BLUE << "------  " << std::left << std::setw(SW) << "swap 3  ------" << C_RES << std::endl;
	map_2.swap(map_1);
	print_map(map_1);
	print_map(map_2);
	for (; it2 != it_end; it2++)
		std::cout << YELLOW << it2->first << " => " << it2->second << C_RES << std::endl;
	std::cout << YELLOW << "- - - - -" << C_RES << std::endl;
	for (; rit != rit_end; rit++)
		std::cout << YELLOW << rit->first << " => " << rit->second << C_RES << std::endl;
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "OPERATIONS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "find"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "count"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "lower_bound"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << map_full.lower_bound(0)->first << std::endl;
	std::cout << map_full.lower_bound(1)->first << std::endl;
	std::cout << map_full.lower_bound(2)->first << std::endl;
	std::cout << map_full.lower_bound(28)->first << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "upper_bound"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << map_full.upper_bound(0)->first << std::endl;
	std::cout << map_full.upper_bound(1)->first << std::endl;
	std::cout << map_full.upper_bound(84)->first << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "equal_range"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << map_full.equal_range(0).first->first << std::endl;
	std::cout << map_full.equal_range(30).first->first << std::endl;
	std::cout << map_full.equal_range(99).first->first << std::endl;
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ELEMENT ACCESS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "operator[]"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << map_full[0] << std::endl;
	std::cout << map_full[4] << std::endl;
	std::cout << map_full[40] << std::endl;
	std::cout << map_full[99] << std::endl;
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "RELATIONAL OPERATORS"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	map_type map_empty;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "=="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (map_1 == map_full) << std::endl;
	std::cout << (map_1 == map_1) << std::endl;
	std::cout << (map_1 == map_empty) << std::endl;
	std::cout << (map_empty == map_empty) << std::endl;
	std::cout << (map_empty == map_1) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "!="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (map_1 != map_full) << std::endl;
	std::cout << (map_1 != map_1) << std::endl;
	std::cout << (map_1 != map_empty) << std::endl;
	std::cout << (map_empty != map_empty) << std::endl;
	std::cout << (map_empty != map_1) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "<"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (map_1 < map_full) << std::endl;
	std::cout << (map_1 < map_1) << std::endl;
	std::cout << (map_1 < map_empty) << std::endl;
	std::cout << (map_empty < map_empty) << std::endl;
	std::cout << (map_empty < map_1) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "<="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (map_1 <= map_full) << std::endl;
	std::cout << (map_1 <= map_1) << std::endl;
	std::cout << (map_1 <= map_empty) << std::endl;
	std::cout << (map_empty <= map_empty) << std::endl;
	std::cout << (map_empty <= map_1) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << ">"
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (map_1 > map_full) << std::endl;
	std::cout << (map_1 > map_1) << std::endl;
	std::cout << (map_1 > map_empty) << std::endl;
	std::cout << (map_empty > map_empty) << std::endl;
	std::cout << (map_empty > map_1) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << ">="
			  << "  --------------------------" << C_RES << std::endl;
	std::cout << (map_1 >= map_full) << std::endl;
	std::cout << (map_1 >= map_1) << std::endl;
	std::cout << (map_1 >= map_empty) << std::endl;
	std::cout << (map_empty >= map_empty) << std::endl;
	std::cout << (map_empty >= map_1) << std::endl;
	std::cout << SKY_BLUE << "--------------------------  " << std::left << std::setw(SW) << "all operators"
			  << "  --------------------------" << C_RES << std::endl;
	{
		NS::map<char, int> foo, bar;
		foo['a'] = 100;
		foo['b'] = 200;
		bar['a'] = 10;
		bar['z'] = 1000;

		// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
		if (foo == bar)
			std::cout << "foo and bar are equal\n";
		if (foo != bar)
			std::cout << "foo and bar are not equal\n";
		if (foo < bar)
			std::cout << "foo is less than bar\n";
		if (foo > bar)
			std::cout << "foo is greater than bar\n";
		if (foo <= bar)
			std::cout << "foo is less than or equal to bar\n";
		if (foo >= bar)
			std::cout << "foo is greater than or equal to bar\n";
	}
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "REVERSE ITERATOR"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	print_map(map_full);
	rprint_map(map_full);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "get_allocator"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	{
		int psize;
		NS::map<char, int> mymap;
		NS::pair<const char, int> *p;

		// allocate an array of 5 elements using mymap's allocator:
		p = mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(NS::map<char, int>::value_type) * 5;
		std::cout << "The allocated array has a size of " << psize << " bytes.\n";
		mymap.get_allocator().deallocate(p, 5);
	}
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ALLOCATOR"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;

	NS::map<char, int> map_A;
	NS::map<std::string, std::string> map_B;

	NS::pair<const char, int> *p_A;
	NS::pair<const std::string, std::string> *p_B;

	int psize_A;
	int psize_B;

	p_A = map_A.get_allocator().allocate(5);
	p_B = map_B.get_allocator().allocate(5);

	psize_A = sizeof(NS::map<char, int>::value_type) * 5;
	psize_B = sizeof(NS::map<std::string, std::string>::value_type) * 5;

	std::cout << "The allocated array has a size of " << psize_A << " bytes.\n";
	std::cout << "The allocated array has a size of " << psize_B << " bytes.\n";

	map_A.get_allocator().deallocate(p_A, 5);
	map_B.get_allocator().deallocate(p_B, 5);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "COMPARE FUNCTION"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	NS::map<int, std::string, std::greater<int>, std::allocator<NS::pair<const int, std::string> > > map_greater;
	map_greater.insert(pair1);
	map_greater.insert(pair2);
	map_greater.insert(pair4);
	map_greater.insert(pair11);
	map_greater.insert(pair3);
	map_greater.insert(pair6);
	map_greater.insert(pair7);
	map_greater.insert(pair99);
	map_greater.insert(pair5);
	map_greater.insert(pair34);
	print_map(map_greater);
	rprint_map(map_greater);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ITERATOR SWAP"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	print_map(map_1);
	map_type::iterator it_test = map_1.begin();
	std::cout << "-------------------- AVANT SWAP --------------------" << std::endl;
	std::cerr << "Adress : " << &(*it_test) << std::endl;
	std::cout << "Value : " << it_test->second << std::endl;
	map_1.swap(map_full);
	std::cout << "-------------------- APRES SWAP --------------------" << std::endl;
	std::cerr << "Adress : " << &(*it_test) << std::endl;
	std::cout << "Value : " << it_test->second << std::endl;
	print_map(map_1);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ITERATOR INSERT"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	NS::pair<int, std::string> pair8 = NS::make_pair(8, "eight");
	std::cout << "-------------------- AVANT INSERT --------------------" << std::endl;
	std::cerr << "Adress : " << &(*it_test) << std::endl;
	std::cout << "Value : " << it_test->second << std::endl;
	map_1.insert(pair8);
	std::cout << "-------------------- APRES INSERT --------------------" << std::endl;
	std::cerr << "Adress : " << &(*it_test) << std::endl;
	std::cout << "Value : " << it_test->second << std::endl;
	print_map(map_1);
	std::cout << SKY_BLUE << "[[[[[[[[[[[[[[[[[[[[[[[[[[  " << std::left << std::setw(SW) << "ITERATOR DELETE"
			  << "  ]]]]]]]]]]]]]]]]]]]]]]]]]]" << C_RES << std::endl;
	map_1.erase(5);
	std::cout << "-------------------- APRES ERASE --------------------" << std::endl;
	std::cerr << "Adress : " << &(*it_test) << std::endl;
	std::cout << "Value : " << it_test->second << std::endl;
	print_map(map_1);
}

int main(void)
{
#if VAR_STACK
	test_stack();
	test_stack_with_stl_containers();
#elif VAR_VECTOR
	test_vector();
	test_vector_str();
#elif VAR_MAP
	test_map();
#else
	test_stack();
	test_stack_with_stl_containers();
	test_vector();
	test_vector_str();
	test_map();
#endif
	return (0);
}
