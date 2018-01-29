#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <string>
#include <cctype>
using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    stringstream ss(rawWords);
    string toString;
    string word;
    set<string> wordset;
    while (ss>>toString){
        stringstream charConv;
        char ch;
        charConv<<toString;
        word="";
        //get one word
        while (charConv>>ch){
            //ispunct comes with cctype library to check punctuation
            if (ispunct(ch)){
                 if (word.size()>=2){
                    word=trim(word);
                    word=convToLower(word);
                    wordset.insert(word);
                    word="";
                }
            }
            if (!ispunct(ch)){
                word=word+ch;
            }
        }

        if (word.size()>=2){
                word=trim(word);
                word=convToLower(word);
                wordset.insert(word);
        }
    }
    return wordset;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
