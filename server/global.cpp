#include "stdafx.h"

namespace local {
 Global* __gspGlobal = nullptr;
 Global* GlobalGet() { return __gspGlobal; }

 Global::Global() {
  Init();
 }

 Global::~Global() {
  UnInit();
 }
 bool Global::Ready() {
  bool result = false;
  do {
   if (!__gspGlobal)
    break;
   result = __gspGlobal->m_Ready.load();
  } while (0);
  return result;
 }
 void Global::Init() {
  m_Ready.store(false);
  do {
   std::string library_pathname;
#if _DEBUG
   library_pathname = std::format(R"(D:\__Github__\Windows\bin\{}\{}\pchacker.dll)", "x64", "Debug");
#else
   library_pathname = shared::Win::PathFixedA(shared::Win::GetModulePathA() + "\\pchacker.dll");
#endif
   m_pPCHacker = pchacker::IPCHacker::CreateInterface(library_pathname.c_str());
   if (!m_pPCHacker)
    break;
   auto pConfig = m_pPCHacker->ConfigureGet();
   pConfig->EnableLibuvppServer(true);
   pConfig->LocalServiceTcpAddr("0.0.0.0:8100");
   m_pPCHacker->Start(pConfig);
   m_pServer = m_pPCHacker->LibuvppGet()->CreateServer();
   if (!m_pServer)
    break;
   if (!m_pServer->Start(pchacker::libuvpp::EnSocketType::TCP, pchacker::libuvpp::EnIPV::IPV4, "0.0.0.0:8100"))
    break;
   m_Ready.store(true);
  } while (0);
 }
 void Global::UnInit() {
  if (m_pServer)
   m_pServer->Stop();
  if (m_pPCHacker)
   m_pPCHacker->Stop();
  pchacker::IPCHacker::DestoryInterface(m_pPCHacker);
  m_Ready.store(false);
 }
 pchacker::libuvpp::IServer* Global::ServerGet() {
  if (__gspGlobal)
   return __gspGlobal->m_pServer;
  return nullptr;
 }
 pchacker::IPCHacker* Global::PCHackerGet() {
  if (__gspGlobal)
   return __gspGlobal->m_pPCHacker;
  return nullptr;
 }
}///namespace local