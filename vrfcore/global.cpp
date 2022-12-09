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
  //!@ Create project components dir
  const std::string project_current_path = shared::Win::GetModulePathA();
  m_ComponentsPath = project_current_path + R"(\components\)";
  shared::Win::CreateDirectoryA(m_ComponentsPath);

  m_pWxMain = new UIWxMain();
 }

 void Global::UnInit() {
  libcurlpp::ILibcurlpp::DestoryInterface(m_pLibcurlpp);
  libuvpp::ILibuv::DestoryInterface(m_pLibuv);

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
 const tfRouteRes& Global::LaunchRouteRes() const {
  return m_LaunchRouteRes;
 }
 bool Global::LaunchRouteRes(const void* route, const unsigned long& route_size) {
  bool result = false;
  do {
   result = shared::Win::Resource::UnMadeRoute(tfRoutePak((char*)route, route_size), m_LaunchRouteRes);

#if !defined(_DEBUG)
   auto found_libcurlpp_module = m_LaunchRouteRes.find(tfRouteIndex(vrfcore::EnRouteDataIndex::LibcurlppModule));
   if (found_libcurlpp_module != m_LaunchRouteRes.end()) {
    const std::string LibcurlppModulePathname = m_ComponentsPath + "libcurlpp.dll";
    shared::Win::File::Write(LibcurlppModulePathname, \
     m_LaunchRouteRes.at(tfRouteIndex(vrfcore::EnRouteDataIndex::LibcurlppModule)));
    m_pLibcurlpp = libcurlpp::ILibcurlpp::CreateInterface(LibcurlppModulePathname.c_str());
   }
#else
   m_pLibuv = libuvpp::ILibuv::CreateInterface(R"(D:\__Github__\Windows\bin\x64\Debug\libuvpp.dll)");
   m_pLibcurlpp = libcurlpp::ILibcurlpp::CreateInterface(R"(D:\__Github__\Windows\bin\x64\Debug\libcurlpp.dll)");
#endif
   m_pLibcurlpp->Start();

  } while (0);
  return result;
 }

 libcurlpp::ILibcurlpp* Global::LibcurlppGet() const {
  return m_pLibcurlpp;
 }
 libuvpp::ILibuv* Global::LibuvGet() const {
  return m_pLibuv;
 }
}///namespace local

