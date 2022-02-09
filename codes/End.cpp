#include "End.h"
#include "game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "math.h"

#define PI 3.141592654f

static int mImageHandle0;
static int mImageHandle1;
static int mImageHandle2;
static int mImageHandle3;
static int mImageHandle4;
static int mImageHandle5;    //�摜�n���h���i�[�p�ϐ�
static int FontHandle0;
static int MouseX, MouseY;
static int White, Brack,end = 0;
static int message = 0,Count = 0;
static int OldMouseOshita;

//������
void End_Initialize() {
	mImageHandle0 = LoadGraph("images/under.png");//�摜�̃��[�h
	mImageHandle1 = LoadGraph("images/zonbi.png");//�摜�̃��[�h
	mImageHandle2 = LoadGraph("images/hukidasi.png");//�摜�̃��[�h
	FontHandle0 = CreateFontToHandle(NULL, 30, 3);

	// ���F�̒l���擾
	White = GetColor(255, 255, 255);

	// ���̒l���擾
	Brack = GetColor(0, 0, 0);

	message = 1;

}

//�I������
void End_Finalize() {
	DeleteGraph(mImageHandle0);//�摜�̉��
	DeleteGraph(mImageHandle1);//�摜�̉��
	DeleteGraph(mImageHandle2);//�摜�̉��
	DeleteGraph(mImageHandle3);//�摜�̉��
	DeleteGraph(mImageHandle4);//�摜�̉��
}
//�X�V
void End_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
	// �}�E�X�̈ʒu���擾
	GetMousePoint(&MouseX, &MouseY);

	if (message != 0) {
		if (165 <= MouseX && MouseX <= 925 && 465 <= MouseY && MouseY <= 585 && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
			message++;
		}
		if (message == 4) {
			message = 0;
		}
	}
	Count++;
	OldMouseOshita = (GetMouseInput() & MOUSE_INPUT_LEFT);
}

//�`��
void End_Draw() {
	DrawGraph(0, 0, mImageHandle0, FALSE);
	if (message != 0) {
		DrawGraph(140, 450, mImageHandle2, TRUE);
		DrawStringToHandle(880, 550 + sin(PI / 10 * Count) * 3, "��", Brack, FontHandle0);
	}
	if (message == 1) {
		DrawStringToHandle(200, 500, "�����K�i���c", Brack, FontHandle0);
	}
	if (message == 2) {
		DrawStringToHandle(200, 500, "�c�c", Brack, FontHandle0);
	}
	if (message == 3) {
		DrawStringToHandle(200, 500, "�c�c�I", Brack, FontHandle0);
	}
	if (message == 4) {
		DrawStringToHandle(200, 500, "�K�i���~���Ƃ����͒n�����������B", Brack, FontHandle0);
	}
	if (message == 5) {
		DrawStringToHandle(200, 500, "�N������B", Brack, FontHandle0);
	}
	if (message == 6) {
		DrawStringToHandle(200, 500, "�����[", Brack, FontHandle0);
	}
	if (message == 7) {
		DrawStringToHandle(200, 500, "������I���܂����A�]���r���B", Brack, FontHandle0);
	}
	if (message == 8) {
		DrawStringToHandle(200, 500, "�ǂ����悤�H", Brack, FontHandle0);
	}
}

