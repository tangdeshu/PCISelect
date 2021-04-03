#ifndef __WTAPI_H
#define __WTAPI_H

#ifdef __cplusplus 
extern "C" {
#endif

typedef  int  (_stdcall *WT_UserHandle)(unsigned int device); 

#define START_BOARD_TYPE
#define WT_PCI642_ARINC429_16TR				0x01
#define WT_CPCI642_1553B				0x02
#define WT_PCI642_DATABUS				0x03
#define WT_PCI642_MULTI_IO_S04			0x04
#define WT_PCI642_1553B					0x05
#define WT_PCI642_485_S01				0x06
#define WT_PCI642_SCDR					0x07
#define WT_PCI642_ARINC453				0x08
#define WT_PCI642_LVDS					0x09
#define WT_PCI642_ARINC429_RS422		0x0A
#define WT_PCI642_ARINC708				0x0B
#define WT_PMC642_HDLC					0x0C
#define WT_PMC642_ARINC429_M			0x0D
#define WT_PCI642_ARINC429_32R			0x14
#define WT_PXI642_ARINC429_16TR				0x15
#define END_BOARD_TYPE



/*----------------------------------------------------------------------------*
 *  AR_GET_CONFIG函数使用的功能定义。
 *----------------------------------------------------------------------------*/
#define ARU_PCI_SLOT_NUM        2006  // PCI卡槽号

 /*----------------------------------------------------------------------------*
 *  AR_SET_CONFIG函数使用的功能定义。
 *----------------------------------------------------------------------------*/
#define ARU_XMIT_RATE           1 /* 发送速率：
                                     AR_HIGH 或AR_100K  (100Kb) 
									 AR_LOW  或AR_12K5  (12.5Kb) 
									 AR_50K             (50Kb) 
									 AR_48K             (48Kb) 
                                     设置对所有通道有效 */

#define ARU_RECV_RATE           2 /* 接收速率：
                                     AR_HIGH 或AR_100K  (100Kb) 
									 AR_LOW  或AR_12K5  (12.5Kb) 
									 AR_50K             (50Kb) 
									 AR_48K             (48Kb) 
                                     设置对所有通道有效 */

#define ARU_PARITY              3 /* 奇偶效验：
									 AR_EVEN            奇效验
									 AR_ODD             偶效验
									 AR_OFF             无效验
                                     设置对所有通道有效 */

#define ARU_INTERNAL_WRAP       4 /* 内部回环测试：
                                     AR_ON              内部回环    
                                     AR_OFF             内部不回环 
                                     设置对所有通道有效 */

/*----------------------------------------------------------------------------*
 *  参数配置函数：AR_SET_CONFIG 使用的宏定义。
 *----------------------------------------------------------------------------*/
#define AR_ODD                  0  /*用于设置奇效验                           */
#define AR_EVEN                 1  /*用于设置偶效验                           */
                                   /* AR_OFF  关闭效验                        */

#define AR_HIGH                 0  /* 使用高速波特率(100 Kbaud)               */
#define AR_LOW                  3  /* 使用低速波特率(12.5 Kbaud)              */

#define AR_100K                 0  /* 与AR_HIGH相同                           */
#define AR_50K                  1  /* 使用扩充的波特率(50 Kbaud)              */
#define AR_48K                  2  /* 使用扩充的波特率(48 Kbaud)              */
#define AR_12K5                 3  /* 与AR_LOW相同                            */

#define AR_WRAP_ON              0  /* 内部回环                                */
#define AR_WRAP_OFF             1  /* 内部不回环                              */
#define AR_ON                   7  /* 通用有效标志                            */
#define AR_OFF                  8  /* 通用无效标志                            */

  /*-----------------------------------------------------------------------------*
 *  每个接收通道独立的接收速率参数定义，在AR_SET_CONFIG 中使用的宏定义。
 *  参数有：  AR_HIGH，AR_LOW，AR_50K，AR_SET_RATE
 *----------------------------------------------------------------------------*/


#define ARU_RX_CH01_BIT_RATE   500  
#define ARU_RX_CH02_BIT_RATE   501  
#define ARU_RX_CH03_BIT_RATE   502  
#define ARU_RX_CH04_BIT_RATE   503  
#define ARU_RX_CH05_BIT_RATE   504
#define ARU_RX_CH06_BIT_RATE   505
#define ARU_RX_CH07_BIT_RATE   506
#define ARU_RX_CH08_BIT_RATE   507
#define ARU_RX_CH09_BIT_RATE   508 
#define ARU_RX_CH10_BIT_RATE   509  
#define ARU_RX_CH11_BIT_RATE   510  
#define ARU_RX_CH12_BIT_RATE   511  
#define ARU_RX_CH13_BIT_RATE   512
#define ARU_RX_CH14_BIT_RATE   513
#define ARU_RX_CH15_BIT_RATE   514
#define ARU_RX_CH16_BIT_RATE   515

/*----------------------------------------------------------------------------*
 *  每个发送通道独立的发送速率参数定义，在AR_SET_CONFIG 中使用的宏定义。
 *  参数有：  AR_HIGH，AR_LOW，AR_50K
 *----------------------------------------------------------------------------*/
#define ARU_TX_CH01_BIT_RATE   700  
#define ARU_TX_CH02_BIT_RATE   701  
#define ARU_TX_CH03_BIT_RATE   702  
#define ARU_TX_CH04_BIT_RATE   703
#define ARU_TX_CH05_BIT_RATE   704
#define ARU_TX_CH06_BIT_RATE   705
#define ARU_TX_CH07_BIT_RATE   706
#define ARU_TX_CH08_BIT_RATE   707
#define ARU_TX_CH09_BIT_RATE   708 
#define ARU_TX_CH10_BIT_RATE   709  
#define ARU_TX_CH11_BIT_RATE   710  
#define ARU_TX_CH12_BIT_RATE   711  
#define ARU_TX_CH13_BIT_RATE   712
#define ARU_TX_CH14_BIT_RATE   713
#define ARU_TX_CH15_BIT_RATE   714
#define ARU_TX_CH16_BIT_RATE   715

/*----------------------------------------------------------------------------*
 *  每个接收通道独立的奇偶效验参数定义，在AR_SET_CONFIG 中使用的宏定义。
 *  支持无效验，AR_OFF
 *  参数有：  AR_ODD，AR_EVEN，AR_OFF
 *---------------------------------------------------------------------------*/
#define ARU_RX_CH01_PARITY     900   /* 配置接收通道奇偶效验参数             */
#define ARU_RX_CH02_PARITY     901   /* AR_ON/AR_ODD 或 AR_OFF               */
#define ARU_RX_CH03_PARITY     902   /* 缺省为AR_ODD 模式(奇效验)            */
#define ARU_RX_CH04_PARITY     903   /* 等同于 AR_ON                         */
#define ARU_RX_CH05_PARITY     904   /* 奇偶效验功能有效，奇效验时，参数和为 */
#define ARU_RX_CH06_PARITY     905   /* 偶数，接收数据的MSB为1。             */
#define ARU_RX_CH07_PARITY     906   /* 偶效验时，参数和为偶数，接收数据的   */
#define ARU_RX_CH08_PARITY     907   /* MSB为0。                             */
#define ARU_RX_CH09_PARITY     908   /* AR_ON 和 AR_ODD 等效                 */
#define ARU_RX_CH09_PARITY     908
#define ARU_RX_CH10_PARITY     909
#define ARU_RX_CH11_PARITY     910
#define ARU_RX_CH12_PARITY     911
#define ARU_RX_CH13_PARITY     912
#define ARU_RX_CH14_PARITY     913
#define ARU_RX_CH15_PARITY     914
#define ARU_RX_CH16_PARITY     915

/*----------------------------------------------------------------------------*
 *  每个发送通道独立的奇偶效验参数定义，在AR_SET_CONFIG 中使用的宏定义。
 *  支持无效验，AR_OFF
 *  参数有：  AR_ODD，AR_EVEN，AR_OFF
 *---------------------------------------------------------------------------*/
#define ARU_TX_CH01_PARITY     1100  /* 配置发送通道奇偶效验参数             */
#define ARU_TX_CH02_PARITY     1101  /* AR_ON/AR_ODD 或 AR_OFF               */
#define ARU_TX_CH03_PARITY     1102  /* 缺省为AR_ODD 模式(奇效验)            */
#define ARU_TX_CH04_PARITY     1103  /* 等同于 AR_ON                         */
#define ARU_TX_CH05_PARITY     1104
#define ARU_TX_CH06_PARITY     1105
#define ARU_TX_CH07_PARITY     1106
#define ARU_TX_CH08_PARITY     1107
#define ARU_TX_CH09_PARITY     1108
#define ARU_TX_CH10_PARITY     1109
#define ARU_TX_CH11_PARITY     1110
#define ARU_TX_CH12_PARITY     1111
#define ARU_TX_CH13_PARITY     1112
#define ARU_TX_CH14_PARITY     1113
#define ARU_TX_CH15_PARITY     1114
#define ARU_TX_CH16_PARITY     1115
 /*----------------------------------------------------------------------------*
 *  定义函数功能
 *----------------------------------------------------------------------------*/
#define ARU_ALL_LABELS          0x1FF /* 打开/关闭所有的标号过滤              */
#define ARU_FILTER_OFF          0     /* 标号过滤关闭--通过所有的标号         */
#define ARU_FILTER_ON           1     /* 标号过滤打开--删除指定的标号         */

/*----------------------------------------------------------------------------*
 *  函数返回值参数
 *----------------------------------------------------------------------------*/
#define ARS_FAILURE             -1

#define ARS_NODATA               0    /* 接收缓冲区无数据                     */
#define ARS_NORMAL               1    /* 函数操作成功                         */
#define ARS_GOTDATA              4    /* 接收缓冲区有数据标志                 */

#define ARS_INVHARCMD         1002    /* 无效的配置命令                       */
#define ARS_INVHARVAL         1003    /* 无效的配置值                         */
#define ARS_XMITOVRFLO        1004    /* 发送缓冲区满                         */
#define ARS_INVBOARD          1005    /* 无效的板卡号                         */
#define ARS_INVARG            1019    /* 无效的通道标志                       */
#define ARS_WINRTFAIL         1022    /* 硬件设备错误                         */

/*===========================================================================*
 *  ARINC429函数
 *===========================================================================*/

short __stdcall  ar_FindDevice(short cardType,short Instance);

short __stdcall  ar_loadslv(short board,unsigned long base_seg,int base_port,unsigned short ram_size);
short __stdcall  ar_go(short board);
short __stdcall  ar_close(short board);
short __stdcall  ar_reset(short board);

short __stdcall  ar_putword(short board,short channel,long xmit_data);
short __stdcall  ar_getnext(short board,short channel,void* dest);
// timetag：接收时标单位0.1ms
short __stdcall  ar_getnextt(short board,short channel,void* dest, void *timetag);
short __stdcall  ar_set_config(short board,short item,unsigned long value);
short __stdcall  ar_get_config(short board,short item,unsigned long* value);
short __stdcall  ar_label_filter(short board,short channel,unsigned short label,short action);
void  __stdcall  ar_get_latest (short board, short channel,unsigned short label, void* data,char* seq_num);

short __stdcall  ar_num_rchans (short board);
short __stdcall  ar_num_xchans (short board);

void  __stdcall	 WT_SetUserRXHandle(short board,WT_UserHandle function);

/*
 RX :error_flag 定义
D0=1 表示有奇偶错误
D0=0 表示无奇偶错误

D1=1 表示有位长度错误
D1=0 表示无位长度错误

D2=1 表示位长度大于32位
D2=0 表示位长度小于32位
*/
unsigned long  __stdcall	ar_RX_GetData(short  device,short ch,unsigned long *data,unsigned __int64 *tag,unsigned char *error_flag,unsigned long length);

// ei_recv_en=1 接收检测错误数据使能，“ar_RX_GetData”函数可接收并检测奇偶错误和位长度错误数据
short __stdcall  ar_set_RX_ei(short board,short ch,unsigned char ei_recv_en);

/*
 TX :error_flag 定义
D0~D5: 位长度 1 到 63
D6:  注入位长度错误使能   不注入错误=0   注入错误=1 

D7:  奇偶错误注入使能	只有有校验方式时才能注入奇偶错误  不注入错误=0   注入错误=1 
*/
short __stdcall  ar_set_TX_ei(short board,short ch,unsigned char error_flag);

/*
	unsigned int wordgap_en;	 //字间隔设置使能 	等于1时字间隔为wordgap值，等于0时为标准4个为时间隔
	unsigned int wordgap;		 //字间隔 单位0.5个位时
*/
short __stdcall ar_set_TX_wordgap(short board,short ch,unsigned int wordgap_en,unsigned int wordgap);

void __stdcall ar_TX_SyncRun(short device,short ch);
void __stdcall ar_TX_SyncStop(short device,short ch);
void __stdcall ar_Set_TX_SyncData(short device,short ch,unsigned long *data,unsigned long period,unsigned long length);
void __stdcall ar_Updata_TX_SyncData(short device,short ch,unsigned long *data);

//板卡计时器清零重置
void __stdcall ar_reset_timetag(short device); 


#ifdef __cplusplus 
}
#endif

#endif