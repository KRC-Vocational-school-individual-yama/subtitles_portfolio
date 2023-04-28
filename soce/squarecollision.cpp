#include"squarecollision.h"

bool SquareCollision(
	float exl, float eyu, float exr, float eyd,
	float mxl, float myu, float mxr, float myd
) {
	bool	left	= mxl <= exr,
			right	= mxr >= exl,
			up		= myu <= eyd,
			down	= myd >= eyu;
	bool collision	= left&&right&&up&&down;
	return collision;
}


//
//#include"squarecollision.h"
//
//bool SquareCollision(
//	float exl, float exr, float eyu, float eyd,
//	float mxl, float mxr, float myu, float myd
//) {
//	bool aup = eyu, adown = eyd, aleft = exl, aright = mxr;
//	bool mup = myu, mdown = myd, mleft = mxl, mright = mxr;
//
//	bool left = false, right = false, up = false, down = false;
//	if (mleft <= aright)left = true;
//	if (mright > aleft)right = true;
//	if (mup < adown)up = true;
//	if (mdown > aup)down = true;
//
//	bool collisiton = left && right && up && down;
//	if (collisiton)return true;
//	return false;
//}