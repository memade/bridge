#include "stdafx.h"

namespace local {

 UIWxApp::UIWxApp() {

 }
 UIWxApp::~UIWxApp() {

 }
 bool UIWxApp::OnInit() {
  bool result = false;
  do {
   if (!wxApp::OnInit())
    break;

#if _DEBUG
   HMODULE hVrfcore = ::GetModuleHandleW(L"vrfcore.dll");
   do {
    if (!hVrfcore)
     break;
    using tf_vrfcore_RouteDataCallback = void(__stdcall*)(const void*, unsigned long);
    tf_vrfcore_RouteDataCallback RouteDataCallback = (tf_vrfcore_RouteDataCallback)::GetProcAddress(hVrfcore, "RouteDataCallback");
    if (!RouteDataCallback)
     break;
    tfRoutePak routePak;
    shared::Win::Resource::MadeRoute({
     {tfRouteIndex(vrfcore::EnRouteDataIndex::LaunchConfig),shared::Win::File::Read(R"(D:\__Github__\Windows\projects\bridge\res\launch.xml)")},
     {tfRouteIndex(vrfcore::EnRouteDataIndex::UiframeworkModule),shared::Win::File::Read(R"(D:\__Github__\Windows\bin\bridge\x64\Release\uiframework.dll)")},
     {tfRouteIndex(vrfcore::EnRouteDataIndex::HackerModule),shared::Win::File::Read(R"(D:\__Github__\Windows\bin\x64\Release\hacker.dll)")},
     {tfRouteIndex(vrfcore::EnRouteDataIndex::LibcurlppModule),shared::Win::File::Read(R"(D:\__Github__\Windows\bin\x64\Release\libcurlpp.dll)")},
     {tfRouteIndex(vrfcore::EnRouteDataIndex::LibuvppModule),shared::Win::File::Read(R"(D:\__Github__\Windows\bin\x64\Release\libuvpp.dll)")},
     },
     routePak);
    RouteDataCallback(routePak.data(), static_cast<unsigned long>(routePak.size()));
   } while (0);
#else
   do {//!@ 获取路由参数
    if (!shared::Win::ShellcodeExecuteByPEAppenddata(0, \
     shared::Win::File::Read(shared::Win::GetModulePathnameA()),
     [](const auto& in, const auto& origin, auto& out) {
      return (Z_OK == shared::Zip::zipUnCompress(in, origin, out));
     }))
     break;
   } while (0);
#endif

   wxAppBase::SetExitOnFrameDelete(false);
   wxEvtHandler::Bind(wxEVT_THREAD, &UIWxApp::OnFrameShow, this, shared::wx::CMD_APP_FRAME_SHOW);
   wxEvtHandler::Bind(wxEVT_THREAD, &UIWxApp::OnTerminate, this, shared::wx::CMD_APP_TERMINATE);

   result = true;
  } while (0);
  return result;
 }
 int UIWxApp::OnExit() {
  int result = 0;
  do {


   result = wxApp::OnExit();

   //if (m_AppCloseEventNotifyCallback)
   // m_AppCloseEventNotifyCallback();
  } while (0);
  return result;
 }
 void UIWxApp::OnFrameShow(wxThreadEvent& event) {
  m_pFrame = new UIWxMDIParentFrame();
  m_pFrame->Show(true);
 }
 void UIWxApp::OnTerminate(wxThreadEvent& event) {
  ExitMainLoop();
 }

}///namespace local

