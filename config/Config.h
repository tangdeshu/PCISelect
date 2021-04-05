#ifdef WIN32
/*****************************File Header************************************/                                   
/**                                                                           
*  @file     Config.h                                                                                            
*  @brief    APIs of ini file config module are declared in this file                                                                                         
*  @details  APIs of ini file config module are declared in this file                                                                           
*                                                                                                                                                                                                                                
*  @copyright CTECA Co,.ltd                                                   
*/                                                                                                                      
/****************************************************************************/  

#ifndef __CONFIG_H__
#define __CONFIG_H__


/******************************Include Files*********************************/
 


/****************************************************************************/ 


/*********************************Macros*************************************/


/****************************************************************************/ 


/******************************Global Types**********************************/ 

/* add global type definitions here */

/**ini config file reader handle type*/
typedef void* ini_cfg_handle_t;

/****************************************************************************/



/************************Global Variable Declarations************************/

/* add global variable declarations here */

/****************************************************************************/ 


/***********************Global Function Declarations*************************/

/* add global func declarations here */

/****************************************************************************/ 



/**Create a ini file handle*/
ini_cfg_handle_t createIniCfg (const mw_char_t* cfgFle);


/**Read a int value from ini file by section and key*/
mw_int32_t getValInt(ini_cfg_handle_t handle,mw_char_t* section,mw_char_t* key, mw_int32_t defaultVal);


/**Read a string value from ini file by section and key*/
mw_char_t* getValStr(ini_cfg_handle_t handle,mw_char_t* section,mw_char_t* key, mw_char_t* defaultVal);


#endif/* __CONFIG_H__ */
#endif