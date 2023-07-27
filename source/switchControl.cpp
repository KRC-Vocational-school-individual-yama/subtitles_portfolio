#include"switchControl.h"
#include<DxLib.h>
SwitchFlags::SwitchFlags() {
	keystop = false;
	oneflag = false;
}

bool SwitchFlags::SwitchControl(bool keyflag) {
	if (keyflag&&!keystop) {
		if (oneflag) {
			oneflag = false;
		}
		else if(!oneflag){
			oneflag = true;
		}
		keystop = true;
	}
	else if (!keyflag) {
		keystop = false;
	}
	return oneflag;
}