#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include "../includes/constants.h"
#include "../includes/array_functions.h"
#include "../includes/utilities.h"


namespace KP{
	//remove all elements from vector that tracks words and their occurrences
	void clear(std::vector<constants::entry>  &entries){
		entries.clear();

	}

	//return how many unique words are in the vector
	int getSize(std::vector<constants::entry>  &entries) {
		return entries.size();
	}

	//get word at location i iff i<size(see above function), otherwise return the last word
	//(this is lazy, should throw an exception instead)
	std::string getWordAt(std::vector<constants::entry>  &entries, int i) {
		return entries[i].word;
	}

	//get number_occurences at location i iff i<size(see above function), otherwise return the last number_occurences
	//(this is lazy, should throw an exception instead)
	int getNumbOccurAt(std::vector<constants::entry>  &entries,int i) {
		return entries[i].number_occurences;
	}

	/*loop through the entire file, one line at a time
	 * call processLine on each line from the file
	 * returns false: myfstream is not open
	 *         true: otherwise*/
	bool processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream) {
			std::string str;
			if (!myfstream.is_open()){
				return false;
			}
			while (getline(myfstream, str)){
				processLine(entries, str);
			}
			return true;
	}

	/*take 1 line and extract all the tokens from it
	feed each token to processToken for recording*/
	void processLine(std::vector<constants::entry>  &entries,std::string &myLine) {
		std::stringstream ss(myLine);
		std::string tempToken;

		while (getline(ss, tempToken, constants::CHAR_TO_SEARCH_FOR)) {
			processToken(entries, tempToken);
		}
	}

	/*NOTE: first call strip_unwanted_chars from utilities to get rid of rubbish chars in the token
	 * if the token is an empty string after this then return since we are not tracking empty strings
	 *
	 * Keep track of how many times each token seen, in other words look thru the entries vector that
	 * holds entry structs to see if there is a struct that has entry.word==token,
	 * if so increment entry.number_occurences, otherwise create a new entry struct for the token,
	 * set entry.number_occurences=1 and add it to the entries vector*/
	void processToken(std::vector<constants::entry>  &entries,std::string &token){
		//calling unwanted chars and stripping
		if (!strip_unwanted_chars(token)) {
			return; //if token is an empty string
		}

		//upper token time!
		std::string upper_token = token;
		toUpper(upper_token);

		int index = -1;
		for (unsigned int i=0; i<entries.size(); i++) {
			if (entries[i].word_uppercase==upper_token) {
				index = i;
				break;
			}
		}

		if (index==-1) {
			constants::entry new_entry={token, upper_token, 1};
			entries.push_back(new_entry);
		}
		//incrementing number of occurrences by 1
		else {
			entries[index].number_occurences += 1;
		}

	}
	//sorting
	bool compareAsc(constants::entry &a, constants::entry &b) {
		return a.word_uppercase < b.word_uppercase;
	}
	bool compareDec(constants::entry &a, constants::entry &b) {
		return a.word_uppercase > b.word_uppercase;
	}
	bool compareNum(constants::entry &a, constants::entry &b) {
		return a.number_occurences > b.number_occurences;
	}


	void sort(std::vector<constants::entry>  &entries, constants::sortOrder so) {
		if (so==constants::NONE) {
			return;
		}
		if (so==constants::ASCENDING) {
			sort(entries.begin(), entries.end(), compareAsc);
		}
		if (so==constants::DESCENDING) {
			sort(entries.begin(), entries.end(), compareDec);
		}
		if (so==constants::NUMBER_OCCURRENCES) {
			sort(entries.begin(), entries.end(), compareNum);
		}
	}
}
