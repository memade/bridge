#if !defined(__2B9A92EB_5AAE_4431_B4E2_FDBA1B34EED9__)
#define __2B9A92EB_5AAE_4431_B4E2_FDBA1B34EED9__

namespace local {

 class IWxChild : public wxMDIChildFrame {
 public:
  IWxChild(wxMDIParentFrame* parent,const wxString& window_title);
  virtual ~IWxChild();
 };

 class GeneralChild : public IWxChild {
 public:
  GeneralChild(wxMDIParentFrame* parent, const wxString& window_title);
  virtual ~GeneralChild();
 private:
  void OnSize(wxSizeEvent&);
  void OnCloseWindow(wxCloseEvent&);
  wxDECLARE_EVENT_TABLE();
 };

 class HackerChild : public IWxChild {
 public:
  HackerChild(wxMDIParentFrame* parent);
  virtual ~HackerChild();
 private:
  void OnSize(wxSizeEvent&);
  void OnCloseWindow(wxCloseEvent&);
  wxDECLARE_EVENT_TABLE();
 };
}///namespace local

/// /*_ Memade®（新生™） _**/
/// /*_ Wed, 07 Dec 2022 10:14:05 GMT _**/
/// /*_____ https://www.skstu.com/ _____ **/
#endif///__2B9A92EB_5AAE_4431_B4E2_FDBA1B34EED9__



