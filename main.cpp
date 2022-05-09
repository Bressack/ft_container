#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include "container_stn/map/map.hpp"
#include <cstdlib>
#include <ctime>

#ifndef NS
# define NS std
#endif

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


typedef NS::map<int,long> map;
typedef NS::pair<int,long> keyval;

int main(void)
{
	srand(time(NULL));
	
	map m;


	for (size_t i = 0; i < 30000; i++)
	{
		keyval kv(rand(), rand() * 1E4 + rand());
		m.insert(kv);
	}

	std::cout << m.size() << std::endl;

	// print_map(m);

	return 0;
}
