#include "Vector.hpp"
#include "iterator.hpp"
#include "const_iterator.hpp"
#include "Utility.hpp"
#include <typeinfo>     // typeid
int main()
{
	using namespace std;

	// std::vector<int> v, v1;
	// v.insert(v.begin(), 10);//n, v
	// cout << v.capacity() << endl;
	// v.insert(v.begin(), 10);//n, v
	// cout << v.capacity() << endl;
	// v.insert(v.begin(), 10, 1);//n, v
	// cout << v.capacity() << endl;
	// v1.insert(v1.begin(), v.begin(), v.begin() + 1 );
	// cout << "----" << v1.capacity() << endl;
//	v1.insert(v1.begin(), v.begin(), v.end());
	// for(int i = 0;i < 13; i++)
	// {	v1.insert(v1.begin(), 1);
	// 	cout << v1.capacity() << endl;}
	// ft::Vector<int> v1(v.begin()+1, v.end());
	// ft::Vector<int> v2(v1);
	// ft::Vector<int>::const_iterator c_it = v1.begin();
	// ft::Vector<int>::iterator it = v2.begin();
	// cout << it - c_it;

	//std::vector<int> v3(v.begin()+1, v.end());
	// std::vector<int> v4(v3);
//	std::vector<int>::const_iterator c_itt = v3.begin();
	// std::vector<int>::iterator itt = v3.begin();


	//ft::Vector<int> v3;
//	v3.insert(1 + v3.begin() , v.begin(), v.end());
//	cout << *(v3.begin() + 1) << "\n";
//	ft::Vector<int> v4(v3);
	//ft::Vector<int>::const_iterator c_it = v3.begin();
	// while (it < v4.end())
	// 	cout << " " << *it++ << ", ";

//	ft::Vector<int> myvector(v.begin(), v.end());
	// ft::Vector<int> myvector1(myvector);
//
	//ft::Vector<int> myvector2(4, 100);
	// ft::Vector<int>::iterator it;
	// int arr[3] = {1,2,3};
	// it = myvector.begin();
	// myvector.insert ( it , v.begin(), v.end() );
	// it = myvector.begin();
	// it = myvector.insert ( it , 200 );
	// cout << *it << " cap is " << myvector.capacity() << "\n";
	// vector<int> real_v;
	// // v.push_back(1);
	// // v.push_back(2);
	// // cout << "The vector v contains elements:";
	// ft::Vector<int>::const_iterator v_cIter;
	// v_cIter = myvector.begin();
    // while (it < myvector.end())
    //     cout << " " << *it++ << ", ";



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



//    c1.push_back(2);    c1.push_back(77);     c1.push_back(40);
//	c1.push_back(12071);
//	c1_Iter = c1.begin();
//	c1.insert (c1_Iter + 1, 2, 200 );
//	for (c1_Iter = c1.begin(); c1_Iter < c1.end(); c1_Iter++)
//		std::cout << ' ' << *c1_Iter <<  " ";
//	std::cout << "\n capacity " << c1.capacity() <<  " ";


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

	typedef ft::iterator_traits<int*> traits;
	if (typeid(traits::iterator_category)==typeid(ft::RandomAccessIteratorTag))
		std::cout << "int* is a random-access iterator";
  return 0;

}
