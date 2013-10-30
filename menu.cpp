/*******************************************************************************
*	File Name     : menu.cpp 
*	Description   : Implementaion of interface/protypes menu  
*	Create Date   : 19-Oct-2013
*	Modified Date : 27-Oct-2013
*	Authour       : Girisha Narayana ( girishanayak )
*	Modifier      : Vinay Kiran (kiran)
*	Vesrion       : 1.0.1
*	Case Study    : gcal ( case-00 )
*	Email Id      : gnarayana77.dev.gyana@gmail.com ( Author )
*	Email Id      : vinaykiran89.dev.gyana@gmail.com ( Modifier )
*******************************************************************************/

#include "menu.h"
#include <cstdlib>
#include "gCalGen.h"
#include <iostream>
using namespace std;

string GCAL_MENU_CONF_PATH;
string MAIN_MENU;
string CONFIG_MENU;
string GRADE_MENU;
string GRADE_CH_MENU;
string MSG_CH_MENU;
string CRS_CH_MENU;
string SCORE_CH_MENU;

map<string,MenuMetaData> MENU_META_CH; 

merr_t readAllMenuFiles(const char menuType)
{
	map<string,MenuMetaData>::iterator itr;
	merr_t res = MENU_NO_ERR;

	for( itr = MENU_META_CH.begin() ; itr != MENU_META_CH.end() ; itr++ ) 
	{
		string key = itr -> first;
		vector<string> ktoks = Tokenizer(key,"|"); 
		switch( menuType )	
		{
			case 'c' : 
								 if ( ktoks[0] == "c" )
								 {
										string menuName = ktoks[1];
  									   MenuMetaData value = itr->second;
									 	if( value.fileOrCache == 'f' )  
										{
  								        string menuMetaFile = GCAL_MENU_CONF_PATH + "/" + value.menuFile;  

										   if( menuName == "MainMenu" )
											{
 												  res = readMenuFileInterface(menuMetaFile,procMainMenuLine);
											}
											else if ( menuName == "ConfigMenu" )
											{
 												  res = readMenuFileInterface(menuMetaFile,procConfigMenuLine);
											}
											else if ( menuName == "GradeMenu" )
											{
 												  res = readMenuFileInterface(menuMetaFile,procGradeMenuLine);
											}
										}
										else if ( value.fileOrCache == 'c' )
										{
										}
										else
										{
			
										}
								 }
								 break;
			case 'h' :
								 if ( ktoks[0].at(0) == 'h' )
								 {
								 }
								 break;
	
			case 'g' :
								 if ( ktoks[0].at(0) == 'g' )
								 {
								 }
								 break;
			default :
								res = MENU_TYPE_ERR;
		}
	}
	return res; 
}

merr_t procMenuMetaLine(const string& line)
{
	vector<string> toks = Tokenizer(line,"|"); // MainMenu|f
	if( toks.size() == 5 || toks.size() == 4 )
	{
	  string key = toks[0] + "|" + toks[1];
  	MenuMetaData value;
  	value.fileOrCache = toks[3].at(0);
  	value.menuFile = toks[4];
  	value.items = atoi(toks[2].c_str()); 
  	MENU_META_CH[key]=value;
	}
	else
	{
		return MENU_META_FORMAT_ERR;
	}
	return MENU_NO_ERR; 
}

merr_t readMenuFileInterface(const string& fileName,merr_t (* procMenuFileLine) ( const string& line)) 
{
	ifstream ifile(fileName.c_str());
	merr_t res = MENU_NO_ERR;
	if ( ifile.is_open() )
  {
	  string line;
	  while( !ifile.eof() )
		{
		  getline(ifile,line);
		  if ( line.size() > 0 &&  line.at(0) != '#' )
		  {
		  	res = procMenuFileLine(line);
		  	if (res != MENU_NO_ERR )
	    	{
					return res;
	    	}
			}
	  }
	}
	else
	{
		res = MENU_FILE_OPEN_ERR;
	}
	
	ifile.close();
	
	return res; 
}

merr_t getGcalMenuConfPath()
{
  const char* menuConfPath = getenv("GCAL_MENU_CONF"); 

  if( menuConfPath )
  {
		GCAL_MENU_CONF_PATH = menuConfPath;			
	}
	else
	{
		GCAL_MENU_CONF_PATH = "/import/home/prodGyana/ui"; 
	}
  /*
			TODO - check PATH exists or not or permissions exists or not 
   */
	return MENU_NO_ERR; 
}

merr_t loadConfig(const char menuType) 
{
  // Get Menu Conf path
  merr_t res = getGcalMenuConfPath();
  if( res != MENU_NO_ERR )
  {
		return res;
  }

  // Read Menu Meta file
  string menuMetaFile = GCAL_MENU_CONF_PATH + "/menu.meta";  
  res = readMenuFileInterface(menuMetaFile,procMenuMetaLine);
  if( res != MENU_NO_ERR )
  {
		return res;
  }
  res  = readAllMenuFiles(menuType);
  if( res != MENU_NO_ERR )
  {
		return res;
  }
  return MENU_NO_ERR; 
}

merr_t procMainMenuLine(const string& line) // Udates Menu Menu Cache
{
	if( MAIN_MENU.size() == 0 )
	{
		MAIN_MENU = line ;
	}
	else
	{
		MAIN_MENU += "\n" + line ;
	}
	return MENU_NO_ERR;
}

merr_t procConfigMenuLine(const string& line ) // Updates Congig Menu Cache
{
	CONFIG_MENU += line + "\n";
	return MENU_NO_ERR;
}

merr_t procGradeMenuLine(const string& line ) // Updates Grade Menu Cache
{
	GRADE_MENU += line + "\n";
	return MENU_NO_ERR;
}
void showMainMenu() 
{
	system("clear");
	cout << MAIN_MENU;
}
