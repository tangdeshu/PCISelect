#ifdef WIN32
/*****************************File Header************************************/                                   
/**                                                                           
*  @file     Config.c                                                                                                     
*  @brief    APIs of ini configuration are implemented in this file                                                                                         
*  @details  APIs of ini configuration are implemented in this file                                                                         
*                                                                                                                                                                                                                                
*  @copyright CTECA Co,.ltd                                                   
*/                                                                                                                      
/****************************************************************************/ 

/******************************Include files*********************************/
 
#include "BasicType.h"
#include "Constants.h" 
#include "Config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************/ 


/*********************************Macros*************************************/


#define FILE_LINE_MAX_LEN 256

/****************************************************************************/ 


/******************************Static Types**********************************/ 

/* add static type definitions here */

/****************************************************************************/
typedef struct
{
    mw_char_t section[FILE_LINE_MAX_LEN];
    mw_char_t key[FILE_LINE_MAX_LEN];
    mw_char_t val[FILE_LINE_MAX_LEN];
    void* next;
}st_line_node_t;

typedef struct  
{
    st_line_node_t* lineNodeList;
    mw_char_t section[FILE_LINE_MAX_LEN];
}st_ini_cfg_inof_t;


/************************Global Variable Definitions*************************/

/* add global variable definitions here */

/****************************************************************************/ 


/*************************Static Variable Definitions************************/

/* add static variable definitions here */

/****************************************************************************/ 

/***********************Static Function Declarations*************************/

/* add static func declarations here */

/****************************************************************************/ 
static mw_bool_t readConfigFile(st_ini_cfg_inof_t* cfg,FILE* file);

static mw_bool_t readLine(FILE* file, mw_char_t* buffer, mw_int32_t* bufLen);

static void trimLine(mw_char_t* dst,mw_char_t* src);

static void parseLine(st_ini_cfg_inof_t* cfg,mw_char_t* line);

static void insertNode(st_ini_cfg_inof_t* cfg,st_line_node_t* node);

static mw_char_t* getVal(st_ini_cfg_inof_t* cfg,mw_char_t* section,mw_char_t* key);

/***********************Static Function Definitions**************************/

/* add static func definitions here */

/****************************************************************************/

/****************************************************************************/
/*!   
*   @brief         createIniCfg\n
*          
*   @details       This func is used to create a ini file handle\n
*   @param[in]     cfgFle      Config file path\n
*   @param[out]    N/A\n
*        
*   @return        INI FILE HANDLE is returned\n
*                  S_NULL means failure,otherwise,this handle of ini file\n
*                  
*   @par example
*   @code
*        ini_cfg_handle_t handle = createIniCfg("config.ini");
*   @endcode
*
*   @note          N/A\n
*                  
*   @see                          
*/
/****************************************************************************/

ini_cfg_handle_t createIniCfg (const mw_char_t* cfgFle)
{
    FILE* file = S_NULL;
	mw_int16_t openVal = 0;
    st_ini_cfg_inof_t* cfg = S_NULL;
    
    openVal = fopen_s(&file,cfgFle, "r");
    if (openVal == 0)
    {
        cfg = malloc(sizeof(st_ini_cfg_inof_t));
    }
    if (cfg)
    {
        memset(cfg,0,sizeof(st_ini_cfg_inof_t));
        
        cfg->lineNodeList = S_NULL;
        if(S_NULL != file)
        {
            readConfigFile(cfg,file);
            fclose(file);
            file = S_NULL;
        }
        else
        {
            //debugTrace(DEBUG_LEVEL, "%s:fopen %s fail\n",(mw_int32_t)__FUNCTION__,(mw_int32_t)cfgFle,3,4,5,6);
			printf("%s:fopen %s fail\n", __FUNCTION__, cfgFle);
        }
    }
	
	return cfg;
}

/****************************************************************************/
/*!   
*   @brief         readConfigFile\n
*          
*   @details       This func is used to initialize configuration from ini file\n
*   @param[in]     cfg          This param is ini configuration\n
*                  file         ini file handle
*   @param[out]    N/A\n
*        
*   @return        result of initialize configuration from ini file\n
*                  SS_TRUE means success,SS_FALSE means failure\n
*                  
*   @par example
*   @code
*   @endcode
*
*   @note         N/A\n
*                  
*   @see                        
*/
/****************************************************************************/

static mw_bool_t readConfigFile(st_ini_cfg_inof_t* cfg,FILE* file)
{
	mw_bool_t retVal = SS_FALSE;
	mw_int32_t readLen = 0;
	mw_char_t lineBuffer[FILE_LINE_MAX_LEN] = {0};
	mw_bool_t readRet = SS_FALSE;
	if(S_NULL != file)
	{
		do
		{
			readRet = readLine(file,lineBuffer, &readLen);
			if(readLen > 0)
			{
				parseLine(cfg,lineBuffer);
			}
		}
		while(SS_TRUE == readRet);
	}

	return retVal;
}


/****************************************************************************/
/*!   
*   @brief         readLine\n
*          
*   @details       This func is used to read a line from ini file\n
*   @param[in]     file         ini file handle\n
*                  
*   @param[out]    buffer       buffer to restore the line\n
*                  bufLen       buffer to restore the line length\n
*        
*   @return        result of read line from ini file\n
*                  SS_TRUE means success,SS_FALSE means failure\n
*                  
*   @par example
*   @code
*   @endcode
*
*   @note         N/A\n
*                  
*   @see                        
*/
/****************************************************************************/

static mw_bool_t readLine(FILE* file, mw_char_t* buffer, mw_int32_t* bufLen)
{
	mw_int32_t readLen = 0;
	mw_char_t chTmp = 0;
	mw_bool_t retVal = SS_TRUE;

	do
	{
		chTmp = (mw_char_t)fgetc(file);
		if((EOF != (mw_int32_t)chTmp))
		{
			if( '\n' != chTmp)
			{
				*(buffer + readLen) = chTmp;
				readLen++;
			}
		}
		else
		{
			retVal = SS_FALSE;
		}
	}
	while((EOF != (mw_int32_t)chTmp) && ('\n' != chTmp));
	*bufLen = readLen;
	*(buffer+ readLen) = '\0';

	return retVal;
}

/****************************************************************************/
/*!   
*   @brief         trimLine\n
*          
*   @details       This func is used to trim a string\n
*   @param[in]     src         string need to be trimmed\n
*                  
*   @param[out]    dst       buffer to restore the string trimmed\n
*        
*   @return        N/A\n
*                  
*   @par example
*   @code
*   @endcode
*
*   @note         N/A\n
*                  
*   @see                        
*/
/****************************************************************************/

static void trimLine(mw_char_t* dst,mw_char_t* src)
{
	mw_uint32_t dstLen = 0u;
	mw_uint32_t idx = 0u;
	mw_char_t chTmp = 0;
	mw_uint32_t srcLen = strlen(src);
	for(idx  = 0; idx < srcLen; idx++)
	{
		chTmp = *(src + idx);
		if(' ' != chTmp)
		{
			*(dst + dstLen) = chTmp;
			dstLen++;
		}
	}
}

/****************************************************************************/
/*!   
*   @brief         parseLine\n
*          
*   @details       This func is used to parse line read from ini file\n
*   @param[in]     cfg          This param is ini configuration\n
*                  line         line need to be parsed.
*   @param[out]    N/A\n
*        
*   @return        N/A\n
*                  
*   @par example
*   @code
*   @endcode
*
*   @note         N/A\n
*                  
*   @see                        
*/
/****************************************************************************/

static void parseLine(st_ini_cfg_inof_t* cfg,mw_char_t* line)
{
	mw_char_t trimBuffer[FILE_LINE_MAX_LEN] = {0};
	mw_char_t strRight[FILE_LINE_MAX_LEN] = {0};
	mw_char_t strLeft[FILE_LINE_MAX_LEN] = {0};
	mw_char_t* strR = S_NULL;
	mw_char_t* strL = S_NULL;
	st_line_node_t* lineNode = S_NULL;
    if (cfg)
    {
        trimLine(trimBuffer, line);


        /*将注释信息去掉*/
        if (strlen(trimBuffer) >= 2)
        {
            if (trimBuffer[0] == '/' && trimBuffer[1] == '/')
            {
                return;
            }
        }

        strR = strchr(trimBuffer, '[');
        strL = strchr(trimBuffer, ']');

        if (strR != S_NULL && strL != S_NULL)
        {
            *strL = '\0';
            strcpy(cfg->section, strR+1);
        }
        else
        {
            strcpy(strLeft, trimBuffer);

            strR = strchr(trimBuffer, '=');
            if(S_NULL != strR)
            {
                strcpy(strRight, strR + 1);
                strLeft[strlen(trimBuffer) - strlen(strR)] = '\0';

                if((strlen(strRight) > 0) && (strlen(strLeft) > 0))
                {
                    lineNode = (st_line_node_t*)malloc(sizeof(st_line_node_t));
                    if(lineNode != S_NULL)
                    {
                        strcpy(lineNode->key, strLeft);
                        strcpy(lineNode->val, strRight);
                        strcpy(lineNode->section, cfg->section);
                        lineNode->next = S_NULL;
                        insertNode(cfg,lineNode);
                    }
                }
            }
        }
    }
	
}

/****************************************************************************/
/*!   
*   @brief         parseLine\n
*          
*   @details       This func is used to record a line information read from ini file\n
*   @param[in]     cfg          This param is ini configuration\n
*                  node         line information node need to be recorded.
*   @param[out]    N/A\n
*        
*   @return        N/A\n
*                  
*   @par example
*   @code
*   @endcode
*
*   @note         N/A\n
*                  
*   @see                        
*/
/****************************************************************************/

static void insertNode(st_ini_cfg_inof_t* cfg,st_line_node_t* node)
{
	st_line_node_t* nodeTmp = S_NULL;
    if (cfg)
    {
        if(S_NULL == cfg->lineNodeList)
        {
            cfg->lineNodeList = node;
            cfg->lineNodeList->next = S_NULL;
        }
        else
        {
            nodeTmp = (st_line_node_t* )cfg->lineNodeList;
            while(S_NULL != nodeTmp->next)
            {
                nodeTmp = (st_line_node_t* )nodeTmp->next;
            }
            nodeTmp->next = node;
        }
    }
	
}


/****************************************************************************/
/*!   
*   @brief         getVal\n
*          
*   @details       This func is used to read a string value from ini file by section and key\n
*   @param[in]     handle      ini file hanlde.\n
*                  section     section in ini file.\n
*                  key         key in ini file.\n
*   @param[out]    N/A\n
*        
*   @return        string value\n
*                  S_NULL means failure,otherwise means success\n
*                  
*   @par example
*   @code
*        mw_char_t* val = getValInt(handle, "section","key");
*   @endcode
*
*   @note          N/A\n
*                  
*   @see                          
*/
/****************************************************************************/


static mw_char_t* getVal(st_ini_cfg_inof_t* cfg,mw_char_t* section,mw_char_t* key)
{
	mw_char_t* retVal = S_NULL;
	st_line_node_t* nodeTmp = S_NULL;
    if (cfg)
    {
        nodeTmp = (st_line_node_t* )cfg->lineNodeList;
        while(S_NULL != nodeTmp)
        {
            if((strcmp(nodeTmp->section, section) == 0) && (strcmp(nodeTmp->key, key) == 0))
            {
                retVal = nodeTmp->val;
                break;
            }
            nodeTmp = (st_line_node_t* )nodeTmp->next;
        }
    }
	
	return retVal;
}


/****************************************************************************/
/*!   
*   @brief         getValInt\n
*          
*   @details       This func is used to read a int value from ini file by section and key\n
*   @param[in]     handle      ini file hanlde.\n
*                  section     section in ini file.\n
*                  key         key in ini file.\n
*                  defaultVal  default value if not found.\n
*   @param[out]    N/A\n
*        
*   @return        int value\n
*                  
*   @par example
*   @code
*        mw_int32_t val = getValInt(handle, "section","key",1);
*   @endcode
*
*   @note          N/A\n
*                  
*   @see          createIniCfg                
*/
/****************************************************************************/

mw_int32_t getValInt(ini_cfg_handle_t handle,mw_char_t* section,mw_char_t* key,mw_int32_t defaultVal)
{
	mw_int32_t retVal = 0;
	mw_char_t* val = getVal((st_ini_cfg_inof_t*)handle,section,key);
	if(S_NULL != val)
	{
		retVal = atoi(val);
	}
	else
	{
		retVal = defaultVal;
	}
	return retVal;
}

/****************************************************************************/
/*!   
*   @brief         getValStr\n
*          
*   @details       This func is used to read a string value from ini file by section and key\n
*   @param[in]     handle      ini file hanlde.\n
*                  section     section in ini file.\n
*                  key         key in ini file.\n
*                  defaultVal  default string if not found.\n
*   @param[out]    N/A\n
*        
*   @return        string value\n
*                  
*   @par example
*   @code
*        mw_char_t* val = getValInt(handle, "section","key","defaultVal");
*   @endcode
*
*   @note          N/A\n
*                  
*   @see          createIniCfg                
*/
/****************************************************************************/

mw_char_t* getValStr(ini_cfg_handle_t handle,mw_char_t* section,mw_char_t* key,mw_char_t* defaultVal)
{
	mw_char_t* retVal = S_NULL;
	retVal = getVal((st_ini_cfg_inof_t*)handle,section,key);
	if(S_NULL == retVal)
	{
		retVal = defaultVal;
	}
	return retVal;
}
#endif


