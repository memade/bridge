#include "stdafx.h"
static uiframework::IUIFrameWork* gspUIFramework = nullptr;

__shared_api_ void __stdcall api_object_init(const void* route, unsigned long route_size) {
 do {
  tfRouteRes routeRes;
#ifdef _DEBUG
 
#else
  if (!route || route_size <= 0)
   break;
#endif

  HMODULE hVrfcore = ::GetModuleHandleW(L"vrfcore.dll");
  do {
   if (!hVrfcore)
    break;
   using tf_vrfcore_RouteDataCallback = void(__stdcall*)(const void*, unsigned long);
   tf_vrfcore_RouteDataCallback RouteDataCallback = (tf_vrfcore_RouteDataCallback)::GetProcAddress(hVrfcore, "RouteDataCallback");
   if (!RouteDataCallback)
    break;
   RouteDataCallback(route, route_size);
  } while (0);

 } while (0);
}




__shared_api_ void __stdcall api_object_uninit() {
 
}

#if 0
#if 0
#if 0
std::string release_uiframework_pathname = shared::Win::PathFixedA(shared::Win::GetTempPathA() + R"(\uiframework.dll)");
::remove(release_uiframework_pathname.c_str());
shared::Win::File::Write(release_uiframework_pathname, routeRes[1]);
gspUIFramework = uiframework::IUIFrameWork::CreateInterface(release_uiframework_pathname.c_str());
#else//!@ 内存加载
void* fn_uninit = nullptr;
gspUIFramework = \
reinterpret_cast<uiframework::IUIFrameWork*>(shared::Win::PELoadPrivateDynamicLinkLibrary(routeRes[1], "", &fn_uninit));
#endif
#endif
if (!gspUIFramework)
break;

auto pWindowConfig = gspUIFramework->CreateWindowConfig();
pWindowConfig->UIType(uiframework::EnUIType::Win32SDKMDI);
//新生® Software delivery platform
pWindowConfig->MainWindowTitleText(LR"(Memade® Window Demo)");
pWindowConfig->WindowDefaultSize(SIZE{ 1024,768 });
pWindowConfig->WindowDefaultPosition(POINT{ 0,0 });
pWindowConfig->EnableDpiAwareness(true);
pWindowConfig->Visible(true);
pWindowConfig->WindowDefaultBackgroundColor(RGB(105, 105, 105), 1.0);
auto pUIMain = gspUIFramework->CreateUIMain(pWindowConfig);
if (!pUIMain)
break;

auto pConfig = pUIMain->CreateChildConfig();
pConfig->UIType(uiframework::EnUIChildType::DearImGui);
pConfig->WindowTitleText(LR"(UI DearImGui)");
auto pChild = pUIMain->CreateChild(pConfig);
pChild->Create();

pConfig = pUIMain->CreateChildConfig();
pConfig->UIType(uiframework::EnUIChildType::Win32);
pConfig->WindowTitleText(LR"(UI Win32)");
pChild = pUIMain->CreateChild(pConfig);
pChild->Create();

//pConfig = pUIMain->CreateChildConfig();
//pConfig->UIType(uiframework::EnUIChildType::WxWidgets);
//pConfig->WindowTitleText(LR"(UI WxWidgets)");
//pChild = pUIMain->CreateChild(pConfig);
//pChild->Create();

pUIMain->MdiConarrange();
pUIMain->MdiCascade();
pUIMain->MdiTile();
#if 0
pUIMain->CreateChild(uiframework::EnUIChildType::DearImGui, "Child demo");

pUIMain->CreateChild(uiframework::EnUIChildType::Win32, "Child demo1");
#endif
/*::MessageBoxA(NULL,\
 std::format("route res count({}) first res size({}).", routeRes.size(),routeRes[0].size()).c_str(), NULL, NULL);*/

uiframework::IUIFrameWork::DestoryInterface(gspUIFramework);
#endif