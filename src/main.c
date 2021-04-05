#include "Constants.h"
#include "BasicType.h"
#include "wtapi.h"
#include "Config.h"

#include <stdio.h>

int main()
{
	mw_int32_t val = 10;
	ini_cfg_handle_t handle = S_NULL;

	//val = ar_FindDevice(0, 1);
	
	handle = createIniCfg("config.ini");

	if (handle)
	{
		val = getValInt(handle, "TCP_L", "TCP1_SEND_TO_PORT", 10000);
	}

	printf("test value = %d \n", val);
	system("pause");
	return 0;
}