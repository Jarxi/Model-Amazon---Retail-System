#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"


class Movie: public Product{
public:
	Movie(const std::string category, const std::string name, double price, int qty,
	std::string genre, std::string rating);
	std::set<std::string> keywords() const;
	std::string displayString() const;
	bool isMatch(std::vector<std::string>& searchTerms) const;
	void dump(std::ostream& os) const;
	std::string getSpecialInfo1() const;
	std::string getSpecialInfo2() const;

private:
	std::string genre_;
	std::string rating_;
};


#endif