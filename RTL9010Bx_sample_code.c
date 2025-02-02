//All functions can refer to RTL9010Bx_Sample_Code_Note_v0.1.pdf.

#include "RTL9010Bx_sample_code.h"

u16 param_check[12*3] = { 0x0bc4,21,0x1e3e,  0x0bc5,18,0x0199,  0x0bcc,16,0x767a,  0, 0x82c2,0x3e34, 
                                               0, 0x82ff,0x3e34,  0, 0x8251,0x4481,  0, 0x828e, 0x4481,  0, 0x8266,0x801b, 
                                               0, 0x826e,0x3400,  0, 0x8229,0xc81b,  0, 0x8231,0x2a00,  0x0ac4,16,0x0190 };

u16 nc_param_check[14] = {0xf002, 0xf007, 0xd71e, 0x606b, 0xc060, 0x2cd6, 0xea43, 0xd71e, 0x606b, 0xc060, 0x2cd6, 0xea75, 0xA01A, 0x0000};

u16 param_with_EEE_check[9*3] = { 0x0a4c,20,0x2a2e,  0x0a59,20,0x0003,  0x0a49,20,0xfb00,  0x0a42,22,0x0001, 
	                                                      0x0ab5,20,0x0002,  0x0a48,23,0xa014,  0x0bcf,19,0x0069,  0x0bc0,17,0x7088,  0x0ac0,20,0x5320 };


u8 RTL9010Bx_Initial_Configuration(void)
{
	u32 mdio_data = 0;
	u32 timer = 2000;


	mdio_write(31, 0x0bc4);
	mdio_write(21, 0x1E3E);
	mdio_write(31, 0x0bc5);
	mdio_write(18, 0x0199);

	mdio_write(31, 0x0bcc);
	mdio_write(16, 0x767A);

	mdio_write(27, 0x82C2);
	mdio_write(28, 0x3E34);
	mdio_write(27, 0x82FF);
	mdio_write(28, 0x3E34);

	mdio_write(27, 0x8251);
	mdio_write(28, 0x4481);
	mdio_write(27, 0x828E);
	mdio_write(28, 0x4481);

	mdio_write(27, 0x8266);
	mdio_write(28, 0x801B);
	mdio_write(27, 0x826E);
	mdio_write(28, 0x3400);

	mdio_write(27, 0x8229);
	mdio_write(28, 0xC81B);
	mdio_write(27, 0x8231);
	mdio_write(28, 0x2A00);

	mdio_write(31, 0x0ac4);
	mdio_write(16, 0x190);

	mdio_write(27, 0x859c);
	mdio_write(28, 0x0509);
	mdio_write(27, 0x859E);
	mdio_write(28, 0x0003);
	mdio_write(27, 0x85A0);
	mdio_write(28, 0x0002);

	mdio_write(27, 0xb820);
	mdio_write(28, 0x0010);

	mdio_write(27, 0xb830);
	mdio_write(28, 0x8000);

	mdio_write(27, 0xb800);
	mdio_data = ((u16) mdio_read(28) & 0x0040);

	while (mdio_data != 0x0040)	
	{
		mdio_data = ((u16) mdio_read(28) & 0x0040);
		timer--;
		if (timer == 0) {
			return E_TIMOUT;
		}
	}

	mdio_write(27, 0x8020);
	mdio_write(28, 0x9100);

	mdio_write(27, 0xb82e);
	mdio_write(28, 0x0001);

	mdio_write(27, 0xB820);
	mdio_write(28, 0x0290);

	mdio_write(27, 0xA012);
	mdio_write(28, 0x0000);
	mdio_write(27, 0xA014);
	mdio_write(28, 0xF002);
	mdio_write(28, 0xf007);
	mdio_write(28, 0xd71e);
	mdio_write(28, 0x606b);
	mdio_write(28, 0xc060);
	mdio_write(28, 0x2cd6);
	mdio_write(28, 0xea43);
	mdio_write(28, 0xd71e);
	mdio_write(28, 0x606b);
	mdio_write(28, 0xc060);
	mdio_write(28, 0x2cd6);
	mdio_write(28, 0xea75);
	mdio_write(28, 0xA01A);
	mdio_write(28, 0x0000);
	mdio_write(27, 0xA00A);
	mdio_write(28, 0x11ff);
	mdio_write(27, 0xA008);
	mdio_write(28, 0x11ff);
	mdio_write(27, 0xA006);
	mdio_write(28, 0x11ff);
	mdio_write(27, 0xA004);
	mdio_write(28, 0x11ff);
	mdio_write(27, 0xA002);
	mdio_write(28, 0x8a73);
	mdio_write(27, 0xA000);
	mdio_write(28, 0x8a41);
	mdio_write(27, 0xB820);
	mdio_write(28, 0x0210);

	mdio_write(27, 0xb82e);
	mdio_write(28, 0x0000);

	mdio_write(27, 0x8020);
	mdio_write(28, 0x0000);

	mdio_write(27, 0xb820);
	mdio_write(28, 0x0000);

	mdio_write(27, 0xb800); 
	mdio_data = ((u16) mdio_read(28) & 0x0040);
	timer = 2000;

	while (mdio_data == 0x0040)	
	{
		mdio_data = ((u16) mdio_read(28) & 0x0040);
		timer--;
		if (timer == 0) {
			return E_TIMOUT;
		}
	}

	mdio_write(0, 0x8000);	// PHY soft-reset
	while (mdio_data != 0x0140){	// Check soft-reset complete
		mdio_data = mdio_read(0);
	}

	return E_NOERR;
}

u8 RTL9010Bx_Initial_with_EEE_Configuration(void)
{
	u32 mdio_data = 0;
	u32 timer = 2000;


	mdio_write(31, 0x0bc4);
	mdio_write(21, 0x1E3E);
	mdio_write(31,0x0bc5);
	mdio_write(18, 0x0199);

	mdio_write(31, 0x0bcc);
	mdio_write(16, 0x767A);

	mdio_write(27, 0x82C2);
	mdio_write(28, 0x3E34);
	mdio_write(27, 0x82FF);
	mdio_write(28, 0x3E34);

	mdio_write(27, 0x8251);
	mdio_write(28, 0x4481);
	mdio_write(27, 0x828E);
	mdio_write(28, 0x4481);

	mdio_write(27, 0x8266);
	mdio_write(28, 0x801B);
	mdio_write(27, 0x826E);
	mdio_write(28, 0x3400);

	mdio_write(27, 0x8229);
	mdio_write(28, 0xC81B);
	mdio_write(27, 0x8231);
	mdio_write(28, 0x2A00);

	mdio_write(27, 0x859c);
	mdio_write(28, 0x0509);
	mdio_write(27, 0x859E);
	mdio_write(28, 0x0003);
	mdio_write(27, 0x85A0);
	mdio_write(28, 0x0002);

	mdio_write(31, 0x0ac4);
	mdio_write(16, 0x190);

	mdio_write(31, 0x0a4c);
	mdio_write(20, 0x2A2E);
	mdio_write(31, 0x0a59);
	mdio_write(20, 0x0003);
	mdio_write(31, 0x0a49);
	mdio_write(20, 0xFB00);
	mdio_write(31, 0x0a42);
	mdio_write(22, 0x0001);
	mdio_write(31, 0x0ab5);
	mdio_write(20, 0x0002);
	mdio_write(31, 0x0a48);
	mdio_write(23, 0xA014);
	mdio_write(31, 0x0bcf);
	mdio_write(19, 0x0069);
	mdio_write(31, 0x0bc0);
	mdio_write(17, 0x7088);
	mdio_write(31, 0x0ac0);
	mdio_write(20, 0x5320);

	mdio_write(27, 0xb820);
	mdio_write(28, 0x0010);

	mdio_write(27, 0xb830);
	mdio_write(28, 0x8000);

	mdio_write(27, 0xb800);
	mdio_data = ((u16) mdio_read(28) & 0x0040);

	while (mdio_data != 0x0040)	
	{
		mdio_data = ((u16) mdio_read(28) & 0x0040);
		timer--;
		if (timer == 0) {
			return E_TIMOUT;
		}
	}

	mdio_write(27, 0x8020);
	mdio_write(28, 0x9100);

	mdio_write(27, 0xb82e);
	mdio_write(28, 0x0001);

	mdio_write(27, 0xB820);
	mdio_write(28, 0x0290);

	mdio_write(27, 0xA012);
	mdio_write(28, 0x0000);
	mdio_write(27, 0xA014);
	mdio_write(28, 0xF002);
	mdio_write(28, 0xf007);
	mdio_write(28, 0xd71e);
	mdio_write(28, 0x606b);
	mdio_write(28, 0xc060);
	mdio_write(28, 0x2cd6);
	mdio_write(28, 0xea43);
	mdio_write(28, 0xd71e);
	mdio_write(28, 0x606b);
	mdio_write(28, 0xc060);
	mdio_write(28, 0x2cd6);
	mdio_write(28, 0xea75);
	mdio_write(28, 0xA01A);
	mdio_write(28, 0x0000);
	mdio_write(27, 0xA00A);
	mdio_write(28, 0x11ff);
	mdio_write(27, 0xA008);
	mdio_write(28, 0x11ff);
	mdio_write(27, 0xA006);
	mdio_write(28, 0x11ff);
	mdio_write(27, 0xA004);
	mdio_write(28, 0x11ff);
	mdio_write(27, 0xA002);
	mdio_write(28, 0x8a73);
	mdio_write(27, 0xA000);
	mdio_write(28, 0x8a41);
	mdio_write(27, 0xB820);
	mdio_write(28, 0x0210);

	mdio_write(27, 0xb82e);
	mdio_write(28, 0x0000);

	mdio_write(27, 0x8020);
	mdio_write(28, 0x0000);

	mdio_write(27, 0xb820);
	mdio_write(28, 0x0000);

	mdio_write(27, 0xb800);
	mdio_data = ((u16) mdio_read(28) & 0x0040);
	timer = 2000;

	while (mdio_data == 0x0040)	
	{
		mdio_data = ((u16) mdio_read(28) & 0x0040);
		timer--;
		if (timer == 0) {
			return E_TIMOUT;
		}
	}

	mdio_write(0, 0x8000);	// PHY soft-reset
	while (mdio_data != 0x0140){	// Check soft-reset complete
		mdio_data = mdio_read(0);
	}

	return E_NOERR;
}


u8 RTL9010Bx_Initial_Configuration_Check(void)
{
	u16 mdio_data = 0;
	u16 mdio_data_chk = 0;

	u16 page;
	u16 reg, i;
	u32 timer = 2000;


	for (i = 0; i < 12 * 3; i = i + 3)
	{
		page = param_check[i];
		mdio_data_chk = param_check[i + 2];
		reg = param_check[i + 1];
		if (page == 0)
		{
			mdio_write(27, reg);
			mdio_data = mdio_read(28);
		}
		else
		{
			mdio_write(31, page);
			mdio_data = mdio_read(reg);
		}

		if (mdio_data_chk != mdio_data)
		{
			DBGMSG(("%dth param error page=0x%04X reg=0x%04X data=0x%04X\r\n", i / 3, page, reg, mdio_data));
			return E_FAILED;
		}
	}

	mdio_write(27, 0xb820);
	mdio_write(28, 0x0010);

	mdio_write(27, 0xb830);
	mdio_write(28, 0x8000);

	mdio_write(27, 0xb800);
	mdio_data = ((u16) mdio_read(28) & 0x0040);

	while (mdio_data != 0x0040)	
	{
		mdio_data = ((u16) mdio_read(28) & 0x0040);
		timer--;
		if (timer == 0) {
			return E_TIMOUT;
		}
	}

	mdio_write(31, 0xa01);
	for(i=0; i<14; i++){
		reg = nc_param_check[i];
		mdio_write(17, i);
		mdio_data = mdio_read(18);
		if (reg != mdio_data)
		{
			DBGMSG(("%dth nctl param error data=0x%04X  expected_data=0x%04X\r\n", i, mdio_data, reg));
			return E_FAILED;
		}
	}

	mdio_write(27, 0xb820);
	mdio_write(28, 0x0000);

	mdio_write(27, 0xb800);
	mdio_data = ((u16) mdio_read(28) & 0x0040);
	timer = 2000;

	while (mdio_data == 0x0040)	
	{
		mdio_data = ((u16) mdio_read(28) & 0x0040);
		timer--;
		if (timer == 0) {
			return E_TIMOUT;
		}
	}

	return E_NOERR;
}

u8 RTL9010Bx_Initial_with_EEE_Configuration_Check(void)
{
	u16 mdio_data = 0;
	u16 mdio_data_chk = 0;

	u16 page;
	u16 reg, i;
	u32 timer = 2000;


	for (i = 0; i < 12 * 3; i = i + 3)
	{
		page = param_check[i];
		mdio_data_chk = param_check[i + 2];
		reg = param_check[i + 1];
		if (page == 0)
		{
			mdio_write(27, reg);
			mdio_data = mdio_read(28);
		}
		else
		{
			mdio_write(31, page);
			mdio_data = mdio_read(reg);
		}

		if (mdio_data_chk != mdio_data)
		{
			DBGMSG(("%dth param error page=0x%04X reg=0x%04X data=0x%04X\r\n", i / 3, page, reg, mdio_data));
			return E_FAILED;
		}
	}


	for (i = 0; i < 9 * 3; i = i + 3)
	{
		page = param_with_EEE_check[i];
		mdio_data_chk = param_with_EEE_check[i + 2];
		reg = param_with_EEE_check[i + 1];
		if (page == 0)
		{
			mdio_write(27, reg);
			mdio_data = mdio_read(28);
		}
		else
		{
			mdio_write(31, page);
			mdio_data = mdio_read(reg);
		}

		if (mdio_data_chk != mdio_data)
		{
			DBGMSG(("%dth EEE param error page=0x%04X reg=0x%04X data=0x%04X\r\n", i / 3, page, reg, mdio_data));
			return E_FAILED;
		}
	}

	mdio_write(27, 0xb820);
	mdio_write(28, 0x0010);
	mdio_write(27, 0xb830);
	mdio_write(28, 0x8000);

	mdio_write(27, 0xb800);
	mdio_data = ((u16) mdio_read(28) & 0x0040);

	while (mdio_data != 0x0040)	
	{
		mdio_data = ((u16) mdio_read(28) & 0x0040);
		timer--;
		if (timer == 0) {
			return E_TIMOUT;
		}
	}

	mdio_write(31, 0xa01);
	for(i=0; i<14; i++){
		reg = nc_param_check[i];
		mdio_write(17, i);
		mdio_data = mdio_read(18);
		if (reg != mdio_data)
		{
			DBGMSG(("%dth nctl param error data=0x%04X  expected_data=0x%04X\r\n", i, mdio_data, reg));
			return E_FAILED;
		}
	}

	mdio_write(27, 0xb820);
	mdio_write(28, 0x0000);

	mdio_write(27, 0xb800); 
	mdio_data = ((u16) mdio_read(28) & 0x0040);
	timer = 2000;

	while (mdio_data == 0x0040)	
	{
		mdio_data = ((u16) mdio_read(28) & 0x0040);
		timer--;
		if (timer == 0) {
			return E_TIMOUT;
		}
	}

	return E_NOERR;
}


u8 RTL9010Bx_GetLinkStatus(u8 SpeedType) 
{
	u16 mdio_data = 0;

	u16 loc_ok = 0;
	u16 rem_ok = 0;
	u16 link_status = 0;
	u16 pcs_status;
	u8 pcs_status_checkOK=0;


	mdio_data = mdio_read(1);
	mdio_data = mdio_read(1);//Read twice for current link status.
	link_status = (u16)(mdio_data & 0x0004);

	mdio_write(31, 0x0A60);
	mdio_data = mdio_read(16);
	pcs_status = (u16)(mdio_data & 0x00FF);

	if(SpeedType == Speed_1000BaseT1){
		mdio_data = mdio_read(10);
		loc_ok = ((u16)(mdio_data & 0x2000) == 0x2000);
		rem_ok = ((u16)(mdio_data & 0x1000) == 0x1000);
		if(pcs_status == 0x0037)
			pcs_status_checkOK = 1;
	} else {
		mdio_write(31, 0x0A64);
		mdio_data = mdio_read(23);
		loc_ok = ((u16)(mdio_data & 0x0004) == 0x0004);
		rem_ok = ((u16)(mdio_data & 0x0400) == 0x0400);
		if(pcs_status == 0x0044)
			pcs_status_checkOK = 1;
	}

	DBGMSG(("link_status = 0x%04X\r\n", link_status));
	DBGMSG(("loc_ok = 0x%04X\r\n", loc_ok));
	DBGMSG(("rem_ok = 0x%04X\r\n", rem_ok));
	DBGMSG(("pcs_status = 0x%04X\r\n", pcs_status));

	if ((link_status == 0x0004) & (loc_ok) & (rem_ok) & pcs_status_checkOK)
		return LinkUp;
	else 
		return LinkDown;

}

u8 RTL9010Bx_CableFaultLocationAndDiagnosis(u16* cable_length)
{
	u32 mdio_data = 0;
	u16 cable_st;

	//Enable RTCT and start to test
	mdio_write(31, 0x0A42);    //PAGSR:change page to 0xA42
	mdio_write(17, 0x0001); //RTCTCR: bit0 = 1,rtct_en, enable RTCT and start to test

	//Wait RTCT finished
	while (mdio_data != 0x8000){   //RTCTCR: bit15 = 1, check RTCT is finished
		mdio_data = mdio_read(17);
		mdio_data = mdio_data & 0x8000;
	}

	//Get channel status and cable length
	mdio_write(31, 0x0A43);    //write reg31,page select register

	mdio_write(27, 0x8022);    //PHYSRAD
	mdio_data = mdio_read(28);  //PHYSRD: this value means cable status
	cable_st = mdio_data & 0xFF00;

	//normal mode
	if (cable_st == 0x6000) {
		*cable_length = 0xFFFF; // Cable is normal.
		return CABLE_NORMAL;
	}

	//open mode
	if (cable_st == 0x4800){ 
		mdio_write(27, 0x8023);
		mdio_data = mdio_read(28);
		mdio_data = mdio_data * 2 / 15;
		*cable_length = (mdio_data & 0xFFFF);
		return CABLE_OPEN;
	}

	if (cable_st == 0x5000){
		return CABLE_SHORT;
	}

	return CABLE_UNKNOWN;
}

u8 RTL9010Bx_Soft_Reset(void)
{
	u32 mdio_data = 0;
	u32 timer = 2000;

	mdio_write(0, 0x8000);	// PHY soft-reset

	while (mdio_data != 0x0140){	// Check soft-reset complete

		mdio_data = mdio_read(0);
		if(mdio_data == 0xFFFF)
			return E_NOTRDY;

		timer--;
		if (timer == 0){
			return E_TIMOUT;
		}
	}

	return E_NOERR;
}

u8 RTL9010Bx_SQI(u8 SpeedType)
{
	u32 mdio_data = 0;
	u8 SQI = 0;


	if (RTL9010Bx_GetLinkStatus(SpeedType) == LinkDown){
		DBGMSG(("Has no link, no SQI information\r\n"));	
		return 0;
	}

	mdio_write(0x1b, 0xd106);
	mdio_data = mdio_read(0x1c);
	SQI = (mdio_data>>1)&7;
	DBGMSG(("SQI value = 0x%04X\r\n", ((u16)mdio_data >> 1) & 7));

	return SQI;
}

u8 RTL9010Bx_Check_Linkup(void)
{
	u16 mdio_data = 0;
	u32 counter = 1000;   //the value of counter is dynamic


	while (0x0004 != (mdio_data & 0x0004)){
		counter--;
		mdio_data = mdio_read(1);
		mdio_data = mdio_read(1); //BMSR:bit2 = 1 linked; bit2 = 0 not linked, read this reg twice for the current link status
		if (mdio_data == 0xFFFF)
			return E_NOTRDY;
		if (0 == counter)
			return E_TIMOUT;

	}

	return E_NOERR;
}

u8 RTL9010Bx_Sleep_initial(void)
{
	u32 mdio_data = 0;


	/*initial setting*/
	mdio_write(31, 0x0a51);    // PAGSR:change Page to 0x0A51
	mdio_data = mdio_read(0x13);  // enable sleep mode
	mdio_write(0x13, mdio_data | 0x0001);

	mdio_write(31, 0x0a59);    // PAGSR:change Page to 0x0A59
	mdio_data = mdio_read(0x14);  // enable oam
	mdio_write(0x14, mdio_data | 0x0002);

	if(RTL9010Bx_Soft_Reset() == E_NOERR) {   // soft - reset
		mdio_write(31, 0x0a42);  // PAGSR:change Page to 0x0A42
		mdio_data = mdio_read(20);
		mdio_write(20, (mdio_data & 0xfffb)); // diasble ,GINMR,page 0xa42,reg20.bit2=0
		return E_NOERR;
	}
	else {
		return E_FAILED;
	}

}

u8 RTL9010Bx_Sleep_reject(void)
{
	u16 mdio_data = 0;


	mdio_write(31, 0x0A42);   //PAGSR:change Page to 0x0A47
	mdio_data = mdio_read (21);
	mdio_write(21, mdio_data | 0x0400);

	DBGMSG(("Reject Sleep request\r\n"));
	return E_NOERR;
}

u8 RTL9010Bx_Sleep_request(void)
{
	u32 mdio_data = 0;

	if (RTL9010Bx_Check_Linkup() == E_NOERR){
		DBGMSG(("PHY is in normal mode and link up; start to sleep \r\n"));
	}
	else {//PHY is not link up and timeout
		DBGMSG(("PHY is not link up, can't sleep\r\n"));
		return E_FAILED;
	}

	mdio_write(31, 0x0A42);  // PAGSR:change Page to 0x0A42
	mdio_data = mdio_read(21);
	mdio_write(21, (mdio_data | 0x0200)); //SLPCR: page 0xa42,reg21,bit[9]=1//mac sends sleep request to PHY
	return E_NOERR;
}

u8 RTL9010Bx_General_purpose_sub_status(u16* general_sub_status)
{
	u32 mdio_data = 0;

	//read sub-flag reg
	mdio_write(0x1f, 0xa47); //PAGSR:changge page to 0xa43
	mdio_data = mdio_read(0x15);//GPSSFR

	if(mdio_data == 0xFFFF)
		return E_NOTRDY;

	if (0x0200 == (mdio_data & 0x0200)){//intr_sleep_ack
		DBGMSG(("the sub-flag: PHY has once entered SLEEP_ACK state\r\n"));
		BIT_SET((*general_sub_status),GENERAL_INTERRUPT_SUB_STATUS_SLEEP_ACK);
	}
	else if (0x0400 == (mdio_data & 0x0400)){//intr_sleep_fail
		DBGMSG(("the sub-flag: PHY has once entered SLEEP_FAIL state\r\n"));
		BIT_SET((*general_sub_status),GENERAL_INTERRUPT_SUB_STATUS_SLEEP_FAIL);
	}
	else if (0x1000 == (mdio_data & 0x1000)) {//intr_LPS_WUR_encode
		DBGMSG(("the sub-flag: LPS and WUR encode at the same time\r\n"));
		BIT_SET((*general_sub_status),GENERAL_INTERRUPT_SUB_STATUS_LPS_WUR);
	}

	return E_NOERR;
}

u8 RTL9010Bx_General_Interrupt_status(u16* general_int_status)
{
	//if MAC receives a low signal via INTB pin, then read general status

	u32 mdio_data = 0;

	mdio_write(0x1f, 0xa43); //PAGSR:changge page to 0xa43
	mdio_data = mdio_read(0x1d);

	if(mdio_data == 0xFFFF)
		return E_NOTRDY;
	DBGMSG(("mdio_data= 0x%04X\r\n",mdio_data));	

	if (BIT_TST(mdio_data,0)){//PHY status changed -> op mode change
		BIT_SET((*general_int_status),GENERAL_INTERRUPT_STATUS_PHY_STATUS_CHANGED);
		DBGMSG(("PHY status changed\r\n"));
	}

	if (BIT_TST(mdio_data,2)){//General Purpose Interrupt
		DBGMSG(("General Purpose Interrupt\r\n"));
		BIT_SET((*general_int_status),GENERAL_INTERRUPT_STATUS_GENERAL_PURPOSE);
	}

	if (BIT_TST(mdio_data,4)){//link status change 
		DBGMSG(("link status changed\r\n"));
		BIT_SET((*general_int_status),GENERAL_INTERRUPT_STATUS_LINK_STATUS_CHANGED);
	}

	if (BIT_TST(mdio_data,8)){// PTP interrupt
		DBGMSG(("PTP event occured\r\n"));
		BIT_SET((*general_int_status),GENERAL_INTERRUPT_STATUS_PTP_EVENT);
	}

	if (BIT_TST(mdio_data,11)){//PHT Fatal Error
		DBGMSG(("PHY Fatal Error occured\r\n"));
		BIT_SET((*general_int_status),GENERAL_INTERRUPT_STATUS_PHY_FATAL_ERROR);
	}

	return E_NOERR;
}

u8 RTL9010Bx_General_Interrupt_setting(void)
{
	//enable all general interrupt: default value is enabled
	mdio_write(0x1f, 0x0a42);   //PAGSR:change Page to 0x0a42
	mdio_write(0x12, 0xffff);   

	mdio_write(0x1f,0x0a43);
	mdio_read(0x1d); // read clear;

	//disable general interrupt mask
	//note: interrupt mask is optional, if the mask of the specified interrupt is enabled, it will not inform MAC when the corresponding event occurs.
	mdio_write(0x1f,0x0a42);
	mdio_write(0x14, 0x0000);//GINMR:disable general interrupt mask,the default value = 0xffff

	return E_NOERR;
}

u8 RTL9010Bx_OP_Interrupt_setting(void)
{
	//enable all OP interrupt: default value is enabled

	mdio_write(0x1b, 0xdd0c);//OPINER1
	mdio_write(0x1c, 0xffff);

	mdio_write(0x1b, 0xdd14);//OPINER2
	mdio_write(0x1c, 0xffff);

	mdio_write(0x1b, 0xdd1c);//OPINER3
	mdio_write(0x1c, 0xffff);

	//disable all op interrupt mask
	mdio_write(0x1b, 0xdd0e);//OPINMR1
	mdio_write(0x1c, 0x0000);
	mdio_write(0x1b, 0xdd16);//OPINMR2
	mdio_write(0x1c, 0x0000);
	mdio_write(0x1b, 0xdd1e);//OPINMR3
	mdio_write(0x1c, 0x0000);

	// read clear

	mdio_write(0x1b, 0xdd08);//OPINMR1
	mdio_read(0x1c);
	mdio_write(0x1b, 0xdd10);//OPINMR2
	mdio_read(0x1c);
	mdio_write(0x1b, 0xdd18);//OPINMR3
	mdio_read(0x1c);

	return E_NOERR;
}

u8 RTL9010Bx_OP_Interrupt_status(u32* op_status)
{
	u32 mdio_data0 = 0;
	u32 mdio_data1= 0;
	u32 mdio_data2 = 0;

	//if MAC receives a low signal via INTB pin, then read OP status regs: OPINSR1,OPINSR2,OPINSR3
	
	mdio_write(0x1b, 0xdd08); //read OPINSR1
	mdio_data0 = mdio_read(0x1c);
	if(mdio_data0 == 0xFFFF)
		return E_NOTRDY;
	mdio_write(0x1b, 0xdd10); //read OPINSR2
	mdio_data1 = mdio_read(0x1c);

	mdio_write(0x1b, 0xdd18); //read OPINSR3
	mdio_data2 = mdio_read(0x1c);

	DBGMSG(("OPINSR1 = 0x%04X\r\n", mdio_data0));
	DBGMSG(("OPINSR2 = 0x%04X\r\n", mdio_data1));
	DBGMSG(("OPINSR3 = 0x%04X\r\n", mdio_data2));

	//analyze mdio_data0->OPINSR1

	if (BIT_TST(mdio_data0,1)){
		DBGMSG(("Transition to SLEEP by UV on DVDD_MII\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_TRANS_TO_SLEEP_BY_UV_DVDD_MII);
	}
	if (BIT_TST(mdio_data0,2)){
		DBGMSG(("Transition to SLEEP by UV on DVDD09\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_TRANS_TO_SLEEP_BY_UV_DVDD09);
	}
	if (BIT_TST(mdio_data0,3)){
		DBGMSG(("Transition to SLEEP by UV on AVDD09\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_TRANS_TO_SLEEP_BY_UV_AVDD09);
	}
	if (BIT_TST(mdio_data0,4)){
		DBGMSG(("Transition to SLEEP by UV on DVDD33\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_TRANS_TO_SLEEP_BY_UV_DVDD33);
	}
	if (BIT_TST(mdio_data0,5)){
		DBGMSG(("Transition to SLEEP by UV on AVDD33\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_TRANS_TO_SLEEP_BY_UV_AVDD33);
	}
	if (BIT_TST(mdio_data0,7)){//host command to sleep mode.(OP go to Sleep command)
		DBGMSG(("Transition to SLEEP by OP go to Sleep command\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_TRANS_TO_SLEEP_BY_HOST_CMD);
	}

	//analyze mdio_data1->OPINSR2

	if (BIT_TST(mdio_data1,0)){
		DBGMSG(("Indicates recovery of UV on AVDD33 has occurred\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_REC_UV_AVDD33);
	}
	if (BIT_TST(mdio_data1,1)){
		DBGMSG(("Indicates recovery of UV on DVDD33 has occurred\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_REC_UV_DVDD33);
	}
	if (BIT_TST(mdio_data1,2)){
		DBGMSG(("Indicates recovery of UV on AVDD09 has occurred\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_REC_UV_AVDD09);
	}
	if (BIT_TST(mdio_data1,3)){
		DBGMSG(("Indicates recovery of UV on DVDD09 has occurred\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_REC_UV_DVDD09);
	}
	if (BIT_TST(mdio_data1,4)){
		DBGMSG(("Indicates recovery of UV on DVDD_MII has occurred\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_REC_UV_DVDD_MII);
	}
	if (BIT_TST(mdio_data1,11)){
		DBGMSG(("OT event occurred\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_OT_EVENT);
	}

	//analyze mdio_data3->OPINSR3

	if (BIT_TST(mdio_data2,0)){
		DBGMSG(("PHY is woken up by remote wake up\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_WOKEUP_BY_REM_WAKE);
		
	}
	if (BIT_TST(mdio_data2,5)){
		DBGMSG(("PHY received WUR\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_RECEIVE_WUR);
	}
	if (BIT_TST(mdio_data2,10)){
		DBGMSG(("PHY is woken up by local wakeup\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_WOKEUP_BY_LOC_WAKE);

	}
	if (BIT_TST(mdio_data2,11)){
		DBGMSG(("PHY is powered on\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_PHY_PWR_ON);
	}

	if (BIT_TST(mdio_data2,14)){
		DBGMSG(("Reset is active by PHYRSTB pin\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_RESET_PHYRSTB);
	}
	if (BIT_TST(mdio_data2,15)){
		DBGMSG(("Reset is active by the MDIO command\r\n"));
		BIT_SET(*op_status,OP_INTERRUPT_STATUS_RESET_MDIO);
	}
	return E_NOERR;
}

u8 RTL9010Bx_Set_lwake_edge(u8 edge_select)
{
	u16 mdio_data = 0;

	mdio_write(0x1b, 0xdc0c); //read OPCR1
	mdio_data = mdio_read(0x1c);
	if(mdio_data == 0xFFFF)
		return E_NOTRDY;

	if(edge_select == Falling_edge_detection) 
		BIT_SET(mdio_data, 5);
	else if(edge_select == Rising_edge_detection)
		BIT_CLR(mdio_data, 5);
	else
		return E_INVALD;

	mdio_write(0x1b, 0xdc0c); 
	mdio_write(0x1c, mdio_data); 

	return E_NOERR;
}

u8 RTL9010Bx_Get_lwake_edge(void)
{
	u16 mdio_data = 0;

	mdio_write(0x1b, 0xdc0c); //read OPCR1
	mdio_data = mdio_read(0x1c);
	if(mdio_data == 0xFFFF)
		return E_NOTRDY;

	if(BIT_TST(mdio_data,5))
		return Falling_edge_detection;
	else
		return Rising_edge_detection;
}

u8 RTL9010Bx_Enable_rwake(void)
{
	u16 mdio_data = 0;

	mdio_write(0x1b, 0xdc0c); //read OPCR1
	mdio_data = mdio_read(0x1c);
	if(mdio_data == 0xFFFF)
		return E_NOTRDY;

	BIT_CLR(mdio_data, 0);
	mdio_write(0x1b, 0xdc0c); 
	mdio_write(0x1c, mdio_data); 
	return E_NOERR;
}

u8 RTL9010Bx_Disable_rwake(void)
{
	u16 mdio_data = 0;

	mdio_write(0x1b, 0xdc0c); //read OPCR1
	mdio_data = mdio_read(0x1c);
	if(mdio_data == 0xFFFF)
		return E_NOTRDY;

	BIT_SET(mdio_data, 0);
	mdio_write(0x1b, 0xdc0c); 
	mdio_write(0x1c, mdio_data); 
	return E_NOERR;
}

u8 RTL9010Bx_Check_rwake_en_dis(void)
{
	u16 mdio_data = 0;

	mdio_write(0x1b, 0xdc0c); //read OPCR1
	mdio_data = mdio_read(0x1c);
	if(mdio_data == 0xFFFF)
		return E_NOTRDY;

	return (BIT_TST(mdio_data,0));
	//1: rwake is disabled, 0: rwake is enabled.
}

u8 RTL9010Bx_Enable_lwake_to_rwake(void)
{
	u16 mdio_data = 0;

	mdio_write(0x1b, 0xdc0e); //read RWCR
	mdio_data = mdio_read(0x1c);
	if(mdio_data == 0xFFFF)
		return E_NOTRDY;

	BIT_SET(mdio_data, 0);

	mdio_write(0x1b, 0xdc0e); 
	mdio_write(0x1c, mdio_data); 
	return E_NOERR;
}

u8 RTL9010Bx_Disable_lwake_to_rwake(void)
{
	u16 mdio_data = 0;

	mdio_write(0x1b, 0xdc0e); //read RWCR
	mdio_data = mdio_read(0x1c);
	if(mdio_data == 0xFFFF)
		return E_NOTRDY;

	BIT_CLR(mdio_data, 0);

	mdio_write(0x1b, 0xdc0e); 
	mdio_write(0x1c, mdio_data); 

	return E_NOERR;
}

u8 RTL9010Bx_Check_lwake_to_rwake(void)
{
	u16 mdio_data = 0;

	mdio_write(0x1b, 0xdc0e); //read RWCR
	mdio_data = mdio_read(0x1c);
	if(mdio_data == 0xFFFF)
		return E_NOTRDY;

	if(BIT_TST(mdio_data, 0))
		return Lwake_to_rwake_is_enabled;
	else
		return Lwake_to_rwake_is_disabled;

}

u8 RTL9010Bx_Get_OP_state(void)
{
	u16 mdio_data=0;

	mdio_write(0x1b, 0xdf10); //read OPMR
	mdio_data = mdio_read(0x1c);
	if(mdio_data == 0xFFFF)
		return OP_STATE_UNKNOWN;

	if((mdio_data&0xff) == 0x20)
		return OP_STATE_STANDBY;
	else if((mdio_data&0xff) == 0x30)
		return OP_STATE_NORMAL;
	else if((mdio_data&0xff) == 0x31)
		return OP_STATE_SAFETY;
	else
		return OP_STATE_UNKNOWN;
}

u8 RTL9010Bx_Set_OP_state(u8 op_cmd)
{
	u16 mdio_data=0;

	mdio_write(0x1b, 0xdd00); //read OPCR2
	mdio_data = mdio_read(0x1c);
	if(mdio_data == 0xFFFF)
		return E_NOTRDY;
	if(op_cmd == OP_CMD_GOTO_STANDBY) {
		mdio_write(0x1b, 0xdd00); //read OPCR2
		mdio_data&=~(0x001f);
		mdio_write(0x1c, (mdio_data|0x12)); 
	}
	else if(op_cmd == OP_CMD_GOTO_SLEEP){
		mdio_write(0x1b, 0xdd00); //read OPCR2
		mdio_data&=~(0x001f);
		mdio_write(0x1c, (mdio_data|0x14)); 
	}
	else if(op_cmd == OP_CMD_GOTO_NORMAL){
		mdio_write(0x1b, 0xdd00); //read OPCR2
		mdio_data&=~(0x001f);
		mdio_write(0x1c, (mdio_data|0x13)); 
		mdio_write(0x1b, 0xdd20); //read OPCR4
		mdio_data = mdio_read(0x1c);
		mdio_data&=~(0x000f);
		mdio_write(0x1c, (mdio_data|0x0B)); 
	}
	else
		return E_INVALD;
		
	return E_NOERR;
}

u8 RTL9010Bx_HOSTCMD_send_rwake(void)
{
	u16 mdio_data=0;

	mdio_write(0x1b, 0xdd20); //read OPCR4
	mdio_data = mdio_read(0x1c);
	if(mdio_data == 0xFFFF)
		return E_NOTRDY;

	BIT_SET(mdio_data,4);

	mdio_write(0x1b, 0xdd20); //read OPCR4
	mdio_write(0x1c, mdio_data); 

	return E_NOERR;
}



u8 RTL9010Bx_Sleep_cap_check(void)
{
	u32 mdio_data = 0;

	mdio_write(31, 0x0a51);    // PAGSR:change Page to 0x0A51
	mdio_data = mdio_read(0x13);  // enable sleep mode, SLPCAP: reg20.bit0=1; bit[15:1]reserved RO
	if(mdio_data!=0xFFFF)
		return (mdio_data & 1);
	else
		return E_NOTRDY;

}

u8 RTL9010Bx_xMII_driving_strength(u8 RGMII_Voltage)
{
	u32 mdio_data = 0;


	if((RGMII_Voltage > Typical_xMII_1V8) ||(RGMII_Voltage < Typical_xMII_3V3))
		return E_INVALD;

	mdio_write(31, 0x0a4c);
	mdio_data = (mdio_read(18) & 0xc7ff);

	switch (RGMII_Voltage){
		case Typical_xMII_3V3:

			BIT_SET(mdio_data, 12); // IO_3.3V
			mdio_write(31, 0x0a4c);
			mdio_write(18, mdio_data);

			wait_x_ms(500);

			mdio_write(31, 0x0d41);
			mdio_data = mdio_read(18);

			BIT_CLR(mdio_data, 12); // rg_pad_rxd0_e2
			BIT_SET(mdio_data, 10); // rg_pad_rxd0_sr
			BIT_CLR(mdio_data, 4); // rg_pad_rxd1_e2
			BIT_SET(mdio_data, 2); // rg_pad_rxd1_sr
			mdio_write(18, mdio_data);

			mdio_data = mdio_read(19);

			BIT_CLR(mdio_data, 12); // rg_pad_rxd2_e2
			BIT_SET(mdio_data, 10); // rg_pad_rxd2_sr
			BIT_CLR(mdio_data, 4); // rg_pad_rxd3_e2
			BIT_SET(mdio_data, 2); // rg_pad_rxd3_sr
			mdio_write(19, mdio_data);

			mdio_data = mdio_read(20);

			BIT_CLR(mdio_data, 12); // rg_pad_rxdv_e2
			BIT_SET(mdio_data, 10); // rg_pad_rxdv_sr
			mdio_write(20, mdio_data);

			mdio_data = mdio_read(21);

			BIT_CLR(mdio_data, 12); // rg_pad_rxc_e2
			BIT_SET(mdio_data, 10); // rg_pad_rxc_sr
			mdio_write(21, mdio_data);

			mdio_write(31, 0x0d42);
			mdio_write(23, 0x057f);
			break;

		case Typical_xMII_2V5:

			BIT_SET(mdio_data, 11); // IO_2.5V
			mdio_write(31, 0x0a4c);
			mdio_write(18, mdio_data);

			wait_x_ms(500);

			mdio_write(31, 0x0d41);
			mdio_data = mdio_read(18);

			BIT_CLR(mdio_data, 12); // rg_pad_rxd0_e2
			BIT_SET(mdio_data, 10); // rg_pad_rxd0_sr
			BIT_CLR(mdio_data, 4); // rg_pad_rxd1_e2
			BIT_SET(mdio_data, 2); // rg_pad_rxd1_sr
			mdio_write(18, mdio_data);

			mdio_data = mdio_read(19);

			BIT_CLR(mdio_data, 12); // rg_pad_rxd2_e2
			BIT_SET(mdio_data, 10); // rg_pad_rxd2_sr
			BIT_CLR(mdio_data, 4); // rg_pad_rxd3_e2
			BIT_SET(mdio_data, 2); // rg_pad_rxd3_sr
			mdio_write(19, mdio_data);

			mdio_data = mdio_read(20);

			BIT_CLR(mdio_data, 12); // rg_pad_rxdv_e2
			BIT_SET(mdio_data, 10); // rg_pad_rxdv_sr
			mdio_write(20, mdio_data);

			mdio_data = mdio_read(21);

			BIT_CLR(mdio_data, 12); // rg_pad_rxc_e2
			BIT_SET(mdio_data, 10); // rg_pad_rxc_sr
			mdio_write(21, mdio_data);

			mdio_write(31, 0x0d42);
			mdio_write(23, 0x057f);
			break;

		case Typical_xMII_1V8:

			BIT_SET(mdio_data, 13); // IO_1.8V
			mdio_write(31, 0x0a4c);
			mdio_write(18, mdio_data);

			wait_x_ms(500);

			mdio_write(31, 0x0d41);
			mdio_data = mdio_read(18);

			BIT_CLR(mdio_data, 12); // rg_pad_rxd0_e2
			BIT_SET(mdio_data, 10); // rg_pad_rxd0_sr
			BIT_CLR(mdio_data, 4); // rg_pad_rxd1_e2
			BIT_SET(mdio_data, 2); // rg_pad_rxd1_sr
			mdio_write(18, mdio_data);

			mdio_data = mdio_read(19);

			BIT_CLR(mdio_data, 12); // rg_pad_rxd2_e2
			BIT_SET(mdio_data, 10); // rg_pad_rxd2_sr
			BIT_CLR(mdio_data, 4); // rg_pad_rxd3_e2
			BIT_SET(mdio_data, 2); // rg_pad_rxd3_sr
			mdio_write(19, mdio_data);

			mdio_data = mdio_read(20);

			BIT_CLR(mdio_data, 12); // rg_pad_rxdv_e2
			BIT_SET(mdio_data, 10); // rg_pad_rxdv_sr
			mdio_write(20, mdio_data);

			mdio_data = mdio_read(21);

			BIT_CLR(mdio_data, 12); // rg_pad_rxc_e2
			BIT_SET(mdio_data, 10); // rg_pad_rxc_sr
			mdio_write(21, mdio_data);

			mdio_write(31, 0x0d42);
			mdio_write(23, 0x057f);
			break;

		default:
			break;
	}

	return E_NOERR;
}

u8 RTL9010Bx_PHY_ready(void)
{
	u32 mdio_data = 0;
	u32 timer = 2000;

	while (mdio_data!=0x0003){
		mdio_write(0x1f, 0x0a42);
		mdio_data = mdio_read(0x10);
		mdio_data = mdio_data & 0x0007;

		timer--;
		if (timer == 0){
			DBGMSG(("PHY NOT ready!!! Reg(16) = 0x%04X\r\n", (u16)mdio_data));
			return E_TIMOUT;
		}
	}

	DBGMSG(("PHY ready!!! Reg(16) = 0x%04X\r\n", (u16)mdio_data));
	return E_NOERR;
}

u8 RTL9010Bx_Get_PCS_status(u8 SpeedType)
{
	//check PCS status
	u32 mdio_data = 0;
	s16 pcs_state = 0;

	mdio_write(0x1f, 0xa60);//change page to 0xa60
	mdio_data = mdio_read(0x10)&0x00ff;// PCS State:page0xa60,reg0x10, bit7:0->PCS state

	if(mdio_data == 0xFF)
		return PCS_STATE_UNKNOWN;

	if(SpeedType == Speed_100BaseT1){
		switch (mdio_data){
			case 0x40://Disable Transmitter State
				DBGMSG(("disable transmitter state\r\n"));
				pcs_state = PCS_STATE_DISABLE_TRANSMITTER;
				break;
			case 0x41://slave silent state
				DBGMSG(("slave silent state\r\n"));
				pcs_state = PCS_STATE_SLAVE_SILENT;
				break;
			case 0x42://training state
				DBGMSG(("training state\r\n"));
				pcs_state = PCS_STATE_TRAINING_STATE;
				break;
			case 0x43://SEND IDLE 
				DBGMSG(("SEND IDLE state\r\n"));
				pcs_state = PCS_STATE_SEND_IDLE;
				break;
			case 0x44://SEND IDLE or DATA
				DBGMSG(("SEND IDLE OR DATA state\r\n"));
				pcs_state = PCS_STATE_SEND_IDLE_OR_DATA;
				break;
			default:
				DBGMSG(("error\n"));
				pcs_state = PCS_STATE_UNKNOWN;
				break;
		}
	}
	else if(SpeedType == Speed_1000BaseT1){
		if((mdio_data&0x80) == 0x80){
			DBGMSG(("LINK SYNCHRONIZATION state\r\n"));
			pcs_state = PCS_STATE_LINK_SYNCHRONIZATION;
		}
		else{ 
			switch (mdio_data){
				case 0x31:
					DBGMSG(("SILENT WAIT state\r\n"));
					pcs_state = PCS_STATE_SILENT_WAIT;
					break;
				case 0x32:
					DBGMSG(("TRAINING state\r\n"));
					pcs_state = PCS_STATE_TRAINING_STATE;
					break;
				case 0x37:
					DBGMSG(("LINK UP state\r\n"));
					pcs_state = PCS_STATE_LINK_UP;
					break;
				default:
					DBGMSG(("error\n"));
					pcs_state = PCS_STATE_UNKNOWN;
					break;
			}
		}
	}
	else
		pcs_state = PCS_STATE_UNKNOWN;

	return pcs_state;
}

u8 RTL9010Bx_PCS_loopback(void)
{
	u32 mdio_data = 0;

	mdio_data = mdio_read(0x0);
	if (mdio_data == 0xFFFF)
		return E_NOTRDY;

	mdio_write(0,	BIT_SET(mdio_data,14));//set BMCR bit14=1-> enable PCS loopback

	return E_NOERR;
}

u8 RTL9010Bx_MDI_loopback(void)
{
	u32 mdio_data = 0;

	mdio_data = mdio_read(0x18);
	if (mdio_data == 0xFFFF)
		return E_NOTRDY;

	mdio_write(0x18, BIT_SET(mdio_data,10)); //set PHYCR bit10=1-> enable MDI loopback

	return E_NOERR;
}

u8 RTL9010Bx_Remote_loopback(void)
{
	u32 mdio_data = 0;

	mdio_write(0x1b, 0xc800);
	mdio_data = mdio_read(0x1c); //IPGR1 address 0xc800
	if (mdio_data == 0xFFFF)
		return E_NOTRDY;

	BIT_CLR(mdio_data,5);
	BIT_SET(mdio_data,4);//set IPGR1 bit5:4=b'01

	mdio_write(0x1b, 0xc800);
	mdio_write(0x1c, mdio_data);

	return E_NOERR;
}

u8 RTL9010Bx_IOL_test(u8 TestMode_selection, u8 SpeedType)
{
	u32 mdio_data = 0;

	mdio_data = mdio_read(0x09);
	if(mdio_data == 0xFFFF)
		return E_NOTRDY;

	if(SpeedType == Speed_1000BaseT1){
		DBGMSG(("Speed_1000BaseT1\r\n"));
		switch(TestMode_selection){

			case 2://Test Mode2
				DBGMSG(("Test Mode 2\r\n"));
				mdio_write(0x09, (mdio_data & 0x1FFF) | 0x4000);//set reg PHYCR bit15:13 = 010
				break;

			case 4://Test Mode4
				DBGMSG(("Test Mode 4\r\n"));
				mdio_write(0x09, (mdio_data & 0x1FFF) | 0x8000);//set reg PHYCR bit15:13 = 100
				break;

			case 5://Test Mode5
				DBGMSG(("Test Mode 5\r\n"));
				mdio_write(0x09, (mdio_data & 0x1FFF) | 0xa000);//set reg PHYCR bit15:13 = 101
				break;

			case 6://Test Mode6
				DBGMSG(("Test Mode 6\r\n"));
				mdio_write(0x09, (mdio_data & 0x1FFF) | 0xC000);//set reg PHYCR bit15:13 = 110
				break;	

			default:
				break;
		}
	}
	else if(SpeedType == Speed_100BaseT1){
		DBGMSG(("Speed_100BaseT1\r\n"));
		mdio_write(0x1f,0xA59);
		mdio_data = mdio_read(17);
		switch(TestMode_selection){

			case 1://Test Mode1
				DBGMSG(("Test Mode 1\r\n"));
				mdio_write(17, (mdio_data & 0x1FFF)|0x2000);//set reg PHYCR bit15:13 = 001
				break;

			case 2://Test Mode2
				DBGMSG(("Test Mode 2\r\n"));
				mdio_write(17, (mdio_data & 0x1FFF) | 0x4000);//set reg PHYCR bit15:13 = 010
				break;

			case 4://Test Mode4
				DBGMSG(("Test Mode 4\r\n"));
				mdio_write(17, (mdio_data & 0x1FFF) | 0x8000);//set reg PHYCR bit15:13 = 100
				break;

			case 5://Test Mode5
				DBGMSG(("Test Mode 5\r\n"));
				mdio_write(17, (mdio_data & 0x1FFF) | 0xa000);//set reg PHYCR bit15:13 = 101
				break;

			default:
				break;
		}
		
	}
	else
		return E_INVALD;

	return E_NOERR;
}


u8 RTL9010Bx_MACsec_Enable(u8 Control)
{
	u32 mdio_data = 0;

	// Set MACsec Enable or Disable //
	mdio_write(31, 0x0D01);
	mdio_data = mdio_read(17);
	if(TurnOn == Control)
		BIT_SET(mdio_data, 4);
	else
		BIT_CLR(mdio_data, 4);

	mdio_write(17, mdio_data);

	return E_NOERR;
}

u8 RTL9010Bx_MACsec_Egress_Check_Access_Correct(void)
{
	u32 reg_value = 0;

	mdio_write(31, 0x0D84);
	mdio_write(19, 0xFFFC);  // write address in.
	mdio_write(20, 0x0010);

	reg_value = mdio_read(17);  // read 15~0 bits of register.

	DBGMSG(("Get Egress Reg[0xFFFC] =  0x%08X \r\n", reg_value));

	if(0x5FA0 == reg_value)
		return E_NOERR;
	else
		return E_INVALD;
}

u8 RTL9010Bx_MACsec_Ingress_Check_Access_Correct(void)
{
	u32 reg_value = 0;

	mdio_write(31, 0x0D85);
	mdio_write(16, 0xFFFC);
	mdio_write(17, 0x0010);
	mdio_write(31, 0x0D84);

	reg_value = mdio_read(22);  // read 15~0 bits of register.

	DBGMSG(("Get Ingress Reg[0xFFFC] =  0x%08X \r\n", reg_value));

	if(0x5FA0 == reg_value)
		return E_NOERR;
	else
		return E_INVALD;
}

u32 RTL9010Bx_MACsec_Egress_Read(u16 Address)
{
	u32 reg_value = 0;
	u16 reg_LSB = 0;

	mdio_write(31, 0x0D84);
	mdio_write(19, Address);  // write address in.
	mdio_write(20, 0x0010);

	reg_value = mdio_read(16);  // read 31~16 bits of register.
	reg_LSB = mdio_read(17);  // read 15~0 bits of register.
	reg_value = (reg_value <<16) | reg_LSB;  // combine values together into 32 bits of register.

	return reg_value;
}

u32 RTL9010Bx_MACsec_Ingress_Read(u16 Address)
{
	u32 reg_value = 0;
	u16 reg_LSB = 0;

	mdio_write(31, 0x0D85);
	mdio_write(16, Address);
	mdio_write(17, 0x0010);
	mdio_write(31, 0x0D84);

	reg_value = mdio_read(21);  // read 31~16 bits of register.
	reg_LSB = mdio_read(22);  // read 15~0 bits of register.
	reg_value = (reg_value << 16) | reg_LSB;  // combine values together into 32 bits of register.

	return reg_value;
}

u8 RTL9010Bx_MACsec_Egress_Write(u16 Address, u32 reg_value)
{
	u16 reg_MSB = 0;
	u16 reg_LSB = 0;

	reg_MSB = (u16)(reg_value >> 16);
	reg_LSB = (u16)(reg_value);
	
	mdio_write(31, 0x0D84);
	mdio_write(19, Address);  // write address in.
	mdio_write(16, reg_MSB);
	mdio_write(17, reg_LSB);
	mdio_write(20, 0x0001);

	return E_NOERR;
}


u8 RTL9010Bx_MACsec_Ingress_Write(u16 Address, u32 reg_value)
{
	u16 reg_MSB = 0;
	u16 reg_LSB = 0;
		
	reg_MSB = (u16)(reg_value >> 16);
	reg_LSB = (u16)(reg_value);
		
	mdio_write(31, 0x0D85);
	mdio_write(16, Address);  // write address in.
	mdio_write(31, 0x0D84);
	mdio_write(21, reg_MSB);
	mdio_write(22, reg_LSB);
	mdio_write(31, 0x0D85);
	mdio_write(17, 0x0001);

	return E_NOERR;
}

u8 RTL9010Bx_Start_MACsec_Function(void)
{
	mdio_write(31, 0x0D81);
	mdio_write(16, 0x0003); // enable macsec_clk_rx, macsec_clk_tx
	mdio_write(31, 0x0D80);
	mdio_write(16, 0xD1D1); // Rx/Tx : normal operation, software reset

	return E_NOERR;
}

u32 RTL9010Bx_Monitor_SAK_Packet_Number(u8 SAK_n)
{  
	u32 pkt_num = 0;

	switch(SAK_n){
		case SAK1:
			pkt_num = RTL9010Bx_MACsec_Egress_Read(0x0028);
			break;

		case SAK2:
			pkt_num = RTL9010Bx_MACsec_Egress_Read(0x0088);
			break;

		default: 
			break;
	}

	return pkt_num;
}

u8 RTL9010Bx_Switch_Egress_SAK(u8 SW_SAK)
{  
	switch(SW_SAK){
		case SAK1_to_SAK2:    // switch SAK from SAK1 to SAK2
			RTL9010Bx_MACsec_Egress_Write(0x7000, 0x00070103);
			RTL9010Bx_MACsec_Egress_Write(0x7000, 0x00870103);
			RTL9010Bx_MACsec_Egress_Write(0x6104, 0x80000000);
			break;

		case SAK2_to_SAK1:   // switch SAK from SAK2 to SAK1
			RTL9010Bx_MACsec_Egress_Write(0x7000, 0x00070003);
			RTL9010Bx_MACsec_Egress_Write(0x7000, 0x00870003);
			RTL9010Bx_MACsec_Egress_Write(0x6104, 0x80000000);
			break;

		default: 
			return E_INVALD;
	}

	return E_NOERR;
}

u8 RTL9010Bx_Update_SAK1(u8 Dir)
{
	switch(Dir){
		case Egress:
			// Install a new SAK (optional)
			RTL9010Bx_MACsec_Egress_Write(0x0028, 0x00000000);
			RTL9010Bx_MACsec_Egress_Write(0x6104, 0x80000000); // Reset packet number of SAK-1
			break;

		case Ingress:
			RTL9010Bx_MACsec_Ingress_Write(0x60C0, 0x00000001);
			// Install a new SAK (optional)
			RTL9010Bx_MACsec_Ingress_Write(0x0028, 0x00000001);
			RTL9010Bx_MACsec_Ingress_Write(0x6104, 0x80000000); // Reset packet number of SAK-1
			RTL9010Bx_MACsec_Ingress_Write(0x6000, 0x00000003);
			break;

		default:
			return E_INVALD;
	}

	return E_NOERR;
}

u8 RTL9010Bx_Update_SAK2(u8 Dir)
{
	switch(Dir){
		case Egress:
			// Install a new SAK (optional)
			RTL9010Bx_MACsec_Egress_Write(0x0088, 0x00000000);
			RTL9010Bx_MACsec_Egress_Write(0x6104, 0x80000000);
			break;

		case Ingress:
			RTL9010Bx_MACsec_Ingress_Write(0x60C0, 0x00000002);
			// Install a new SAK (optional)
			RTL9010Bx_MACsec_Ingress_Write(0x0078, 0x00000001);
			RTL9010Bx_MACsec_Ingress_Write(0x6104, 0x80000000);
			RTL9010Bx_MACsec_Ingress_Write(0x6000, 0x00000003);
			break;

		default:
			return E_INVALD;
	}

	return E_NOERR;
}

u32 RTL9010Bx_Egress_MIBCounter_Encrypted_OutPktBytes(u8 SAK_n)
{  // Number of the packet bytes encrypted by the SAK.
	if((SAK_n > SAK2) ||(SAK_n < SAK1))
		return 0xFFFFFFFF;

	return RTL9010Bx_MACsec_Egress_Read(0x8000 + (SAK_n - 1)*0x80 );
}

u32 RTL9010Bx_Egress_MIBCounter_Encrypted_OutPkts(u8 SAK_n)
{ // Number of the packets encrypted by the SAK.
	if((SAK_n > SAK2) ||(SAK_n < SAK1))
		return 0xFFFFFFFF;

	return RTL9010Bx_MACsec_Egress_Read(0x8010 + (SAK_n - 1)*0x80 );
}

u32 RTL9010Bx_Egress_MIBCounter_Encrypted_OutPktsTooLong(u8 SAK_n)
{
	if((SAK_n > SAK2) ||(SAK_n < SAK1))
		return 0xFFFFFFFF;

	return RTL9010Bx_MACsec_Egress_Read(0x8018 + (SAK_n - 1)*0x80 );
}

u32 RTL9010Bx_Ingress_MIBCounter_Decrypted_InPktBytes(u8 SAK_n)
{  // Number of the packet bytes decrypted by the SAK.
	if((SAK_n > SAK2) ||(SAK_n < SAK1))
		return 0xFFFFFFFF;

	return RTL9010Bx_MACsec_Ingress_Read(0x8000 + (SAK_n - 1)*0x80 );
}

u32 RTL9010Bx_Ingress_MIBCounter_Decrypted_InPktsOK(u8 SAK_n)
{  // Packet decrypted by MACsec is succeed.
	if((SAK_n > SAK2) ||(SAK_n < SAK1))
		return 0xFFFFFFFF;

	return RTL9010Bx_MACsec_Ingress_Read(0x8028 + (SAK_n - 1)*0x80 );
}

u32 RTL9010Bx_Ingress_MIBCounter_Decrypted_InPktsNotValid(u8 SAK_n)
{  
	if((SAK_n > SAK2) ||(SAK_n < SAK1))
		return 0xFFFFFFFF;

	return RTL9010Bx_MACsec_Ingress_Read(0x8038 + (SAK_n - 1)*0x80 );
}

u32 RTL9010Bx_Ingress_MIBCounter_Decrypted_InPktsDelayed(u8 SAK_n)
{  
	if((SAK_n > SAK2) ||(SAK_n < SAK1))
		return 0xFFFFFFFF;

	return RTL9010Bx_MACsec_Ingress_Read(0x8018 + (SAK_n - 1)*0x80 );
}

u32 RTL9010Bx_Ingress_MIBCounter_Decrypted_InPktsLate(u8 SAK_n)
{  
	if((SAK_n > SAK2) ||(SAK_n < SAK1))
		return 0xFFFFFFFF;

	return RTL9010Bx_MACsec_Ingress_Read(0x8020 + (SAK_n - 1)*0x80 );
}

u32 RTL9010Bx_Ingress_MIBCounter_Decrypted_InPktsInvalid(u8 SAK_n)
{
	if((SAK_n > SAK2) ||(SAK_n < SAK1))
		return 0xFFFFFFFF;

	return RTL9010Bx_MACsec_Ingress_Read(0x8030 + (SAK_n - 1)*0x80 );
}

u32 RTL9010Bx_Ingress_MIBCounter_Decrypted_InPktsNotUsingSA(u8 SAK_n)
{
	if((SAK_n > SAK2) ||(SAK_n < SAK1))
		return 0xFFFFFFFF;

	return RTL9010Bx_MACsec_Ingress_Read(0x8040 + (SAK_n - 1)*0x80 );
}

u32 RTL9010Bx_Ingress_MIBCounter_Decrypted_InPktsUnusedSA(u8 SAK_n)
{
	if((SAK_n > SAK2) ||(SAK_n < SAK1))
		return 0xFFFFFFFF;

	return RTL9010Bx_MACsec_Ingress_Read(0x8048 + (SAK_n - 1)*0x80 );
}

u32 RTL9010Bx_Ingress_MIBCounter_Decrypted_InPktsUntaggedHit(u8 SAK_n)
{  
	if((SAK_n > SAK2) ||(SAK_n < SAK1))
		return 0xFFFFFFFF;

	return RTL9010Bx_MACsec_Ingress_Read(0x8050 + (SAK_n - 1)*0x80 );
}


u8 RTL9010Bx_MACsec_Initial_Configuration_example(void)
{
	// Step 1. Set MACsec enable
	RTL9010Bx_MACsec_Enable(TurnOn);

	// Step 2. Initial Setting for MACsec Egress Block
	RTL9010Bx_MACsec_Egress_Write(0xC810, 0x0000000C);
	RTL9010Bx_MACsec_Egress_Write(0xF408, 0xE5880218);
	RTL9010Bx_MACsec_Egress_Write(0xF430, 0x00000003);
	RTL9010Bx_MACsec_Egress_Write(0x797C, 0x0200003C);

	// Non-match packet flow, set as bypass
	RTL9010Bx_MACsec_Egress_Write(0x7944, 0x010101C1);

	RTL9010Bx_MACsec_Egress_Write(0xF100, 0x00003FFF);
	RTL9010Bx_MACsec_Egress_Write(0xF120, 0x00003FFF);

	// MACsec Egress parsing setting, match DA[7~0] = 0x63 to encrypt with MACsec SA.
	RTL9010Bx_MACsec_Egress_Write(0x400C, 0x00006300);
	RTL9010Bx_MACsec_Egress_Write(0x401C, 0x00000040);

	RTL9010Bx_MACsec_Egress_Write(0x4010, 0x000F2100);
	RTL9010Bx_MACsec_Egress_Write(0x4020, 0x00000000);

	// SAK-1 MACsec setting, Bit 26~27 = AN = 2.
	RTL9010Bx_MACsec_Egress_Write(0x0000, 0x9A4BE066);
	RTL9010Bx_MACsec_Egress_Write(0x0004, 0x00000000);

	// SAK-1 MACsec key setting
	// The 128-bits SAK key = AD 7A 2B D0 - 3E AC 83 5A - 6F 62 0F DC - B5 06 B3 45.
	RTL9010Bx_MACsec_Egress_Write(0x0008, 0xD02B7AAD);
	RTL9010Bx_MACsec_Egress_Write(0x000C, 0x5A83AC3E);
	RTL9010Bx_MACsec_Egress_Write(0x0010, 0xDC0F626F);
	RTL9010Bx_MACsec_Egress_Write(0x0014, 0x45B306B5);

	// SAK-1 H-key setting, Hash ytansform of the MACsec SA key
	// H(SAK) = 72 A2 3D 80 - 12 1D E2 D5 - A8 50 25 3F - CF 43 12 0E.
	RTL9010Bx_MACsec_Egress_Write(0x0018, 0x803DA273);
	RTL9010Bx_MACsec_Egress_Write(0x001C, 0xD5E21D12);
	RTL9010Bx_MACsec_Egress_Write(0x0020, 0x3F2550A8);
	RTL9010Bx_MACsec_Egress_Write(0x0024, 0x0E1243CF);

	// Packet number of SAK-1.
	RTL9010Bx_MACsec_Egress_Write(0x0028, 0x00000000);

	// SCI setting of SAK-1.
	// SCI 12 15 35 24 - C0 89 5E 81.
	RTL9010Bx_MACsec_Egress_Write(0x002C, 0x24351512);
	RTL9010Bx_MACsec_Egress_Write(0x0030, 0x815E89C0);

	// SAK update setting of SAK-1.
//	RTL9010Bx_MACsec_Egress_Write(0x003C, 0x8000C001);

	// SAK-2 MACsec setting, Bit 26~27 = AN = 3.
	RTL9010Bx_MACsec_Egress_Write(0x0060, 0x9E4BE066);
	RTL9010Bx_MACsec_Egress_Write(0x0064, 0x00000001);

	// SAK-2 MACsec key setting (same as SA-1)
	// The 128-bits SAK key = AD 7A 2B D0 - 3E AC 83 5A - 6F 62 0F DC - B5 06 B3 45.
	RTL9010Bx_MACsec_Egress_Write(0x0068, 0xD02B7AAD);
	RTL9010Bx_MACsec_Egress_Write(0x006C, 0x5A83AC3E);
	RTL9010Bx_MACsec_Egress_Write(0x0070, 0xDC0F626F);
	RTL9010Bx_MACsec_Egress_Write(0x0074, 0x45B306B5);

	// SAK-2 H-key setting, Hash transform of the MACsec SA key (same as SA-1)
	// H(SAK) = 72 A2 3D 80 - 12 1D E2 D5 - A8 50 25 3F - CF 43 12 0E.
	RTL9010Bx_MACsec_Egress_Write(0x0078, 0x803DA273);
	RTL9010Bx_MACsec_Egress_Write(0x007C, 0xD5E21D12);
	RTL9010Bx_MACsec_Egress_Write(0x0080, 0x3F2550A8);
	RTL9010Bx_MACsec_Egress_Write(0x0084, 0x0E1243CF);

	// Packet number of SAK-2.
	RTL9010Bx_MACsec_Egress_Write(0x0088, 0x00000000);

	// SCI setting of SAK-1. (same as SA-1)
	// SCI 12 15 35 24 - C0 89 5E 81.
	RTL9010Bx_MACsec_Egress_Write(0x008C, 0x24351512);
	RTL9010Bx_MACsec_Egress_Write(0x0090, 0x815E89C0);

	// SAK update setting of SAK-2.
//	RTL9010Bx_MACsec_Egress_Write(0x009C, 0x8000C000);

	// MACsec flow setting,
	// Bit[16] protect_frame	1b : enable frame protection		 / 0b : bypass function through crypto-core.
 	// Bit[15:8] sa_index
	// Bit[18] include_sci	1b : include explicit SCI in packet	 / 0b : use implicit SCI (not transmitted in packet).
	// Bit[31] conf_protect	1b : enable confidentiality protection	 / 0b : disable confidentiality protection.
	RTL9010Bx_MACsec_Egress_Write(0x7000, 0x80070003);

	// Enablel SA match rule-1.
	RTL9010Bx_MACsec_Egress_Write(0x6000, 0x00000001);

	// Step 3. Initial Setting for MACsec Ingress Block
	RTL9010Bx_MACsec_Ingress_Write(0x7900, 0x90FAC688);
	RTL9010Bx_MACsec_Ingress_Write(0xC810, 0x0000000C);
	RTL9010Bx_MACsec_Ingress_Write(0xF408, 0xE5880214);
	RTL9010Bx_MACsec_Ingress_Write(0xF430, 0x00000003);
	RTL9010Bx_MACsec_Ingress_Write(0x797C, 0x01000048);

	// Non-match packet flow, set as bypass
	RTL9010Bx_MACsec_Ingress_Write(0x7944, 0x0909C9C9);

	// MACsec Ingress Initialization
	RTL9010Bx_MACsec_Ingress_Write(0xF100, 0x00003FFF);
	RTL9010Bx_MACsec_Ingress_Write(0xF120, 0x00003FFF);
	RTL9010Bx_MACsec_Ingress_Write(0xE840, 0x0000C000);

	// MACsec Ingress parsing setting for SAK-1, 
	// Match DA[7~0] = 0x63 and SCI = 12 15 35 24 - C0 89 5E 81 to encrypt with SA-1 key.
	RTL9010Bx_MACsec_Ingress_Write(0x400C, 0x00006300);
	RTL9010Bx_MACsec_Ingress_Write(0x4014, 0x24351512);
	RTL9010Bx_MACsec_Ingress_Write(0x4018, 0x815E89C0);

	// MACsec Ingress parsing setting for SAK-1, 
	// Bit[9] tagged	1b : allow packets with a standard and valid MACsec tag to match.
 	// Bit[25:24] match AN number = 2
	RTL9010Bx_MACsec_Ingress_Write(0x4010, 0x020F0200);

	// MACsec Ingress parsing setting for SAK-1, 
	RTL9010Bx_MACsec_Ingress_Write(0x401C, 0x03800040);

	// MACsec Ingress setting for SAK-1, 
	RTL9010Bx_MACsec_Ingress_Write(0x4020, 0x00000000);

	// MACsec Ingress setting for SAK-1, 
	RTL9010Bx_MACsec_Ingress_Write(0x0000, 0xD24BE06F);
	RTL9010Bx_MACsec_Ingress_Write(0x0004, 0x00000000);

	// SAK-1 MACsec key setting
	RTL9010Bx_MACsec_Ingress_Write(0x0008, 0xD02B7AAD);
	RTL9010Bx_MACsec_Ingress_Write(0x000C, 0x5A83AC3E);
	RTL9010Bx_MACsec_Ingress_Write(0x0010, 0xDC0F626F);
	RTL9010Bx_MACsec_Ingress_Write(0x0014, 0x45B306B5);

	// SAK-1 H-key setting, Hash transform of the MACsec SA key
	RTL9010Bx_MACsec_Ingress_Write(0x0018, 0x803DA273);
	RTL9010Bx_MACsec_Ingress_Write(0x001C, 0xD5E21D12);
	RTL9010Bx_MACsec_Ingress_Write(0x0020, 0x3F2550A8);
	RTL9010Bx_MACsec_Ingress_Write(0x0024, 0x0E1243CF);

	// Packet number of SAK-1.
	RTL9010Bx_MACsec_Ingress_Write(0x0028, 0x00000001);

	// Reply window for ingress SAK-1.
	RTL9010Bx_MACsec_Ingress_Write(0x002C, 0x00000000);

	// Flow control setting for SAK-1,
	// Bit[16] replay_protect	1b : enable replay protection		 / 0b : disable replay protection.
 	// Bit[15:8] sa_index = 0
	// Bit[7:6] drop_action	00b : bypass with CRC corruption signaling,
	//					01b : bypass with bad packet indicator,
	//					10b : internal drop by crypto-core (packet is not seen outside),
	//					11b : do not drop (for debugging only).
	RTL9010Bx_MACsec_Ingress_Write(0x7000, 0x0013000A);

	// MACsec Ingress parsing setting for SAK-2, 
	// Match DA[7~0] = 0x63 and SCI = 12 15 35 24 - C0 89 5E 81 to encrypt with SA-1 key.
	RTL9010Bx_MACsec_Ingress_Write(0x404C, 0x00006300);
	RTL9010Bx_MACsec_Ingress_Write(0x4054, 0x24351512);
	RTL9010Bx_MACsec_Ingress_Write(0x4058, 0x815E89C0);

	// MACsec Ingress parsing setting for SAK-2, 
	// Bit[9] tagged	1b : allow packets with a standard and valid MACsec tag to match.
 	// Bit[25:24] match AN number = 3
	RTL9010Bx_MACsec_Ingress_Write(0x4050, 0x030F0200);

	// MACsec Ingress parsing setting for SAK-2, 
	RTL9010Bx_MACsec_Ingress_Write(0x405C, 0x03800040);

	// MACsec Ingress setting for SAK-2, 
	RTL9010Bx_MACsec_Ingress_Write(0x4060, 0x00010000);

	// MACsec Ingress setting for SAK-2, 
	RTL9010Bx_MACsec_Ingress_Write(0x0050, 0xD24BE06F);
	RTL9010Bx_MACsec_Ingress_Write(0x0054, 0x00000000);

	// SAK-1 MACsec key setting (same as SA-1)
	RTL9010Bx_MACsec_Ingress_Write(0x0058, 0xD02B7AAD);
	RTL9010Bx_MACsec_Ingress_Write(0x005C, 0x5A83AC3E);
	RTL9010Bx_MACsec_Ingress_Write(0x0060, 0xDC0F626F);
	RTL9010Bx_MACsec_Ingress_Write(0x0064, 0x45B306B5);

	// SAK-2 H-key setting, Hash transform of the MACsec SA key (same as SA-1)
	RTL9010Bx_MACsec_Ingress_Write(0x0068, 0x803DA273);
	RTL9010Bx_MACsec_Ingress_Write(0x006C, 0xD5E21D12);
	RTL9010Bx_MACsec_Ingress_Write(0x0070, 0x3F2550A8);
	RTL9010Bx_MACsec_Ingress_Write(0x0074, 0x0E1243CF);

	// Packet number of SAK-2.
	RTL9010Bx_MACsec_Ingress_Write(0x0078, 0x00000001);

	// Reply window for ingress SAK-2.
	RTL9010Bx_MACsec_Ingress_Write(0x007C, 0x00000000);

	// Flow control setting for SAK-2,
	// Bit[16] replay_protect	1b : enable replay protection		 / 0b : disable replay protection.
 	// Bit[15:8] sa_index = 1
	// Bit[7:6] drop_action	00b : bypass with CRC corruption signaling,
	//					01b : bypass with bad packet indicator,
	//					10b : internal drop by crypto-core (packet is not seen outside),
	//					11b : do not drop (for debugging only).
	RTL9010Bx_MACsec_Ingress_Write(0x7004, 0x0013010A);

	// Enable SA match for SAK-1 and SAK-2.
	RTL9010Bx_MACsec_Ingress_Write(0x6000, 0x00000003);

	// Step 4. Start MACsec function
	RTL9010Bx_Start_MACsec_Function();

	return E_NOERR;

}


