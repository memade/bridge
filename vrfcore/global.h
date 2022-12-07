#if !defined(__E7207E93_8CA3_49A7_9915_49F4F68E69DF__)
#define __E7207E93_8CA3_49A7_9915_49F4F68E69DF__

namespace local {

 class Global {
 public:
  Global();
  ~Global();
 private:
  void Init();
  void UnInit();
 public:
  static UIWxMain* UIMain();
  static tfRouteRes LaunchRouteRes();
  static bool LaunchRouteRes(const void*, const unsigned long&);
 private:
  UIWxMain* m_pWxMain = nullptr;
  tfRouteRes m_LaunchRouteRes;
 };

 extern Global* __gpGlobal;
 extern Global* GlobalGet();
 extern HINSTANCE __gpHinstance;
}///namespace local

/// /*_ Memade®（新生™） _**/
/// /*_ Tue, 06 Dec 2022 10:40:17 GMT _**/
/// /*_____ https://www.skstu.com/ _____ **/
#endif///__E7207E93_8CA3_49A7_9915_49F4F68E69DF__


