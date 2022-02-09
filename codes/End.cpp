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
static int mImageHandle5;    //画像ハンドル格納用変数
static int FontHandle0;
static int MouseX, MouseY;
static int White, Brack,end = 0;
static int message = 0,Count = 0;
static int OldMouseOshita;

//初期化
void End_Initialize() {
	mImageHandle0 = LoadGraph("images/under.png");//画像のロード
	mImageHandle1 = LoadGraph("images/zonbi.png");//画像のロード
	mImageHandle2 = LoadGraph("images/hukidasi.png");//画像のロード
	FontHandle0 = CreateFontToHandle(NULL, 30, 3);

	// 白色の値を取得
	White = GetColor(255, 255, 255);

	// 黒の値を取得
	Brack = GetColor(0, 0, 0);

	message = 1;

}

//終了処理
void End_Finalize() {
	DeleteGraph(mImageHandle0);//画像の解放
	DeleteGraph(mImageHandle1);//画像の解放
	DeleteGraph(mImageHandle2);//画像の解放
	DeleteGraph(mImageHandle3);//画像の解放
	DeleteGraph(mImageHandle4);//画像の解放
}
//更新
void End_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
	// マウスの位置を取得
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

//描画
void End_Draw() {
	DrawGraph(0, 0, mImageHandle0, FALSE);
	if (message != 0) {
		DrawGraph(140, 450, mImageHandle2, TRUE);
		DrawStringToHandle(880, 550 + sin(PI / 10 * Count) * 3, "▼", Brack, FontHandle0);
	}
	if (message == 1) {
		DrawStringToHandle(200, 500, "長い階段だ…", Brack, FontHandle0);
	}
	if (message == 2) {
		DrawStringToHandle(200, 500, "……", Brack, FontHandle0);
	}
	if (message == 3) {
		DrawStringToHandle(200, 500, "……！", Brack, FontHandle0);
	}
	if (message == 4) {
		DrawStringToHandle(200, 500, "階段を降りるとそこは地下室だった。", Brack, FontHandle0);
	}
	if (message == 5) {
		DrawStringToHandle(200, 500, "誰かいる。", Brack, FontHandle0);
	}
	if (message == 6) {
		DrawStringToHandle(200, 500, "がおー", Brack, FontHandle0);
	}
	if (message == 7) {
		DrawStringToHandle(200, 500, "うわっ！しまった、ゾンビだ。", Brack, FontHandle0);
	}
	if (message == 8) {
		DrawStringToHandle(200, 500, "どうしよう？", Brack, FontHandle0);
	}
}

