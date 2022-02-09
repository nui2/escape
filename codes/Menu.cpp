#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int GAME_Y = 405;    //�u�Q�[���v������y�ʒu
const static int CONFIG_Y = 490;    //�u�ݒ�v������y�ʒu
static int MouseX, MouseY;
static char StrBuf[128], StrBuf2[32];
static int StringCr, BoxCr;
static int OldMouseOshita;
static int FontHandle;
static int SoundHandle0;
static int SoundHandle1;
static int SoundHandle2;
static int SoundHandle3;


typedef enum {
	eMenu_Game,        //�Q�[��
	eMenu_Config,    //�ݒ�

	eMenu_Num,        //�{���ڂ̐�
} eMenu;

static int NowSelect = eMenu_Game;    //���݂̑I�����(�����̓Q�[���I��)

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�

//������
void Menu_Initialize() {
	mImageHandle = LoadGraph("./images/Scene_Menu.png");    //�摜�̃��[�h
	SoundHandle0 = LoadSoundMem("./sound/.ogg");
	SoundHandle1 = LoadSoundMem("./sound/.ogg");
	SoundHandle2 = LoadSoundMem("./sound/.ogg");
	FontHandle = CreateFontToHandle(NULL, 50, 3);
	
	// �}�E�X��\����Ԃɂ���
	SetMouseDispFlag(TRUE);

	// ���F�̒l���擾
	StringCr = GetColor(255, 255, 255);

	// ���̒l���擾
	BoxCr = GetColor(0, 0, 0);

	PlaySoundMem(SoundHandle0, DX_PLAYTYPE_LOOP);
}

//�I������
void Menu_Finalize() {
	DeleteGraph(mImageHandle);    //�摜�̉��
}

//�X�V
void Menu_Update() {
	// �}�E�X�̈ʒu���擾
	GetMousePoint(&MouseX, &MouseY);
	if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {//���L�[��������Ă�����
		NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
	}
	if (Keyboard_Get(KEY_INPUT_UP) == 1) {//��L�[��������Ă�����
		NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
	}
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//�G���^�[�L�[�������ꂽ��
		switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
		case eMenu_Game://�Q�[���I�𒆂Ȃ�
			SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
			break;
		case eMenu_Config://�ݒ�I�𒆂Ȃ�
			SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
			break;
		}
	}
	if ((345 <= MouseX) && (MouseX <= 700) && (390 <= MouseY) && (MouseY <= 455)) {
		NowSelect = eMenu_Game;
	}
	if (345 <= MouseX && MouseX <= 550 && 456 <= MouseY && MouseY <= 550) {
		NowSelect = eMenu_Config;
	}
	if ((345 <= MouseX) && (MouseX <= 700) && (390 <= MouseY) && (MouseY <= 455) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
		SceneMgr_ChangeScene(eScene_Game);
	}
	if ((345 <= MouseX) && (MouseX <= 550) && (456 <= MouseY) && (MouseY <= 550) && (GetMouseInput() & MOUSE_INPUT_LEFT != 0) && OldMouseOshita == 0) {
		SceneMgr_ChangeScene(eScene_Config);
	}
	// �\�����镶������쐬
	{
		lstrcpy(StrBuf, "���W �w"); // ������"���W �w"��StrBuf�ɃR�s�[	
		itoa(MouseX, StrBuf2, 10); // MouseX�̒l�𕶎���ɂ���StrBuf2�Ɋi�[
		lstrcat(StrBuf, StrBuf2); // StrBuf�̓��e��StrBuf2�̓��e��t������
		lstrcat(StrBuf, "�@�x "); // StrBuf�̓��e�ɕ�����"�x"��t������
		itoa(MouseY, StrBuf2, 10); // MouseY�̒l�𕶎���ɂ���StrBuf2�Ɋi�[
		lstrcat(StrBuf, StrBuf2); // StrBuf�̓��e��StrBuf2�̓��e��t������
	}
	OldMouseOshita = (GetMouseInput() & MOUSE_INPUT_LEFT);
}

//�`��
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	int y = 0;
	switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
	case eMenu_Game://�Q�[���I�𒆂Ȃ�
		y = GAME_Y;    //�Q�[���̍��W���i�[
		break;
	case eMenu_Config://�ݒ�I�𒆂Ȃ�
		y = CONFIG_Y;    //�ݒ�̍��W���i�[
		break;
	}
	DrawStringToHandle(285, y, "��", GetColor(8, 138, 8), FontHandle);
	// ��ʍ���̗̈�ɍ����l�p��`���O�ɕ`���Ă�����
	// �����������
	//DrawBox(0, 0, 200, 32, BoxCr, TRUE);
	// ���W�������`��
	//DrawString(0, 0, StrBuf, StringCr);
}
