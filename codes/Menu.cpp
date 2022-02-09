#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int GAME_Y = 405;    //「ゲーム」文字のy位置
const static int CONFIG_Y = 490;    //「設定」文字のy位置
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
	eMenu_Game,        //ゲーム
	eMenu_Config,    //設定

	eMenu_Num,        //本項目の数
} eMenu;

static int NowSelect = eMenu_Game;    //現在の選択状態(初期はゲーム選択中)

static int mImageHandle;    //画像ハンドル格納用変数

//初期化
void Menu_Initialize() {
	mImageHandle = LoadGraph("./images/Scene_Menu.png");    //画像のロード
	SoundHandle0 = LoadSoundMem("./sound/.ogg");
	SoundHandle1 = LoadSoundMem("./sound/.ogg");
	SoundHandle2 = LoadSoundMem("./sound/.ogg");
	FontHandle = CreateFontToHandle(NULL, 50, 3);
	
	// マウスを表示状態にする
	SetMouseDispFlag(TRUE);

	// 白色の値を取得
	StringCr = GetColor(255, 255, 255);

	// 黒の値を取得
	BoxCr = GetColor(0, 0, 0);

	PlaySoundMem(SoundHandle0, DX_PLAYTYPE_LOOP);
}

//終了処理
void Menu_Finalize() {
	DeleteGraph(mImageHandle);    //画像の解放
}

//更新
void Menu_Update() {
	// マウスの位置を取得
	GetMousePoint(&MouseX, &MouseY);
	if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {//下キーが押されていたら
		NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
	}
	if (Keyboard_Get(KEY_INPUT_UP) == 1) {//上キーが押されていたら
		NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
	}
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//エンターキーが押されたら
		switch (NowSelect) {//現在選択中の状態によって処理を分岐
		case eMenu_Game://ゲーム選択中なら
			SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
			break;
		case eMenu_Config://設定選択中なら
			SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
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
	// 表示する文字列を作成
	{
		lstrcpy(StrBuf, "座標 Ｘ"); // 文字列"座標 Ｘ"をStrBufにコピー	
		itoa(MouseX, StrBuf2, 10); // MouseXの値を文字列にしてStrBuf2に格納
		lstrcat(StrBuf, StrBuf2); // StrBufの内容にStrBuf2の内容を付け足す
		lstrcat(StrBuf, "　Ｙ "); // StrBufの内容に文字列"Ｙ"を付け足す
		itoa(MouseY, StrBuf2, 10); // MouseYの値を文字列にしてStrBuf2に格納
		lstrcat(StrBuf, StrBuf2); // StrBufの内容にStrBuf2の内容を付け足す
	}
	OldMouseOshita = (GetMouseInput() & MOUSE_INPUT_LEFT);
}

//描画
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	int y = 0;
	switch (NowSelect) {//現在の選択状態に従って処理を分岐
	case eMenu_Game://ゲーム選択中なら
		y = GAME_Y;    //ゲームの座標を格納
		break;
	case eMenu_Config://設定選択中なら
		y = CONFIG_Y;    //設定の座標を格納
		break;
	}
	DrawStringToHandle(285, y, "→", GetColor(8, 138, 8), FontHandle);
	// 画面左上の領域に黒い四角を描き前に描いてあった
	// 文字列を消す
	//DrawBox(0, 0, 200, 32, BoxCr, TRUE);
	// 座標文字列を描く
	//DrawString(0, 0, StrBuf, StringCr);
}
