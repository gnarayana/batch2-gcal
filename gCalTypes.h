/*###############################################################################################
#	File Name     : gCalTypes.h 
#	Description   :
#	Created Date  : 24-Oct-2013 
#	Modified Date : 26-Oct-2013
#	Authour       : Girisha Narayana ( girishanayak )
#	Modifier      : Chethan S ( chethans  )
#	Vesrion       : 1.0.1
#	Case Study    : gcal ( case-00 )
#	Email Id      : gnarayana77.dev.gyana@gmail.com ( Author )
#	Email Id      : chethans.dev.gyana@gmail.com ( Modifier )
###################################################################################################
*/

 #include <string>
 #include <map>

 using namespace std;

 /*
		NOT Documented !
  */ 
 enum CONFIG_ERRS 
 {
	CONF_NO_ERR, // ..
	CONF_META_NF_ERR, // ..
	CONF_META_EMPTY_ERR, // ..
	CONF_PATH_ERR, // ..
	CONF_ACCESS_ERR,
	CONF_FILE_OPEN_ERR
 };

 typedef CONFIG_ERRS cerr_t; 

 /*
	
  */
 extern string GCAL_CONF_PATH;
 /*
	
  */
 extern map<string,string> META_CH;

 /*
	
  */
 struct Bounds
 {
	short lb;
	short ub;
	bool  lbEq;
	bool  ubEq;
 };
 
 extern map<char,Bounds> GRADE_CH;
 
 /*
	
  */
 // Key A|a or A|c Value - Message
 extern map<string,string> MSG_CH;
 /* 
	
  */
 extern map<string,short> CRS_CH;
 
 /*
	
  */

typedef map<short,short> SemScore;	//if 0 => all sem else semester number

extern map<string,SemScore > SEM_SCORES_CH; 
