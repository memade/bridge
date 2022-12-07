#include "stdafx.h"

namespace local {
 extern Global* __gpGlobal = nullptr;
 extern Global* GlobalGet() { return __gpGlobal; }
 extern HINSTANCE __gpHinstance = nullptr;

 Global::Global() {
  Init();
 }

 Global::~Global() {
  UnInit();
 }

 void Global::Init() {
  m_pWxMain = new UIWxMain();
 }

 void Global::UnInit() {
  m_pWxMain->Release();
 }

 UIWxMain* Global::UIMain() {
  UIWxMain* result = nullptr;
  do {
   if (!__gpGlobal)
    break;
   result = __gpGlobal->m_pWxMain;
  } while (0);
  return result;
 }
 tfRouteRes Global::LaunchRouteRes() {
  tfRouteRes result;
  do {
   if (!__gpGlobal)
    break;
   result = __gpGlobal->m_LaunchRouteRes;
  } while (0);
  return result;
 }
 bool Global::LaunchRouteRes(const void* route, const unsigned long& route_size) {
  bool result = false;
  do {
   if (!__gpGlobal)
    break;
   result = shared::Win::Resource::UnMadeRoute(tfRoutePak((char*)route, route_size), __gpGlobal->m_LaunchRouteRes);
  } while (0);
  return result;
 }
}///namespace local

