#include "Game.h"
#include "End.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "math.h"

#define PI 3.141592654f

static int direction = 0, MouseX, MouseY, White, Brack, message = 0, OldMouseOshita;
static int FontHandle0;
static int FontHandle1;
static int SoundHandle0;
static int SoundHandle1;
static int SoundHandle2;
static int SoundHandle3;
static int SoundHandle4;
static int SoundHandle5;
static int SoundHandle6;
static int SoundHandle7;
static int SoundHandle8;
static int SoundHandle9;
static int SoundHandle10;
static int SoundHandle11;
static int SoundHandle12;
static int SoundHandle13;
static int SoundHandle14;
static int SoundHandle15;
static int SoundHandle16;
static int SoundHandle17;
static int mImageHandle0;
static int mImageHandle1;
static int mImageHandle2;
static int mImageHandle3;
static int mImageHandle4;
static int mImageHandle5;
static int mImageHandle6;
static int mImageHandle7;
static int mImageHandle8;
static int mImageHandle9;
static int mImageHandle10;
static int mImageHandle11;
static int mImageHandle12;
static int mImageHandle13;
static int mImageHandle14;
static int mImageHandle15;
static int mImageHandle16;
static int mImageHandle17;
static int mImageHandle18;
static int mImageHandle19;
static int mImageHandle20;
static int mImageHandle21;
static int mImageHandle22;
static int mImageHandle23;
static int mImageHandle24;
static int mImageHandle25;
static int mImageHandle26;
static int mImageHandle27;
static int mImageHandle28;
static int mImageHandle29;
static int mImageHandle30;
static int mImageHandle31;
static int mImageHandle32;
static int mImageHandle33;
static int mImageHandle34;
static int mImageHandle35;
static int mImageHandle36;
static int mImageHandle37;
static int mImageHandle38;
static int mImageHandle39;
static int mImageHandle40;
static int mImageHandle41;
static int mImageHandle42;
static int mImageHandle43;
static int mImageHandle44;
static int mImageHandle45;
static int mImageHandle46;
static int mImageHandle47;
static int mImageHandle48;
static int mImageHandle49;
static int item1get = 0;
static int item2get = 0;
static int item3get = 0;
static int item4get = 0;
static int item5get = 0;
static int item6get = 0;
static int item7get = 0;
static int item8get = 0;
static int item9get = 0;
static int itemuse = 0;
static int chair = 0, Count,end,zonbi = 0,eat = 0;
static int lock1 = TRUE;
static int lock2 = TRUE;
static int lock3 = TRUE;
static int lock4 = TRUE;
static int fire = FALSE;
static int box01open = FALSE;
static int box02open = FALSE;
static int box03open = FALSE;
static int box04open = FALSE;
static int item_slot[5]{0,0,0,0,0};
static int item_info[10]{};
static int SelectNum = 0;
static int SelectNum_2 = 0;
static int SelectNum_3 = 0;
static char StrBuf[128], StrBuf2[32], StrBuf3[128];

typedef struct {
	int x, y;
	char name[128];
} MenuElement_t;

MenuElement_t MenuElement[10] = {
	{ 0, 0, "???" },
	{ 200, 50, "�}�b�`" },
	{ 200, 100, "�����ׂ�" },
	{ 200, 150, "���b�v(�O���b�v)" },
	{ 200, 200, "���b�v(�֎�)" },
	{ 200, 250, "���b�v(���S��)" },
	{ 200, 300, "�`���̌�" },
	{ 200, 350, "�֎q" },
	{ 200, 400, "����" },
	{ 200, 450, "���񂪂�ȓ�" },
};

int item_get(int item) {
	int place;
	item_info[item] = 1;
	for (int i = 0; i < 8; i++) {
		if (item_slot[i] == 0) {
			item_slot[i] = item;
			place = i + 1;
			break;
		}
		if (i == 5) place = 0;
	}
	return place;
}

int item_lost(int item) {
	for (int i = 0; i < 5; i++) {
		if (item_slot[i] == item) {
			item_slot[i] = 0;
			break;
		}
	}
	return 0;
}

int input(int a) {
	char String[256];
	char Answer[] = "��҂���";
	char Answer1[] = "�ӂ���܂�";
	char Answer2[] = "�����炠";
	char Answer3[] = "�҂����炷";
	int InputHandle;

	SetDrawScreen(DX_SCREEN_BACK);
	InputHandle = MakeKeyInput(10, FALSE, FALSE, FALSE);
	SetActiveKeyInput(InputHandle);
	SetFontSize(80);

	while (!ProcessMessage()) {
		if (CheckKeyInput(InputHandle) != 0) break;
		ClearDrawScreen();
		DrawGraph(0, 0, mImageHandle25, FALSE);
		DrawKeyInputString(320, 370, InputHandle);
		ScreenFlip();
	}
	GetKeyInputString(String, InputHandle);
	DeleteKeyInput(InputHandle);
	ClearDrawScreen();
	if (String[0] == Answer[0] && String[1] == Answer[1] && String[2] == Answer[2]
		&& String[3] == Answer[3] && String[4] == Answer[4] && String[5] == Answer[5]
		&& String[6] == Answer[6] && String[7] == Answer[7] && String[8] == Answer[8]) {
		PlaySoundMem(SoundHandle10, DX_PLAYTYPE_NORMAL);
		lock4 = FALSE;
		a = 60;
	}
	else if(String[0] == Answer1[0] && String[1] == Answer1[1] && String[2] == Answer1[2]
		&& String[3] == Answer1[3] && String[4] == Answer1[4] && String[5] == Answer1[5]
		&& String[6] == Answer1[6] && String[7] == Answer1[7] && String[8] == Answer1[8]){
		PlaySoundMem(SoundHandle10, DX_PLAYTYPE_NORMAL);
		a = 75;
	}
	else if (String[0] == Answer2[0] && String[1] == Answer2[1] && String[2] == Answer2[2]
		&& String[3] == Answer2[3] && String[4] == Answer2[4] && String[5] == Answer2[5]
		&& String[6] == Answer2[6] && String[7] == Answer2[7] && String[8] == Answer2[8]) {
		PlaySoundMem(SoundHandle10, DX_PLAYTYPE_NORMAL);
		a = 77;
	}
	else if (String[0] == Answer3[0] && String[1] == Answer3[1] && String[2] == Answer3[2]
		&& String[3] == Answer3[3] && String[4] == Answer3[4] && String[5] == Answer3[5]
		&& String[6] == Answer3[6] && String[7] == Answer3[7] && String[8] == Answer3[8]) {
		PlaySoundMem(SoundHandle10, DX_PLAYTYPE_NORMAL);
		a = 79;
	}
	else {
		PlaySoundMem(SoundHandle11, DX_PLAYTYPE_NORMAL);
		a = 0;
	}
	SetFontSize(16);
	return a;
}

int pc(int a) 
{
	int AnswerNum[4] = {2,3,9,4};
	int InputNum[4] = {};
	
	a = 0;

	SetDrawScreen(DX_SCREEN_BACK);

	while (!ProcessMessage()) 
	{

		GetMousePoint(&MouseX, &MouseY);

		if ((720 <= MouseX) && (MouseX <= 840) && (420 <= MouseY) && (MouseY <= 640) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) break;
		if (380 <= MouseX && MouseX <= 430 && 260 <= MouseY && MouseY <= 300 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
			InputNum[0] = (InputNum[0] + 1) % 10;
			PlaySoundMem(SoundHandle12, DX_PLAYTYPE_BACK);
		}
		if ((380 <= MouseX) && (MouseX <= 430) && (360 <= MouseY) && (MouseY <= 400) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
			InputNum[0] = (InputNum[0] + 9) % 10;
			PlaySoundMem(SoundHandle12, DX_PLAYTYPE_BACK);
		}
		if (460 <= MouseX && MouseX <= 510 && 260 <= MouseY && MouseY <= 300 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
			InputNum[1] = (InputNum[1] + 1) % 10;
			PlaySoundMem(SoundHandle12, DX_PLAYTYPE_BACK);
		}
		if ((460 <= MouseX) && (MouseX <= 510) && (360 <= MouseY) && (MouseY <= 400) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
			InputNum[1] = (InputNum[1] + 9) % 10;
			PlaySoundMem(SoundHandle12, DX_PLAYTYPE_BACK);
		}
		if (540 <= MouseX && MouseX <= 590 && 260 <= MouseY && MouseY <= 300 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
			InputNum[2] = (InputNum[2] + 1) % 10;
			PlaySoundMem(SoundHandle12, DX_PLAYTYPE_BACK);
		}
		if ((540 <= MouseX) && (MouseX <= 590) && (360 <= MouseY) && (MouseY <= 400) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
			InputNum[2] = (InputNum[2] + 9) % 10;
			PlaySoundMem(SoundHandle12, DX_PLAYTYPE_BACK);
		}
		if (620 <= MouseX && MouseX <= 670 && 260 <= MouseY && MouseY <= 300 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
			InputNum[3] = (InputNum[3] + 1) % 10;
			PlaySoundMem(SoundHandle12, DX_PLAYTYPE_BACK);
		}
		if ((620 <= MouseX) && (MouseX <= 670) && (360 <= MouseY) && (MouseY <= 400) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
			InputNum[3] = (InputNum[3] + 9) % 10;
			PlaySoundMem(SoundHandle12, DX_PLAYTYPE_BACK);
		}
		ClearDrawScreen();
		DrawGraph(0, 0, mImageHandle38, FALSE);
		for (int i = 0; i < 4; i++) {
			DrawFormatStringToHandle(395 + i * 80,  310, White, FontHandle0, "%d",InputNum[i]);
		}
		OldMouseOshita = (GetMouseInput() & MOUSE_INPUT_LEFT);
		ScreenFlip();
	}
	ClearDrawScreen();
	if (InputNum[0] == AnswerNum[0] && InputNum[1] == AnswerNum[1] && InputNum[2] == AnswerNum[2] &&
		InputNum[3] == AnswerNum[3])
	{
		PlaySoundMem(SoundHandle10, DX_PLAYTYPE_NORMAL);
		lock2 = FALSE;
		a = 48;
	}
	else
	{
		PlaySoundMem(SoundHandle11, DX_PLAYTYPE_NORMAL);
	}
	return a;
}

//������
void Game_Initialize() {
	mImageHandle0 = LoadGraph("./images/left_arrow.png");
	mImageHandle1 = LoadGraph("./images/right_arrow.png");
	mImageHandle2 = LoadGraph("./images/room1.png");
	mImageHandle3 = LoadGraph("./images/room2.png");
	mImageHandle4 = LoadGraph("./images/room3.png");
	mImageHandle5 = LoadGraph("./images/room4.png");
	mImageHandle6 = LoadGraph("./images/item1.png");
	mImageHandle7 = LoadGraph("./images/item_slot.png");
	mImageHandle8 = LoadGraph("./images/match.png");
	mImageHandle9 = LoadGraph("./images/room5.png");
	mImageHandle10 = LoadGraph("./images/usefilter.png");
	mImageHandle11 = LoadGraph("./images/zukan.png");
	mImageHandle12 = LoadGraph("./images/kaeito.png");
	mImageHandle13 = LoadGraph("./images/grip.png");
	mImageHandle14 = LoadGraph("./images/danro1.png");
	mImageHandle15 = LoadGraph("./images/danro2.png");
	mImageHandle16 = LoadGraph("./images/ken.png");
	mImageHandle17 = LoadGraph("./images/tansuup2.png");
	mImageHandle18 = LoadGraph("./images/box01.png");
	mImageHandle19 = LoadGraph("./images/box02.png");
	mImageHandle20 = LoadGraph("./images/back_arrow.png");
	mImageHandle21 = LoadGraph("./images/siro.png");
	mImageHandle22 = LoadGraph("./images/kaeito.png");
	mImageHandle23 = LoadGraph("./images/moppu.png");
	mImageHandle24 = LoadGraph("./images/hukidasi.png");
	mImageHandle25 = LoadGraph("./images/input.png");
	mImageHandle26 = LoadGraph("./images/yogore.png");
	mImageHandle27 = LoadGraph("./images/roka.png");
	mImageHandle28 = LoadGraph("./images/tansu.png");
	mImageHandle29 = LoadGraph("./images/tansuup.png");
	mImageHandle30 = LoadGraph("./images/roka2.png");
	mImageHandle31 = LoadGraph("./images/bed.png");
	mImageHandle32 = LoadGraph("./images/chair.png");
	mImageHandle33 = LoadGraph("./images/chairbehinde.png");
	mImageHandle34 = LoadGraph("./images/sentakushi.png");
	mImageHandle35 = LoadGraph("./images/left_sentaku.png");
	mImageHandle36 = LoadGraph("./images/right_sentaku.png");
	mImageHandle37 = LoadGraph("./images/shelf.png");
	mImageHandle38 = LoadGraph("./images/pc.png");
	mImageHandle39 = LoadGraph("./images/maho.png");
	mImageHandle40 = LoadGraph("./images/zonbi.png");
	mImageHandle41 = LoadGraph("./images/under.png");
	mImageHandle42 = LoadGraph("./images/name.png");
	mImageHandle43 = LoadGraph("./images/namaniku.png");
	mImageHandle44 = LoadGraph("./images/gameover.png");
	mImageHandle45 = LoadGraph("./images/end.png");
	mImageHandle46 = LoadGraph("./images/end1.png");
	mImageHandle47 = LoadGraph("./images/yakiniku.png");
	mImageHandle48 = LoadGraph("./images/end3.png");//�摜�̃��[�h
	FontHandle0 = CreateFontToHandle(NULL, 30, 3);
	FontHandle1 = CreateFontToHandle(NULL, 11, 3);
	SoundHandle0 = LoadSoundMem("./sound/find.ogg");
	SoundHandle1 = LoadSoundMem("./sound/fire.ogg");
	SoundHandle2 = LoadSoundMem("./sound/ignition.ogg");
	SoundHandle3 = LoadSoundMem("./sound/door.ogg");
	SoundHandle4 = LoadSoundMem("./sound/book.ogg");
	SoundHandle5 = LoadSoundMem("./sound/next.ogg");
	SoundHandle6 = LoadSoundMem("./sound/cut.ogg");
	SoundHandle7 = LoadSoundMem("./sound/roka.ogg");
	SoundHandle8 = LoadSoundMem("./sound/footstep.ogg");
	SoundHandle9 = LoadSoundMem("./sound/lock.ogg");
	SoundHandle10 = LoadSoundMem("./sound/seikai.ogg");
	SoundHandle11 = LoadSoundMem("./sound/hazure.ogg");
	SoundHandle12 = LoadSoundMem("./sound/select.ogg");
	SoundHandle13 = LoadSoundMem("./sound/footstep2.ogg");
	SoundHandle14 = LoadSoundMem("./sound/bgm.ogg");
	SoundHandle15 = LoadSoundMem("./sound/ending.ogg");
	SoundHandle16 = LoadSoundMem("./sound/ending2.ogg");
	SoundHandle17 = LoadSoundMem("./sound/gameover.ogg");


	// �}�E�X��\����Ԃɂ���
	SetMouseDispFlag(TRUE);

	// ���F�̒l���擾
	White = GetColor(255, 255, 255);

	// ���̒l���擾
	Brack = GetColor(0, 0, 0);
	
	message = 44;

	PlaySoundMem(SoundHandle14, DX_PLAYTYPE_LOOP);
}

//�I������
void Game_Finalize() {
		DeleteGraph(mImageHandle0);
		DeleteGraph(mImageHandle1);
		DeleteGraph(mImageHandle2);
		DeleteGraph(mImageHandle3);
		DeleteGraph(mImageHandle4);
		DeleteGraph(mImageHandle5);
		DeleteGraph(mImageHandle6);
		DeleteGraph(mImageHandle7);
		DeleteGraph(mImageHandle8);
		DeleteGraph(mImageHandle9);
		DeleteGraph(mImageHandle10);
		DeleteGraph(mImageHandle11);
		DeleteGraph(mImageHandle12);
		DeleteGraph(mImageHandle13);
		DeleteGraph(mImageHandle14);
		DeleteGraph(mImageHandle15);
		DeleteGraph(mImageHandle16);
		DeleteGraph(mImageHandle17);
		DeleteGraph(mImageHandle18);
		DeleteGraph(mImageHandle19);
		DeleteGraph(mImageHandle20);
		DeleteGraph(mImageHandle21);
		DeleteGraph(mImageHandle22);
		DeleteGraph(mImageHandle23);
		DeleteGraph(mImageHandle24);
		DeleteGraph(mImageHandle25);
		DeleteGraph(mImageHandle26);
		DeleteGraph(mImageHandle27);
		DeleteGraph(mImageHandle28);
		DeleteGraph(mImageHandle29);
		DeleteGraph(mImageHandle30);
		DeleteGraph(mImageHandle31);
		DeleteGraph(mImageHandle32);
		DeleteGraph(mImageHandle33);
		DeleteGraph(mImageHandle34);
		DeleteGraph(mImageHandle35);
		DeleteGraph(mImageHandle36);
		DeleteGraph(mImageHandle37);
		DeleteGraph(mImageHandle38);
		DeleteGraph(mImageHandle39);
		DeleteGraph(mImageHandle40);
		DeleteGraph(mImageHandle41);
		DeleteGraph(mImageHandle42);
		DeleteGraph(mImageHandle43);
		DeleteGraph(mImageHandle44);
		DeleteGraph(mImageHandle45);
		DeleteGraph(mImageHandle46);
		DeleteGraph(mImageHandle47);
		DeleteGraph(mImageHandle48);
		DeleteFontToHandle(FontHandle0);
		DeleteFontToHandle(FontHandle1);
		DeleteSoundMem(SoundHandle0);
		DeleteSoundMem(SoundHandle1);
		DeleteSoundMem(SoundHandle2);
		DeleteSoundMem(SoundHandle3);
		DeleteSoundMem(SoundHandle4);
		DeleteSoundMem(SoundHandle5);
		DeleteSoundMem(SoundHandle6);
		DeleteSoundMem(SoundHandle7);
		DeleteSoundMem(SoundHandle8);
		DeleteSoundMem(SoundHandle9);
		DeleteSoundMem(SoundHandle10);
		DeleteSoundMem(SoundHandle11);
		DeleteSoundMem(SoundHandle12);
		DeleteSoundMem(SoundHandle13);
		DeleteSoundMem(SoundHandle14);
		DeleteSoundMem(SoundHandle15);
		DeleteSoundMem(SoundHandle16);
		DeleteSoundMem(SoundHandle17);
	//�摜�̉��
}

//�X�V
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
	// �}�E�X�̈ʒu���擾
	GetMousePoint(&MouseX, &MouseY);

	// �\�����镶������쐬
	{
		lstrcpy(StrBuf, "���W �w"); // ������"���W �w"��StrBuf�ɃR�s�[	
		itoa(MouseX, StrBuf2, 10); // MouseX�̒l�𕶎���ɂ���StrBuf2�Ɋi�[
		lstrcat(StrBuf, StrBuf2); // StrBuf�̓��e��StrBuf2�̓��e��t������
		lstrcat(StrBuf, "�@�x "); // StrBuf�̓��e�ɕ�����"�x"��t������
		itoa(MouseY, StrBuf2, 10); // MouseY�̒l�𕶎���ɂ���StrBuf2�Ɋi�[
		lstrcat(StrBuf, StrBuf2); // StrBuf�̓��e��StrBuf2�̓��e��t������
	}
	if (end != 0) {
		if ((GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
			DxLib_End();
		}
	}
	if (direction == 4) {
		if (message == 56 && end == 0) {
			end = 1;
			StopSoundMem(SoundHandle14);
			PlaySoundMem(SoundHandle15, DX_PLAYTYPE_LOOP);
		}
		if (message == 82 && end == 0) {
			end = 3;
			StopSoundMem(SoundHandle14);
			PlaySoundMem(SoundHandle16, DX_PLAYTYPE_LOOP);
		}
		if (message != 0) {
			if (165 <= MouseX && MouseX <= 925 && 465 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
				message++;
			}
		}
	}
	if (direction == 5) {
		if (message == 110 || message == 132) {
			if (165 <= MouseX && MouseX <= 925 && 465 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
				direction = 2;
				message = 0;
			}
		}
		if (message == 130) {
			if (165 <= MouseX && MouseX <= 925 && 465 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
				item8get = item_get(8);
				PlaySoundMem(SoundHandle0, DX_PLAYTYPE_BACK);
			}
		}
		if (message == 149) {
			if (165 <= MouseX && MouseX <= 925 && 465 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
				end = 2;
				StopSoundMem(SoundHandle14);
				PlaySoundMem(SoundHandle17, DX_PLAYTYPE_LOOP);
			}
		}
		if ((message < 107 && message > 99) || message == 109 || (message > 127 && message < 138) || message == 148) {
			if (165 <= MouseX && MouseX <= 925 && 465 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
				message++;
			}
		}
		if (message == 108 || message == 118 || message == 138) {
			if (165 <= MouseX && MouseX <= 925 && 465 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
				message = 109;
			}
		}
		if (message == 107) {
			if ((200 <= MouseX) && (MouseX <= 310) && (230 <= MouseY) && (MouseY <= 245) && item3get != 0) {
				SelectNum_3 = 1;
			}
			if ((200 <= MouseX) && (MouseX <= 310) && (280 <= MouseY) && (MouseY <= 295) && item5get != 0) {
				SelectNum_3 = 2;
			}
			if ((200 <= MouseX) && (MouseX <= 310) && (330 <= MouseY) && (MouseY <= 345) && item6get != 0) {
				SelectNum_3 = 3;
			}
			if ((200 <= MouseX) && (MouseX <= 310) && (380 <= MouseY) && (MouseY <= 395) && item7get != 0) {
				SelectNum_3 = 4;
			}
			if ((200 <= MouseX) && (MouseX <= 310) && (430 <= MouseY) && (MouseY <= 445)) {
				SelectNum_3 = 5;
			}
			if ((200 <= MouseX) && (MouseX <= 310) && (230 <= MouseY) && (MouseY <= 245) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && SelectNum_3 == 1) {
				message = 108;
			}
			if ((200 <= MouseX) && (MouseX <= 310) && (280 <= MouseY) && (MouseY <= 295) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && SelectNum_3 == 2) {
				message = 118;
			}
			if ((200 <= MouseX) && (MouseX <= 310) && (330 <= MouseY) && (MouseY <= 345) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && SelectNum_3 == 3) {
				message = 128;
			}
			if ((200 <= MouseX) && (MouseX <= 310) && (380 <= MouseY) && (MouseY <= 395) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && SelectNum_3 == 4) {
				message = 138;
			}
			if ((200 <= MouseX) && (MouseX <= 310) && (430 <= MouseY) && (MouseY <= 445) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && SelectNum_3 == 5) {
				message = 148;
			}
		}
	}
	if(direction < 4){
	if (message == 0) {
		if (itemuse != 10) {
			if (box01open == TRUE) {
				if (355 <= MouseX && MouseX <= 600 && 200 <= MouseY && MouseY <= 360 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item6get == FALSE && item_info[6] == 0) {
					item6get = item_get(6);
					PlaySoundMem(SoundHandle0, DX_PLAYTYPE_BACK);
					message = 20;
				}
				if ((30 <= MouseX) && (MouseX <= 110) && (435 <= MouseY) && (MouseY <= 505) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
					box01open = FALSE;
				}
			}
			if (box02open == TRUE) {
				if (410 <= MouseX && MouseX <= 615 && 120 <= MouseY && MouseY <= 340 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item6get != 0 && itemuse == 6) {
					message = 5;
					item6get = item_lost(6);
					item4get = item_get(4);
					PlaySoundMem(SoundHandle6, DX_PLAYTYPE_BACK);
				}
				if (410 <= MouseX && MouseX <= 615 && 120 <= MouseY && MouseY <= 340 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && itemuse != 6) {
					message = 22;
				}
				if ((30 <= MouseX) && (MouseX <= 110) && (435 <= MouseY) && (MouseY <= 505) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
					box02open = FALSE;
				}
			}
			if (box04open == TRUE) {
				if ((30 <= MouseX) && (MouseX <= 110) && (435 <= MouseY) && (MouseY <= 505) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
					box04open = FALSE;
				}
			}
			if (box01open == FALSE && box02open == FALSE && box04open == FALSE) {
				if ((30 <= MouseX) && (MouseX <= 110) && (280 <= MouseY) && (MouseY <= 350) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
					direction = (direction + 3) % 4;
					PlaySoundMem(SoundHandle8, DX_PLAYTYPE_BACK);
				}
				if (970 <= MouseX && MouseX <= 1050 && 280 <= MouseY && MouseY <= 350 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
					direction = (direction + 1) % 4;
					PlaySoundMem(SoundHandle8, DX_PLAYTYPE_BACK);
				}
				if (direction == 0) {
					if (660 <= MouseX && MouseX <= 755 && 410 <= MouseY && MouseY <= 440 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock1 == TRUE) {
						message = 1;
					}
					if (660 <= MouseX && MouseX <= 755 && 410 <= MouseY && MouseY <= 440 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock1 == TRUE && item5get != 0 && itemuse == 5) {
						lock1 = FALSE;
						message = 12;
					}
					if (660 <= MouseX && MouseX <= 755 && 410 <= MouseY && MouseY <= 440 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock1 == FALSE && message == 0) {
						message = 40;
					}
					if (640 <= MouseX && MouseX <= 770 && 160 <= MouseY && MouseY <= 400 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock1 == FALSE && eat == 1) {
						message = 81;
						direction = 4;
					}
					if (640 <= MouseX && MouseX <= 770 && 160 <= MouseY && MouseY <= 400 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock1 == FALSE && eat == 0) {
						message = 53;
						direction = 4;
					}
					if (640 <= MouseX && MouseX <= 770 && 160 <= MouseY && MouseY <= 400 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock1 == TRUE) {
						message = 1;
					}
					if (300 <= MouseX && MouseX <= 500 && 180 <= MouseY && MouseY <= 430 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
						box02open = TRUE;
					}
				}
				if (direction == 1) {
					if (660 <= MouseX && MouseX <= 710 && 345 <= MouseY && MouseY <= 380 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item2get == FALSE && item_info[2] == 0) {
						message = 16;
						item2get = item_get(2);
						PlaySoundMem(SoundHandle0, DX_PLAYTYPE_BACK);
					}
					if (630 <= MouseX && MouseX <= 790 && 215 <= MouseY && MouseY <= 310 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
						box04open = TRUE;
					}
					if (350 <= MouseX && MouseX <= 435 && 200 <= MouseY && MouseY <= 260 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock2 == TRUE) {
						message = pc(0);
					}
					if (350 <= MouseX && MouseX <= 435 && 200 <= MouseY && MouseY <= 260 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock2 == FALSE) {
						
					}
					if (305 <= MouseX && MouseX <= 395 && 270 <= MouseY && MouseY <= 420 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item7get == FALSE && item_info[7] == 0) {
						message = 33;
						item7get = item_get(7);
						PlaySoundMem(SoundHandle0, DX_PLAYTYPE_BACK);
					}
					if (700 <= MouseX && MouseX <= 820 && 450 <= MouseY && MouseY <= 464 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock3 == TRUE) {
						message = 50;
					}
					if (700 <= MouseX && MouseX <= 820 && 465 <= MouseY && MouseY <= 500 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock3 == TRUE) {
						message = 49;
					}
					if (700 <= MouseX && MouseX <= 820 && 457 <= MouseY && MouseY <= 500 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock3 == FALSE) {
						box01open = TRUE;
					}
				}
				if (direction == 2) {
					if (290 <= MouseX && MouseX <= 345 && 435 <= MouseY && MouseY <= 465 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item1get == FALSE && item_info[1] == 0) {
						message = 14;
						item1get = item_get(1);
						PlaySoundMem(SoundHandle0, DX_PLAYTYPE_BACK);
					}
					if (700 <= MouseX && MouseX <= 800 && 150 <= MouseY && MouseY <= 450 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock2 == TRUE) {
						message = 27;
						PlaySoundMem(SoundHandle9, DX_PLAYTYPE_BACK);
					}
					if (box03open == TRUE) {
						if (760 <= MouseX && MouseX <= 770 && 190 <= MouseY && MouseY <= 420 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item3get == FALSE && item_info[3] == 0) {
							message = 24;
							item3get = item_get(3);
							PlaySoundMem(SoundHandle0, DX_PLAYTYPE_BACK);
						}
					}
					if (700 <= MouseX && MouseX <= 800 && 150 <= MouseY && MouseY <= 450 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock2 == FALSE && box03open == FALSE) {
						box03open = TRUE;
						PlaySoundMem(SoundHandle7, DX_PLAYTYPE_BACK);
					}
					if (355 <= MouseX && MouseX <= 480 && 400 <= MouseY && MouseY <= 460 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock4 == FALSE && item_info[8] == 0 && zonbi == 1) {
						direction = 5;
						PlaySoundMem(SoundHandle13, DX_PLAYTYPE_BACK);
						message = 107;
					}
					if (355 <= MouseX && MouseX <= 480 && 400 <= MouseY && MouseY <= 460 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock4 == FALSE && item_info[8] == 0 && zonbi == 0) {
						zonbi = 1;
						direction = 5;
						PlaySoundMem(SoundHandle13, DX_PLAYTYPE_BACK);
						message = 100;
					}
					if (355 <= MouseX && MouseX <= 480 && 400 <= MouseY && MouseY <= 460 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && lock4 == FALSE && item_info[8] == 1) {
						message = 71;
					}
				}
				if (direction == 3) {
					if (600 <= MouseX && MouseX <= 900 && 250 <= MouseY && MouseY <= 464 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item1get != 0 && itemuse == 1) {
						fire = TRUE;
						PlaySoundMem(SoundHandle2, DX_PLAYTYPE_BACK);
						item1get = item_lost(1);
						message = 46;
					}
					if (600 <= MouseX && MouseX <= 900 && 465 <= MouseY && MouseY <= 500 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item1get != 0 && itemuse == 1) {
						fire = TRUE;
						PlaySoundMem(SoundHandle2, DX_PLAYTYPE_BACK);
						item1get = item_lost(1);
						message = 45;
					}
					if (300 <= MouseX && MouseX <= 430 && 260 <= MouseY && MouseY <= 440 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item7get == 0 && chair == 1) {
						item7get = item_get(7);
						PlaySoundMem(SoundHandle0, DX_PLAYTYPE_BACK);
						chair = 0;
					}
					if (300 <= MouseX && MouseX <= 430 && 260 <= MouseY && MouseY <= 440 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item7get != 0 && itemuse == 7) {
						chair = 1;
						item7get = item_lost(7);
						itemuse = 0;
					}
					if (305 <= MouseX && MouseX <= 385 && 50 <= MouseY && MouseY <= 125 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && chair != 1) {
						message = 35;
					}
					if (305 <= MouseX && MouseX <= 385 && 50 <= MouseY && MouseY <= 125 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && chair == 1) {
						message = 66;
					}
					if (600 <= MouseX && MouseX <= 900 && 250 <= MouseY && MouseY <= 464 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item2get != 0 && itemuse == 2 && fire == TRUE) {
						message = 9;
						item2get = item_lost(2);
						lock3 = FALSE;
						PlaySoundMem(SoundHandle1, DX_PLAYTYPE_BACK);
					}
					if (600 <= MouseX && MouseX <= 900 && 465 <= MouseY && MouseY <= 500 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item2get != 0 && itemuse == 2 && fire == TRUE) {
						message = 8;
						item2get = item_lost(2);
						lock3 = FALSE;
						PlaySoundMem(SoundHandle1, DX_PLAYTYPE_BACK);
					}
					if (600 <= MouseX && MouseX <= 900 && 250 <= MouseY && MouseY <= 464 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item8get != 0 && itemuse == 8 && fire == TRUE) {
						message = 57;
						item8get = item_lost(8);
						item9get = item_get(9);
						PlaySoundMem(SoundHandle1, DX_PLAYTYPE_BACK);
					}
					if (600 <= MouseX && MouseX <= 900 && 465 <= MouseY && MouseY <= 500 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item8get != 0 && itemuse == 8 && fire == TRUE) {
						message = 56;
						item8get = item_lost(8);
						item9get = item_get(9);
						PlaySoundMem(SoundHandle1, DX_PLAYTYPE_BACK);
					}
				}
			}
			if (130 * item5get + 20 <= MouseX && MouseX <= 130 * item5get + 140 && 510 <= MouseY && MouseY <= 630 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item5get != 0) {
				if (itemuse == 5) { itemuse = 0; }
				else { itemuse = 5; }
			}
			if (130 * item6get + 20 <= MouseX && MouseX <= 130 * item6get + 140 && 510 <= MouseY && MouseY <= 630 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item6get != 0) {
				if (itemuse == 6) { itemuse = 0; }
				else { itemuse = 6; }
			}
			if (130 * item4get + 20 <= MouseX && MouseX <= 130 * item4get + 140 && 510 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item3get != 0 && item4get != 0 && itemuse == 3) {
				message = 29;
				item3get = item_lost(3);
				item4get = item_lost(4);
				item5get = item_get(5);
			}
			if (130 * item4get + 20 <= MouseX && MouseX <= 130 * item4get + 140 && 586 <= MouseY && MouseY <= 630 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item3get != 0 && item4get != 0 && itemuse == 3) {
				message = 30;
				item3get = item_lost(3);
				item4get = item_lost(4);
				item5get = item_get(5);
			}
			if (130 * item3get + 20 <= MouseX && MouseX <= 130 * item3get + 140 && 510 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item3get != 0 && item4get != 0 && itemuse == 4) {
				message = 29;
				item3get = item_lost(3);
				item4get = item_lost(4);
				item5get = item_get(5);
			}
			if (130 * item3get + 20 <= MouseX && MouseX <= 130 * item3get + 140 && 586 <= MouseY && MouseY <= 630 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item3get != 0 && item4get != 0 && itemuse == 4) {
				message = 30;
				item3get = item_lost(3);
				item4get = item_lost(4);
				item5get = item_get(5);
			}
			if (130 * item1get + 20 <= MouseX && MouseX <= 130 * item1get + 140 && 510 <= MouseY && MouseY <= 630 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item1get != 0) {
				if (itemuse == 1) { itemuse = 0; }
				else { itemuse = 1; }
			}
			if (130 * item2get + 20 <= MouseX && MouseX <= 130 * item2get + 140 && 510 <= MouseY && MouseY <= 630 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item2get != 0) {
				if (itemuse == 2) { itemuse = 0; }
				else { itemuse = 2; }
			}
			if (130 * item3get + 20 <= MouseX && MouseX <= 130 * item3get + 140 && 510 <= MouseY && MouseY <= 630 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item3get != 0) {
				if (itemuse == 3) { itemuse = 0; }
				else { itemuse = 3; }
			}
			if (130 * item4get + 20 <= MouseX && MouseX <= 130 * item4get + 140 && 510 <= MouseY && MouseY <= 630 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item4get != 0) {
				if (itemuse == 4) { itemuse = 0; }
				else { itemuse = 4; }
			}
			if (130 * item7get + 20 <= MouseX && MouseX <= 130 * item7get + 140 && 510 <= MouseY && MouseY <= 630 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item7get != 0) {
				if (itemuse == 7) { itemuse = 0; }
				else { itemuse = 7; }
			}
			if (130 * item8get + 20 <= MouseX && MouseX <= 130 * item8get + 140 && 510 <= MouseY && MouseY <= 630 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item8get != 0) {
				if (itemuse == 8) { itemuse = 0; }
				else { itemuse = 8; }
			}
			if (130 * item9get + 20 <= MouseX && MouseX <= 130 * item9get + 140 && 510 <= MouseY && MouseY <= 630 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item9get != 0) {
				if (itemuse == 9) { itemuse = 0; }
				else { itemuse = 9; }
			}
			if (130 * item8get + 50 <= MouseX && MouseX <= 130 * item8get + 110 && 470 <= MouseY && MouseY <= 490 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item8get != 0) {
				message = 61;
				item8get = item_lost(8);
			}
			if (130 * item9get + 50 <= MouseX && MouseX <= 130 * item9get + 110 && 470 <= MouseY && MouseY <= 490 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && item9get != 0) {
				message = 67;
				item9get = item_lost(9);
				eat = 1;
			}
		}
		if (itemuse == 10) {
			if ((200<= MouseX) && (MouseX <= 300) && (50 <= MouseY) && (MouseY <= 65) && item_info[1] == 1) {
				SelectNum = 1;
			}else
			if ((200 <= MouseX) && (MouseX <= 300) && (100 <= MouseY) && (MouseY <= 115) && item_info[2] == 1) {
				SelectNum = 2;
			}else
			if ((200 <= MouseX) && (MouseX <= 300) && (150 <= MouseY) && (MouseY <= 165) && item_info[3] == 1) {
				SelectNum = 3;
			}
			else
			if ((200 <= MouseX) && (MouseX <= 300) && (200 <= MouseY) && (MouseY <= 215) && item_info[4] == 1) {
				SelectNum = 4;
			}
			else
			if ((200 <= MouseX) && (MouseX <= 300) && (250 <= MouseY) && (MouseY <= 265) && item_info[5] == 1) {
				SelectNum = 5;
			}
			else
			if ((200 <= MouseX) && (MouseX <= 300) && (300 <= MouseY) && (MouseY <= 315) && item_info[6] == 1) {
				SelectNum = 6;
			}
			else
			if ((200 <= MouseX) && (MouseX <= 300) && (350 <= MouseY) && (MouseY <= 365) && item_info[7] == 1) {
				SelectNum = 7;
			}
			else
			if ((200 <= MouseX) && (MouseX <= 300) && (400 <= MouseY) && (MouseY <= 415) && item_info[8] == 1) {
				SelectNum = 8;
			}
			else
			if ((200 <= MouseX) && (MouseX <= 300) && (450 <= MouseY) && (MouseY <= 465) && item_info[9] == 1) {
				SelectNum = 9;
			}
			else { SelectNum = 0; }
		}
		if (800 <= MouseX && MouseX <= 920 && 510 <= MouseY && MouseY <= 630 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {		
			PlaySoundMem(SoundHandle4, DX_PLAYTYPE_BACK);
			if (itemuse == 10) { itemuse = 0; }		
			else { itemuse = 10; }
			SelectNum = 0;
		}
	}
	if (message != 0) {
		if (message == 65) {
			if (165 <= MouseX && MouseX <= 925 && 465 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
				end = 2;
				StopSoundMem(SoundHandle14);
				PlaySoundMem(SoundHandle17, DX_PLAYTYPE_LOOP);
			}
		}
		if (message == 69) {
			if (165 <= MouseX && MouseX <= 925 && 465 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
			
			}
		}
		if (message == 66) {
			if (165 <= MouseX && MouseX <= 925 && 465 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
				message = input(0);
			}
		}
		if (165 <= MouseX && MouseX <= 925 && 465 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
			message++;
		}
		if (165 <= MouseX && MouseX <= 925 && 465 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0 && (message == 6 || message == 31)) {
			PlaySoundMem(SoundHandle0, DX_PLAYTYPE_BACK);
		}
		if (message == 18) {
			if ((230 <= MouseX) && (MouseX <= 440) && (310 <= MouseY) && (MouseY <= 445)) {
				SelectNum_2 = 1;
			}
			if ((630 <= MouseX) && (MouseX <= 845) && (310 <= MouseY) && (MouseY <= 445)) {
				SelectNum_2 = 2;
			}
			if ((230 <= MouseX) && (MouseX <= 440) && (310 <= MouseY) && (MouseY <= 445) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
				PlaySoundMem(SoundHandle3, DX_PLAYTYPE_BACK);
				message = 53;
				direction = 4;
			}
			if ((630 <= MouseX) && (MouseX <= 845) && (310 <= MouseY) && (MouseY <= 445) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
				message = 0;
			}
		}
		else {
			if (message == 4 || message == 8 || message == 11 || message == 13 || message == 15 || message == 17 || message == 19 || message == 21
				|| message == 23 || message == 26 || message == 28 || message == 32 || message == 34 || message == 37 || message == 39 || message == 43
				|| message == 45 || message == 47 || message == 49 || message == 52 || message == 59 || message == 61 || message == 70 || message == 72
				|| message == 74 || message == 76 || message == 78 || message == 80) {
				message = 0;
			}
		}
	}
}
	OldMouseOshita = (GetMouseInput() & MOUSE_INPUT_LEFT);
	Count++;
}

/////////////////////////////////////////////////////////////////////////�`��
void Game_Draw() {
	if (box01open != TRUE && itemuse != 10 && direction != 4) {
		DrawGraph(0, 0, mImageHandle0, FALSE);
		DrawGraph(940, 0, mImageHandle1, FALSE);
	}
	DrawGraph(140, 500, mImageHandle7, FALSE);
	if (itemuse == 10) {
		DrawModiGraph(
			800, 510,        //����
			920, 510,         //�E��
			920, 630,        //�E��
			800, 630,        //����
			mImageHandle10, TRUE);
	}
	if (item1get != 0) {
		DrawModiGraph(
			130 * item1get + 20, 510,        //����
			130 * item1get + 140, 510,         //�E��
			130 * item1get + 140, 630,        //�E��
			130 * item1get + 20, 630,        //����
			mImageHandle8, TRUE);
	}
	if (item1get != 0 && itemuse == 1) {
		DrawModiGraph(
			130 * item1get + 20, 510,        //����
			130 * item1get + 140, 510,         //�E��
			130 * item1get + 140, 630,        //�E��
			130 * item1get + 20, 630,        //����
			mImageHandle10, TRUE);
	}
	if (item2get != 0) {
		DrawModiGraph(
			130 * item2get + 20, 510,        //����
			130 * item2get + 140, 510,         //�E��
			130 * item2get + 140, 630,        //�E��
			130 * item2get + 20, 630,        //����
			mImageHandle6, TRUE);
	}
	if (item2get != 0 && itemuse == 2) {
		DrawModiGraph(
			130 * item2get + 20, 510,        //����
			130 * item2get + 140, 510,         //�E��
			130 * item2get + 140, 630,        //�E��
			130 * item2get + 20, 630,        //����
			mImageHandle10, TRUE);
	}
	if (item3get != 0) {
		DrawModiGraph(
			130 * item3get + 20, 510,        //����
			130 * item3get + 140, 510,         //�E��
			130 * item3get + 140, 630,        //�E��
			130 * item3get + 20, 630,        //����
			mImageHandle13, TRUE);
	}
	if (item3get != 0 && itemuse == 3) {
		DrawModiGraph(
			130 * item3get + 20, 510,        //����
			130 * item3get + 140, 510,         //�E��
			130 * item3get + 140, 630,        //�E��
			130 * item3get + 20, 630,        //����
			mImageHandle10, TRUE);
	}
	if (item4get != 0) {
		DrawModiGraph(
			130 * item4get + 20, 510,        //����
			130 * item4get + 140, 510,         //�E��
			130 * item4get + 140, 630,        //�E��
			130 * item4get + 20, 630,        //����
			mImageHandle22, TRUE);
	}
	if (item4get != 0 && itemuse == 4) {
		DrawModiGraph(
			130 * item4get + 20, 510,        //����
			130 * item4get + 140, 510,         //�E��
			130 * item4get + 140, 630,        //�E��
			130 * item4get + 20, 630,        //����
			mImageHandle10, TRUE);
	}
	if (item5get != 0) {
		DrawModiGraph(
			130 * item5get + 20, 510,        //����
			130 * item5get + 140, 510,         //�E��
			130 * item5get + 140, 630,        //�E��
			130 * item5get + 20, 630,        //����
			mImageHandle23, TRUE);
	}
	if (item5get != 0 && itemuse == 5) {
		DrawModiGraph(
			130 * item5get + 20, 510,        //����
			130 * item5get + 140, 510,         //�E��
			130 * item5get + 140, 630,        //�E��
			130 * item5get + 20, 630,        //����
			mImageHandle10, TRUE);
	}
	if (item6get != 0) {
		DrawModiGraph(
			130 * item6get + 20, 510,        //����
			130 * item6get + 140, 510,         //�E��
			130 * item6get + 140, 630,        //�E��
			130 * item6get + 20, 630,        //����
			mImageHandle16, TRUE);
	}
	if (item6get != 0 && itemuse == 6) {
		DrawModiGraph(
			130 * item6get + 20, 510,        //����
			130 * item6get + 140, 510,         //�E��
			130 * item6get + 140, 630,        //�E��
			130 * item6get + 20, 630,        //����
			mImageHandle10, TRUE);
	}
	if (item7get != 0) {
		DrawModiGraph(
			130 * item7get + 20, 510,        //����
			130 * item7get + 140, 510,         //�E��
			130 * item7get + 140, 630,        //�E��
			130 * item7get + 20, 630,        //����
			mImageHandle32, TRUE);
	}
	if (item7get != 0 && itemuse == 7) {
		DrawModiGraph(
			130 * item7get + 20, 510,        //����
			130 * item7get + 140, 510,         //�E��
			130 * item7get + 140, 630,        //�E��
			130 * item7get + 20, 630,        //����
			mImageHandle10, TRUE);
	}
	if (item8get != 0) {
		DrawModiGraph(
			130 * item8get + 20, 510,        //����
			130 * item8get + 140, 510,         //�E��
			130 * item8get + 140, 630,        //�E��
			130 * item8get + 20, 630,        //����
			mImageHandle43, TRUE);
	}
	if (item8get != 0 && itemuse == 8) {
		DrawModiGraph(
			130 * item8get + 20, 510,        //����
			130 * item8get + 140, 510,         //�E��
			130 * item8get + 140, 630,        //�E��
			130 * item8get + 20, 630,        //����
			mImageHandle10, TRUE);
	}
	if (item9get != 0) {
		DrawModiGraph(
			130 * item9get + 20, 510,        //����
			130 * item9get + 140, 510,         //�E��
			130 * item9get + 140, 630,        //�E��
			130 * item9get + 20, 630,        //����
			mImageHandle47, TRUE);
	}
	if (item9get != 0 && itemuse == 9) {
		DrawModiGraph(
			130 * item9get + 20, 510,        //����
			130 * item9get + 140, 510,         //�E��
			130 * item9get + 140, 630,        //�E��
			130 * item9get + 20, 630,        //����
			mImageHandle10, TRUE);
		DrawString(130 * item9get + 20, 450, "�H�ׂ�", Brack);
	}
	if (direction == 0) {
		DrawGraph(140, 0, mImageHandle2, FALSE);
		DrawGraph(250, 120, mImageHandle28, TRUE);
		if (lock1 == TRUE) {
			DrawGraph(620, 390, mImageHandle26, TRUE);
		}
	}
	if (direction == 1) {
		DrawGraph(140, 0, mImageHandle3, FALSE);
		if (item2get == 0 && item_info[2] == 0) {
				DrawModiGraph(
					645, 320,        //����
					725, 320,         //�E��
					725, 400,        //�E��
					645, 400,        //����
					mImageHandle6, TRUE);
		}
		if (item7get == 0 && item_info[7] == 0) {
			DrawGraph(260, 250, mImageHandle33, TRUE);
		}
		DrawGraph(700, 457, mImageHandle18, TRUE);		
		if (lock3 == TRUE) {
			DrawGraph(685, 385, mImageHandle39, TRUE);
		}
	}
	if (direction == 2) {
		DrawGraph(140, 0, mImageHandle4, FALSE);
		if (item1get == 0 && item_info[1] == 0) {
			DrawGraph(290, 405, mImageHandle8, TRUE);
		}
		if (lock4 == TRUE) {
			DrawGraph(145, 245, mImageHandle31, TRUE);
		}

		if (box03open == TRUE) {
			DrawGraph(655, 100, mImageHandle30, TRUE);
			if (item3get == 0 && item_info[3] == 0) {
				DrawGraph(655, 190, mImageHandle13, TRUE);
			}
		}
		else { DrawGraph(655, 100, mImageHandle27, TRUE); }
	}
	if (direction == 3) {
		DrawGraph(140, 0, mImageHandle5, FALSE);
		if (fire == FALSE) { DrawGraph(600, 250, mImageHandle14, TRUE); }
		else { DrawGraph(600, 250, mImageHandle15, TRUE); }
		if (chair == 1) {
			DrawGraph(280, 250, mImageHandle32, TRUE);
		}
	}
	if (direction == 4) {
		DrawGraph(0, 0, mImageHandle45, FALSE);
	}
	if (direction == 5) {
		if (message > 102) {
			DrawGraph(0, 0, mImageHandle41, FALSE);
		}
		if(message > 103){
			DrawGraph(550, 250, mImageHandle40, TRUE);
		}
	}
	if (box01open == TRUE) {
		DrawGraph(0, 0, mImageHandle20, FALSE);
		DrawGraph(140, 0, mImageHandle19, FALSE);
		DrawGraph(940, 0, mImageHandle21, FALSE);
		if (item6get == 0 && item_info[6] == 0) {
			DrawGraph(290, 100, mImageHandle16, TRUE);
		}
	}
	if (box02open == TRUE) {
		DrawGraph(940, 0, mImageHandle21, FALSE);
		DrawGraph(0, 0, mImageHandle20, FALSE);
		if (item4get == 0 && item_info[4] == 0) {
			DrawGraph(140, 0, mImageHandle29, TRUE);
		}
		else { DrawGraph(140, 0, mImageHandle17, TRUE); }
	}
	if (box04open == TRUE) {
		DrawGraph(0, 0, mImageHandle20, FALSE);
		DrawGraph(940, 0, mImageHandle21, FALSE);
		DrawGraph(140, 0, mImageHandle37, FALSE);
	}
	if (item8get != 0 && itemuse == 8) {
		DrawString(130 * item8get + 50, 470, "�H�ׂ�", Brack);
	}
	if (item9get != 0 && itemuse == 9) {
		DrawString(130 * item9get + 50, 470, "�H�ׂ�", Brack);
	}
	if (message != 0) {
		DrawGraph(140, 450, mImageHandle24, TRUE);
		DrawStringToHandle(880, 550 + sin(PI / 10 * Count) * 3, "��", Brack, FontHandle0);
	}
	if (message == 18) {
		DrawGraph(140, 300, mImageHandle34, TRUE);
		if (SelectNum_2 == 1) {
			DrawGraph(140, 300, mImageHandle35, TRUE);
		}
		if (SelectNum_2 == 2) {
			DrawGraph(140, 300, mImageHandle36, TRUE);
		}
	}
	if (message == 1) {
		DrawStringToHandle(200, 500, "�h�A�̑O�̏����ƂĂ�����", Brack, FontHandle0);
	}
	if (message == 2) {
		DrawStringToHandle(200, 500, "�Ԃ����Ⴏ�ʂ肽���Ȃ�", Brack, FontHandle0);
	}
	if (message == 3) {
		DrawStringToHandle(200, 500, "�|�����Ȃ��Ɓc", Brack, FontHandle0);
	}
	if (message == 5) {
		DrawStringToHandle(200, 500, "�u�`���̌��v�ŌR���̌��̏���؂�􂢂��B", Brack, FontHandle0);
	}
	if (message == 6) {
		DrawStringToHandle(200, 500, "�u���b�v(�ւ���)�v����ɓ��ꂽ�B", Brack, FontHandle0);
	}
	if (message == 7) {
		DrawStringToHandle(200, 500, "�u�`���̌��v�͉��Ă��܂����c", Brack, FontHandle0);
	}
	if (message == 9) {
		DrawStringToHandle(200, 500, "�u�Ԃׂ��v��g�F�ɂ��ׂ��B", Brack, FontHandle0);
	}
	if (message == 10) {
		DrawStringToHandle(200, 500, "�ǂ����ŕ���̉�����C�z�������B", Brack, FontHandle0);
	}
	if (message == 12) {
		DrawStringToHandle(200, 500, "��������B", Brack, FontHandle0);
	}
	if (message == 14) {
		DrawStringToHandle(200, 500, "�u�}�b�`�v����ɓ��ꂽ�B", Brack, FontHandle0);
	}
	if (message == 16) {
		DrawStringToHandle(200, 500, "�u�Ԃׂ��v����ɓ��ꂽ�B", Brack, FontHandle0);
	}
	if (message == 18) {
		DrawStringToHandle(200, 500, "�{���ɂ��̂܂ܕ�����E�o���܂����H", Brack, FontHandle0);
	}
	if (message == 20) {
		DrawStringToHandle(200, 500, "�u�`���̌��v����ɓ��ꂽ�B", Brack, FontHandle0);
	}
	if (message == 22) {
		DrawStringToHandle(200, 500, "���̂ӂ��ӂ��͂ƂĂ�������z�����Ă��ꂻ�����B", Brack, FontHandle0);
	}
	if (message == 24) {
		DrawStringToHandle(200, 500, "�u���b�v�i�O���b�v�j����ɓ��ꂽ�B�v", Brack, FontHandle0);
	}
	if (message == 25) {
		DrawStringToHandle(200, 500, "���ꂾ���ł͎g���Ȃ��B\n�������ꂻ���Ȃ��̂Ƒg�ݍ��킹�Ȃ��Ɓc", Brack, FontHandle0);
	}
	if (message == 27) {
		DrawStringToHandle(200, 500, "�����������Ă���B", Brack, FontHandle0);
	}
	if (message == 30) {
		DrawStringToHandle(200, 500, "�u���b�v�i�O���b�v�j�v�Ɓu���b�v�i�ւ����j�v\n��g�ݍ��킹���B", Brack, FontHandle0);
	}
	if (message == 31) {
		DrawStringToHandle(200, 500, "�u���b�v�v����ɓ��ꂽ�B", Brack, FontHandle0);
	}
	if (message == 33) {
		DrawStringToHandle(200, 500, "�u�֎q�v����ɓ��ꂽ�B", Brack, FontHandle0);
	}
	if (message == 35) {
		DrawStringToHandle(200, 500, "���̎��v�A�����I", Brack, FontHandle0);
	}
	if (message == 36) {
		DrawStringToHandle(200, 500, "�肪�A�͂��Ȃ��I", Brack, FontHandle0);
	}
	if (message == 38) {
		DrawStringToHandle(200, 500, "�߂��Ō��Ă݂������Ɏd�|���͂Ȃ������c", Brack, FontHandle0);
	}
	if (message == 40) {
		DrawStringToHandle(200, 500, "�悭����ƂȂɂ������Ă���c", Brack, FontHandle0);
	}
	if (message == 41) {
		DrawStringToHandle(200, 500, "�u�ӂ���܂��v", Brack, FontHandle0);
	}
	if (message == 42) {
		DrawStringToHandle(200, 500, "�Ȃ�̂��Ƃ��낤�B", Brack, FontHandle0);
	}
	if (message == 44) {
		DrawStringToHandle(200, 500, "�������B��������E�o���悤�B", Brack, FontHandle0);
	}
	if (message == 46) {
		DrawStringToHandle(200, 500, "�}�b�`�Œg�F�ɉ΂������B", Brack, FontHandle0);
	}
	if (message == 48) {
		DrawStringToHandle(200, 500, "�ǂ����Ń��b�J�[�̌����J�����������B", Brack, FontHandle0);
	}
	if (message == 50) {
		DrawStringToHandle(200, 500, "�J���Ȃ�", Brack, FontHandle0);
	}
	if (message == 51) {
		DrawStringToHandle(200, 500, "���@�I�ȗ͂ɂ���ĕ������Ă���B", Brack, FontHandle0);
	}
	if (message == 53) {
		DrawStringToHandle(200, 500, "�c�c", Brack, FontHandle0);
	}
	if (message == 54) {
		DrawStringToHandle(200, 500, "�������c�󂢂��c", Brack, FontHandle0);
	}
	if (message == 55) {
		DrawStringToHandle(200, 500, "�����c�c�c", Brack, FontHandle0);
	}
	if (message == 57) {
		DrawStringToHandle(200, 500, "���ɏĂ��܂���", Brack, FontHandle0);
	}
	if (message == 58) {
		DrawStringToHandle(200, 500, "�u���񂪂�ȓ��v����ɓ��ꂽ�B", Brack, FontHandle0);
	}
	if (message == 60) {
		DrawStringToHandle(200, 500, "�ǂ����ő傫�Ȃ��̂������鉹�������B", Brack, FontHandle0);
	}
	if (message == 62) {
		DrawStringToHandle(200, 500, "�����c����", Brack, FontHandle0);
	}
	if (message == 63) {
		DrawStringToHandle(200, 500, "�H���ł��̒���I�ށB", Brack, FontHandle0);
	}
	if (message == 64) {
		DrawStringToHandle(200, 500, "�΂��c�ʂ��΁c�c�c�悩���c���c", Brack, FontHandle0);
	}
	if (message == 65) {
		DrawStringToHandle(200, 500, "�c�c�c�c�c�c�c�c�c�c", Brack, FontHandle0);
	}
	if (message == 66) {
		DrawStringToHandle(200, 500, "���v�̗��ɉ�������", Brack, FontHandle0);
	}
	if (message == 68) {
		DrawStringToHandle(200, 500, "�ƂĂ���������", Brack, FontHandle0);
	}
	if (message == 69) {
		DrawStringToHandle(200, 500, "�������������ꂽ�B", Brack, FontHandle0);
	}
	if (message == 71) {
		DrawStringToHandle(200, 500, "�����s���K�v�͂Ȃ�", Brack, FontHandle0);
	}
	if (message == 73) {
		DrawStringToHandle(200, 500, "���ݖ������ł�", Brack, FontHandle0);
	}
	if (message == 75) {
		DrawStringToHandle(200, 500, "���̃��b�Z�[�W��������Ȃ�Ă������B", Brack, FontHandle0);
	}
	if (message == 77) {
		DrawStringToHandle(200, 500, "", Brack, FontHandle0);
	}
	if (message == 79) {
		DrawStringToHandle(200, 500, "�O�����̒藝", Brack, FontHandle0);
	}
	if (message == 81) {
		DrawStringToHandle(200, 500, "�E�o�������߂łƂ�", Brack, FontHandle0);
	}
	if (message == 100) {
		DrawStringToHandle(200, 500, "�����K�i���c", Brack, FontHandle0);
	}
	if (message == 101) {
		DrawStringToHandle(200, 500, "�c�c", Brack, FontHandle0);
	}
	if (message == 102) {
		DrawStringToHandle(200, 500, "�c�c�I", Brack, FontHandle0);
	}
	if (message == 103) {
		DrawStringToHandle(200, 500, "�K�i���~���Ƃ����͒n�����������B", Brack, FontHandle0);
	}
	if (message == 104) {
		DrawStringToHandle(200, 500, "�N������B", Brack, FontHandle0);
	}
	if (message == 105) {
		DrawGraph(162, 390, mImageHandle42, TRUE);
		DrawStringToHandle(200, 500, "�����[", Brack, FontHandle0);
		DrawStringToHandle(200, 410, "�]���r", Brack, FontHandle0);
	}
	if (message == 106) {
		DrawStringToHandle(200, 500, "������I���܂����A�]���r���B", Brack, FontHandle0);
	}
	if (message == 107) {
		DrawStringToHandle(200, 500, "�ǂ����悤�H", Brack, FontHandle0);
		if (item3get > 0) {
			DrawString(200, 230, "���b�v�ŉ���", Brack);
		}
		if (item5get > 0) {
			DrawString(200, 280, "���b�v�ŉ���", Brack);
		}
		if (item6get > 0) {
			DrawString(200, 330, "�`���̌��ŉ���", Brack);
		}
		if (item7get > 0) {
			DrawString(200, 380, "�֎q�ŉ���", Brack);
		}
		if (SelectNum_3 > 0) {
			DrawString(180, 180 + SelectNum_3 * 50, "��", Brack);
		}
		DrawString(200, 430, "���߂�", Brack);
	}
	if (message == 109) {
		DrawStringToHandle(200, 500, "�������̃]���r������ɂ͂т����肾�I�I", Brack, FontHandle0);
	}
	if (message == 110) {
		DrawStringToHandle(200, 500, "���̂����ɓ����悤�B", Brack, FontHandle0);
	}
	if (message == 108) {
		DrawStringToHandle(200, 500, "���̃N�b�V�������Ȃ����A�U���͂�����!", Brack, FontHandle0);
	}
	if (message == 118) {
		DrawStringToHandle(200, 500, "�����N�b�V�����ɂȂ��ă_���[�W������Ȃ��B", Brack, FontHandle0);
	}
	if (message == 138) {
		DrawStringToHandle(200, 500, "�֎q��U��񂷂̂͊�Ȃ��B", Brack, FontHandle0);
	}
	if (message == 128) {
		DrawStringToHandle(200, 500, "�u�i�����������Z���j�I�v���z���ɂ��C�����܂��B", Brack, FontHandle0);
	}
	if (message == 129) {
		DrawStringToHandle(200, 500, "���ʂ͔��Q���I", Brack, FontHandle0);
	}
	if (message == 130) {
		DrawStringToHandle(200, 500, "�]���r��|�����B", Brack, FontHandle0);
	}
	if (message == 131) {
		DrawStringToHandle(200, 500, "�u�����v����ɓ��ꂽ�B", Brack, FontHandle0);
	}
	if (message == 132) {
		DrawStringToHandle(200, 500, "��ɖ߂낤�B", Brack, FontHandle0);
	}
	if (message == 148) {
		DrawStringToHandle(200, 500, "�����ނ�B�܂��ނ�B���߂��B", Brack, FontHandle0);
	}
	if (message == 149) {
		DrawStringToHandle(200, 500, "�]���r�ɐH�ׂ�ꂿ������B", Brack, FontHandle0);
	}
	if (itemuse == 10) { 
		DrawGraph(140, 0, mImageHandle11, TRUE);
		for (int i = 1; i < 10; i++) { // ���j���[���ڂ�`��
			if (item_info[i] == 1) {
				DrawFormatString(MenuElement[i].x, MenuElement[i].y, White, MenuElement[i].name);
			}
			else {
				DrawFormatString(MenuElement[i].x, MenuElement[i].y, White, MenuElement[0].name);
			}
		}
		if (SelectNum > 0) {
			DrawString(180, SelectNum * 50, "��", White);
		}
		if (SelectNum == 0) {
			DrawString(455, 65, "��x��ɓ��ꂽ�A�C�e���͖��O�ɃJ�[�\��������\n����ΐ��������邱�Ƃ��ł���B\n�E�o�̃q���g�ɂȂ邩���H\n\n���̉�ʂ����ɂ͉E���̃A�C�e���}�ӂ̃A�C\n�R�����N���b�N�B", White);
		}
		if (SelectNum == 1) {
			DrawStringToHandle(455, 65, "�΂����邱�Ƃ��ł���B", White, FontHandle0);
		}
		if (SelectNum == 2) {
			DrawString(455, 65, "���킸�ƒm�ꂽ�����������u�Ԃׂ��v�B\n����͂����ؐ��̐l�`�Ŗ��悯�̌��ʂ�����B\n�����Ėؐ��ł���B", White);
		}
		if (SelectNum == 3) {
			DrawString(455, 65, "��ʓI�ȁA����ւ���^�C�v�̃��b�v�B\n���ꂾ���ł͑|���p��Ƃ��Ă͖��ɗ����Ȃ��c\n�ǂ����ɉ�����z�����Ă��ꂻ���Ȏ���̂��̂�\n�Ȃ����낤���B", White);
		}
		if (SelectNum == 4) {
			DrawString(455, 65, "�`���̗͂ɂ��^�̎p�����߂����Ƃɐ�������\n�u���b�v�v�̑ւ����B\n���Ă͌R���̌��͂Ƃ��ĊK���╺�Ȃ���ʂ���\n���߂Ɏg�p����Ă�����������Ȃ������ƂȂ���\n�͂��Ă̈Ќ��͌���e���Ȃ��B\n�Ƃ���Ŏ��ۂ̌R���̌��͂͐؂����Ă����b�v\n�̑���ɂ͂Ȃ�Ȃ��̂ŁA�ƂɌR���Ɠ`���̌�\n�������Ă��^�������Ă͂����Ȃ��B\n", White);
		}
		if (SelectNum == 5) {
			DrawString(455, 65, "���w���̎��͂悭�g���Ă������ǁA�ŋ߂͑|���@\n�Ƃ��ق����΂���g���Ă���C�����鍡�����̍��A\n���������Β��w�ł����Z�ł��|���p��b�J�[��\n�͂ق����Ƃ���Ƃ�ƎG�Ђƃg���O�݂����Ȃ��\n���������ĂȂ������悤�ȁc�Ђ炪�Ȃł���Ƃ�\n���ď����Ƃ�݂Â炢�Ȃ��B\n�������L�v�f", White);
		}
		if (SelectNum == 6) {
			DrawString(455, 65, "���Amaz�Zn�œ͂����`���B\n����Ƃ����閂�𕥂����Ƃ��ł���͂͊�ł�\n���̃V�~�ɂ��L���ōJ�ł͎�w�̊ԂŐl�C�㏸��\n�Ԉ���ĕ���؂��Ă��܂�Ȃ��悤�ɒ��ӂ��悤�B", White);
		}
		if (SelectNum == 7) {
			DrawString(455, 65, "�w�Z�Ƃ��ɂ悭����^�C�v�̈֎q�B\n���΍����Ƃ���Ɏ肪�͂��悤�ɂȂ邪�֎q��\n��ɗ��̂͊�Ȃ����s�V�������̂Ŏ��ۂ͂��\n���ق��������B\n\n\n�g����\n�u�֎q�v���g�p��Ԃɂ��āA�肪�͂��Ȃ��ꏊ��\n���̕����N���b�N����Ƃ����ɒu�����Ƃ��ł���B\n���̏�Ԃō����Ƃ���𒲂ׂ悤�B", White);
		}
		if (SelectNum == 8) {
			DrawString(455, 65, "�]���r��|�������Ɏ�ɓ��ꂽ�����B�Ȃ��]���r\n��|���Đ�������ɓ���̂��͂킩��Ȃ��B\n�@���������n�����ɒu���Ă�������\n�A�]���r�̓����͂��������\n�B�v���O�����~�X��\n�����l�����邪�A�{���̏��͂悭�킩��Ȃ��B\n�Ƃɂ����Ȃ�̓��ɂ�����M�����ɐH�ׂ�̂�\n�������߂��Ȃ��B�咰�ۂ�񐶒��A�T�����l���A\n�J���s���o�N�^�[�B�댯�ȗv�f���グ��΂���\n���Ȃ��B\n", White);
		}
		if (SelectNum == 9) {
			DrawString(455, 65, "��̓������ɏĂ��Ēa�������u���񂪂�ȓ��v\n�J��Ԃ����u���񂪂�ȓ��v�ł���B\n���܂��܋��R�A�^��Q�[�̃A�C�e���ɖ��O������\n���܂������̈ӂł͂Ȃ����R�ł���B�S��������\n���������S�R�A�ӎ��Ƃ��͂��ĂȂ��񂾂���ˁB\n���Ⴂ���Ȃ��ł�ˁB", White);
		}
	}
	if (end == 1) {
		DrawGraph(0, 0, mImageHandle46, FALSE);
	}
	if (end == 2) {
		DrawGraph(0, 0, mImageHandle44, FALSE);
	}
	if (end == 3) {
		DrawGraph(0, 0, mImageHandle48, FALSE);
	}
	// ��ʍ���̗̈�ɍ����l�p��`���O�ɕ`���Ă�����
	// �����������
	//DrawBox(0, 0, 200, 32, Brack, TRUE);

	// ���W�������`��
	//DrawString(0, 0, StrBuf, White);
}
