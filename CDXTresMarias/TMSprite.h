/**
*	TMSprite
*	Autor:	Rafael Pagani Savastano
*	Versão:	1.0
*	Ult. Atualização:	28-Jul-2004
 **/

#ifndef __TMSPRITE_H__
#define __TMSPRITE_H__

#define CDXINCLUDEALL
#include <cdx.h>
#include <math.h>

// Estados do saquinho de areia
#define STOPPED 0
#define THROWABLE 1
#define THROWN 2
#define FETCHED 3


class CDXTresMarias;


class TMSprite : public CDXSprite
{
	protected:
		long limitex, limitey;
		CDXTresMarias *Jogo;
		TMSprite* m_Next;
		TMSprite* m_Prev;

	public:
		TMSprite(CDXTresMarias *Jogo, const TCHAR *file, long width, long height, long frames, long x, long y);
		~TMSprite();

		void SetNext(TMSprite* lpCDXS) { m_Next = lpCDXS; }
	    void SetPrev(TMSprite* lpCDXS) { m_Prev = lpCDXS; }
	    TMSprite* GetNext(void) { return m_Next; }
	    TMSprite* GetPrev(void) { return m_Prev; }

		long GetPosZ() { return m_PosZ; }
		bool IsX(long x) { return((m_PosX == x) ? true : false); }
		bool IsY(long y) { return((m_PosY == y) ? true : false); }
		bool IsZ(long z) { return((m_PosZ == z) ? true : false); }

		virtual void Move(long x, long y);
		virtual bool Desenha( void );
		virtual void Click();

};

class TMCursor : public TMSprite
{
	private:
		bool m_bClick;

	public:
		TMCursor(CDXTresMarias *Jogo, const TCHAR *file, long width, long height, long frames, long x, long y);

		bool IsClicking() { return m_bClick; }
		void SetClick(bool state) { m_bClick = state; }

		void Move(long x, long y);
		bool Desenha( void );
};

class TMBag : public TMSprite
{
	private:
		bool m_bClickable;
		int m_iLayer;
		int m_PosYOrig;
		double ThrowTime;
		double ThisTime;
		double m_dAccel;
		double m_dPosY;
		double m_dVelY;

		TMBag* m_Next;
		TMBag* m_Prev;

		void Move();

	public:
		TMBag (CDXTresMarias *Jogo, const TCHAR *file, long width, long height, long frames, long x, long y, 
			   long layer, bool throwable);

		bool Throw();
		bool IsClickable() { return m_bClickable; }

		void Activate() { m_bClickable = true; }
		void Deactivate() { m_bClickable = false; }

		void SetNext(TMBag* lpCDXS) { m_Next = lpCDXS; }
	    void SetPrev(TMBag* lpCDXS) { m_Prev = lpCDXS; }
	    TMBag* GetNext(void) { return m_Next; }
	    TMBag* GetPrev(void) { return m_Prev; }

		bool Desenha( void );
		void Click();

};

class TMSpriteList : public CDXSpriteList
{
	public:
		TMSpriteList() : CDXSpriteList() {}

		TMSprite* GetFirst(void) { return m_spriteList.GetFirst(); }
	    TMSprite* GetNext(TMSprite* pSprite) { return m_spriteList.Next(pSprite); }

		virtual void Click(TMCursor* cursor);
		virtual void Desenha(CDXSurface* lpTMB);

	private:
		CDXCList<TMSprite> m_spriteList;
};

class TMBagList : public TMSpriteList
{
	public:
		TMBagList(CDXTresMarias* Jogo);

		TMBag* GetFirst(void) { return m_spriteList.GetFirst(); }
	    TMBag* GetNext(TMBag* pBag) { return m_spriteList.Next(pBag); }

		void AddBag(TMBag* pBag);
		TMBag* Remove(TMBag* pBag) { return m_spriteList.Remove( pBag, TRUE ); }

		bool IsBagInPos(long x, long y, long z);

		void Desenha(CDXSurface* lpTMB);
		void Click(TMCursor* cursor);

		void Activate( int wich );
		void Deactivate();
		void Throw();

		int GetBagsLeft() { return BagCount; }

	private:
		CDXCList<TMBag> m_spriteList;
		CDXTresMarias* Jogo;
		int BagCount;
		int ClickableBagCount;
		int ClickableBagTot;
};

#endif