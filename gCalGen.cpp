/*############################################################################################
#	File Name     : gCalGen.cpp  
#	Description   : Implementation of tokens/prototype for reading configuration files.
#	Create Date   : 26-Oct-2013
#	Modified Date : 27-Oct-2013
#	Authour       : Girisha Narayana ( girishanayak )
#	Modifier      : Girisha Narayana ( girishanayak )
#	Vesrion       : 1.0.1
#	Case Study    : gcal ( case-00 )
#	Email Id      : gnarayana77.dev.gyana@gmail.com ( Author )
#	Email Id      : gnarayana77.dev.gyana@gmail.com ( Modifier )
#
###############################################################################################
*/

#include "gCalGen.h"
#include <iostream>

/*Tokenizer take the given line as input  and converts them into series of tokens .In this we 
  used "|"(pipe) as delimeter,which converts string into substring.If we use other than the 
  given delimeter it results whole string as an single token.  
 */

vector<string> Tokenizer(const string& line,const string& delim)
{
	vector<string> tokens;
	size_t spos=0;
	size_t epos=0;
	string tline = line;
	while( epos!= string::npos)
	{
		epos = 0;
		epos=tline.find_first_of(delim);
		string tok=tline.substr(spos,epos);
		tokens.push_back(tok);
		tline=tline.substr(epos+1);
	}
	return tokens;
}
