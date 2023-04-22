/**
fonte       : EasyWindow.h
autor       : Rafael A. Costa
comentários : Encapsulamento das mensagens do WINDOWS
**/
#ifndef __EASYWINDOW__

#define __EASYWINDOW__

#include <windows.h>

#define RET_OK    0
#define RET_ERROR 1

class EasyWindow
{
   private:
      WNDCLASS wcApp;

   protected :
      HINSTANCE hinst;
      HWND hwndWin;
      int iY;
      int iX;
      int iWidth;
      int iHeight;


      //Loop principal
      virtual void Run() {};

   public:
      static LRESULT WINAPI WndProcForm(HWND hwnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);

      EasyWindow() :
          hinst(nullptr),
          hwndWin(nullptr),
          iY(0),
          iX(0),
          iWidth(640),
          iHeight(480)
      {
          wcApp.style = 0;
          wcApp.lpfnWndProc = DefWindowProc;
          wcApp.cbClsExtra = 0;
          wcApp.cbWndExtra = 0;
          wcApp.hInstance = hinst;
          wcApp.hIcon = NULL;
          wcApp.hCursor = NULL;
          wcApp.hbrBackground = NULL;
          wcApp.lpszMenuName = NULL;
          wcApp.lpszClassName = NULL;
      };

      void SetUp(LPCWSTR lpszClass, HINSTANCE hinstTmp,
         int iTmpX = CW_USEDEFAULT,
         int iTmpY = CW_USEDEFAULT, 
         int iHeight = CW_USEDEFAULT,
         int iWidth = CW_USEDEFAULT);
      void SetCursor(HCURSOR);
      void SetIcon(HICON);
      void SetMenu(LPCWSTR lpszMenuName);

      HWND getWinHandle()        { return(hwndWin); }
      HINSTANCE getWinInstance() { return(hinst); }

      static LRESULT CALLBACK Hook(int nCode,// Hook code
         WPARAM wParam,                      // Flag do processo atual
         LPARAM lParam);                     // Estrutura com os dados da mensagen atual(CWPSTRUCT)

      int Start(LPCWSTR lpszWindowName, DWORD dwStyle = WS_OVERLAPPEDWINDOW, int iCmdShow = SW_NORMAL);

      virtual int InitEasyWindow(); // Chamado antes do loop de mensagens
      virtual int EndEasyWindow();  // Chamado assim que a aplicação termina

      // Métodos para responder mensagens
      virtual int OnCreate(LPCREATESTRUCT lp);
      virtual int OnDestroy(void);
      virtual int OnSize(WORD wSizeParam, WORD iWidth, WORD iHeight);
      virtual int OnPaint(void);
      virtual int OnCommand(WORD wControl, HWND hwnd, WORD wNM);
      virtual int OnSysCommand(WORD wControl, WORD wXPos, WORD wYPos);
      virtual int OnClose(void);
      virtual int OnTimer(WORD wTimerId, TIMERPROC FAR *lTimerProc);
      virtual int OnChar(WORD wVKey, DWORD dwKeydata);
      virtual int OnKeyUp(WORD nVirtKey, DWORD dwKeydata);
      virtual int OnKeyDown(WORD nVirtKey, DWORD dwKeydata);
      virtual int OnLButtonDown(WORD wKeys, int iXPos, int iYPos);
      virtual int OnLButtonUp(WORD wKeys, int iXPos, int iYPos);
      virtual int OnRButtonDown(WORD wKeys, int iXPos, int iYPos);
      virtual int OnRButtonUp(WORD wKeys, int iXPos, int iYPos);
      virtual int OnUser(UINT uiMsg, WPARAM wParam, LPARAM lParam);
      virtual int OnShowWindow(BOOL bShow, WORD wStatus);
      virtual int OnKillFocus(HWND hwndGetFocus);
      virtual int OnSetFocus(HWND hwndLooseFocus);
      virtual int OnNotify(int iIdCtrl, LPNMHDR pnmh);
      virtual int OnMouseMove(WORD wKeys, WORD wX, WORD wY);
      virtual int OnActivate(WORD wActivateFlag, WORD wMinimizeFlag, HWND hwndPrevious);

      //Métodos para mudar a visualização da janela
      int Hide(void);
      int Show(void);
      int Maximize(void);
      int Minimize(void);

};


class EasyDialog
{
   protected :
      bool bInitialized;
      HWND hwndWinMain;
      HINSTANCE hinst;
      HWND hwndWin;
      int iDialog;

   public:
      static BOOL CALLBACK DlgProcForm(HWND hwnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);

      // Construtor
      EasyDialog() : 
          bInitialized(false), 
          hinst(NULL), 
          hwndWinMain(NULL), 
          hwndWin(NULL),
          iDialog(0)
      {};

      // Destrutor
      ~EasyDialog() {};

      void SetUp(int iDialog, HINSTANCE hinst, HWND hwndWinMain);

      bool Start(bool bModal = true);
      void Stop(void);

      void showDialog(bool bShow = true);

      // Métodos para responder mensagens
      virtual int OnCreate(void);
      virtual int OnChar(WORD wVKey, DWORD dwKeydata);
      virtual int OnCommand(WORD wControl, HWND hwnd, WORD wNM);
      virtual int OnClose(void);
      virtual int OnUser(UINT uiMsg, WPARAM wParam, LPARAM lParam);
};

#endif 

