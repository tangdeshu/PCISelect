/*****************°å¿¨³õÊ¼»¯*************************/

#include "Constants.h"
#include "BasicType.h"
#include "board.h"
#include "wtapi.h"

typedef struct BoardType
{
	int a;

}st_board_type_t;

#define BOARD_NUMBER_CNT (5)
static mw_int16_t g_boardNumber = 0;


mw_uint16_t g_boardType[] = {
	WT_PCI642_ARINC429_16TR,		//0x01
	WT_CPCI642_1553B,			    //0x02
	WT_PCI642_DATABUS,			    //0x03
	WT_PCI642_MULTI_IO_S04,		    //0x04
	WT_PCI642_1553B,		        //0x05
	WT_PCI642_485_S01,	         	//0x06
	WT_PCI642_SCDR,					//0x07
	WT_PCI642_ARINC453,				//0x08
	WT_PCI642_LVDS,					//0x09
	WT_PCI642_ARINC429_RS422,		//0x0A
	WT_PCI642_ARINC708,				//0x0B
	WT_PMC642_HDLC,					//0x0C
	WT_PMC642_ARINC429_M,			//0x0D
	WT_PCI642_ARINC429_32R,			//0x14
	WT_PXI642_ARINC429_16TR,		//0x15
};

static mw_int16_t findBoard(void);

static mw_bool_t initBoardCard(mw_int16_t cardNumber);

static mw_int16_t setTxChlRate(mw_int16_t cardNumber, mw_int16_t item, mw_uint32_t value);
static mw_int16_t setRxChlRate(mw_int16_t cardNumber, mw_int16_t item, mw_uint32_t value);
static mw_int16_t setTxChlParity(mw_int16_t cardNumber, mw_int16_t item, mw_uint32_t value);
static mw_int16_t setInternalTest(mw_int16_t cardNumber, mw_int16_t item, mw_uint32_t value);

mw_bool_t initBoard()
{
	mw_bool_t ret = SS_FALSE;
	mw_int16_t cardNumber = findBoard();
	if (cardNumber != ARS_FAILURE)
	{
		ret = initBoardCard(cardNumber);
	}

	return ret;
}

static mw_int16_t findBoard(void)
{
	mw_int16_t ret = 0;
	mw_int16_t idx1 = 0;
	mw_int16_t idx2 = 1;
	for (idx1 = 0; idx1 < sizeof(g_boardType) / sizeof(mw_uint16_t); idx1++)
	{
		for (idx2 = 1; idx2 < BOARD_NUMBER_CNT; idx2++)
		{
			ret = ar_FindDevice(g_boardType[idx1], idx2);
			if (ret != ARS_FAILURE)
				break;
		}
	}

	return ret;
}

static mw_bool_t initBoardCard(mw_int16_t cardNumber)
{
	mw_bool_t ret = SS_FALSE;
	mw_int16_t val = 0;
	val = ar_loadslv(cardNumber, 0, 0, 0);
	ret = (val == ARS_NORMAL) ? SS_TRUE : SS_FALSE;
	return ret;
}

static mw_int16_t setTxChlRate(mw_int16_t cardNumber, mw_int16_t item, mw_uint32_t value)
{
	return ar_set_config(cardNumber, ARU_XMIT_RATE, AR_HIGH);
}

static mw_int16_t setRxChlRate(mw_int16_t cardNumber, mw_int16_t item, mw_uint32_t value)
{
	return ar_set_config(cardNumber, ARU_RECV_RATE, AR_HIGH);
}

static mw_int16_t setTxChlParity(mw_int16_t cardNumber, mw_int16_t item, mw_uint32_t value)
{
	return ar_set_config(cardNumber, ARU_PARITY, AR_ODD);
}


static mw_int16_t setInternalTest(mw_int16_t cardNumber, mw_int16_t item, mw_uint32_t value)
{
	return ar_set_config(cardNumber, ARU_INTERNAL_WRAP, AR_WRAP_OFF);
}