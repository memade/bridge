#if !defined(INC_H___8A9B42F1_9E26_4845_8424_71CDAF36C1D1__HEAD__)
#define INC_H___8A9B42F1_9E26_4845_8424_71CDAF36C1D1__HEAD__

namespace local {

 class Global final {
  using tf_pchacker_api_object_init = void*(__stdcall*)(const void*, unsigned long);
  using tf_pchacker_api_object_uninit = void(__stdcall*)(void);
 public:
  Global();
  virtual ~Global();
 public:
  static bool Ready();
  static pchacker::libuvpp::IServer* ServerGet();
  static pchacker::IPCHacker* PCHackerGet();
 private:
  void Init();
  void UnInit();
 private:
  std::atomic_bool m_Ready = false;
  HMODULE m_hPCHacker = nullptr;
  pchacker::IPCHacker* m_pPCHacker = nullptr;
  tf_pchacker_api_object_init m_pchacker_api_object_init = nullptr;
  tf_pchacker_api_object_uninit m_pchacker_api_object_uninit = nullptr;
  pchacker::libuvpp::IServer* m_pServer = nullptr;

 };

 extern Global* __gspGlobal;
 extern Global* GlobalGet();
}///namespace local

/// /*新生®（上海）**/
/// /*2022_11_14T00:36:01.3007609Z**/
/// /*_ _ _ _ _ _ _ www.skstu.com _ _ _ _ _ _ _**/
#endif ///INC_H___8A9B42F1_9E26_4845_8424_71CDAF36C1D1__HEAD__


