#define CDXINCLUDEALL
#include <cdx.h>

#include "CDXtresmarias.h"
#include "TMSprite.h"

////******************************************************************////
//*							Classe TMSprite							   *//
////******************************************************************////

/**
*	Método:		TMSprite()
*	Descrição:	Construtor da classe TMSprite
 **/
TMSprite::TMSprite(CDXTresMarias *Jogo, const TCHAR *file, long width, long height, long frames, long x, long y) : CDXSprite()
{
	Create(Jogo->getScreen(), file, width, height, frames, CDXMEM_SYSTEMONLY);	// Cria o sprite a partir dos parâmetros passados
	SetPos(x, y);																// Coloca o sprite na posição passada
	SetColorKey(0);																// Habilita a transparência em preto

	this->limitex = SCREEN_LIMX - width;										// Calcula o limite das dimensões da tela
	this->limitey = SCREEN_LIMY - height;										//   em função do tamanho da imagem e da tela

	this->Jogo = Jogo;															// Inicializa variáveis
	this->m_PosZ = 0;															//   locais
	this->m_Next = NULL;														//
	this->m_Prev = NULL;														//

} /** Fim do método TMSprite() **/



/**
*	Método:		~TMSprite()
*	Descrição:	Destrutor da classe TMSprite
 **/
TMSprite::~TMSprite()
{
	Jogo = NULL;
} /** Fim do método ~TMSprite() **/



/**
*	Método:		Desenha()
*	Descrição:	Desenha o sprite na tela
 **/
bool TMSprite::Desenha()
{
	Draw(Jogo->getSurface(), 0, 0, CDXBLT_TRANS);
	return true;
} /** Fim do método Desenha() **/



/**
*	Método:		Move()
*	Descrição:	Movimenta o sprite pela tela
 **/
void TMSprite::Move(long x, long y)
{
	this->m_PosX += x;
	this->m_PosY += y;
} /** Fim do método Move() **/



/**
*	Método:		Click()
*	Descrição:	Processa um clique sobre o sprite
 **/
void TMSprite::Click()
{
} /** Fim do método Click() **/




////******************************************************************////
//*							Classe TMCursor							   *//
////******************************************************************////



/**
*	Método:		TMCursor()
*	Descrição:	Construtor da classe TMCursor
 **/
TMCursor::TMCursor(CDXTresMarias *Jogo, const TCHAR *file, long width, long height, long frames, long x, long y)
		 : TMSprite(Jogo, file, width, height, frames, x, y)
{
	m_bClick = false;				// inicializa a variável de estado de clique
} /** Fim do método TMCursor() **/



/**
*	Método:		Move()
*	Descrição:	Movimenta o cursor
 **/
void TMCursor::Move(long x, long y)
{
	SetPosX(GetPosX() + x);						// Atualiza x de acordo
	if (GetPosX() < 0) SetPosX(0);				//   com o deslocamento
	if (GetPosX() > limitex) SetPosX(limitex);	//   passado nos parâmetros

	SetPosY(GetPosY() + y);						// Atualiza y de acordo
	if (GetPosY() < 0) SetPosY(0);				//   com o deslocamento
	if (GetPosY() > limitey) SetPosY(limitey);	//   passado nos parâmetros

} /** Fim do método Move() **/



/**
*	Método:		Desenha()
*	Descrição:	Exibe o cursor na tela
 **/
bool TMCursor::Desenha()
{
	if (Jogo->m_GameState == STARTSCR)				// Não exibe o cursor se
		return false;								//   estivermos na Tela Inicial

	Draw(Jogo->getSurface(), 0, 0, CDXBLT_TRANS);	// Desenha o cursor

	return true;

} /** Fim do método Desenha() **/





////******************************************************************////
//*							Classe TMBag							   *//
////******************************************************************////


/**
*	Método:		TMBag()
*	Descrição:	Construtor da classe TMCursor
 **/
TMBag::TMBag(CDXTresMarias *Jogo, const TCHAR *file, long width, long height, long frames, long x, long y, 
			 long layer, bool throwable = false) 
	  : TMSprite(Jogo, file, width, height, frames, x, y)
{
	this->m_PosZ = layer;					// Recebe a posição Z do saquinho, usada para definir a ordem de exibição
	this->m_bClickable = false;				// Inicializa com o clique desabilitado por padrão

	if (throwable)							// Inicializa o estado do saquinho
		this->m_State = THROWABLE;			//   de acordo com a opção
	else									//   passada nos parâmetros
		this->m_State = STOPPED;			//   (atirável ou não)

	this->ThrowTime = 0.0;					// Inicializa as variáveis internas
	this->ThisTime = 0.0;					//   de controle da movimentação
	this->m_dVelY = 0.0;					//   usados no algoritmo do lançamento

	this->m_Next = NULL;					// Inicializa as variáveis
	this->m_Prev = NULL;					//   dinâmicas

} /** Fim do método Desenha() **/



/**
*	Método:		Throw()
*	Descrição:	Inicia o lançamento do saquinho
 **/
bool TMBag::Throw()
{
	if (m_State == THROWABLE)									// Checa se o saquinho é atirável
	{
		m_State = THROWN;										// Muda o estado do saquinho para 'lançado'
		ThisTime = ThrowTime = Jogo->GetTick();					// Armazena o momento do lançamento para calcular o movimento do saquinho
		m_dPosY = (double) m_PosY;								// Captura a posição Y em uma variável double para usar no cálculo de movimento
		m_PosYOrig = m_PosY;									// Armazena a posição Y inicial do saquinho, para saber quando ele atingiu o chão
		m_dVelY = (2 * JUMPHEIGHT) / (Jogo->GetJumpDur()/2);	// Calcula a velocidade inicial do lançamento ( Velocidade inicial deve ser 2x a velocidade média para cobrir o trajeto: dV = dS / dT )
		m_dAccel = (-m_dVelY) / (Jogo->GetJumpDur()/2);			// Calcula a aceleração da gravidade em relação ao tempo que o lançamento deve durar ( dV = -A / dT )
		return true;
	}
	return false;
} /** Fim do método Throw() **/



/**
*	Método:		Click()
*	Descrição:	Processa um clique sobre o saquinho
 **/
void TMBag::Click()
{
	if (m_bClickable)									// Testa se o saquinho está 'clicável'
	{
		Jogo->PlayGet();								// Toca o som de saquinho sendo pego
		Jogo->m_Score += ((Jogo->GetFase() + 1) * 10);	// Aumenta a pontuação de um saquinho no placar
		m_State = FETCHED;								// Modifica o estado do saquinho para 'apanhado'. 
	}
} /** Fim do método Click() **/



/**
*	Método:		Move()
*	Descrição:	Movimenta o saquinho ao longo do lançamento
 **/
void TMBag::Move()
{
	if (m_State != THROWN)				// Ignora chamadas feitas por saquinhos
		return;							//    que não estejam lançados

	double Now = Jogo->GetTick();										// Captura o tempo agora
	double dTime = (Now - ThisTime) ;									// Calcula o tempo decorrido desde o último frame

	double dY = ( (m_dVelY * dTime) + ((m_dAccel*dTime*dTime)/2) );		// Calcula o deslocamento pela fórmula de MUV ( dS = V0 dT + A * dT²/2 )
	m_dPosY -= dY;														// Atualiza a variável de posição Y precisa (double) com o deslocamento
	m_dVelY += m_dAccel * dTime;										// Atualiza a variável de velocidade de acordo com a aceleração
	ThisTime = Now ;													// Guarda o tempo do frame atual para usar no próximo frame

	m_PosY = (int) m_dPosY;												// Arredonda a posição Y precisa (double) e joga na variável de posição Y inteira (int)

	if ( ThisTime >= (ThrowTime + ((m_Frame+1) * (Jogo->GetJumpDur() / 10))) )	// Calcula se é necessária uma
		m_Frame = (m_Frame + 1) % CountFrames();								//    troca de frame da animação

	if (( ThisTime >= (ThrowTime + Jogo->GetJumpDur()) ) || 
		( m_PosY >= m_PosYOrig ))								// Calcula se o saquinho já atingiu o chão novamente
	{
		Jogo->PlayFall();										// Toca o som de saquinho caindo
		m_PosY = m_PosYOrig;									// Ajusta a posição Y para a original, para corrigir o erro
		m_Frame = 0;											// Modifica o frame do sprite para o inicial novamente
		m_State = STOPPED;										// Muda o estado do saquinho para 'parado'
		Jogo->GameLost();										// Envia para o jogo uma mensagem de Game Over
	}
} /** Fim do método Move() **/



/**
*	Método:		Desenha()
*	Descrição:	Desenha o saquinho na tela
 **/
bool TMBag::Desenha()
{
	switch (m_State)
	{
		case (FETCHED):			// Se o saquinho tiver sido apanhado,
			return false;		//   não desenha e retorna falso

		case (THROWN):			// Se o saquinho estiver em lançamento,
			Move();				//   atualiza a posição antes de desenhar

		default:
			Draw(Jogo->getSurface(), 0, 0, CDXBLT_TRANS);  // Desenha o saquinho na tela
	}
	return true;
} /** Fim do método Desenha() **/




////******************************************************************////
//*							Classe TMSpriteList						   *//
////******************************************************************////


/**
*	Método:		Click()
*	Descrição:	Checa qual sprite o clique atingiu e emite o sinal de clique
 **/
void TMSpriteList::Click(TMCursor* cursor)
{
	TMSprite* Node;

	for (Node = m_spriteList.GetLast(); Node != NULL ; Node = Node->GetPrev() )
	{
		if (Node->SpriteHitPixel(cursor) == TRUE)
		{
			Node->Click();
			break;
		}
	}
} /** Fim do método Click() **/



/**
*	Método:		Desenha()
*	Descrição:	Desenha todos os sprites da lista
 **/
void TMSpriteList::Desenha(CDXSurface* lpTMB)
{
	TMSprite* Node;

	for (Node = m_spriteList.GetFirst(); Node != NULL ; Node = Node->GetNext() )
	{
		Node->Desenha();
	}
} /** Fim do método Desenha() **/




////*****************************************************************////
//*							Classe TMBagList						  *//
////*****************************************************************////



/**
*	Método:		Click()
*	Descrição:	Checa qual sprite o clique atingiu e emite o sinal de clique
 **/
void TMBagList::Click(TMCursor* cursor)
{
	TMBag* Node;

	for (Node = m_spriteList.GetLast(); Node != NULL ; Node = Node->GetPrev() )
	{
		if (Node->SpriteHitPixel(cursor) == TRUE)
		{
			Node->Click();
			break;
		}
	}
} /** Fim do método Click() **/


/**
*	Método:		TMBagList()
*	Descrição:	Construtor da classe TMBagList
 **/
TMBagList::TMBagList(CDXTresMarias* Jogo) : TMSpriteList()
{
	BagCount = 0;									// Inicializa a contagem de saquinhos apanhados
	this->Jogo = Jogo;								// Inicializa a referência ao jogo
	this->ClickableBagTot = Jogo->GetBagCount();	// Armazena o total de saquinhos não-lançáveis na fase atual
	this->ClickableBagCount = 0;					// Inicializa a contagem de saquinhos não-lançáveis

} /** Fim do método TMBagList() **/



/**
*	Método:		Desenha()
*	Descrição:	Desenha os saquinhos, deleta os que não puderem ser desenhados
 **/
void TMBagList::Desenha(CDXSurface* lpTMB)
{
	TMBag* Node;								// Ponteiro para varrer a lista

	Node = m_spriteList.GetFirst();				// Aponta o primeiro saquinho da lista

	while (Node != NULL)						// Enquanto não for um ponteiro nulo
	{
		if ( !Node->Desenha() )						// Se o comando para desenhar retornar false,
		{											//   o saquinho foi apanhado (FETCHED),
			Node = Remove( Node );					//   portanto é deletado da lista
			BagCount--;								// Diminui a contagem total de saquinhos na cena
			ClickableBagCount++;					// Aumenta a contagem de saquinhos apanhados
		}

		if (Node == NULL)							// Se o saquinho deletado for o primeiro da lista,
			Node = m_spriteList.GetFirst();			//   pega o novo primeiro da lista,
		else										//   senão,
			Node = Node->GetNext();					//   joga o ponteiro para o próximo da fila
	}

	if (ClickableBagCount == ClickableBagTot)	// Se já foram apanhados todos os saquinhos não-lançáveis da cena,
		Activate(THROWN);						//   ativa os saquinhos que estão no ar

	else if (BagCount == 0)						// Se já foram apanhados todos os saquinhos da cena,
		Jogo->GameWin();						//   envia mensagem de vitória para o jogo

} /** Fim do método Desenha() **/



/**
*	Método:		AddBag()
*	Descrição:	Adiciona um saquinho à cena, ordenando a lista pela camada de profundidade
 **/
void TMBagList::AddBag( TMBag* pBag )
{
	TMBag* Node;		// Ponteiro para vasculhar a lista
	DWORD pos = 0;		// Posição em que o saquinho será inserido

	for (Node = m_spriteList.GetFirst(); Node != NULL ; Node = Node->GetNext() )
	{
		if (pBag->GetPosZ() > Node->GetPosZ())			// Se a profundidade é maior que a do saquinho atual,
			break;										//   sai do laço com a posição do atual

		pos++;											// Incremento da posição
	}

	m_spriteList.Insert( pBag, pos );				// Insere o saquinho na posição

	BagCount++;										// Incrementa a contagem de saquinhos na cena

} /** Fim do método AddBag() **/



/**
*	Método:		IsBagInPos()
*	Descrição:	Verifica se já existe um saquinho posicionado nas coordenadas fornecidas
 **/
bool TMBagList::IsBagInPos(long x, long y, long z)
{
	TMBag* Node;		// Ponteiro para varrer a lista

	for (Node = m_spriteList.GetFirst(); Node != NULL ; Node = Node->GetNext() )
	{
		if ( Node->IsZ(z) && Node->IsX(x) && Node->IsY(y) )		// Se for encontrado um saquinho nas coordenadas,
			return true;										//   retorna verdadeiro
	}
	return false;												// Se não, retorna falso

} /** Fim do método IsBagInPos() **/



/**
*	Método:		Activate()
*	Descrição:	Ativa os saquinhos que estejam no estado 'wich'
 **/
void TMBagList::Activate( int wich )
{
	TMBag* Node;		// Ponteiro para varrer a lista

	for (Node = m_spriteList.GetFirst(); Node != NULL ; Node = Node->GetNext() )
	{
		if (Node->GetState() == wich)		// Se o estado do saquinho for o que procuramos,
			Node->Activate();				//   ativa o saquinho para ser apanhado
	}
} /** Fim do método Activate() **/



/**
*	Método:		Deactivate()
*	Descrição:	Ativa os saquinhos que estejam no estado 'wich'
 **/
void TMBagList::Deactivate()
{
	TMBag* Node;		// Ponteiro para varrer a lista

	for (Node = m_spriteList.GetFirst(); Node != NULL ; Node = Node->GetNext() )
		Node->Deactivate();			// Desativa os saquinhos

} /** Fim do método Deactivate() **/



/**
*	Método:		Throw()
*	Descrição:	Propaga a mensagem de lançamento para os saquinhos da lista, ativando os que não forem lançáveis
 **/
void TMBagList::Throw()
{
	TMBag* Node;		// Ponteiro para varrer a lista

	for (Node = m_spriteList.GetFirst(); Node != NULL ; Node = Node->GetNext() )
		if (!Node->Throw())			// Se o saquinho não aceitar o comando de lançamento,
			Node->Activate();		//   ativa-o para ser clicado

} /** Fim do método Throw() **/