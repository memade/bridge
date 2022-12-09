#include "stdafx.h"

namespace local {

 IWxChild::IWxChild(wxMDIParentFrame* parent, const wxString& window_title) :
  wxMDIChildFrame(parent, wxID_ANY, window_title, wxDefaultPosition, wxDefaultSize) {

 }
 IWxChild::~IWxChild() {

 }

 ////////////////////////////////////////////////////////////////////////////////////////////////////////////
 wxBEGIN_EVENT_TABLE(GeneralChild, IWxChild)
  EVT_SIZE(GeneralChild::OnSize)
  EVT_CLOSE(GeneralChild::OnCloseWindow)
  wxEND_EVENT_TABLE();

 GeneralChild::GeneralChild(wxMDIParentFrame* parent, const wxString& window_title) :
  IWxChild(parent, window_title) {

  std::string res_ico_main;
  shared::Win::Resource::UnRespak(std::string((char*)&RES_ICO_MAIN[0], sizeof(RES_ICO_MAIN)), res_ico_main);
  shared::Win::MainWindowLoadIcon(GetHWND(), res_ico_main);

 }

 GeneralChild::~GeneralChild() {

 }
 void GeneralChild::OnSize(wxSizeEvent& evt) {
  evt.Skip();
 }
 void GeneralChild::OnCloseWindow(wxCloseEvent& evt) {
  evt.Skip();
 }

 ////////////////////////////////////////////////////////////////////////////////////////////////////////////
 wxBEGIN_EVENT_TABLE(HackerChild, IWxChild)
  EVT_SIZE(HackerChild::OnSize)
  EVT_CLOSE(HackerChild::OnCloseWindow)
  wxEND_EVENT_TABLE();

 HackerChild::HackerChild(wxMDIParentFrame* parent) :
  IWxChild(parent, LR"(Hacker)") {

  std::string logo_res;
  shared::Win::Resource::UnRespak(std::string((char*)&RES_ICO_CHILD_HACKER[0], sizeof(RES_ICO_CHILD_HACKER)), logo_res);
  shared::Win::MainWindowLoadIcon(GetHWND(), logo_res);

 }

HackerChild::~HackerChild() {

 }
 void HackerChild::OnSize(wxSizeEvent& evt) {
  evt.Skip();
 }
 void HackerChild::OnCloseWindow(wxCloseEvent& evt) {
  evt.Skip();
 }
}///namespace local

