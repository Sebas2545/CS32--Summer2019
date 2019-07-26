#include <string>
#include <iostream>

int prod(unsigned int m, unsigned int n) {
	if(n == 0)
		return 0;

    return m + prod(m, n - 1);
}

int numberOfDigits(int num, int digit) {
	if(num == 0)
		return 0;

	if((num - digit) % 10 == 0)
		return 1 + numberOfDigits(num/10, digit);
	else
		return numberOfDigits(num/10, digit);

	throw std::logic_error("End of Function w/o Return");
}

std::string doubleDouble(std::string n) {

	if (n.length() == 0) {
		return "";
	}
	else if(n[0] == n[1]) {
		std::string str(1, n[0]);
		return str + "22" + doubleDouble(n.erase(0,1));
	}
	else {
		std::string str(1, n[0]);
		return str + doubleDouble(n.erase(0,1));
	}

	throw std::logic_error("Sad Boy Days");
}

std::string curlyFries(std::string str) {
	if(str.front() != '{')
		return curlyFries(str.erase(0,1)); // remove chars from front
	else if(str.back() != '}')
		return curlyFries(str.erase(str.length() - 1, 1)); //remove chars from back

	return str;
}

bool addEmUp(const int a[], int size, int target) {
	if(target == 0)
		return true;
	if(size <= 0)
		return false;

	bool bA;
	bool bB;

	bA =  addEmUp(a + 1, size - 1, target - a[0]);

	bB = addEmUp(a + 1, size - 1, target);

	if(bA || bB)
		return true;
	return false;
}

bool canWeFinish(std::string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
	bool bA, bB, bC, bD, bE;
	bA = bB = bC = bD = bE = false;

	maze[sr][sc] = '#';
	if(sr == er && sc == ec)
		bA = true;
	if(maze[sr - 1][sc] == '.')
		bB = canWeFinish(maze, nRows, nCols, sr - 1, sc, er, ec);
	if(maze[sr + 1][sc] == '.'	)
		bC = canWeFinish(maze, nRows, nCols, sr + 1, sc, er, ec);
	if(maze[sr][sc - 1] == '.')
		bD = canWeFinish(maze, nRows, nCols, sr, sc - 1, er, ec);
	if(maze[sr][sc + 1] == '.')
		bE = canWeFinish(maze, nRows, nCols, sr, sc + 1, er, ec);

	return (bA || bB || bC || bD || bE);
}
