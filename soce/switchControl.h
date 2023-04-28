#pragma once
class SwitchFlags {
	bool keystop;
	bool oneflag;
public:
	bool SwitchControl(bool keyflag);
	SwitchFlags();
};