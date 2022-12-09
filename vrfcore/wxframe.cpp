#include "stdafx.h"

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

  std::string logo_res;
  shared::Win::Resource::UnRespak(std::string((char*)&RES_ICO_MAIN[0], sizeof(RES_ICO_MAIN)), logo_res);
  shared::Win::MainWindowLoadIcon(GetHWND(), logo_res);

  m_pMenuMain = new wxMenuBar();
  wxFrameBase::SetMenuBar(m_pMenuMain);

  m_pStatusbarMain = wxFrameBase::CreateStatusBar();

  auto pChildObj = new HackerChild(this);
  pChildObj->Show();
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
   wxWindowBase::Center();
   Cascade();

   auto reqObj = GlobalGet()->LibcurlppGet()->CreateRequest(100);
   reqObj->RequestUrl(R"(https://cn.bing.com/)");
   reqObj->RequestType(libcurlpp::EnRequestType::REQUEST_TYPE_GET);
   reqObj->FinishCb(
    [&](const libcurlpp::IResponse* resObj) {

    });
   GlobalGet()->LibcurlppGet()->Perform(reqObj);

  }break;
  default:
   break;
  }
  return __super::MSWWindowProc(nMsg, wParam, lParam);
 }


}///namespace local

