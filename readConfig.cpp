/*#######################################################################################
#	File Name     : readConfig.cpp 
#	Description   : Implementation of interfaces/protype of reading configuration files.
#	Create Date   : 19-Oct-2013
#	Modified Date : 26-Oct-2013
#	Authour       : Girisha Narayana ( girishanayak )
#	Modifier      : Chethan S ( chethans )
#	Vesrion       : 1.0
#	Case Study    : gcal ( case-00 )
#	Email Id      : gnarayana77.dev.gyana@gmail.com ( Author )
#	Email Id      : chethans.dev.gyana@gmail.com ( Modifier )
###########################################################################################
*/
#include "gCalGen.h"
#include "readConfig.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

 /*
		Reads the GradeTable ( gCalGradeTable.config )  line by line 
		Tokenize the line using Pipe as delimeter.==>{ A|=90|=100 }
  */
 cerr_t procGradeLine(const string& line) 
 {
		vector<string> toks = Tokenizer(line,"|");
		char key = toks[0].at(0);
		Bounds value; 
		if( toks[1].find("=") != string::npos)
		{
			value.lbEq=true;	
			cout << toks[1] << endl;
			value.lb= (short)atoi((toks[1].substr(1)).c_str());
		}
		else 	
		{
			value.lbEq=false;	
			value.lb= (short)atoi(toks[1].c_str());
		}

		if( toks[2].find("=") != string::npos)
		{
			value.ubEq=true;	
			value.ub= (short)atoi((toks[2].substr(1)).c_str());
		}
		else 	
		{
			value.ubEq=false;	
			value.ub= (short)atoi(toks[2].c_str());
		}

		GRADE_CH[key] =value;
		return CONF_NO_ERR; 
 }

/*
		Reads the MsgTable ( gCalMsgTable.config )  line by line 
		Tokenize the line using Pipe as delimeter.==>{ A|a|GOOD } 
*/
 cerr_t procMsgLine(const string& line) 
 {
	
		vector<string> toks = Tokenizer(line,"|"); 
		string key = toks[0] + "|" + toks[1];
		string value = toks[2];
		MSG_CH[key]	= value;
		return CONF_NO_ERR; 
 }

/*
		Reads the SemScore ( gCalSemScoreTable.config )  line by line 
		Tokenize the line using Pipe as delimeter.==>{ BE|1|700 } 
*/
 cerr_t procScoreLine(const string& line) 
 {
		vector<string> toks = Tokenizer(line,"|"); 
		string key = toks[0];			
		short in_key = 0;
	   SemScore value;
		if( toks[1] != "a" )	
		{
			in_key = (short)atoi(toks[1].c_str());	
		}
		short in_value= (short)atoi(toks[2].c_str());

	   //SemScore value;
		if( SEM_SCORES_CH.find(key) == SEM_SCORES_CH.end() )
		{
			value[in_key] = in_value;
		}
		else
		{
			value = SEM_SCORES_CH[key];
			value[in_key] = in_value;
		}
		SEM_SCORES_CH[key] =   value;
		return CONF_NO_ERR; 
 }

/*
		Reads the CourseTable ( gCalCrsSemTable.config )  line by line 
		Tokenize the line using Pipe as delimeter ==> { MTECH|4 }
*/

 cerr_t procCourseLine(const string& line) 
 {
		vector<string> toks = Tokenizer(line,"|"); 
		string key = toks[0];
		short value = (short)atoi(toks[1].c_str());
	
		CRS_CH[key] =value;
		return CONF_NO_ERR; 
 }
 /*
	Reads the meta cache file (gcal.Meta) which contians table name and file name.
  */
 cerr_t procAllConfigTableFiles() 
 {
	map<string,string>::iterator itr; 	
   cerr_t res = CONF_NO_ERR;
	for( itr = META_CH.begin(); itr != META_CH.end() ; itr++ ) 
	{
		string fileName =  GCAL_CONF_PATH + "/" + itr->second; 	
		string tableName = itr -> first;
		if( tableName == "gradeTable")
		{
			res = readConfigFile(fileName,procGradeLine);
		}
		else if (tableName == "msgTable" )
		{
			res = readConfigFile(fileName,procMsgLine);
		}
		else if (tableName == "semScoreTable" )
		{
			res = readConfigFile(fileName,procScoreLine);
		}
		else if (tableName == "courseSem" )
		{
			res = readConfigFile(fileName,procCourseLine);
		}
		if( res != CONF_NO_ERR )
				break;
	}
	return res; 
 }
/*
reads the meta file which is table name and file name separated by :
 */
cerr_t procMetaLine(const string& line) 
{
	vector<string> toks = Tokenizer(line,":");
	string metaKey = toks[0] ;//metaKey -> table name
	string metaValue = toks[1] ;//metaValue->file name
	META_CH[metaKey] =metaValue;
	return CONF_NO_ERR; 
}

/*
	
	
*/
cerr_t readConfigFile(const string& fileName,cerr_t (*procConfigLine)(const string& line)) 
{
	ifstream ifile(fileName.c_str());
	cerr_t res = CONF_NO_ERR;
	if( ifile.is_open() )
	{
		string line;
		while( !ifile.eof() )
		{
			getline(ifile,line);
			if( line.size() > 0 && line.at(0) != '#' )
			 res = procConfigLine(line);
			if( res != CONF_NO_ERR )
			{
				return res;
			}
		}
	}
	else
	{
	   res = CONF_FILE_OPEN_ERR;  
	}
	ifile.close();
	return res; 
}

/*
  The readConfigPath fuction checks for the path existane
 */
cerr_t readConfigPath()
{
	const char* configPath = getenv("GCAL_CONF_PATH"); 

	if( configPath != NULL )
	{
		GCAL_CONF_PATH = configPath;
	}
   /*
	cerr_t res = checkConfPath(configPath);  //TO DO

	if( res != PATH_EXIST) 
	{
		return CONF_PATH_ERR;
	}
	cerr_t res = checkConfPathAccess(configPath);  // TO DO

	if( res != PATH_ACCESS_NO_ERR  ) 
	{
		return CONF_PATH_ACCESS_ERR;
	}
	*/
	return CONF_NO_ERR; 

}

/*
readConfig function checks the path and stores in a string(metaFile)
 */
cerr_t readConfig()
{
	cerr_t res = readConfigPath();	
	if( res != CONF_NO_ERR ) 
	{
		return res;	}

	string metaFile = GCAL_CONF_PATH + "/gcal.meta";
	res = readConfigFile(metaFile,procMetaLine);
	if( res != CONF_NO_ERR ) 
	{
		return res;
	}
 	res = procAllConfigTableFiles(); 
	if( res != CONF_NO_ERR ) 
	{
		return res;
	}
	
	return CONF_NO_ERR;
} 
