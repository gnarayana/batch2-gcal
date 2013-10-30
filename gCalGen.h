/*
	File Name     : readConfig.h 
	Description   : Header file declares tokens/prototype for reading configuration files.
	Create Date   : 26-Oct-2013
	Modified Date : 27-Oct-2013
	Authour       : Girisha Narayana ( girishanayak )
	Modifier      : Girisha Narayana ( girishanayak )
	Vesrion       : 1.0.1
	Case Study    : gcal ( case-00 )
	Email Id      : gnarayana77.dev.gyana@gmail.com ( Author )
	Email Id      : gnarayana77.dev.gyana@gmail.com ( Modifier )

*/
#ifndef _GCAL_GEN_H_
#define _GCAL_GEN_H_

#include<string>
#include<vector>

using namespace std;


vector<string> Tokenizer(const string& line,const string& delim);

#endif
