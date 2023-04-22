#define CDXINCLUDEALL
#include <cdx.h>

#include <mmsystem.h>

#include "CDXTresMarias.h"
#include <time.h>

// Configurações de Saquinhos por fase;
int CDXTresMarias::throwableQuant[NUMFASES] = { 1, 1, 1, 2, 2, 2, 2, 3, 3, 3 };
int CDXTresMarias::bagQuant[NUMFASES] = { 2, 3, 4, 3, 4, 5, 6, 5, 7, 9 };

/**
*	Método:		Run()
*	Descrição:	Loop Principal do Jogo
 **/
void CDXTresMarias::Run()
{
	if (!BGM->IsPlaying(0))
		BGM->Play(0);														// Caso a música tenha terminado, reinicia a reprodução
	
	Picture->DrawBlk(WorkSurface,0,0);										// Desenha o background

	GetInput();																// Processa a entrada do jogador

	switch (m_GameState) // Máquina de Estados principal do jogo
	{
		case (LOST): //// Quando Perde o jogo. ////
			if ( GetTick() < m_Timer )
			{
				WorkSurface->TextXY((SCREEN_LIMX/2)-24,240,0, (LPCTSTR)L"GAME OVER");	// Exibe mensagem de Game Over pelo intervalo definido em GAMEOVERDUR
				bagList->Desenha(WorkSurface);								// Continua exibindo a tela do jogo em seu último estado
				break;
			}
			StartScreenSetUp();												// Reseta os valores da tela inicial
			m_GameState = STARTSCR;											// Muda o estado da máquina

		case (STARTSCR): //// Quando na Tela inicial ////
			if (titleLogo->GetPosY() < 0)
				titleLogo->Move(0, 10);										// Animação do Logo
			else
				WorkSurface->TextXY((SCREEN_LIMX/2)-90,420,0, (LPCTSTR)L"Pressione ENTER para iniciar."); // Exibe mensagem da tela inicial 

			titleLogo->Desenha();
			break;

		case (WON): //// Quando obtém Vitória no jogo ////
			if ( GetTick() < m_Timer )
			{
				WorkSurface->TextXY((SCREEN_LIMX/2)-30,240,0, (LPCTSTR)L"PARABENS!!"); // Exibe a congratulação pelo intervalo deifinido em VICTORYDUR
				break;
			}
			m_Fase++;														// Aumenta a fase
			JumpDur -= 100.0;
			if (JumpDur <= 1000.0)											// Caso a duração do lançamento chegue a menos de 1 segundo, o jogo acaba
			{
				StartScreenSetUp();											// Reseta os valores da tela inicial
				m_GameState = STARTSCR;										// Muda o estado da máquina
				break;
			}
			DeleteScene();													// Deleta a cena atual
			CreateScene();													// Monta a cena da nova fase
			m_GameState = PLAYING;											// Muda o estado da máquina

		case (PLAYING): //// Quando na Tela do jogo ////

			bagList->Desenha(WorkSurface);												// Desenha a cena

			if (bagList->GetBagsLeft() == (throwableQuant[m_Fase] + bagQuant[m_Fase]))	// Se ainda não foi feito o lançamento, exibir a instrução
				WorkSurface->TextXY((SCREEN_LIMX/2)-90,420,0, (LPCTSTR)L"Pressione ESPAÇO para lançar.");

	} // Fim da Máquina de Estados

	ShowScore();									// Exibe a pontuação se necessário
	ShowStage();									// Exibe a fase atual se necessário

	cursor->Desenha();								// Exibe o cursor do mouse

	WorkSurface->DrawBlk(Screen->GetBack(),0,0);	// Envia a tela para o back buffer

	Screen->Flip();									// Troca os buffers

} /** Fim do método Run() **/



/**
*	Método:		InitEasyWindow()
*	Descrição:	Inicializa o jogo
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

	
	Sound.ContinuousPlay(TRUE);													// Habilita a reprodução contínua

	
	BGM = new CDXMidi;															// Carrega e inicia
	if (FAILED(	BGM->Init(hwndWin, &Sound)))									//   a reprodução de
		return RET_ERROR;														//   música de fundo
	BGM->LoadMidi(_T(".\\resources\\bgm.mid"));									//
	BGM->SetVolume(1024);														//
	BGM->Play(0);																//


	Audio = new CDXSoundBuffer;													// Carrega e inicia
	if (FAILED(Audio->Load(&Sound,_T(".\\resources\\kidsplay.wav"))))			//   a reprodução do
		return RET_ERROR;														//   som ambiente
	Audio->Play(DSBPLAY_LOOPING);												//


	GetSound = new CDXSoundBuffer;												// Carrega no buffer de
	if (FAILED(GetSound->Load(&Sound,_T(".\\resources\\bagget.wav"))))			//   áudio o som de um
		return RET_ERROR;														//   saquinho sendo pego


	FallSound = new CDXSoundBuffer;												// Carrega no buffer de
	if (FAILED(FallSound->Load(&Sound,_T(".\\resources\\bagfall.wav"))))			//   áudio o som de um
		return RET_ERROR;														//   saquinho caindo no chão


	m_Score = 0;																// Inicializa o placar
	m_Fase = 0;																	// Inicializa o contador de fase
	throwTime = 0.0;															// Inicializa para zero o cronômetro de jogo
	JumpDur = JUMPDURINI;														// Inicializa a duração do lançamento para o valor inicial definido dem JUMPDURINI
	LastMouseKeySt = 0;															// Atribui 'desclicado' ao último valor capturado do botão do mouse
	m_Timer = 0.0;																// Inicializa o timer das telas de jogo

	m_GameState = STARTSCR;														// Muda o estdo da máquina pada "Tela Inicial"

	titleLogo = NULL;															// Limpa os ponteiros
	bagList = NULL;																// Limpa os ponteiros

	StartScreenSetUp();															// Inicializa as variáveis para a Tela Inicial

	return RET_OK;
} /** Fim do método InitEasyWindow() **/



/**
*	Método:		EndEasyWindow()
*	Descrição:	Finaliza o jogo
 **/
int CDXTresMarias::EndEasyWindow()
{
	Audio->Stop();				// Interrompe a execução do som ambiente

	BGM->Stop(0);				// Interrompe a execução da música de fundo
	
	DeleteScene();				// Deleta qualquer cena que estiver na memória

	if ( titleLogo != NULL )	// Deleta o logotipo caso ele esteja na memória, e
		delete titleLogo;		//   limpa o endereço do ponteiro

	delete cursor;				// Deleta variáveis alocadas dinamicamente.
	delete WorkSurface;			//
	delete Picture;				//
	delete Screen;				//
	delete BGM;					//
	delete Audio;				//
	delete GetSound;			//
	delete FallSound;			//

	return RET_OK;
} /** Fim do método EndEasyWindow() **/



/**
*	Método:		ShowScore()
*	Descrição:	Exibe a pontuação do jogador na tela
 **/
void CDXTresMarias::ShowScore()
{
	if (m_GameState != STARTSCR)						// Se não estivermos na Tela inicial
	{
		TCHAR buffer[33];
		_itot_s(m_Score, buffer, 10);
		m_ScoreText = (LPCTSTR)buffer;
		WorkSurface->TextXY(555, 5, 0, (LPCTSTR)L"Pontuação");
		WorkSurface->TextXY(555, 20, 0, m_ScoreText);
	}
} /** Fim do método ShowScore() **/



/**
*	Método:		ShowStage()
*	Descrição:	Exibe a fase atual do jogo na tela
 **/
void CDXTresMarias::ShowStage()
{
	if (m_GameState != STARTSCR)						// Se não estivermos na Tela inicial
	{
		TCHAR buffer[33];
		_itot_s(m_Fase+1, buffer, 10);
		m_StageText = (LPCTSTR)buffer;
		WorkSurface->TextXY(15, 5, 0, (LPCTSTR)L"Fase");
		WorkSurface->TextXY(15, 20, 0, m_StageText);
	}
} /** Fim do método ShowStage() **/



/**
*	Método:		GameReset()
*	Descrição:	Reinicia todas as variáveis ao estado primário
 **/
void CDXTresMarias::GameReset()
{
	if (titleLogo != NULL)
	{
		delete titleLogo;					// Deleta a imagem do logotipo
		titleLogo = NULL;					// Deleta a referência de memória
	}

	m_Score = 0;							// Reinicia o placar
	m_Fase = 0;								// Reinicia o contador de fase

	DeleteScene();							// Deleta a cena atual
	CreateScene();							// Cria uma cena nova na fase atual (1)

	m_GameState = PLAYING;					// Muda o estado da Máquina para "Jogando"

} /** Fim do método GameReset() **/



/**
*	Método:		GameLost()
*	Descrição:	Perde o jogo e inicia o processo de Game Over
 **/
void CDXTresMarias::GameLost()
{
	m_Timer = GetTick() + GAMEOVERDUR;		// Atribui ao tempo de duração da tela o valor definido em GAMEOVERDUR
	bagList->Deactivate();					// Desativa os cliques em todos os saquinhos exibidos na tela
	JumpDur = JUMPDURINI;					// Reseta a duração do lançamento para o tempo inicial definido em JUMPDURINI
	m_GameState = LOST;						// Muda o estado da Máquina para "Perdeu"
} /** Fim do método GameLost() **/



/**
*	Método:		GameWin()
*	Descrição:	Vence o jogo e troca de fase
 **/
void CDXTresMarias::GameWin()
{
	m_Score += ((int)(((throwTime + JumpDur) - GetTick())/100) * (10*(m_Fase+1)));	// Calcula a pontuação ganha pelo tempo de lançamento restante na fase
	m_Timer = GetTick() + VICTORYDUR;												// Atribui ao tempo de duração da tela o valor definido em VICTORYDUR
	m_GameState = WON;																// Muda o estado da Máquina para "Ganhou"
} /** Fim do método GameWin() **/



/**
*	Método:		StartScreenSetUp()
*	Descrição:	Configura o jogo para a exibição da Tela Inicial
 **/
void CDXTresMarias::StartScreenSetUp()
{
	DeleteScene();																			// Deleta alguma cena existente

	titleLogo = new TMSprite(this,_T(".\\resources\\titlescr.bmp"), 640, 480, 0, 0, -450);	// Carrega a imagem da tela de abertura
	titleLogo->SetColorKey();																// Habilita a transparência

} /** Fim do método StartScreenSetUp() **/



/**
*	Método:		CreateScene()
*	Descrição:	Configura a tela e cria os saquinhos de acordo com a configuração da fase
 **/
void CDXTresMarias::CreateScene()
{
	bagList = new TMBagList( this );									// Cria uma nova lista dinâmica de saquinhos

	srand ( (unsigned)time(NULL));										// Inicializa o randomizador numérico

	for (int i = 0; i < throwableQuant[(m_Fase%NUMFASES)]; i++)			// Cria os saquinhos
	{																	//   atiráveis
		bagList->AddBag(configNewBag(bagList, true));					//
	}																	//

	for (int j = 0; j < bagQuant[(m_Fase%NUMFASES)]; j++)				// Cria o resto
	{																	//   dos saquinhos
		bagList->AddBag(configNewBag(bagList, false));					//   da fase
	}

} /** Fim do método CreateScene() **/



/**
*	Método:		DeleteScene()
*	Descrição:	Limpa a lista de saquinhos e prepara o jogo para uma próxima configuração
 **/
void CDXTresMarias::DeleteScene()
{
	if (bagList != NULL)					// Limpa a lista
	{										//   de saquinhos
		delete bagList;						//
		bagList = NULL;						//
	}										//
	
	isThrown = false;						// Reseta o estado de lançamento

} /** Fim do método CreateScene() **/



/**
*	Método:		configNewBag()
*	Descrição:	Configura um novo saquinho
 **/
TMBag* CDXTresMarias::configNewBag(TMBagList* bagList, bool isThrow = false)
{
	int tempx, tempy, tempLayer, tempLook;
	TCHAR filename[23];

	if (isThrow)																		// Se for um saquinho atirável,
	{																					//   as configurações são fixas
		tempLayer=0;																	// Layer frontal.
		tempy = 300;																	// Mesma altura na tela
		int i = 0;
		do																				// Configura a posição X
		{																				//   centralizada na tela
			i++;																		//   e de acordo com o
			tempx = (((SCREEN_LIMX / (throwableQuant[(m_Fase%NUMFASES)]+1)) * i) - 80);	//   número total de
																						//   saquinhos atiráveis
			if (tempx < 0)																//   da fase atual.
				tempx = 0;																//
			else if (tempx > SCREEN_LIMX - 160)											//
				tempx = (SCREEN_LIMX - 160);											//
																						//
		} while (bagList->IsBagInPos(tempx, tempy, tempLayer));							// Repete enquanto já houver saquinho na posição
	
	} else {													// Se for um saquinho comum

		do														// Configura a tela
		{														//   para exibir os
			tempx = ((rand()%4) * 160);							//   saquinhos em alturas
			tempLayer = (rand()%4)+1;							//   e posições diferentes
			tempy = (((4 - tempLayer) * 25) + 200);				//
		} while (bagList->IsBagInPos(tempx, tempy, tempLayer));	// Repete enquanto já houver saquinho na posição
	}

	tempLook = rand()%5;																		// Seleciona aleatoriamente a cor do saquinho
	int tmp = _stprintf_s(filename, sizeof(filename),_T(".\\resources\\bag%d.bmp"), tempLook);

	TMBag* tempBag = new TMBag(this, filename, 160, 120, 10, tempx, tempy, tempLayer, isThrow);	// Chama o construtor do saquinho com as configurações acertadas
	
	tempBag->SetColorKey();																		// Inicializa a transparência

	return (tempBag);																			// Retorna o ponteiro para o saquinho recém-criado
} /** Fim do método configNewBag() **/


/**
*	Método:		GetInput()
*	Descrição:	Recebe e processa a entrada do teclado
 **/
void CDXTresMarias::GetInput()
{
	Input.Update();														// Atualiza as informações do objeto CDXInput

	long x = 0, y = 0;

	Input.GetMouseDeltas(&x, &y);										// Pega o deslocamento do mouse desde o último frame

	cursor->Move(x,y);													// Move o cursor

	if (Input.GetKeyState(CDXKEY_ENTER) && m_GameState == STARTSCR)		// Se estivermos na Tela Inicial e for pressionado ENTER,
		GameReset();													//   o jogo se inicia

	if (Input.GetKeyState(CDXKEY_MOUSELEFT) && m_GameState == PLAYING)	// Se estivermos na tela de Jogo,
	{																	//    e for pressionado o BOTÃO ESQUERDO do mouse,
		if (!LastMouseKeySt)											//    checa se o botão estava pressionado no frame
			bagList->Click(cursor);										//    anterior, e caso não esteja, emite o click para
		LastMouseKeySt = 1;												//    a tela de jogo.
	} else {															// Guarda o último estado do botão esquerdo do mouse
		LastMouseKeySt = 0;												//    para comparar com o próximo frame
	}																	//

	if (Input.GetKeyState(CDXKEY_SPACE) && m_GameState == PLAYING)		// Se estivermos na tela de Jogo e for pressionado ESPAÇO.
		if (!isThrown)													//    caso ainda não tenha havido lançamento,
		{																//    os saquinhos lançáveis são atirados e os demais
			throwTime = GetTick();										//    habilitados para clique. A hora do lançamento é
			bagList->Throw();											//    guardada para contagem posterior de pontos
			isThrown = true;											//
		}																//
} /** Fim do método GetInput() **/



/**
*	Método:		GetLowResTime()
*	Descrição:	Pega resultado de timers de baixa precisão
 **/
double CDXTresMarias::GetLowResTime()
{
	return (double) timeGetTime();
} /** Fim do método GetLowResTime() **/



/**
*	Método:		GetHiResTime()
*	Descrição:	Pega resultado de timers de alta precisão
 **/
double CDXTresMarias::GetHiResTime()
{
	LARGE_INTEGER freq, perf;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&perf);

	return (double)perf.QuadPart / (double)freq.QuadPart * 1000;
} /** Fim do método GetHiResTime() **/



/**
*	Método:		WinMain()
*	Descrição:	Procedure WinMain
 **/
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hInstAnt, LPSTR lpszCmd, int iCmd)
{
   CDXTresMarias jogo;

   jogo.SetUp((LPCTSTR)L"TresMarias", hInst, 0, 0, 640, 480);

   jogo.Start((LPCTSTR)L"Três Marias");

   return(RET_OK);
} /** Fim do método WinMain() **/