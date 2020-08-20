// *** Hardwarespecific functions ***

void UTFT::_hw_special_init(){}

void UTFT::LCD_Writ_Bus(char VH,char VL, byte mode)
{
	if(mode == 16) {
		digitalWriteFast(digitalPinToPinName(PA0), bitRead(VL, 0));
		digitalWriteFast(digitalPinToPinName(PA1), bitRead(VL, 1));
		digitalWriteFast(digitalPinToPinName(PA2), bitRead(VL, 2));
		digitalWriteFast(digitalPinToPinName(PA3), bitRead(VL, 3));
		digitalWriteFast(digitalPinToPinName(PA4), bitRead(VL, 4));
		digitalWriteFast(digitalPinToPinName(PA5), bitRead(VL, 5));
		digitalWriteFast(digitalPinToPinName(PA6), bitRead(VL, 6));
		digitalWriteFast(digitalPinToPinName(PA7), bitRead(VL, 7));
		
		digitalWriteFast(digitalPinToPinName(PB8), bitRead(VH, 0));
		digitalWriteFast(digitalPinToPinName(PB9), bitRead(VH, 1));
		digitalWriteFast(digitalPinToPinName(PB10), bitRead(VH, 2));
		digitalWriteFast(digitalPinToPinName(PB11), bitRead(VH, 3));
		digitalWriteFast(digitalPinToPinName(PB12), bitRead(VH, 4));
		digitalWriteFast(digitalPinToPinName(PB13), bitRead(VH, 5));
		digitalWriteFast(digitalPinToPinName(PB14), bitRead(VH, 6));
		digitalWriteFast(digitalPinToPinName(PB15), bitRead(VH, 7));
		
		pulse_low(P_WR, B_WR);
	}	
}

void UTFT::_set_direction_registers(byte mode)
{
	if(mode == 16) {
		pinMode(PA0, OUTPUT);
		pinMode(PA1, OUTPUT);
		pinMode(PA2, OUTPUT);
		pinMode(PA3, OUTPUT);
		pinMode(PA4, OUTPUT);
		pinMode(PA5, OUTPUT);
		pinMode(PA6, OUTPUT);
		pinMode(PA7, OUTPUT);
		pinMode(PB8, OUTPUT);
		pinMode(PB9, OUTPUT);
		pinMode(PB10, OUTPUT);
		pinMode(PB11, OUTPUT);
		pinMode(PB12, OUTPUT);
		pinMode(PB13, OUTPUT);
		pinMode(PB14, OUTPUT);
		pinMode(PB15, OUTPUT);
	}
}

void UTFT::_fast_fill_16(int ch, int cl, long pix)
{
	long blocks;

	digitalWriteFast(digitalPinToPinName(PA0), bitRead(cl, 0));
	digitalWriteFast(digitalPinToPinName(PA1), bitRead(cl, 1));
	digitalWriteFast(digitalPinToPinName(PA2), bitRead(cl, 2));
	digitalWriteFast(digitalPinToPinName(PA3), bitRead(cl, 3));
	digitalWriteFast(digitalPinToPinName(PA4), bitRead(cl, 4));
	digitalWriteFast(digitalPinToPinName(PA5), bitRead(cl, 5));
	digitalWriteFast(digitalPinToPinName(PA6), bitRead(cl, 6));
	digitalWriteFast(digitalPinToPinName(PA7), bitRead(cl, 7));
		
	digitalWriteFast(digitalPinToPinName(PB8), bitRead(ch, 0));
	digitalWriteFast(digitalPinToPinName(PB9), bitRead(ch, 1));
	digitalWriteFast(digitalPinToPinName(PB10), bitRead(ch, 2));
	digitalWriteFast(digitalPinToPinName(PB11), bitRead(ch, 3));
	digitalWriteFast(digitalPinToPinName(PB12), bitRead(ch, 4));
	digitalWriteFast(digitalPinToPinName(PB13), bitRead(ch, 5));
	digitalWriteFast(digitalPinToPinName(PB14), bitRead(ch, 6));
	digitalWriteFast(digitalPinToPinName(PB15), bitRead(ch, 7));

	blocks = pix/16;
	for (int i=0; i<blocks; i++)
	{
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
	}
	if ((pix % 16) != 0)
		for (int i=0; i<(pix % 16)+1; i++)
		{
			pulse_low(P_WR, B_WR);
		}
}

void UTFT::_fast_fill_8(int ch, long pix)
{
	long blocks;

	digitalWriteFast(digitalPinToPinName(PB8), bitRead(ch, 0));
	digitalWriteFast(digitalPinToPinName(PB9), bitRead(ch, 1));
	digitalWriteFast(digitalPinToPinName(PB10), bitRead(ch, 2));
	digitalWriteFast(digitalPinToPinName(PB11), bitRead(ch, 3));
	digitalWriteFast(digitalPinToPinName(PB12), bitRead(ch, 4));
	digitalWriteFast(digitalPinToPinName(PB13), bitRead(ch, 5));
	digitalWriteFast(digitalPinToPinName(PB14), bitRead(ch, 6));
	digitalWriteFast(digitalPinToPinName(PB15), bitRead(ch, 7));

	blocks = pix/16;
	for (int i=0; i<blocks; i++)
	{
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
	}
	if ((pix % 16) != 0)
		for (int i=0; i<(pix % 16)+1; i++)
		{
			pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		}
}
