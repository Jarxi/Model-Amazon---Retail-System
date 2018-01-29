#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
using namespace std;

class Book: public Product{
public:
	Book(const std::string category, const std::string name, double price, int qty,
	string ISBN, string author);
	std::set<std::string> keywords() const;
	bool isMatch(std::vector<std::string>& searchTerms) const;
	std::string displayString() const;
	void dump(std::ostream& os) const;
	std::string getSpecialInfo1() const;
	std::string getSpecialInfo2() const;
private:
	string ISBN_;
	string author_;
};


#endif