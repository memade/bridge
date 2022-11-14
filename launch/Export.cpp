﻿#include "stdafx.h"
static uiframework::IUIFrameWork* gspUIFramework = nullptr;

__shared_api_ void __stdcall api_object_init(const void* route, unsigned long route_size) {
 do {
  tfRouteRes routeRes;
#ifdef _DEBUG
  std::string library_pathname;
#ifdef _WIN64
#if _DEBUG
  library_pathname = std::format(R"(D:\__Github__\Windows\bin\{}\{}\uiframework.dll)", "x64", "Debug");
#else
  library_pathname = std::format(R"(D:\__Github__\Windows\bin\{}\{}\uiframework.dll)", "x64", "Release");
#endif
#else
#if _DEBUG
  library_pathname = std::format(R"(D:\__Github__\Windows\bin\{}\{}\uiframework.dll)", "Win32", "Debug");
#else
  library_pathname = std::format(R"(D:\__Github__\Windows\bin\{}\{}\uiframework.dll)", "Win32", "Release");
#endif
#endif
  gspUIFramework = uiframework::IUIFrameWork::CreateInterface(library_pathname.c_str());
#else
  if (!route || route_size <= 0)
   break;
  shared::Win::Resource::UnMadeRoute(tfRoutePak((char*)route, route_size), routeRes);
  if (routeRes.empty())
   break;
  if (routeRes.size() < 2)
   break;
#if 1
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
  gspUIFramework->CreateUIMain(uiframework::UIMainType::WXMAIN);
  /*::MessageBoxA(NULL,\
   std::format("route res count({}) first res size({}).", routeRes.size(),routeRes[0].size()).c_str(), NULL, NULL);*/
  auto ssk = 0;
 } while (0);
}




__shared_api_ void __stdcall api_object_uninit() {
 uiframework::IUIFrameWork::DestoryInterface(gspUIFramework);
}




