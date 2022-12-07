#if !defined(__A7B4E187_F58B_43DC_8AA3_C689E73BF000__)
#define __A7B4E187_F58B_43DC_8AA3_C689E73BF000__

namespace local {

 class UIWxApp : public wxApp {
 public:
  UIWxApp();
  virtual ~UIWxApp();
 private:
  UIWxMDIParentFrame* m_pFrame = nullptr;
 public:
  bool OnInit() override;
  int OnExit() override;
 private:
  void OnFrameShow(wxThreadEvent& event);
  void OnTerminate(wxThreadEvent& event);
 protected:
  std::vector<std::thread> m_Threads;
 };

}///namespace local

/// /*_ Memade®（新生™） _**/
/// /*_ Tue, 06 Dec 2022 12:28:41 GMT _**/
/// /*_____ https://www.skstu.com/ _____ **/
#endif///__A7B4E187_F58B_43DC_8AA3_C689E73BF000__


