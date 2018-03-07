#include "Lists/SimpleList.h"
#include <iostream>

using namespace std;
int main(){

	SimpleList list;

	list.AddEnd(54);
	list.AddEnd(476);
	list.AddEnd(87);
	list.AddEnd(523);

	list.AddStart(43);
	list.AddStart(443);
	list.AddStart(54);
	list.AddStart(456);
	

	list.toString();

	/*list.AddPosition(00, 0);
	list.AddPosition(00, 1);
	list.AddPosition(00, 7);
	list.AddPosition(00, 4);*/
	/*SimpleList delList;

	delList.AddStart(45);
	delList.AddStart(65);
	delList.AddStart(23);

	//DEletes with elm
	delList.DelStart();
	delList.DelEnd();

	//DEletes wit one elm
	delList.DelStart();

	delList.AddStart(12);
	delList.DelEnd();*/

	/*list.DelPosition(4);
	list.DelPosition(0);
	list.DelPosition(5);*/

	list.EditPosition(98, 0);
	list.EditPosition(98, 5);
	list.EditPosition(98, 2);
	list.EditPosition(98, 7);

	list.toString();

}