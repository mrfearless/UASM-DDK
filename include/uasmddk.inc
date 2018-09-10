;==============================================================================
; UASM-DDK - uasmddk.inc
; 
; www.github.com/mrfearless/UASM-DDK by fearless
;
; For assembling WMD and WDF x64 drivers using UASM x64
;==============================================================================

include ntdll.inc
include ntoskrnl.inc
include ntstatus.inc
include ntdef.inc
include ntddk.inc
include wdm.inc
include wdf.inc

includelib ntdll.lib
includelib ntoskrnl.lib
includelib kernel32.lib
includelib wdfdriverentry.lib
includelib wdfldr.lib