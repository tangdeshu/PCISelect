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
 *  AR_GET_CONFIG����ʹ�õĹ��ܶ��塣
 *----------------------------------------------------------------------------*/
#define ARU_PCI_SLOT_NUM        2006  // PCI���ۺ�

 /*----------------------------------------------------------------------------*
 *  AR_SET_CONFIG����ʹ�õĹ��ܶ��塣
 *----------------------------------------------------------------------------*/
#define ARU_XMIT_RATE           1 /* �������ʣ�
                                     AR_HIGH ��AR_100K  (100Kb) 
									 AR_LOW  ��AR_12K5  (12.5Kb) 
									 AR_50K             (50Kb) 
									 AR_48K             (48Kb) 
                                     ���ö�����ͨ����Ч */

#define ARU_RECV_RATE           2 /* �������ʣ�
                                     AR_HIGH ��AR_100K  (100Kb) 
									 AR_LOW  ��AR_12K5  (12.5Kb) 
									 AR_50K             (50Kb) 
									 AR_48K             (48Kb) 
                                     ���ö�����ͨ����Ч */

#define ARU_PARITY              3 /* ��żЧ�飺
									 AR_EVEN            ��Ч��
									 AR_ODD             żЧ��
									 AR_OFF             ��Ч��
                                     ���ö�����ͨ����Ч */

#define ARU_INTERNAL_WRAP       4 /* �ڲ��ػ����ԣ�
                                     AR_ON              �ڲ��ػ�    
                                     AR_OFF             �ڲ����ػ� 
                                     ���ö�����ͨ����Ч */

/*----------------------------------------------------------------------------*
 *  �������ú�����AR_SET_CONFIG ʹ�õĺ궨�塣
 *----------------------------------------------------------------------------*/
#define AR_ODD                  0  /*����������Ч��                           */
#define AR_EVEN                 1  /*��������żЧ��                           */
                                   /* AR_OFF  �ر�Ч��                        */

#define AR_HIGH                 0  /* ʹ�ø��ٲ�����(100 Kbaud)               */
#define AR_LOW                  3  /* ʹ�õ��ٲ�����(12.5 Kbaud)              */

#define AR_100K                 0  /* ��AR_HIGH��ͬ                           */
#define AR_50K                  1  /* ʹ������Ĳ�����(50 Kbaud)              */
#define AR_48K                  2  /* ʹ������Ĳ�����(48 Kbaud)              */
#define AR_12K5                 3  /* ��AR_LOW��ͬ                            */

#define AR_WRAP_ON              0  /* �ڲ��ػ�                                */
#define AR_WRAP_OFF             1  /* �ڲ����ػ�                              */
#define AR_ON                   7  /* ͨ����Ч��־                            */
#define AR_OFF                  8  /* ͨ����Ч��־                            */

  /*-----------------------------------------------------------------------------*
 *  ÿ������ͨ�������Ľ������ʲ������壬��AR_SET_CONFIG ��ʹ�õĺ궨�塣
 *  �����У�  AR_HIGH��AR_LOW��AR_50K��AR_SET_RATE
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
 *  ÿ������ͨ�������ķ������ʲ������壬��AR_SET_CONFIG ��ʹ�õĺ궨�塣
 *  �����У�  AR_HIGH��AR_LOW��AR_50K
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
 *  ÿ������ͨ����������żЧ��������壬��AR_SET_CONFIG ��ʹ�õĺ궨�塣
 *  ֧����Ч�飬AR_OFF
 *  �����У�  AR_ODD��AR_EVEN��AR_OFF
 *---------------------------------------------------------------------------*/
#define ARU_RX_CH01_PARITY     900   /* ���ý���ͨ����żЧ�����             */
#define ARU_RX_CH02_PARITY     901   /* AR_ON/AR_ODD �� AR_OFF               */
#define ARU_RX_CH03_PARITY     902   /* ȱʡΪAR_ODD ģʽ(��Ч��)            */
#define ARU_RX_CH04_PARITY     903   /* ��ͬ�� AR_ON                         */
#define ARU_RX_CH05_PARITY     904   /* ��żЧ�鹦����Ч����Ч��ʱ��������Ϊ */
#define ARU_RX_CH06_PARITY     905   /* ż�����������ݵ�MSBΪ1��             */
#define ARU_RX_CH07_PARITY     906   /* żЧ��ʱ��������Ϊż�����������ݵ�   */
#define ARU_RX_CH08_PARITY     907   /* MSBΪ0��                             */
#define ARU_RX_CH09_PARITY     908   /* AR_ON �� AR_ODD ��Ч                 */
#define ARU_RX_CH09_PARITY     908
#define ARU_RX_CH10_PARITY     909
#define ARU_RX_CH11_PARITY     910
#define ARU_RX_CH12_PARITY     911
#define ARU_RX_CH13_PARITY     912
#define ARU_RX_CH14_PARITY     913
#define ARU_RX_CH15_PARITY     914
#define ARU_RX_CH16_PARITY     915

/*----------------------------------------------------------------------------*
 *  ÿ������ͨ����������żЧ��������壬��AR_SET_CONFIG ��ʹ�õĺ궨�塣
 *  ֧����Ч�飬AR_OFF
 *  �����У�  AR_ODD��AR_EVEN��AR_OFF
 *---------------------------------------------------------------------------*/
#define ARU_TX_CH01_PARITY     1100  /* ���÷���ͨ����żЧ�����             */
#define ARU_TX_CH02_PARITY     1101  /* AR_ON/AR_ODD �� AR_OFF               */
#define ARU_TX_CH03_PARITY     1102  /* ȱʡΪAR_ODD ģʽ(��Ч��)            */
#define ARU_TX_CH04_PARITY     1103  /* ��ͬ�� AR_ON                         */
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
 *  ���庯������
 *----------------------------------------------------------------------------*/
#define ARU_ALL_LABELS          0x1FF /* ��/�ر����еı�Ź���              */
#define ARU_FILTER_OFF          0     /* ��Ź��˹ر�--ͨ�����еı��         */
#define ARU_FILTER_ON           1     /* ��Ź��˴�--ɾ��ָ���ı��         */

/*----------------------------------------------------------------------------*
 *  ��������ֵ����
 *----------------------------------------------------------------------------*/
#define ARS_FAILURE             -1

#define ARS_NODATA               0    /* ���ջ�����������                     */
#define ARS_NORMAL               1    /* ���������ɹ�                         */
#define ARS_GOTDATA              4    /* ���ջ����������ݱ�־                 */

#define ARS_INVHARCMD         1002    /* ��Ч����������                       */
#define ARS_INVHARVAL         1003    /* ��Ч������ֵ                         */
#define ARS_XMITOVRFLO        1004    /* ���ͻ�������                         */
#define ARS_INVBOARD          1005    /* ��Ч�İ忨��                         */
#define ARS_INVARG            1019    /* ��Ч��ͨ����־                       */
#define ARS_WINRTFAIL         1022    /* Ӳ���豸����                         */

/*===========================================================================*
 *  ARINC429����
 *===========================================================================*/

short __stdcall  ar_FindDevice(short cardType,short Instance);

short __stdcall  ar_loadslv(short board,unsigned long base_seg,int base_port,unsigned short ram_size);
short __stdcall  ar_go(short board);
short __stdcall  ar_close(short board);
short __stdcall  ar_reset(short board);

short __stdcall  ar_putword(short board,short channel,long xmit_data);
short __stdcall  ar_getnext(short board,short channel,void* dest);
// timetag������ʱ�굥λ0.1ms
short __stdcall  ar_getnextt(short board,short channel,void* dest, void *timetag);
short __stdcall  ar_set_config(short board,short item,unsigned long value);
short __stdcall  ar_get_config(short board,short item,unsigned long* value);
short __stdcall  ar_label_filter(short board,short channel,unsigned short label,short action);
void  __stdcall  ar_get_latest (short board, short channel,unsigned short label, void* data,char* seq_num);

short __stdcall  ar_num_rchans (short board);
short __stdcall  ar_num_xchans (short board);

void  __stdcall	 WT_SetUserRXHandle(short board,WT_UserHandle function);

/*
 RX :error_flag ����
D0=1 ��ʾ����ż����
D0=0 ��ʾ����ż����

D1=1 ��ʾ��λ���ȴ���
D1=0 ��ʾ��λ���ȴ���

D2=1 ��ʾλ���ȴ���32λ
D2=0 ��ʾλ����С��32λ
*/
unsigned long  __stdcall	ar_RX_GetData(short  device,short ch,unsigned long *data,unsigned __int64 *tag,unsigned char *error_flag,unsigned long length);

// ei_recv_en=1 ���ռ���������ʹ�ܣ���ar_RX_GetData�������ɽ��ղ������ż�����λ���ȴ�������
short __stdcall  ar_set_RX_ei(short board,short ch,unsigned char ei_recv_en);

/*
 TX :error_flag ����
D0~D5: λ���� 1 �� 63
D6:  ע��λ���ȴ���ʹ��   ��ע�����=0   ע�����=1 

D7:  ��ż����ע��ʹ��	ֻ����У�鷽ʽʱ����ע����ż����  ��ע�����=0   ע�����=1 
*/
short __stdcall  ar_set_TX_ei(short board,short ch,unsigned char error_flag);

/*
	unsigned int wordgap_en;	 //�ּ������ʹ�� 	����1ʱ�ּ��Ϊwordgapֵ������0ʱΪ��׼4��Ϊʱ���
	unsigned int wordgap;		 //�ּ�� ��λ0.5��λʱ
*/
short __stdcall ar_set_TX_wordgap(short board,short ch,unsigned int wordgap_en,unsigned int wordgap);

void __stdcall ar_TX_SyncRun(short device,short ch);
void __stdcall ar_TX_SyncStop(short device,short ch);
void __stdcall ar_Set_TX_SyncData(short device,short ch,unsigned long *data,unsigned long period,unsigned long length);
void __stdcall ar_Updata_TX_SyncData(short device,short ch,unsigned long *data);

//�忨��ʱ����������
void __stdcall ar_reset_timetag(short device); 


#ifdef __cplusplus 
}
#endif

#endif