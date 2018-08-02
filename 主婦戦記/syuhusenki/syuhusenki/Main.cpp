#include "Main.h"
#include "GameMain.h"

SoundManager& soundManager = SoundManager::GetInstance();


RECT testWord = { 100,200,1100,500 };
void gameRoop();
int g_scene = SCENE_TEAMLOGO;
bool seOn = false;

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hInstance, LPSTR szStr, INT iCmdShow) {
	HWND hWnd = NULL;


	InitWindowEx("εwνL", &hWnd, WIDTH, HEIGHT, hInst, hInstance, NULL, "Texture/Yasuko.png");

	DirectSound::CreateInstance(hWnd);

	ReadInTexture("Texture/Blank.jpg", BLANK);
	ReadInTexture("Texture/Yasuko.png", YASUKO_TEX);
	ReadInTexture("Texture/karititle.png", BG_TEX);

	SetUpFont(100, 70, DEFAULT_CHARSET, NULL, FONT);
	soundManager.Load("Sound/Buppigan.wav");
	soundManager.Load("Sound/Buppigan2.wav");

	FlameRoop(gameRoop);

}
void gameRoop() {
	sound();
	switch (g_scene) {
	case SCENE_TEAMLOGO:
		control();
		render();
		break;
	case SCENE_TITLE:
		control();
		render();
		break;
	case SCENE_SERECTCHAR:
		control();
		render();
		break;
	case SCENE_SERECTSTEGE:
		control();
		render();
		break;
	case SCENE_MAIN:
		gameMain();
		break;
	case SCENE_RESULT:
		control();
		render();
		break;
	}

}

void control(void) {
	gamePad();
	
	CheckKeyState(DIK_RETURN);
	if (KeyState[DIK_RETURN] == KeyRelease)// ©L[π΅Δι
	{
		seOn = true;
		switch (g_scene) {
		case SCENE_TEAMLOGO:
			g_scene = SCENE_TITLE;
			break;
		case SCENE_TITLE:
			g_scene = SCENE_SERECTCHAR;
			break;
		case SCENE_SERECTCHAR:
			g_scene = SCENE_SERECTSTEGE;
			break;
		case SCENE_SERECTSTEGE:
			g_scene = SCENE_MAIN;
			break;
		case SCENE_MAIN:
			//g_scene = SCENE_RESULT;
			break;
		case SCENE_RESULT:
			g_scene = SCENE_TITLE;
			break;
		}
	}
}

void render(void) {
	BeginSetTexture();
	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, BLANK);

	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, YASUKO_TEX);

	switch (g_scene) {
	case SCENE_TEAMLOGO:
		WriteWord("SΝMadam", testWord, DT_CENTER, RED, FONT);
		break;
	case SCENE_TITLE:
		//WriteWord("εwνL", testWord, DT_CENTER, RED, FONT);
		EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, BG_TEX);

		break;
	case SCENE_SERECTCHAR:
		WriteWord("LIπ", testWord, DT_CENTER, RED, FONT);
		break;
	case SCENE_SERECTSTEGE:
		WriteWord("Xe[WIπ", testWord, DT_CENTER, RED, FONT);
		break;
	case SCENE_MAIN:
		WriteWord("CQ[", testWord, DT_CENTER, RED, FONT);
		break;
	case SCENE_RESULT:
		WriteWord("Ug", testWord, DT_CENTER, RED, FONT);
		break;
	}

	EndSetTexture();

}
void sound(void) {
	if (seOn) {
		soundManager.Play("Sound/Buppigan.wav", false);
		seOn = false;
	}

}
void gamePad() {
	//XInputfoCXμ
	GetControl(0);
	BottonCheck();
	if (PadState[ButtonA] == PadRelease) {
		seOn = true;
		switch (g_scene) {
		case SCENE_TEAMLOGO:
			g_scene = SCENE_TITLE;
			break;
		case SCENE_TITLE:
			g_scene = SCENE_SERECTCHAR;
			break;
		case SCENE_SERECTCHAR:
			g_scene = SCENE_SERECTSTEGE;
			break;
		case SCENE_SERECTSTEGE:
			g_scene = SCENE_MAIN;
			break;
		case SCENE_MAIN:
			g_scene = SCENE_RESULT;
			break;
		case SCENE_RESULT:
			g_scene = SCENE_TITLE;
			break;
		}

	}

}