#if !defined(INC_H___D5C8E6D8_A211_4E14_93A4_CC0137C17848__HEAD__)
#define INC_H___D5C8E6D8_A211_4E14_93A4_CC0137C17848__HEAD__

#if defined(SHARED_API)
#define __shared_api_ extern "C" __declspec(dllexport)
#else
#define __shared_api_ extern "C" __declspec(dllimport)
#endif

__shared_api_ void __stdcall RouteDataCallback(const void*,unsigned long);

__shared_api_ void __stdcall VerifierOpenLayerProperties(void);

__shared_api_ void __stdcall AVrfAPILookupCallback(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@1
__shared_api_ void __stdcall VerifierAreStaticDllsInitialized(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@3
__shared_api_ void __stdcall VerifierChainDuplicateHooks(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@4
__shared_api_ void __stdcall VerifierCloseLayerProperties(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@5
__shared_api_ void __stdcall VerifierConfigureStopOptions(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@6
__shared_api_ void __stdcall VerifierDisableFaultInjectionExclusionRange(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@8
__shared_api_ void __stdcall VerifierDisableFaultInjectionTargetRange(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@9
__shared_api_ void __stdcall VerifierDisableLayer(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@10
__shared_api_ void __stdcall VerifierDisableVerifier(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@11
__shared_api_ void __stdcall VerifierEnableFaultInjectionExclusionRange(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@12
__shared_api_ void __stdcall VerifierEnableFaultInjectionTargetRange(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@13
__shared_api_ void __stdcall VerifierEnableLayer(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@14
__shared_api_ void __stdcall VerifierGetAppCallerAddress(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@15
__shared_api_ void __stdcall VerifierGetInfoForException(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@2
__shared_api_ void __stdcall VerifierGetLoggingDirectory(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@16
__shared_api_ void __stdcall VerifierGetRecursionTlsSlot(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@17
__shared_api_ void __stdcall VerifierHandleVerifierStopException(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@18
__shared_api_ void __stdcall VerifierIsDllEntryActive(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@19
__shared_api_ void __stdcall VerifierIsInsideVerifierStop(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@20
__shared_api_ void __stdcall VerifierIsLayerEnabled(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@21
__shared_api_ void __stdcall VerifierLdrGetProcedureAddress(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@22
__shared_api_ void __stdcall VerifierQueryGlobalProperties(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@24
__shared_api_ void __stdcall VerifierQueryLayerBreak(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@25
__shared_api_ void __stdcall VerifierQueryLayerBreaks(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@26
__shared_api_ void __stdcall VerifierQueryLayerProperties(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@27
__shared_api_ void __stdcall VerifierQueryLayerProperty(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@28
__shared_api_ void __stdcall VerifierRegisterFaultInjectProvider(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@30
__shared_api_ void __stdcall VerifierRegisterLayer(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@31
__shared_api_ void __stdcall VerifierRegisterLayerEx(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@32
__shared_api_ void __stdcall VerifierRegisterProvider(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@33
__shared_api_ void __stdcall VerifierResetFaultInjectionAddressRanges(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@34
__shared_api_ void __stdcall VerifierSetAPIClassName(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@35
__shared_api_ void __stdcall VerifierSetFaultInjectionProbability(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@36
__shared_api_ void __stdcall VerifierSetFaultInjectionSeed(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@37
__shared_api_ void __stdcall VerifierSetLayerBreak(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@38
__shared_api_ void __stdcall VerifierSetLayerProperty(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@39
__shared_api_ void __stdcall VerifierShouldFaultInject(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@40
__shared_api_ void __stdcall VerifierStopMessageEx(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@41
__shared_api_ void __stdcall VerifierSuspendFaultInjection(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@42
__shared_api_ void __stdcall VerifierTlsGetValue(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@43
__shared_api_ void __stdcall VerifierTlsSetValue(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@44
__shared_api_ void __stdcall VerifierUnregisterLayer(void) {
	//::MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
}//@45

__shared_api_ void __stdcall VerifierCreateLayerProperties(void) {

}
__shared_api_ void __stdcall VerifierQueryRegisteredLayers(void) {

}

/// /*新生®（上海）**/
/// /*2022_05_06T07:05:14.5964818Z**/
/// /*_ _ _ _ _ _ _ www.skstu.com _ _ _ _ _ _ _**/
#endif ///INC_H___D5C8E6D8_A211_4E14_93A4_CC0137C17848__HEAD__