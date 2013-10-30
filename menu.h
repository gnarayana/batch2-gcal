/***********************************************************************************
*	File Name     : menu.h 
*	Description   : Header file declares interface/protypes for displaying menu  
*	Create Date   : 19-Oct-2013
*	Modified Date : 27-Oct-2013
*	Authour       : Girisha Narayana ( girishanayak )
*	Modifier      : Vinay Kiran (Kiran)
*	Vesrion       : 1.0
*	Case Study    : gcal ( case-00 )
*	Email Id      : gnarayana77.dev.gyana@gmail.com ( Author )
*	Email Id      : vinaykiran.dev.gyana@gmail.com ( Modifier )
***********************************************************************************/
#ifndef _READ_CONFIG_H_
#define _READ_CONFIG_H_
#include <fstream>
#include <string>
#include <map>
using namespace std;

/*

*/
enum MENU_ERRS
{
	MENU_NO_ERR,
	MENU_TYPE_ERR,
	MENU_META_FORMAT_ERR,
   MENU_CONF_PATH_ERR,
	MENU_FILE_NOT_FOUND_ERR,
	MENU_META_DATA_NOT_FOUND_ERR,
	MENU_META_DATA_IS_EMPTY_ERR,
	MENU_CACHE_EMPTY_ERR,
	MENU_INVALID_CHOICE,
	MENU_CACHE_CORPT_ERR,
	MENU_FILE_OPEN_ERR
};

typedef MENU_ERRS merr_t; 

extern string GCAL_MENU_CONF_PATH;

/*
	Used to store configuration data
*/
struct MenuMetaData
{
	char fileOrCache;// Read from filed from config	
	string menuFile;
	int items; // for variable menu make it 0 ( V OR v )
	
};

// Menu Meta's Cache
// Key - type|MenuName form Key
extern map<string,MenuMetaData> MENU_META_CH; 

// Cache Main Menu contants
extern string MAIN_MENU;
extern string CONFIG_MENU;
extern string GRADE_MENU;
extern string GRADE_CH_MENU;
extern string MSG_CH_MENU;
extern string CRS_CH_MENU;
extern string SCORE_CH_MENU;


/*
	Process the menu.meta file 
*/
merr_t procMenuMetaLine(const string& line); //Updates the Menu Meta Cache
merr_t procMainMenuLine(const string& line); //Updates the Main Menu Cache
merr_t procConfigMenuLine(const string& line); //Updates the Config Menu Cache
merr_t procGradeMenuLine(const string& line); //Updates the Grade Menu Cache

merr_t procGradeCache();
merr_t procMsgCache();
merr_t procScoreCache();
merr_t procCourseCache();
/*
	Read all the menu files 
*/
merr_t readAllMenuFiles(const char menuType);
/*
	Read all the menu config caches 
*/
merr_t readAllMenuConfigCaches(const char menuType);
/*

 */
merr_t getGcalMenuConfPath();
/*
	Interface to read menu files
*/
merr_t readMenuFileInterface(const string& fileName,merr_t (* procMenuFileLine) ( const string& line)); 
/*
	Load Main Menu Config
*/
merr_t loadConfig(const char menuType); 

void showMainMenu();
void showConfigMenu();
void showGradeMenu();
#endif
