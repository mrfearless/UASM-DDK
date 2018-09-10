;==============================================================================
; UASM-DDK - ntstrsafe.inc
; 
; www.github.com/mrfearless/UASM-DDK by fearless
; 
;==============================================================================

RaiseException PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlAlternateDosPathSeperatorString PROTO C :VARARG
RtlDosPathSeperatorsString PROTO C :VARARG
RtlNtPathSeperatorString PROTO C :VARARG
RtlStringCopyWideCharArrayWorker PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlStringCopyWorkerA PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlStringCopyWorker equ <RtlStringCopyWorkerA>

RtlStringCopyWorkerW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlStringExHandleFillBehindNullA PROTO :QWORD,:QWORD,:QWORD
RtlStringExHandleFillBehindNull equ <RtlStringExHandleFillBehindNullA>

RtlStringExHandleFillBehindNullW PROTO :QWORD,:QWORD,:QWORD
RtlStringExHandleOtherFlagsA PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlStringExHandleOtherFlags equ <RtlStringExHandleOtherFlagsA>

RtlStringExHandleOtherFlagsW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlStringExValidateDestA PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlStringExValidateDest equ <RtlStringExValidateDestA>

RtlStringExValidateDestAndLengthA PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlStringExValidateDestAndLength equ <RtlStringExValidateDestAndLengthA>

RtlStringExValidateDestAndLengthW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlStringExValidateDestW PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlStringExValidateSrcA PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlStringExValidateSrc equ <RtlStringExValidateSrcA>

RtlStringExValidateSrcW PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlStringLengthWorkerA PROTO :QWORD,:QWORD,:QWORD
RtlStringLengthWorker equ <RtlStringLengthWorkerA>

RtlStringLengthWorkerW PROTO :QWORD,:QWORD,:QWORD
RtlStringVPrintfWorkerA PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlStringVPrintfWorker equ <RtlStringVPrintfWorkerA>

RtlStringVPrintfWorkerW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlStringValidateDestA PROTO :QWORD,:QWORD,:QWORD
RtlStringValidateDest equ <RtlStringValidateDestA>

RtlStringValidateDestAndLengthA PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlStringValidateDestAndLength equ <RtlStringValidateDestAndLengthA>

RtlStringValidateDestAndLengthW PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlStringValidateDestW PROTO :QWORD,:QWORD,:QWORD
RtlUnicodeStringExHandleFill PROTO :QWORD,:QWORD,:QWORD
RtlUnicodeStringExHandleOtherFlags PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlUnicodeStringInitWorker PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlUnicodeStringValidateDestWorker PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlUnicodeStringValidateSrcWorker PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlUnicodeStringValidateWorker PROTO :QWORD,:QWORD,:QWORD
RtlWideCharArrayCopyStringWorker PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlWideCharArrayCopyWorker PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlWideCharArrayVPrintfWorker PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD

getwchar PROTO C :VARARG
isalnum PROTO C :VARARG
isalpha PROTO C :VARARG
iscntrl PROTO C :VARARG
isdigit PROTO C :VARARG
isgraph PROTO C :VARARG
isleadbyte PROTO C :VARARG
islower PROTO C :VARARG
isprint PROTO C :VARARG
ispunct PROTO C :VARARG
isspace PROTO C :VARARG
isupper PROTO C :VARARG
iswalnum PROTO C :VARARG
iswalpha PROTO C :VARARG
iswascii PROTO C :VARARG
iswcntrl PROTO C :VARARG
iswctype PROTO C :VARARG
iswdigit PROTO C :VARARG
iswgraph PROTO C :VARARG
iswlower PROTO C :VARARG
iswprint PROTO C :VARARG
iswpunct PROTO C :VARARG
iswspace PROTO C :VARARG
iswupper PROTO C :VARARG
iswxdigit PROTO C :VARARG
isxdigit PROTO C :VARARG

memchr PROTO C :VARARG
memcmp PROTO C :VARARG
memcpy PROTO C :VARARG
memmove PROTO C :VARARG
memset PROTO C :VARARG

sprintf PROTO C :VARARG

sscanf PROTO C :VARARG
strcat PROTO C :VARARG
strchr PROTO C :VARARG
strcmp PROTO C :VARARG
strcoll PROTO C :VARARG
strcpy PROTO C :VARARG
strcspn PROTO C :VARARG
strlen PROTO C :VARARG
strncat PROTO C :VARARG
strncmp PROTO C :VARARG
strncpy PROTO C :VARARG
strnlen PROTO C :VARARG
strpbrk PROTO C :VARARG
strrchr PROTO C :VARARG
strspn PROTO C :VARARG
strstr PROTO C :VARARG
strtod PROTO C :VARARG
strtok PROTO C :VARARG
strtol PROTO C :VARARG
strtolX PROTO C :VARARG
strtoul PROTO C :VARARG
strxfrm PROTO C :VARARG
swprintf PROTO C :VARARG
swscanf PROTO C :VARARG
tolower PROTO C :VARARG
toupper PROTO C :VARARG
towlower PROTO C :VARARG
towupper PROTO C :VARARG
vsprintf PROTO C :VARARG
vswprintf PROTO C :VARARG
wcscat PROTO C :VARARG
wcschr PROTO C :VARARG
wcscmp PROTO C :VARARG
wcscoll PROTO C :VARARG
wcscpy PROTO C :VARARG
wcscspn PROTO C :VARARG
wcslen PROTO C :VARARG
wcsncat PROTO C :VARARG
wcsncmp PROTO C :VARARG
wcsncpy PROTO C :VARARG
wcsnlen PROTO C :VARARG
wcspbrk PROTO C :VARARG
wcsrchr PROTO C :VARARG
wcsspn PROTO C :VARARG
wcsstr PROTO C :VARARG
wcstod PROTO C :VARARG
wcstok PROTO C :VARARG
wcstol PROTO C :VARARG
wcstolX PROTO C :VARARG
wcstombs PROTO C :VARARG
wcstoul PROTO C :VARARG
wcsxfrm PROTO C :VARARG
wctomb PROTO C :VARARG
wctomb_s PROTO C :VARARG
