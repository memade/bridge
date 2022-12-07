#include "stdafx.h"

namespace local {

 wxIMPLEMENT_APP_NO_MAIN(UIWxApp);

 UIWxMain::UIWxMain() {
  Init();
 }

 UIWxMain::~UIWxMain() {
  UnInit();
 }

 void UIWxMain::Init() {
 }

 void UIWxMain::UnInit() {
 }
 void UIWxMain::Release() const {
  delete this;
 }
 void UIWxMain::Perfrom() {
  std::thread(
   [this]() {
    do {
     if (!__gpHinstance)
      break;

     wxDISABLE_DEBUG_SUPPORT();
     wxInitializer wxinit;
     if (!wxinit.IsOk())
      break;

     wxThreadEvent* event = new wxThreadEvent(wxEVT_THREAD, shared::wx::CMD_APP_FRAME_SHOW);
     event->SetString("Hello wxWidgets!");
     wxQueueEvent(wxApp::GetInstance(), event);

     wxEntry(__gpHinstance);
    } while (0); 
   }).join();
 }


}///namespace local

