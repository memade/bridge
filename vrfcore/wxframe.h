#if !defined(__5591D94B_A769_4E80_A1CC_6F49A90793E4__)
#define __5591D94B_A769_4E80_A1CC_6F49A90793E4__

namespace local {

 class UIWxMDIParentFrame : public wxMDIParentFrame {
 public:
  UIWxMDIParentFrame(wxWindow* parent = nullptr,
   const wxWindowID& id = wxID_ANY,
   const wxString& title = L"",
   const wxPoint& pos = wxDefaultPosition,
   const wxSize& size = wxSize(1024, 768),
   long style = wxDEFAULT_FRAME_STYLE | wxSUNKEN_BORDER);
  virtual ~UIWxMDIParentFrame();
 protected:
  void OnSize(wxSizeEvent&);
  void OnClose(wxCloseEvent&);
  WXLRESULT MSWWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam) override final;
 private:
  wxDECLARE_EVENT_TABLE();
 };

}///namespace local

/// /*_ Memade®（新生™） _**/
/// /*_ Tue, 06 Dec 2022 12:29:37 GMT _**/
/// /*_____ https://www.skstu.com/ _____ **/
#endif///__5591D94B_A769_4E80_A1CC_6F49A90793E4__


