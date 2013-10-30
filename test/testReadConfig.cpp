#include "readConfig.h"
#include <iostream>
using namespace std;

void testReadConfig();
void checkMetaCache();
void checkGradeCache();

int main(void)
{
	testReadConfig();
	return 0;
}

void checkGradeCache()
{
	if( GRADE_CH.size() == 6 )
	{
		cout << "GRADE_CACHE Size check case - Pass" << endl;
	}
	else
	{
		cout << "GRADE_CACHE Size check case - Fails" << endl;
		return;
	}
	map<char,Bounds>::iterator itr;
	for( itr = GRADE_CH.begin() ; itr != GRADE_CH.end() ; itr++ )
	{
		cout << "GRADE : " << itr->first << endl;
		if( itr->second.lbEq )
			cout << "LB >= " << itr->second.lb << endl;
		else
			cout << "LB > " << itr->second.lb << endl;
		if( itr->second.ubEq )
			cout << "UB <= " << itr->second.ub << endl;
		else
			cout << "UB < " << itr->second.ub << endl;
	}
	cout << " Is content are OK ! (y|n) :" ;
	char yn;
	cin >> yn;
	if( yn == 'y' )
		cout << "Grade cache content test pass" << endl;
	else
		cout << "Grade cache content test fails" << endl;
}
void checkMetaCache()
{
	cout << "--------------------" << endl;
	cout << "Check for size .... " << endl;
	cout << "--------------------" << endl;
	if( META_CH.size() == 4 )
	{
		cout << "META_CACHE Size check case - Pass" << endl;
	}
	else
	{
		cout << "META_CACHE Size check case - Fails" << endl;
		return;
	}
	map<string,string>::iterator itr;
	for( itr = META_CH.begin() ; itr != META_CH.end() ; itr++ )
	{
		cout << "TableName : " << itr->first << endl;
		cout << "FileName  : " << itr->second<< endl;
	}
	cout << " Is content are OK ! (y|n) :" ;
	char yn;
	cin >> yn;
	if( yn == 'y' )
		cout << "Meta cache content test pass" << endl;
	else
		cout << "Meta cache content test fails" << endl;

}

void testReadConfig()
{
	cerr_t res = readConfig();
	if( res != CONF_NO_ERR )
	{
		cout << "Reading Cofiguration fails!" << endl;
		cout << res << endl;
	}
	else
	{
		cout << "Reading Cofiguration Pass :)" << endl;
		cout << "----------------------------" << endl;
		cout << " Test Meta Cache " << endl;
		cout << "----------------------------" << endl;
		checkMetaCache();	
		checkGradeCache();
		cout << "----------------------------" << endl;
		
	}
}
