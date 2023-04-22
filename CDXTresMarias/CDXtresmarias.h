/**
*	CDXTresMarias
*	Autor:	Rafael Pagani Savastano
*	Versão:	1.0
*	Ult. Atualização:	28-Jul-2004
 **/

#ifndef __CDXTRESMARIAS_H__
#define __CDXTRESMARIAS_H__

#include "EasyWindow.h"

#include <list>
using namespace std;

#include <tchar.h>
#define CDXINCLUDEALL
#include <cdx.h>
#include "TMSprite.h"


// Dimensões da tela
#define SCREEN_LIMX 640
#define SCREEN_LIMY 480

// Altura do pulo do saquinho em pixels
#define JUMPHEIGHT (double) 245.0

// Estados do Gerenciador de Cena
#define STARTSCR 0
#define PLAYING 1
#define WON 2
#define LOST 3

// Duração da exibição das telas de gameover e vitória
#define GAMEOVERDUR (double) 5000.0
#define VICTORYDUR (double) 2000.0

// Duração inicial do pulo do saquinho
#define JUMPDURINI (double) 3000.0

// Número de fases
#define NUMFASES 10


class CDXTresMarias : public EasyWindow
{
	private:
		CDXScreen *Screen;

		CDXSurface *WorkSurface;
		CDXSurface *Picture;
		TMCursor *cursor;
		TMBagList *bagList;
		TMSprite* titleLogo;

		CDXSound Sound;
		CDXSoundBuffer *Audio;
		CDXSoundBuffer *GetSound;
		CDXSoundBuffer *FallSound;
		CDXMidi *BGM;

		CDXInput Input;

		int LastMouseKeySt;
		int m_Fase;
		LPCTSTR m_ScoreText;
		LPCTSTR m_StageText;
		double m_Timer;
		double throwTime;
		double JumpDur;
		bool isThrown;

		static int throwableQuant[NUMFASES];
		static int bagQuant[NUMFASES];

		void GameReset();
		void GetInput();
		void CreateScene();
		void DeleteScene();
		void ShowScore();
		void ShowStage();
		void StartScreenSetUp();

		TMBag* configNewBag(TMBagList* bagList, bool isThrow);
		static double GetLowResTime();
		static double GetHiResTime();

	public:
		CDXTresMarias() :
			Screen(nullptr),
			WorkSurface(nullptr),
			Picture(nullptr),
			cursor(nullptr),
			bagList(nullptr),
			titleLogo(nullptr),
			Sound(),
			Audio(nullptr),
			GetSound(nullptr),
			FallSound(nullptr),
			BGM(nullptr),
			Input(),
			LastMouseKeySt(CDXKEY_NONE),
			m_Fase(0),
			m_ScoreText(_T("0")),
			m_StageText(_T("0")),
			m_Timer(0.0),
			throwTime(0.0),
			JumpDur(0.0),
			isThrown(false),
			m_Score(0),
			m_GameState(STARTSCR)
		{
			::EasyWindow();
		}
		~CDXTresMarias() {
			DeleteScene();
			if (cursor != nullptr) delete cursor;
			if (WorkSurface != nullptr) delete WorkSurface;
			if (Picture != nullptr) delete Picture;
			if (Screen != nullptr) delete Screen;
			if (BGM != nullptr) { BGM->Shutdown(); delete BGM; }
			if (Audio != nullptr) { Audio->Stop(); delete Audio; }
			if (GetSound != nullptr) delete GetSound;
			if (FallSound != nullptr) delete FallSound;
		}

		int m_Score;
		int m_GameState;

		int InitEasyWindow();
		int EndEasyWindow();
		void Run();

		void PlayGet() { GetSound->Stop(); GetSound->Play(); }
		void PlayFall() { FallSound->Stop(); FallSound->Play(); }

		void GameLost();
		void GameWin();

		void SetThrowTime( double time ) { this->throwTime = time; }
		double GetThrowTime() { return throwTime;}

		double GetJumpDur() { return JumpDur; }

		int GetBagCount() { return bagQuant[(m_Fase%NUMFASES)]; }
		int GetFase() { return m_Fase; }

		CDXScreen* getScreen()   { return Screen; }
		CDXSurface* getSurface() { return WorkSurface; }

		double (*GetTick)();
	
};

#endif