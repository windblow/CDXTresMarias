#define CDXINCLUDEALL
#include <cdx.h>

#include <mmsystem.h>

#include "CDXTresMarias.h"
#include <time.h>

// Configura��es de Saquinhos por fase;
int CDXTresMarias::throwableQuant[NUMFASES] = { 1, 1, 1, 2, 2, 2, 2, 3, 3, 3 };
int CDXTresMarias::bagQuant[NUMFASES] = { 2, 3, 4, 3, 4, 5, 6, 5, 7, 9 };

/**
*	M�todo:		Run()
*	Descri��o:	Loop Principal do Jogo
 **/
void CDXTresMarias::Run()
{
	if (!BGM->IsPlaying(0))
		BGM->Play(0);														// Caso a m�sica tenha terminado, reinicia a reprodu��o
	
	Picture->DrawBlk(WorkSurface,0,0);										// Desenha o background

	GetInput();																// Processa a entrada do jogador

	switch (m_GameState) // M�quina de Estados principal do jogo
	{
		case (LOST): //// Quando Perde o jogo. ////
			if ( GetTick() < m_Timer )
			{
				WorkSurface->TextXY((SCREEN_LIMX/2)-24,240,0, (LPCTSTR)L"GAME OVER");	// Exibe mensagem de Game Over pelo intervalo definido em GAMEOVERDUR
				bagList->Desenha(WorkSurface);								// Continua exibindo a tela do jogo em seu �ltimo estado
				break;
			}
			StartScreenSetUp();												// Reseta os valores da tela inicial
			m_GameState = STARTSCR;											// Muda o estado da m�quina

		case (STARTSCR): //// Quando na Tela inicial ////
			if (titleLogo->GetPosY() < 0)
				titleLogo->Move(0, 10);										// Anima��o do Logo
			else
				WorkSurface->TextXY((SCREEN_LIMX/2)-90,420,0, (LPCTSTR)L"Pressione ENTER para iniciar."); // Exibe mensagem da tela inicial 

			titleLogo->Desenha();
			break;

		case (WON): //// Quando obt�m Vit�ria no jogo ////
			if ( GetTick() < m_Timer )
			{
				WorkSurface->TextXY((SCREEN_LIMX/2)-30,240,0, (LPCTSTR)L"PARABENS!!"); // Exibe a congratula��o pelo intervalo deifinido em VICTORYDUR
				break;
			}
			m_Fase++;														// Aumenta a fase
			JumpDur -= 100.0;
			if (JumpDur <= 1000.0)											// Caso a dura��o do lan�amento chegue a menos de 1 segundo, o jogo acaba
			{
				StartScreenSetUp();											// Reseta os valores da tela inicial
				m_GameState = STARTSCR;										// Muda o estado da m�quina
				break;
			}
			DeleteScene();													// Deleta a cena atual
			CreateScene();													// Monta a cena da nova fase
			m_GameState = PLAYING;											// Muda o estado da m�quina

		case (PLAYING): //// Quando na Tela do jogo ////

			bagList->Desenha(WorkSurface);												// Desenha a cena

			if (bagList->GetBagsLeft() == (throwableQuant[m_Fase] + bagQuant[m_Fase]))	// Se ainda n�o foi feito o lan�amento, exibir a instru��o
				WorkSurface->TextXY((SCREEN_LIMX/2)-90,420,0, (LPCTSTR)L"Pressione ESPA�O para lan�ar.");

	} // Fim da M�quina de Estados

	ShowScore();									// Exibe a pontua��o se necess�rio
	ShowStage();									// Exibe a fase atual se necess�rio

	cursor->Desenha();								// Exibe o cursor do mouse

	WorkSurface->DrawBlk(Screen->GetBack(),0,0);	// Envia a tela para o back buffer

	Screen->Flip();									// Troca os buffers

} /** Fim do m�todo Run() **/



/**
*	M�todo:		InitEasyWindow()
*	Descri��o:	Inicializa o jogo
 **/
int CDXTresMarias::InitEasyWindow()
{
	LARGE_INTEGER freq;															// Seleciona o tipo de timer
	if (QueryPerformanceCounter(&freq))											//   a ser utilizado.
		GetTick = GetHiResTime;													//
	else																		//
		GetTick = GetLowResTime;												//


	Screen = new CDXScreen;														// Inicializa a
	if (FAILED(Screen->CreateWindowed(hwndWin, 640, 480)))						//   tela do jogo
  		return RET_ERROR;														//


	WorkSurface = new CDXSurface;												// Inicializa o 
	WorkSurface->Create(Screen,640,480,CDXMEM_SYSTEMONLY);						//   buffer de trabalho.


	Picture = new CDXSurface;													// Carrega a imagem
	Picture->Create(Screen,_T(".\\resources\\3mariasBG.bmp"),CDXMEM_SYSTEMONLY);	//   de fundo.


	Input.Create(hinst, hwndWin);												// Inicializa a entrada de dados
	Input.SetMouseExclusive(TRUE);												// Atribui o modo de mouse exclusivo


	cursor = new TMCursor(this,_T(".\\resources\\cursor.bmp"), 21, 21, 0, 319, 239); // Inicializa o cursor do mouse


	if (FAILED(Sound.Create(hwndWin, TRUE)))									// Cria o objeto
		return RET_ERROR;														//   de som

	
	Sound.ContinuousPlay(TRUE);													// Habilita a reprodu��o cont�nua

	
	BGM = new CDXMidi;															// Carrega e inicia
	if (FAILED(	BGM->Init(hwndWin, &Sound)))									//   a reprodu��o de
		return RET_ERROR;														//   m�sica de fundo
	BGM->LoadMidi(_T(".\\resources\\bgm.mid"));									//
	BGM->SetVolume(1024);														//
	BGM->Play(0);																//


	Audio = new CDXSoundBuffer;													// Carrega e inicia
	if (FAILED(Audio->Load(&Sound,_T(".\\resources\\kidsplay.wav"))))			//   a reprodu��o do
		return RET_ERROR;														//   som ambiente
	Audio->Play(DSBPLAY_LOOPING);												//


	GetSound = new CDXSoundBuffer;												// Carrega no buffer de
	if (FAILED(GetSound->Load(&Sound,_T(".\\resources\\bagget.wav"))))			//   �udio o som de um
		return RET_ERROR;														//   saquinho sendo pego


	FallSound = new CDXSoundBuffer;												// Carrega no buffer de
	if (FAILED(FallSound->Load(&Sound,_T(".\\resources\\bagfall.wav"))))			//   �udio o som de um
		return RET_ERROR;														//   saquinho caindo no ch�o


	m_Score = 0;																// Inicializa o placar
	m_Fase = 0;																	// Inicializa o contador de fase
	throwTime = 0.0;															// Inicializa para zero o cron�metro de jogo
	JumpDur = JUMPDURINI;														// Inicializa a dura��o do lan�amento para o valor inicial definido dem JUMPDURINI
	LastMouseKeySt = 0;															// Atribui 'desclicado' ao �ltimo valor capturado do bot�o do mouse
	m_Timer = 0.0;																// Inicializa o timer das telas de jogo

	m_GameState = STARTSCR;														// Muda o estdo da m�quina pada "Tela Inicial"

	titleLogo = NULL;															// Limpa os ponteiros
	bagList = NULL;																// Limpa os ponteiros

	StartScreenSetUp();															// Inicializa as vari�veis para a Tela Inicial

	return RET_OK;
} /** Fim do m�todo InitEasyWindow() **/



/**
*	M�todo:		EndEasyWindow()
*	Descri��o:	Finaliza o jogo
 **/
int CDXTresMarias::EndEasyWindow()
{
	Audio->Stop();				// Interrompe a execu��o do som ambiente

	BGM->Stop(0);				// Interrompe a execu��o da m�sica de fundo
	
	DeleteScene();				// Deleta qualquer cena que estiver na mem�ria

	if ( titleLogo != NULL )	// Deleta o logotipo caso ele esteja na mem�ria, e
		delete titleLogo;		//   limpa o endere�o do ponteiro

	delete cursor;				// Deleta vari�veis alocadas dinamicamente.
	delete WorkSurface;			//
	delete Picture;				//
	delete Screen;				//
	delete BGM;					//
	delete Audio;				//
	delete GetSound;			//
	delete FallSound;			//

	return RET_OK;
} /** Fim do m�todo EndEasyWindow() **/



/**
*	M�todo:		ShowScore()
*	Descri��o:	Exibe a pontua��o do jogador na tela
 **/
void CDXTresMarias::ShowScore()
{
	if (m_GameState != STARTSCR)						// Se n�o estivermos na Tela inicial
	{
		TCHAR buffer[33];
		_itot_s(m_Score, buffer, 10);
		m_ScoreText = (LPCTSTR)buffer;
		WorkSurface->TextXY(555, 5, 0, (LPCTSTR)L"Pontua��o");
		WorkSurface->TextXY(555, 20, 0, m_ScoreText);
	}
} /** Fim do m�todo ShowScore() **/



/**
*	M�todo:		ShowStage()
*	Descri��o:	Exibe a fase atual do jogo na tela
 **/
void CDXTresMarias::ShowStage()
{
	if (m_GameState != STARTSCR)						// Se n�o estivermos na Tela inicial
	{
		TCHAR buffer[33];
		_itot_s(m_Fase+1, buffer, 10);
		m_StageText = (LPCTSTR)buffer;
		WorkSurface->TextXY(15, 5, 0, (LPCTSTR)L"Fase");
		WorkSurface->TextXY(15, 20, 0, m_StageText);
	}
} /** Fim do m�todo ShowStage() **/



/**
*	M�todo:		GameReset()
*	Descri��o:	Reinicia todas as vari�veis ao estado prim�rio
 **/
void CDXTresMarias::GameReset()
{
	if (titleLogo != NULL)
	{
		delete titleLogo;					// Deleta a imagem do logotipo
		titleLogo = NULL;					// Deleta a refer�ncia de mem�ria
	}

	m_Score = 0;							// Reinicia o placar
	m_Fase = 0;								// Reinicia o contador de fase

	DeleteScene();							// Deleta a cena atual
	CreateScene();							// Cria uma cena nova na fase atual (1)

	m_GameState = PLAYING;					// Muda o estado da M�quina para "Jogando"

} /** Fim do m�todo GameReset() **/



/**
*	M�todo:		GameLost()
*	Descri��o:	Perde o jogo e inicia o processo de Game Over
 **/
void CDXTresMarias::GameLost()
{
	m_Timer = GetTick() + GAMEOVERDUR;		// Atribui ao tempo de dura��o da tela o valor definido em GAMEOVERDUR
	bagList->Deactivate();					// Desativa os cliques em todos os saquinhos exibidos na tela
	JumpDur = JUMPDURINI;					// Reseta a dura��o do lan�amento para o tempo inicial definido em JUMPDURINI
	m_GameState = LOST;						// Muda o estado da M�quina para "Perdeu"
} /** Fim do m�todo GameLost() **/



/**
*	M�todo:		GameWin()
*	Descri��o:	Vence o jogo e troca de fase
 **/
void CDXTresMarias::GameWin()
{
	m_Score += ((int)(((throwTime + JumpDur) - GetTick())/100) * (10*(m_Fase+1)));	// Calcula a pontua��o ganha pelo tempo de lan�amento restante na fase
	m_Timer = GetTick() + VICTORYDUR;												// Atribui ao tempo de dura��o da tela o valor definido em VICTORYDUR
	m_GameState = WON;																// Muda o estado da M�quina para "Ganhou"
} /** Fim do m�todo GameWin() **/



/**
*	M�todo:		StartScreenSetUp()
*	Descri��o:	Configura o jogo para a exibi��o da Tela Inicial
 **/
void CDXTresMarias::StartScreenSetUp()
{
	DeleteScene();																			// Deleta alguma cena existente

	titleLogo = new TMSprite(this,_T(".\\resources\\titlescr.bmp"), 640, 480, 0, 0, -450);	// Carrega a imagem da tela de abertura
	titleLogo->SetColorKey();																// Habilita a transpar�ncia

} /** Fim do m�todo StartScreenSetUp() **/



/**
*	M�todo:		CreateScene()
*	Descri��o:	Configura a tela e cria os saquinhos de acordo com a configura��o da fase
 **/
void CDXTresMarias::CreateScene()
{
	bagList = new TMBagList( this );									// Cria uma nova lista din�mica de saquinhos

	srand ( (unsigned)time(NULL));										// Inicializa o randomizador num�rico

	for (int i = 0; i < throwableQuant[(m_Fase%NUMFASES)]; i++)			// Cria os saquinhos
	{																	//   atir�veis
		bagList->AddBag(configNewBag(bagList, true));					//
	}																	//

	for (int j = 0; j < bagQuant[(m_Fase%NUMFASES)]; j++)				// Cria o resto
	{																	//   dos saquinhos
		bagList->AddBag(configNewBag(bagList, false));					//   da fase
	}

} /** Fim do m�todo CreateScene() **/



/**
*	M�todo:		DeleteScene()
*	Descri��o:	Limpa a lista de saquinhos e prepara o jogo para uma pr�xima configura��o
 **/
void CDXTresMarias::DeleteScene()
{
	if (bagList != NULL)					// Limpa a lista
	{										//   de saquinhos
		delete bagList;						//
		bagList = NULL;						//
	}										//
	
	isThrown = false;						// Reseta o estado de lan�amento

} /** Fim do m�todo CreateScene() **/



/**
*	M�todo:		configNewBag()
*	Descri��o:	Configura um novo saquinho
 **/
TMBag* CDXTresMarias::configNewBag(TMBagList* bagList, bool isThrow = false)
{
	int tempx, tempy, tempLayer, tempLook;
	TCHAR filename[23];

	if (isThrow)																		// Se for um saquinho atir�vel,
	{																					//   as configura��es s�o fixas
		tempLayer=0;																	// Layer frontal.
		tempy = 300;																	// Mesma altura na tela
		int i = 0;
		do																				// Configura a posi��o X
		{																				//   centralizada na tela
			i++;																		//   e de acordo com o
			tempx = (((SCREEN_LIMX / (throwableQuant[(m_Fase%NUMFASES)]+1)) * i) - 80);	//   n�mero total de
																						//   saquinhos atir�veis
			if (tempx < 0)																//   da fase atual.
				tempx = 0;																//
			else if (tempx > SCREEN_LIMX - 160)											//
				tempx = (SCREEN_LIMX - 160);											//
																						//
		} while (bagList->IsBagInPos(tempx, tempy, tempLayer));							// Repete enquanto j� houver saquinho na posi��o
	
	} else {													// Se for um saquinho comum

		do														// Configura a tela
		{														//   para exibir os
			tempx = ((rand()%4) * 160);							//   saquinhos em alturas
			tempLayer = (rand()%4)+1;							//   e posi��es diferentes
			tempy = (((4 - tempLayer) * 25) + 200);				//
		} while (bagList->IsBagInPos(tempx, tempy, tempLayer));	// Repete enquanto j� houver saquinho na posi��o
	}

	tempLook = rand()%5;																		// Seleciona aleatoriamente a cor do saquinho
	int tmp = _stprintf_s(filename, sizeof(filename),_T(".\\resources\\bag%d.bmp"), tempLook);

	TMBag* tempBag = new TMBag(this, filename, 160, 120, 10, tempx, tempy, tempLayer, isThrow);	// Chama o construtor do saquinho com as configura��es acertadas
	
	tempBag->SetColorKey();																		// Inicializa a transpar�ncia

	return (tempBag);																			// Retorna o ponteiro para o saquinho rec�m-criado
} /** Fim do m�todo configNewBag() **/


/**
*	M�todo:		GetInput()
*	Descri��o:	Recebe e processa a entrada do teclado
 **/
void CDXTresMarias::GetInput()
{
	Input.Update();														// Atualiza as informa��es do objeto CDXInput

	long x = 0, y = 0;

	Input.GetMouseDeltas(&x, &y);										// Pega o deslocamento do mouse desde o �ltimo frame

	cursor->Move(x,y);													// Move o cursor

	if (Input.GetKeyState(CDXKEY_ENTER) && m_GameState == STARTSCR)		// Se estivermos na Tela Inicial e for pressionado ENTER,
		GameReset();													//   o jogo se inicia

	if (Input.GetKeyState(CDXKEY_MOUSELEFT) && m_GameState == PLAYING)	// Se estivermos na tela de Jogo,
	{																	//    e for pressionado o BOT�O ESQUERDO do mouse,
		if (!LastMouseKeySt)											//    checa se o bot�o estava pressionado no frame
			bagList->Click(cursor);										//    anterior, e caso n�o esteja, emite o click para
		LastMouseKeySt = 1;												//    a tela de jogo.
	} else {															// Guarda o �ltimo estado do bot�o esquerdo do mouse
		LastMouseKeySt = 0;												//    para comparar com o pr�ximo frame
	}																	//

	if (Input.GetKeyState(CDXKEY_SPACE) && m_GameState == PLAYING)		// Se estivermos na tela de Jogo e for pressionado ESPA�O.
		if (!isThrown)													//    caso ainda n�o tenha havido lan�amento,
		{																//    os saquinhos lan��veis s�o atirados e os demais
			throwTime = GetTick();										//    habilitados para clique. A hora do lan�amento �
			bagList->Throw();											//    guardada para contagem posterior de pontos
			isThrown = true;											//
		}																//
} /** Fim do m�todo GetInput() **/



/**
*	M�todo:		GetLowResTime()
*	Descri��o:	Pega resultado de timers de baixa precis�o
 **/
double CDXTresMarias::GetLowResTime()
{
	return (double) timeGetTime();
} /** Fim do m�todo GetLowResTime() **/



/**
*	M�todo:		GetHiResTime()
*	Descri��o:	Pega resultado de timers de alta precis�o
 **/
double CDXTresMarias::GetHiResTime()
{
	LARGE_INTEGER freq, perf;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&perf);

	return (double)perf.QuadPart / (double)freq.QuadPart * 1000;
} /** Fim do m�todo GetHiResTime() **/



/**
*	M�todo:		WinMain()
*	Descri��o:	Procedure WinMain
 **/
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hInstAnt, LPSTR lpszCmd, int iCmd)
{
   CDXTresMarias jogo;

   jogo.SetUp((LPCTSTR)L"TresMarias", hInst, 0, 0, 640, 480);

   jogo.Start((LPCTSTR)L"Tr�s Marias");

   return(RET_OK);
} /** Fim do m�todo WinMain() **/