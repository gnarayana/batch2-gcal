/*###########################################################################################
#	File Name     : readConfig.h 
#	Description   : Header file declares interfaces/protype for reading configuration files.
#	Create Date   : 19-Oct-2013
#	Modified Date : 26-Oct-2013
#	Authour       : Girisha Narayana ( girishanayak )
#	Modifier      : Girisha Narayana ( girishanayak )
#	Vesrion       : 1.0.1
#	Case Study    : gcal ( case-00 )
#	Email Id      : gnarayana77.dev.gyana@gmail.com ( Author )
#	Email Id      : gnarayana77.dev.gyana@gmail.com ( Modifier )
##############################################################################################
*/
 
 #include <string>
 #include "gCalTypes.h"
 #include "gCalGen.h"

 using namespace std;

 /*
   
  */
 cerr_t procMetaLine(const string& line); 
 /*

  */
 cerr_t procGradeLine(const string& line); 
 /*

  */
 cerr_t procMsgLine(const string& line); 
 /*

  */
 cerr_t procScoreLine(const string& line); 
 /*

  */
 cerr_t procCourseLine(const string& line); 

 /*
	
  */
 cerr_t procAllConfigTableFiles(); 
 


 /*
	Interface for reading files

  */
 cerr_t readConfigFile(const string& fileName,cerr_t (*procConfigLile)(const string& line)); 
 /*

  */
 cerr_t readConfigPath();   
 /*

  */
 cerr_t readConfig();
