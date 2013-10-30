#include "menu.h"
#include <iostream>
using namespace std;

void testMenu();
void checkMenuMetaCache();

int main(void)
{
	testMenu();
	return 0;
}

void testMenu()
{
	merr_t res = loadConfig('c');
	if( res != MENU_NO_ERR )
	{
		cout << "Cacheing menu fails!" << endl;
		cout << res << endl;
	}
	else
	{
		cout << "Cacheing menu pass!" << endl;
		showMainMenu();
		return;
	}
}
