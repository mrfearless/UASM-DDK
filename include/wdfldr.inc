;==============================================================================
; UASM-DDK - wdfldr.inc
; 
; www.github.com/mrfearless/UASM-DDK by fearless
; 
;==============================================================================

WdfLdrDiagnosticsValueByNameAsULONG PROTO :QWORD,:QWORD
WdfLdrQueryInterface PROTO :QWORD
WdfRegisterClassLibrary PROTO :QWORD,:QWORD,:QWORD
WdfRegisterLibrary PROTO :QWORD,:QWORD,:QWORD
WdfVersionBind PROTO :QWORD,:QWORD,:QWORD,:QWORD
WdfVersionBindClass PROTO :QWORD,:QWORD,:QWORD
WdfVersionUnbind PROTO :QWORD,:QWORD,:QWORD
WdfVersionUnbindClass PROTO :QWORD,:QWORD,:QWORD
