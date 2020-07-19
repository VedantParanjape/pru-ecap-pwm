#include <pru/io.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pru_cfg.h>
#include <pru_intc.h>
#include <rsc_types.h>
#include <pru_ecap.h>
#include "resource_table_0.h"

// ECCTL1 ( ECAP Control Reg 1)
//==========================
// CAPxPOL bits
#define EC_RISING  0x0 
#define EC_FALL NG 0x1

// CTRRSTx bits
#define EC_ABS_MODE   0x0
#define EC_DELTA_MODE 0x1

// PRESCALE bits
#define EC_BYPASS 0x0
#define EC_DIV1   0x0
#define EC_DIV2   0x1
#define EC_DIV4   0x2
#define EC_DIV6   0x3
#define EC_DIV8   0x4
#define EC_DIV10  0x5

// ECCTL2 ( ECAP Control Reg 2)
//==========================
// CONT/ONESHOT bit
#define EC_CONTINUOUS 0x0
#define EC_ONESHOT 	  0x1

// STOPVALUE bit
#define EC_EVENT1 0x0
#define EC_EVENT2 0x1
#define EC_EVENT3 0x2
#define EC_EVENT4 0x3

// RE-ARM bit
#define EC_ARM 0x1

// TSCTRSTOP bit
#define EC_FREEZE 0x0
#define EC_RUN    0x1

// SYNCO_SEL bit
#define EC_SYNCIN    0x0
#define EC_CTR_PRD   0x1
#define EC_SYNCO_DIS 0x2

// CAP/APWM mode bit
#define EC_CAP_MODE  0x0
#define EC_APWM_MODE 0x1

// APWMPOL bit
#define EC_ACTV_HI 0x0
#define EC_ACTV_LO 0x1

// Generic
#define EC_DISABLE 0x0
#define EC_ENABLE  0x1
#define EC_FORCE   0x1

int main()
{	
    // CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

	CT_ECAP.CAP1 = 0x1000;
	CT_ECAP.CTRPHS = 0x0;
	CT_ECAP.EECTL2_bit.CAP_APWM = EC_APWM_MODE;
	CT_ECAP.EECTL2_bit.APWMPOL = EC_ACTV_HI;
	CT_ECAP.EECTL2_bit.SYNCI_EN = EC_DISABLE;
	CT_ECAP.EECTL2_bit.SYNCO_SEL = EC_SYNCO_DIS;
	CT_ECAP.EECTL2_bit.TSCTRSTOP = EC_RUN;

	int counter = 0;

	while(1)
	{
		CT_ECAP.CAP2 = counter;
		__delay_cycles(20000000);
		counter = (counter+50)%4096;
	}

	return 0;
}
