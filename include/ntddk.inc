;Include file created by h2incX, Version 00.10.00, (C) 2018 Biterider, 2005-2009 Japheth
;Source file: 'A:\SDKs\Windows Kits\10\Include\10.0.17134.0\km\ntddk.h', last modified: 4/10/2018 19:55
;Command line used for creation:  ntddk.h

ifndef _NTDDK_
  _NTDDK_ equ <>
  _NTDDK_INCLUDED_ equ <>
  _DDK_DRIVER_ equ <>
  NT_INCLUDED equ <>





  PBUS_HANDLER typedef ptr _BUS_HANDLER
  PCALLBACK_OBJECT typedef ptr _CALLBACK_OBJECT
  PDEVICE_HANDLER_OBJECT typedef ptr _DEVICE_HANDLER_OBJECT
  
  PEPROCESS typedef ptr _KPROCESS
  ;PETHREAD typedef ptr _ETHREAD
  PKAFFINITY_EX typedef ptr _KAFFINITY_EX

  PEPROCESS typedef ptr _KPROCESS
  PETHREAD typedef ptr _KTHREAD

  ;PEPROCESS typedef ptr _EPROCESS
  ;PETHREAD typedef ptr _ETHREAD

  PEJOB typedef ptr _EJOB
  PESILO typedef ptr _EJOB
  PSILO_MONITOR typedef ptr _SILO_MONITOR

  PIO_TIMER typedef ptr _IO_TIMER
  PKINTERRUPT typedef ptr _KINTERRUPT
  PKTHREAD typedef ptr _KTHREAD
  PRKTHREAD typedef ptr _KTHREAD
  POBJECT_TYPE typedef ptr _OBJECT_TYPE
  PPEB typedef ptr _PEB
  
  PIMAGE_NT_HEADERS32 typedef ptr _IMAGE_NT_HEADERS
  
  PIMAGE_NT_HEADERS64 typedef ptr _IMAGE_NT_HEADERS64
  
  PIMAGE_NT_HEADERS typedef PIMAGE_NT_HEADERS64



    KERNEL_STACK_SIZE equ 6000h
    KERNEL_LARGE_STACK_SIZE equ 12000h
    KERNEL_LARGE_STACK_COMMIT equ <KERNEL_STACK_SIZE>
    KERNEL_MCA_EXCEPTION_STACK_SIZE equ 2000h
    EXCEPTION_READ_FAULT equ 0
    EXCEPTION_WRITE_FAULT equ 1
    EXCEPTION_EXECUTE_FAULT equ 8
    
    CONTEXT_AMD64 equ 00100000h
    CONTEXT_CONTROL equ ( CONTEXT_AMD64 or 00000001h )
    CONTEXT_INTEGER equ ( CONTEXT_AMD64 or 00000002h )
    CONTEXT_SEGMENTS equ ( CONTEXT_AMD64 or 00000004h )
    CONTEXT_FLOATING_POINT equ ( CONTEXT_AMD64 or 00000008h )
    CONTEXT_DEBUG_REGISTERS equ ( CONTEXT_AMD64 or 00000010h )
    CONTEXT_FULL equ <( CONTEXT_CONTROL or CONTEXT_INTEGER or CONTEXT_FLOATING_POINT )>
    CONTEXT_ALL equ <( CONTEXT_CONTROL or CONTEXT_INTEGER or CONTEXT_SEGMENTS or CONTEXT_FLOATING_POINT or CONTEXT_DEBUG_REGISTERS )>
    CONTEXT_XSTATE equ ( CONTEXT_AMD64 or 00000040h )
    
    CONTEXT_KERNEL_DEBUGGER equ 04000000h
    
    CONTEXT_EXCEPTION_ACTIVE equ 08000000h
    CONTEXT_SERVICE_ACTIVE equ 10000000h
    CONTEXT_EXCEPTION_REQUEST equ 40000000h
    CONTEXT_EXCEPTION_REPORTING equ 80000000h
    
    INITIAL_MXCSR equ 1f80h
    INITIAL_FPCSR equ 027fh




  WELL_KNOWN_SID_TYPE typedef SDWORD
  WinNullSid EQU 0 
  WinWorldSid EQU 1 
  WinLocalSid EQU 2 
  WinCreatorOwnerSid EQU 3 
  WinCreatorGroupSid EQU 4 
  WinCreatorOwnerServerSid EQU 5 
  WinCreatorGroupServerSid EQU 6 
  WinNtAuthoritySid EQU 7 
  WinDialupSid EQU 8 
  WinNetworkSid EQU 9 
  WinBatchSid EQU 10 
  WinInteractiveSid EQU 11 
  WinServiceSid EQU 12 
  WinAnonymousSid EQU 13 
  WinProxySid EQU 14 
  WinEnterpriseControllersSid EQU 15 
  WinSelfSid EQU 16 
  WinAuthenticatedUserSid EQU 17 
  WinRestrictedCodeSid EQU 18 
  WinTerminalServerSid EQU 19 
  WinRemoteLogonIdSid EQU 20 
  WinLogonIdsSid EQU 21 
  WinLocalSystemSid EQU 22 
  WinLocalServiceSid EQU 23 
  WinNetworkServiceSid EQU 24 
  WinBuiltinDomainSid EQU 25 
  WinBuiltinAdministratorsSid EQU 26 
  WinBuiltinUsersSid EQU 27 
  WinBuiltinGuestsSid EQU 28 
  WinBuiltinPowerUsersSid EQU 29 
  WinBuiltinAccountOperatorsSid EQU 30 
  WinBuiltinSystemOperatorsSid EQU 31 
  WinBuiltinPrintOperatorsSid EQU 32 
  WinBuiltinBackupOperatorsSid EQU 33 
  WinBuiltinReplicatorSid EQU 34 
  WinBuiltinPreWindows2000CompatibleAccessSid EQU 35 
  WinBuiltinRemoteDesktopUsersSid EQU 36 
  WinBuiltinNetworkConfigurationOperatorsSid EQU 37 
  WinAccountAdministratorSid EQU 38 
  WinAccountGuestSid EQU 39 
  WinAccountKrbtgtSid EQU 40 
  WinAccountDomainAdminsSid EQU 41 
  WinAccountDomainUsersSid EQU 42 
  WinAccountDomainGuestsSid EQU 43 
  WinAccountComputersSid EQU 44 
  WinAccountControllersSid EQU 45 
  WinAccountCertAdminsSid EQU 46 
  WinAccountSchemaAdminsSid EQU 47 
  WinAccountEnterpriseAdminsSid EQU 48 
  WinAccountPolicyAdminsSid EQU 49 
  WinAccountRasAndIasServersSid EQU 50 
  WinNTLMAuthenticationSid EQU 51 
  WinDigestAuthenticationSid EQU 52 
  WinSChannelAuthenticationSid EQU 53 
  WinThisOrganizationSid EQU 54 
  WinOtherOrganizationSid EQU 55 
  WinBuiltinIncomingForestTrustBuildersSid EQU 56 
  WinBuiltinPerfMonitoringUsersSid EQU 57 
  WinBuiltinPerfLoggingUsersSid EQU 58 
  WinBuiltinAuthorizationAccessSid EQU 59 
  WinBuiltinTerminalServerLicenseServersSid EQU 60 
  WinBuiltinDCOMUsersSid EQU 61 
  WinBuiltinIUsersSid EQU 62 
  WinIUserSid EQU 63 
  WinBuiltinCryptoOperatorsSid EQU 64 
  WinUntrustedLabelSid EQU 65 
  WinLowLabelSid EQU 66 
  WinMediumLabelSid EQU 67 
  WinHighLabelSid EQU 68 
  WinSystemLabelSid EQU 69 
  WinWriteRestrictedCodeSid EQU 70 
  WinCreatorOwnerRightsSid EQU 71 
  WinCacheablePrincipalsGroupSid EQU 72 
  WinNonCacheablePrincipalsGroupSid EQU 73 
  WinEnterpriseReadonlyControllersSid EQU 74 
  WinAccountReadonlyControllersSid EQU 75 
  WinBuiltinEventLogReadersGroup EQU 76 
  WinNewEnterpriseReadonlyControllersSid EQU 77 
  WinBuiltinCertSvcDComAccessGroup EQU 78 
  WinMediumPlusLabelSid EQU 79 
  WinLocalLogonSid EQU 80 
  WinConsoleLogonSid EQU 81 
  WinThisOrganizationCertificateSid EQU 82 
  WinApplicationPackageAuthoritySid EQU 83 
  WinBuiltinAnyPackageSid EQU 84 
  WinCapabilityInternetClientSid EQU 85 
  WinCapabilityInternetClientServerSid EQU 86 
  WinCapabilityPrivateNetworkClientServerSid EQU 87 
  WinCapabilityPicturesLibrarySid EQU 88 
  WinCapabilityVideosLibrarySid EQU 89 
  WinCapabilityMusicLibrarySid EQU 90 
  WinCapabilityDocumentsLibrarySid EQU 91 
  WinCapabilitySharedUserCertificatesSid EQU 92 
  WinCapabilityEnterpriseAuthenticationSid EQU 93 
  WinCapabilityRemovableStorageSid EQU 94 
  WinBuiltinRDSRemoteAccessServersSid EQU 95 
  WinBuiltinRDSEndpointServersSid EQU 96 
  WinBuiltinRDSManagementServersSid EQU 97 
  WinUserModeDriversSid EQU 98 
  WinBuiltinHyperVAdminsSid EQU 99 
  WinAccountCloneableControllersSid EQU 100 
  WinBuiltinAccessControlAssistanceOperatorsSid EQU 101 
  WinBuiltinRemoteManagementUsersSid EQU 102 
  WinAuthenticationAuthorityAssertedSid EQU 103 
  WinAuthenticationServiceAssertedSid EQU 104 
  WinLocalAccountSid EQU 105 
  WinLocalAccountAndAdministratorSid EQU 106 
  WinAccountProtectedUsersSid EQU 107 
  WinCapabilityAppointmentsSid EQU 108 
  WinCapabilityContactsSid EQU 109 
  WinAccountDefaultSystemManagedSid EQU 110 
  WinBuiltinDefaultSystemManagedGroupSid EQU 111 
  WinBuiltinStorageReplicaAdminsSid EQU 112 
  WinAccountKeyAdminsSid EQU 113 
  WinAccountEnterpriseKeyAdminsSid EQU 114 
  WinAuthenticationKeyTrustSid EQU 115 
  WinAuthenticationKeyPropertyMFASid EQU 116 
  WinAuthenticationKeyPropertyAttestationSid EQU 117 
  WinAuthenticationFreshKeyAuthSid EQU 118 
  WinBuiltinDeviceOwnersSid EQU 119 
  
  SE_UNSOLICITED_INPUT_PRIVILEGE equ 6
  SE_SIGNING_LEVEL typedef BYTE
  PSE_SIGNING_LEVEL typedef ptr BYTE
  SE_SIGNING_LEVEL_UNCHECKED equ 00000000h
  SE_SIGNING_LEVEL_UNSIGNED equ 00000001h
  SE_SIGNING_LEVEL_ENTERPRISE equ 00000002h
  SE_SIGNING_LEVEL_CUSTOM_1 equ 00000003h
  SE_SIGNING_LEVEL_AUTHENTICODE equ 00000004h
  SE_SIGNING_LEVEL_CUSTOM_2 equ 00000005h
  SE_SIGNING_LEVEL_STORE equ 00000006h
  SE_SIGNING_LEVEL_CUSTOM_3 equ 00000007h
  SE_SIGNING_LEVEL_ANTIMALWARE equ <SE_SIGNING_LEVEL_CUSTOM_3>
  SE_SIGNING_LEVEL_MICROSOFT equ 00000008h
  SE_SIGNING_LEVEL_CUSTOM_4 equ 00000009h
  SE_SIGNING_LEVEL_CUSTOM_5 equ 0000000Ah
  SE_SIGNING_LEVEL_DYNAMIC_CODEGEN equ 0000000Bh
  SE_SIGNING_LEVEL_WINDOWS equ 0000000Ch
  SE_SIGNING_LEVEL_CUSTOM_7 equ 0000000Dh
  SE_SIGNING_LEVEL_WINDOWS_TCB equ 0000000Eh
  SE_SIGNING_LEVEL_CUSTOM_6 equ 0000000Fh
  SE_IMAGE_SIGNATURE_TYPE typedef SDWORD
  SeImageSignatureNone EQU 0 
  SeImageSignatureEmbedded EQU 1
  SeImageSignatureCache EQU 2
  SeImageSignatureCatalogCached EQU 3
  SeImageSignatureCatalogNotCached EQU 4
  SeImageSignatureCatalogHint EQU 5
  SeImageSignaturePackageCatalog EQU 6
  
  PSE_IMAGE_SIGNATURE_TYPE typedef ptr SE_IMAGE_SIGNATURE_TYPE
  
  ifndef _NTLSA_IFS_
    ifndef _NTLSA_AUDIT_
      _NTLSA_AUDIT_ equ <>
      SE_ADT_PARAMETER_TYPE typedef SDWORD
      SeAdtParmTypeNone EQU 0 
      SeAdtParmTypeString EQU 1
      SeAdtParmTypeFileSpec EQU 2
      SeAdtParmTypeUlong EQU 3
      SeAdtParmTypeSid EQU 4
      SeAdtParmTypeLogonId EQU 5
      SeAdtParmTypeNoLogonId EQU 6
      SeAdtParmTypeAccessMask EQU 7
      SeAdtParmTypePrivs EQU 8
      SeAdtParmTypeObjectTypes EQU 9
      SeAdtParmTypeHexUlong EQU 10
      SeAdtParmTypePtr EQU 11
      SeAdtParmTypeTime EQU 12
      SeAdtParmTypeGuid EQU 13
      SeAdtParmTypeLuid EQU 14
      SeAdtParmTypeHexInt64 EQU 15
      SeAdtParmTypeStringList EQU 16
      SeAdtParmTypeSidList EQU 17
      SeAdtParmTypeDuration EQU 18
      SeAdtParmTypeUserAccountControl EQU 19
      SeAdtParmTypeNoUac EQU 20
      SeAdtParmTypeMessage EQU 21
      SeAdtParmTypeDateTime EQU 22
      SeAdtParmTypeSockAddr EQU 23
      SeAdtParmTypeSD EQU 24
      SeAdtParmTypeLogonHours EQU 25
      SeAdtParmTypeLogonIdNoSid EQU 26
      SeAdtParmTypeUlongNoConv EQU 27
      SeAdtParmTypeSockAddrNoPort EQU 28
      SeAdtParmTypeAccessReason EQU 29
      SeAdtParmTypeStagingReason EQU 30
      SeAdtParmTypeResourceAttribute EQU 31
      SeAdtParmTypeClaims EQU 32
      SeAdtParmTypeLogonIdAsSid EQU 33
      SeAdtParmTypeMultiSzString EQU 34
      SeAdtParmTypeLogonIdEx EQU 35
      
      PSE_ADT_PARAMETER_TYPE typedef ptr SE_ADT_PARAMETER_TYPE
      
      ACCESS_MASK typedef DWORD

      SE_ADT_OBJECT_TYPE struct
        ObjectType GUID <>
        Flags WORD ?
        SE_ADT_OBJECT_ONLY equ 1h
        Level WORD ?
        AccessMask ACCESS_MASK ?
      SE_ADT_OBJECT_TYPE ends

      PSE_ADT_OBJECT_TYPE typedef ptr SE_ADT_OBJECT_TYPE
      
      SE_ADT_PARAMETER_ARRAY_ENTRY struct
        Type_ SE_ADT_PARAMETER_TYPE ?
        Length_ DWORD ?
        Data_ ULONG_PTR 2 dup (?)
        Address PVOID ?
      SE_ADT_PARAMETER_ARRAY_ENTRY ends

      PSE_ADT_PARAMETER_ARRAY_ENTRY typedef ptr SE_ADT_PARAMETER_ARRAY_ENTRY
      
      PSECURITY_DESCRIPTOR	typedef	PTR
      
      SE_ADT_ACCESS_REASON struct
        AccessMask ACCESS_MASK ?
        AccessReasons DWORD 32 dup (?)
        ObjectTypeIndex DWORD ?
        AccessGranted DWORD ?
        SecurityDescriptor PSECURITY_DESCRIPTOR ?
      SE_ADT_ACCESS_REASON ends

      PSE_ADT_ACCESS_REASON typedef ptr SE_ADT_ACCESS_REASON
      
      PCLAIMS_BLOB TYPEDEF PTR QWORD
      
      SE_ADT_CLAIMS struct
        Length_ DWORD ?
        Claims PCLAIMS_BLOB ?
      SE_ADT_CLAIMS ends

      PSE_ADT_CLAIMS typedef ptr SE_ADT_CLAIMS
      
      SE_MAX_AUDIT_PARAMETERS equ 32
      SE_MAX_GENERIC_AUDIT_PARAMETERS equ 28
      SE_ADT_PARAMETER_ARRAY struct
        CategoryId DWORD ?
        AuditId DWORD ?
        ParameterCount DWORD ?
        Length_ DWORD ?
        FlatSubCategoryId WORD ?
        Type_ WORD ?
        Flags DWORD ?
        Parameters SE_ADT_PARAMETER_ARRAY_ENTRY SE_MAX_AUDIT_PARAMETERS dup (<>)
      SE_ADT_PARAMETER_ARRAY ends

      PSE_ADT_PARAMETER_ARRAY typedef ptr SE_ADT_PARAMETER_ARRAY
      
      SE_ADT_PARAMETER_ARRAY_EX struct
        CategoryId DWORD ?
        AuditId DWORD ?
        Version DWORD ?
        ParameterCount DWORD ?
        Length_ DWORD ?
        FlatSubCategoryId WORD ?
        Type_ WORD ?
        Flags DWORD ?
        Parameters SE_ADT_PARAMETER_ARRAY_ENTRY SE_MAX_AUDIT_PARAMETERS dup (<>)
      SE_ADT_PARAMETER_ARRAY_EX ends

      PSE_ADT_PARAMETER_ARRAY_EX typedef ptr SE_ADT_PARAMETER_ARRAY_EX
      
      SE_ADT_PARAMETERS_SELF_RELATIVE equ 00000001h
      SE_ADT_PARAMETERS_SEND_TO_LSA equ 00000002h
      SE_ADT_PARAMETER_EXTENSIBLE_AUDIT equ 00000004h
      SE_ADT_PARAMETER_GENERIC_AUDIT equ 00000008h
      SE_ADT_PARAMETER_WRITE_SYNCHRONOUS equ 00000010h
      LSAP_SE_ADT_PARAMETER_ARRAY_TRUE_SIZE macro AuditParameters
       exitm <( sizeof ( SE_ADT_PARAMETER_ARRAY ) - sizeof ( SE_ADT_PARAMETER_ARRAY_ENTRY ) * ( SE_MAX_AUDIT_PARAMETERS - AuditParameters - ParameterCount ) ) >
      endm
    endif
  endif
  ifndef _RTL_RUN_ONCE_DEF
    _RTL_RUN_ONCE_DEF equ <>
    RTL_RUN_ONCE_INIT equ { 0 }
    RTL_RUN_ONCE_CHECK_ONLY equ 00000001h
    RTL_RUN_ONCE_ASYNC equ 00000002h
    RTL_RUN_ONCE_INIT_FAILED equ 00000004h
    RTL_RUN_ONCE_CTX_RESERVED_BITS equ 2
    RTL_RUN_ONCE union
      Ptr_ PVOID ?
    RTL_RUN_ONCE ends

    PRTL_RUN_ONCE typedef ptr RTL_RUN_ONCE
    
    RTL_RUN_ONCE_INIT_FN typedef proto stdcall :PRTL_RUN_ONCE,:PVOID,:ptr PVOID
    PRTL_RUN_ONCE_INIT_FN typedef ptr RTL_RUN_ONCE_INIT_FN
  endif

  TABLE_SEARCH_RESULT typedef SDWORD
  TableEmptyTree EQU 0
  TableFoundNode EQU 1
  TableInsertAsLeft EQU 2
  TableInsertAsRight EQU 3
  
  RTL_GENERIC_COMPARE_RESULTS typedef SDWORD
  GenericLessThan EQU 0
  GenericGreaterThan EQU 1
  GenericEqual EQU 2
  
  RTL_AVL_COMPARE_ROUTINE typedef proto stdcall :ptr _RTL_AVL_TABLE,:PVOID,:PVOID
  PRTL_AVL_COMPARE_ROUTINE typedef ptr RTL_AVL_COMPARE_ROUTINE
  RTL_AVL_ALLOCATE_ROUTINE typedef proto stdcall :ptr _RTL_AVL_TABLE,:CLONG
  PRTL_AVL_ALLOCATE_ROUTINE typedef ptr RTL_AVL_ALLOCATE_ROUTINE
  RTL_AVL_FREE_ROUTINE typedef proto stdcall :ptr _RTL_AVL_TABLE,:PVOID
  PRTL_AVL_FREE_ROUTINE typedef ptr RTL_AVL_FREE_ROUTINE
  RTL_AVL_MATCH_FUNCTION typedef proto stdcall :ptr _RTL_AVL_TABLE,:PVOID,:PVOID
  PRTL_AVL_MATCH_FUNCTION typedef ptr RTL_AVL_MATCH_FUNCTION
  RTL_BALANCED_LINKS struct
    Parent POINTER ?
    LeftChild POINTER ?
    RightChild POINTER ?
    Balance CHAR ?
    Reserved BYTE 3 dup (?)
  RTL_BALANCED_LINKS ends

  PRTL_BALANCED_LINKS typedef ptr RTL_BALANCED_LINKS
  RTL_AVL_TABLE struct
    BalancedRoot RTL_BALANCED_LINKS <>
    OrderedPointer PVOID ?
    WhichOrderedElement DWORD ?
    NumberGenericTableElements DWORD ?
    DepthOfTree DWORD ?
    RestartKey PRTL_BALANCED_LINKS ?
    DeleteCount DWORD ?
    CompareRoutine PRTL_AVL_COMPARE_ROUTINE ?
    AllocateRoutine PRTL_AVL_ALLOCATE_ROUTINE ?
    FreeRoutine PRTL_AVL_FREE_ROUTINE ?
    TableContext PVOID ?
  RTL_AVL_TABLE ends

  PRTL_AVL_TABLE typedef ptr RTL_AVL_TABLE


  ifdef RTL_USE_AVL_TABLES
    PRTL_GENERIC_COMPARE_ROUTINE equ <PRTL_AVL_COMPARE_ROUTINE>
    RTL_GENERIC_COMPARE_ROUTINE equ <RTL_AVL_COMPARE_ROUTINE>
    PRTL_GENERIC_ALLOCATE_ROUTINE equ <PRTL_AVL_ALLOCATE_ROUTINE>
    RTL_GENERIC_ALLOCATE_ROUTINE equ <RTL_AVL_ALLOCATE_ROUTINE>
    PRTL_GENERIC_FREE_ROUTINE equ <PRTL_AVL_FREE_ROUTINE>
    RTL_GENERIC_FREE_ROUTINE equ <RTL_AVL_FREE_ROUTINE>
    RTL_GENERIC_TABLE equ <RTL_AVL_TABLE>
    PRTL_GENERIC_TABLE equ <PRTL_AVL_TABLE>
    RtlInitializeGenericTable equ <RtlInitializeGenericTableAvl>
    RtlInsertElementGenericTable equ <RtlInsertElementGenericTableAvl>
    RtlInsertElementGenericTableFull equ <RtlInsertElementGenericTableFullAvl>
    RtlDeleteElementGenericTable equ <RtlDeleteElementGenericTableAvl>
    RtlLookupElementGenericTable equ <RtlLookupElementGenericTableAvl>
    RtlLookupElementGenericTableFull equ <RtlLookupElementGenericTableFullAvl>
    RtlEnumerateGenericTable equ <RtlEnumerateGenericTableAvl>
    RtlEnumerateGenericTableWithoutSplaying equ <RtlEnumerateGenericTableWithoutSplayingAvl>
    RtlGetElementGenericTable equ <RtlGetElementGenericTableAvl>
    RtlNumberGenericTableElements equ <RtlNumberGenericTableElementsAvl>
    RtlIsGenericTableEmpty equ <RtlIsGenericTableEmptyAvl>
  endif
  RTL_SPLAY_LINKS struct
    Parent POINTER ?
    LeftChild POINTER ?
    RightChild POINTER ?
  RTL_SPLAY_LINKS ends

  PRTL_SPLAY_LINKS typedef ptr RTL_SPLAY_LINKS

  RtlInitializeSplayLinks proto fastcall :PRTL_SPLAY_LINKS

  RtlParent macro Links
   exitm <( ( PRTL_SPLAY_LINKS ) ( Links ) - Parent ) >
  endm
  RtlLeftChild macro Links
   exitm <( ( PRTL_SPLAY_LINKS ) ( Links ) - LeftChild ) >
  endm
  RtlRightChild macro Links
   exitm <( ( PRTL_SPLAY_LINKS ) ( Links ) - RightChild ) >
  endm
  RtlIsRoot macro Links
   exitm <( ( RtlParent ( Links ) == ( PRTL_SPLAY_LINKS ) ( Links ) ) ) >
  endm
  RtlIsLeftChild macro Links
   exitm <( ( RtlLeftChild ( RtlParent ( Links ) ) == ( PRTL_SPLAY_LINKS ) ( Links ) ) ) >
  endm
  RtlIsRightChild macro Links
   exitm <( ( RtlRightChild ( RtlParent ( Links ) ) == ( PRTL_SPLAY_LINKS ) ( Links ) ) ) >
  endm

  RtlInsertAsLeftChild proto fastcall :PRTL_SPLAY_LINKS, :PRTL_SPLAY_LINKS
  RtlInsertAsRightChild proto fastcall :PRTL_SPLAY_LINKS, :PRTL_SPLAY_LINKS



  ifndef RTL_USE_AVL_TABLES
    RTL_GENERIC_COMPARE_ROUTINE typedef proto stdcall :ptr _RTL_GENERIC_TABLE,:PVOID,:PVOID
    PRTL_GENERIC_COMPARE_ROUTINE typedef ptr RTL_GENERIC_COMPARE_ROUTINE
    RTL_GENERIC_ALLOCATE_ROUTINE typedef proto stdcall :ptr _RTL_GENERIC_TABLE,:CLONG
    PRTL_GENERIC_ALLOCATE_ROUTINE typedef ptr RTL_GENERIC_ALLOCATE_ROUTINE
    RTL_GENERIC_FREE_ROUTINE typedef proto stdcall :ptr _RTL_GENERIC_TABLE,:PVOID
    PRTL_GENERIC_FREE_ROUTINE typedef ptr RTL_GENERIC_FREE_ROUTINE
    RTL_GENERIC_TABLE struct
      TableRoot PRTL_SPLAY_LINKS ?
      InsertOrderList LIST_ENTRY <>
      OrderedPointer PLIST_ENTRY ?
      WhichOrderedElement DWORD ?
      NumberGenericTableElements DWORD ?
      CompareRoutine PRTL_GENERIC_COMPARE_ROUTINE ?
      AllocateRoutine PRTL_GENERIC_ALLOCATE_ROUTINE ?
      FreeRoutine PRTL_GENERIC_FREE_ROUTINE ?
      TableContext PVOID ?
    RTL_GENERIC_TABLE ends

    PRTL_GENERIC_TABLE typedef ptr RTL_GENERIC_TABLE

  endif
  RTL_HASH_ALLOCATED_HEADER equ 00000001h
  RTL_HASH_RESERVED_SIGNATURE equ 0
  RTL_DYNAMIC_HASH_TABLE_ENTRY struct
    Linkage LIST_ENTRY <>
    Signature ULONG_PTR ?
  RTL_DYNAMIC_HASH_TABLE_ENTRY ends

  PRTL_DYNAMIC_HASH_TABLE_ENTRY typedef ptr RTL_DYNAMIC_HASH_TABLE_ENTRY
  
  HASH_ENTRY_KEY macro x
   exitm <( ( x ) - Signature ) >
  endm
  RTL_DYNAMIC_HASH_TABLE_CONTEXT struct
    ChainHead PLIST_ENTRY ?
    PrevLinkage PLIST_ENTRY ?
    Signature ULONG_PTR ?
  RTL_DYNAMIC_HASH_TABLE_CONTEXT ends

  PRTL_DYNAMIC_HASH_TABLE_CONTEXT typedef ptr RTL_DYNAMIC_HASH_TABLE_CONTEXT
  
  RTL_DYNAMIC_HASH_TABLE_ENUMERATOR struct
    union
      HashEntry RTL_DYNAMIC_HASH_TABLE_ENTRY <>
      CurEntry PLIST_ENTRY ?
    ends
    ChainHead PLIST_ENTRY ?
    BucketIndex DWORD ?
  RTL_DYNAMIC_HASH_TABLE_ENUMERATOR ends

  PRTL_DYNAMIC_HASH_TABLE_ENUMERATOR typedef ptr RTL_DYNAMIC_HASH_TABLE_ENUMERATOR
  
  RTL_DYNAMIC_HASH_TABLE struct
    Flags DWORD ?
    Shift DWORD ?
    TableSize DWORD ?
    Pivot DWORD ?
    DivisorMask DWORD ?
    NumEntries DWORD ?
    NonEmptyBuckets DWORD ?
    NumEnumerators DWORD ?
    Directory PVOID ?
  RTL_DYNAMIC_HASH_TABLE ends

  PRTL_DYNAMIC_HASH_TABLE typedef ptr RTL_DYNAMIC_HASH_TABLE
  

      RtlInitHashTableContext proto fastcall :PRTL_DYNAMIC_HASH_TABLE_CONTEXT


      RtlInitHashTableContextFromEnumerator proto fastcall :PRTL_DYNAMIC_HASH_TABLE_CONTEXT, :PRTL_DYNAMIC_HASH_TABLE_ENUMERATOR

      RtlReleaseHashTableContext proto fastcall :PRTL_DYNAMIC_HASH_TABLE_CONTEXT

      RtlTotalBucketsHashTable proto fastcall :PRTL_DYNAMIC_HASH_TABLE

      RtlNonEmptyBucketsHashTable proto fastcall :PRTL_DYNAMIC_HASH_TABLE

      RtlEmptyBucketsHashTable proto fastcall :PRTL_DYNAMIC_HASH_TABLE

      RtlTotalEntriesHashTable proto fastcall :PRTL_DYNAMIC_HASH_TABLE

      RtlActiveEnumeratorsHashTable proto fastcall :PRTL_DYNAMIC_HASH_TABLE





    NV_MEMORY_RANGE struct
      BaseAddress POINTER ?
      Length_ SIZE_T ?
    NV_MEMORY_RANGE ends

    PNV_MEMORY_RANGE typedef ptr NV_MEMORY_RANGE
    
    FLUSH_NV_MEMORY_IN_FLAG_NO_DRAIN equ 00000001h
    FLUSH_NV_MEMORY_DEFAULT_TOKEN equ - 1
    proto_RtlGetNonVolatileToken typedef proto stdcall :PVOID, :SIZE_T, :ptr PVOID
    externdef stdcall _imp__RtlGetNonVolatileToken@12: ptr proto_RtlGetNonVolatileToken
    RtlGetNonVolatileToken equ <_imp__RtlGetNonVolatileToken@12>
    proto_RtlFreeNonVolatileToken typedef proto stdcall :PVOID
    externdef stdcall _imp__RtlFreeNonVolatileToken@4: ptr proto_RtlFreeNonVolatileToken
    RtlFreeNonVolatileToken equ <_imp__RtlFreeNonVolatileToken@4>
    proto_RtlFlushNonVolatileMemory typedef proto stdcall :PVOID, :PVOID, :SIZE_T, :DWORD
    externdef stdcall _imp__RtlFlushNonVolatileMemory@16: ptr proto_RtlFlushNonVolatileMemory
    RtlFlushNonVolatileMemory equ <_imp__RtlFlushNonVolatileMemory@16>
    proto_RtlDrainNonVolatileFlush typedef proto stdcall :PVOID
    externdef stdcall _imp__RtlDrainNonVolatileFlush@4: ptr proto_RtlDrainNonVolatileFlush
    RtlDrainNonVolatileFlush equ <_imp__RtlDrainNonVolatileFlush@4>
    proto_RtlWriteNonVolatileMemory typedef proto stdcall :PVOID, :ptr , :ptr , :SIZE_T, :DWORD
    externdef stdcall _imp__RtlWriteNonVolatileMemory@20: ptr proto_RtlWriteNonVolatileMemory
    RtlWriteNonVolatileMemory equ <_imp__RtlWriteNonVolatileMemory@20>
    proto_RtlFlushNonVolatileMemoryRanges typedef proto stdcall :PVOID, :PNV_MEMORY_RANGE, :SIZE_T, :DWORD
    externdef stdcall _imp__RtlFlushNonVolatileMemoryRanges@16: ptr proto_RtlFlushNonVolatileMemoryRanges
    RtlFlushNonVolatileMemoryRanges equ <_imp__RtlFlushNonVolatileMemoryRanges@16>


    RTL_CORRELATION_VECTOR_STRING_LENGTH equ 129
    RTL_CORRELATION_VECTOR_VERSION_1 equ 1
    RTL_CORRELATION_VECTOR_VERSION_2 equ 2
    RTL_CORRELATION_VECTOR_VERSION_CURRENT equ <RTL_CORRELATION_VECTOR_VERSION_2>
    RTL_CORRELATION_VECTOR_V1_PREFIX_LENGTH equ 16
    RTL_CORRELATION_VECTOR_V1_LENGTH equ 64
    RTL_CORRELATION_VECTOR_V2_PREFIX_LENGTH equ 22
    RTL_CORRELATION_VECTOR_V2_LENGTH equ 128
    CORRELATION_VECTOR struct
      Version CHAR ?
      Vector CHAR RTL_CORRELATION_VECTOR_STRING_LENGTH dup (?)
    CORRELATION_VECTOR ends

    PCORRELATION_VECTOR typedef ptr CORRELATION_VECTOR
    TraceLoggingCORRELATION_VECTOR macro cv
     exitm <TraceLoggingString ( ( cv ) .Vector , "__TlgCV__",0 ) >
    endm
    proto_RtlInitializeCorrelationVector typedef proto stdcall :PCORRELATION_VECTOR, :DWORD, :ptr GUID
    externdef stdcall _imp__RtlInitializeCorrelationVector@12: ptr proto_RtlInitializeCorrelationVector
    RtlInitializeCorrelationVector equ <_imp__RtlInitializeCorrelationVector@12>
    proto_RtlIncrementCorrelationVector typedef proto stdcall :PCORRELATION_VECTOR
    externdef stdcall _imp__RtlIncrementCorrelationVector@4: ptr proto_RtlIncrementCorrelationVector
    RtlIncrementCorrelationVector equ <_imp__RtlIncrementCorrelationVector@4>
    proto_RtlExtendCorrelationVector typedef proto stdcall :PCORRELATION_VECTOR
    externdef stdcall _imp__RtlExtendCorrelationVector@4: ptr proto_RtlExtendCorrelationVector
    RtlExtendCorrelationVector equ <_imp__RtlExtendCorrelationVector@4>
    proto_RtlValidateCorrelationVector typedef proto stdcall :PCORRELATION_VECTOR
    externdef stdcall _imp__RtlValidateCorrelationVector@4: ptr proto_RtlValidateCorrelationVector
    RtlValidateCorrelationVector equ <_imp__RtlValidateCorrelationVector@4>


    CUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG struct
      Size_ DWORD ?
      TriggerId PCWSTR ?
    CUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG ends

    PCUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG typedef ptr CUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG
    

      CUSTOM_SYSTEM_EVENT_TRIGGER_INIT proto fastcall :PCUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG, :PCWSTR

    RtlRaiseCustomSystemEventTrigger proto stdcall :PCUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG

  DEVICE_TYPE equ <ULONG>
  FILE_DEVICE_BEEP equ 00000001h
  FILE_DEVICE_CD_ROM equ 00000002h
  FILE_DEVICE_CD_ROM_FILE_SYSTEM equ 00000003h
  FILE_DEVICE_CONTROLLER equ 00000004h
  FILE_DEVICE_DATALINK equ 00000005h
  FILE_DEVICE_DFS equ 00000006h
  FILE_DEVICE_DISK equ 00000007h
  FILE_DEVICE_DISK_FILE_SYSTEM equ 00000008h
  FILE_DEVICE_FILE_SYSTEM equ 00000009h
  FILE_DEVICE_INPORT_PORT equ 0000000ah
  FILE_DEVICE_KEYBOARD equ 0000000bh
  FILE_DEVICE_MAILSLOT equ 0000000ch
  FILE_DEVICE_MIDI_IN equ 0000000dh
  FILE_DEVICE_MIDI_OUT equ 0000000eh
  FILE_DEVICE_MOUSE equ 0000000fh
  FILE_DEVICE_MULTI_UNC_PROVIDER equ 00000010h
  FILE_DEVICE_NAMED_PIPE equ 00000011h
  FILE_DEVICE_NETWORK equ 00000012h
  FILE_DEVICE_NETWORK_BROWSER equ 00000013h
  FILE_DEVICE_NETWORK_FILE_SYSTEM equ 00000014h
  FILE_DEVICE_NULL equ 00000015h
  FILE_DEVICE_PARALLEL_PORT equ 00000016h
  FILE_DEVICE_PHYSICAL_NETCARD equ 00000017h
  FILE_DEVICE_PRINTER equ 00000018h
  FILE_DEVICE_SCANNER equ 00000019h
  FILE_DEVICE_SERIAL_MOUSE_PORT equ 0000001ah
  FILE_DEVICE_SERIAL_PORT equ 0000001bh
  FILE_DEVICE_SCREEN equ 0000001ch
  FILE_DEVICE_SOUND equ 0000001dh
  FILE_DEVICE_STREAMS equ 0000001eh
  FILE_DEVICE_TAPE equ 0000001fh
  FILE_DEVICE_TAPE_FILE_SYSTEM equ 00000020h
  FILE_DEVICE_TRANSPORT equ 00000021h
  FILE_DEVICE_UNKNOWN equ 00000022h
  FILE_DEVICE_VIDEO equ 00000023h
  FILE_DEVICE_VIRTUAL_DISK equ 00000024h
  FILE_DEVICE_WAVE_IN equ 00000025h
  FILE_DEVICE_WAVE_OUT equ 00000026h
  FILE_DEVICE_8042_PORT equ 00000027h
  FILE_DEVICE_NETWORK_REDIRECTOR equ 00000028h
  FILE_DEVICE_BATTERY equ 00000029h
  FILE_DEVICE_BUS_EXTENDER equ 0000002ah
  FILE_DEVICE_MODEM equ 0000002bh
  FILE_DEVICE_VDM equ 0000002ch
  FILE_DEVICE_MASS_STORAGE equ 0000002dh
  FILE_DEVICE_SMB equ 0000002eh
  FILE_DEVICE_KS equ 0000002fh
  FILE_DEVICE_CHANGER equ 00000030h
  FILE_DEVICE_SMARTCARD equ 00000031h
  FILE_DEVICE_ACPI equ 00000032h
  FILE_DEVICE_DVD equ 00000033h
  FILE_DEVICE_FULLSCREEN_VIDEO equ 00000034h
  FILE_DEVICE_DFS_FILE_SYSTEM equ 00000035h
  FILE_DEVICE_DFS_VOLUME equ 00000036h
  FILE_DEVICE_SERENUM equ 00000037h
  FILE_DEVICE_TERMSRV equ 00000038h
  FILE_DEVICE_KSEC equ 00000039h
  FILE_DEVICE_FIPS equ 0000003Ah
  FILE_DEVICE_INFINIBAND equ 0000003Bh
  FILE_DEVICE_VMBUS equ 0000003Eh
  FILE_DEVICE_CRYPT_PROVIDER equ 0000003Fh
  FILE_DEVICE_WPD equ 00000040h
  FILE_DEVICE_BLUETOOTH equ 00000041h
  FILE_DEVICE_MT_COMPOSITE equ 00000042h
  FILE_DEVICE_MT_TRANSPORT equ 00000043h
  FILE_DEVICE_BIOMETRIC equ 00000044h
  FILE_DEVICE_PMI equ 00000045h
  FILE_DEVICE_EHSTOR equ 00000046h
  FILE_DEVICE_DEVAPI equ 00000047h
  FILE_DEVICE_GPIO equ 00000048h
  FILE_DEVICE_USBEX equ 00000049h
  FILE_DEVICE_CONSOLE equ 00000050h
  FILE_DEVICE_NFP equ 00000051h
  FILE_DEVICE_SYSENV equ 00000052h
  FILE_DEVICE_VIRTUAL_BLOCK equ 00000053h
  FILE_DEVICE_POINT_OF_SERVICE equ 00000054h
  FILE_DEVICE_STORAGE_REPLICATION equ 00000055h
  FILE_DEVICE_TRUST_ENV equ 00000056h
  FILE_DEVICE_UCM equ 00000057h
  FILE_DEVICE_UCMTCPCI equ 00000058h
  FILE_DEVICE_PERSISTENT_MEMORY equ 00000059h
  FILE_DEVICE_NVDIMM equ 0000005ah
  FILE_DEVICE_HOLOGRAPHIC equ 0000005bh
  FILE_DEVICE_SDFXHCI equ 0000005ch
  CTL_CODE macro DeviceType,Function,Method,Access
   exitm <( ( ( DeviceType ) shl 16 ) or ( ( Access ) shl 14 ) or ( ( Function ) shl 2 ) or ( Method ) ) >
  endm
  DEVICE_TYPE_FROM_CTL_CODE macro ctrlCode
   exitm <( ( ( ctrlCode and 0ffff0000h ) ) shr 16 ) >
  endm
  METHOD_FROM_CTL_CODE macro ctrlCode
   exitm <( ( ctrlCode and 3 ) ) >
  endm
  METHOD_BUFFERED equ 0
  METHOD_IN_DIRECT equ 1
  METHOD_OUT_DIRECT equ 2
  METHOD_NEITHER equ 3
  METHOD_DIRECT_TO_HARDWARE equ <METHOD_IN_DIRECT>
  METHOD_DIRECT_FROM_HARDWARE equ <METHOD_OUT_DIRECT>
  FILE_ANY_ACCESS equ 0
  FILE_SPECIAL_ACCESS equ <( FILE_ANY_ACCESS )>
  FILE_READ_ACCESS equ 0001h
  FILE_WRITE_ACCESS equ 0002h

    FILE_CHARACTERISTICS_EXPECT_ORDERLY_REMOVAL_EX equ 00004000h
    FILE_CHARACTERISTICS_EXPECT_SURPRISE_REMOVAL_EX equ 00008000h
    FILE_CHARACTERISTICS_REMOVAL_POLICY_MASK_EX equ <( FILE_CHARACTERISTICS_EXPECT_ORDERLY_REMOVAL_EX or FILE_CHARACTERISTICS_EXPECT_SURPRISE_REMOVAL_EX )>
    FILE_CHARACTERISTICS_EXPECT_ORDERLY_REMOVAL_DEPRECATED equ 00000200h
    FILE_CHARACTERISTICS_EXPECT_SURPRISE_REMOVAL_DEPRECATED equ 00000300h
    FILE_CHARACTERISTICS_REMOVAL_POLICY_MASK_DEPRECATED equ 00000300h

  FILE_CHARACTERISTICS_PROPAGATED equ <( FILE_REMOVABLE_MEDIA or FILE_READ_ONLY_DEVICE or FILE_FLOPPY_DISKETTE or FILE_WRITE_ONCE_MEDIA or FILE_DEVICE_SECURE_OPEN or FILE_CHARACTERISTIC_CSV or FILE_PORTABLE_DEVICE )>
  FILE_ALIGNMENT_INFORMATION struct
    AlignmentRequirement DWORD ?
  FILE_ALIGNMENT_INFORMATION ends

  PFILE_ALIGNMENT_INFORMATION typedef ptr FILE_ALIGNMENT_INFORMATION
  
  FILE_NAME_INFORMATION struct
    FileNameLength DWORD ?
    FileName WCHAR 1 dup (?)
  FILE_NAME_INFORMATION ends

  PFILE_NAME_INFORMATION typedef ptr FILE_NAME_INFORMATION
  
  FILE_ATTRIBUTE_TAG_INFORMATION struct
    FileAttributes DWORD ?
    ReparseTag DWORD ?
  FILE_ATTRIBUTE_TAG_INFORMATION ends

  PFILE_ATTRIBUTE_TAG_INFORMATION typedef ptr FILE_ATTRIBUTE_TAG_INFORMATION
  
  FILE_DISPOSITION_INFORMATION struct
    DeleteFile BOOLEAN ?
  FILE_DISPOSITION_INFORMATION ends

  PFILE_DISPOSITION_INFORMATION typedef ptr FILE_DISPOSITION_INFORMATION

    FILE_DISPOSITION_DO_NOT_DELETE equ 00000000h
    FILE_DISPOSITION_DELETE equ 00000001h
    FILE_DISPOSITION_POSIX_SEMANTICS equ 00000002h
    FILE_DISPOSITION_FORCE_IMAGE_SECTION_CHECK equ 00000004h
    FILE_DISPOSITION_ON_CLOSE equ 00000008h
    FILE_DISPOSITION_INFORMATION_EX struct
      Flags DWORD ?
    FILE_DISPOSITION_INFORMATION_EX ends

    PFILE_DISPOSITION_INFORMATION_EX typedef ptr FILE_DISPOSITION_INFORMATION_EX

  FILE_END_OF_FILE_INFORMATION struct
    EndOfFile LARGE_INTEGER <>
  FILE_END_OF_FILE_INFORMATION ends

  PFILE_END_OF_FILE_INFORMATION typedef ptr FILE_END_OF_FILE_INFORMATION
  
  FILE_VALID_DATA_LENGTH_INFORMATION struct
    ValidDataLength LARGE_INTEGER <>
  FILE_VALID_DATA_LENGTH_INFORMATION ends

  PFILE_VALID_DATA_LENGTH_INFORMATION typedef ptr FILE_VALID_DATA_LENGTH_INFORMATION
  
  FILE_FS_LABEL_INFORMATION struct
    VolumeLabelLength DWORD ?
    VolumeLabel WCHAR 1 dup (?)
  FILE_FS_LABEL_INFORMATION ends

  PFILE_FS_LABEL_INFORMATION typedef ptr FILE_FS_LABEL_INFORMATION
  
  FILE_FS_VOLUME_INFORMATION struct
    VolumeCreationTime LARGE_INTEGER <>
    VolumeSerialNumber DWORD ?
    VolumeLabelLength DWORD ?
    SupportsObjects BOOLEAN ?
    VolumeLabel WCHAR 1 dup (?)
  FILE_FS_VOLUME_INFORMATION ends

  PFILE_FS_VOLUME_INFORMATION typedef ptr FILE_FS_VOLUME_INFORMATION
  
  FILE_FS_SIZE_INFORMATION struct
    TotalAllocationUnits LARGE_INTEGER <>
    AvailableAllocationUnits LARGE_INTEGER <>
    SectorsPerAllocationUnit DWORD ?
    BytesPerSector DWORD ?
  FILE_FS_SIZE_INFORMATION ends

  PFILE_FS_SIZE_INFORMATION typedef ptr FILE_FS_SIZE_INFORMATION
  
  FILE_FS_FULL_SIZE_INFORMATION struct
    TotalAllocationUnits LARGE_INTEGER <>
    CallerAvailableAllocationUnits LARGE_INTEGER <>
    ActualAvailableAllocationUnits LARGE_INTEGER <>
    SectorsPerAllocationUnit DWORD ?
    BytesPerSector DWORD ?
  FILE_FS_FULL_SIZE_INFORMATION ends

  PFILE_FS_FULL_SIZE_INFORMATION typedef ptr FILE_FS_FULL_SIZE_INFORMATION
  

    FILE_FS_METADATA_SIZE_INFORMATION struct
      TotalMetadataAllocationUnits LARGE_INTEGER <>
      SectorsPerAllocationUnit DWORD ?
      BytesPerSector DWORD ?
    FILE_FS_METADATA_SIZE_INFORMATION ends

    PFILE_FS_METADATA_SIZE_INFORMATION typedef ptr FILE_FS_METADATA_SIZE_INFORMATION

  SSINFO_FLAGS_ALIGNED_DEVICE equ 00000001h
  SSINFO_FLAGS_PARTITION_ALIGNED_ON_DEVICE equ 00000002h
  SSINFO_FLAGS_NO_SEEK_PENALTY equ 00000004h
  SSINFO_FLAGS_TRIM_ENABLED equ 00000008h
  SSINFO_FLAGS_BYTE_ADDRESSABLE equ 00000010h
  SSINFO_OFFSET_UNKNOWN equ 0ffffffffh
  FILE_FS_SECTOR_SIZE_INFORMATION struct
    LogicalBytesPerSector DWORD ?
    PhysicalBytesPerSectorForAtomicity DWORD ?
    PhysicalBytesPerSectorForPerformance DWORD ?
    FileSystemEffectivePhysicalBytesPerSectorForAtomicity DWORD ?
    Flags DWORD ?
    ByteOffsetForSectorAlignment DWORD ?
    ByteOffsetForPartitionAlignment DWORD ?
  FILE_FS_SECTOR_SIZE_INFORMATION ends

  PFILE_FS_SECTOR_SIZE_INFORMATION typedef ptr FILE_FS_SECTOR_SIZE_INFORMATION
  
  FILE_FS_OBJECTID_INFORMATION struct
    ObjectId BYTE 16 dup (?)
    ExtendedInfo BYTE 48 dup (?)
  FILE_FS_OBJECTID_INFORMATION ends

  PFILE_FS_OBJECTID_INFORMATION typedef ptr FILE_FS_OBJECTID_INFORMATION
  
  IOCTL_AVIO_ALLOCATE_STREAM equ CTL_CODE ( FILE_DEVICE_AVIO , 1 , METHOD_BUFFERED , FILE_SPECIAL_ACCESS )
  IOCTL_AVIO_FREE_STREAM equ CTL_CODE ( FILE_DEVICE_AVIO , 2 , METHOD_BUFFERED , FILE_SPECIAL_ACCESS )
  IOCTL_AVIO_MODIFY_STREAM equ CTL_CODE ( FILE_DEVICE_AVIO , 3 , METHOD_BUFFERED , FILE_SPECIAL_ACCESS )
  BUS_DATA_TYPE typedef SDWORD
  ConfigurationSpaceUndefined EQU - 1 
  Cmos EQU 2
  EisaConfiguration EQU 3
  Pos EQU 4
  CbusConfiguration EQU 5
  PCIConfiguration EQU 6
  VMEConfiguration EQU 7
  NuBusConfiguration EQU 8
  PCMCIAConfiguration EQU 9
  MPIConfiguration EQU 10
  MPSAConfiguration EQU 11
  PNPISAConfiguration EQU 12
  SgiInternalConfiguration EQU 13
  MaximumBusDataType EQU 14
  
  PBUS_DATA_TYPE typedef ptr BUS_DATA_TYPE
  
  KEY_NAME_INFORMATION struct
    NameLength DWORD ?
    Name_ WCHAR 1 dup (?)
  KEY_NAME_INFORMATION ends

  PKEY_NAME_INFORMATION typedef ptr KEY_NAME_INFORMATION
  
  KEY_CACHED_INFORMATION struct
    LastWriteTime LARGE_INTEGER <>
    TitleIndex DWORD ?
    SubKeys DWORD ?
    MaxNameLen DWORD ?
    Values DWORD ?
    MaxValueNameLen DWORD ?
    MaxValueDataLen DWORD ?
    NameLength DWORD ?
  KEY_CACHED_INFORMATION ends

  PKEY_CACHED_INFORMATION typedef ptr KEY_CACHED_INFORMATION
  
  KEY_VIRTUALIZATION_INFORMATION struct
    KEY_VIRTUALIZATION_INFORMATION_??0 record VirtualizationCandidate_??0:1, VirtualizationEnabled_??0:1, VirtualTarget_??0:1, VirtualStore_??0:1, VirtualSource_??0:1, Reserved_??0:27
    KEY_VIRTUALIZATION_INFORMATION_??0 <>
  KEY_VIRTUALIZATION_INFORMATION ends

  PKEY_VIRTUALIZATION_INFORMATION typedef ptr KEY_VIRTUALIZATION_INFORMATION
  
  KEY_LAYER_INFORMATION struct
    KEY_LAYER_INFORMATION_??1 record IsTombstone_??1:1, IsSupersedeLocal_??1:1, IsSupersedeTree_??1:1, ClassIsInherited_??1:1, Reserved_??1:28
    KEY_LAYER_INFORMATION_??1 <>
  KEY_LAYER_INFORMATION ends

  PKEY_LAYER_INFORMATION typedef ptr KEY_LAYER_INFORMATION
  
  EXCEPTION_REGISTRATION_RECORD struct
    Next POINTER ?
    Handler PEXCEPTION_ROUTINE ?
  EXCEPTION_REGISTRATION_RECORD ends

  PEXCEPTION_REGISTRATION_RECORD typedef ptr EXCEPTION_REGISTRATION_RECORD
  NT_TIB struct
    ExceptionList POINTER ?
    StackBase PVOID ?
    StackLimit PVOID ?
    SubSystemTib PVOID ?
      FiberData PVOID ?
    ArbitraryUserPointer PVOID ?
    Self POINTER ?
  NT_TIB ends

  PNT_TIB typedef ptr NT_TIB
  NT_TIB32 struct
    ExceptionList DWORD ?
    StackBase DWORD ?
    StackLimit DWORD ?
    SubSystemTib DWORD ?
      FiberData DWORD ?
    ArbitraryUserPointer DWORD ?
    Self DWORD ?
  NT_TIB32 ends

  PNT_TIB32 typedef ptr NT_TIB32
  
  NT_TIB64 struct
    ExceptionList ULONG64 ?
    StackBase ULONG64 ?
    StackLimit ULONG64 ?
    SubSystemTib ULONG64 ?
      FiberData ULONG64 ?
    ArbitraryUserPointer ULONG64 ?
    Self ULONG64 ?
  NT_TIB64 ends

  PNT_TIB64 typedef ptr NT_TIB64
  
  PROCESSINFOCLASS typedef SDWORD
  ProcessBasicInformation EQU 0 
  ProcessQuotaLimits EQU 1 
  ProcessIoCounters EQU 2 
  ProcessVmCounters EQU 3 
  ProcessTimes EQU 4 
  ProcessBasePriority EQU 5 
  ProcessRaisePriority EQU 6 
  ProcessDebugPort EQU 7 
  ProcessExceptionPort EQU 8 
  ProcessAccessToken EQU 9 
  ProcessLdtInformation EQU 10 
  ProcessLdtSize EQU 11 
  ProcessDefaultHardErrorMode EQU 12 
  ProcessIoPortHandlers EQU 13 
  ProcessPooledUsageAndLimits EQU 14 
  ProcessWorkingSetWatch EQU 15 
  ProcessUserModeIOPL EQU 16 
  ProcessEnableAlignmentFaultFixup EQU 17 
  ProcessPriorityClass EQU 18 
  ProcessWx86Information EQU 19 
  ProcessHandleCount EQU 20 
  ProcessAffinityMask EQU 21 
  ProcessPriorityBoost EQU 22 
  ProcessDeviceMap EQU 23 
  ProcessSessionInformation EQU 24 
  ProcessForegroundInformation EQU 25 
  ProcessWow64Information EQU 26 
  ProcessImageFileName EQU 27 
  ProcessLUIDDeviceMapsEnabled EQU 28 
  ProcessBreakOnTermination EQU 29 
  ProcessDebugObjectHandle EQU 30 
  ProcessDebugFlags EQU 31 
  ProcessHandleTracing EQU 32 
  ProcessIoPriority EQU 33 
  ProcessExecuteFlags EQU 34 
  ProcessTlsInformation EQU 35 
  ProcessCookie EQU 36 
  ProcessImageInformation EQU 37 
  ProcessCycleTime EQU 38 
  ProcessPagePriority EQU 39 
  ProcessInstrumentationCallback EQU 40 
  ProcessThreadStackAllocation EQU 41 
  ProcessWorkingSetWatchEx EQU 42 
  ProcessImageFileNameWin32 EQU 43 
  ProcessImageFileMapping EQU 44 
  ProcessAffinityUpdateMode EQU 45 
  ProcessMemoryAllocationMode EQU 46 
  ProcessGroupInformation EQU 47 
  ProcessTokenVirtualizationEnabled EQU 48 
  ProcessOwnerInformation EQU 49 
  ProcessWindowInformation EQU 50 
  ProcessHandleInformation EQU 51 
  ProcessMitigationPolicy EQU 52 
  ProcessDynamicFunctionTableInformation EQU 53 
  ProcessHandleCheckingMode EQU 54 
  ProcessKeepAliveCount EQU 55 
  ProcessRevokeFileHandles EQU 56 
  ProcessWorkingSetControl EQU 57 
  ProcessHandleTable EQU 58 
  ProcessCheckStackExtentsMode EQU 59 
  ProcessCommandLineInformation EQU 60 
  ProcessProtectionInformation EQU 61 
  ProcessMemoryExhaustion EQU 62 
  ProcessFaultInformation EQU 63 
  ProcessTelemetryIdInformation EQU 64 
  ProcessCommitReleaseInformation EQU 65 
  ProcessReserved1Information EQU 66 
  ProcessReserved2Information EQU 67 
  ProcessSubsystemProcess EQU 68 
  ProcessInPrivate EQU 70 
  ProcessRaiseUMExceptionOnInvalidHandleClose EQU 71 
  ProcessSubsystemInformation EQU 75 
  ProcessWin32kSyscallFilterInformation EQU 79 
  ProcessEnergyTrackingState EQU 82 
  MaxProcessInfoClass EQU 83
  
  THREADINFOCLASS typedef SDWORD
  ThreadBasicInformation EQU 0 
  ThreadTimes EQU 1 
  ThreadPriority EQU 2 
  ThreadBasePriority EQU 3 
  ThreadAffinityMask EQU 4 
  ThreadImpersonationToken EQU 5 
  ThreadDescriptorTableEntry EQU 6 
  ThreadEnableAlignmentFaultFixup EQU 7 
  ThreadEventPair_Reusable EQU 8 
  ThreadQuerySetWin32StartAddress EQU 9 
  ThreadZeroTlsCell EQU 10 
  ThreadPerformanceCount EQU 11 
  ThreadAmILastThread EQU 12 
  ThreadIdealProcessor EQU 13 
  ThreadPriorityBoost EQU 14 
  ThreadSetTlsArrayAddress EQU 15 
  ThreadIsIoPending EQU 16 
  ThreadHideFromDebugger EQU 17 
  ThreadBreakOnTermination EQU 18 
  ThreadSwitchLegacyState EQU 19 
  ThreadIsTerminated EQU 20 
  ThreadLastSystemCall EQU 21 
  ThreadIoPriority EQU 22 
  ThreadCycleTime EQU 23 
  ThreadPagePriority EQU 24 
  ThreadActualBasePriority EQU 25 
  ThreadTebInformation EQU 26 
  ThreadCSwitchMon EQU 27 
  ThreadCSwitchPmu EQU 28 
  ThreadWow64Context EQU 29 
  ThreadGroupInformation EQU 30 
  ThreadUmsInformation EQU 31 
  ThreadCounterProfiling EQU 32 
  ThreadIdealProcessorEx EQU 33 
  ThreadCpuAccountingInformation EQU 34 
  ThreadSuspendCount EQU 35 
  ThreadActualGroupAffinity EQU 41 
  ThreadDynamicCodePolicyInfo EQU 42 
  ThreadSubsystemInformation EQU 45 
  MaxThreadInfoClass EQU 50 
  
  THREAD_CSWITCH_PMU_DISABLE equ <FALSE>
  THREAD_CSWITCH_PMU_ENABLE equ <TRUE>
  MEMORY_PRIORITY_LOWEST equ 0
  MEMORY_PRIORITY_VERY_LOW equ 1
  MEMORY_PRIORITY_LOW equ 2
  MEMORY_PRIORITY_MEDIUM equ 3
  MEMORY_PRIORITY_BELOW_NORMAL equ 4
  MEMORY_PRIORITY_NORMAL equ 5
  PAGE_PRIORITY_INFORMATION struct
    PagePriority DWORD ?
  PAGE_PRIORITY_INFORMATION ends

  PPAGE_PRIORITY_INFORMATION typedef ptr PAGE_PRIORITY_INFORMATION
  
  PROCESS_WS_WATCH_INFORMATION struct
    FaultingPc PVOID ?
    FaultingVa PVOID ?
  PROCESS_WS_WATCH_INFORMATION ends

  PPROCESS_WS_WATCH_INFORMATION typedef ptr PROCESS_WS_WATCH_INFORMATION
  
  KPRIORITY typedef SDWORD
  
  PROCESS_BASIC_INFORMATION struct
    ExitStatus NTSTATUS ?
    PebBaseAddress PPEB ?
    AffinityMask ULONG_PTR ?
    BasePriority KPRIORITY ?
    UniqueProcessId ULONG_PTR ?
    InheritedFromUniqueProcessId ULONG_PTR ?
  PROCESS_BASIC_INFORMATION ends

  PPROCESS_BASIC_INFORMATION typedef ptr PROCESS_BASIC_INFORMATION
  
  PROCESS_EXTENDED_BASIC_INFORMATION struct
    Size_ SIZE_T ?
    BasicInfo PROCESS_BASIC_INFORMATION <>
    union DUMMYUNIONNAME_6
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_7
        DUMMYSTRUCTNAME_7_??2 record IsProtectedProcess_??2:1, IsWow64Process_??2:1, IsProcessDeleting_??2:1, IsCrossSessionCreate_??2:1, IsFrozen_??2:1, IsBackground_??2:1, IsStronglyNamed_??2:1, IsSecureProcess_??2:1, IsSubsystemProcess_??2:1, SpareBits_??2:23
        DUMMYSTRUCTNAME_7_??2 <>
      ends
    ends
  PROCESS_EXTENDED_BASIC_INFORMATION ends

  PPROCESS_EXTENDED_BASIC_INFORMATION typedef ptr PROCESS_EXTENDED_BASIC_INFORMATION
  
  PROCESS_DEVICEMAP_INFORMATION struct
    union DUMMYUNIONNAME_8
      struct Set
        DirectoryHandle HANDLE ?
      ends
      struct Query
        DriveMap DWORD ?
        DriveType BYTE 32 dup (?)
      ends
    ends
  PROCESS_DEVICEMAP_INFORMATION ends

  PPROCESS_DEVICEMAP_INFORMATION typedef ptr PROCESS_DEVICEMAP_INFORMATION
  
  PROCESS_DEVICEMAP_INFORMATION_EX struct
    union DUMMYUNIONNAME_9
      struct Set
        DirectoryHandle HANDLE ?
      ends
      struct Query
        DriveMap DWORD ?
        DriveType BYTE 32 dup (?)
      ends
    ends
    Flags DWORD ?
  PROCESS_DEVICEMAP_INFORMATION_EX ends

  PPROCESS_DEVICEMAP_INFORMATION_EX typedef ptr PROCESS_DEVICEMAP_INFORMATION_EX
  
  PROCESS_LUID_DOSDEVICES_ONLY equ 00000001h
  PROCESS_SESSION_INFORMATION struct
    SessionId DWORD ?
  PROCESS_SESSION_INFORMATION ends

  PPROCESS_SESSION_INFORMATION typedef ptr PROCESS_SESSION_INFORMATION
  
  PROCESS_HANDLE_TRACING_ENABLE struct
    Flags DWORD ?
  PROCESS_HANDLE_TRACING_ENABLE ends

  PPROCESS_HANDLE_TRACING_ENABLE typedef ptr PROCESS_HANDLE_TRACING_ENABLE
  
  PROCESS_HANDLE_TRACING_ENABLE_EX struct
    Flags DWORD ?
    TotalSlots DWORD ?
  PROCESS_HANDLE_TRACING_ENABLE_EX ends

  PPROCESS_HANDLE_TRACING_ENABLE_EX typedef ptr PROCESS_HANDLE_TRACING_ENABLE_EX

CLIENT_ID STRUCT
	UniqueProcess	QWORD	?
	UniqueThread	QWORD	?
CLIENT_ID ENDS
PCLIENT_ID typedef PTR CLIENT_ID
  
  PROCESS_HANDLE_EXCEPTIONS_ENABLED equ 00000001h
  PROCESS_HANDLE_RAISE_UM_EXCEPTION_ON_INVALID_HANDLE_CLOSE_DISABLED equ 00000000h
  PROCESS_HANDLE_RAISE_UM_EXCEPTION_ON_INVALID_HANDLE_CLOSE_ENABLED equ 00000001h
  PROCESS_HANDLE_TRACING_MAX_STACKS equ 16
  PROCESS_HANDLE_TRACING_ENTRY struct
    Handle HANDLE ?
    ClientId CLIENT_ID <>
    Type_ DWORD ?
    Stacks PVOID PROCESS_HANDLE_TRACING_MAX_STACKS dup (?)
  PROCESS_HANDLE_TRACING_ENTRY ends

  PPROCESS_HANDLE_TRACING_ENTRY typedef ptr PROCESS_HANDLE_TRACING_ENTRY
  
  PROCESS_HANDLE_TRACING_QUERY struct
    Handle HANDLE ?
    TotalTraces DWORD ?
    HandleTrace PROCESS_HANDLE_TRACING_ENTRY 1 dup (<>)
  PROCESS_HANDLE_TRACING_QUERY ends

  PPROCESS_HANDLE_TRACING_QUERY typedef ptr PROCESS_HANDLE_TRACING_QUERY
  
  QUOTA_LIMITS struct
    PagedPoolLimit SIZE_T ?
    NonPagedPoolLimit SIZE_T ?
    MinimumWorkingSetSize SIZE_T ?
    MaximumWorkingSetSize SIZE_T ?
    PagefileLimit SIZE_T ?
    TimeLimit LARGE_INTEGER <>
  QUOTA_LIMITS ends

  PQUOTA_LIMITS typedef ptr QUOTA_LIMITS
  
  QUOTA_LIMITS_HARDWS_MIN_ENABLE equ 00000001h
  QUOTA_LIMITS_HARDWS_MIN_DISABLE equ 00000002h
  QUOTA_LIMITS_HARDWS_MAX_ENABLE equ 00000004h
  QUOTA_LIMITS_HARDWS_MAX_DISABLE equ 00000008h
  QUOTA_LIMITS_USE_DEFAULT_LIMITS equ 00000010h
  RATE_QUOTA_LIMIT union
    RateData DWORD ?
    struct DUMMYSTRUCTNAME_10
      DUMMYSTRUCTNAME_10_??3 record RatePercent_??3:7, Reserved0_??3:25
      DUMMYSTRUCTNAME_10_??3 <>
    ends
  RATE_QUOTA_LIMIT ends

  PRATE_QUOTA_LIMIT typedef ptr RATE_QUOTA_LIMIT
  
  QUOTA_LIMITS_EX struct
    PagedPoolLimit SIZE_T ?
    NonPagedPoolLimit SIZE_T ?
    MinimumWorkingSetSize SIZE_T ?
    MaximumWorkingSetSize SIZE_T ?
    PagefileLimit SIZE_T ?
    TimeLimit LARGE_INTEGER <>
    WorkingSetLimit SIZE_T ?
    Reserved2 SIZE_T ?
    Reserved3 SIZE_T ?
    Reserved4 SIZE_T ?
    Flags DWORD ?
    CpuRateLimit RATE_QUOTA_LIMIT <>
  QUOTA_LIMITS_EX ends

  PQUOTA_LIMITS_EX typedef ptr QUOTA_LIMITS_EX
  
  IO_COUNTERS struct
    ReadOperationCount QWORD ?
    WriteOperationCount QWORD ?
    OtherOperationCount QWORD ?
    ReadTransferCount QWORD ?
    WriteTransferCount QWORD ?
    OtherTransferCount QWORD ?
  IO_COUNTERS ends

  PIO_COUNTERS typedef ptr IO_COUNTERS
  VM_COUNTERS struct
    PeakVirtualSize SIZE_T ?
    VirtualSize SIZE_T ?
    PageFaultCount DWORD ?
    PeakWorkingSetSize SIZE_T ?
    WorkingSetSize SIZE_T ?
    QuotaPeakPagedPoolUsage SIZE_T ?
    QuotaPagedPoolUsage SIZE_T ?
    QuotaPeakNonPagedPoolUsage SIZE_T ?
    QuotaNonPagedPoolUsage SIZE_T ?
    PagefileUsage SIZE_T ?
    PeakPagefileUsage SIZE_T ?
  VM_COUNTERS ends

  PVM_COUNTERS typedef ptr VM_COUNTERS
  VM_COUNTERS_EX struct
    PeakVirtualSize SIZE_T ?
    VirtualSize SIZE_T ?
    PageFaultCount DWORD ?
    PeakWorkingSetSize SIZE_T ?
    WorkingSetSize SIZE_T ?
    QuotaPeakPagedPoolUsage SIZE_T ?
    QuotaPagedPoolUsage SIZE_T ?
    QuotaPeakNonPagedPoolUsage SIZE_T ?
    QuotaNonPagedPoolUsage SIZE_T ?
    PagefileUsage SIZE_T ?
    PeakPagefileUsage SIZE_T ?
    PrivateUsage SIZE_T ?
  VM_COUNTERS_EX ends

  PVM_COUNTERS_EX typedef ptr VM_COUNTERS_EX
  VM_COUNTERS_EX2 struct
    CountersEx VM_COUNTERS_EX <>
    PrivateWorkingSetSize SIZE_T ?
    SharedCommitUsage QWORD ?
  VM_COUNTERS_EX2 ends

  PVM_COUNTERS_EX2 typedef ptr VM_COUNTERS_EX2
  
  MAX_HW_COUNTERS equ 16
  THREAD_PROFILING_FLAG_DISPATCH equ 00000001h
  HARDWARE_COUNTER_TYPE typedef SDWORD
  PMCCounter EQU 0
  MaxHardwareCounterType EQU 1
  
  PHARDWARE_COUNTER_TYPE typedef ptr HARDWARE_COUNTER_TYPE
  
  HARDWARE_COUNTER struct
    Type_ HARDWARE_COUNTER_TYPE ?
    Reserved DWORD ?
    Index ULONG64 ?
  HARDWARE_COUNTER ends

  PHARDWARE_COUNTER typedef ptr HARDWARE_COUNTER
  
  PROCESS_MITIGATION_POLICY typedef SDWORD
  ProcessDEPPolicy EQU 0
  ProcessASLRPolicy EQU 1
  ProcessDynamicCodePolicy EQU 2
  ProcessStrictHandleCheckPolicy EQU 3
  ProcessSystemCallDisablePolicy EQU 4
  ProcessMitigationOptionsMask EQU 5
  ProcessExtensionPointDisablePolicy EQU 6
  ProcessControlFlowGuardPolicy EQU 7
  ProcessSignaturePolicy EQU 8
  ProcessFontDisablePolicy EQU 9
  ProcessImageLoadPolicy EQU 10
  ProcessSystemCallFilterPolicy EQU 11
  ProcessPayloadRestrictionPolicy EQU 12
  ProcessChildProcessPolicy EQU 13
  MaxProcessMitigationPolicy EQU 14
  
  PPROCESS_MITIGATION_POLICY typedef ptr PROCESS_MITIGATION_POLICY
  
  PROCESS_MITIGATION_ASLR_POLICY struct
    union DUMMYUNIONNAME_11
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_12
        DUMMYSTRUCTNAME_12_??4 record EnableBottomUpRandomization_??4:1, EnableForceRelocateImages_??4:1, EnableHighEntropy_??4:1, DisallowStrippedImages_??4:1, ReservedFlags_??4:28
        DUMMYSTRUCTNAME_12_??4 <>
      ends
    ends
  PROCESS_MITIGATION_ASLR_POLICY ends

  PPROCESS_MITIGATION_ASLR_POLICY typedef ptr PROCESS_MITIGATION_ASLR_POLICY
  
  PROCESS_MITIGATION_DEP_POLICY struct
    union DUMMYUNIONNAME_13
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_14
        DUMMYSTRUCTNAME_14_??5 record Enable_??5:1, DisableAtlThunkEmulation_??5:1, ReservedFlags_??5:30
        DUMMYSTRUCTNAME_14_??5 <>
      ends
    ends
    Permanent BOOLEAN ?
  PROCESS_MITIGATION_DEP_POLICY ends

  PPROCESS_MITIGATION_DEP_POLICY typedef ptr PROCESS_MITIGATION_DEP_POLICY
  
  PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY struct
    union DUMMYUNIONNAME_15
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_16
        DUMMYSTRUCTNAME_16_??6 record RaiseExceptionOnInvalidHandleReference_??6:1, HandleExceptionsPermanentlyEnabled_??6:1, ReservedFlags_??6:30
        DUMMYSTRUCTNAME_16_??6 <>
      ends
    ends
  PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY ends

  PPROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY typedef ptr PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY
  
  PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY struct
    union DUMMYUNIONNAME_17
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_18
        DUMMYSTRUCTNAME_18_??7 record DisallowWin32kSystemCalls_??7:1, AuditDisallowWin32kSystemCalls_??7:1, ReservedFlags_??7:30
        DUMMYSTRUCTNAME_18_??7 <>
      ends
    ends
  PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY ends

  PPROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY typedef ptr PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY
  
  PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY struct
    union DUMMYUNIONNAME_19
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_20
        DUMMYSTRUCTNAME_20_??8 record DisableExtensionPoints_??8:1, ReservedFlags_??8:31
        DUMMYSTRUCTNAME_20_??8 <>
      ends
    ends
  PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY ends

  PPROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY typedef ptr PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY
  
  PROCESS_MITIGATION_DYNAMIC_CODE_POLICY struct
    union DUMMYUNIONNAME_21
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_22
        DUMMYSTRUCTNAME_22_??9 record ProhibitDynamicCode_??9:1, AllowThreadOptOut_??9:1, AllowRemoteDowngrade_??9:1, AuditProhibitDynamicCode_??9:1, ReservedFlags_??9:28
        DUMMYSTRUCTNAME_22_??9 <>
      ends
    ends
  PROCESS_MITIGATION_DYNAMIC_CODE_POLICY ends

  PPROCESS_MITIGATION_DYNAMIC_CODE_POLICY typedef ptr PROCESS_MITIGATION_DYNAMIC_CODE_POLICY
  
  PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY struct
    union DUMMYUNIONNAME_23
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_24
        DUMMYSTRUCTNAME_24_??10 record EnableControlFlowGuard_??10:1, EnableExportSuppression_??10:1, StrictMode_??10:1, ReservedFlags_??10:29
        DUMMYSTRUCTNAME_24_??10 <>
      ends
    ends
  PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY ends

  PPROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY typedef ptr PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY
  
  PROCESS_MITIGATION_BINARY_SIGNATURE_POLICY struct
    union DUMMYUNIONNAME_25
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_26
        DUMMYSTRUCTNAME_26_??11 record MicrosoftSignedOnly_??11:1, StoreSignedOnly_??11:1, MitigationOptIn_??11:1, AuditMicrosoftSignedOnly_??11:1, AuditStoreSignedOnly_??11:1, ReservedFlags_??11:27
        DUMMYSTRUCTNAME_26_??11 <>
      ends
    ends
  PROCESS_MITIGATION_BINARY_SIGNATURE_POLICY ends

  PPROCESS_MITIGATION_BINARY_SIGNATURE_POLICY typedef ptr PROCESS_MITIGATION_BINARY_SIGNATURE_POLICY
  
  PROCESS_MITIGATION_FONT_DISABLE_POLICY struct
    union DUMMYUNIONNAME_27
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_28
        DUMMYSTRUCTNAME_28_??12 record DisableNonSystemFonts_??12:1, AuditNonSystemFontLoading_??12:1, ReservedFlags_??12:30
        DUMMYSTRUCTNAME_28_??12 <>
      ends
    ends
  PROCESS_MITIGATION_FONT_DISABLE_POLICY ends

  PPROCESS_MITIGATION_FONT_DISABLE_POLICY typedef ptr PROCESS_MITIGATION_FONT_DISABLE_POLICY
  
  PROCESS_MITIGATION_IMAGE_LOAD_POLICY struct
    union DUMMYUNIONNAME_29
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_30
        DUMMYSTRUCTNAME_30_??13 record NoRemoteImages_??13:1, NoLowMandatoryLabelImages_??13:1, PreferSystem32Images_??13:1, AuditNoRemoteImages_??13:1, AuditNoLowMandatoryLabelImages_??13:1, ReservedFlags_??13:27
        DUMMYSTRUCTNAME_30_??13 <>
      ends
    ends
  PROCESS_MITIGATION_IMAGE_LOAD_POLICY ends

  PPROCESS_MITIGATION_IMAGE_LOAD_POLICY typedef ptr PROCESS_MITIGATION_IMAGE_LOAD_POLICY
  
  PROCESS_MITIGATION_SYSTEM_CALL_FILTER_POLICY struct
    union DUMMYUNIONNAME_31
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_32
        DUMMYSTRUCTNAME_32_??14 record FilterId_??14:4, ReservedFlags_??14:28
        DUMMYSTRUCTNAME_32_??14 <>
      ends
    ends
  PROCESS_MITIGATION_SYSTEM_CALL_FILTER_POLICY ends

  PPROCESS_MITIGATION_SYSTEM_CALL_FILTER_POLICY typedef ptr PROCESS_MITIGATION_SYSTEM_CALL_FILTER_POLICY
  
  PROCESS_MITIGATION_PAYLOAD_RESTRICTION_POLICY struct
    union DUMMYUNIONNAME_33
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_34
        DUMMYSTRUCTNAME_34_??15 record EnableExportAddressFilter_??15:1, AuditExportAddressFilter_??15:1, EnableExportAddressFilterPlus_??15:1, AuditExportAddressFilterPlus_??15:1, EnableImportAddressFilter_??15:1, AuditImportAddressFilter_??15:1, EnableRopStackPivot_??15:1, AuditRopStackPivot_??15:1, EnableRopCallerCheck_??15:1, AuditRopCallerCheck_??15:1, EnableRopSimExec_??15:1, AuditRopSimExec_??15:1, ReservedFlags_??15:20
        DUMMYSTRUCTNAME_34_??15 <>
      ends
    ends
  PROCESS_MITIGATION_PAYLOAD_RESTRICTION_POLICY ends

  PPROCESS_MITIGATION_PAYLOAD_RESTRICTION_POLICY typedef ptr PROCESS_MITIGATION_PAYLOAD_RESTRICTION_POLICY
  
  PROCESS_MITIGATION_CHILD_PROCESS_POLICY struct
    union DUMMYUNIONNAME_35
      Flags DWORD ?
      struct DUMMYSTRUCTNAME_36
        DUMMYSTRUCTNAME_36_??16 record NoChildProcessCreation_??16:1, AuditNoChildProcessCreation_??16:1, AllowSecureProcessCreation_??16:1, ReservedFlags_??16:29
        DUMMYSTRUCTNAME_36_??16 <>
      ends
    ends
  PROCESS_MITIGATION_CHILD_PROCESS_POLICY ends

  PPROCESS_MITIGATION_CHILD_PROCESS_POLICY typedef ptr PROCESS_MITIGATION_CHILD_PROCESS_POLICY
  
  PROCESS_KEEPALIVE_COUNT_INFORMATION struct
    WakeCount DWORD ?
    NoWakeCount DWORD ?
  PROCESS_KEEPALIVE_COUNT_INFORMATION ends

  PPROCESS_KEEPALIVE_COUNT_INFORMATION typedef ptr PROCESS_KEEPALIVE_COUNT_INFORMATION
  
  PROCESS_REVOKE_FILE_HANDLES_INFORMATION struct
    TargetDevicePath UNICODE_STRING <>
  PROCESS_REVOKE_FILE_HANDLES_INFORMATION ends

  PPROCESS_REVOKE_FILE_HANDLES_INFORMATION typedef ptr PROCESS_REVOKE_FILE_HANDLES_INFORMATION
  
  PROCESS_READWRITEVM_LOGGING_ENABLE_READVM equ 01h
  PROCESS_READWRITEVM_LOGGING_ENABLE_READVM_V equ 1
  PROCESS_READWRITEVM_LOGGING_ENABLE_WRITEVM equ 02h
  PROCESS_READWRITEVM_LOGGING_ENABLE_WRITEVM_V equ 2
  PROCESS_READWRITEVM_LOGGING_INFORMATION union
    Flags BYTE ?
    struct
      PROCESS_READWRITEVM_LOGGING_INFORMATION_??17 record EnableReadVmLogging_??17:1, EnableWriteVmLogging_??17:1, Unused_??17:6
      PROCESS_READWRITEVM_LOGGING_INFORMATION_??17 <>
    ends
  PROCESS_READWRITEVM_LOGGING_INFORMATION ends

  PPROCESS_READWRITEVM_LOGGING_INFORMATION typedef ptr PROCESS_READWRITEVM_LOGGING_INFORMATION
  
  POOLED_USAGE_AND_LIMITS struct
    PeakPagedPoolUsage SIZE_T ?
    PagedPoolUsage SIZE_T ?
    PagedPoolLimit SIZE_T ?
    PeakNonPagedPoolUsage SIZE_T ?
    NonPagedPoolUsage SIZE_T ?
    NonPagedPoolLimit SIZE_T ?
    PeakPagefileUsage SIZE_T ?
    PagefileUsage SIZE_T ?
    PagefileLimit SIZE_T ?
  POOLED_USAGE_AND_LIMITS ends

  PPOOLED_USAGE_AND_LIMITS typedef ptr POOLED_USAGE_AND_LIMITS
  PROCESS_ACCESS_TOKEN struct
    Token HANDLE ?
    Thread HANDLE ?
  PROCESS_ACCESS_TOKEN ends

  PPROCESS_ACCESS_TOKEN typedef ptr PROCESS_ACCESS_TOKEN
  
  PROCESS_EXCEPTION_PORT_ALL_STATE_BITS equ 00000003h
  PROCESS_EXCEPTION_PORT_ALL_STATE_FLAGS equ ( ( ( 1 shl PROCESS_EXCEPTION_PORT_ALL_STATE_BITS ) - 1 ) )
  PROCESS_EXCEPTION_PORT struct
    ExceptionPortHandle HANDLE ?
    StateFlags DWORD ?
  PROCESS_EXCEPTION_PORT ends

  PPROCESS_EXCEPTION_PORT typedef ptr PROCESS_EXCEPTION_PORT
  
  KERNEL_USER_TIMES struct
    CreateTime LARGE_INTEGER <>
    ExitTime LARGE_INTEGER <>
    KernelTime LARGE_INTEGER <>
    UserTime LARGE_INTEGER <>
  KERNEL_USER_TIMES ends

  PKERNEL_USER_TIMES typedef ptr KERNEL_USER_TIMES
  SUBSYSTEM_INFORMATION_TYPE typedef SDWORD
  SubsystemInformationTypeWin32 EQU 0 
  SubsystemInformationTypeWSL EQU 1 
  MaxSubsystemInformationType EQU 2
  
  PSUBSYSTEM_INFORMATION_TYPE typedef ptr SUBSYSTEM_INFORMATION_TYPE
  
  POWER_THROTTLING_PROCESS_CURRENT_VERSION equ 1
  POWER_THROTTLING_PROCESS_EXECUTION_SPEED equ 1h
  POWER_THROTTLING_PROCESS_DELAYTIMERS equ 2h
  POWER_THROTTLING_PROCESS_VALID_FLAGS equ <( ( POWER_THROTTLING_PROCESS_EXECUTION_SPEED or POWER_THROTTLING_PROCESS_DELAYTIMERS ) )>
  POWER_THROTTLING_PROCESS_STATE struct
    Version DWORD ?
    ControlMask DWORD ?
    StateMask DWORD ?
  POWER_THROTTLING_PROCESS_STATE ends

  PPOWER_THROTTLING_PROCESS_STATE typedef ptr POWER_THROTTLING_PROCESS_STATE
  
  POWER_THROTTLING_THREAD_CURRENT_VERSION equ 1
  POWER_THROTTLING_THREAD_EXECUTION_SPEED equ 1h
  POWER_THROTTLING_THREAD_VALID_FLAGS equ <( POWER_THROTTLING_THREAD_EXECUTION_SPEED )>
  POWER_THROTTLING_THREAD_STATE struct
    Version DWORD ?
    ControlMask DWORD ?
    StateMask DWORD ?
  POWER_THROTTLING_THREAD_STATE ends

  PPOWER_THROTTLING_THREAD_STATE typedef ptr POWER_THROTTLING_THREAD_STATE
  

      KeRaiseIrqlToDpcLevel proto fastcall

      KeRaiseIrqlToSynchLevel proto fastcall


    M128A  STRUCT
    	qwLow     ULONGLONG ?
    	qwHigh    LONGLONG ?
    M128A ENDS
    PM128A TYPEDEF PTR M128A
    
    IFNDEF KSPIN_LOCK_QUEUE
    KSPIN_LOCK_QUEUE STRUCT
        Next    ULONG ?
    KSPIN_LOCK_QUEUE ends
    ENDIF
    PKSPIN_LOCK_QUEUE TYPEDEF PTR KSPIN_LOCK_QUEUE


    PCR_MINOR_VERSION equ 1
    PCR_MAJOR_VERSION equ 1
    KPCR struct
      union
        NtTib NT_TIB <>
        struct
          GdtBase DWORD ?
          TssBase POINTER ?
          UserRsp ULONG64 ?
          Self POINTER ?
          CurrentPrcb POINTER ?
          LockArray PKSPIN_LOCK_QUEUE ?
          Used_Self PVOID ?
        ends
      ends
      IdtBase DWORD ?
      Unused ULONG64 2 dup (?)
      Irql KIRQL ?
      SecondLevelCacheAssociativity BYTE ?
      ObsoleteNumber BYTE ?
      Fill0 BYTE ?
      Unused0 DWORD 3 dup (?)
      MajorVersion WORD ?
      MinorVersion WORD ?
      StallScaleFactor DWORD ?
      Unused1 PVOID 3 dup (?)
      KernelReserved DWORD 15 dup (?)
      SecondLevelCacheSize DWORD ?
      HalReserved DWORD 16 dup (?)
      Unused2 DWORD ?
      KdVersionBlock PVOID ?
      Unused3 PVOID ?
      PcrAlign1 DWORD 24 dup (?)
    KPCR ends

    PKPCR typedef ptr KPCR
    
    KEXCEPTION_FRAME struct
      P1Home ULONG64 ?
      P2Home ULONG64 ?
      P3Home ULONG64 ?
      P4Home ULONG64 ?
      P5 ULONG64 ?
      Spare1 ULONG64 ?
      Xmm6_ M128A <?,?>
      Xmm7_ M128A <>
      Xmm8_ M128A <>
      Xmm9_ M128A <>
      Xmm10_ M128A <>
      Xmm11_ M128A <>
      Xmm12_ M128A <>
      Xmm13_ M128A <>
      Xmm14_ M128A <>
      Xmm15_ M128A <>
      TrapFrame ULONG64 ?
      OutputBuffer ULONG64 ?
      OutputLength ULONG64 ?
      Spare2 ULONG64 ?
      MxCsr ULONG64 ?
      Rbp_ ULONG64 ?
      Rbx_ ULONG64 ?
      Rdi_ ULONG64 ?
      Rsi_ ULONG64 ?
      R12_ ULONG64 ?
      R13_ ULONG64 ?
      R14_ ULONG64 ?
      R15_ ULONG64 ?
      Return ULONG64 ?
    KEXCEPTION_FRAME ends

    PKEXCEPTION_FRAME typedef ptr KEXCEPTION_FRAME


KPROCESSOR_MODE typedef	BYTE
    
    KTRAP_FRAME struct
      P1Home ULONG64 ?
      P2Home ULONG64 ?
      P3Home ULONG64 ?
      P4Home ULONG64 ?
      P5 ULONG64 ?
      PreviousMode KPROCESSOR_MODE ?
      PreviousIrql KIRQL ?
      FaultIndicator BYTE ?
      ExceptionActive BYTE ?
      MxCsr DWORD ?
      Rax_ ULONG64 ?
      Rcx_ ULONG64 ?
      Rdx_ ULONG64 ?
      R8_ ULONG64 ?
      R9_ ULONG64 ?
      R10_ ULONG64 ?
      R11_ ULONG64 ?
      union
        GsBase ULONG64 ?
        GsSwap ULONG64 ?
      ends
      Xmm0_ M128A <>
      Xmm1_ M128A <>
      Xmm2_ M128A <>
      Xmm3_ M128A <>
      Xmm4_ M128A <>
      Xmm5_ M128A <>
      union
        FaultAddress ULONG64 ?
        ContextRecord ULONG64 ?
      ends
      Dr0_ ULONG64 ?
      Dr1_ ULONG64 ?
      Dr2_ ULONG64 ?
      Dr3_ ULONG64 ?
      Dr6_ ULONG64 ?
      Dr7_ ULONG64 ?
      struct
        DebugControl ULONG64 ?
        LastBranchToRip ULONG64 ?
        LastBranchFromRip ULONG64 ?
        LastExceptionToRip ULONG64 ?
        LastExceptionFromRip ULONG64 ?
      ends
      SegDs WORD ?
      SegEs WORD ?
      SegFs WORD ?
      SegGs WORD ?
      TrapFrame ULONG64 ?
      Rbx_ ULONG64 ?
      Rdi_ ULONG64 ?
      Rsi_ ULONG64 ?
      Rbp_ ULONG64 ?
      union
        ErrorCode ULONG64 ?
        ExceptionFrame ULONG64 ?
      ends
      Rip_ ULONG64 ?
      SegCs WORD ?
      Fill0 BYTE ?
      Logging BYTE ?
      Fill1 WORD 2 dup (?)
      EFlags_ DWORD ?
      Fill2 DWORD ?
      Rsp_ ULONG64 ?
      SegSs WORD ?
      Fill3 WORD ?
      Fill4 DWORD ?
    KTRAP_FRAME ends

    PKTRAP_FRAME typedef ptr KTRAP_FRAME
    
PXMM_SAVE_AREA32 TYPEDEF PTR XMM_SAVE_AREA32    
    
    
    KUMS_CONTEXT_HEADER struct
      P1Home ULONG64 ?
      P2Home ULONG64 ?
      P3Home ULONG64 ?
      P4Home ULONG64 ?
      StackTop PVOID ?
      StackSize ULONG64 ?
      RspOffset ULONG64 ?
      Rip_ ULONG64 ?
      FltSave PXMM_SAVE_AREA32 ?
      KUMS_UCH_VOLATILE_BIT equ 0
      KUMS_UCH_VOLATILE_MASK equ ( 1UL shl KUMS_UCH_VOLATILE_BIT )
      union
        struct
          KUMS_CONTEXT_HEADER_??18 record Volatile_??18:1, Reserved_??18:63
          KUMS_CONTEXT_HEADER_??18 <>
        ends
        Flags ULONG64 ?
      ends
      TrapFrame PKTRAP_FRAME ?
      ExceptionFrame PKEXCEPTION_FRAME ?
      SourceThread POINTER ?
      Return ULONG64 ?
    KUMS_CONTEXT_HEADER ends

    PKUMS_CONTEXT_HEADER typedef ptr KUMS_CONTEXT_HEADER
    

    MM_HIGHEST_USER_ADDRESS equ <MmHighestUserAddress>
    MM_SYSTEM_RANGE_START equ <MmSystemRangeStart>
      MM_USER_PROBE_ADDRESS equ <MmUserProbeAddress>
    MM_LOWEST_USER_ADDRESS equ 10000h
      RESULT_ZERO equ 0
      RESULT_NEGATIVE equ 1
      RESULT_POSITIVE equ 2
      INTERLOCKED_RESULT typedef SDWORD
      ResultNegative EQU RESULT_NEGATIVE 
      ResultZero EQU RESULT_ZERO 
      ResultPositive EQU RESULT_POSITIVE 

      _ExInterlockedExchangeUlong proto fastcall :PULONG, :DWORD

      KeGetPcr proto fastcall
        KeGetCurrentProcessorNumber proto fastcall


    KeRaiseIrqlToDpcLevel proto fastcall
    KeRaiseIrqlToSynchLevel proto fastcall



  SYSTEM_FIRMWARE_TABLE_ACTION typedef SDWORD
  SystemFirmwareTable_Enumerate EQU 0
  SystemFirmwareTable_Get EQU 1

  ANYSIZE_ARRAY EQU 1
  
  SYSTEM_FIRMWARE_TABLE_INFORMATION struct
    ProviderSignature DWORD ?
    Action SYSTEM_FIRMWARE_TABLE_ACTION ?
    TableID DWORD ?
    TableBufferLength DWORD ?
    TableBuffer BYTE ANYSIZE_ARRAY dup (?)
  SYSTEM_FIRMWARE_TABLE_INFORMATION ends

  PSYSTEM_FIRMWARE_TABLE_INFORMATION typedef ptr SYSTEM_FIRMWARE_TABLE_INFORMATION
  
  proto_PFNFTH typedef proto c :PSYSTEM_FIRMWARE_TABLE_INFORMATION
  PFNFTH typedef ptr proto_PFNFTH
  SYSTEM_FIRMWARE_TABLE_HANDLER struct
    ProviderSignature DWORD ?
    Register BOOLEAN ?
    FirmwareTableHandler PFNFTH ?
    DriverObject PVOID ?
  SYSTEM_FIRMWARE_TABLE_HANDLER ends

  PSYSTEM_FIRMWARE_TABLE_HANDLER typedef ptr SYSTEM_FIRMWARE_TABLE_HANDLER
  
  proto_PTIMER_APC_ROUTINE typedef proto fastcall :PVOID, :DWORD, :SDWORD
  PTIMER_APC_ROUTINE typedef ptr proto_PTIMER_APC_ROUTINE
  TIMER_SET_INFORMATION_CLASS typedef SDWORD
  TimerSetCoalescableTimer EQU 0
  MaxTimerInfoClass EQU 1
  

    TIMER_SET_COALESCABLE_TIMER_INFO struct
      DueTime LARGE_INTEGER <>
      TimerApcRoutine PTIMER_APC_ROUTINE ?
      TimerContext PVOID ?
      WakeContext POINTER ?
      Period DWORD ?
      TolerableDelay DWORD ?
      PreviousState PBOOLEAN ?
    TIMER_SET_COALESCABLE_TIMER_INFO ends

    PTIMER_SET_COALESCABLE_TIMER_INFO typedef ptr TIMER_SET_COALESCABLE_TIMER_INFO

  proto_PDRIVER_VERIFIER_THUNK_ROUTINE typedef proto fastcall :PVOID
  PDRIVER_VERIFIER_THUNK_ROUTINE typedef ptr proto_PDRIVER_VERIFIER_THUNK_ROUTINE
  DRIVER_VERIFIER_THUNK_PAIRS struct
    PristineRoutine PDRIVER_VERIFIER_THUNK_ROUTINE ?
    NewRoutine PDRIVER_VERIFIER_THUNK_ROUTINE ?
  DRIVER_VERIFIER_THUNK_PAIRS ends

  PDRIVER_VERIFIER_THUNK_PAIRS typedef ptr DRIVER_VERIFIER_THUNK_PAIRS
  
  DRIVER_VERIFIER_SPECIAL_POOLING equ 0001h
  DRIVER_VERIFIER_FORCE_IRQL_CHECKING equ 0002h
  DRIVER_VERIFIER_INJECT_ALLOCATION_FAILURES equ 0004h
  DRIVER_VERIFIER_TRACK_POOL_ALLOCATIONS equ 0008h
  DRIVER_VERIFIER_IO_CHECKING equ 0010h
  XSTATE_LEGACY_FLOATING_POINT equ 0
  XSTATE_LEGACY_SSE equ 1
  XSTATE_GSSE equ 2
  XSTATE_AVX equ <( XSTATE_GSSE )>
  XSTATE_MPX_BNDREGS equ 3
  XSTATE_MPX_BNDCSR equ 4
  XSTATE_AVX512_KMASK equ 5
  XSTATE_AVX512_ZMM_H equ 6
  XSTATE_AVX512_ZMM equ 7
  XSTATE_IPT equ 8
  XSTATE_LWP equ 62
  MAXIMUM_XSTATE_FEATURES equ 64
  XSTATE_MASK_LEGACY_FLOATING_POINT equ ( 1 shl ( XSTATE_LEGACY_FLOATING_POINT ) )
  XSTATE_MASK_LEGACY_SSE equ ( 1 shl ( XSTATE_LEGACY_SSE ) )
  XSTATE_MASK_LEGACY equ <( XSTATE_MASK_LEGACY_FLOATING_POINT or XSTATE_MASK_LEGACY_SSE )>
  XSTATE_MASK_GSSE equ ( 1 shl ( XSTATE_GSSE ) )
  XSTATE_MASK_AVX equ <( XSTATE_MASK_GSSE )>
  XSTATE_MASK_MPX equ ( ( 1 shl ( XSTATE_MPX_BNDREGS ) ) or ( 1 shl ( XSTATE_MPX_BNDCSR ) ) )
  XSTATE_MASK_AVX512 equ ( ( 1 shl ( XSTATE_AVX512_KMASK ) ) or ( 1 shl ( XSTATE_AVX512_ZMM_H ) ) or ( 1 shl ( XSTATE_AVX512_ZMM ) ) )
  XSTATE_MASK_IPT equ ( 1 shl ( XSTATE_IPT ) )
  XSTATE_MASK_LWP equ ( 1 shl ( XSTATE_LWP ) )
  XSTATE_MASK_ALLOWED equ <( XSTATE_MASK_LEGACY or XSTATE_MASK_AVX or XSTATE_MASK_MPX or XSTATE_MASK_AVX512 or XSTATE_MASK_IPT or XSTATE_MASK_LWP )>
  XSTATE_MASK_PERSISTENT equ ( ( 1 shl ( XSTATE_MPX_BNDCSR ) ) or XSTATE_MASK_LWP )
  XSTATE_COMPACTION_ENABLE equ 63
  XSTATE_COMPACTION_ENABLE_MASK equ ( 1 shl ( XSTATE_COMPACTION_ENABLE ) )
  XSTATE_ALIGN_BIT equ 1
  XSTATE_ALIGN_MASK equ ( 1 shl ( XSTATE_ALIGN_BIT ) )
  XSTATE_CONTROLFLAG_XSAVEOPT_MASK equ 1
  XSTATE_CONTROLFLAG_XSAVEC_MASK equ 2
  XSTATE_CONTROLFLAG_VALID_MASK equ <( XSTATE_CONTROLFLAG_XSAVEOPT_MASK or XSTATE_CONTROLFLAG_XSAVEC_MASK )>
  XSTATE_FEATURE struct
    Offset_ DWORD ?
    Size_ DWORD ?
  XSTATE_FEATURE ends

  PXSTATE_FEATURE typedef ptr XSTATE_FEATURE
  
  XSTATE_CONFIGURATION struct
    EnabledFeatures ULONG64 ?
    EnabledVolatileFeatures ULONG64 ?
    Size_ DWORD ?
    union
      ControlFlags DWORD ?
      struct
        XSTATE_CONFIGURATION_??19 record OptimizedSave_??19:1, CompactionEnabled_??19:1
        XSTATE_CONFIGURATION_??19 <>
      ends
    ends
    Features XSTATE_FEATURE MAXIMUM_XSTATE_FEATURES dup (<>)
    EnabledSupervisorFeatures ULONG64 ?
    AlignedFeatures ULONG64 ?
    AllFeatureSize DWORD ?
    AllFeatures DWORD MAXIMUM_XSTATE_FEATURES dup (?)
  XSTATE_CONFIGURATION ends

  PXSTATE_CONFIGURATION typedef ptr XSTATE_CONFIGURATION
  

  NX_SUPPORT_POLICY_ALWAYSOFF equ 0
  NX_SUPPORT_POLICY_ALWAYSON equ 1
  NX_SUPPORT_POLICY_OPTIN equ 2
  NX_SUPPORT_POLICY_OPTOUT equ 3
  SEH_VALIDATION_POLICY_ON equ 0
  SEH_VALIDATION_POLICY_OFF equ 1
  SEH_VALIDATION_POLICY_TELEMETRY equ 2
  SEH_VALIDATION_POLICY_DEFER equ 3
  SHARED_GLOBAL_FLAGS_ERROR_PORT_V equ 0h
  SHARED_GLOBAL_FLAGS_ERROR_PORT equ ( 1 shl SHARED_GLOBAL_FLAGS_ERROR_PORT_V )
  SHARED_GLOBAL_FLAGS_ELEVATION_ENABLED_V equ 1h
  SHARED_GLOBAL_FLAGS_ELEVATION_ENABLED equ ( 1 shl SHARED_GLOBAL_FLAGS_ELEVATION_ENABLED_V )
  SHARED_GLOBAL_FLAGS_VIRT_ENABLED_V equ 2h
  SHARED_GLOBAL_FLAGS_VIRT_ENABLED equ ( 1 shl SHARED_GLOBAL_FLAGS_VIRT_ENABLED_V )
  SHARED_GLOBAL_FLAGS_INSTALLER_DETECT_ENABLED_V equ 3h
  SHARED_GLOBAL_FLAGS_INSTALLER_DETECT_ENABLED equ ( 1 shl SHARED_GLOBAL_FLAGS_INSTALLER_DETECT_ENABLED_V )
  SHARED_GLOBAL_FLAGS_LKG_ENABLED_V equ 4h
  SHARED_GLOBAL_FLAGS_LKG_ENABLED equ ( 1 shl SHARED_GLOBAL_FLAGS_LKG_ENABLED_V )
  SHARED_GLOBAL_FLAGS_DYNAMIC_PROC_ENABLED_V equ 5h
  SHARED_GLOBAL_FLAGS_DYNAMIC_PROC_ENABLED equ ( 1 shl SHARED_GLOBAL_FLAGS_DYNAMIC_PROC_ENABLED_V )
  SHARED_GLOBAL_FLAGS_CONSOLE_BROKER_ENABLED_V equ 6h
  SHARED_GLOBAL_FLAGS_CONSOLE_BROKER_ENABLED equ ( 1 shl SHARED_GLOBAL_FLAGS_CONSOLE_BROKER_ENABLED_V )
  SHARED_GLOBAL_FLAGS_SECURE_BOOT_ENABLED_V equ 7h
  SHARED_GLOBAL_FLAGS_SECURE_BOOT_ENABLED equ ( 1 shl SHARED_GLOBAL_FLAGS_SECURE_BOOT_ENABLED_V )
  SHARED_GLOBAL_FLAGS_MULTI_SESSION_SKU_V equ 8h
  SHARED_GLOBAL_FLAGS_MULTI_SESSION_SKU equ ( 1 shl SHARED_GLOBAL_FLAGS_MULTI_SESSION_SKU_V )
  SHARED_GLOBAL_FLAGS_MULTIUSERS_IN_SESSION_SKU_V equ 9h
  SHARED_GLOBAL_FLAGS_MULTIUSERS_IN_SESSION_SKU equ ( 1 shl SHARED_GLOBAL_FLAGS_MULTIUSERS_IN_SESSION_SKU_V )
  SHARED_GLOBAL_FLAGS_STATE_SEPARATION_ENABLED_V equ 0Ah
  SHARED_GLOBAL_FLAGS_STATE_SEPARATION_ENABLED equ ( 1 shl SHARED_GLOBAL_FLAGS_STATE_SEPARATION_ENABLED_V )
  EX_INIT_BITS macro Flags,Bit
   exitm <* ( ( Flags ) ) or ( Bit ) >
  endm
  EX_TEST_SET_BIT macro Flags,Bit
   exitm <InterlockedBitTestAndSet ( ( PLONG ) ( Flags ) , ( Bit ) ) >
  endm
  EX_TEST_CLEAR_BIT macro Flags,Bit
   exitm <InterlockedBitTestAndReset ( ( PLONG ) ( Flags ) , ( Bit ) ) >
  endm
  SYSTEM_CALL_SYSCALL equ 0
  SYSTEM_CALL_INT_2E equ 1
  SHARED_GLOBAL_FLAGS_QPC_BYPASS_ENABLED equ 01h
  SHARED_GLOBAL_FLAGS_QPC_BYPASS_USE_HV_PAGE equ 02h
  SHARED_GLOBAL_FLAGS_QPC_BYPASS_USE_MFENCE equ 10h
  SHARED_GLOBAL_FLAGS_QPC_BYPASS_USE_LFENCE equ 20h
  SHARED_GLOBAL_FLAGS_QPC_BYPASS_A73_ERRATA equ 40h
  SHARED_GLOBAL_FLAGS_QPC_BYPASS_USE_RDTSCP equ 80h
  
KSYSTEM_TIME STRUCT		; sizeof = 0Ch
	LowPart		DWORD	?
	High1Time	SDWORD	?
	High2Time	SDWORD	?
KSYSTEM_TIME ENDS
PKSYSTEM_TIME typedef PTR KSYSTEM_TIME  
  
  PROCESSOR_FEATURE_MAX equ 64
  
  ALTERNATIVE_ARCHITECTURE_TYPE TYPEDEF DWORD
  
  KUSER_SHARED_DATA struct
    TickCountLowDeprecated DWORD ?
    TickCountMultiplier DWORD ?
    InterruptTime KSYSTEM_TIME <>
    SystemTime KSYSTEM_TIME <>
    TimeZoneBias KSYSTEM_TIME <>
    ImageNumberLow WORD ?
    ImageNumberHigh WORD ?
    NtSystemRoot WCHAR 260 dup (?)
    MaxStackTraceDepth DWORD ?
    CryptoExponent DWORD ?
    TimeZoneId DWORD ?
    LargePageMinimum DWORD ?
    AitSamplingValue DWORD ?
    AppCompatFlag DWORD ?
    RNGSeedVersion QWORD ?
    GlobalValidationRunlevel DWORD ?
    TimeZoneBiasStamp SDWORD ?
    NtBuildNumber DWORD ?
    NtProductType NT_PRODUCT_TYPE ?
    ProductTypeIsValid BOOLEAN ?
    Reserved0 BOOLEAN 1 dup (?)
    NativeProcessorArchitecture WORD ?
    NtMajorVersion DWORD ?
    NtMinorVersion DWORD ?
    ProcessorFeatures BOOLEAN PROCESSOR_FEATURE_MAX dup (?)
    Reserved1 DWORD ?
    Reserved3 DWORD ?
    TimeSlip DWORD ?
    AlternativeArchitecture ALTERNATIVE_ARCHITECTURE_TYPE ?
    BootId DWORD ?
    SystemExpirationDate LARGE_INTEGER <>
    SuiteMask DWORD ?
    KdDebuggerEnabled BOOLEAN ?
    union
      MitigationPolicies BYTE ?
      struct
        KUSER_SHARED_DATA_??20 record NXSupportPolicy_??20:2, SEHValidationPolicy_??20:2, CurDirDevicesSkippedForDlls_??20:2, Reserved_??20:2
        KUSER_SHARED_DATA_??20 <>
      ends
    ends
    Reserved6 BYTE 2 dup (?)
    ActiveConsoleId DWORD ?
    DismountCount DWORD ?
    ComPlusPackage DWORD ?
    LastSystemRITEventTickCount DWORD ?
    NumberOfPhysicalPages DWORD ?
    SafeBootMode BOOLEAN ?
    VirtualizationFlags BYTE ?
    Reserved12 BYTE 2 dup (?)
    union DUMMYUNIONNAME2
      SharedDataFlags DWORD ?
      struct DUMMYSTRUCTNAME2
        DUMMYSTRUCTNAME2_??21 record DbgErrorPortPresent_??21:1, DbgElevationEnabled_??21:1, DbgVirtEnabled_??21:1, DbgInstallerDetectEnabled_??21:1, DbgLkgEnabled_??21:1, DbgDynProcessorEnabled_??21:1, DbgConsoleBrokerEnabled_??21:1, DbgSecureBootEnabled_??21:1, DbgMultiSessionSku_??21:1, DbgMultiUsersInSessionSku_??21:1, DbgStateSeparationEnabled_??21:1, SpareBits_??21:21
        DUMMYSTRUCTNAME2_??21 <>
      ends
    ends
    DataFlagsPad DWORD 1 dup (?)
    TestRetInstruction QWORD ?
    QpcFrequency QWORD ?
    SystemCall DWORD ?
    SystemCallPad0 DWORD ?
    SystemCallPad QWORD 2 dup (?)
    union DUMMYUNIONNAME3
      TickCount KSYSTEM_TIME <>
      TickCountQuad ULONG64 ?
      struct DUMMYSTRUCTNAME_37
        ReservedTickCountOverlay DWORD 3 dup (?)
        TickCountPad DWORD 1 dup (?)
      ends
    ends
    Cookie DWORD ?
    CookiePad DWORD 1 dup (?)
    ConsoleSessionForegroundProcessId QWORD ?
    TimeUpdateLock QWORD ?
    BaselineSystemTimeQpc QWORD ?
    BaselineInterruptTimeQpc QWORD ?
    QpcSystemTimeIncrement QWORD ?
    QpcInterruptTimeIncrement QWORD ?
    QpcSystemTimeIncrementShift BYTE ?
    QpcInterruptTimeIncrementShift BYTE ?
    UnparkedProcessorCount WORD ?
    EnclaveFeatureMask DWORD 4 dup (?)
    TelemetryCoverageRound DWORD ?
    UserModeGlobalLogger WORD 16 dup (?)
    ImageFileExecutionOptions DWORD ?
    LangGenerationCount DWORD ?
    Reserved4 QWORD ?
    InterruptTimeBias QWORD ?
    QpcBias QWORD ?
    ActiveProcessorCount DWORD ?
    ActiveGroupCount BYTE ?
    Reserved9 BYTE ?
    union
      QpcData WORD ?
      struct
        QpcBypassEnabled BYTE ?
        QpcShift BYTE ?
      ends
    ends
    TimeZoneBiasEffectiveStart LARGE_INTEGER <>
    TimeZoneBiasEffectiveEnd LARGE_INTEGER <>
    XState XSTATE_CONFIGURATION <>
  KUSER_SHARED_DATA ends

  PKUSER_SHARED_DATA typedef ptr KUSER_SHARED_DATA
  
 
  CmResourceTypeMaximum equ 8
  CM_PCCARD_DEVICE_DATA struct
    Flags BYTE ?
    ErrorCode BYTE ?
    Reserved WORD ?
    BusData DWORD ?
    DeviceId DWORD ?
    LegacyBaseAddress DWORD ?
    IRQMap BYTE 16 dup (?)
  CM_PCCARD_DEVICE_DATA ends

  PCM_PCCARD_DEVICE_DATA typedef ptr CM_PCCARD_DEVICE_DATA
  
  PCCARD_MAP_ERROR equ 01h
  PCCARD_DEVICE_PCI equ 10h
  PCCARD_SCAN_DISABLED equ 01h
  PCCARD_MAP_ZERO equ 02h
  PCCARD_NO_TIMER equ 03h
  PCCARD_NO_PIC equ 04h
  PCCARD_NO_LEGACY_BASE equ 05h
  PCCARD_DUP_LEGACY_BASE equ 06h
  PCCARD_NO_CONTROLLERS equ 07h
  ifndef _ARC_DDK_
    _ARC_DDK_ equ <>
    CONFIGURATION_TYPE typedef SDWORD
    ArcSystem EQU 0
    CentralProcessor EQU 1
    FloatingPointProcessor EQU 2
    PrimaryIcache EQU 3
    PrimaryDcache EQU 4
    SecondaryIcache EQU 5
    SecondaryDcache EQU 6
    SecondaryCache EQU 7
    EisaAdapter EQU 8
    TcAdapter EQU 9
    ScsiAdapter EQU 10
    DtiAdapter EQU 11
    MultiFunctionAdapter EQU 12
    DiskController EQU 13
    TapeController EQU 14
    CdromController EQU 15
    WormController EQU 16
    SerialController EQU 17
    NetworkController EQU 18
    DisplayController EQU 19
    ParallelController EQU 20
    PointerController EQU 21
    KeyboardController EQU 22
    AudioController EQU 23
    OtherController EQU 24
    DiskPeripheral EQU 25
    FloppyDiskPeripheral EQU 26
    TapePeripheral EQU 27
    ModemPeripheral EQU 28
    MonitorPeripheral EQU 29
    PrinterPeripheral EQU 30
    PointerPeripheral EQU 31
    KeyboardPeripheral EQU 32
    TerminalPeripheral EQU 33
    OtherPeripheral EQU 34
    LinePeripheral EQU 35
    NetworkPeripheral EQU 36
    SystemMemory EQU 37
    DockingInformation EQU 38
    RealModeIrqRoutingTable EQU 39
    RealModePCIEnumeration EQU 40
    MaximumType EQU 41
    
    PCONFIGURATION_TYPE typedef ptr CONFIGURATION_TYPE
    
  endif

    SINGLE_GROUP_LEGACY_API equ 1
    PAUSE_PROCESSOR equ <YieldProcessor ( ) ;>




  MAXIMUM_EXPANSION_SIZE equ ( KERNEL_LARGE_STACK_SIZE - ( PAGE_SIZE / 2 ) )
  proto_EXPAND_STACK_CALLOUT typedef proto stdcall :PVOID
  EXPAND_STACK_CALLOUT typedef ptr proto_EXPAND_STACK_CALLOUT
  PEXPAND_STACK_CALLOUT typedef ptr EXPAND_STACK_CALLOUT





  KeShouldYieldProcessor proto fastcall



  CP_GET_SUCCESS equ 0
  CP_GET_NODATA equ 1
  CP_GET_ERROR equ 2
  PROTECTED_POOL equ 0h



  ZONE_SEGMENT_HEADER struct
    SegmentList SINGLE_LIST_ENTRY <>
    Reserved PVOID ?
  ZONE_SEGMENT_HEADER ends

  PZONE_SEGMENT_HEADER typedef ptr ZONE_SEGMENT_HEADER
  
  ZONE_HEADER struct
    FreeList SINGLE_LIST_ENTRY <>
    SegmentList SINGLE_LIST_ENTRY <>
    BlockSize DWORD ?
    TotalSegmentSize DWORD ?
  ZONE_HEADER ends

  PZONE_HEADER typedef ptr ZONE_HEADER
  


  ExAllocateFromZone macro Zone
   exitm <( ( Zone ) - FreeList.Next ) ; if ( ( Zone ) - FreeList.Next ) ( Zone ) - FreeList.Next = ( Zone ) - FreeList.Next - Next >
  endm

  ExFreeToZone macro Zone,Block
   exitm <( ( ( PSINGLE_LIST_ENTRY ) ( Block ) ) - Next = ( Zone ) - FreeList.Next , ( Zone ) - FreeList.Next = ( ( PSINGLE_LIST_ENTRY ) ( Block ) ) , ( ( PSINGLE_LIST_ENTRY ) ( Block ) ) - Next ) >
  endm

  ExIsFullZone macro Zone
   exitm <( ( Zone ) - FreeList.Next == ( PSINGLE_LIST_ENTRY ) NULL ) >
  endm

  ExInterlockedAllocateFromZone macro Zone,Lock_
   exitm <ExInterlockedPopEntryList ( and ( Zone ) - FreeList , Lock_ ) >
  endm

  ExInterlockedFreeToZone macro Zone,Block,Lock_
   exitm <ExInterlockedPushEntryList ( and ( Zone ) - FreeList , ( ( PSINGLE_LIST_ENTRY ) ( Block ) ) , Lock_ ) >
  endm

  ExIsObjectInFirstZoneSegment macro Zone,Object
   exitm <( ( ( ( PUCHAR ) ( Object ) >= ( PUCHAR ) ( Zone ) - SegmentList.Next ) and ( ( PUCHAR ) ( Object ) < ( PUCHAR ) ( Zone ) - SegmentList.Next + ( Zone ) - TotalSegmentSize ) ) ) >
  endm

  ExInitializeResource equ <ExInitializeResourceLite>
  ExAcquireResourceShared equ <ExAcquireResourceSharedLite>
  ExAcquireResourceExclusive equ <ExAcquireResourceExclusiveLite>
  ExReleaseResourceForThread equ <ExReleaseResourceForThreadLite>
  ExConvertExclusiveToShared equ <ExConvertExclusiveToSharedLite>
  ExDeleteResource equ <ExDeleteResourceLite>
  ExIsResourceAcquiredExclusive equ <ExIsResourceAcquiredExclusiveLite>
  ExIsResourceAcquiredShared equ <ExIsResourceAcquiredSharedLite>
  ExIsResourceAcquired equ <ExIsResourceAcquiredSharedLite>
  UUID typedef GUID



  EVENT_INCREMENT equ 1
  IO_NO_INCREMENT equ 0
  IO_CD_ROM_INCREMENT equ 1
  IO_DISK_INCREMENT equ 1
  IO_KEYBOARD_INCREMENT equ 6
  IO_MAILSLOT_INCREMENT equ 2
  IO_MOUSE_INCREMENT equ 6
  IO_NAMED_PIPE_INCREMENT equ 2
  IO_NETWORK_INCREMENT equ 2
  IO_PARALLEL_INCREMENT equ 1
  IO_SERIAL_INCREMENT equ 2
  IO_SOUND_INCREMENT equ 8
  IO_VIDEO_INCREMENT equ 1
  SEMAPHORE_INCREMENT equ 1


  PHYSICAL_MEMORY_RANGE struct
    BaseAddress PHYSICAL_ADDRESS <>
    NumberOfBytes LARGE_INTEGER <>
  PHYSICAL_MEMORY_RANGE ends

  PPHYSICAL_MEMORY_RANGE typedef ptr PHYSICAL_MEMORY_RANGE
  
  ;MM_ADD_PHYSICAL_MEMORY_ALREADY_ZEROED equ 1h

  PMM_ROTATE_COPY_CALLBACK_FUNCTION typedef ptr proto_PMM_ROTATE_COPY_CALLBACK_FUNCTION
  MM_ROTATE_DIRECTION typedef SDWORD
  MmToFrameBuffer EQU 0
  MmToFrameBufferNoCopy EQU 1
  MmToRegularMemory EQU 2
  MmToRegularMemoryNoCopy EQU 3
  MmMaximumRotateDirection EQU 4
  
  PMM_ROTATE_DIRECTION typedef ptr MM_ROTATE_DIRECTION
  



    MM_SYSTEM_PARTITION_OBJECT equ <NULL>
    MM_CURRENT_PROCESS_PARTITION_OBJECT equ <( MAXULONG_PTR )>
    MmGetPhysicalMemoryRangesEx proto fastcall :PVOID



    MM_COPY_ADDRESS struct
      union
        VirtualAddress PVOID ?
        PhysicalAddress PHYSICAL_ADDRESS <>
      ends
    MM_COPY_ADDRESS ends

    PMMCOPY_ADDRESS typedef ptr MM_COPY_ADDRESS
    
    MM_COPY_MEMORY_PHYSICAL equ 1h
    MM_COPY_MEMORY_VIRTUAL equ 2h



    NODE_REQUIREMENT typedef DWORD
    MM_ANY_NODE_OK equ 80000000h




    ;MmSecureVirtualMemory proto fastcall :__in_data_source :PVOID, :__in_data_source :SIZE_T, :DWORD


    MM_SYSTEM_VIEW_EXCEPTIONS_FOR_INPAGE_ERRORS equ 1h




    _PSGETCURRENTTHREAD_ equ <>


  PS_CREATE_NOTIFY_INFO struct
    Size_ SIZE_T ?
    union
      Flags DWORD ?
      struct
        PS_CREATE_NOTIFY_INFO_??22 record FileOpenNameAvailable_??22:1, IsSubsystemProcess_??22:1, Reserved_??22:30
        PS_CREATE_NOTIFY_INFO_??22 <>
      ends
    ends
    ParentProcessId HANDLE ?
    CreatingThreadId CLIENT_ID <>
    FileObject POINTER ?
    ImageFileName PCUNICODE_STRING ?
    CommandLine PCUNICODE_STRING ?
    CreationStatus NTSTATUS ?
  PS_CREATE_NOTIFY_INFO ends

  PPS_CREATE_NOTIFY_INFO typedef ptr PS_CREATE_NOTIFY_INFO
  
  proto_PCREATE_PROCESS_NOTIFY_ROUTINE typedef proto fastcall :HANDLE, :HANDLE, :BOOLEAN
  PCREATE_PROCESS_NOTIFY_ROUTINE typedef ptr proto_PCREATE_PROCESS_NOTIFY_ROUTINE



  proto_PCREATE_PROCESS_NOTIFY_ROUTINE_EX typedef proto fastcall :PEPROCESS, :HANDLE, :PPS_CREATE_NOTIFY_INFO
  PCREATE_PROCESS_NOTIFY_ROUTINE_EX typedef ptr proto_PCREATE_PROCESS_NOTIFY_ROUTINE_EX




    PSCREATEPROCESSNOTIFYTYPE typedef SDWORD
    PsCreateProcessNotifySubsystems EQU 0 
    
    PsSetCreateProcessNotifyRoutineEx2 proto fastcall :PSCREATEPROCESSNOTIFYTYPE, :PVOID, :BOOLEAN

  proto_PCREATE_THREAD_NOTIFY_ROUTINE typedef proto fastcall :HANDLE, :HANDLE, :BOOLEAN
  PCREATE_THREAD_NOTIFY_ROUTINE typedef ptr proto_PCREATE_THREAD_NOTIFY_ROUTINE



    PSCREATETHREADNOTIFYTYPE typedef SDWORD
    PsCreateThreadNotifyNonSystem EQU 0 
    PsCreateThreadNotifySubsystems EQU 1 
    
    PsSetCreateThreadNotifyRoutineEx proto fastcall :PSCREATETHREADNOTIFYTYPE, :PVOID




  IMAGE_ADDRESSING_MODE_32BIT equ 3
  IMAGE_INFO struct
    union
      Properties DWORD ?
      struct
        IMAGE_INFO_??23 record ImageAddressingMode_??23:8, SystemModeImage_??23:1, ImageMappedToAllPids_??23:1, ExtendedInfoPresent_??23:1, MachineTypeMismatch_??23:1, ImageSignatureLevel_??23:4, ImageSignatureType_??23:3, ImagePartialMap_??23:1, Reserved_??23:12
        IMAGE_INFO_??23 <>
      ends
    ends
    ImageBase PVOID ?
    ImageSelector DWORD ?
    ImageSize SIZE_T ?
    ImageSectionNumber DWORD ?
  IMAGE_INFO ends

  PIMAGE_INFO typedef ptr IMAGE_INFO
  
  IMAGE_INFO_EX struct
    Size_ SIZE_T ?
    ImageInfo IMAGE_INFO <>
    FileObject POINTER ?
  IMAGE_INFO_EX ends

  PIMAGE_INFO_EX typedef ptr IMAGE_INFO_EX
  
  proto_PLOAD_IMAGE_NOTIFY_ROUTINE typedef proto fastcall :PUNICODE_STRING, :HANDLE, :PIMAGE_INFO
  PLOAD_IMAGE_NOTIFY_ROUTINE typedef ptr proto_PLOAD_IMAGE_NOTIFY_ROUTINE


;typedef enum _POOL_TYPE {
    NonPagedPool							equ 0
    PagedPool								equ 1
    NonPagedPoolMustSucceed					equ 2
    DontUseThisType							equ 3
    NonPagedPoolCacheAligned				equ 4
    PagedPoolCacheAligned					equ 5
    NonPagedPoolCacheAlignedMustS			equ 6
    MaxPoolType								equ 7

	; Note these per session types are carefully chosen so that the appropriate
	; masking still applies as well as MaxPoolType above.

    NonPagedPoolSession						equ 32
    PagedPoolSession						equ 33
    NonPagedPoolMustSucceedSession			equ 34
    DontUseThisTypeSession					equ 35
    NonPagedPoolCacheAlignedSession			equ 36
    PagedPoolCacheAlignedSession			equ 37
    NonPagedPoolCacheAlignedMustSSession	equ 38
    POOL_TYPE TYPEDEF QWORD

    PS_IMAGE_NOTIFY_CONFLICTING_ARCHITECTURE equ 1h
    PsSetLoadImageNotifyRoutineEx proto fastcall :PLOAD_IMAGE_NOTIFY_ROUTINE, :ULONG_PTR



    PsGetProcessStartKey proto fastcall :PEPROCESS




  PsGetThreadProperty proto fastcall :PETHREAD, :ULONG_PTR, :DWORD



    PsGetThreadCreateTime proto fastcall :PETHREAD


    proto_SILO_CONTEXT_CLEANUP_CALLBACK typedef proto stdcall :PVOID
    SILO_CONTEXT_CLEANUP_CALLBACK typedef ptr proto_SILO_CONTEXT_CLEANUP_CALLBACK
    proto_SILO_MONITOR_CREATE_CALLBACK typedef proto stdcall :PESILO
    SILO_MONITOR_CREATE_CALLBACK typedef ptr proto_SILO_MONITOR_CREATE_CALLBACK
    proto_SILO_MONITOR_TERMINATE_CALLBACK typedef proto stdcall :PESILO
    SILO_MONITOR_TERMINATE_CALLBACK typedef ptr proto_SILO_MONITOR_TERMINATE_CALLBACK
    SILO_MONITOR_REGISTRATION_VERSION equ 1
    SILO_MONITOR_REGISTRATION struct
      Version BYTE ?
      MonitorHost BOOLEAN ?
      MonitorExistingSilos BOOLEAN ?
      Reserved BYTE 5 dup (?)
      union
        DriverObjectName PUNICODE_STRING ?
        ComponentName PUNICODE_STRING ?
      ends
      CreateCallback SILO_MONITOR_CREATE_CALLBACK ?
      TerminateCallback SILO_MONITOR_TERMINATE_CALLBACK ?
    SILO_MONITOR_REGISTRATION ends

    PSILO_MONITOR_REGISTRATION typedef ptr SILO_MONITOR_REGISTRATION
    
    PsGetJobSilo proto fastcall :PEJOB, :ptr PESILO
    PsGetJobServerSilo proto fastcall :PEJOB, :ptr PESILO
    PsGetEffectiveServerSilo proto fastcall :PESILO
    PsAttachSiloToCurrentThread proto fastcall :PESILO
    PsDetachSiloFromCurrentThread proto fastcall :PESILO
    PsIsHostSilo proto fastcall :PESILO
    PsGetHostSilo proto fastcall
    PsGetCurrentSilo proto fastcall
    PsGetCurrentServerSilo proto fastcall
    PsGetCurrentServerSiloName proto fastcall
    PsIsCurrentThreadInServerSilo proto fastcall
    PsAcquireSiloHardReference proto fastcall :PESILO
    PsReleaseSiloHardReference proto fastcall :PESILO
    PS_INVALID_SILO_CONTEXT_SLOT equ 0ffffffffh
    PsAllocSiloContextSlot proto fastcall :ULONG_PTR, :ptr DWORD
    PsFreeSiloContextSlot proto fastcall :DWORD
    PsCreateSiloContext proto fastcall :PESILO, :DWORD, :POOL_TYPE, :SILO_CONTEXT_CLEANUP_CALLBACK, :ptr PVOID
    PsInsertSiloContext proto fastcall :PESILO, :DWORD, :PVOID
    PsReplaceSiloContext proto fastcall :PESILO, :DWORD, :PVOID, :ptr PVOID
    PsGetSiloContext proto fastcall :PESILO, :DWORD, :ptr PVOID
    PsRemoveSiloContext proto fastcall :PESILO, :DWORD, :ptr PVOID
    PsReferenceSiloContext proto fastcall :PVOID
    PsDereferenceSiloContext proto fastcall :PVOID
    PsInsertPermanentSiloContext proto fastcall :PESILO, :DWORD, :PVOID
    PsMakeSiloContextPermanent proto fastcall :PESILO, :DWORD
    PsGetPermanentSiloContext proto fastcall :PESILO, :DWORD, :ptr PVOID
    PsRegisterSiloMonitor proto fastcall :PSILO_MONITOR_REGISTRATION, :ptr PSILO_MONITOR
    PsStartSiloMonitor proto fastcall :PSILO_MONITOR
    PsGetSiloMonitorContextSlot proto fastcall :PSILO_MONITOR
    PsUnregisterSiloMonitor proto fastcall :PSILO_MONITOR
    PsGetServerSiloServiceSessionId proto fastcall :PESILO
    PsGetServerSiloActiveConsoleId proto fastcall :PESILO
    PsTerminateServerSilo proto fastcall :PESILO, :NTSTATUS


    PsGetParentSilo proto fastcall :PEJOB

    ; enum _INTERFACE_TYPE
    InterfaceTypeUndefined EQU - 1 
    Internal EQU 2
    Isa EQU 3
    Eisa EQU 4
    MicroChannel EQU 5
    TurboChannel EQU 6
    PCIBus EQU 7
    VMEBus EQU 8
    NuBus EQU 9
    PCMCIABus EQU 10
    CBus EQU 11
    MPIBus EQU 12
    MPSABus EQU 13
    ProcessorInternal EQU 14
    InternalPowerBus EQU 15
    PNPISABus EQU 16
    PNPBus EQU 17
    Vmcs EQU 18
    ACPIBus EQU 19
    MaximumInterfaceType EQU 20

    INTERFACE_TYPE TYPEDEF SDWORD
    PINTERFACE_TYPE typedef ptr INTERFACE_TYPE

  IRP_MN_QUERY_DIRECTORY equ 01h
  IRP_MN_NOTIFY_CHANGE_DIRECTORY equ 02h
  IRP_MN_NOTIFY_CHANGE_DIRECTORY_EX equ 03h
  IRP_MN_USER_FS_REQUEST equ 00h
  IRP_MN_MOUNT_VOLUME equ 01h
  IRP_MN_VERIFY_VOLUME equ 02h
  IRP_MN_LOAD_FILE_SYSTEM equ 03h
  IRP_MN_TRACK_LINK equ 04h
  IRP_MN_KERNEL_CALL equ 04h
  IRP_MN_LOCK equ 01h
  IRP_MN_UNLOCK_SINGLE equ 02h
  IRP_MN_UNLOCK_ALL equ 03h
  IRP_MN_UNLOCK_ALL_BY_KEY equ 04h
  IRP_MN_FLUSH_AND_PURGE equ 01h

    IRP_MN_FLUSH_DATA_ONLY equ 02h
    IRP_MN_FLUSH_NO_SYNC equ 03h


    IRP_MN_FLUSH_DATA_SYNC_ONLY equ 04h

  IRP_MN_NORMAL equ 00h
  IRP_MN_DPC equ 01h
  IRP_MN_MDL equ 02h
  IRP_MN_COMPLETE equ 04h
  IRP_MN_COMPRESSED equ 08h
  IRP_MN_MDL_DPC equ <( IRP_MN_MDL or IRP_MN_DPC )>
  IRP_MN_COMPLETE_MDL equ <( IRP_MN_COMPLETE or IRP_MN_MDL )>
  IRP_MN_COMPLETE_MDL_DPC equ <( IRP_MN_COMPLETE_MDL or IRP_MN_DPC )>
  IRP_MN_QUERY_LEGACY_BUS_INFORMATION equ 18h
  IO_CHECK_CREATE_PARAMETERS equ 0200h
  IO_ATTACH_DEVICE equ 0400h
  IO_IGNORE_SHARE_ACCESS_CHECK equ 0800h
  proto_PIO_QUERY_DEVICE_ROUTINE typedef proto fastcall :PVOID, :PUNICODE_STRING, :INTERFACE_TYPE, :DWORD, :ptr PKEY_VALUE_FULL_INFORMATION, :CONFIGURATION_TYPE, :DWORD, :ptr PKEY_VALUE_FULL_INFORMATION, :CONFIGURATION_TYPE, :DWORD, :ptr PKEY_VALUE_FULL_INFORMATION
  PIO_QUERY_DEVICE_ROUTINE typedef ptr proto_PIO_QUERY_DEVICE_ROUTINE
  IO_QUERY_DEVICE_DATA_FORMAT typedef SDWORD
  IoQueryDeviceIdentifier EQU 0 
  IoQueryDeviceConfigurationData EQU 1
  IoQueryDeviceComponentInformation EQU 2
  IoQueryDeviceMaxData EQU 3
  
  PIO_QUERY_DEVICE_DATA_FORMAT typedef ptr IO_QUERY_DEVICE_DATA_FORMAT

    KSPIN_LOCK				typedef	ULONG_PTR
    IFNDEF KDEVICE_QUEUE
    KDEVICE_QUEUE STRUCT	; sizeof = 14h
    	fwType			WORD		IO_TYPE_DEVICE_QUEUE; 14h
    	cbSize			WORD		?					; cb
    	DeviceListHead	LIST_ENTRY	<>
    	ksLock			KSPIN_LOCK	?					; Lock is masm reserved symbol
    	Busy			BOOLEAN		?
    					db			3 dup(?)			; padding
    KDEVICE_QUEUE ENDS
    ENDIF
    PKDEVICE_QUEUE	typedef PTR KDEVICE_QUEUE

  
  DRIVER_REINITIALIZE typedef proto stdcall :ptr _DRIVER_OBJECT,:PVOID,:DWORD
  PDRIVER_REINITIALIZE typedef ptr DRIVER_REINITIALIZE
  CONTROLLER_OBJECT struct
    Type_ CSHORT ?
    Size_ CSHORT ?
    ControllerExtension PVOID ?
    DeviceWaitQueue KDEVICE_QUEUE <>
    Spare1 DWORD ?
    Spare2 LARGE_INTEGER <>
  CONTROLLER_OBJECT ends

  PCONTROLLER_OBJECT typedef ptr CONTROLLER_OBJECT
  
  DO_VERIFY_VOLUME equ 00000002h
  DO_BUFFERED_IO equ 00000004h
  DO_EXCLUSIVE equ 00000008h
  DO_DIRECT_IO equ 00000010h
  DO_MAP_IO_BUFFER equ 00000020h
  DO_DEVICE_HAS_NAME equ 00000040h
  DO_DEVICE_INITIALIZING equ 00000080h
  DO_SYSTEM_BOOT_PARTITION equ 00000100h
  DO_LONG_TERM_REQUESTS equ 00000200h
  DO_NEVER_LAST_DEVICE equ 00000400h
  DO_SHUTDOWN_REGISTERED equ 00000800h
  DO_BUS_ENUMERATED_DEVICE equ 00001000h
  DO_POWER_PAGABLE equ 00002000h
  DO_POWER_INRUSH equ 00004000h
  DO_LOW_PRIORITY_FILESYSTEM equ 00010000h
  DO_SUPPORTS_TRANSACTIONS equ 00040000h
  DO_FORCE_NEITHER_IO equ 00080000h
  DO_VOLUME_DEVICE_OBJECT equ 00100000h
  DO_SYSTEM_SYSTEM_PARTITION equ 00200000h
  DO_SYSTEM_CRITICAL_PARTITION equ 00400000h
  DO_DISALLOW_EXECUTE equ 00800000h
  DO_DEVICE_TO_BE_RESET equ 04000000h
  DO_DEVICE_IRP_REQUIRES_EXTENSION equ 08000000h
  DO_DAX_VOLUME equ 10000000h
  DRVO_REINIT_REGISTERED equ 00000008h
  DRVO_INITIALIZED equ 00000010h
  DRVO_BOOTREINIT_REGISTERED equ 00000020h
  DRVO_LEGACY_RESOURCES equ 00000040h
  CONFIGURATION_INFORMATION struct
    DiskCount DWORD ?
    FloppyCount DWORD ?
    CdRomCount DWORD ?
    TapeCount DWORD ?
    ScsiPortCount DWORD ?
    SerialCount DWORD ?
    ParallelCount DWORD ?
    AtDiskPrimaryAddressClaimed BOOLEAN ?
    AtDiskSecondaryAddressClaimed BOOLEAN ?
    Version DWORD ?
    MediumChangerCount DWORD ?
  CONFIGURATION_INFORMATION ends

  PCONFIGURATION_INFORMATION typedef ptr CONFIGURATION_INFORMATION
 

  IoAssignArcName macro ArcName,DeviceName
   exitm <( IoCreateSymbolicLink ( ( ArcName ) , ( DeviceName ) ) ) >
  endm


  IoDeassignArcName macro ArcName
   exitm <( IoDeleteSymbolicLink ( ( ArcName ) ) ) >
  endm



  DISK_SIGNATURE struct
    PartitionStyle DWORD ?
    union
      struct Mbr
        Signature DWORD ?
        CheckSum DWORD ?
      ends
      struct Gpt
        DiskId GUID <>
      ends
    ends
  DISK_SIGNATURE ends

  PDISK_SIGNATURE typedef ptr DISK_SIGNATURE
  



    IoVolumeDeviceNameToGuid proto fastcall :PUNICODE_STRING, :ptr GUID

    IoVolumeDeviceNameToGuidPath proto fastcall :PUNICODE_STRING, :PUNICODE_STRING
 

    IO_FOEXT_SILO_PARAMETERS struct
      Length_ DWORD ?
      union
        struct
          IO_FOEXT_SILO_PARAMETERS_??24 record HasHardReference_??24:1, SpareFlags_??24:31
          IO_FOEXT_SILO_PARAMETERS_??24 <>
        ends
        Flags DWORD ?
      ends
      SiloContext PESILO ?
    IO_FOEXT_SILO_PARAMETERS ends

    PIO_FOEXT_SILO_PARAMETERS typedef ptr IO_FOEXT_SILO_PARAMETERS
    


  TXN_PARAMETER_BLOCK struct
    Length_ WORD ?
    TxFsContext WORD ?
    TransactionObject PVOID ?
  TXN_PARAMETER_BLOCK ends

  PTXN_PARAMETER_BLOCK typedef ptr TXN_PARAMETER_BLOCK
  
  TXF_MINIVERSION_DEFAULT_VIEW equ 0FFFEh

    PACCESS_TOKEN typedef PVOID

    CREATE_USER_PROCESS_ECP_CONTEXT struct
      Size_ WORD ?
      Reserved WORD ?
      AccessToken PACCESS_TOKEN ?
    CREATE_USER_PROCESS_ECP_CONTEXT ends

    PCREATE_USER_PROCESS_ECP_CONTEXT typedef ptr CREATE_USER_PROCESS_ECP_CONTEXT

    IFNDEF GUID
    GUID STRUCT
       Data1   DWORD   ?
       Data2   WORD   ?
       Data3   WORD   ?
       Data4   BYTE 8 dup(?)
    GUID ENDS
    PGUID typedef ptr GUID
    ENDIF
    
    IFNDEF GUID_DEFINED
    DEFINE_GUID MACRO name_:REQ, l:REQ, w1:REQ, w2:REQ, b1:REQ, b2:REQ, b3:REQ, b4:REQ, b5:REQ, b6:REQ, b7:REQ, b8:REQ
        ;local segn
       ;segn TEXTEQU @CurSeg
       .const
          ALIGN 4
          name_ dd l
                dw w1
                dw w2
                db b1
                db b2
                db b3
                db b4
                db b5
                db b6
                db b7
                db b8
       @CurSeg ENDS
       ;segn SEGMENT
    ENDM
    ENDIF ; GUID_DEFINED

    
    DEFINE_GUID GUID_ECP_CREATE_USER_PROCESS, 0e0e429ffh, 6ddch, 4e65h, 0aah, 0b6h, 45h, 0d0h, 5ah, 3h, 8ah, 8h 

    POPLOCK_KEY_ECP_CONTEXT typedef ptr _OPLOCK_KEY_ECP_CONTEXT
    


    OPLOCK_KEY_CONTEXT struct
      Version WORD ?
      Flags WORD ?
      ParentOplockKey GUID <>
      TargetOplockKey GUID <>
      Reserved DWORD ?
    OPLOCK_KEY_CONTEXT ends

    POPLOCK_KEY_CONTEXT typedef ptr OPLOCK_KEY_CONTEXT
    
    OPLOCK_KEY_VERSION_WIN7 equ 0001h
    OPLOCK_KEY_VERSION_WIN8 equ 0002h
    OPLOCK_KEY_FLAG_PARENT_KEY equ 0001h
    OPLOCK_KEY_FLAG_TARGET_KEY equ 0002h


  IO_DRIVER_CREATE_CONTEXT struct
    Size_ CSHORT ?
    ExtraCreateParameter POINTER ?
    DeviceObjectHint PVOID ?
    TxnParameters PTXN_PARAMETER_BLOCK ?

      SiloContext PESILO ?

  IO_DRIVER_CREATE_CONTEXT ends

  PIO_DRIVER_CREATE_CONTEXT typedef ptr IO_DRIVER_CREATE_CONTEXT
  
  IO_DRIVER_CREATE_CONTEXT_IS_MIN_SIZE macro DriverContext
   exitm <( DriverContext - Size >= ( FIELD_OFFSET ( IO_DRIVER_CREATE_CONTEXT , TxnParameters ) + sizeof ( DriverContext - TxnParameters ) ) ) >
  endm
  IO_DRIVER_CREATE_CONTEXT_CONTAINS_SILO_CONTEXT macro DriverContext
   exitm <( DriverContext - Size >= ( FIELD_OFFSET ( IO_DRIVER_CREATE_CONTEXT , SiloContext ) + sizeof ( DriverContext - SiloContext ) ) ) >
  endm

    IO_USE_AMBIENT_SILO equ ( ( PESILO ) 1 )

  IoInitializeDriverCreateContext proto fastcall :PIO_DRIVER_CREATE_CONTEXT



    BDCB_IMAGEFLAGS_FAILED_CODE_INTEGRITY equ ( 1 shl 0 )
    BDCB_CALLBACK_TYPE typedef SDWORD
    BdCbStatusUpdate EQU 0
    BdCbInitializeImage EQU 1
    
    PBDCB_CALLBACK_TYPE typedef ptr BDCB_CALLBACK_TYPE
    
    BDCB_CLASSIFICATION typedef SDWORD
    BdCbClassificationUnknownImage EQU 0
    BdCbClassificationKnownGoodImage EQU 1
    BdCbClassificationKnownBadImage EQU 2
    BdCbClassificationKnownBadImageBootCritical EQU 3
    BdCbClassificationEnd EQU 4
    
    PBDCB_CLASSIFICATION typedef ptr BDCB_CLASSIFICATION
    
    BDCB_STATUS_UPDATE_TYPE typedef SDWORD
    BdCbStatusPrepareForDependencyLoad EQU 0
    BdCbStatusPrepareForDriverLoad EQU 1
    BdCbStatusPrepareForUnload EQU 2
    
    PBDCB_STATUS_UPDATE_TYPE typedef ptr BDCB_STATUS_UPDATE_TYPE
    
    BDCB_STATUS_UPDATE_CONTEXT struct
      StatusType BDCB_STATUS_UPDATE_TYPE ?
    BDCB_STATUS_UPDATE_CONTEXT ends

    PBDCB_STATUS_UPDATE_CONTEXT typedef ptr BDCB_STATUS_UPDATE_CONTEXT
    
    BDCB_IMAGE_INFORMATION struct
      Classification BDCB_CLASSIFICATION ?
      ImageFlags DWORD ?
      ImageName UNICODE_STRING <>
      RegistryPath UNICODE_STRING <>
      CertificatePublisher UNICODE_STRING <>
      CertificateIssuer UNICODE_STRING <>
      ImageHash PVOID ?
      CertificateThumbprint PVOID ?
      ImageHashAlgorithm DWORD ?
      ThumbprintHashAlgorithm DWORD ?
      ImageHashLength DWORD ?
      CertificateThumbprintLength DWORD ?
    BDCB_IMAGE_INFORMATION ends

    PBDCB_IMAGE_INFORMATION typedef ptr BDCB_IMAGE_INFORMATION
    
    BOOT_DRIVER_CALLBACK_FUNCTION typedef proto stdcall :PVOID,:BDCB_CALLBACK_TYPE,:PBDCB_IMAGE_INFORMATION
    PBOOT_DRIVER_CALLBACK_FUNCTION typedef ptr BOOT_DRIVER_CALLBACK_FUNCTION

    PINTERFACE_REFERENCE typedef ptr QWORD
    PINTERFACE_DEREFERENCE typedef ptr QWORD
    PGET_SET_DEVICE_DATA typedef ptr QWORD

  AGP_TARGET_BUS_INTERFACE_STANDARD struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    SetBusData PGET_SET_DEVICE_DATA ?
    GetBusData PGET_SET_DEVICE_DATA ?
    CapabilityID BYTE ?
  AGP_TARGET_BUS_INTERFACE_STANDARD ends

  PAGP_TARGET_BUS_INTERFACE_STANDARD typedef ptr AGP_TARGET_BUS_INTERFACE_STANDARD
  


  proto_PGET_LOCATION_STRING typedef proto fastcall :PVOID, :ptr PZZWSTR
  PGET_LOCATION_STRING typedef ptr proto_PGET_LOCATION_STRING
  PNP_LOCATION_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    GetLocationString PGET_LOCATION_STRING ?
  PNP_LOCATION_INTERFACE ends

  PPNP_LOCATION_INTERFACE typedef ptr PNP_LOCATION_INTERFACE
  
  ARBITER_ACTION typedef SDWORD
  ArbiterActionTestAllocation EQU 0
  ArbiterActionRetestAllocation EQU 1
  ArbiterActionCommitAllocation EQU 2
  ArbiterActionRollbackAllocation EQU 3
  ArbiterActionQueryAllocatedResources EQU 4
  ArbiterActionWriteReservedResources EQU 5
  ArbiterActionQueryConflict EQU 6
  ArbiterActionQueryArbitrate EQU 7
  ArbiterActionAddReserved EQU 8
  ArbiterActionBootAllocation EQU 9
  
  PARBITER_ACTION typedef ptr ARBITER_ACTION



    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; I/O system definitions.
    ;
    ; Define a Memory Descriptor List (MDL)
    ;
    ; An MDL describes pages in a virtual buffer in terms of physical pages.  The
    ; pages associated with the buffer are described in an array that is allocated
    ; just after the MDL header structure itself.  In a future compiler this will
    ; be placed at:
    ;
    ;      ULONG Pages[];
    ;
    ; Until this declaration is permitted, however, one simply calculates the
    ; base of the array by adding one to the base MDL pointer:
    ;
    ;      Pages = (PULONG) (Mdl + 1);
    ;
    ; Notice that while in the context of the subject thread, the base virtual
    ; address of a buffer mapped by an MDL may be referenced using the following:
    ;
    ;      Mdl->StartVa | Mdl->ByteOffset
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    IFNDEF MDL
    MDL STRUCT			; sizeof= 1Ch
    	Next			PVOID	?	; PTR MDL
    	woSize			WORD	?	; 04h original name Size
    	MdlFlags		WORD	?	; 06h
    	Process			PVOID	?	; 08h PTR EPROCESS
    	MappedSystemVa	PVOID	?	; 0Ch
    	StartVa			PVOID	?	; 10h
    	ByteCount		DWORD	?	; 14h
    	ByteOffset		DWORD	?	; 18h
    MDL ENDS
    ENDIF
    PMDL typedef PTR MDL
    
    MDL_MAPPED_TO_SYSTEM_VA     equ 0001h
    MDL_PAGES_LOCKED            equ 0002h
    MDL_SOURCE_IS_NONPAGED_POOL equ 0004h
    MDL_ALLOCATED_FIXED_SIZE    equ 0008h
    MDL_PARTIAL                 equ 0010h
    MDL_PARTIAL_HAS_BEEN_MAPPED equ 0020h
    MDL_IO_PAGE_READ            equ 0040h
    MDL_WRITE_OPERATION         equ 0080h
    MDL_LOCKED_PAGE_TABLES      equ 0100h
    MDL_PARENT_MAPPED_SYSTEM_VA equ MDL_LOCKED_PAGE_TABLES
    MDL_FREE_EXTRA_PTES         equ 0200h
    MDL_DESCRIBES_AWE           equ 0400h
    MDL_LOCK_HELD               equ 0200h
    MDL_PHYSICAL_VIEW           equ 0400h
    MDL_IO_SPACE                equ 0800h
    MDL_NETWORK_HEADER          equ 1000h
    MDL_MAPPING_CAN_FAIL        equ 2000h
    MDL_PAGE_CONTENTS_INVARIANT equ 4000h
    MDL_ALLOCATED_MUST_SUCCEED  equ MDL_PAGE_CONTENTS_INVARIANT
    MDL_INTERNAL                equ 8000h
    MDL_MAPPING_FLAGS           equ (MDL_MAPPED_TO_SYSTEM_VA or MDL_PAGES_LOCKED or MDL_SOURCE_IS_NONPAGED_POOL or MDL_PARTIAL_HAS_BEEN_MAPPED or MDL_PARENT_MAPPED_SYSTEM_VA or MDL_LOCK_HELD or MDL_SYSTEM_VA or MDL_IO_SPACE)
    

    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ;  The following are masks for the predefined standard access types
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    DELETE                           equ 00010000h
    READ_CONTROL                     equ 00020000h
    WRITE_DAC                        equ 00040000h
    WRITE_OWNER                      equ 00080000h
    SYNCHRONIZE                      equ 00100000h
    STANDARD_RIGHTS_REQUIRED         equ 000F0000h
    STANDARD_RIGHTS_READ             equ READ_CONTROL
    STANDARD_RIGHTS_WRITE            equ READ_CONTROL
    STANDARD_RIGHTS_EXECUTE          equ READ_CONTROL
    STANDARD_RIGHTS_ALL              equ 001F0000h
    SPECIFIC_RIGHTS_ALL              equ 0000FFFFh
    ACCESS_SYSTEM_SECURITY           equ 01000000h
    MAXIMUM_ALLOWED                  equ 02000000h
    GENERIC_READ                     equ 80000000h
    GENERIC_WRITE                    equ 40000000h
    GENERIC_EXECUTE                  equ 20000000h
    GENERIC_ALL                      equ 10000000h

    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ;  Define the generic mapping array.  This is used to denote the
    ;  mapping of each generic access right to a specific access mask.
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    GENERIC_MAPPING STRUCT	; sizeof = 10h
    	GenericRead		DWORD	?
    	GenericWrite	DWORD	?	; 04h
    	GenericExecute	DWORD	?	; 08h
    	GenericAll		DWORD	?	; 0Ch
    GENERIC_MAPPING ENDS
    PGENERIC_MAPPING typedef PTR GENERIC_MAPPING
    
    ; Priority increment definitions.  The comment for each definition gives
    ; the names of the system services that use the definition when satisfying
    ; a wait.
    
    ; Priority increment used when satisfying a wait on an executive event
    ; (NtPulseEvent and NtSetEvent)
    
    EVENT_INCREMENT			equ 1
    
    ; Priority increment when no I/O has been done.  This is used by device
    ; and file system drivers when completing an IRP (IoCompleteRequest).
    
    IO_NO_INCREMENT			equ 0
    
    ; Priority increment for completing CD-ROM I/O.  This is used by CD-ROM device
    ; and file system drivers when completing an IRP (IoCompleteRequest)
    
    IO_CD_ROM_INCREMENT		equ 1
    
    ; Priority increment for completing disk I/O.  This is used by disk device
    ; and file system drivers when completing an IRP (IoCompleteRequest)
    
    IO_DISK_INCREMENT		equ 1
    
    ; Priority increment for completing keyboard I/O.  This is used by keyboard
    ; device drivers when completing an IRP (IoCompleteRequest)
    
    IO_KEYBOARD_INCREMENT	equ 6
    
    ; Priority increment for completing mailslot I/O.  This is used by the mail-
    ; slot file system driver when completing an IRP (IoCompleteRequest).
    
    IO_MAILSLOT_INCREMENT	equ 2
    
    ; Priority increment for completing mouse I/O.  This is used by mouse device
    ; drivers when completing an IRP (IoCompleteRequest)
    
    IO_MOUSE_INCREMENT		equ 6
    
    ; Priority increment for completing named pipe I/O.  This is used by the
    ; named pipe file system driver when completing an IRP (IoCompleteRequest).
    
    IO_NAMED_PIPE_INCREMENT	equ 2
    
    ; Priority increment for completing network I/O.  This is used by network
    ; device and network file system drivers when completing an IRP
    ; (IoCompleteRequest).
    
    IO_NETWORK_INCREMENT	equ 2
    
    ; Priority increment for completing parallel I/O.  This is used by parallel
    ; device drivers when completing an IRP (IoCompleteRequest)
    
    IO_PARALLEL_INCREMENT	equ 1
    
    ; Priority increment for completing serial I/O.  This is used by serial device
    ; drivers when completing an IRP (IoCompleteRequest)
    
    IO_SERIAL_INCREMENT		equ 2
    
    ; Priority increment for completing sound I/O.  This is used by sound device
    ; drivers when completing an IRP (IoCompleteRequest)
    
    IO_SOUND_INCREMENT		equ 8
    
    ; Priority increment for completing video I/O.  This is used by video device
    ; drivers when completing an IRP (IoCompleteRequest)
    
    IO_VIDEO_INCREMENT		equ 1
    
    ; Priority increment used when satisfying a wait on an executive semaphore
    ; (NtReleaseSemaphore)
    
    SEMAPHORE_INCREMENT		equ 1
    
    IFNDEF IO_STATUS_BLOCK
    IO_STATUS_BLOCK STRUCT
    	Status			NTSTATUS	?
    	Information		ULONG_PTR	?
    IO_STATUS_BLOCK ENDS
    ENDIF
    PIO_STATUS_BLOCK typedef PTR IO_STATUS_BLOCK

    IFNDEF 
    IO_STATUS_BLOCK32 struct
    Status NTSTATUS ?
    Information DWORD ?
    IO_STATUS_BLOCK32 ends
    ENDIF
    PIO_STATUS_BLOCK32 typedef ptr IO_STATUS_BLOCK32

    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Asynchronous Procedure Call (APC) object
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    IFNDEF KAPC
    KAPC STRUCT			; sizeof = 30h
    	fwType			WORD		IO_TYPE_APC	; 12h
    	cbSize			WORD		?			; cb
    	Spare0			DWORD		?
    	Thread			PVOID		?			; PTR KTHREAD
    	ApcListEntry	LIST_ENTRY	<>
    	KernelRoutine	PVOID		?			; KiSuspendNop
    	RundownRoutine	PVOID		?
    	NormalRoutine	PVOID		?			; KiSuspendThread
    	NormalContext	PVOID		?
    
    	; N.B. The following two members MUST be together.
    
    	SystemArgument1	PVOID		?
    	SystemArgument2	PVOID		?
    	ApcStateIndex	CHAR		?
    	ApcMode			KPROCESSOR_MODE	?
    	Inserted		BOOLEAN		?
    					db			?			; padding
    KAPC ENDS
    ENDIF
    PKAPC typedef PTR KAPC

    ; Define the format of a completion message.
    
    IO_COMPLETION_CONTEXT STRUCT		; sizeof = 8h
    	Port	PVOID	?
    	Key		PVOID	?
    IO_COMPLETION_CONTEXT ENDS
    PIO_COMPLETION_CONTEXT typedef PTR IO_COMPLETION_CONTEXT



    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Common dispatcher object header
    ; 
    ; N.B. The size field contains the number of dwords in the structure.
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    IFNDEF DISPATCHER_HEADER
    DISPATCHER_HEADER STRUCT		; sizeof = 10h
    	byType			BYTE		?	; DISP_TYPE_* (original name Type)
    	Absolute		BYTE		?
    	cbSize			BYTE		?	; cb
    	Inserted		BYTE		?
    	SignalState		DWORD		?
    	WaitListHead	LIST_ENTRY	<>
    DISPATCHER_HEADER ENDS
    ENDIF
    PDISPATCHER_HEADER typedef ptr DISPATCHER_HEADER
    
    IFNDEF KWAIT_BLOCK
    KWAIT_BLOCK STRUCT		; sizeof = 18h
    	WaitListEntry	LIST_ENTRY	<>
    	Thread			PVOID		?	; PTR KTHREAD
    	Object			PVOID		?
    	NextWaitBlock	PVOID		?	; PTR KWAIT_BLOCK
    	WaitKey			WORD		?
    	WaitType		WORD		?
    KWAIT_BLOCK ENDS
    ENDIF
    PKWAIT_BLOCK typedef PTR KWAIT_BLOCK

    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Event object
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

    KEVENT STRUCT	; sizeof = 10h
    	Header	DISPATCHER_HEADER	<>
    KEVENT ENDS
    PKEVENT typedef PTR KEVENT
    
    IFNDEF KDEVICE_QUEUE
    KDEVICE_QUEUE STRUCT	; sizeof = 14h
    	fwType			WORD		IO_TYPE_DEVICE_QUEUE; 14h
    	cbSize			WORD		?					; cb
    	DeviceListHead	LIST_ENTRY	<>
    	ksLock			KSPIN_LOCK	?					; Lock is masm reserved symbol
    	Busy			BOOLEAN		?
    					db			3 dup(?)			; padding
    KDEVICE_QUEUE ENDS
    ENDIF
    PKDEVICE_QUEUE	typedef PTR KDEVICE_QUEUE
    
    IFNDEF
    KDEVICE_QUEUE_ENTRY STRUCT	; sizeof = 10h
    	DeviceListEntry	LIST_ENTRY	<>
    	SortKey		DWORD		?
    	Inserted	BOOLEAN		?
    				db			3 dup(?)			; padding
    KDEVICE_QUEUE_ENTRY ENDS
    ENDIF
    PKDEVICE_QUEUE_ENTRY typedef PTR KDEVICE_QUEUE_ENTRY
    
    IFNDEF KDPC
    KDPC STRUCT			; sizeof = 20h
    	woType			WORD		IO_TYPE_DPC	; 13h (original name Type)
    	Number			BYTE		?
    	Importance		BYTE		?
    	DpcListEntry	LIST_ENTRY	<>
    	DeferredRoutine	QWORD		?
    	DeferredContext	QWORD		?
    	SystemArgument1	QWORD		?
    	SystemArgument2	QWORD		?
    	DpcData			QWORD		?			; (original Lock)
    KDPC ENDS
    ENDIF
    PKDPC typedef PTR KDPC

    IFNDEF WAIT_CONTEXT_BLOCK
    WAIT_CONTEXT_BLOCK STRUCT	; sizeof = 28h
    	WaitQueueEntry			KDEVICE_QUEUE_ENTRY	<>
    	DeviceRoutine			QWORD				?	; PDRIVER_CONTROL
    	DeviceContext			QWORD				?
    	NumberOfMapRegisters	DWORD				?
    	DeviceObject			QWORD				?
    	CurrentIrp				QWORD				?
    	BufferChainingDpc		QWORD				?	; PKDPC
    WAIT_CONTEXT_BLOCK ENDS
    ENDIF
    PWAIT_CONTEXT_BLOCK typedef PTR WAIT_CONTEXT_BLOCK

    MAXIMUM_VOLUME_LABEL_LENGTH	equ (32 * sizeof(WCHAR))	; 32 characters
    
    IFNDEF VPB
    VPB STRUCT				; sizeof = 58h
    	fwType				WORD			IO_TYPE_VPB	; 0Ah
    	cbSize				WORD			?			; cb
    	Flags				WORD			?
    	VolumeLabelLength	WORD			?			; in bytes without terminat. zero
    	DeviceObject		QWORD			?			; PDEVICE_OBJECT
    	RealDevice			QWORD			?			; PDEVICE_OBJECT
    	SerialNumber		DWORD			?
    	ReferenceCount		DWORD			?
    	VolumeLabel			WORD			(MAXIMUM_VOLUME_LABEL_LENGTH / (sizeof WCHAR)) dup(?)
    VPB ENDS
    ENDIF
    PVPB typedef PTR VPB




    ; The following structure is pointed to by the SectionObject pointer field
    ; of a file object, and is allocated by the various NT file systems.
    
    SECTION_OBJECT_POINTERS STRUCT		; sizeof = 0Ch
    	DataSectionObject	PVOID	?
    	SharedCacheMap		PVOID	?
    	ImageSectionObject	PVOID	?
    SECTION_OBJECT_POINTERS ENDS
    PSECTION_OBJECT_POINTERS typedef PTR SECTION_OBJECT_POINTERS

    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Define File Object (FO) flags
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    FO_FILE_OPEN                    equ 00000001h
    FO_SYNCHRONOUS_IO               equ 00000002h
    FO_ALERTABLE_IO                 equ 00000004h
    FO_NO_INTERMEDIATE_BUFFERING    equ 00000008h
    FO_WRITE_THROUGH                equ 00000010h
    FO_SEQUENTIAL_ONLY              equ 00000020h
    FO_CACHE_SUPPORTED              equ 00000040h
    FO_NAMED_PIPE                   equ 00000080h
    FO_STREAM_FILE                  equ 00000100h
    FO_MAILSLOT                     equ 00000200h
    FO_GENERATE_AUDIT_ON_CLOSE      equ 00000400h
    FO_DIRECT_DEVICE_OPEN           equ 00000800h
    FO_FILE_MODIFIED                equ 00001000h
    FO_FILE_SIZE_CHANGED            equ 00002000h
    FO_CLEANUP_COMPLETE             equ 00004000h
    FO_TEMPORARY_FILE               equ 00008000h
    FO_DELETE_ON_CLOSE              equ 00010000h
    FO_OPENED_CASE_SENSITIVE        equ 00020000h
    FO_HANDLE_CREATED               equ 00040000h
    FO_FILE_FAST_IO_READ            equ 00080000h
    FO_RANDOM_ACCESS                equ 00100000h
    FO_FILE_OPEN_CANCELLED          equ 00200000h
    FO_VOLUME_OPEN                  equ 00400000h
    
    IFNDEF FILE_OBJECT
    FILE_OBJECT STRUCT		; sizeof = 70h
    	fwType				WORD				IO_TYPE_FILE	; 5
    	cbSize				WORD				?				; cb
    	DeviceObject		PVOID				?				; 04h PTR DEVICE_OBJECT
    	Vpb					PVOID				?				; 08h PVPB
    	FsContext			PVOID				?				; 0Ch
    	FsContext2			PVOID				?				; 10h
    	SectionObjectPointer	PSECTION_OBJECT_POINTERS ?		; 14h
    	PrivateCacheMap		PVOID				?				; 18h
    	FinalStatus			NTSTATUS			?				; 1Ch
    	RelatedFileObject	PVOID				?				; 20h PTR FILE_OBJECT
    	LockOperation		BOOLEAN				?				; 24h
    	DeletePending		BOOLEAN				?				; 25h
    	ReadAccess			BOOLEAN				?				; 26h
    	WriteAccess			BOOLEAN				?				; 27h
    	DeleteAccess		BOOLEAN				?				; 28h
    	SharedRead			BOOLEAN				?				; 29h
    	SharedWrite			BOOLEAN				?				; 2Ah
    	SharedDelete		BOOLEAN				?				; 2Bh
    	Flags				DWORD				?				; 2Ch FO_*
    	FileName			UNICODE_STRING		<>				; 30h
    	CurrentByteOffset	LARGE_INTEGER		<>				; 38h
    	Waiters				DWORD				?				; 40h
    	Busy				DWORD				?				; 44h
    	LastLock			PVOID				?				; 48h
    	kevLock				KEVENT				<>				; 4Ch Lock is masm reserved symbol
    	Event_			    KEVENT				<>				; 5Ch
    	CompletionContext	PIO_COMPLETION_CONTEXT	?			; 6Ch
        IrpListLock         KSPIN_LOCK ?
        IrpList             LIST_ENTRY <>
        FileObjectExtension PVOID ?    	
    FILE_OBJECT ENDS
    ENDIF
    PFILE_OBJECT typedef PTR FILE_OBJECT


    IFNDEF DEVICE_OBJECT
    DEVICE_OBJECT STRUCT	; sizeof = 0B8h
    	fwType				WORD			IO_TYPE_DEVICE	; 3
    	cbSize				WORD			?	; 02h
    	ReferenceCount		DWORD			?	; 04h
    	DriverObject		QWORD			?	; 08h PDRIVER_OBJECT
    	NextDevice			QWORD			?	; 0Ch PDEVICE_OBJECT
    	AttachedDevice		QWORD			?	; 10h PDEVICE_OBJECT
    	CurrentIrp			QWORD			?	; 14h PTR _IRP
    	Timer				QWORD			?	; 18h PIO_TIMER
    	Flags				DWORD			?	; 1Ch DO_*
    	Characteristics		DWORD			?	; 20h FILE_*
    	Vpb					PVPB			?	; 24h PTR VPB
    	DeviceExtension		QWORD			?	; 28h 
    	DeviceType			DEVICE_TYPE		?	; 2Ch
    	StackSize			CHAR			?	; 30h
    						db		3 dup(?)	; padding
    	UNION Queue
    		ListEntry		LIST_ENTRY		<>	; 34h
    		Wcb				WAIT_CONTEXT_BLOCK <>	; 34h
    	ENDS ; Queue
    	AlignmentRequirement	DWORD		?	; 5Ch
    	DeviceQueue			KDEVICE_QUEUE	<>	; 60h
    	Dpc					KDPC			<>	; 74h
    
    	; The following field is for exclusive use by the filesystem to keep
    	; track of the number of Fsp threads currently using the device
    
    	ActiveThreadCount	DWORD			?	; 94h
    	SecurityDescriptor	PSECURITY_DESCRIPTOR ?	; 98h
    	DeviceLock			KEVENT			<>	; 9Ch
    
    	SectorSize			WORD			?	; 0ACh
    	Spare1				WORD			?	; 0AEh
    
    	DeviceObjectExtension	QWORD		?	; 0B0h PDEVOBJ_EXTENSION
    	Reserved				PVOID		?	; 0B4h
    DEVICE_OBJECT ENDS
    ENDIF
    PDEVICE_OBJECT TYPEDEF PTR DEVICE_OBJECT

    IFNDEF DEVOBJ_EXTENSION
    DEVOBJ_EXTENSION STRUCT		; sizeof = 8h
    	woType			WORD			IO_TYPE_DEVICE_OBJECT_EXTENSION	; 00h (original name Type)
    	cbSize			WORD			?						; 02h (original name Size)
    	; Public part of the DeviceObjectExtension structure
    	DeviceObject	PDEVICE_OBJECT	?						; 04h owning device object
        PowerFlags DWORD ?
        Dope POINTER ?
        ExtensionFlags DWORD ?
        DeviceNode PVOID ?
        AttachedTo PDEVICE_OBJECT ?
        StartIoCount SDWORD ?
        StartIoKey SDWORD ?
        StartIoFlags DWORD ?
        Vpb PVPB ?
        DependencyNode PVOID ?
        InterruptContext PVOID ?
        VerifierContext PVOID ?
    DEVOBJ_EXTENSION ENDS
    ENDIF
    PDEVOBJ_EXTENSION typedef PTR DEVOBJ_EXTENSION
  
    ; Define I/O system data structure type codes.  Each major data structure in
    ; the I/O system has a type code  The type field in each structure is at the
    ; same offset.  The following values can be used to determine which type of
    ; data structure a pointer refers to.
    
    IO_TYPE_ADAPTER					equ 1
    IO_TYPE_CONTROLLER				equ 2
    IO_TYPE_DEVICE					equ 3
    IO_TYPE_DRIVER					equ 4
    IO_TYPE_FILE					equ 5
    IO_TYPE_IRP						equ 6
    IO_TYPE_MASTER_ADAPTER			equ 7
    IO_TYPE_OPEN_PACKET				equ 8
    IO_TYPE_TIMER					equ 9
    IO_TYPE_VPB						equ 0Ah
    IO_TYPE_ERROR_LOG				equ 0Bh
    IO_TYPE_ERROR_MESSAGE			equ 0Ch
    IO_TYPE_DEVICE_OBJECT_EXTENSION	equ 0Dh
    
    IO_TYPE_APC						equ 12h
    IO_TYPE_DPC						equ 13h
    IO_TYPE_DEVICE_QUEUE			equ 14h
    IO_TYPE_EVENT_PAIR				equ 15h
    IO_TYPE_INTERRUPT				equ 16h
    IO_TYPE_PROFILE					equ 17h
    
    
    ; Define the major function codes for IRPs.
    
    IRP_MJ_CREATE					equ 0
    IRP_MJ_CREATE_NAMED_PIPE		equ 1
    IRP_MJ_CLOSE					equ 2
    IRP_MJ_READ						equ 3
    IRP_MJ_WRITE					equ 4
    IRP_MJ_QUERY_INFORMATION		equ 5
    IRP_MJ_SET_INFORMATION			equ 6
    IRP_MJ_QUERY_EA					equ 7
    IRP_MJ_SET_EA					equ 8
    IRP_MJ_FLUSH_BUFFERS			equ 9
    IRP_MJ_QUERY_VOLUME_INFORMATION	equ 0Ah
    IRP_MJ_SET_VOLUME_INFORMATION	equ 0Bh
    IRP_MJ_DIRECTORY_CONTROL		equ 0Ch
    IRP_MJ_FILE_SYSTEM_CONTROL		equ 0Dh
    IRP_MJ_DEVICE_CONTROL			equ 0Eh
    IRP_MJ_INTERNAL_DEVICE_CONTROL	equ 0Fh
    IRP_MJ_SHUTDOWN					equ 10h
    IRP_MJ_LOCK_CONTROL				equ 11h
    IRP_MJ_CLEANUP					equ 12h
    IRP_MJ_CREATE_MAILSLOT			equ 13h
    IRP_MJ_QUERY_SECURITY			equ 14h
    IRP_MJ_SET_SECURITY				equ 15h
    IRP_MJ_POWER					equ 16h
    IRP_MJ_SYSTEM_CONTROL			equ 17h
    IRP_MJ_DEVICE_CHANGE			equ 18h
    IRP_MJ_QUERY_QUOTA				equ 19h
    IRP_MJ_SET_QUOTA				equ 1Ah
    IRP_MJ_PNP						equ 1Bh
    IRP_MJ_PNP_POWER				equ IRP_MJ_PNP	; Obsolete....
    IRP_MJ_MAXIMUM_FUNCTION			equ 1Bh
    IRP_MJ_SCSI                     equ IRP_MJ_INTERNAL_DEVICE_CONTROL

    IRP_MN_SCSI_CLASS               equ 01h
    IRP_MN_START_DEVICE             equ 00h
    IRP_MN_QUERY_REMOVE_DEVICE      equ 01h
    IRP_MN_REMOVE_DEVICE            equ 02h
    IRP_MN_CANCEL_REMOVE_DEVICE     equ 03h
    IRP_MN_STOP_DEVICE              equ 04h
    IRP_MN_QUERY_STOP_DEVICE        equ 05h
    IRP_MN_CANCEL_STOP_DEVICE       equ 06h
    IRP_MN_QUERY_DEVICE_RELATIONS   equ 07h
    IRP_MN_QUERY_INTERFACE          equ 08h
    IRP_MN_QUERY_CAPABILITIES       equ 09h
    IRP_MN_QUERY_RESOURCES          equ 0Ah
    IRP_MN_QUERY_RESOURCE_REQUIREMENTS equ 0Bh
    IRP_MN_QUERY_DEVICE_TEXT        equ 0Ch
    IRP_MN_FILTER_RESOURCE_REQUIREMENTS equ 0Dh
    IRP_MN_READ_CONFIG              equ 0Fh
    IRP_MN_WRITE_CONFIG             equ 10h
    IRP_MN_EJECT                    equ 11h
    IRP_MN_SET_LOCK                 equ 12h
    IRP_MN_QUERY_ID                 equ 13h
    IRP_MN_QUERY_PNP_DEVICE_STATE   equ 14h
    IRP_MN_QUERY_BUS_INFORMATION    equ 15h
    IRP_MN_DEVICE_USAGE_NOTIFICATION equ 16h
    IRP_MN_SURPRISE_REMOVAL         equ 17h
    IRP_MN_DEVICE_ENUMERATED        equ 19h
    IRP_MN_WAIT_WAKE                equ 00h
    IRP_MN_POWER_SEQUENCE           equ 01h
    IRP_MN_SET_POWER                equ 02h
    IRP_MN_QUERY_POWER              equ 03h
    IRP_MN_QUERY_ALL_DATA           equ 00h
    IRP_MN_QUERY_SINGLE_INSTANCE    equ 01h
    IRP_MN_CHANGE_SINGLE_INSTANCE   equ 02h
    IRP_MN_CHANGE_SINGLE_ITEM       equ 03h
    IRP_MN_ENABLE_EVENTS            equ 04h
    IRP_MN_DISABLE_EVENTS           equ 05h
    IRP_MN_ENABLE_COLLECTION        equ 06h
    IRP_MN_DISABLE_COLLECTION       equ 07h
    IRP_MN_REGINFO                  equ 08h
    IRP_MN_EXECUTE_METHOD           equ 09h
    IRP_MN_REGINFO_EX               equ 0bh

    PDRIVER_ADD_DEVICE typedef QWORD

    IFNDEF DRIVER_EXTENSION
    DRIVER_EXTENSION STRUCT		; sizeof = 14h
    	; Back pointer to Driver Object
    	DriverObject	POINTER			?	; PDRIVER_OBJECT
    	; The AddDevice entry point is called by the Plug & Play manager
    	; to inform the driver when a new device instance arrives that this
    	; driver must control.
    	AddDevice		PDRIVER_ADD_DEVICE			?	; 04h PDRIVER_ADD_DEVICE
    	; The count field is used to count the number of times the driver has
    	; had its registered reinitialization routine invoked.
    	Count			DWORD			?	; 08h
    	; The service name field is used by the pnp manager to determine
    	; where the driver related info is stored in the registry.
    	ServiceKeyName	UNICODE_STRING	<>	; 0Ch
    	; Note: any new shared fields get added here.
    ; kd displays additional field
    ;+14 struct   _IO_CLIENT_EXTENSION *ClientDriverExtension
        ClientDriverExtension QWORD ? ; ptr to IO_CLIENT_EXTENSION 
        FsFilterCallbacks QWORD ? ; ptr to FS_FILTER_CALLBACKS 
        KseCallbacks QWORD ?
        DvCallbacks QWORD ?
        VerifierContext QWORD ?
    DRIVER_EXTENSION ENDS
    ENDIF
    PDRIVER_EXTENSION typedef PTR DRIVER_EXTENSION

    IFNDEF DRIVER_OBJECT
    DRIVER_OBJECT STRUCT	; sizeof= 0A8h
    	fwType			WORD			IO_TYPE_DRIVER	; 4
    	cbSize			WORD			?			; cb
    	; The following links all of the devices created by a single driver
    	; together on a list, and the Flags word provides an extensible flag
    	; location for driver objects.
    	DeviceObject	PDEVICE_OBJECT	?
    	Flags			DWORD			?
    	; The following section describes where the driver is loaded.  The count
    	; field is used to count the number of times the driver has had its
    	; registered reinitialization routine invoked.
    	DriverStart		PVOID			?
    	DriverSize		DWORD			?
    	DriverSection	PVOID			?
    	DriverExtension	PDRIVER_EXTENSION	?
    	; The driver name field is used by the error log thread
    	; determine the name of the driver that an I/O request is/was bound.
    	DriverName		UNICODE_STRING	<>
    	; The following section is for registry support.  Thise is a pointer
    	; to the path to the hardware information in the registry
    	HardwareDatabase	PUNICODE_STRING	?
    	; The following section contains the optional pointer to an array of
    	; alternate entry points to a driver for "fast I/O" support.  Fast I/O
    	; is performed by invoking the driver routine directly with separate
    	; parameters, rather than using the standard IRP call mechanism.  Note
    	; that these functions may only be used for synchronous I/O, and when
    	; the file is cached.
    	FastIoDispatch	PVOID			?
    	; The following section describes the entry points to this particular
    	; driver.  Note that the major function dispatch table must be the last
    	; field in the object so that it remains extensible.
    	DriverInit		PVOID			?
    	DriverStartIo	PVOID			?
    	DriverUnload	PVOID			?
    	MajorFunction	PVOID			(IRP_MJ_MAXIMUM_FUNCTION + 1) dup(?)
    DRIVER_OBJECT ENDS
    ENDIF
    PDRIVER_OBJECT typedef PTR DRIVER_OBJECT
  
  
  
    IRP_NOCACHE                     equ 00000001h
    IRP_PAGING_IO                   equ 00000002h
    IRP_MOUNT_COMPLETION            equ 00000002h
    IRP_SYNCHRONOUS_API             equ 00000004h
    IRP_ASSOCIATED_IRP              equ 00000008h
    IRP_BUFFERED_IO                 equ 00000010h
    IRP_DEALLOCATE_BUFFER           equ 00000020h
    IRP_INPUT_OPERATION             equ 00000040h
    IRP_SYNCHRONOUS_PAGING_IO       equ 00000040h
    IRP_CREATE_OPERATION            equ 00000080h
    IRP_READ_OPERATION              equ 00000100h
    IRP_WRITE_OPERATION             equ 00000200h
    IRP_CLOSE_OPERATION             equ 00000400h
    
    IRP_DEFER_IO_COMPLETION         equ 00000800h
    IRP_OB_QUERY_NAME               equ 00001000h
    IRP_HOLD_DEVICE_QUEUE           equ 00002000h
    IRP_RETRY_IO_COMPLETION         equ 00004000h
    
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Define I/O request packet (IRP) alternate flags for allocation control.
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    IRP_QUOTA_CHARGED               equ 01h
    IRP_ALLOCATED_MUST_SUCCEED      equ 02h
    IRP_ALLOCATED_FIXED_SIZE        equ 04h
    IRP_LOOKASIDE_ALLOCATION        equ 08h
    
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; I/O Request Packet (IRP) definition
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    IFNDEF _IRP
    _IRP STRUCT			; sizeof = 70h
    	fwType			WORD	?
    	cbSize			WORD	?	; 02h
    
    	; Define the common fields used to control the IRP.
    
    	; Define a pointer to the Memory Descriptor List (MDL) for this I/O
    	; request.  This field is only used if the I/O is "direct I/O".
    
    	MdlAddress		PVOID	?		; 04h PMDL
    
    	; Flags word - used to remember various flags.
    
    	Flags			DWORD	?		; 08h
    
    	; The following union is used for one of three purposes:
    	;
    	; 1. This IRP is an associated IRP.  The field is a pointer to a master IRP.
    	;
    	; 2. This is the master IRP.  The field is the count of the number of
    	; IRPs which must complete (associated IRPs) before the master can
    	; complete.
    	;
    	; 3. This operation is being buffered and the field is the address of
    	; the system space buffer.
    
    	UNION AssociatedIrp
    		MasterIrp		PVOID	?	; 0Ch PIRP
    		IrpCount		DWORD	?	; 0Ch 
    		SystemBuffer	PVOID	?	; 0Ch 
    	ENDS	; AssociatedIrp
    
    	; Thread list entry - allows queueing the IRP to the thread pending I/O
    	; request packet list.
    
    	ThreadListEntry	LIST_ENTRY	<>	; 10h
    
    	; I/O status - final status of operation.
    
    	IoStatus		IO_STATUS_BLOCK	<>	; 18h
    
    	; Requestor mode - mode of the original requestor of this operation.
    
    	RequestorMode	BYTE	?	; 20h KPROCESSOR_MODE
    
    	; Pending returned - TRUE if pending was initially returned as the
    	; status for this packet.
    
    	PendingReturned	BYTE	?	; 21h
    
    	; Stack state information.
    
    	StackCount		BYTE	?	; 22h
    	CurrentLocation	BYTE	?	; 23h
    
    	; Cancel - packet has been canceled.
    
    	Cancel			BYTE	?	; 24h
    
    	; Cancel Irql - Irql at which the cancel spinlock was acquired.
    
    	CancelIrql		BYTE	?	; 25h
    
    	; ApcEnvironment - Used to save the APC environment at the time that the
    	; packet was initialized.
    
    	ApcEnvironment	BYTE	?	; 26h
    
    	; Allocation control flags.
    
    	AllocationFlags	BYTE	?	; 27h
    
    	; User parameters.
    
    	UserIosb		PIO_STATUS_BLOCK	?	; 28h
    	UserEvent		PKEVENT				?	; 2Ch
    	UNION Overlay							; 30h
    		STRUCT AsynchronousParameters		; 30h
    			UserApcRoutine	PVOID	?	; 30h PIO_APC_ROUTINE
    			UserApcContext	PVOID	?	; 34h
    		ENDS	; AsynchronousParameters
    		AllocationSize		LARGE_INTEGER	<>	; 30h
    	ENDS	; Overlay
    
    	; CancelRoutine - Used to contain the address of a cancel routine supplied
    	; by a device driver when the IRP is in a cancelable state.
    
    	CancelRoutine	PVOID		?		; 38h PDRIVER_CANCEL
    
    	; Note that the UserBuffer parameter is outside of the stack so that I/O
    	; completion can copy data back into the user's address space without
    	; having to know exactly which service was being invoked.  The length
    	; of the copy is stored in the second half of the I/O status block. If
    	; the UserBuffer field is NULL, then no copy is performed.
    
    	UserBuffer		PVOID		?	; 3Ch
    
    	; Kernel structures
    	;
    	; The following section contains kernel structures which the IRP needs
    	; in order to place various work information in kernel controller system
    	; queues.  Because the size and alignment cannot be controlled, they are
    	; placed here at the end so they just hang off and do not affect the
    	; alignment of other fields in the IRP.
    
    	UNION Tail
    		STRUCT Overlay
    			UNION
    				; DeviceQueueEntry - The device queue entry field is used to
    				; queue the IRP to the device driver device queue.
    
    				DeviceQueueEntry	KDEVICE_QUEUE_ENTRY	<>
    
    				STRUCT
    					; The following are available to the driver to use in
    					; whatever manner is desired, while the driver owns the
    					; packet.
    					DriverContext	PVOID	4 dup(?)
    				ENDS
    
    			ENDS
    
    			; Thread - pointer to caller's Thread Control Block.
    
    			Thread				PVOID	?			; PETHREAD
    
    			; Auxiliary buffer - pointer to any auxiliary buffer that is
    			; required to pass information to a driver that is not contained
    			; in a normal buffer.
    
    			AuxiliaryBuffer		PCHAR	?
    
    			; The following unnamed structure must be exactly identical
    			; to the unnamed structure used in the minipacket header used
    			; for completion queue entries.
    
    			STRUCT
    
    				; List entry - used to queue the packet to completion queue, among
    				; others.
    
    				ListEntry		LIST_ENTRY	<>
    
    				UNION
    
    					; Current stack location - contains a pointer to the current
    					; IO_STACK_LOCATION structure in the IRP stack.  This field
    					; should never be directly accessed by drivers.  They should
    					; use the standard functions.
    					CurrentStackLocation	PVOID	?	; PTR IO_STACK_LOCATION
    
    					; Minipacket type.
    
    					PacketType				DWORD	?
    				ENDS
    			ENDS
    
    			; Original file object - pointer to the original file object
    			; that was used to open the file.  This field is owned by the
    			; I/O system and should not be used by any other drivers.
    
    			OriginalFileObject	PFILE_OBJECT	?
    
    		ENDS	; Overlay
    
    		; APC - This APC control block is used for the special kernel APC as
    		; well as for the caller's APC, if one was specified in the original
    		; argument list.  If so, then the APC is reused for the normal APC for
    		; whatever mode the caller was in and the "special" routine that is
    		; invoked before the APC gets control simply deallocates the IRP.
    
    		Apc		KAPC	<>
    
    		; CompletionKey - This is the key that is used to distinguish
    		; individual I/O operations initiated on a single file handle.
    
    		CompletionKey	PVOID	?
    
    	ENDS	;Tail
    
    _IRP ENDS
    ENDIF
    PIRP typedef PTR _IRP
  
    IFNDEF IO_STACK_LOCATION
    IO_STACK_LOCATION STRUCT	; sizeof = 24h
    	MajorFunction		BYTE	?	; 00h
    	MinorFunction		BYTE	?	; 01h
    	Flags				BYTE	?	; 02h
    	Control				BYTE	?	; 03h
    
    	; The following user parameters are based on the service that is being
    	; invoked.  Drivers and file systems can determine which set to use based
    	; on the above major and minor function codes.
    
    	union Parameters				; 04h
    
    		; System service parameters for:  NtCreateFile
    
    		struct Create				; 04h
    			SecurityContext		PVOID	?	; 04h PTR IO_SECURITY_CONTEXT
    			Options				DWORD	?	; 08h
    			; if _WIN64
    			;	POINTER_ALIGNMENT DECLSPEC_ALIGN(8)
    			; endif
    			FileAttributes		WORD	?	; 0Ch POINTER_ALIGNMENT
    			ShareAccess			WORD	?	; 0Eh
    			EaLength			DWORD	?	; 10h POINTER_ALIGNMENT
    		ends	; Create
    
    		; System service parameters for:  NtReadFile
    
    		struct Read					; 04h
    			dwLength			DWORD	?	; 04h
    			Key					DWORD	?	; 08h POINTER_ALIGNMENT
    			ByteOffset			LARGE_INTEGER	<>	; 0Ch
    		ends	; Read
    
    		; System service parameters for:  NtWriteFile
    
    		struct Write				; 04h
    			dwLength			DWORD	?	; 04h
    			Key					DWORD	?	; 08h POINTER_ALIGNMENT
    			ByteOffset			LARGE_INTEGER	<>	; 0Ch
    		ends	; Write
    
    		; System service parameters for:  NtQueryInformationFile
    
    		struct QueryFile
    			dwLength				DWORD	?	; 04h original field name Length
    			FileInformationClass	DWORD	?	; 08h POINTER_ALIGNMENT
    		ends	; QueryFile
    
    
    		; System service parameters for:  NtFlushBuffersFile
    		;
    		; No extra user-supplied parameters.
    
    		; System service parameters for:  NtDeviceIoControlFile
    		; 
    		; Note that the user's output buffer is stored in the UserBuffer field
    		; and the user's input buffer is stored in the SystemBuffer field.
    
    		struct DeviceIoControl		; 04h
    			OutputBufferLength		DWORD	?	; 04h
    			InputBufferLength		DWORD	?	; 08h POINTER_ALIGNMENT
    			IoControlCode			DWORD	?	; 0Ch POINTER_ALIGNMENT
    			Type3InputBuffer		PVOID	?	; 10h
    		ends	; DeviceIoControl
    
    		; Parameters for IRP_MN_READ_CONFIG and IRP_MN_WRITE_CONFIG
    
    		struct ReadWriteConfig			; 04h
    			WhichSpace		DWORD	?	; 04h
    			Buffer			PVOID	?	; 08h
    			dwOffset		DWORD	?	; 0Ch
    			wdLength		DWORD	?	; 10h POINTER_ALIGNMENT (original field name Length)
    		ends
    
    		; Parameters for IRP_MN_SET_LOCK
    
    		struct SetLock					; 04h
    			bLock			BOOLEAN	?	; 04h (original name Lock)
    							db 3 dup(?)	; padding ???
    		ends
    
    		; Others - driver-specific
    
    		struct Others
    			Argument1	PVOID	?
    			Argument2	PVOID	?
    			Argument3	PVOID	?
    			Argument4	PVOID	?
    		ends
    
    	ends	; Parameters
    
    	; Save a pointer to this device driver's device object for this request
    	; so it can be passed to the completion routine if needed.
    
    	DeviceObject		PDEVICE_OBJECT	?
    
    	; The following location contains a pointer to the file object for this
    
    	FileObject			PFILE_OBJECT	?
    
    	; The following routine is invoked depending on the flags in the above
    	; flags field.
    
    	CompletionRoutine	PVOID	?	; PIO_COMPLETION_ROUTINE
    
    	; The following is used to store the address of the context parameter
    	; that should be passed to the CompletionRoutine.
    
    	Context				PVOID	?
    
    IO_STACK_LOCATION ENDS
    ENDIF
    PIO_STACK_LOCATION typedef PTR IO_STACK_LOCATION


    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; PIO_STACK_LOCATION IoGetCurrentIrpStackLocation( IN PIRP Irp )
    ;
    ; Macro Description:
    ;
    ;     This macro is invoked to return a pointer to the current stack location
    ;     in an I/O Request Packet (IRP).
    ;
    ; Arguments:
    ;
    ;     Irp - Pointer to the I/O Request Packet.
    ;
    ; Return Value:
    ;
    ;     The function value is a pointer to the current stack location in the
    ;     packet.
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    IoGetCurrentIrpStackLocation MACRO pIrp:REQ
    	IFDIFI <pIrp>, <rax>	;; don't move eax onto itself
    		mov rax, pIrp
    	ENDIF
    	mov rax, (_IRP PTR [rax]).Tail.Overlay.CurrentStackLocation
    ENDM
  
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Define share access rights to files and directories
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    FILE_SHARE_READ                 equ 1
    FILE_SHARE_WRITE                equ 2
    FILE_SHARE_DELETE               equ 4
    FILE_SHARE_VALID_FLAGS          equ 7
    
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Define the file attributes values
    ;
    ; Note:  0x00000008 is reserved for use for the old DOS VOLID (volume ID)
    ;         and is therefore not considered valid in NT.
    ;
    ; Note:  0x00000010 is reserved for use for the old DOS SUBDIRECTORY flag
    ;         and is therefore not considered valid in NT.  This flag has
    ;         been disassociated with file attributes since the other flags are
    ;         protected with READ_ and WRITE_ATTRIBUTES access to the file.
    ;
    ; Note:  Note also that the order of these flags is set to allow both the
    ;         FAT and the Pinball File Systems to directly set the attributes
    ;         flags in attributes words without having to pick each flag out
    ;         individually.  The order of these flags should not be changed!
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    FILE_ATTRIBUTE_READONLY             equ 00000001h
    FILE_ATTRIBUTE_HIDDEN               equ 00000002h
    FILE_ATTRIBUTE_SYSTEM               equ 00000004h
    
    FILE_ATTRIBUTE_DIRECTORY            equ 00000010h
    FILE_ATTRIBUTE_ARCHIVE              equ 00000020h
    FILE_ATTRIBUTE_DEVICE               equ 00000040h
    FILE_ATTRIBUTE_NORMAL               equ 00000080h
    
    FILE_ATTRIBUTE_TEMPORARY            equ 00000100h
    FILE_ATTRIBUTE_SPARSE_FILE          equ 00000200h
    FILE_ATTRIBUTE_REPARSE_POINT        equ 00000400h
    FILE_ATTRIBUTE_COMPRESSED           equ 00000800h
    
    FILE_ATTRIBUTE_OFFLINE              equ 00001000h
    FILE_ATTRIBUTE_NOT_CONTENT_INDEXED  equ 00002000h
    
    ; defined in windows.inc as:
    ;     FILE_ATTRIBUTE_ENCRYPTED equ 00000040h
    
    ;FILE_ATTRIBUTE_ENCRYPTED            equ 00004000h
    
    ; This definition is old and will disappear shortly
    
    FILE_ATTRIBUTE_CONTENT_INDEXED  equ FILE_ATTRIBUTE_NOT_CONTENT_INDEXED
    
    FILE_ATTRIBUTE_VALID_FLAGS      equ 00007fb7h
    FILE_ATTRIBUTE_VALID_SET_FLAGS  equ 000031a7h
    
    ; Define the create disposition values
    
    FILE_SUPERSEDE                  equ 0
    FILE_OPEN                       equ 1
    FILE_CREATE                     equ 2
    FILE_OPEN_IF                    equ 3
    FILE_OVERWRITE                  equ 4
    FILE_OVERWRITE_IF               equ 5
    FILE_MAXIMUM_DISPOSITION        equ 5
    
    ; Define the create/open option flags
    
    FILE_DIRECTORY_FILE                     equ 00000001h
    FILE_WRITE_THROUGH                      equ 00000002h
    FILE_SEQUENTIAL_ONLY                    equ 00000004h
    FILE_NO_INTERMEDIATE_BUFFERING          equ 00000008h
    
    FILE_SYNCHRONOUS_IO_ALERT               equ 00000010h
    FILE_SYNCHRONOUS_IO_NONALERT            equ 00000020h
    FILE_NON_DIRECTORY_FILE                 equ 00000040h
    FILE_CREATE_TREE_CONNECTION             equ 00000080h
    
    FILE_COMPLETE_IF_OPLOCKED               equ 00000100h
    FILE_NO_EA_KNOWLEDGE                    equ 00000200h
    FILE_OPEN_FOR_RECOVERY                  equ 00000400h
    FILE_RANDOM_ACCESS                      equ 00000800h
    
    FILE_DELETE_ON_CLOSE                    equ 00001000h
    FILE_OPEN_BY_FILE_ID                    equ 00002000h
    FILE_OPEN_FOR_BACKUP_INTENT             equ 00004000h
    FILE_NO_COMPRESSION                     equ 00008000h
    
    FILE_RESERVE_OPFILTER                   equ 00100000h
    FILE_OPEN_REPARSE_POINT                 equ 00200000h
    FILE_OPEN_NO_RECALL                     equ 00400000h
    FILE_OPEN_FOR_FREE_SPACE_QUERY          equ 00800000h
    
    FILE_COPY_STRUCTURED_STORAGE            equ 00000041h
    FILE_STRUCTURED_STORAGE                 equ 00000441h
    
    FILE_VALID_OPTION_FLAGS                 equ 00ffffffh
    FILE_VALID_PIPE_OPTION_FLAGS            equ 00000032h
    FILE_VALID_MAILSLOT_OPTION_FLAGS        equ 00000032h
    FILE_VALID_SET_FLAGS                    equ 00000036h
    
    ; Define the I/O status information return values for NtCreateFile/NtOpenFile
    
    FILE_SUPERSEDED                 equ 0
    FILE_OPENED                     equ 1
    FILE_CREATED                    equ 2
    FILE_OVERWRITTEN                equ 3
    FILE_EXISTS                     equ 4
    FILE_DOES_NOT_EXIST             equ 5
    
    ; Define special ByteOffset parameters for read and write operations
    
    FILE_WRITE_TO_END_OF_FILE       equ ffffffffh
    FILE_USE_FILE_POINTER_POSITION  equ fffffffeh
    
    ; Define alignment requirement values
    
    FILE_BYTE_ALIGNMENT             equ 00000000h
    FILE_WORD_ALIGNMENT             equ 00000001h
    FILE_LONG_ALIGNMENT             equ 00000003h
    FILE_QUAD_ALIGNMENT             equ 00000007h
    FILE_OCTA_ALIGNMENT             equ 0000000fh
    FILE_32_BYTE_ALIGNMENT          equ 0000001fh
    FILE_64_BYTE_ALIGNMENT          equ 0000003fh
    FILE_128_BYTE_ALIGNMENT         equ 0000007fh
    FILE_256_BYTE_ALIGNMENT         equ 000000ffh
    FILE_512_BYTE_ALIGNMENT         equ 000001ffh
    
    ; Define the maximum length of a filename string
    
    MAXIMUM_FILENAME_LENGTH         equ 256
    
    ; Define the various device characteristics flags
    
    FILE_REMOVABLE_MEDIA            equ 00000001h
    FILE_READ_ONLY_DEVICE           equ 00000002h
    FILE_FLOPPY_DISKETTE            equ 00000004h
    FILE_WRITE_ONCE_MEDIA           equ 00000008h
    FILE_REMOTE_DEVICE              equ 00000010h
    FILE_DEVICE_IS_MOUNTED          equ 00000020h
    FILE_VIRTUAL_VOLUME             equ 00000040h
    FILE_AUTOGENERATED_DEVICE_NAME  equ 00000080h
    FILE_DEVICE_SECURE_OPEN         equ 00000100h
    
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; flags specified here will be propagated up and down a device stack
    ; after FDO and all filter devices are added, but before the device
    ; stack is started
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    FILE_CHARACTERISTICS_PROPAGATED equ FILE_REMOVABLE_MEDIA or FILE_READ_ONLY_DEVICE or FILE_FLOPPY_DISKETTE or FILE_WRITE_ONCE_MEDIA or FILE_DEVICE_SECURE_OPEN
  

    ; enum FILE_INFORMATION_CLASS
    FileDirectoryInformation EQU 1 
    FileFullDirectoryInformation EQU 2
    FileBothDirectoryInformation EQU 3
    FileBasicInformation EQU 4
    FileStandardInformation EQU 5
    FileInternalInformation EQU 6
    FileEaInformation EQU 7
    FileAccessInformation EQU 8
    FileNameInformation EQU 9
    FileRenameInformation EQU 10
    FileLinkInformation EQU 11
    FileNamesInformation EQU 12
    FileDispositionInformation EQU 13
    FilePositionInformation EQU 14
    FileFullEaInformation EQU 15
    FileModeInformation EQU 16
    FileAlignmentInformation EQU 17
    FileAllInformation EQU 18
    FileAllocationInformation EQU 19
    FileEndOfFileInformation EQU 20
    FileAlternateNameInformation EQU 21
    FileStreamInformation EQU 22
    FilePipeInformation EQU 23
    FilePipeLocalInformation EQU 24
    FilePipeRemoteInformation EQU 25
    FileMailslotQueryInformation EQU 26
    FileMailslotSetInformation EQU 27
    FileCompressionInformation EQU 28
    FileObjectIdInformation EQU 29
    FileCompletionInformation EQU 30
    FileMoveClusterInformation EQU 31
    FileQuotaInformation EQU 32
    FileReparsePointInformation EQU 33
    FileNetworkOpenInformation EQU 34
    FileAttributeTagInformation EQU 35
    FileTrackingInformation EQU 36
    FileIdBothDirectoryInformation EQU 37
    FileIdFullDirectoryInformation EQU 38
    FileValidDataLengthInformation EQU 39
    FileShortNameInformation EQU 40
    FileIoCompletionNotificationInformation EQU 41
    FileIoStatusBlockRangeInformation EQU 42
    FileIoPriorityHintInformation EQU 43
    FileSfioReserveInformation EQU 44
    FileSfioVolumeInformation EQU 45
    FileHardLinkInformation EQU 46
    FileProcessIdsUsingFileInformation EQU 47
    FileNormalizedNameInformation EQU 48
    FileNetworkPhysicalNameInformation EQU 49
    FileIdGlobalTxDirectoryInformation EQU 50
    FileIsRemoteDeviceInformation EQU 51
    FileUnusedInformation EQU 52
    FileNumaNodeInformation EQU 53
    FileStandardLinkInformation EQU 54
    FileRemoteProtocolInformation EQU 55
    FileRenameInformationBypassAccessCheck EQU 56
    FileLinkInformationBypassAccessCheck EQU 57
    FileVolumeNameInformation EQU 58
    FileIdInformation EQU 59
    FileIdExtdDirectoryInformation EQU 60
    FileReplaceCompletionInformation EQU 61
    FileHardLinkFullIdInformation EQU 62
    FileIdExtdBothDirectoryInformation EQU 63
    FileDispositionInformationEx EQU 64
    FileRenameInformationEx EQU 65
    FileRenameInformationExBypassAccessCheck EQU 66
    FileDesiredStorageClassInformation EQU 67
    FileStatInformation EQU 68
    FileMemoryPartitionInformation EQU 69
    FileStatLxInformation EQU 70
    FileCaseSensitiveInformation EQU 71
    FileMaximumInformation EQU 72

    ; enum _FSINFOCLASS
    FileFsVolumeInformation EQU 1 
    FileFsLabelInformation EQU 2
    FileFsSizeInformation EQU 3
    FileFsDeviceInformation EQU 4
    FileFsAttributeInformation EQU 5
    FileFsControlInformation EQU 6
    FileFsFullSizeInformation EQU 7
    FileFsObjectIdInformation EQU 8
    FileFsDriverPathInformation EQU 9
    FileFsVolumeFlagsInformation EQU 10
    FileFsSectorSizeInformation EQU 11
    FileFsDataCopyInformation EQU 12
    FileFsMetadataSizeInformation EQU 13
    FileFsMaximumInformation EQU 14

    IFNDEF FILE_FS_DEVICE_INFORMATION
    FILE_FS_DEVICE_INFORMATION STRUCT		; sizeof = 8
    	DeviceType			DWORD	?	; 00h DEVICE_TYPE
    	Characteristics		DWORD	?	; 04h
    FILE_FS_DEVICE_INFORMATION ENDS
    ENDIF
    PFILE_FS_DEVICE_INFORMATION typedef PTR FILE_FS_DEVICE_INFORMATION   

    
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Registry Specific Access Rights.
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    KEY_QUERY_VALUE                 equ 0001h
    KEY_SET_VALUE                   equ 0002h
    KEY_CREATE_SUB_KEY              equ 0004h
    KEY_ENUMERATE_SUB_KEYS          equ 0008h
    KEY_NOTIFY                      equ 0010h
    KEY_CREATE_LINK                 equ 0020h
    KEY_WOW64_32KEY                 equ 0200h
    KEY_WOW64_64KEY                 equ 0100h
    KEY_WOW64_RES                   equ 0300h
    KEY_READ	                    equ (STANDARD_RIGHTS_READ or KEY_QUERY_VALUE or KEY_ENUMERATE_SUB_KEYS or KEY_NOTIFY) AND NOT SYNCHRONIZE
    KEY_WRITE	                    equ (STANDARD_RIGHTS_WRITE or KEY_SET_VALUE or KEY_CREATE_SUB_KEY) AND NOT SYNCHRONIZE
    KEY_EXECUTE	                    equ KEY_READ AND NOT SYNCHRONIZE
    KEY_ALL_ACCESS	                equ (STANDARD_RIGHTS_ALL or KEY_QUERY_VALUE or KEY_SET_VALUE or KEY_CREATE_SUB_KEY or KEY_ENUMERATE_SUB_KEYS or KEY_NOTIFY or KEY_CREATE_LINK) AND NOT SYNCHRONIZE
    REG_OPTION_RESERVED             equ 00000000h
    REG_OPTION_NON_VOLATILE         equ 00000000h
    REG_OPTION_VOLATILE             equ 00000001h
    REG_OPTION_CREATE_LINK          equ 00000002h
    REG_OPTION_BACKUP_RESTORE       equ 00000004h
    REG_OPTION_OPEN_LINK            equ 00000008h
    REG_OPTION_DONT_VIRTUALIZE      equ 00000010h
    REG_LEGAL_OPTION                equ (REG_OPTION_RESERVED or REG_OPTION_NON_VOLATILE or REG_OPTION_VOLATILE or REG_OPTION_CREATE_LINK or REG_OPTION_BACKUP_RESTORE or REG_OPTION_OPEN_LINK or REG_OPTION_DONT_VIRTUALIZE)
    REG_OPEN_LEGAL_OPTION           equ (REG_OPTION_RESERVED or REG_OPTION_BACKUP_RESTORE or REG_OPTION_OPEN_LINK or REG_OPTION_DONT_VIRTUALIZE)
    REG_CREATED_NEW_KEY             equ 00000001h
    REG_OPENED_EXISTING_KEY         equ 00000002h
    REG_STANDARD_FORMAT             equ 1
    REG_LATEST_FORMAT               equ 2
    REG_NO_COMPRESSION              equ 4
    REG_WHOLE_HIVE_VOLATILE         equ 00000001h
    REG_REFRESH_HIVE                equ 00000002h
    REG_NO_LAZY_FLUSH               equ 00000004h
    REG_FORCE_RESTORE               equ 00000008h
    REG_APP_HIVE                    equ 00000010h
    REG_PROCESS_PRIVATE             equ 00000020h
    REG_START_JOURNAL               equ 00000040h
    REG_HIVE_EXACT_FILE_GROWTH      equ 00000080h
    REG_HIVE_NO_RM                  equ 00000100h
    REG_HIVE_SINGLE_LOG             equ 00000200h
    REG_BOOT_HIVE                   equ 00000400h
    REG_LOAD_HIVE_OPEN_HANDLE       equ 00000800h
    REG_FLUSH_HIVE_FILE_GROWTH      equ 00001000h
    REG_OPEN_READ_ONLY              equ 00002000h
    REG_IMMUTABLE                   equ 00004000h
    REG_APP_HIVE_OPEN_READ_ONLY     equ REG_OPEN_READ_ONLY
    REG_FORCE_UNLOAD                equ 1
    REG_UNLOAD_LEGAL_FLAGS          equ REG_FORCE_UNLOAD
    REG_NOTIFY_CHANGE_NAME          equ 00000001h
    REG_NOTIFY_CHANGE_ATTRIBUTES    equ 00000002h
    REG_NOTIFY_CHANGE_LAST_SET      equ 00000004h
    REG_NOTIFY_CHANGE_SECURITY      equ 00000008h
    REG_NOTIFY_THREAD_AGNOSTIC      equ 10000000h
    REG_LEGAL_CHANGE_FILTER         equ (REG_NOTIFY_CHANGE_NAME or REG_NOTIFY_CHANGE_ATTRIBUTES or REG_NOTIFY_CHANGE_LAST_SET or REG_NOTIFY_CHANGE_SECURITY or REG_NOTIFY_THREAD_AGNOSTIC)
    
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Key query structures
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    IFNDEF KEY_VALUE_BASIC_INFORMATION
    KEY_VALUE_BASIC_INFORMATION STRUCT	; sizeof = 10h
    	TitleIndex	DWORD	?	; 00h
    	dwType		DWORD	?	; 04h (original field name Type)
    	NameLength	DWORD	?	; 08h
    	woName		WORD	?	; 0Ch Variable size (original field name Name)
    				WORD	?	; padding
    KEY_VALUE_BASIC_INFORMATION ENDS
    ENDIF
    PKEY_VALUE_BASIC_INFORMATION typedef PTR KEY_VALUE_BASIC_INFORMATION
    
    IFNDEF KEY_VALUE_FULL_INFORMATION
    KEY_VALUE_FULL_INFORMATION STRUCT	; sizeof = 18h
    	TitleIndex	DWORD	?	; 00h
    	dwType		DWORD	?	; 04h (original field name Type)
    	DataOffset	DWORD	?	; 08h
    	DataLength	DWORD	?	; 0Ch
    	NameLength	DWORD	?	; 10h
    	woName		WORD	?	; 14h Variable size  (original field name Name)
    				WORD	?	; 16h padding
    	;Data[1];            // Variable size data not declared
    KEY_VALUE_FULL_INFORMATION ENDS
    ENDIF
    PKEY_VALUE_FULL_INFORMATION typedef PTR KEY_VALUE_FULL_INFORMATION
    
    IFNDEF KEY_VALUE_PARTIAL_INFORMATION
    KEY_VALUE_PARTIAL_INFORMATION STRUCT	; sizeof = 10h
    	TitleIndex	DWORD	?
    	dwType		DWORD	?	; original field name Type
    	DataLength	DWORD	?
    	Data		BYTE	?	; Variable size
    				db 3 dup(?)	; padding
    KEY_VALUE_PARTIAL_INFORMATION ENDS
    ENDIF
    PKEY_VALUE_PARTIAL_INFORMATION typedef PTR KEY_VALUE_PARTIAL_INFORMATION
    
    IFNDEF KEY_VALUE_PARTIAL_INFORMATION_ALIGN64
    KEY_VALUE_PARTIAL_INFORMATION_ALIGN64 STRUCT	; sizeof = 0Ch
    	dwType		DWORD	?	; original field name Type
    	DataLength	DWORD	?
    	Data		BYTE	?	; Variable size
    				db 3 dup(?)	; padding
    KEY_VALUE_PARTIAL_INFORMATION_ALIGN64 ENDS
    ENDIF
    PKEY_VALUE_PARTIAL_INFORMATION_ALIGN64 typedef PTR KEY_VALUE_PARTIAL_INFORMATION_ALIGN64
    
    IFNDEF KEY_VALUE_ENTRY
    KEY_VALUE_ENTRY STRUCT	; sizeof = 10h
    	ValueName	PVOID	?	; PTR UNICODE_STRING
    	DataLength	DWORD	?
    	DataOffset	DWORD	?
    	dwType		DWORD	?	; original field name Type
    KEY_VALUE_ENTRY ENDS
    ENDIF
    PKEY_VALUE_ENTRY typedef PTR KEY_VALUE_ENTRY
    
    ;typedef enum _KEY_VALUE_INFORMATION_CLASS {
    KeyValueBasicInformation			equ 0
    KeyValueFullInformation				equ 1
    KeyValuePartialInformation			equ 2
    KeyValueFullInformationAlign64		equ 3
    KeyValuePartialInformationAlign64	equ 4
    
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Process Information Structures
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    ; PageFaultHistory Information
    ;  NtQueryInformationProcess using ProcessWorkingSetWatch
    
    PROCESS_WS_WATCH_INFORMATION STRUCT	; sizeof = 8
    	FaultingPc	PVOID	?
    	FaultingVa	PVOID	?
    PROCESS_WS_WATCH_INFORMATION ENDS
    PPROCESS_WS_WATCH_INFORMATION typedef PTR PROCESS_WS_WATCH_INFORMATION

    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Basic Process Information
    ;  NtQueryInformationProcess using ProcessBasicInfo
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
;    PROCESS_BASIC_INFORMATION STRUCT	; sizeof = 18h
;    	ExitStatus				NTSTATUS	?
;    	PebBaseAddress			PVOID		? ; PPEB
;    	AffinityMask			DWORD		?
;    	BasePriority			DWORD		? ; KPRIORITY
;    	UniqueProcessId			DWORD		?
;    	InheritedFromUniqueProcessId	DWORD		?
;    PROCESS_BASIC_INFORMATION ENDS
;    PPROCESS_BASIC_INFORMATION typedef PTR PROCESS_BASIC_INFORMATION
  
  
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Exception flag definitions.
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    EXCEPTION_NONCONTINUABLE 			equ 1	; Noncontinuable exception
    
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Define maximum number of exception parameters.
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    EXCEPTION_MAXIMUM_PARAMETERS		equ 15	; maximum number of exception parameters
    
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Exception record definition.
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    IFNDEF EXCEPTION_RECORD
    EXCEPTION_RECORD STRUCT
    	ExceptionCode			NTSTATUS	?
    	ExceptionFlags			DWORD		?
    	ExceptionRecord			PVOID		?	; PTR EXCEPTION_RECORD
    	ExceptionAddress		PVOID		?
    	NumberParameters		DWORD		?
    	ExceptionInformation	DWORD 		EXCEPTION_MAXIMUM_PARAMETERS dup(?)
    EXCEPTION_RECORD ENDS
    ENDIF
    PEXCEPTION_RECORD typedef PTR EXCEPTION_RECORD
    
    IFNDEF EXCEPTION_RECORD32
    EXCEPTION_RECORD32 STRUCT
    	ExceptionCode			NTSTATUS	?
    	ExceptionFlags			DWORD	?
    	ExceptionRecord			DWORD	?
    	ExceptionAddress		DWORD	?
    	NumberParameters		DWORD	?
    	ExceptionInformation	DWORD EXCEPTION_MAXIMUM_PARAMETERS dup(?)
    EXCEPTION_RECORD32 ENDS
    ENDIF
    PEXCEPTION_RECORD32 typedef PTR EXCEPTION_RECORD32
    
    IFNDEF EXCEPTION_RECORD64
    EXCEPTION_RECORD64 struct
        ExceptionCode NTSTATUS ?
        ExceptionFlags DWORD ?
        ExceptionRecord ULONG64 ?
        ExceptionAddress ULONG64 ?
        NumberParameters DWORD ?
        __unusedAlignment DWORD ?
        ExceptionInformation ULONG64 EXCEPTION_MAXIMUM_PARAMETERS dup (?)
    EXCEPTION_RECORD64 ends
    ENDIF
    PEXCEPTION_RECORD64 typedef ptr EXCEPTION_RECORD64    
    
    
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ; Typedef for pointer returned by exception_info()
    ;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    IFNDEF EXCEPTION_POINTERS
    EXCEPTION_POINTERS STRUCT
    	ExceptionRecord	PVOID	?	; PTR EXCEPTION_RECORD
    	ContextRecord	PVOID	?	; PTR CONTEXT
    EXCEPTION_POINTERS ENDS
    ENDIF
    PEXCEPTION_POINTERS typedef PTR EXCEPTION_POINTERS
  
  
  
  
  
  
  
  
  
  
  ARBITER_CONFLICT_INFO struct
    OwningObject PDEVICE_OBJECT ?
    Start QWORD ?
    End_ QWORD ?
  ARBITER_CONFLICT_INFO ends

  PARBITER_CONFLICT_INFO typedef ptr ARBITER_CONFLICT_INFO

    IFNDEF CM_PARTIAL_RESOURCE_DESCRIPTOR
    CM_PARTIAL_RESOURCE_DESCRIPTOR struct
    Type_ BYTE ?
    ShareDisposition BYTE ?
    Flags WORD ?
    union u
      struct Generic
        Start PHYSICAL_ADDRESS <>
        Length_ DWORD ?
      ends
      struct Port
        Start PHYSICAL_ADDRESS <>
        Length_ DWORD ?
      ends
      struct Interrupt
        ;if defined(NT_PROCESSOR_GROUPS)
        ;  Level WORD ?
        ;  Group_ WORD ?
        ;else
          Level DWORD ?
        ;endif
        Vector DWORD ?
        Affinity KAFFINITY ?
      ends
      struct MessageInterrupt
        union DUMMYUNIONNAME_6
          struct Raw
            ;if defined(NT_PROCESSOR_GROUPS)
            ;  Group_ WORD ?
            ;else
              Reserved WORD ?
            ;endif
            MessageCount WORD ?
            Vector DWORD ?
            Affinity KAFFINITY ?
          ends
          struct Translated
            ;if defined(NT_PROCESSOR_GROUPS)
            ;  Level WORD ?
            ;  Group_ WORD ?
            ;else
              Level DWORD ?
            ;endif
            Vector DWORD ?
            Affinity KAFFINITY ?
          ends
        ends
      ends
      struct Memory
        Start PHYSICAL_ADDRESS <>
        Length_ DWORD ?
      ends
      struct Dma
        Channel DWORD ?
        Port DWORD ?
        Reserved1 DWORD ?
      ends
      struct DmaV3
        Channel DWORD ?
        RequestLine DWORD ?
        TransferWidth BYTE ?
        Reserved1 BYTE ?
        Reserved2 BYTE ?
        Reserved3 BYTE ?
      ends
      struct DevicePrivate
        Data DWORD 3 dup (?)
      ends
      struct BusNumber
        Start DWORD ?
        Length_ DWORD ?
        Reserved DWORD ?
      ends
      struct DeviceSpecificData
        DataSize DWORD ?
        Reserved1 DWORD ?
        Reserved2 DWORD ?
      ends
      struct Memory40
        Start PHYSICAL_ADDRESS <>
        Length40 DWORD ?
      ends
      struct Memory48
        Start PHYSICAL_ADDRESS <>
        Length48 DWORD ?
      ends
      struct Memory64
        Start PHYSICAL_ADDRESS <>
        Length64 DWORD ?
      ends
      struct Connection
        Class BYTE ?
        Type_ BYTE ?
        Reserved1 BYTE ?
        Reserved2 BYTE ?
        IdLowPart DWORD ?
        IdHighPart DWORD ?
      ends
    ends
    CM_PARTIAL_RESOURCE_DESCRIPTOR ends
    ENDIF
    PCM_PARTIAL_RESOURCE_DESCRIPTOR typedef ptr CM_PARTIAL_RESOURCE_DESCRIPTOR
  
    IFNDEF CM_PARTIAL_RESOURCE_LIST
    CM_PARTIAL_RESOURCE_LIST struct
        Version WORD ?
        Revision WORD ?
        Count DWORD ?
        PartialDescriptors CM_PARTIAL_RESOURCE_DESCRIPTOR 1 dup (<>)
    CM_PARTIAL_RESOURCE_LIST ends
    ENDIF
    PCM_PARTIAL_RESOURCE_LIST typedef ptr CM_PARTIAL_RESOURCE_LIST
    
    IFNDEF CM_FULL_RESOURCE_DESCRIPTOR
    CM_FULL_RESOURCE_DESCRIPTOR struct
        InterfaceType INTERFACE_TYPE ?
        BusNumber DWORD ?
        PartialResourceList CM_PARTIAL_RESOURCE_LIST <>
    CM_FULL_RESOURCE_DESCRIPTOR ends
    ENDIF
    PCM_FULL_RESOURCE_DESCRIPTOR typedef ptr CM_FULL_RESOURCE_DESCRIPTOR
    
    IFNDEF CM_RESOURCE_LIST
    CM_RESOURCE_LIST struct
        Count DWORD ?
        List CM_FULL_RESOURCE_DESCRIPTOR 1 dup (<>)
    CM_RESOURCE_LIST ends
    ENDIF
    PCM_RESOURCE_LIST typedef ptr CM_RESOURCE_LIST

  
  ARBITER_TEST_ALLOCATION_PARAMETERS struct
    ArbitrationList PLIST_ENTRY ?
    AllocateFromCount DWORD ?
    AllocateFrom PCM_PARTIAL_RESOURCE_DESCRIPTOR ?
  ARBITER_TEST_ALLOCATION_PARAMETERS ends

  PARBITER_TEST_ALLOCATION_PARAMETERS typedef ptr ARBITER_TEST_ALLOCATION_PARAMETERS
  
  ARBITER_RETEST_ALLOCATION_PARAMETERS struct
    ArbitrationList PLIST_ENTRY ?
    AllocateFromCount DWORD ?
    AllocateFrom PCM_PARTIAL_RESOURCE_DESCRIPTOR ?
  ARBITER_RETEST_ALLOCATION_PARAMETERS ends

  PARBITER_RETEST_ALLOCATION_PARAMETERS typedef ptr ARBITER_RETEST_ALLOCATION_PARAMETERS
  
  ARBITER_BOOT_ALLOCATION_PARAMETERS struct
    ArbitrationList PLIST_ENTRY ?
  ARBITER_BOOT_ALLOCATION_PARAMETERS ends

  PARBITER_BOOT_ALLOCATION_PARAMETERS typedef ptr ARBITER_BOOT_ALLOCATION_PARAMETERS
  
  ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS struct
    AllocatedResources POINTER ?
  ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS ends

  PARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS typedef ptr ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS

    IRQ_DEVICE_POLICY typedef SDWORD
    IRQ_PRIORITY typedef SDWORD

  IFNDEF IO_RESOURCE_DESCRIPTOR
  IO_RESOURCE_DESCRIPTOR struct
    Option_ BYTE ?
    Type_ BYTE ?
    ShareDisposition BYTE ?
    Spare1 BYTE ?
    Flags WORD ?
    Spare2 WORD ?
    union u
      struct Port
        Length_ DWORD ?
        Alignment DWORD ?
        MinimumAddress PHYSICAL_ADDRESS <>
        MaximumAddress PHYSICAL_ADDRESS <>
      ends
      struct Memory
        Length_ DWORD ?
        Alignment DWORD ?
        MinimumAddress PHYSICAL_ADDRESS <>
        MaximumAddress PHYSICAL_ADDRESS <>
      ends
      struct Interrupt
        MinimumVector DWORD ?
        MaximumVector DWORD ?
        ;if defined(NT_PROCESSOR_GROUPS)
        ;  AffinityPolicy IRQ_DEVICE_POLICY ?
        ;  Group_ WORD ?
        ;else
          AffinityPolicy IRQ_DEVICE_POLICY ?
        ;endif
        PriorityPolicy IRQ_PRIORITY ?
        TargetedProcessors KAFFINITY ?
      ends
      struct Dma
        MinimumChannel DWORD ?
        MaximumChannel DWORD ?
      ends
      struct DmaV3
        RequestLine DWORD ?
        Reserved DWORD ?
        Channel DWORD ?
        TransferWidth DWORD ?
      ends
      struct Generic
        Length_ DWORD ?
        Alignment DWORD ?
        MinimumAddress PHYSICAL_ADDRESS <>
        MaximumAddress PHYSICAL_ADDRESS <>
      ends
      struct DevicePrivate
        Data DWORD 3 dup (?)
      ends
      struct BusNumber
        Length_ DWORD ?
        MinBusNumber DWORD ?
        MaxBusNumber DWORD ?
        Reserved DWORD ?
      ends
      struct ConfigData
        Priority DWORD ?
        Reserved1 DWORD ?
        Reserved2 DWORD ?
      ends
      struct Memory40
        Length40 DWORD ?
        Alignment40 DWORD ?
        MinimumAddress PHYSICAL_ADDRESS <>
        MaximumAddress PHYSICAL_ADDRESS <>
      ends
      struct Memory48
        Length48 DWORD ?
        Alignment48 DWORD ?
        MinimumAddress PHYSICAL_ADDRESS <>
        MaximumAddress PHYSICAL_ADDRESS <>
      ends
      struct Memory64
        Length64 DWORD ?
        Alignment64 DWORD ?
        MinimumAddress PHYSICAL_ADDRESS <>
        MaximumAddress PHYSICAL_ADDRESS <>
      ends
      struct Connection
        Class BYTE ?
        Type_ BYTE ?
        Reserved1 BYTE ?
        Reserved2 BYTE ?
        IdLowPart DWORD ?
        IdHighPart DWORD ?
      ends
    ends
  IO_RESOURCE_DESCRIPTOR ends
  ENDIF

  PIO_RESOURCE_DESCRIPTOR typedef ptr IO_RESOURCE_DESCRIPTOR
  
  ARBITER_QUERY_CONFLICT_PARAMETERS struct
    PhysicalDeviceObject PDEVICE_OBJECT ?
    ConflictingResource PIO_RESOURCE_DESCRIPTOR ?
    ConflictCount PULONG ?
    Conflicts POINTER ?
  ARBITER_QUERY_CONFLICT_PARAMETERS ends

  PARBITER_QUERY_CONFLICT_PARAMETERS typedef ptr ARBITER_QUERY_CONFLICT_PARAMETERS
  
  ARBITER_QUERY_ARBITRATE_PARAMETERS struct
    ArbitrationList PLIST_ENTRY ?
  ARBITER_QUERY_ARBITRATE_PARAMETERS ends

  PARBITER_QUERY_ARBITRATE_PARAMETERS typedef ptr ARBITER_QUERY_ARBITRATE_PARAMETERS
  
  ARBITER_ADD_RESERVED_PARAMETERS struct
    ReserveDevice PDEVICE_OBJECT ?
  ARBITER_ADD_RESERVED_PARAMETERS ends

  PARBITER_ADD_RESERVED_PARAMETERS typedef ptr ARBITER_ADD_RESERVED_PARAMETERS
  
  ARBITER_PARAMETERS struct
    union Parameters
      TestAllocation ARBITER_TEST_ALLOCATION_PARAMETERS <>
      RetestAllocation ARBITER_RETEST_ALLOCATION_PARAMETERS <>
      BootAllocation ARBITER_BOOT_ALLOCATION_PARAMETERS <>
      QueryAllocatedResources ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS <>
      QueryConflict ARBITER_QUERY_CONFLICT_PARAMETERS <>
      QueryArbitrate ARBITER_QUERY_ARBITRATE_PARAMETERS <>
      AddReserved ARBITER_ADD_RESERVED_PARAMETERS <>
    ends
  ARBITER_PARAMETERS ends

  PARBITER_PARAMETERS typedef ptr ARBITER_PARAMETERS
  
  ARBITER_REQUEST_SOURCE typedef SDWORD
  ArbiterRequestUndefined EQU - 1 
  ArbiterRequestLegacyReported EQU 2
  ArbiterRequestHalReported EQU 3
  ArbiterRequestLegacyAssigned EQU 4
  ArbiterRequestPnpDetected EQU 5
  ArbiterRequestPnpEnumerated EQU 6
  
  ARBITER_RESULT typedef SDWORD
  ArbiterResultUndefined EQU - 1 
  ArbiterResultSuccess EQU 2
  ArbiterResultExternalConflict EQU 3
  ArbiterResultNullRequest EQU 4
  
  ARBITER_FLAG_BOOT_CONFIG equ 00000001h
  ARBITER_FLAG_ROOT_ENUM equ 00000002h
  ARBITER_FLAG_OTHER_ENUM equ 00000004h


  ARBITER_LIST_ENTRY struct
    ListEntry LIST_ENTRY <>
    AlternativeCount DWORD ?
    Alternatives PIO_RESOURCE_DESCRIPTOR ?
    PhysicalDeviceObject PDEVICE_OBJECT ?
    RequestSource ARBITER_REQUEST_SOURCE ?
    Flags DWORD ?
    WorkSpace LONG_PTR ?
    InterfaceType INTERFACE_TYPE ?
    SlotNumber DWORD ?
    BusNumber DWORD ?
    Assignment PCM_PARTIAL_RESOURCE_DESCRIPTOR ?
    SelectedAlternative PIO_RESOURCE_DESCRIPTOR ?
    Result ARBITER_RESULT ?
  ARBITER_LIST_ENTRY ends

  PARBITER_LIST_ENTRY typedef ptr ARBITER_LIST_ENTRY
  
  proto_PARBITER_HANDLER typedef proto fastcall :PVOID, :ARBITER_ACTION, :PARBITER_PARAMETERS
  PARBITER_HANDLER typedef ptr proto_PARBITER_HANDLER
  ARBITER_PARTIAL equ 00000001h
  ARBITER_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    ArbiterHandler PARBITER_HANDLER ?
    Flags DWORD ?
  ARBITER_INTERFACE ends

  PARBITER_INTERFACE typedef ptr ARBITER_INTERFACE
  
  RESOURCE_TRANSLATION_DIRECTION typedef SDWORD
  TranslateChildToParent EQU 0
  TranslateParentToChild EQU 1

    PTRANSLATE_RESOURCE_HANDLER typedef QWORD
    PTRANSLATE_RESOURCE_REQUIREMENTS_HANDLER typedef QWORD

  TRANSLATOR_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    TranslateResources PTRANSLATE_RESOURCE_HANDLER ?
    TranslateResourceRequirements PTRANSLATE_RESOURCE_REQUIREMENTS_HANDLER ?
  TRANSLATOR_INTERFACE ends

  PTRANSLATOR_INTERFACE typedef ptr TRANSLATOR_INTERFACE
  
      HAL_DMA_CRASH_DUMP_REGISTER_TYPE typedef SDWORD
      HalDmaCrashDumpRegisterSet1 EQU 0 
      HalDmaCrashDumpRegisterSet2 EQU 1
      HalDmaCrashDumpRegisterSetMax EQU 2
      
      PHAL_DMA_CRASH_DUMP_REGISTER_TYPE typedef ptr HAL_DMA_CRASH_DUMP_REGISTER_TYPE

  HAL_QUERY_INFORMATION_CLASS typedef SDWORD
  HalInstalledBusInformation EQU 0
  HalProfileSourceInformation EQU 1
  HalInformationClassUnused1 EQU 2
  HalPowerInformation EQU 3
  HalProcessorSpeedInformation EQU 4
  HalCallbackInformation EQU 5
  HalMapRegisterInformation EQU 6
  HalMcaLogInformation EQU 7
  HalFrameBufferCachingInformation EQU 8
  HalDisplayBiosInformation EQU 9
  HalProcessorFeatureInformation EQU 10
  HalNumaTopologyInterface EQU 11
  HalErrorInformation EQU 12
  HalCmcLogInformation EQU 13
  HalCpeLogInformation EQU 14
  HalQueryMcaInterface EQU 15
  HalQueryAMLIIllegalIOPortAddresses EQU 16
  HalQueryMaxHotPlugMemoryAddress EQU 17
  HalPartitionIpiInterface EQU 18
  HalPlatformInformation EQU 19
  HalQueryProfileSourceList EQU 20
  HalInitLogInformation EQU 21
  HalFrequencyInformation EQU 22
  HalProcessorBrandString EQU 23
  HalHypervisorInformation EQU 24
  HalPlatformTimerInformation EQU 25
  HalAcpiAuditInformation EQU 26
  HalIrtInformation EQU 27
  HalSecondaryInterruptInformation EQU 28
  HalParkingPageInformation EQU 29
  HalNumaRangeTableInformation EQU 30
  HalChannelTopologyInformation EQU 31
  HalExternalCacheInformation EQU 32
  HalQueryDebuggerInformation EQU 33
  HalFwBootPerformanceInformation EQU 34
  HalFwS3PerformanceInformation EQU 35
  HalGetChannelPowerInformation EQU 36
  HalQueryStateElementInformation EQU 37
  HalPsciInformation EQU 38
  HalInterruptControllerInformation EQU 39
  HalQueryIommuReservedRegionInformation EQU 40
  HalQueryArmErrataInformation EQU 41
  HalQueryProcessorEfficiencyInformation EQU 42
  HalQueryAcpiWakeAlarmSystemPowerStateInformation EQU 43
  HalQueryProfileNumberOfCounters EQU 44
  HalQueryHyperlaunchEntrypoint EQU 45
  HalHardwareWatchdogInformation EQU 46
  HalDmaRemappingInformation EQU 47
  HalQueryRuntimeServicesBlockInformation EQU 48
  
  PHAL_QUERY_INFORMATION_CLASS typedef ptr HAL_QUERY_INFORMATION_CLASS
  
  HAL_SET_INFORMATION_CLASS typedef SDWORD
  HalProfileSourceInterval EQU 0
  HalProfileSourceInterruptHandler EQU 1
  HalMcaRegisterDriver EQU 2
  HalKernelErrorHandler EQU 3
  HalCmcRegisterDriver EQU 4
  HalCpeRegisterDriver EQU 5
  HalMcaLog EQU 6
  HalCmcLog EQU 7
  HalCpeLog EQU 8
  HalGenerateCmcInterrupt EQU 9
  HalProfileSourceTimerHandler EQU 10
  HalEnlightenment EQU 11
  HalProfileDpgoSourceInterruptHandler EQU 12
  HalRegisterSecondaryInterruptInterface EQU 13
  HalSetChannelPowerInformation EQU 14
  HalI386ExceptionChainTerminatorInformation EQU 15
  HalSetResetParkDisposition EQU 16
  HalSetPsciSuspendMode EQU 17
  HalSetHvciEnabled EQU 18
  HalSetProcessorTraceInterruptHandler EQU 19
  HalProfileSourceAdd EQU 20
  HalProfileSourceRemove EQU 21
  
  PHAL_SET_INFORMATION_CLASS typedef ptr HAL_SET_INFORMATION_CLASS
  
  proto_pHalQuerySystemInformation typedef proto fastcall :HAL_QUERY_INFORMATION_CLASS, :DWORD, :PVOID, :PULONG
  pHalQuerySystemInformation typedef ptr proto_pHalQuerySystemInformation
  proto_pHalSetSystemInformation typedef proto fastcall :HAL_SET_INFORMATION_CLASS, :DWORD, :PVOID
  pHalSetSystemInformation typedef ptr proto_pHalSetSystemInformation
  proto_pHalExamineMBR typedef proto fastcall :PDEVICE_OBJECT, :DWORD, :DWORD, :ptr PVOID
  pHalExamineMBR typedef ptr proto_pHalExamineMBR
  proto_pHalIoReadPartitionTable typedef proto fastcall :PDEVICE_OBJECT, :DWORD, :BOOLEAN, :ptr ptr _DRIVE_LAYOUT_INFORMATION
  pHalIoReadPartitionTable typedef ptr proto_pHalIoReadPartitionTable
  proto_pHalIoSetPartitionInformation typedef proto fastcall :PDEVICE_OBJECT, :DWORD, :DWORD, :DWORD
  pHalIoSetPartitionInformation typedef ptr proto_pHalIoSetPartitionInformation
  proto_pHalIoWritePartitionTable typedef proto fastcall :PDEVICE_OBJECT, :DWORD, :DWORD, :DWORD, :ptr _DRIVE_LAYOUT_INFORMATION
  pHalIoWritePartitionTable typedef ptr proto_pHalIoWritePartitionTable
  proto_pHalQueryBusSlots typedef proto fastcall :PBUS_HANDLER, :DWORD, :PULONG, :PULONG
  pHalQueryBusSlots typedef ptr proto_pHalQueryBusSlots
  proto_pHalInitPnpDriver typedef proto fastcall 
  pHalInitPnpDriver typedef ptr proto_pHalInitPnpDriver
  PM_DISPATCH_TABLE struct
    Signature DWORD ?
    Version DWORD ?
    Function PVOID 1 dup (?)
  PM_DISPATCH_TABLE ends

  PPM_DISPATCH_TABLE typedef ptr PM_DISPATCH_TABLE
  


  PhysicalDeviceObject typedef ptr ptr _DMA_ADAPTER
  DeviceDescriptor typedef ptr _DMA_ADAPTER


  MAP_REGISTER_ENTRY struct
    MapRegister PVOID ?
    WriteToDevice BOOLEAN ?
  MAP_REGISTER_ENTRY ends

  PMAP_REGISTER_ENTRY typedef ptr MAP_REGISTER_ENTRY
  

  DEBUG_DEVICE_ADDRESS struct
    Type_ BYTE ?
    Valid BOOLEAN ?
    union
      Reserved BYTE 2 dup (?)
      struct
        BitWidth BYTE ?
        AccessSize BYTE ?
      ends
    ends
    TranslatedAddress PUCHAR ?
    Length_ DWORD ?
  DEBUG_DEVICE_ADDRESS ends

  PDEBUG_DEVICE_ADDRESS typedef ptr DEBUG_DEVICE_ADDRESS
  
  DEBUG_MEMORY_REQUIREMENTS struct
    Start PHYSICAL_ADDRESS <>
    MaxEnd PHYSICAL_ADDRESS <>
    VirtualAddress PVOID ?
    Length_ DWORD ?
    Cached BOOLEAN ?
    Aligned BOOLEAN ?
  DEBUG_MEMORY_REQUIREMENTS ends

  PDEBUG_MEMORY_REQUIREMENTS typedef ptr DEBUG_MEMORY_REQUIREMENTS
  
  KD_NAMESPACE_ENUM typedef SDWORD
  KdNameSpacePCI EQU 0
  KdNameSpaceACPI EQU 1
  KdNameSpaceAny EQU 2
  KdNameSpaceNone EQU 3
  KdNameSpaceMax EQU 4
  
  PKD_NAMESPACE_ENUM typedef ptr KD_NAMESPACE_ENUM
  
  KD_CALLBACK_ACTION typedef SDWORD
  KdConfigureDeviceAndContinue EQU 0
  KdSkipDeviceAndContinue EQU 1
  KdConfigureDeviceAndStop EQU 2
  KdSkipDeviceAndStop EQU 3
  
  PKD_CALLBACK_ACTION typedef ptr KD_CALLBACK_ACTION
  
  DEBUG_TRANSPORT_DATA struct
    HwContextSize DWORD ?
    UseSerialFraming BOOLEAN ?
  DEBUG_TRANSPORT_DATA ends

  PDEBUG_TRANSPORT_DATA typedef ptr DEBUG_TRANSPORT_DATA
  
  MAXIMUM_DEBUG_BARS equ 6
  DBG_DEVICE_FLAG_HAL_SCRATCH_ALLOCATED equ 01h
  DBG_DEVICE_FLAG_BARS_MAPPED equ 02h
  DBG_DEVICE_FLAG_SCRATCH_ALLOCATED equ 04h
  DBG_DEVICE_FLAG_UNCACHED_MEMORY equ 08h
  DBG_DEVICE_FLAG_SYNTHETIC equ 10h
  DEBUG_DEVICE_DESCRIPTOR struct
    Bus DWORD ?
    Slot DWORD ?
    Segment_ WORD ?
    VendorID WORD ?
    DeviceID WORD ?
    BaseClass BYTE ?
    SubClass BYTE ?
    ProgIf BYTE ?
    union
      Flags BYTE ?
      struct
        DEBUG_DEVICE_DESCRIPTOR_??25 record DbgHalScratchAllocated_??25:1, DbgBarsMapped_??25:1, DbgScratchAllocated_??25:1
        DEBUG_DEVICE_DESCRIPTOR_??25 <>
      ends
    ends
    Initialized BOOLEAN ?
    Configured BOOLEAN ?
    BaseAddress DEBUG_DEVICE_ADDRESS MAXIMUM_DEBUG_BARS dup (<>)
    Memory DEBUG_MEMORY_REQUIREMENTS <>
    PortType WORD ?
    PortSubtype WORD ?
    OemData PVOID ?
    OemDataLength DWORD ?
    NameSpace KD_NAMESPACE_ENUM ?
    NameSpacePath PWCHAR ?
    NameSpacePathLength DWORD ?
    TransportType DWORD ?
    TransportData DEBUG_TRANSPORT_DATA <>
  DEBUG_DEVICE_DESCRIPTOR ends

  PDEBUG_DEVICE_DESCRIPTOR typedef ptr DEBUG_DEVICE_DESCRIPTOR
  
  PCI_DEBUGGING_DEVICE_IN_USE struct
    Segment_ WORD ?
    Bus DWORD ?
    Slot DWORD ?
  PCI_DEBUGGING_DEVICE_IN_USE ends

  PPCI_DEBUGGING_DEVICE_IN_USE typedef ptr PCI_DEBUGGING_DEVICE_IN_USE
  
  ACPI_DEBUGGING_DEVICE_IN_USE struct
    NameSpacePathLength DWORD ?
    NameSpacePath WCHAR ANYSIZE_ARRAY dup (?)
  ACPI_DEBUGGING_DEVICE_IN_USE ends

  PACPI_DEBUGGING_DEVICE_IN_USE typedef ptr ACPI_DEBUGGING_DEVICE_IN_USE
  
  DEBUGGING_DEVICE_IN_USE struct
    NameSpace KD_NAMESPACE_ENUM ?
    StructureLength DWORD ?
    union
      AcpiDevice ACPI_DEBUGGING_DEVICE_IN_USE <>
      PciDevice PCI_DEBUGGING_DEVICE_IN_USE <>
    ends
  DEBUGGING_DEVICE_IN_USE ends

  PDEBUGGING_DEVICE_IN_USE typedef ptr DEBUGGING_DEVICE_IN_USE
  
  DEBUGGING_DEVICE_IN_USE_INFORMATION struct
    DeviceCount DWORD ?
    Device DEBUGGING_DEVICE_IN_USE ANYSIZE_ARRAY dup (<>)
  DEBUGGING_DEVICE_IN_USE_INFORMATION ends

  PDEBUGGING_DEVICE_IN_USE_INFORMATION typedef ptr DEBUGGING_DEVICE_IN_USE_INFORMATION

  HAL_DISPATCH struct
    Version DWORD ?
    HalQuerySystemInformation QWORD ? ;pHalQuerySystemInformation ?
    HalSetSystemInformation QWORD ? ;pHalSetSystemInformation ?
    HalQueryBusSlots QWORD ? ;pHalQueryBusSlots ?
    Spare1 DWORD ?
    HalExamineMBR QWORD ? ;pHalExamineMBR ?
    HalIoReadPartitionTable QWORD ? ;pHalIoReadPartitionTable ?
    HalIoSetPartitionInformation QWORD ? ;pHalIoSetPartitionInformation ?
    HalIoWritePartitionTable QWORD ? ;pHalIoWritePartitionTable ?
    HalReferenceHandlerForBus QWORD ? ;pHalHandlerForBus ?
    HalReferenceBusHandler QWORD ? ;pHalReferenceBusHandler ?
    HalDereferenceBusHandler QWORD ? ;pHalReferenceBusHandler ?
    HalInitPnpDriver QWORD ? ;pHalInitPnpDriver ?
    HalInitPowerManagement QWORD ? ;pHalInitPowerManagement ?
    HalGetDmaAdapter QWORD ? ;pHalGetDmaAdapter ?
    HalGetInterruptTranslator QWORD ? ;pHalGetInterruptTranslator ?
    HalStartMirroring QWORD ? ;pHalStartMirroring ?
    HalEndMirroring QWORD ? ;pHalEndMirroring ?
    HalMirrorPhysicalMemory QWORD ? ;pHalMirrorPhysicalMemory ?
    HalEndOfBoot QWORD ? ;pHalEndOfBoot ?
    HalMirrorVerify QWORD ? ;pHalMirrorVerify ?
    HalGetCachedAcpiTable QWORD ? ;pHalGetAcpiTable ?
    HalSetPciErrorHandlerCallback QWORD ? ;pHalSetPciErrorHandlerCallback ?
  HAL_DISPATCH ends

  PHAL_DISPATCH typedef ptr HAL_DISPATCH


  HAL_DISPATCH_VERSION equ 4
  HalDispatchTableVersion equ <HALDISPATCH - Version>
  HalQuerySystemInformation equ <HALDISPATCH - HalQuerySystemInformation>
  HalSetSystemInformation equ <HALDISPATCH - HalSetSystemInformation>
  HalQueryBusSlots equ <HALDISPATCH - HalQueryBusSlots>
  HalReferenceHandlerForBus equ <HALDISPATCH - HalReferenceHandlerForBus>
  HalReferenceBusHandler equ <HALDISPATCH - HalReferenceBusHandler>
  HalDereferenceBusHandler equ <HALDISPATCH - HalDereferenceBusHandler>
  HalInitPnpDriver equ <HALDISPATCH - HalInitPnpDriver>
  HalInitPowerManagement equ <HALDISPATCH - HalInitPowerManagement>
  HalGetDmaAdapter equ <HALDISPATCH - HalGetDmaAdapter>
  HalGetInterruptTranslator equ <HALDISPATCH - HalGetInterruptTranslator>
  HalStartMirroring equ <HALDISPATCH - HalStartMirroring>
  HalEndMirroring equ <HALDISPATCH - HalEndMirroring>
  HalMirrorPhysicalMemory equ <HALDISPATCH - HalMirrorPhysicalMemory>
  HalEndOfBoot equ <HALDISPATCH - HalEndOfBoot>
  HalMirrorVerify equ <HALDISPATCH - HalMirrorVerify>
  HalGetCachedAcpiTable equ <HALDISPATCH - HalGetCachedAcpiTable>
  HalSetPciErrorHandlerCallback equ <HALDISPATCH - HalSetPciErrorHandlerCallback>
  HAL_BUS_INFORMATION struct
    BusType INTERFACE_TYPE ?
    ConfigurationType BUS_DATA_TYPE ?
    BusNumber DWORD ?
    Reserved DWORD ?
  HAL_BUS_INFORMATION ends

  PHAL_BUS_INFORMATION typedef ptr HAL_BUS_INFORMATION
  
  HAL_DISPLAY_BIOS_INFORMATION typedef SDWORD
  HalDisplayInt10Bios EQU 0
  HalDisplayEmulatedBios EQU 1
  HalDisplayNoBios EQU 2
  
  PHAL_DISPLAY_BIOS_INFORMATION typedef ptr HAL_DISPLAY_BIOS_INFORMATION
  
  HAL_POWER_INFORMATION struct
    TBD DWORD ?
  HAL_POWER_INFORMATION ends

  PHAL_POWER_INFORMATION typedef ptr HAL_POWER_INFORMATION
  
  HAL_PROCESSOR_SPEED_INFORMATION struct
    ProcessorSpeed DWORD ?
  HAL_PROCESSOR_SPEED_INFORMATION ends

  PHAL_PROCESSOR_SPEED_INFORMATION typedef ptr HAL_PROCESSOR_SPEED_INFORMATION
  
  HAL_CALLBACKS struct
    SetSystemInformation PCALLBACK_OBJECT ?
    BusCheck PCALLBACK_OBJECT ?
  HAL_CALLBACKS ends

  PHAL_CALLBACKS typedef ptr HAL_CALLBACKS
  
  HAL_PROCESSOR_FEATURE struct
    UsableFeatureBits DWORD ?
  HAL_PROCESSOR_FEATURE ends

  proto_PHALIOREADWRITEHANDLER typedef proto fastcall :BOOLEAN, :DWORD, :DWORD, :PULONG
  PHALIOREADWRITEHANDLER typedef ptr proto_PHALIOREADWRITEHANDLER
  HAL_AMLI_BAD_IO_ADDRESS_LIST struct
    BadAddrBegin DWORD ?
    BadAddrSize DWORD ?
    OSVersionTrigger DWORD ?
    IOHandler PHALIOREADWRITEHANDLER ?
  HAL_AMLI_BAD_IO_ADDRESS_LIST ends

  PHAL_AMLI_BAD_IO_ADDRESS_LIST typedef ptr HAL_AMLI_BAD_IO_ADDRESS_LIST
  
  proto_PHALMCAINTERFACELOCK typedef proto fastcall 
  PHALMCAINTERFACELOCK typedef ptr proto_PHALMCAINTERFACELOCK
  proto_PHALMCAINTERFACEUNLOCK typedef proto fastcall 
  PHALMCAINTERFACEUNLOCK typedef ptr proto_PHALMCAINTERFACEUNLOCK
  proto_PHALMCAINTERFACEREADREGISTER typedef proto fastcall :BYTE, :PVOID
  PHALMCAINTERFACEREADREGISTER typedef ptr proto_PHALMCAINTERFACEREADREGISTER
  HAL_MCA_INTERFACE struct
    Lock_ PHALMCAINTERFACELOCK ?
    Unlock PHALMCAINTERFACEUNLOCK ?
    ReadRegister PHALMCAINTERFACEREADREGISTER ?
  HAL_MCA_INTERFACE ends

  HAL_APIC_DESTINATION_MODE typedef SDWORD
  ApicDestinationModePhysical EQU 1 
  ApicDestinationModeLogicalFlat EQU 2
  ApicDestinationModeLogicalClustered EQU 3
  ApicDestinationModeUnknown EQU 4
  
  PHAL_APIC_DESTINATION_MODE typedef ptr HAL_APIC_DESTINATION_MODE
  
  PDRIVER_EXCPTN_CALLBACK typedef PTR QWORD
  PKDEFERRED_ROUTINE typedef PTR QWORD

  PDRIVER_MCA_EXCEPTION_CALLBACK typedef PDRIVER_EXCPTN_CALLBACK
  MCA_DRIVER_INFO struct
    ExceptionCallback PDRIVER_MCA_EXCEPTION_CALLBACK ?
    DpcCallback PKDEFERRED_ROUTINE ?
    DeviceContext PVOID ?
  MCA_DRIVER_INFO ends

  PMCA_DRIVER_INFO typedef ptr MCA_DRIVER_INFO
  
  HAL_ERROR_INFO struct
    Version DWORD ?
    InitMaxSize DWORD ?
    McaMaxSize DWORD ?
    McaPreviousEventsCount DWORD ?
    McaCorrectedEventsCount DWORD ?
    McaKernelDeliveryFails DWORD ?
    McaDriverDpcQueueFails DWORD ?
    McaReserved DWORD ?
    CmcMaxSize DWORD ?
    CmcPollingInterval DWORD ?
    CmcInterruptsCount DWORD ?
    CmcKernelDeliveryFails DWORD ?
    CmcDriverDpcQueueFails DWORD ?
    CmcGetStateFails DWORD ?
    CmcClearStateFails DWORD ?
    CmcReserved DWORD ?
    CmcLogId QWORD ?
    CpeMaxSize DWORD ?
    CpePollingInterval DWORD ?
    CpeInterruptsCount DWORD ?
    CpeKernelDeliveryFails DWORD ?
    CpeDriverDpcQueueFails DWORD ?
    CpeGetStateFails DWORD ?
    CpeClearStateFails DWORD ?
    CpeInterruptSources DWORD ?
    CpeLogId QWORD ?
    KernelReserved QWORD 4 dup (?)
  HAL_ERROR_INFO ends

  PHAL_ERROR_INFO typedef ptr HAL_ERROR_INFO
  
  HAL_MCE_INTERRUPTS_BASED equ - 1
  HAL_MCE_DISABLED equ 0
  HAL_CMC_INTERRUPTS_BASED equ <HAL_MCE_INTERRUPTS_BASED>
  HAL_CMC_DISABLED equ <HAL_MCE_DISABLED>
  HAL_CPE_INTERRUPTS_BASED equ <HAL_MCE_INTERRUPTS_BASED>
  HAL_CPE_DISABLED equ <HAL_MCE_DISABLED>
  HAL_MCA_INTERRUPTS_BASED equ <HAL_MCE_INTERRUPTS_BASED>
  HAL_MCA_DISABLED equ <HAL_MCE_DISABLED>


    PDRIVER_CMC_EXCEPTION_CALLBACK TYPEDEF PTR QWORD
    PKDEFERRED_ROUTINE TYPEDEF PTR QWORD

  CMC_DRIVER_INFO struct
    ExceptionCallback PDRIVER_CMC_EXCEPTION_CALLBACK ?
    DpcCallback PKDEFERRED_ROUTINE ?
    DeviceContext PVOID ?
  CMC_DRIVER_INFO ends

  PCMC_DRIVER_INFO typedef ptr CMC_DRIVER_INFO
  
  PDRIVER_CPE_EXCEPTION_CALLBACK TYPEDEF PTR QWORD
  
  CPE_DRIVER_INFO struct
    ExceptionCallback PDRIVER_CPE_EXCEPTION_CALLBACK ?
    DpcCallback PKDEFERRED_ROUTINE ?
    DeviceContext PVOID ?
  CPE_DRIVER_INFO ends

  PCPE_DRIVER_INFO typedef ptr CPE_DRIVER_INFO
  
  HAL_PLATFORM_INFORMATION struct
    PlatformFlags DWORD ?
  HAL_PLATFORM_INFORMATION ends

  PHAL_PLATFORM_INFORMATION typedef ptr HAL_PLATFORM_INFORMATION
  
  HAL_PLATFORM_DISABLE_WRITE_COMBINING equ 01h
  HAL_PLATFORM_DISABLE_PTCG equ 04h
  HAL_PLATFORM_DISABLE_UC_MAIN_MEMORY equ 08h
  HAL_PLATFORM_ENABLE_WRITE_COMBINING_MMIO equ 10h
  HAL_PLATFORM_ACPI_TABLES_CACHED equ 20h


      PWHEA_ERROR_SOURCE_DESCRIPTOR typedef ptr _WHEA_ERROR_SOURCE_DESCRIPTOR
      
      PWHEA_ERROR_RECORD typedef ptr _WHEA_ERROR_RECORD
      
      HalBugCheckSystem proto fastcall :PWHEA_ERROR_SOURCE_DESCRIPTOR, :PWHEA_ERROR_RECORD

      PWHEA_ERROR_RECORD typedef ptr _WHEA_ERROR_RECORD


  PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE typedef SDWORD
  ResourceTypeSingle EQU 0 
  ResourceTypeRange EQU 1
  ResourceTypeExtendedCounterConfiguration EQU 2
  ResourceTypeOverflow EQU 3
  ResourceTypeMax EQU 4
  
  PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR struct
    Type_ PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE ?
    Flags DWORD ?
    union u
      CounterIndex DWORD ?
      ExtendedRegisterAddress DWORD ?
      struct Range
        Begin DWORD ?
        End_ DWORD ?
      ends
    ends
  PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR ends

  PPHYSICAL_COUNTER_RESOURCE_DESCRIPTOR typedef ptr PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR
  
  PHYSICAL_COUNTER_RESOURCE_LIST struct
    Count DWORD ?
    Descriptors PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR ANYSIZE_ARRAY dup (<>)
  PHYSICAL_COUNTER_RESOURCE_LIST ends

  PPHYSICAL_COUNTER_RESOURCE_LIST typedef ptr PHYSICAL_COUNTER_RESOURCE_LIST
  

    HalAllocateHardwareCounters proto fastcall :PGROUP_AFFINITY, :DWORD, :PPHYSICAL_COUNTER_RESOURCE_LIST, :PHANDLE

    HalFreeHardwareCounters proto fastcall :HANDLE


    pcixechdr RECORD Version:4, Next:12
    PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER struct
      CapabilityID WORD ?
      struct
      pcixechdr <>
      ends
    PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER ends

    IFNDEF 
    PCI_CAPABILITIES_HEADER struct
      CapabilityID  UCHAR ?
      Next          UCHAR ?
    PCI_CAPABILITIES_HEADER ends
    ENDIF 
    PPCI_CAPABILITIES_HEADER typedef ptr PCI_CAPABILITIES_HEADER

    PCI_AGP_VER RECORD Minor:4,Major:4,Rsvdv:8
    
    PCI_AGP_STATUS RECORD Rate1:3, Agp3Mode:1, FastWrite:1, FourGB:1, HostTransDisable:1, Gart641:1, ITA_Coherent:1, SideBandAddressing:1, CalibrationCycle1:3, AsyncRequestSize:3, Rsvd1:1, Isoch:1, Rsvd2:6, RequestQueueDepthMaximum:8
    
    PCI_AGP_COMMAND RECORD Rate2:3, Rsvd3:1, FastWriteEnable:1, FourGBEnable:1, Rsvd4:1, Gart642:1, AGPEnable:1, SBAEnable:1, CalibrationCycle2:3, AsyncReqSize:3, Rsvd5:8, RequestQueueDepth:8
    
    PCI_AGP_CAPABILITY STRUCT
    
        Header PCI_CAPABILITIES_HEADER <>
    
        STRUCT
        pciagpver PCI_AGP_VER <>
        ENDS
        
        STRUCT
        pciagpstatus PCI_AGP_STATUS <>
        ENDS
        
        STRUCT
        pciagpcommand PCI_AGP_COMMAND <>
        ENDS
    
    PCI_AGP_CAPABILITY ENDS

  PPCI_AGP_CAPABILITY typedef ptr PCI_AGP_CAPABILITY
  
  EXTENDED_AGP_REGISTER typedef SDWORD
  IsochStatus EQU 0
  AgpControl EQU 1
  ApertureSize EQU 2
  AperturePageSize EQU 3
  GartLow EQU 4
  GartHigh EQU 5
  IsochCommand EQU 6
  
  PEXTENDED_AGP_REGISTER typedef ptr EXTENDED_AGP_REGISTER
  
  PCI_AGP_ISOCH_STATUS struct
    PCI_AGP_ISOCH_STATUS_??28 record ErrorCode_??28:2, Rsvd1_??28:1, Isoch_L_??28:3, Isoch_Y_??28:2, Isoch_N_??28:8, Rsvd2_??28:16
    PCI_AGP_ISOCH_STATUS_??28 <>
  PCI_AGP_ISOCH_STATUS ends

  PPCI_AGP_ISOCH_STATUS typedef ptr PCI_AGP_ISOCH_STATUS
  
  PCI_AGP_CONTROL struct
    PCI_AGP_CONTROL_??29 record Rsvd1_??29:7, GTLB_Enable_??29:1, AP_Enable_??29:1, CAL_Disable_??29:1, Rsvd2_??29:22
    PCI_AGP_CONTROL_??29 <>
  PCI_AGP_CONTROL ends

  PPCI_AGP_CONTROL typedef ptr PCI_AGP_CONTROL
  
  PCI_AGP_APERTURE_PAGE_SIZE struct
    PCI_AGP_APERTURE_PAGE_SIZE_??30 record PageSizeMask_??30:11, Rsvd1_??30:1, PageSizeSelect_??30:4
    PCI_AGP_APERTURE_PAGE_SIZE_??30 <>
  PCI_AGP_APERTURE_PAGE_SIZE ends

  PPCI_AGP_APERTURE_PAGE_SIZE typedef ptr PCI_AGP_APERTURE_PAGE_SIZE
  
  PCI_AGP_ISOCH_COMMAND struct
    PCI_AGP_ISOCH_COMMAND_??31 record Rsvd1_??31:6, Isoch_Y_??31:2, Isoch_N_??31:8
    PCI_AGP_ISOCH_COMMAND_??31 <>
  PCI_AGP_ISOCH_COMMAND ends

  PPCI_AGP_ISOCH_COMMAND typedef ptr PCI_AGP_ISOCH_COMMAND
  
  PCI_AGP_EXTENDED_CAPABILITY struct
    IsochStatus PCI_AGP_ISOCH_STATUS <>
    AgpControl PCI_AGP_CONTROL <>
    ApertureSize WORD ?
    AperturePageSize PCI_AGP_APERTURE_PAGE_SIZE <>
    GartLow DWORD ?
    GartHigh DWORD ?
    IsochCommand PCI_AGP_ISOCH_COMMAND <>
  PCI_AGP_EXTENDED_CAPABILITY ends

  PPCI_AGP_EXTENDED_CAPABILITY typedef ptr PCI_AGP_EXTENDED_CAPABILITY
  
  PCI_AGP_RATE_1X equ 1h
  PCI_AGP_RATE_2X equ 2h
  PCI_AGP_RATE_4X equ 4h
  PCIX_MODE_CONVENTIONAL_PCI equ 0h
  PCIX_MODE1_66MHZ equ 1h
  PCIX_MODE1_100MHZ equ 2h
  PCIX_MODE1_133MHZ equ 3h
  PCIX_MODE2_266_66MHZ equ 9h
  PCIX_MODE2_266_100MHZ equ 0Ah
  PCIX_MODE2_266_133MHZ equ 0Bh
  PCIX_MODE2_533_66MHZ equ 0Dh
  PCIX_MODE2_533_100MHZ equ 0Eh
  PCIX_MODE2_533_133MHZ equ 0Fh
  PCIX_VERSION_MODE1_ONLY equ 0h
  PCIX_VERSION_MODE2_ECC equ 1h
  PCIX_VERSION_DUAL_MODE_ECC equ 2h
  PCIX_BRIDGE_CAPABILITY struct
    Header PCI_CAPABILITIES_HEADER <>
    union SecondaryStatus
      struct DUMMYSTRUCTNAME_38
        DUMMYSTRUCTNAME_38_??32 record Bus64Bit_??32:1, Bus133MHzCapable_??32:1, SplitCompletionDiscarded_??32:1, UnexpectedSplitCompletion_??32:1, SplitCompletionOverrun_??32:1, SplitRequestDelayed_??32:1, BusModeFrequency_??32:4, Rsvd_??32:2, Version_??32:2, Bus266MHzCapable_??32:1, Bus533MHzCapable_??32:1
        DUMMYSTRUCTNAME_38_??32 <>
      ends
      AsUSHORT WORD ?
    ends
    union BridgeStatus
      struct DUMMYSTRUCTNAME_39
        DUMMYSTRUCTNAME_39_??33 record FunctionNumber_??33:3, DeviceNumber_??33:5, BusNumber_??33:8, Device64Bit_??33:1, Device133MHzCapable_??33:1, SplitCompletionDiscarded_??33:1, UnexpectedSplitCompletion_??33:1, SplitCompletionOverrun_??33:1, SplitRequestDelayed_??33:1, Rsvd_??33:7, DIMCapable_??33:1, Device266MHzCapable_??33:1, Device533MHzCapable_??33:1
        DUMMYSTRUCTNAME_39_??33 <>
      ends
      AsULONG DWORD ?
    ends
    UpstreamSplitTransactionCapacity WORD ?
    UpstreamSplitTransactionLimit WORD ?
    DownstreamSplitTransactionCapacity WORD ?
    DownstreamSplitTransactionLimit WORD ?
    union EccControlStatus
      struct DUMMYSTRUCTNAME_40
        DUMMYSTRUCTNAME_40_??34 record SelectSecondaryRegisters_??34:1, ErrorPresentInOtherBank_??34:1, AdditionalCorrectableError_??34:1, AdditionalUncorrectableError_??34:1, ErrorPhase_??34:3, ErrorCorrected_??34:1, Syndrome_??34:8, ErrorFirstCommand_??34:4, ErrorSecondCommand_??34:4, ErrorUpperAttributes_??34:4, ControlUpdateEnable_??34:1, Rsvd_??34:1, DisableSingleBitCorrection_??34:1, EccMode_??34:1
        DUMMYSTRUCTNAME_40_??34 <>
      ends
      AsULONG DWORD ?
    ends
    EccFirstAddress DWORD ?
    EccSecondAddress DWORD ?
    EccAttribute DWORD ?
  PCIX_BRIDGE_CAPABILITY ends

  PPCIX_BRIDGE_CAPABILITY typedef ptr PCIX_BRIDGE_CAPABILITY
  
  PCI_SUBSYSTEM_IDS_CAPABILITY struct
    Header PCI_CAPABILITIES_HEADER <>
    Reserved WORD ?
    SubVendorID WORD ?
    SubSystemID WORD ?
  PCI_SUBSYSTEM_IDS_CAPABILITY ends

  PPCI_SUBSYSTEM_IDS_CAPABILITY typedef ptr PCI_SUBSYSTEM_IDS_CAPABILITY
  
  PCI_ADVANCED_FEATURES_CAPABILITY struct
    Header PCI_CAPABILITIES_HEADER <>
    Length_ BYTE ?
    union Capabilities
      struct DUMMYSTRUCTNAME_41
        DUMMYSTRUCTNAME_41_??35 record FunctionLevelResetSupported_??35:1, TransactionsPendingSupported_??35:1, Rsvd_??35:6
        DUMMYSTRUCTNAME_41_??35 <>
      ends
      AsUCHAR BYTE ?
    ends
    union Control
      struct DUMMYSTRUCTNAME_42
        DUMMYSTRUCTNAME_42_??36 record InitiateFunctionLevelReset_??36:1, Rsvd_??36:7
        DUMMYSTRUCTNAME_42_??36 <>
      ends
      AsUCHAR BYTE ?
    ends
    union Status
      struct DUMMYSTRUCTNAME_43
        DUMMYSTRUCTNAME_43_??37 record TransactionsPending_??37:1, Rsvd_??37:7
        DUMMYSTRUCTNAME_43_??37 <>
      ends
      AsUCHAR BYTE ?
    ends
  PCI_ADVANCED_FEATURES_CAPABILITY ends

  PPCI_ADVANCED_FEATURES_CAPABILITY typedef ptr PCI_ADVANCED_FEATURES_CAPABILITY
  
  OSC_FIRMWARE_FAILURE equ 02h
  OSC_UNRECOGNIZED_UUID equ 04h
  OSC_UNRECOGNIZED_REVISION equ 08h
  OSC_CAPABILITIES_MASKED equ 10h
  PCI_ROOT_BUS_OSC_METHOD_CAPABILITY_REVISION equ 01h
  PCI_ROOT_BUS_OSC_SUPPORT_FIELD struct
    union u
      struct DUMMYSTRUCTNAME_44
        DUMMYSTRUCTNAME_44_??38 record ExtendedConfigOpRegions_??38:1, ActiveStatePowerManagement_??38:1, ClockPowerManagement_??38:1, SegmentGroups_??38:1, MessageSignaledInterrupts_??38:1, OptimizedBufferFlushAndFill_??38:1, AspmOptionality_??38:1, Reserved_??38:25
        DUMMYSTRUCTNAME_44_??38 <>
      ends
      AsULONG DWORD ?
    ends
  PCI_ROOT_BUS_OSC_SUPPORT_FIELD ends

  PPCI_ROOT_BUS_OSC_SUPPORT_FIELD typedef ptr PCI_ROOT_BUS_OSC_SUPPORT_FIELD
  
  PCI_ROOT_BUS_OSC_CONTROL_FIELD struct
    union u
      struct DUMMYSTRUCTNAME_45
        DUMMYSTRUCTNAME_45_??39 record ExpressNativeHotPlug_??39:1, ShpcNativeHotPlug_??39:1, ExpressNativePME_??39:1, ExpressAdvancedErrorReporting_??39:1, ExpressCapabilityStructure_??39:1, LatencyToleranceReporting_??39:1, Reserved_??39:26
        DUMMYSTRUCTNAME_45_??39 <>
      ends
      AsULONG DWORD ?
    ends
  PCI_ROOT_BUS_OSC_CONTROL_FIELD ends

  PPCI_ROOT_BUS_OSC_CONTROL_FIELD typedef ptr PCI_ROOT_BUS_OSC_CONTROL_FIELD
  
  PCI_FIRMWARE_BUS_CAPS struct
    Type_ WORD ?
    Length_ WORD ?
    struct DUMMYSTRUCTNAME_46
      DUMMYSTRUCTNAME_46_??40 record SixtyFourBitDevice_??40:1, PciXMode1EccCapable_??40:1, DeviceIdMessagingCapable_??40:1, ObffWakeSignalCapable_??40:1, Reserved1_??40:4
      DUMMYSTRUCTNAME_46_??40 <>
    ends
    CurrentSpeedAndMode BYTE ?
    SupportedSpeedsAndModesLowByte BYTE ?
    SupportedSpeedsAndModesHighByte BYTE ?
    Voltage BYTE ?
    Reserved2 BYTE 7 dup (?)
  PCI_FIRMWARE_BUS_CAPS ends

  PPCI_FIRMWARE_BUS_CAPS typedef ptr PCI_FIRMWARE_BUS_CAPS
  
  PCI_FIRMWARE_BUS_CAPS_RETURN_BUFFER struct
    Version WORD ?
    Status WORD ?
    Length_ DWORD ?
    Caps PCI_FIRMWARE_BUS_CAPS <>
  PCI_FIRMWARE_BUS_CAPS_RETURN_BUFFER ends

  PPCI_FIRMWARE_BUS_CAPS_RETURN_BUFFER typedef ptr PCI_FIRMWARE_BUS_CAPS_RETURN_BUFFER
  
  PCI_HARDWARE_INTERFACE typedef SDWORD
  PciConventional EQU 0
  PciXMode1 EQU 1
  PciXMode2 EQU 2
  PciExpress EQU 3
  
  PPCI_HARDWARE_INTERFACE typedef ptr PCI_HARDWARE_INTERFACE
  
  PCI_BUS_WIDTH typedef SDWORD
  BusWidth32Bits EQU 0
  BusWidth64Bits EQU 1
  
  PCI_ROOT_BUS_HARDWARE_CAPABILITY struct
    SecondaryInterface PCI_HARDWARE_INTERFACE ?
    struct DUMMYSTRUCTNAME_47
      BusCapabilitiesFound BOOLEAN ?
      CurrentSpeedAndMode DWORD ?
      SupportedSpeedsAndModes DWORD ?
      DeviceIDMessagingCapable BOOLEAN ?
      SecondaryBusWidth PCI_BUS_WIDTH ?
    ends
    OscFeatureSupport PCI_ROOT_BUS_OSC_SUPPORT_FIELD <>
    OscControlRequest PCI_ROOT_BUS_OSC_CONTROL_FIELD <>
    OscControlGranted PCI_ROOT_BUS_OSC_CONTROL_FIELD <>
  PCI_ROOT_BUS_HARDWARE_CAPABILITY ends

  PPCI_ROOT_BUS_HARDWARE_CAPABILITY typedef ptr PCI_ROOT_BUS_HARDWARE_CAPABILITY
  
  PCI_EXPRESS_CAPABILITIES_REGISTER union
    struct DUMMYSTRUCTNAME_48
      DUMMYSTRUCTNAME_48_??41 record CapabilityVersion_??41:4, DeviceType_??41:4, SlotImplemented_??41:1, InterruptMessageNumber_??41:5, Rsvd_??41:2
      DUMMYSTRUCTNAME_48_??41 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_CAPABILITIES_REGISTER ends

  PPCI_EXPRESS_CAPABILITIES_REGISTER typedef ptr PCI_EXPRESS_CAPABILITIES_REGISTER
  
  PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER union
    struct DUMMYSTRUCTNAME_49
      DUMMYSTRUCTNAME_49_??42 record MaxPayloadSizeSupported_??42:3, PhantomFunctionsSupported_??42:2, ExtendedTagSupported_??42:1, L0sAcceptableLatency_??42:3, L1AcceptableLatency_??42:3, Undefined_??42:3, RoleBasedErrorReporting_??42:1, Rsvd1_??42:2, CapturedSlotPowerLimit_??42:8, CapturedSlotPowerLimitScale_??42:2, FunctionLevelResetCapability_??42:1, Rsvd2_??42:3
      DUMMYSTRUCTNAME_49_??42 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER ends

  PPCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER typedef ptr PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER
  
  PCI_EXPRESS_AER_DEVICE_CONTROL_MASK equ 07h ;
  PCI_EXPRESS_DEVICE_CONTROL_REGISTER union
    struct DUMMYSTRUCTNAME_50
      DUMMYSTRUCTNAME_50_??43 record CorrectableErrorEnable_??43:1, NonFatalErrorEnable_??43:1, FatalErrorEnable_??43:1, UnsupportedRequestErrorEnable_??43:1, EnableRelaxedOrder_??43:1, MaxPayloadSize_??43:3, ExtendedTagEnable_??43:1, PhantomFunctionsEnable_??43:1, AuxPowerEnable_??43:1, NoSnoopEnable_??43:1, MaxReadRequestSize_??43:3, BridgeConfigRetryEnable_??43:1
      DUMMYSTRUCTNAME_50_??43 <>
    ends
    struct DUMMYSTRUCTNAME2
      DUMMYSTRUCTNAME2_??44 record USHORT_??44:15, InitiateFunctionLevelReset_??44:1
      DUMMYSTRUCTNAME2_??44 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_DEVICE_CONTROL_REGISTER ends

  PPCI_EXPRESS_DEVICE_CONTROL_REGISTER typedef ptr PCI_EXPRESS_DEVICE_CONTROL_REGISTER
  
  PCI_EXPRESS_AER_DEVICE_STATUS_MASK equ 0Fh ;
  PCI_EXPRESS_DEVICE_STATUS_REGISTER union
    struct DUMMYSTRUCTNAME_51
      DUMMYSTRUCTNAME_51_??45 record CorrectableErrorDetected_??45:1, NonFatalErrorDetected_??45:1, FatalErrorDetected_??45:1, UnsupportedRequestDetected_??45:1, AuxPowerDetected_??45:1, TransactionsPending_??45:1, Rsvd_??45:10
      DUMMYSTRUCTNAME_51_??45 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_DEVICE_STATUS_REGISTER ends

  PPCI_EXPRESS_DEVICE_STATUS_REGISTER typedef ptr PCI_EXPRESS_DEVICE_STATUS_REGISTER
  
  PCI_EXPRESS_LINK_CAPABILITIES_REGISTER union
    struct DUMMYSTRUCTNAME_52
      DUMMYSTRUCTNAME_52_??46 record MaximumLinkSpeed_??46:4, MaximumLinkWidth_??46:6, ActiveStatePMSupport_??46:2, L0sExitLatency_??46:3, L1ExitLatency_??46:3, ClockPowerManagement_??46:1, SurpriseDownErrorReportingCapable_??46:1, DataLinkLayerActiveReportingCapable_??46:1, LinkBandwidthNotificationCapability_??46:1, AspmOptionalityCompliance_??46:1, Rsvd_??46:1, PortNumber_??46:8
      DUMMYSTRUCTNAME_52_??46 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_LINK_CAPABILITIES_REGISTER ends

  PPCI_EXPRESS_LINK_CAPABILITIES_REGISTER typedef ptr PCI_EXPRESS_LINK_CAPABILITIES_REGISTER
  
  PCI_EXPRESS_LINK_CONTROL_REGISTER union
    struct DUMMYSTRUCTNAME_53
      DUMMYSTRUCTNAME_53_??47 record ActiveStatePMControl_??47:2, Rsvd1_??47:1, ReadCompletionBoundary_??47:1, LinkDisable_??47:1, RetrainLink_??47:1, CommonClockConfig_??47:1, ExtendedSynch_??47:1, EnableClockPowerManagement_??47:1, Rsvd2_??47:7
      DUMMYSTRUCTNAME_53_??47 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_LINK_CONTROL_REGISTER ends

  PPCI_EXPRESS_LINK_CONTROL_REGISTER typedef ptr PCI_EXPRESS_LINK_CONTROL_REGISTER
  
  PCI_EXPRESS_LINK_STATUS_REGISTER union
    struct DUMMYSTRUCTNAME_54
      DUMMYSTRUCTNAME_54_??48 record LinkSpeed_??48:4, LinkWidth_??48:6, Undefined_??48:1, LinkTraining_??48:1, SlotClockConfig_??48:1, DataLinkLayerActive_??48:1, Rsvd_??48:2
      DUMMYSTRUCTNAME_54_??48 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_LINK_STATUS_REGISTER ends

  PPCI_EXPRESS_LINK_STATUS_REGISTER typedef ptr PCI_EXPRESS_LINK_STATUS_REGISTER
  
  PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER union
    struct DUMMYSTRUCTNAME_55
      DUMMYSTRUCTNAME_55_??49 record AttentionButtonPresent_??49:1, PowerControllerPresent_??49:1, MRLSensorPresent_??49:1, AttentionIndicatorPresent_??49:1, PowerIndicatorPresent_??49:1, HotPlugSurprise_??49:1, HotPlugCapable_??49:1, SlotPowerLimit_??49:8, SlotPowerLimitScale_??49:2, ElectromechanicalLockPresent_??49:1, NoCommandCompletedSupport_??49:1, PhysicalSlotNumber_??49:13
      DUMMYSTRUCTNAME_55_??49 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER ends

  PPCI_EXPRESS_SLOT_CAPABILITIES_REGISTER typedef ptr PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER
  
  PCI_EXPRESS_SLOT_CONTROL_REGISTER union
    struct DUMMYSTRUCTNAME_56
      DUMMYSTRUCTNAME_56_??50 record AttentionButtonEnable_??50:1, PowerFaultDetectEnable_??50:1, MRLSensorEnable_??50:1, PresenceDetectEnable_??50:1, CommandCompletedEnable_??50:1, HotPlugInterruptEnable_??50:1, AttentionIndicatorControl_??50:2, PowerIndicatorControl_??50:2, PowerControllerControl_??50:1, ElectromechanicalLockControl_??50:1, DataLinkStateChangeEnable_??50:1, Rsvd_??50:3
      DUMMYSTRUCTNAME_56_??50 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_SLOT_CONTROL_REGISTER ends

  PPCI_EXPRESS_SLOT_CONTROL_REGISTER typedef ptr PCI_EXPRESS_SLOT_CONTROL_REGISTER
  
  PCI_EXPRESS_SLOT_STATUS_REGISTER union
    struct DUMMYSTRUCTNAME_57
      DUMMYSTRUCTNAME_57_??51 record AttentionButtonPressed_??51:1, PowerFaultDetected_??51:1, MRLSensorChanged_??51:1, PresenceDetectChanged_??51:1, CommandCompleted_??51:1, MRLSensorState_??51:1, PresenceDetectState_??51:1, ElectromechanicalLockEngaged_??51:1, DataLinkStateChanged_??51:1, Rsvd_??51:7
      DUMMYSTRUCTNAME_57_??51 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_SLOT_STATUS_REGISTER ends

  PPCI_EXPRESS_SLOT_STATUS_REGISTER typedef ptr PCI_EXPRESS_SLOT_STATUS_REGISTER
  
  PCI_EXPRESS_ROOT_CONTROL_REGISTER union
    struct DUMMYSTRUCTNAME_58
      DUMMYSTRUCTNAME_58_??52 record CorrectableSerrEnable_??52:1, NonFatalSerrEnable_??52:1, FatalSerrEnable_??52:1, PMEInterruptEnable_??52:1, CRSSoftwareVisibilityEnable_??52:1, Rsvd_??52:11
      DUMMYSTRUCTNAME_58_??52 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_ROOT_CONTROL_REGISTER ends

  PPCI_EXPRESS_ROOT_CONTROL_REGISTER typedef ptr PCI_EXPRESS_ROOT_CONTROL_REGISTER
  
  PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER union
    struct DUMMYSTRUCTNAME_59
      DUMMYSTRUCTNAME_59_??53 record CRSSoftwareVisibility_??53:1, Rsvd_??53:15
      DUMMYSTRUCTNAME_59_??53 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER ends

  PPCI_EXPRESS_ROOT_CAPABILITIES_REGISTER typedef ptr PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER
  
  PCI_EXPRESS_ROOT_STATUS_REGISTER union
    struct DUMMYSTRUCTNAME_60
      DUMMYSTRUCTNAME_60_??54 record PMERequestorId_??54:16, PMEStatus_??54:1, PMEPending_??54:1, Rsvd_??54:14
      DUMMYSTRUCTNAME_60_??54 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_ROOT_STATUS_REGISTER ends

  PPCI_EXPRESS_ROOT_STATUS_REGISTER typedef ptr PCI_EXPRESS_ROOT_STATUS_REGISTER
  
  PCI_EXPRESS_DEVICE_CAPABILITIES_2_REGISTER union
    struct DUMMYSTRUCTNAME_61
      DUMMYSTRUCTNAME_61_??55 record CompletionTimeoutRangesSupported_??55:4, CompletionTimeoutDisableSupported_??55:1, AriForwardingSupported_??55:1, AtomicOpRoutingSupported_??55:1, AtomicOpCompleterSupported32Bit_??55:1, AtomicOpCompleterSupported64Bit_??55:1, CASCompleterSupported128Bit_??55:1, NoROEnabledPRPRPassing_??55:1, LTRMechanismSupported_??55:1, TPHCompleterSupported_??55:2, Rsvd_??55:4, OBFFSupported_??55:2, ExtendedFmtFieldSuported_??55:1, EndEndTLPPrefixSupported_??55:1, MaxEndEndTLPPrefixes_??55:2, Rsvd2_??55:8
      DUMMYSTRUCTNAME_61_??55 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_DEVICE_CAPABILITIES_2_REGISTER ends

  PPCI_EXPRESS_DEVICE_CAPABILITIES_2_REGISTER typedef ptr PCI_EXPRESS_DEVICE_CAPABILITIES_2_REGISTER
  
  PCI_EXPRESS_DEVICE_CONTROL_2_REGISTER union
    struct DUMMYSTRUCTNAME_62
      DUMMYSTRUCTNAME_62_??56 record CompletionTimeoutValue_??56:4, CompletionTimeoutDisable_??56:1, AriForwardingEnable_??56:1, AtomicOpRequesterEnable_??56:1, AtomicOpEgresBlocking_??56:1, IDORequestEnable_??56:1, IDOCompletionEnable_??56:1, LTRMechanismEnable_??56:1, Rsvd_??56:2, OBFFEnable_??56:2, EndEndTLPPrefixBlocking_??56:1
      DUMMYSTRUCTNAME_62_??56 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_DEVICE_CONTROL_2_REGISTER ends

  PPCI_EXPRESS_DEVICE_CONTROL_2_REGISTER typedef ptr PCI_EXPRESS_DEVICE_CONTROL_2_REGISTER
  
  PCI_EXPRESS_DEVICE_STATUS_2_REGISTER union
    struct DUMMYSTRUCTNAME_63
      DUMMYSTRUCTNAME_63_??57 record Rsvd_??57:16
      DUMMYSTRUCTNAME_63_??57 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_DEVICE_STATUS_2_REGISTER ends

  PPCI_EXPRESS_DEVICE_STATUS_2_REGISTER typedef ptr PCI_EXPRESS_DEVICE_STATUS_2_REGISTER
  
  PCI_EXPRESS_CAPABILITY struct
    Header PCI_CAPABILITIES_HEADER <>
    ExpressCapabilities PCI_EXPRESS_CAPABILITIES_REGISTER <>
    DeviceCapabilities PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER <>
    DeviceControl PCI_EXPRESS_DEVICE_CONTROL_REGISTER <>
    DeviceStatus PCI_EXPRESS_DEVICE_STATUS_REGISTER <>
    LinkCapabilities PCI_EXPRESS_LINK_CAPABILITIES_REGISTER <>
    LinkControl PCI_EXPRESS_LINK_CONTROL_REGISTER <>
    LinkStatus PCI_EXPRESS_LINK_STATUS_REGISTER <>
    SlotCapabilities PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER <>
    SlotControl PCI_EXPRESS_SLOT_CONTROL_REGISTER <>
    SlotStatus PCI_EXPRESS_SLOT_STATUS_REGISTER <>
    RootControl PCI_EXPRESS_ROOT_CONTROL_REGISTER <>
    RootCapabilities PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER <>
    RootStatus PCI_EXPRESS_ROOT_STATUS_REGISTER <>
    DeviceCapabilities2 PCI_EXPRESS_DEVICE_CAPABILITIES_2_REGISTER <>
    DeviceControl2 PCI_EXPRESS_DEVICE_CONTROL_2_REGISTER <>
    DeviceStatus2 PCI_EXPRESS_DEVICE_STATUS_2_REGISTER <>
  PCI_EXPRESS_CAPABILITY ends

  PPCI_EXPRESS_CAPABILITY typedef ptr PCI_EXPRESS_CAPABILITY
  
  PCI_EXPRESS_MRL_STATE typedef SDWORD
  MRLClosed EQU 0 
  MRLOpen EQU 1
  
  PCI_EXPRESS_CARD_PRESENCE typedef SDWORD
  SlotEmpty EQU 0 
  CardPresent EQU 1
  
  PCI_EXPRESS_INDICATOR_STATE typedef SDWORD
  IndicatorOn EQU 1 
  IndicatorBlink EQU 2
  IndicatorOff EQU 3
  
  PCI_EXPRESS_POWER_STATE typedef SDWORD
  PowerOn EQU 0 
  PowerOff EQU 1
  
  PCI_EXPRESS_ASPM_SUPPORT typedef SDWORD
  NoAspmSupport EQU 0 
  L0sEntrySupport EQU 1 
  L1EntrySupport EQU 2 
  L0sAndL1EntrySupport EQU 3 
  
  PCI_EXPRESS_ASPM_CONTROL typedef SDWORD
  L0sAndL1EntryDisabled EQU 0
  L0sEntryEnabled EQU 1
  L1EntryEnabled EQU 2
  L0sAndL1EntryEnabled EQU 3
  
  PCI_EXPRESS_L0s_EXIT_LATENCY typedef SDWORD
  L0s_Below64ns EQU 0 
  L0s_64ns_128ns EQU 1
  L0s_128ns_256ns EQU 2
  L0s_256ns_512ns EQU 3
  L0s_512ns_1us EQU 4
  L0s_1us_2us EQU 5
  L0s_2us_4us EQU 6
  L0s_Above4us EQU 7
  
  PCI_EXPRESS_L1_EXIT_LATENCY typedef SDWORD
  L1_Below1us EQU 0 
  L1_1us_2us EQU 1
  L1_2us_4us EQU 2
  L1_4us_8us EQU 3
  L1_8us_16us EQU 4
  L1_16us_32us EQU 5
  L1_32us_64us EQU 6
  L1_Above64us EQU 7
  
  PCI_EXPRESS_DEVICE_TYPE typedef SDWORD
  PciExpressEndpoint EQU 0 
  PciExpressLegacyEndpoint EQU 1
  PciExpressRootPort EQU 4 
  PciExpressUpstreamSwitchPort EQU 5
  PciExpressDownstreamSwitchPort EQU 6
  PciExpressToPciXBridge EQU 7
  PciXToExpressBridge EQU 8
  PciExpressRootComplexIntegratedEndpoint EQU 9
  PciExpressRootComplexEventCollector EQU 10
  
  PCI_EXPRESS_MAX_PAYLOAD_SIZE typedef SDWORD
  MaxPayload128Bytes EQU 0 
  MaxPayload256Bytes EQU 1
  MaxPayload512Bytes EQU 2
  MaxPayload1024Bytes EQU 3
  MaxPayload2048Bytes EQU 4
  MaxPayload4096Bytes EQU 5
  
  PCI_EXPRESS_PME_REQUESTOR_ID union
    struct DUMMYSTRUCTNAME_64
      DUMMYSTRUCTNAME_64_??58 record FunctionNumber_??58:3, DeviceNumber_??58:5, BusNumber_??58:8
      DUMMYSTRUCTNAME_64_??58 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_PME_REQUESTOR_ID ends

  PPCI_EXPRESS_PME_REQUESTOR_ID typedef ptr PCI_EXPRESS_PME_REQUESTOR_ID


    PCI_SLOT_NUMBER struct
      union u
        struct bits
          bits_??34 record DeviceNumber_??34:5, FunctionNumber_??34:3, Reserved_??34:24
          bits_??34 <>
        ends
        AsULONG DWORD ?
      ends
    PCI_SLOT_NUMBER ends


  PCI_DATA_TAG equ <' ICP'>
  PCI_DATA_VERSION equ 1
  PCIBUSDATA struct
    Tag DWORD ?
    Version DWORD ?
    ReadConfig QWORD ? ;PciReadWriteConfig ?
    WriteConfig QWORD ? ;PciReadWriteConfig ?
    Pin2Line QWORD ? ;PciPin2Line ?
    Line2Pin QWORD ? ;PciLine2Pin ?
    ParentSlot PCI_SLOT_NUMBER <>
    Reserved PVOID 4 dup (?)
  PCIBUSDATA ends

  PPCIBUSDATA typedef ptr PCIBUSDATA
  
  PCI_EXPRESS_LTR_MAX_LATENCY_REGISTER union
    struct DUMMYSTRUCTNAME_65
      DUMMYSTRUCTNAME_65_??59 record MaxSnoopLatencyValue_??59:10, MaxSnoopLatencyScale_??59:3, Rsvd_??59:2, MaxSnoopRequirement_??59:1, MaxNoSnoopLatencyValue_??59:10, MaxNoSnoopLatencyScale_??59:3, Rsvd2_??59:2, MaxNoSnoopRequirement_??59:1
      DUMMYSTRUCTNAME_65_??59 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_LTR_MAX_LATENCY_REGISTER ends

  PPCI_EXPRESS_LTR_MAX_LATENCY_REGISTER typedef ptr PCI_EXPRESS_LTR_MAX_LATENCY_REGISTER
  
  PCI_EXPRESS_LTR_CAPABILITY struct
    Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
    Latency PCI_EXPRESS_LTR_MAX_LATENCY_REGISTER <>
  PCI_EXPRESS_LTR_CAPABILITY ends

  PPCI_EXPRESS_LTR_CAPABILITY typedef ptr PCI_EXPRESS_LTR_CAPABILITY
  
  PCI_EXPRESS_TPH_ST_LOCATION_NONE equ 0
  PCI_EXPRESS_TPH_ST_LOCATION_TPH_CAPABILITY equ 1
  PCI_EXPRESS_TPH_ST_LOCATION_MSIX_TABLE equ 2
  PCI_EXPRESS_TPH_ST_LOCATION_RESERVED equ 3
  PCI_EXPRESS_TPH_REQUESTER_CAPABILITY_REGISTER union
    struct DUMMYSTRUCTNAME_66
      DUMMYSTRUCTNAME_66_??60 record NoStModeSupported_??60:1, InteruptVectorModeSupported_??60:1, DeviceSpecificModeSupported_??60:1, Rsvd_??60:5, ExtendedTPHRequesterSupported_??60:1, StTableLocation_??60:2, Rsvd2_??60:5, StTableSize_??60:11, Rsvd3_??60:5
      DUMMYSTRUCTNAME_66_??60 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_TPH_REQUESTER_CAPABILITY_REGISTER ends

  PPCI_EXPRESS_TPH_REQUESTER_CAPABILITY_REGISTER typedef ptr PCI_EXPRESS_TPH_REQUESTER_CAPABILITY_REGISTER
  
  PCI_EXPRESS_TPH_REQUESTER_CONTROL_REGISTER union
    struct DUMMYSTRUCTNAME_67
      DUMMYSTRUCTNAME_67_??61 record StModeSelect_??61:3, Rsvd_??61:5, TphRequesterEnable_??61:2, Rsvd2_??61:22
      DUMMYSTRUCTNAME_67_??61 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_TPH_REQUESTER_CONTROL_REGISTER ends

  PPCI_EXPRESS_TPH_REQUESTER_CONTROL_REGISTER typedef ptr PCI_EXPRESS_TPH_REQUESTER_CONTROL_REGISTER
  
  PCI_EXPRESS_TPH_ST_TABLE_ENTRY union
    struct DUMMYSTRUCTNAME_68
      DUMMYSTRUCTNAME_68_??62 record LowerEntry_??62:8, UpperEntry_??62:8
      DUMMYSTRUCTNAME_68_??62 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_TPH_ST_TABLE_ENTRY ends

  PPCI_EXPRESS_TPH_ST_TABLE_ENTRY typedef ptr PCI_EXPRESS_TPH_ST_TABLE_ENTRY
  
  PCI_EXPRESS_TPH_REQUESTER_CAPABILITY struct
    Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
    RequesterCapability PCI_EXPRESS_TPH_REQUESTER_CAPABILITY_REGISTER <>
    RequesterControl PCI_EXPRESS_TPH_REQUESTER_CONTROL_REGISTER <>
  PCI_EXPRESS_TPH_REQUESTER_CAPABILITY ends

  PPCI_EXPRESS_TPH_REQUESTER_CAPABILITY typedef ptr PCI_EXPRESS_TPH_REQUESTER_CAPABILITY
  
  PCI_EXPRESS_L1_PM_SS_CAPABILITIES_REGISTER union
    struct DUMMYSTRUCTNAME_69
      DUMMYSTRUCTNAME_69_??63 record PciPmL12Supported_??63:1, PciPmL11Supported_??63:1, AspmL12Supported_??63:1, AspmL11Supported_??63:1, L1PmSsSupported_??63:1, Rsvd_??63:3, PortCommonModeRestoreTime_??63:8, PortTPowerOnScale_??63:2, Rsvd2_??63:1, PortTPowerOnValue_??63:5, Rsvd3_??63:8
      DUMMYSTRUCTNAME_69_??63 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_L1_PM_SS_CAPABILITIES_REGISTER ends

  PPCI_EXPRESS_L1_PM_SS_CAPABILITIES_REGISTER typedef ptr PCI_EXPRESS_L1_PM_SS_CAPABILITIES_REGISTER
  
  PCI_EXPRESS_L1_PM_SS_CONTROL_1_REGISTER union
    struct DUMMYSTRUCTNAME_70
      DUMMYSTRUCTNAME_70_??64 record PciPmL12Enabled_??64:1, PciPmL11Enabled_??64:1, AspmL12Enabled_??64:1, AspmL11Enabled_??64:1, Rsvd_??64:4, CommonModeRestoreTime_??64:8, LtrL12ThresholdValue_??64:10, Rsvd2_??64:3, LtrL12ThresholdScale_??64:3
      DUMMYSTRUCTNAME_70_??64 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_L1_PM_SS_CONTROL_1_REGISTER ends

  PPCI_EXPRESS_L1_PM_SS_CONTROL_1_REGISTER typedef ptr PCI_EXPRESS_L1_PM_SS_CONTROL_1_REGISTER
  
  PCI_EXPRESS_L1_PM_SS_CONTROL_2_REGISTER union
    struct DUMMYSTRUCTNAME_71
      DUMMYSTRUCTNAME_71_??65 record TPowerOnScale_??65:2, Rsvd_??65:1, TPowerOnValue_??65:5, Rsvd2_??65:24
      DUMMYSTRUCTNAME_71_??65 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_L1_PM_SS_CONTROL_2_REGISTER ends

  PPCI_EXPRESS_L1_PM_SS_CONTROL_2_REGISTER typedef ptr PCI_EXPRESS_L1_PM_SS_CONTROL_2_REGISTER
  
  PCI_EXPRESS_L1_PM_SS_CAPABILITY struct
    Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
    L1PmSsCapabilities PCI_EXPRESS_L1_PM_SS_CAPABILITIES_REGISTER <>
    L1PmSsControl1 PCI_EXPRESS_L1_PM_SS_CONTROL_1_REGISTER <>
    L1PmSsControl2 PCI_EXPRESS_L1_PM_SS_CONTROL_2_REGISTER <>
  PCI_EXPRESS_L1_PM_SS_CAPABILITY ends

  PPCI_EXPRESS_L1_PM_SS_CAPABILITY typedef ptr PCI_EXPRESS_L1_PM_SS_CAPABILITY
  
  PCI_EXPRESS_RESIZABLE_BAR_CAPABILITY_REGISTER union
    struct DUMMYSTRUCTNAME_72
      DUMMYSTRUCTNAME_72_??66 record Rsvd_??66:4, SizesSupported_??66:20, Rsvd2_??66:8
      DUMMYSTRUCTNAME_72_??66 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_RESIZABLE_BAR_CAPABILITY_REGISTER ends

  PPCI_EXPRESS_RESIZABLE_BAR_CAPABILITY_REGISTER typedef ptr PCI_EXPRESS_RESIZABLE_BAR_CAPABILITY_REGISTER
  
  PCI_EXPRESS_RESIZABLE_BAR_CONTROL_REGISTER union
    struct DUMMYSTRUCTNAME_73
      DUMMYSTRUCTNAME_73_??67 record BarIndex_??67:3, Rsvd_??67:2, NumberOfResizableBars_??67:3, BarSize_??67:5, Rsvd2_??67:19
      DUMMYSTRUCTNAME_73_??67 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_RESIZABLE_BAR_CONTROL_REGISTER ends

  PPCI_EXPRESS_RESIZABLE_BAR_CONTROL_REGISTER typedef ptr PCI_EXPRESS_RESIZABLE_BAR_CONTROL_REGISTER
  
  PCI_EXPRESS_RESIZABLE_BAR_ENTRY struct
    Capability PCI_EXPRESS_RESIZABLE_BAR_CAPABILITY_REGISTER <>
    Control PCI_EXPRESS_RESIZABLE_BAR_CONTROL_REGISTER <>
  PCI_EXPRESS_RESIZABLE_BAR_ENTRY ends

  PPCI_EXPRESS_RESIZABLE_BAR_ENTRY typedef ptr PCI_EXPRESS_RESIZABLE_BAR_ENTRY
  
  PCI_EXPRESS_RESIZABLE_BAR_CAPABILITY struct
    Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
    Entry PCI_EXPRESS_RESIZABLE_BAR_ENTRY 6 dup (<>)
  PCI_EXPRESS_RESIZABLE_BAR_CAPABILITY ends

  PPCI_EXPRESS_RESIZABLE_BAR_CAPABILITY typedef ptr PCI_EXPRESS_RESIZABLE_BAR_CAPABILITY
  
  PCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_HEADER_1 union
    struct DUMMYSTRUCTNAME_74
      DUMMYSTRUCTNAME_74_??68 record DvsecVendorId_??68:16, DvsecVersion_??68:4, DvsecLength_??68:12
      DUMMYSTRUCTNAME_74_??68 <>
    ends
    AsULONG DWORD ?
  PCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_HEADER_1 ends

  PPCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_HEADER_1 typedef ptr PCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_HEADER_1
  
  PCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_HEADER_2 union
    struct DUMMYSTRUCTNAME_75
      DUMMYSTRUCTNAME_75_??69 record DvsecId_??69:16
      DUMMYSTRUCTNAME_75_??69 <>
    ends
    AsUSHORT WORD ?
  PCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_HEADER_2 ends

  PPCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_HEADER_2 typedef ptr PCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_HEADER_2



  
  PCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_CAPABILITY struct
    Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
    DvsecHeader1 PCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_HEADER_1 <>
    DvsecHeader2 PCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_HEADER_2 <>
    DvsecRegisters WORD 1 dup (?)
  PCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_CAPABILITY ends

  PPCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_CAPABILITY typedef ptr PCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_CAPABILITY

    PCI_TYPE0_ADDRESSES equ 6
    PCI_TYPE1_ADDRESSES equ 2
    PCI_TYPE2_ADDRESSES equ 5

    PCI_COMMON_HEADER struct
      VendorID WORD ?
      DeviceID WORD ?
      Command WORD ?
      Status WORD ?
      RevisionID BYTE ?
      ProgIf BYTE ?
      SubClass BYTE ?
      BaseClass BYTE ?
      CacheLineSize BYTE ?
      LatencyTimer BYTE ?
      HeaderType BYTE ?
      BIST BYTE ?
      union u
        struct type0
          BaseAddresses DWORD PCI_TYPE0_ADDRESSES dup (?)
          CIS DWORD ?
          SubVendorID WORD ?
          SubSystemID WORD ?
          ROMBaseAddress DWORD ?
          CapabilitiesPtr BYTE ?
          Reserved1 BYTE 3 dup (?)
          Reserved2 DWORD ?
          InterruptLine BYTE ?
          InterruptPin BYTE ?
          MinimumGrant BYTE ?
          MaximumLatency BYTE ?
        ends
        struct type1
          BaseAddresses DWORD PCI_TYPE1_ADDRESSES dup (?)
          PrimaryBus BYTE ?
          SecondaryBus BYTE ?
          SubordinateBus BYTE ?
          SecondaryLatency BYTE ?
          IOBase BYTE ?
          IOLimit BYTE ?
          SecondaryStatus WORD ?
          MemoryBase WORD ?
          MemoryLimit WORD ?
          PrefetchBase WORD ?
          PrefetchLimit WORD ?
          PrefetchBaseUpper32 DWORD ?
          PrefetchLimitUpper32 DWORD ?
          IOBaseUpper16 WORD ?
          IOLimitUpper16 WORD ?
          CapabilitiesPtr BYTE ?
          Reserved1 BYTE 3 dup (?)
          ROMBaseAddress DWORD ?
          InterruptLine BYTE ?
          InterruptPin BYTE ?
          BridgeControl WORD ?
        ends
        struct type2
          SocketRegistersBaseAddress DWORD ?
          CapabilitiesPtr BYTE ?
          Reserved BYTE ?
          SecondaryStatus WORD ?
          PrimaryBus BYTE ?
          SecondaryBus BYTE ?
          SubordinateBus BYTE ?
          SecondaryLatency BYTE ?
          struct Range
            Base DWORD ?
            Limit DWORD ?
          ends
          InterruptLine BYTE ?
          InterruptPin BYTE ?
          BridgeControl WORD ?
        ends
      ends
    PCI_COMMON_HEADER ends

    PPCI_COMMON_HEADER typedef ptr PCI_COMMON_HEADER

    IFNDEF PCI_COMMON_CONFIG
    PCI_COMMON_CONFIG STRUCT
      DeviceSpecific    UCHAR 192 DUP (?)
      base_class PCI_COMMON_HEADER <>
    PCI_COMMON_CONFIG ENDS
    ENDIF
    PPCI_COMMON_CONFIG TYPEDEF PTR PCI_COMMON_CONFIG

  
  PCI_INVALID_ALTERNATE_FUNCTION_NUMBER equ 0FFh
  ifndef _PCIINTRF_X_
    _PCIINTRF_X_ equ <>
    PCI_READ_WRITE_CONFIG typedef proto stdcall :PVOID,:DWORD,:DWORD,:PVOID,:DWORD,:DWORD
    PPCI_READ_WRITE_CONFIG typedef ptr PCI_READ_WRITE_CONFIG
    PCI_PIN_TO_LINE typedef proto stdcall :PVOID,:PPCI_COMMON_CONFIG
    PPCI_PIN_TO_LINE typedef ptr PCI_PIN_TO_LINE
    PCI_LINE_TO_PIN typedef proto stdcall :PVOID,:PPCI_COMMON_CONFIG,:PPCI_COMMON_CONFIG
    PPCI_LINE_TO_PIN typedef ptr PCI_LINE_TO_PIN
    PCI_ROOT_BUS_CAPABILITY typedef proto stdcall :PVOID,:PPCI_ROOT_BUS_HARDWARE_CAPABILITY
    PPCI_ROOT_BUS_CAPABILITY typedef ptr PCI_ROOT_BUS_CAPABILITY
    PCI_EXPRESS_WAKE_CONTROL typedef proto stdcall :PVOID,:BOOLEAN
    PPCI_EXPRESS_WAKE_CONTROL typedef ptr PCI_EXPRESS_WAKE_CONTROL
    PCI_PREPARE_MULTISTAGE_RESUME typedef proto stdcall :PVOID
    PPCI_PREPARE_MULTISTAGE_RESUME typedef ptr PCI_PREPARE_MULTISTAGE_RESUME
    PCI_BUS_INTERFACE_STANDARD struct
      Size_ WORD ?
      Version WORD ?
      Context PVOID ?
      InterfaceReference PINTERFACE_REFERENCE ?
      InterfaceDereference PINTERFACE_DEREFERENCE ?
      ReadConfig PPCI_READ_WRITE_CONFIG ?
      WriteConfig PPCI_READ_WRITE_CONFIG ?
      PinToLine PPCI_PIN_TO_LINE ?
      LineToPin PPCI_LINE_TO_PIN ?
      RootBusCapability PPCI_ROOT_BUS_CAPABILITY ?
      ExpressWakeControl PPCI_EXPRESS_WAKE_CONTROL ?
      PrepareMultistageResume PPCI_PREPARE_MULTISTAGE_RESUME ?
    PCI_BUS_INTERFACE_STANDARD ends

    PPCI_BUS_INTERFACE_STANDARD typedef ptr PCI_BUS_INTERFACE_STANDARD
    
    PCI_BUS_INTERFACE_STANDARD_VERSION equ 2
    PCI_BUS_INTERFACE_STANDARD_VERSION_1_LENGTH equ <FIELD_OFFSET ( PCI_BUS_INTERFACE_STANDARD , PrepareMultistageResume )>
  endif



  WHEA_PHYSICAL_ADDRESS equ <LARGE_INTEGER>
  WHEA_ERROR_SOURCE_TYPE typedef SDWORD
  WheaErrSrcTypeMCE EQU 00h 
  WheaErrSrcTypeCMC EQU 01h 
  WheaErrSrcTypeCPE EQU 02h 
  WheaErrSrcTypeNMI EQU 03h 
  WheaErrSrcTypePCIe EQU 04h 
  WheaErrSrcTypeGeneric EQU 05h 
  WheaErrSrcTypeINIT EQU 06h 
  WheaErrSrcTypeBOOT EQU 07h 
  WheaErrSrcTypeSCIGeneric EQU 08h 
  WheaErrSrcTypeIPFMCA EQU 09h 
  WheaErrSrcTypeIPFCMC EQU 0ah 
  WheaErrSrcTypeIPFCPE EQU 0bh 
  WheaErrSrcTypeGenericV2 EQU 0ch 
  WheaErrSrcTypeSCIGenericV2 EQU 0dh 
  WheaErrSrcTypeMax EQU 1
  
  PWHEA_ERROR_SOURCE_TYPE typedef ptr WHEA_ERROR_SOURCE_TYPE
  
  WHEA_ERROR_SOURCE_STATE typedef SDWORD
  WheaErrSrcStateStopped EQU 01h 
  WheaErrSrcStateStarted EQU 02h 
  
  PWHEA_ERROR_SOURCE_STATE typedef ptr WHEA_ERROR_SOURCE_STATE
  
  WHEA_ERROR_SOURCE_DESCRIPTOR_VERSION_10 equ 10
  WHEA_MAX_MC_BANKS equ 32
  WHEA_ERROR_SOURCE_FLAG_FIRMWAREFIRST equ 00000001h
  WHEA_ERROR_SOURCE_FLAG_GLOBAL equ 00000002h
  WHEA_ERROR_SOURCE_FLAG_PREALLOCATE_PER_PROCESSOR equ 00000004h
  WHEA_ERROR_SOURCE_FLAG_DEFAULTSOURCE equ 80000000h
  WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_XPFMCE equ 0
  WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_XPFCMC equ 1
  WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_XPFNMI equ 2
  WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_IPFMCA equ 3
  WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_IPFCMC equ 4
  WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_IPFCPE equ 5
  WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_AERROOTPORT equ 6
  WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_AERENDPOINT equ 7
  WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_AERBRIDGE equ 8
  WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_GENERIC equ 9
  WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_GENERIC_V2 equ 10
  WHEA_XPF_MC_BANK_STATUSFORMAT_IA32MCA equ 0
  WHEA_XPF_MC_BANK_STATUSFORMAT_Intel64MCA equ 1
  WHEA_XPF_MC_BANK_STATUSFORMAT_AMD64MCA equ 2
  WHEA_NOTIFICATION_TYPE_POLLED equ 0
  WHEA_NOTIFICATION_TYPE_EXTERNALINTERRUPT equ 1
  WHEA_NOTIFICATION_TYPE_LOCALINTERRUPT equ 2
  WHEA_NOTIFICATION_TYPE_SCI equ 3
  WHEA_NOTIFICATION_TYPE_NMI equ 4
  WHEA_NOTIFICATION_TYPE_CMCI equ 5
  WHEA_NOTIFICATION_TYPE_MCE equ 6
  WHEA_NOTIFICATION_TYPE_GPIO_SIGNAL equ 7
  WHEA_NOTIFICATION_TYPE_ARMV8_SEA equ 8
  WHEA_NOTIFICATION_TYPE_ARMV8_SEI equ 9
  WHEA_NOTIFICATION_TYPE_EXTERNALINTERRUPT_GSIV equ 10
  WHEA_NOTIFICATION_TYPE_SDEI equ 11

  WHEA_NOTIFICATION_FLAGS union
    struct DUMMYSTRUCTNAME_76
      DUMMYSTRUCTNAME_76_??70 record PollIntervalRW_??70:1, SwitchToPollingThresholdRW_??70:1, SwitchToPollingWindowRW_??70:1, ErrorThresholdRW_??70:1, ErrorThresholdWindowRW_??70:1, Reserved_??70:11
      DUMMYSTRUCTNAME_76_??70 <>
    ends
    AsUSHORT WORD ?
  WHEA_NOTIFICATION_FLAGS ends

  PWHEA_NOTIFICATION_FLAGS typedef ptr WHEA_NOTIFICATION_FLAGS
  
  XPF_MC_BANK_FLAGS union
    struct DUMMYSTRUCTNAME_77
      DUMMYSTRUCTNAME_77_??71 record ClearOnInitializationRW_??71:1, ControlDataRW_??71:1, Reserved_??71:6
      DUMMYSTRUCTNAME_77_??71 <>
    ends
    AsUCHAR BYTE ?
  XPF_MC_BANK_FLAGS ends

  PXPF_MC_BANK_FLAGS typedef ptr XPF_MC_BANK_FLAGS
  
  XPF_MCE_FLAGS union
    struct DUMMYSTRUCTNAME_78
      DUMMYSTRUCTNAME_78_??72 record MCG_CapabilityRW_??72:1, MCG_GlobalControlRW_??72:1, Reserved_??72:30
      DUMMYSTRUCTNAME_78_??72 <>
    ends
    AsULONG DWORD ?
  XPF_MCE_FLAGS ends

  PXPF_MCE_FLAGS typedef ptr XPF_MCE_FLAGS
  
  AER_ROOTPORT_DESCRIPTOR_FLAGS union
    struct DUMMYSTRUCTNAME_79
      DUMMYSTRUCTNAME_79_??73 record UncorrectableErrorMaskRW_??73:1, UncorrectableErrorSeverityRW_??73:1, CorrectableErrorMaskRW_??73:1, AdvancedCapsAndControlRW_??73:1, RootErrorCommandRW_??73:1, Reserved_??73:11
      DUMMYSTRUCTNAME_79_??73 <>
    ends
    AsUSHORT WORD ?
  AER_ROOTPORT_DESCRIPTOR_FLAGS ends

  PAER_ROOTPORT_DESCRIPTOR_FLAGS typedef ptr AER_ROOTPORT_DESCRIPTOR_FLAGS
  
  AER_ENDPOINT_DESCRIPTOR_FLAGS union
    struct DUMMYSTRUCTNAME_80
      DUMMYSTRUCTNAME_80_??74 record UncorrectableErrorMaskRW_??74:1, UncorrectableErrorSeverityRW_??74:1, CorrectableErrorMaskRW_??74:1, AdvancedCapsAndControlRW_??74:1, Reserved_??74:12
      DUMMYSTRUCTNAME_80_??74 <>
    ends
    AsUSHORT WORD ?
  AER_ENDPOINT_DESCRIPTOR_FLAGS ends

  PAER_ENDPOINT_DESCRIPTOR_FLAGS typedef ptr AER_ENDPOINT_DESCRIPTOR_FLAGS
  
  AER_BRIDGE_DESCRIPTOR_FLAGS union
    struct DUMMYSTRUCTNAME_81
      DUMMYSTRUCTNAME_81_??75 record UncorrectableErrorMaskRW_??75:1, UncorrectableErrorSeverityRW_??75:1, CorrectableErrorMaskRW_??75:1, AdvancedCapsAndControlRW_??75:1, SecondaryUncorrectableErrorMaskRW_??75:1, SecondaryUncorrectableErrorSevRW_??75:1, SecondaryCapsAndControlRW_??75:1, Reserved_??75:9
      DUMMYSTRUCTNAME_81_??75 <>
    ends
    AsUSHORT WORD ?
  AER_BRIDGE_DESCRIPTOR_FLAGS ends

  PAER_BRIDGE_DESCRIPTOR_FLAGS typedef ptr AER_BRIDGE_DESCRIPTOR_FLAGS
  
  WHEA_NOTIFICATION_DESCRIPTOR struct
    Type_ BYTE ?
    Length_ BYTE ?
    Flags WHEA_NOTIFICATION_FLAGS <>
    union u
      struct Polled
        PollInterval DWORD ?
      ends
      struct Interrupt
        PollInterval DWORD ?
        Vector DWORD ?
        SwitchToPollingThreshold DWORD ?
        SwitchToPollingWindow DWORD ?
        ErrorThreshold DWORD ?
        ErrorThresholdWindow DWORD ?
      ends
      struct LocalInterrupt
        PollInterval DWORD ?
        Vector DWORD ?
        SwitchToPollingThreshold DWORD ?
        SwitchToPollingWindow DWORD ?
        ErrorThreshold DWORD ?
        ErrorThresholdWindow DWORD ?
      ends
      struct Sci
        PollInterval DWORD ?
        Vector DWORD ?
        SwitchToPollingThreshold DWORD ?
        SwitchToPollingWindow DWORD ?
        ErrorThreshold DWORD ?
        ErrorThresholdWindow DWORD ?
      ends
      struct Nmi
        PollInterval DWORD ?
        Vector DWORD ?
        SwitchToPollingThreshold DWORD ?
        SwitchToPollingWindow DWORD ?
        ErrorThreshold DWORD ?
        ErrorThresholdWindow DWORD ?
      ends
      struct Sea
        PollInterval DWORD ?
        Vector DWORD ?
        SwitchToPollingThreshold DWORD ?
        SwitchToPollingWindow DWORD ?
        ErrorThreshold DWORD ?
        ErrorThresholdWindow DWORD ?
      ends
      struct Sei
        PollInterval DWORD ?
        Vector DWORD ?
        SwitchToPollingThreshold DWORD ?
        SwitchToPollingWindow DWORD ?
        ErrorThreshold DWORD ?
        ErrorThresholdWindow DWORD ?
      ends
      struct Gsiv
        PollInterval DWORD ?
        Vector DWORD ?
        SwitchToPollingThreshold DWORD ?
        SwitchToPollingWindow DWORD ?
        ErrorThreshold DWORD ?
        ErrorThresholdWindow DWORD ?
      ends
    ends
  WHEA_NOTIFICATION_DESCRIPTOR ends

  PWHEA_NOTIFICATION_DESCRIPTOR typedef ptr WHEA_NOTIFICATION_DESCRIPTOR
  
  WHEA_XPF_MC_BANK_DESCRIPTOR struct
    BankNumber BYTE ?
    ClearOnInitialization BOOLEAN ?
    StatusDataFormat BYTE ?
    Flags XPF_MC_BANK_FLAGS <>
    ControlMsr DWORD ?
    StatusMsr DWORD ?
    AddressMsr DWORD ?
    MiscMsr DWORD ?
    ControlData QWORD ?
  WHEA_XPF_MC_BANK_DESCRIPTOR ends

  PWHEA_XPF_MC_BANK_DESCRIPTOR typedef ptr WHEA_XPF_MC_BANK_DESCRIPTOR
  
  WHEA_XPF_MCE_DESCRIPTOR struct
    Type_ WORD ?
    Enabled BYTE ?
    NumberOfBanks BYTE ?
    Flags XPF_MCE_FLAGS <>
    MCG_Capability QWORD ?
    MCG_GlobalControl QWORD ?
    Banks WHEA_XPF_MC_BANK_DESCRIPTOR WHEA_MAX_MC_BANKS dup (<>)
  WHEA_XPF_MCE_DESCRIPTOR ends

  PWHEA_XPF_MCE_DESCRIPTOR typedef ptr WHEA_XPF_MCE_DESCRIPTOR
  
  WHEA_XPF_CMC_DESCRIPTOR struct
    Type_ WORD ?
    Enabled BOOLEAN ?
    NumberOfBanks BYTE ?
    Reserved DWORD ?
    Notify WHEA_NOTIFICATION_DESCRIPTOR <>
    Banks WHEA_XPF_MC_BANK_DESCRIPTOR WHEA_MAX_MC_BANKS dup (<>)
  WHEA_XPF_CMC_DESCRIPTOR ends

  PWHEA_XPF_CMC_DESCRIPTOR typedef ptr WHEA_XPF_CMC_DESCRIPTOR
  
  WHEA_PCI_SLOT_NUMBER struct
    union u
      struct bits
        bits_??76 record DeviceNumber_??76:5, FunctionNumber_??76:3, Reserved_??76:24
        bits_??76 <>
      ends
      AsULONG DWORD ?
    ends
  WHEA_PCI_SLOT_NUMBER ends

  PWHEA_PCI_SLOT_NUMBER typedef ptr WHEA_PCI_SLOT_NUMBER
  
  WHEA_XPF_NMI_DESCRIPTOR struct
    Type_ WORD ?
    Enabled BOOLEAN ?
  WHEA_XPF_NMI_DESCRIPTOR ends

  PWHEA_XPF_NMI_DESCRIPTOR typedef ptr WHEA_XPF_NMI_DESCRIPTOR
  
  WHEA_AER_ROOTPORT_DESCRIPTOR struct
    Type_ WORD ?
    Enabled BOOLEAN ?
    Reserved BYTE ?
    BusNumber DWORD ?
    Slot WHEA_PCI_SLOT_NUMBER <>
    DeviceControl WORD ?
    Flags AER_ROOTPORT_DESCRIPTOR_FLAGS <>
    UncorrectableErrorMask DWORD ?
    UncorrectableErrorSeverity DWORD ?
    CorrectableErrorMask DWORD ?
    AdvancedCapsAndControl DWORD ?
    RootErrorCommand DWORD ?
  WHEA_AER_ROOTPORT_DESCRIPTOR ends

  PWHEA_AER_ROOTPORT_DESCRIPTOR typedef ptr WHEA_AER_ROOTPORT_DESCRIPTOR
  
  WHEA_AER_ENDPOINT_DESCRIPTOR struct
    Type_ WORD ?
    Enabled BOOLEAN ?
    Reserved BYTE ?
    BusNumber DWORD ?
    Slot WHEA_PCI_SLOT_NUMBER <>
    DeviceControl WORD ?
    Flags AER_ENDPOINT_DESCRIPTOR_FLAGS <>
    UncorrectableErrorMask DWORD ?
    UncorrectableErrorSeverity DWORD ?
    CorrectableErrorMask DWORD ?
    AdvancedCapsAndControl DWORD ?
  WHEA_AER_ENDPOINT_DESCRIPTOR ends

  PWHEA_AER_ENDPOINT_DESCRIPTOR typedef ptr WHEA_AER_ENDPOINT_DESCRIPTOR
  
  WHEA_AER_BRIDGE_DESCRIPTOR struct
    Type_ WORD ?
    Enabled BOOLEAN ?
    Reserved BYTE ?
    BusNumber DWORD ?
    Slot WHEA_PCI_SLOT_NUMBER <>
    DeviceControl WORD ?
    Flags AER_BRIDGE_DESCRIPTOR_FLAGS <>
    UncorrectableErrorMask DWORD ?
    UncorrectableErrorSeverity DWORD ?
    CorrectableErrorMask DWORD ?
    AdvancedCapsAndControl DWORD ?
    SecondaryUncorrectableErrorMask DWORD ?
    SecondaryUncorrectableErrorSev DWORD ?
    SecondaryCapsAndControl DWORD ?
  WHEA_AER_BRIDGE_DESCRIPTOR ends

  PWHEA_AER_BRIDGE_DESCRIPTOR typedef ptr WHEA_AER_BRIDGE_DESCRIPTOR
  
  WHEA_GENERIC_ERROR_DESCRIPTOR struct
    Type_ WORD ?
    Reserved BYTE ?
    Enabled BYTE ?
    ErrStatusBlockLength DWORD ?
    RelatedErrorSourceId DWORD ?
    ErrStatusAddressSpaceID BYTE ?
    ErrStatusAddressBitWidth BYTE ?
    ErrStatusAddressBitOffset BYTE ?
    ErrStatusAddressAccessSize BYTE ?
    ErrStatusAddress WHEA_PHYSICAL_ADDRESS <>
    Notify WHEA_NOTIFICATION_DESCRIPTOR <>
  WHEA_GENERIC_ERROR_DESCRIPTOR ends

  PWHEA_GENERIC_ERROR_DESCRIPTOR typedef ptr WHEA_GENERIC_ERROR_DESCRIPTOR
  
  WHEA_GENERIC_ERROR_DESCRIPTOR_V2 struct
    Type_ WORD ?
    Reserved BYTE ?
    Enabled BYTE ?
    ErrStatusBlockLength DWORD ?
    RelatedErrorSourceId DWORD ?
    ErrStatusAddressSpaceID BYTE ?
    ErrStatusAddressBitWidth BYTE ?
    ErrStatusAddressBitOffset BYTE ?
    ErrStatusAddressAccessSize BYTE ?
    ErrStatusAddress WHEA_PHYSICAL_ADDRESS <>
    Notify WHEA_NOTIFICATION_DESCRIPTOR <>
    ReadAckAddressSpaceID BYTE ?
    ReadAckAddressBitWidth BYTE ?
    ReadAckAddressBitOffset BYTE ?
    ReadAckAddressAccessSize BYTE ?
    ReadAckAddress WHEA_PHYSICAL_ADDRESS <>
    ReadAckPreserveMask QWORD ?
    ReadAckWriteMask QWORD ?
  WHEA_GENERIC_ERROR_DESCRIPTOR_V2 ends

  PWHEA_GENERIC_ERROR_DESCRIPTOR_V2 typedef ptr WHEA_GENERIC_ERROR_DESCRIPTOR_V2
  
  WHEA_IPF_MCA_DESCRIPTOR struct
    Type_ WORD ?
    Enabled BYTE ?
    Reserved BYTE ?
  WHEA_IPF_MCA_DESCRIPTOR ends

  PWHEA_IPF_MCA_DESCRIPTOR typedef ptr WHEA_IPF_MCA_DESCRIPTOR
  
  WHEA_IPF_CMC_DESCRIPTOR struct
    Type_ WORD ?
    Enabled BYTE ?
    Reserved BYTE ?
  WHEA_IPF_CMC_DESCRIPTOR ends

  PWHEA_IPF_CMC_DESCRIPTOR typedef ptr WHEA_IPF_CMC_DESCRIPTOR
  
  WHEA_IPF_CPE_DESCRIPTOR struct
    Type_ WORD ?
    Enabled BYTE ?
    Reserved BYTE ?
  WHEA_IPF_CPE_DESCRIPTOR ends

  PWHEA_IPF_CPE_DESCRIPTOR typedef ptr WHEA_IPF_CPE_DESCRIPTOR
  
  WHEA_ERROR_SOURCE_DESCRIPTOR struct
    Length_ DWORD ?
    Version DWORD ?
    Type_ WHEA_ERROR_SOURCE_TYPE ?
    State WHEA_ERROR_SOURCE_STATE ?
    MaxRawDataLength DWORD ?
    NumRecordsToPreallocate DWORD ?
    MaxSectionsPerRecord DWORD ?
    ErrorSourceId DWORD ?
    PlatformErrorSourceId DWORD ?
    Flags DWORD ?
    union Info
      XpfMceDescriptor WHEA_XPF_MCE_DESCRIPTOR <>
      XpfCmcDescriptor WHEA_XPF_CMC_DESCRIPTOR <>
      XpfNmiDescriptor WHEA_XPF_NMI_DESCRIPTOR <>
      IpfMcaDescriptor WHEA_IPF_MCA_DESCRIPTOR <>
      IpfCmcDescriptor WHEA_IPF_CMC_DESCRIPTOR <>
      IpfCpeDescriptor WHEA_IPF_CPE_DESCRIPTOR <>
      AerRootportDescriptor WHEA_AER_ROOTPORT_DESCRIPTOR <>
      AerEndpointDescriptor WHEA_AER_ENDPOINT_DESCRIPTOR <>
      AerBridgeDescriptor WHEA_AER_BRIDGE_DESCRIPTOR <>
      GenErrDescriptor WHEA_GENERIC_ERROR_DESCRIPTOR <>
      GenErrDescriptorV2 WHEA_GENERIC_ERROR_DESCRIPTOR_V2 <>
    ends
  WHEA_ERROR_SOURCE_DESCRIPTOR ends

  
  WHEA_DISABLE_OFFLINE equ 0
  WHEA_MEM_PERSISTOFFLINE equ 1
  WHEA_MEM_PFA_DISABLE equ 2
  WHEA_MEM_PFA_PAGECOUNT equ 3
  WHEA_MEM_PFA_THRESHOLD equ 4
  WHEA_MEM_PFA_TIMEOUT equ 5
  WHEA_DISABLE_DUMMY_WRITE equ 6

  CPER_FIELD_CHECK macro type_,field_,offset_,length_
   exitm <C_ASSERT ( ( ( FIELD_OFFSET ( type_ , field_ ) == ( offset_ ) ) and ( RTL_FIELD_SIZE ( type_ , field_ ) == ( length_ ) ) ) ) >
  endm


    PROCESSOR_GENERIC_SECTION_GUID equ <PROCESSOR_GENERIC_ERROR_SECTION_GUID>
    X86_PROCESSOR_SPECIFIC_SECTION_GUID equ <XPF_PROCESSOR_ERROR_SECTION_GUID>
    IPF_PROCESSOR_SPECIFIC_SECTION_GUID equ <IPF_PROCESSOR_ERROR_SECTION_GUID>
    ARM_PROCESSOR_SPECIFIC_SECTION_GUID equ <ARM_PROCESSOR_ERROR_SECTION_GUID>
    PLATFORM_MEMORY_SECTION_GUID equ <MEMORY_ERROR_SECTION_GUID>
    PCIEXPRESS_SECTION_GUID equ <PCIEXPRESS_ERROR_SECTION_GUID>
    PCIX_BUS_SECTION_GUID equ <PCIXBUS_ERROR_SECTION_GUID>
    PCIX_COMPONENT_SECTION_GUID equ <PCIXDEVICE_ERROR_SECTION_GUID>
    IPF_SAL_RECORD_REFERENCE_SECTION_GUID equ <FIRMWARE_ERROR_RECORD_REFERENCE_GUID>

  WHEA_REVISION union
    struct DUMMYSTRUCTNAME_82
      MinorRevision BYTE ?
      MajorRevision BYTE ?
    ends
    AsUSHORT WORD ?
  WHEA_REVISION ends

  PWHEA_REVISION typedef ptr WHEA_REVISION
  
  WHEA_ERROR_SEVERITY typedef SDWORD
  WheaErrSevRecoverable EQU 0 
  WheaErrSevFatal EQU 1 
  WheaErrSevCorrected EQU 2 
  WheaErrSevInformational EQU 3 
  
  PWHEA_ERROR_SEVERITY typedef ptr WHEA_ERROR_SEVERITY
  
  WHEA_TIMESTAMP union
    struct DUMMYSTRUCTNAME_83
      DUMMYSTRUCTNAME_83_??77 record Seconds_??77:8, Minutes_??77:8, Hours_??77:8, Precise_??77:1, Reserved_??77:7, Day_??77:8, Month_??77:8, Year_??77:8, Century_??77:8
      DUMMYSTRUCTNAME_83_??77 <>
    ends
    AsLARGE_INTEGER LARGE_INTEGER <>
  WHEA_TIMESTAMP ends

  PWHEA_TIMESTAMP typedef ptr WHEA_TIMESTAMP
  
  WHEA_PERSISTENCE_INFO union
    struct DUMMYSTRUCTNAME_84
      DUMMYSTRUCTNAME_84_??78 record Signature_??78:16, Length_??78:24, Identifier_??78:16, Attributes_??78:2, DoNotLog_??78:1, Reserved_??78:5
      DUMMYSTRUCTNAME_84_??78 <>
    ends
    AsULONGLONG QWORD ?
  WHEA_PERSISTENCE_INFO ends

  PWHEA_PERSISTENCE_INFO typedef ptr WHEA_PERSISTENCE_INFO
  
  ERRTYP_INTERNAL equ 01h
  ERRTYP_BUS equ 10h
  ERRTYP_MEM equ 04h
  ERRTYP_TLB equ 05h
  ERRTYP_CACHE equ 06h
  ERRTYP_FUNCTION equ 07h
  ERRTYP_SELFTEST equ 08h
  ERRTYP_FLOW equ 09h
  ERRTYP_MAP equ 11h
  ERRTYP_IMPROPER equ 12h
  ERRTYP_UNIMPL equ 13h
  ERRTYP_LOSSOFLOCKSTEP equ 14h
  ERRTYP_RESPONSE equ 15h
  ERRTYP_PARITY equ 16h
  ERRTYP_PROTOCOL equ 17h
  ERRTYP_PATHERROR equ 18h
  ERRTYP_TIMEOUT equ 19h
  ERRTYP_POISONED equ 1Ah
  WHEA_ERROR_STATUS union
    ErrorStatus QWORD ?
    struct DUMMYSTRUCTNAME_85
      DUMMYSTRUCTNAME_85_??79 record Reserved1_??79:8, ErrorType_??79:8, Address_??79:1, Control_??79:1, Data_??79:1, Responder_??79:1, Requester_??79:1, FirstError_??79:1, Overflow_??79:1, Reserved2_??79:41
      DUMMYSTRUCTNAME_85_??79 <>
    ends
  WHEA_ERROR_STATUS ends

  PWHEA_ERROR_STATUS typedef ptr WHEA_ERROR_STATUS
  
  WHEA_ERROR_RECORD_HEADER_VALIDBITS union
    struct DUMMYSTRUCTNAME_86
      DUMMYSTRUCTNAME_86_??80 record PlatformId_??80:1, Timestamp_??80:1, PartitionId_??80:1, Reserved_??80:29
      DUMMYSTRUCTNAME_86_??80 <>
    ends
    AsULONG DWORD ?
  WHEA_ERROR_RECORD_HEADER_VALIDBITS ends

  PWHEA_ERROR_RECORD_HEADER_VALIDBITS typedef ptr WHEA_ERROR_RECORD_HEADER_VALIDBITS
  
  WHEA_ERROR_RECORD_VALID_PLATFORMID equ 00000001h
  WHEA_ERROR_RECORD_VALID_TIMESTAMP equ 00000002h
  WHEA_ERROR_RECORD_VALID_PARTITIONID equ 00000004h
  WHEA_ERROR_RECORD_HEADER_FLAGS union
    struct DUMMYSTRUCTNAME_87
      DUMMYSTRUCTNAME_87_??81 record Recovered_??81:1, PreviousError_??81:1, Simulated_??81:1, Reserved_??81:29
      DUMMYSTRUCTNAME_87_??81 <>
    ends
    AsULONG DWORD ?
  WHEA_ERROR_RECORD_HEADER_FLAGS ends

  PWHEA_ERROR_RECORD_HEADER_FLAGS typedef ptr WHEA_ERROR_RECORD_HEADER_FLAGS
  
  WHEA_ERROR_RECORD_FLAGS_RECOVERED equ 00000001h
  WHEA_ERROR_RECORD_FLAGS_PREVIOUSERROR equ 00000002h
  WHEA_ERROR_RECORD_FLAGS_SIMULATED equ 00000004h
  WHEA_ERROR_RECORD_HEADER struct
    Signature DWORD ?
    Revision WHEA_REVISION <>
    SignatureEnd DWORD ?
    SectionCount WORD ?
    Severity WHEA_ERROR_SEVERITY ?
    ValidBits WHEA_ERROR_RECORD_HEADER_VALIDBITS <>
    Length_ DWORD ?
    Timestamp WHEA_TIMESTAMP <>
    PlatformId GUID <>
    PartitionId GUID <>
    CreatorId GUID <>
    NotifyType GUID <>
    RecordId QWORD ?
    Flags WHEA_ERROR_RECORD_HEADER_FLAGS <>
    PersistenceInfo WHEA_PERSISTENCE_INFO <>
    Reserved BYTE 12 dup (?)
  WHEA_ERROR_RECORD_HEADER ends

  PWHEA_ERROR_RECORD_HEADER typedef ptr WHEA_ERROR_RECORD_HEADER
  
  WHEA_ERROR_RECORD_SIGNATURE equ <'REPC'>
  WHEA_ERROR_RECORD_REVISION equ 0210h
  WHEA_ERROR_RECORD_SIGNATURE_END equ 0FFFFFFFFh

  WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS union
    struct DUMMYSTRUCTNAME_88
      DUMMYSTRUCTNAME_88_??82 record Primary_??82:1, ContainmentWarning_??82:1, Reset_??82:1, ThresholdExceeded_??82:1, ResourceNotAvailable_??82:1, LatentError_??82:1, Propagated_??82:1, Reserved_??82:25
      DUMMYSTRUCTNAME_88_??82 <>
    ends
    AsULONG DWORD ?
  WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS ends

  PWHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS typedef ptr WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS
  
  WHEA_SECTION_DESCRIPTOR_FLAGS_PRIMARY equ 00000001h
  WHEA_SECTION_DESCRIPTOR_FLAGS_CONTAINMENTWRN equ 00000002h
  WHEA_SECTION_DESCRIPTOR_FLAGS_RESET equ 00000004h
  WHEA_SECTION_DESCRIPTOR_FLAGS_THRESHOLDEXCEEDED equ 00000008h
  WHEA_SECTION_DESCRIPTOR_FLAGS_RESOURCENA equ 00000010h
  WHEA_SECTION_DESCRIPTOR_FLAGS_LATENTERROR equ 00000020h
  WHEA_SECTION_DESCRIPTOR_FLAGS_PROPAGATED equ 00000040h
  WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS union
    struct DUMMYSTRUCTNAME_89
      DUMMYSTRUCTNAME_89_??83 record FRUId_??83:1, FRUText_??83:1, Reserved_??83:6
      DUMMYSTRUCTNAME_89_??83 <>
    ends
    AsUCHAR BYTE ?
  WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS ends

  PWHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS typedef ptr WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS
  
  WHEA_ERROR_RECORD_SECTION_DESCRIPTOR struct
    SectionOffset DWORD ?
    SectionLength DWORD ?
    Revision WHEA_REVISION <>
    ValidBits WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS <>
    Reserved BYTE ?
    Flags WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS <>
    SectionType GUID <>
    FRUId GUID <>
    SectionSeverity WHEA_ERROR_SEVERITY ?
    FRUText CCHAR 20 dup (?)
  WHEA_ERROR_RECORD_SECTION_DESCRIPTOR ends

  PWHEA_ERROR_RECORD_SECTION_DESCRIPTOR typedef ptr WHEA_ERROR_RECORD_SECTION_DESCRIPTOR
  
  WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_REVISION equ 0300h

    WHEA_SECTION_DESCRIPTOR_REVISION equ <WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_REVISION>


  WHEA_ERROR_RECORD struct
    Header WHEA_ERROR_RECORD_HEADER <>
    SectionDescriptor WHEA_ERROR_RECORD_SECTION_DESCRIPTOR ANYSIZE_ARRAY dup (<>)
  WHEA_ERROR_RECORD ends

  

  GENPROC_PROCTYPE_XPF equ 0
  GENPROC_PROCTYPE_IPF equ 1
  GENPROC_PROCTYPE_ARM equ 2
  GENPROC_PROCISA_X86 equ 0
  GENPROC_PROCISA_IPF equ 1
  GENPROC_PROCISA_X64 equ 2
  GENPROC_PROCISA_ARM32 equ 4
  GENPROC_PROCISA_ARM64 equ 8
  GENPROC_PROCERRTYPE_UNKNOWN equ 0
  GENPROC_PROCERRTYPE_CACHE equ 1
  GENPROC_PROCERRTYPE_TLB equ 2
  GENPROC_PROCERRTYPE_BUS equ 4
  GENPROC_PROCERRTYPE_MAE equ 8
  GENPROC_OP_GENERIC equ 0
  GENPROC_OP_DATAREAD equ 1
  GENPROC_OP_DATAWRITE equ 2
  GENPROC_OP_INSTRUCTIONEXE equ 3
  GENPROC_FLAGS_RESTARTABLE equ 01h
  GENPROC_FLAGS_PRECISEIP equ 02h
  GENPROC_FLAGS_OVERFLOW equ 04h
  GENPROC_FLAGS_CORRECTED equ 08h
  WHEA_PROCESSOR_FAMILY_INFO union
    struct DUMMYSTRUCTNAME_90
      DUMMYSTRUCTNAME_90_??84 record Stepping_??84:4, Model_??84:4, Family_??84:4, ProcessorType_??84:2, Reserved1_??84:2, ExtendedModel_??84:4, ExtendedFamily_??84:8, Reserved2_??84:4
      DUMMYSTRUCTNAME_90_??84 <>
      Reserved3 DWORD ?
    ends
    AsULONGLONG QWORD ?
  WHEA_PROCESSOR_FAMILY_INFO ends

  PWHEA_PROCESSOR_FAMILY_INFO typedef ptr WHEA_PROCESSOR_FAMILY_INFO
  
  WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS union
    struct DUMMYSTRUCTNAME_91
      DUMMYSTRUCTNAME_91_??85 record ProcessorType_??85:1, InstructionSet_??85:1, ErrorType_??85:1, Operation_??85:1, Flags_??85:1, Level_??85:1, CPUVersion_??85:1, CPUBrandString_??85:1, ProcessorId_??85:1, TargetAddress_??85:1, RequesterId_??85:1, ResponderId_??85:1, InstructionPointer_??85:1, Reserved_??85:51
      DUMMYSTRUCTNAME_91_??85 <>
    ends
    ValidBits QWORD ?
  WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS ends

  PWHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS typedef ptr WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS
  
  WHEA_PROCESSOR_GENERIC_ERROR_SECTION struct
    ValidBits WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS <>
    ProcessorType BYTE ?
    InstructionSet BYTE ?
    ErrorType BYTE ?
    Operation BYTE ?
    Flags BYTE ?
    Level BYTE ?
    Reserved WORD ?
    CPUVersion QWORD ?
    CPUBrandString BYTE 128 dup (?)
    ProcessorId QWORD ?
    TargetAddress QWORD ?
    RequesterId QWORD ?
    ResponderId QWORD ?
    InstructionPointer QWORD ?
  WHEA_PROCESSOR_GENERIC_ERROR_SECTION ends

  PWHEA_PROCESSOR_GENERIC_ERROR_SECTION typedef ptr WHEA_PROCESSOR_GENERIC_ERROR_SECTION
  

    WHEA_GENERIC_PROCESSOR_ERROR_VALIDBITS typedef WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS
    PWHEA_GENERIC_PROCESSOR_ERROR_VALIDBITS typedef ptr WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS
    WHEA_GENERIC_PROCESSOR_ERROR typedef WHEA_PROCESSOR_GENERIC_ERROR_SECTION
    PWHEA_GENERIC_PROCESSOR_ERROR typedef ptr WHEA_PROCESSOR_GENERIC_ERROR_SECTION


  XPF_CACHE_CHECK_TRANSACTIONTYPE_INSTRUCTION equ 0
  XPF_CACHE_CHECK_TRANSACTIONTYPE_DATAACCESS equ 1
  XPF_CACHE_CHECK_TRANSACTIONTYPE_GENERIC equ 2
  XPF_CACHE_CHECK_OPERATION_GENERIC equ 0
  XPF_CACHE_CHECK_OPERATION_GENREAD equ 1
  XPF_CACHE_CHECK_OPERATION_GENWRITE equ 2
  XPF_CACHE_CHECK_OPERATION_DATAREAD equ 3
  XPF_CACHE_CHECK_OPERATION_DATAWRITE equ 4
  XPF_CACHE_CHECK_OPERATION_INSTRUCTIONFETCH equ 5
  XPF_CACHE_CHECK_OPERATION_PREFETCH equ 6
  XPF_CACHE_CHECK_OPERATION_EVICTION equ 7
  XPF_CACHE_CHECK_OPERATION_SNOOP equ 8
  WHEA_XPF_CACHE_CHECK union
    struct DUMMYSTRUCTNAME_92
      DUMMYSTRUCTNAME_92_??86 record TransactionTypeValid_??86:1, OperationValid_??86:1, LevelValid_??86:1, ProcessorContextCorruptValid_??86:1, UncorrectedValid_??86:1, PreciseIPValid_??86:1, RestartableIPValid_??86:1, OverflowValid_??86:1, ReservedValid_??86:8, TransactionType_??86:2, Operation_??86:4, Level_??86:3, ProcessorContextCorrupt_??86:1, Uncorrected_??86:1, PreciseIP_??86:1, RestartableIP_??86:1, Overflow_??86:1, Reserved_??86:34
      DUMMYSTRUCTNAME_92_??86 <>
    ends
    XpfCacheCheck QWORD ?
  WHEA_XPF_CACHE_CHECK ends

  PWHEA_XPF_CACHE_CHECK typedef ptr WHEA_XPF_CACHE_CHECK
  
  XPF_TLB_CHECK_TRANSACTIONTYPE_INSTRUCTION equ 0
  XPF_TLB_CHECK_TRANSACTIONTYPE_DATAACCESS equ 1
  XPF_TLB_CHECK_TRANSACTIONTYPE_GENERIC equ 2
  XPF_TLB_CHECK_OPERATION_GENERIC equ 0
  XPF_TLB_CHECK_OPERATION_GENREAD equ 1
  XPF_TLB_CHECK_OPERATION_GENWRITE equ 2
  XPF_TLB_CHECK_OPERATION_DATAREAD equ 3
  XPF_TLB_CHECK_OPERATION_DATAWRITE equ 4
  XPF_TLB_CHECK_OPERATION_INSTRUCTIONFETCH equ 5
  XPF_TLB_CHECK_OPERATION_PREFETCH equ 6
  WHEA_XPF_TLB_CHECK union
    struct DUMMYSTRUCTNAME_93
      DUMMYSTRUCTNAME_93_??87 record TransactionTypeValid_??87:1, OperationValid_??87:1, LevelValid_??87:1, ProcessorContextCorruptValid_??87:1, UncorrectedValid_??87:1, PreciseIPValid_??87:1, RestartableIPValid_??87:1, OverflowValid_??87:1, ReservedValid_??87:8, TransactionType_??87:2, Operation_??87:4, Level_??87:3, ProcessorContextCorrupt_??87:1, Uncorrected_??87:1, PreciseIP_??87:1, RestartableIP_??87:1, Overflow_??87:1, Reserved_??87:34
      DUMMYSTRUCTNAME_93_??87 <>
    ends
    XpfTLBCheck QWORD ?
  WHEA_XPF_TLB_CHECK ends

  PWHEA_XPF_TLB_CHECK typedef ptr WHEA_XPF_TLB_CHECK
  
  XPF_BUS_CHECK_TRANSACTIONTYPE_INSTRUCTION equ 0
  XPF_BUS_CHECK_TRANSACTIONTYPE_DATAACCESS equ 1
  XPF_BUS_CHECK_TRANSACTIONTYPE_GENERIC equ 2
  XPF_BUS_CHECK_OPERATION_GENERIC equ 0
  XPF_BUS_CHECK_OPERATION_GENREAD equ 1
  XPF_BUS_CHECK_OPERATION_GENWRITE equ 2
  XPF_BUS_CHECK_OPERATION_DATAREAD equ 3
  XPF_BUS_CHECK_OPERATION_DATAWRITE equ 4
  XPF_BUS_CHECK_OPERATION_INSTRUCTIONFETCH equ 5
  XPF_BUS_CHECK_OPERATION_PREFETCH equ 6
  XPF_BUS_CHECK_PARTICIPATION_PROCORIGINATED equ 0
  XPF_BUS_CHECK_PARTICIPATION_PROCRESPONDED equ 1
  XPF_BUS_CHECK_PARTICIPATION_PROCOBSERVED equ 2
  XPF_BUS_CHECK_PARTICIPATION_GENERIC equ 3
  XPF_BUS_CHECK_ADDRESS_MEMORY equ 0
  XPF_BUS_CHECK_ADDRESS_RESERVED equ 1
  XPF_BUS_CHECK_ADDRESS_IO equ 2
  XPF_BUS_CHECK_ADDRESS_OTHER equ 3
  WHEA_XPF_BUS_CHECK union
    struct DUMMYSTRUCTNAME_94
      DUMMYSTRUCTNAME_94_??88 record TransactionTypeValid_??88:1, OperationValid_??88:1, LevelValid_??88:1, ProcessorContextCorruptValid_??88:1, UncorrectedValid_??88:1, PreciseIPValid_??88:1, RestartableIPValid_??88:1, OverflowValid_??88:1, ParticipationValid_??88:1, TimeoutValid_??88:1, AddressSpaceValid_??88:1, ReservedValid_??88:5, TransactionType_??88:2, Operation_??88:4, Level_??88:3, ProcessorContextCorrupt_??88:1, Uncorrected_??88:1, PreciseIP_??88:1, RestartableIP_??88:1, Overflow_??88:1, Participation_??88:2, Timeout_??88:1, AddressSpace_??88:2, Reserved_??88:29
      DUMMYSTRUCTNAME_94_??88 <>
    ends
    XpfBusCheck QWORD ?
  WHEA_XPF_BUS_CHECK ends

  PWHEA_XPF_BUS_CHECK typedef ptr WHEA_XPF_BUS_CHECK
  
  XPF_MS_CHECK_ERRORTYPE_NOERROR equ 0
  XPF_MS_CHECK_ERRORTYPE_UNCLASSIFIED equ 1
  XPF_MS_CHECK_ERRORTYPE_MCROMPARITY equ 2
  XPF_MS_CHECK_ERRORTYPE_EXTERNAL equ 3
  XPF_MS_CHECK_ERRORTYPE_FRC equ 4
  XPF_MS_CHECK_ERRORTYPE_INTERNALUNCLASSIFIED equ 5
  WHEA_XPF_MS_CHECK union
    struct DUMMYSTRUCTNAME_95
      DUMMYSTRUCTNAME_95_??89 record ErrorTypeValid_??89:1, ProcessorContextCorruptValid_??89:1, UncorrectedValid_??89:1, PreciseIPValid_??89:1, RestartableIPValid_??89:1, OverflowValid_??89:1, ReservedValue_??89:10, ErrorType_??89:3, ProcessorContextCorrupt_??89:1, Uncorrected_??89:1, PreciseIP_??89:1, RestartableIP_??89:1, Overflow_??89:1, Reserved_??89:40
      DUMMYSTRUCTNAME_95_??89 <>
    ends
    XpfMsCheck QWORD ?
  WHEA_XPF_MS_CHECK ends

  PWHEA_XPF_MS_CHECK typedef ptr WHEA_XPF_MS_CHECK
  
  WHEA_XPF_PROCINFO_VALIDBITS union
    struct DUMMYSTRUCTNAME_96
      DUMMYSTRUCTNAME_96_??90 record CheckInfo_??90:1, TargetId_??90:1, RequesterId_??90:1, ResponderId_??90:1, InstructionPointer_??90:1, Reserved_??90:59
      DUMMYSTRUCTNAME_96_??90 <>
    ends
    ValidBits QWORD ?
  WHEA_XPF_PROCINFO_VALIDBITS ends

  PWHEA_XPF_PROCINFO_VALIDBITS typedef ptr WHEA_XPF_PROCINFO_VALIDBITS
  
  WHEA_XPF_PROCINFO struct
    CheckInfoId GUID <>
    ValidBits WHEA_XPF_PROCINFO_VALIDBITS <>
    union CheckInfo
      CacheCheck WHEA_XPF_CACHE_CHECK <>
      TlbCheck WHEA_XPF_TLB_CHECK <>
      BusCheck WHEA_XPF_BUS_CHECK <>
      MsCheck WHEA_XPF_MS_CHECK <>
      AsULONGLONG QWORD ?
    ends
    TargetId QWORD ?
    RequesterId QWORD ?
    ResponderId QWORD ?
    InstructionPointer QWORD ?
  WHEA_XPF_PROCINFO ends

  PWHEA_XPF_PROCINFO typedef ptr WHEA_XPF_PROCINFO
  
  WHEA_X86_REGISTER_STATE struct
    Eax_ DWORD ?
    Ebx_ DWORD ?
    Ecx_ DWORD ?
    Edx_ DWORD ?
    Esi_ DWORD ?
    Edi_ DWORD ?
    Ebp_ DWORD ?
    Esp_ DWORD ?
    Cs_ WORD ?
    Ds_ WORD ?
    Ss_ WORD ?
    Es_ WORD ?
    Fs_ WORD ?
    Gs_ WORD ?
    Eflags_ DWORD ?
    Eip_ DWORD ?
    Cr0_ DWORD ?
    Cr1 DWORD ?
    Cr2_ DWORD ?
    Cr3_ DWORD ?
    Cr4_ DWORD ?
    Gdtr_ QWORD ?
    Idtr_ QWORD ?
    Ldtr_ WORD ?
    Tr WORD ?
  WHEA_X86_REGISTER_STATE ends

  PWHEA_X86_REGISTER_STATE typedef ptr WHEA_X86_REGISTER_STATE

WHEA128A STRUCT
  qwLow ULONGLONG ?
  qwHigh LONGLONG ?
WHEA128A ENDS
PWHEA128A TYPEDEF PTR WHEA128A

  WHEA_X64_REGISTER_STATE struct
    Rax_ QWORD ?
    Rbx_ QWORD ?
    Rcx_ QWORD ?
    Rdx_ QWORD ?
    Rsi_ QWORD ?
    Rdi_ QWORD ?
    Rbp_ QWORD ?
    Rsp_ QWORD ?
    R8_ QWORD ?
    R9_ QWORD ?
    R10_ QWORD ?
    R11_ QWORD ?
    R12_ QWORD ?
    R13_ QWORD ?
    R14_ QWORD ?
    R15_ QWORD ?
    Cs_ WORD ?
    Ds_ WORD ?
    Ss_ WORD ?
    Es_ WORD ?
    Fs_ WORD ?
    Gs_ WORD ?
    Reserved DWORD ?
    Rflags_ QWORD ?
    Eip_ QWORD ?
    Cr0_ QWORD ?
    Cr1 QWORD ?
    Cr2_ QWORD ?
    Cr3_ QWORD ?
    Cr4_ QWORD ?
    Cr8_ QWORD ?
    Gdtr_ WHEA128A <>
    Idtr_ WHEA128A <>
    Ldtr_ WORD ?
    Tr WORD ?
  WHEA_X64_REGISTER_STATE ends

  PWHEA_X64_REGISTER_STATE typedef ptr WHEA_X64_REGISTER_STATE

  XPF_CONTEXT_INFO_UNCLASSIFIEDDATA equ 0
  XPF_CONTEXT_INFO_MSRREGISTERS equ 1
  XPF_CONTEXT_INFO_32BITCONTEXT equ 2
  XPF_CONTEXT_INFO_64BITCONTEXT equ 3
  XPF_CONTEXT_INFO_FXSAVE equ 4
  XPF_CONTEXT_INFO_32BITDEBUGREGS equ 5
  XPF_CONTEXT_INFO_64BITDEBUGREGS equ 6
  XPF_CONTEXT_INFO_MMREGISTERS equ 7
  WHEA_XPF_CONTEXT_INFO struct
    RegisterContextType WORD ?
    RegisterDataSize WORD ?
    MSRAddress DWORD ?
    MmRegisterAddress QWORD ?
  WHEA_XPF_CONTEXT_INFO ends

  PWHEA_XPF_CONTEXT_INFO typedef ptr WHEA_XPF_CONTEXT_INFO
  
  WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS union
    struct DUMMYSTRUCTNAME_97
      DUMMYSTRUCTNAME_97_??91 record LocalAPICId_??91:1, CpuId_??91:1, ProcInfoCount_??91:6, ContextInfoCount_??91:6, Reserved_??91:50
      DUMMYSTRUCTNAME_97_??91 <>
    ends
    ValidBits QWORD ?
  WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS ends

  PWHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS typedef ptr WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS
  
  WHEA_XPF_PROCESSOR_ERROR_SECTION struct
    ValidBits WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS <>
    LocalAPICId QWORD ?
    CpuId_ BYTE 48 dup (?)
    VariableInfo BYTE ANYSIZE_ARRAY dup (?)
  WHEA_XPF_PROCESSOR_ERROR_SECTION ends

  PWHEA_XPF_PROCESSOR_ERROR_SECTION typedef ptr WHEA_XPF_PROCESSOR_ERROR_SECTION
  

    WHEA_XPF_PROCESSOR_ERROR_VALIDBITS typedef WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS
    PWHEA_XPF_PROCESSOR_ERROR_VALIDBITS typedef ptr WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS
    
    WHEA_XPF_PROCESSOR_ERROR typedef WHEA_XPF_PROCESSOR_ERROR_SECTION
    PWHEA_XPF_PROCESSOR_ERROR typedef ptr WHEA_XPF_PROCESSOR_ERROR_SECTION


  WHEA_MEMORY_ERROR_SECTION_VALIDBITS union
    struct DUMMYSTRUCTNAME_98
      DUMMYSTRUCTNAME_98_??92 record ErrorStatus_??92:1, PhysicalAddress_??92:1, PhysicalAddressMask_??92:1, Node_??92:1, Card_??92:1, Module_??92:1, Bank_??92:1, Device_??92:1, Row_??92:1, Column_??92:1, BitPosition_??92:1, RequesterId_??92:1, ResponderId_??92:1, TargetId_??92:1, ErrorType_??92:1, RankNumber_??92:1, CardHandle_??92:1, ModuleHandle_??92:1, ExtendedRow_??92:1, BankGroup_??92:1, BankAddress_??92:1, ChipIdentification_??92:1, Reserved_??92:42
      DUMMYSTRUCTNAME_98_??92 <>
    ends
    ValidBits QWORD ?
  WHEA_MEMORY_ERROR_SECTION_VALIDBITS ends

  PWHEA_MEMORY_ERROR_SECTION_VALIDBITS typedef ptr WHEA_MEMORY_ERROR_SECTION_VALIDBITS
  
  WHEA_MEMERRTYPE_UNKNOWN equ 00h
  WHEA_MEMERRTYPE_NOERROR equ 01h
  WHEA_MEMERRTYPE_SINGLEBITECC equ 02h
  WHEA_MEMERRTYPE_MULTIBITECC equ 03h
  WHEA_MEMERRTYPE_SINGLESYMCHIPKILL equ 04h
  WHEA_MEMERRTYPE_MULTISYMCHIPKILL equ 05h
  WHEA_MEMERRTYPE_MASTERABORT equ 06h
  WHEA_MEMERRTYPE_TARGETABORT equ 07h
  WHEA_MEMERRTYPE_PARITYERROR equ 08h
  WHEA_MEMERRTYPE_WATCHDOGTIMEOUT equ 09h
  WHEA_MEMERRTYPE_INVALIDADDRESS equ 0Ah
  WHEA_MEMERRTYPE_MIRRORBROKEN equ 0Bh
  WHEA_MEMERRTYPE_MEMORYSPARING equ 0Ch
  WHEA_MEMORY_ERROR_SECTION struct
    ValidBits WHEA_MEMORY_ERROR_SECTION_VALIDBITS <>
    ErrorStatus WHEA_ERROR_STATUS <>
    PhysicalAddress QWORD ?
    PhysicalAddressMask QWORD ?
    Node WORD ?
    Card WORD ?
    Module WORD ?
    Bank WORD ?
    Device WORD ?
    Row WORD ?
    Column WORD ?
    BitPosition WORD ?
    RequesterId QWORD ?
    ResponderId QWORD ?
    TargetId QWORD ?
    ErrorType BYTE ?
    Extended BYTE ?
    RankNumber WORD ?
    CardHandle WORD ?
    ModuleHandle WORD ?
  WHEA_MEMORY_ERROR_SECTION ends

  PWHEA_MEMORY_ERROR_SECTION typedef ptr WHEA_MEMORY_ERROR_SECTION
  

    WHEA_MEMORY_ERROR_VALIDBITS typedef WHEA_MEMORY_ERROR_SECTION_VALIDBITS
    PWHEA_MEMORY_ERROR_VALIDBITS typedef ptr WHEA_MEMORY_ERROR_SECTION_VALIDBITS
    WHEA_MEMORY_ERROR typedef WHEA_MEMORY_ERROR_SECTION
    PWHEA_MEMORY_ERROR typedef ptr WHEA_MEMORY_ERROR_SECTION


  WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS union
    struct DUMMYSTRUCTNAME_99
      DUMMYSTRUCTNAME_99_??93 record PortType_??93:1, Version_??93:1, CommandStatus_??93:1, DeviceId_??93:1, DeviceSerialNumber_??93:1, BridgeControlStatus_??93:1, ExpressCapability_??93:1, AerInfo_??93:1, Reserved_??93:56
      DUMMYSTRUCTNAME_99_??93 <>
    ends
    ValidBits QWORD ?
  WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS ends

  PWHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS typedef ptr WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS
  
  WHEA_PCIEXPRESS_DEVICE_ID struct
    VendorID WORD ?
    DeviceID WORD ?
    WHEA_PCIEXPRESS_DEVICE_ID_??94 record ClassCode_??94:24, FunctionNumber_??94:8, DeviceNumber_??94:8, Segment_??94:16, PrimaryBusNumber_??94:8, SecondaryBusNumber_??94:8, Reserved1_??94:3, SlotNumber_??94:13, Reserved2_??94:8
    WHEA_PCIEXPRESS_DEVICE_ID_??94 <>
  WHEA_PCIEXPRESS_DEVICE_ID ends

  PWHEA_PCIEXPRESS_DEVICE_ID typedef ptr WHEA_PCIEXPRESS_DEVICE_ID
  
  WHEA_PCIEXPRESS_VERSION union
    struct DUMMYSTRUCTNAME_100
      MinorVersion BYTE ?
      MajorVersion BYTE ?
      Reserved WORD ?
    ends
    AsULONG DWORD ?
  WHEA_PCIEXPRESS_VERSION ends

  PWHEA_PCIEXPRESS_VERSION typedef ptr WHEA_PCIEXPRESS_VERSION
  
  WHEA_PCIEXPRESS_COMMAND_STATUS union
    struct DUMMYSTRUCTNAME_101
      Command WORD ?
      Status WORD ?
    ends
    AsULONG DWORD ?
  WHEA_PCIEXPRESS_COMMAND_STATUS ends

  PWHEA_PCIEXPRESS_COMMAND_STATUS typedef ptr WHEA_PCIEXPRESS_COMMAND_STATUS
  
  WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS union
    struct DUMMYSTRUCTNAME_102
      BridgeSecondaryStatus WORD ?
      BridgeControl WORD ?
    ends
    AsULONG DWORD ?
  WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS ends

  PWHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS typedef ptr WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS
  
  WHEA_PCIEXPRESS_DEVICE_TYPE typedef SDWORD
  WheaPciExpressEndpoint EQU 0 
  WheaPciExpressLegacyEndpoint EQU 1
  WheaPciExpressRootPort EQU 4 
  WheaPciExpressUpstreamSwitchPort EQU 5
  WheaPciExpressDownstreamSwitchPort EQU 6
  WheaPciExpressToPciXBridge EQU 7
  WheaPciXToExpressBridge EQU 8
  WheaPciExpressRootComplexIntegratedEndpoint EQU 9
  WheaPciExpressRootComplexEventCollector EQU 10
  
  WHEA_PCIEXPRESS_ERROR_SECTION struct
    ValidBits WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS <>
    PortType WHEA_PCIEXPRESS_DEVICE_TYPE ?
    Version WHEA_PCIEXPRESS_VERSION <>
    CommandStatus WHEA_PCIEXPRESS_COMMAND_STATUS <>
    Reserved DWORD ?
    DeviceId WHEA_PCIEXPRESS_DEVICE_ID <>
    DeviceSerialNumber QWORD ?
    BridgeControlStatus WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS <>
    ExpressCapability BYTE 60 dup (?)
    AerInfo BYTE 96 dup (?)
  WHEA_PCIEXPRESS_ERROR_SECTION ends

  PWHEA_PCIEXPRESS_ERROR_SECTION typedef ptr WHEA_PCIEXPRESS_ERROR_SECTION
  

    WHEA_PCIEXPRESS_ERROR_VALIDBITS typedef WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS
    PWHEA_PCIEXPRESS_ERROR_VALIDBITS typedef ptr WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS
    WHEA_PCIEXPRESS_ERROR typedef WHEA_PCIEXPRESS_ERROR_SECTION
    PWHEA_PCIEXPRESS_ERROR typedef ptr WHEA_PCIEXPRESS_ERROR_SECTION


  PCIXBUS_ERRTYPE_UNKNOWN equ 0000h
  PCIXBUS_ERRTYPE_DATAPARITY equ 0001h
  PCIXBUS_ERRTYPE_SYSTEM equ 0002h
  PCIXBUS_ERRTYPE_MASTERABORT equ 0003h
  PCIXBUS_ERRTYPE_BUSTIMEOUT equ 0004h
  PCIXBUS_ERRTYPE_MASTERDATAPARITY equ 0005h
  PCIXBUS_ERRTYPE_ADDRESSPARITY equ 0006h
  PCIXBUS_ERRTYPE_COMMANDPARITY equ 0007h
  WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS union
    struct DUMMYSTRUCTNAME_103
      DUMMYSTRUCTNAME_103_??95 record ErrorStatus_??95:1, ErrorType_??95:1, BusId_??95:1, BusAddress_??95:1, BusData_??95:1, BusCommand_??95:1, RequesterId_??95:1, CompleterId_??95:1, TargetId_??95:1, Reserved_??95:55
      DUMMYSTRUCTNAME_103_??95 <>
    ends
    ValidBits QWORD ?
  WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS ends

  PWHEA_PCIXBUS_ERROR_SECTION_VALIDBITS typedef ptr WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS
  
  WHEA_PCIXBUS_ID union
    struct DUMMYSTRUCTNAME_104
      BusNumber BYTE ?
      BusSegment BYTE ?
    ends
    AsUSHORT WORD ?
  WHEA_PCIXBUS_ID ends

  PWHEA_PCIXBUS_ID typedef ptr WHEA_PCIXBUS_ID
  
  WHEA_PCIXBUS_COMMAND union
    struct DUMMYSTRUCTNAME_105
      DUMMYSTRUCTNAME_105_??96 record Command_??96:56, PCIXCommand_??96:1, Reserved_??96:7
      DUMMYSTRUCTNAME_105_??96 <>
    ends
    AsULONGLONG QWORD ?
  WHEA_PCIXBUS_COMMAND ends

  PWHEA_PCIXBUS_COMMAND typedef ptr WHEA_PCIXBUS_COMMAND
  
  WHEA_PCIXBUS_ERROR_SECTION struct
    ValidBits WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS <>
    ErrorStatus WHEA_ERROR_STATUS <>
    ErrorType WORD ?
    BusId WHEA_PCIXBUS_ID <>
    Reserved DWORD ?
    BusAddress QWORD ?
    BusData QWORD ?
    BusCommand WHEA_PCIXBUS_COMMAND <>
    RequesterId QWORD ?
    CompleterId QWORD ?
    TargetId QWORD ?
  WHEA_PCIXBUS_ERROR_SECTION ends

  PWHEA_PCIXBUS_ERROR_SECTION typedef ptr WHEA_PCIXBUS_ERROR_SECTION
  

    WHEA_PCIXBUS_ERROR_VALIDBITS typedef WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS
    PWHEA_PCIXBUS_ERROR_VALIDBITS typedef ptr WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS
    WHEA_PCIXBUS_ERROR typedef WHEA_PCIXBUS_ERROR_SECTION
    PWHEA_PCIXBUS_ERROR typedef ptr WHEA_PCIXBUS_ERROR_SECTION


  WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS union
    struct DUMMYSTRUCTNAME_106
      DUMMYSTRUCTNAME_106_??97 record ErrorStatus_??97:1, IdInfo_??97:1, MemoryNumber_??97:1, IoNumber_??97:1, RegisterDataPairs_??97:1, Reserved_??97:59
      DUMMYSTRUCTNAME_106_??97 <>
    ends
    ValidBits QWORD ?
  WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS ends

  PWHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS typedef ptr WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS
  
  WHEA_PCIXDEVICE_ID struct
    VendorId WORD ?
    DeviceId WORD ?
    WHEA_PCIXDEVICE_ID_??98 record ClassCode_??98:24, FunctionNumber_??98:8, DeviceNumber_??98:8, BusNumber_??98:8, SegmentNumber_??98:8, Reserved1_??98:8
    WHEA_PCIXDEVICE_ID_??98 <>
    Reserved2 DWORD ?
  WHEA_PCIXDEVICE_ID ends

  PWHEA_PCIXDEVICE_ID typedef ptr WHEA_PCIXDEVICE_ID
  
  WHEA_PCIXDEVICE_REGISTER_PAIR struct
    Register QWORD ?
    Data QWORD ?
  WHEA_PCIXDEVICE_REGISTER_PAIR ends

  PWHEA_PCIXDEVICE_REGISTER_PAIR typedef ptr WHEA_PCIXDEVICE_REGISTER_PAIR
  
  WHEA_PCIXDEVICE_ERROR_SECTION struct
    ValidBits WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS <>
    ErrorStatus WHEA_ERROR_STATUS <>
    IdInfo WHEA_PCIXDEVICE_ID <>
    MemoryNumber DWORD ?
    IoNumber DWORD ?
    RegisterDataPairs WHEA_PCIXDEVICE_REGISTER_PAIR ANYSIZE_ARRAY dup (<>)
  WHEA_PCIXDEVICE_ERROR_SECTION ends

  PWHEA_PCIXDEVICE_ERROR_SECTION typedef ptr WHEA_PCIXDEVICE_ERROR_SECTION

    WHEA_PCIXDEVICE_ERROR_VALIDBITS typedef WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS
    PWHEA_PCIXDEVICE_ERROR_VALIDBITS typedef ptr WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS
    WHEA_PCIXDEVICE_ERROR typedef WHEA_PCIXDEVICE_ERROR_SECTION
    PWHEA_PCIXDEVICE_ERROR typedef ptr WHEA_PCIXDEVICE_ERROR_SECTION


  WHEA_FIRMWARE_RECORD_TYPE_IPFSAL equ 0
  WHEA_FIRMWARE_ERROR_RECORD_REFERENCE struct
    Type_ BYTE ?
    Reserved BYTE 7 dup (?)
    FirmwareRecordId QWORD ?
  WHEA_FIRMWARE_ERROR_RECORD_REFERENCE ends

  PWHEA_FIRMWARE_ERROR_RECORD_REFERENCE typedef ptr WHEA_FIRMWARE_ERROR_RECORD_REFERENCE
  

    WHEA_FIRMWARE_RECORD typedef WHEA_FIRMWARE_ERROR_RECORD_REFERENCE
    PWHEA_FIRMWARE_RECORD typedef ptr WHEA_FIRMWARE_ERROR_RECORD_REFERENCE


  MCG_STATUS union
    struct DUMMYSTRUCTNAME_107
      DUMMYSTRUCTNAME_107_??99 record RestartIpValid_??99:1, ErrorIpValid_??99:1, MachineCheckInProgress_??99:1, Reserved1_??99:29
      DUMMYSTRUCTNAME_107_??99 <>
      Reserved2 DWORD ?
    ends
    QuadPart QWORD ?
  MCG_STATUS ends

  PMCG_STATUS typedef ptr MCG_STATUS
  
  MCI_STATUS union
    struct DUMMYSTRUCTNAME_108
      McaErrorCode WORD ?
      ModelErrorCode WORD ?
      DUMMYSTRUCTNAME_108_??100 record OtherInformation_??100:23, ActionRequired_??100:1, Signalling_??100:1, ContextCorrupt_??100:1, AddressValid_??100:1, MiscValid_??100:1, ErrorEnabled_??100:1, UncorrectedError_??100:1, StatusOverFlow_??100:1, Valid_??100:1
      DUMMYSTRUCTNAME_108_??100 <>
    ends
    QuadPart ULONG64 ?
  MCI_STATUS ends

  PMCI_STATUS typedef ptr MCI_STATUS
  
  WHEA_CPU_VENDOR typedef SDWORD
  WheaCpuVendorOther EQU 0 
  WheaCpuVendorIntel EQU 1
  WheaCpuVendorAmd EQU 2
  
  PWHEA_CPU_VENDOR typedef ptr WHEA_CPU_VENDOR
  
  WHEA_XPF_MCA_EXTREG_MAX_COUNT equ 24
  WHEA_XPF_MCA_SECTION_VERSION_2 equ 2
  WHEA_XPF_MCA_SECTION_VERSION equ <WHEA_XPF_MCA_SECTION_VERSION_2>
  WHEA_XPF_MCA_SECTION struct
    VersionNumber DWORD ?
    CpuVendor WHEA_CPU_VENDOR ?
    Timestamp LARGE_INTEGER <>
    ProcessorNumber DWORD ?
    GlobalStatus MCG_STATUS <>
    InstructionPointer QWORD ?
    BankNumber DWORD ?
    Status MCI_STATUS <>
    Address QWORD ?
    Misc QWORD ?
    ExtendedRegisterCount DWORD ?
    ApicId DWORD ?
    ExtendedRegisters QWORD WHEA_XPF_MCA_EXTREG_MAX_COUNT dup (?)
  WHEA_XPF_MCA_SECTION ends

  PWHEA_XPF_MCA_SECTION typedef ptr WHEA_XPF_MCA_SECTION
  
  WHEA_NMI_ERROR_SECTION_FLAGS union
    struct DUMMYSTRUCTNAME_109
      DUMMYSTRUCTNAME_109_??101 record HypervisorError_??101:1, Reserved_??101:31
      DUMMYSTRUCTNAME_109_??101 <>
    ends
    AsULONG DWORD ?
  WHEA_NMI_ERROR_SECTION_FLAGS ends

  PWHEA_NMI_ERROR_SECTION_FLAGS typedef ptr WHEA_NMI_ERROR_SECTION_FLAGS
  
  WHEA_NMI_ERROR_SECTION struct
    Data BYTE 8 dup (?)
    Flags WHEA_NMI_ERROR_SECTION_FLAGS <>
  WHEA_NMI_ERROR_SECTION ends

  PWHEA_NMI_ERROR_SECTION typedef ptr WHEA_NMI_ERROR_SECTION
  
  WHEA_ARM_PROCESSOR_ERROR_SECTION_VALID_BITS union
    struct DUMMYSTRUCTNAME_110
      DUMMYSTRUCTNAME_110_??102 record MPIDR_??102:1, AffinityLevel_??102:1, RunningState_??102:1, VendorSpecificInfo_??102:1, Reserved_??102:28
      DUMMYSTRUCTNAME_110_??102 <>
    ends
    AsULONG DWORD ?
  WHEA_ARM_PROCESSOR_ERROR_SECTION_VALID_BITS ends

  PWHEA_ARM_PROCESSOR_ERROR_SECTION_VALID_BITS typedef ptr WHEA_ARM_PROCESSOR_ERROR_SECTION_VALID_BITS
  
  WHEA_ARM_PROCESSOR_ERROR_SECTION struct
    ValidBits WHEA_ARM_PROCESSOR_ERROR_SECTION_VALID_BITS <>
    ErrorInformationStructures WORD ?
    ContextInformationStructures WORD ?
    SectionLength DWORD ?
    ErrorAffinityLevel BYTE ?
    Reserved BYTE 3 dup (?)
    MPIDR_EL1 QWORD ?
    MIDR_EL1 QWORD ?
    RunningState DWORD ?
    PSCIState DWORD ?
    Data BYTE 1 dup (?)
  WHEA_ARM_PROCESSOR_ERROR_SECTION ends

  PWHEA_ARM_PROCESSOR_ERROR_SECTION typedef ptr WHEA_ARM_PROCESSOR_ERROR_SECTION
  

  WHEA_ARM_PROCESSOR_ERROR_INFORMATION_VALID_BITS union
    struct DUMMYSTRUCTNAME_111
      DUMMYSTRUCTNAME_111_??103 record MultipleError_??103:1, Flags_??103:1, ErrorInformation_??103:1, VirtualFaultAddress_??103:1, PhysicalFaultAddress_??103:1, Reserved_??103:11
      DUMMYSTRUCTNAME_111_??103 <>
    ends
    AsUSHORT WORD ?
  WHEA_ARM_PROCESSOR_ERROR_INFORMATION_VALID_BITS ends

  PWHEA_ARM_PROCESSOR_ERROR_INFORMATION_VALID_BITS typedef ptr WHEA_ARM_PROCESSOR_ERROR_INFORMATION_VALID_BITS
  
  WHEA_ARM_CACHE_ERROR_VALID_BITS union
    struct DUMMYSTRUCTNAME_112
      DUMMYSTRUCTNAME_112_??104 record TransactionType_??104:1, Operation_??104:1, Level_??104:1, ProcessorContextCorrupt_??104:1, Corrected_??104:1, PrecisePC_??104:1, RestartablePC_??104:1, Reserved_??104:9
      DUMMYSTRUCTNAME_112_??104 <>
    ends
    AsUSHORT WORD ?
  WHEA_ARM_CACHE_ERROR_VALID_BITS ends

  PWHEA_ARM_CACHE_ERROR_VALID_BITS typedef ptr WHEA_ARM_CACHE_ERROR_VALID_BITS
  
  WHEA_ARM_CACHE_ERROR struct
    ValidationBit WHEA_ARM_CACHE_ERROR_VALID_BITS <>
    WHEA_ARM_CACHE_ERROR_??105 record TransactionType_??105:2, Operation_??105:4, Level_??105:3, ProcessorContextCorrupt_??105:1, Corrected_??105:1, PrecisePC_??105:1, RestartablePC_??105:1, Reserved_??105:35
    WHEA_ARM_CACHE_ERROR_??105 <>
  WHEA_ARM_CACHE_ERROR ends

  PWHEA_ARM_CACHE_ERROR typedef ptr WHEA_ARM_CACHE_ERROR
  
  WHEA_ARM_TLB_ERROR_VALID_BITS union
    struct DUMMYSTRUCTNAME_113
      DUMMYSTRUCTNAME_113_??106 record TransactionType_??106:1, Operation_??106:1, Level_??106:1, ProcessorContextCorrupt_??106:1, Corrected_??106:1, PrecisePC_??106:1, RestartablePC_??106:1, Reserved_??106:9
      DUMMYSTRUCTNAME_113_??106 <>
    ends
    AsUSHORT WORD ?
  WHEA_ARM_TLB_ERROR_VALID_BITS ends

  PWHEA_ARM_TLB_ERROR_VALID_BITS typedef ptr WHEA_ARM_TLB_ERROR_VALID_BITS
  
  WHEA_ARM_TLB_ERROR struct
    ValidationBit WHEA_ARM_TLB_ERROR_VALID_BITS <>
    WHEA_ARM_TLB_ERROR_??107 record TransactionType_??107:2, Operation_??107:4, Level_??107:3, ProcessorContextCorrupt_??107:1, Corrected_??107:1, PrecisePC_??107:1, RestartablePC_??107:1, Reserved_??107:36
    WHEA_ARM_TLB_ERROR_??107 <>
  WHEA_ARM_TLB_ERROR ends

  PWHEA_ARM_TLB_ERROR typedef ptr WHEA_ARM_TLB_ERROR
  
  WHEA_ARM_BUS_ERROR_VALID_BITS union
    struct DUMMYSTRUCTNAME_114
      DUMMYSTRUCTNAME_114_??108 record TransactionType_??108:1, Operation_??108:1, Level_??108:1, ProcessorContextCorrupt_??108:1, Corrected_??108:1, PrecisePC_??108:1, RestartablePC_??108:1, ParticipationType_??108:1, Timeout_??108:1, AddressSpace_??108:1, MemoryAttributes_??108:1, AccessMode_??108:1, Reserved_??108:4
      DUMMYSTRUCTNAME_114_??108 <>
    ends
    AsUSHORT WORD ?
  WHEA_ARM_BUS_ERROR_VALID_BITS ends

  PWHEA_ARM_BUS_ERROR_VALID_BITS typedef ptr WHEA_ARM_BUS_ERROR_VALID_BITS
  
  WHEA_ARM_BUS_ERROR struct
    ValidationBit WHEA_ARM_BUS_ERROR_VALID_BITS <>
    WHEA_ARM_BUS_ERROR_??109 record TransactionType_??109:2, Operation_??109:4, Level_??109:3, ProcessorContextCorrupt_??109:1, Corrected_??109:1, PrecisePC_??109:1, RestartablePC_??109:1, ParticipationType_??109:2, TimeOut_??109:1, AddressSpace_??109:2, MemoryAccessAttributes_??109:9, AccessMode_??109:1, Reserved_??109:20
    WHEA_ARM_BUS_ERROR_??109 <>
  WHEA_ARM_BUS_ERROR ends

  PWHEA_ARM_BUS_ERROR typedef ptr WHEA_ARM_BUS_ERROR
  
  WHEA_ARM_PROCESSOR_ERROR union
    CacheError WHEA_ARM_CACHE_ERROR <>
    TlbError WHEA_ARM_TLB_ERROR <>
    BusError WHEA_ARM_BUS_ERROR <>
    AsULONGLONG QWORD ?
  WHEA_ARM_PROCESSOR_ERROR ends

  PWHEA_ARM_PROCESSOR_ERROR typedef ptr WHEA_ARM_PROCESSOR_ERROR
  
  WHEA_ARM_PROCESSOR_ERROR_INFORMATION struct
    Version BYTE ?
    Length_ BYTE ?
    ValidationBit WHEA_ARM_PROCESSOR_ERROR_INFORMATION_VALID_BITS <>
    Type_ BYTE ?
    MultipleError WORD ?
    Flags BYTE ?
    ErrorInformation QWORD ?
    VirtualFaultAddress QWORD ?
    PhysicalFaultAddress QWORD ?
  WHEA_ARM_PROCESSOR_ERROR_INFORMATION ends

  PWHEA_ARM_PROCESSOR_ERROR_INFORMATION typedef ptr WHEA_ARM_PROCESSOR_ERROR_INFORMATION
  

  WHEA_ARM_PROCESSOR_ERROR_CONTEXT_INFORMATION_HEADER_FLAGS union
    struct DUMMYSTRUCTNAME_115
      DUMMYSTRUCTNAME_115_??110 record ExceptionLevel_??110:1, NonSecure_??110:1, AArch64_??110:1, Reserved_??110:29
      DUMMYSTRUCTNAME_115_??110 <>
    ends
    AsULONG DWORD ?
  WHEA_ARM_PROCESSOR_ERROR_CONTEXT_INFORMATION_HEADER_FLAGS ends

  PWHEA_ARM_PROCESSOR_ERROR_CONTEXT_INFORMATION_HEADER_FLAGS typedef ptr WHEA_ARM_PROCESSOR_ERROR_CONTEXT_INFORMATION_HEADER_FLAGS
  
  WHEA_ARMV8_AARCH32_GPRS struct
    R0_ DWORD ?
    R1_ DWORD ?
    R2_ DWORD ?
    R3_ DWORD ?
    R4_ DWORD ?
    R5_ DWORD ?
    R6_ DWORD ?
    R7_ DWORD ?
    R8_ DWORD ?
    R9_ DWORD ?
    R10_ DWORD ?
    R11_ DWORD ?
    R12_ DWORD ?
    R13_ DWORD ?
    R14_ DWORD ?
    R15_ DWORD ?
  WHEA_ARMV8_AARCH32_GPRS ends

  PWHEA_ARMV8_AARCH32_GPRS typedef ptr WHEA_ARMV8_AARCH32_GPRS
  
  WHEA_ARM_AARCH32_EL1_CSR struct
    DFAR DWORD ?
    DFSR DWORD ?
    IFAR DWORD ?
    ISR DWORD ?
    MAIR0 DWORD ?
    MAIR1 DWORD ?
    MIDR DWORD ?
    MPIDR DWORD ?
    NMRR DWORD ?
    PRRR DWORD ?
    SCTLR DWORD ?
    SPSR DWORD ?
    SPSR_abt DWORD ?
    SPSR_fiq DWORD ?
    SPSR_irq DWORD ?
    SPSR_svc DWORD ?
    SPSR_und DWORD ?
    TPIDRPRW DWORD ?
    TPIDRURO DWORD ?
    TPIDRURW DWORD ?
    TTBCR DWORD ?
    TTBR0 DWORD ?
    TTBR1 DWORD ?
    DACR DWORD ?
  WHEA_ARM_AARCH32_EL1_CSR ends

  PWHEA_ARM_AARCH32_EL1 typedef ptr WHEA_ARM_AARCH32_EL1_CSR
  
  WHEA_ARM_AARCH32_EL2_CSR struct
    ELR_hyp DWORD ?
    HAMAIR0 DWORD ?
    HAMAIR1 DWORD ?
    HCR DWORD ?
    HCR2 DWORD ?
    HDFAR DWORD ?
    HIFAR DWORD ?
    HPFAR DWORD ?
    HSR DWORD ?
    HTCR DWORD ?
    HTPIDR DWORD ?
    HTTBR DWORD ?
    SPSR_hyp DWORD ?
    VTCR DWORD ?
    VTTBR DWORD ?
    DACR32_EL2 DWORD ?
  WHEA_ARM_AARCH32_EL2_CSR ends

  PWHEA_ARM_AARCH32_EL2_CSR typedef ptr WHEA_ARM_AARCH32_EL2_CSR
  
  WHEA_ARM_AARCH32_SECURE_CSR struct
    SCTLR DWORD ?
    SPSR_mon DWORD ?
  WHEA_ARM_AARCH32_SECURE_CSR ends

  PWHEA_ARM_AARCH32_SECURE_CSR typedef ptr WHEA_ARM_AARCH32_SECURE_CSR
  
  WHEA_ARMV8_AARCH64_GPRS struct
    X0 QWORD ?
    X1 QWORD ?
    X2 QWORD ?
    X3 QWORD ?
    X4 QWORD ?
    X5 QWORD ?
    X6 QWORD ?
    X7 QWORD ?
    X8 QWORD ?
    X9 QWORD ?
    X10 QWORD ?
    X11 QWORD ?
    X12 QWORD ?
    X13 QWORD ?
    X14 QWORD ?
    X15 QWORD ?
    X16 QWORD ?
    X17 QWORD ?
    X18 QWORD ?
    X19 QWORD ?
    X20 QWORD ?
    X21 QWORD ?
    X22 QWORD ?
    X23 QWORD ?
    X24 QWORD ?
    X25 QWORD ?
    X26 QWORD ?
    X27 QWORD ?
    X28 QWORD ?
    X29 QWORD ?
    X30 QWORD ?
    SP_ QWORD ?
  WHEA_ARMV8_AARCH64_GPRS ends

  PWHEA_ARMV8_AARCH64_GPRS typedef ptr WHEA_ARMV8_AARCH64_GPRS
  
  WHEA_ARM_AARCH64_EL1_CSR struct
    ELR_EL1 QWORD ?
    ESR_EL2 QWORD ?
    FAR_EL1 QWORD ?
    ISR_EL1 QWORD ?
    MAIR_EL1 QWORD ?
    MIDR_EL1 QWORD ?
    MPIDR_EL1 QWORD ?
    SCTLR_EL1 QWORD ?
    SP_EL0 QWORD ?
    SP_EL1 QWORD ?
    SPSR_EL1 QWORD ?
    TCR_EL1 QWORD ?
    TPIDR_EL0 QWORD ?
    TPIDR_EL1 QWORD ?
    TPIDRRO_EL0 QWORD ?
    TTBR0_EL1 QWORD ?
    TTBR1_EL1 QWORD ?
  WHEA_ARM_AARCH64_EL1_CSR ends

  PWHEA_ARM_AARCH64_EL1_CSR typedef ptr WHEA_ARM_AARCH64_EL1_CSR
  
  WHEA_ARM_AARCH64_EL2_CSR struct
    ELR_EL2 QWORD ?
    ESR_EL2 QWORD ?
    FAR_EL2 QWORD ?
    HACR_EL2 QWORD ?
    HCR_EL2 QWORD ?
    HPFAR_EL2 QWORD ?
    MAIR_EL2 QWORD ?
    SCTLR_EL2 QWORD ?
    SP_EL2 QWORD ?
    SPSR_EL2 QWORD ?
    TCR_EL2 QWORD ?
    TPIDR_EL2 QWORD ?
    TTBR0_EL2 QWORD ?
    VTCR_EL2 QWORD ?
    VTTBR_EL2 QWORD ?
  WHEA_ARM_AARCH64_EL2_CSR ends

  PWHEA_ARM_AARCH64_EL2_CSR typedef ptr WHEA_ARM_AARCH64_EL2_CSR
  
  WHEA_ARMV8_AARCH64_EL3_CSR struct
    ELR_EL3 QWORD ?
    ESR_EL3 QWORD ?
    FAR_EL3 QWORD ?
    MAIR_EL3 QWORD ?
    SCTLR_EL3 QWORD ?
    SP_EL3 QWORD ?
    SPSR_EL3 QWORD ?
    TCR_EL3 QWORD ?
    TPIDR_EL3 QWORD ?
    TTBR0_EL3 QWORD ?
  WHEA_ARMV8_AARCH64_EL3_CSR ends

  PWHEA_ARMV8_AARCH64_EL3_CSR typedef ptr WHEA_ARMV8_AARCH64_EL3_CSR
  
  WHEA_ARM_MISC_CSR struct
    MRSEncoding WORD ?
    Value QWORD ?
  WHEA_ARM_MISC_CSR ends

  PWHEA_ARM_MISC_CSR typedef ptr WHEA_ARM_MISC_CSR
  
  WHEA_ARM_PROCESSOR_ERROR_CONTEXT_INFORMATION_HEADER struct
    Version WORD ?
    RegisterContextType WORD ?
    RegisterArraySize DWORD ?
    RegisterArray BYTE 1 dup (?)
  WHEA_ARM_PROCESSOR_ERROR_CONTEXT_INFORMATION_HEADER ends

  PWHEA_ARM_PROCESSOR_ERROR_CONTEXT_INFORMATION_HEADER typedef ptr WHEA_ARM_PROCESSOR_ERROR_CONTEXT_INFORMATION_HEADER
  


  DEFINE_GUID CMC_NOTIFY_TYPE_GUID, 2dce8bb1h, 0bdd7h, 450eh, 0b9h, 0adh, 9ch, 0f4h, 0ebh, 0d4h, 0f8h, 90h 
  DEFINE_GUID CPE_NOTIFY_TYPE_GUID, 4e292f96h, 0d843h, 4a55h, 0a8h, 0c2h, 0d4h, 81h, 0f2h, 7eh, 0beh, 0eeh 
  DEFINE_GUID MCE_NOTIFY_TYPE_GUID, 0e8f56ffeh, 919ch, 4cc5h, 0bah, 88h, 65h, 0abh, 0e1h, 49h, 13h, 0bbh 
  DEFINE_GUID PCIe_NOTIFY_TYPE_GUID, 0cf93c01fh, 1a16h, 4dfch, 0b8h, 0bch, 9ch, 4dh, 0afh, 67h, 0c1h, 04h 
  DEFINE_GUID INIT_NOTIFY_TYPE_GUID, 0cc5263e8h, 9308h, 454ah, 89h, 0d0h, 34h, 0bh, 0d3h, 9bh, 0c9h, 8eh 
  DEFINE_GUID NMI_NOTIFY_TYPE_GUID, 5bad89ffh, 0b7e6h, 42c9h, 81h, 4ah, 0cfh, 24h, 85h, 0d6h, 0e9h, 8ah 
  DEFINE_GUID BOOT_NOTIFY_TYPE_GUID, 3d61a466h, 0ab40h, 409ah, 0a6h, 98h, 0f3h, 62h, 0d4h, 64h, 0b3h, 8fh 
  DEFINE_GUID SEA_NOTIFY_TYPE_GUID, 9a78788ah, 0bbe8h, 11e4h, 80h, 9eh, 67h, 61h, 1eh, 5dh, 46h, 0b0h 
  DEFINE_GUID SEI_NOTIFY_TYPE_GUID, 5c284c81h, 0b0aeh, 4e87h, 0a3h, 22h, 0b0h, 4ch, 85h, 62h, 43h, 23h 
  DEFINE_GUID PEI_NOTIFY_TYPE_GUID, 09a9D5ach, 5204h, 4214h, 96h, 0e5h, 94h, 99h, 2eh, 75h, 2bh, 0cdh 
  DEFINE_GUID PROCESSOR_GENERIC_ERROR_SECTION_GUID, 9876ccadh, 47b4h, 4bdbh, 0b6h, 5eh, 16h, 0f1h, 93h, 0c4h, 0f3h, 0dbh 
  DEFINE_GUID XPF_PROCESSOR_ERROR_SECTION_GUID, 0dc3ea0b0h, 0a144h, 4797h, 0b9h, 5bh, 53h, 0fah, 24h, 2bh, 6eh, 1dh 
  DEFINE_GUID IPF_PROCESSOR_ERROR_SECTION_GUID, 0e429faf1h, 3cb7h, 11d4h, 0bch, 0a7h, 00h, 80h, 0c7h, 3ch, 88h, 81h 
  DEFINE_GUID ARM_PROCESSOR_ERROR_SECTION_GUID, 0e19e3d16h, 0bc11h, 11e4h, 9ch, 0aah, 0c2h, 05h, 1dh, 5dh, 46h, 0b0h 
  DEFINE_GUID MEMORY_ERROR_SECTION_GUID, 0a5bc1114h, 6f64h, 4edeh, 0b8h, 63h, 3eh, 83h, 0edh, 7ch, 83h, 0b1h 
  DEFINE_GUID PCIEXPRESS_ERROR_SECTION_GUID, 0d995e954h, 0bbc1h, 430fh, 0adh, 91h, 0b4h, 4dh, 0cbh, 3ch, 6fh, 35h 
  DEFINE_GUID PCIXBUS_ERROR_SECTION_GUID, 0c5753963h, 3b84h, 4095h, 0bfh, 78h, 0edh, 0dah, 0d3h, 0f9h, 0c9h, 0ddh 
  DEFINE_GUID PCIXDEVICE_ERROR_SECTION_GUID, 0eb5e4685h, 0ca66h, 4769h, 0b6h, 0a2h, 26h, 06h, 8bh, 00h, 13h, 26h 
  DEFINE_GUID FIRMWARE_ERROR_RECORD_REFERENCE_GUID, 81212a96h, 09edh, 4996h, 94h, 71h, 8dh, 72h, 9ch, 8eh, 69h, 0edh 
  DEFINE_GUID WHEA_CACHECHECK_GUID, 0a55701f5h, 0e3efh, 43deh, 0ach, 72h, 24h, 9bh, 57h, 3fh, 0adh, 2ch 
  DEFINE_GUID WHEA_TLBCHECK_GUID, 0fc06b535h, 5e1fh, 4562h, 9fh, 25h, 0ah, 3bh, 9ah, 0dbh, 63h, 0c3h 
  DEFINE_GUID WHEA_BUSCHECK_GUID, 1cf3f8b3h, 0c5b1h, 49a2h, 0aah, 59h, 5eh, 0efh, 92h, 0ffh, 0a6h, 3ch 
  DEFINE_GUID WHEA_MSCHECK_GUID, 48ab7f57h, 0dc34h, 4f6ch, 0a7h, 0d3h, 0b0h, 0b5h, 0b0h, 0a7h, 43h, 14h 
  DEFINE_GUID WHEA_RECORD_CREATOR_GUID, 0cf07c4bdh, 0b789h, 4e18h, 0b3h, 0c4h, 1fh, 73h, 2ch, 0b5h, 71h, 31h 
  DEFINE_GUID GENERIC_NOTIFY_TYPE_GUID, 3e62a467h, 0ab40h, 409ah, 0a6h, 98h, 0f3h, 62h, 0d4h, 64h, 0b3h, 8fh 
  DEFINE_GUID IPF_SAL_RECORD_SECTION_GUID, 6f3380d1h, 6eb0h, 497fh, 0a5h, 78h, 4dh, 4ch, 65h, 0a7h, 16h, 17h 
  DEFINE_GUID XPF_MCA_SECTION_GUID, 8a1e1d01h, 42f9h, 4557h, 9ch, 33h, 56h, 5eh, 5ch, 0c3h, 0f7h, 0e8h 
  DEFINE_GUID NMI_SECTION_GUID, 0e71254e7h, 0c1b9h, 4940h, 0abh, 76h, 90h, 97h, 03h, 0a4h, 32h, 0fh 
  DEFINE_GUID GENERIC_SECTION_GUID, 0e71254e8h, 0c1b9h, 4940h, 0abh, 76h, 90h, 97h, 03h, 0a4h, 32h, 0fh 
  DEFINE_GUID WHEA_ERROR_PACKET_SECTION_GUID, 0e71254e9h, 0c1b9h, 4940h, 0abh, 76h, 90h, 97h, 03h, 0a4h, 32h, 0fh 


  WHEA_ERROR_TYPE typedef SDWORD
  WheaErrTypeProcessor EQU 0 
  WheaErrTypeMemory EQU 1
  WheaErrTypePCIExpress EQU 2
  WheaErrTypeNMI EQU 3
  WheaErrTypePCIXBus EQU 4
  WheaErrTypePCIXDevice EQU 5
  WheaErrTypeGeneric EQU 6
  
  PWHEA_ERROR_TYPE typedef ptr WHEA_ERROR_TYPE
  
  WHEA_ERROR_PACKET_FLAGS union
    struct DUMMYSTRUCTNAME_116
      DUMMYSTRUCTNAME_116_??111 record PreviousError_??111:1, Reserved1_??111:1, HypervisorError_??111:1, Simulated_??111:1, PlatformPfaControl_??111:1, PlatformDirectedOffline_??111:1, Reserved2_??111:26
      DUMMYSTRUCTNAME_116_??111 <>
    ends
    AsULONG DWORD ?
  WHEA_ERROR_PACKET_FLAGS ends

  PWHEA_ERROR_PACKET_FLAGS typedef ptr WHEA_ERROR_PACKET_FLAGS
  
  WHEA_ERROR_PACKET_DATA_FORMAT typedef SDWORD
  WheaDataFormatIPFSalRecord EQU 0 
  WheaDataFormatXPFMCA EQU 1
  WheaDataFormatMemory EQU 2
  WheaDataFormatPCIExpress EQU 3
  WheaDataFormatNMIPort EQU 4
  WheaDataFormatPCIXBus EQU 5
  WheaDataFormatPCIXDevice EQU 6
  WheaDataFormatGeneric EQU 7
  WheaDataFormatMax EQU 8
  
  PWHEA_ERROR_PACKET_DATA_FORMAT typedef ptr WHEA_ERROR_PACKET_DATA_FORMAT
  
  WHEA_RAW_DATA_FORMAT typedef SDWORD
  WheaRawDataFormatIPFSalRecord EQU 00h 
  WheaRawDataFormatIA32MCA EQU 1
  WheaRawDataFormatIntel64MCA EQU 2
  WheaRawDataFormatAMD64MCA EQU 3
  WheaRawDataFormatMemory EQU 4
  WheaRawDataFormatPCIExpress EQU 5
  WheaRawDataFormatNMIPort EQU 6
  WheaRawDataFormatPCIXBus EQU 7
  WheaRawDataFormatPCIXDevice EQU 8
  WheaRawDataFormatGeneric EQU 9
  WheaRawDataFormatMax EQU 10
  
  PWHEA_RAW_DATA_FORMAT typedef ptr WHEA_RAW_DATA_FORMAT
  
  WHEA_ERROR_PACKET_V1 struct
    Signature DWORD ?
    Flags WHEA_ERROR_PACKET_FLAGS <>
    Size_ DWORD ?
    RawDataLength DWORD ?
    Reserved1 QWORD ?
    Context QWORD ?
    ErrorType WHEA_ERROR_TYPE ?
    ErrorSeverity WHEA_ERROR_SEVERITY ?
    ErrorSourceId DWORD ?
    ErrorSourceType WHEA_ERROR_SOURCE_TYPE ?
    Reserved2 DWORD ?
    Version DWORD ?
    Cpu QWORD ?
    union u
      ProcessorError WHEA_PROCESSOR_GENERIC_ERROR_SECTION <>
      MemoryError WHEA_MEMORY_ERROR_SECTION <>
      NmiError WHEA_NMI_ERROR_SECTION <>
      PciExpressError WHEA_PCIEXPRESS_ERROR_SECTION <>
      PciXBusError WHEA_PCIXBUS_ERROR_SECTION <>
      PciXDeviceError WHEA_PCIXDEVICE_ERROR_SECTION <>
    ends
    RawDataFormat WHEA_RAW_DATA_FORMAT ?
    RawDataOffset DWORD ?
    RawData BYTE 1 dup (?)
  WHEA_ERROR_PACKET_V1 ends

  PWHEA_ERROR_PACKET_V1 typedef ptr WHEA_ERROR_PACKET_V1
  
  WHEA_ERROR_PACKET_V1_SIGNATURE equ <'tPrE'>
  WHEA_ERROR_PACKET_V1_VERSION equ 2
  WHEA_ERROR_PACKET_V2 struct
    Signature DWORD ?
    Version DWORD ?
    Length_ DWORD ?
    Flags WHEA_ERROR_PACKET_FLAGS <>
    ErrorType WHEA_ERROR_TYPE ?
    ErrorSeverity WHEA_ERROR_SEVERITY ?
    ErrorSourceId DWORD ?
    ErrorSourceType WHEA_ERROR_SOURCE_TYPE ?
    NotifyType GUID <>
    Context QWORD ?
    DataFormat WHEA_ERROR_PACKET_DATA_FORMAT ?
    Reserved1 DWORD ?
    DataOffset DWORD ?
    DataLength DWORD ?
    PshedDataOffset DWORD ?
    PshedDataLength DWORD ?
  WHEA_ERROR_PACKET_V2 ends

  PWHEA_ERROR_PACKET_V2 typedef ptr WHEA_ERROR_PACKET_V2

  WHEA_ERROR_PACKET_V2_SIGNATURE equ <'AEHW'>
  WHEA_ERROR_PACKET_V2_VERSION equ 3

    WHEA_ERROR_PACKET_SIGNATURE equ <WHEA_ERROR_PACKET_V2_SIGNATURE>
    WHEA_ERROR_PACKET_VERSION equ <WHEA_ERROR_PACKET_V2_VERSION>
    WHEA_ERROR_PACKET typedef WHEA_ERROR_PACKET_V2
    PWHEA_ERROR_PACKET typedef ptr WHEA_ERROR_PACKET_V2

  WHEA_GENERIC_ERROR_BLOCKSTATUS union
    struct DUMMYSTRUCTNAME_117
      DUMMYSTRUCTNAME_117_??112 record UncorrectableError_??112:1, CorrectableError_??112:1, MultipleUncorrectableErrors_??112:1, MultipleCorrectableErrors_??112:1, ErrorDataEntryCount_??112:10, Reserved_??112:18
      DUMMYSTRUCTNAME_117_??112 <>
    ends
    AsULONG DWORD ?
  WHEA_GENERIC_ERROR_BLOCKSTATUS ends

  PWHEA_GENERIC_ERROR_BLOCKSTATUS typedef ptr WHEA_GENERIC_ERROR_BLOCKSTATUS
  
  WHEA_GENERIC_ERROR struct
    BlockStatus WHEA_GENERIC_ERROR_BLOCKSTATUS <>
    RawDataOffset DWORD ?
    RawDataLength DWORD ?
    DataLength DWORD ?
    ErrorSeverity WHEA_ERROR_SEVERITY ?
    Data BYTE 1 dup (?)
  WHEA_GENERIC_ERROR ends

  PWHEA_GENERIC_ERROR typedef ptr WHEA_GENERIC_ERROR
  
  WHEA_GENERIC_ERROR_DATA_ENTRY_V1 struct
    SectionType GUID <>
    ErrorSeverity WHEA_ERROR_SEVERITY ?
    Revision WHEA_REVISION <>
    ValidBits BYTE ?
    Flags BYTE ?
    ErrorDataLength DWORD ?
    FRUId GUID <>
    FRUText BYTE 20 dup (?)
    Data BYTE 1 dup (?)
  WHEA_GENERIC_ERROR_DATA_ENTRY_V1 ends

  PWHEA_GENERIC_ERROR_DATA_ENTRY_V1 typedef ptr WHEA_GENERIC_ERROR_DATA_ENTRY_V1
  
  WHEA_GENERIC_ERROR_DATA_ENTRY_V2 struct
    SectionType GUID <>
    ErrorSeverity WHEA_ERROR_SEVERITY ?
    Revision WHEA_REVISION <>
    ValidBits BYTE ?
    Flags BYTE ?
    ErrorDataLength DWORD ?
    FRUId GUID <>
    FRUText BYTE 20 dup (?)
    Timestamp WHEA_TIMESTAMP <>
    Data BYTE 1 dup (?)
  WHEA_GENERIC_ERROR_DATA_ENTRY_V2 ends

  PWHEA_GENERIC_ERROR_DATA_ENTRY_V2 typedef ptr WHEA_GENERIC_ERROR_DATA_ENTRY_V2
  
  WHEA_GENERIC_ENTRY_V2_VERSION equ 300h
  WHEA_GENERIC_ENTRY_VERSION equ <WHEA_GENERIC_ENTRY_V2_VERSION>
  WHEA_GENERIC_ERROR_DATA_ENTRY typedef WHEA_GENERIC_ERROR_DATA_ENTRY_V2
  PWHEA_GENERIC_ERROR_DATA_ENTRY typedef ptr WHEA_GENERIC_ERROR_DATA_ENTRY_V2
  

  WheaGetErrPacketFromErrRecord proto fastcall :PWHEA_ERROR_RECORD
  WHEA_ERROR_INJECTION_CAPABILITIES union
    struct DUMMYSTRUCTNAME_118
      DUMMYSTRUCTNAME_118_??113 record ProcessorCorrectable_??113:1, ProcessorUncorrectableNonFatal_??113:1, ProcessorUncorrectableFatal_??113:1, MemoryCorrectable_??113:1, MemoryUncorrectableNonFatal_??113:1, MemoryUncorrectableFatal_??113:1, PCIExpressCorrectable_??113:1, PCIExpressUncorrectableNonFatal_??113:1, PCIExpressUncorrectableFatal_??113:1, PlatformCorrectable_??113:1, PlatformUncorrectableNonFatal_??113:1, PlatformUncorrectableFatal_??113:1, IA64Corrected_??113:1, IA64Recoverable_??113:1, IA64Fatal_??113:1, IA64RecoverableCache_??113:1, IA64RecoverableRegFile_??113:1, Reserved_??113:15
      DUMMYSTRUCTNAME_118_??113 <>
    ends
    AsULONG DWORD ?
  WHEA_ERROR_INJECTION_CAPABILITIES ends

  PWHEA_ERROR_INJECTION_CAPABILITIES typedef ptr WHEA_ERROR_INJECTION_CAPABILITIES
  
  INJECT_ERRTYPE_PROCESSOR_CORRECTABLE equ 00000001h
  INJECT_ERRTYPE_PROCESSOR_UNCORRECTABLENONFATAL equ 00000002h
  INJECT_ERRTYPE_PROCESSOR_UNCORRECTABLEFATAL equ 00000004h
  INJECT_ERRTYPE_MEMORY_CORRECTABLE equ 00000008h
  INJECT_ERRTYPE_MEMORY_UNCORRECTABLENONFATAL equ 00000010h
  INJECT_ERRTYPE_MEMORY_UNCORRECTABLEFATAL equ 00000020h
  INJECT_ERRTYPE_PCIEXPRESS_CORRECTABLE equ 00000040h
  INJECT_ERRTYPE_PCIEXPRESS_UNCORRECTABLENONFATAL equ 00000080h
  INJECT_ERRTYPE_PCIEXPRESS_UNCORRECTABLEFATAL equ 00000100h
  INJECT_ERRTYPE_PLATFORM_CORRECTABLE equ 00000200h
  INJECT_ERRTYPE_PLATFORM_UNCORRECTABLENONFATAL equ 00000400h
  INJECT_ERRTYPE_PLATFORM_UNCORRECTABLEFATAL equ 00000800h


  WHEA_RECOVERY_CONTEXT struct
    union
      struct MemoryError
        Address ULONG_PTR ?
        Consumed BOOLEAN ?
        ErrorCode UINT16 ?
        ErrorIpValid BOOLEAN ?
        RestartIpValid BOOLEAN ?
      ends
    ends
    PartitionId UINT64 ?
    VpIndex UINT32 ?
  WHEA_RECOVERY_CONTEXT ends

  PWHEA_RECOVERY_CONTEXT typedef ptr WHEA_RECOVERY_CONTEXT
  

;  WHEA_PSHED_PLUGIN_CALLBACKS struct
;    GetAllErrorSources PSHED_PI_GET_ALL_ERROR_SOURCES ?
;    Reserved PVOID ?
;    GetErrorSourceInfo PSHED_PI_GET_ERROR_SOURCE_INFO ?
;    SetErrorSourceInfo PSHED_PI_SET_ERROR_SOURCE_INFO ?
;    EnableErrorSource PSHED_PI_ENABLE_ERROR_SOURCE ?
;    DisableErrorSource PSHED_PI_DISABLE_ERROR_SOURCE ?
;    WriteErrorRecord PSHED_PI_WRITE_ERROR_RECORD ?
;    ReadErrorRecord PSHED_PI_READ_ERROR_RECORD ?
;    ClearErrorRecord PSHED_PI_CLEAR_ERROR_RECORD ?
;    RetrieveErrorInfo PSHED_PI_RETRIEVE_ERROR_INFO ?
;    FinalizeErrorRecord PSHED_PI_FINALIZE_ERROR_RECORD ?
;    ClearErrorStatus PSHED_PI_CLEAR_ERROR_STATUS ?
;    AttemptRecovery PSHED_PI_ATTEMPT_ERROR_RECOVERY ?
;    GetInjectionCapabilities PSHED_PI_GET_INJECTION_CAPABILITIES ?
;    InjectError PSHED_PI_INJECT_ERROR ?
;  WHEA_PSHED_PLUGIN_CALLBACKS ends

;  PWHEA_PSHED_PLUGIN_CALLBACKS typedef ptr WHEA_PSHED_PLUGIN_CALLBACKS
;  
;  WHEA_PSHED_PLUGIN_REGISTRATION_PACKET struct
;    Length_ DWORD ?
;    Version DWORD ?
;    Context PVOID ?
;    FunctionalAreaMask DWORD ?
;    Reserved DWORD ?
;    Callbacks WHEA_PSHED_PLUGIN_CALLBACKS <>
;  WHEA_PSHED_PLUGIN_REGISTRATION_PACKET ends
;
;  PWHEA_PSHED_PLUGIN_REGISTRATION_PACKET typedef ptr WHEA_PSHED_PLUGIN_REGISTRATION_PACKET
  
  WHEA_PLUGIN_REGISTRATION_PACKET_VERSION equ 00010000h
  PshedFADiscovery equ 00000001h
  PshedFAErrorSourceControl equ 00000002h
  PshedFAErrorRecordPersistence equ 00000004h
  PshedFAErrorInfoRetrieval equ 00000008h
  PshedFAErrorRecovery equ 00000010h
  PshedFAErrorInjection equ 00000020h
  WHEA_WRITE_FLAG_DUMMY equ 00000001h




  WheaIsValidErrorRecordSignature proto fastcall :PWHEA_ERROR_RECORD
  WheaFindErrorRecordSection proto fastcall :PWHEA_ERROR_RECORD, :ptr GUID, :ptr PWHEA_ERROR_RECORD_SECTION_DESCRIPTOR, :ptr PVOID
  WheaFindNextErrorRecordSection proto fastcall :PWHEA_ERROR_RECORD, :ptr DWORD, :ptr PWHEA_ERROR_RECORD_SECTION_DESCRIPTOR, :ptr PVOID
  SOC_SUBSYSTEM_TYPE typedef SDWORD
  SOC_SUBSYS_WIRELESS_MODEM EQU 0 
  SOC_SUBSYS_AUDIO_DSP EQU 1 
  SOC_SUBSYS_WIRELSS_CONNECTIVITY EQU 2 
  SOC_SUBSYS_SENSORS EQU 3 
  SOC_SUBSYS_COMPUTE_DSP EQU 4 
  SOC_SUBSYS_VENDOR_DEFINED EQU 10000h 
  
  PSOC_SUBSYSTEM_TYPE typedef ptr SOC_SUBSYSTEM_TYPE
  
  SOC_SUBSYSTEM_FAILURE_DETAILS struct
    SubsysType SOC_SUBSYSTEM_TYPE ?
    FirmwareVersion ULONG64 ?
    HardwareVersion ULONG64 ?
    UnifiedFailureRegionSize DWORD ?
    UnifiedFailureRegion CHAR 1 dup (?)
  SOC_SUBSYSTEM_FAILURE_DETAILS ends

  PSOC_SUBSYSTEM_FAILURE_DETAILS typedef ptr SOC_SUBSYSTEM_FAILURE_DETAILS
  

endif

 