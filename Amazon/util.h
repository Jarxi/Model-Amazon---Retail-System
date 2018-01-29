#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates  
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{

	typename std::set<T> s3;
	typename std::set<T>::iterator it2=s2.begin();
	typename std::set<T>::iterator it1;
	for (; it2!=s2.end(); ++it2){
		it1=s1.find(*it2);
		if (it1!=s1.end()){
			s3.insert(*it2);
		}
	}
	return s3;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
	typename std::set<T>::iterator it2=s2.begin();
	typename std::set<T>::iterator it1;
	for (; it2!=s2.end(); ++it2){
		it1=s1.find(*it2);
		if (it1==s1.end()){
			s1.insert(*it2);
		}
	}
	return s1;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// trim from start
std::string &ltrim(std::string &s) ;

// trim from end
std::string &rtrim(std::string &s) ;

// trim from both ends
std::string &trim(std::string &s) ;
#endif
