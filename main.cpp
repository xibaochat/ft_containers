#include "vector.hpp"
#include "iterator.hpp"
#include "const_iterator.hpp"
#include "Utility.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"

int main()
{
	using namespace std;
	std::vector<int> v, v1;
	ft::vector<int> v3;
	v.insert(v.begin(), 5, 42);//n, v
	v3.insert(v3.begin(), 5, 42);//n, v
	std::cout <<  (v.end() - v.begin()) << "\n" << (v3.end() - v3.begin());
//	std::cout <<  *(v.end() - 1) << "\n" << *(v3.end() - 1);

	// try
	// {
	// 	int const a = v.at(1);
	// 	cout <<  "v[2] " << a  << "\n";
	// }
	// catch (const out_of_range& oor) {
	// 	std::cerr << "Out of Range error: " << oor.what() << '\n';
	// }
    // vector<int> c1(3, 100);
	// vector<int> c2(c1);
    // vector<int>::iterator c1_Iter;
    // vector<int>::const_iterator c1_cIter;
	// c1_Iter = c1.begin();
	// c1_Iter = c1.insert ( c1_Iter , 200 );
	// c1_Iter = c1.begin();
	// c1_Iter = c1.insert ( c1_Iter , 200 );
	//std::cout << "\n capacity " << c1.capacity() <<  " ";

//	std::cout << "\n capacity " << c1.capacity() <<  " ";




  return 0;

}
