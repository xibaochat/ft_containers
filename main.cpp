#include "Vector.hpp"
#include "iterator.hpp"
#include "const_iterator.hpp"
#include "Utility.hpp"

int main()
{
	using namespace std;
	ft::Vector<int> v;
	vector<int> real_v;
	// v.push_back(1);
	// v.push_back(2);
	// cout << "The vector v contains elements:";
	// ft::Vector<int>::const_iterator v_cIter;
	// v_cIter = v.begin();
	// std::cout << *v_cIter << " " << *v.begin() << "\n";

	int foo [5] = { 1, 2, 77, 40, 12071 };
	ft::Vector<int>::iterator it;
	v._arr = foo;
	v._len = 5;
	v._cap = 8;
//	v.resize(19);
	it = v.begin();
	v.insert ( it + 1 , 2, 200 );
	for (it=v.begin(); it<v.end(); it++)
		std::cout << ' ' << *it <<  " ";
	cout << "\n";

	// cout << "mine cap " << v.capacity() << " size " << v.size() << endl << "ele are \n";
	// for (size_t i = 0; i < v.size(); ++i)
	// 	cout << v[i] << "; ";

	// try
	// {
	// 	int const a = v.at(1);
	// 	cout <<  "v[2] " << a  << "\n";
	// }
	// catch (const out_of_range& oor) {
	// 	std::cerr << "Out of Range error: " << oor.what() << '\n';
	// }
    vector<int> c1;
vector<int> c2(c1);
    vector<int>::iterator c1_Iter;
    vector<int>::const_iterator c1_cIter;

    c1.push_back(1);
    c1.push_back(2);    c1.push_back(77);     c1.push_back(40);
	c1.push_back(12071);
	c1_Iter = c1.begin();
	c1.insert (c1_Iter + 1, 2, 200 );
	for (c1_Iter = c1.begin(); c1_Iter < c1.end(); c1_Iter++)
		std::cout << ' ' << *c1_Iter <<  " ";


    // cout << "The vector c1 contains elements:";
    // c1_Iter = c1.begin();
    // for (; c1_Iter != c1.end(); c1_Iter++)
    // {
    //     cout << " " << *c1_Iter;
    // }
    // cout << endl;

    // cout << "The vector c1 now contains elements:";
    // c1_Iter = c1.begin();
    // *c1_Iter = 20;
    // for (; c1_Iter != c1.end(); c1_Iter++)
    // {
    //     cout << " " << *c1_Iter;
    // }
    // cout << endl;
	// c1_cIter = c1.begin();
	// cout << " " << *c1_cIter;
    // The following line would be an error because iterator is const
//    *c1_cIter = 200;















}
