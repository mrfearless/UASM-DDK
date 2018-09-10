;==============================================================================
; UASM-DDK - wdfdriverentry.inc
; 
; www.github.com/mrfearless/UASM-DDK by fearless
; 
;==============================================================================

FxDriverEntry PROTO :QWORD,:QWORD
FxDriverEntryWorker PROTO :QWORD,:QWORD
FxStubDriverMiniportUnload PROTO :QWORD,:QWORD
FxStubDriverUnload PROTO :QWORD
GUID_WDF_LOADER_INTERFACE_CLASS_BIND PROTO :VARARG
GUID_WDF_LOADER_INTERFACE_DIAGNOSTIC PROTO :VARARG
GUID_WDF_LOADER_INTERFACE_STANDARD PROTO :VARARG
WdfDriverGlobals PROTO C :VARARG
WdfDumpGuid PROTO :VARARG
WdfDumpGuid2 PROTO :VARARG
WdfFunctions PROTO :VARARG
WdfTraceGuid PROTO :VARARG
typeWDF_IFR_HEADER PROTO :VARARG
