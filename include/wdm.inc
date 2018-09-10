;==============================================================================
; UASM-DDK - wdm.inc
; 
; www.github.com/mrfearless/UASM-DDK by fearless
; 
;==============================================================================


option nokeyword:<irp> ; required for IRP structure, otherwise rename IRP struct to _IRP

ifndef _WDMDDK_
  _WDMDDK_ equ <>

  PACCESS_STATE typedef ptr ACCESS_STATE
  
  PCALLBACK_OBJECT typedef ptr _CALLBACK_OBJECT
  
  PEPROCESS typedef ptr _KPROCESS
  ;PETHREAD typedef ptr _ETHREAD
  PKAFFINITY_EX typedef ptr _KAFFINITY_EX

  PEPROCESS typedef ptr _KPROCESS
  PETHREAD typedef ptr _KTHREAD

  ;PEPROCESS typedef ptr _EPROCESS
  ;PETHREAD typedef ptr _ETHREAD
  
  PIO_TIMER typedef ptr _IO_TIMER
  
  PKINTERRUPT typedef ptr _KINTERRUPT
  
  PKTHREAD typedef ptr _KTHREAD
  PRKTHREAD typedef ptr _KTHREAD
  
  PKPROCESS typedef ptr _KPROCESS
  PRKPROCESS typedef ptr _KPROCESS
  
  POBJECT_TYPE typedef ptr _OBJECT_TYPE
  
  
  PCONTEXT typedef ptr _CONTEXT
  
  
  PFILE_GET_QUOTA_INFORMATION typedef ptr _FILE_GET_QUOTA_INFORMATION
  

    KADDRESS_BASE equ 0
    UADDRESS_BASE equ 0
    PASSIVE_LEVEL equ 0
    LOW_LEVEL equ 0
    APC_LEVEL equ 1
    DISPATCH_LEVEL equ 2
    CMCI_LEVEL equ 5
    CLOCK_LEVEL equ 13
    IPI_LEVEL equ 14
    DRS_LEVEL equ 14
    POWER_LEVEL equ 14
    PROFILE_LEVEL equ 15
    HIGH_LEVEL equ 15


  LOW_PRIORITY equ 0
  LOW_REALTIME_PRIORITY equ 16
  HIGH_PRIORITY equ 31
  MAXIMUM_PRIORITY equ 32
  MAXIMUM_WAIT_OBJECTS equ 64
  MAXIMUM_SUSPEND_COUNT equ <MAXCHAR>
  KSYSTEM_TIME struct
    LowPart DWORD ?
    High1Time SDWORD ?
    High2Time SDWORD ?
  KSYSTEM_TIME ends

  PKSYSTEM_TIME typedef ptr KSYSTEM_TIME
  
  KPRIORITY typedef SDWORD
  KSPIN_LOCK typedef ULONG_PTR
  PKSPIN_LOCK typedef ptr KSPIN_LOCK
  LOCK_QUEUE_WAIT equ 1
  LOCK_QUEUE_WAIT_BIT equ 0
  LOCK_QUEUE_OWNER equ 2
  LOCK_QUEUE_OWNER_BIT equ 1

    KSPIN_LOCK_QUEUE_NUMBER typedef ULONG64
    LockQueueUnusedSpare0 equ 0
    LockQueueUnusedSpare1 equ 1
    LockQueueUnusedSpare2 equ 2
    LockQueueUnusedSpare3 equ 3
    LockQueueVacbLock equ 4
    LockQueueMasterLock equ 5
    LockQueueNonPagedPoolLock equ 6
    LockQueueIoCancelLock equ 7
    LockQueueUnusedSpare8 equ 8
    LockQueueIoVpbLock equ 9
    LockQueueIoDatabaseLock equ 10
    LockQueueIoCompletionLock equ 11
    LockQueueNtfsStructLock equ 12
    LockQueueAfdWorkQueueLock equ 13
    LockQueueBcbLock equ 14
    LockQueueUnusedSpare15 equ 15
    LockQueueUnusedSpare16 equ 16
    LockQueueMaximumLock equ ( LockQueueUnusedSpare16 + 1 )

    IFNDEF KSPIN_LOCK_QUEUE
    KSPIN_LOCK_QUEUE STRUCT
        Next    ULONG ?
    KSPIN_LOCK_QUEUE ends
    ENDIF
    PKSPIN_LOCK_QUEUE typedef ptr KSPIN_LOCK_QUEUE
  
  KLOCK_QUEUE_HANDLE struct
    LockQueue KSPIN_LOCK_QUEUE <>
    OldIrql KIRQL ?
  KLOCK_QUEUE_HANDLE ends

  PKLOCK_QUEUE_HANDLE typedef ptr KLOCK_QUEUE_HANDLE
  
  KPROFILE_SOURCE typedef SDWORD
  ProfileTime EQU 0
  ProfileAlignmentFixup EQU 1
  ProfileTotalIssues EQU 2
  ProfilePipelineDry EQU 3
  ProfileLoadInstructions EQU 4
  ProfilePipelineFrozen EQU 5
  ProfileBranchInstructions EQU 6
  ProfileTotalNonissues EQU 7
  ProfileDcacheMisses EQU 8
  ProfileIcacheMisses EQU 9
  ProfileCacheMisses EQU 10
  ProfileBranchMispredictions EQU 11
  ProfileStoreInstructions EQU 12
  ProfileFpInstructions EQU 13
  ProfileIntegerInstructions EQU 14
  Profile2Issue EQU 15
  Profile3Issue EQU 16
  Profile4Issue EQU 17
  ProfileSpecialInstructions EQU 18
  ProfileTotalCycles EQU 19
  ProfileIcacheIssues EQU 20
  ProfileDcacheAccesses EQU 21
  ProfileMemoryBarrierCycles EQU 22
  ProfileLoadLinkedIssues EQU 23
  ProfileMaximum EQU 24
  
  DPC_WATCHDOG_GLOBAL_TRIAGE_BLOCK_SIGNATURE equ 0AEBECEDEh
  DPC_WATCHDOG_GLOBAL_TRIAGE_BLOCK_REVISION_1 equ 1h
  DPC_WATCHDOG_GLOBAL_TRIAGE_BLOCK_VER_1_SIZE equ <RTL_SIZEOF_THROUGH_FIELD ( DPC_WATCHDOG_GLOBAL_TRIAGE_BLOCK , DpcWatchdogProfileLength )>
  DPC_WATCHDOG_GLOBAL_TRIAGE_BLOCK struct
    Signature DWORD ?
    Revision WORD ?
    Size_ WORD ?
    DpcWatchdogProfileOffset WORD ?
    DpcWatchdogProfileLength DWORD ?
  DPC_WATCHDOG_GLOBAL_TRIAGE_BLOCK ends

  PDPC_WATCHDOG_GLOBAL_TRIAGE_BLOCK typedef ptr DPC_WATCHDOG_GLOBAL_TRIAGE_BLOCK


    XSAVE_AREA_HEADER STRUCT
        Mask_ UINT64 ?
        CompactionMask UINT64 ?
        Reserved2 UINT64 6 dup (?)
    XSAVE_AREA_HEADER ENDS
    PXSAVE_AREA_HEADER TYPEDEF PTR XSAVE_AREA_HEADER

    XSAVE_FORMAT STRUCT
        ControlWord UINT16 ?
        StatusWord UINT16 ?
        TagWord UINT8 ?
        Reserved1 UINT8 ?
        ErrorOpcode UINT16 ?
        ErrorOffset ULONG32 ?
        ErrorSelector UINT16 ?
        Reserved2 UINT16 ?
        DataOffset ULONG32 ?
        DataSelector UINT16 ?
        Reserved3 UINT16 ?
        MxCsr ULONG32 ?
        MxCsr_Mask ULONG32 ?
        FloatRegisters M128A 8 dup (<>)
        XmmRegisters M128A 16 dup (<>)
        Reserved4 UINT8 96 dup (?)
    XSAVE_FORMAT ENDS
    PXSAVE_FORMAT TYPEDEF PTR XSAVE_FORMAT

    XSAVE_AREA STRUCT
        LegacyState XSAVE_FORMAT <>
        Header XSAVE_AREA_HEADER <>
    XSAVE_AREA ENDS
    PXSAVE_AREA TYPEDEF PTR XSAVE_AREA  

    XSTATE_CONTEXT STRUCT
        Mask_ ULONG64 ?
        Length_ DWORD ?
        Reserved1 DWORD ?
        Area PXSAVE_AREA ?
        Reserved2 DWORD ?
        Buffer PVOID ?
        Reserved3 DWORD ?
    XSTATE_CONTEXT ENDS
    PXSTATE_CONTEXT typedef ptr XSTATE_CONTEXT
  

  ifdef _AMD64_
    if defined(_M_AMD64) and  not defined(RC_INVOKED) and  not defined(MIDL_PASS)

      BitTest equ <_bittest>
      BitTestAndComplement equ <_bittestandcomplement>
      BitTestAndSet equ <_bittestandset>
      BitTestAndReset equ <_bittestandreset>
      InterlockedBitTestAndSet equ <_interlockedbittestandset>
      InterlockedBitTestAndSetAcquire equ <_interlockedbittestandset>
      InterlockedBitTestAndSetRelease equ <_interlockedbittestandset>
      InterlockedBitTestAndSetNoFence equ <_interlockedbittestandset>
      InterlockedBitTestAndReset equ <_interlockedbittestandreset>
      InterlockedBitTestAndResetAcquire equ <_interlockedbittestandreset>
      InterlockedBitTestAndResetRelease equ <_interlockedbittestandreset>
      InterlockedBitTestAndResetNoFence equ <_interlockedbittestandreset>
      BitTest64 equ <_bittest64>
      BitTestAndComplement64 equ <_bittestandcomplement64>
      BitTestAndSet64 equ <_bittestandset64>
      BitTestAndReset64 equ <_bittestandreset64>
      InterlockedBitTestAndSet64 equ <_interlockedbittestandset64>
      InterlockedBitTestAndSet64Acquire equ <_interlockedbittestandset64>
      InterlockedBitTestAndSet64Release equ <_interlockedbittestandset64>
      InterlockedBitTestAndSet64NoFence equ <_interlockedbittestandset64>
      InterlockedBitTestAndReset64 equ <_interlockedbittestandreset64>
      InterlockedBitTestAndReset64Acquire equ <_interlockedbittestandreset64>
      InterlockedBitTestAndReset64Release equ <_interlockedbittestandreset64>
      InterlockedBitTestAndReset64NoFence equ <_interlockedbittestandreset64>
      _bittest proto fastcall :ptr SDWORD, :SDWORD
      _bittestandcomplement proto fastcall :ptr SDWORD, :SDWORD
      _bittestandset proto fastcall :ptr SDWORD, :SDWORD
      _bittestandreset proto fastcall :ptr SDWORD, :SDWORD
      _interlockedbittestandset proto fastcall :ptr SDWORD, :SDWORD
      _interlockedbittestandreset proto fastcall :ptr SDWORD, :SDWORD
      _bittest64 proto fastcall :ptr LONG64, :LONG64
      _bittestandcomplement64 proto fastcall :ptr LONG64, :LONG64
      _bittestandset64 proto fastcall :ptr LONG64, :LONG64
      _bittestandreset64 proto fastcall :ptr LONG64, :LONG64
      _interlockedbittestandset64 proto fastcall :ptr LONG64, :LONG64
      _interlockedbittestandreset64 proto fastcall :ptr LONG64, :LONG64
      ;#pragma intrinsic ( _bittest )
      ;#pragma intrinsic ( _bittestandcomplement )
      ;#pragma intrinsic ( _bittestandset )
      ;#pragma intrinsic ( _bittestandreset )
      ;#pragma intrinsic ( _interlockedbittestandset )
      ;#pragma intrinsic ( _interlockedbittestandreset )
      ;#pragma intrinsic ( _bittest64 )
      ;#pragma intrinsic ( _bittestandcomplement64 )
      ;#pragma intrinsic ( _bittestandset64 )
      ;#pragma intrinsic ( _bittestandreset64 )
      ;#pragma intrinsic ( _interlockedbittestandset64 )
      ;#pragma intrinsic ( _interlockedbittestandreset64 )
      BitScanForward equ <_BitScanForward>
      BitScanReverse equ <_BitScanReverse>
      BitScanForward64 equ <_BitScanForward64>
      BitScanReverse64 equ <_BitScanReverse64>
      _BitScanForward proto fastcall :ptr DWORD, :DWORD
      _BitScanReverse proto fastcall :ptr DWORD, :DWORD
      _BitScanForward64 proto fastcall :ptr DWORD, :ULONG64
      _BitScanReverse64 proto fastcall :ptr DWORD, :ULONG64
      ;#pragma intrinsic ( _BitScanForward )
      ;#pragma intrinsic ( _BitScanReverse )
      ;#pragma intrinsic ( _BitScanForward64 )
      ;#pragma intrinsic ( _BitScanReverse64 )
      InterlockedIncrement16 equ <_InterlockedIncrement16>
      InterlockedIncrementAcquire16 equ <_InterlockedIncrement16>
      InterlockedIncrementRelease16 equ <_InterlockedIncrement16>
      InterlockedIncrementNoFence16 equ <_InterlockedIncrement16>
      InterlockedDecrement16 equ <_InterlockedDecrement16>
      InterlockedDecrementAcquire16 equ <_InterlockedDecrement16>
      InterlockedDecrementRelease16 equ <_InterlockedDecrement16>
      InterlockedDecrementNoFence16 equ <_InterlockedDecrement16>
      InterlockedCompareExchange16 equ <_InterlockedCompareExchange16>
      InterlockedCompareExchangeAcquire16 equ <_InterlockedCompareExchange16>
      InterlockedCompareExchangeRelease16 equ <_InterlockedCompareExchange16>
      InterlockedCompareExchangeNoFence16 equ <_InterlockedCompareExchange16>
      InterlockedAnd equ <_InterlockedAnd>
      InterlockedAndAcquire equ <_InterlockedAnd>
      InterlockedAndRelease equ <_InterlockedAnd>
      InterlockedAndNoFence equ <_InterlockedAnd>
      InterlockedOr equ <_InterlockedOr>
      InterlockedOrAcquire equ <_InterlockedOr>
      InterlockedOrRelease equ <_InterlockedOr>
      InterlockedOrNoFence equ <_InterlockedOr>
      InterlockedXor equ <_InterlockedXor>
      InterlockedXorAcquire equ <_InterlockedXor>
      InterlockedXorRelease equ <_InterlockedXor>
      InterlockedXorNoFence equ <_InterlockedXor>
      InterlockedIncrement equ <_InterlockedIncrement>
      InterlockedIncrementAcquire equ <_InterlockedIncrement>
      InterlockedIncrementRelease equ <_InterlockedIncrement>
      InterlockedIncrementNoFence equ <_InterlockedIncrement>
      InterlockedDecrement equ <_InterlockedDecrement>
      InterlockedDecrementAcquire equ <_InterlockedDecrement>
      InterlockedDecrementRelease equ <_InterlockedDecrement>
      InterlockedDecrementNoFence equ <_InterlockedDecrement>
      InterlockedAdd equ <_InlineInterlockedAdd>
      InterlockedAddAcquire equ <_InlineInterlockedAdd>
      InterlockedAddRelease equ <_InlineInterlockedAdd>
      InterlockedAddNoFence equ <_InlineInterlockedAdd>
      InterlockedExchange equ <_InterlockedExchange>
      InterlockedExchangeAcquire equ <_InterlockedExchange>
      InterlockedExchangeNoFence equ <_InterlockedExchange>
      InterlockedExchangeAdd equ <_InterlockedExchangeAdd>
      InterlockedExchangeAddAcquire equ <_InterlockedExchangeAdd>
      InterlockedExchangeAddRelease equ <_InterlockedExchangeAdd>
      InterlockedExchangeAddNoFence equ <_InterlockedExchangeAdd>
      InterlockedCompareExchange equ <_InterlockedCompareExchange>
      InterlockedCompareExchangeAcquire equ <_InterlockedCompareExchange>
      InterlockedCompareExchangeRelease equ <_InterlockedCompareExchange>
      InterlockedCompareExchangeNoFence equ <_InterlockedCompareExchange>
      InterlockedAnd64 equ <_InterlockedAnd64>
      InterlockedAnd64Acquire equ <_InterlockedAnd64>
      InterlockedAnd64Release equ <_InterlockedAnd64>
      InterlockedAnd64NoFence equ <_InterlockedAnd64>
      InterlockedAndAffinity equ <InterlockedAnd64>
      InterlockedOr64 equ <_InterlockedOr64>
      InterlockedOr64Acquire equ <_InterlockedOr64>
      InterlockedOr64Release equ <_InterlockedOr64>
      InterlockedOr64NoFence equ <_InterlockedOr64>
      InterlockedOrAffinity equ <InterlockedOr64>
      InterlockedXor64 equ <_InterlockedXor64>
      InterlockedXor64Acquire equ <_InterlockedXor64>
      InterlockedXor64Release equ <_InterlockedXor64>
      InterlockedXor64NoFence equ <_InterlockedXor64>
      InterlockedIncrement64 equ <_InterlockedIncrement64>
      InterlockedIncrementAcquire64 equ <_InterlockedIncrement64>
      InterlockedIncrementRelease64 equ <_InterlockedIncrement64>
      InterlockedIncrementNoFence64 equ <_InterlockedIncrement64>
      InterlockedDecrement64 equ <_InterlockedDecrement64>
      InterlockedDecrementAcquire64 equ <_InterlockedDecrement64>
      InterlockedDecrementRelease64 equ <_InterlockedDecrement64>
      InterlockedDecrementNoFence64 equ <_InterlockedDecrement64>
      InterlockedAdd64 equ <_InlineInterlockedAdd64>
      InterlockedAddAcquire64 equ <_InlineInterlockedAdd64>
      InterlockedAddRelease64 equ <_InlineInterlockedAdd64>
      InterlockedAddNoFence64 equ <_InlineInterlockedAdd64>
      InterlockedExchange64 equ <_InterlockedExchange64>
      InterlockedExchangeAcquire64 equ <InterlockedExchange64>
      InterlockedExchangeNoFence64 equ <InterlockedExchange64>
      InterlockedExchangeAdd64 equ <_InterlockedExchangeAdd64>
      InterlockedExchangeAddAcquire64 equ <_InterlockedExchangeAdd64>
      InterlockedExchangeAddRelease64 equ <_InterlockedExchangeAdd64>
      InterlockedExchangeAddNoFence64 equ <_InterlockedExchangeAdd64>
      InterlockedCompareExchange64 equ <_InterlockedCompareExchange64>
      InterlockedCompareExchangeAcquire64 equ <InterlockedCompareExchange64>
      InterlockedCompareExchangeRelease64 equ <InterlockedCompareExchange64>
      InterlockedCompareExchangeNoFence64 equ <InterlockedCompareExchange64>
      InterlockedCompareExchange128 equ <_InterlockedCompareExchange128>
      InterlockedExchangePointer equ <_InterlockedExchangePointer>
      InterlockedExchangePointerNoFence equ <_InterlockedExchangePointer>
      InterlockedExchangePointerAcquire equ <_InterlockedExchangePointer>
      InterlockedCompareExchangePointer equ <_InterlockedCompareExchangePointer>
      InterlockedCompareExchangePointerAcquire equ <_InterlockedCompareExchangePointer>
      InterlockedCompareExchangePointerRelease equ <_InterlockedCompareExchangePointer>
      InterlockedCompareExchangePointerNoFence equ <_InterlockedCompareExchangePointer>
      InterlockedExchangeAddSizeT macro a,b
       exitm <InterlockedExchangeAdd64 ( ( LONG64 * ) a , b ) >
      endm
      InterlockedExchangeAddSizeTAcquire macro a,b
       exitm <InterlockedExchangeAdd64 ( ( LONG64 * ) a , b ) >
      endm
      InterlockedExchangeAddSizeTNoFence macro a,b
       exitm <InterlockedExchangeAdd64 ( ( LONG64 * ) a , b ) >
      endm
      InterlockedIncrementSizeT macro a
       exitm <InterlockedIncrement64 ( ( LONG64 * ) a ) >
      endm
      InterlockedIncrementSizeTNoFence macro a
       exitm <InterlockedIncrement64 ( ( LONG64 * ) a ) >
      endm
      InterlockedDecrementSizeT macro a
       exitm <InterlockedDecrement64 ( ( LONG64 * ) a ) >
      endm
      InterlockedDecrementSizeTNoFence macro a
       exitm <InterlockedDecrement64 ( ( LONG64 * ) a ) >
      endm
      InterlockedIncrement16 proto fastcall :ptr SWORD
      InterlockedDecrement16 proto fastcall :ptr SWORD
      InterlockedCompareExchange16 proto fastcall :ptr SWORD, :SWORD, :SWORD
      InterlockedAnd proto fastcall :ptr SDWORD, :SDWORD
      InterlockedOr proto fastcall :ptr SDWORD, :SDWORD
      InterlockedXor proto fastcall :ptr SDWORD, :SDWORD
      InterlockedAnd64 proto fastcall :ptr LONG64, :LONG64
      InterlockedOr64 proto fastcall :ptr LONG64, :LONG64
      InterlockedXor64 proto fastcall :ptr LONG64, :LONG64
      InterlockedIncrement proto fastcall :ptr SDWORD
      InterlockedDecrement proto fastcall :ptr SDWORD
      InterlockedExchange proto fastcall :ptr SDWORD, :SDWORD
      InterlockedExchangeAdd proto fastcall :ptr SDWORD, :SDWORD
      if  not defined(_X86AMD64_)
        InterlockedAdd proto fastcall :ptr SDWORD, :SDWORD
      endif
      InterlockedCompareExchange proto fastcall :ptr SDWORD, :SDWORD, :SDWORD
      InterlockedIncrement64 proto fastcall :ptr LONG64
      InterlockedDecrement64 proto fastcall :ptr LONG64
      InterlockedExchange64 proto fastcall :ptr LONG64, :LONG64
      InterlockedExchangeAdd64 proto fastcall :ptr LONG64, :LONG64
      if  not defined(_X86AMD64_)
        _InlineInterlockedAdd64 proto fastcall :ptr LONG64, :LONG64
      endif
      InterlockedCompareExchange64 proto fastcall :ptr LONG64, :LONG64, :LONG64
      InterlockedCompareExchange128 proto fastcall :ptr LONG64, :LONG64, :LONG64, :ptr LONG64
      InterlockedCompareExchangePointer proto fastcall :ptr PVOID, :PVOID, :PVOID
      InterlockedExchangePointer proto fastcall :ptr PVOID, :PVOID
      ;#pragma intrinsic ( _InterlockedIncrement16 )
      ;#pragma intrinsic ( _InterlockedDecrement16 )
      ;#pragma intrinsic ( _InterlockedCompareExchange16 )
      ;#pragma intrinsic ( _InterlockedAnd )
      ;#pragma intrinsic ( _InterlockedOr )
      ;#pragma intrinsic ( _InterlockedXor )
      ;#pragma intrinsic ( _InterlockedIncrement )
      ;#pragma intrinsic ( _InterlockedDecrement )
      ;#pragma intrinsic ( _InterlockedExchange )
      ;#pragma intrinsic ( _InterlockedExchangeAdd )
      ;#pragma intrinsic ( _InterlockedCompareExchange )
      ;#pragma intrinsic ( _InterlockedAnd64 )
      ;#pragma intrinsic ( _InterlockedOr64 )
      ;#pragma intrinsic ( _InterlockedXor64 )
      ;#pragma intrinsic ( _InterlockedIncrement64 )
      ;#pragma intrinsic ( _InterlockedDecrement64 )
      ;#pragma intrinsic ( _InterlockedExchange64 )
      ;#pragma intrinsic ( _InterlockedExchangeAdd64 )
      ;#pragma intrinsic ( _InterlockedCompareExchange64 )
      if _MSC_VER ge 1500
        ;#pragma intrinsic ( _InterlockedCompareExchange128 )
      endif
      ;#pragma intrinsic ( _InterlockedExchangePointer )
      ;#pragma intrinsic ( _InterlockedCompareExchangePointer )
      if (_MSC_VER ge 1600)
        InterlockedExchange8 equ <_InterlockedExchange8>
        InterlockedExchange16 equ <_InterlockedExchange16>
        InterlockedExchange8 proto fastcall :ptr CHAR, :CHAR
        InterlockedExchange16 proto fastcall :ptr SWORD, :SWORD
        ;#pragma intrinsic ( _InterlockedExchange8 )
        ;#pragma intrinsic ( _InterlockedExchange16 )
      endif
      if _MSC_FULL_VER ge 140041204
        InterlockedExchangeAdd8 equ <_InterlockedExchangeAdd8>
        InterlockedAnd8 equ <_InterlockedAnd8>
        InterlockedOr8 equ <_InterlockedOr8>
        InterlockedXor8 equ <_InterlockedXor8>
        InterlockedAnd16 equ <_InterlockedAnd16>
        InterlockedOr16 equ <_InterlockedOr16>
        InterlockedXor16 equ <_InterlockedXor16>
        InterlockedExchangeAdd8 proto fastcall :ptr SBYTE, :SBYTE
        InterlockedAnd8 proto fastcall :ptr SBYTE, :SBYTE
        InterlockedOr8 proto fastcall :ptr SBYTE, :SBYTE
        InterlockedXor8 proto fastcall :ptr SBYTE, :SBYTE
        InterlockedAnd16 proto fastcall :ptr SWORD, :SWORD
        InterlockedOr16 proto fastcall :ptr SWORD, :SWORD
        InterlockedXor16 proto fastcall :ptr SWORD, :SWORD
        ;#pragma intrinsic ( _InterlockedExchangeAdd8 )
        ;#pragma intrinsic ( _InterlockedAnd8 )
        ;#pragma intrinsic ( _InterlockedOr8 )
        ;#pragma intrinsic ( _InterlockedXor8 )
        ;#pragma intrinsic ( _InterlockedAnd16 )
        ;#pragma intrinsic ( _InterlockedOr16 )
        ;#pragma intrinsic ( _InterlockedXor16 )
      endif
      CpuIdEx equ <__cpuidex>
      __cpuidex proto fastcall :ptr DWORD, :DWORD, :DWORD
      ;#pragma intrinsic ( __cpuidex )
      CacheLineFlush macro Address
       exitm <_mm_clflush ( Address ) >
      endm
      _mm_clflush proto fastcall :ptr 
      ;#pragma intrinsic ( _mm_clflush )
      _ReadWriteBarrier proto fastcall
      ;#pragma intrinsic ( _ReadWriteBarrier )
      FastFence equ <__faststorefence>
      LoadFence equ <_mm_lfence>
      MemoryFence equ <_mm_mfence>
      StoreFence equ <_mm_sfence>
      __faststorefence proto fastcall
      _mm_lfence proto fastcall
      _mm_mfence proto fastcall
      _mm_sfence proto fastcall
      _mm_pause proto fastcall
      _mm_prefetch proto fastcall :ptr CHAR, :DWORD
      _m_prefetchw proto fastcall :ptr 
      _MM_HINT_T0 equ 1
      _MM_HINT_T1 equ 2
      _MM_HINT_T2 equ 3
      _MM_HINT_NTA equ 0
      ;#pragma intrinsic ( __faststorefence )
      ;#pragma intrinsic ( _mm_pause )
      ;#pragma intrinsic ( _mm_prefetch )
      ;#pragma intrinsic ( _mm_lfence )
      ;#pragma intrinsic ( _mm_mfence )
      ;#pragma intrinsic ( _mm_sfence )
      ;#pragma intrinsic ( _m_prefetchw )
      YieldProcessor equ <_mm_pause>
      MemoryBarrier equ <__faststorefence>
      PreFetchCacheLine macro l,a
       exitm <_mm_prefetch ( ( CHAR CONST * ) a , l ) >
      endm
      PrefetchForWrite macro p
       exitm <_m_prefetchw ( p ) >
      endm
      ReadForWriteAccess macro p
       exitm <( _m_prefetchw ( p ) , * ( p ) ) >
      endm
      PF_TEMPORAL_LEVEL_1 equ <_MM_HINT_T0>
      PF_TEMPORAL_LEVEL_2 equ <_MM_HINT_T1>
      PF_TEMPORAL_LEVEL_3 equ <_MM_HINT_T2>
      PF_NON_TEMPORAL_LEVEL_ALL equ <_MM_HINT_NTA>
      ReadMxCsr equ <_mm_getcsr>
      WriteMxCsr equ <_mm_setcsr>
      _mm_getcsr proto fastcall
      _mm_setcsr proto fastcall :DWORD
      ;#pragma intrinsic ( _mm_getcsr )
      ;#pragma intrinsic ( _mm_setcsr )
      GetCallersEflags macro 
       exitm <__getcallerseflags ( ) >
      endm
      __getcallerseflags proto fastcall
      ;#pragma intrinsic ( __getcallerseflags )
      GetSegmentLimit equ <__segmentlimit>
      __segmentlimit proto fastcall :DWORD
      ;#pragma intrinsic ( __segmentlimit )
      ReadPMC equ <__readpmc>
      __readpmc proto fastcall :DWORD
      ;#pragma intrinsic ( __readpmc )
      ReadTimeStampCounter macro 
       exitm <__rdtsc ( ) >
      endm
      __rdtsc proto fastcall
      ;#pragma intrinsic ( __rdtsc )
      __movsb proto fastcall :PUCHAR, :ptr BYTE, :SIZE_T
      __movsw proto fastcall :PUSHORT, :ptr WORD, :SIZE_T
      __movsd proto fastcall :PULONG, :ptr DWORD, :SIZE_T
      __movsq proto fastcall :PULONG64, :ptr ULONG64, :SIZE_T
      ;#pragma intrinsic ( __movsb )
      ;#pragma intrinsic ( __movsw )
      ;#pragma intrinsic ( __movsd )
      ;#pragma intrinsic ( __movsq )
      __stosb proto fastcall :PUCHAR, :BYTE, :SIZE_T
      __stosw proto fastcall :PUSHORT, :WORD, :SIZE_T
      __stosd proto fastcall :PULONG, :DWORD, :SIZE_T
      __stosq proto fastcall :PULONG64, :ULONG64, :SIZE_T
      ;#pragma intrinsic ( __stosb )
      ;#pragma intrinsic ( __stosw )
      ;#pragma intrinsic ( __stosd )
      ;#pragma intrinsic ( __stosq )
      MultiplyHigh equ <__mulh>
      UnsignedMultiplyHigh equ <__umulh>
      MultiplyHigh proto fastcall :LONG64, :LONG64
      UnsignedMultiplyHigh proto fastcall :ULONG64, :ULONG64
      ;#pragma intrinsic ( __mulh )
      ;#pragma intrinsic ( __umulh )
      PopulationCount64 equ <__popcnt64>
      PopulationCount64 proto fastcall :ULONG64
      if _MSC_VER ge 1500
        ;#pragma intrinsic ( __popcnt64 )
      endif
      ShiftLeft128 equ <__shiftleft128>
      ShiftRight128 equ <__shiftright128>
      ShiftLeft128 proto fastcall :ULONG64, :ULONG64, :BYTE
      ShiftRight128 proto fastcall :ULONG64, :ULONG64, :BYTE
      ;#pragma intrinsic ( __shiftleft128 )
      ;#pragma intrinsic ( __shiftright128 )
      Multiply128 equ <_mul128>
      Multiply128 proto fastcall :LONG64, :LONG64, :ptr LONG64
      ;#pragma intrinsic ( _mul128 )
      ifndef UnsignedMultiply128
        UnsignedMultiply128 equ <_umul128>
        UnsignedMultiply128 proto fastcall :ULONG64, :ULONG64, :ptr ULONG64
        ;#pragma intrinsic ( _umul128 )
      endif
      MultiplyExtract128 proto fastcall :LONG64, :LONG64, :BYTE
      UnsignedMultiplyExtract128 proto fastcall :ULONG64, :ULONG64, :BYTE
      __readgsbyte proto fastcall :DWORD
      __readgsword proto fastcall :DWORD
      __readgsdword proto fastcall :DWORD
      __readgsqword proto fastcall :DWORD
      __writegsbyte proto fastcall :DWORD, :BYTE
      __writegsword proto fastcall :DWORD, :WORD
      __writegsdword proto fastcall :DWORD, :DWORD
      __writegsqword proto fastcall :DWORD, :ULONG64
      ;#pragma intrinsic ( __readgsbyte )
      ;#pragma intrinsic ( __readgsword )
      ;#pragma intrinsic ( __readgsdword )
      ;#pragma intrinsic ( __readgsqword )
      ;#pragma intrinsic ( __writegsbyte )
      ;#pragma intrinsic ( __writegsword )
      ;#pragma intrinsic ( __writegsdword )
      ;#pragma intrinsic ( __writegsqword )
      if  not defined(_MANAGED)
        __incgsbyte proto fastcall :DWORD
        __addgsbyte proto fastcall :DWORD, :BYTE
        __incgsword proto fastcall :DWORD
        __addgsword proto fastcall :DWORD, :WORD
        __incgsdword proto fastcall :DWORD
        __addgsdword proto fastcall :DWORD, :DWORD
        __incgsqword proto fastcall :DWORD
        __addgsqword proto fastcall :DWORD, :ULONG64
        if 0
          ;#pragma intrinsic ( __incgsbyte )
          ;#pragma intrinsic ( __addgsbyte )
          ;#pragma intrinsic ( __incgsword )
          ;#pragma intrinsic ( __addgsword )
          ;#pragma intrinsic ( __incgsdword )
          ;#pragma intrinsic ( __addgsdword )
          ;#pragma intrinsic ( __incgsqword )
          ;#pragma intrinsic ( __addgsqword )
        endif
      endif
      ifdef __cplusplus
        ;}
      endif
    endif
    XMM_SAVE_AREA32 typedef XSAVE_FORMAT
    PXMM_SAVE_AREA32 typedef ptr XSAVE_FORMAT
    if defined(_KERNEL_MODE) or defined(_BOOT_ENVIRONMENT)
      KI_USER_SHARED_DATA equ 0FFFFF78000000000h
      SharedUserData equ <( ( KUSER_SHARED_DATA * const ) KI_USER_SHARED_DATA )>
      SharedInterruptTime equ ( KI_USER_SHARED_DATA + 8h )
      SharedSystemTime equ ( KI_USER_SHARED_DATA + 14h )
      SharedTickCount equ ( KI_USER_SHARED_DATA + 320h )
      KeQueryInterruptTime macro 
       exitm <* ( ( volatile ULONG64 * ) ( SharedInterruptTime ) ) >
      endm
      KeQuerySystemTime macro CurrentCount
       exitm <* ( ( PULONG64 ) ( CurrentCount ) ) = * ( ( volatile ULONG64 * ) ( SharedSystemTime ) ) >
      endm
      KeQueryTickCount macro CurrentCount
       exitm <* ( ( PULONG64 ) ( CurrentCount ) ) = * ( ( volatile ULONG64 * ) ( SharedTickCount ) ) >
      endm
    endif
  endif



      ReadAcquire8 proto fastcall :ptr CHAR
      ReadNoFence8 proto fastcall :ptr CHAR
      WriteRelease8 proto fastcall :ptr CHAR, :CHAR
      WriteNoFence8 proto fastcall :ptr CHAR, :CHAR
      ReadAcquire16 proto fastcall :ptr SWORD
      ReadNoFence16 proto fastcall :ptr SWORD
      WriteRelease16 proto fastcall :ptr SWORD, :SWORD
      WriteNoFence16 proto fastcall :ptr SWORD, :SWORD
      ReadAcquire proto fastcall :ptr SDWORD
      ReadNoFence proto fastcall :ptr SDWORD
      WriteRelease proto fastcall :ptr SDWORD, :SDWORD
      WriteNoFence proto fastcall :ptr SDWORD, :SDWORD
      ReadAcquire64 proto fastcall :ptr LONG64
      ReadNoFence64 proto fastcall :ptr LONG64
      WriteRelease64 proto fastcall :ptr LONG64, :LONG64
      WriteNoFence64 proto fastcall :ptr LONG64, :LONG64

    ReadRaw8 proto fastcall :ptr CHAR
    WriteRaw8 proto fastcall :ptr CHAR, :CHAR
    ReadRaw16 proto fastcall :ptr SWORD
    WriteRaw16 proto fastcall :ptr SWORD, :SWORD
    ReadRaw proto fastcall :ptr SDWORD
    WriteRaw proto fastcall :ptr SDWORD, :SDWORD
    ReadRaw64 proto fastcall :ptr LONG64
    WriteRaw64 proto fastcall :ptr LONG64, :LONG64
    ReadUCharAcquire proto fastcall :ptr BYTE
    ReadUCharNoFence proto fastcall :ptr BYTE
    ReadBooleanAcquire proto fastcall :ptr BOOLEAN
    ReadBooleanNoFence proto fastcall :ptr BOOLEAN
    ReadUCharRaw proto fastcall :ptr BYTE
    WriteUCharRelease proto fastcall :ptr BYTE, :BYTE
    WriteUCharNoFence proto fastcall :ptr BYTE, :BYTE
    WriteBooleanRelease proto fastcall :ptr BOOLEAN, :BOOLEAN
    WriteBooleanNoFence proto fastcall :ptr BOOLEAN, :BOOLEAN
    WriteUCharRaw proto fastcall :ptr BYTE, :BYTE
    ReadUShortAcquire proto fastcall :ptr WORD
    ReadUShortNoFence proto fastcall :ptr WORD
    ReadUShortRaw proto fastcall :ptr WORD
    WriteUShortRelease proto fastcall :ptr WORD, :WORD
    WriteUShortNoFence proto fastcall :ptr WORD, :WORD
    WriteUShortRaw proto fastcall :ptr WORD, :WORD
    ReadULongAcquire proto fastcall :ptr DWORD
    ReadULongNoFence proto fastcall :ptr DWORD
    ReadULongRaw proto fastcall :ptr DWORD
    WriteULongRelease proto fastcall :ptr DWORD, :DWORD
    WriteULongNoFence proto fastcall :ptr DWORD, :DWORD
    WriteULongRaw proto fastcall :ptr DWORD, :DWORD
    ReadULong64Acquire proto fastcall :ptr ULONG64
    ReadULong64NoFence proto fastcall :ptr ULONG64
    ReadULong64Raw proto fastcall :ptr ULONG64
    WriteULong64Release proto fastcall :ptr ULONG64, :ULONG64
    WriteULong64NoFence proto fastcall :ptr ULONG64, :ULONG64
    WriteULong64Raw proto fastcall :ptr ULONG64, :ULONG64
    ReadSizeTAcquire equ <ReadULongPtrAcquire>
    ReadSizeTNoFence equ <ReadULongPtrNoFence>
    ReadSizeTRaw equ <ReadULongPtrRaw>
    WriteSizeTRelease equ <WriteULongPtrRelease>
    WriteSizeTNoFence equ <WriteULongPtrNoFence>
    WriteSizeTRaw equ <WriteULongPtrRaw>

      ReadPointerAcquire proto fastcall :ptr PVOID
      ReadPointerNoFence proto fastcall :ptr PVOID
      ReadPointerRaw proto fastcall :ptr PVOID
      WritePointerRelease proto fastcall :ptr PVOID, :PVOID
      WritePointerNoFence proto fastcall :ptr PVOID, :PVOID
      WritePointerRaw proto fastcall :ptr PVOID, :PVOID
      ReadLongPtrAcquire equ <ReadAcquire>
      ReadLongPtrNoFence equ <ReadNoFence>
      ReadLongPtrRaw equ <ReadRaw>
      WriteLongPtrRelease equ <WriteRelease>
      WriteLongPtrNoFence equ <WriteNoFence>
      WriteLongPtrRaw equ <WriteRaw>
      ReadULongPtrAcquire equ <ReadULongAcquire>
      ReadULongPtrNoFence equ <ReadULongNoFence>
      ReadULongPtrRaw equ <ReadULongRaw>
      WriteULongPtrRelease equ <WriteULongRelease>
      WriteULongPtrNoFence equ <WriteULongNoFence>
      WriteULongPtrRaw equ <WriteULongRaw>


      DbgRaiseAssertionFailure proto fastcall


  PACCESS_TOKEN typedef PVOID

  PSID typedef PVOID
  PCLAIMS_BLOB typedef PVOID
  ACCESS_MASK typedef DWORD
  PACCESS_MASK typedef ptr ACCESS_MASK
  DELETE equ 00010000h
  READ_CONTROL equ 00020000h
  WRITE_DAC equ 00040000h
  WRITE_OWNER equ 00080000h
  SYNCHRONIZE equ 00100000h
  STANDARD_RIGHTS_REQUIRED equ 000F0000h
  STANDARD_RIGHTS_ALL equ 001F0000h
  SPECIFIC_RIGHTS_ALL equ 0000FFFFh
  ACCESS_SYSTEM_SECURITY equ 01000000h
  MAXIMUM_ALLOWED equ 02000000h
  GENERIC_READ equ 80000000h
  GENERIC_WRITE equ 40000000h
  GENERIC_EXECUTE equ 20000000h
  GENERIC_ALL equ 10000000h
  GENERIC_MAPPING struct
    GenericRead ACCESS_MASK ?
    GenericWrite ACCESS_MASK ?
    GenericExecute ACCESS_MASK ?
    GenericAll ACCESS_MASK ?
  GENERIC_MAPPING ends

  PGENERIC_MAPPING typedef ptr GENERIC_MAPPING

  LUID_AND_ATTRIBUTES struct
    Luid LUID <>
    Attributes DWORD ?
  LUID_AND_ATTRIBUTES ends

  PLUID_AND_ATTRIBUTES typedef ptr LUID_AND_ATTRIBUTES
  
  LUID_AND_ATTRIBUTES_ARRAY struct
  LUID_AND_ATTRIBUTES ANYSIZE_ARRAY dup (<>)
  LUID_AND_ATTRIBUTES_ARRAY ends
  PLUID_AND_ATTRIBUTES_ARRAY typedef ptr LUID_AND_ATTRIBUTES_ARRAY

  ACL_REVISION equ 2
  ACL_REVISION_DS equ 4
  ACL_REVISION1 equ 1
  MIN_ACL_REVISION equ <ACL_REVISION2>
  ACL_REVISION2 equ 2
  ACL_REVISION3 equ 3
  ACL_REVISION4 equ 4
  MAX_ACL_REVISION equ <ACL_REVISION4>
  ACL struct
    AclRevision BYTE ?
    Sbz1 BYTE ?
    AclSize WORD ?
    AceCount WORD ?
    Sbz2 WORD ?
  ACL ends

  PACL typedef ptr ACL
  SECURITY_DESCRIPTOR_REVISION equ 1
  SECURITY_DESCRIPTOR_REVISION1 equ 1
  SE_PRIVILEGE_ENABLED_BY_DEFAULT equ 00000001h
  SE_PRIVILEGE_ENABLED equ 00000002h
  SE_PRIVILEGE_REMOVED equ 00000004h
  SE_PRIVILEGE_USED_FOR_ACCESS equ 80000000h
  SE_PRIVILEGE_VALID_ATTRIBUTES equ <( SE_PRIVILEGE_ENABLED_BY_DEFAULT or SE_PRIVILEGE_ENABLED or SE_PRIVILEGE_REMOVED or SE_PRIVILEGE_USED_FOR_ACCESS )>
  PRIVILEGE_SET_ALL_NECESSARY equ 1
  PRIVILEGE_SET struct
    PrivilegeCount DWORD ?
    Control DWORD ?
    Privilege LUID_AND_ATTRIBUTES ANYSIZE_ARRAY dup (<>)
  PRIVILEGE_SET ends

  PPRIVILEGE_SET typedef ptr PRIVILEGE_SET
  
  SE_MIN_WELL_KNOWN_PRIVILEGE equ 2
  SE_CREATE_TOKEN_PRIVILEGE equ 2
  SE_ASSIGNPRIMARYTOKEN_PRIVILEGE equ 3
  SE_LOCK_MEMORY_PRIVILEGE equ 4
  SE_INCREASE_QUOTA_PRIVILEGE equ 5
  SE_MACHINE_ACCOUNT_PRIVILEGE equ 6
  SE_TCB_PRIVILEGE equ 7
  SE_SECURITY_PRIVILEGE equ 8
  SE_TAKE_OWNERSHIP_PRIVILEGE equ 9
  SE_LOAD_DRIVER_PRIVILEGE equ 10
  SE_SYSTEM_PROFILE_PRIVILEGE equ 11
  SE_SYSTEMTIME_PRIVILEGE equ 12
  SE_PROF_SINGLE_PROCESS_PRIVILEGE equ 13
  SE_INC_BASE_PRIORITY_PRIVILEGE equ 14
  SE_CREATE_PAGEFILE_PRIVILEGE equ 15
  SE_CREATE_PERMANENT_PRIVILEGE equ 16
  SE_BACKUP_PRIVILEGE equ 17
  SE_RESTORE_PRIVILEGE equ 18
  SE_SHUTDOWN_PRIVILEGE equ 19
  SE_DEBUG_PRIVILEGE equ 20
  SE_AUDIT_PRIVILEGE equ 21
  SE_SYSTEM_ENVIRONMENT_PRIVILEGE equ 22
  SE_CHANGE_NOTIFY_PRIVILEGE equ 23
  SE_REMOTE_SHUTDOWN_PRIVILEGE equ 24
  SE_UNDOCK_PRIVILEGE equ 25
  SE_SYNC_AGENT_PRIVILEGE equ 26
  SE_ENABLE_DELEGATION_PRIVILEGE equ 27
  SE_MANAGE_VOLUME_PRIVILEGE equ 28
  SE_IMPERSONATE_PRIVILEGE equ 29
  SE_CREATE_GLOBAL_PRIVILEGE equ 30
  SE_TRUSTED_CREDMAN_ACCESS_PRIVILEGE equ 31
  SE_RELABEL_PRIVILEGE equ 32
  SE_INC_WORKING_SET_PRIVILEGE equ 33
  SE_TIME_ZONE_PRIVILEGE equ 34
  SE_CREATE_SYMBOLIC_LINK_PRIVILEGE equ 35
  SE_DELEGATE_SESSION_USER_IMPERSONATE_PRIVILEGE equ 36
  SE_MAX_WELL_KNOWN_PRIVILEGE equ <( SE_DELEGATE_SESSION_USER_IMPERSONATE_PRIVILEGE )>
  SECURITY_IMPERSONATION_LEVEL typedef SDWORD
  SecurityAnonymous EQU 0
  SecurityIdentification EQU 1
  SecurityImpersonation EQU 2
  SecurityDelegation EQU 3
  
  PSECURITY_IMPERSONATION_LEVEL typedef ptr SECURITY_IMPERSONATION_LEVEL
  
  SECURITY_MAX_IMPERSONATION_LEVEL equ <SecurityDelegation>
  SECURITY_MIN_IMPERSONATION_LEVEL equ <SecurityAnonymous>
  DEFAULT_IMPERSONATION_LEVEL equ <SecurityImpersonation>
  VALID_IMPERSONATION_LEVEL macro L
   exitm <( ( ( L ) >= SECURITY_MIN_IMPERSONATION_LEVEL ) and ( ( L ) <= SECURITY_MAX_IMPERSONATION_LEVEL ) ) >
  endm
  SECURITY_DYNAMIC_TRACKING equ <( TRUE )>
  SECURITY_STATIC_TRACKING equ <( FALSE )>
  SECURITY_CONTEXT_TRACKING_MODE typedef BOOLEAN
  PSECURITY_CONTEXT_TRACKING_MODE typedef ptr BOOLEAN
  SECURITY_QUALITY_OF_SERVICE struct
    Length_ DWORD ?
    ImpersonationLevel SECURITY_IMPERSONATION_LEVEL ?
    ContextTrackingMode SECURITY_CONTEXT_TRACKING_MODE ?
    EffectiveOnly BOOLEAN ?
  SECURITY_QUALITY_OF_SERVICE ends

  PSECURITY_QUALITY_OF_SERVICE typedef ptr SECURITY_QUALITY_OF_SERVICE
  
  SE_IMPERSONATION_STATE struct
    Token PACCESS_TOKEN ?
    CopyOnOpen BOOLEAN ?
    EffectiveOnly BOOLEAN ?
    Level SECURITY_IMPERSONATION_LEVEL ?
  SE_IMPERSONATION_STATE ends

  PSE_IMPERSONATION_STATE typedef ptr SE_IMPERSONATION_STATE
  
  SECURITY_INFORMATION typedef DWORD
  PSECURITY_INFORMATION typedef ptr DWORD
  OWNER_SECURITY_INFORMATION equ 00000001h
  GROUP_SECURITY_INFORMATION equ 00000002h
  DACL_SECURITY_INFORMATION equ 00000004h
  SACL_SECURITY_INFORMATION equ 00000008h
  LABEL_SECURITY_INFORMATION equ 00000010h
  ATTRIBUTE_SECURITY_INFORMATION equ 00000020h
  SCOPE_SECURITY_INFORMATION equ 00000040h
  PROCESS_TRUST_LABEL_SECURITY_INFORMATION equ 00000080h
  ACCESS_FILTER_SECURITY_INFORMATION equ 00000100h
  BACKUP_SECURITY_INFORMATION equ 00010000h
  PROTECTED_DACL_SECURITY_INFORMATION equ 80000000h
  PROTECTED_SACL_SECURITY_INFORMATION equ 40000000h
  UNPROTECTED_DACL_SECURITY_INFORMATION equ 20000000h
  UNPROTECTED_SACL_SECURITY_INFORMATION equ 10000000h
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
        Data ULONG_PTR 2 dup (?)
        Address PVOID ?
      SE_ADT_PARAMETER_ARRAY_ENTRY ends

      PSE_ADT_PARAMETER_ARRAY_ENTRY typedef ptr SE_ADT_PARAMETER_ARRAY_ENTRY
      
      SE_ADT_ACCESS_REASON struct
        AccessMask ACCESS_MASK ?
        AccessReasons DWORD 32 dup (?)
        ObjectTypeIndex DWORD ?
        AccessGranted DWORD ?
        SecurityDescriptor PSECURITY_DESCRIPTOR ?
      SE_ADT_ACCESS_REASON ends

      PSE_ADT_ACCESS_REASON typedef ptr SE_ADT_ACCESS_REASON
      
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
  FILE_READ_DATA equ 0001h
  FILE_LIST_DIRECTORY equ 0001h
  FILE_WRITE_DATA equ 0002h
  FILE_ADD_FILE equ 0002h
  FILE_APPEND_DATA equ 0004h
  FILE_ADD_SUBDIRECTORY equ 0004h
  FILE_CREATE_PIPE_INSTANCE equ 0004h
  FILE_READ_EA equ 0008h
  FILE_WRITE_EA equ 0010h
  FILE_EXECUTE equ 0020h
  FILE_TRAVERSE equ 0020h
  FILE_DELETE_CHILD equ 0040h
  FILE_READ_ATTRIBUTES equ 0080h
  FILE_WRITE_ATTRIBUTES equ 0100h
  FILE_ALL_ACCESS equ ( STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 1FFh )
  FILE_GENERIC_READ equ <( STANDARD_RIGHTS_READ or FILE_READ_DATA or FILE_READ_ATTRIBUTES or FILE_READ_EA or SYNCHRONIZE )>
  FILE_GENERIC_WRITE equ <( STANDARD_RIGHTS_WRITE or FILE_WRITE_DATA or FILE_WRITE_ATTRIBUTES or FILE_WRITE_EA or FILE_APPEND_DATA or SYNCHRONIZE )>
  FILE_GENERIC_EXECUTE equ <( STANDARD_RIGHTS_EXECUTE or FILE_READ_ATTRIBUTES or FILE_EXECUTE or SYNCHRONIZE )>
  FILE_SHARE_READ equ 00000001h
  FILE_SHARE_WRITE equ 00000002h
  FILE_SHARE_DELETE equ 00000004h
  FILE_SHARE_VALID_FLAGS equ 00000007h
  FILE_ATTRIBUTE_READONLY equ 00000001h
  FILE_ATTRIBUTE_HIDDEN equ 00000002h
  FILE_ATTRIBUTE_SYSTEM equ 00000004h
  FILE_ATTRIBUTE_DIRECTORY equ 00000010h
  FILE_ATTRIBUTE_ARCHIVE equ 00000020h
  FILE_ATTRIBUTE_DEVICE equ 00000040h
  FILE_ATTRIBUTE_NORMAL equ 00000080h
  FILE_ATTRIBUTE_TEMPORARY equ 00000100h
  FILE_ATTRIBUTE_SPARSE_FILE equ 00000200h
  FILE_ATTRIBUTE_REPARSE_POINT equ 00000400h
  FILE_ATTRIBUTE_COMPRESSED equ 00000800h
  FILE_ATTRIBUTE_OFFLINE equ 00001000h
  FILE_ATTRIBUTE_NOT_CONTENT_INDEXED equ 00002000h
  FILE_ATTRIBUTE_ENCRYPTED equ 00004000h

    FILE_ATTRIBUTE_INTEGRITY_STREAM equ 00008000h
    FILE_ATTRIBUTE_VIRTUAL equ 00010000h
    FILE_ATTRIBUTE_NO_SCRUB_DATA equ 00020000h
    FILE_ATTRIBUTE_EA equ 00040000h
    FILE_ATTRIBUTE_PINNED equ 00080000h
    FILE_ATTRIBUTE_UNPINNED equ 00100000h
    FILE_ATTRIBUTE_RECALL_ON_OPEN equ 00040000h
    FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS equ 00400000h
    TREE_CONNECT_ATTRIBUTE_PRIVACY equ 00004000h
    TREE_CONNECT_ATTRIBUTE_INTEGRITY equ 00008000h
    TREE_CONNECT_ATTRIBUTE_GLOBAL equ 00000004h
    FILE_ATTRIBUTE_STRICTLY_SEQUENTIAL equ 20000000h
    FILE_ATTRIBUTE_VALID_FLAGS equ 00007fb7h
    FILE_ATTRIBUTE_VALID_SET_FLAGS equ 000031a7h
    FILE_ATTRIBUTE_VALID_KERNEL_SET_FLAGS equ 005a31a7h


  FILE_SUPERSEDE equ 00000000h
  FILE_OPEN equ 00000001h
  FILE_CREATE equ 00000002h
  FILE_OPEN_IF equ 00000003h
  FILE_OVERWRITE equ 00000004h
  FILE_OVERWRITE_IF equ 00000005h
  FILE_MAXIMUM_DISPOSITION equ 00000005h
  FILE_DIRECTORY_FILE equ 00000001h
  FILE_WRITE_THROUGH equ 00000002h
  FILE_SEQUENTIAL_ONLY equ 00000004h
  FILE_NO_INTERMEDIATE_BUFFERING equ 00000008h
  FILE_SYNCHRONOUS_IO_ALERT equ 00000010h
  FILE_SYNCHRONOUS_IO_NONALERT equ 00000020h
  FILE_NON_DIRECTORY_FILE equ 00000040h
  FILE_CREATE_TREE_CONNECTION equ 00000080h
  FILE_COMPLETE_IF_OPLOCKED equ 00000100h
  FILE_NO_EA_KNOWLEDGE equ 00000200h
  FILE_OPEN_REMOTE_INSTANCE equ 00000400h
  FILE_RANDOM_ACCESS equ 00000800h
  FILE_DELETE_ON_CLOSE equ 00001000h
  FILE_OPEN_BY_FILE_ID equ 00002000h
  FILE_OPEN_FOR_BACKUP_INTENT equ 00004000h
  FILE_NO_COMPRESSION equ 00008000h

    FILE_OPEN_REQUIRING_OPLOCK equ 00010000h
    FILE_DISALLOW_EXCLUSIVE equ 00020000h
    FILE_SESSION_AWARE equ 00040000h

  FILE_RESERVE_OPFILTER equ 00100000h
  FILE_OPEN_REPARSE_POINT equ 00200000h
  FILE_OPEN_NO_RECALL equ 00400000h
  FILE_OPEN_FOR_FREE_SPACE_QUERY equ 00800000h
  FILE_VALID_OPTION_FLAGS equ 00ffffffh
  FILE_VALID_PIPE_OPTION_FLAGS equ 00000032h
  FILE_VALID_MAILSLOT_OPTION_FLAGS equ 00000032h
  FILE_VALID_SET_FLAGS equ 00000036h
  FILE_SUPERSEDED equ 00000000h
  FILE_OPENED equ 00000001h
  FILE_CREATED equ 00000002h
  FILE_OVERWRITTEN equ 00000003h
  FILE_EXISTS equ 00000004h
  FILE_DOES_NOT_EXIST equ 00000005h

    FILE_QUERY_RESTART_SCAN equ 00000001h
    FILE_QUERY_RETURN_SINGLE_ENTRY equ 00000002h
    FILE_QUERY_INDEX_SPECIFIED equ 00000004h
    FILE_QUERY_RETURN_ON_DISK_ENTRIES_ONLY equ 00000008h

  FILE_WRITE_TO_END_OF_FILE equ 0ffffffffh
  FILE_USE_FILE_POINTER_POSITION equ 0fffffffeh
  FILE_BYTE_ALIGNMENT equ 00000000h
  FILE_WORD_ALIGNMENT equ 00000001h
  FILE_LONG_ALIGNMENT equ 00000003h
  FILE_QUAD_ALIGNMENT equ 00000007h
  FILE_OCTA_ALIGNMENT equ 0000000fh
  FILE_32_BYTE_ALIGNMENT equ 0000001fh
  FILE_64_BYTE_ALIGNMENT equ 0000003fh
  FILE_128_BYTE_ALIGNMENT equ 0000007fh
  FILE_256_BYTE_ALIGNMENT equ 000000ffh
  FILE_512_BYTE_ALIGNMENT equ 000001ffh
  MAXIMUM_FILENAME_LENGTH equ 256
  FILE_REMOVABLE_MEDIA equ 00000001h
  FILE_READ_ONLY_DEVICE equ 00000002h
  FILE_FLOPPY_DISKETTE equ 00000004h
  FILE_WRITE_ONCE_MEDIA equ 00000008h
  FILE_REMOTE_DEVICE equ 00000010h
  FILE_DEVICE_IS_MOUNTED equ 00000020h
  FILE_VIRTUAL_VOLUME equ 00000040h
  FILE_AUTOGENERATED_DEVICE_NAME equ 00000080h
  FILE_DEVICE_SECURE_OPEN equ 00000100h
  FILE_CHARACTERISTIC_PNP_DEVICE equ 00000800h
  FILE_CHARACTERISTIC_TS_DEVICE equ 00001000h
  FILE_CHARACTERISTIC_WEBDAV_DEVICE equ 00002000h
  FILE_CHARACTERISTIC_CSV equ 00010000h
  FILE_DEVICE_ALLOW_APPCONTAINER_TRAVERSAL equ 00020000h
  FILE_PORTABLE_DEVICE equ 00040000h
    
    IFNDEF IO_STATUS_BLOCK
    IO_STATUS_BLOCK STRUCT
    	Status			NTSTATUS	?
    	Information		ULONG_PTR	?
    IO_STATUS_BLOCK ENDS
    ENDIF
    PIO_STATUS_BLOCK typedef ptr IO_STATUS_BLOCK
  
    IFNDEF 
    IO_STATUS_BLOCK32 struct
    Status NTSTATUS ?
    Information DWORD ?
    IO_STATUS_BLOCK32 ends
    ENDIF
    PIO_STATUS_BLOCK32 typedef ptr IO_STATUS_BLOCK32
  
  proto_PIO_APC_ROUTINE typedef proto stdcall :PVOID, :PIO_STATUS_BLOCK, :DWORD
  PIO_APC_ROUTINE typedef ptr proto_PIO_APC_ROUTINE
  PIO_APC_ROUTINE_DEFINED equ <>
  IO_SESSION_EVENT typedef SDWORD
  IoSessionEventIgnore EQU 0 
  IoSessionEventCreated EQU 1
  IoSessionEventTerminated EQU 2
  IoSessionEventConnected EQU 3
  IoSessionEventDisconnected EQU 4
  IoSessionEventLogon EQU 5
  IoSessionEventLogoff EQU 6
  IoSessionEventMax EQU 7
  
  PIO_SESSION_EVENT typedef ptr IO_SESSION_EVENT
  
  IO_SESSION_STATE typedef SDWORD
  IoSessionStateCreated EQU 1 
  IoSessionStateInitialized EQU 2
  IoSessionStateConnected EQU 3
  IoSessionStateDisconnected EQU 4
  IoSessionStateDisconnectedLoggedOn EQU 5
  IoSessionStateLoggedOn EQU 6
  IoSessionStateLoggedOff EQU 7
  IoSessionStateTerminated EQU 8
  IoSessionStateMax EQU 9
  
  PIO_SESSION_STATE typedef ptr IO_SESSION_STATE
  
  IO_SESSION_STATE_ALL_EVENTS equ 0ffffffffh
  IO_SESSION_STATE_CREATION_EVENT equ 00000001h
  IO_SESSION_STATE_TERMINATION_EVENT equ 00000002h
  IO_SESSION_STATE_CONNECT_EVENT equ 00000004h
  IO_SESSION_STATE_DISCONNECT_EVENT equ 00000008h
  IO_SESSION_STATE_LOGON_EVENT equ 00000010h
  IO_SESSION_STATE_LOGOFF_EVENT equ 00000020h
  IO_SESSION_STATE_VALID_EVENT_MASK equ 0000003fh
  IO_SESSION_MAX_PAYLOAD_SIZE equ 256
  IO_SESSION_CONNECT_INFO struct
    SessionId DWORD ?
    LocalSession BOOLEAN ?
  IO_SESSION_CONNECT_INFO ends

  PIO_SESSION_CONNECT_INFO typedef ptr IO_SESSION_CONNECT_INFO
  
  FILE_INFORMATION_CLASS typedef SDWORD
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
  
  PFILE_INFORMATION_CLASS typedef ptr FILE_INFORMATION_CLASS
  
  DIRECTORY_NOTIFY_INFORMATION_CLASS typedef SDWORD
  DirectoryNotifyInformation EQU 1 
  DirectoryNotifyExtendedInformation EQU 2
  
  PDIRECTORY_NOTIFY_INFORMATION_CLASS typedef ptr DIRECTORY_NOTIFY_INFORMATION_CLASS
  
  FILE_BASIC_INFORMATION struct
    CreationTime LARGE_INTEGER <>
    LastAccessTime LARGE_INTEGER <>
    LastWriteTime LARGE_INTEGER <>
    ChangeTime LARGE_INTEGER <>
    FileAttributes DWORD ?
  FILE_BASIC_INFORMATION ends

  PFILE_BASIC_INFORMATION typedef ptr FILE_BASIC_INFORMATION
  
  FILE_STANDARD_INFORMATION struct
    AllocationSize LARGE_INTEGER <>
    EndOfFile LARGE_INTEGER <>
    NumberOfLinks DWORD ?
    DeletePending BOOLEAN ?
    Directory BOOLEAN ?
  FILE_STANDARD_INFORMATION ends

  PFILE_STANDARD_INFORMATION typedef ptr FILE_STANDARD_INFORMATION
  

    FILE_STANDARD_INFORMATION_EX struct
      AllocationSize LARGE_INTEGER <>
      EndOfFile LARGE_INTEGER <>
      NumberOfLinks DWORD ?
      DeletePending BOOLEAN ?
      Directory BOOLEAN ?
      AlternateStream BOOLEAN ?
      MetadataAttribute BOOLEAN ?
    FILE_STANDARD_INFORMATION_EX ends

    PFILE_STANDARD_INFORMATION_EX typedef ptr FILE_STANDARD_INFORMATION_EX

  FILE_POSITION_INFORMATION struct
    CurrentByteOffset LARGE_INTEGER <>
  FILE_POSITION_INFORMATION ends

  PFILE_POSITION_INFORMATION typedef ptr FILE_POSITION_INFORMATION
  
  FILE_NETWORK_OPEN_INFORMATION struct
    CreationTime LARGE_INTEGER <>
    LastAccessTime LARGE_INTEGER <>
    LastWriteTime LARGE_INTEGER <>
    ChangeTime LARGE_INTEGER <>
    AllocationSize LARGE_INTEGER <>
    EndOfFile LARGE_INTEGER <>
    FileAttributes DWORD ?
  FILE_NETWORK_OPEN_INFORMATION ends

  PFILE_NETWORK_OPEN_INFORMATION typedef ptr FILE_NETWORK_OPEN_INFORMATION
  
  FILE_FULL_EA_INFORMATION struct
    NextEntryOffset DWORD ?
    Flags BYTE ?
    EaNameLength BYTE ?
    EaValueLength WORD ?
    EaName CHAR 1 dup (?)
  FILE_FULL_EA_INFORMATION ends

  PFILE_FULL_EA_INFORMATION typedef ptr FILE_FULL_EA_INFORMATION
  
  FILE_SFIO_RESERVE_INFORMATION struct
    RequestsPerPeriod DWORD ?
    Period DWORD ?
    RetryFailures BOOLEAN ?
    Discardable BOOLEAN ?
    RequestSize DWORD ?
    NumOutstandingRequests DWORD ?
  FILE_SFIO_RESERVE_INFORMATION ends

  PFILE_SFIO_RESERVE_INFORMATION typedef ptr FILE_SFIO_RESERVE_INFORMATION
  
  FILE_SFIO_VOLUME_INFORMATION struct
    MaximumRequestsPerPeriod DWORD ?
    MinimumPeriod DWORD ?
    MinimumTransferSize DWORD ?
  FILE_SFIO_VOLUME_INFORMATION ends

  PFILE_SFIO_VOLUME_INFORMATION typedef ptr FILE_SFIO_VOLUME_INFORMATION
  
  IO_PRIORITY_HINT typedef SDWORD
  IoPriorityVeryLow EQU 0 
  IoPriorityLow EQU 1
  IoPriorityNormal EQU 2
  IoPriorityHigh EQU 3
  IoPriorityCritical EQU 4
  MaxIoPriorityTypes EQU 5
  
  FILE_IO_PRIORITY_HINT_INFORMATION struct
    PriorityHint IO_PRIORITY_HINT ?
  FILE_IO_PRIORITY_HINT_INFORMATION ends

  PFILE_IO_PRIORITY_HINT_INFORMATION typedef ptr FILE_IO_PRIORITY_HINT_INFORMATION
  
  FILE_IO_PRIORITY_HINT_INFORMATION_EX struct
    PriorityHint IO_PRIORITY_HINT ?
    BoostOutstanding BOOLEAN ?
  FILE_IO_PRIORITY_HINT_INFORMATION_EX ends

  PFILE_IO_PRIORITY_HINT_INFORMATION_EX typedef ptr FILE_IO_PRIORITY_HINT_INFORMATION_EX
  
  FILE_SKIP_COMPLETION_PORT_ON_SUCCESS equ 1h
  FILE_SKIP_SET_EVENT_ON_HANDLE equ 2h
  FILE_SKIP_SET_USER_EVENT_ON_FAST_IO equ 4h
  FILE_IO_COMPLETION_NOTIFICATION_INFORMATION struct
    Flags DWORD ?
  FILE_IO_COMPLETION_NOTIFICATION_INFORMATION ends

  PFILE_IO_COMPLETION_NOTIFICATION_INFORMATION typedef ptr FILE_IO_COMPLETION_NOTIFICATION_INFORMATION
  
  FILE_PROCESS_IDS_USING_FILE_INFORMATION struct
    NumberOfProcessIdsInList DWORD ?
    ProcessIdList ULONG_PTR 1 dup (?)
  FILE_PROCESS_IDS_USING_FILE_INFORMATION ends

  PFILE_PROCESS_IDS_USING_FILE_INFORMATION typedef ptr FILE_PROCESS_IDS_USING_FILE_INFORMATION
  
  FILE_IS_REMOTE_DEVICE_INFORMATION struct
    IsRemote BOOLEAN ?
  FILE_IS_REMOTE_DEVICE_INFORMATION ends

  PFILE_IS_REMOTE_DEVICE_INFORMATION typedef ptr FILE_IS_REMOTE_DEVICE_INFORMATION
  
  FILE_NUMA_NODE_INFORMATION struct
    NodeNumber WORD ?
  FILE_NUMA_NODE_INFORMATION ends

  PFILE_NUMA_NODE_INFORMATION typedef ptr FILE_NUMA_NODE_INFORMATION
  
  FILE_IOSTATUSBLOCK_RANGE_INFORMATION struct
    IoStatusBlockRange PUCHAR ?
    Length_ DWORD ?
  FILE_IOSTATUSBLOCK_RANGE_INFORMATION ends

  PFILE_IOSTATUSBLOCK_RANGE_INFORMATION typedef ptr FILE_IOSTATUSBLOCK_RANGE_INFORMATION
  

    FILE_MEMORY_PARTITION_INFORMATION struct
      OwnerPartitionHandle ULONG_PTR ?
      union Flags
        struct DUMMYSTRUCTNAME_1
          NoCrossPartitionAccess BYTE ?
          Spare BYTE 3 dup (?)
        ends
        AllFlags DWORD ?
      ends
    FILE_MEMORY_PARTITION_INFORMATION ends

    PFILE_MEMORY_PARTITION_INFORMATION typedef ptr FILE_MEMORY_PARTITION_INFORMATION

  FS_INFORMATION_CLASS typedef SDWORD
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
  
  PFS_INFORMATION_CLASS typedef ptr FS_INFORMATION_CLASS
  
    IFNDEF FILE_FS_DEVICE_INFORMATION
    FILE_FS_DEVICE_INFORMATION STRUCT		; sizeof = 8
    	DeviceType			DWORD	?	; 00h DEVICE_TYPE
    	Characteristics		DWORD	?	; 04h
    FILE_FS_DEVICE_INFORMATION ENDS
    ENDIF
    PFILE_FS_DEVICE_INFORMATION typedef ptr FILE_FS_DEVICE_INFORMATION
  
  FILE_SEGMENT_ELEMENT union
    Buffer PVOID64 ?
    Alignment QWORD ?
  FILE_SEGMENT_ELEMENT ends

  PFILE_SEGMENT_ELEMENT typedef ptr FILE_SEGMENT_ELEMENT
  

    FLUSH_FLAGS_FILE_DATA_ONLY equ 00000001h
    FLUSH_FLAGS_NO_SYNC equ 00000002h


    FLUSH_FLAGS_FILE_DATA_SYNC_ONLY equ 00000004h

  INTERFACE_TYPE typedef SDWORD
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
  
  PINTERFACE_TYPE typedef ptr INTERFACE_TYPE
  
  DMA_WIDTH typedef SDWORD
  Width8Bits EQU 0
  Width16Bits EQU 1
  Width32Bits EQU 2
  Width64Bits EQU 3
  WidthNoWrap EQU 4
  MaximumDmaWidth EQU 5
  
  PDMA_WIDTH typedef ptr DMA_WIDTH
  
  DMA_SPEED typedef SDWORD
  Compatible EQU 0
  TypeA EQU 1
  TypeB EQU 2
  TypeC EQU 3
  TypeF EQU 4
  MaximumDmaSpeed EQU 5
  
  PDMA_SPEED typedef ptr DMA_SPEED
  
  IO_ERROR_LOG_PACKET struct
    MajorFunctionCode BYTE ?
    RetryCount BYTE ?
    DumpDataSize WORD ?
    NumberOfStrings WORD ?
    StringOffset WORD ?
    EventCategory WORD ?
    ErrorCode NTSTATUS ?
    UniqueErrorValue DWORD ?
    FinalStatus NTSTATUS ?
    SequenceNumber DWORD ?
    IoControlCode DWORD ?
    DeviceOffset LARGE_INTEGER <>
    DumpData DWORD 1 dup (?)
  IO_ERROR_LOG_PACKET ends

  PIO_ERROR_LOG_PACKET typedef ptr IO_ERROR_LOG_PACKET
  
  IO_ERROR_LOG_MESSAGE struct
    Type_ WORD ?
    Size_ WORD ?
    DriverNameLength WORD ?
    TimeStamp LARGE_INTEGER <>
    DriverNameOffset DWORD ?
    EntryData IO_ERROR_LOG_PACKET <>
  IO_ERROR_LOG_MESSAGE ends

  PIO_ERROR_LOG_MESSAGE typedef ptr IO_ERROR_LOG_MESSAGE
  
  ERROR_LOG_LIMIT_SIZE equ ( 256 - 16 )
  IO_ERROR_LOG_MESSAGE_HEADER_LENGTH equ ( sizeof ( IO_ERROR_LOG_MESSAGE ) - sizeof ( IO_ERROR_LOG_PACKET ) + ( sizeof ( WCHAR ) * 40 ) )
  ERROR_LOG_MESSAGE_LIMIT_SIZE equ <( ERROR_LOG_LIMIT_SIZE + IO_ERROR_LOG_MESSAGE_HEADER_LENGTH )>
  IO_ERROR_LOG_MESSAGE_LENGTH equ ( ( PORT_MAXIMUM_MESSAGE_LENGTH gt ERROR_LOG_MESSAGE_LIMIT_SIZE ) ? ERROR_LOG_MESSAGE_LIMIT_SIZE : PORT_MAXIMUM_MESSAGE_LENGTH )
  ERROR_LOG_MAXIMUM_SIZE equ <( IO_ERROR_LOG_MESSAGE_LENGTH - IO_ERROR_LOG_MESSAGE_HEADER_LENGTH )>

    PORT_MAXIMUM_MESSAGE_LENGTH equ 512

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

  KEY_BASIC_INFORMATION struct
    LastWriteTime LARGE_INTEGER <>
    TitleIndex DWORD ?
    NameLength DWORD ?
    Name_ WCHAR 1 dup (?)
  KEY_BASIC_INFORMATION ends

  PKEY_BASIC_INFORMATION typedef ptr KEY_BASIC_INFORMATION
  
  KEY_NODE_INFORMATION struct
    LastWriteTime LARGE_INTEGER <>
    TitleIndex DWORD ?
    ClassOffset DWORD ?
    ClassLength DWORD ?
    NameLength DWORD ?
    Name_ WCHAR 1 dup (?)
  KEY_NODE_INFORMATION ends

  PKEY_NODE_INFORMATION typedef ptr KEY_NODE_INFORMATION
  
  KEY_FULL_INFORMATION struct
    LastWriteTime LARGE_INTEGER <>
    TitleIndex DWORD ?
    ClassOffset DWORD ?
    ClassLength DWORD ?
    SubKeys DWORD ?
    MaxNameLen DWORD ?
    MaxClassLen DWORD ?
    Values DWORD ?
    MaxValueNameLen DWORD ?
    MaxValueDataLen DWORD ?
    Class WCHAR 1 dup (?)
  KEY_FULL_INFORMATION ends

  PKEY_FULL_INFORMATION typedef ptr KEY_FULL_INFORMATION
  
  KEY_INFORMATION_CLASS typedef SDWORD
  KeyBasicInformation EQU 0
  KeyNodeInformation EQU 1
  KeyFullInformation EQU 2
  KeyNameInformation EQU 3
  KeyCachedInformation EQU 4
  KeyFlagsInformation EQU 5
  KeyVirtualizationInformation EQU 6
  KeyHandleTagsInformation EQU 7
  KeyTrustInformation EQU 8
  KeyLayerInformation EQU 9
  MaxKeyInfoClass EQU 10
  
  KEY_WRITE_TIME_INFORMATION struct
    LastWriteTime LARGE_INTEGER <>
  KEY_WRITE_TIME_INFORMATION ends

  PKEY_WRITE_TIME_INFORMATION typedef ptr KEY_WRITE_TIME_INFORMATION
  
  KEY_WOW64_FLAGS_INFORMATION struct
    UserFlags DWORD ?
  KEY_WOW64_FLAGS_INFORMATION ends

  PKEY_WOW64_FLAGS_INFORMATION typedef ptr KEY_WOW64_FLAGS_INFORMATION
  
  KEY_CONTROL_FLAGS_INFORMATION struct
    ControlFlags DWORD ?
  KEY_CONTROL_FLAGS_INFORMATION ends

  PKEY_CONTROL_FLAGS_INFORMATION typedef ptr KEY_CONTROL_FLAGS_INFORMATION
  
  KEY_SET_VIRTUALIZATION_INFORMATION struct
    KEY_SET_VIRTUALIZATION_INFORMATION_??0 record VirtualTarget_??10:1, VirtualStore_??10:1, VirtualSource_??10:1, Reservedvz_??0:29
    KEY_SET_VIRTUALIZATION_INFORMATION_??0 <>
  KEY_SET_VIRTUALIZATION_INFORMATION ends

  PKEY_SET_VIRTUALIZATION_INFORMATION typedef ptr KEY_SET_VIRTUALIZATION_INFORMATION
  
  KEY_SET_INFORMATION_CLASS typedef SDWORD
  KeyWriteTimeInformation EQU 0
  KeyWow64FlagsInformation EQU 1
  KeyControlFlagsInformation EQU 2
  KeySetVirtualizationInformation EQU 3
  KeySetDebugInformation EQU 4
  KeySetHandleTagsInformation EQU 5
  KeySetLayerInformation EQU 6
  MaxKeySetInfoClass EQU 7
  
  
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
    KEY_VALUE_PARTIAL_INFORMATION ENDS
    ENDIF
    PKEY_VALUE_PARTIAL_INFORMATION typedef PTR KEY_VALUE_PARTIAL_INFORMATION
    
    IFNDEF KEY_VALUE_PARTIAL_INFORMATION_ALIGN64
    KEY_VALUE_PARTIAL_INFORMATION_ALIGN64 STRUCT	; sizeof = 0Ch
    	dwType		DWORD	?	; original field name Type
    	DataLength	DWORD	?
    	Data		BYTE	?	; Variable size
    KEY_VALUE_PARTIAL_INFORMATION_ALIGN64 ENDS
    ENDIF
    PKEY_VALUE_PARTIAL_INFORMATION_ALIGN64 typedef PTR KEY_VALUE_PARTIAL_INFORMATION_ALIGN64
    
    IFNDEF KEY_VALUE_ENTRY
    KEY_VALUE_ENTRY STRUCT	; sizeof = 10h
    	ValueName	PUNICODE_STRING	?	; PTR UNICODE_STRING
    	DataLength	DWORD	?
    	DataOffset	DWORD	?
    	dwType		DWORD	?	; original field name Type
    KEY_VALUE_ENTRY ENDS
    ENDIF
    PKEY_VALUE_ENTRY typedef PTR KEY_VALUE_ENTRY


  
  KEY_VALUE_LAYER_INFORMATION struct
    KEY_VALUE_LAYER_INFORMATION_??1 record IsTombstonekvl_??1:1, Reservedkvl_??1:31
    KEY_VALUE_LAYER_INFORMATION_??1 <>
  KEY_VALUE_LAYER_INFORMATION ends

  PKEY_VALUE_LAYER_INFORMATION typedef ptr KEY_VALUE_LAYER_INFORMATION

  KEY_VALUE_INFORMATION_CLASS typedef SDWORD
  KeyValueBasicInformation EQU 0
  KeyValueFullInformation EQU 1
  KeyValuePartialInformation EQU 2
  KeyValueFullInformationAlign64 EQU 3
  KeyValuePartialInformationAlign64 EQU 4
  KeyValueLayerInformation EQU 5
  MaxKeyValueInfoClass EQU 6
  
  KEY_TRUST_INFORMATION struct
    KEY_TRUST_INFORMATION_??2 record TrustedKey_??2:1, Reserved_??2:31
    KEY_TRUST_INFORMATION_??2 <>
  KEY_TRUST_INFORMATION ends

  PKEY_TRUST_INFORMATION typedef ptr KEY_TRUST_INFORMATION
  
  OBJ_NAME_PATH_SEPARATOR equ <( L'\\' )>
  OBJECT_TYPE_CREATE equ 0001h
  OBJECT_TYPE_ALL_ACCESS equ ( STANDARD_RIGHTS_REQUIRED or 1h )
  DIRECTORY_QUERY equ 0001h
  DIRECTORY_TRAVERSE equ 0002h
  DIRECTORY_CREATE_OBJECT equ 0004h
  DIRECTORY_CREATE_SUBDIRECTORY equ 0008h
  DIRECTORY_ALL_ACCESS equ ( STANDARD_RIGHTS_REQUIRED or 0Fh )
  SYMBOLIC_LINK_QUERY equ 0001h
  SYMBOLIC_LINK_SET equ 0002h
  SYMBOLIC_LINK_ALL_ACCESS equ ( STANDARD_RIGHTS_REQUIRED or 1h )
  SYMBOLIC_LINK_ALL_ACCESS_EX equ ( STANDARD_RIGHTS_REQUIRED or 0FFFFh )
  OBJECT_NAME_INFORMATION struct
    Name_ UNICODE_STRING <>
  OBJECT_NAME_INFORMATION ends

  POBJECT_NAME_INFORMATION typedef ptr OBJECT_NAME_INFORMATION
  
  DUPLICATE_CLOSE_SOURCE equ 00000001h
  DUPLICATE_SAME_ACCESS equ 00000002h
  DUPLICATE_SAME_ATTRIBUTES equ 00000004h
  SECTION_INHERIT typedef SDWORD
  ViewShare EQU 1 
  ViewUnmap EQU 2 
  
  SECTION_QUERY equ 0001h
  SECTION_MAP_WRITE equ 0002h
  SECTION_MAP_READ equ 0004h
  SECTION_MAP_EXECUTE equ 0008h
  SECTION_EXTEND_SIZE equ 0010h
  SECTION_MAP_EXECUTE_EXPLICIT equ 0020h
  SECTION_ALL_ACCESS equ <( STANDARD_RIGHTS_REQUIRED or SECTION_QUERY or SECTION_MAP_WRITE or SECTION_MAP_READ or SECTION_MAP_EXECUTE or SECTION_EXTEND_SIZE )>
  SESSION_QUERY_ACCESS equ 0001h
  SESSION_MODIFY_ACCESS equ 0002h
  SESSION_ALL_ACCESS equ <( STANDARD_RIGHTS_REQUIRED or SESSION_QUERY_ACCESS or SESSION_MODIFY_ACCESS )>
  SEGMENT_ALL_ACCESS equ <SECTION_ALL_ACCESS>
  PAGE_NOACCESS equ 01h
  PAGE_READONLY equ 02h
  PAGE_READWRITE equ 04h
  PAGE_WRITECOPY equ 08h
  PAGE_EXECUTE equ 10h
  PAGE_EXECUTE_READ equ 20h
  PAGE_EXECUTE_READWRITE equ 40h
  PAGE_EXECUTE_WRITECOPY equ 80h
  PAGE_GUARD equ 100h
  PAGE_NOCACHE equ 200h
  PAGE_WRITECOMBINE equ 400h
  PAGE_ENCLAVE_THREAD_CONTROL equ 80000000h
  PAGE_REVERT_TO_FILE_MAP equ 80000000h
  PAGE_TARGETS_NO_UPDATE equ 40000000h
  PAGE_TARGETS_INVALID equ 40000000h
  PAGE_ENCLAVE_UNVALIDATED equ 20000000h
  PAGE_ENCLAVE_NO_CHANGE equ 20000000h
  PAGE_ENCLAVE_DECOMMIT equ 10000000h
  MEM_COMMIT equ 00001000h
  MEM_RESERVE equ 00002000h
  MEM_RESET equ 00080000h
  MEM_TOP_DOWN equ 00100000h
  MEM_RESET_UNDO equ 01000000h
  MEM_LARGE_PAGES equ 20000000h
  MEM_4MB_PAGES equ 80000000h
  MEM_64K_PAGES equ <( MEM_LARGE_PAGES or MEM_PHYSICAL )>
  MEM_DECOMMIT equ 00004000h
  MEM_RELEASE equ 00008000h
  MEM_FREE equ 00010000h
  SEC_64K_PAGES equ 00080000h
  SEC_FILE equ 00800000h
  SEC_RESERVE equ 04000000h
  SEC_COMMIT equ 08000000h
  SEC_LARGE_PAGES equ 80000000h
  MEM_PRIVATE equ 00020000h
  MEM_MAPPED equ 00040000h
  PROCESS_DUP_HANDLE equ 0040h

    PROCESS_ALL_ACCESS equ ( STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 0FFFFh )

  THREAD_TERMINATE equ 0001h
  THREAD_SUSPEND_RESUME equ 0002h
  THREAD_ALERT equ 0004h
  THREAD_GET_CONTEXT equ 0008h
  THREAD_SET_CONTEXT equ 0010h
  THREAD_SET_INFORMATION equ 0020h
  THREAD_SET_LIMITED_INFORMATION equ 0400h
  THREAD_QUERY_LIMITED_INFORMATION equ 0800h
  THREAD_RESUME equ 1000h

    THREAD_ALL_ACCESS equ ( STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 0FFFFh )

  CLIENT_ID struct
    UniqueProcess HANDLE ?
    UniqueThread HANDLE ?
  CLIENT_ID ends

  PCLIENT_ID typedef ptr CLIENT_ID

  DEFINE_GUID GUID_MAX_POWER_SAVINGS, 0A1841308h, 3541h, 4FABh, 0BCh, 81h, 0F7h, 15h, 56h, 0F2h, 0Bh, 4Ah 
  DEFINE_GUID GUID_MIN_POWER_SAVINGS, 8C5E7FDAh, 0E8BFh, 4A96h, 9Ah, 85h, 0A6h, 0E2h, 3Ah, 8Ch, 63h, 5Ch 
  DEFINE_GUID GUID_TYPICAL_POWER_SAVINGS, 381B4222h, 0F694h, 41F0h, 96h, 85h, 0FFh, 5Bh, 0B2h, 60h, 0DFh, 2Eh 
  DEFINE_GUID NO_SUBGROUP_GUID, 0FEA3413Eh, 7E05h, 4911h, 9Ah, 71h, 70h, 03h, 31h, 0F1h, 0C2h, 94h 
  DEFINE_GUID ALL_POWERSCHEMES_GUID, 68A1E95Eh, 13EAh, 41E1h, 80h, 11h, 0Ch, 49h, 6Ch, 0A4h, 90h, 0B0h 
  DEFINE_GUID GUID_POWERSCHEME_PERSONALITY, 245D8541h, 3943h, 4422h, 0B0h, 25h, 13h, 0A7h, 84h, 0F6h, 79h, 0B7h 
  DEFINE_GUID GUID_ACTIVE_POWERSCHEME, 31F9F286h, 5084h, 42FEh, 0B7h, 20h, 2Bh, 02h, 64h, 99h, 37h, 63h 
  DEFINE_GUID GUID_IDLE_RESILIENCY_SUBGROUP, 2e601130h, 5351h, 4d9dh, 8eh, 4h, 25h, 29h, 66h, 0bah, 0d0h, 54h 
  DEFINE_GUID GUID_IDLE_RESILIENCY_PERIOD, 0c42b79aah, 0aa3ah, 484bh, 0a9h, 8fh, 2ch, 0f3h, 2ah, 0a9h, 0ah, 28h 
  DEFINE_GUID GUID_DEEP_SLEEP_ENABLED, 0d502f7eeh, 1dc7h, 4efdh, 0a5h, 5dh, 0f0h, 4bh, 6fh, 5ch, 5h, 45h 
  DEFINE_GUID GUID_DEEP_SLEEP_PLATFORM_STATE, 0d23f2fb8h, 9536h, 4038h, 9ch, 94h, 1ch, 0e0h, 2eh, 5ch, 21h, 52h 
  DEFINE_GUID GUID_DISK_COALESCING_POWERDOWN_TIMEOUT, 0c36f0eb4h, 2988h, 4a70h, 8eh, 0eeh, 8h, 84h, 0fch, 2ch, 24h, 33h 
  DEFINE_GUID GUID_EXECUTION_REQUIRED_REQUEST_TIMEOUT, 3166bc41h, 7e98h, 4e03h, 0b3h, 4eh, 0ech, 0fh, 5fh, 2bh, 21h, 8eh 
  DEFINE_GUID GUID_VIDEO_SUBGROUP, 7516B95Fh, 0F776h, 4464h, 8Ch, 53h, 06h, 16h, 7Fh, 40h, 0CCh, 99h 
  DEFINE_GUID GUID_VIDEO_POWERDOWN_TIMEOUT, 3C0BC021h, 0C8A8h, 4E07h, 0A9h, 73h, 6Bh, 14h, 0CBh, 0CBh, 2Bh, 7Eh 
  DEFINE_GUID GUID_VIDEO_ANNOYANCE_TIMEOUT, 82DBCF2Dh, 0CD67h, 40C5h, 0BFh, 0DCh, 9Fh, 1Ah, 5Ch, 0CDh, 46h, 63h 
  DEFINE_GUID GUID_VIDEO_ADAPTIVE_PERCENT_INCREASE, 0EED904DFh, 0B142h, 4183h, 0B1h, 0Bh, 5Ah, 11h, 97h, 0A3h, 78h, 64h 
  DEFINE_GUID GUID_VIDEO_DIM_TIMEOUT, 17aaa29bh, 8b43h, 4b94h, 0aah, 0feh, 35h, 0f6h, 4dh, 0aah, 0f1h, 0eeh 
  DEFINE_GUID GUID_VIDEO_ADAPTIVE_POWERDOWN, 90959D22h, 0D6A1h, 49B9h, 0AFh, 93h, 0BCh, 0E8h, 85h, 0ADh, 33h, 5Bh 
  DEFINE_GUID GUID_MONITOR_POWER_ON, 02731015h, 4510h, 4526h, 99h, 0E6h, 0E5h, 0A1h, 7Eh, 0BDh, 1Ah, 0EAh 
  DEFINE_GUID GUID_DEVICE_POWER_POLICY_VIDEO_BRIGHTNESS, 0aded5e82h, 0b909h, 4619h, 99h, 49h, 0f5h, 0d7h, 1dh, 0ach, 0bh, 0cbh 
  DEFINE_GUID GUID_DEVICE_POWER_POLICY_VIDEO_DIM_BRIGHTNESS, 0f1fbfde2h, 0a960h, 4165h, 9fh, 88h, 50h, 66h, 79h, 11h, 0ceh, 96h 
  DEFINE_GUID GUID_VIDEO_CURRENT_MONITOR_BRIGHTNESS, 8ffee2c6h, 2d01h, 46beh, 0adh, 0b9h, 39h, 8ah, 0ddh, 0c5h, 0b4h, 0ffh 
  DEFINE_GUID GUID_VIDEO_ADAPTIVE_DISPLAY_BRIGHTNESS, 0FBD9AA66h, 9553h, 4097h, 0BAh, 44h, 0EDh, 6Eh, 9Dh, 65h, 0EAh, 0B8h 
  DEFINE_GUID GUID_CONSOLE_DISPLAY_STATE, 6fe69556h, 704ah, 47a0h, 8fh, 24h, 0c2h, 8dh, 93h, 6fh, 0dah, 47h 
  DEFINE_GUID GUID_ALLOW_DISPLAY_REQUIRED, 0A9CEB8DAh, 0CD46h, 44FBh, 0A9h, 8Bh, 02h, 0AFh, 69h, 0DEh, 46h, 23h 
  DEFINE_GUID GUID_VIDEO_CONSOLE_LOCK_TIMEOUT, 8ec4b3a5h, 6868h, 48c2h, 0beh, 75h, 4fh, 30h, 44h, 0beh, 88h, 0a7h 
  DEFINE_GUID GUID_ADAPTIVE_POWER_BEHAVIOR_SUBGROUP, 8619b916h, 0e004h, 4dd8h, 9bh, 66h, 0dah, 0e8h, 6fh, 80h, 66h, 98h 
  DEFINE_GUID GUID_NON_ADAPTIVE_INPUT_TIMEOUT, 5adbbfbch, 74eh, 4da1h, 0bah, 38h, 0dbh, 8bh, 36h, 0b2h, 0c8h, 0f3h 
  DEFINE_GUID GUID_ADAPTIVE_INPUT_CONTROLLER_STATE, 0e98fae9h, 0f45ah, 4de1h, 0a7h, 57h, 60h, 31h, 0f1h, 97h, 0f6h, 0eah 
  DEFINE_GUID GUID_DISK_SUBGROUP, 0012EE47h, 9041h, 4B5Dh, 9Bh, 77h, 53h, 5Fh, 0BAh, 8Bh, 14h, 42h 
  DEFINE_GUID GUID_DISK_MAX_POWER, 51dea550h, 0bb38h, 4bc4h, 99h, 1bh, 0eah, 0cfh, 37h, 0beh, 5eh, 0c8h 
  DEFINE_GUID GUID_DISK_POWERDOWN_TIMEOUT, 6738E2C4h, 0E8A5h, 4A42h, 0B1h, 6Ah, 0E0h, 40h, 0E7h, 69h, 75h, 6Eh 
  DEFINE_GUID GUID_DISK_IDLE_TIMEOUT, 58E39BA8h, 0B8E6h, 4EF6h, 90h, 0D0h, 89h, 0AEh, 32h, 0B2h, 58h, 0D6h 
  DEFINE_GUID GUID_DISK_BURST_IGNORE_THRESHOLD, 80e3c60eh, 0bb94h, 4ad8h, 0bbh, 0e0h, 0dh, 31h, 95h, 0efh, 0c6h, 63h 
  DEFINE_GUID GUID_DISK_ADAPTIVE_POWERDOWN, 396A32E1h, 499Ah, 40B2h, 91h, 24h, 0A9h, 6Ah, 0FEh, 70h, 76h, 67h 
  DEFINE_GUID GUID_SLEEP_SUBGROUP, 238C9FA8h, 0AADh, 41EDh, 83h, 0F4h, 97h, 0BEh, 24h, 2Ch, 8Fh, 20h 
  DEFINE_GUID GUID_SLEEP_IDLE_THRESHOLD, 81cd32e0h, 7833h, 44f3h, 87h, 37h, 70h, 81h, 0f3h, 8dh, 1fh, 70h 
  DEFINE_GUID GUID_STANDBY_TIMEOUT, 29F6C1DBh, 86DAh, 48C5h, 9Fh, 0DBh, 0F2h, 0B6h, 7Bh, 1Fh, 44h, 0DAh 
  DEFINE_GUID GUID_UNATTEND_SLEEP_TIMEOUT, 7bc4a2f9h, 0d8fch, 4469h, 0b0h, 7bh, 33h, 0ebh, 78h, 5ah, 0ach, 0a0h 
  DEFINE_GUID GUID_HIBERNATE_TIMEOUT, 9D7815A6h, 7EE4h, 497Eh, 88h, 88h, 51h, 5Ah, 05h, 0F0h, 23h, 64h 
  DEFINE_GUID GUID_HIBERNATE_FASTS4_POLICY, 94AC6D29h, 73CEh, 41A6h, 80h, 9Fh, 63h, 63h, 0BAh, 21h, 0B4h, 7Eh 
  DEFINE_GUID GUID_CRITICAL_POWER_TRANSITION, 0B7A27025h, 0E569h, 46c2h, 0A5h, 04h, 2Bh, 96h, 0CAh, 0D2h, 25h, 0A1h 
  DEFINE_GUID GUID_SYSTEM_AWAYMODE, 98A7F580h, 01F7h, 48AAh, 9Ch, 0Fh, 44h, 35h, 2Ch, 29h, 0E5h, 0C0h 
  DEFINE_GUID GUID_ALLOW_AWAYMODE, 25dfa149h, 5dd1h, 4736h, 0b5h, 0abh, 0e8h, 0a3h, 7bh, 5bh, 81h, 87h 
  DEFINE_GUID GUID_USER_PRESENCE_PREDICTION, 82011705h, 0fb95h, 4d46h, 8dh, 35h, 40h, 42h, 0b1h, 0d2h, 0dh, 0efh 
  DEFINE_GUID GUID_STANDBY_BUDGET_GRACE_PERIOD, 60c07fe1h, 0556h, 45cfh, 99h, 03h, 0d5h, 6eh, 32h, 21h, 2h, 42h 
  DEFINE_GUID GUID_STANDBY_BUDGET_PERCENT, 9fe527beh, 1b70h, 48dah, 93h, 0dh, 7bh, 0cfh, 17h, 0b4h, 49h, 90h 
  DEFINE_GUID GUID_STANDBY_RESERVE_GRACE_PERIOD, 0c763ee92h, 71e8h, 4127h, 84h, 0ebh, 0f6h, 0edh, 04h, 3ah, 3eh, 3dh 
  DEFINE_GUID GUID_STANDBY_RESERVE_TIME, 468FE7E5h, 1158h, 46ECh, 88h, 0bch, 5bh, 96h, 0c9h, 0e4h, 4fh, 0d0h 
  DEFINE_GUID GUID_STANDBY_RESET_PERCENT, 49cb11a5h, 56e2h, 4afbh, 9dh, 38h, 3dh, 0f4h, 78h, 72h, 0e2h, 1bh 
  DEFINE_GUID GUID_ALLOW_STANDBY_STATES, 0abfc2519h, 3608h, 4c2ah, 94h, 0eah, 17h, 1bh, 0eh, 0d5h, 46h, 0abh 
  DEFINE_GUID GUID_ALLOW_RTC_WAKE, 0BD3B718Ah, 0680h, 4D9Dh, 8Ah, 0B2h, 0E1h, 0D2h, 0B4h, 0ACh, 80h, 6Dh 
  DEFINE_GUID GUID_LEGACY_RTC_MITIGATION, 1A34BDC3h, 7E6Bh, 442Eh, 0A9h, 0D0h, 64h, 0B6h, 0EFh, 37h, 8Eh, 84h 
  DEFINE_GUID GUID_ALLOW_SYSTEM_REQUIRED, 0A4B195F5h, 8225h, 47D8h, 80h, 12h, 9Dh, 41h, 36h, 97h, 86h, 0E2h 
  DEFINE_GUID GUID_POWER_SAVING_STATUS, 0e00958c0h, 0c213h, 4aceh, 0ach, 77h, 0feh, 0cch, 0edh, 2eh, 0eeh, 0a5h 
  DEFINE_GUID GUID_ENERGY_SAVER_SUBGROUP, 0DE830923h, 0A562h, 41AFh, 0A0h, 86h, 0E3h, 0A2h, 0C6h, 0BAh, 0D2h, 0DAh 
  DEFINE_GUID GUID_ENERGY_SAVER_BATTERY_THRESHOLD, 0E69653CAh, 0CF7Fh, 4F05h, 0AAh, 73h, 0CBh, 83h, 3Fh, 0A9h, 0Ah, 0D4h 
  DEFINE_GUID GUID_ENERGY_SAVER_BRIGHTNESS, 13D09884h, 0F74Eh, 474Ah, 0A8h, 52h, 0B6h, 0BDh, 0E8h, 0ADh, 03h, 0A8h 
  DEFINE_GUID GUID_ENERGY_SAVER_POLICY, 5c5bb349h, 0ad29h, 4ee2h, 9dh, 0bh, 2bh, 25h, 27h, 0fh, 7ah, 81h 
  DEFINE_GUID GUID_SYSTEM_BUTTON_SUBGROUP, 4F971E89h, 0EEBDh, 4455h, 0A8h, 0DEh, 9Eh, 59h, 04h, 0Eh, 73h, 47h 
  POWERBUTTON_ACTION_INDEX_NOTHING equ 0
  POWERBUTTON_ACTION_INDEX_SLEEP equ 1
  POWERBUTTON_ACTION_INDEX_HIBERNATE equ 2
  POWERBUTTON_ACTION_INDEX_SHUTDOWN equ 3
  POWERBUTTON_ACTION_INDEX_TURN_OFF_THE_DISPLAY equ 4
  POWERBUTTON_ACTION_VALUE_NOTHING equ 0
  POWERBUTTON_ACTION_VALUE_SLEEP equ 2
  POWERBUTTON_ACTION_VALUE_HIBERNATE equ 3
  POWERBUTTON_ACTION_VALUE_SHUTDOWN equ 6
  POWERBUTTON_ACTION_VALUE_TURN_OFF_THE_DISPLAY equ 8
  DEFINE_GUID GUID_POWERBUTTON_ACTION, 7648EFA3h, 0DD9Ch, 4E3Eh, 0B5h, 66h, 50h, 0F9h, 29h, 38h, 62h, 80h 
  DEFINE_GUID GUID_SLEEPBUTTON_ACTION, 96996BC0h, 0AD50h, 47ECh, 92h, 3Bh, 6Fh, 41h, 87h, 4Dh, 0D9h, 0EBh 
  DEFINE_GUID GUID_USERINTERFACEBUTTON_ACTION, 0A7066653h, 8D6Ch, 40A8h, 91h, 0Eh, 0A1h, 0F5h, 4Bh, 84h, 0C7h, 0E5h 
  DEFINE_GUID GUID_LIDCLOSE_ACTION, 5CA83367h, 6E45h, 459Fh, 0A2h, 7Bh, 47h, 6Bh, 1Dh, 01h, 0C9h, 36h 
  DEFINE_GUID GUID_LIDOPEN_POWERSTATE, 99FF10E7h, 23B1h, 4C07h, 0A9h, 0D1h, 5Ch, 32h, 06h, 0D7h, 41h, 0B4h 
  DEFINE_GUID GUID_BATTERY_SUBGROUP, 0E73A048Dh, 0BF27h, 4F12h, 97h, 31h, 8Bh, 20h, 76h, 0E8h, 89h, 1Fh 
  DEFINE_GUID GUID_BATTERY_DISCHARGE_ACTION_0, 637EA02Fh, 0BBCBh, 4015h, 8Eh, 2Ch, 0A1h, 0C7h, 0B9h, 0C0h, 0B5h, 46h 
  DEFINE_GUID GUID_BATTERY_DISCHARGE_LEVEL_0, 9A66D8D7h, 4FF7h, 4EF9h, 0B5h, 0A2h, 5Ah, 32h, 6Ch, 0A2h, 0A4h, 69h 
  DEFINE_GUID GUID_BATTERY_DISCHARGE_FLAGS_0, 5dbb7c9fh, 38e9h, 40d2h, 97h, 49h, 4fh, 8ah, 0eh, 9fh, 64h, 0fh 
  DEFINE_GUID GUID_BATTERY_DISCHARGE_ACTION_1, 0D8742DCBh, 3E6Ah, 4B3Ch, 0B3h, 0FEh, 37h, 46h, 23h, 0CDh, 0CFh, 06h 
  DEFINE_GUID GUID_BATTERY_DISCHARGE_LEVEL_1, 8183BA9Ah, 0E910h, 48DAh, 87h, 69h, 14h, 0AEh, 6Dh, 0C1h, 17h, 0Ah 
  DEFINE_GUID GUID_BATTERY_DISCHARGE_FLAGS_1, 0bcded951h, 187bh, 4d05h, 0bch, 0cch, 0f7h, 0e5h, 19h, 60h, 0c2h, 58h 
  DEFINE_GUID GUID_BATTERY_DISCHARGE_ACTION_2, 421CBA38h, 1A8Eh, 4881h, 0ACh, 89h, 0E3h, 3Ah, 8Bh, 04h, 0ECh, 0E4h 
  DEFINE_GUID GUID_BATTERY_DISCHARGE_LEVEL_2, 07A07CA2h, 0ADAFh, 40D7h, 0B0h, 77h, 53h, 3Ah, 0ADh, 0EDh, 1Bh, 0FAh 
  DEFINE_GUID GUID_BATTERY_DISCHARGE_FLAGS_2, 7fd2f0c4h, 0feb7h, 4da3h, 81h, 17h, 0e3h, 0fbh, 0edh, 0c4h, 65h, 82h 
  DEFINE_GUID GUID_BATTERY_DISCHARGE_ACTION_3, 80472613h, 9780h, 455Eh, 0B3h, 08h, 72h, 0D3h, 00h, 3Ch, 0F2h, 0F8h 
  DEFINE_GUID GUID_BATTERY_DISCHARGE_LEVEL_3, 58AFD5A6h, 0C2DDh, 47D2h, 9Fh, 0BFh, 0EFh, 70h, 0CCh, 5Ch, 59h, 65h 
  DEFINE_GUID GUID_BATTERY_DISCHARGE_FLAGS_3, 73613ccfh, 0dbfah, 4279h, 83h, 56h, 49h, 35h, 0f6h, 0bfh, 62h, 0f3h 
  DEFINE_GUID GUID_PROCESSOR_SETTINGS_SUBGROUP, 54533251h, 82BEh, 4824h, 96h, 0C1h, 47h, 0B6h, 0Bh, 74h, 0Dh, 00h 
  DEFINE_GUID GUID_PROCESSOR_THROTTLE_POLICY, 57027304h, 4AF6h, 4104h, 92h, 60h, 0E3h, 0D9h, 52h, 48h, 0FCh, 36h 
  PERFSTATE_POLICY_CHANGE_IDEAL equ 0
  PERFSTATE_POLICY_CHANGE_SINGLE equ 1
  PERFSTATE_POLICY_CHANGE_ROCKET equ 2
  PERFSTATE_POLICY_CHANGE_IDEAL_AGGRESSIVE equ 3
  PERFSTATE_POLICY_CHANGE_DECREASE_MAX equ <PERFSTATE_POLICY_CHANGE_ROCKET>
  PERFSTATE_POLICY_CHANGE_INCREASE_MAX equ <PERFSTATE_POLICY_CHANGE_IDEAL_AGGRESSIVE>
  DEFINE_GUID GUID_PROCESSOR_THROTTLE_MAXIMUM, 0BC5038F7h, 23E0h, 4960h, 96h, 0DAh, 33h, 0ABh, 0AFh, 59h, 35h, 0ECh 
  DEFINE_GUID GUID_PROCESSOR_THROTTLE_MAXIMUM_1, 0BC5038F7h, 23E0h, 4960h, 96h, 0DAh, 33h, 0ABh, 0AFh, 59h, 35h, 0EDh 
  DEFINE_GUID GUID_PROCESSOR_THROTTLE_MINIMUM, 893DEE8Eh, 2BEFh, 41E0h, 89h, 0C6h, 0B5h, 5Dh, 09h, 29h, 96h, 4Ch 
  DEFINE_GUID GUID_PROCESSOR_THROTTLE_MINIMUM_1, 893DEE8Eh, 2BEFh, 41E0h, 89h, 0C6h, 0B5h, 5Dh, 09h, 29h, 96h, 4Dh 
  DEFINE_GUID GUID_PROCESSOR_FREQUENCY_LIMIT, 75b0ae3fh, 0bce0h, 45a7h, 8ch, 89h, 0c9h, 61h, 1ch, 25h, 0e1h, 00h 
  DEFINE_GUID GUID_PROCESSOR_FREQUENCY_LIMIT_1, 75b0ae3fh, 0bce0h, 45a7h, 8ch, 89h, 0c9h, 61h, 1ch, 25h, 0e1h, 01h 
  DEFINE_GUID GUID_PROCESSOR_ALLOW_THROTTLING, 3b04d4fdh, 1cc7h, 4f23h, 0abh, 1ch, 0d1h, 33h, 78h, 19h, 0c4h, 0bbh 
  PROCESSOR_THROTTLE_DISABLED equ 0
  PROCESSOR_THROTTLE_ENABLED equ 1
  PROCESSOR_THROTTLE_AUTOMATIC equ 2
  DEFINE_GUID GUID_PROCESSOR_IDLESTATE_POLICY, 68f262a7h, 0f621h, 4069h, 0b9h, 0a5h, 48h, 74h, 16h, 9bh, 0e2h, 3ch 
  DEFINE_GUID GUID_PROCESSOR_PERFSTATE_POLICY, 0BBDC3814h, 18E9h, 4463h, 8Ah, 55h, 0D1h, 97h, 32h, 7Ch, 45h, 0C0h 
  DEFINE_GUID GUID_PROCESSOR_PERF_INCREASE_THRESHOLD, 06cadf0eh, 64edh, 448ah, 89h, 27h, 0ceh, 7bh, 0f9h, 0eh, 0b3h, 5dh 
  DEFINE_GUID GUID_PROCESSOR_PERF_INCREASE_THRESHOLD_1, 06cadf0eh, 64edh, 448ah, 89h, 27h, 0ceh, 7bh, 0f9h, 0eh, 0b3h, 5eh 
  DEFINE_GUID GUID_PROCESSOR_PERF_DECREASE_THRESHOLD, 12a0ab44h, 0fe28h, 4fa9h, 0b3h, 0bdh, 4bh, 64h, 0f4h, 49h, 60h, 0a6h 
  DEFINE_GUID GUID_PROCESSOR_PERF_DECREASE_THRESHOLD_1, 12a0ab44h, 0fe28h, 4fa9h, 0b3h, 0bdh, 4bh, 64h, 0f4h, 49h, 60h, 0a7h 
  DEFINE_GUID GUID_PROCESSOR_PERF_INCREASE_POLICY, 465e1f50h, 0b610h, 473ah, 0abh, 58h, 0h, 0d1h, 7h, 7dh, 0c4h, 18h 
  DEFINE_GUID GUID_PROCESSOR_PERF_INCREASE_POLICY_1, 465e1f50h, 0b610h, 473ah, 0abh, 58h, 0h, 0d1h, 7h, 7dh, 0c4h, 19h 
  DEFINE_GUID GUID_PROCESSOR_PERF_DECREASE_POLICY, 40fbefc7h, 2e9dh, 4d25h, 0a1h, 85h, 0ch, 0fdh, 85h, 74h, 0bah, 0c6h 
  DEFINE_GUID GUID_PROCESSOR_PERF_DECREASE_POLICY_1, 40fbefc7h, 2e9dh, 4d25h, 0a1h, 85h, 0ch, 0fdh, 85h, 74h, 0bah, 0c7h 
  DEFINE_GUID GUID_PROCESSOR_PERF_INCREASE_TIME, 984cf492h, 3bedh, 4488h, 0a8h, 0f9h, 42h, 86h, 0c9h, 7bh, 0f5h, 0aah 
  DEFINE_GUID GUID_PROCESSOR_PERF_INCREASE_TIME_1, 984cf492h, 3bedh, 4488h, 0a8h, 0f9h, 42h, 86h, 0c9h, 7bh, 0f5h, 0abh 
  DEFINE_GUID GUID_PROCESSOR_PERF_DECREASE_TIME, 0d8edeb9bh, 95cfh, 4f95h, 0a7h, 3ch, 0b0h, 61h, 97h, 36h, 93h, 0c8h 
  DEFINE_GUID GUID_PROCESSOR_PERF_DECREASE_TIME_1, 0d8edeb9bh, 95cfh, 4f95h, 0a7h, 3ch, 0b0h, 61h, 97h, 36h, 93h, 0c9h 
  DEFINE_GUID GUID_PROCESSOR_PERF_TIME_CHECK, 4d2b0152h, 7d5ch, 498bh, 88h, 0e2h, 34h, 34h, 53h, 92h, 0a2h, 0c5h 
  DEFINE_GUID GUID_PROCESSOR_PERF_BOOST_POLICY, 45bcc044h, 0d885h, 43e2h, 86h, 5h, 0eeh, 0eh, 0c6h, 0e9h, 6bh, 59h 
  PROCESSOR_PERF_BOOST_POLICY_DISABLED equ 0
  PROCESSOR_PERF_BOOST_POLICY_MAX equ 100
  DEFINE_GUID GUID_PROCESSOR_PERF_BOOST_MODE, 0be337238h, 0d82h, 4146h, 0a9h, 60h, 4fh, 37h, 49h, 0d4h, 70h, 0c7h 
  PROCESSOR_PERF_BOOST_MODE_DISABLED equ 0
  PROCESSOR_PERF_BOOST_MODE_ENABLED equ 1
  PROCESSOR_PERF_BOOST_MODE_AGGRESSIVE equ 2
  PROCESSOR_PERF_BOOST_MODE_EFFICIENT_ENABLED equ 3
  PROCESSOR_PERF_BOOST_MODE_EFFICIENT_AGGRESSIVE equ 4
  PROCESSOR_PERF_BOOST_MODE_AGGRESSIVE_AT_GUARANTEED equ 5
  PROCESSOR_PERF_BOOST_MODE_EFFICIENT_AGGRESSIVE_AT_GUARANTEED equ 6
  PROCESSOR_PERF_BOOST_MODE_MAX equ <PROCESSOR_PERF_BOOST_MODE_EFFICIENT_AGGRESSIVE_AT_GUARANTEED>
  DEFINE_GUID GUID_PROCESSOR_PERF_AUTONOMOUS_MODE, 8baa4a8ah, 14c6h, 4451h, 8eh, 8bh, 14h, 0bdh, 0bdh, 19h, 75h, 37h 
  PROCESSOR_PERF_AUTONOMOUS_MODE_DISABLED equ 0
  PROCESSOR_PERF_AUTONOMOUS_MODE_ENABLED equ 1
  DEFINE_GUID GUID_PROCESSOR_PERF_ENERGY_PERFORMANCE_PREFERENCE, 36687f9eh, 0e3a5h, 4dbfh, 0b1h, 0dch, 15h, 0ebh, 38h, 1ch, 68h, 63h 
  PROCESSOR_PERF_PERFORMANCE_PREFERENCE equ 0ffh
  PROCESSOR_PERF_ENERGY_PREFERENCE equ 0
  DEFINE_GUID GUID_PROCESSOR_PERF_AUTONOMOUS_ACTIVITY_WINDOW, 0cfeda3d0h, 7697h, 4566h, 0a9h, 22h, 0a9h, 8h, 6ch, 0d4h, 9dh, 0fah 
  PROCESSOR_PERF_MINIMUM_ACTIVITY_WINDOW equ 0
  PROCESSOR_PERF_MAXIMUM_ACTIVITY_WINDOW equ 1270000000
  DEFINE_GUID GUID_PROCESSOR_DUTY_CYCLING, 4e4450b3h, 6179h, 4e91h, 0b8h, 0f1h, 5bh, 0b9h, 93h, 8fh, 81h, 0a1h 
  PROCESSOR_DUTY_CYCLING_DISABLED equ 0
  PROCESSOR_DUTY_CYCLING_ENABLED equ 1
  DEFINE_GUID GUID_PROCESSOR_IDLE_ALLOW_SCALING, 6c2993b0h, 8f48h, 481fh, 0bch, 0c6h, 0h, 0ddh, 27h, 42h, 0aah, 6h 
  DEFINE_GUID GUID_PROCESSOR_IDLE_DISABLE, 5d76a2cah, 0e8c0h, 402fh, 0a1h, 33h, 21h, 58h, 49h, 2dh, 58h, 0adh 
  DEFINE_GUID GUID_PROCESSOR_IDLE_STATE_MAXIMUM, 9943e905h, 9a30h, 4ec1h, 9bh, 99h, 44h, 0ddh, 3bh, 76h, 0f7h, 0a2h 
  DEFINE_GUID GUID_PROCESSOR_IDLE_TIME_CHECK, 0c4581c31h, 89abh, 4597h, 8eh, 2bh, 9ch, 9ch, 0abh, 44h, 0eh, 6bh 
  DEFINE_GUID GUID_PROCESSOR_IDLE_DEMOTE_THRESHOLD, 4b92d758h, 5a24h, 4851h, 0a4h, 70h, 81h, 5dh, 78h, 0aeh, 0e1h, 19h 
  DEFINE_GUID GUID_PROCESSOR_IDLE_PROMOTE_THRESHOLD, 7b224883h, 0b3cch, 4d79h, 81h, 9fh, 83h, 74h, 15h, 2ch, 0beh, 7ch 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_INCREASE_THRESHOLD, 0df142941h, 20f3h, 4edfh, 9ah, 4ah, 9ch, 83h, 0d3h, 0d7h, 17h, 0d1h 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_DECREASE_THRESHOLD, 68dd2f27h, 0a4ceh, 4e11h, 84h, 87h, 37h, 94h, 0e4h, 13h, 5dh, 0fah 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_INCREASE_POLICY, 0c7be0679h, 2817h, 4d69h, 9dh, 02h, 51h, 9ah, 53h, 7eh, 0d0h, 0c6h 
  CORE_PARKING_POLICY_CHANGE_IDEAL equ 0
  CORE_PARKING_POLICY_CHANGE_SINGLE equ 1
  CORE_PARKING_POLICY_CHANGE_ROCKET equ 2
  CORE_PARKING_POLICY_CHANGE_MULTISTEP equ 3
  CORE_PARKING_POLICY_CHANGE_MAX equ <CORE_PARKING_POLICY_CHANGE_MULTISTEP>
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_DECREASE_POLICY, 71021b41h, 0c749h, 4d21h, 0beh, 74h, 0a0h, 0fh, 33h, 5dh, 58h, 2bh 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_MAX_CORES, 0ea062031h, 0e34h, 4ff1h, 9bh, 6dh, 0ebh, 10h, 59h, 33h, 40h, 28h 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_MAX_CORES_1, 0ea062031h, 0e34h, 4ff1h, 9bh, 6dh, 0ebh, 10h, 59h, 33h, 40h, 29h 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_MIN_CORES, 0cc5b647h, 0c1dfh, 4637h, 89h, 1ah, 0deh, 0c3h, 5ch, 31h, 85h, 83h 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_MIN_CORES_1, 0cc5b647h, 0c1dfh, 4637h, 89h, 1ah, 0deh, 0c3h, 5ch, 31h, 85h, 84h 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_INCREASE_TIME, 2ddd5a84h, 5a71h, 437eh, 91h, 2ah, 0dbh, 0bh, 8ch, 78h, 87h, 32h 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_DECREASE_TIME, 0dfd10d17h, 0d5ebh, 45ddh, 87h, 7ah, 9ah, 34h, 0ddh, 0d1h, 5ch, 82h 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_DECREASE_FACTOR, 8f7b45e3h, 0c393h, 480ah, 87h, 8ch, 0f6h, 7ah, 0c3h, 0d0h, 70h, 82h 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_THRESHOLD, 5b33697bh, 0e89dh, 4d38h, 0aah, 46h, 9eh, 7dh, 0fbh, 7ch, 0d2h, 0f9h 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_AFFINITY_WEIGHTING, 0e70867f1h, 0fa2fh, 4f4eh, 0aeh, 0a1h, 4dh, 8ah, 0bh, 0a2h, 3bh, 20h 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_DECREASE_FACTOR, 1299023ch, 0bc28h, 4f0ah, 81h, 0ech, 0d3h, 29h, 5ah, 8dh, 81h, 5dh 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_THRESHOLD, 9ac18e92h, 0aa3ch, 4e27h, 0b3h, 07h, 01h, 0aeh, 37h, 30h, 71h, 29h 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_WEIGHTING, 8809c2d8h, 0b155h, 42d4h, 0bch, 0dah, 0dh, 34h, 56h, 51h, 0b1h, 0dbh 
  DEFINE_GUID GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_THRESHOLD, 943c8cb6h, 6f93h, 4227h, 0adh, 87h, 0e9h, 0a3h, 0feh, 0ech, 08h, 0d1h 
  DEFINE_GUID GUID_PROCESSOR_PARKING_CORE_OVERRIDE, 0a55612aah, 0f624h, 42c6h, 0a4h, 43h, 73h, 97h, 0d0h, 64h, 0c0h, 4fh 
  DEFINE_GUID GUID_PROCESSOR_PARKING_PERF_STATE, 447235c7h, 6a8dh, 4cc0h, 8eh, 24h, 9eh, 0afh, 70h, 0b9h, 6eh, 2bh 
  DEFINE_GUID GUID_PROCESSOR_PARKING_PERF_STATE_1, 447235c7h, 6a8dh, 4cc0h, 8eh, 24h, 9eh, 0afh, 70h, 0b9h, 6eh, 2ch 
  DEFINE_GUID GUID_PROCESSOR_PARKING_CONCURRENCY_THRESHOLD, 2430ab6fh, 0a520h, 44a2h, 96h, 01h, 0f7h, 0f2h, 3bh, 51h, 34h, 0b1h 
  DEFINE_GUID GUID_PROCESSOR_PARKING_HEADROOM_THRESHOLD, 0f735a673h, 2066h, 4f80h, 0a0h, 0c5h, 0ddh, 0eeh, 0ch, 0f1h, 0bfh, 5dh 
  DEFINE_GUID GUID_PROCESSOR_PARKING_DISTRIBUTION_THRESHOLD, 4bdaf4e9h, 0d103h, 46d7h, 0a5h, 0f0h, 62h, 80h, 12h, 16h, 16h, 0efh 
  DEFINE_GUID GUID_PROCESSOR_PERF_HISTORY, 7d24baa7h, 0b84h, 480fh, 84h, 0ch, 1bh, 07h, 43h, 0c0h, 0fh, 5fh 
  DEFINE_GUID GUID_PROCESSOR_PERF_HISTORY_1, 7d24baa7h, 0b84h, 480fh, 84h, 0ch, 1bh, 07h, 43h, 0c0h, 0fh, 60h 
  DEFINE_GUID GUID_PROCESSOR_PERF_INCREASE_HISTORY, 99b3ef01h, 752fh, 46a1h, 80h, 0fbh, 77h, 30h, 1h, 1fh, 23h, 54h 
  DEFINE_GUID GUID_PROCESSOR_PERF_DECREASE_HISTORY, 300f6f8h, 0abd6h, 45a9h, 0b7h, 4fh, 49h, 8h, 69h, 1ah, 40h, 0b5h 
  DEFINE_GUID GUID_PROCESSOR_PERF_CORE_PARKING_HISTORY, 77d7f282h, 8f1ah, 42cdh, 85h, 37h, 45h, 45h, 0ah, 83h, 9bh, 0e8h 
  DEFINE_GUID GUID_PROCESSOR_PERF_LATENCY_HINT, 0822df31h, 9c83h, 441ch, 0a0h, 79h, 0dh, 0e4h, 0cfh, 00h, 9ch, 7bh 
  DEFINE_GUID GUID_PROCESSOR_PERF_LATENCY_HINT_PERF, 619b7505h, 3bh, 4e82h, 0b7h, 0a6h, 4dh, 0d2h, 9ch, 30h, 9h, 71h 
  DEFINE_GUID GUID_PROCESSOR_PERF_LATENCY_HINT_PERF_1, 619b7505h, 3bh, 4e82h, 0b7h, 0a6h, 4dh, 0d2h, 9ch, 30h, 9h, 72h 
  DEFINE_GUID GUID_PROCESSOR_LATENCY_HINT_MIN_UNPARK, 616cdaa5h, 695eh, 4545h, 97h, 0adh, 97h, 0dch, 2dh, 1bh, 0ddh, 88h 
  DEFINE_GUID GUID_PROCESSOR_LATENCY_HINT_MIN_UNPARK_1, 616cdaa5h, 695eh, 4545h, 97h, 0adh, 97h, 0dch, 2dh, 1bh, 0ddh, 89h 
  DEFINE_GUID GUID_PROCESSOR_DISTRIBUTE_UTILITY, 0e0007330h, 0f589h, 42edh, 0a4h, 01h, 5dh, 0dbh, 10h, 0e7h, 85h, 0d3h 
  DEFINE_GUID GUID_PROCESSOR_HETEROGENEOUS_POLICY, 7f2f5cfah, 0f10ch, 4823h, 0b5h, 0e1h, 0e9h, 3ah, 0e8h, 5fh, 46h, 0b5h 
  DEFINE_GUID GUID_PROCESSOR_HETERO_DECREASE_TIME, 7f2492b6h, 60b1h, 45e5h, 0aeh, 55h, 77h, 3fh, 8ch, 0d5h, 0cah, 0ech 
  DEFINE_GUID GUID_PROCESSOR_HETERO_INCREASE_TIME, 4009efa7h, 0e72dh, 4cbah, 9eh, 0dfh, 91h, 08h, 4eh, 0a8h, 0cbh, 0c3h 
  DEFINE_GUID GUID_PROCESSOR_HETERO_DECREASE_THRESHOLD, 0f8861c27h, 95e7h, 475ch, 86h, 5bh, 13h, 0c0h, 0cbh, 3fh, 9dh, 6bh 
  DEFINE_GUID GUID_PROCESSOR_HETERO_INCREASE_THRESHOLD, 0b000397dh, 9b0bh, 483dh, 98h, 0c9h, 69h, 2ah, 60h, 60h, 0cfh, 0bfh 
  DEFINE_GUID GUID_PROCESSOR_CLASS0_FLOOR_PERF, 0fddc842bh, 8364h, 4edch, 94h, 0cfh, 0c1h, 7fh, 60h, 0deh, 1ch, 80h 
  DEFINE_GUID GUID_PROCESSOR_CLASS1_INITIAL_PERF, 1facfc65h, 0a930h, 4bc5h, 9fh, 38h, 50h, 4eh, 0c0h, 97h, 0bbh, 0c0h 
  DEFINE_GUID GUID_PROCESSOR_THREAD_SCHEDULING_POLICY, 93b8b6dch, 698h, 4d1ch, 9eh, 0e4h, 6h, 44h, 0e9h, 0h, 0c8h, 5dh 
  DEFINE_GUID GUID_PROCESSOR_SHORT_THREAD_SCHEDULING_POLICY, 0bae08b81h, 2d5eh, 4688h, 0adh, 6ah, 13h, 24h, 33h, 56h, 65h, 4bh 
  DEFINE_GUID GUID_SYSTEM_COOLING_POLICY, 94D3A615h, 0A899h, 4AC5h, 0AEh, 2Bh, 0E4h, 0D8h, 0F6h, 34h, 36h, 7Fh 
  DEFINE_GUID GUID_LOCK_CONSOLE_ON_WAKE, 0E796BDBh, 100Dh, 47D6h, 0A2h, 0D5h, 0F7h, 0D2h, 0DAh, 0A5h, 1Fh, 51h 
  DEFINE_GUID GUID_DEVICE_IDLE_POLICY, 4faab71ah, 92e5h, 4726h, 0b5h, 31h, 22h, 45h, 59h, 67h, 2dh, 19h 
  POWER_DEVICE_IDLE_POLICY_PERFORMANCE equ 0
  POWER_DEVICE_IDLE_POLICY_CONSERVATIVE equ 1
  DEFINE_GUID GUID_CONNECTIVITY_IN_STANDBY, 0F15576E8h, 98B7h, 4186h, 0B9h, 44h, 0EAh, 0FAh, 66h, 44h, 02h, 0D9h 
  POWER_CONNECTIVITY_IN_STANDBY_DISABLED equ 0
  POWER_CONNECTIVITY_IN_STANDBY_ENABLED equ 1
  POWER_CONNECTIVITY_IN_STANDBY_SYSTEM_MANAGED equ 2
  DEFINE_GUID GUID_DISCONNECTED_STANDBY_MODE, 68AFB2D9h, 0EE95h, 47A8h, 8Fh, 50h, 41h, 15h, 08h, 80h, 73h, 0B1h 
  POWER_DISCONNECTED_STANDBY_MODE_NORMAL equ 0
  POWER_DISCONNECTED_STANDBY_MODE_AGGRESSIVE equ 1
  DEFINE_GUID GUID_ACDC_POWER_SOURCE, 5D3E9A59h, 0E9D5h, 4B00h, 0A6h, 0BDh, 0FFh, 34h, 0FFh, 51h, 65h, 48h 
  DEFINE_GUID GUID_LIDSWITCH_STATE_CHANGE, 0BA3E0F4Dh, 0B817h, 4094h, 0A2h, 0D1h, 0D5h, 63h, 79h, 0E6h, 0A0h, 0F3h 
  DEFINE_GUID GUID_BATTERY_PERCENTAGE_REMAINING, 0A7AD8041h, 0B45Ah, 4CAEh, 87h, 0A3h, 0EEh, 0CBh, 0B4h, 68h, 0A9h, 0E1h 
  DEFINE_GUID GUID_BATTERY_COUNT, 7d263f15h, 0fca4h, 49e5h, 85h, 4bh, 0a9h, 0f2h, 0bfh, 0bdh, 5ch, 24h 
  DEFINE_GUID GUID_GLOBAL_USER_PRESENCE, 786e8a1dh, 0b427h, 4344h, 92h, 7h, 9h, 0e7h, 0bh, 0dch, 0beh, 0a9h 
  DEFINE_GUID GUID_SESSION_DISPLAY_STATUS, 2b84c20eh, 0ad23h, 4ddfh, 93h, 0dbh, 5h, 0ffh, 0bdh, 7eh, 0fch, 0a5h 
  DEFINE_GUID GUID_SESSION_USER_PRESENCE, 3c0f4548h, 0c03fh, 4c4dh, 0b9h, 0f2h, 23h, 7eh, 0deh, 68h, 63h, 76h 
  DEFINE_GUID GUID_IDLE_BACKGROUND_TASK, 515C31D8h, 0F734h, 163Dh, 0A0h, 0FDh, 11h, 0A0h, 8Ch, 91h, 0E8h, 0F1h 
  DEFINE_GUID GUID_BACKGROUND_TASK_NOTIFICATION, 0CF23F240h, 2A54h, 48D8h, 0B1h, 14h, 0DEh, 15h, 18h, 0FFh, 05h, 2Eh 
  DEFINE_GUID GUID_APPLAUNCH_BUTTON, 1A689231h, 7399h, 4E9Ah, 8Fh, 99h, 0B7h, 1Fh, 99h, 9Dh, 0B3h, 0FAh 
  DEFINE_GUID GUID_PCIEXPRESS_SETTINGS_SUBGROUP, 501a4d13h, 42afh, 4429h, 9fh, 0d1h, 0a8h, 21h, 8ch, 26h, 8eh, 20h 
  DEFINE_GUID GUID_PCIEXPRESS_ASPM_POLICY, 0ee12f906h, 0d277h, 404bh, 0b6h, 0dah, 0e5h, 0fah, 1ah, 57h, 6dh, 0f5h 
  DEFINE_GUID GUID_ENABLE_SWITCH_FORCED_SHUTDOWN, 833a6b62h, 0dfa4h, 46d1h, 82h, 0f8h, 0e0h, 9eh, 34h, 0d0h, 29h, 0d6h 
  DEFINE_GUID GUID_INTSTEER_SUBGROUP, 48672f38h, 7a9ah, 4bb2h, 8bh, 0f8h, 3dh, 85h, 0beh, 19h, 0deh, 4eh 
  DEFINE_GUID GUID_INTSTEER_MODE, 2bfc24f9h, 5ea2h, 4801h, 82h, 13h, 3dh, 0bah, 0e0h, 1ah, 0a3h, 9dh 
  DEFINE_GUID GUID_INTSTEER_LOAD_PER_PROC_TRIGGER, 73cde64dh, 0d720h, 4bb2h, 0a8h, 60h, 0c7h, 55h, 0afh, 0e7h, 7eh, 0f2h 
  DEFINE_GUID GUID_INTSTEER_TIME_UNPARK_TRIGGER, 0d6ba4903h, 386fh, 4c2ch, 8ah, 0dbh, 5ch, 21h, 0b3h, 32h, 8dh, 25h 
  DEFINE_GUID GUID_GRAPHICS_SUBGROUP, 5fb4938dh, 1ee8h, 4b0fh, 9ah, 3ch, 50h, 36h, 0b0h, 0abh, 99h, 5ch 
  DEFINE_GUID GUID_GPU_PREFERENCE_POLICY, 0dd848b2ah, 8a5dh, 4451h, 9ah, 0e2h, 39h, 0cdh, 41h, 65h, 8fh, 6ch 
  DEFINE_GUID GUID_MIXED_REALITY_MODE, 1e626b4eh, 0cf04h, 4f8dh, 9ch, 0c7h, 0c9h, 7ch, 5bh, 0fh, 23h, 91h 
  DEFINE_GUID GUID_SPR_ACTIVE_SESSION_CHANGE, 0e24ce38h, 0c393h, 4742h, 0bdh, 0b1h, 74h, 4fh, 4bh, 9eh, 0e0h, 8eh 
  ifndef _PO_DDK_
    _PO_DDK_ equ <>
    SYSTEM_POWER_STATE typedef SDWORD
    PowerSystemUnspecified EQU 0 
    PowerSystemWorking EQU 1 
    PowerSystemSleeping1 EQU 2 
    PowerSystemSleeping2 EQU 3 
    PowerSystemSleeping3 EQU 4 
    PowerSystemHibernate EQU 5 
    PowerSystemShutdown EQU 6 
    PowerSystemMaximum EQU 7 
    
    PSYSTEM_POWER_STATE typedef ptr SYSTEM_POWER_STATE
    
    POWER_SYSTEM_MAXIMUM equ 7
    POWER_ACTION typedef SDWORD
    PowerActionNone EQU 0 
    PowerActionReserved EQU 1
    PowerActionSleep EQU 2
    PowerActionHibernate EQU 3
    PowerActionShutdown EQU 4
    PowerActionShutdownReset EQU 5
    PowerActionShutdownOff EQU 6
    PowerActionWarmEject EQU 7
    PowerActionDisplayOff EQU 8
    
    PPOWER_ACTION typedef ptr POWER_ACTION
    
    DEVICE_POWER_STATE typedef SDWORD
    PowerDeviceUnspecified EQU 0 
    PowerDeviceD0 EQU 1
    PowerDeviceD1 EQU 2
    PowerDeviceD2 EQU 3
    PowerDeviceD3 EQU 4
    PowerDeviceMaximum EQU 5
    
    PDEVICE_POWER_STATE typedef ptr DEVICE_POWER_STATE
    
    MONITOR_DISPLAY_STATE typedef SDWORD
    PowerMonitorOff EQU 0 
    PowerMonitorOn EQU 1
    PowerMonitorDim EQU 2
    
    PMONITOR_DISPLAY_STATE typedef ptr MONITOR_DISPLAY_STATE
    
    USER_ACTIVITY_PRESENCE typedef SDWORD
    PowerUserPresent EQU 0 
    PowerUserNotPresent EQU 1
    PowerUserInactive EQU 2
    PowerUserMaximum EQU 3
    PowerUserInvalid EQU PowerUserMaximum 
    
    PUSER_ACTIVITY_PRESENCE typedef ptr USER_ACTIVITY_PRESENCE
    
    POWER_STATE union
      SystemState SYSTEM_POWER_STATE ?
      DeviceState DEVICE_POWER_STATE ?
    POWER_STATE ends

    PPOWER_STATE typedef ptr POWER_STATE
    
    POWER_STATE_TYPE typedef SDWORD
    SystemPowerState EQU 0 
    DevicePowerState EQU 1
    
    PPOWER_STATE_TYPE typedef ptr POWER_STATE_TYPE
    

      SYSTEM_POWER_STATE_CONTEXT struct
        union DUMMYUNIONNAME_2
          struct DUMMYSTRUCTNAME_3
            DUMMYSTRUCTNAME_3_??3 record Reserved1_??3:8, TargetSystemState_??3:4, EffectiveSystemState_??3:4, CurrentSystemState_??3:4, IgnoreHibernationPath_??3:1, PseudoTransition_??3:1, KernelSoftReboot_??3:1, Reserved2_??3:9
            DUMMYSTRUCTNAME_3_??3 <>
          ends
          ContextAsUlong DWORD ?
        ends
      SYSTEM_POWER_STATE_CONTEXT ends

      PSYSTEM_POWER_STATE_CONTEXT typedef ptr SYSTEM_POWER_STATE_CONTEXT


      COUNTED_REASON_CONTEXT struct
        Version DWORD ?
        Flags DWORD ?
        union DUMMYUNIONNAME_4
          struct DUMMYSTRUCTNAME_5
            ResourceFileName UNICODE_STRING <>
            ResourceReasonId WORD ?
            StringCount DWORD ?
            ReasonStrings PUNICODE_STRING ?
          ends
          SimpleString UNICODE_STRING <>
        ends
      COUNTED_REASON_CONTEXT ends

      PCOUNTED_REASON_CONTEXT typedef ptr COUNTED_REASON_CONTEXT

    IOCTL_QUERY_DEVICE_POWER_STATE equ CTL_CODE ( FILE_DEVICE_BATTERY , 0h , METHOD_BUFFERED , FILE_READ_ACCESS )
    IOCTL_SET_DEVICE_WAKE equ CTL_CODE ( FILE_DEVICE_BATTERY , 1h , METHOD_BUFFERED , FILE_WRITE_ACCESS )
    IOCTL_CANCEL_DEVICE_WAKE equ CTL_CODE ( FILE_DEVICE_BATTERY , 2h , METHOD_BUFFERED , FILE_WRITE_ACCESS )
    ES_SYSTEM_REQUIRED equ 00000001h
    ES_DISPLAY_REQUIRED equ 00000002h
    ES_USER_PRESENT equ 00000004h
    ES_AWAYMODE_REQUIRED equ 00000040h
    ES_CONTINUOUS equ 80000000h
    EXECUTION_STATE typedef DWORD
    PEXECUTION_STATE typedef ptr DWORD
    LATENCY_TIME typedef SDWORD
    LT_DONT_CARE EQU 0
    LT_LOWEST_LATENCY EQU 1
    
    DIAGNOSTIC_REASON_VERSION equ 0
    DIAGNOSTIC_REASON_SIMPLE_STRING equ 00000001h
    DIAGNOSTIC_REASON_DETAILED_STRING equ 00000002h
    DIAGNOSTIC_REASON_NOT_SPECIFIED equ 80000000h
    DIAGNOSTIC_REASON_INVALID_FLAGS equ ( not 80000007h )
    POWER_REQUEST_CONTEXT_VERSION equ <DIAGNOSTIC_REASON_VERSION>
    POWER_REQUEST_CONTEXT_SIMPLE_STRING equ <DIAGNOSTIC_REASON_SIMPLE_STRING>
    POWER_REQUEST_CONTEXT_DETAILED_STRING equ <DIAGNOSTIC_REASON_DETAILED_STRING>
    POWER_REQUEST_TYPE typedef SDWORD
    PowerRequestDisplayRequired EQU 0
    PowerRequestSystemRequired EQU 1
    PowerRequestAwayModeRequired EQU 2
    PowerRequestExecutionRequired EQU 3
    
    PPOWER_REQUEST_TYPE typedef ptr POWER_REQUEST_TYPE

      PDCAP_D0_SUPPORTED equ 00000001h
      PDCAP_D1_SUPPORTED equ 00000002h
      PDCAP_D2_SUPPORTED equ 00000004h
      PDCAP_D3_SUPPORTED equ 00000008h
      PDCAP_WAKE_FROM_D0_SUPPORTED equ 00000010h
      PDCAP_WAKE_FROM_D1_SUPPORTED equ 00000020h
      PDCAP_WAKE_FROM_D2_SUPPORTED equ 00000040h
      PDCAP_WAKE_FROM_D3_SUPPORTED equ 00000080h
      PDCAP_WARM_EJECT_SUPPORTED equ 00000100h
      CM_POWER_DATA struct
        PD_Size DWORD ?
        PD_MostRecentPowerState DEVICE_POWER_STATE ?
        PD_Capabilities DWORD ?
        PD_D1Latency DWORD ?
        PD_D2Latency DWORD ?
        PD_D3Latency DWORD ?
        PD_PowerStateMapping DEVICE_POWER_STATE POWER_SYSTEM_MAXIMUM dup (?)
        PD_DeepestSystemWake SYSTEM_POWER_STATE ?
      CM_POWER_DATA ends

      PCM_POWER_DATA typedef ptr CM_POWER_DATA

    POWER_INFORMATION_LEVEL typedef SDWORD
    SystemPowerPolicyAc EQU 0
    SystemPowerPolicyDc EQU 1
    VerifySystemPolicyAc EQU 2
    VerifySystemPolicyDc EQU 3
    SystemPowerCapabilities EQU 4
    SystemBatteryState EQU 5
    SystemPowerStateHandler EQU 6
    ProcessorStateHandler EQU 7
    SystemPowerPolicyCurrent EQU 8
    AdministratorPowerPolicy EQU 9
    SystemReserveHiberFile EQU 10
    ProcessorInformation EQU 11
    SystemPowerInformation EQU 12
    ProcessorStateHandler2 EQU 13
    LastWakeTime EQU 14
    LastSleepTime EQU 15
    SystemExecutionState EQU 16
    SystemPowerStateNotifyHandler EQU 17
    ProcessorPowerPolicyAc EQU 18
    ProcessorPowerPolicyDc EQU 19
    VerifyProcessorPowerPolicyAc EQU 20
    VerifyProcessorPowerPolicyDc EQU 21
    ProcessorPowerPolicyCurrent EQU 22
    SystemPowerStateLogging EQU 23
    SystemPowerLoggingEntry EQU 24
    SetPowerSettingValue EQU 25
    NotifyUserPowerSetting EQU 26
    PowerInformationLevelUnused0 EQU 27
    SystemMonitorHiberBootPowerOff EQU 28
    SystemVideoState EQU 29
    TraceApplicationPowerMessage EQU 30
    TraceApplicationPowerMessageEnd EQU 31
    ProcessorPerfStates EQU 32
    ProcessorIdleStates EQU 33
    ProcessorCap EQU 34
    SystemWakeSource EQU 35
    SystemHiberFileInformation EQU 36
    TraceServicePowerMessage EQU 37
    ProcessorLoad EQU 38
    PowerShutdownNotification EQU 39
    MonitorCapabilities EQU 40
    SessionPowerInit EQU 41
    SessionDisplayState EQU 42
    PowerRequestCreate EQU 43
    PowerRequestAction EQU 44
    GetPowerRequestList EQU 45
    ProcessorInformationEx EQU 46
    NotifyUserModeLegacyPowerEvent EQU 47
    GroupPark EQU 48
    ProcessorIdleDomains EQU 49
    WakeTimerList EQU 50
    SystemHiberFileSize EQU 51
    ProcessorIdleStatesHv EQU 52
    ProcessorPerfStatesHv EQU 53
    ProcessorPerfCapHv EQU 54
    ProcessorSetIdle EQU 55
    LogicalProcessorIdling EQU 56
    UserPresence EQU 57
    PowerSettingNotificationName EQU 58
    GetPowerSettingValue EQU 59
    IdleResiliency EQU 60
    SessionRITState EQU 61
    SessionConnectNotification EQU 62
    SessionPowerCleanup EQU 63
    SessionLockState EQU 64
    SystemHiberbootState EQU 65
    PlatformInformation EQU 66
    PdcInvocation EQU 67
    MonitorInvocation EQU 68
    FirmwareTableInformationRegistered EQU 69
    SetShutdownSelectedTime EQU 70
    SuspendResumeInvocation EQU 71
    PlmPowerRequestCreate EQU 72
    ScreenOff EQU 73
    CsDeviceNotification EQU 74
    PlatformRole EQU 75
    LastResumePerformance EQU 76
    DisplayBurst EQU 77
    ExitLatencySamplingPercentage EQU 78
    RegisterSpmPowerSettings EQU 79
    PlatformIdleStates EQU 80
    ProcessorIdleVeto EQU 81
    PlatformIdleVeto EQU 82
    SystemBatteryStatePrecise EQU 83
    ThermalEvent EQU 84
    PowerRequestActionInternal EQU 85
    BatteryDeviceState EQU 86
    PowerInformationInternal EQU 87
    ThermalStandby EQU 88
    SystemHiberFileType EQU 89
    PhysicalPowerButtonPress EQU 90
    QueryPotentialDripsConstraint EQU 91
    EnergyTrackerCreate EQU 92
    EnergyTrackerQuery EQU 93
    UpdateBlackBoxRecorder EQU 94
    PowerInformationLevelMaximum EQU 95
    
    POWER_USER_PRESENCE_TYPE typedef SDWORD
    UserNotPresent EQU 0 
    UserPresent EQU 1 
    UserUnknown EQU 0ffh 
    
    PPOWER_USER_PRESENCE_TYPE typedef ptr POWER_USER_PRESENCE_TYPE
    
    POWER_USER_PRESENCE struct
      UserPresence POWER_USER_PRESENCE_TYPE ?
    POWER_USER_PRESENCE ends

    PPOWER_USER_PRESENCE typedef ptr POWER_USER_PRESENCE
    
    POWER_SESSION_CONNECT struct
      Connected BOOLEAN ?
      Console BOOLEAN ?
    POWER_SESSION_CONNECT ends

    PPOWER_SESSION_CONNECT typedef ptr POWER_SESSION_CONNECT
    
    POWER_SESSION_TIMEOUTS struct
      InputTimeout DWORD ?
      DisplayTimeout DWORD ?
    POWER_SESSION_TIMEOUTS ends

    PPOWER_SESSION_TIMEOUTS typedef ptr POWER_SESSION_TIMEOUTS
    
    POWER_SESSION_RIT_STATE struct
      Active BOOLEAN ?
      LastInputTime DWORD ?
    POWER_SESSION_RIT_STATE ends

    PPOWER_SESSION_RIT_STATE typedef ptr POWER_SESSION_RIT_STATE
    
    POWER_SESSION_WINLOGON struct
      SessionId DWORD ?
      Console BOOLEAN ?
      Locked BOOLEAN ?
    POWER_SESSION_WINLOGON ends

    PPOWER_SESSION_WINLOGON typedef ptr POWER_SESSION_WINLOGON
    
    POWER_IDLE_RESILIENCY struct
      CoalescingTimeout DWORD ?
      IdleResiliencyPeriod DWORD ?
    POWER_IDLE_RESILIENCY ends

    PPOWER_IDLE_RESILIENCY typedef ptr POWER_IDLE_RESILIENCY
    
    POWER_MONITOR_REQUEST_REASON typedef SDWORD
    MonitorRequestReasonUnknown EQU 0
    MonitorRequestReasonPowerButton EQU 1
    MonitorRequestReasonRemoteConnection EQU 2
    MonitorRequestReasonScMonitorpower EQU 3
    MonitorRequestReasonUserInput EQU 4
    MonitorRequestReasonAcDcDisplayBurst EQU 5
    MonitorRequestReasonUserDisplayBurst EQU 6
    MonitorRequestReasonPoSetSystemState EQU 7
    MonitorRequestReasonSetThreadExecutionState EQU 8
    MonitorRequestReasonFullWake EQU 9
    MonitorRequestReasonSessionUnlock EQU 10
    MonitorRequestReasonScreenOffRequest EQU 11
    MonitorRequestReasonIdleTimeout EQU 12
    MonitorRequestReasonPolicyChange EQU 13
    MonitorRequestReasonSleepButton EQU 14
    MonitorRequestReasonLid EQU 15
    MonitorRequestReasonBatteryCountChange EQU 16
    MonitorRequestReasonGracePeriod EQU 17
    MonitorRequestReasonPnP EQU 18
    MonitorRequestReasonDP EQU 19
    MonitorRequestReasonSxTransition EQU 20
    MonitorRequestReasonSystemIdle EQU 21
    MonitorRequestReasonNearProximity EQU 22
    MonitorRequestReasonThermalStandby EQU 23
    MonitorRequestReasonResumePdc EQU 24
    MonitorRequestReasonResumeS4 EQU 25
    MonitorRequestReasonTerminal EQU 26
    MonitorRequestReasonPdcSignal EQU 27
    MonitorRequestReasonAcDcDisplayBurstSuppressed EQU 28
    MonitorRequestReasonSystemStateEntered EQU 29
    MonitorRequestReasonWinrt EQU 30
    MonitorRequestReasonUserInputKeyboard EQU 31
    MonitorRequestReasonUserInputMouse EQU 32
    MonitorRequestReasonUserInputTouch EQU 33
    MonitorRequestReasonUserInputPen EQU 34
    MonitorRequestReasonUserInputAccelerometer EQU 35
    MonitorRequestReasonUserInputHid EQU 36
    MonitorRequestReasonUserInputPoUserPresent EQU 37
    MonitorRequestReasonUserInputSessionSwitch EQU 38
    MonitorRequestReasonUserInputInitialization EQU 39
    MonitorRequestReasonPdcSignalWindowsMobilePwrNotif EQU 40
    MonitorRequestReasonPdcSignalWindowsMobileShell EQU 41
    MonitorRequestReasonPdcSignalHeyCortana EQU 42
    MonitorRequestReasonPdcSignalHolographicShell EQU 43
    MonitorRequestReasonPdcSignalFingerprint EQU 44
    MonitorRequestReasonMax EQU 45
    
    POWER_MONITOR_REQUEST_TYPE typedef SDWORD
    MonitorRequestTypeOff EQU 0
    MonitorRequestTypeOnAndPresent EQU 1
    MonitorRequestTypeToggleOn EQU 2
    
    POWER_MONITOR_INVOCATION struct
      Console BOOLEAN ?
      RequestReason POWER_MONITOR_REQUEST_REASON ?
    POWER_MONITOR_INVOCATION ends

    PPOWER_MONITOR_INVOCATION typedef ptr POWER_MONITOR_INVOCATION
    
    RESUME_PERFORMANCE struct
      PostTimeMs DWORD ?
      TotalResumeTimeMs QWORD ?
      ResumeCompleteTimestamp QWORD ?
    RESUME_PERFORMANCE ends

    PRESUME_PERFORMANCE typedef ptr RESUME_PERFORMANCE
    
    SYSTEM_POWER_CONDITION typedef SDWORD
    PoAc EQU 0
    PoDc EQU 1
    PoHot EQU 2
    PoConditionMaximum EQU 3
    
    SET_POWER_SETTING_VALUE struct
      Version DWORD ?
      Guid GUID <>
      PowerCondition SYSTEM_POWER_CONDITION ?
      DataLength DWORD ?
      Data BYTE ANYSIZE_ARRAY dup (?)
    SET_POWER_SETTING_VALUE ends

    PSET_POWER_SETTING_VALUE typedef ptr SET_POWER_SETTING_VALUE
    
    POWER_SETTING_VALUE_VERSION equ 1h
    NOTIFY_USER_POWER_SETTING struct
      Guid GUID <>
    NOTIFY_USER_POWER_SETTING ends

    PNOTIFY_USER_POWER_SETTING typedef ptr NOTIFY_USER_POWER_SETTING
    
    APPLICATIONLAUNCH_SETTING_VALUE struct
      ActivationTime LARGE_INTEGER <>
      Flags DWORD ?
      ButtonInstanceID DWORD ?
    APPLICATIONLAUNCH_SETTING_VALUE ends

    PAPPLICATIONLAUNCH_SETTING_VALUE typedef ptr APPLICATIONLAUNCH_SETTING_VALUE
    
    POWER_PLATFORM_ROLE typedef SDWORD
    PlatformRoleUnspecified EQU 0 
    PlatformRoleDesktop EQU 1
    PlatformRoleMobile EQU 2
    PlatformRoleWorkstation EQU 3
    PlatformRoleEnterpriseServer EQU 4
    PlatformRoleSOHOServer EQU 5
    PlatformRoleAppliancePC EQU 6
    PlatformRolePerformanceServer EQU 7
    PlatformRoleSlate EQU 8
    PlatformRoleMaximum EQU 9
    
    PPOWER_PLATFORM_ROLE typedef ptr POWER_PLATFORM_ROLE
    
    POWER_PLATFORM_ROLE_V1 equ 00000001h
    POWER_PLATFORM_ROLE_V1_MAX equ ( PlatformRolePerformanceServer + 1 )
    POWER_PLATFORM_ROLE_V2 equ 00000002h
    POWER_PLATFORM_ROLE_V2_MAX equ ( PlatformRoleSlate + 1 )

      POWER_PLATFORM_ROLE_VERSION equ <POWER_PLATFORM_ROLE_V2>
      POWER_PLATFORM_ROLE_VERSION_MAX equ <POWER_PLATFORM_ROLE_V2_MAX>

    POWER_PLATFORM_INFORMATION struct
      AoAc BOOLEAN ?
    POWER_PLATFORM_INFORMATION ends

    PPOWER_PLATFORM_INFORMATION typedef ptr POWER_PLATFORM_INFORMATION

      BATTERY_REPORTING_SCALE struct
        Granularity DWORD ?
        Capacity DWORD ?
      BATTERY_REPORTING_SCALE ends

      PBATTERY_REPORTING_SCALE typedef ptr BATTERY_REPORTING_SCALE

  endif

  REG_NONE equ 0
  REG_SZ equ 1
  REG_EXPAND_SZ equ 2
  REG_BINARY equ 3
  REG_DWORD equ 4
  REG_DWORD_LITTLE_ENDIAN equ 4
  REG_DWORD_BIG_ENDIAN equ 5
  REG_LINK equ 6
  REG_MULTI_SZ equ 7
  REG_RESOURCE_LIST equ 8
  REG_FULL_RESOURCE_DESCRIPTOR equ 9
  REG_RESOURCE_REQUIREMENTS_LIST equ 10
  REG_QWORD equ 11
  REG_QWORD_LITTLE_ENDIAN equ 11
  SERVICE_KERNEL_DRIVER equ 00000001h
  SERVICE_FILE_SYSTEM_DRIVER equ 00000002h
  SERVICE_ADAPTER equ 00000004h
  SERVICE_RECOGNIZER_DRIVER equ 00000008h
  SERVICE_DRIVER equ <( SERVICE_KERNEL_DRIVER or SERVICE_FILE_SYSTEM_DRIVER or SERVICE_RECOGNIZER_DRIVER )>
  SERVICE_WIN32_OWN_PROCESS equ 00000010h
  SERVICE_WIN32_SHARE_PROCESS equ 00000020h
  SERVICE_WIN32 equ <( SERVICE_WIN32_OWN_PROCESS or SERVICE_WIN32_SHARE_PROCESS )>
  SERVICE_USER_SERVICE equ 00000040h
  SERVICE_USERSERVICE_INSTANCE equ 00000080h
  SERVICE_USER_SHARE_PROCESS equ <( SERVICE_USER_SERVICE or SERVICE_WIN32_SHARE_PROCESS )>
  SERVICE_USER_OWN_PROCESS equ <( SERVICE_USER_SERVICE or SERVICE_WIN32_OWN_PROCESS )>
  SERVICE_INTERACTIVE_PROCESS equ 00000100h
  SERVICE_PKG_SERVICE equ 00000200h
  SERVICE_TYPE_ALL equ <( SERVICE_WIN32 or SERVICE_ADAPTER or SERVICE_DRIVER or SERVICE_INTERACTIVE_PROCESS or SERVICE_USER_SERVICE or SERVICE_USERSERVICE_INSTANCE or SERVICE_PKG_SERVICE )>
  SERVICE_BOOT_START equ 00000000h
  SERVICE_SYSTEM_START equ 00000001h
  SERVICE_AUTO_START equ 00000002h
  SERVICE_DEMAND_START equ 00000003h
  SERVICE_DISABLED equ 00000004h
  SERVICE_ERROR_IGNORE equ 00000000h
  SERVICE_ERROR_NORMAL equ 00000001h
  SERVICE_ERROR_SEVERE equ 00000002h
  SERVICE_ERROR_CRITICAL equ 00000003h
  SERVICE_NODE_TYPE typedef SDWORD
  DriverType EQU SERVICE_KERNEL_DRIVER 
  FileSystemType EQU SERVICE_FILE_SYSTEM_DRIVER 
  Win32ServiceOwnProcess EQU SERVICE_WIN32_OWN_PROCESS 
  Win32ServiceShareProcess EQU SERVICE_WIN32_SHARE_PROCESS 
  AdapterType EQU SERVICE_ADAPTER 
  RecognizerType EQU SERVICE_RECOGNIZER_DRIVER 
  
  SERVICE_LOAD_TYPE typedef SDWORD
  BootLoad EQU SERVICE_BOOT_START 
  SystemLoad EQU SERVICE_SYSTEM_START 
  AutoLoad EQU SERVICE_AUTO_START 
  DemandLoad EQU SERVICE_DEMAND_START 
  DisableLoad EQU SERVICE_DISABLED 
  
  SERVICE_ERROR_TYPE typedef SDWORD
  IgnoreError EQU SERVICE_ERROR_IGNORE 
  NormalError EQU SERVICE_ERROR_NORMAL 
  SevereError EQU SERVICE_ERROR_SEVERE 
  CriticalError EQU SERVICE_ERROR_CRITICAL 
  
  CM_SERVICE_NETWORK_BOOT_LOAD equ 00000001h
  CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD equ 00000002h
  CM_SERVICE_USB_DISK_BOOT_LOAD equ 00000004h
  CM_SERVICE_SD_DISK_BOOT_LOAD equ 00000008h
  CM_SERVICE_USB3_DISK_BOOT_LOAD equ 00000010h
  CM_SERVICE_MEASURED_BOOT_LOAD equ 00000020h
  CM_SERVICE_VERIFIER_BOOT_LOAD equ 00000040h
  CM_SERVICE_WINPE_BOOT_LOAD equ 00000080h
  CM_SERVICE_VALID_PROMOTION_MASK equ <( CM_SERVICE_NETWORK_BOOT_LOAD or CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD or CM_SERVICE_USB_DISK_BOOT_LOAD or CM_SERVICE_SD_DISK_BOOT_LOAD or CM_SERVICE_USB3_DISK_BOOT_LOAD or CM_SERVICE_MEASURED_BOOT_LOAD or CM_SERVICE_VERIFIER_BOOT_LOAD or CM_SERVICE_WINPE_BOOT_LOAD )>
  
  
    CM_RESOURCE_TYPE typedef DWORD
    CmResourceTypeNull equ 0
    CmResourceTypePort equ 1
    CmResourceTypeInterrupt equ 2
    CmResourceTypeMemory equ 3
    CmResourceTypeDma equ 4
    CmResourceTypeDeviceSpecific equ 5
    CmResourceTypeBusNumber equ 6
    CmResourceTypeMemoryLarge equ 7
    CmResourceTypeNonArbitrated equ 128
    CmResourceTypeConfigData equ 128
    CmResourceTypeDevicePrivate equ 129
    CmResourceTypePcCardConfig equ 130
    CmResourceTypeMfCardConfig equ 131
    CmResourceTypeConnection equ 132
    CM_SHARE_DISPOSITION typedef SDWORD
    CmResourceShareUndetermined EQU 0 
    CmResourceShareDeviceExclusive EQU 1
    CmResourceShareDriverExclusive EQU 2
    CmResourceShareShared EQU 3
    
    CM_RESOURCE_INTERRUPT_LEVEL_SENSITIVE equ 00h
    CM_RESOURCE_INTERRUPT_LATCHED equ 01h
    CM_RESOURCE_INTERRUPT_MESSAGE equ 02h
    CM_RESOURCE_INTERRUPT_POLICY_INCLUDED equ 04h
    CM_RESOURCE_INTERRUPT_SECONDARY_INTERRUPT equ 10h
    CM_RESOURCE_INTERRUPT_WAKE_HINT equ 20h
    CM_RESOURCE_INTERRUPT_LEVEL_LATCHED_BITS equ 0001h
    CM_RESOURCE_INTERRUPT_MESSAGE_TOKEN equ - 2
    CM_RESOURCE_MEMORY_READ_WRITE equ 0000h
    CM_RESOURCE_MEMORY_READ_ONLY equ 0001h
    CM_RESOURCE_MEMORY_WRITE_ONLY equ 0002h
    CM_RESOURCE_MEMORY_WRITEABILITY_MASK equ 0003h
    CM_RESOURCE_MEMORY_PREFETCHABLE equ 0004h
    CM_RESOURCE_MEMORY_COMBINEDWRITE equ 0008h
    CM_RESOURCE_MEMORY_24 equ 0010h
    CM_RESOURCE_MEMORY_CACHEABLE equ 0020h
    CM_RESOURCE_MEMORY_WINDOW_DECODE equ 0040h
    CM_RESOURCE_MEMORY_BAR equ 0080h
    CM_RESOURCE_MEMORY_COMPAT_FOR_INACCESSIBLE_RANGE equ 0100h
    CM_RESOURCE_MEMORY_LARGE equ 0E00h
    CM_RESOURCE_MEMORY_LARGE_40 equ 0200h
    CM_RESOURCE_MEMORY_LARGE_48 equ 0400h
    CM_RESOURCE_MEMORY_LARGE_64 equ 0800h
    CM_RESOURCE_MEMORY_LARGE_40_MAXLEN equ 000000FFFFFFFF00h
    CM_RESOURCE_MEMORY_LARGE_48_MAXLEN equ 0000FFFFFFFF0000h
    CM_RESOURCE_MEMORY_LARGE_64_MAXLEN equ 0FFFFFFFF00000000h
    CM_RESOURCE_PORT_MEMORY equ 0000h
    CM_RESOURCE_PORT_IO equ 0001h
    CM_RESOURCE_PORT_10_BIT_DECODE equ 0004h
    CM_RESOURCE_PORT_12_BIT_DECODE equ 0008h
    CM_RESOURCE_PORT_16_BIT_DECODE equ 0010h
    CM_RESOURCE_PORT_POSITIVE_DECODE equ 0020h
    CM_RESOURCE_PORT_PASSIVE_DECODE equ 0040h
    CM_RESOURCE_PORT_WINDOW_DECODE equ 0080h
    CM_RESOURCE_PORT_BAR equ 0100h
    CM_RESOURCE_DMA_8 equ 0000h
    CM_RESOURCE_DMA_16 equ 0001h
    CM_RESOURCE_DMA_32 equ 0002h
    CM_RESOURCE_DMA_8_AND_16 equ 0004h
    CM_RESOURCE_DMA_BUS_MASTER equ 0008h
    CM_RESOURCE_DMA_TYPE_A equ 0010h
    CM_RESOURCE_DMA_TYPE_B equ 0020h
    CM_RESOURCE_DMA_TYPE_F equ 0040h
    CM_RESOURCE_DMA_V3 equ 0080h
    DMAV3_TRANFER_WIDTH_8 equ 00h
    DMAV3_TRANFER_WIDTH_16 equ 01h
    DMAV3_TRANFER_WIDTH_32 equ 02h
    DMAV3_TRANFER_WIDTH_64 equ 03h
    DMAV3_TRANFER_WIDTH_128 equ 04h
    DMAV3_TRANFER_WIDTH_256 equ 05h
    CM_RESOURCE_CONNECTION_CLASS_GPIO equ 01h
    CM_RESOURCE_CONNECTION_CLASS_SERIAL equ 02h
    CM_RESOURCE_CONNECTION_CLASS_FUNCTION_CONFIG equ 03h
    CM_RESOURCE_CONNECTION_TYPE_GPIO_IO equ 02h
    CM_RESOURCE_CONNECTION_TYPE_SERIAL_I2C equ 01h
    CM_RESOURCE_CONNECTION_TYPE_SERIAL_SPI equ 02h
    CM_RESOURCE_CONNECTION_TYPE_SERIAL_UART equ 03h
    CM_RESOURCE_CONNECTION_TYPE_FUNCTION_CONFIG equ 01h
  
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
  
  DEVICE_FLAGS struct
    DEVICE_FLAGS_??4 record Failed_??4:1, ReadOnly_??4:1, Removable_??4:1, ConsoleIn_??4:1, ConsoleOut_??4:1, Input_??4:1, Output_??4:1
    DEVICE_FLAGS_??4 <>
  DEVICE_FLAGS ends

  PDEVICE_FLAGS typedef ptr DEVICE_FLAGS
  
  CM_COMPONENT_INFORMATION struct
    Flags DEVICE_FLAGS <>
    Version DWORD ?
    Key DWORD ?
    AffinityMask KAFFINITY ?
  CM_COMPONENT_INFORMATION ends

  PCM_COMPONENT_INFORMATION typedef ptr CM_COMPONENT_INFORMATION
  
  CM_ROM_BLOCK struct
    Address DWORD ?
    Size_ DWORD ?
  CM_ROM_BLOCK ends

  PCM_ROM_BLOCK typedef ptr CM_ROM_BLOCK
  

  CM_INT13_DRIVE_PARAMETER struct
    DriveSelect WORD ?
    MaxCylinders DWORD ?
    SectorsPerTrack WORD ?
    MaxHeads WORD ?
    NumberDrives WORD ?
  CM_INT13_DRIVE_PARAMETER ends

  PCM_INT13_DRIVE_PARAMETER typedef ptr CM_INT13_DRIVE_PARAMETER
  
  CM_MCA_POS_DATA struct
    AdapterId WORD ?
    PosData1 BYTE ?
    PosData2 BYTE ?
    PosData3 BYTE ?
    PosData4 BYTE ?
  CM_MCA_POS_DATA ends

  PCM_MCA_POS_DATA typedef ptr CM_MCA_POS_DATA
  
  EISA_MEMORY_TYPE struct
    EISA_MEMORY_TYPE_??5 record ReadWrite_??5:1, Cached_??5:1, Reserved0_??5:1, Type_??5:2, Shared_??5:1, Reserved1_??5:1, MoreEntries_??5:1
    EISA_MEMORY_TYPE_??5 <>
  EISA_MEMORY_TYPE ends

  PEISA_MEMORY_TYPE typedef ptr EISA_MEMORY_TYPE
  
  EISA_MEMORY_CONFIGURATION struct
    ConfigurationByte EISA_MEMORY_TYPE <>
    DataSize BYTE ?
    AddressLowWord WORD ?
    AddressHighByte BYTE ?
    MemorySize WORD ?
  EISA_MEMORY_CONFIGURATION ends

  PEISA_MEMORY_CONFIGURATION typedef ptr EISA_MEMORY_CONFIGURATION
  
  EISA_IRQ_DESCRIPTOR struct
    EISA_IRQ_DESCRIPTOR_??6 record Interrupt_??6:4, Reserved_??6:1, LevelTriggered_??6:1, Shared_??6:1, MoreEntries_??6:1
    EISA_IRQ_DESCRIPTOR_??6 <>
  EISA_IRQ_DESCRIPTOR ends

  PEISA_IRQ_DESCRIPTOR typedef ptr EISA_IRQ_DESCRIPTOR
  
  EISA_IRQ_CONFIGURATION struct
    ConfigurationByte EISA_IRQ_DESCRIPTOR <>
    Reserved BYTE ?
  EISA_IRQ_CONFIGURATION ends

  PEISA_IRQ_CONFIGURATION typedef ptr EISA_IRQ_CONFIGURATION
  
  DMA_CONFIGURATION_BYTE0 struct
    DMA_CONFIGURATION_BYTE0_??7 record Channel_??7:3, Reserved_??7:3, Shared_??7:1, MoreEntries_??7:1
    DMA_CONFIGURATION_BYTE0_??7 <>
  DMA_CONFIGURATION_BYTE0 ends

  DMA_CONFIGURATION_BYTE1 struct
    DMA_CONFIGURATION_BYTE1_??8 record Reserved0_??8:2, TransferSize_??8:2, Timing_??8:2, Reserved1_??8:2
    DMA_CONFIGURATION_BYTE1_??8 <>
  DMA_CONFIGURATION_BYTE1 ends

  EISA_DMA_CONFIGURATION struct
    ConfigurationByte0 DMA_CONFIGURATION_BYTE0 <>
    ConfigurationByte1 DMA_CONFIGURATION_BYTE1 <>
  EISA_DMA_CONFIGURATION ends

  PEISA_DMA_CONFIGURATION typedef ptr EISA_DMA_CONFIGURATION
  
  EISA_PORT_DESCRIPTOR struct
    EISA_PORT_DESCRIPTOR_??9 record NumberPorts_??9:5, Reserved_??9:1, Shared_??9:1, MoreEntries_??9:1
    EISA_PORT_DESCRIPTOR_??9 <>
  EISA_PORT_DESCRIPTOR ends

  PEISA_PORT_DESCRIPTOR typedef ptr EISA_PORT_DESCRIPTOR
  
  EISA_PORT_CONFIGURATION struct
    Configuration EISA_PORT_DESCRIPTOR <>
    PortAddress WORD ?
  EISA_PORT_CONFIGURATION ends

  PEISA_PORT_CONFIGURATION typedef ptr EISA_PORT_CONFIGURATION
  
  CM_EISA_SLOT_INFORMATION struct
    ReturnCode BYTE ?
    ReturnFlags BYTE ?
    MajorRevision BYTE ?
    MinorRevision BYTE ?
    Checksum WORD ?
    NumberFunctions BYTE ?
    FunctionInformation BYTE ?
    CompressedId DWORD ?
  CM_EISA_SLOT_INFORMATION ends

  PCM_EISA_SLOT_INFORMATION typedef ptr CM_EISA_SLOT_INFORMATION
  
  CM_EISA_FUNCTION_INFORMATION struct
    CompressedId DWORD ?
    IdSlotFlags1 BYTE ?
    IdSlotFlags2 BYTE ?
    MinorRevision BYTE ?
    MajorRevision BYTE ?
    Selections BYTE 26 dup (?)
    FunctionFlags BYTE ?
    TypeString BYTE 80 dup (?)
    EisaMemory EISA_MEMORY_CONFIGURATION 9 dup (<>)
    EisaIrq EISA_IRQ_CONFIGURATION 7 dup (<>)
    EisaDma EISA_DMA_CONFIGURATION 4 dup (<>)
    EisaPort EISA_PORT_CONFIGURATION 20 dup (<>)
    InitializationData BYTE 60 dup (?)
  CM_EISA_FUNCTION_INFORMATION ends

  PCM_EISA_FUNCTION_INFORMATION typedef ptr CM_EISA_FUNCTION_INFORMATION
  
  CM_PNP_BIOS_DEVICE_NODE struct
    Size_ WORD ?
    Node BYTE ?
    ProductId DWORD ?
    DeviceType BYTE 3 dup (?)
    DeviceAttributes WORD ?
  CM_PNP_BIOS_DEVICE_NODE ends

  PCM_PNP_BIOS_DEVICE_NODE typedef ptr CM_PNP_BIOS_DEVICE_NODE
  
  CM_PNP_BIOS_INSTALLATION_CHECK struct
    Signature BYTE 4 dup (?)
    Revision BYTE ?
    Length_ BYTE ?
    ControlField WORD ?
    Checksum BYTE ?
    EventFlagAddress DWORD ?
    RealModeEntryOffset WORD ?
    RealModeEntrySegment WORD ?
    ProtectedModeEntryOffset WORD ?
    ProtectedModeCodeBaseAddress DWORD ?
    OemDeviceId DWORD ?
    RealModeDataBaseAddress WORD ?
    ProtectedModeDataBaseAddress DWORD ?
  CM_PNP_BIOS_INSTALLATION_CHECK ends

  PCM_PNP_BIOS_INSTALLATION_CHECK typedef ptr CM_PNP_BIOS_INSTALLATION_CHECK
  

  EISA_FUNCTION_ENABLED equ 80h
  EISA_FREE_FORM_DATA equ 40h
  EISA_HAS_PORT_INIT_ENTRY equ 20h
  EISA_HAS_PORT_RANGE equ 10h
  EISA_HAS_DMA_ENTRY equ 08h
  EISA_HAS_IRQ_ENTRY equ 04h
  EISA_HAS_MEMORY_ENTRY equ 02h
  EISA_HAS_TYPE_ENTRY equ 01h
  EISA_HAS_INFORMATION equ <EISA_HAS_PORT_RANGE + EISA_HAS_DMA_ENTRY + EISA_HAS_IRQ_ENTRY + EISA_HAS_MEMORY_ENTRY + EISA_HAS_TYPE_ENTRY>
  EISA_MORE_ENTRIES equ 80h
  EISA_SYSTEM_MEMORY equ 00h
  EISA_MEMORY_TYPE_RAM equ 01h
  EISA_INVALID_SLOT equ 80h
  EISA_INVALID_FUNCTION equ 81h
  EISA_INVALID_CONFIGURATION equ 82h
  EISA_EMPTY_SLOT equ 83h
  EISA_INVALID_BIOS_CALL equ 86h
  CM_SCSI_DEVICE_DATA struct
    Version WORD ?
    Revision WORD ?
    HostIdentifier BYTE ?
  CM_SCSI_DEVICE_DATA ends

  PCM_SCSI_DEVICE_DATA typedef ptr CM_SCSI_DEVICE_DATA
  
  CM_VIDEO_DEVICE_DATA struct
    Version WORD ?
    Revision WORD ?
    VideoClock DWORD ?
  CM_VIDEO_DEVICE_DATA ends

  PCM_VIDEO_DEVICE_DATA typedef ptr CM_VIDEO_DEVICE_DATA
  
  CM_SONIC_DEVICE_DATA struct
    Version WORD ?
    Revision WORD ?
    DataConfigurationRegister WORD ?
    EthernetAddress BYTE 8 dup (?)
  CM_SONIC_DEVICE_DATA ends

  PCM_SONIC_DEVICE_DATA typedef ptr CM_SONIC_DEVICE_DATA
  
  CM_SERIAL_DEVICE_DATA struct
    Version WORD ?
    Revision WORD ?
    BaudClock DWORD ?
  CM_SERIAL_DEVICE_DATA ends

  PCM_SERIAL_DEVICE_DATA typedef ptr CM_SERIAL_DEVICE_DATA
  
  CM_MONITOR_DEVICE_DATA struct
    Version WORD ?
    Revision WORD ?
    HorizontalScreenSize WORD ?
    VerticalScreenSize WORD ?
    HorizontalResolution WORD ?
    VerticalResolution WORD ?
    HorizontalDisplayTimeLow WORD ?
    HorizontalDisplayTime WORD ?
    HorizontalDisplayTimeHigh WORD ?
    HorizontalBackPorchLow WORD ?
    HorizontalBackPorch WORD ?
    HorizontalBackPorchHigh WORD ?
    HorizontalFrontPorchLow WORD ?
    HorizontalFrontPorch WORD ?
    HorizontalFrontPorchHigh WORD ?
    HorizontalSyncLow WORD ?
    HorizontalSync WORD ?
    HorizontalSyncHigh WORD ?
    VerticalBackPorchLow WORD ?
    VerticalBackPorch WORD ?
    VerticalBackPorchHigh WORD ?
    VerticalFrontPorchLow WORD ?
    VerticalFrontPorch WORD ?
    VerticalFrontPorchHigh WORD ?
    VerticalSyncLow WORD ?
    VerticalSync WORD ?
    VerticalSyncHigh WORD ?
  CM_MONITOR_DEVICE_DATA ends

  PCM_MONITOR_DEVICE_DATA typedef ptr CM_MONITOR_DEVICE_DATA
  
  CM_FLOPPY_DEVICE_DATA struct
    Version WORD ?
    Revision WORD ?
    Size_ CHAR 8 dup (?)
    MaxDensity DWORD ?
    MountDensity DWORD ?
    StepRateHeadUnloadTime BYTE ?
    HeadLoadTime BYTE ?
    MotorOffTime BYTE ?
    SectorLengthCode BYTE ?
    SectorPerTrack BYTE ?
    ReadWriteGapLength BYTE ?
    DataTransferLength BYTE ?
    FormatGapLength BYTE ?
    FormatFillCharacter BYTE ?
    HeadSettleTime BYTE ?
    MotorSettleTime BYTE ?
    MaximumTrackValue BYTE ?
    DataTransferRate BYTE ?
  CM_FLOPPY_DEVICE_DATA ends

  PCM_FLOPPY_DEVICE_DATA typedef ptr CM_FLOPPY_DEVICE_DATA
  
  CM_KEYBOARD_DEVICE_DATA struct
    Version WORD ?
    Revision WORD ?
    Type_ BYTE ?
    Subtype BYTE ?
    KeyboardFlags WORD ?
  CM_KEYBOARD_DEVICE_DATA ends

  PCM_KEYBOARD_DEVICE_DATA typedef ptr CM_KEYBOARD_DEVICE_DATA
  
  CM_DISK_GEOMETRY_DEVICE_DATA struct
    BytesPerSector DWORD ?
    NumberOfCylinders DWORD ?
    SectorsPerTrack DWORD ?
    NumberOfHeads DWORD ?
  CM_DISK_GEOMETRY_DEVICE_DATA ends

  PCM_DISK_GEOMETRY_DEVICE_DATA typedef ptr CM_DISK_GEOMETRY_DEVICE_DATA
  
  IO_RESOURCE_PREFERRED equ 01h
  IO_RESOURCE_DEFAULT equ 02h
  IO_RESOURCE_ALTERNATIVE equ 08h
;  if defined(NT_PROCESSOR_GROUPS)
;    IRQ_DEVICE_POLICY typedef WORD
;    PIRQ_DEVICE_POLICY typedef ptr WORD
;    _IRQ_DEVICE_POLICY_USHORT typedef SDWORD
;    IrqPolicyMachineDefault EQU 0 
;    IrqPolicyAllCloseProcessors EQU 1 
;    IrqPolicyOneCloseProcessor EQU 2 
;    IrqPolicyAllProcessorsInMachine EQU 3 
;    IrqPolicyAllProcessorsInGroup EQU 3 
;    IrqPolicySpecifiedProcessors EQU 4 
;    IrqPolicySpreadMessagesAcrossAllProcessors EQU 5 
;    IrqPolicyAllProcessorsInMachineWhenSteered EQU 6 
;    IrqPolicyAllProcessorsInGroupWhenSteered EQU 6 
;    
;  else
    IRQ_DEVICE_POLICY typedef SDWORD
    IrqPolicyMachineDefault EQU 0 
    IrqPolicyAllCloseProcessors EQU 1
    IrqPolicyOneCloseProcessor EQU 2
    IrqPolicyAllProcessorsInMachine EQU 3
    IrqPolicySpecifiedProcessors EQU 4
    IrqPolicySpreadMessagesAcrossAllProcessors EQU 5
    IrqPolicyAllProcessorsInMachineWhenSteered EQU 6
    
    PIRQ_DEVICE_POLICY typedef ptr IRQ_DEVICE_POLICY
    
;  endif
  IRQ_PRIORITY typedef SDWORD
  IrqPriorityUndefined EQU 0 
  IrqPriorityLow EQU 1
  IrqPriorityNormal EQU 2
  IrqPriorityHigh EQU 3
  
  PIRQ_PRIORITY typedef ptr IRQ_PRIORITY
  
  IRQ_GROUP_POLICY typedef SDWORD
  GroupAffinityAllGroupZero EQU 0 
  GroupAffinityDontCare EQU 1
  
  PIRQ_GROUP_POLICY typedef ptr IRQ_GROUP_POLICY
  
  IRQ_DEVICE_POLICY typedef SDWORD
  
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
  
  IO_RESOURCE_LIST struct
    Version WORD ?
    Revision WORD ?
    Count DWORD ?
    Descriptors IO_RESOURCE_DESCRIPTOR 1 dup (<>)
  IO_RESOURCE_LIST ends

  PIO_RESOURCE_LIST typedef ptr IO_RESOURCE_LIST
  
  IO_RESOURCE_REQUIREMENTS_LIST struct
    ListSize DWORD ?
    InterfaceType INTERFACE_TYPE ?
    BusNumber DWORD ?
    SlotNumber DWORD ?
    Reserved DWORD 3 dup (?)
    AlternativeLists DWORD ?
    List IO_RESOURCE_LIST 1 dup (<>)
  IO_RESOURCE_REQUIREMENTS_LIST ends

  PIO_RESOURCE_REQUIREMENTS_LIST typedef ptr IO_RESOURCE_REQUIREMENTS_LIST
  


      SLIST_ENTRY typedef SINGLE_LIST_ENTRY
      PSLIST_ENTRY typedef ptr SINGLE_LIST_ENTRY
      

      SLIST_HEADER union
        Alignment QWORD ?
        struct DUMMYSTRUCTNAME_7
          Next SLIST_ENTRY <>
          Depth WORD ?
          CpuId_ WORD ?
        ends
      SLIST_HEADER ends

      PSLIST_HEADER typedef ptr SLIST_HEADER



    FAST_FAIL_LEGACY_GS_VIOLATION equ 0
    FAST_FAIL_VTGUARD_CHECK_FAILURE equ 1
    FAST_FAIL_STACK_COOKIE_CHECK_FAILURE equ 2
    FAST_FAIL_CORRUPT_LIST_ENTRY equ 3
    FAST_FAIL_INCORRECT_STACK equ 4
    FAST_FAIL_INVALID_ARG equ 5
    FAST_FAIL_GS_COOKIE_INIT equ 6
    FAST_FAIL_FATAL_APP_EXIT equ 7
    FAST_FAIL_RANGE_CHECK_FAILURE equ 8
    FAST_FAIL_UNSAFE_REGISTRY_ACCESS equ 9
    FAST_FAIL_GUARD_ICALL_CHECK_FAILURE equ 10
    FAST_FAIL_GUARD_WRITE_CHECK_FAILURE equ 11
    FAST_FAIL_INVALID_FIBER_SWITCH equ 12
    FAST_FAIL_INVALID_SET_OF_CONTEXT equ 13
    FAST_FAIL_INVALID_REFERENCE_COUNT equ 14
    FAST_FAIL_INVALID_JUMP_BUFFER equ 18
    FAST_FAIL_MRDATA_MODIFIED equ 19
    FAST_FAIL_CERTIFICATION_FAILURE equ 20
    FAST_FAIL_INVALID_EXCEPTION_CHAIN equ 21
    FAST_FAIL_CRYPTO_LIBRARY equ 22
    FAST_FAIL_INVALID_CALL_IN_DLL_CALLOUT equ 23
    FAST_FAIL_INVALID_IMAGE_BASE equ 24
    FAST_FAIL_DLOAD_PROTECTION_FAILURE equ 25
    FAST_FAIL_UNSAFE_EXTENSION_CALL equ 26
    FAST_FAIL_DEPRECATED_SERVICE_INVOKED equ 27
    FAST_FAIL_INVALID_BUFFER_ACCESS equ 28
    FAST_FAIL_INVALID_BALANCED_TREE equ 29
    FAST_FAIL_INVALID_NEXT_THREAD equ 30
    FAST_FAIL_GUARD_ICALL_CHECK_SUPPRESSED equ 31
    FAST_FAIL_APCS_DISABLED equ 32
    FAST_FAIL_INVALID_IDLE_STATE equ 33
    FAST_FAIL_MRDATA_PROTECTION_FAILURE equ 34
    FAST_FAIL_UNEXPECTED_HEAP_EXCEPTION equ 35
    FAST_FAIL_INVALID_LOCK_STATE equ 36
    FAST_FAIL_GUARD_JUMPTABLE equ 37
    FAST_FAIL_INVALID_LONGJUMP_TARGET equ 38
    FAST_FAIL_INVALID_DISPATCH_CONTEXT equ 39
    FAST_FAIL_INVALID_THREAD equ 40
    FAST_FAIL_INVALID_SYSCALL_NUMBER equ 41
    FAST_FAIL_INVALID_FILE_OPERATION equ 42
    FAST_FAIL_LPAC_ACCESS_DENIED equ 43
    FAST_FAIL_GUARD_SS_FAILURE equ 44
    FAST_FAIL_LOADER_CONTINUITY_FAILURE equ 45
    FAST_FAIL_GUARD_EXPORT_SUPPRESSION_FAILURE equ 46
    FAST_FAIL_INVALID_CONTROL_STACK equ 47
    FAST_FAIL_SET_CONTEXT_DENIED equ 48
    FAST_FAIL_INVALID_IAT equ 49
    FAST_FAIL_HEAP_METADATA_CORRUPTION equ 50
    FAST_FAIL_PAYLOAD_RESTRICTION_VIOLATION equ 51
    FAST_FAIL_LOW_LABEL_ACCESS_DENIED equ 52
    FAST_FAIL_ENCLAVE_CALL_FAILURE equ 53
    FAST_FAIL_UNHANDLED_LSS_EXCEPTON equ 54
    FAST_FAIL_ADMINLESS_ACCESS_DENIED equ 55
    FAST_FAIL_UNEXPECTED_CALL equ 56
    FAST_FAIL_INVALID_FAST_FAIL_CODE equ 0FFFFFFFFh


      RtlFailFast proto fastcall :DWORD

    RTL_STATIC_LIST_HEAD macro x
     exitm <LIST_ENTRY x = { and x , and x } >
    endm
    InitializeListHead proto fastcall :PLIST_ENTRY
    IsListEmpty proto fastcall :ptr LIST_ENTRY
    RemoveEntryListUnsafe proto fastcall :PLIST_ENTRY
      RemoveEntryList proto fastcall :PLIST_ENTRY
      RemoveHeadList proto fastcall :PLIST_ENTRY
      RemoveTailList proto fastcall :PLIST_ENTRY
      InsertTailList proto fastcall :PLIST_ENTRY, :PLIST_ENTRY
      InsertHeadList proto fastcall :PLIST_ENTRY, :PLIST_ENTRY
      AppendTailList proto fastcall :PLIST_ENTRY, :PLIST_ENTRY
    PopEntryList proto fastcall :PSINGLE_LIST_ENTRY
    PushEntryList proto fastcall :PSINGLE_LIST_ENTRY, :PSINGLE_LIST_ENTRY

 

    NLS_MB_CODE_PAGE_TAG equ <NlsMbCodePageTag>
    NLS_MB_OEM_CODE_PAGE_TAG equ <NlsMbOemCodePageTag>




    RtlInitEmptyUnicodeString proto fastcall :PUNICODE_STRING, :PWCHAR, :WORD
    RtlInitEmptyAnsiString proto fastcall :PANSI_STRING, :PCHAR, :WORD

  RTL_QUERY_REGISTRY_ROUTINE typedef proto stdcall :PWSTR,:DWORD,:PVOID,:DWORD,:PVOID,:PVOID
  PRTL_QUERY_REGISTRY_ROUTINE typedef ptr RTL_QUERY_REGISTRY_ROUTINE
  RTL_QUERY_REGISTRY_TABLE struct
    QueryRoutine PRTL_QUERY_REGISTRY_ROUTINE ?
    Flags DWORD ?
    Name_ PWSTR ?
    EntryContext PVOID ?
    DefaultType DWORD ?
    DefaultData PVOID ?
    DefaultLength DWORD ?
  RTL_QUERY_REGISTRY_TABLE ends

  PRTL_QUERY_REGISTRY_TABLE typedef ptr RTL_QUERY_REGISTRY_TABLE
  
  RTL_QUERY_REGISTRY_SUBKEY equ 00000001h
  RTL_QUERY_REGISTRY_TOPKEY equ 00000002h
  RTL_QUERY_REGISTRY_REQUIRED equ 00000004h
  RTL_QUERY_REGISTRY_NOVALUE equ 00000008h
  RTL_QUERY_REGISTRY_NOEXPAND equ 00000010h
  RTL_QUERY_REGISTRY_DIRECT equ 00000020h
  RTL_QUERY_REGISTRY_DELETE equ 00000040h
  RTL_QUERY_REGISTRY_NOSTRING equ 00000080h
  RTL_QUERY_REGISTRY_TYPECHECK equ 00000100h
  RTL_QUERY_REGISTRY_TYPECHECK_SHIFT equ 24
  RTL_QUERY_REGISTRY_TYPECHECK_MASK equ ( 0ffh shl RTL_QUERY_REGISTRY_TYPECHECK_SHIFT )

  RTL_REGISTRY_ABSOLUTE equ 0
  RTL_REGISTRY_SERVICES equ 1
  RTL_REGISTRY_CONTROL equ 2
  RTL_REGISTRY_WINDOWS_NT equ 3
  RTL_REGISTRY_DEVICEMAP equ 4
  RTL_REGISTRY_USER equ 5
  RTL_REGISTRY_MAXIMUM equ 6
  RTL_REGISTRY_HANDLE equ 40000000h
  RTL_REGISTRY_OPTIONAL equ 80000000h


  HASH_STRING_ALGORITHM_DEFAULT equ 0
  HASH_STRING_ALGORITHM_X65599 equ 1
  HASH_STRING_ALGORITHM_INVALID equ 0ffffffffh

  ifndef DEFINE_GUIDEX
    DEFINE_GUIDEX macro name
     exitm <EXTERN_C const CDECL GUID name >
    endm
  endif
  ifndef STATICGUIDOF
    STATICGUIDOF macro guid
     exitm <STATIC_ ## guid >
    endm
  endif

  RTL_GUID_STRING_SIZE equ 38



  RtlCopyBytes equ <RtlCopyMemory>
  RtlZeroBytes equ <RtlZeroMemory>
  RtlFillBytes equ <RtlFillMemory>



  DBG_STATUS_CONTROL_C equ 1
  DBG_STATUS_SYSRQ equ 2
  DBG_STATUS_BUGCHECK_FIRST equ 3
  DBG_STATUS_BUGCHECK_SECOND equ 4
  DBG_STATUS_FATAL equ 5
  DBG_STATUS_DEBUG_CONTROL equ 6
  DBG_STATUS_WORKER equ 7

    ; DPFLTR_TYPE
    DPFLTR_SYSTEM_ID EQU 0
    DPFLTR_SMSS_ID EQU 1
    DPFLTR_SETUP_ID EQU 2
    DPFLTR_NTFS_ID EQU 3
    DPFLTR_FSTUB_ID EQU 4
    DPFLTR_CRASHDUMP_ID EQU 5
    DPFLTR_CDAUDIO_ID EQU 6
    DPFLTR_CDROM_ID EQU 7
    DPFLTR_CLASSPNP_ID EQU 8
    DPFLTR_DISK_ID EQU 9
    DPFLTR_REDBOOK_ID EQU 10
    DPFLTR_STORPROP_ID EQU 11
    DPFLTR_SCSIPORT_ID EQU 12
    DPFLTR_SCSIMINIPORT_ID EQU 13
    DPFLTR_CONFIG_ID EQU 14
    DPFLTR_I8042PRT_ID EQU 15
    DPFLTR_SERMOUSE_ID EQU 16
    DPFLTR_LSERMOUS_ID EQU 17
    DPFLTR_KBDHID_ID EQU 18
    DPFLTR_MOUHID_ID EQU 19
    DPFLTR_KBDCLASS_ID EQU 20
    DPFLTR_MOUCLASS_ID EQU 21
    DPFLTR_TWOTRACK_ID EQU 22
    DPFLTR_WMILIB_ID EQU 23
    DPFLTR_ACPI_ID EQU 24
    DPFLTR_AMLI_ID EQU 25
    DPFLTR_HALIA64_ID EQU 26
    DPFLTR_VIDEO_ID EQU 27
    DPFLTR_SVCHOST_ID EQU 28
    DPFLTR_VIDEOPRT_ID EQU 29
    DPFLTR_TCPIP_ID EQU 30
    DPFLTR_DMSYNTH_ID EQU 31
    DPFLTR_NTOSPNP_ID EQU 32
    DPFLTR_FASTFAT_ID EQU 33
    DPFLTR_SAMSS_ID EQU 34
    DPFLTR_PNPMGR_ID EQU 35
    DPFLTR_NETAPI_ID EQU 36
    DPFLTR_SCSERVER_ID EQU 37
    DPFLTR_SCCLIENT_ID EQU 38
    DPFLTR_SERIAL_ID EQU 39
    DPFLTR_SERENUM_ID EQU 40
    DPFLTR_UHCD_ID EQU 41
    DPFLTR_RPCPROXY_ID EQU 42
    DPFLTR_AUTOCHK_ID EQU 43
    DPFLTR_DCOMSS_ID EQU 44
    DPFLTR_UNIMODEM_ID EQU 45
    DPFLTR_SIS_ID EQU 46
    DPFLTR_FLTMGR_ID EQU 47
    DPFLTR_WMICORE_ID EQU 48
    DPFLTR_BURNENG_ID EQU 49
    DPFLTR_IMAPI_ID EQU 50
    DPFLTR_SXS_ID EQU 51
    DPFLTR_FUSION_ID EQU 52
    DPFLTR_IDLETASK_ID EQU 53
    DPFLTR_SOFTPCI_ID EQU 54
    DPFLTR_TAPE_ID EQU 55
    DPFLTR_MCHGR_ID EQU 56
    DPFLTR_IDEP_ID EQU 57
    DPFLTR_PCIIDE_ID EQU 58
    DPFLTR_FLOPPY_ID EQU 59
    DPFLTR_FDC_ID EQU 60
    DPFLTR_TERMSRV_ID EQU 61
    DPFLTR_W32TIME_ID EQU 62
    DPFLTR_PREFETCHER_ID EQU 63
    DPFLTR_RSFILTER_ID EQU 64
    DPFLTR_FCPORT_ID EQU 65
    DPFLTR_PCI_ID EQU 66
    DPFLTR_DMIO_ID EQU 67
    DPFLTR_DMCONFIG_ID EQU 68
    DPFLTR_DMADMIN_ID EQU 69
    DPFLTR_WSOCKTRANSPORT_ID EQU 70
    DPFLTR_VSS_ID EQU 71
    DPFLTR_PNPMEM_ID EQU 72
    DPFLTR_PROCESSOR_ID EQU 73
    DPFLTR_DMSERVER_ID EQU 74
    DPFLTR_SR_ID EQU 75
    DPFLTR_INFINIBAND_ID EQU 76
    DPFLTR_IHVDRIVER_ID EQU 77
    DPFLTR_IHVVIDEO_ID EQU 78
    DPFLTR_IHVAUDIO_ID EQU 79
    DPFLTR_IHVNETWORK_ID EQU 80
    DPFLTR_IHVSTREAMING_ID EQU 81
    DPFLTR_IHVBUS_ID EQU 82
    DPFLTR_HPS_ID EQU 83
    DPFLTR_RTLTHREADPOOL_ID EQU 84
    DPFLTR_LDR_ID EQU 85
    DPFLTR_TCPIP6_ID EQU 86
    DPFLTR_ISAPNP_ID EQU 87
    DPFLTR_SHPC_ID EQU 88
    DPFLTR_STORPORT_ID EQU 89
    DPFLTR_STORMINIPORT_ID EQU 90
    DPFLTR_PRINTSPOOLER_ID EQU 91
    DPFLTR_VSSDYNDISK_ID EQU 92
    DPFLTR_VERIFIER_ID EQU 93
    DPFLTR_VDS_ID EQU 94
    DPFLTR_VDSBAS_ID EQU 95
    DPFLTR_VDSDYN_ID EQU 96
    DPFLTR_VDSDYNDR_ID EQU 97
    DPFLTR_VDSLDR_ID EQU 98
    DPFLTR_VDSUTIL_ID EQU 99
    DPFLTR_DFRGIFC_ID EQU 100
    DPFLTR_DEFAULT_ID EQU 101
    DPFLTR_MM_ID EQU 102
    DPFLTR_DFSC_ID EQU 103
    DPFLTR_WOW64_ID EQU 104
    DPFLTR_ALPC_ID EQU 105
    DPFLTR_WDI_ID EQU 106
    DPFLTR_PERFLIB_ID EQU 107
    DPFLTR_KTM_ID EQU 108
    DPFLTR_IOSTRESS_ID EQU 109
    DPFLTR_HEAP_ID EQU 110
    DPFLTR_WHEA_ID EQU 111
    DPFLTR_USERGDI_ID EQU 112
    DPFLTR_MMCSS_ID EQU 113
    DPFLTR_TPM_ID EQU 114
    DPFLTR_THREADORDER_ID EQU 115
    DPFLTR_ENVIRON_ID EQU 116
    DPFLTR_EMS_ID EQU 117
    DPFLTR_WDT_ID EQU 118
    DPFLTR_FVEVOL_ID EQU 119
    DPFLTR_NDIS_ID EQU 120
    DPFLTR_NVCTRACE_ID EQU 121
    DPFLTR_LUAFV_ID EQU 122
    DPFLTR_APPCOMPAT_ID EQU 123
    DPFLTR_USBSTOR_ID EQU 124
    DPFLTR_SBP2PORT_ID EQU 125
    DPFLTR_COVERAGE_ID EQU 126
    DPFLTR_CACHEMGR_ID EQU 127
    DPFLTR_MOUNTMGR_ID EQU 128
    DPFLTR_CFR_ID EQU 129
    DPFLTR_TXF_ID EQU 130
    DPFLTR_KSECDD_ID EQU 131
    DPFLTR_FLTREGRESS_ID EQU 132
    DPFLTR_MPIO_ID EQU 133
    DPFLTR_MSDSM_ID EQU 134
    DPFLTR_UDFS_ID EQU 135
    DPFLTR_ENDOFTABLE_ID EQU 136

    DPFLTR_ERROR_LEVEL      EQU 0
    DPFLTR_WARNING_LEVEL    EQU 1
    DPFLTR_TRACE_LEVEL      EQU 2
    DPFLTR_INFO_LEVEL       EQU 3
    DPFLTR_MASK             EQU 80000000h

    KdPrint TEXTEQU <DbgPrint>
    KdPrintEx TEXTEQU <DbgPrintEx>
    
    KdBreakPoint TEXTEQU <DbgBreakPoint>
    KdBreakPointWithStatus TEXTEQU <DbgBreakPointWithStatus>
    
    vKdPrintEx TEXTEQU <vDbgPrintEx>
    vKdPrintExWithPrefix TEXTEQU <vDbgPrintExWithPrefix>
    


  TIME_FIELDS struct
    Year CSHORT ?
    Month CSHORT ?
    Day CSHORT ?
    Hour CSHORT ?
    Minute CSHORT ?
    Second CSHORT ?
    Milliseconds CSHORT ?
    Weekday CSHORT ?
  TIME_FIELDS ends

  PTIME_FIELDS typedef ptr TIME_FIELDS

  SHORT_SIZE equ <( sizeof ( USHORT ) )>
  SHORT_MASK equ ( SHORT_SIZE - 1 )
  LONG_SIZE equ <( sizeof ( LONG ) )>
  LONGLONG_SIZE equ <( sizeof ( LONGLONG ) )>
  LONG_MASK equ ( LONG_SIZE - 1 )
  LONGLONG_MASK equ ( LONGLONG_SIZE - 1 )
  LOWBYTE_MASK equ 00FFh
  FIRSTBYTE macro VALUE
   exitm <( ( VALUE ) and LOWBYTE_MASK ) >
  endm
  SECONDBYTE macro VALUE
   exitm <( ( ( VALUE ) shr 8 ) and LOWBYTE_MASK ) >
  endm
  THIRDBYTE macro VALUE
   exitm <( ( ( VALUE ) shr 16 ) and LOWBYTE_MASK ) >
  endm
  FOURTHBYTE macro VALUE
   exitm <( ( ( VALUE ) shr 24 ) and LOWBYTE_MASK ) >
  endm
  SHORT_LEAST_SIGNIFICANT_BIT equ 0
  SHORT_MOST_SIGNIFICANT_BIT equ 1
  LONG_LEAST_SIGNIFICANT_BIT equ 0
  LONG_3RD_MOST_SIGNIFICANT_BIT equ 1
  LONG_2ND_MOST_SIGNIFICANT_BIT equ 2
  LONG_MOST_SIGNIFICANT_BIT equ 3

  RTL_BITMAP struct
    SizeOfBitMap DWORD ?
    Buffer PULONG ?
  RTL_BITMAP ends

  PRTL_BITMAP typedef ptr RTL_BITMAP


  RTL_BITMAP_RUN struct
    StartingIndex DWORD ?
    NumberOfBits DWORD ?
  RTL_BITMAP_RUN ends

  PRTL_BITMAP_RUN typedef ptr RTL_BITMAP_RUN


  SEF_DACL_AUTO_INHERIT equ 01h
  SEF_SACL_AUTO_INHERIT equ 02h
  SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT equ 04h
  SEF_AVOID_PRIVILEGE_CHECK equ 08h
  SEF_AVOID_OWNER_CHECK equ 10h
  SEF_DEFAULT_OWNER_FROM_PARENT equ 20h
  SEF_DEFAULT_GROUP_FROM_PARENT equ 40h
  SEF_MACL_NO_WRITE_UP equ 100h
  SEF_MACL_NO_READ_UP equ 200h
  SEF_MACL_NO_EXECUTE_UP equ 400h
  SEF_AI_USE_EXTRA_PARAMS equ 800h
  SEF_AVOID_OWNER_RESTRICTION equ 1000h
  SEF_FORCE_USER_MODE equ 2000h
  SEF_MACL_VALID_FLAGS equ <( SEF_MACL_NO_WRITE_UP or SEF_MACL_NO_READ_UP or SEF_MACL_NO_EXECUTE_UP )>

    _byteswap_ushort proto c :WORD
    _byteswap_ulong proto c :DWORD
    _byteswap_uint64 proto c :QWORD



  OSVERSIONINFOA struct
    dwOSVersionInfoSize DWORD ?
    dwMajorVersion DWORD ?
    dwMinorVersion DWORD ?
    dwBuildNumber DWORD ?
    dwPlatformId DWORD ?
    szCSDVersion CHAR 128 dup (?)
  OSVERSIONINFOA ends

  POSVERSIONINFOA typedef ptr OSVERSIONINFOA
  LPOSVERSIONINFOA typedef ptr OSVERSIONINFOA
  
  OSVERSIONINFOW struct
    dwOSVersionInfoSize DWORD ?
    dwMajorVersion DWORD ?
    dwMinorVersion DWORD ?
    dwBuildNumber DWORD ?
    dwPlatformId DWORD ?
    szCSDVersion WCHAR 128 dup (?)
  OSVERSIONINFOW ends

  POSVERSIONINFOW typedef ptr OSVERSIONINFOW
  LPOSVERSIONINFOW typedef ptr OSVERSIONINFOW
  RTL_OSVERSIONINFOW typedef OSVERSIONINFOW
  PRTL_OSVERSIONINFOW typedef ptr OSVERSIONINFOW
  
  ifdef UNICODE
    OSVERSIONINFO typedef OSVERSIONINFOW
    POSVERSIONINFO typedef POSVERSIONINFOW
    LPOSVERSIONINFO typedef LPOSVERSIONINFOW
  else
    OSVERSIONINFO typedef OSVERSIONINFOA
    POSVERSIONINFO typedef POSVERSIONINFOA
    LPOSVERSIONINFO typedef LPOSVERSIONINFOA
  endif
  OSVERSIONINFOEXA struct
    dwOSVersionInfoSize DWORD ?
    dwMajorVersion DWORD ?
    dwMinorVersion DWORD ?
    dwBuildNumber DWORD ?
    dwPlatformId DWORD ?
    szCSDVersion CHAR 128 dup (?)
    wServicePackMajor WORD ?
    wServicePackMinor WORD ?
    wSuiteMask WORD ?
    wProductType BYTE ?
    wReserved BYTE ?
  OSVERSIONINFOEXA ends

  POSVERSIONINFOEXA typedef ptr OSVERSIONINFOEXA
  LPOSVERSIONINFOEXA typedef ptr OSVERSIONINFOEXA
  
  OSVERSIONINFOEXW struct
    dwOSVersionInfoSize DWORD ?
    dwMajorVersion DWORD ?
    dwMinorVersion DWORD ?
    dwBuildNumber DWORD ?
    dwPlatformId DWORD ?
    szCSDVersion WCHAR 128 dup (?)
    wServicePackMajor WORD ?
    wServicePackMinor WORD ?
    wSuiteMask WORD ?
    wProductType BYTE ?
    wReserved BYTE ?
  OSVERSIONINFOEXW ends

  POSVERSIONINFOEXW typedef ptr OSVERSIONINFOEXW
  LPOSVERSIONINFOEXW typedef ptr OSVERSIONINFOEXW
  RTL_OSVERSIONINFOEXW typedef OSVERSIONINFOEXW
  PRTL_OSVERSIONINFOEXW typedef ptr OSVERSIONINFOEXW
  
  ifdef UNICODE
    OSVERSIONINFOEX typedef OSVERSIONINFOEXW
    POSVERSIONINFOEX typedef POSVERSIONINFOEXW
    LPOSVERSIONINFOEX typedef LPOSVERSIONINFOEXW
  else
    OSVERSIONINFOEX typedef OSVERSIONINFOEXA
    POSVERSIONINFOEX typedef POSVERSIONINFOEXA
    LPOSVERSIONINFOEX typedef LPOSVERSIONINFOEXA
  endif
  VER_EQUAL equ 1
  VER_GREATER equ 2
  VER_GREATER_EQUAL equ 3
  VER_LESS equ 4
  VER_LESS_EQUAL equ 5
  VER_AND equ 6
  VER_OR equ 7
  VER_CONDITION_MASK equ 7
  VER_NUM_BITS_PER_CONDITION_MASK equ 3
  VER_MINORVERSION equ 0000001h
  VER_MAJORVERSION equ 0000002h
  VER_BUILDNUMBER equ 0000004h
  VER_PLATFORMID equ 0000008h
  VER_SERVICEPACKMINOR equ 0000010h
  VER_SERVICEPACKMAJOR equ 0000020h
  VER_SUITENAME equ 0000040h
  VER_PRODUCT_TYPE equ 0000080h
  VER_NT_WORKSTATION equ 0000001h
  VER_NT_DOMAIN_CONTROLLER equ 0000002h
  VER_NT_SERVER equ 0000003h
  VER_PLATFORM_WIN32s equ 0
  VER_PLATFORM_WIN32_WINDOWS equ 1
  VER_PLATFORM_WIN32_NT equ 2



  proto_PFN_RTL_IS_NTDDI_VERSION_AVAILABLE typedef proto fastcall :DWORD
  PFN_RTL_IS_NTDDI_VERSION_AVAILABLE typedef ptr proto_PFN_RTL_IS_NTDDI_VERSION_AVAILABLE
  proto_PFN_RTL_IS_SERVICE_PACK_VERSION_INSTALLED typedef proto fastcall :DWORD
  PFN_RTL_IS_SERVICE_PACK_VERSION_INSTALLED typedef ptr proto_PFN_RTL_IS_SERVICE_PACK_VERSION_INSTALLED




      VRL_PREDEFINED_CLASS_BEGIN equ ( 1 shl 0 )
      VRL_CUSTOM_CLASS_BEGIN equ ( 1 shl 8 )
      VRL_CLASS_CONSISTENCY equ ( VRL_PREDEFINED_CLASS_BEGIN shl 0 )
      VRL_ENABLE_KERNEL_BREAKS equ ( 1 shl 31 )


    CTMF_INCLUDE_APPCONTAINER equ 00000001h
    CTMF_INCLUDE_LPAC equ 00000002h
    CTMF_VALID_FLAGS equ <( CTMF_INCLUDE_APPCONTAINER or CTMF_INCLUDE_LPAC )>



    OS_DEPLOYEMENT_STATE_VALUES typedef SDWORD
    OS_DEPLOYMENT_STANDARD EQU 1 
    OS_DEPLOYMENT_COMPACT EQU 2
    
    proto_RtlOsDeploymentState typedef proto stdcall :DWORD
    externdef stdcall _imp__RtlOsDeploymentState@4: ptr proto_RtlOsDeploymentState
    RtlOsDeploymentState equ <_imp__RtlOsDeploymentState@4>

  IMAGE_POLICY_METADATA_VERSION equ 1
  IMAGE_POLICY_SECTION_NAME equ <".tPolicy",0>
  IMAGE_POLICY_METADATA_NAME equ <__ImagePolicyMetadata>
  IMAGE_POLICY_ENTRY_TYPE typedef SDWORD
  ImagePolicyEntryTypeNone EQU 0 
  ImagePolicyEntryTypeBool EQU 1
  ImagePolicyEntryTypeInt8 EQU 2
  ImagePolicyEntryTypeUInt8 EQU 3
  ImagePolicyEntryTypeInt16 EQU 4
  ImagePolicyEntryTypeUInt16 EQU 5
  ImagePolicyEntryTypeInt32 EQU 6
  ImagePolicyEntryTypeUInt32 EQU 7
  ImagePolicyEntryTypeInt64 EQU 8
  ImagePolicyEntryTypeUInt64 EQU 9
  ImagePolicyEntryTypeAnsiString EQU 10
  ImagePolicyEntryTypeUnicodeString EQU 11
  ImagePolicyEntryTypeOverride EQU 12
  ImagePolicyEntryTypeMaximum EQU 13
  
  IMAGE_POLICY_ID typedef SDWORD
  ImagePolicyIdNone EQU 0 
  ImagePolicyIdEtw EQU 1
  ImagePolicyIdDebug EQU 2
  ImagePolicyIdCrashDump EQU 3
  ImagePolicyIdCrashDumpKey EQU 4
  ImagePolicyIdCrashDumpKeyGuid EQU 5
  ImagePolicyIdParentSd EQU 6
  ImagePolicyIdParentSdRev EQU 7
  ImagePolicyIdSvn EQU 8
  ImagePolicyIdDeviceId EQU 9
  ImagePolicyIdCapability EQU 10
  ImagePolicyIdScenarioId EQU 11
  ImagePolicyIdMaximum EQU 12
  
  IMAGE_POLICY_ENTRY struct
    Type_ IMAGE_POLICY_ENTRY_TYPE ?
    PolicyId IMAGE_POLICY_ID ?
    union u
      None POINTER ?
      BoolValue BOOLEAN ?
      Int8Value INT8 ?
      UInt8Value UINT8 ?
      Int16Value INT16 ?
      UInt16Value UINT16 ?
      Int32Value INT32 ?
      UInt32Value UINT32 ?
      Int64Value INT64 ?
      UInt64Value UINT64 ?
      AnsiStringValue PCSTR ?
      UnicodeStringValue PCWSTR ?
    ends
  IMAGE_POLICY_ENTRY ends

  PCIMAGE_POLICY_ENTRY typedef ptr IMAGE_POLICY_ENTRY
  ;#pragma warning ( push )
  ;#pragma warning ( disable : 4200 )
  IMAGE_POLICY_METADATA struct
    Version BYTE ?
    Reserved0 BYTE 7 dup (?)
    ApplicationId QWORD ?
    Policies IMAGE_POLICY_ENTRY 0 dup (<>)
  IMAGE_POLICY_METADATA ends

  PCIMAGE_POLICY_METADATA typedef ptr IMAGE_POLICY_METADATA
  ;#pragma warning ( pop )
  IMAGE_POLICY_START macro _ApplicationId_
   exitm <__pragma ( const_seg ( push , IMAGE_POLICY_SECTION_NAME ) ) ; EXTERN_C __declspec ( dllexport ) const IMAGE_POLICY_METADATA IMAGE_POLICY_METADATA_NAME = { IMAGE_POLICY_METADATA_VERSION , { 0 } , _ApplicationId_ , { >
  endm
  IMAGE_POLICY_END macro 
   exitm <{ ImagePolicyEntryTypeNone , ImagePolicyIdNone , NULL } } } ; __pragma ( const_seg ( pop ) ) >
  endm
  IMAGE_POLICY_BOOL macro _PolicyId_,_Value_
   exitm <{ ImagePolicyEntryTypeBool , _PolicyId_ , ( const VOID * ) _Value_ } , >
  endm
  IMAGE_POLICY_INT8 macro _PolicyId_,_Value_
   exitm <{ ImagePolicyEntryTypeInt8 , _PolicyId_ , ( const VOID * ) _Value_ } , >
  endm
  IMAGE_POLICY_UINT8 macro _PolicyId_,_Value_
   exitm <{ ImagePolicyEntryTypeUInt8 , _PolicyId_ , ( const VOID * ) _Value_ } , >
  endm
  IMAGE_POLICY_INT16 macro _PolicyId_,_Value_
   exitm <{ ImagePolicyEntryTypeInt16 , _PolicyId_ , ( const VOID * ) _Value_ } , >
  endm
  IMAGE_POLICY_UINT16 macro _PolicyId_,_Value_
   exitm <{ ImagePolicyEntryTypeUInt16 , _PolicyId_ , ( const VOID * ) _Value_ } , >
  endm
  IMAGE_POLICY_INT32 macro _PolicyId_,_Value_
   exitm <{ ImagePolicyEntryTypeInt32 , _PolicyId_ , ( const VOID * ) _Value_ } , >
  endm
  IMAGE_POLICY_UINT32 macro _PolicyId_,_Value_
   exitm <{ ImagePolicyEntryTypeUInt32 , _PolicyId_ , ( const VOID * ) _Value_ } , >
  endm
  IMAGE_POLICY_INT64 macro _PolicyId_,_Value_
   exitm <{ ImagePolicyEntryTypeInt64 , _PolicyId_ , ( const VOID * ) _Value_ } , >
  endm
  IMAGE_POLICY_UINT64 macro _PolicyId_,_Value_
   exitm <{ ImagePolicyEntryTypeUInt64 , _PolicyId_ , ( const VOID * ) _Value_ } , >
  endm
  IMAGE_POLICY_ANSI_STRING macro _PolicyId_,_Value_
   exitm <{ ImagePolicyEntryTypeAnsiString , _PolicyId_ , _Value_ } , >
  endm
  IMAGE_POLICY_UNICODE_STRING macro _PolicyId_,_Value_
   exitm <{ ImagePolicyEntryTypeUnicodeString , _PolicyId_ , _Value_ } , >
  endm
  IMAGE_POLICY_OVERRIDE macro _PolicyId_
   exitm <{ ImagePolicyEntryTypeOverride , _PolicyId_ , 0 } , >
  endm


    TRANSACTIONMANAGER_QUERY_INFORMATION equ 0001h
    TRANSACTIONMANAGER_SET_INFORMATION equ 0002h
    TRANSACTIONMANAGER_RECOVER equ 0004h
    TRANSACTIONMANAGER_RENAME equ 0008h
    TRANSACTIONMANAGER_CREATE_RM equ 0010h
    TRANSACTIONMANAGER_BIND_TRANSACTION equ 0020h
    TRANSACTIONMANAGER_GENERIC_READ equ <( STANDARD_RIGHTS_READ or TRANSACTIONMANAGER_QUERY_INFORMATION )>
    TRANSACTIONMANAGER_GENERIC_WRITE equ <( STANDARD_RIGHTS_WRITE or TRANSACTIONMANAGER_SET_INFORMATION or TRANSACTIONMANAGER_RECOVER or TRANSACTIONMANAGER_RENAME or TRANSACTIONMANAGER_CREATE_RM )>
    TRANSACTIONMANAGER_GENERIC_EXECUTE equ <( STANDARD_RIGHTS_EXECUTE )>
    TRANSACTIONMANAGER_ALL_ACCESS equ <( STANDARD_RIGHTS_REQUIRED or TRANSACTIONMANAGER_GENERIC_READ or TRANSACTIONMANAGER_GENERIC_WRITE or TRANSACTIONMANAGER_GENERIC_EXECUTE or TRANSACTIONMANAGER_BIND_TRANSACTION )>
    TRANSACTION_QUERY_INFORMATION equ 0001h
    TRANSACTION_SET_INFORMATION equ 0002h
    TRANSACTION_ENLIST equ 0004h
    TRANSACTION_COMMIT equ 0008h
    TRANSACTION_ROLLBACK equ 0010h
    TRANSACTION_PROPAGATE equ 0020h
    TRANSACTION_RIGHT_RESERVED1 equ 0040h
    TRANSACTION_GENERIC_READ equ <( STANDARD_RIGHTS_READ or TRANSACTION_QUERY_INFORMATION or SYNCHRONIZE )>
    TRANSACTION_GENERIC_WRITE equ <( STANDARD_RIGHTS_WRITE or TRANSACTION_SET_INFORMATION or TRANSACTION_COMMIT or TRANSACTION_ENLIST or TRANSACTION_ROLLBACK or TRANSACTION_PROPAGATE or SYNCHRONIZE )>
    TRANSACTION_GENERIC_EXECUTE equ <( STANDARD_RIGHTS_EXECUTE or TRANSACTION_COMMIT or TRANSACTION_ROLLBACK or SYNCHRONIZE )>
    TRANSACTION_ALL_ACCESS equ <( STANDARD_RIGHTS_REQUIRED or TRANSACTION_GENERIC_READ or TRANSACTION_GENERIC_WRITE or TRANSACTION_GENERIC_EXECUTE )>
    TRANSACTION_RESOURCE_MANAGER_RIGHTS equ <( TRANSACTION_GENERIC_READ or STANDARD_RIGHTS_WRITE or TRANSACTION_SET_INFORMATION or TRANSACTION_ENLIST or TRANSACTION_ROLLBACK or TRANSACTION_PROPAGATE or SYNCHRONIZE )>
    RESOURCEMANAGER_QUERY_INFORMATION equ 0001h
    RESOURCEMANAGER_SET_INFORMATION equ 0002h
    RESOURCEMANAGER_RECOVER equ 0004h
    RESOURCEMANAGER_ENLIST equ 0008h
    RESOURCEMANAGER_GET_NOTIFICATION equ 0010h
    RESOURCEMANAGER_REGISTER_PROTOCOL equ 0020h
    RESOURCEMANAGER_COMPLETE_PROPAGATION equ 0040h
    RESOURCEMANAGER_GENERIC_READ equ <( STANDARD_RIGHTS_READ or RESOURCEMANAGER_QUERY_INFORMATION or SYNCHRONIZE )>
    RESOURCEMANAGER_GENERIC_WRITE equ <( STANDARD_RIGHTS_WRITE or RESOURCEMANAGER_SET_INFORMATION or RESOURCEMANAGER_RECOVER or RESOURCEMANAGER_ENLIST or RESOURCEMANAGER_GET_NOTIFICATION or RESOURCEMANAGER_REGISTER_PROTOCOL or RESOURCEMANAGER_COMPLETE_PROPAGATION or SYNCHRONIZE )>
    RESOURCEMANAGER_GENERIC_EXECUTE equ <( STANDARD_RIGHTS_EXECUTE or RESOURCEMANAGER_RECOVER or RESOURCEMANAGER_ENLIST or RESOURCEMANAGER_GET_NOTIFICATION or RESOURCEMANAGER_COMPLETE_PROPAGATION or SYNCHRONIZE )>
    RESOURCEMANAGER_ALL_ACCESS equ <( STANDARD_RIGHTS_REQUIRED or RESOURCEMANAGER_GENERIC_READ or RESOURCEMANAGER_GENERIC_WRITE or RESOURCEMANAGER_GENERIC_EXECUTE )>
    ENLISTMENT_QUERY_INFORMATION equ 0001h
    ENLISTMENT_SET_INFORMATION equ 0002h
    ENLISTMENT_RECOVER equ 0004h
    ENLISTMENT_SUBORDINATE_RIGHTS equ 0008h
    ENLISTMENT_SUPERIOR_RIGHTS equ 0010h
    ENLISTMENT_GENERIC_READ equ <( STANDARD_RIGHTS_READ or ENLISTMENT_QUERY_INFORMATION )>
    ENLISTMENT_GENERIC_WRITE equ <( STANDARD_RIGHTS_WRITE or ENLISTMENT_SET_INFORMATION or ENLISTMENT_RECOVER or ENLISTMENT_SUBORDINATE_RIGHTS or ENLISTMENT_SUPERIOR_RIGHTS )>
    ENLISTMENT_GENERIC_EXECUTE equ <( STANDARD_RIGHTS_EXECUTE or ENLISTMENT_RECOVER or ENLISTMENT_SUBORDINATE_RIGHTS or ENLISTMENT_SUPERIOR_RIGHTS )>
    ENLISTMENT_ALL_ACCESS equ <( STANDARD_RIGHTS_REQUIRED or ENLISTMENT_GENERIC_READ or ENLISTMENT_GENERIC_WRITE or ENLISTMENT_GENERIC_EXECUTE )>
    TRANSACTION_OUTCOME typedef SDWORD
    TransactionOutcomeUndetermined EQU 1 
    TransactionOutcomeCommitted EQU 2
    TransactionOutcomeAborted EQU 3
    
    TRANSACTION_STATE typedef SDWORD
    TransactionStateNormal EQU 1 
    TransactionStateIndoubt EQU 2
    TransactionStateCommittedNotify EQU 3
    
    TRANSACTION_BASIC_INFORMATION struct
      TransactionId GUID <>
      State DWORD ?
      Outcome DWORD ?
    TRANSACTION_BASIC_INFORMATION ends

    PTRANSACTION_BASIC_INFORMATION typedef ptr TRANSACTION_BASIC_INFORMATION
    
    TRANSACTIONMANAGER_BASIC_INFORMATION struct
      TmIdentity GUID <>
      VirtualClock LARGE_INTEGER <>
    TRANSACTIONMANAGER_BASIC_INFORMATION ends

    PTRANSACTIONMANAGER_BASIC_INFORMATION typedef ptr TRANSACTIONMANAGER_BASIC_INFORMATION
    
    TRANSACTIONMANAGER_LOG_INFORMATION struct
      LogIdentity GUID <>
    TRANSACTIONMANAGER_LOG_INFORMATION ends

    PTRANSACTIONMANAGER_LOG_INFORMATION typedef ptr TRANSACTIONMANAGER_LOG_INFORMATION
    
    TRANSACTIONMANAGER_LOGPATH_INFORMATION struct
      LogPathLength DWORD ?
      LogPath WCHAR 1 dup (?)
    TRANSACTIONMANAGER_LOGPATH_INFORMATION ends

    PTRANSACTIONMANAGER_LOGPATH_INFORMATION typedef ptr TRANSACTIONMANAGER_LOGPATH_INFORMATION
    
    TRANSACTIONMANAGER_RECOVERY_INFORMATION struct
      LastRecoveredLsn QWORD ?
    TRANSACTIONMANAGER_RECOVERY_INFORMATION ends

    PTRANSACTIONMANAGER_RECOVERY_INFORMATION typedef ptr TRANSACTIONMANAGER_RECOVERY_INFORMATION
    
    TRANSACTION_PROPERTIES_INFORMATION struct
      IsolationLevel DWORD ?
      IsolationFlags DWORD ?
      Timeout LARGE_INTEGER <>
      Outcome DWORD ?
      DescriptionLength DWORD ?
      Description WCHAR 1 dup (?)
    TRANSACTION_PROPERTIES_INFORMATION ends

    PTRANSACTION_PROPERTIES_INFORMATION typedef ptr TRANSACTION_PROPERTIES_INFORMATION
    
    TRANSACTION_BIND_INFORMATION struct
      TmHandle HANDLE ?
    TRANSACTION_BIND_INFORMATION ends

    PTRANSACTION_BIND_INFORMATION typedef ptr TRANSACTION_BIND_INFORMATION
    
    TRANSACTION_ENLISTMENT_PAIR struct
      EnlistmentId GUID <>
      ResourceManagerId GUID <>
    TRANSACTION_ENLISTMENT_PAIR ends

    PTRANSACTION_ENLISTMENT_PAIR typedef ptr TRANSACTION_ENLISTMENT_PAIR
    
    TRANSACTION_ENLISTMENTS_INFORMATION struct
      NumberOfEnlistments DWORD ?
      EnlistmentPair TRANSACTION_ENLISTMENT_PAIR 1 dup (<>)
    TRANSACTION_ENLISTMENTS_INFORMATION ends

    PTRANSACTION_ENLISTMENTS_INFORMATION typedef ptr TRANSACTION_ENLISTMENTS_INFORMATION
    
    TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION struct
      SuperiorEnlistmentPair TRANSACTION_ENLISTMENT_PAIR <>
    TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION ends

    PTRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION typedef ptr TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION
    
    RESOURCEMANAGER_BASIC_INFORMATION struct
      ResourceManagerId GUID <>
      DescriptionLength DWORD ?
      Description WCHAR 1 dup (?)
    RESOURCEMANAGER_BASIC_INFORMATION ends

    PRESOURCEMANAGER_BASIC_INFORMATION typedef ptr RESOURCEMANAGER_BASIC_INFORMATION
    
    RESOURCEMANAGER_COMPLETION_INFORMATION struct
      IoCompletionPortHandle HANDLE ?
      CompletionKey ULONG_PTR ?
    RESOURCEMANAGER_COMPLETION_INFORMATION ends

    PRESOURCEMANAGER_COMPLETION_INFORMATION typedef ptr RESOURCEMANAGER_COMPLETION_INFORMATION
    
    TRANSACTION_INFORMATION_CLASS typedef SDWORD
    TransactionBasicInformation EQU 0
    TransactionPropertiesInformation EQU 1
    TransactionEnlistmentInformation EQU 2
    TransactionSuperiorEnlistmentInformation EQU 3
    
    TRANSACTIONMANAGER_INFORMATION_CLASS typedef SDWORD
    TransactionManagerBasicInformation EQU 0
    TransactionManagerLogInformation EQU 1
    TransactionManagerLogPathInformation EQU 2
    TransactionManagerRecoveryInformation EQU 4 
    
    RESOURCEMANAGER_INFORMATION_CLASS typedef SDWORD
    ResourceManagerBasicInformation EQU 0
    ResourceManagerCompletionInformation EQU 1
    
    ENLISTMENT_BASIC_INFORMATION struct
      EnlistmentId GUID <>
      TransactionId GUID <>
      ResourceManagerId GUID <>
    ENLISTMENT_BASIC_INFORMATION ends

    PENLISTMENT_BASIC_INFORMATION typedef ptr ENLISTMENT_BASIC_INFORMATION
    
    ENLISTMENT_CRM_INFORMATION struct
      CrmTransactionManagerId GUID <>
      CrmResourceManagerId GUID <>
      CrmEnlistmentId GUID <>
    ENLISTMENT_CRM_INFORMATION ends

    PENLISTMENT_CRM_INFORMATION typedef ptr ENLISTMENT_CRM_INFORMATION
    
    ENLISTMENT_INFORMATION_CLASS typedef SDWORD
    EnlistmentBasicInformation EQU 0
    EnlistmentRecoveryInformation EQU 1
    EnlistmentCrmInformation EQU 2
    
    UOW TYPEDEF GUID    
    
    TRANSACTION_LIST_ENTRY struct
      tUOW UOW <>
    TRANSACTION_LIST_ENTRY ends

    PTRANSACTION_LIST_ENTRY typedef ptr TRANSACTION_LIST_ENTRY
    
    TRANSACTION_LIST_INFORMATION struct
      NumberOfTransactions DWORD ?
      TransactionInformation TRANSACTION_LIST_ENTRY 1 dup (<>)
    TRANSACTION_LIST_INFORMATION ends

    PTRANSACTION_LIST_INFORMATION typedef ptr TRANSACTION_LIST_INFORMATION
    
    KTMOBJECT_TYPE typedef SDWORD
    KTMOBJECT_TRANSACTION EQU 0
    KTMOBJECT_TRANSACTION_MANAGER EQU 1
    KTMOBJECT_RESOURCE_MANAGER EQU 2
    KTMOBJECT_ENLISTMENT EQU 3
    KTMOBJECT_INVALID EQU 4
    
    PKTMOBJECT_TYPE typedef ptr KTMOBJECT_TYPE
    
    KTMOBJECT_CURSOR struct
      LastQuery GUID <>
      ObjectIdCount DWORD ?
      ObjectIds GUID 1 dup (<>)
    KTMOBJECT_CURSOR ends

    PKTMOBJECT_CURSOR typedef ptr KTMOBJECT_CURSOR


  ALIGN_DOWN_BY macro length,alignment
   exitm <( ( length ) and not ( alignment - 1 ) ) >
  endm
  ALIGN_UP_BY macro length,alignment
   exitm <( ALIGN_DOWN_BY ( ( ( length ) + alignment - 1 ) , alignment ) ) >
  endm
  ALIGN_DOWN_POINTER_BY macro address,alignment
   exitm <( ( ( address ) and not ( alignment - 1 ) ) ) >
  endm
  ALIGN_UP_POINTER_BY macro address,alignment
   exitm <( ALIGN_DOWN_POINTER_BY ( ( ( address ) + alignment - 1 ) , alignment ) ) >
  endm
  ALIGN_DOWN macro length,type
   exitm <ALIGN_DOWN_BY ( length , sizeof ( type ) ) >
  endm
  ALIGN_UP macro length,type
   exitm <ALIGN_UP_BY ( length , sizeof ( type ) ) >
  endm
  ALIGN_DOWN_POINTER macro address,type
   exitm <ALIGN_DOWN_POINTER_BY ( address , sizeof ( type ) ) >
  endm
  ALIGN_UP_POINTER macro address,type
   exitm <ALIGN_UP_POINTER_BY ( address , sizeof ( type ) ) >
  endm
  ifndef FIELD_OFFSET
    FIELD_OFFSET macro type,field
     exitm <( and ( ( ( type * ) 0 ) - field ) ) >
    endm
  endif
  ifndef FIELD_SIZE
    FIELD_SIZE macro type,field
     exitm <( sizeof ( ( ( type * ) 0 ) - field ) ) >
    endm
  endif



  ALLOCATE_FUNCTION typedef proto stdcall :POOL_TYPE,:SIZE_T,:DWORD
  PALLOCATE_FUNCTION typedef ptr ALLOCATE_FUNCTION
  FREE_FUNCTION typedef proto stdcall :PVOID
  PFREE_FUNCTION typedef ptr FREE_FUNCTION
  PLOOKASIDE_LIST_EX typedef ptr _LOOKASIDE_LIST_EX
  
  ALLOCATE_FUNCTION_EX typedef proto stdcall :POOL_TYPE,:SIZE_T,:DWORD,:PLOOKASIDE_LIST_EX
  PALLOCATE_FUNCTION_EX typedef ptr ALLOCATE_FUNCTION_EX
  FREE_FUNCTION_EX typedef proto stdcall :PVOID,:PLOOKASIDE_LIST_EX
  PFREE_FUNCTION_EX typedef ptr FREE_FUNCTION_EX


;  GENERAL_LOOKASIDE_LAYOUT equ union { SLIST_HEADER ListHead ; SINGLE_LIST_ENTRY SingleListHead ; } DUMMYUNIONNAME ; USHORT Depth ; USHORT MaximumDepth ; ULONG TotalAllocates ; union { ULONG AllocateMisses ; ULONG AllocateHits ; } DUMMYUNIONNAME2 ; ULONG TotalFrees ; union { ULONG FreeMisses ; ULONG FreeHits ; } DUMMYUNIONNAME3 ; POOL_TYPE Type ; ULONG Tag ; ULONG Size ; union { PALLOCATE_FUNCTION_EX AllocateEx ; PALLOCATE_FUNCTION Allocate ; } DUMMYUNIONNAME4 ; union { PFREE_FUNCTION_EX FreeEx ; PFREE_FUNCTION Free ; } DUMMYUNIONNAME5 ; LIST_ENTRY ListEntry ; ULONG LastTotalAllocates ; union { ULONG LastAllocateMisses ; ULONG LastAllocateHits ; } DUMMYUNIONNAME6 ; ULONG Future [ 2 ] ;
;
;
;  GENERAL_LOOKASIDE_POOL struct
;    GENERAL_LOOKASIDE_LAYOUT DWORD ?
;  GENERAL_LOOKASIDE_POOL ends
;
;  PGENERAL_LOOKASIDE_POOL typedef ptr GENERAL_LOOKASIDE_POOL


;  KPROCESSOR_MODE typedef CCHAR
  MODE typedef SDWORD
  KernelMode EQU 0
  UserMode EQU 1
  MaximumMode EQU 2
  
  KSYNCHRONIZE_ROUTINE typedef proto stdcall :PVOID
  PKSYNCHRONIZE_ROUTINE typedef ptr KSYNCHRONIZE_ROUTINE
  
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
    PRKAPC typedef ptr KAPC
  
  KAPC_OFFSET_TO_SPARE_BYTE0 equ <FIELD_OFFSET ( KAPC , SpareByte0 )>
  KAPC_OFFSET_TO_SPARE_BYTE1 equ <FIELD_OFFSET ( KAPC , SpareByte1 )>
  KAPC_OFFSET_TO_SPARE_LONG equ <FIELD_OFFSET ( KAPC , SpareLong0 )>
  KAPC_OFFSET_TO_SYSTEMARGUMENT1 equ <FIELD_OFFSET ( KAPC , SystemArgument1 )>
  KAPC_OFFSET_TO_SYSTEMARGUMENT2 equ <FIELD_OFFSET ( KAPC , SystemArgument2 )>
  KAPC_OFFSET_TO_APCSTATEINDEX equ <FIELD_OFFSET ( KAPC , ApcStateIndex )>
  KAPC_ACTUAL_LENGTH equ <( FIELD_OFFSET ( KAPC , Inserted ) + sizeof ( BOOLEAN ) )>

  KDPC_IMPORTANCE typedef SDWORD
  LowImportance EQU 0
  MediumImportance EQU 1
  HighImportance EQU 2
  MediumHighImportance EQU 3
  
  DPC_NORMAL equ 0
  DPC_THREADED equ 1
  
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
    PKDPC typedef ptr KDPC
    PRKDPC typedef ptr KDPC


    PAGE_SIZE equ 1000h
    PAGE_SHIFT equ 12

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
    PMDL typedef ptr MDL
    PMDLX typedef ptr MDL
    
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
    

    KENCODED_TIMER_PROCESSOR equ 1

  TIMER_TOLERABLE_DELAY_BITS equ 6
  TIMER_EXPIRED_INDEX_BITS equ 6
  TIMER_PROCESSOR_INDEX_BITS equ 5

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
  
  KEVENT struct
    Header DISPATCHER_HEADER <>
  KEVENT ends

  PKEVENT typedef ptr KEVENT
  PRKEVENT typedef ptr KEVENT
  
  KGATE struct
    Header DISPATCHER_HEADER <>
  KGATE ends

  PKGATE typedef ptr KGATE
  
  KTIMER struct
    Header DISPATCHER_HEADER <>
    DueTime ULARGE_INTEGER <>
    TimerListEntry LIST_ENTRY <>
    Dpc POINTER ?
    ;if  not defined(KENCODED_TIMER_PROCESSOR)
      Processor DWORD ?
    ;endif
    Period DWORD ?
  KTIMER ends

  PKTIMER typedef ptr KTIMER
  PRKTIMER typedef ptr KTIMER
  
  KTIMER_ACTUAL_LENGTH equ <( FIELD_OFFSET ( KTIMER , Period ) + sizeof ( LONG ) )>
  LOCK_OPERATION typedef SDWORD
  IoReadAccess EQU 0
  IoWriteAccess EQU 1
  IoModifyAccess EQU 2
  
  FAST_MUTEX struct
    Count SDWORD ?
    Owner PVOID ?
    Contention DWORD ?
    Event_ KEVENT <>
    OldIrql DWORD ?
  FAST_MUTEX ends

  PFAST_MUTEX typedef ptr FAST_MUTEX
  KGUARDED_MUTEX typedef FAST_MUTEX
  PKGUARDED_MUTEX typedef ptr FAST_MUTEX
  

    PFN_COUNT typedef DWORD
    SPFN_NUMBER typedef SDWORD
    PSPFN_NUMBER typedef ptr SDWORD
    PFN_NUMBER typedef DWORD
    PPFN_NUMBER typedef ptr DWORD
    FLUSH_MULTIPLE_MAXIMUM equ 32
    ALLOC_PRAGMA equ 1
    ALLOC_DATA_PRAGMA equ 1

      KfLowerIrql proto fastcall :KIRQL

      KfRaiseIrql proto fastcall :KIRQL

    KeLowerIrql macro a
     exitm <KfLowerIrql ( a ) >
    endm
    KeRaiseIrql macro a,b
     exitm <* ( b ) = KfRaiseIrql ( a ) >
    endm

      KeRaiseIrqlToDpcLevel proto fastcall


    KeGetDcacheFillSize macro 
     exitm <1 >
    endm

      KeFlushIoBuffers proto fastcall :PMDL, :BOOLEAN, :BOOLEAN

    ExAcquireSpinLock macro Lock,OldIrql
     exitm <KeAcquireSpinLock ( ( Lock ) , ( OldIrql ) ) >
    endm
    ExReleaseSpinLock macro Lock,OldIrql
     exitm <KeReleaseSpinLock ( ( Lock ) , ( OldIrql ) ) >
    endm
    ExAcquireSpinLockAtDpcLevel macro Lock
     exitm <KeAcquireSpinLockAtDpcLevel ( Lock ) >
    endm
    ExReleaseSpinLockFromDpcLevel macro Lock
     exitm <KeReleaseSpinLockFromDpcLevel ( Lock ) >
    endm

    KFLOATING_SAVE struct
      ControlWord DWORD ?
      StatusWord DWORD ?
      ErrorOffset DWORD ?
      ErrorSelector DWORD ?
      DataOffset DWORD ?
      DataSelector DWORD ?
      Spare0 DWORD ?
      Spare1 DWORD ?
    KFLOATING_SAVE ends

    PKFLOATING_SAVE typedef ptr KFLOATING_SAVE
    
    AMD_L1_CACHE_INFO union
      Ulong DWORD ?
      struct
        LineSize BYTE ?
        LinesPerTag BYTE ?
        Associativity BYTE ?
        Size_ BYTE ?
      ends
    AMD_L1_CACHE_INFO ends

    PAMD_L1_CACHE_INFO typedef ptr AMD_L1_CACHE_INFO
    
    AMD_L2_CACHE_INFO union
      Ulong DWORD ?
      struct
        LineSize BYTE ?
        AMD_L2_CACHE_INFO_??19 record LinesPerTag_??19:4, Associativity_??19:4
        AMD_L2_CACHE_INFO_??19 <>
        Size_ WORD ?
      ends
    AMD_L2_CACHE_INFO ends

    PAMD_L2_CACHE_INFO typedef ptr AMD_L2_CACHE_INFO
    
    AMD_L3_CACHE_INFO union
      Ulong DWORD ?
      struct
        LineSize BYTE ?
        AMD_L3_CACHE_INFO_??20 record LinesPerTag_??20:4, Associativity_??20:4, Reserved_??210:2, Size_??20:14
        AMD_L3_CACHE_INFO_??20 <>
      ends
    AMD_L3_CACHE_INFO ends

    PAMD_L3_CACHE_INFO typedef ptr AMD_L3_CACHE_INFO
    
    INTEL_CACHE_TYPE typedef SDWORD
    IntelCacheNull EQU 0
    IntelCacheData EQU 1
    IntelCacheInstruction EQU 2
    IntelCacheUnified EQU 3
    IntelCacheRam EQU 4
    IntelCacheTrace EQU 5
    
    INTEL_CACHE_INFO_EAX union
      Ulong DWORD ?
      struct
        INTEL_CACHE_INFO_EAX_??21 record Type_??21:5, Level_??21:3, SelfInitializing_??21:1, FullyAssociative_??21:1, Reserved_??21:4, ThreadsSharing_??21:12, ProcessorCores_??21:6
        INTEL_CACHE_INFO_EAX_??21 <>
      ends
    INTEL_CACHE_INFO_EAX ends

    PINTEL_CACHE_INFO_EAX typedef ptr INTEL_CACHE_INFO_EAX
    
    INTEL_CACHE_INFO_EBX union
      Ulong DWORD ?
      struct
        INTEL_CACHE_INFO_EBX_??22 record LineSize_??22:12, Partitions_??22:10, Associativity_??22:10
        INTEL_CACHE_INFO_EBX_??22 <>
      ends
    INTEL_CACHE_INFO_EBX ends

    PINTEL_CACHE_INFO_EBX typedef ptr INTEL_CACHE_INFO_EBX
    
    MmGetProcedureAddress macro Address
     exitm <( Address ) >
    endm
    MmLockPagableCodeSection macro Address
     exitm <MmLockPagableDataSection ( Address ) >
    endm



      KeGetCurrentIrql proto stdcall

        KeGetCurrentProcessorIndex proto stdcall

    CacheLineFlush macro Address
     exitm <_mm_clflush ( Address ) >
    endm
    _mm_clflush proto fastcall :ptr 
    ;#pragma intrinsic ( _mm_clflush )
    InvalidatePage macro Page
     exitm <__invlpg ( Page ) >
    endm
    __invlpg proto fastcall :PVOID
    WritebackInvalidate macro 
     exitm <__wbinvd ( ) >
    endm
    __wbinvd proto fastcall
    ;#pragma intrinsic ( __invlpg )
    ;#pragma intrinsic ( __wbinvd )
    ReadCR3 macro 
     exitm <__readcr3 ( ) >
    endm
    __readcr3 proto fastcall
    WriteCR3 macro Data
     exitm <__writecr3 ( Data ) >
    endm
    __writecr3 proto fastcall :UINT32

    __readeflags proto fastcall
    ReadEflags macro 
     exitm <__readeflags ( ) >
    endm

    _ReadWriteBarrier proto fastcall

    KeMemoryBarrier proto fastcall

    KeMemoryBarrierWithoutFence macro 
     exitm <_ReadWriteBarrier ( ) >
    endm




    __inbyte proto fastcall :WORD
    __inword proto fastcall :WORD
    __indword proto fastcall :WORD
    __outbyte proto fastcall :WORD, :BYTE
    __outword proto fastcall :WORD, :WORD
    __outdword proto fastcall :WORD, :DWORD
    __inbytestring proto fastcall :WORD, :PUCHAR, :DWORD
    __inwordstring proto fastcall :WORD, :PUSHORT, :DWORD
    __indwordstring proto fastcall :WORD, :PULONG, :DWORD
    __outbytestring proto fastcall :WORD, :PUCHAR, :DWORD
    __outwordstring proto fastcall :WORD, :PUSHORT, :DWORD
    __outdwordstring proto fastcall :WORD, :PULONG, :DWORD


    PFN_COUNT typedef DWORD



    ALLOC_PRAGMA equ 1
    ALLOC_DATA_PRAGMA equ 1

    ReadCR8 macro 
     exitm <__readcr8 ( ) >
    endm
    __readcr8 proto fastcall
    WriteCR8 macro Data
     exitm <__writecr8 ( Data ) >
    endm
    __writecr8 proto fastcall :ULONG64

    KeGetDcacheFillSize macro 
     exitm <1 >
    endm


    ExAcquireSpinLock macro Lock,OldIrql
     exitm <KeAcquireSpinLock ( ( Lock ) , ( OldIrql ) ) >
    endm
    ExReleaseSpinLock macro Lock,OldIrql
     exitm <KeReleaseSpinLock ( ( Lock ) , ( OldIrql ) ) >
    endm
    ExAcquireSpinLockAtDpcLevel macro Lock
     exitm <KeAcquireSpinLockAtDpcLevel ( Lock ) >
    endm
    ExReleaseSpinLockFromDpcLevel macro Lock
     exitm <KeReleaseSpinLockFromDpcLevel ( Lock ) >
    endm


    PKFLOATING_SAVE typedef ptr KFLOATING_SAVE
    
    MmGetProcedureAddress macro Address
     exitm <( Address ) >
    endm
    MmLockPagableCodeSection macro Address
     exitm <MmLockPagableDataSection ( Address ) >
    endm


 
      KeMemoryBarrier proto fastcall
      KeMemoryBarrierWithoutFence macro 
       exitm <_ReadWriteBarrier ( ) >
      endm


    KeSaveFloatingPointState proto fastcall :PKFLOATING_SAVE

    KeRestoreFloatingPointState proto fastcall :PKFLOATING_SAVE


    KeRaiseIrql macro a,b
     exitm <* ( b ) = KfRaiseIrql ( a ) >
    endm



      KzLowerIrql proto fastcall :KIRQL
      KzRaiseIrql proto fastcall :KIRQL




  FIRMWARE_TYPE typedef SDWORD
  FirmwareTypeUnknown EQU 0
  FirmwareTypeBios EQU 1
  FirmwareTypeUefi EQU 2
  FirmwareTypeMax EQU 3
  
  PFIRMWARE_TYPE typedef ptr FIRMWARE_TYPE
  
  EVENT_QUERY_STATE equ 0001h
  EVENT_MODIFY_STATE equ 0002h
  EVENT_ALL_ACCESS equ ( STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 3h )
  SEMAPHORE_QUERY_STATE equ 0001h
  SEMAPHORE_MODIFY_STATE equ 0002h
  SEMAPHORE_ALL_ACCESS equ ( STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 3h )
  LOGICAL_PROCESSOR_RELATIONSHIP typedef SDWORD
  RelationProcessorCore EQU 0
  RelationNumaNode EQU 1
  RelationCache EQU 2
  RelationProcessorPackage EQU 3
  RelationGroup EQU 4
  RelationAll EQU 0ffffh 
  
  LTP_PC_SMT equ 1h
  PROCESSOR_CACHE_TYPE typedef SDWORD
  CacheUnified EQU 0
  CacheInstruction EQU 1
  CacheData EQU 2
  CacheTrace EQU 3
  
  CACHE_FULLY_ASSOCIATIVE equ 0FFh
  CACHE_DESCRIPTOR struct
    Level BYTE ?
    Associativity BYTE ?
    LineSize WORD ?
    Size_ DWORD ?
    Type_ PROCESSOR_CACHE_TYPE ?
  CACHE_DESCRIPTOR ends

  PCACHE_DESCRIPTOR typedef ptr CACHE_DESCRIPTOR
  
  SYSTEM_LOGICAL_PROCESSOR_INFORMATION struct
    ProcessorMask ULONG_PTR ?
    Relationship LOGICAL_PROCESSOR_RELATIONSHIP ?
    union DUMMYUNIONNAME_24
      struct ProcessorCore
        Flags BYTE ?
      ends
      struct NumaNode
        NodeNumber DWORD ?
      ends
      Cache CACHE_DESCRIPTOR <>
      Reserved QWORD 2 dup (?)
    ends
  SYSTEM_LOGICAL_PROCESSOR_INFORMATION ends

  PSYSTEM_LOGICAL_PROCESSOR_INFORMATION typedef ptr SYSTEM_LOGICAL_PROCESSOR_INFORMATION
  
  PROCESSOR_RELATIONSHIP struct
    Flags BYTE ?
    EfficiencyClass BYTE ?
    Reserved BYTE 20 dup (?)
    GroupCount WORD ?
    GroupMask GROUP_AFFINITY ANYSIZE_ARRAY dup (<>)
  PROCESSOR_RELATIONSHIP ends

  PPROCESSOR_RELATIONSHIP typedef ptr PROCESSOR_RELATIONSHIP
  
  NUMA_NODE_RELATIONSHIP struct
    NodeNumber DWORD ?
    Reserved BYTE 20 dup (?)
    GroupMask GROUP_AFFINITY <>
  NUMA_NODE_RELATIONSHIP ends

  PNUMA_NODE_RELATIONSHIP typedef ptr NUMA_NODE_RELATIONSHIP
  
  CACHE_RELATIONSHIP struct
    Level BYTE ?
    Associativity BYTE ?
    LineSize WORD ?
    CacheSize DWORD ?
    Type_ PROCESSOR_CACHE_TYPE ?
    Reserved BYTE 20 dup (?)
    GroupMask GROUP_AFFINITY <>
  CACHE_RELATIONSHIP ends

  PCACHE_RELATIONSHIP typedef ptr CACHE_RELATIONSHIP
  
  PROCESSOR_GROUP_INFO struct
    MaximumProcessorCount BYTE ?
    ActiveProcessorCount BYTE ?
    Reserved BYTE 38 dup (?)
    ActiveProcessorMask KAFFINITY ?
  PROCESSOR_GROUP_INFO ends

  PPROCESSOR_GROUP_INFO typedef ptr PROCESSOR_GROUP_INFO
  
  GROUP_RELATIONSHIP struct
    MaximumGroupCount WORD ?
    ActiveGroupCount WORD ?
    Reserved BYTE 20 dup (?)
    GroupInfo PROCESSOR_GROUP_INFO ANYSIZE_ARRAY dup (<>)
  GROUP_RELATIONSHIP ends

  PGROUP_RELATIONSHIP typedef ptr GROUP_RELATIONSHIP
  
  ;{
  DUMMYUNIONNAME_25 union
    Processor PROCESSOR_RELATIONSHIP <>
    NumaNode NUMA_NODE_RELATIONSHIP <>
    Cache CACHE_RELATIONSHIP <>
    Group_ GROUP_RELATIONSHIP <>
  DUMMYUNIONNAME_25 ends

  
  CPU_SET_INFORMATION_TYPE typedef SDWORD
  CpuSetInformation EQU 0
  
  PCPU_SET_INFORMATION_TYPE typedef ptr CPU_SET_INFORMATION_TYPE

  DUMMYUNIONNAME_26 union
    struct CpuSet
      Id DWORD ?
      Group_ WORD ?
      LogicalProcessorIndex BYTE ?
      CoreIndex BYTE ?
      LastLevelCacheIndex BYTE ?
      NumaNodeIndex BYTE ?
      EfficiencyClass BYTE ?
      union DUMMYUNIONNAME2
        SYSTEM_CPU_SET_INFORMATION_PARKED equ 1h
        SYSTEM_CPU_SET_INFORMATION_ALLOCATED equ 2h
        SYSTEM_CPU_SET_INFORMATION_ALLOCATED_TO_TARGET_PROCESS equ 4h
        SYSTEM_CPU_SET_INFORMATION_REALTIME equ 8h
        AllFlags BYTE ?
        struct DUMMYSTRUCTNAME_27
          DUMMYSTRUCTNAME_27_??25 record Parked_??25:1, Allocated_??25:1, AllocatedToTargetProcess_??25:1, RealTime_??25:1, ReservedFlags_??25:4
          DUMMYSTRUCTNAME_27_??25 <>
        ends
      ends
      union
        Reserved DWORD ?
        SchedulingClass BYTE ?
      ends
      AllocationTag ULONG64 ?
    ends
  DUMMYUNIONNAME_26 ends


  
  PF_FLOATING_POINT_PRECISION_ERRATA equ 0
  PF_FLOATING_POINT_EMULATED equ 1
  PF_COMPARE_EXCHANGE_DOUBLE equ 2
  PF_MMX_INSTRUCTIONS_AVAILABLE equ 3
  PF_PPC_MOVEMEM_64BIT_OK equ 4
  PF_ALPHA_BYTE_INSTRUCTIONS equ 5
  PF_XMMI_INSTRUCTIONS_AVAILABLE equ 6
  PF_3DNOW_INSTRUCTIONS_AVAILABLE equ 7
  PF_RDTSC_INSTRUCTION_AVAILABLE equ 8
  PF_PAE_ENABLED equ 9
  PF_XMMI64_INSTRUCTIONS_AVAILABLE equ 10
  PF_SSE_DAZ_MODE_AVAILABLE equ 11
  PF_NX_ENABLED equ 12
  PF_SSE3_INSTRUCTIONS_AVAILABLE equ 13
  PF_COMPARE_EXCHANGE128 equ 14
  PF_COMPARE64_EXCHANGE128 equ 15
  PF_CHANNELS_ENABLED equ 16
  PF_XSAVE_ENABLED equ 17
  PF_ARM_VFP_32_REGISTERS_AVAILABLE equ 18
  PF_ARM_NEON_INSTRUCTIONS_AVAILABLE equ 19
  PF_SECOND_LEVEL_ADDRESS_TRANSLATION equ 20
  PF_VIRT_FIRMWARE_ENABLED equ 21
  PF_RDWRFSGSBASE_AVAILABLE equ 22
  PF_FASTFAIL_AVAILABLE equ 23
  PF_ARM_DIVIDE_INSTRUCTION_AVAILABLE equ 24
  PF_ARM_64BIT_LOADSTORE_ATOMIC equ 25
  PF_ARM_EXTERNAL_CACHE_AVAILABLE equ 26
  PF_ARM_FMAC_INSTRUCTIONS_AVAILABLE equ 27
  PF_RDRAND_INSTRUCTION_AVAILABLE equ 28
  PF_ARM_V8_INSTRUCTIONS_AVAILABLE equ 29
  PF_ARM_V8_CRYPTO_INSTRUCTIONS_AVAILABLE equ 30
  PF_ARM_V8_CRC32_INSTRUCTIONS_AVAILABLE equ 31
  PF_RDTSCP_INSTRUCTION_AVAILABLE equ 32
  
  ;ALTERNATIVE_ARCHITECTURE_TYPE
  StandardDesign EQU 0
  NEC98x86 EQU 1
  EndAlternatives EQU 2
  

  PROCESSOR_FEATURE_MAX equ 64
  EXCEPTION_NONCONTINUABLE equ 1h
  EXCEPTION_UNWINDING equ 2h
  EXCEPTION_EXIT_UNWIND equ 4h
  EXCEPTION_STACK_INVALID equ 8h
  EXCEPTION_NESTED_CALL equ 10h
  EXCEPTION_TARGET_UNWIND equ 20h
  EXCEPTION_COLLIDED_UNWIND equ 40h
  EXCEPTION_UNWIND equ <( EXCEPTION_UNWINDING or EXCEPTION_EXIT_UNWIND or EXCEPTION_TARGET_UNWIND or EXCEPTION_COLLIDED_UNWIND )>
  IS_UNWINDING macro Flag
   exitm <( ( Flag and EXCEPTION_UNWIND ) != 0 ) >
  endm
  IS_DISPATCHING macro Flag
   exitm <( ( Flag and EXCEPTION_UNWIND ) == 0 ) >
  endm
  IS_TARGET_UNWIND macro Flag
   exitm <( Flag and EXCEPTION_TARGET_UNWIND ) >
  endm
  
  
    EXCEPTION_MAXIMUM_PARAMETERS equ 15
    
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
  
    IFNDEF EXCEPTION_POINTERS
    EXCEPTION_POINTERS STRUCT
    	ExceptionRecord	PVOID	?	; PTR EXCEPTION_RECORD
    	ContextRecord	PVOID	?	; PTR CONTEXT
    EXCEPTION_POINTERS ENDS
    ENDIF
    PEXCEPTION_POINTERS typedef PTR EXCEPTION_POINTERS
  
  THREAD_WAIT_OBJECTS equ 3


    ;SINGLE_GROUP_LEGACY_API equ 1

  KINTERRUPT_MODE typedef SDWORD
  LevelSensitive EQU 0
  Latched EQU 1
  
  KINTERRUPT_POLARITY typedef SDWORD
  InterruptPolarityUnknown EQU 0
  InterruptActiveHigh EQU 1
  InterruptRisingEdge EQU InterruptActiveHigh 
  InterruptActiveLow EQU 1
  InterruptFallingEdge EQU InterruptActiveLow 

    InterruptActiveBoth EQU 1


    InterruptActiveBothTriggerLow EQU InterruptActiveBoth 
    InterruptActiveBothTriggerHigh EQU 1

  
  PKINTERRUPT_POLARITY typedef ptr KINTERRUPT_POLARITY
  
  KWAIT_REASON typedef SDWORD
  Executive EQU 0
  FreePage EQU 1
  PageIn EQU 2
  PoolAllocation EQU 3
  DelayExecution EQU 4
  Suspended EQU 5
  UserRequest EQU 6
  WrExecutive EQU 7
  WrFreePage EQU 8
  WrPageIn EQU 9
  WrPoolAllocation EQU 10
  WrDelayExecution EQU 11
  WrSuspended EQU 12
  WrUserRequest EQU 13
  WrSpare0 EQU 14
  WrQueue EQU 15
  WrLpcReceive EQU 16
  WrLpcReply EQU 17
  WrVirtualMemory EQU 18
  WrPageOut EQU 19
  WrRendezvous EQU 20
  WrKeyedEvent EQU 21
  WrTerminated EQU 22
  WrProcessInSwap EQU 23
  WrCpuRateControl EQU 24
  WrCalloutStack EQU 25
  WrKernel EQU 26
  WrResource EQU 27
  WrPushLock EQU 28
  WrMutex EQU 29
  WrQuantumEnd EQU 30
  WrDispatchInt EQU 31
  WrPreempted EQU 32
  WrYieldExecution EQU 33
  WrFastMutex EQU 34
  WrGuardedMutex EQU 35
  WrRundown EQU 36
  WrAlertByThreadId EQU 37
  WrDeferredPreempt EQU 38
  WrPhysicalFault EQU 39
  MaximumWaitReason EQU 40
  
;  KWAIT_BLOCK struct
;    WaitListEntry LIST_ENTRY <>
;    WaitType BYTE ?
;    BlockState BYTE ?
;    WaitKey WORD ?
;    SpareLong SDWORD ?
;    union
;      Thread POINTER ?
;      NotificationQueue POINTER ?
;    ends
;    Object_ PVOID ?
;    SparePtr PVOID ?
;  KWAIT_BLOCK ends

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
    PRKWAIT_BLOCK typedef ptr KWAIT_BLOCK
  
  KSTART_ROUTINE typedef proto stdcall :PVOID
  PKSTART_ROUTINE typedef ptr KSTART_ROUTINE

   
  
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
    PRKDEVICE_QUEUE typedef ptr KDEVICE_QUEUE
    
    IFNDEF
    KDEVICE_QUEUE_ENTRY STRUCT	; sizeof = 10h
    	DeviceListEntry	LIST_ENTRY	<>
    	SortKey		DWORD		?
    	Inserted	BOOLEAN		?
    				db			3 dup(?)			; padding
    KDEVICE_QUEUE_ENTRY ENDS
    ENDIF
    PKDEVICE_QUEUE_ENTRY typedef PTR KDEVICE_QUEUE_ENTRY
    PRKDEVICE_QUEUE_ENTRY typedef ptr KDEVICE_QUEUE_ENTRY
  
  KSERVICE_ROUTINE typedef proto stdcall :ptr _KINTERRUPT,:PVOID
  PKSERVICE_ROUTINE typedef ptr KSERVICE_ROUTINE
  KMESSAGE_SERVICE_ROUTINE typedef proto stdcall :ptr _KINTERRUPT,:PVOID,:DWORD
  PKMESSAGE_SERVICE_ROUTINE typedef ptr KMESSAGE_SERVICE_ROUTINE
  KMUTANT struct
    Header DISPATCHER_HEADER <>
    MutantListEntry LIST_ENTRY <>
    OwnerThread POINTER ?
    Abandoned BOOLEAN ?
    ApcDisable BYTE ?
  KMUTANT ends

  PKMUTANT typedef ptr KMUTANT
  PRKMUTANT typedef ptr KMUTANT
  KMUTEX typedef KMUTANT
  PKMUTEX typedef ptr KMUTANT
  PRKMUTEX typedef ptr KMUTANT
  
  KSEMAPHORE struct
    Header DISPATCHER_HEADER <>
    Limit SDWORD ?
  KSEMAPHORE ends

  PKSEMAPHORE typedef ptr KSEMAPHORE
  PRKSEMAPHORE typedef ptr KSEMAPHORE
  
  KSEMAPHORE_ACTUAL_LENGTH equ <( FIELD_OFFSET ( KSEMAPHORE , Limit ) + sizeof ( LONG ) )>


  KDPC_WATCHDOG_INFORMATION struct
    DpcTimeLimit DWORD ?
    DpcTimeCount DWORD ?
    DpcWatchdogLimit DWORD ?
    DpcWatchdogCount DWORD ?
    Reserved DWORD ?
  KDPC_WATCHDOG_INFORMATION ends

  PKDPC_WATCHDOG_INFORMATION typedef ptr KDPC_WATCHDOG_INFORMATION


  KBUGCHECK_BUFFER_DUMP_STATE typedef SDWORD
  BufferEmpty EQU 0
  BufferInserted EQU 1
  BufferStarted EQU 2
  BufferFinished EQU 3
  BufferIncomplete EQU 4
  
  KBUGCHECK_CALLBACK_ROUTINE typedef proto stdcall :PVOID,:DWORD
  PKBUGCHECK_CALLBACK_ROUTINE typedef ptr KBUGCHECK_CALLBACK_ROUTINE
  KBUGCHECK_CALLBACK_RECORD struct
    Entry LIST_ENTRY <>
    CallbackRoutine PKBUGCHECK_CALLBACK_ROUTINE ?
    Buffer PVOID ?
    Length_ DWORD ?
    Component PUCHAR ?
    Checksum ULONG_PTR ?
    State BYTE ?
  KBUGCHECK_CALLBACK_RECORD ends

  PKBUGCHECK_CALLBACK_RECORD typedef ptr KBUGCHECK_CALLBACK_RECORD

  KBUGCHECK_CALLBACK_REASON typedef SDWORD
  KbCallbackInvalid EQU 0
  KbCallbackReserved1 EQU 1
  KbCallbackSecondaryDumpData EQU 2
  KbCallbackDumpIo EQU 3
  KbCallbackAddPages EQU 4
  KbCallbackSecondaryMultiPartDumpData EQU 5
  KbCallbackRemovePages EQU 6
  KbCallbackTriageDumpData EQU 7
  
  KBUGCHECK_REASON_CALLBACK_ROUTINE typedef proto stdcall :KBUGCHECK_CALLBACK_REASON,:ptr _KBUGCHECK_REASON_CALLBACK_RECORD,:PVOID,:DWORD
  PKBUGCHECK_REASON_CALLBACK_ROUTINE typedef ptr KBUGCHECK_REASON_CALLBACK_ROUTINE
  KBUGCHECK_REASON_CALLBACK_RECORD struct
    Entry LIST_ENTRY <>
    CallbackRoutine PKBUGCHECK_REASON_CALLBACK_ROUTINE ?
    Component PUCHAR ?
    Checksum ULONG_PTR ?
    Reason KBUGCHECK_CALLBACK_REASON ?
    State BYTE ?
  KBUGCHECK_REASON_CALLBACK_RECORD ends

  PKBUGCHECK_REASON_CALLBACK_RECORD typedef ptr KBUGCHECK_REASON_CALLBACK_RECORD
  
  KBUGCHECK_SECONDARY_DUMP_DATA struct
    InBuffer PVOID ?
    InBufferLength DWORD ?
    MaximumAllowed DWORD ?
    Guid GUID <>
    OutBuffer PVOID ?
    OutBufferLength DWORD ?
  KBUGCHECK_SECONDARY_DUMP_DATA ends

  PKBUGCHECK_SECONDARY_DUMP_DATA typedef ptr KBUGCHECK_SECONDARY_DUMP_DATA
  
  KBUGCHECK_SECONDARY_DUMP_DATA_EX struct
    InBuffer PVOID ?
    InBufferLength DWORD ?
    MaximumAllowed DWORD ?
    Guid GUID <>
    OutBuffer PVOID ?
    OutBufferLength DWORD ?
    Context PVOID ?
    Flags DWORD ?
    DumpType DWORD ?
    BugCheckCode DWORD ?
    BugCheckParameter1 ULONG_PTR ?
    BugCheckParameter2 ULONG_PTR ?
    BugCheckParameter3 ULONG_PTR ?
    BugCheckParameter4 ULONG_PTR ?
  KBUGCHECK_SECONDARY_DUMP_DATA_EX ends

  PKBUGCHECK_SECONDARY_DUMP_DATA_EX typedef ptr KBUGCHECK_SECONDARY_DUMP_DATA_EX
  
  KB_SECONDARY_DATA_FLAG_ADDITIONAL_DATA equ 00000001h
  KB_SECONDARY_DATA_FLAG_NO_DEVICE_ACCESS equ 00000002h
  KBUGCHECK_DUMP_IO_TYPE typedef SDWORD
  KbDumpIoInvalid EQU 0
  KbDumpIoHeader EQU 1
  KbDumpIoBody EQU 2
  KbDumpIoSecondaryData EQU 3
  KbDumpIoComplete EQU 4
  
  KBUGCHECK_DUMP_IO struct
    Offset_ ULONG64 ?
    Buffer PVOID ?
    BufferLength DWORD ?
    Type_ KBUGCHECK_DUMP_IO_TYPE ?
  KBUGCHECK_DUMP_IO ends

  PKBUGCHECK_DUMP_IO typedef ptr KBUGCHECK_DUMP_IO
  
  KB_ADD_PAGES_FLAG_VIRTUAL_ADDRESS equ 00000001h
  KB_ADD_PAGES_FLAG_PHYSICAL_ADDRESS equ 00000002h
  KB_ADD_PAGES_FLAG_ADDITIONAL_RANGES_EXIST equ 80000000h
  KBUGCHECK_ADD_PAGES struct
    Context PVOID ?
    Flags DWORD ?
    BugCheckCode DWORD ?
    Address ULONG_PTR ?
    Count ULONG_PTR ?
  KBUGCHECK_ADD_PAGES ends

  PKBUGCHECK_ADD_PAGES typedef ptr KBUGCHECK_ADD_PAGES
  
  KB_REMOVE_PAGES_FLAG_VIRTUAL_ADDRESS equ 00000001h
  KB_REMOVE_PAGES_FLAG_PHYSICAL_ADDRESS equ 00000002h
  KB_REMOVE_PAGES_FLAG_ADDITIONAL_RANGES_EXIST equ 80000000h
  KBUGCHECK_REMOVE_PAGES struct
    Context PVOID ?
    Flags DWORD ?
    BugCheckCode DWORD ?
    Address ULONG_PTR ?
    Count ULONG_PTR ?
  KBUGCHECK_REMOVE_PAGES ends

  PKBUGCHECK_REMOVE_PAGES typedef ptr KBUGCHECK_REMOVE_PAGES
  
  KADDRESS_RANGE struct
    Address PVOID ?
    Size_ SIZE_T ?
  KADDRESS_RANGE ends

  PKADDRESS_RANGE typedef ptr KADDRESS_RANGE
  
  KADDRESS_RANGE_DESCRIPTOR struct
    AddressRanges POINTER ?
    AddressRangeCount SIZE_T ?
  KADDRESS_RANGE_DESCRIPTOR ends

  PKADDRESS_RANGE_DESCRIPTOR typedef ptr KADDRESS_RANGE_DESCRIPTOR
  
  KTRIAGE_DUMP_DATA_ARRAY struct
    List LIST_ENTRY <>
    NumBlocksUsed DWORD ?
    NumBlocksTotal DWORD ?
    VirtMemSize DWORD ?
    ComponentNameBufferLength DWORD ?
    ComponentName PUCHAR ?
    Blocks KADDRESS_RANGE ANYSIZE_ARRAY dup (<>)
  KTRIAGE_DUMP_DATA_ARRAY ends

  PKTRIAGE_DUMP_DATA_ARRAY typedef ptr KTRIAGE_DUMP_DATA_ARRAY
  
  KB_TRIAGE_DUMP_DATA_FLAG_BUGCHECK_ACTIVE equ 00000001h
  KBUGCHECK_TRIAGE_DUMP_DATA struct
    DataArray PKTRIAGE_DUMP_DATA_ARRAY ?
    Flags DWORD ?
    MaxVirtMemSize DWORD ?
    BugCheckCode DWORD ?
    BugCheckParameter1 ULONG_PTR ?
    BugCheckParameter2 ULONG_PTR ?
    BugCheckParameter3 ULONG_PTR ?
    BugCheckParameter4 ULONG_PTR ?
  KBUGCHECK_TRIAGE_DUMP_DATA ends

  PKBUGCHECK_TRIAGE_DUMP_DATA typedef ptr KBUGCHECK_TRIAGE_DUMP_DATA
  
  KeInitializeTriageDumpDataArray proto fastcall :PKTRIAGE_DUMP_DATA_ARRAY, :DWORD
  KeAddTriageDumpDataBlock proto fastcall :PKTRIAGE_DUMP_DATA_ARRAY, :PVOID, :SIZE_T
  EXCEPTION_DIVIDED_BY_ZERO equ 0
  EXCEPTION_DEBUG equ 1
  EXCEPTION_NMI equ 2
  EXCEPTION_INT3 equ 3
  EXCEPTION_BOUND_CHECK equ 5
  EXCEPTION_INVALID_OPCODE equ 6
  EXCEPTION_NPX_NOT_AVAILABLE equ 7
  EXCEPTION_DOUBLE_FAULT equ 8
  EXCEPTION_NPX_OVERRUN equ 9
  EXCEPTION_INVALID_TSS equ 0Ah
  EXCEPTION_SEGMENT_NOT_PRESENT equ 0Bh
  EXCEPTION_STACK_FAULT equ 0Ch
  EXCEPTION_GP_FAULT equ 0Dh
  EXCEPTION_RESERVED_TRAP equ 0Fh
  EXCEPTION_NPX_ERROR equ 10h
  EXCEPTION_ALIGNMENT_CHECK equ 11h
  EXCEPTION_VIRTUALIZATION_FAULT equ 20h



      BOUND_CALLBACK_STATUS typedef SDWORD
      BoundExceptionContinueSearch EQU 0 
      BoundExceptionHandled EQU 1
      BoundExceptionError EQU 2
      BoundExceptionMaximum EQU 3
      
      PBOUND_CALLBACK_STATUS typedef ptr BOUND_CALLBACK_STATUS
      

      BOUND_CALLBACK typedef proto stdcall 
      PBOUND_CALLBACK typedef ptr BOUND_CALLBACK





  MEMORY_CACHING_TYPE_ORIG typedef SDWORD
  MmFrameBufferCached EQU 2 
  
  MEMORY_CACHING_TYPE typedef SDWORD
  MmNonCached EQU FALSE 
  MmCached EQU TRUE 
  MmWriteCombined EQU MmFrameBufferCached 
  MmHardwareCoherentCached EQU 1
  MmNonCachedUnordered EQU 2
  MmUSWCCached EQU 3
  MmMaximumCacheType EQU 4
  MmNotMapped EQU - 1 
  


  KE_PROCESSOR_CHANGE_NOTIFY_STATE typedef SDWORD
  KeProcessorAddStartNotify EQU 0 
  KeProcessorAddCompleteNotify EQU 1
  KeProcessorAddFailureNotify EQU 2
  
  KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT struct
    State KE_PROCESSOR_CHANGE_NOTIFY_STATE ?
    NtNumber DWORD ?
    Status NTSTATUS ?

      ProcNumber PROCESSOR_NUMBER <>

  KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT ends

  PKE_PROCESSOR_CHANGE_NOTIFY_CONTEXT typedef ptr KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT
  
  PROCESSOR_CALLBACK_FUNCTION typedef proto stdcall :PVOID,:PKE_PROCESSOR_CHANGE_NOTIFY_CONTEXT,:PNTSTATUS
  PPROCESSOR_CALLBACK_FUNCTION typedef ptr PROCESSOR_CALLBACK_FUNCTION
  KE_PROCESSOR_CHANGE_ADD_EXISTING equ 1



  INVALID_PROCESSOR_INDEX equ 0ffffffffh

  XSTATE_SAVE struct

      Prev POINTER ?
      Thread POINTER ?
      Level BYTE ?
      XStateContext XSTATE_CONTEXT <>

  XSTATE_SAVE ends

  PXSTATE_SAVE typedef ptr XSTATE_SAVE



  EXT_SET_PARAMETERS struct
    Version DWORD ?
    Reserved DWORD ?
    NoWakeTolerance QWORD ?
  EXT_SET_PARAMETERS ends

  PEXT_SET_PARAMETERS typedef ptr EXT_SET_PARAMETERS
  
  KT2_SET_PARAMETERS typedef EXT_SET_PARAMETERS
  PKT2_SET_PARAMETERS typedef ptr EXT_SET_PARAMETERS


  KWAIT_CHAIN struct
    Head PVOID ?
  KWAIT_CHAIN ends

  PKWAIT_CHAIN typedef ptr KWAIT_CHAIN


  KD_OPTION typedef SDWORD
  KD_OPTION_SET_BLOCK_ENABLE EQU 0


  _Enum_is_bitflag_ typedef SDWORD
  NonPagedPool EQU 0
  NonPagedPoolExecute EQU NonPagedPool 
  PagedPool EQU 1
  NonPagedPoolMustSucceed EQU NonPagedPool + 2 
  DontUseThisType EQU 3
  NonPagedPoolCacheAligned EQU NonPagedPool + 4 
  PagedPoolCacheAligned EQU 5
  NonPagedPoolCacheAlignedMustS EQU NonPagedPool + 6 
  MaxPoolType EQU 7
  NonPagedPoolBase EQU 0 
  NonPagedPoolBaseMustSucceed EQU NonPagedPoolBase + 2 
  NonPagedPoolBaseCacheAligned EQU NonPagedPoolBase + 4 
  NonPagedPoolBaseCacheAlignedMustS EQU NonPagedPoolBase + 6 
  NonPagedPoolSession EQU 32 
  PagedPoolSession EQU NonPagedPoolSession + 1 
  NonPagedPoolMustSucceedSession EQU PagedPoolSession + 1 
  DontUseThisTypeSession EQU NonPagedPoolMustSucceedSession + 1 
  NonPagedPoolCacheAlignedSession EQU DontUseThisTypeSession + 1 
  PagedPoolCacheAlignedSession EQU NonPagedPoolCacheAlignedSession + 1 
  NonPagedPoolCacheAlignedMustSSession EQU PagedPoolCacheAlignedSession + 1 
  NonPagedPoolNx EQU 512 
  NonPagedPoolNxCacheAligned EQU NonPagedPoolNx + 4 
  NonPagedPoolSessionNx EQU NonPagedPoolNx + 32 
  

  
  POOL_COLD_ALLOCATION equ 256
  POOL_NX_ALLOCATION equ 512

    ;#undef  POOL_NX_OPTIN
    POOL_NX_OPTIN_AUTO equ 1



  POOL_QUOTA_FAIL_INSTEAD_OF_RAISE equ 8
  POOL_RAISE_IF_ALLOCATION_FAILURE equ 16


  EX_POOL_PRIORITY typedef SDWORD
  LowPoolPriority EQU 0
  LowPoolPrioritySpecialPoolOverrun EQU 8 
  LowPoolPrioritySpecialPoolUnderrun EQU 9 
  NormalPoolPriority EQU 16 
  NormalPoolPrioritySpecialPoolOverrun EQU 24 
  NormalPoolPrioritySpecialPoolUnderrun EQU 25 
  HighPoolPriority EQU 32 
  HighPoolPrioritySpecialPoolOverrun EQU 40 
  HighPoolPrioritySpecialPoolUnderrun EQU 41 



  FM_LOCK_BIT equ 1h
  FM_LOCK_BIT_V equ 0h



  WORK_QUEUE_TYPE typedef SDWORD
  CriticalWorkQueue EQU 0
  DelayedWorkQueue EQU 1
  HyperCriticalWorkQueue EQU 2
  NormalWorkQueue EQU 3
  BackgroundWorkQueue EQU 4
  RealTimeWorkQueue EQU 5
  SuperCriticalWorkQueue EQU 6
  MaximumWorkQueue EQU 7
  CustomPriorityWorkQueue EQU 32 
  
  WORKER_THREAD_ROUTINE typedef proto stdcall :PVOID
  PWORKER_THREAD_ROUTINE typedef ptr WORKER_THREAD_ROUTINE
  WORK_QUEUE_ITEM struct
    List LIST_ENTRY <>
    WorkerRoutine PWORKER_THREAD_ROUTINE ?
    Parameter PVOID ?
  WORK_QUEUE_ITEM ends

  PWORK_QUEUE_ITEM typedef ptr WORK_QUEUE_ITEM
  

  ERESOURCE_THREAD typedef ULONG_PTR
  PERESOURCE_THREAD typedef ptr ERESOURCE_THREAD
  OWNER_ENTRY struct
    OwnerThread ERESOURCE_THREAD ?
    union
      struct
        OWNER_ENTRY_??27 record IoPriorityBoosted_??27:1, OwnerReferenced_??27:1, IoQoSPriorityBoosted_??27:1, OwnerCount_??27:29
        OWNER_ENTRY_??27 <>
      ends
      TableSize DWORD ?
    ends
  OWNER_ENTRY ends

  POWNER_ENTRY typedef ptr OWNER_ENTRY
  
  ERESOURCE struct
    SystemResourcesList LIST_ENTRY <>
    OwnerTable POWNER_ENTRY ?
    ActiveCount SWORD ?
    union
      Flag WORD ?
      struct
        ReservedLowFlags BYTE ?
        WaiterPriority BYTE ?
      ends
    ends
    SharedWaiters PVOID ?
    ExclusiveWaiters PVOID ?
    OwnerEntry OWNER_ENTRY <>
    ActiveEntries DWORD ?
    ContentionCount DWORD ?
    NumberOfSharedWaiters DWORD ?
    NumberOfExclusiveWaiters DWORD ?
      Reserved2 PVOID ?
    union
      Address PVOID ?
      CreatorBackTraceIndex ULONG_PTR ?
    ends
    SpinLock KSPIN_LOCK ?
  ERESOURCE ends

  PERESOURCE typedef ptr ERESOURCE
  
  ResourceNeverExclusive equ 0010h
  ResourceReleaseByOtherThread equ 0020h
  ResourceOwnedExclusive equ 0080h
  RESOURCE_HASH_TABLE_SIZE equ 64
  RESOURCE_HASH_ENTRY struct
    ListEntry LIST_ENTRY <>
    Address PVOID ?
    ContentionCount DWORD ?
    Number DWORD ?
  RESOURCE_HASH_ENTRY ends

  PRESOURCE_HASH_ENTRY typedef ptr RESOURCE_HASH_ENTRY
  
  RESOURCE_PERFORMANCE_DATA struct
    ActiveResourceCount DWORD ?
    TotalResourceCount DWORD ?
    ExclusiveAcquire DWORD ?
    SharedFirstLevel DWORD ?
    SharedSecondLevel DWORD ?
    StarveFirstLevel DWORD ?
    StarveSecondLevel DWORD ?
    WaitForExclusive DWORD ?
    OwnerTableExpands DWORD ?
    MaximumTableExpand DWORD ?
    HashTable LIST_ENTRY RESOURCE_HASH_TABLE_SIZE dup (<>)
  RESOURCE_PERFORMANCE_DATA ends

  PRESOURCE_PERFORMANCE_DATA typedef ptr RESOURCE_PERFORMANCE_DATA


  EX_RUNDOWN_REF struct
    EX_RUNDOWN_ACTIVE equ 1h
    EX_RUNDOWN_COUNT_SHIFT equ 1h
    EX_RUNDOWN_COUNT_INC equ ( 1 shl EX_RUNDOWN_COUNT_SHIFT )
    union
      Count ULONG_PTR ?
      Ptr_ PVOID ?
    ends
  EX_RUNDOWN_REF ends

  PEX_RUNDOWN_REF typedef ptr EX_RUNDOWN_REF
  
  PEX_RUNDOWN_REF_CACHE_AWARE typedef ptr _EX_RUNDOWN_REF_CACHE_AWARE
  
  PEX_TIMER typedef ptr _EX_TIMER
  
  PEXT_CANCEL_PARAMETERS typedef PVOID
  EXT_DELETE_PARAMETERS struct
    Version DWORD ?
    Reserved DWORD ?
    DeleteCallback QWORD ?
    DeleteContext PVOID ?
  EXT_DELETE_PARAMETERS ends

  PEXT_DELETE_PARAMETERS typedef ptr EXT_DELETE_PARAMETERS
  

    EX_TIMER_HIGH_RESOLUTION equ 4h
    EX_TIMER_NO_WAKE equ 8h
    EX_TIMER_UNLIMITED_TOLERANCE equ - 1
    EX_TIMER_NOTIFICATION equ ( 1 shl 31 )


  PCALLBACK_OBJECT typedef ptr _CALLBACK_OBJECT
  
  CALLBACK_FUNCTION typedef proto stdcall :PVOID,:PVOID,:PVOID
  PCALLBACK_FUNCTION typedef ptr CALLBACK_FUNCTION



    EX_CARR_ALLOCATE_PAGED_POOL equ 00000000h
    EX_CARR_ALLOCATE_NONPAGED_POOL equ 00000001h
    EX_CARR_DISABLE_EXPANSION equ 00000002h
    EX_CARR_VALID_FLAGS equ <( EX_CARR_ALLOCATE_NONPAGED_POOL or EX_CARR_DISABLE_EXPANSION )>



  REG_NOTIFY_CLASS typedef SDWORD
  RegNtDeleteKey EQU 0
  RegNtPreDeleteKey EQU RegNtDeleteKey 
  RegNtSetValueKey EQU 1
  RegNtPreSetValueKey EQU RegNtSetValueKey 
  RegNtDeleteValueKey EQU 1
  RegNtPreDeleteValueKey EQU RegNtDeleteValueKey 
  RegNtSetInformationKey EQU 1
  RegNtPreSetInformationKey EQU RegNtSetInformationKey 
  RegNtRenameKey EQU 1
  RegNtPreRenameKey EQU RegNtRenameKey 
  RegNtEnumerateKey EQU 1
  RegNtPreEnumerateKey EQU RegNtEnumerateKey 
  RegNtEnumerateValueKey EQU 1
  RegNtPreEnumerateValueKey EQU RegNtEnumerateValueKey 
  RegNtQueryKey EQU 1
  RegNtPreQueryKey EQU RegNtQueryKey 
  RegNtQueryValueKey EQU 1
  RegNtPreQueryValueKey EQU RegNtQueryValueKey 
  RegNtQueryMultipleValueKey EQU 1
  RegNtPreQueryMultipleValueKey EQU RegNtQueryMultipleValueKey 
  RegNtPreCreateKey EQU 1
  RegNtPostCreateKey EQU 2
  RegNtPreOpenKey EQU 3
  RegNtPostOpenKey EQU 4
  RegNtKeyHandleClose EQU 5
  RegNtPreKeyHandleClose EQU RegNtKeyHandleClose 
  RegNtPostDeleteKey EQU 1
  RegNtPostSetValueKey EQU 2
  RegNtPostDeleteValueKey EQU 3
  RegNtPostSetInformationKey EQU 4
  RegNtPostRenameKey EQU 5
  RegNtPostEnumerateKey EQU 6
  RegNtPostEnumerateValueKey EQU 7
  RegNtPostQueryKey EQU 8
  RegNtPostQueryValueKey EQU 9
  RegNtPostQueryMultipleValueKey EQU 10
  RegNtPostKeyHandleClose EQU 11
  RegNtPreCreateKeyEx EQU 12
  RegNtPostCreateKeyEx EQU 13
  RegNtPreOpenKeyEx EQU 14
  RegNtPostOpenKeyEx EQU 15
  RegNtPreFlushKey EQU 16
  RegNtPostFlushKey EQU 17
  RegNtPreLoadKey EQU 18
  RegNtPostLoadKey EQU 19
  RegNtPreUnLoadKey EQU 20
  RegNtPostUnLoadKey EQU 21
  RegNtPreQueryKeySecurity EQU 22
  RegNtPostQueryKeySecurity EQU 23
  RegNtPreSetKeySecurity EQU 24
  RegNtPostSetKeySecurity EQU 25
  RegNtCallbackObjectContextCleanup EQU 26
  RegNtPreRestoreKey EQU 27
  RegNtPostRestoreKey EQU 28
  RegNtPreSaveKey EQU 29
  RegNtPostSaveKey EQU 30
  RegNtPreReplaceKey EQU 31
  RegNtPostReplaceKey EQU 32
  RegNtPreQueryKeyName EQU 33
  RegNtPostQueryKeyName EQU 34
  MaxRegNtNotifyClass EQU 35
  
  REG_DELETE_KEY_INFORMATION struct
    Object_ PVOID ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_DELETE_KEY_INFORMATION ends


    PREG_DELETE_KEY_INFORMATION typedef ptr REG_DELETE_KEY_INFORMATION
    REG_FLUSH_KEY_INFORMATION typedef REG_DELETE_KEY_INFORMATION

  PREG_FLUSH_KEY_INFORMATION typedef ptr REG_DELETE_KEY_INFORMATION
  
  REG_SET_VALUE_KEY_INFORMATION struct
    Object_ PVOID ?
    ValueName PUNICODE_STRING ?
    TitleIndex DWORD ?
    Type_ DWORD ?
    Data PVOID ?
    DataSize DWORD ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_SET_VALUE_KEY_INFORMATION ends

  PREG_SET_VALUE_KEY_INFORMATION typedef ptr REG_SET_VALUE_KEY_INFORMATION
  
  REG_DELETE_VALUE_KEY_INFORMATION struct
    Object_ PVOID ?
    ValueName PUNICODE_STRING ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_DELETE_VALUE_KEY_INFORMATION ends

  PREG_DELETE_VALUE_KEY_INFORMATION typedef ptr REG_DELETE_VALUE_KEY_INFORMATION
  
  REG_SET_INFORMATION_KEY_INFORMATION struct
    Object_ PVOID ?
    KeySetInformationClass KEY_SET_INFORMATION_CLASS ?
    KeySetInformation PVOID ?
    KeySetInformationLength DWORD ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_SET_INFORMATION_KEY_INFORMATION ends

  PREG_SET_INFORMATION_KEY_INFORMATION typedef ptr REG_SET_INFORMATION_KEY_INFORMATION
  
  REG_ENUMERATE_KEY_INFORMATION struct
    Object_ PVOID ?
    Index DWORD ?
    KeyInformationClass KEY_INFORMATION_CLASS ?
    KeyInformation PVOID ?
    Length_ DWORD ?
    ResultLength PULONG ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_ENUMERATE_KEY_INFORMATION ends

  PREG_ENUMERATE_KEY_INFORMATION typedef ptr REG_ENUMERATE_KEY_INFORMATION
  
  REG_ENUMERATE_VALUE_KEY_INFORMATION struct
    Object_ PVOID ?
    Index DWORD ?
    KeyValueInformationClass KEY_VALUE_INFORMATION_CLASS ?
    KeyValueInformation PVOID ?
    Length_ DWORD ?
    ResultLength PULONG ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_ENUMERATE_VALUE_KEY_INFORMATION ends

  PREG_ENUMERATE_VALUE_KEY_INFORMATION typedef ptr REG_ENUMERATE_VALUE_KEY_INFORMATION
  
  REG_QUERY_KEY_INFORMATION struct
    Object_ PVOID ?
    KeyInformationClass KEY_INFORMATION_CLASS ?
    KeyInformation PVOID ?
    Length_ DWORD ?
    ResultLength PULONG ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_QUERY_KEY_INFORMATION ends

  PREG_QUERY_KEY_INFORMATION typedef ptr REG_QUERY_KEY_INFORMATION
  
  REG_QUERY_VALUE_KEY_INFORMATION struct
    Object_ PVOID ?
    ValueName PUNICODE_STRING ?
    KeyValueInformationClass KEY_VALUE_INFORMATION_CLASS ?
    KeyValueInformation PVOID ?
    Length_ DWORD ?
    ResultLength PULONG ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_QUERY_VALUE_KEY_INFORMATION ends

  PREG_QUERY_VALUE_KEY_INFORMATION typedef ptr REG_QUERY_VALUE_KEY_INFORMATION
  
  REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION struct
    Object_ PVOID ?
    ValueEntries PKEY_VALUE_ENTRY ?
    EntryCount DWORD ?
    ValueBuffer PVOID ?
    BufferLength PULONG ?
    RequiredBufferLength PULONG ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION ends

  PREG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION typedef ptr REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION
  
  REG_RENAME_KEY_INFORMATION struct
    Object_ PVOID ?
    NewName PUNICODE_STRING ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_RENAME_KEY_INFORMATION ends

  PREG_RENAME_KEY_INFORMATION typedef ptr REG_RENAME_KEY_INFORMATION
  
  REG_KEY_HANDLE_CLOSE_INFORMATION struct
    Object_ PVOID ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_KEY_HANDLE_CLOSE_INFORMATION ends

  PREG_KEY_HANDLE_CLOSE_INFORMATION typedef ptr REG_KEY_HANDLE_CLOSE_INFORMATION
  
  REG_CREATE_KEY_INFORMATION struct
    CompleteName PUNICODE_STRING ?
    RootObject PVOID ?
    ObjectType PVOID ?
    CreateOptions DWORD ?
    Class PUNICODE_STRING ?
    SecurityDescriptor PVOID ?
    SecurityQualityOfService PVOID ?
    DesiredAccess ACCESS_MASK ?
    GrantedAccess ACCESS_MASK ?
    Disposition PULONG ?
    ResultObject POINTER ?
    CallContext PVOID ?
    RootObjectContext PVOID ?
    Transaction PVOID ?
    Reserved PVOID ?
  REG_CREATE_KEY_INFORMATION ends

  REG_OPEN_KEY_INFORMATION typedef REG_CREATE_KEY_INFORMATION
  PREG_CREATE_KEY_INFORMATION typedef ptr REG_CREATE_KEY_INFORMATION
  PREG_OPEN_KEY_INFORMATION typedef ptr REG_CREATE_KEY_INFORMATION
  
  REG_CREATE_KEY_INFORMATION_V1 struct
    CompleteName PUNICODE_STRING ?
    RootObject PVOID ?
    ObjectType PVOID ?
    Options DWORD ?
    Class PUNICODE_STRING ?
    SecurityDescriptor PVOID ?
    SecurityQualityOfService PVOID ?
    DesiredAccess ACCESS_MASK ?
    GrantedAccess ACCESS_MASK ?
    Disposition PULONG ?
    ResultObject POINTER ?
    CallContext PVOID ?
    RootObjectContext PVOID ?
    Transaction PVOID ?
    Version ULONG_PTR ?
    RemainingName PUNICODE_STRING ?
    Wow64Flags DWORD ?
    Attributes DWORD ?
    CheckAccessMode KPROCESSOR_MODE ?
  REG_CREATE_KEY_INFORMATION_V1 ends

  REG_OPEN_KEY_INFORMATION_V1 typedef REG_CREATE_KEY_INFORMATION_V1
  PREG_CREATE_KEY_INFORMATION_V1 typedef ptr REG_CREATE_KEY_INFORMATION_V1
  PREG_OPEN_KEY_INFORMATION_V1 typedef ptr REG_CREATE_KEY_INFORMATION_V1
  
  REG_POST_OPERATION_INFORMATION struct
    Object_ PVOID ?
    Status NTSTATUS ?
    PreInformation PVOID ?
    ReturnStatus NTSTATUS ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_POST_OPERATION_INFORMATION ends

  PREG_POST_OPERATION_INFORMATION typedef ptr REG_POST_OPERATION_INFORMATION
  
  REG_PRE_CREATE_KEY_INFORMATION struct
    CompleteName PUNICODE_STRING ?
  REG_PRE_CREATE_KEY_INFORMATION ends

  REG_PRE_OPEN_KEY_INFORMATION typedef REG_PRE_CREATE_KEY_INFORMATION
  PREG_PRE_CREATE_KEY_INFORMATION typedef ptr REG_PRE_CREATE_KEY_INFORMATION
  PREG_PRE_OPEN_KEY_INFORMATION typedef ptr REG_PRE_CREATE_KEY_INFORMATION
  
  REG_POST_CREATE_KEY_INFORMATION struct
    CompleteName PUNICODE_STRING ?
    Object_ PVOID ?
    Status NTSTATUS ?
  REG_POST_CREATE_KEY_INFORMATION ends

  REG_POST_OPEN_KEY_INFORMATION typedef REG_POST_CREATE_KEY_INFORMATION
  PREG_POST_CREATE_KEY_INFORMATION typedef ptr REG_POST_CREATE_KEY_INFORMATION
  PREG_POST_OPEN_KEY_INFORMATION typedef ptr REG_POST_CREATE_KEY_INFORMATION
  

    REG_LOAD_KEY_INFORMATION struct
      Object_ PVOID ?
      KeyName PUNICODE_STRING ?
      SourceFile PUNICODE_STRING ?
      Flags DWORD ?
      TrustClassObject PVOID ?
      UserEvent PVOID ?
      DesiredAccess ACCESS_MASK ?
      RootHandle PHANDLE ?
      CallContext PVOID ?
      ObjectContext PVOID ?
      Reserved PVOID ?
    REG_LOAD_KEY_INFORMATION ends

    PREG_LOAD_KEY_INFORMATION typedef ptr REG_LOAD_KEY_INFORMATION
    
    REG_UNLOAD_KEY_INFORMATION struct
      Object_ PVOID ?
      UserEvent PVOID ?
      CallContext PVOID ?
      ObjectContext PVOID ?
      Reserved PVOID ?
    REG_UNLOAD_KEY_INFORMATION ends

    PREG_UNLOAD_KEY_INFORMATION typedef ptr REG_UNLOAD_KEY_INFORMATION
    
    REG_CALLBACK_CONTEXT_CLEANUP_INFORMATION struct
      Object_ PVOID ?
      ObjectContext PVOID ?
      Reserved PVOID ?
    REG_CALLBACK_CONTEXT_CLEANUP_INFORMATION ends

    PREG_CALLBACK_CONTEXT_CLEANUP_INFORMATION typedef ptr REG_CALLBACK_CONTEXT_CLEANUP_INFORMATION
    
    REG_QUERY_KEY_SECURITY_INFORMATION struct
      Object_ PVOID ?
      SecurityInformation PSECURITY_INFORMATION ?
      SecurityDescriptor PSECURITY_DESCRIPTOR ?
      Length_ PULONG ?
      CallContext PVOID ?
      ObjectContext PVOID ?
      Reserved PVOID ?
    REG_QUERY_KEY_SECURITY_INFORMATION ends

    PREG_QUERY_KEY_SECURITY_INFORMATION typedef ptr REG_QUERY_KEY_SECURITY_INFORMATION
    
    REG_SET_KEY_SECURITY_INFORMATION struct
      Object_ PVOID ?
      SecurityInformation PSECURITY_INFORMATION ?
      SecurityDescriptor PSECURITY_DESCRIPTOR ?
      CallContext PVOID ?
      ObjectContext PVOID ?
      Reserved PVOID ?
    REG_SET_KEY_SECURITY_INFORMATION ends

    PREG_SET_KEY_SECURITY_INFORMATION typedef ptr REG_SET_KEY_SECURITY_INFORMATION
    
    REG_RESTORE_KEY_INFORMATION struct
      Object_ PVOID ?
      FileHandle HANDLE ?
      Flags DWORD ?
      CallContext PVOID ?
      ObjectContext PVOID ?
      Reserved PVOID ?
    REG_RESTORE_KEY_INFORMATION ends

    PREG_RESTORE_KEY_INFORMATION typedef ptr REG_RESTORE_KEY_INFORMATION
    
    REG_SAVE_KEY_INFORMATION struct
      Object_ PVOID ?
      FileHandle HANDLE ?
      Format DWORD ?
      CallContext PVOID ?
      ObjectContext PVOID ?
      Reserved PVOID ?
    REG_SAVE_KEY_INFORMATION ends

    PREG_SAVE_KEY_INFORMATION typedef ptr REG_SAVE_KEY_INFORMATION
    
    REG_REPLACE_KEY_INFORMATION struct
      Object_ PVOID ?
      OldFileName PUNICODE_STRING ?
      NewFileName PUNICODE_STRING ?
      CallContext PVOID ?
      ObjectContext PVOID ?
      Reserved PVOID ?
    REG_REPLACE_KEY_INFORMATION ends

    PREG_REPLACE_KEY_INFORMATION typedef ptr REG_REPLACE_KEY_INFORMATION

  REG_QUERY_KEY_NAME struct
    Object_ PVOID ?
    ObjectNameInfo POBJECT_NAME_INFORMATION ?
    Length_ DWORD ?
    ReturnLength PULONG ?
    CallContext PVOID ?
    ObjectContext PVOID ?
    Reserved PVOID ?
  REG_QUERY_KEY_NAME ends

  PREG_QUERY_KEY_NAME typedef ptr REG_QUERY_KEY_NAME


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


  MM_MAXIMUM_DISK_IO_SIZE equ 10000h
  ROUND_TO_PAGES macro Size
   exitm <( ( ( Size ) + PAGE_SIZE - 1 ) and not ( PAGE_SIZE - 1 ) ) >
  endm
  BYTES_TO_PAGES macro Size
   exitm <( ( ( Size ) shr PAGE_SHIFT ) + ( ( ( Size ) and ( PAGE_SIZE - 1 ) ) != 0 ) ) >
  endm
  BYTE_OFFSET macro Va
   exitm <( ( ( Va ) and ( PAGE_SIZE - 1 ) ) ) >
  endm
  PAGE_ALIGN macro Va
   exitm <( ( ( Va ) and not ( PAGE_SIZE - 1 ) ) ) >
  endm
  ADDRESS_AND_SIZE_TO_SPAN_PAGES macro Va,Size
   exitm <( ( BYTE_OFFSET ( Va ) + ( ( Size ) ) + ( PAGE_SIZE - 1 ) ) shr PAGE_SHIFT ) >
  endm

  COMPUTE_PAGES_SPANNED macro Va,Size
   exitm <ADDRESS_AND_SIZE_TO_SPAN_PAGES ( Va , Size ) >
  endm
  MmGetMdlPfnArray macro Mdl
   exitm <( ( PPFN_NUMBER ) ( Mdl + 1 ) ) >
  endm
  MmGetMdlVirtualAddress macro Mdl
   exitm <( ( ( PCHAR ) ( ( Mdl ) - StartVa ) + ( Mdl ) - ByteOffset ) ) >
  endm
  MmGetMdlByteCount macro Mdl
   exitm <( ( Mdl ) - ByteCount ) >
  endm
  MmGetMdlByteOffset macro Mdl
   exitm <( ( Mdl ) - ByteOffset ) >
  endm
  MmGetMdlBaseVa macro Mdl
   exitm <( ( Mdl ) - StartVa ) >
  endm
  MM_SYSTEMSIZE typedef SDWORD
  MmSmallSystem EQU 0
  MmMediumSystem EQU 1
  MmLargeSystem EQU 2


    MM_PHYSICAL_ADDRESS_LIST struct
      PhysicalAddress PHYSICAL_ADDRESS <>
      NumberOfBytes SIZE_T ?
    MM_PHYSICAL_ADDRESS_LIST ends

    PMM_PHYSICAL_ADDRESS_LIST typedef ptr MM_PHYSICAL_ADDRESS_LIST
    MM_PERMANENT_ADDRESS_IS_IO_SPACE equ 1h


  MM_PAGE_PRIORITY typedef SDWORD
  LowPagePriority EQU 0
  NormalPagePriority EQU 16 
  HighPagePriority EQU 32 
  
  MdlMappingNoWrite equ 80000000h
  MdlMappingNoExecute equ 40000000h


  MM_DONT_ZERO_ALLOCATION equ 00000001h
  MM_ALLOCATE_FROM_LOCAL_NODE_ONLY equ 00000002h
  MM_ALLOCATE_FULLY_REQUIRED equ 00000004h
  MM_ALLOCATE_NO_WAIT equ 00000008h
  MM_ALLOCATE_PREFER_CONTIGUOUS equ 00000010h
  MM_ALLOCATE_REQUIRE_CONTIGUOUS_CHUNKS equ 00000020h
  MM_ALLOCATE_FAST_LARGE_PAGES equ 00000040h
  MM_ALLOCATE_TRIM_IF_NECESSARY equ 00000080h
  MM_ALLOCATE_AND_HOT_REMOVE equ 00000100h



    MM_FREE_MDL_PAGES_ZERO equ 1h


    NODE_REQUIREMENT typedef DWORD
    MM_ANY_NODE_OK equ 80000000h

 
    MM_MDL_PAGE_CONTENTS_STATE typedef SDWORD
    MmMdlPageContentsDynamic EQU 0
    MmMdlPageContentsInvariant EQU 1
    MmMdlPageContentsQuery EQU 2
    
    PMM_MDL_PAGE_CONTENTS_STATE typedef MM_MDL_PAGE_CONTENTS_STATE
    


  MmGetSystemAddressForMdl macro MDL
   exitm <( ( ( MDL ) - MdlFlags and ( MDL_MAPPED_TO_SYSTEM_VA or MDL_SOURCE_IS_NONPAGED_POOL ) ) ? ( ( MDL ) - MappedSystemVa ) : ( MmMapLockedPages ( ( MDL ) , KernelMode ) ) ) >
  endm
  MmPrepareMdlForReuse proto fastcall :PMDL
  proto_PMM_DLL_INITIALIZE typedef proto fastcall :PUNICODE_STRING
  PMM_DLL_INITIALIZE typedef ptr proto_PMM_DLL_INITIALIZE
  proto_PMM_DLL_UNLOAD typedef proto fastcall 
  PMM_DLL_UNLOAD typedef ptr proto_PMM_DLL_UNLOAD

    MmIsDriverSuspectForVerifier proto fastcall :ptr _DRIVER_OBJECT

    MmIsDriverVerifying proto fastcall :ptr _DRIVER_OBJECT

    MmIsDriverVerifyingByAddress proto fastcall :PVOID

  SECURITY_OPERATION_CODE typedef SDWORD
  SetSecurityDescriptor EQU 0
  QuerySecurityDescriptor EQU 1
  DeleteSecurityDescriptor EQU 2
  AssignSecurityDescriptor EQU 3
  
  PSECURITY_OPERATION_CODE typedef ptr SECURITY_OPERATION_CODE
  
  SECURITY_SUBJECT_CONTEXT struct
    ClientToken PACCESS_TOKEN ?
    ImpersonationLevel SECURITY_IMPERSONATION_LEVEL ?
    PrimaryToken PACCESS_TOKEN ?
    ProcessAuditId PVOID ?
  SECURITY_SUBJECT_CONTEXT ends

  PSECURITY_SUBJECT_CONTEXT typedef ptr SECURITY_SUBJECT_CONTEXT
  
  INITIAL_PRIVILEGE_COUNT equ 3
  INITIAL_PRIVILEGE_SET struct
    PrivilegeCount DWORD ?
    Control DWORD ?
    Privilege LUID_AND_ATTRIBUTES INITIAL_PRIVILEGE_COUNT dup (<>)
  INITIAL_PRIVILEGE_SET ends

  PINITIAL_PRIVILEGE_SET typedef ptr INITIAL_PRIVILEGE_SET
  
  ACCESS_STATE struct
    OperationID LUID <>
    SecurityEvaluated BOOLEAN ?
    GenerateAudit BOOLEAN ?
    GenerateOnClose BOOLEAN ?
    PrivilegesAllocated BOOLEAN ?
    Flags DWORD ?
    RemainingDesiredAccess ACCESS_MASK ?
    PreviouslyGrantedAccess ACCESS_MASK ?
    OriginalDesiredAccess ACCESS_MASK ?
    SubjectSecurityContext SECURITY_SUBJECT_CONTEXT <>
    SecurityDescriptor PSECURITY_DESCRIPTOR ?
    AuxData PVOID ?
    union Privileges
      InitialPrivilegeSet INITIAL_PRIVILEGE_SET <>
      PrivilegeSet PRIVILEGE_SET <>
    ends
    AuditPrivileges BOOLEAN ?
    ObjectName UNICODE_STRING <>
    ObjectTypeName UNICODE_STRING <>
  ACCESS_STATE ends

  PACCESS_STATE typedef ptr ACCESS_STATE
  
  NTFS_DEREF_EXPORTED_SECURITY_DESCRIPTOR typedef proto stdcall :PVOID,:PSECURITY_DESCRIPTOR
  PNTFS_DEREF_EXPORTED_SECURITY_DESCRIPTOR typedef ptr NTFS_DEREF_EXPORTED_SECURITY_DESCRIPTOR
 


  SE_IMAGE_TYPE typedef SDWORD
  SeImageTypeElamDriver EQU 0 
  SeImageTypeDriver EQU 1
  SeImageTypePlatformSecureFile EQU 2
  SeImageTypeDynamicCodeFile EQU 3
  SeImageTypeMax EQU 4
  
  PSE_IMAGE_TYPE typedef ptr SE_IMAGE_TYPE

  
  SE_IMAGE_VERIFICATION_CALLBACK_FUNCTION typedef proto stdcall :PVOID,:SE_IMAGE_TYPE,:PBDCB_IMAGE_INFORMATION
  PSE_IMAGE_VERIFICATION_CALLBACK_FUNCTION typedef ptr SE_IMAGE_VERIFICATION_CALLBACK_FUNCTION
  SE_IMAGE_VERIFICATION_CALLBACK_TYPE typedef SDWORD
  SeImageVerificationCallbackInformational EQU 0 
  
  PSE_IMAGE_VERIFICATION_CALLBACK_TYPE typedef ptr SE_IMAGE_VERIFICATION_CALLBACK_TYPE
  
  SE_IMAGE_VERIFICATION_CALLBACK_TOKEN typedef PVOID
  PSE_IMAGE_VERIFICATION_CALLBACK_TOKEN typedef ptr PVOID


  IO_TYPE_ADAPTER equ 00000001h
  IO_TYPE_CONTROLLER equ 00000002h
  IO_TYPE_DEVICE equ 00000003h
  IO_TYPE_DRIVER equ 00000004h
  IO_TYPE_FILE equ 00000005h
  IO_TYPE_IRP equ 00000006h
  IO_TYPE_MASTER_ADAPTER equ 00000007h
  IO_TYPE_OPEN_PACKET equ 00000008h
  IO_TYPE_TIMER equ 00000009h
  IO_TYPE_VPB equ 0000000ah
  IO_TYPE_ERROR_LOG equ 0000000bh
  IO_TYPE_ERROR_MESSAGE equ 0000000ch
  IO_TYPE_DEVICE_OBJECT_EXTENSION equ 0000000dh
  
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
  
    IRP_MN_SCSI_CLASS equ 01h
    IRP_MN_START_DEVICE equ 00h
    IRP_MN_QUERY_REMOVE_DEVICE equ 01h
    IRP_MN_REMOVE_DEVICE equ 02h
    IRP_MN_CANCEL_REMOVE_DEVICE equ 03h
    IRP_MN_STOP_DEVICE equ 04h
    IRP_MN_QUERY_STOP_DEVICE equ 05h
    IRP_MN_CANCEL_STOP_DEVICE equ 06h
    IRP_MN_QUERY_DEVICE_RELATIONS equ 07h
    IRP_MN_QUERY_INTERFACE equ 08h
    IRP_MN_QUERY_CAPABILITIES equ 09h
    IRP_MN_QUERY_RESOURCES equ 0Ah
    IRP_MN_QUERY_RESOURCE_REQUIREMENTS equ 0Bh
    IRP_MN_QUERY_DEVICE_TEXT equ 0Ch
    IRP_MN_FILTER_RESOURCE_REQUIREMENTS equ 0Dh
    IRP_MN_READ_CONFIG equ 0Fh
    IRP_MN_WRITE_CONFIG equ 10h
    IRP_MN_EJECT equ 11h
    IRP_MN_SET_LOCK equ 12h
    IRP_MN_QUERY_ID equ 13h
    IRP_MN_QUERY_PNP_DEVICE_STATE equ 14h
    IRP_MN_QUERY_BUS_INFORMATION equ 15h
    IRP_MN_DEVICE_USAGE_NOTIFICATION equ 16h
    IRP_MN_SURPRISE_REMOVAL equ 17h
    IRP_MN_DEVICE_ENUMERATED equ 19h
    IRP_MN_WAIT_WAKE equ 00h
    IRP_MN_POWER_SEQUENCE equ 01h
    IRP_MN_SET_POWER equ 02h
    IRP_MN_QUERY_POWER equ 03h
    IRP_MN_QUERY_ALL_DATA equ 00h
    IRP_MN_QUERY_SINGLE_INSTANCE equ 01h
    IRP_MN_CHANGE_SINGLE_INSTANCE equ 02h
    IRP_MN_CHANGE_SINGLE_ITEM equ 03h
    IRP_MN_ENABLE_EVENTS equ 04h
    IRP_MN_DISABLE_EVENTS equ 05h
    IRP_MN_ENABLE_COLLECTION equ 06h
    IRP_MN_DISABLE_COLLECTION equ 07h
    IRP_MN_REGINFO equ 08h
    IRP_MN_EXECUTE_METHOD equ 09h
    IRP_MN_REGINFO_EX equ 0bh
  
  
  IO_FORCE_ACCESS_CHECK equ 0001h
  IO_NO_PARAMETER_CHECKING equ 0100h
  IO_REPARSE equ 0h
  IO_REMOUNT equ 1h
  IO_REPARSE_GLOBAL equ 2h
  CREATE_FILE_TYPE typedef SDWORD
  CreateFileTypeNone EQU 0
  CreateFileTypeNamedPipe EQU 1
  CreateFileTypeMailslot EQU 2
  
  NAMED_PIPE_CREATE_PARAMETERS struct
    NamedPipeType DWORD ?
    ReadMode DWORD ?
    CompletionMode DWORD ?
    MaximumInstances DWORD ?
    InboundQuota DWORD ?
    OutboundQuota DWORD ?
    DefaultTimeout LARGE_INTEGER <>
    TimeoutSpecified BOOLEAN ?
  NAMED_PIPE_CREATE_PARAMETERS ends

  PNAMED_PIPE_CREATE_PARAMETERS typedef ptr NAMED_PIPE_CREATE_PARAMETERS
  
  MAILSLOT_CREATE_PARAMETERS struct
    MailslotQuota DWORD ?
    MaximumMessageSize DWORD ?
    ReadTimeout LARGE_INTEGER <>
    TimeoutSpecified BOOLEAN ?
  MAILSLOT_CREATE_PARAMETERS ends

  PMAILSLOT_CREATE_PARAMETERS typedef ptr MAILSLOT_CREATE_PARAMETERS


  IO_DPC_ROUTINE proto fastcall :PKDPC, :ptr _DEVICE_OBJECT, :ptr _IRP, :PVOID

  IO_TIMER_ROUTINE proto fastcall :ptr _DEVICE_OBJECT, :PVOID

  DRIVER_INITIALIZE proto fastcall :ptr _DRIVER_OBJECT, :PUNICODE_STRING

  DRIVER_CANCEL proto fastcall :ptr _DEVICE_OBJECT, :ptr _IRP

  DRIVER_DISPATCH proto fastcall :ptr _DEVICE_OBJECT, :ptr _IRP


  DRIVER_DISPATCH_PAGED proto fastcall :ptr _DEVICE_OBJECT, :ptr _IRP

  DRIVER_STARTIO proto fastcall :ptr _DEVICE_OBJECT, :ptr _IRP

  DRIVER_UNLOAD proto fastcall :ptr _DRIVER_OBJECT

  DRIVER_ADD_DEVICE proto fastcall :ptr _DRIVER_OBJECT, :ptr _DEVICE_OBJECT

  FAST_IO_CHECK_IF_POSSIBLE proto fastcall :ptr _FILE_OBJECT, :PLARGE_INTEGER, :DWORD, :BOOLEAN, :DWORD, :BOOLEAN, :PIO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_READ proto fastcall :ptr _FILE_OBJECT, :PLARGE_INTEGER, :DWORD, :BOOLEAN, :DWORD, :PVOID, :PIO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_WRITE proto fastcall :ptr _FILE_OBJECT, :PLARGE_INTEGER, :DWORD, :BOOLEAN, :DWORD, :PVOID, :PIO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_QUERY_BASIC_INFO proto fastcall :ptr _FILE_OBJECT, :BOOLEAN, :PFILE_BASIC_INFORMATION, :PIO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_QUERY_STANDARD_INFO proto fastcall :ptr _FILE_OBJECT, :BOOLEAN, :PFILE_STANDARD_INFORMATION, :PIO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_LOCK proto fastcall :ptr _FILE_OBJECT, :PLARGE_INTEGER, :PLARGE_INTEGER, :PEPROCESS, :DWORD, :BOOLEAN, :BOOLEAN, :PIO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_UNLOCK_SINGLE proto fastcall :ptr _FILE_OBJECT, :PLARGE_INTEGER, :PLARGE_INTEGER, :PEPROCESS, :DWORD, :PIO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_UNLOCK_ALL proto fastcall :ptr _FILE_OBJECT, :PEPROCESS, :PIO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_UNLOCK_ALL_BY_KEY proto fastcall :ptr _FILE_OBJECT, :PVOID, :DWORD, :PIO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_DEVICE_CONTROL proto fastcall :ptr _FILE_OBJECT, :BOOLEAN, :PVOID, :DWORD, :PVOID, :DWORD, :DWORD, :PIO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_ACQUIRE_FILE proto fastcall :ptr _FILE_OBJECT

  FAST_IO_RELEASE_FILE proto fastcall :ptr _FILE_OBJECT

  FAST_IO_DETACH_DEVICE proto fastcall :ptr _DEVICE_OBJECT, :ptr _DEVICE_OBJECT

  FAST_IO_QUERY_NETWORK_OPEN_INFO proto fastcall :ptr _FILE_OBJECT, :BOOLEAN, :ptr _FILE_NETWORK_OPEN_INFORMATION, :ptr _IO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_MDL_READ proto fastcall :ptr _FILE_OBJECT, :PLARGE_INTEGER, :DWORD, :DWORD, :ptr PMDL, :PIO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_MDL_READ_COMPLETE proto fastcall :ptr _FILE_OBJECT, :PMDL, :ptr _DEVICE_OBJECT

  FAST_IO_PREPARE_MDL_WRITE proto fastcall :ptr _FILE_OBJECT, :PLARGE_INTEGER, :DWORD, :DWORD, :ptr PMDL, :PIO_STATUS_BLOCK, :ptr _DEVICE_OBJECT

  FAST_IO_MDL_WRITE_COMPLETE proto fastcall :ptr _FILE_OBJECT, :PLARGE_INTEGER, :PMDL, :ptr _DEVICE_OBJECT

  FAST_IO_ACQUIRE_FOR_MOD_WRITE proto fastcall :ptr _FILE_OBJECT, :PLARGE_INTEGER, :ptr ptr _ERESOURCE, :ptr _DEVICE_OBJECT

  FAST_IO_RELEASE_FOR_MOD_WRITE proto fastcall :ptr _FILE_OBJECT, :ptr _ERESOURCE, :ptr _DEVICE_OBJECT

  FAST_IO_ACQUIRE_FOR_CCFLUSH proto fastcall :ptr _FILE_OBJECT, :ptr _DEVICE_OBJECT

  FAST_IO_RELEASE_FOR_CCFLUSH proto fastcall :ptr _FILE_OBJECT, :ptr _DEVICE_OBJECT

  FAST_IO_READ_COMPRESSED proto fastcall :ptr _FILE_OBJECT, :PLARGE_INTEGER, :DWORD, :DWORD, :PVOID, :ptr PMDL, :PIO_STATUS_BLOCK, :ptr _COMPRESSED_DATA_INFO, :DWORD, :ptr _DEVICE_OBJECT

  FAST_IO_WRITE_COMPRESSED proto fastcall :ptr _FILE_OBJECT, :PLARGE_INTEGER, :DWORD, :DWORD, :PVOID, :ptr PMDL, :PIO_STATUS_BLOCK, :ptr _COMPRESSED_DATA_INFO, :DWORD, :ptr _DEVICE_OBJECT

  FAST_IO_MDL_READ_COMPLETE_COMPRESSED proto fastcall :ptr _FILE_OBJECT, :PMDL, :ptr _DEVICE_OBJECT

  FAST_IO_MDL_WRITE_COMPLETE_COMPRESSED proto fastcall :ptr _FILE_OBJECT, :PLARGE_INTEGER, :PMDL, :ptr _DEVICE_OBJECT

  FAST_IO_QUERY_OPEN proto fastcall :ptr _IRP, :PFILE_NETWORK_OPEN_INFORMATION, :ptr _DEVICE_OBJECT

    IFNDEF FAST_IO_DISPATCH
    FAST_IO_DISPATCH                    STRUCT
        SizeOfFastIoDispatch            DWORD ?
        FastIoCheckIfPossible           QWORD ? ;PFAST_IO_CHECK_IF_POSSIBLE ?
        FastIoRead                      QWORD ? ;PFAST_IO_READ ?
        FastIoWrite                     QWORD ? ;PFAST_IO_WRITE ?
        FastIoQueryBasicInfo            QWORD ? ;PFAST_IO_QUERY_BASIC_INFO ?
        FastIoQueryStandardInfo         QWORD ? ;PFAST_IO_QUERY_STANDARD_INFO ?
        FastIoLock                      QWORD ? ;PFAST_IO_LOCK ?
        FastIoUnlockSingle              QWORD ? ;PFAST_IO_UNLOCK_SINGLE ?
        FastIoUnlockAll                 QWORD ? ;PFAST_IO_UNLOCK_ALL ?
        FastIoUnlockAllByKey            QWORD ? ;PFAST_IO_UNLOCK_ALL_BY_KEY ?
        FastIoDeviceControl             QWORD ? ;PFAST_IO_DEVICE_CONTROL ?
        AcquireFileForNtCreateSection   QWORD ? ;PFAST_IO_ACQUIRE_FILE ?
        ReleaseFileForNtCreateSection   QWORD ? ;PFAST_IO_RELEASE_FILE ?
        FastIoDetachDevice              QWORD ? ;PFAST_IO_DETACH_DEVICE ?
        FastIoQueryNetworkOpenInfo      QWORD ? ;PFAST_IO_QUERY_NETWORK_OPEN_INFO ?
        AcquireForModWrite              QWORD ? ;PFAST_IO_ACQUIRE_FOR_MOD_WRITE ?
        MdlRead                         QWORD ? ;PFAST_IO_MDL_READ ?
        MdlReadComplete                 QWORD ? ;PFAST_IO_MDL_READ_COMPLETE ?
        PrepareMdlWrite                 QWORD ? ;PFAST_IO_PREPARE_MDL_WRITE ?
        MdlWriteComplete                QWORD ? ;PFAST_IO_MDL_WRITE_COMPLETE ?
        FastIoReadCompressed            QWORD ? ;PFAST_IO_READ_COMPRESSED ?
        FastIoWriteCompressed           QWORD ? ;PFAST_IO_WRITE_COMPRESSED ?
        MdlReadCompleteCompressed       QWORD ? ;PFAST_IO_MDL_READ_COMPLETE_COMPRESSED ?
        MdlWriteCompleteCompressed      QWORD ? ;PFAST_IO_MDL_WRITE_COMPLETE_COMPRESSED ?
        FastIoQueryOpen                 QWORD ? ;PFAST_IO_QUERY_OPEN ?
        ReleaseForModWrite              QWORD ? ;PFAST_IO_RELEASE_FOR_MOD_WRITE ?
        AcquireForCcFlush               QWORD ? ;PFAST_IO_ACQUIRE_FOR_CCFLUSH ?
        ReleaseForCcFlush               QWORD ? ;PFAST_IO_RELEASE_FOR_CCFLUSH ?
    FAST_IO_DISPATCH                    ENDS
    ENDIF
    PFAST_IO_DISPATCH typedef ptr FAST_IO_DISPATCH
  
  IO_ALLOCATION_ACTION typedef SDWORD
  KeepObject EQU 1 
  DeallocateObject EQU 2
  DeallocateObjectKeepRegisters EQU 3
  
  PIO_ALLOCATION_ACTION typedef ptr IO_ALLOCATION_ACTION
  
  DRIVER_CONTROL typedef proto stdcall :ptr _DEVICE_OBJECT,:ptr _IRP,:PVOID,:PVOID
  PDRIVER_CONTROL typedef ptr DRIVER_CONTROL
  IO_SECURITY_CONTEXT struct
    SecurityQos PSECURITY_QUALITY_OF_SERVICE ?
    AccessState PACCESS_STATE ?
    DesiredAccess ACCESS_MASK ?
    FullCreateOptions DWORD ?
  IO_SECURITY_CONTEXT ends

  PIO_SECURITY_CONTEXT typedef ptr IO_SECURITY_CONTEXT
  
  VPB_MOUNTED equ 00000001h
  VPB_LOCKED equ 00000002h
  VPB_PERSISTENT equ 00000004h
  VPB_REMOVE_PENDING equ 00000008h
  VPB_RAW_MOUNT equ 00000010h
  VPB_DIRECT_WRITES_ALLOWED equ 00000020h
  MAXIMUM_VOLUME_LABEL_LENGTH equ ( 32 * sizeof ( WCHAR ) )

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
    PVPB typedef ptr VPB

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
    PWAIT_CONTEXT_BLOCK typedef ptr WAIT_CONTEXT_BLOCK
  
  PADAPTER_OBJECT typedef ptr _DMA_ADAPTER
  
  DO_VERIFY_VOLUME equ 00000002h
  DO_BUFFERED_IO equ 00000004h
  DO_EXCLUSIVE equ 00000008h
  DO_DIRECT_IO equ 00000010h
  DO_MAP_IO_BUFFER equ 00000020h
  DO_DEVICE_INITIALIZING equ 00000080h
  DO_SHUTDOWN_REGISTERED equ 00000800h
  DO_BUS_ENUMERATED_DEVICE equ 00001000h
  DO_POWER_PAGABLE equ 00002000h
  DO_POWER_INRUSH equ 00004000h
  DO_DEVICE_TO_BE_RESET equ 04000000h
  DO_DAX_VOLUME equ 10000000h


  
  Queue union
    ListEntry LIST_ENTRY <>
    Wcb WAIT_CONTEXT_BLOCK <>
  Queue ends

  PDEVICE_OBJECT typedef ptr DEVICE_OBJECT
  
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
    PDEVOBJ_EXTENSION typedef ptr DEVOBJ_EXTENSION
  
  
  DRVO_UNLOAD_INVOKED equ 00000001h
  DRVO_LEGACY_DRIVER equ 00000002h
  DRVO_BUILTIN_DRIVER equ 00000004h
  
  
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
  
  SECTION_OBJECT_POINTERS struct
    DataSectionObject PVOID ?
    SharedCacheMap PVOID ?
    ImageSectionObject PVOID ?
  SECTION_OBJECT_POINTERS ends

  PSECTION_OBJECT_POINTERS typedef ptr SECTION_OBJECT_POINTERS
  IO_COMPLETION_CONTEXT struct
    Port PVOID ?
    Key PVOID ?
  IO_COMPLETION_CONTEXT ends

  PIO_COMPLETION_CONTEXT typedef ptr IO_COMPLETION_CONTEXT
  
  FO_FILE_OPEN equ 00000001h
  FO_SYNCHRONOUS_IO equ 00000002h
  FO_ALERTABLE_IO equ 00000004h
  FO_NO_INTERMEDIATE_BUFFERING equ 00000008h
  FO_WRITE_THROUGH equ 00000010h
  FO_SEQUENTIAL_ONLY equ 00000020h
  FO_CACHE_SUPPORTED equ 00000040h
  FO_NAMED_PIPE equ 00000080h
  FO_STREAM_FILE equ 00000100h
  FO_MAILSLOT equ 00000200h
  FO_GENERATE_AUDIT_ON_CLOSE equ 00000400h
  FO_QUEUE_IRP_TO_THREAD equ <FO_GENERATE_AUDIT_ON_CLOSE>
  FO_DIRECT_DEVICE_OPEN equ 00000800h
  FO_FILE_MODIFIED equ 00001000h
  FO_FILE_SIZE_CHANGED equ 00002000h
  FO_CLEANUP_COMPLETE equ 00004000h
  FO_TEMPORARY_FILE equ 00008000h
  FO_DELETE_ON_CLOSE equ 00010000h
  FO_OPENED_CASE_SENSITIVE equ 00020000h
  FO_HANDLE_CREATED equ 00040000h
  FO_FILE_FAST_IO_READ equ 00080000h
  FO_RANDOM_ACCESS equ 00100000h
  FO_FILE_OPEN_CANCELLED equ 00200000h
  FO_VOLUME_OPEN equ 00400000h
  FO_REMOTE_ORIGIN equ 01000000h
  FO_DISALLOW_EXCLUSIVE equ 02000000h
  FO_SKIP_COMPLETION_PORT equ <FO_DISALLOW_EXCLUSIVE>
  FO_SKIP_SET_EVENT equ 04000000h
  FO_SKIP_SET_FAST_IO equ 08000000h
  FO_INDIRECT_WAIT_OBJECT equ 10000000h
  FO_SECTION_MINSTORE_TREATMENT equ 20000000h
  FO_FLAGS_VALID_ONLY_DURING_CREATE equ <FO_DISALLOW_EXCLUSIVE>
  
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
    PFILE_OBJECT typedef ptr FILE_OBJECT

    IFNDEF IRP
    IRP STRUCT
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
    
    IRP ENDS
    ENDIF
    PIRP typedef PTR IRP

  
  IRP_NOCACHE equ 00000001h
  IRP_PAGING_IO equ 00000002h
  IRP_MOUNT_COMPLETION equ 00000002h
  IRP_SYNCHRONOUS_API equ 00000004h
  IRP_ASSOCIATED_IRP equ 00000008h
  IRP_BUFFERED_IO equ 00000010h
  IRP_DEALLOCATE_BUFFER equ 00000020h
  IRP_INPUT_OPERATION equ 00000040h
  IRP_SYNCHRONOUS_PAGING_IO equ 00000040h
  IRP_CREATE_OPERATION equ 00000080h
  IRP_READ_OPERATION equ 00000100h
  IRP_WRITE_OPERATION equ 00000200h
  IRP_CLOSE_OPERATION equ 00000400h
  IRP_DEFER_IO_COMPLETION equ 00000800h
  IRP_OB_QUERY_NAME equ 00001000h
  IRP_HOLD_DEVICE_QUEUE equ 00002000h
  IRP_UM_DRIVER_INITIATED_IO equ 00400000h
  IRP_QUOTA_CHARGED equ 01h
  IRP_ALLOCATED_MUST_SUCCEED equ 02h
  IRP_ALLOCATED_FIXED_SIZE equ 04h
  IRP_LOOKASIDE_ALLOCATION equ 08h

  
  AssociatedIrp union
    MasterIrp POINTER ?
    IrpCount SDWORD ?
    SystemBuffer PVOID ?
  AssociatedIrp ends

  Overlay union
    struct AsynchronousParameters
      union
        UserApcRoutine PIO_APC_ROUTINE ?
        IssuingProcess PVOID ?
      ends
      UserApcContext PVOID ?
    ends
    AllocationSize LARGE_INTEGER <>
  Overlay ends

  Tail union
    struct Overlay
      union
        DeviceQueueEntry KDEVICE_QUEUE_ENTRY <>
        struct
          DriverContext PVOID 4 dup (?)
        ends
      ends
      Thread PETHREAD ?
      AuxiliaryBuffer PCHAR ?
      struct
        ListEntry LIST_ENTRY <>
        union
          CurrentStackLocation POINTER ?
          PacketType DWORD ?
        ends
      ends
      OriginalFileObject PFILE_OBJECT ?
    ends
    Apc KAPC <>
    CompletionKey PVOID ?
  Tail ends






  IO_COMPLETION_ROUTINE proto fastcall :PDEVICE_OBJECT, :PIRP, :PVOID

  SL_PENDING_RETURNED equ 01h
  SL_ERROR_RETURNED equ 02h
  SL_INVOKE_ON_CANCEL equ 20h
  SL_INVOKE_ON_SUCCESS equ 40h
  SL_INVOKE_ON_ERROR equ 80h
  SL_FORCE_ACCESS_CHECK equ 01h
  SL_OPEN_PAGING_FILE equ 02h
  SL_OPEN_TARGET_DIRECTORY equ 04h
  SL_STOP_ON_SYMLINK equ 08h
  SL_IGNORE_READONLY_ATTRIBUTE equ 40h
  SL_CASE_SENSITIVE equ 80h
  SL_KEY_SPECIFIED equ 01h
  SL_OVERRIDE_VERIFY_VOLUME equ 02h
  SL_WRITE_THROUGH equ 04h
  SL_FT_SEQUENTIAL_WRITE equ 08h
  SL_FORCE_DIRECT_WRITE equ 10h
  SL_REALTIME_STREAM equ 20h
  SL_PERSISTENT_MEMORY_FIXED_MAPPING equ 20h
  SL_FORCE_ASYNCHRONOUS equ 01h
  SL_READ_ACCESS_GRANTED equ 01h
  SL_WRITE_ACCESS_GRANTED equ 04h
  SL_FAIL_IMMEDIATELY equ 01h
  SL_EXCLUSIVE_LOCK equ 02h
  SL_RESTART_SCAN equ 01h
  SL_RETURN_SINGLE_ENTRY equ 02h
  SL_INDEX_SPECIFIED equ 04h
  SL_RETURN_ON_DISK_ENTRIES_ONLY equ 08h
  SL_QUERY_DIRECTORY_MASK equ 0bh
  SL_WATCH_TREE equ 01h
  SL_ALLOW_RAW_MOUNT equ 01h
  SL_BYPASS_ACCESS_CHECK equ 01h
  DEVICE_RELATION_TYPE typedef SDWORD
  BusRelations EQU 0
  EjectionRelations EQU 1
  PowerRelations EQU 2
  RemovalRelations EQU 3
  TargetDeviceRelation EQU 4
  SingleBusRelations EQU 5
  TransportRelations EQU 6
  
  PDEVICE_RELATION_TYPE typedef ptr DEVICE_RELATION_TYPE
  
  DEVICE_RELATIONS struct
    Count DWORD ?
    Objects PDEVICE_OBJECT 1 dup (?)
  DEVICE_RELATIONS ends

  PDEVICE_RELATIONS typedef ptr DEVICE_RELATIONS
  
  DEVICE_USAGE_NOTIFICATION_TYPE typedef SDWORD
  DeviceUsageTypeUndefined EQU 0
  DeviceUsageTypePaging EQU 1
  DeviceUsageTypeHibernation EQU 2
  DeviceUsageTypeDumpFile EQU 3
  DeviceUsageTypeBoot EQU 4
  DeviceUsageTypePostDisplay EQU 5
  

  INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
  INTERFACE ends

  PINTERFACE typedef ptr INTERFACE
  
  DEVICE_CAPABILITIES struct
    Size_ WORD ?
    Version WORD ?
    DEVICE_CAPABILITIES_??29 record DeviceD1_??29:1, DeviceD2_??29:1, LockSupported_??29:1, EjectSupported_??29:1, Removable_??29:1, DockDevice_??29:1, UniqueID_??29:1, SilentInstall_??29:1, RawDeviceOK_??29:1, SurpriseRemovalOK_??29:1, WakeFromD0_??29:1, WakeFromD1_??29:1, WakeFromD2_??29:1, WakeFromD3_??29:1, HardwareDisabled_??29:1, NonDynamic_??29:1, WarmEjectSupported_??29:1, NoDisplayInUI_??29:1, Reserved1_??29:1, WakeFromInterrupt_??29:1, SecureDevice_??29:1, ChildOfVgaEnabledBridge_??29:1, DecodeIoOnBoot_??29:1, Reserved_??29:9
    DEVICE_CAPABILITIES_??29 <>
    Address DWORD ?
    UINumber DWORD ?
    DeviceState DEVICE_POWER_STATE POWER_SYSTEM_MAXIMUM dup (?)
    SystemWake SYSTEM_POWER_STATE ?
    DeviceWake DEVICE_POWER_STATE ?
    D1Latency DWORD ?
    D2Latency DWORD ?
    D3Latency DWORD ?
  DEVICE_CAPABILITIES ends

  PDEVICE_CAPABILITIES typedef ptr DEVICE_CAPABILITIES
  
  POWER_SEQUENCE struct
    SequenceD1 DWORD ?
    SequenceD2 DWORD ?
    SequenceD3 DWORD ?
  POWER_SEQUENCE ends

  PPOWER_SEQUENCE typedef ptr POWER_SEQUENCE
  
  BUS_QUERY_ID_TYPE typedef SDWORD
  BusQueryDeviceID EQU 0 
  BusQueryHardwareIDs EQU 1 
  BusQueryCompatibleIDs EQU 2 
  BusQueryInstanceID EQU 3 
  BusQueryDeviceSerialNumber EQU 4 
  BusQueryContainerID EQU 5 
  
  PBUS_QUERY_ID_TYPE typedef ptr BUS_QUERY_ID_TYPE
  
  PNP_DEVICE_STATE typedef DWORD
  PPNP_DEVICE_STATE typedef ptr DWORD
  PNP_DEVICE_DISABLED equ 00000001h
  PNP_DEVICE_DONT_DISPLAY_IN_UI equ 00000002h
  PNP_DEVICE_FAILED equ 00000004h
  PNP_DEVICE_REMOVED equ 00000008h
  PNP_DEVICE_RESOURCE_REQUIREMENTS_CHANGED equ 00000010h
  PNP_DEVICE_NOT_DISABLEABLE equ 00000020h
  PNP_DEVICE_DISCONNECTED equ 00000040h
  DEVICE_TEXT_TYPE typedef SDWORD
  DeviceTextDescription EQU 0 
  DeviceTextLocationInformation EQU 1 
  
  PDEVICE_TEXT_TYPE typedef ptr DEVICE_TEXT_TYPE
  

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
    PIO_STACK_LOCATION typedef ptr IO_STACK_LOCATION

  SHARE_ACCESS struct
    OpenCount DWORD ?
    Readers DWORD ?
    Writers DWORD ?
    Deleters DWORD ?
    SharedRead DWORD ?
    SharedWrite DWORD ?
    SharedDelete DWORD ?
  SHARE_ACCESS ends

  PSHARE_ACCESS typedef ptr SHARE_ACCESS
  
  LINK_SHARE_ACCESS struct
    OpenCount DWORD ?
    Deleters DWORD ?
    SharedDelete DWORD ?
  LINK_SHARE_ACCESS ends

  PLINK_SHARE_ACCESS typedef ptr LINK_SHARE_ACCESS
  

  IO_PAGING_PRIORITY typedef SDWORD
  IoPagingPriorityInvalid EQU 0
  IoPagingPriorityNormal EQU 1
  IoPagingPriorityHigh EQU 2
  IoPagingPriorityReserved1 EQU 3
  IoPagingPriorityReserved2 EQU 4

  BOOTDISK_INFORMATION struct
    BootPartitionOffset QWORD ?
    SystemPartitionOffset QWORD ?
    BootDeviceSignature DWORD ?
    SystemDeviceSignature DWORD ?
  BOOTDISK_INFORMATION ends

  PBOOTDISK_INFORMATION typedef ptr BOOTDISK_INFORMATION
  
  BOOTDISK_INFORMATION_EX struct
    BootPartitionOffset QWORD ?
    SystemPartitionOffset QWORD ?
    BootDeviceSignature DWORD ?
    SystemDeviceSignature DWORD ?
    BootDeviceGuid GUID <>
    SystemDeviceGuid GUID <>
    BootDeviceIsGpt BOOLEAN ?
    SystemDeviceIsGpt BOOLEAN ?
  BOOTDISK_INFORMATION_EX ends

  PBOOTDISK_INFORMATION_EX typedef ptr BOOTDISK_INFORMATION_EX
  

    LOADER_PARTITION_INFORMATION_EX struct
      PartitionStyle DWORD ?
      PartitionNumber DWORD ?
      union
        Signature DWORD ?
        DeviceId GUID <>
      ends
      Flags DWORD ?
    LOADER_PARTITION_INFORMATION_EX ends

    PLOADER_PARTITION_INFORMATION_EX typedef ptr LOADER_PARTITION_INFORMATION_EX

      BOOTDISK_INFORMATION_LITE struct
        BootDeviceSignature DWORD ?
        SystemDeviceSignature DWORD ?
        BootDeviceGuid GUID <>
        SystemDeviceGuid GUID <>
        BootDeviceIsGpt BOOLEAN ?
        SystemDeviceIsGpt BOOLEAN ?
      BOOTDISK_INFORMATION_LITE ends

      PBOOTDISK_INFORMATION_LITE typedef ptr BOOTDISK_INFORMATION_LITE


  IO_SHARE_ACCESS_NO_WRITE_PERMISSION equ 80000000h
  IO_CHECK_SHARE_ACCESS_UPDATE_SHARE_ACCESS equ 00000001h
  IO_CHECK_SHARE_ACCESS_DONT_UPDATE_FILE_OBJECT equ 00000002h
  IO_CHECK_SHARE_ACCESS_DONT_CHECK_READ equ 00000004h
  IO_CHECK_SHARE_ACCESS_DONT_CHECK_WRITE equ 00000008h
  IO_CHECK_SHARE_ACCESS_DONT_CHECK_DELETE equ 00000010h
  IO_CHECK_SHARE_ACCESS_FORCE_CHECK equ 00000020h
  STATUS_CONTINUE_COMPLETION equ <STATUS_SUCCESS>
  IO_COMPLETION_ROUTINE_RESULT typedef SDWORD
  ContinueCompletion EQU STATUS_CONTINUE_COMPLETION 
  StopCompletion EQU STATUS_MORE_PROCESSING_REQUIRED 
  
  PIO_COMPLETION_ROUTINE_RESULT typedef ptr IO_COMPLETION_ROUTINE_RESULT

  IO_INTERRUPT_MESSAGE_INFO_ENTRY struct
    MessageAddress PHYSICAL_ADDRESS <>
    TargetProcessorSet KAFFINITY ?
    InterruptObject PKINTERRUPT ?
    MessageData DWORD ?
    Vector DWORD ?
    Irql KIRQL ?
    Mode KINTERRUPT_MODE ?
    Polarity KINTERRUPT_POLARITY ?
  IO_INTERRUPT_MESSAGE_INFO_ENTRY ends

  PIO_INTERRUPT_MESSAGE_INFO_ENTRY typedef ptr IO_INTERRUPT_MESSAGE_INFO_ENTRY
  
  IO_INTERRUPT_MESSAGE_INFO struct
    UnifiedIrql KIRQL ?
    MessageCount DWORD ?
    MessageInfo IO_INTERRUPT_MESSAGE_INFO_ENTRY 1 dup (<>)
  IO_INTERRUPT_MESSAGE_INFO ends

  PIO_INTERRUPT_MESSAGE_INFO typedef ptr IO_INTERRUPT_MESSAGE_INFO
  
  IO_CONNECT_INTERRUPT_FULLY_SPECIFIED_PARAMETERS struct
    PhysicalDeviceObject PDEVICE_OBJECT ?
    InterruptObject POINTER ?
    ServiceRoutine PKSERVICE_ROUTINE ?
    ServiceContext PVOID ?
    SpinLock PKSPIN_LOCK ?
    SynchronizeIrql KIRQL ?
    FloatingSave BOOLEAN ?
    ShareVector BOOLEAN ?
    Vector DWORD ?
    Irql KIRQL ?
    InterruptMode KINTERRUPT_MODE ?
    ProcessorEnableMask KAFFINITY ?
    Group_ WORD ?
  IO_CONNECT_INTERRUPT_FULLY_SPECIFIED_PARAMETERS ends

  PIO_CONNECT_INTERRUPT_FULLY_SPECIFIED_PARAMETERS typedef ptr IO_CONNECT_INTERRUPT_FULLY_SPECIFIED_PARAMETERS
  
  IO_CONNECT_INTERRUPT_LINE_BASED_PARAMETERS struct
    PhysicalDeviceObject PDEVICE_OBJECT ?
    InterruptObject POINTER ?
    ServiceRoutine PKSERVICE_ROUTINE ?
    ServiceContext PVOID ?
    SpinLock PKSPIN_LOCK ?
    SynchronizeIrql KIRQL ?
    FloatingSave BOOLEAN ?
  IO_CONNECT_INTERRUPT_LINE_BASED_PARAMETERS ends

  PIO_CONNECT_INTERRUPT_LINE_BASED_PARAMETERS typedef ptr IO_CONNECT_INTERRUPT_LINE_BASED_PARAMETERS
  
  IO_CONNECT_INTERRUPT_MESSAGE_BASED_PARAMETERS struct
    PhysicalDeviceObject PDEVICE_OBJECT ?
    union ConnectionContext
      Generic POINTER ?
      InterruptMessageTable POINTER ?
      InterruptObject POINTER ?
    ends
    MessageServiceRoutine PKMESSAGE_SERVICE_ROUTINE ?
    ServiceContext PVOID ?
    SpinLock PKSPIN_LOCK ?
    SynchronizeIrql KIRQL ?
    FloatingSave BOOLEAN ?
    FallBackServiceRoutine PKSERVICE_ROUTINE ?
  IO_CONNECT_INTERRUPT_MESSAGE_BASED_PARAMETERS ends

  PIO_CONNECT_INTERRUPT_MESSAGE_BASED_PARAMETERS typedef ptr IO_CONNECT_INTERRUPT_MESSAGE_BASED_PARAMETERS
  
  CONNECT_FULLY_SPECIFIED equ 1h
  CONNECT_LINE_BASED equ 2h
  CONNECT_MESSAGE_BASED equ 3h
  CONNECT_FULLY_SPECIFIED_GROUP equ 4h
  CONNECT_MESSAGE_BASED_PASSIVE equ 5h
  CONNECT_CURRENT_VERSION equ 5h
  IO_CONNECT_INTERRUPT_PARAMETERS struct
    Version DWORD ?
    union
      FullySpecified IO_CONNECT_INTERRUPT_FULLY_SPECIFIED_PARAMETERS <>
      LineBased IO_CONNECT_INTERRUPT_LINE_BASED_PARAMETERS <>
      MessageBased IO_CONNECT_INTERRUPT_MESSAGE_BASED_PARAMETERS <>
    ends
  IO_CONNECT_INTERRUPT_PARAMETERS ends

  PIO_CONNECT_INTERRUPT_PARAMETERS typedef ptr IO_CONNECT_INTERRUPT_PARAMETERS

  WDM_MAJORVERSION equ 06h
  WDM_MINORVERSION equ 00h


  IO_DISCONNECT_INTERRUPT_PARAMETERS struct
    Version DWORD ?
    union ConnectionContext
      Generic PVOID ?
      InterruptObject PKINTERRUPT ?
      InterruptMessageTable PIO_INTERRUPT_MESSAGE_INFO ?
    ends
  IO_DISCONNECT_INTERRUPT_PARAMETERS ends

  PIO_DISCONNECT_INTERRUPT_PARAMETERS typedef ptr IO_DISCONNECT_INTERRUPT_PARAMETERS

  IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS struct
    Version DWORD ?
    union ConnectionContext
      Generic PVOID ?
      InterruptObject PKINTERRUPT ?
      InterruptMessageTable PIO_INTERRUPT_MESSAGE_INFO ?
    ends
  IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS ends

  PIO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS typedef ptr IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS


  PIO_REMOVE_LOCK_TRACKING_BLOCK typedef ptr _IO_REMOVE_LOCK_TRACKING_BLOCK
  
  IO_REMOVE_LOCK_COMMON_BLOCK struct
    Removed BOOLEAN ?
    Reserved BOOLEAN 3 dup (?)
    IoCount SDWORD ?
    RemoveEvent KEVENT <>
  IO_REMOVE_LOCK_COMMON_BLOCK ends

  IO_REMOVE_LOCK_DBG_BLOCK struct
    Signature SDWORD ?
    HighWatermark DWORD ?
    MaxLockedTicks QWORD ?
    AllocateTag SDWORD ?
    LockList LIST_ENTRY <>
    Spin KSPIN_LOCK ?
    LowMemoryCount SDWORD ?
    Reserved1 DWORD 4 dup (?)
    Reserved2 PVOID ?
    Blocks PIO_REMOVE_LOCK_TRACKING_BLOCK ?
  IO_REMOVE_LOCK_DBG_BLOCK ends

  IO_REMOVE_LOCK struct
    Common IO_REMOVE_LOCK_COMMON_BLOCK <>
      Dbg IO_REMOVE_LOCK_DBG_BLOCK <>
  IO_REMOVE_LOCK ends

  PIO_REMOVE_LOCK typedef ptr IO_REMOVE_LOCK


  PIO_WORKITEM typedef ptr _IO_WORKITEM
  

  WMIREG_ACTION_REGISTER equ 1
  WMIREG_ACTION_DEREGISTER equ 2
  WMIREG_ACTION_REREGISTER equ 3
  WMIREG_ACTION_UPDATE_GUIDS equ 4
  WMIREG_ACTION_BLOCK_IRPS equ 5
  WMIREGISTER equ 0
  WMIUPDATE equ 1



  FWMI_NOTIFICATION_CALLBACK typedef proto stdcall :PVOID,:PVOID
  WMI_NOTIFICATION_CALLBACK typedef ptr FWMI_NOTIFICATION_CALLBACK

  IO_CSQ struct
    Type_ DWORD ?
    CsqInsertIrp QWORD ? ; PIO_CSQ_INSERT_IRP ?
    CsqRemoveIrp QWORD ? ; PIO_CSQ_REMOVE_IRP ?
    CsqPeekNextIrp QWORD ? ; PIO_CSQ_PEEK_NEXT_IRP ?
    CsqAcquireLock QWORD ? ; PIO_CSQ_ACQUIRE_LOCK ?
    CsqReleaseLock QWORD ? ; PIO_CSQ_RELEASE_LOCK ?
    CsqCompleteCanceledIrp QWORD ? ; PIO_CSQ_COMPLETE_CANCELED_IRP ?
    ReservePointer PVOID ?
  IO_CSQ ends
  PIO_CSQ typedef ptr IO_CSQ
  
  IO_TYPE_CSQ_IRP_CONTEXT equ 1
  IO_TYPE_CSQ equ 2
  IO_TYPE_CSQ_EX equ 3
  IO_CSQ_IRP_CONTEXT struct
    Type_ DWORD ?
    Irp_ PIRP ?
    Csq PIO_CSQ ?
  IO_CSQ_IRP_CONTEXT ends

  PIO_CSQ_IRP_CONTEXT typedef ptr IO_CSQ_IRP_CONTEXT  


    IO_ATTRIBUTION_INFO_V1 equ 1
    IO_ATTRIBUTION_INFORMATION struct
      Version DWORD ?
      union Flags
        struct
          Flags_??30 record MajorCode_??30:8, IoStart_??30:1, QueueOnly_??30:1, IoFailed_??30:1, VirtualDevice_??30:1, Spare_??30:20
          Flags_??30 <>
        ends
        AllFlags DWORD ?
      ends
      Length_ DWORD ?
      ServiceStartTime QWORD ?
      CurrentTime QWORD ?
    IO_ATTRIBUTION_INFORMATION ends

    PIO_ATTRIBUTION_INFORMATION typedef ptr IO_ATTRIBUTION_INFORMATION
    

    IO_SET_IRP_IO_ATTRIBUTION_FROM_THREAD equ 1h
    IO_SET_IRP_IO_ATTRIBUTION_FROM_PROCESS equ 2h
    IO_SET_IRP_IO_ATTRIBUTION_FLAGS_MASK equ 3h


  IO_ACCESS_TYPE typedef SDWORD
  ReadAccess EQU 0
  WriteAccess EQU 1
  ModifyAccess EQU 2
  
  IO_ACCESS_MODE typedef SDWORD
  SequentialAccess EQU 0
  RandomAccess EQU 1
  
  IO_CONTAINER_NOTIFICATION_CLASS typedef SDWORD
  IoSessionStateNotification EQU 0
  IoMaxContainerNotificationClass EQU 1
  
  IO_SESSION_STATE_NOTIFICATION struct
    Size_ DWORD ?
    Flags DWORD ?
    IoObject PVOID ?
    EventMask DWORD ?
    Context PVOID ?
  IO_SESSION_STATE_NOTIFICATION ends

  PIO_SESSION_STATE_NOTIFICATION typedef ptr IO_SESSION_STATE_NOTIFICATION
  
  IO_CONTAINER_INFORMATION_CLASS typedef SDWORD
  IoSessionStateInformation EQU 0
  IoMaxContainerInformationClass EQU 1
  
  IO_SESSION_STATE_INFORMATION struct
    SessionId DWORD ?
    SessionState IO_SESSION_STATE ?
    LocalSession BOOLEAN ?
  IO_SESSION_STATE_INFORMATION ends

  PIO_SESSION_STATE_INFORMATION typedef ptr IO_SESSION_STATE_INFORMATION
  
    _TRACEHANDLE_DEFINED equ <>
    TRACEHANDLE typedef ULONG64
    PTRACEHANDLE typedef ptr ULONG64


    ETW_TRACE_SESSION_SETTINGS struct
      Version DWORD ?
      BufferSize DWORD ?
      MinimumBuffers DWORD ?
      MaximumBuffers DWORD ?
      LoggerMode DWORD ?
      FlushTimer DWORD ?
      FlushThreshold DWORD ?
      ClockType DWORD ?
    ETW_TRACE_SESSION_SETTINGS ends

    PETW_TRACE_SESSION_SETTINGS typedef ptr ETW_TRACE_SESSION_SETTINGS
    
    TRACE_INFORMATION_CLASS typedef SDWORD
    TraceIdClass EQU 0
    TraceHandleClass EQU 1
    TraceEnableFlagsClass EQU 2
    TraceEnableLevelClass EQU 3
    GlobalLoggerHandleClass EQU 4
    EventLoggerHandleClass EQU 5
    AllLoggerHandlesClass EQU 6
    TraceHandleByNameClass EQU 7
    LoggerEventsLostClass EQU 8
    TraceSessionSettingsClass EQU 9
    LoggerEventsLoggedClass EQU 10
    DiskIoNotifyRoutinesClass EQU 11
    TraceInformationClassReserved1 EQU 12
    FltIoNotifyRoutinesClass EQU 13
    TraceInformationClassReserved2 EQU 14
    WdfNotifyRoutinesClass EQU 15
    MaxTraceInformationClass EQU 16



    __string_type equ 0
    __guid_type equ 0
    __multiString_type equ 0

  DEVICE_REGISTRY_PROPERTY typedef SDWORD
  DevicePropertyDeviceDescription EQU 0h or __string_type 
  DevicePropertyHardwareID EQU 1h or __multiString_type 
  DevicePropertyCompatibleIDs EQU 2h or __multiString_type 
  DevicePropertyBootConfiguration EQU 3h 
  DevicePropertyBootConfigurationTranslated EQU 4h 
  DevicePropertyClassName EQU 5h or __string_type 
  DevicePropertyClassGuid EQU 6h or __string_type 
  DevicePropertyDriverKeyName EQU 7h or __string_type 
  DevicePropertyManufacturer EQU 8h or __string_type 
  DevicePropertyFriendlyName EQU 9h or __string_type 
  DevicePropertyLocationInformation EQU 0ah or __string_type 
  DevicePropertyPhysicalDeviceObjectName EQU 0bh or __string_type 
  DevicePropertyBusTypeGuid EQU 0ch or __guid_type 
  DevicePropertyLegacyBusType EQU 0dh 
  DevicePropertyBusNumber EQU 0eh 
  DevicePropertyEnumeratorName EQU 0fh or __string_type 
  DevicePropertyAddress EQU 10h 
  DevicePropertyUINumber EQU 11h 
  DevicePropertyInstallState EQU 12h 
  DevicePropertyRemovalPolicy EQU 13h 
  DevicePropertyResourceRequirements EQU 14h 
  DevicePropertyAllocatedResources EQU 15h 
  DevicePropertyContainerID EQU 16h or __string_type 
  
  TRANSLATE_BUS_ADDRESS typedef proto stdcall :PVOID,:PHYSICAL_ADDRESS,:DWORD,:PULONG,:PPHYSICAL_ADDRESS
  PTRANSLATE_BUS_ADDRESS typedef ptr TRANSLATE_BUS_ADDRESS
  Context typedef ptr _DMA_ADAPTER
  DeviceDescriptor typedef ptr _DMA_ADAPTER
  
  PGET_DMA_ADAPTER typedef ptr GET_DMA_ADAPTER

  DEVICE_INSTALL_STATE typedef SDWORD
  InstallStateInstalled EQU 0
  InstallStateNeedsReinstall EQU 1
  InstallStateFailedInstall EQU 2
  InstallStateFinishInstall EQU 3
  
  PDEVICE_INSTALL_STATE typedef ptr DEVICE_INSTALL_STATE
  
  PNP_BUS_INFORMATION struct
    BusTypeGuid GUID <>
    LegacyBusType INTERFACE_TYPE ?
    BusNumber DWORD ?
  PNP_BUS_INFORMATION ends

  PPNP_BUS_INFORMATION typedef ptr PNP_BUS_INFORMATION
  
  LEGACY_BUS_INFORMATION struct
    BusTypeGuid GUID <>
    LegacyBusType INTERFACE_TYPE ?
    BusNumber DWORD ?
  LEGACY_BUS_INFORMATION ends

  PLEGACY_BUS_INFORMATION typedef ptr LEGACY_BUS_INFORMATION
  
  DEVICE_REMOVAL_POLICY typedef SDWORD
  RemovalPolicyExpectNoRemoval EQU 1 
  RemovalPolicyExpectOrderlyRemoval EQU 2 
  RemovalPolicyExpectSurpriseRemoval EQU 3 
  
  PDEVICE_REMOVAL_POLICY typedef ptr DEVICE_REMOVAL_POLICY
  
  BUS_INTERFACE_STANDARD struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    TranslateBusAddress PTRANSLATE_BUS_ADDRESS ?
    GetDmaAdapter PGET_DMA_ADAPTER ?
    SetBusData PGET_SET_DEVICE_DATA ?
    GetBusData PGET_SET_DEVICE_DATA ?
  BUS_INTERFACE_STANDARD ends

  PBUS_INTERFACE_STANDARD typedef ptr BUS_INTERFACE_STANDARD
  
  GET_VIRTUAL_DEVICE_DATA typedef proto stdcall :PVOID,:WORD,:PVOID,:DWORD,:DWORD
  PGET_VIRTUAL_DEVICE_DATA typedef ptr GET_VIRTUAL_DEVICE_DATA
  SET_VIRTUAL_DEVICE_DATA typedef proto stdcall :PVOID,:WORD,:PVOID,:DWORD,:DWORD
  PSET_VIRTUAL_DEVICE_DATA typedef ptr SET_VIRTUAL_DEVICE_DATA
  GET_VIRTUAL_DEVICE_LOCATION typedef proto stdcall :PVOID,:WORD,:PUINT16,:PUINT8,:PUINT8
  PGET_VIRTUAL_DEVICE_LOCATION typedef ptr GET_VIRTUAL_DEVICE_LOCATION
  GET_VIRTUAL_DEVICE_RESOURCES typedef proto stdcall :PVOID,:PUINT8
  PGET_VIRTUAL_DEVICE_RESOURCES typedef ptr GET_VIRTUAL_DEVICE_RESOURCES
  ENABLE_VIRTUALIZATION typedef proto stdcall :PVOID,:UINT16,:BOOLEAN,:BOOLEAN,:BOOLEAN
  PENABLE_VIRTUALIZATION typedef ptr ENABLE_VIRTUALIZATION
  GET_VIRTUAL_FUNCTION_PROBED_BARS typedef proto stdcall :PVOID,:PULONG
  PGET_VIRTUAL_FUNCTION_PROBED_BARS typedef ptr GET_VIRTUAL_FUNCTION_PROBED_BARS
  PCI_VIRTUALIZATION_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    SetVirtualFunctionData PSET_VIRTUAL_DEVICE_DATA ?
    GetVirtualFunctionData PGET_VIRTUAL_DEVICE_DATA ?
    GetLocation PGET_VIRTUAL_DEVICE_LOCATION ?
    GetResources PGET_VIRTUAL_DEVICE_RESOURCES ?
    EnableVirtualization PENABLE_VIRTUALIZATION ?
    GetVirtualFunctionProbedBars PGET_VIRTUAL_FUNCTION_PROBED_BARS ?
  PCI_VIRTUALIZATION_INTERFACE ends

  PPCI_VIRTUALIZATION_INTERFACE typedef ptr PCI_VIRTUALIZATION_INTERFACE
  
  PCI_SECURITY_INTERFACE_VERSION equ 1
  PCI_ACS_BIT typedef SDWORD
  PciAcsReserved EQU 0 
  PciAcsBitEnable EQU 1
  PciAcsBitDisable EQU 2
  PciAcsBitDontCare EQU 3
  
  PPCI_ACS_BIT typedef ptr PCI_ACS_BIT
  
  PCI_SET_ACS typedef proto stdcall :PVOID,:PCI_ACS_BIT,:PCI_ACS_BIT,:PCI_ACS_BIT,:PCI_ACS_BIT,:PCI_ACS_BIT,:PCI_ACS_BIT,:PCI_ACS_BIT
  PPCI_SET_ACS typedef ptr PCI_SET_ACS
  PCI_SECURITY_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    SetAccessControlServices PPCI_SET_ACS ?
  PCI_SECURITY_INTERFACE ends

  PPCI_SECURITY_INTERFACE typedef ptr PCI_SECURITY_INTERFACE
  
  proto_PREENUMERATE_SELF typedef proto fastcall :PVOID
  PREENUMERATE_SELF typedef ptr proto_PREENUMERATE_SELF
  REENUMERATE_SELF_INTERFACE_STANDARD struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    SurpriseRemoveAndReenumerateSelf PREENUMERATE_SELF ?
  REENUMERATE_SELF_INTERFACE_STANDARD ends

  PREENUMERATE_SELF_INTERFACE_STANDARD typedef ptr REENUMERATE_SELF_INTERFACE_STANDARD
  
  proto_PQUERYEXTENDEDADDRESS typedef proto fastcall :PVOID, :PULONG64
  PQUERYEXTENDEDADDRESS typedef ptr proto_PQUERYEXTENDEDADDRESS
  PNP_EXTENDED_ADDRESS_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    QueryExtendedAddress PQUERYEXTENDEDADDRESS ?
  PNP_EXTENDED_ADDRESS_INTERFACE ends

  PPNP_EXTENDED_ADDRESS_INTERFACE typedef ptr PNP_EXTENDED_ADDRESS_INTERFACE
  
  PNP_EXTENDED_ADDRESS_INTERFACE_VERSION equ 1h
  D3COLD_SUPPORT_INTERFACE_VERSION equ 1
  SET_D3COLD_SUPPORT typedef proto stdcall :PVOID,:BOOLEAN
  PSET_D3COLD_SUPPORT typedef ptr SET_D3COLD_SUPPORT
  DEVICE_WAKE_DEPTH typedef SDWORD
  DeviceWakeDepthNotWakeable EQU 0 
  DeviceWakeDepthD0 EQU 1
  DeviceWakeDepthD1 EQU 2
  DeviceWakeDepthD2 EQU 3
  DeviceWakeDepthD3hot EQU 4
  DeviceWakeDepthD3cold EQU 5
  DeviceWakeDepthMaximum EQU 6
  
  PDEVICE_WAKE_DEPTH typedef ptr DEVICE_WAKE_DEPTH
  
  MapWakeDepthToDstate proto fastcall :DEVICE_WAKE_DEPTH
  GET_IDLE_WAKE_INFO typedef proto stdcall :PVOID,:SYSTEM_POWER_STATE,:PDEVICE_WAKE_DEPTH
  PGET_IDLE_WAKE_INFO typedef ptr GET_IDLE_WAKE_INFO
  GET_D3COLD_CAPABILITY typedef proto stdcall :PVOID,:PBOOLEAN
  PGET_D3COLD_CAPABILITY typedef ptr GET_D3COLD_CAPABILITY
  D3COLD_LAST_TRANSITION_STATUS typedef SDWORD
  LastDStateTransitionStatusUnknown EQU 0 
  LastDStateTransitionD3hot EQU 1
  LastDStateTransitionD3cold EQU 2
  
  PD3COLD_LAST_TRANSITION_STATUS typedef ptr D3COLD_LAST_TRANSITION_STATUS
  
  GET_D3COLD_LAST_TRANSITION_STATUS typedef proto stdcall :PVOID,:PD3COLD_LAST_TRANSITION_STATUS
  PGET_D3COLD_LAST_TRANSITION_STATUS typedef ptr GET_D3COLD_LAST_TRANSITION_STATUS
  D3COLD_SUPPORT_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    SetD3ColdSupport PSET_D3COLD_SUPPORT ?
    GetIdleWakeInfo PGET_IDLE_WAKE_INFO ?
    GetD3ColdCapability PGET_D3COLD_CAPABILITY ?
    GetBusDriverD3ColdSupport PGET_D3COLD_CAPABILITY ?
    GetLastTransitionStatus PGET_D3COLD_LAST_TRANSITION_STATUS ?
  D3COLD_SUPPORT_INTERFACE ends

  PD3COLD_SUPPORT_INTERFACE typedef ptr D3COLD_SUPPORT_INTERFACE
  
  D3COLD_REQUEST_CORE_POWER_RAIL typedef proto stdcall :PVOID,:BOOLEAN
  PD3COLD_REQUEST_CORE_POWER_RAIL typedef ptr D3COLD_REQUEST_CORE_POWER_RAIL
  D3COLD_REQUEST_AUX_POWER typedef proto stdcall :PVOID,:DWORD,:PULONG
  PD3COLD_REQUEST_AUX_POWER typedef ptr D3COLD_REQUEST_AUX_POWER
  D3COLD_REQUEST_PERST_DELAY typedef proto stdcall :PVOID,:DWORD
  PD3COLD_REQUEST_PERST_DELAY typedef ptr D3COLD_REQUEST_PERST_DELAY
  D3COLD_AUX_POWER_AND_TIMING_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    RequestCorePowerRail PD3COLD_REQUEST_CORE_POWER_RAIL ?
    RequestAuxPower PD3COLD_REQUEST_AUX_POWER ?
    RequestPerstDelay PD3COLD_REQUEST_PERST_DELAY ?
  D3COLD_AUX_POWER_AND_TIMING_INTERFACE ends

  PD3COLD_AUX_POWER_AND_TIMING_INTERFACE typedef ptr D3COLD_AUX_POWER_AND_TIMING_INTERFACE
  
  FPGA_BUS_SCAN typedef proto stdcall :PVOID
  PFPGA_BUS_SCAN typedef ptr FPGA_BUS_SCAN
  FPGA_CONTROL_LINK typedef proto stdcall :PVOID,:BOOLEAN
  PFPGA_CONTROL_LINK typedef ptr FPGA_CONTROL_LINK
  FPGA_CONTROL_CONFIG_SPACE typedef proto stdcall :PVOID,:BOOLEAN
  PFPGA_CONTROL_CONFIG_SPACE typedef ptr FPGA_CONTROL_CONFIG_SPACE
  FPGA_CONTROL_ERROR_REPORTING typedef proto stdcall :PVOID,:DWORD,:DWORD,:BOOLEAN
  PFPGA_CONTROL_ERROR_REPORTING typedef ptr FPGA_CONTROL_ERROR_REPORTING
  FPGA_CONTROL_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    BusScan PFPGA_BUS_SCAN ?
    ControlLink PFPGA_CONTROL_LINK ?
    ControlConfigSpace PFPGA_CONTROL_CONFIG_SPACE ?
    ControlErrorReporting PFPGA_CONTROL_ERROR_REPORTING ?
  FPGA_CONTROL_INTERFACE ends

  PFPGA_CONTROL_INTERFACE typedef ptr FPGA_CONTROL_INTERFACE
  
  proto_PGPE_SERVICE_ROUTINE typedef proto fastcall :PVOID, :PVOID
  PGPE_SERVICE_ROUTINE typedef ptr proto_PGPE_SERVICE_ROUTINE
  proto_PGPE_CONNECT_VECTOR typedef proto fastcall :PDEVICE_OBJECT, :DWORD, :KINTERRUPT_MODE, :BOOLEAN, :PGPE_SERVICE_ROUTINE, :PVOID, :PVOID
  PGPE_CONNECT_VECTOR typedef ptr proto_PGPE_CONNECT_VECTOR
  proto_PGPE_DISCONNECT_VECTOR typedef proto fastcall :PVOID
  PGPE_DISCONNECT_VECTOR typedef ptr proto_PGPE_DISCONNECT_VECTOR
  proto_PGPE_ENABLE_EVENT typedef proto fastcall :PDEVICE_OBJECT, :PVOID
  PGPE_ENABLE_EVENT typedef ptr proto_PGPE_ENABLE_EVENT
  proto_PGPE_DISABLE_EVENT typedef proto fastcall :PDEVICE_OBJECT, :PVOID
  PGPE_DISABLE_EVENT typedef ptr proto_PGPE_DISABLE_EVENT
  proto_PGPE_CLEAR_STATUS typedef proto fastcall :PDEVICE_OBJECT, :PVOID
  PGPE_CLEAR_STATUS typedef ptr proto_PGPE_CLEAR_STATUS
  proto_PDEVICE_NOTIFY_CALLBACK typedef proto fastcall :PVOID, :DWORD
  PDEVICE_NOTIFY_CALLBACK typedef ptr proto_PDEVICE_NOTIFY_CALLBACK
  proto_PREGISTER_FOR_DEVICE_NOTIFICATIONS typedef proto fastcall :PDEVICE_OBJECT, :PDEVICE_NOTIFY_CALLBACK, :PVOID
  PREGISTER_FOR_DEVICE_NOTIFICATIONS typedef ptr proto_PREGISTER_FOR_DEVICE_NOTIFICATIONS
  proto_PUNREGISTER_FOR_DEVICE_NOTIFICATIONS typedef proto fastcall :PDEVICE_OBJECT, :PDEVICE_NOTIFY_CALLBACK
  PUNREGISTER_FOR_DEVICE_NOTIFICATIONS typedef ptr proto_PUNREGISTER_FOR_DEVICE_NOTIFICATIONS
  ACPI_INTERFACE_STANDARD struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    GpeConnectVector PGPE_CONNECT_VECTOR ?
    GpeDisconnectVector PGPE_DISCONNECT_VECTOR ?
    GpeEnableEvent PGPE_ENABLE_EVENT ?
    GpeDisableEvent PGPE_DISABLE_EVENT ?
    GpeClearStatus PGPE_CLEAR_STATUS ?
    RegisterForDeviceNotifications PREGISTER_FOR_DEVICE_NOTIFICATIONS ?
    UnregisterForDeviceNotifications PUNREGISTER_FOR_DEVICE_NOTIFICATIONS ?
  ACPI_INTERFACE_STANDARD ends

  PACPI_INTERFACE_STANDARD typedef ptr ACPI_INTERFACE_STANDARD
  
  proto_PGPE_SERVICE_ROUTINE2 typedef proto fastcall :PVOID, :PVOID
  PGPE_SERVICE_ROUTINE2 typedef ptr proto_PGPE_SERVICE_ROUTINE2
  proto_PGPE_CONNECT_VECTOR2 typedef proto fastcall :PVOID, :DWORD, :KINTERRUPT_MODE, :BOOLEAN, :PGPE_SERVICE_ROUTINE, :PVOID, :ptr PVOID
  PGPE_CONNECT_VECTOR2 typedef ptr proto_PGPE_CONNECT_VECTOR2
  proto_PGPE_DISCONNECT_VECTOR2 typedef proto fastcall :PVOID, :PVOID
  PGPE_DISCONNECT_VECTOR2 typedef ptr proto_PGPE_DISCONNECT_VECTOR2
  proto_PGPE_ENABLE_EVENT2 typedef proto fastcall :PVOID, :PVOID
  PGPE_ENABLE_EVENT2 typedef ptr proto_PGPE_ENABLE_EVENT2
  proto_PGPE_DISABLE_EVENT2 typedef proto fastcall :PVOID, :PVOID
  PGPE_DISABLE_EVENT2 typedef ptr proto_PGPE_DISABLE_EVENT2
  proto_PGPE_CLEAR_STATUS2 typedef proto fastcall :PVOID, :PVOID
  PGPE_CLEAR_STATUS2 typedef ptr proto_PGPE_CLEAR_STATUS2
  proto_PDEVICE_NOTIFY_CALLBACK2 typedef proto fastcall :PVOID, :DWORD
  PDEVICE_NOTIFY_CALLBACK2 typedef ptr proto_PDEVICE_NOTIFY_CALLBACK2
  proto_PREGISTER_FOR_DEVICE_NOTIFICATIONS2 typedef proto fastcall :PVOID, :PDEVICE_NOTIFY_CALLBACK2, :PVOID
  PREGISTER_FOR_DEVICE_NOTIFICATIONS2 typedef ptr proto_PREGISTER_FOR_DEVICE_NOTIFICATIONS2
  proto_PUNREGISTER_FOR_DEVICE_NOTIFICATIONS2 typedef proto fastcall :PVOID
  PUNREGISTER_FOR_DEVICE_NOTIFICATIONS2 typedef ptr proto_PUNREGISTER_FOR_DEVICE_NOTIFICATIONS2
  ACPI_INTERFACE_STANDARD2 struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    GpeConnectVector PGPE_CONNECT_VECTOR2 ?
    GpeDisconnectVector PGPE_DISCONNECT_VECTOR2 ?
    GpeEnableEvent PGPE_ENABLE_EVENT2 ?
    GpeDisableEvent PGPE_DISABLE_EVENT2 ?
    GpeClearStatus PGPE_CLEAR_STATUS2 ?
    RegisterForDeviceNotifications PREGISTER_FOR_DEVICE_NOTIFICATIONS2 ?
    UnregisterForDeviceNotifications PUNREGISTER_FOR_DEVICE_NOTIFICATIONS2 ?
  ACPI_INTERFACE_STANDARD2 ends

  PACPI_INTERFACE_STANDARD2 typedef ptr ACPI_INTERFACE_STANDARD2

  PLUGPLAY_REGKEY_DEVICE equ 1
  PLUGPLAY_REGKEY_DRIVER equ 2
  PLUGPLAY_REGKEY_CURRENT_HWPROFILE equ 4


  DEVICE_INTERFACE_INCLUDE_NONACTIVE equ 00000001h

  IO_NOTIFICATION_EVENT_CATEGORY typedef SDWORD
  EventCategoryReserved EQU 0
  EventCategoryHardwareProfileChange EQU 1
  EventCategoryDeviceInterfaceChange EQU 2
  EventCategoryTargetDeviceChange EQU 3
  
  PNPNOTIFY_DEVICE_INTERFACE_INCLUDE_EXISTING_INTERFACES equ 00000001h


    DRIVER_DIRECTORY_TYPE typedef SDWORD
    DriverDirectoryImage EQU 0 
    DriverDirectoryData EQU 1 
    
    PDRIVER_DIRECTORY_TYPE typedef ptr DRIVER_DIRECTORY_TYPE


    DEVICE_DIRECTORY_TYPE typedef SDWORD
    DeviceDirectoryData EQU 0 
    
    PDEVICE_DIRECTORY_TYPE typedef ptr DEVICE_DIRECTORY_TYPE

    DRIVER_REGKEY_TYPE typedef SDWORD
    DriverRegKeyParameters EQU 0 
    DriverRegKeyPersistentState EQU 1 
    
    PDRIVER_REGKEY_TYPE typedef ptr DRIVER_REGKEY_TYPE


  PLUGPLAY_NOTIFICATION_HEADER struct
    Version WORD ?
    Size_ WORD ?
    Event_ GUID <>
  PLUGPLAY_NOTIFICATION_HEADER ends

  PPLUGPLAY_NOTIFICATION_HEADER typedef ptr PLUGPLAY_NOTIFICATION_HEADER
  
  HWPROFILE_CHANGE_NOTIFICATION struct
    Version WORD ?
    Size_ WORD ?
    Event_ GUID <>
  HWPROFILE_CHANGE_NOTIFICATION ends

  PHWPROFILE_CHANGE_NOTIFICATION typedef ptr HWPROFILE_CHANGE_NOTIFICATION
  
  DEVICE_INTERFACE_CHANGE_NOTIFICATION struct
    Version WORD ?
    Size_ WORD ?
    Event_ GUID <>
    InterfaceClassGuid GUID <>
    SymbolicLinkName PUNICODE_STRING ?
  DEVICE_INTERFACE_CHANGE_NOTIFICATION ends

  PDEVICE_INTERFACE_CHANGE_NOTIFICATION typedef ptr DEVICE_INTERFACE_CHANGE_NOTIFICATION
  
  TARGET_DEVICE_REMOVAL_NOTIFICATION struct
    Version WORD ?
    Size_ WORD ?
    Event_ GUID <>
    FileObject PFILE_OBJECT ?
  TARGET_DEVICE_REMOVAL_NOTIFICATION ends

  PTARGET_DEVICE_REMOVAL_NOTIFICATION typedef ptr TARGET_DEVICE_REMOVAL_NOTIFICATION
  
  TARGET_DEVICE_CUSTOM_NOTIFICATION struct
    Version WORD ?
    Size_ WORD ?
    Event_ GUID <>
    FileObject PFILE_OBJECT ?
    NameBufferOffset SDWORD ?
    CustomDataBuffer BYTE 1 dup (?)
  TARGET_DEVICE_CUSTOM_NOTIFICATION ends

  PTARGET_DEVICE_CUSTOM_NOTIFICATION typedef ptr TARGET_DEVICE_CUSTOM_NOTIFICATION
  


    PLUGPLAY_PROPERTY_PERSISTENT equ 00000001h

  PNP_REPLACE_NO_MAP equ <MAXLONGLONG>

  PNP_REPLACE_MEMORY_LIST struct
    AllocatedCount DWORD ?
    Count DWORD ?
    TotalLength QWORD ?
    struct Ranges
      Address PHYSICAL_ADDRESS <>
      Length_ QWORD ?
    ends
  PNP_REPLACE_MEMORY_LIST ends

  PPNP_REPLACE_MEMORY_LIST typedef ptr PNP_REPLACE_MEMORY_LIST
  
  PKAFFINITY TYPEDEF PTR KAFFINITY
  
  PNP_REPLACE_PROCESSOR_LIST struct
    Affinity PKAFFINITY ?
    GroupCount DWORD ?
    AllocatedCount DWORD ?
    Count DWORD ?
    ApicIds DWORD ANYSIZE_ARRAY dup (?)
  PNP_REPLACE_PROCESSOR_LIST ends

  PPNP_REPLACE_PROCESSOR_LIST typedef ptr PNP_REPLACE_PROCESSOR_LIST
  
  PNP_REPLACE_PROCESSOR_LIST_V1 struct
    AffinityMask KAFFINITY ?
    AllocatedCount DWORD ?
    Count DWORD ?
    ApicIds DWORD ANYSIZE_ARRAY dup (?)
  PNP_REPLACE_PROCESSOR_LIST_V1 ends

  PPNP_REPLACE_PROCESSOR_LIST_V1 typedef ptr PNP_REPLACE_PROCESSOR_LIST_V1
  
  PNP_REPLACE_PARAMETERS_VERSION equ 2
  PNP_REPLACE_PARAMETERS struct
    Size_ DWORD ?
    Version DWORD ?
    Target ULONG64 ?
    Spare ULONG64 ?
    TargetProcessors PPNP_REPLACE_PROCESSOR_LIST ?
    SpareProcessors PPNP_REPLACE_PROCESSOR_LIST ?
    TargetMemory PPNP_REPLACE_MEMORY_LIST ?
    SpareMemory PPNP_REPLACE_MEMORY_LIST ?
    MapMemory QWORD ? ;PREPLACE_MAP_MEMORY ?
  PNP_REPLACE_PARAMETERS ends

  PPNP_REPLACE_PARAMETERS typedef ptr PNP_REPLACE_PARAMETERS
  
  proto_PREPLACE_UNLOAD typedef proto fastcall 
  PREPLACE_UNLOAD typedef ptr proto_PREPLACE_UNLOAD
  proto_PREPLACE_BEGIN typedef proto fastcall :PPNP_REPLACE_PARAMETERS, :ptr PVOID
  PREPLACE_BEGIN typedef ptr proto_PREPLACE_BEGIN
  proto_PREPLACE_END typedef proto fastcall :PVOID
  PREPLACE_END typedef ptr proto_PREPLACE_END
  proto_PREPLACE_MIRROR_PHYSICAL_MEMORY typedef proto fastcall :PVOID, :PHYSICAL_ADDRESS, :LARGE_INTEGER
  PREPLACE_MIRROR_PHYSICAL_MEMORY typedef ptr proto_PREPLACE_MIRROR_PHYSICAL_MEMORY
  proto_PREPLACE_SET_PROCESSOR_ID typedef proto fastcall :PVOID, :DWORD, :BOOLEAN
  PREPLACE_SET_PROCESSOR_ID typedef ptr proto_PREPLACE_SET_PROCESSOR_ID
  proto_PREPLACE_SWAP typedef proto fastcall :PVOID
  PREPLACE_SWAP typedef ptr proto_PREPLACE_SWAP
  proto_PREPLACE_INITIATE_HARDWARE_MIRROR typedef proto fastcall :PVOID
  PREPLACE_INITIATE_HARDWARE_MIRROR typedef ptr proto_PREPLACE_INITIATE_HARDWARE_MIRROR
  proto_PREPLACE_MIRROR_PLATFORM_MEMORY typedef proto fastcall :PVOID
  PREPLACE_MIRROR_PLATFORM_MEMORY typedef ptr proto_PREPLACE_MIRROR_PLATFORM_MEMORY
  proto_PREPLACE_GET_MEMORY_DESTINATION typedef proto fastcall :PVOID, :PHYSICAL_ADDRESS, :PPHYSICAL_ADDRESS
  PREPLACE_GET_MEMORY_DESTINATION typedef ptr proto_PREPLACE_GET_MEMORY_DESTINATION
  proto_PREPLACE_ENABLE_DISABLE_HARDWARE_QUIESCE typedef proto fastcall :PVOID, :BOOLEAN
  PREPLACE_ENABLE_DISABLE_HARDWARE_QUIESCE typedef ptr proto_PREPLACE_ENABLE_DISABLE_HARDWARE_QUIESCE
  PNP_REPLACE_DRIVER_INTERFACE_VERSION equ 1
  PNP_REPLACE_DRIVER_INTERFACE_MINIMUM_SIZE equ <UFIELD_OFFSET ( PNP_REPLACE_DRIVER_INTERFACE , InitiateHardwareMirror )>
  PNP_REPLACE_MEMORY_SUPPORTED equ 0001h
  PNP_REPLACE_PROCESSOR_SUPPORTED equ 0002h
  PNP_REPLACE_HARDWARE_MEMORY_MIRRORING equ 0004h
  PNP_REPLACE_HARDWARE_PAGE_COPY equ 0008h
  PNP_REPLACE_HARDWARE_QUIESCE equ 0010h
  PNP_REPLACE_DRIVER_INTERFACE struct
    Size_ DWORD ?
    Version DWORD ?
    Flags DWORD ?
    Unload PREPLACE_UNLOAD ?
    BeginReplace PREPLACE_BEGIN ?
    EndReplace PREPLACE_END ?
    MirrorPhysicalMemory PREPLACE_MIRROR_PHYSICAL_MEMORY ?
    SetProcessorId PREPLACE_SET_PROCESSOR_ID ?
    Swap PREPLACE_SWAP ?
    InitiateHardwareMirror PREPLACE_INITIATE_HARDWARE_MIRROR ?
    MirrorPlatformMemory PREPLACE_MIRROR_PLATFORM_MEMORY ?
    GetMemoryDestination PREPLACE_GET_MEMORY_DESTINATION ?
    EnableDisableHardwareQuiesce PREPLACE_ENABLE_DISABLE_HARDWARE_QUIESCE ?
  PNP_REPLACE_DRIVER_INTERFACE ends

  PPNP_REPLACE_DRIVER_INTERFACE typedef ptr PNP_REPLACE_DRIVER_INTERFACE
  

    proto_PCRASHDUMP_POWER_ON typedef proto fastcall :PVOID
    PCRASHDUMP_POWER_ON typedef ptr proto_PCRASHDUMP_POWER_ON
    CRASHDUMP_FUNCTIONS_INTERFACE struct
      Size_ WORD ?
      Version WORD ?
      Context PVOID ?
      InterfaceReference PINTERFACE_REFERENCE ?
      InterfaceDereference PINTERFACE_DEREFERENCE ?
      PowerOn PCRASHDUMP_POWER_ON ?
    CRASHDUMP_FUNCTIONS_INTERFACE ends

    PCRASHDUMP_FUNCTIONS_INTERFACE typedef ptr CRASHDUMP_FUNCTIONS_INTERFACE


    DEVICE_RESET_INTERFACE_VERSION equ 1
    DEVICE_RESET_TYPE typedef SDWORD
    FunctionLevelDeviceReset EQU 0
    PlatformLevelDeviceReset EQU 1
    
    proto_DEVICE_RESET_COMPLETION typedef proto fastcall :NTSTATUS, :PVOID
    DEVICE_RESET_COMPLETION typedef ptr proto_DEVICE_RESET_COMPLETION
    PDEVICE_RESET_COMPLETION typedef ptr DEVICE_RESET_COMPLETION
    FUNCTION_LEVEL_DEVICE_RESET_PARAMETERS struct
      Size_ DWORD ?
      DeviceResetCompletion PDEVICE_RESET_COMPLETION ?
      CompletionContext PVOID ?
    FUNCTION_LEVEL_DEVICE_RESET_PARAMETERS ends

    PFUNCTION_LEVEL_DEVICE_RESET_PARAMETERS typedef ptr FUNCTION_LEVEL_DEVICE_RESET_PARAMETERS
    
    proto_PDEVICE_RESET_HANDLER typedef proto fastcall :PVOID, :DEVICE_RESET_TYPE, :DWORD, :PVOID
    PDEVICE_RESET_HANDLER typedef ptr proto_PDEVICE_RESET_HANDLER
    DEVICE_RESET_INTERFACE_STANDARD struct
      Size_ WORD ?
      Version WORD ?
      Context PVOID ?
      InterfaceReference PINTERFACE_REFERENCE ?
      InterfaceDereference PINTERFACE_DEREFERENCE ?
      DeviceReset PDEVICE_RESET_HANDLER ?
      SupportedResetTypes DWORD ?
      Reserved PVOID ?
    DEVICE_RESET_INTERFACE_STANDARD ends

    PDEVICE_RESET_INTERFACE_STANDARD typedef ptr DEVICE_RESET_INTERFACE_STANDARD
    

    SECURE_DRIVER_INTERFACE_VERSION equ 1
    SECURE_DRIVER_PROCESS_REFERENCE typedef proto stdcall :PVOID
    PSECURE_DRIVER_PROCESS_REFERENCE typedef ptr SECURE_DRIVER_PROCESS_REFERENCE
    SECURE_DRIVER_PROCESS_DEREFERENCE typedef proto stdcall :PVOID,:PEPROCESS
    PSECURE_DRIVER_PROCESS_DEREFERENCE typedef ptr SECURE_DRIVER_PROCESS_DEREFERENCE
    SECURE_DRIVER_INTERFACE struct
      InterfaceHeader INTERFACE <>
      ProcessReference PSECURE_DRIVER_PROCESS_REFERENCE ?
      ProcessDereference PSECURE_DRIVER_PROCESS_DEREFERENCE ?
      Reserved DWORD ?
    SECURE_DRIVER_INTERFACE ends

    PSECURE_DRIVER_INTERFACE typedef ptr SECURE_DRIVER_INTERFACE
 
  SDEV_IDENTIFIER_INTERFACE_VERSION equ 1
  GET_SDEV_IDENTIFIER typedef proto stdcall :PVOID
  PGET_SDEV_IDENTIFIER typedef ptr GET_SDEV_IDENTIFIER
  SDEV_IDENTIFIER_INTERFACE struct
    InterfaceHeader INTERFACE <>
    GetIdentifier PGET_SDEV_IDENTIFIER ?
  SDEV_IDENTIFIER_INTERFACE ends

  PSDEV_IDENTIFIER_INTERFACE typedef ptr SDEV_IDENTIFIER_INTERFACE
  
  DEVICE_DESCRIPTION struct
    Version DWORD ?
    Master BOOLEAN ?
    ScatterGather BOOLEAN ?
    DemandMode BOOLEAN ?
    AutoInitialize BOOLEAN ?
    Dma32BitAddresses BOOLEAN ?
    IgnoreCount BOOLEAN ?
    Reserved1 BOOLEAN ?
    Dma64BitAddresses BOOLEAN ?
    BusNumber DWORD ?
    DmaChannel DWORD ?
    InterfaceType INTERFACE_TYPE ?
    DmaWidth DMA_WIDTH ?
    DmaSpeed DMA_SPEED ?
    MaximumLength DWORD ?
    DmaPort DWORD ?

      DmaAddressWidth DWORD ?
      DmaControllerInstance DWORD ?
      DmaRequestLine DWORD ?
      DeviceAddress PHYSICAL_ADDRESS <>

  DEVICE_DESCRIPTION ends

  PDEVICE_DESCRIPTION typedef ptr DEVICE_DESCRIPTION
  
  DEVICE_DESCRIPTION_VERSION equ 0
  DEVICE_DESCRIPTION_VERSION1 equ 1
  DEVICE_DESCRIPTION_VERSION2 equ 2
  DEVICE_DESCRIPTION_VERSION3 equ 3
  DMA_ADAPTER_INFO_VERSION1 equ 1
  DMA_TRANSFER_INFO_VERSION1 equ 1
  DMA_ADAPTER_INFO_V1 struct
    ReadDmaCounterAvailable DWORD ?
    ScatterGatherLimit DWORD ?
    DmaAddressWidth DWORD ?
    Flags DWORD ?
    MinimumTransferUnit DWORD ?
  DMA_ADAPTER_INFO_V1 ends

  PDMA_ADAPTER_INFO_V1 typedef ptr DMA_ADAPTER_INFO_V1
  
  DMA_ADAPTER_INFO struct
    Version DWORD ?
    union
      V1 DMA_ADAPTER_INFO_V1 <>
    ends
  DMA_ADAPTER_INFO ends

  PDMA_ADAPTER_INFO typedef ptr DMA_ADAPTER_INFO
  
  ADAPTER_INFO_SYNCHRONOUS_CALLBACK equ 0001h
  ADAPTER_INFO_API_BYPASS equ 0002h
  DMA_TRANSFER_INFO_V1 struct
    MapRegisterCount DWORD ?
    ScatterGatherElementCount DWORD ?
    ScatterGatherListSize DWORD ?
  DMA_TRANSFER_INFO_V1 ends

  PDMA_TRANSFER_INFO_V1 typedef ptr DMA_TRANSFER_INFO_V1
  
  DMA_TRANSFER_INFO struct
    Version DWORD ?
    union
      V1 DMA_TRANSFER_INFO_V1 <>
    ends
  DMA_TRANSFER_INFO ends

  PDMA_TRANSFER_INFO typedef ptr DMA_TRANSFER_INFO
  
  DMA_TRANSFER_CONTEXT_VERSION1 equ 1
    DMA_TRANSFER_CONTEXT_SIZE_V1 equ 128
  DMA_SYNCHRONOUS_CALLBACK equ 01h
  DMA_ZERO_BUFFERS equ 02h
  KeFlushWriteBuffer proto fastcall

    KeQueryPerformanceCounter proto fastcall :PLARGE_INTEGER


    KeStallExecutionProcessor proto fastcall :DWORD

  HAL_MASK_UNMASK_FLAGS_NONE equ 0h
  HAL_MASK_UNMASK_FLAGS_SERVICING_DEFERRED equ 1h
  HAL_MASK_UNMASK_FLAGS_SERVICING_COMPLETE equ 2h
  PROCESSOR_HALT_ROUTINE typedef proto stdcall :PVOID
  PPROCESSOR_HALT_ROUTINE typedef ptr PROCESSOR_HALT_ROUTINE
  SCATTER_GATHER_ELEMENT struct
    Address PHYSICAL_ADDRESS <>
    Length_ DWORD ?
    Reserved ULONG_PTR ?
  SCATTER_GATHER_ELEMENT ends

  PSCATTER_GATHER_ELEMENT typedef ptr SCATTER_GATHER_ELEMENT
  

    SCATTER_GATHER_LIST struct
      NumberOfElements DWORD ?
      Reserved ULONG_PTR ?
      Elements SCATTER_GATHER_ELEMENT 0 dup (<>)
    SCATTER_GATHER_LIST ends

    PSCATTER_GATHER_LIST typedef ptr SCATTER_GATHER_LIST
    

  PDMA_OPERATIONS typedef ptr _DMA_OPERATIONS
  
  HAL_DMA_ADAPTER_VERSION_1 equ 1
  DMA_ADAPTER struct
    Version WORD ?
    Size_ WORD ?
    DmaOperations PDMA_OPERATIONS ?
  DMA_ADAPTER ends

  PDMA_ADAPTER typedef ptr DMA_ADAPTER
  
  DMA_COMPLETION_STATUS typedef SDWORD
  DmaComplete EQU 0
  DmaAborted EQU 1
  DmaError EQU 2
  DmaCancelled EQU 3
  
  proto_PPUT_DMA_ADAPTER typedef proto fastcall :PDMA_ADAPTER
  PPUT_DMA_ADAPTER typedef ptr proto_PPUT_DMA_ADAPTER
  proto_PALLOCATE_COMMON_BUFFER typedef proto fastcall :PDMA_ADAPTER, :DWORD, :PPHYSICAL_ADDRESS, :BOOLEAN
  PALLOCATE_COMMON_BUFFER typedef ptr proto_PALLOCATE_COMMON_BUFFER
  proto_PFREE_COMMON_BUFFER typedef proto fastcall :PDMA_ADAPTER, :DWORD, :PHYSICAL_ADDRESS, :PVOID, :BOOLEAN
  PFREE_COMMON_BUFFER typedef ptr proto_PFREE_COMMON_BUFFER
  proto_PALLOCATE_ADAPTER_CHANNEL typedef proto fastcall :PDMA_ADAPTER, :PDEVICE_OBJECT, :DWORD, :PDRIVER_CONTROL, :PVOID
  PALLOCATE_ADAPTER_CHANNEL typedef ptr proto_PALLOCATE_ADAPTER_CHANNEL
  proto_PFLUSH_ADAPTER_BUFFERS typedef proto fastcall :PDMA_ADAPTER, :PMDL, :PVOID, :PVOID, :DWORD, :BOOLEAN
  PFLUSH_ADAPTER_BUFFERS typedef ptr proto_PFLUSH_ADAPTER_BUFFERS
  proto_PFREE_ADAPTER_CHANNEL typedef proto fastcall :PDMA_ADAPTER
  PFREE_ADAPTER_CHANNEL typedef ptr proto_PFREE_ADAPTER_CHANNEL
  proto_PFREE_ADAPTER_OBJECT typedef proto fastcall :PDMA_ADAPTER, :IO_ALLOCATION_ACTION
  PFREE_ADAPTER_OBJECT typedef ptr proto_PFREE_ADAPTER_OBJECT
  proto_PFREE_MAP_REGISTERS typedef proto fastcall :PDMA_ADAPTER, :PVOID, :DWORD
  PFREE_MAP_REGISTERS typedef ptr proto_PFREE_MAP_REGISTERS
  proto_PMAP_TRANSFER typedef proto fastcall :PDMA_ADAPTER, :PMDL, :PVOID, :PVOID, :PULONG, :BOOLEAN
  PMAP_TRANSFER typedef ptr proto_PMAP_TRANSFER
  proto_PGET_DMA_ALIGNMENT typedef proto fastcall :PDMA_ADAPTER
  PGET_DMA_ALIGNMENT typedef ptr proto_PGET_DMA_ALIGNMENT
  proto_PREAD_DMA_COUNTER typedef proto fastcall :PDMA_ADAPTER
  PREAD_DMA_COUNTER typedef ptr proto_PREAD_DMA_COUNTER
  DRIVER_LIST_CONTROL typedef proto stdcall :ptr _DEVICE_OBJECT,:ptr _IRP,:PSCATTER_GATHER_LIST,:PVOID
  PDRIVER_LIST_CONTROL typedef ptr DRIVER_LIST_CONTROL
  proto_PGET_SCATTER_GATHER_LIST typedef proto fastcall :PDMA_ADAPTER, :PDEVICE_OBJECT, :PMDL, :PVOID, :DWORD, :PDRIVER_LIST_CONTROL, :PVOID, :BOOLEAN
  PGET_SCATTER_GATHER_LIST typedef ptr proto_PGET_SCATTER_GATHER_LIST
  proto_PPUT_SCATTER_GATHER_LIST typedef proto fastcall :PDMA_ADAPTER, :PSCATTER_GATHER_LIST, :BOOLEAN
  PPUT_SCATTER_GATHER_LIST typedef ptr proto_PPUT_SCATTER_GATHER_LIST
  proto_PCALCULATE_SCATTER_GATHER_LIST_SIZE typedef proto fastcall :PDMA_ADAPTER, :PMDL, :PVOID, :DWORD, :PULONG, :PULONG
  PCALCULATE_SCATTER_GATHER_LIST_SIZE typedef ptr proto_PCALCULATE_SCATTER_GATHER_LIST_SIZE
  proto_PBUILD_SCATTER_GATHER_LIST typedef proto fastcall :PDMA_ADAPTER, :PDEVICE_OBJECT, :PMDL, :PVOID, :DWORD, :PDRIVER_LIST_CONTROL, :PVOID, :BOOLEAN, :PVOID, :DWORD
  PBUILD_SCATTER_GATHER_LIST typedef ptr proto_PBUILD_SCATTER_GATHER_LIST
  proto_PBUILD_MDL_FROM_SCATTER_GATHER_LIST typedef proto fastcall :PDMA_ADAPTER, :PSCATTER_GATHER_LIST, :PMDL, :ptr PMDL
  PBUILD_MDL_FROM_SCATTER_GATHER_LIST typedef ptr proto_PBUILD_MDL_FROM_SCATTER_GATHER_LIST
  proto_PGET_DMA_ADAPTER_INFO typedef proto fastcall :PDMA_ADAPTER, :PDMA_ADAPTER_INFO
  PGET_DMA_ADAPTER_INFO typedef ptr proto_PGET_DMA_ADAPTER_INFO
  proto_PGET_DMA_TRANSFER_INFO typedef proto fastcall :PDMA_ADAPTER, :PMDL, :QWORD, :DWORD, :BOOLEAN, :PDMA_TRANSFER_INFO
  PGET_DMA_TRANSFER_INFO typedef ptr proto_PGET_DMA_TRANSFER_INFO
  proto_PCONFIGURE_ADAPTER_CHANNEL typedef proto fastcall :PDMA_ADAPTER, :DWORD, :PVOID
  PCONFIGURE_ADAPTER_CHANNEL typedef ptr proto_PCONFIGURE_ADAPTER_CHANNEL
  proto_PINITIALIZE_DMA_TRANSFER_CONTEXT typedef proto fastcall :PDMA_ADAPTER, :PVOID
  PINITIALIZE_DMA_TRANSFER_CONTEXT typedef ptr proto_PINITIALIZE_DMA_TRANSFER_CONTEXT
  proto_PALLOCATE_COMMON_BUFFER_EX typedef proto fastcall :PDMA_ADAPTER, :PPHYSICAL_ADDRESS, :DWORD, :PPHYSICAL_ADDRESS, :BOOLEAN, :NODE_REQUIREMENT
  PALLOCATE_COMMON_BUFFER_EX typedef ptr proto_PALLOCATE_COMMON_BUFFER_EX
  proto_PALLOCATE_ADAPTER_CHANNEL_EX typedef proto fastcall :PDMA_ADAPTER, :PDEVICE_OBJECT, :PVOID, :DWORD, :DWORD, :PDRIVER_CONTROL, :PVOID, :ptr PVOID
  PALLOCATE_ADAPTER_CHANNEL_EX typedef ptr proto_PALLOCATE_ADAPTER_CHANNEL_EX
  DMA_COMPLETION_ROUTINE typedef proto stdcall :PDMA_ADAPTER,:PDEVICE_OBJECT,:PVOID,:DMA_COMPLETION_STATUS
  PDMA_COMPLETION_ROUTINE typedef ptr DMA_COMPLETION_ROUTINE
  proto_PMAP_TRANSFER_EX typedef proto fastcall :PDMA_ADAPTER, :PMDL, :PVOID, :QWORD, :DWORD, :PULONG, :BOOLEAN, :PSCATTER_GATHER_LIST, :DWORD, :PDMA_COMPLETION_ROUTINE, :PVOID
  PMAP_TRANSFER_EX typedef ptr proto_PMAP_TRANSFER_EX
  proto_PCANCEL_ADAPTER_CHANNEL typedef proto fastcall :PDMA_ADAPTER, :PDEVICE_OBJECT, :PVOID
  PCANCEL_ADAPTER_CHANNEL typedef ptr proto_PCANCEL_ADAPTER_CHANNEL
  proto_PCANCEL_MAPPED_TRANSFER typedef proto fastcall :PDMA_ADAPTER, :PVOID
  PCANCEL_MAPPED_TRANSFER typedef ptr proto_PCANCEL_MAPPED_TRANSFER
  proto_PFLUSH_ADAPTER_BUFFERS_EX typedef proto fastcall :PDMA_ADAPTER, :PMDL, :PVOID, :QWORD, :DWORD, :BOOLEAN
  PFLUSH_ADAPTER_BUFFERS_EX typedef ptr proto_PFLUSH_ADAPTER_BUFFERS_EX
  proto_PGET_SCATTER_GATHER_LIST_EX typedef proto fastcall :PDMA_ADAPTER, :PDEVICE_OBJECT, :PVOID, :PMDL, :QWORD, :DWORD, :DWORD, :PDRIVER_LIST_CONTROL, :PVOID, :BOOLEAN, :PDMA_COMPLETION_ROUTINE, :PVOID, :ptr PSCATTER_GATHER_LIST
  PGET_SCATTER_GATHER_LIST_EX typedef ptr proto_PGET_SCATTER_GATHER_LIST_EX
  proto_PBUILD_SCATTER_GATHER_LIST_EX typedef proto fastcall :PDMA_ADAPTER, :PDEVICE_OBJECT, :PVOID, :PMDL, :QWORD, :DWORD, :DWORD, :PDRIVER_LIST_CONTROL, :PVOID, :BOOLEAN, :PVOID, :DWORD, :PDMA_COMPLETION_ROUTINE, :PVOID, :PVOID
  PBUILD_SCATTER_GATHER_LIST_EX typedef ptr proto_PBUILD_SCATTER_GATHER_LIST_EX
  proto_PALLOCATE_DOMAIN_COMMON_BUFFER typedef proto fastcall :PDMA_ADAPTER, :HANDLE, :PPHYSICAL_ADDRESS, :DWORD, :DWORD, :ptr MEMORY_CACHING_TYPE, :NODE_REQUIREMENT, :PPHYSICAL_ADDRESS, :ptr PVOID
  PALLOCATE_DOMAIN_COMMON_BUFFER typedef ptr proto_PALLOCATE_DOMAIN_COMMON_BUFFER
  proto_PALLOCATE_COMMON_BUFFER_WITH_BOUNDS typedef proto fastcall :PDMA_ADAPTER, :PPHYSICAL_ADDRESS, :PPHYSICAL_ADDRESS, :DWORD, :DWORD, :ptr MEMORY_CACHING_TYPE, :NODE_REQUIREMENT, :PPHYSICAL_ADDRESS
  PALLOCATE_COMMON_BUFFER_WITH_BOUNDS typedef ptr proto_PALLOCATE_COMMON_BUFFER_WITH_BOUNDS
  DOMAIN_COMMON_BUFFER_LARGE_PAGE equ 0001h
  proto_PFLUSH_DMA_BUFFER typedef proto fastcall :PDMA_ADAPTER, :PMDL, :BOOLEAN
  PFLUSH_DMA_BUFFER typedef ptr proto_PFLUSH_DMA_BUFFER
  proto_PJOIN_DMA_DOMAIN typedef proto fastcall :PDMA_ADAPTER, :HANDLE
  PJOIN_DMA_DOMAIN typedef ptr proto_PJOIN_DMA_DOMAIN
  proto_PLEAVE_DMA_DOMAIN typedef proto fastcall :PDMA_ADAPTER
  PLEAVE_DMA_DOMAIN typedef ptr proto_PLEAVE_DMA_DOMAIN
  proto_PGET_DMA_DOMAIN typedef proto fastcall :PDMA_ADAPTER
  PGET_DMA_DOMAIN typedef ptr proto_PGET_DMA_DOMAIN
  DMA_OPERATIONS struct
    Size_ DWORD ?
    PutDmaAdapter PPUT_DMA_ADAPTER ?
    AllocateCommonBuffer PALLOCATE_COMMON_BUFFER ?
    FreeCommonBuffer PFREE_COMMON_BUFFER ?
    AllocateAdapterChannel PALLOCATE_ADAPTER_CHANNEL ?
    FlushAdapterBuffers PFLUSH_ADAPTER_BUFFERS ?
    FreeAdapterChannel PFREE_ADAPTER_CHANNEL ?
    FreeMapRegisters PFREE_MAP_REGISTERS ?
    MapTransfer PMAP_TRANSFER ?
    GetDmaAlignment PGET_DMA_ALIGNMENT ?
    ReadDmaCounter PREAD_DMA_COUNTER ?
    GetScatterGatherList PGET_SCATTER_GATHER_LIST ?
    PutScatterGatherList PPUT_SCATTER_GATHER_LIST ?
    CalculateScatterGatherList PCALCULATE_SCATTER_GATHER_LIST_SIZE ?
    BuildScatterGatherList PBUILD_SCATTER_GATHER_LIST ?
    BuildMdlFromScatterGatherList PBUILD_MDL_FROM_SCATTER_GATHER_LIST ?
    GetDmaAdapterInfo PGET_DMA_ADAPTER_INFO ?
    GetDmaTransferInfo PGET_DMA_TRANSFER_INFO ?
    InitializeDmaTransferContext PINITIALIZE_DMA_TRANSFER_CONTEXT ?
    AllocateCommonBufferEx PALLOCATE_COMMON_BUFFER_EX ?
    AllocateAdapterChannelEx PALLOCATE_ADAPTER_CHANNEL_EX ?
    ConfigureAdapterChannel PCONFIGURE_ADAPTER_CHANNEL ?
    CancelAdapterChannel PCANCEL_ADAPTER_CHANNEL ?
    MapTransferEx PMAP_TRANSFER_EX ?
    GetScatterGatherListEx PGET_SCATTER_GATHER_LIST_EX ?
    BuildScatterGatherListEx PBUILD_SCATTER_GATHER_LIST_EX ?
    FlushAdapterBuffersEx PFLUSH_ADAPTER_BUFFERS_EX ?
    FreeAdapterObject PFREE_ADAPTER_OBJECT ?
    CancelMappedTransfer PCANCEL_MAPPED_TRANSFER ?
    AllocateDomainCommonBuffer PALLOCATE_DOMAIN_COMMON_BUFFER ?
    FlushDmaBuffer PFLUSH_DMA_BUFFER ?
    JoinDmaDomain PJOIN_DMA_DOMAIN ?
    LeaveDmaDomain PLEAVE_DMA_DOMAIN ?
    GetDmaDomain PGET_DMA_DOMAIN ?
    AllocateCommonBufferWithBounds PALLOCATE_COMMON_BUFFER_WITH_BOUNDS ?
  DMA_OPERATIONS ends

    HalAllocateCommonBuffer proto fastcall :PDMA_ADAPTER, :DWORD, :PPHYSICAL_ADDRESS, :BOOLEAN
    HalFreeCommonBuffer proto fastcall :PDMA_ADAPTER, :DWORD, :PHYSICAL_ADDRESS, :PVOID, :BOOLEAN

    IoFlushAdapterBuffers proto fastcall :PDMA_ADAPTER, :PMDL, :PVOID, :PVOID, :DWORD, :BOOLEAN
    IoFreeAdapterChannel proto fastcall :PDMA_ADAPTER
    IoFreeMapRegisters proto fastcall :PDMA_ADAPTER, :PVOID, :DWORD
    IoMapTransfer proto fastcall :PDMA_ADAPTER, :PMDL, :PVOID, :PVOID, :PULONG, :BOOLEAN
    HalGetDmaAlignment proto fastcall :PDMA_ADAPTER
    HalReadDmaCounter proto fastcall :PDMA_ADAPTER

    IOMMU_ACCESS_NONE equ 00h
    IOMMU_ACCESS_READ equ 01h
    IOMMU_ACCESS_WRITE equ 02h

    PIOMMU_DMA_DOMAIN typedef ptr _IOMMU_DMA_DOMAIN
    
    DOMAIN_CONFIGURATION_ARCH typedef SDWORD
    DomainConfigurationArm64 EQU 0
    DomainConfigurationInvalid EQU 1
    
    PDOMAIN_CONFIGURATION_ARCH typedef ptr DOMAIN_CONFIGURATION_ARCH
    
    DOMAIN_CONFIGURATION_ARM64 struct
      Ttbr0 PHYSICAL_ADDRESS <>
      Ttbr1 PHYSICAL_ADDRESS <>
      Mair0 DWORD ?
      Mair1 DWORD ?
      InputSize0 BYTE ?
      InputSize1 BYTE ?
    DOMAIN_CONFIGURATION_ARM64 ends

    PDOMAIN_CONFIGURATION_ARM64 typedef ptr DOMAIN_CONFIGURATION_ARM64
    
    DOMAIN_CONFIGURATION struct
      Type_ DOMAIN_CONFIGURATION_ARCH ?
      union
        Arm64 DOMAIN_CONFIGURATION_ARM64 <>
      ends
    DOMAIN_CONFIGURATION ends

    PDOMAIN_CONFIGURATION typedef ptr DOMAIN_CONFIGURATION
    
    FAULT_INFORMATION_ARCH typedef SDWORD
    FaultInformationInvalid EQU 0
    FaultInformationArm64 EQU 1
    
    PFAULT_INFORMATION_ARCH typedef ptr FAULT_INFORMATION_ARCH
    
    FAULT_INFORMATION_ARM64 struct
      DomainHandle PVOID ?
      FaultAddress PVOID ?
      PhysicalDeviceObject PDEVICE_OBJECT ?
      InputMappingId DWORD ?
      struct Flags
        Flags_??31 record WriteNotRead_??31:1, InstructionNotData_??31:1, Privileged_??31:1, Multi_??31:1, Asynchronous_??31:1, PageTableWalkFault_??31:1, Reserved_??31:26
        Flags_??31 <>
      ends
      UnsupportedUpstreamTransaction DWORD ?
      AddressSizeFault DWORD ?
      TlbMatchConflict DWORD ?
      ExternalFault DWORD ?
      PermissionFault DWORD ?
      AccessFlagFault DWORD ?
      TranslationFault DWORD ?
    FAULT_INFORMATION_ARM64 ends

    FAULT_INFORMATION struct
      Type_ FAULT_INFORMATION_ARCH ?
      union
        Arm64 FAULT_INFORMATION_ARM64 <>
      ends
    FAULT_INFORMATION ends

    PFAULT_INFORMATION typedef ptr FAULT_INFORMATION
    
    IOMMU_DOMAIN_FAULT_HANDLER typedef proto stdcall :PVOID,:PFAULT_INFORMATION
    PIOMMU_DOMAIN_FAULT_HANDLER typedef ptr IOMMU_DOMAIN_FAULT_HANDLER
    IOMMU_DOMAIN_CREATE typedef proto stdcall :BOOLEAN,:ptr PIOMMU_DMA_DOMAIN
    PIOMMU_DOMAIN_CREATE typedef ptr IOMMU_DOMAIN_CREATE
    IOMMU_DOMAIN_DELETE typedef proto stdcall :PIOMMU_DMA_DOMAIN
    PIOMMU_DOMAIN_DELETE typedef ptr IOMMU_DOMAIN_DELETE
    IOMMU_DOMAIN_ATTACH_DEVICE typedef proto stdcall :PIOMMU_DMA_DOMAIN,:PDEVICE_OBJECT,:DWORD,:DWORD
    PIOMMU_DOMAIN_ATTACH_DEVICE typedef ptr IOMMU_DOMAIN_ATTACH_DEVICE
    IOMMU_DOMAIN_DETACH_DEVICE typedef proto stdcall :PIOMMU_DMA_DOMAIN,:PDEVICE_OBJECT,:DWORD
    PIOMMU_DOMAIN_DETACH_DEVICE typedef ptr IOMMU_DOMAIN_DETACH_DEVICE
    IOMMU_DOMAIN_CONFIGURE typedef proto stdcall :PIOMMU_DMA_DOMAIN,:PDOMAIN_CONFIGURATION
    PIOMMU_DOMAIN_CONFIGURE typedef ptr IOMMU_DOMAIN_CONFIGURE
    IOMMU_FLUSH_DOMAIN typedef proto stdcall :PIOMMU_DMA_DOMAIN
    PIOMMU_FLUSH_DOMAIN typedef ptr IOMMU_FLUSH_DOMAIN
    IOMMU_FLUSH_DOMAIN_VA_LIST typedef proto stdcall :PIOMMU_DMA_DOMAIN,:BOOLEAN,:DWORD,:PVOID
    PIOMMU_FLUSH_DOMAIN_VA_LIST typedef ptr IOMMU_FLUSH_DOMAIN_VA_LIST
    INPUT_MAPPING_ELEMENT struct
      InputMappingId DWORD ?
    INPUT_MAPPING_ELEMENT ends

    PINPUT_MAPPING_ELEMENT typedef ptr INPUT_MAPPING_ELEMENT
    
    IOMMU_QUERY_INPUT_MAPPINGS typedef proto stdcall :PDEVICE_OBJECT,:PINPUT_MAPPING_ELEMENT,:DWORD,:PULONG
    PIOMMU_QUERY_INPUT_MAPPINGS typedef ptr IOMMU_QUERY_INPUT_MAPPINGS
    IOMMU_MAP_LOGICAL_RANGE typedef proto stdcall :PIOMMU_DMA_DOMAIN,:DWORD,:PMDL,:QWORD
    PIOMMU_MAP_LOGICAL_RANGE typedef ptr IOMMU_MAP_LOGICAL_RANGE
    IOMMU_UNMAP_LOGICAL_RANGE typedef proto stdcall :PIOMMU_DMA_DOMAIN,:QWORD,:QWORD
    PIOMMU_UNMAP_LOGICAL_RANGE typedef ptr IOMMU_UNMAP_LOGICAL_RANGE
    IOMMU_MAP_IDENTITY_RANGE typedef proto stdcall :PIOMMU_DMA_DOMAIN,:DWORD,:PMDL
    PIOMMU_MAP_IDENTITY_RANGE typedef ptr IOMMU_MAP_IDENTITY_RANGE
    IOMMU_UNMAP_IDENTITY_RANGE typedef proto stdcall :PIOMMU_DMA_DOMAIN,:PMDL
    PIOMMU_UNMAP_IDENTITY_RANGE typedef ptr IOMMU_UNMAP_IDENTITY_RANGE
    DMA_IOMMU_INTERFACE_VERSION_1 equ 1
    DMA_IOMMU_INTERFACE_VERSION equ <DMA_IOMMU_INTERFACE_VERSION_1>
    DMA_IOMMU_INTERFACE struct
      Version DWORD ?
      CreateDomain PIOMMU_DOMAIN_CREATE ?
      DeleteDomain PIOMMU_DOMAIN_DELETE ?
      AttachDevice PIOMMU_DOMAIN_ATTACH_DEVICE ?
      DetachDevice PIOMMU_DOMAIN_DETACH_DEVICE ?
      ConfigureDomain PIOMMU_DOMAIN_CONFIGURE ?
      FlushDomain PIOMMU_FLUSH_DOMAIN ?
      FlushDomainByVaList PIOMMU_FLUSH_DOMAIN_VA_LIST ?
      QueryInputMappings PIOMMU_QUERY_INPUT_MAPPINGS ?
      MapLogicalRange PIOMMU_MAP_LOGICAL_RANGE ?
      UnmapLogicalRange PIOMMU_UNMAP_LOGICAL_RANGE ?
      MapIdentityRange PIOMMU_MAP_IDENTITY_RANGE ?
      UnmapIdentityRange PIOMMU_UNMAP_IDENTITY_RANGE ?
    DMA_IOMMU_INTERFACE ends

    PDMA_IOMMU_INTERFACE typedef ptr DMA_IOMMU_INTERFACE


  PO_MEM_PRESERVE equ 00000001h
  PO_MEM_CLONE equ 00000002h
  PO_MEM_CL_OR_NCHK equ 00000004h
  PO_MEM_DISCARD equ 00008000h
  PO_MEM_PAGE_ADDRESS equ 00004000h
  PO_MEM_BOOT_PHASE equ 00010000h


  REQUEST_POWER_COMPLETE typedef proto stdcall :PDEVICE_OBJECT,:BYTE,:POWER_STATE,:PVOID,:PIO_STATUS_BLOCK
  PREQUEST_POWER_COMPLETE typedef ptr REQUEST_POWER_COMPLETE


  PO_CB_SYSTEM_POWER_POLICY equ 0
  PO_CB_AC_STATUS equ 1
  PO_CB_BUTTON_COLLISION equ 2
  PO_CB_SYSTEM_STATE_LOCK equ 3
  PO_CB_LID_SWITCH_STATE equ 4
  PO_CB_PROCESSOR_POWER_POLICY equ 5
  PO_FX_VERSION_V1 equ 00000001h
  PO_FX_VERSION_V2 equ 00000002h
  PO_FX_VERSION equ <PO_FX_VERSION_V1>


  PO_FX_COMPONENT_IDLE_STATE struct
    TransitionLatency QWORD ?
    ResidencyRequirement QWORD ?
    NominalPower DWORD ?
  PO_FX_COMPONENT_IDLE_STATE ends

  PPO_FX_COMPONENT_IDLE_STATE typedef ptr PO_FX_COMPONENT_IDLE_STATE
  
  PO_FX_COMPONENT_V1 struct
    Id GUID <>
    IdleStateCount DWORD ?
    DeepestWakeableIdleState DWORD ?
    IdleStates PPO_FX_COMPONENT_IDLE_STATE ?
  PO_FX_COMPONENT_V1 ends

  PPO_FX_COMPONENT_V1 typedef ptr PO_FX_COMPONENT_V1
  
  PO_FX_DEVICE_V1 struct
    Version DWORD ?
    ComponentCount DWORD ?
    ComponentActiveConditionCallback QWORD ? ; PPO_FX_COMPONENT_ACTIVE_CONDITION_CALLBACK ?
    ComponentIdleConditionCallback QWORD ? ; PPO_FX_COMPONENT_IDLE_CONDITION_CALLBACK ?
    ComponentIdleStateCallback QWORD ? ; PPO_FX_COMPONENT_IDLE_STATE_CALLBACK ?
    DevicePowerRequiredCallback QWORD ? ; PPO_FX_DEVICE_POWER_REQUIRED_CALLBACK ?
    DevicePowerNotRequiredCallback QWORD ? ; PPO_FX_DEVICE_POWER_NOT_REQUIRED_CALLBACK ?
    PowerControlCallback QWORD ? ; PPO_FX_POWER_CONTROL_CALLBACK ?
    DeviceContext PVOID ?
    Components PO_FX_COMPONENT_V1 ANYSIZE_ARRAY dup (<>)
  PO_FX_DEVICE_V1 ends

  PPO_FX_DEVICE_V1 typedef ptr PO_FX_DEVICE_V1
  
  PO_FX_COMPONENT_FLAG_F0_ON_DX equ 0000000000000001h
  PO_FX_COMPONENT_FLAG_NO_DEBOUNCE equ 0000000000000002h
  PO_FX_COMPONENT_V2 struct
    Id GUID <>
    Flags QWORD ?
    DeepestWakeableIdleState DWORD ?
    IdleStateCount DWORD ?
    IdleStates PPO_FX_COMPONENT_IDLE_STATE ?
    ProviderCount DWORD ?
    Providers PULONG ?
  PO_FX_COMPONENT_V2 ends

  PPO_FX_COMPONENT_V2 typedef ptr PO_FX_COMPONENT_V2
  
  PO_FX_DEVICE_V2 struct
    Version DWORD ?
    Flags QWORD ?
    ComponentActiveConditionCallback QWORD ? ; PPO_FX_COMPONENT_ACTIVE_CONDITION_CALLBACK ?
    ComponentIdleConditionCallback QWORD ? ; PPO_FX_COMPONENT_IDLE_CONDITION_CALLBACK ?
    ComponentIdleStateCallback QWORD ? ; PPO_FX_COMPONENT_IDLE_STATE_CALLBACK ?
    DevicePowerRequiredCallback QWORD ? ; PPO_FX_DEVICE_POWER_REQUIRED_CALLBACK ?
    DevicePowerNotRequiredCallback QWORD ? ; PPO_FX_DEVICE_POWER_NOT_REQUIRED_CALLBACK ?
    PowerControlCallback QWORD ? ; PPO_FX_POWER_CONTROL_CALLBACK ?
    DeviceContext PVOID ?
    ComponentCount DWORD ?
    Components PO_FX_COMPONENT_V2 ANYSIZE_ARRAY dup (<>)
  PO_FX_DEVICE_V2 ends

  PPO_FX_DEVICE_V2 typedef ptr PO_FX_DEVICE_V2
  
  if (PO_FX_VERSION eq PO_FX_VERSION_V1)
    PO_FX_COMPONENT typedef PO_FX_COMPONENT_V1
    PPO_FX_COMPONENT typedef ptr PO_FX_COMPONENT_V1
    PO_FX_DEVICE typedef PO_FX_DEVICE_V1
    PPO_FX_DEVICE typedef ptr PO_FX_DEVICE_V1
  elseif (PO_FX_VERSION eq PO_FX_VERSION_V2)
    PO_FX_COMPONENT typedef PO_FX_COMPONENT_V2
    PPO_FX_COMPONENT typedef ptr PO_FX_COMPONENT_V2
    PO_FX_DEVICE typedef PO_FX_DEVICE_V2
    PPO_FX_DEVICE typedef ptr PO_FX_DEVICE_V2
  else
    .err <PO_FX_VERSION undefined !>
  endif
  PO_FX_PERF_STATE_UNIT typedef SDWORD
  PoFxPerfStateUnitOther EQU 0
  PoFxPerfStateUnitFrequency EQU 1
  PoFxPerfStateUnitBandwidth EQU 2
  PoFxPerfStateUnitMaximum EQU 3
  
  PPO_FX_PERF_STATE_UNIT typedef ptr PO_FX_PERF_STATE_UNIT
  
  PO_FX_PERF_STATE_TYPE typedef SDWORD
  PoFxPerfStateTypeDiscrete EQU 0
  PoFxPerfStateTypeRange EQU 1
  PoFxPerfStateTypeMaximum EQU 2
  
  PPO_FX_PERF_STATE_TYPE typedef ptr PO_FX_PERF_STATE_TYPE
  
  PO_FX_PERF_STATE struct
    Value QWORD ?
    Context PVOID ?
  PO_FX_PERF_STATE ends

  PPO_FX_PERF_STATE typedef ptr PO_FX_PERF_STATE
  
  PO_FX_COMPONENT_PERF_SET struct
    Name_ UNICODE_STRING <>
    Flags QWORD ?
    Unit PO_FX_PERF_STATE_UNIT ?
    Type_ PO_FX_PERF_STATE_TYPE ?
    union
      struct Discrete
        Count DWORD ?
        States PPO_FX_PERF_STATE ?
      ends
      struct Range
        Minimum QWORD ?
        Maximum QWORD ?
      ends
    ends
  PO_FX_COMPONENT_PERF_SET ends

  PPO_FX_COMPONENT_PERF_SET typedef ptr PO_FX_COMPONENT_PERF_SET
  
  PO_FX_COMPONENT_PERF_INFO struct
    PerfStateSetsCount DWORD ?
    PerfStateSets PO_FX_COMPONENT_PERF_SET ANYSIZE_ARRAY dup (<>)
  PO_FX_COMPONENT_PERF_INFO ends

  PPO_FX_COMPONENT_PERF_INFO typedef ptr PO_FX_COMPONENT_PERF_INFO
  
  PO_FX_PERF_STATE_CHANGE struct
    Set DWORD ?
    union
      StateIndex DWORD ?
      StateValue QWORD ?
    ends
  PO_FX_PERF_STATE_CHANGE ends

  PPO_FX_PERF_STATE_CHANGE typedef ptr PO_FX_PERF_STATE_CHANGE
  
  PO_FX_UNKNOWN_POWER equ 0FFFFFFFFh
  PO_FX_UNKNOWN_TIME equ 0FFFFFFFFFFFFFFFFh
  PO_FX_FLAG_BLOCKING equ 01h
  PO_FX_FLAG_ASYNC_ONLY equ 02h
  PO_FX_FLAG_PERF_PEP_OPTIONAL equ 01h
  PO_FX_FLAG_PERF_QUERY_ON_F0 equ 02h
  PO_FX_FLAG_PERF_QUERY_ON_ALL_IDLE_STATES equ 04h



  PO_THERMAL_REQUEST_TYPE typedef SDWORD
  PoThermalRequestPassive EQU 0
  PoThermalRequestActive EQU 1
  
  PPO_THERMAL_REQUEST_TYPE typedef ptr PO_THERMAL_REQUEST_TYPE

  OBJECT_HANDLE_INFORMATION struct
    HandleAttributes DWORD ?
    GrantedAccess ACCESS_MASK ?
  OBJECT_HANDLE_INFORMATION ends

  POBJECT_HANDLE_INFORMATION typedef ptr OBJECT_HANDLE_INFORMATION


  OB_FLT_REGISTRATION_VERSION_0100 equ 0100h
  OB_FLT_REGISTRATION_VERSION equ <OB_FLT_REGISTRATION_VERSION_0100>
  OB_OPERATION typedef DWORD
  OB_OPERATION_HANDLE_CREATE equ 00000001h
  OB_OPERATION_HANDLE_DUPLICATE equ 00000002h
  OB_PRE_CREATE_HANDLE_INFORMATION struct
    DesiredAccess ACCESS_MASK ?
    OriginalDesiredAccess ACCESS_MASK ?
  OB_PRE_CREATE_HANDLE_INFORMATION ends

  POB_PRE_CREATE_HANDLE_INFORMATION typedef ptr OB_PRE_CREATE_HANDLE_INFORMATION
  
  OB_PRE_DUPLICATE_HANDLE_INFORMATION struct
    DesiredAccess ACCESS_MASK ?
    OriginalDesiredAccess ACCESS_MASK ?
    SourceProcess PVOID ?
    TargetProcess PVOID ?
  OB_PRE_DUPLICATE_HANDLE_INFORMATION ends

  POB_PRE_DUPLICATE_HANDLE_INFORMATION typedef ptr OB_PRE_DUPLICATE_HANDLE_INFORMATION
  
  OB_PRE_OPERATION_PARAMETERS union
    CreateHandleInformation OB_PRE_CREATE_HANDLE_INFORMATION <>
    DuplicateHandleInformation OB_PRE_DUPLICATE_HANDLE_INFORMATION <>
  OB_PRE_OPERATION_PARAMETERS ends

  POB_PRE_OPERATION_PARAMETERS typedef ptr OB_PRE_OPERATION_PARAMETERS
  
  OB_PRE_OPERATION_INFORMATION struct
    Operation OB_OPERATION ?
    union
      Flags DWORD ?
      struct
        OB_PRE_OPERATION_INFORMATION_??32 record KernelHandle_??32:1, Reserved_??32:31
        OB_PRE_OPERATION_INFORMATION_??32 <>
      ends
    ends
    Object_ PVOID ?
    ObjectType POBJECT_TYPE ?
    CallContext PVOID ?
    Parameters POB_PRE_OPERATION_PARAMETERS ?
  OB_PRE_OPERATION_INFORMATION ends

  POB_PRE_OPERATION_INFORMATION typedef ptr OB_PRE_OPERATION_INFORMATION
  
  OB_POST_CREATE_HANDLE_INFORMATION struct
    GrantedAccess ACCESS_MASK ?
  OB_POST_CREATE_HANDLE_INFORMATION ends

  POB_POST_CREATE_HANDLE_INFORMATION typedef ptr OB_POST_CREATE_HANDLE_INFORMATION
  
  OB_POST_DUPLICATE_HANDLE_INFORMATION struct
    GrantedAccess ACCESS_MASK ?
  OB_POST_DUPLICATE_HANDLE_INFORMATION ends

  POB_POST_DUPLICATE_HANDLE_INFORMATION typedef ptr OB_POST_DUPLICATE_HANDLE_INFORMATION
  
  OB_POST_OPERATION_PARAMETERS union
    CreateHandleInformation OB_POST_CREATE_HANDLE_INFORMATION <>
    DuplicateHandleInformation OB_POST_DUPLICATE_HANDLE_INFORMATION <>
  OB_POST_OPERATION_PARAMETERS ends

  POB_POST_OPERATION_PARAMETERS typedef ptr OB_POST_OPERATION_PARAMETERS
  
  OB_POST_OPERATION_INFORMATION struct
    Operation OB_OPERATION ?
    union
      Flags DWORD ?
      struct
        OB_POST_OPERATION_INFORMATION_??33 record KernelHandle_??33:1, Reserved_??33:31
        OB_POST_OPERATION_INFORMATION_??33 <>
      ends
    ends
    Object_ PVOID ?
    ObjectType POBJECT_TYPE ?
    CallContext PVOID ?
    ReturnStatus NTSTATUS ?
    Parameters POB_POST_OPERATION_PARAMETERS ?
  OB_POST_OPERATION_INFORMATION ends

  POB_POST_OPERATION_INFORMATION typedef ptr OB_POST_OPERATION_INFORMATION
  
  OB_PREOP_CALLBACK_STATUS typedef SDWORD
  OB_PREOP_SUCCESS EQU 0
  
  POB_PREOP_CALLBACK_STATUS typedef ptr OB_PREOP_CALLBACK_STATUS
  
  proto_POB_PRE_OPERATION_CALLBACK typedef proto fastcall :PVOID, :POB_PRE_OPERATION_INFORMATION
  POB_PRE_OPERATION_CALLBACK typedef ptr proto_POB_PRE_OPERATION_CALLBACK
  proto_POB_POST_OPERATION_CALLBACK typedef proto fastcall :PVOID, :POB_POST_OPERATION_INFORMATION
  POB_POST_OPERATION_CALLBACK typedef ptr proto_POB_POST_OPERATION_CALLBACK
  OB_OPERATION_REGISTRATION struct
    ObjectType POINTER ?
    Operations OB_OPERATION ?
    PreOperation POB_PRE_OPERATION_CALLBACK ?
    PostOperation POB_POST_OPERATION_CALLBACK ?
  OB_OPERATION_REGISTRATION ends

  POB_OPERATION_REGISTRATION typedef ptr OB_OPERATION_REGISTRATION
  
  OB_CALLBACK_REGISTRATION struct
    Version WORD ?
    OperationRegistrationCount WORD ?
    Altitude UNICODE_STRING <>
    RegistrationContext PVOID ?
    OperationRegistration POINTER ?
  OB_CALLBACK_REGISTRATION ends

  POB_CALLBACK_REGISTRATION typedef ptr OB_CALLBACK_REGISTRATION
  

    ObRegisterCallbacks proto fastcall :POB_CALLBACK_REGISTRATION, :ptr PVOID
    ObUnRegisterCallbacks proto fastcall :PVOID
    ObGetFilterVersion proto fastcall

  ifndef _PCI_X_
    _PCI_X_ equ <>
    PCI_SLOT_NUMBER struct
      union u
        struct bits
          bits_??34 record DeviceNumber_??34:5, FunctionNumber_??34:3, Reserved_??34:24
          bits_??34 <>
        ends
        AsULONG DWORD ?
      ends
    PCI_SLOT_NUMBER ends

    PPCI_SLOT_NUMBER typedef ptr PCI_SLOT_NUMBER
    
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
    PPCI_COMMON_CONFIG typedef ptr PCI_COMMON_CONFIG

    PCI_COMMON_HDR_LENGTH equ <( UFIELD_OFFSET ( PCI_COMMON_CONFIG , DeviceSpecific ) )>
    PCI_EXTENDED_CONFIG_LENGTH equ 1000h
    PCI_MAX_DEVICES equ 32
    PCI_MAX_FUNCTION equ 8
    PCI_MAX_BRIDGE_NUMBER equ 0FFh
    PCI_INVALID_VENDORID equ 0FFFFh
    PCI_MULTIFUNCTION equ 80h
    PCI_DEVICE_TYPE equ 00h
    PCI_BRIDGE_TYPE equ 01h
    PCI_CARDBUS_BRIDGE_TYPE equ 02h
    PCI_CONFIGURATION_TYPE macro PciData
     exitm <( ( ( PPCI_COMMON_CONFIG ) ( PciData ) ) - HeaderType and not PCI_MULTIFUNCTION ) >
    endm
    PCI_MULTIFUNCTION_DEVICE macro PciData
     exitm <( ( ( ( PPCI_COMMON_CONFIG ) ( PciData ) ) - HeaderType and PCI_MULTIFUNCTION ) != 0 ) >
    endm
    PCI_ENABLE_IO_SPACE equ 0001h
    PCI_ENABLE_MEMORY_SPACE equ 0002h
    PCI_ENABLE_BUS_MASTER equ 0004h
    PCI_ENABLE_SPECIAL_CYCLES equ 0008h
    PCI_ENABLE_WRITE_AND_INVALIDATE equ 0010h
    PCI_ENABLE_VGA_COMPATIBLE_PALETTE equ 0020h
    PCI_ENABLE_PARITY equ 0040h
    PCI_ENABLE_WAIT_CYCLE equ 0080h
    PCI_ENABLE_SERR equ 0100h
    PCI_ENABLE_FAST_BACK_TO_BACK equ 0200h
    PCI_DISABLE_LEVEL_INTERRUPT equ 0400h
    PCI_STATUS_INTERRUPT_PENDING equ 0008h
    PCI_STATUS_CAPABILITIES_LIST equ 0010h
    PCI_STATUS_66MHZ_CAPABLE equ 0020h
    PCI_STATUS_UDF_SUPPORTED equ 0040h
    PCI_STATUS_FAST_BACK_TO_BACK equ 0080h
    PCI_STATUS_DATA_PARITY_DETECTED equ 0100h
    PCI_STATUS_DEVSEL equ 0600h
    PCI_STATUS_SIGNALED_TARGET_ABORT equ 0800h
    PCI_STATUS_RECEIVED_TARGET_ABORT equ 1000h
    PCI_STATUS_RECEIVED_MASTER_ABORT equ 2000h
    PCI_STATUS_SIGNALED_SYSTEM_ERROR equ 4000h
    PCI_STATUS_DETECTED_PARITY_ERROR equ 8000h
    PCI_WHICHSPACE_CONFIG equ 0h
    PCI_WHICHSPACE_ROM equ 52696350h
    PCI_CAPABILITY_ID_POWER_MANAGEMENT equ 01h
    PCI_CAPABILITY_ID_AGP equ 02h
    PCI_CAPABILITY_ID_VPD equ 03h
    PCI_CAPABILITY_ID_SLOT_ID equ 04h
    PCI_CAPABILITY_ID_MSI equ 05h
    PCI_CAPABILITY_ID_CPCI_HOTSWAP equ 06h
    PCI_CAPABILITY_ID_PCIX equ 07h
    PCI_CAPABILITY_ID_HYPERTRANSPORT equ 08h
    PCI_CAPABILITY_ID_VENDOR_SPECIFIC equ 09h
    PCI_CAPABILITY_ID_DEBUG_PORT equ 0Ah
    PCI_CAPABILITY_ID_CPCI_RES_CTRL equ 0Bh
    PCI_CAPABILITY_ID_SHPC equ 0Ch
    PCI_CAPABILITY_ID_P2P_SSID equ 0Dh
    PCI_CAPABILITY_ID_AGP_TARGET equ 0Eh
    PCI_CAPABILITY_ID_SECURE equ 0Fh
    PCI_CAPABILITY_ID_PCI_EXPRESS equ 10h
    PCI_CAPABILITY_ID_MSIX equ 11h
    PCI_CAPABILITY_ID_SATA_CONFIG equ 12h
    PCI_CAPABILITY_ID_ADVANCED_FEATURES equ 13h
    PCI_CAPABILITIES_HEADER struct
      CapabilityID BYTE ?
      Next BYTE ?
    PCI_CAPABILITIES_HEADER ends

    PPCI_CAPABILITIES_HEADER typedef ptr PCI_CAPABILITIES_HEADER
    
    PCI_PMC STRUCT
        Rsvd1 UCHAR ?
        struct PM_SUPPORT
            Rsvd2   UCHAR  ?
        ends
    PCI_PMC ENDS

    PPCI_PMC typedef ptr PCI_PMC
    
    PCI_PMCSR struct
      PCI_PMCSR_??36 record PowerState_??36:2, Rsvd1_??36:1, NoSoftReset_??36:1, Rsvd2_??36:4, PMEEnable_??36:1, DataSelect_??36:4, DataScale_??36:2, PMEStatus_??36:1
      PCI_PMCSR_??36 <>
    PCI_PMCSR ends

    PPCI_PMCSR typedef ptr PCI_PMCSR
    
    PCI_PMCSR_BSE struct
      PCI_PMCSR_BSE_??37 record Rsvd1_??37:6, D3HotSupportsStopClock_??37:1, BusPowerClockControlEnabled_??37:1
      PCI_PMCSR_BSE_??37 <>
    PCI_PMCSR_BSE ends

    PPCI_PMCSR_BSE typedef ptr PCI_PMCSR_BSE
    
    PCI_PM_CAPABILITY struct
      Header PCI_CAPABILITIES_HEADER <>
      union PMC
        Capabilities PCI_PMC <>
        AsUSHORT WORD ?
      ends
      union PMCSR
        ControlStatus PCI_PMCSR <>
        AsUSHORT WORD ?
      ends
      union PMCSR_BSE
        BridgeSupport PCI_PMCSR_BSE <>
        AsUCHAR BYTE ?
      ends
      Data BYTE ?
    PCI_PM_CAPABILITY ends

    PPCI_PM_CAPABILITY typedef ptr PCI_PM_CAPABILITY
    
    PCI_X_CAPABILITY struct
      Header PCI_CAPABILITIES_HEADER <>
      union Command
        struct bits
          bits_??38 record DataParityErrorRecoveryEnable_??38:1, EnableRelaxedOrdering_??38:1, MaxMemoryReadByteCount_??38:2, MaxOutstandingSplitTransactions_??38:3, Reserved_??138:9
          bits_??38 <>
        ends
        AsUSHORT WORD ?
      ends
      union Status
        struct bits
          bits_??39 record FunctionNumber_??39:3, DeviceNumber_??39:5, BusNumber_??39:8, Device64Bit_??39:1, Capable133MHz_??39:1, SplitCompletionDiscarded_??39:1, UnexpectedSplitCompletion_??39:1, DeviceComplexity_??39:1, DesignedMaxMemoryReadByteCount_??39:2, DesignedMaxOutstandingSplitTransactions_??39:3, DesignedMaxCumulativeReadSize_??39:3, ReceivedSplitCompletionErrorMessage_??39:1, CapablePCIX266_??39:1, CapablePCIX533_??39:1
          bits_??39 <>
        ends
        AsULONG DWORD ?
      ends
    PCI_X_CAPABILITY ends

    PPCI_X_CAPABILITY typedef ptr PCI_X_CAPABILITY
    
    PCI_EXPRESS_ADVANCED_ERROR_REPORTING_CAP_ID equ 0001h
    PCI_EXPRESS_VIRTUAL_CHANNEL_CAP_ID equ 0002h
    PCI_EXPRESS_DEVICE_SERIAL_NUMBER_CAP_ID equ 0003h
    PCI_EXPRESS_POWER_BUDGETING_CAP_ID equ 0004h
    PCI_EXPRESS_RC_LINK_DECLARATION_CAP_ID equ 0005h
    PCI_EXPRESS_RC_INTERNAL_LINK_CONTROL_CAP_ID equ 0006h
    PCI_EXPRESS_RC_EVENT_COLLECTOR_ENDPOINT_ASSOCIATION_CAP_ID equ 0007h
    PCI_EXPRESS_MFVC_CAP_ID equ 0008h
    PCI_EXPRESS_VC_AND_MFVC_CAP_ID equ 0009h
    PCI_EXPRESS_RCRB_HEADER_CAP_ID equ 000Ah
    PCI_EXPRESS_VENDOR_SPECIFIC_CAP_ID equ 000Bh
    PCI_EXPRESS_CONFIGURATION_ACCESS_CORRELATION_CAP_ID equ 000Ch
    PCI_EXPRESS_ACCESS_CONTROL_SERVICES_CAP_ID equ 000Dh
    PCI_EXPRESS_ARI_CAP_ID equ 000Eh
    PCI_EXPRESS_ATS_CAP_ID equ 000Fh
    PCI_EXPRESS_SINGLE_ROOT_IO_VIRTUALIZATION_CAP_ID equ 0010h
    PCI_EXPRESS_MULTI_ROOT_IO_VIRTUALIZATION_CAP_ID equ 0011h
    PCI_EXPRESS_MULTICAST_CAP_ID equ 0012h
    PCI_EXPRESS_PAGE_REQUEST_CAP_ID equ 0013h
    PCI_EXPRESS_RESERVED_FOR_AMD_CAP_ID equ 0014h
    PCI_EXPRESS_RESIZABLE_BAR_CAP_ID equ 0015h
    PCI_EXPRESS_DPA_CAP_ID equ 0016h
    PCI_EXPRESS_TPH_REQUESTER_CAP_ID equ 0017h
    PCI_EXPRESS_LTR_CAP_ID equ 0018h
    PCI_EXPRESS_SECONDARY_PCI_EXPRESS_CAP_ID equ 0019h
    PCI_EXPRESS_PMUX_CAP_ID equ 001Ah
    PCI_EXPRESS_PASID_CAP_ID equ 001Bh
    PCI_EXPRESS_LN_REQUESTER_CAP_ID equ 001Ch
    PCI_EXPRESS_DPC_CAP_ID equ 001Dh
    PCI_EXPRESS_L1_PM_SS_CAP_ID equ 001Eh
    PCI_EXPRESS_PTM_CAP_ID equ 001Fh
    PCI_EXPRESS_MPCIE_CAP_ID equ 0020h
    PCI_EXPRESS_FRS_QUEUEING_CAP_ID equ 0021h
    PCI_EXPRESS_READINESS_TIME_REPORTING_CAP_ID equ 0022h
    PCI_EXPRESS_DESIGNATED_VENDOR_SPECIFIC_CAP_ID equ 0023h
    
    pcixechdr RECORD Version:4, Next:12
    PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER struct
      CapabilityID WORD ?
      struct
      pcixechdr <>
      ends
    PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER ends

    PPCI_EXPRESS_ENHANCED_CAPABILITY_HEADER typedef ptr PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER
    
    PCI_EXPRESS_VENDOR_SPECIFIC_CAPABILITY struct
      Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
      VsecId WORD ?
      PCI_EXPRESS_VENDOR_SPECIFIC_CAPABILITY_??41 record VsecRev_??41:4, VsecLength_??41:12
      PCI_EXPRESS_VENDOR_SPECIFIC_CAPABILITY_??41 <>
    PCI_EXPRESS_VENDOR_SPECIFIC_CAPABILITY ends

    PPCI_EXPRESS_VENDOR_SPECIFIC_CAPABILITY typedef ptr PCI_EXPRESS_VENDOR_SPECIFIC_CAPABILITY
    
    PCI_EXPRESS_SERIAL_NUMBER_CAPABILITY struct
      Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
      LowSerialNumber DWORD ?
      HighSerialNumber DWORD ?
    PCI_EXPRESS_SERIAL_NUMBER_CAPABILITY ends

    PPCI_EXPRESS_SERIAL_NUMBER_CAPABILITY typedef ptr PCI_EXPRESS_SERIAL_NUMBER_CAPABILITY
    
    PCI_EXPRESS_ARI_CAPABILITY_REGISTER struct
      PCI_EXPRESS_ARI_CAPABILITY_REGISTER_??42 record MfvcFunctionGroupsCapability_??42:1, AcsFunctionGroupsCapability_??42:1, Reserved_??42:6, NextFunctionNumber_??42:8
      PCI_EXPRESS_ARI_CAPABILITY_REGISTER_??42 <>
    PCI_EXPRESS_ARI_CAPABILITY_REGISTER ends

    PPCI_EXPRESS_ARI_CAPABILITY_REGISTER typedef ptr PCI_EXPRESS_ARI_CAPABILITY_REGISTER
    
    PCI_EXPRESS_ARI_CONTROL_REGISTER struct
      PCI_EXPRESS_ARI_CONTROL_REGISTER_??43 record MfvcFunctionGroupsEnable_??43:1, AcsFunctionGroupsEnable_??43:1, Reserved1_??43:2, FunctionGroup_??43:3, Reserved2_??43:9
      PCI_EXPRESS_ARI_CONTROL_REGISTER_??43 <>
    PCI_EXPRESS_ARI_CONTROL_REGISTER ends

    PPCI_EXPRESS_ARI_CONTROL_REGISTER typedef ptr PCI_EXPRESS_ARI_CONTROL_REGISTER
    
    PCI_EXPRESS_ARI_CAPABILITY struct
      Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
      Capability PCI_EXPRESS_ARI_CAPABILITY_REGISTER <>
      Control PCI_EXPRESS_ARI_CONTROL_REGISTER <>
    PCI_EXPRESS_ARI_CAPABILITY ends

    PPCI_EXPRESS_ARI_CAPABILITY typedef ptr PCI_EXPRESS_ARI_CAPABILITY
    
    VIRTUAL_CHANNEL_CAPABILITIES1 union
      struct
        VIRTUAL_CHANNEL_CAPABILITIES1_??44 record ExtendedVCCount_??44:3, RsvdP1_??44:1, LowPriorityExtendedVCCount_??44:3, RsvdP2_??44:1, ReferenceClock_??44:2, PortArbitrationTableEntrySize_??44:2, RsvdP3_??44:20
        VIRTUAL_CHANNEL_CAPABILITIES1_??44 <>
      ends
      AsULONG DWORD ?
    VIRTUAL_CHANNEL_CAPABILITIES1 ends

    PVIRTUAL_CHANNEL_CAPABILITIES1 typedef ptr VIRTUAL_CHANNEL_CAPABILITIES1
    
    VIRTUAL_CHANNEL_CAPABILITIES2 union
      struct
        VIRTUAL_CHANNEL_CAPABILITIES2_??45 record VCArbitrationCapability_??45:8, RsvdP_??45:16, VCArbitrationTableOffset_??45:8
        VIRTUAL_CHANNEL_CAPABILITIES2_??45 <>
      ends
      AsULONG DWORD ?
    VIRTUAL_CHANNEL_CAPABILITIES2 ends

    PVIRTUAL_CHANNEL_CAPABILITIES2 typedef ptr VIRTUAL_CHANNEL_CAPABILITIES2
    
    VIRTUAL_CHANNEL_CONTROL union
      struct
        VIRTUAL_CHANNEL_CONTROL_??46 record LoadVCArbitrationTable_??46:1, VCArbitrationSelect_??46:3, RsvdP_??46:12
        VIRTUAL_CHANNEL_CONTROL_??46 <>
      ends
      AsUSHORT WORD ?
    VIRTUAL_CHANNEL_CONTROL ends

    PVIRTUAL_CHANNEL_CONTROL typedef ptr VIRTUAL_CHANNEL_CONTROL
    
    VIRTUAL_CHANNEL_STATUS union
      struct
        VIRTUAL_CHANNEL_STATUS_??47 record VCArbitrationTableStatus_??47:1, RsvdZ_??47:15
        VIRTUAL_CHANNEL_STATUS_??47 <>
      ends
      AsUSHORT WORD ?
    VIRTUAL_CHANNEL_STATUS ends

    PVIRTUAL_CHANNEL_STATUS typedef ptr VIRTUAL_CHANNEL_STATUS
    
    VIRTUAL_RESOURCE_CAPABILITY union
      struct
        VIRTUAL_RESOURCE_CAPABILITY_??48 record PortArbitrationCapability_??48:8, RsvdP1_??48:6, Undefined_??148:1, RejectSnoopTransactions_??48:1, MaximumTimeSlots_??48:7, RsvdP2_??48:1, PortArbitrationTableOffset_??48:8
        VIRTUAL_RESOURCE_CAPABILITY_??48 <>
      ends
      AsULONG DWORD ?
    VIRTUAL_RESOURCE_CAPABILITY ends

    PVIRTUAL_RESOURCE_CAPABILITY typedef ptr VIRTUAL_RESOURCE_CAPABILITY
    
    VIRTUAL_RESOURCE_CONTROL union
      struct
        VIRTUAL_RESOURCE_CONTROL_??49 record TcVcMap_??49:8, RsvdP1_??49:8, LoadPortArbitrationTable_??49:1, PortArbitrationSelect_??49:3, RsvdP2_??49:4, VcID_??49:3, RsvdP3_??49:4, VcEnable_??49:1
        VIRTUAL_RESOURCE_CONTROL_??49 <>
      ends
      AsULONG DWORD ?
    VIRTUAL_RESOURCE_CONTROL ends

    PVIRTUAL_RESOURCE_CONTROL typedef ptr VIRTUAL_RESOURCE_CONTROL
    
    VIRTUAL_RESOURCE_STATUS union
      struct
        VIRTUAL_RESOURCE_STATUS_??50 record PortArbitrationTableStatus_??50:1, VcNegotiationPending_??50:1, RsvdZ_??50:14
        VIRTUAL_RESOURCE_STATUS_??50 <>
      ends
      AsUSHORT WORD ?
    VIRTUAL_RESOURCE_STATUS ends

    PVIRTUAL_RESOURCE_STATUS typedef ptr VIRTUAL_RESOURCE_STATUS
    
    VIRTUAL_RESOURCE struct
      Capability VIRTUAL_RESOURCE_CAPABILITY <>
      Control VIRTUAL_RESOURCE_CONTROL <>
      RsvdP WORD ?
      Status VIRTUAL_RESOURCE_STATUS <>
    VIRTUAL_RESOURCE ends

    PVIRTUAL_RESOURCE typedef ptr VIRTUAL_RESOURCE
    
    PCI_EXPRESS_VIRTUAL_CHANNEL_CAPABILITY struct
      Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
      Capabilities1 VIRTUAL_CHANNEL_CAPABILITIES1 <>
      Capabilities2 VIRTUAL_CHANNEL_CAPABILITIES2 <>
      Control VIRTUAL_CHANNEL_CONTROL <>
      Status VIRTUAL_CHANNEL_STATUS <>
      Resource VIRTUAL_RESOURCE 8 dup (<>)
    PCI_EXPRESS_VIRTUAL_CHANNEL_CAPABILITY ends

    PPCI_EXPRESS_VIRTUAL_CHANNEL_CAPABILITY typedef ptr PCI_EXPRESS_VIRTUAL_CHANNEL_CAPABILITY
    
    PCI_EXPRESS_ATS_CAPABILITY_REGISTER struct
      PCI_EXPRESS_ATS_CAPABILITY_REGISTER_??51 record InvalidateQueueDepth_??51:5, PageAlignedRequest_??51:1, GlobalInvalidateSupported_??51:1, Reserved_??51:9
      PCI_EXPRESS_ATS_CAPABILITY_REGISTER_??51 <>
    PCI_EXPRESS_ATS_CAPABILITY_REGISTER ends

    PPCI_EXPRESS_ATS_CAPABILITY_REGISTER typedef ptr PCI_EXPRESS_ATS_CAPABILITY_REGISTER
    
    PCI_EXPRESS_ATS_CONTROL_REGISTER struct
      PCI_EXPRESS_ATS_CONTROL_REGISTER_??52 record SmallestTransactionUnit_??52:5, Reserved_??52:10, Enable_??52:1
      PCI_EXPRESS_ATS_CONTROL_REGISTER_??52 <>
    PCI_EXPRESS_ATS_CONTROL_REGISTER ends

    PPCI_EXPRESS_ATS_CONTROL_REGISTER typedef ptr PCI_EXPRESS_ATS_CONTROL_REGISTER
    
    PCI_EXPRESS_ATS_CAPABILITY struct
      Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
      Capability PCI_EXPRESS_ATS_CAPABILITY_REGISTER <>
      Control PCI_EXPRESS_ATS_CONTROL_REGISTER <>
    PCI_EXPRESS_ATS_CAPABILITY ends

    PPCI_EXPRESS_ATS_CAPABILITY typedef ptr PCI_EXPRESS_ATS_CAPABILITY
    
    PCI_EXPRESS_PASID_CAPABILITY_REGISTER union
      struct DUMMYSTRUCTNAME_28
        DUMMYSTRUCTNAME_28_??53 record Rsvd_??153:1, ExecutePermissionSupported_??53:1, PrivilegedModeSupported_??53:1, Rsvd2_??53:5, MaxPASIDWidth_??53:5, Rsvd3_??53:3
        DUMMYSTRUCTNAME_28_??53 <>
      ends
      AsUSHORT WORD ?
    PCI_EXPRESS_PASID_CAPABILITY_REGISTER ends

    PPCI_EXPRESS_PASID_CAPABILITY_REGISTER typedef ptr PCI_EXPRESS_PASID_CAPABILITY_REGISTER
    
    PCI_EXPRESS_PASID_CONTROL_REGISTER union
      struct DUMMYSTRUCTNAME_29
        DUMMYSTRUCTNAME_29_??54 record PASIDEnable_??54:1, ExecutePermissionEnable_??54:1, PrivilegedModeEnable_??54:1, Rsvd_??154:13
        DUMMYSTRUCTNAME_29_??54 <>
      ends
      AsUSHORT WORD ?
    PCI_EXPRESS_PASID_CONTROL_REGISTER ends

    PPCI_EXPRESS_PASID_CONTROL_REGISTER typedef ptr PCI_EXPRESS_PASID_CONTROL_REGISTER
    
    PCI_EXPRESS_PASID_CAPABILITY struct
      Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
      Capability PCI_EXPRESS_PASID_CAPABILITY_REGISTER <>
      Control PCI_EXPRESS_PASID_CONTROL_REGISTER <>
    PCI_EXPRESS_PASID_CAPABILITY ends

    PPCI_EXPRESS_PASID_CAPABILITY typedef ptr PCI_EXPRESS_PASID_CAPABILITY
    
    PCI_EXPRESS_PRI_STATUS_REGISTER union
      struct DUMMYSTRUCTNAME_30
        DUMMYSTRUCTNAME_30_??55 record ResponseFailure_??55:1, UnexpectedPageRequestGroupIndex_??55:1, Rsvd_??155:6, Stopped_??55:1, Rsvd2_??255:6, PrgResponsePasidRequired_??55:1
        DUMMYSTRUCTNAME_30_??55 <>
      ends
      AsUSHORT WORD ?
    PCI_EXPRESS_PRI_STATUS_REGISTER ends

    PPCI_EXPRESS_PRI_STATUS_REGISTER typedef ptr PCI_EXPRESS_PRI_STATUS_REGISTER
    
    PCI_EXPRESS_PRI_CONTROL_REGISTER union
      struct DUMMYSTRUCTNAME_31
        DUMMYSTRUCTNAME_31_??56 record Enable_??56:1, Reset_??56:1, Rsvd_??156:14
        DUMMYSTRUCTNAME_31_??56 <>
      ends
      AsUSHORT WORD ?
    PCI_EXPRESS_PRI_CONTROL_REGISTER ends

    PPCI_EXPRESS_PRI_CONTROL_REGISTER typedef ptr PCI_EXPRESS_PRI_CONTROL_REGISTER
    
    PCI_EXPRESS_PRI_CAPABILITY struct
      Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
      Control PCI_EXPRESS_PRI_CONTROL_REGISTER <>
      Status PCI_EXPRESS_PRI_STATUS_REGISTER <>
      PRCapacity DWORD ?
      PRAllocation DWORD ?
    PCI_EXPRESS_PRI_CAPABILITY ends

    PPCI_EXPRESS_PRI_CAPABILITY typedef ptr PCI_EXPRESS_PRI_CAPABILITY
    
    PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS union
      struct DUMMYSTRUCTNAME_32
        DUMMYSTRUCTNAME_32_??57 record Undefined_??57:1, Reserved1_??57:3, DataLinkProtocolError_??57:1, SurpriseDownError_??57:1, Reserved2_??57:6, PoisonedTLP_??57:1, FlowControlProtocolError_??57:1, CompletionTimeout_??57:1, CompleterAbort_??57:1, UnexpectedCompletion_??57:1, ReceiverOverflow_??57:1, MalformedTLP_??57:1, ECRCError_??57:1, UnsupportedRequestError_??57:1, AcsViolation_??57:1, UncorrectableInternalError_??57:1, MCBlockedTlp_??57:1, AtomicOpEgressBlocked_??57:1, TlpPrefixBlocked_??57:1, Reserved3_??57:6
        DUMMYSTRUCTNAME_32_??57 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS ends

    PPCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS typedef ptr PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS
    
    PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK union
      struct DUMMYSTRUCTNAME_33
        DUMMYSTRUCTNAME_33_??58 record Undefined_??58:1, Reserved1_??58:3, DataLinkProtocolError_??58:1, SurpriseDownError_??58:1, Reserved2_??58:6, PoisonedTLP_??58:1, FlowControlProtocolError_??58:1, CompletionTimeout_??58:1, CompleterAbort_??58:1, UnexpectedCompletion_??58:1, ReceiverOverflow_??58:1, MalformedTLP_??58:1, ECRCError_??58:1, UnsupportedRequestError_??58:1, AcsViolation_??58:1, UncorrectableInternalError_??58:1, MCBlockedTlp_??58:1, AtomicOpEgressBlocked_??58:1, TlpPrefixBlocked_??58:1, Reserved3_??58:6
        DUMMYSTRUCTNAME_33_??58 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK ends

    PPCI_EXPRESS_UNCORRECTABLE_ERROR_MASK typedef ptr PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK
    
    PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY union
      struct DUMMYSTRUCTNAME_34
        DUMMYSTRUCTNAME_34_??59 record Undefined_??59:1, Reserved1_??59:3, DataLinkProtocolError_??59:1, SurpriseDownError_??59:1, Reserved2_??59:6, PoisonedTLP_??59:1, FlowControlProtocolError_??59:1, CompletionTimeout_??59:1, CompleterAbort_??59:1, UnexpectedCompletion_??59:1, ReceiverOverflow_??59:1, MalformedTLP_??59:1, ECRCError_??59:1, UnsupportedRequestError_??59:1, AcsViolation_??59:1, UncorrectableInternalError_??59:1, MCBlockedTlp_??59:1, AtomicOpEgressBlocked_??59:1, TlpPrefixBlocked_??59:1, Reserved3_??59:6
        DUMMYSTRUCTNAME_34_??59 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY ends

    PPCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY typedef ptr PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY
    
    PCI_EXPRESS_CORRECTABLE_ERROR_STATUS union
      struct DUMMYSTRUCTNAME_35
        DUMMYSTRUCTNAME_35_??60 record ReceiverError_??60:1, Reserved1_??60:5, BadTLP_??60:1, BadDLLP_??60:1, ReplayNumRollover_??60:1, Reserved2_??60:3, ReplayTimerTimeout_??60:1, AdvisoryNonFatalError_??60:1, CorrectedInternalError_??60:1, HeaderLogOverflow_??60:1, Reserved3_??60:16
        DUMMYSTRUCTNAME_35_??60 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_CORRECTABLE_ERROR_STATUS ends

    PPCI_CORRECTABLE_ERROR_STATUS typedef ptr PCI_EXPRESS_CORRECTABLE_ERROR_STATUS
    
    PCI_EXPRESS_CORRECTABLE_ERROR_MASK union
      struct DUMMYSTRUCTNAME_36
        DUMMYSTRUCTNAME_36_??61 record ReceiverError_??61:1, Reserved1_??61:5, BadTLP_??61:1, BadDLLP_??61:1, ReplayNumRollover_??61:1, Reserved2_??61:3, ReplayTimerTimeout_??61:1, AdvisoryNonFatalError_??61:1, CorrectedInternalError_??61:1, HeaderLogOverflow_??61:1, Reserved3_??61:16
        DUMMYSTRUCTNAME_36_??61 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_CORRECTABLE_ERROR_MASK ends

    PPCI_CORRECTABLE_ERROR_MASK typedef ptr PCI_EXPRESS_CORRECTABLE_ERROR_MASK
    
    PCI_EXPRESS_AER_CAPABILITIES union
      struct DUMMYSTRUCTNAME_37
        DUMMYSTRUCTNAME_37_??62 record FirstErrorPointer_??62:5, ECRCGenerationCapable_??62:1, ECRCGenerationEnable_??62:1, ECRCCheckCapable_??62:1, ECRCCheckEnable_??62:1, MultipleHeaderRecordingCapable_??62:1, MultipleHeaderRecordingEnable_??62:1, TlpPrefixLogPresent_??62:1, Reserved_??62:20
        DUMMYSTRUCTNAME_37_??62 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_AER_CAPABILITIES ends

    PPCI_EXPRESS_AER_CAPABILITIES typedef ptr PCI_EXPRESS_AER_CAPABILITIES
    
    PCI_EXPRESS_ROOT_ERROR_COMMAND union
      struct DUMMYSTRUCTNAME_38
        DUMMYSTRUCTNAME_38_??63 record CorrectableErrorReportingEnable_??63:1, NonFatalErrorReportingEnable_??63:1, FatalErrorReportingEnable_??63:1, Reserved_??63:29
        DUMMYSTRUCTNAME_38_??63 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_ROOT_ERROR_COMMAND ends

    PPCI_EXPRESS_ROOT_ERROR_COMMAND typedef ptr PCI_EXPRESS_ROOT_ERROR_COMMAND
    
    PCI_EXPRESS_ROOT_ERROR_STATUS union
      struct DUMMYSTRUCTNAME_39
        DUMMYSTRUCTNAME_39_??64 record CorrectableErrorReceived_??64:1, MultipleCorrectableErrorsReceived_??64:1, UncorrectableErrorReceived_??64:1, MultipleUncorrectableErrorsReceived_??64:1, FirstUncorrectableFatal_??64:1, NonFatalErrorMessagesReceived_??64:1, FatalErrorMessagesReceived_??64:1, Reserved_??64:20, AdvancedErrorInterruptMessageNumber_??64:5
        DUMMYSTRUCTNAME_39_??64 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_ROOT_ERROR_STATUS ends

    PPCI_EXPRESS_ROOT_ERROR_STATUS typedef ptr PCI_EXPRESS_ROOT_ERROR_STATUS
    
    PCI_EXPRESS_ERROR_SOURCE_ID union
      struct DUMMYSTRUCTNAME_40
        DUMMYSTRUCTNAME_40_??65 record CorrectableSourceIdFun_??65:3, CorrectableSourceIdDev_??65:5, CorrectableSourceIdBus_??65:8, UncorrectableSourceIdFun_??65:3, UncorrectableSourceIdDev_??65:5, UncorrectableSourceIdBus_??65:8
        DUMMYSTRUCTNAME_40_??65 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_ERROR_SOURCE_ID ends

    PPCI_EXPRESS_ERROR_SOURCE_ID typedef ptr PCI_EXPRESS_ERROR_SOURCE_ID
    
    PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS union
      struct DUMMYSTRUCTNAME_41
        DUMMYSTRUCTNAME_41_??66 record TargetAbortOnSplitCompletion_??66:1, MasterAbortOnSplitCompletion_??66:1, ReceivedTargetAbort_??66:1, ReceivedMasterAbort_??66:1, RsvdZ_??66:1, UnexpectedSplitCompletionError_??66:1, UncorrectableSplitCompletion_??66:1, UncorrectableDataError_??66:1, UncorrectableAttributeError_??66:1, UncorrectableAddressError_??66:1, DelayedTransactionDiscardTimerExpired_??66:1, PERRAsserted_??66:1, SERRAsserted_??66:1, InternalBridgeError_??66:1, Reserved_??66:18
        DUMMYSTRUCTNAME_41_??66 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS ends

    PPCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS typedef ptr PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS
    
    PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK union
      struct DUMMYSTRUCTNAME_42
        DUMMYSTRUCTNAME_42_??67 record TargetAbortOnSplitCompletion_??67:1, MasterAbortOnSplitCompletion_??67:1, ReceivedTargetAbort_??67:1, ReceivedMasterAbort_??67:1, RsvdZ_??67:1, UnexpectedSplitCompletionError_??67:1, UncorrectableSplitCompletion_??67:1, UncorrectableDataError_??67:1, UncorrectableAttributeError_??67:1, UncorrectableAddressError_??67:1, DelayedTransactionDiscardTimerExpired_??67:1, PERRAsserted_??67:1, SERRAsserted_??67:1, InternalBridgeError_??67:1, Reserved_??67:18
        DUMMYSTRUCTNAME_42_??67 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK ends

    PPCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK typedef ptr PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK
    
    PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY union
      struct DUMMYSTRUCTNAME_43
        DUMMYSTRUCTNAME_43_??68 record TargetAbortOnSplitCompletion_??68:1, MasterAbortOnSplitCompletion_??68:1, ReceivedTargetAbort_??68:1, ReceivedMasterAbort_??68:1, RsvdZ_??68:1, UnexpectedSplitCompletionError_??68:1, UncorrectableSplitCompletion_??68:1, UncorrectableDataError_??68:1, UncorrectableAttributeError_??68:1, UncorrectableAddressError_??68:1, DelayedTransactionDiscardTimerExpired_??68:1, PERRAsserted_??68:1, SERRAsserted_??68:1, InternalBridgeError_??68:1, Reserved_??68:18
        DUMMYSTRUCTNAME_43_??68 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY ends

    PPCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY typedef ptr PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY
    
    PCI_EXPRESS_SEC_AER_CAPABILITIES union
      struct DUMMYSTRUCTNAME_44
        DUMMYSTRUCTNAME_44_??69 record SecondaryUncorrectableFirstErrorPtr_??69:5, Reserved_??69:27
        DUMMYSTRUCTNAME_44_??69 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_SEC_AER_CAPABILITIES ends

    PPCI_EXPRESS_SEC_AER_CAPABILITIES typedef ptr PCI_EXPRESS_SEC_AER_CAPABILITIES
    
    ROOT_CMD_ENABLE_CORRECTABLE_ERROR_REPORTING equ 00000001h
    ROOT_CMD_ENABLE_NONFATAL_ERROR_REPORTING equ 00000002h
    ROOT_CMD_ENABLE_FATAL_ERROR_REPORTING equ 00000004h
    ROOT_CMD_ERROR_REPORTING_ENABLE_MASK equ <( ROOT_CMD_ENABLE_FATAL_ERROR_REPORTING or ROOT_CMD_ENABLE_NONFATAL_ERROR_REPORTING or ROOT_CMD_ENABLE_CORRECTABLE_ERROR_REPORTING )>
    PCI_EXPRESS_AER_CAPABILITY struct
      Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
      UncorrectableErrorStatus PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS <>
      UncorrectableErrorMask PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK <>
      UncorrectableErrorSeverity PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY <>
      CorrectableErrorStatus PCI_EXPRESS_CORRECTABLE_ERROR_STATUS <>
      CorrectableErrorMask PCI_EXPRESS_CORRECTABLE_ERROR_MASK <>
      CapabilitiesAndControl PCI_EXPRESS_AER_CAPABILITIES <>
      HeaderLog DWORD 4 dup (?)
      SecUncorrectableErrorStatus PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS <>
      SecUncorrectableErrorMask PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK <>
      SecUncorrectableErrorSeverity PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY <>
      SecCapabilitiesAndControl PCI_EXPRESS_SEC_AER_CAPABILITIES <>
      SecHeaderLog DWORD 4 dup (?)
    PCI_EXPRESS_AER_CAPABILITY ends

    PPCI_EXPRESS_AER_CAPABILITY typedef ptr PCI_EXPRESS_AER_CAPABILITY
    
    PCI_EXPRESS_ROOTPORT_AER_CAPABILITY struct
      Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
      UncorrectableErrorStatus PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS <>
      UncorrectableErrorMask PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK <>
      UncorrectableErrorSeverity PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY <>
      CorrectableErrorStatus PCI_EXPRESS_CORRECTABLE_ERROR_STATUS <>
      CorrectableErrorMask PCI_EXPRESS_CORRECTABLE_ERROR_MASK <>
      CapabilitiesAndControl PCI_EXPRESS_AER_CAPABILITIES <>
      HeaderLog DWORD 4 dup (?)
      RootErrorCommand PCI_EXPRESS_ROOT_ERROR_COMMAND <>
      RootErrorStatus PCI_EXPRESS_ROOT_ERROR_STATUS <>
      ErrorSourceId PCI_EXPRESS_ERROR_SOURCE_ID <>
    PCI_EXPRESS_ROOTPORT_AER_CAPABILITY ends

    PPCI_EXPRESS_ROOTPORT_AER_CAPABILITY typedef ptr PCI_EXPRESS_ROOTPORT_AER_CAPABILITY
    
    PCI_EXPRESS_BRIDGE_AER_CAPABILITY struct
      Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
      UncorrectableErrorStatus PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS <>
      UncorrectableErrorMask PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK <>
      UncorrectableErrorSeverity PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY <>
      CorrectableErrorStatus PCI_EXPRESS_CORRECTABLE_ERROR_STATUS <>
      CorrectableErrorMask PCI_EXPRESS_CORRECTABLE_ERROR_MASK <>
      CapabilitiesAndControl PCI_EXPRESS_AER_CAPABILITIES <>
      HeaderLog DWORD 4 dup (?)
      SecUncorrectableErrorStatus PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS <>
      SecUncorrectableErrorMask PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK <>
      SecUncorrectableErrorSeverity PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY <>
      SecCapabilitiesAndControl PCI_EXPRESS_SEC_AER_CAPABILITIES <>
      SecHeaderLog DWORD 4 dup (?)
    PCI_EXPRESS_BRIDGE_AER_CAPABILITY ends

    PPCI_EXPRESS_BRIDGE_AER_CAPABILITY typedef ptr PCI_EXPRESS_BRIDGE_AER_CAPABILITY
    
    PCI_EXPRESS_ACS_CAPABILITY_REGISTER union
      struct DUMMYSTRUCTNAME_45
        DUMMYSTRUCTNAME_45_??70 record SourceValidation_??70:1, TranslationBlocking_??70:1, RequestRedirect_??70:1, CompletionRedirect_??70:1, UpstreamForwarding_??70:1, EgressControl_??70:1, DirectTranslation_??70:1, Reserved_??170:1, EgressControlVectorSize_??70:8
        DUMMYSTRUCTNAME_45_??70 <>
      ends
      AsUSHORT WORD ?
    PCI_EXPRESS_ACS_CAPABILITY_REGISTER ends

    PPCI_EXPRESS_ACS_CAPABILITY_REGISTER typedef ptr PCI_EXPRESS_ACS_CAPABILITY_REGISTER
    
    PCI_EXPRESS_ACS_CONTROL union
      struct DUMMYSTRUCTNAME_46
        DUMMYSTRUCTNAME_46_??71 record SourceValidation_??71:1, TranslationBlocking_??71:1, RequestRedirect_??71:1, CompletionRedirect_??71:1, UpstreamForwarding_??71:1, EgressControl_??71:1, DirectTranslation_??71:1, Reserved_??171:9
        DUMMYSTRUCTNAME_46_??71 <>
      ends
      AsUSHORT WORD ?
    PCI_EXPRESS_ACS_CONTROL ends

    PPCI_EXPRESS_ACS_CONTROL typedef ptr PCI_EXPRESS_ACS_CONTROL
    
    PCI_EXPRESS_ACS_CAPABILITY struct
      Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
      Capability PCI_EXPRESS_ACS_CAPABILITY_REGISTER <>
      Control PCI_EXPRESS_ACS_CONTROL <>
      EgressControl DWORD 1 dup (?)
    PCI_EXPRESS_ACS_CAPABILITY ends

    PPCI_EXPRESS_ACS_CAPABILITY typedef ptr PCI_EXPRESS_ACS_CAPABILITY
    
    PCI_EXPRESS_SRIOV_CAPS union
      struct DUMMYSTRUCTNAME_47
        DUMMYSTRUCTNAME_47_??72 record VFMigrationCapable_??72:1, Reserved1_??72:20, VFMigrationInterruptNumber_??72:11
        DUMMYSTRUCTNAME_47_??72 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_SRIOV_CAPS ends

    PPCI_EXPRESS_SRIOV_CAPS typedef ptr PCI_EXPRESS_SRIOV_CAPS
    
    PCI_EXPRESS_SRIOV_CONTROL union
      struct DUMMYSTRUCTNAME_48
        DUMMYSTRUCTNAME_48_??73 record VFEnable_??73:1, VFMigrationEnable_??73:1, VFMigrationInterruptEnable_??73:1, VFMemorySpaceEnable_??73:1, ARICapableHierarchy_??73:1, Reserved1_??73:11
        DUMMYSTRUCTNAME_48_??73 <>
      ends
      AsUSHORT WORD ?
    PCI_EXPRESS_SRIOV_CONTROL ends

    PPCI_EXPRESS_SRIOV_CONTROL typedef ptr PCI_EXPRESS_SRIOV_CONTROL
    
    PCI_EXPRESS_SRIOV_STATUS union
      struct DUMMYSTRUCTNAME_49
        DUMMYSTRUCTNAME_49_??74 record VFMigrationStatus_??74:1, Reserved1_??74:15
        DUMMYSTRUCTNAME_49_??74 <>
      ends
      AsUSHORT WORD ?
    PCI_EXPRESS_SRIOV_STATUS ends

    PPCI_EXPRESS_SRIOV_STATUS typedef ptr PCI_EXPRESS_SRIOV_STATUS
    
    PCI_EXPRESS_SRIOV_MIGRATION_STATE_ARRAY union
      struct DUMMYSTRUCTNAME_50
        DUMMYSTRUCTNAME_50_??75 record VFMigrationStateBIR_??75:3, VFMigrationStateOffset_??75:29
        DUMMYSTRUCTNAME_50_??75 <>
      ends
      AsULONG DWORD ?
    PCI_EXPRESS_SRIOV_MIGRATION_STATE_ARRAY ends

    PPCI_EXPRESS_SRIOV_MIGRATION_STATE_ARRAY typedef ptr PCI_EXPRESS_SRIOV_MIGRATION_STATE_ARRAY
    
    PCI_EXPRESS_SRIOV_CAPABILITY struct
      Header PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER <>
      SRIOVCapabilities PCI_EXPRESS_SRIOV_CAPS <>
      SRIOVControl PCI_EXPRESS_SRIOV_CONTROL <>
      SRIOVStatus PCI_EXPRESS_SRIOV_STATUS <>
      InitialVFs WORD ?
      TotalVFs WORD ?
      NumVFs WORD ?
      FunctionDependencyLink BYTE ?
      RsvdP1 BYTE ?
      FirstVFOffset WORD ?
      VFStride WORD ?
      RsvdP2 WORD ?
      VFDeviceId WORD ?
      SupportedPageSizes DWORD ?
      SystemPageSize DWORD ?
      BaseAddresses DWORD PCI_TYPE0_ADDRESSES dup (?)
      VFMigrationStateArrayOffset PCI_EXPRESS_SRIOV_MIGRATION_STATE_ARRAY <>
    PCI_EXPRESS_SRIOV_CAPABILITY ends

    PPCI_EXPRESS_SRIOV_CAPABILITY typedef ptr PCI_EXPRESS_SRIOV_CAPABILITY
    
    PCI_CLASS_PRE_20 equ 00h
    PCI_CLASS_MASS_STORAGE_CTLR equ 01h
    PCI_CLASS_NETWORK_CTLR equ 02h
    PCI_CLASS_DISPLAY_CTLR equ 03h
    PCI_CLASS_MULTIMEDIA_DEV equ 04h
    PCI_CLASS_MEMORY_CTLR equ 05h
    PCI_CLASS_BRIDGE_DEV equ 06h
    PCI_CLASS_SIMPLE_COMMS_CTLR equ 07h
    PCI_CLASS_BASE_SYSTEM_DEV equ 08h
    PCI_CLASS_INPUT_DEV equ 09h
    PCI_CLASS_DOCKING_STATION equ 0ah
    PCI_CLASS_PROCESSOR equ 0bh
    PCI_CLASS_SERIAL_BUS_CTLR equ 0ch
    PCI_CLASS_WIRELESS_CTLR equ 0dh
    PCI_CLASS_INTELLIGENT_IO_CTLR equ 0eh
    PCI_CLASS_SATELLITE_COMMS_CTLR equ 0fh
    PCI_CLASS_ENCRYPTION_DECRYPTION equ 10h
    PCI_CLASS_DATA_ACQ_SIGNAL_PROC equ 11h
    PCI_CLASS_NOT_DEFINED equ 0ffh
    PCI_SUBCLASS_PRE_20_NON_VGA equ 00h
    PCI_SUBCLASS_PRE_20_VGA equ 01h
    PCI_SUBCLASS_MSC_SCSI_BUS_CTLR equ 00h
    PCI_SUBCLASS_MSC_IDE_CTLR equ 01h
    PCI_SUBCLASS_MSC_FLOPPY_CTLR equ 02h
    PCI_SUBCLASS_MSC_IPI_CTLR equ 03h
    PCI_SUBCLASS_MSC_RAID_CTLR equ 04h
    PCI_SUBCLASS_MSC_AHCI_CTLR equ 06h
    PCI_SUBCLASS_MSC_NVM_CTLR equ 08h
    PCI_SUBCLASS_MSC_OTHER equ 80h
    PCI_PROGRAMMING_INTERFACE_MSC_NVM_EXPRESS equ 02h
    PCI_SUBCLASS_NET_ETHERNET_CTLR equ 00h
    PCI_SUBCLASS_NET_TOKEN_RING_CTLR equ 01h
    PCI_SUBCLASS_NET_FDDI_CTLR equ 02h
    PCI_SUBCLASS_NET_ATM_CTLR equ 03h
    PCI_SUBCLASS_NET_ISDN_CTLR equ 04h
    PCI_SUBCLASS_NET_OTHER equ 80h
    PCI_SUBCLASS_VID_VGA_CTLR equ 00h
    PCI_SUBCLASS_VID_XGA_CTLR equ 01h
    PCI_SUBLCASS_VID_3D_CTLR equ 02h
    PCI_SUBCLASS_VID_OTHER equ 80h
    PCI_SUBCLASS_MM_VIDEO_DEV equ 00h
    PCI_SUBCLASS_MM_AUDIO_DEV equ 01h
    PCI_SUBCLASS_MM_TELEPHONY_DEV equ 02h
    PCI_SUBCLASS_MM_OTHER equ 80h
    PCI_SUBCLASS_MEM_RAM equ 00h
    PCI_SUBCLASS_MEM_FLASH equ 01h
    PCI_SUBCLASS_MEM_OTHER equ 80h
    PCI_SUBCLASS_BR_HOST equ 00h
    PCI_SUBCLASS_BR_ISA equ 01h
    PCI_SUBCLASS_BR_EISA equ 02h
    PCI_SUBCLASS_BR_MCA equ 03h
    PCI_SUBCLASS_BR_PCI_TO_PCI equ 04h
    PCI_SUBCLASS_BR_PCMCIA equ 05h
    PCI_SUBCLASS_BR_NUBUS equ 06h
    PCI_SUBCLASS_BR_CARDBUS equ 07h
    PCI_SUBCLASS_BR_RACEWAY equ 08h
    PCI_SUBCLASS_BR_OTHER equ 80h
    PCI_SUBCLASS_COM_SERIAL equ 00h
    PCI_SUBCLASS_COM_PARALLEL equ 01h
    PCI_SUBCLASS_COM_MULTIPORT equ 02h
    PCI_SUBCLASS_COM_MODEM equ 03h
    PCI_SUBCLASS_COM_OTHER equ 80h
    PCI_SUBCLASS_SYS_INTERRUPT_CTLR equ 00h
    PCI_SUBCLASS_SYS_DMA_CTLR equ 01h
    PCI_SUBCLASS_SYS_SYSTEM_TIMER equ 02h
    PCI_SUBCLASS_SYS_REAL_TIME_CLOCK equ 03h
    PCI_SUBCLASS_SYS_GEN_HOTPLUG_CTLR equ 04h
    PCI_SUBCLASS_SYS_SDIO_CTRL equ 05h
    PCI_SUBCLASS_SYS_OTHER equ 80h
    PCI_SUBCLASS_INP_KEYBOARD equ 00h
    PCI_SUBCLASS_INP_DIGITIZER equ 01h
    PCI_SUBCLASS_INP_MOUSE equ 02h
    PCI_SUBCLASS_INP_SCANNER equ 03h
    PCI_SUBCLASS_INP_GAMEPORT equ 04h
    PCI_SUBCLASS_INP_OTHER equ 80h
    PCI_SUBCLASS_DOC_GENERIC equ 00h
    PCI_SUBCLASS_DOC_OTHER equ 80h
    PCI_SUBCLASS_PROC_386 equ 00h
    PCI_SUBCLASS_PROC_486 equ 01h
    PCI_SUBCLASS_PROC_PENTIUM equ 02h
    PCI_SUBCLASS_PROC_ALPHA equ 10h
    PCI_SUBCLASS_PROC_POWERPC equ 20h
    PCI_SUBCLASS_PROC_COPROCESSOR equ 40h
    PCI_SUBCLASS_SB_IEEE1394 equ 00h
    PCI_SUBCLASS_SB_ACCESS equ 01h
    PCI_SUBCLASS_SB_SSA equ 02h
    PCI_SUBCLASS_SB_USB equ 03h
    PCI_SUBCLASS_SB_FIBRE_CHANNEL equ 04h
    PCI_SUBCLASS_SB_SMBUS equ 05h
    PCI_SUBCLASS_SB_THUNDERBOLT equ 0Ah
    PCI_SUBCLASS_WIRELESS_IRDA equ 00h
    PCI_SUBCLASS_WIRELESS_CON_IR equ 01h
    PCI_SUBCLASS_WIRELESS_RF equ 10h
    PCI_SUBCLASS_WIRELESS_OTHER equ 80h
    PCI_SUBCLASS_INTIO_I2O equ 00h
    PCI_SUBCLASS_SAT_TV equ 01h
    PCI_SUBCLASS_SAT_AUDIO equ 02h
    PCI_SUBCLASS_SAT_VOICE equ 03h
    PCI_SUBCLASS_SAT_DATA equ 04h
    PCI_SUBCLASS_CRYPTO_NET_COMP equ 00h
    PCI_SUBCLASS_CRYPTO_ENTERTAINMENT equ 10h
    PCI_SUBCLASS_CRYPTO_OTHER equ 80h
    PCI_SUBCLASS_DASP_DPIO equ 00h
    PCI_SUBCLASS_DASP_OTHER equ 80h
    PCI_ADDRESS_IO_SPACE equ 00000001h
    PCI_ADDRESS_MEMORY_TYPE_MASK equ 00000006h
    PCI_ADDRESS_MEMORY_PREFETCHABLE equ 00000008h
    PCI_ADDRESS_IO_ADDRESS_MASK equ 0fffffffch
    PCI_ADDRESS_MEMORY_ADDRESS_MASK equ 0fffffff0h
    PCI_ADDRESS_ROM_ADDRESS_MASK equ 0fffff800h
    PCI_TYPE_32BIT equ 0
    PCI_TYPE_20BIT equ 2
    PCI_TYPE_64BIT equ 4
    PCI_ROMADDRESS_ENABLED equ 00000001h
  endif
  PCI_DEVICE_PRESENT_INTERFACE_VERSION equ 1
  PCI_USE_SUBSYSTEM_IDS equ 00000001h
  PCI_USE_REVISION equ 00000002h
  PCI_USE_VENDEV_IDS equ 00000004h
  PCI_USE_CLASS_SUBCLASS equ 00000008h
  PCI_USE_PROGIF equ 00000010h
  PCI_USE_LOCAL_BUS equ 00000020h
  PCI_USE_LOCAL_DEVICE equ 00000040h
  PCI_DEVICE_PRESENCE_PARAMETERS struct
    Size_ DWORD ?
    Flags DWORD ?
    VendorID WORD ?
    DeviceID WORD ?
    RevisionID BYTE ?
    SubVendorID WORD ?
    SubSystemID WORD ?
    BaseClass BYTE ?
    SubClass BYTE ?
    ProgIf BYTE ?
  PCI_DEVICE_PRESENCE_PARAMETERS ends

  PPCI_DEVICE_PRESENCE_PARAMETERS typedef ptr PCI_DEVICE_PRESENCE_PARAMETERS

  PPCI_IS_DEVICE_PRESENT_EX typedef ptr PCI_IS_DEVICE_PRESENT_EX
  PCI_DEVICE_PRESENT_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    IsDevicePresent QWORD ?;PPCI_IS_DEVICE_PRESENT ?
    IsDevicePresentEx QWORD ?;PPCI_IS_DEVICE_PRESENT_EX ?
  PCI_DEVICE_PRESENT_INTERFACE ends

  PPCI_DEVICE_PRESENT_INTERFACE typedef ptr PCI_DEVICE_PRESENT_INTERFACE
  
  PCI_EXPRESS_LINK_QUIESCENT_INTERFACE_VERSION equ 1

  PCI_EXPRESS_LINK_QUIESCENT_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    PciExpressEnterLinkQuiescentMode QWORD ?;PPCI_EXPRESS_ENTER_LINK_QUIESCENT_MODE ?
    PciExpressExitLinkQuiescentMode QWORD ?;PPCI_EXPRESS_EXIT_LINK_QUIESCENT_MODE ?
  PCI_EXPRESS_LINK_QUIESCENT_INTERFACE ends

  PPCI_EXPRESS_LINK_QUIESCENT_INTERFACE typedef ptr PCI_EXPRESS_LINK_QUIESCENT_INTERFACE
  
  PCI_EXPRESS_ROOT_PORT_INTERFACE_VERSION equ 1
  proto_PPCI_EXPRESS_ROOT_PORT_READ_CONFIG_SPACE typedef proto fastcall :PVOID, :PVOID, :DWORD, :DWORD
  PPCI_EXPRESS_ROOT_PORT_READ_CONFIG_SPACE typedef ptr proto_PPCI_EXPRESS_ROOT_PORT_READ_CONFIG_SPACE
  proto_PPCI_EXPRESS_ROOT_PORT_WRITE_CONFIG_SPACE typedef proto fastcall :PVOID, :PVOID, :DWORD, :DWORD
  PPCI_EXPRESS_ROOT_PORT_WRITE_CONFIG_SPACE typedef ptr proto_PPCI_EXPRESS_ROOT_PORT_WRITE_CONFIG_SPACE
  PCI_EXPRESS_ROOT_PORT_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    ReadConfigSpace PPCI_EXPRESS_ROOT_PORT_READ_CONFIG_SPACE ?
    WriteConfigSpace PPCI_EXPRESS_ROOT_PORT_WRITE_CONFIG_SPACE ?
  PCI_EXPRESS_ROOT_PORT_INTERFACE ends

  PPCI_EXPRESS_ROOT_PORT_INTERFACE typedef ptr PCI_EXPRESS_ROOT_PORT_INTERFACE
  
  PCI_MSIX_TABLE_CONFIG_INTERFACE_VERSION equ 1

  PCI_MSIX_TABLE_CONFIG_INTERFACE struct
    Size_ WORD ?
    Version WORD ?
    Context PVOID ?
    InterfaceReference PINTERFACE_REFERENCE ?
    InterfaceDereference PINTERFACE_DEREFERENCE ?
    SetTableEntry QWORD ?;PPCI_MSIX_SET_ENTRY ?
    MaskTableEntry QWORD ?;PPCI_MSIX_MASKUNMASK_ENTRY ?
    UnmaskTableEntry QWORD ?;PPCI_MSIX_MASKUNMASK_ENTRY ?
    GetTableEntry QWORD ?;PPCI_MSIX_GET_ENTRY ?
    GetTableSize QWORD ?;PPCI_MSIX_GET_TABLE_SIZE ?
  PCI_MSIX_TABLE_CONFIG_INTERFACE ends

  PPCI_MSIX_TABLE_CONFIG_INTERFACE typedef ptr PCI_MSIX_TABLE_CONFIG_INTERFACE
  
  PCI_MSIX_TABLE_CONFIG_MINIMUM_SIZE equ <RTL_SIZEOF_THROUGH_FIELD ( PCI_MSIX_TABLE_CONFIG_INTERFACE , UnmaskTableEntry )>



      FILE_ATTRIBUTE_DEDICATED equ <FILE_ATTRIBUTE_TEMPORARY>
      EA_CONTAINER_NAME equ <"ContainerName",0>
      EA_CONTAINER_SIZE equ <"ContainerSize",0>
      CLFS_BASELOG_EXTENSION equ <L(".blf",0)>
      CLFS_FLAG_NO_FLAGS equ 00000000h
      CLFS_FLAG_FORCE_APPEND equ 00000001h
      CLFS_FLAG_FORCE_FLUSH equ 00000002h
      CLFS_FLAG_USE_RESERVATION equ 00000004h
      CLFS_FLAG_REENTRANT_FILE_SYSTEM equ 00000008h
      CLFS_FLAG_NON_REENTRANT_FILTER equ 00000010h
      CLFS_FLAG_REENTRANT_FILTER equ 00000020h
      CLFS_FLAG_IGNORE_SHARE_ACCESS equ 00000040h
      CLFS_FLAG_READ_IN_PROGRESS equ 00000080h
      CLFS_FLAG_MINIFILTER_LEVEL equ 00000100h
      CLFS_FLAG_HIDDEN_SYSTEM_LOG equ 00000200h
      CLFS_MARSHALLING_FLAG_NONE equ 00000000h
      CLFS_MARSHALLING_FLAG_DISABLE_BUFF_INIT equ 00000001h
      CLFS_FLAG_FILTER_INTERMEDIATE_LEVEL equ <CLFS_FLAG_NON_REENTRANT_FILTER>
      CLFS_FLAG_FILTER_TOP_LEVEL equ <CLFS_FLAG_REENTRANT_FILTER>
      CLFS_CONTAINER_ID typedef DWORD
      PCLFS_CONTAINER_ID typedef ptr CLFS_CONTAINER_ID
      PPCLFS_CONTAINER_ID typedef ptr ptr CLFS_CONTAINER_ID


        CLS_LSN struct
          Internal QWORD ?
        CLS_LSN ends

        PCLS_LSN typedef ptr CLS_LSN
        PPCLS_LSN typedef ptr ptr CLS_LSN


      CLFS_LSN typedef CLS_LSN
      PCLFS_LSN typedef ptr CLFS_LSN
      PPCLFS_LSN typedef ptr ptr CLFS_LSN


        ClfsNullRecord equ 00h
        ClfsDataRecord equ 01h
        ClfsRestartRecord equ 02h
        ClfsClientRecord equ <( ClfsDataRecord or ClfsRestartRecord )>

        CLFS_CONTAINER_STREAM_PREFIX equ <L("%BLF%:",0)>


        CLFS_CONTAINER_RELATIVE_PREFIX equ <L("%BLF%\",0)>

      CLS_RECORD_TYPE typedef BYTE
      PCLS_RECORD_TYPE typedef ptr BYTE
      PPCLS_RECORD_TYPE typedef ptr ptr BYTE
      CLFS_RECORD_TYPE typedef CLS_RECORD_TYPE
      PCLFS_RECORD_TYPE typedef ptr CLS_RECORD_TYPE
      PPCLFS_RECORD_TYPE typedef ptr ptr CLS_RECORD_TYPE


      CLS_CONTEXT_MODE typedef SDWORD
      ClsContextNone EQU 00h 
      ClsContextUndoNext EQU 1
      ClsContextPrevious EQU 2
      ClsContextForward EQU 3
      
      PCLS_CONTEXT_MODE typedef ptr CLS_CONTEXT_MODE
      PPCLS_CONTEXT_MODE typedef ptr ptr CLS_CONTEXT_MODE
      


      CLFS_NODE_ID struct
        cType DWORD ?
        cbNode DWORD ?
      CLFS_NODE_ID ends

      PCLFS_NODE_ID typedef ptr CLFS_NODE_ID
      

      CLS_WRITE_ENTRY struct
        Buffer PVOID ?
        ByteLength DWORD ?
      CLS_WRITE_ENTRY ends

      PCLS_WRITE_ENTRY typedef ptr CLS_WRITE_ENTRY
      PPCLS_WRITE_ENTRY typedef ptr ptr CLS_WRITE_ENTRY

      CLFS_WRITE_ENTRY typedef CLS_WRITE_ENTRY
      PCLFS_WRITE_ENTRY typedef ptr CLFS_WRITE_ENTRY
      PPCLFS_WRITE_ENTRY typedef ptr ptr CLFS_WRITE_ENTRY

      CLFS_LOG_ID typedef GUID

      CLS_INFORMATION struct
        TotalAvailable QWORD ?
        CurrentAvailable QWORD ?
        TotalReservation QWORD ?
        BaseFileSize QWORD ?
        ContainerSize QWORD ?
        TotalContainers DWORD ?
        FreeContainers DWORD ?
        TotalClients DWORD ?
        Attributes DWORD ?
        FlushThreshold DWORD ?
        SectorSize DWORD ?
        MinArchiveTailLsn CLS_LSN <>
        BaseLsn CLS_LSN <>
        LastFlushedLsn CLS_LSN <>
        LastLsn CLS_LSN <>
        RestartLsn CLS_LSN <>
        Identity GUID <>
      CLS_INFORMATION ends

      PCLS_INFORMATION typedef ptr CLS_INFORMATION
      PPCLS_INFORMATION typedef ptr CLS_INFORMATION

      CLFS_INFORMATION typedef CLS_INFORMATION
      PCLFS_INFORMATION typedef ptr CLFS_INFORMATION
      PPCLFS_INFORMATION typedef ptr CLFS_INFORMATION


      CLFS_LOG_NAME_INFORMATION struct
        NameLengthInBytes WORD ?
        Name_ WCHAR 1 dup (?)
      CLFS_LOG_NAME_INFORMATION ends

      PCLFS_LOG_NAME_INFORMATION typedef ptr CLFS_LOG_NAME_INFORMATION
      PPCLFS_LOG_NAME_INFORMATION typedef ptr ptr CLFS_LOG_NAME_INFORMATION

      CLFS_STREAM_ID_INFORMATION struct
        StreamIdentifier BYTE ?
      CLFS_STREAM_ID_INFORMATION ends

      PCLFS_STREAM_ID_INFORMATION typedef ptr CLFS_STREAM_ID_INFORMATION
      PPCLFS_STREAM_ID_INFORMATION typedef ptr ptr CLFS_STREAM_ID_INFORMATION


      CLFS_PHYSICAL_LSN_INFORMATION struct
        StreamIdentifier BYTE ?
        VirtualLsn CLFS_LSN <>
        PhysicalLsn CLFS_LSN <>
      CLFS_PHYSICAL_LSN_INFORMATION ends

      PCLFS_PHYSICAL_LSN_INFORMATION typedef ptr CLFS_PHYSICAL_LSN_INFORMATION


      CLS_CONTAINER_STATE typedef UINT32
      PCLS_CONTAINER_STATE typedef ptr UINT32
      PPCLS_CONTAINER_STATE typedef ptr UINT32
      CLFS_CONTAINER_STATE typedef CLS_CONTAINER_STATE
      PCLFS_CONTAINER_STATE typedef ptr CLS_CONTAINER_STATE
      PPCLFS_CONTAINER_STATE typedef ptr CLS_CONTAINER_STATE


        ClsContainerInitializing equ 01h
        ClsContainerInactive equ 02h
        ClsContainerActive equ 04h
        ClsContainerActivePendingDelete equ 08h
        ClsContainerPendingArchive equ 10h
        ClsContainerPendingArchiveAndDelete equ 20h
        ClfsContainerInitializing equ 01h
        ClfsContainerInactive equ 02h
        ClfsContainerActive equ 04h
        ClfsContainerActivePendingDelete equ 08h
        ClfsContainerPendingArchive equ 10h
        ClfsContainerPendingArchiveAndDelete equ 20h


        CLFS_MAX_CONTAINER_INFO equ 256


      CLS_CONTAINER_INFORMATION struct
        FileAttributes DWORD ?
        CreationTime QWORD ?
        LastAccessTime QWORD ?
        LastWriteTime QWORD ?
        ContainerSize QWORD ?
        FileNameActualLength DWORD ?
        FileNameLength DWORD ?
        FileName WCHAR CLFS_MAX_CONTAINER_INFO dup (?)
        State CLFS_CONTAINER_STATE ?
        PhysicalContainerId CLFS_CONTAINER_ID ?
        LogicalContainerId CLFS_CONTAINER_ID ?
      CLS_CONTAINER_INFORMATION ends

      PCLS_CONTAINER_INFORMATION typedef ptr CLS_CONTAINER_INFORMATION
      PPCLS_CONTAINER_INFORMATION typedef ptr ptr CLS_CONTAINER_INFORMATION
      
      CLFS_CONTAINER_INFORMATION typedef CLS_CONTAINER_INFORMATION
      PCLFS_CONTAINER_INFORMATION typedef ptr CLFS_CONTAINER_INFORMATION
      PPCLFS_CONTAINER_INFORMATION typedef ptr ptr CLFS_CONTAINER_INFORMATION

      CLS_LOG_INFORMATION_CLASS typedef SDWORD
      ClfsLogBasicInformation EQU 00h 
      ClfsLogBasicInformationPhysical EQU 1
      ClfsLogPhysicalNameInformation EQU 2
      ClfsLogStreamIdentifierInformation EQU 3

        ClfsLogSystemMarkingInformation EQU 4
        ClfsLogPhysicalLsnInformation EQU 5
      
      PCLS_LOG_INFORMATION_CLASS typedef ptr CLS_LOG_INFORMATION_CLASS
      PPCLS_LOG_INFORMATION_CLASS typedef ptr ptr CLS_LOG_INFORMATION_CLASS
      
      CLFS_LOG_INFORMATION_CLASS typedef CLS_LOG_INFORMATION_CLASS
      PCLFS_LOG_INFORMATION_CLASS typedef ptr CLFS_LOG_INFORMATION_CLASS
      PPCLFS_LOG_INFORMATION_CLASS typedef ptr ptr CLFS_LOG_INFORMATION_CLASS

      CLS_IOSTATS_CLASS typedef SDWORD
      ClsIoStatsDefault EQU 0000h 
      ClsIoStatsMax EQU 0FFFFh 
      
      PCLS_IOSTATS_CLASS typedef ptr CLS_IOSTATS_CLASS
      PPCLS_IOSTATS_CLASS typedef ptr ptr CLS_IOSTATS_CLASS
      

      CLFS_IOSTATS_CLASS typedef SDWORD
      ClfsIoStatsDefault EQU 0000h 
      ClfsIoStatsMax EQU 0FFFFh 
      
      PCLFS_IOSTATS_CLASS typedef ptr CLFS_IOSTATS_CLASS
      PPCLFS_IOSTATS_CLASS typedef ptr ptr CLFS_IOSTATS_CLASS

      CLS_IO_STATISTICS_HEADER struct
        ubMajorVersion BYTE ?
        ubMinorVersion BYTE ?
        eStatsClass CLFS_IOSTATS_CLASS ?
        cbLength WORD ?
        coffData DWORD ?
      CLS_IO_STATISTICS_HEADER ends

      PCLS_IO_STATISTICS_HEADER typedef ptr CLS_IO_STATISTICS_HEADER
      PPCLS_IO_STATISTICS_HEADER typedef ptr ptr CLS_IO_STATISTICS_HEADER
      
      CLFS_IO_STATISTICS_HEADER typedef CLS_IO_STATISTICS_HEADER
      PCLFS_IO_STATISTICS_HEADER typedef ptr CLFS_IO_STATISTICS_HEADER
      PPCLFS_IO_STATISTICS_HEADER typedef ptr ptr CLFS_IO_STATISTICS_HEADER

      CLS_IO_STATISTICS struct
        hdrIoStats CLS_IO_STATISTICS_HEADER <>
        cFlush QWORD ?
        cbFlush QWORD ?
        cMetaFlush QWORD ?
        cbMetaFlush QWORD ?
      CLS_IO_STATISTICS ends

      PCLS_IO_STATISTICS typedef ptr CLS_IO_STATISTICS
      PPCLS_IO_STATISTICS typedef ptr ptr CLS_IO_STATISTICS
      
      CLFS_IO_STATISTICS typedef CLS_IO_STATISTICS
      PCLFS_IO_STATISTICS typedef ptr CLFS_IO_STATISTICS
      PPCLFS_IO_STATISTICS typedef ptr ptr CLFS_IO_STATISTICS

        CLFS_SCAN_INIT equ 01h
        CLFS_SCAN_FORWARD equ 02h
        CLFS_SCAN_BACKWARD equ 04h
        CLFS_SCAN_CLOSE equ 08h
        CLFS_SCAN_INITIALIZED equ 10h
        CLFS_SCAN_BUFFERED equ 20h

      CLFS_SCAN_MODE typedef BYTE
      PCLFS_SCAN_MODE typedef ptr BYTE

      LOG_FILE_OBJECT typedef FILE_OBJECT
      PLOG_FILE_OBJECT typedef ptr FILE_OBJECT
      PPLOG_FILE_OBJECT typedef ptr ptr FILE_OBJECT

      CLS_SCAN_CONTEXT struct
        cidNode CLFS_NODE_ID <>
        plfoLog PLOG_FILE_OBJECT ?

        cIndex DWORD ?

        cContainers DWORD ?

        cContainersReturned DWORD ?

        eScanMode CLFS_SCAN_MODE ?

        pinfoContainer PCLS_CONTAINER_INFORMATION ?
      CLS_SCAN_CONTEXT ends

      PCLS_SCAN_CONTEXT typedef ptr CLS_SCAN_CONTEXT
      PPCLS_SCAN_CONTEXT typedef ptr ptr CLS_SCAN_CONTEXT
      


      CLFS_SCAN_CONTEXT typedef CLS_SCAN_CONTEXT
      PCLFS_SCAN_CONTEXT typedef ptr CLFS_SCAN_CONTEXT
      PPCLFS_SCAN_CONTEXT typedef ptr ptr CLFS_SCAN_CONTEXT

      CLS_ARCHIVE_DESCRIPTOR struct
        coffLow QWORD ?
        coffHigh QWORD ?
        infoContainer CLS_CONTAINER_INFORMATION <>
      CLS_ARCHIVE_DESCRIPTOR ends

      PCLS_ARCHIVE_DESCRIPTOR typedef ptr CLS_ARCHIVE_DESCRIPTOR
      PPCLS_ARCHIVE_DESCRIPTOR typedef ptr ptr CLS_ARCHIVE_DESCRIPTOR
      
      CLFS_ARCHIVE_DESCRIPTOR typedef CLS_ARCHIVE_DESCRIPTOR
      PCLFS_ARCHIVE_DESCRIPTOR typedef ptr CLFS_ARCHIVE_DESCRIPTOR
      PPCLFS_ARCHIVE_DESCRIPTOR typedef ptr ptr CLFS_ARCHIVE_DESCRIPTOR

      proto_CLFS_BLOCK_ALLOCATION typedef proto fastcall :DWORD, :PVOID
      CLFS_BLOCK_ALLOCATION typedef ptr proto_CLFS_BLOCK_ALLOCATION
      proto_CLFS_BLOCK_DEALLOCATION typedef proto fastcall :PVOID, :PVOID
      CLFS_BLOCK_DEALLOCATION typedef ptr proto_CLFS_BLOCK_DEALLOCATION

      CLFS_LOG_ARCHIVE_MODE typedef SDWORD
      ClfsLogArchiveEnabled EQU 01h 
      ClfsLogArchiveDisabled EQU 02h 
      
      PCLFS_LOG_ARCHIVE_MODE typedef ptr CLFS_LOG_ARCHIVE_MODE
      


      ClfsLsnEqual proto stdcall :ptr CLFS_LSN, :ptr CLFS_LSN

      ClfsLsnLess proto stdcall :ptr CLFS_LSN, :ptr CLFS_LSN

      ClfsLsnGreater proto stdcall :ptr CLFS_LSN, :ptr CLFS_LSN

      ClfsLsnNull proto stdcall :ptr CLFS_LSN

      ClfsLsnContainer proto stdcall :ptr CLFS_LSN

      ClfsLsnCreate proto stdcall :CLFS_CONTAINER_ID, :DWORD, :DWORD

      ClfsLsnBlockOffset proto stdcall :ptr CLFS_LSN

      ClfsLsnRecordSequence proto stdcall :ptr CLFS_LSN

      ClfsLsnInvalid proto stdcall :ptr CLFS_LSN

      ClfsLsnIncrement proto stdcall :PCLFS_LSN


 

    CLFS_MGMT_POLICY_TYPE typedef SDWORD
    ClfsMgmtPolicyMaximumSize EQU 0h 
    ClfsMgmtPolicyMinimumSize EQU 1
    ClfsMgmtPolicyNewContainerSize EQU 2
    ClfsMgmtPolicyGrowthRate EQU 3
    ClfsMgmtPolicyLogTail EQU 4
    ClfsMgmtPolicyAutoShrink EQU 5
    ClfsMgmtPolicyAutoGrow EQU 6
    ClfsMgmtPolicyNewContainerPrefix EQU 7
    ClfsMgmtPolicyNewContainerSuffix EQU 8
    ClfsMgmtPolicyNewContainerExtension EQU 9
    ClfsMgmtPolicyInvalid EQU 10
    
    PCLFS_MGMT_POLICY_TYPE typedef ptr CLFS_MGMT_POLICY_TYPE


    CLFS_MGMT_NUM_POLICIES equ <( ClfsMgmtPolicyInvalid )>

    CLFS_LOG_SIZE_MINIMUM equ ( 0 )
    CLFS_LOG_SIZE_MAXIMUM equ ( - 1 )

    CLFS_MGMT_POLICY_VERSION equ 01h

    LOG_POLICY_OVERWRITE equ 01h
    LOG_POLICY_PERSIST equ 02h

    CLFS_MGMT_POLICY struct
      Version DWORD ?
      LengthInBytes DWORD ?
      PolicyFlags DWORD ?
      PolicyType CLFS_MGMT_POLICY_TYPE ?
      union PolicyParameters
        struct MaximumSize
          Containers DWORD ?
        ends
        struct MinimumSize
          Containers DWORD ?
        ends
        struct NewContainerSize
          SizeInBytes DWORD ?
        ends
        struct GrowthRate
          AbsoluteGrowthInContainers DWORD ?
          RelativeGrowthPercentage DWORD ?
        ends
        struct LogTail
          MinimumAvailablePercentage DWORD ?
          MinimumAvailableContainers DWORD ?
        ends
        struct AutoShrink
          Percentage DWORD ?
        ends
        struct AutoGrow
          Enabled DWORD ?
        ends
        struct NewContainerPrefix
          PrefixLengthInBytes WORD ?
          PrefixString WCHAR 1 dup (?)
        ends
        struct NewContainerSuffix
          NextContainerSuffix QWORD ?
        ends
        struct NewContainerExtension
          ExtensionLengthInBytes WORD ?
          ExtensionString WCHAR 1 dup (?)
        ends
      ends
    CLFS_MGMT_POLICY ends

    PCLFS_MGMT_POLICY typedef ptr CLFS_MGMT_POLICY
    

    CLFS_MGMT_NOTIFICATION_TYPE typedef SDWORD
    ClfsMgmtAdvanceTailNotification EQU 0 
    ClfsMgmtLogFullHandlerNotification EQU 1
    ClfsMgmtLogUnpinnedNotification EQU 2
    ClfsMgmtLogWriteNotification EQU 3
    
    PCLFS_MGMT_NOTIFICATION_TYPE typedef ptr CLFS_MGMT_NOTIFICATION_TYPE
    

    CLFS_MGMT_NOTIFICATION struct
      Notification CLFS_MGMT_NOTIFICATION_TYPE ?
      Lsn CLFS_LSN <>
      LogIsPinned WORD ?
    CLFS_MGMT_NOTIFICATION ends

    PCLFS_MGMT_NOTIFICATION typedef ptr CLFS_MGMT_NOTIFICATION
    

    proto_PCLFS_CLIENT_ADVANCE_TAIL_CALLBACK typedef proto fastcall :PLOG_FILE_OBJECT, :PCLFS_LSN, :PVOID
    PCLFS_CLIENT_ADVANCE_TAIL_CALLBACK typedef ptr proto_PCLFS_CLIENT_ADVANCE_TAIL_CALLBACK

    proto_PCLFS_CLIENT_LFF_HANDLER_COMPLETE_CALLBACK typedef proto fastcall :PLOG_FILE_OBJECT, :NTSTATUS, :BOOLEAN, :PVOID
    PCLFS_CLIENT_LFF_HANDLER_COMPLETE_CALLBACK typedef ptr proto_PCLFS_CLIENT_LFF_HANDLER_COMPLETE_CALLBACK

    proto_PCLFS_CLIENT_LOG_UNPINNED_CALLBACK typedef proto fastcall :PLOG_FILE_OBJECT, :PVOID
    PCLFS_CLIENT_LOG_UNPINNED_CALLBACK typedef ptr proto_PCLFS_CLIENT_LOG_UNPINNED_CALLBACK

    proto_PCLFS_SET_LOG_SIZE_COMPLETE_CALLBACK typedef proto fastcall :PLOG_FILE_OBJECT, :NTSTATUS, :PVOID
    PCLFS_SET_LOG_SIZE_COMPLETE_CALLBACK typedef ptr proto_PCLFS_SET_LOG_SIZE_COMPLETE_CALLBACK

    CLFS_MGMT_CLIENT_REGISTRATION_VERSION equ 1h
    CLFS_MGMT_CLIENT_REGISTRATION struct
      Version DWORD ?
      AdvanceTailCallback PCLFS_CLIENT_ADVANCE_TAIL_CALLBACK ?
      AdvanceTailCallbackData PVOID ?
      LogGrowthCompleteCallback PCLFS_CLIENT_LFF_HANDLER_COMPLETE_CALLBACK ?
      LogGrowthCompleteCallbackData PVOID ?
      LogUnpinnedCallback PCLFS_CLIENT_LOG_UNPINNED_CALLBACK ?
      LogUnpinnedCallbackData PVOID ?
    CLFS_MGMT_CLIENT_REGISTRATION ends

    PCLFS_MGMT_CLIENT_REGISTRATION typedef ptr CLFS_MGMT_CLIENT_REGISTRATION
    

    CLFS_MGMT_CLIENT typedef PVOID
    PCLFS_MGMT_CLIENT typedef ptr PVOID



  ;KTRANSACTION typedef _KTRANSACTION
  ;PKTRANSACTION typedef ptr _KTRANSACTION
  ;PRKTRANSACTION typedef ptr _KTRANSACTION
  
  ;KENLISTMENT typedef _KENLISTMENT
  ;PKENLISTMENT typedef ptr _KENLISTMENT
  ;PRKENLISTMENT typedef ptr _KENLISTMENT
  
  ;KRESOURCEMANAGER typedef _KRESOURCEMANAGER
  ;PKRESOURCEMANAGER typedef ptr _KRESOURCEMANAGER
  ;PRKRESOURCEMANAGER typedef ptr _KRESOURCEMANAGER
  
  ;KTM typedef _KTM
  ;PKTM typedef ptr _KTM
  ;PRKTM typedef ptr _KTM
  
  UOW typedef GUID
  PUOW typedef ptr GUID
  PGUID typedef ptr GUID

  KCRM_PROTOCOL_ID typedef GUID
  PKCRM_PROTOCOL_ID typedef ptr GUID
  PCW_VERSION_1 equ 0100h
  PCW_CURRENT_VERSION equ <PCW_VERSION_1>
  PPCW_INSTANCE typedef ptr _PCW_INSTANCE
  
  PPCW_REGISTRATION typedef ptr _PCW_REGISTRATION
  
  PPCW_BUFFER typedef ptr _PCW_BUFFER
  
  PCW_COUNTER_DESCRIPTOR struct
    Id WORD ?
    StructIndex WORD ?
    Offset_ WORD ?
    Size_ WORD ?
  PCW_COUNTER_DESCRIPTOR ends

  PPCW_COUNTER_DESCRIPTOR typedef ptr PCW_COUNTER_DESCRIPTOR
  
  PCW_DATA struct
    Data POINTER ?
    Size_ DWORD ?
  PCW_DATA ends

  PPCW_DATA typedef ptr PCW_DATA
  
  PCW_COUNTER_INFORMATION struct
    CounterMask ULONG64 ?
    InstanceMask PCUNICODE_STRING ?
  PCW_COUNTER_INFORMATION ends

  PPCW_COUNTER_INFORMATION typedef ptr PCW_COUNTER_INFORMATION
  
  PCW_MASK_INFORMATION struct
    CounterMask ULONG64 ?
    InstanceMask PCUNICODE_STRING ?
    InstanceId DWORD ?
    CollectMultiple BOOLEAN ?
    Buffer PPCW_BUFFER ?
    CancelEvent PKEVENT ?
  PCW_MASK_INFORMATION ends

  PPCW_MASK_INFORMATION typedef ptr PCW_MASK_INFORMATION
  
  PCW_CALLBACK_INFORMATION union
    AddCounter PCW_COUNTER_INFORMATION <>
    RemoveCounter PCW_COUNTER_INFORMATION <>
    EnumerateInstances PCW_MASK_INFORMATION <>
    CollectData PCW_MASK_INFORMATION <>
  PCW_CALLBACK_INFORMATION ends

  PPCW_CALLBACK_INFORMATION typedef ptr PCW_CALLBACK_INFORMATION
  
  PCW_CALLBACK_TYPE typedef SDWORD
  PcwCallbackAddCounter EQU 0 
  PcwCallbackRemoveCounter EQU 1
  PcwCallbackEnumerateInstances EQU 2
  PcwCallbackCollectData EQU 3
  
  PPCW_CALLBACK_TYPE typedef ptr PCW_CALLBACK_TYPE
  
  PCW_CALLBACK typedef proto stdcall :PCW_CALLBACK_TYPE,:PPCW_CALLBACK_INFORMATION,:PVOID
  PPCW_CALLBACK typedef ptr PCW_CALLBACK
  PCW_REGISTRATION_INFORMATION struct
    Version DWORD ?
    Name_ PCUNICODE_STRING ?
    CounterCount DWORD ?
    Counters PPCW_COUNTER_DESCRIPTOR ?
    Callback PPCW_CALLBACK ?
    CallbackContext PVOID ?
  PCW_REGISTRATION_INFORMATION ends

  PPCW_REGISTRATION_INFORMATION typedef ptr PCW_REGISTRATION_INFORMATION


    SECURE_SECTION_ALLOW_PARTIAL_MDL equ 1

  ifndef _OB_REFERENCE_TAGS_
    _OB_REFERENCE_TAGS_ equ <>
    REFTAG_AFDCONN equ <'CdfA'>
    REFTAG_AFDENDPOINT equ <'EdfA'>
    REFTAG_AFDPOLL equ <'PdfA'>
    REFTAG_ALEIO equ <'IelA'>
    REFTAG_ALEPROCTBL equ <'PelA'>
    REFTAG_ALESIDTOKEN equ <'SelA'>
    REFTAG_CFSFILTER equ <'FsfC'>
    REFTAG_DWMKERNEL equ <'KmwD'>
    REFTAG_HTTP equ <'pttH'>
    REFTAG_MAILSLOT equ <'sFsM'>
    REFTAG_NFSVOLUME equ <'VsfN'>
    REFTAG_PGMFILE equ <'TmgP'>
    REFTAG_PSLOOKUP equ <'ULsP'>
    REFTAG_PSNOTIFICATION equ <'oNsP'>
    REFTAG_PSWAKE equ <'kWsP'>
    REFTAG_RAWENDPOINT equ <'EwaR'>
    REFTAG_TCPENDPOINT equ <'EpcT'>
    REFTAG_TCPLISTENER equ <'LpcT'>
    REFTAG_TCPTCB equ <'TpcT'>
    REFTAG_UDPENDPOINT equ <'EpdU'>
    REFTAG_USRKDESKTOP equ <'DrsU'>
    REFTAG_VIDEO_PORT_I386 equ <'idiV'>
    REFTAG_VIDEO_PORT equ <'PdiV'>
    REFTAG_WIN32K equ <'k23W'>
    REFTAG_WIN32KQUEUE equ <'q23W'>
    REFTAG_WIN32KRESTRICT equ <'r23W'>
    REFTAG_WIN32KSERVER equ <'S23W'>
    REFTAG_WIN32KSTUBS equ <'s23W'>
    REFTAG_WS2IFSL equ <'i2sW'>
    REFTAG_WSKNAMERES equ <'NksW'>
    REFTAG_WSKPROV equ <'PksW'>
    REFTAG_WSKTDI equ <'TksW'>
  endif
  DRIVER_RUNTIME_INIT_FLAGS typedef SDWORD
  DrvRtPoolNxOptIn EQU 00000001h 
  LastDrvRtFlag EQU 2
  
  PDRIVER_RUNTIME_INIT_FLAGS typedef ptr DRIVER_RUNTIME_INIT_FLAGS
  
  PCDRIVER_RUNTIME_INIT_FLAGS typedef ptr SDWORD
  ExInitializeDriverRuntime proto fastcall :DWORD


endif

 