#include"object.h"
#include<DxLib.h>
#include<string>
#include"config.h"
#include"switchControl.h"
#include"squarecollision.h"
#include<sstream>
#include<vector>

using namespace std;

namespace {
	int x, y;
	int count;
	int masunum;
	int mousex, mousey;
	bool keystop = false;
	bool moveflag = false;
	int alphacount = 0;
	SwitchFlags milk;
	SwitchFlags ak;
	//SwitchFlags *aaa;


	string str, s;
	vector<string>v;
	int sc = 0;
}


void Init() {
	x = 400;
	y = 300;
	mousex = 0;
	mousey = 0;
	keystop = false;
	masunum = 0;
	moveflag = false;
	alphacount = 0;

	str = "1,2,3,4,5,6";
	stringstream ss{ str };
	while (getline(ss, s, ',')) {
		v.push_back(s);
	}

	//aaa= new SwitchFlags;

}
void Keystopflag() {
	bool mousekey = GetMouseInput() & MOUSE_INPUT_LEFT;
	bool mouserightkey = GetMouseInput() & MOUSE_INPUT_RIGHT;
	if (
		!mousekey&&
		!mouserightkey
		) {
		keystop = false;
	}
}
void Update() {
	GetMousePoint(&mousex,&mousey);
	/*bool mousekey = GetMouseInput() & MOUSE_INPUT_LEFT;
	if (mousekey&&!keystop) {
		moveflag = false;
		keystop = true;
	}
	bool mouserightkey = GetMouseInput() & MOUSE_INPUT_RIGHT;
	if (mouserightkey&&!keystop) {
		moveflag = true;
		keystop = true;
	}*/
	int x1=0, x2 = 0, y1 = 0, y2 = 0;
	bool move=SquareCollision(x1=x-200,y1=y-20,x2=x+200,y2=y+20,mousex,mousey,mousex+1,mousey+1);
	if (move)moveflag =milk.SwitchControl(GetMouseInput() & MOUSE_INPUT_LEFT);
	//SwitchFlags ak;milk

	if(ak.SwitchControl(CheckHitKey(KEY_INPUT_A)==1))
	DrawBox(x1,y1,x2,y2,GetColor(255,0,0),false);
	
	if (moveflag) {
		x = mousex;
		y = mousey;
	}
	


	if (masunum < 300) {
		masunum += 5;// count++;
	}
	if(masunum>300)alphacount = 255;
	alphacount+=5;
	if (alphacount >= 255)alphacount = 255;
	if (alphacount <= 0)alphacount = 0;

	bool key = CheckHitKey(KEY_INPUT_SPACE);
	if (key) {
		masunum = 0;
		alphacount = 0;
		sc=0;
	}

	Keystopflag();
}
void Draw() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,alphacount);
	DrawLine(x+-masunum,y,x+ masunum,y,GetColor(255,255,255));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);

	std::string a[] = {
	"マウス右　　 →位置調整\n",
	"マウス左　　 →位置決定\n",
	"スペースキー →リスタート\n",
	"Aキー　　　　→デバッグ線\n",
	"\n",
	};
	for (std::string x : a) {
	printfDx(x.c_str());
	}
	SetFontSize(64);
	for (int i = 0; i < v.size(); i++) {
		sc++;
		if (sc>60+i*60) {
	DrawFormatString(x-270+i*96,y-64,GetColor(100,200,50),v.at(i).c_str());
		}
	}
	SetFontSize(16);

}
void Delete() {

}