#define CDXINCLUDEALL
#include <cdx.h>

#include "CDXtresmarias.h"
#include "TMSprite.h"

////******************************************************************////
//*							Classe TMSprite							   *//
////******************************************************************////

/**
*	M�todo:		TMSprite()
*	Descri��o:	Construtor da classe TMSprite
 **/
TMSprite::TMSprite(CDXTresMarias *Jogo, const TCHAR *file, long width, long height, long frames, long x, long y) : CDXSprite()
{
	Create(Jogo->getScreen(), file, width, height, frames, CDXMEM_SYSTEMONLY);	// Cria o sprite a partir dos par�metros passados
	SetPos(x, y);																// Coloca o sprite na posi��o passada
	SetColorKey(0);																// Habilita a transpar�ncia em preto

	this->limitex = SCREEN_LIMX - width;										// Calcula o limite das dimens�es da tela
	this->limitey = SCREEN_LIMY - height;										//   em fun��o do tamanho da imagem e da tela

	this->Jogo = Jogo;															// Inicializa vari�veis
	this->m_PosZ = 0;															//   locais
	this->m_Next = NULL;														//
	this->m_Prev = NULL;														//

} /** Fim do m�todo TMSprite() **/



/**
*	M�todo:		~TMSprite()
*	Descri��o:	Destrutor da classe TMSprite
 **/
TMSprite::~TMSprite()
{
	Jogo = NULL;
} /** Fim do m�todo ~TMSprite() **/



/**
*	M�todo:		Desenha()
*	Descri��o:	Desenha o sprite na tela
 **/
bool TMSprite::Desenha()
{
	Draw(Jogo->getSurface(), 0, 0, CDXBLT_TRANS);
	return true;
} /** Fim do m�todo Desenha() **/



/**
*	M�todo:		Move()
*	Descri��o:	Movimenta o sprite pela tela
 **/
void TMSprite::Move(long x, long y)
{
	this->m_PosX += x;
	this->m_PosY += y;
} /** Fim do m�todo Move() **/



/**
*	M�todo:		Click()
*	Descri��o:	Processa um clique sobre o sprite
 **/
void TMSprite::Click()
{
} /** Fim do m�todo Click() **/




////******************************************************************////
//*							Classe TMCursor							   *//
////******************************************************************////



/**
*	M�todo:		TMCursor()
*	Descri��o:	Construtor da classe TMCursor
 **/
TMCursor::TMCursor(CDXTresMarias *Jogo, const TCHAR *file, long width, long height, long frames, long x, long y)
		 : TMSprite(Jogo, file, width, height, frames, x, y)
{
	m_bClick = false;				// inicializa a vari�vel de estado de clique
} /** Fim do m�todo TMCursor() **/



/**
*	M�todo:		Move()
*	Descri��o:	Movimenta o cursor
 **/
void TMCursor::Move(long x, long y)
{
	SetPosX(GetPosX() + x);						// Atualiza x de acordo
	if (GetPosX() < 0) SetPosX(0);				//   com o deslocamento
	if (GetPosX() > limitex) SetPosX(limitex);	//   passado nos par�metros

	SetPosY(GetPosY() + y);						// Atualiza y de acordo
	if (GetPosY() < 0) SetPosY(0);				//   com o deslocamento
	if (GetPosY() > limitey) SetPosY(limitey);	//   passado nos par�metros

} /** Fim do m�todo Move() **/



/**
*	M�todo:		Desenha()
*	Descri��o:	Exibe o cursor na tela
 **/
bool TMCursor::Desenha()
{
	if (Jogo->m_GameState == STARTSCR)				// N�o exibe o cursor se
		return false;								//   estivermos na Tela Inicial

	Draw(Jogo->getSurface(), 0, 0, CDXBLT_TRANS);	// Desenha o cursor

	return true;

} /** Fim do m�todo Desenha() **/





////******************************************************************////
//*							Classe TMBag							   *//
////******************************************************************////


/**
*	M�todo:		TMBag()
*	Descri��o:	Construtor da classe TMCursor
 **/
TMBag::TMBag(CDXTresMarias *Jogo, const TCHAR *file, long width, long height, long frames, long x, long y, 
			 long layer, bool throwable = false) 
	  : TMSprite(Jogo, file, width, height, frames, x, y)
{
	this->m_PosZ = layer;					// Recebe a posi��o Z do saquinho, usada para definir a ordem de exibi��o
	this->m_bClickable = false;				// Inicializa com o clique desabilitado por padr�o

	if (throwable)							// Inicializa o estado do saquinho
		this->m_State = THROWABLE;			//   de acordo com a op��o
	else									//   passada nos par�metros
		this->m_State = STOPPED;			//   (atir�vel ou n�o)

	this->ThrowTime = 0.0;					// Inicializa as vari�veis internas
	this->ThisTime = 0.0;					//   de controle da movimenta��o
	this->m_dVelY = 0.0;					//   usados no algoritmo do lan�amento

	this->m_Next = NULL;					// Inicializa as vari�veis
	this->m_Prev = NULL;					//   din�micas

} /** Fim do m�todo Desenha() **/



/**
*	M�todo:		Throw()
*	Descri��o:	Inicia o lan�amento do saquinho
 **/
bool TMBag::Throw()
{
	if (m_State == THROWABLE)									// Checa se o saquinho � atir�vel
	{
		m_State = THROWN;										// Muda o estado do saquinho para 'lan�ado'
		ThisTime = ThrowTime = Jogo->GetTick();					// Armazena o momento do lan�amento para calcular o movimento do saquinho
		m_dPosY = (double) m_PosY;								// Captura a posi��o Y em uma vari�vel double para usar no c�lculo de movimento
		m_PosYOrig = m_PosY;									// Armazena a posi��o Y inicial do saquinho, para saber quando ele atingiu o ch�o
		m_dVelY = (2 * JUMPHEIGHT) / (Jogo->GetJumpDur()/2);	// Calcula a velocidade inicial do lan�amento ( Velocidade inicial deve ser 2x a velocidade m�dia para cobrir o trajeto: dV = dS / dT )
		m_dAccel = (-m_dVelY) / (Jogo->GetJumpDur()/2);			// Calcula a acelera��o da gravidade em rela��o ao tempo que o lan�amento deve durar ( dV = -A / dT )
		return true;
	}
	return false;
} /** Fim do m�todo Throw() **/



/**
*	M�todo:		Click()
*	Descri��o:	Processa um clique sobre o saquinho
 **/
void TMBag::Click()
{
	if (m_bClickable)									// Testa se o saquinho est� 'clic�vel'
	{
		Jogo->PlayGet();								// Toca o som de saquinho sendo pego
		Jogo->m_Score += ((Jogo->GetFase() + 1) * 10);	// Aumenta a pontua��o de um saquinho no placar
		m_State = FETCHED;								// Modifica o estado do saquinho para 'apanhado'. 
	}
} /** Fim do m�todo Click() **/



/**
*	M�todo:		Move()
*	Descri��o:	Movimenta o saquinho ao longo do lan�amento
 **/
void TMBag::Move()
{
	if (m_State != THROWN)				// Ignora chamadas feitas por saquinhos
		return;							//    que n�o estejam lan�ados

	double Now = Jogo->GetTick();										// Captura o tempo agora
	double dTime = (Now - ThisTime) ;									// Calcula o tempo decorrido desde o �ltimo frame

	double dY = ( (m_dVelY * dTime) + ((m_dAccel*dTime*dTime)/2) );		// Calcula o deslocamento pela f�rmula de MUV ( dS = V0 dT + A * dT�/2 )
	m_dPosY -= dY;														// Atualiza a vari�vel de posi��o Y precisa (double) com o deslocamento
	m_dVelY += m_dAccel * dTime;										// Atualiza a vari�vel de velocidade de acordo com a acelera��o
	ThisTime = Now ;													// Guarda o tempo do frame atual para usar no pr�ximo frame

	m_PosY = (int) m_dPosY;												// Arredonda a posi��o Y precisa (double) e joga na vari�vel de posi��o Y inteira (int)

	if ( ThisTime >= (ThrowTime + ((m_Frame+1) * (Jogo->GetJumpDur() / 10))) )	// Calcula se � necess�ria uma
		m_Frame = (m_Frame + 1) % CountFrames();								//    troca de frame da anima��o

	if (( ThisTime >= (ThrowTime + Jogo->GetJumpDur()) ) || 
		( m_PosY >= m_PosYOrig ))								// Calcula se o saquinho j� atingiu o ch�o novamente
	{
		Jogo->PlayFall();										// Toca o som de saquinho caindo
		m_PosY = m_PosYOrig;									// Ajusta a posi��o Y para a original, para corrigir o erro
		m_Frame = 0;											// Modifica o frame do sprite para o inicial novamente
		m_State = STOPPED;										// Muda o estado do saquinho para 'parado'
		Jogo->GameLost();										// Envia para o jogo uma mensagem de Game Over
	}
} /** Fim do m�todo Move() **/



/**
*	M�todo:		Desenha()
*	Descri��o:	Desenha o saquinho na tela
 **/
bool TMBag::Desenha()
{
	switch (m_State)
	{
		case (FETCHED):			// Se o saquinho tiver sido apanhado,
			return false;		//   n�o desenha e retorna falso

		case (THROWN):			// Se o saquinho estiver em lan�amento,
			Move();				//   atualiza a posi��o antes de desenhar

		default:
			Draw(Jogo->getSurface(), 0, 0, CDXBLT_TRANS);  // Desenha o saquinho na tela
	}
	return true;
} /** Fim do m�todo Desenha() **/




////******************************************************************////
//*							Classe TMSpriteList						   *//
////******************************************************************////


/**
*	M�todo:		Click()
*	Descri��o:	Checa qual sprite o clique atingiu e emite o sinal de clique
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
} /** Fim do m�todo Click() **/



/**
*	M�todo:		Desenha()
*	Descri��o:	Desenha todos os sprites da lista
 **/
void TMSpriteList::Desenha(CDXSurface* lpTMB)
{
	TMSprite* Node;

	for (Node = m_spriteList.GetFirst(); Node != NULL ; Node = Node->GetNext() )
	{
		Node->Desenha();
	}
} /** Fim do m�todo Desenha() **/




////*****************************************************************////
//*							Classe TMBagList						  *//
////*****************************************************************////



/**
*	M�todo:		Click()
*	Descri��o:	Checa qual sprite o clique atingiu e emite o sinal de clique
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
} /** Fim do m�todo Click() **/


/**
*	M�todo:		TMBagList()
*	Descri��o:	Construtor da classe TMBagList
 **/
TMBagList::TMBagList(CDXTresMarias* Jogo) : TMSpriteList()
{
	BagCount = 0;									// Inicializa a contagem de saquinhos apanhados
	this->Jogo = Jogo;								// Inicializa a refer�ncia ao jogo
	this->ClickableBagTot = Jogo->GetBagCount();	// Armazena o total de saquinhos n�o-lan��veis na fase atual
	this->ClickableBagCount = 0;					// Inicializa a contagem de saquinhos n�o-lan��veis

} /** Fim do m�todo TMBagList() **/



/**
*	M�todo:		Desenha()
*	Descri��o:	Desenha os saquinhos, deleta os que n�o puderem ser desenhados
 **/
void TMBagList::Desenha(CDXSurface* lpTMB)
{
	TMBag* Node;								// Ponteiro para varrer a lista

	Node = m_spriteList.GetFirst();				// Aponta o primeiro saquinho da lista

	while (Node != NULL)						// Enquanto n�o for um ponteiro nulo
	{
		if ( !Node->Desenha() )						// Se o comando para desenhar retornar false,
		{											//   o saquinho foi apanhado (FETCHED),
			Node = Remove( Node );					//   portanto � deletado da lista
			BagCount--;								// Diminui a contagem total de saquinhos na cena
			ClickableBagCount++;					// Aumenta a contagem de saquinhos apanhados
		}

		if (Node == NULL)							// Se o saquinho deletado for o primeiro da lista,
			Node = m_spriteList.GetFirst();			//   pega o novo primeiro da lista,
		else										//   sen�o,
			Node = Node->GetNext();					//   joga o ponteiro para o pr�ximo da fila
	}

	if (ClickableBagCount == ClickableBagTot)	// Se j� foram apanhados todos os saquinhos n�o-lan��veis da cena,
		Activate(THROWN);						//   ativa os saquinhos que est�o no ar

	else if (BagCount == 0)						// Se j� foram apanhados todos os saquinhos da cena,
		Jogo->GameWin();						//   envia mensagem de vit�ria para o jogo

} /** Fim do m�todo Desenha() **/



/**
*	M�todo:		AddBag()
*	Descri��o:	Adiciona um saquinho � cena, ordenando a lista pela camada de profundidade
 **/
void TMBagList::AddBag( TMBag* pBag )
{
	TMBag* Node;		// Ponteiro para vasculhar a lista
	DWORD pos = 0;		// Posi��o em que o saquinho ser� inserido

	for (Node = m_spriteList.GetFirst(); Node != NULL ; Node = Node->GetNext() )
	{
		if (pBag->GetPosZ() > Node->GetPosZ())			// Se a profundidade � maior que a do saquinho atual,
			break;										//   sai do la�o com a posi��o do atual

		pos++;											// Incremento da posi��o
	}

	m_spriteList.Insert( pBag, pos );				// Insere o saquinho na posi��o

	BagCount++;										// Incrementa a contagem de saquinhos na cena

} /** Fim do m�todo AddBag() **/



/**
*	M�todo:		IsBagInPos()
*	Descri��o:	Verifica se j� existe um saquinho posicionado nas coordenadas fornecidas
 **/
bool TMBagList::IsBagInPos(long x, long y, long z)
{
	TMBag* Node;		// Ponteiro para varrer a lista

	for (Node = m_spriteList.GetFirst(); Node != NULL ; Node = Node->GetNext() )
	{
		if ( Node->IsZ(z) && Node->IsX(x) && Node->IsY(y) )		// Se for encontrado um saquinho nas coordenadas,
			return true;										//   retorna verdadeiro
	}
	return false;												// Se n�o, retorna falso

} /** Fim do m�todo IsBagInPos() **/



/**
*	M�todo:		Activate()
*	Descri��o:	Ativa os saquinhos que estejam no estado 'wich'
 **/
void TMBagList::Activate( int wich )
{
	TMBag* Node;		// Ponteiro para varrer a lista

	for (Node = m_spriteList.GetFirst(); Node != NULL ; Node = Node->GetNext() )
	{
		if (Node->GetState() == wich)		// Se o estado do saquinho for o que procuramos,
			Node->Activate();				//   ativa o saquinho para ser apanhado
	}
} /** Fim do m�todo Activate() **/



/**
*	M�todo:		Deactivate()
*	Descri��o:	Ativa os saquinhos que estejam no estado 'wich'
 **/
void TMBagList::Deactivate()
{
	TMBag* Node;		// Ponteiro para varrer a lista

	for (Node = m_spriteList.GetFirst(); Node != NULL ; Node = Node->GetNext() )
		Node->Deactivate();			// Desativa os saquinhos

} /** Fim do m�todo Deactivate() **/



/**
*	M�todo:		Throw()
*	Descri��o:	Propaga a mensagem de lan�amento para os saquinhos da lista, ativando os que n�o forem lan��veis
 **/
void TMBagList::Throw()
{
	TMBag* Node;		// Ponteiro para varrer a lista

	for (Node = m_spriteList.GetFirst(); Node != NULL ; Node = Node->GetNext() )
		if (!Node->Throw())			// Se o saquinho n�o aceitar o comando de lan�amento,
			Node->Activate();		//   ativa-o para ser clicado

} /** Fim do m�todo Throw() **/