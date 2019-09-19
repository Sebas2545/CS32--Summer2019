#include <iostream>
#include <string>
#include <fstream>

const int MAXRESULTS = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

void pLoop(int, int, std::string, std::string, const std::string [], int, std::string [], int&);
bool helperFindAnagram(const std::string arr[], int size, std::string target);

int helperLoadDict(std::istream &dictfile, std::string dict[], int size) {
	if(size >= MAXDICTWORDS)
		return 0;
	if(dictfile.eof())
		return 0;

	dictfile >> dict[0];
	return 1 + helperLoadDict(dictfile, dict + 1, size + 1);
}

int loadWords(std::istream &dictfile, std::string dict[]) {
	return helperLoadDict(dictfile, dict, 0);
}

void getPermutations(std::string prefix, std::string rest, const std::string dict[], int sizeDict, std::string results[], int& sizeResults) {
	if (rest.size() == 0) {
		if(helperFindAnagram(dict, sizeDict, prefix)) //if it IS in dict
			if(!helperFindAnagram(results, sizeResults, prefix)) { // if it is NOT in results
				results[sizeResults] = prefix; // add it to results
				++sizeResults;
			}
		return;
	}

	pLoop(0, rest.size(), prefix, rest, dict, sizeDict, results, sizeResults);

}

void pLoop(int i, int max, std::string prefix, std::string rest, const std::string dict[], int sizeDict, std::string results[], int& sizeResults) {
	if(i == max)
		return;

	getPermutations(prefix + rest[i], rest.substr(0, i) + rest.substr(i + 1), dict, sizeDict, results, sizeResults);
	pLoop(i + 1, max, prefix, rest, dict, sizeDict, results, sizeResults);

}

bool helperFindAnagram(const std::string arr[], int size, std::string target) {
	if(size == 0)
		return false;
	if(arr[0] == target)
		return true;

	return helperFindAnagram(arr + 1, size - 1, target);
}

int recBlends(std::string word, const std::string dict[], int size, std::string results[]) {

	int sizeResults = 0;
	getPermutations("", word, dict, size, results, sizeResults);

	return sizeResults;
}

void showResults(const std::string results[], int size) {
	if(size == 0)
		return;

	std::cout << results[0] << std::endl;
	return showResults(results + 1, size - 1);
}

int main() {
	std::string results[MAXRESULTS];
	std::string dict[MAXDICTWORDS];
	std::ifstream dictfile;         // file containing the list of words
	int nwords;                // number of words read from dictionary
	std::string word;

	dictfile.open("dict.txt");
	if (!dictfile) {
		std::cout << "File not found!" << std::endl;
		return (1);
	}

	nwords = loadWords(dictfile, dict);

	std::cout << "Please enter a string for an anagram: ";
	    std::cin >> word;

	    int numMatches = recBlends(word, dict, nwords, results);
	    if (!numMatches)
	        std::cout << "No matches found" << std::endl;
	    else
	        showResults(results, numMatches);

	return 0;
}
