/* Based upon first homework assignment for CS32--Summer Quarter; UCLA
 *  Created on: Jul 8, 2019
 *  Author: Sebastian Gonzalez
 */

#include "LinkedList.h"

int main() {
	LinkedList list;
	list.insertToFront("1");
	list.insertToFront("2");
	list.insertToFront("3");
	list.insertToFront("4");

	list.printReverse();


	return 0;
}


