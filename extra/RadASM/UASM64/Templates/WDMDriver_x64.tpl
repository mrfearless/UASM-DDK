Driver64
Driver64Template
WDM Driver x64
[*BEGINPRO*]
[*BEGINDEF*]
[MakeDef]
Menu=1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0
1=4,O,$B\RC.EXE /v,1
2=3,O,$B\UASM64.EXE /c -win64 -Zp8 /win64 /D_WIN64 /Cp /nologo /W2 /I"$I",2
3=16,O,$B\LINK.EXE /RELEASE /VERSION:"10.0" /DRIVER /ENTRY:"DriverEntry" /MACHINE:X64 /SUBSYSTEM:NATIVE /MERGE:"_TEXT=.text;_PAGE=PAGE" /OPT:REF /INCREMENTAL:NO /OPT:ICF /SECTION:INIT|d /LIBPATH:"$L" /OUT:"$16",3,4
4=0,O,$C\testsign.bat
5=rsrc.obj,O,$B\CVTRES.EXE,rsrc.res
6=*.obj,O,$B\UASM64.EXE /c -win64 -Zp8 /win64 /D_WIN64 /Cp /nologo /I"$I",*.asm
7=
11=4,O,$B\RC.EXE /v,1
12=3,O,$B\UASM64.EXE /c -win64 -Zp8 /win64 /D_WIN64 /Cp /nologo /W2 /Zi /Zd /I"$I",2
13=16,O,$B\LINK.EXE /DEBUG /DEBUGTYPE:CV /PDB:"$18" /DRIVER /MACHINE:X64 /SUBSYSTEM:NATIVE /MERGE:"_TEXT=.text;_PAGE=PAGE" /OPT:REF /INCREMENTAL:NO /OPT:ICF /SECTION:INIT|d /LIBPATH:"$L" /out:"$16",3,4
14=0,O,$C\testsign.bat
15=rsrc.obj,O,$B\CVTRES.EXE,rsrc.res
16=*.obj,O,$B\UASM64.EXE /c -win64 -Zp8 /win64 /D_WIN64 /Cp /nologo /W2 /Zi /Zd  /I"$I" *.asm
17=
[MakeFiles]
0=Driver64Template.rap
1=Driver64Template.rc
2=Driver64Template.asm
3=Driver64Template.obj
4=Driver64Template.res
5=Driver64Template.exe
6=Driver64Template.def
7=Driver64Template.dll
8=Driver64Template.txt
9=Driver64Template.lib
10=Driver64Template.mak
11=Driver64Template.inf
12=Driver64Template.com
13=Driver64Template.ocx
14=Driver64Template.idl
15=Driver64Template.tlb
16=Driver64Template.sys
17=Driver64Template.dp32
18=Driver64Template.pdb
19=Driver64Template.dp64
[Resource]
[StringTable]
[Accel]
[VerInf]
Nme=VERINF1
ID=1
FV=1.0.0.0
PV=1.0.0.0
VerOS=0x00000004
VerFT=0x00000003
VerLNG=0x00000409
VerCHS=0x000004B0
ProductVersion=1.0.0.0
ProductName=
OriginalFilename=
LegalTrademarks=
LegalCopyright=
InternalName=
FileDescription=
FileVersion=1.0.0.0
CompanyName=
[Group]
Group=Assembly,Resources,Misc
1=1
2=1
3=2
4=3
5=3
6=2
[*ENDDEF*]
[*BEGINTXT*]
Driver64Template.asm
;==============================================================================
; Driver64Template x64
;
;==============================================================================

.686
.MMX
.XMM
.x64

option casemap : none
option win64 : 11
option frame : auto
option stackbase : rsp
option literals:on ; turn on L"" and dw wide strings
option dotname

_WIN64 EQU 1
WINVER equ 0501h

;------------------------------------------------------------------------------
; Driver64Template Prototypes
;------------------------------------------------------------------------------
OutputDebugString TEXTEQU <OutputDebugStringA>
OutputDebugStringA PROTO :PTR
DbgPrint PROTO :VARARG


include uasmddk.inc

include Driver64Template.inc


;.CODE          ; non-paged code
;.CODE PAGExxx  ; paged code
;.CODE INIT     ; discardable

.CODE


;------------------------------------------------------------------------------
; DriverEntry
;
;------------------------------------------------------------------------------
DriverEntry PROC FRAME USES RBX RCX RDX pDriverObject:PDRIVER_OBJECT, pRegistryPath:PUNICODE_STRING
    LOCAL NtStatus:NTSTATUS
    LOCAL uiIndex:UINT64
    LOCAL pDeviceObject:PDEVICE_OBJECT
    LOCAL usDriverName:UNICODE_STRING
    LOCAL usDosDeviceName:UNICODE_STRING
    
     
    mov NtStatus, STATUS_SUCCESS
    mov uiIndex, 0
    mov pDeviceObject, 0
    Invoke OutputDebugString, "[*] DriverEntry Called - OutputDebugString"
    Invoke DbgPrint, Addr szFmt, "[*] DriverEntry Called - DbgPrint"
    
	Invoke RtlInitUnicodeString, Addr usDriverName, L"\\Device\\MyHypervisorDevice"
	Invoke RtlInitUnicodeString, Addr usDosDeviceName, L"\\DosDevices\\MyHypervisorDevice"
    
	Invoke IoCreateDevice, pDriverObject, 0, Addr usDriverName, FILE_DEVICE_UNKNOWN, FILE_DEVICE_SECURE_OPEN, FALSE, Addr pDeviceObject
    mov NtStatus, eax
	.IF (NtStatus == STATUS_SUCCESS)
	    mov rbx, pDriverObject
	    lea rbx, [rbx].DRIVER_OBJECT.MajorFunction
		.FOR (rcx=0: rcx < IRP_MJ_MAXIMUM_FUNCTION: rcx++) ; rcx = uiIndex
			lea rax, [rbx+rcx*SIZEOF QWORD]
			lea rdx, DrvUnsupported
			mov [rax], rdx
        .ENDFOR
        
		Invoke DbgPrint, Addr szFmt, "[*] Setting Devices major functions."
		mov rbx, pDriverObject
		lea rbx, [rbx].DRIVER_OBJECT.MajorFunction

		lea rax, [rbx+IRP_MJ_CLOSE*SIZEOF QWORD]
		lea rdx, DrvClose
		mov [rax], rdx

		lea rax, [rbx+IRP_MJ_CREATE*SIZEOF QWORD]
		lea rdx, DrvCreate
		mov [rax], rdx

		lea rax, [rbx+IRP_MJ_DEVICE_CONTROL*SIZEOF QWORD]
		lea rdx, DrvIOCTLDispatcher
		mov [rax], rdx

		lea rax, [rbx+IRP_MJ_READ*SIZEOF QWORD]
		lea rdx, DrvRead
		mov [rax], rdx

		lea rax, [rbx+IRP_MJ_WRITE*SIZEOF QWORD]
		lea rdx, DrvWrite
		mov [rax], rdx
		
		mov rbx, pDriverObject
		lea rax, [rbx].DRIVER_OBJECT.DriverUnload
		lea rdx, DrvUnload
		mov [rax], rdx

		Invoke IoCreateSymbolicLink, Addr usDosDeviceName, Addr usDriverName
	.ENDIF   

    mov eax, NtStatus
    ret
DriverEntry ENDP

;------------------------------------------------------------------------------
; DrvUnload
;------------------------------------------------------------------------------
DrvUnload PROC FRAME USES RBX pDriverObject:PDRIVER_OBJECT  
	LOCAL usDosDeviceName:UNICODE_STRING
	
	Invoke DbgPrint, Addr szFmt, "[*] DrvUnload Called."
	Invoke RtlInitUnicodeString, Addr usDosDeviceName, L"\\Device\\MyDriverx64"
	Invoke IoDeleteSymbolicLink, Addr usDosDeviceName
	mov rbx, pDriverObject
	mov rax, [rbx].DRIVER_OBJECT.DeviceObject
	Invoke IoDeleteDevice, rax
	mov eax, STATUS_SUCCESS
	ret	
DrvUnload ENDP

;------------------------------------------------------------------------------
; DrvCreate
;------------------------------------------------------------------------------
DrvCreate PROC FRAME pDeviceObject:PDEVICE_OBJECT, pIrp:PIRP
	Invoke DbgPrint, Addr szFmt, "[*] DrvCreate Operation!"
	mov eax, STATUS_SUCCESS
	ret
DrvCreate ENDP

;------------------------------------------------------------------------------
; DrvRead
;------------------------------------------------------------------------------
DrvRead PROC FRAME pDeviceObject:PDEVICE_OBJECT, pIrp:PIRP
	Invoke DbgPrint, Addr szFmt, "[*] Not implemented yet :( !"
	mov eax, STATUS_SUCCESS
	ret
DrvRead ENDP

;------------------------------------------------------------------------------
; DrvWrite
;------------------------------------------------------------------------------
DrvWrite PROC FRAME pDeviceObject:PDEVICE_OBJECT, pIrp:PIRP
	Invoke DbgPrint, Addr szFmt, "[*] Not implemented yet :( !"
	mov eax, STATUS_SUCCESS
	ret
DrvWrite ENDP

;------------------------------------------------------------------------------
; DrvClose
;------------------------------------------------------------------------------
DrvClose PROC FRAME pDeviceObject:PDEVICE_OBJECT, pIrp:PIRP
	Invoke DbgPrint, Addr szFmt, "[*] Not implemented yet :( !"
	mov eax, STATUS_SUCCESS
	ret
DrvClose ENDP

;------------------------------------------------------------------------------
; DrvUnsupported
;------------------------------------------------------------------------------
DrvUnsupported PROC FRAME pDeviceObject:PDEVICE_OBJECT, pIrp:PIRP
	Invoke DbgPrint, Addr szFmt, "[*] This function is not supported :( !"
	mov eax, STATUS_SUCCESS
	ret
DrvUnsupported ENDP

;------------------------------------------------------------------------------
; DrvIOCTLDispatcher
;------------------------------------------------------------------------------
DrvIOCTLDispatcher PROC FRAME pDeviceObject:PDEVICE_OBJECT, pIrp:PIRP
    mov eax, STATUS_SUCCESS
    ret
DrvIOCTLDispatcher ENDP


END DriverEntry






















[*ENDTXT*]
[*BEGINTXT*]
Driver64Template.inc
;==============================================================================
; Driver64Template x64
;
;==============================================================================


;------------------------------------------------------------------------------
; Driver64Template Prototypes
;------------------------------------------------------------------------------

DriverEntry             PROTO :PDRIVER_OBJECT, :PUNICODE_STRING
DrvUnload               PROTO :PDRIVER_OBJECT
DrvCreate               PROTO :PDEVICE_OBJECT, :PIRP
DrvRead                 PROTO :PDEVICE_OBJECT, :PIRP
DrvWrite                PROTO :PDEVICE_OBJECT, :PIRP
DrvClose                PROTO :PDEVICE_OBJECT, :PIRP
DrvUnsupported          PROTO :PDEVICE_OBJECT, :PIRP
DrvIOCTLDispatcher      PROTO :PDEVICE_OBJECT, :PIRP



;PAGEDAT1 SEGMENT       ; paged data
;PAGEDAT1 ENDS

.DATA                   ; non-paged data
szFmt                   DB "%s",0



[*ENDTXT*]
[*BEGINTXT*]
Driver64Template.inf
;
; Driver64Template.inf
;

[Version]
Signature="$WINDOWS NT$"
Class=Sample ; TODO: edit Class
ClassGuid={78A1C341-4539-11d3-B88D-00C04FAD5171} ; TODO: edit ClassGuid
Provider=%ManufacturerName%
CatalogFile=Driver64Template.cat
DriverVer = 06/09/2018,1.0.0.0

[DestinationDirs]
DefaultDestDir = 12
Driver64Template_Device_CoInstaller_CopyFiles = 11

; ================= Class section =====================

[ClassInstall32]
Addreg=SampleClassReg

[SampleClassReg]
HKR,,,0,%ClassName%
HKR,,Icon,,-5

[SourceDisksNames]
1 = %DiskName%,,,""

[SourceDisksFiles]
Driver64Template.sys  = 1,,
WdfCoInstaller$KMDFCOINSTALLERVERSION$.dll=1 ; make sure the number matches with SourceDisksNames

;*****************************************
; Install Section
;*****************************************

[Manufacturer]
%ManufacturerName%=Standard,NTx86,NTAMD64

[Standard.NT]
%Driver64Template.DeviceDesc%=Driver64Template_Device, Root\Driver64Template ; TODO: edit hw-id

[Driver64Template_Device.NT]
CopyFiles=Drivers_Dir

[Drivers_Dir]
Driver64Template.sys

;-------------- Service installation
[Driver64Template_Device.NT.Services]
AddService = Driver64Template,%SPSVCINST_ASSOCSERVICE%, Driver64Template_Service_Inst

; -------------- Driver64Template driver install sections
[Driver64Template_Service_Inst]
DisplayName    = %Driver64Template.SVCDESC%
ServiceType    = 1               ; SERVICE_KERNEL_DRIVER
StartType      = 3               ; SERVICE_DEMAND_START
ErrorControl   = 1               ; SERVICE_ERROR_NORMAL
ServiceBinary  = %12%\Driver64Template.sys

;
;--- Driver64Template_Device Coinstaller installation ------
;

[Driver64Template_Device.NT.CoInstallers]
AddReg=Driver64Template_Device_CoInstaller_AddReg
CopyFiles=Driver64Template_Device_CoInstaller_CopyFiles

[Driver64Template_Device_CoInstaller_AddReg]
HKR,,CoInstallers32,0x00010000, "WdfCoInstaller$KMDFCOINSTALLERVERSION$.dll,WdfCoInstaller"

[Driver64Template_Device_CoInstaller_CopyFiles]
WdfCoInstaller$KMDFCOINSTALLERVERSION$.dll

[Driver64Template_Device.NT.Wdf]
KmdfService =  Driver64Template, Driver64Template_wdfsect

[Driver64Template_wdfsect]
KmdfLibraryVersion = $KMDFVERSION$

[Strings]
SPSVCINST_ASSOCSERVICE= 0x00000002
ManufacturerName="<Your manufacturer name>" ;TODO: Replace with your manufacturer name
ClassName="Samples" ; TODO: edit ClassName
DiskName = "Driver64Template Installation Disk"
Driver64Template.DeviceDesc = "Driver64Template Device"
Driver64Template.SVCDESC = "Driver64Template Service"
[*ENDTXT*]
[*BEGINTXT*]
Notes.txt
;==============================================================================
; Driver64Template Notes
;
;==============================================================================
Driver Signing:
https://docs.microsoft.com/en-us/windows-hardware/drivers/install/test-signing
https://msfn.org/board/topic/104891-how-can-i-install-a-inf-file-from-the-command-line/

UASM Notes:

String Literal Support

Wide character literal data can now be declared with: awideStr dw "wide caption",0

String literals can be used directly in INVOKE using “” or L””. For a string literal to be accepted as such, the corresponding procedure parameter must be defined as PTR. Any other type will expect a character constant or numerical value. 

String literal support is switched off by default but can be enabled with : OPTION LITERALS:ON

Declaring wide string data with dw will only happen with OPTION LITERALS:ON and using command line switches –Zm or –Zne will disable this.


[*ENDTXT*]
[*BEGINTXT*]
testsign.bat
\UASM\bin\makecert -r -pe -ss PrivateCertStore -n CN="KMDF64 Test" "Driver64Template.cer"
\UASM\bin\stampinf.exe -f "Driver64Template.inf" -d 06/09/2018 -v 1.0.0.0 
\UASM\bin\inf2cat.exe /driver:"M:\radasm\UASM64\Projects\Driver Projects\Driver64Template" /os:"7_x64"
\UASM\bin\signtool sign /v /a /s PrivateCertStore /n "KMDF64 Test" /t http://timestamp.verisign.com/scripts/timstamp.dll "Driver64Template.cat"
\UASM\bin\signtool sign /v /a /s PrivateCertStore /n "KMDF64 Test" /t http://timestamp.verisign.com/scripts/timstamp.dll "Driver64Template.sys"
\UASM\bin\signtool verify /v /kp /c "Driver64Template.cat" "Driver64Template.inf"
\UASM\bin\signtool verify /v /kp "Driver64Template.sys"
[*ENDTXT*]
[*BEGINTXT*]
Driver64Template.rc
#include "Res/Driver64TemplateVer.rc"
[*ENDTXT*]
[*ENDPRO*]
[*BEGINTXT*]
Res\Driver64TemplateVer.rc
#define VERINF1 1
VERINF1 VERSIONINFO
FILEVERSION 1,0,0,0
PRODUCTVERSION 1,0,0,0
FILEOS 0x00000004
FILETYPE 0x00000003
BEGIN
  BLOCK "StringFileInfo"
  BEGIN
    BLOCK "040904B0"
    BEGIN
      VALUE "FileVersion", "1.0.0.0\0"
      VALUE "FileDescription", "[*PROJECTNAME*]\0"
      VALUE "InternalName", "[*PROJECTNAME*]\0"
      VALUE "OriginalFilename", "[*PROJECTNAME*]\0"
      VALUE "ProductName", "[*PROJECTNAME*]\0"
      VALUE "ProductVersion", "1.0.0.0\0"
    END
  END
  BLOCK "VarFileInfo"
  BEGIN
    VALUE "Translation", 0x0409, 0x04B0
  END
END
[*ENDTXT*]
[*BEGINTXT*]
installdriver.bat
rundll32.exe advpack.dll,LaunchINFSectionEx ".\Driver64Template.inf",,,
[*ENDTXT*]