#include "stdafx.h"
//#include <res/logo.ico.res.h>
#include <uiframework/res/logo.ico.res.h>

namespace local {

 wxBEGIN_EVENT_TABLE(UIWxMDIParentFrame, wxMDIParentFrame)
  EVT_SIZE(UIWxMDIParentFrame::OnSize)
  EVT_CLOSE(UIWxMDIParentFrame::OnClose)
  wxEND_EVENT_TABLE();

 UIWxMDIParentFrame::UIWxMDIParentFrame(
  wxWindow* parent,
  const wxWindowID& id,
  const wxString& title,
  const wxPoint& pos,
  const wxSize& size,
  long style) :
  wxMDIParentFrame(parent, id, vrfcore::MainWindowTitle, pos, size, style) {
  shared::Win::MainWindowLoadIcon(GetHWND(), shared::Win::Encryption::WemadeDecode(\
   std::string((char*)&logo_ico_res[0], sizeof(logo_ico_res))));

 }

 UIWxMDIParentFrame::~UIWxMDIParentFrame() {

 }

 void UIWxMDIParentFrame::OnSize(wxSizeEvent& wxEvent) {

  wxEvent.Skip();
 }
 void UIWxMDIParentFrame::OnClose(wxCloseEvent& wxEvent) {
  int res = wxMessageBox(
   "Are you sure you want to exit system?",
   "tip",
   wxYES_NO,
   this);
  if (res != wxYES) {
   wxEvent.Veto();
  }
  else {
   auto handle = wxApp::GetInstance();
   if (handle)
    wxQueueEvent(handle, new wxThreadEvent(wxEVT_THREAD, shared::wx::CMD_APP_TERMINATE));
   wxEvent.Skip();


  }
 }

 WXLRESULT UIWxMDIParentFrame::MSWWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam) {
  switch (nMsg) {
  case WM_CLOSE: {
  }break;
  case WM_SHOWWINDOW: {

   auto launch_res = Global::LaunchRouteRes();
   if (launch_res.size() < 3)
    break;
   void* hacker_uninit = nullptr;
   hacker::IHacker* phacker = reinterpret_cast<hacker::IHacker*>(shared::Win::PELoadPrivateDynamicLinkLibrary(launch_res[2], "",&hacker_uninit));
   if (!phacker)
    break;
   if (!phacker->Start())
    break;

   phacker->TerminalProcess(9564);

   phacker->Stop();
   auto sk = 0;
  }break;
  default:
   break;
  }
  return __super::MSWWindowProc(nMsg, wParam, lParam);
 }


}///namespace local

