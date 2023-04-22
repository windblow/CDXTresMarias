/****
fonte       : EasyWindow.cpp
criador     : Rafael A. Costa
coment�rios : Encapsulamento das mensagens do WINDOWS
*****/

#include <windows.h>
#include <commctrl.h>
#include "EasyWindow.h"

/****
m�todo      :  EasyWindow::InitEasyWindow
criador     :  Rafael A. Costa
coment�rios :  Encapsula a cria��o e execu��o do thread
*******/
int EasyWindow::InitEasyWindow()
{
   // Geralmente utilizada para mudar o �cone da aplica��o, instalar menus e outras coisas
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::EndEasyWindow
criador     :  Rafael A. Costa
coment�rios :  Fun��o chamada antes do fim da aplica��o
*******/
int EasyWindow::EndEasyWindow()
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::SetUp
criador     :  Rafael A. Costa
coment�rios :  Inicializa��o geral da janela.
*******/
void EasyWindow::SetUp(LPCWSTR lpszClass, HINSTANCE hinstTmp,
      int iTmpX, int iTmpY, int iTmpWidth, int iTmpHeight)
{
   // Inicia estrutura com os dados da classe, para registrar no Windows
   wcApp.style         = 0;
   wcApp.lpfnWndProc   = EasyWindow::WndProcForm;
   wcApp.cbClsExtra    = 0;
   wcApp.cbWndExtra    = sizeof(EasyWindow *); // Tente inserir a callback do Windows
   wcApp.hInstance     = hinstTmp;
   wcApp.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
   wcApp.hCursor       = LoadCursor(NULL, IDC_ARROW);
   wcApp.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
   wcApp.lpszMenuName  = NULL;
   wcApp.lpszClassName = lpszClass;

   // Inicializa os demais atributos da classe
   hwndWin = NULL;
   hinst = hinstTmp;
   iY = iTmpY;
   iX = iTmpX;
   iWidth = iTmpWidth;
   iHeight = iTmpHeight;
}

/****
m�todo      :  EasyWindow::Start
criador     :  Rafael A. Costa
coment�rios :  Fun��o que registra a classe, cria a janela principal e inicializa os objetos gr�ficos
*******/
int EasyWindow::Start(LPCWSTR lpszWindowName, DWORD dwStyle, int iCmdShow)
{
   MSG msg;
   ATOM atomClass;
   LPCWSTR lpszWork;
   WORD w = (WORD)::GetCurrentThreadId();

   //Habilita COM
   CoInitialize(NULL);

   atomClass = RegisterClass(&wcApp);
   if(atomClass==0)
   {
      // Poupa o usuario da classe(eu) a exibir mensagens
      ::MessageBeep(MB_ICONHAND);
      ::MessageBox(NULL, (LPCWSTR)L"N�o pude registrar a sua classe", (LPCWSTR)L"EasyWindow",
         MB_OK | MB_ICONHAND);
      return(RET_OK);
   }

   // Agora cria a janela da aplicacao
   if(lpszWindowName == NULL)
      lpszWork = (LPCWSTR)L"EasyWindow";
   else
      lpszWork = lpszWindowName;

   // Passa this como parametro para resolver problema do WM_CREATE
   hwndWin = CreateWindow(wcApp.lpszClassName, lpszWork,
      dwStyle, iX, iY, iWidth, iHeight,
      NULL, NULL, hinst, (LPSTR)this);
   if(hwndWin == NULL)
   {
      // Poupa o usuario da classe(eu) a exibir mensagens
      ::MessageBeep(MB_ICONHAND);
      ::MessageBox(NULL, (LPCWSTR)L"N�o pude criar a janela da aplica��o", (LPCWSTR)L"EasyWindow",
         MB_OK | MB_ICONHAND);
      return(RET_OK);
   }

   // Exibe a janela e inicia o loop de mensagens
	ShowWindow(hwndWin, iCmdShow);
	UpdateWindow(hwndWin);

   // Chama inicializa��es do usu�rio
   int iRet = RET_OK;
   try
   {
      iRet = InitEasyWindow();
   }
   catch(int iError)
   {
      iRet = iError;
   }
   //Fecha n�o conseguiu inicializar OK
   if(iRet != RET_OK)
      PostQuitMessage(iRet);

   // Loop de mensagens otimizado
   int iMsg;
   do
   {
      iMsg = PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE );
      if(iMsg)
      {
         ::TranslateMessage(&msg);
         ::DispatchMessage(&msg);
      }
      //Usa aqui pra fazer atualizacoes qualquer(ex: frame move)
      Run();

   }while(iMsg != 0?WM_QUIT != msg.message:true);

   // Chama finaliza��es do usu�rio
   EndEasyWindow();

   //desabilita COM
   CoUninitialize();

   return(msg.wParam);
}

/****
m�todo      :  EasyWindow::InitEasyWindow
criador     :  Rafael A. Costa
coment�rios :  Fun��o callback do Windows
*******/
LRESULT WINAPI EasyWindow::WndProcForm(HWND hwnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
   // Obtem a classe ligada a janela
   EasyWindow *papp = (EasyWindow *)GetWindowLong(hwnd, 0);
   LPCREATESTRUCT lpcs;  // Probleminha com WM_CREATE(Nao existe papp ainda)

   switch(uiMsg)
   {
      case WM_CREATE :
         lpcs = (LPCREATESTRUCT) lParam;
         papp = (EasyWindow *)lpcs->lpCreateParams;

         // Salva o ponteiro da janela
         SetWindowLong(hwnd, 0, (DWORD) papp);
         papp->hwndWin = hwnd;
         if(papp->OnCreate((LPCREATESTRUCT)lParam)==0)
            return(RET_OK);
         break;

      case WM_DESTROY :
         if(papp->OnDestroy()==0)
            return(RET_OK);
         break;

      case WM_SIZE :
         if(papp->OnSize(wParam, LOWORD(lParam), HIWORD(lParam))==0)
            return(RET_OK);
         break;

      case WM_COMMAND :
         if(papp->OnCommand(LOWORD(wParam), (HWND)lParam, HIWORD(wParam))==0)
            return(RET_OK);
         break;

      case WM_SYSCOMMAND :
         if(papp->OnSysCommand(wParam, LOWORD(lParam), HIWORD(lParam))==0)
            return(RET_OK);
         break;

      case WM_CLOSE :
         if(papp->OnClose()==0)
            return(RET_OK);
         break;

      case WM_PAINT :
         if(papp->OnPaint()==0)
            return(RET_OK);
         break;

      case WM_TIMER :
         if(papp->OnTimer(wParam, (TIMERPROC FAR *)lParam)==0)
            return(RET_OK);
         break;

      case WM_CHAR :
         if(papp->OnChar(wParam, lParam)==0)
            return(RET_OK);
         break;

      case WM_KEYUP :
         if(papp->OnKeyUp(wParam,lParam)==0)
            return(RET_OK);
         break;

      case WM_KEYDOWN :
         if(papp->OnKeyUp(wParam,lParam)==0)
            return(RET_OK);
         break;


      case WM_LBUTTONDOWN :
         if(papp->OnLButtonDown(wParam, LOWORD(lParam), HIWORD(lParam))==0)
            return(RET_OK);
         break;

      case WM_RBUTTONDOWN :
         if(papp->OnRButtonDown(wParam, LOWORD(lParam), HIWORD(lParam))==0)
            return(RET_OK);
         break;

      case WM_LBUTTONUP :
         if(papp->OnLButtonUp(wParam, LOWORD(lParam), HIWORD(lParam))==0)
            return(RET_OK);
         break;

      case WM_RBUTTONUP :
         if(papp->OnRButtonUp(wParam, LOWORD(lParam), HIWORD(lParam))==0)
            return(RET_OK);
         break;

      case WM_SHOWWINDOW :
         if(papp->OnShowWindow(wParam, LOWORD(lParam))==0)
            return(RET_OK);
         break;

      case WM_KILLFOCUS :
         if(papp->OnKillFocus((HWND)wParam)==0)
            return(RET_OK);
         break;

      case WM_SETFOCUS :
         if(papp->OnSetFocus((HWND)wParam)==0)
            return(RET_OK);
         break;

      case WM_NOTIFY :
         if(papp->OnNotify((int)wParam, (LPNMHDR)lParam)==0)
            return(RET_OK);
         break;

      case WM_MOUSEMOVE :
         if(papp->OnMouseMove((int)wParam, LOWORD(lParam), HIWORD(lParam))==0)
            return(RET_OK);
         break;

      case WM_ACTIVATE :
         if(papp->OnActivate(LOWORD(wParam), HIWORD(wParam), (HWND)lParam)==0)
            return(RET_OK);
         break;

      default:
         if(uiMsg>=WM_USER)
         {
            if(papp->OnUser(uiMsg, wParam, lParam)==0)
               return(RET_OK);
         }
         break;
   }

   // Mensagens nao tratadas
   return(::DefWindowProc(hwnd, uiMsg, wParam, lParam));
}

/****
m�todo      :  EasyWindow::SetIcon
criador     :  Rafael A. Costa
coment�rios :  Altera o �cone da aplica��o. Deve ser chamado de InitEasyWindow.
*******/
void EasyWindow::SetIcon(HICON hIcon)
{
   wcApp.hIcon = hIcon;
}

/****
m�todo      :  EasyWindow::SetCursor
criador     :  Rafael A. Costa
coment�rios :  Instala o cursor da aplica��o
*******/
void EasyWindow::SetCursor(HCURSOR hCursor)
{
   wcApp.hCursor = hCursor;
}

/****
m�todo      :  EasyWindow::SetMenu
criador     :  Rafael A. Costa
coment�rios :  Instala o menu da aplica��o. Deve ser chamado de InitEasyWindow.
*******/
void EasyWindow::SetMenu(LPCWSTR lpszMenuName)
{
   wcApp.lpszMenuName = lpszMenuName;
}

/****
m�todo      :  EasyWindow::OnCreate
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_CREATE
*******/
int EasyWindow::OnCreate(LPCREATESTRUCT lp)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnDestroy
criador     :  Rafael
coment�rios :  Responde aos eventos WM_DESTROY
*******/
int EasyWindow::OnDestroy(void)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnSize
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_SIZE
*******/
int EasyWindow::OnSize(WORD wSizeParam, WORD iTmpWidth, WORD iTmpHeight)
{
   iWidth = iTmpWidth;
   iHeight = iTmpHeight;
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnPaint
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_PAINT
*******/
int EasyWindow::OnPaint(void)
{
   PAINTSTRUCT ps;

   // Obrigatorio para os programas Windows
   ::BeginPaint(hwndWin, &ps);

   ::EndPaint(hwndWin, &ps);
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnCommand
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_COMMAND
*******/
int EasyWindow::OnCommand(WORD wControl, HWND hwnd, WORD wNM)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnSysCommand
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_SYSCOMMAND
*******/
int EasyWindow::OnSysCommand(WORD wControl, WORD wXPos, WORD wYPos)
{
   return 1;
}

/****
m�todo      :  EasyWindow::OnClose
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_CLOSE
*******/
int EasyWindow::OnClose(void)
{
   PostQuitMessage(RET_OK);
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnTimer
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_TIMER
*******/
int EasyWindow::OnTimer(WORD wTimerId, TIMERPROC FAR *lTimerProc)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnChar
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_CHAR
*******/
int EasyWindow::OnChar(WORD wVKey, DWORD dwKeydata)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnKeyUp
criador     :  Rafael
coment�rios :  Responde aos eventos WM_KEYUP
*******/
int EasyWindow::OnKeyUp(WORD wVKey, DWORD dwKeydata)
{
	switch (wVKey)
	{
		case VK_ESCAPE:
			PostMessage(hwndWin, WM_CLOSE, 0, 0);
		break;

	}

   return(RET_OK);
}


/****
m�todo      :  EasyWindow::OnKeyDown
criador     :  Binder
coment�rios :  Responde aos eventos WM_KEYDOWN
*******/
int EasyWindow::OnKeyDown(WORD wVKey, DWORD dwKeydata)
{
   return(RET_OK);
}


/****
m�todo      :  EasyWindow::OnLButtonDown
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_LBUTTONDOWN
*******/
int EasyWindow::OnLButtonDown(WORD wKeys, int iXPos, int iYPos)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnRButtonDown
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_RBUTTONDOWN
*******/
int EasyWindow::OnRButtonDown(WORD wKeys, int iXPos, int iYPos)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnLButtonUp
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_LBUTTONUP
*******/
int EasyWindow::OnLButtonUp(WORD wKeys, int iXPos, int iYPos)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnRButtonUp
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_RBUTTONUP
*******/
int EasyWindow::OnRButtonUp(WORD wKeys, int iXPos, int iYPos)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnShowWindow
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_SHOWWINDOW
*******/
int EasyWindow::OnShowWindow(BOOL bShow, WORD wStatus)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnUser
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_USER
*******/
int EasyWindow::OnUser(UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnKillFocus
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_KILLFOCUS
*******/
int EasyWindow::OnKillFocus(HWND hwndGetFocus)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnSetFocus
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_SETFOCUS
*******/
int EasyWindow::OnSetFocus(HWND hwndLooseFocus)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnNotify
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_NOTIFY
*******/
int EasyWindow::OnNotify(int iIdCtrl, LPNMHDR pnmh)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnMouseMove
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_MOUSEMOVE
*******/
int EasyWindow::OnMouseMove(WORD wKeys, WORD wX, WORD wY)
{
   // r0007 - Retirando interfaces
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::OnMouseMove
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_ACTIVATE
*******/
int EasyWindow::OnActivate(WORD wActivateFlag, WORD wMinimizeFlag, HWND hwndPrevious)
{
   return(RET_OK);
}

/****
m�todo      :  EasyWindow::Hide
criador     :  Rafael A. Costa
coment�rios :  "Esconde" a janela
*******/
int EasyWindow::Hide(void)
{
   if(!hwndWin)
      return(RET_ERROR);

   // Exibe a janela e inicia o loop de mensagens
	ShowWindow(hwndWin, SW_HIDE);
	UpdateWindow(hwndWin);

   return(RET_OK);
}

/****
m�todo      :  EasyWindow::Show
criador     :  Rafael A. Costa
coment�rios :  Mostra a janela default
*******/
int EasyWindow::Show(void)
{
   if(!hwndWin)
      return(RET_ERROR);

   // Exibe a janela e inicia o loop de mensagens
	ShowWindow(hwndWin, SW_NORMAL);
	UpdateWindow(hwndWin);

   return(RET_OK);
}

/****
m�todo      :  EasyWindow::Maximize
criador     :  Rafael A. Costa
coment�rios :  Mostra a janela maximizada
*******/
int EasyWindow::Maximize(void)
{
   if(!hwndWin)
      return(RET_ERROR);

   // Exibe a janela e inicia o loop de mensagens
	ShowWindow(hwndWin, SW_MAXIMIZE);
	UpdateWindow(hwndWin);

   return(RET_OK);
}

/****
m�todo      :  EasyWindow::Minimize
criador     :  Rafael A. Costa
coment�rios :  Mostra a janela minimizada
*******/
int EasyWindow::Minimize(void)
{
   if(!hwndWin)
      return(RET_ERROR);

   // Exibe a janela e inicia o loop de mensagens
	ShowWindow(hwndWin, SW_MINIMIZE);
	UpdateWindow(hwndWin);

   return(RET_OK);
}

/****************************************************************************************
*****************************************************************************************
*****************************************************************************************
****************************************************************************************/

/****
m�todo      :  EasyDialog::SetUp
criador     :  Rafael A. Costa
coment�rios :  Inicializa��o geral da janela.
*******/
void EasyDialog::SetUp(int iDialog, HINSTANCE hinst, HWND hwndWinMain)
{
   if(bInitialized)
      return;

   this->iDialog     = iDialog;
   this->hinst       = hinst;
   this->hwndWinMain = hwndWinMain;
}


/****
m�todo      :  EasyDialog::Start
criador     :  Rafael A. Costa
coment�rios :  Fun��o que inicia a Dialog
*******/
bool EasyDialog::Start(bool bModal)
{
   if(bInitialized)
      return(true);

   InitCommonControls();

   if(bModal)
   {
      DialogBoxParam(hinst, MAKEINTRESOURCE(iDialog),hwndWinMain, DLGPROC(EasyDialog::DlgProcForm), (LPARAM)this);
      return(true);
   }
   else
      if((hwndWin = CreateDialogParam(hinst, MAKEINTRESOURCE(iDialog),hwndWinMain, DLGPROC(EasyDialog::DlgProcForm), (LPARAM)this)) == NULL)
         return(false);

   bInitialized = true;

   showDialog();

   return(true);
}

/****
m�todo      :  EasyDialog::showDialog
criador     :  Rafael A. Costa
coment�rios :  Controle de visibilidade
*******/
void EasyDialog::showDialog(bool bShow)
{
   if(!bInitialized)
      return;

   if(bShow)
   {
      ShowWindow(hwndWin, SW_SHOW);
      SetFocus(hwndWin);
   }
   else
   {
      ShowWindow(hwndWin, SW_HIDE);
      SetFocus(hwndWinMain);
   }

}

/****
m�todo      :  EasyDialog::OnCommand
criador     :  Rafael A. Costa
coment�rios :  Processamento da mensagem WM_COMMAND
*******/
int EasyDialog::OnCommand(WORD wControl, HWND hwnd, WORD wNM)
{
   return(true);
}

/****
m�todo      :  EasyDialog::OnCreate
criador     :  Rafael A. Costa
coment�rios :  Processamento da inicializa��o da janela
*******/
int EasyDialog::OnCreate(void)
{
   return(true);
}

/****
m�todo      :  EasyDialog::OnClose
criador     :  Rafael A. Costa
coment�rios :  Processamento do fechamento da janela
*******/
int EasyDialog::OnClose(void)
{
   return(true);
}

/****
m�todo      :  EasyDialog::OnUser
criador     :  Rafael A. Costa
coment�rios :  Processamento de mesagens do usuario
*******/
int EasyDialog::OnUser(UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
   return(true);
}

/****
m�todo      :  EasyDialog::OnChar
criador     :  Rafael A. Costa
coment�rios :  Responde aos eventos WM_CHAR
*******/
int EasyDialog::OnChar(WORD wVKey, DWORD dwKeydata)
{
   return(true);
}

/****
m�todo      :  EasyDialog::DlgProcForm
criador     :  Rafael A. Costa
coment�rios :  Processamento das mensagens
*******/
BOOL CALLBACK EasyDialog::DlgProcForm(HWND hwnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{

   //Na primeira mensagem seta o THIS da classe que controla tudo
   if(uiMsg == WM_INITDIALOG)
   {
      SetWindowLong(hwnd, DWLP_USER, lParam);
      ((EasyDialog*)lParam)->hwndWin = hwnd;
      ((EasyDialog*)lParam)->bInitialized = true;
      return(((EasyDialog*)lParam)->OnCreate());
   }

   // Obtem a classe ligada a janela
   EasyDialog *papp = (EasyDialog *)GetWindowLong(hwnd, DWLP_USER);

   if(!papp)
      return(false);

   switch(uiMsg)
   {
      case WM_COMMAND :
         return(papp->OnCommand(LOWORD(wParam), (HWND)lParam, HIWORD(wParam)));
         break;
      case WM_CLOSE :
         if(papp->bInitialized)
         {
            EndDialog(papp->hwndWin, 0);
            papp->hwndWin = NULL;
            papp->bInitialized = false;
         }
         if(papp->OnClose()==0)
            return(true);
         break;
      case WM_CHAR :
         if(papp->OnChar(wParam, lParam)==0)
            return(true);
         break;
      default:
         if(uiMsg>=WM_USER)
         {
            if(papp->OnUser(uiMsg, wParam, lParam)==0)
               return(true);
         }
         break;
   }
   return(false);
}
