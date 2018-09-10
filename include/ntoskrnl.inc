;==============================================================================
; UASM-DDK - ntoskrnl.inc
; 
; www.github.com/mrfearless/UASM-DDK by fearless
; 
;==============================================================================

ei386EoiHelper PROTO 
AlpcGetHeaderSize PROTO :QWORD
AlpcGetMessageAttribute PROTO :QWORD,:QWORD
AlpcInitializeMessageAttribute PROTO :QWORD,:QWORD,:QWORD,:QWORD
BgkDisplayCharacter PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
BgkGetConsoleState PROTO :QWORD
BgkGetCursorState PROTO :QWORD,:QWORD,:QWORD
BgkSetCursor PROTO :QWORD,:QWORD,:QWORD
CcAddDirtyPagesToExternalCache PROTO :QWORD,:QWORD
CcCanIWrite PROTO :QWORD,:QWORD,:QWORD,:QWORD
CcCoherencyFlushAndPurgeCache PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcCopyRead PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcCopyReadEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcCopyWrite PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcCopyWriteEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcCopyWriteWontFlush PROTO :QWORD,:QWORD,:QWORD
CcDeductDirtyPagesFromExternalCache PROTO :QWORD,:QWORD
CcDeferWrite PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcFastCopyRead PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcFastCopyWrite PROTO :QWORD,:QWORD,:QWORD,:QWORD
CcFastMdlReadWait PROTO C :VARARG
CcFlushCache PROTO :QWORD,:QWORD,:QWORD,:QWORD
CcFlushCacheToLsn PROTO :QWORD,:QWORD,:QWORD
CcGetDirtyPages PROTO :QWORD,:QWORD,:QWORD,:QWORD
CcGetFileObjectFromBcb PROTO :QWORD
CcGetFileObjectFromSectionPtrs PROTO :QWORD
CcGetFileObjectFromSectionPtrsRef PROTO :QWORD
CcGetFlushedValidData PROTO :QWORD,:QWORD
CcGetLsnForFileObject PROTO :QWORD,:QWORD
CcInitializeCacheMap PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcIsThereDirtyData PROTO :QWORD
CcIsThereDirtyDataEx PROTO :QWORD,:QWORD
CcIsThereDirtyLoggedPages PROTO :QWORD,:QWORD
CcMapData PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcMdlRead PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcMdlReadComplete PROTO :QWORD,:QWORD
CcMdlWriteAbort PROTO :QWORD,:QWORD
CcMdlWriteComplete PROTO :QWORD,:QWORD,:QWORD
CcPinMappedData PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcPinRead PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcPrepareMdlWrite PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcPreparePinWrite PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcPurgeCacheSection PROTO :QWORD,:QWORD,:QWORD,:QWORD
CcRegisterExternalCache PROTO :QWORD,:QWORD
CcRemapBcb PROTO :QWORD
CcRepinBcb PROTO :QWORD
CcScheduleReadAhead PROTO :QWORD,:QWORD,:QWORD
CcScheduleReadAheadEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
CcSetAdditionalCacheAttributes PROTO :QWORD,:QWORD,:QWORD
CcSetAdditionalCacheAttributesEx PROTO :QWORD,:QWORD
CcSetBcbOwnerPointer PROTO :QWORD,:QWORD
CcSetDirtyPageThreshold PROTO :QWORD,:QWORD
CcSetDirtyPinnedData PROTO :QWORD,:QWORD
CcSetFileSizes PROTO :QWORD,:QWORD
CcSetFileSizesEx PROTO :QWORD,:QWORD
CcSetLogHandleForFile PROTO :QWORD,:QWORD,:QWORD
CcSetLogHandleForFileEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CcSetLoggedDataThreshold PROTO :QWORD,:QWORD
CcSetParallelFlushFile PROTO :QWORD,:QWORD
CcSetReadAheadGranularity PROTO :QWORD,:QWORD
CcSetReadAheadGranularityEx PROTO :QWORD,:QWORD
CcTestControl PROTO :QWORD,:QWORD,:QWORD
CcUninitializeCacheMap PROTO :QWORD,:QWORD,:QWORD
CcUnmapFileOffsetFromSystemCache PROTO :QWORD,:QWORD,:QWORD,:QWORD
CcUnpinData PROTO :QWORD
CcUnpinDataForThread PROTO :QWORD,:QWORD
CcUnpinRepinnedBcb PROTO :QWORD,:QWORD,:QWORD
CcUnregisterExternalCache PROTO :QWORD
CcWaitForCurrentLazyWriterActivity PROTO 
CcZeroData PROTO :QWORD,:QWORD,:QWORD,:QWORD
CcZeroDataOnDisk PROTO :QWORD,:QWORD,:QWORD,:QWORD
CmCallbackGetKeyObjectID PROTO :QWORD,:QWORD,:QWORD,:QWORD
CmCallbackGetKeyObjectIDEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CmCallbackReleaseKeyObjectIDEx PROTO :QWORD
CmGetBoundTransaction PROTO :QWORD,:QWORD
CmGetCallbackVersion PROTO :QWORD,:QWORD
CmKeyObjectType PROTO C :VARARG
CmRegisterCallback PROTO :QWORD,:QWORD,:QWORD
CmRegisterCallbackEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
CmSetCallbackObjectContext PROTO :QWORD,:QWORD,:QWORD,:QWORD
CmUnRegisterCallback PROTO :QWORD,:QWORD
DbgBreakPoint PROTO 
DbgBreakPointWithStatus PROTO :QWORD
DbgCommandString PROTO :QWORD,:QWORD
DbgLoadImageSymbols PROTO :QWORD,:QWORD,:QWORD
;DbgPrint PROTO C :VARARG
;DbgPrintEx PROTO C :VARARG
DbgPrintReturnControlC PROTO C :VARARG
DbgPrompt PROTO :QWORD,:QWORD,:QWORD
DbgQueryDebugFilterState PROTO :QWORD,:QWORD
DbgSetDebugFilterState PROTO :QWORD,:QWORD,:QWORD
DbgSetDebugPrintCallback PROTO :QWORD,:QWORD
DbgkLkmdRegisterCallback PROTO :QWORD,:QWORD,:QWORD
DbgkLkmdUnregisterCallback PROTO :QWORD
DbgkWerCaptureLiveKernelDump PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EmClientQueryRuleState PROTO :QWORD,:QWORD
EmClientRuleDeregisterNotification PROTO :QWORD
EmClientRuleEvaluate PROTO :QWORD,:QWORD,:QWORD,:QWORD
EmClientRuleRegisterNotification PROTO :QWORD,:QWORD,:QWORD,:QWORD
EmProviderDeregister PROTO :QWORD
EmProviderDeregisterEntry PROTO :QWORD
EmProviderRegister PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EmProviderRegisterEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD
EmpProviderRegister PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EtwActivityIdControl PROTO :QWORD,:QWORD
EtwEnableTrace PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EtwEventEnabled PROTO :QWORD,:QWORD,:QWORD
EtwProviderEnabled PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EtwRegister PROTO :QWORD,:QWORD,:QWORD,:QWORD
EtwRegisterClassicProvider PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EtwSendTraceBuffer PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EtwUnregister PROTO :QWORD,:QWORD
EtwWrite PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EtwWriteEndScenario PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EtwWriteEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EtwWriteStartScenario PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EtwWriteString PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EtwWriteTransfer PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ExAcquireCacheAwarePushLockExclusive PROTO :QWORD
ExAcquireCacheAwarePushLockExclusiveEx PROTO :QWORD,:QWORD
ExAcquireCacheAwarePushLockSharedEx PROTO :QWORD,:QWORD
ExAcquireFastMutexUnsafe PROTO :QWORD
ExAcquirePushLockExclusiveEx PROTO :QWORD,:QWORD
ExAcquirePushLockSharedEx PROTO :QWORD,:QWORD
ExAcquireResourceExclusiveLite PROTO :QWORD,:QWORD
ExAcquireResourceSharedLite PROTO :QWORD,:QWORD
ExAcquireRundownProtection PROTO :QWORD
ExAcquireRundownProtectionCacheAware PROTO :QWORD
ExAcquireRundownProtectionCacheAwareEx PROTO :QWORD,:QWORD
ExAcquireRundownProtectionEx PROTO :QWORD,:QWORD
ExAcquireSharedStarveExclusive PROTO :QWORD,:QWORD
ExAcquireSharedWaitForExclusive PROTO :QWORD,:QWORD
ExAcquireSpinLockExclusive PROTO :QWORD
ExAcquireSpinLockExclusiveAtDpcLevel PROTO :QWORD
ExAcquireSpinLockShared PROTO :QWORD
ExAcquireSpinLockSharedAtDpcLevel PROTO :QWORD
ExAllocateCacheAwarePushLock PROTO :QWORD
ExAllocateCacheAwareRundownProtection PROTO :QWORD,:QWORD
ExAllocateFromPagedLookasideList PROTO :QWORD
ExAllocatePool PROTO :QWORD,:QWORD
ExAllocatePoolWithQuota PROTO :QWORD,:QWORD
ExAllocatePoolWithQuotaTag PROTO :QWORD,:QWORD,:QWORD
ExAllocatePoolWithTag PROTO :QWORD,:QWORD,:QWORD
ExAllocatePoolWithTagPriority PROTO :QWORD,:QWORD,:QWORD,:QWORD
ExAllocateTimer PROTO :QWORD,:QWORD,:QWORD
ExAllocateTimerInternal PROTO :QWORD,:QWORD,:QWORD
ExBlockOnAddressPushLock PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ExBlockPushLock PROTO :QWORD,:QWORD
ExCancelTimer PROTO :QWORD,:QWORD
ExCompositionObjectType PROTO C :VARARG
ExConvertExclusiveToSharedLite PROTO :QWORD
ExCreateCallback PROTO :QWORD,:QWORD,:QWORD,:QWORD
ExDeleteLookasideListEx PROTO :QWORD
ExDeleteNPagedLookasideList PROTO :QWORD
ExDeletePagedLookasideList PROTO :QWORD
ExDeleteResourceLite PROTO :QWORD
ExDeleteTimer PROTO :QWORD,:QWORD,:QWORD,:QWORD
ExDesktopObjectType PROTO C :VARARG
ExDisableResourceBoostLite PROTO :QWORD
ExEnterCriticalRegionAndAcquireFastMutexUnsafe PROTO :QWORD
ExEnterCriticalRegionAndAcquireResourceExclusive PROTO :QWORD
ExEnterCriticalRegionAndAcquireResourceShared PROTO :QWORD
ExEnterCriticalRegionAndAcquireSharedWaitForExclusive PROTO :QWORD
ExEnterPriorityRegionAndAcquireResourceExclusive PROTO :QWORD
ExEnterPriorityRegionAndAcquireResourceShared PROTO :QWORD
ExEnumHandleTable PROTO :QWORD,:QWORD,:QWORD,:QWORD
ExEventObjectType PROTO C :VARARG
ExExtendZone PROTO :QWORD,:QWORD,:QWORD
ExFetchLicenseData PROTO :QWORD,:QWORD,:QWORD
ExFlushLookasideListEx PROTO :QWORD
ExFreeCacheAwarePushLock PROTO :QWORD
ExFreeCacheAwareRundownProtection PROTO :QWORD
ExFreePool PROTO :QWORD
ExFreePoolWithTag PROTO :QWORD,:QWORD
ExFreeToPagedLookasideList PROTO :QWORD,:QWORD
ExGetCurrentProcessorCounts PROTO :QWORD,:QWORD,:QWORD
ExGetCurrentProcessorCpuUsage PROTO :QWORD
ExGetExclusiveWaiterCount PROTO :QWORD
ExGetFirmwareEnvironmentVariable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ExGetLicenseTamperState PROTO :QWORD
ExGetPreviousMode PROTO 
ExGetSharedWaiterCount PROTO :QWORD
ExInitializeLookasideListEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ExInitializeNPagedLookasideList PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ExInitializePagedLookasideList PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ExInitializePushLock PROTO :QWORD
ExInitializeResourceLite PROTO :QWORD
ExInitializeRundownProtection PROTO :QWORD
ExInitializeRundownProtectionCacheAware PROTO :QWORD,:QWORD
ExInitializeZone PROTO :QWORD,:QWORD,:QWORD,:QWORD
ExInterlockedAddLargeInteger PROTO :QWORD,:QWORD,:QWORD,:QWORD
ExInterlockedAddLargeStatistic PROTO :QWORD,:QWORD
ExInterlockedAddUlong PROTO :QWORD,:QWORD,:QWORD
ExInterlockedCompareExchange64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
ExInterlockedDecrementLong PROTO :QWORD,:QWORD
ExInterlockedExchangeUlong PROTO :QWORD,:QWORD,:QWORD
ExInterlockedExtendZone PROTO :QWORD,:QWORD,:QWORD,:QWORD
ExInterlockedFlushSList PROTO :QWORD
ExInterlockedIncrementLong PROTO :QWORD,:QWORD
ExInterlockedInsertHeadList PROTO :QWORD,:QWORD,:QWORD
ExInterlockedInsertTailList PROTO :QWORD,:QWORD,:QWORD
ExInterlockedPopEntryList PROTO :QWORD,:QWORD
ExInterlockedPopEntrySList PROTO :QWORD,:QWORD
ExInterlockedPushEntryList PROTO :QWORD,:QWORD,:QWORD
ExInterlockedPushEntrySList PROTO :QWORD,:QWORD,:QWORD
ExInterlockedRemoveHeadList PROTO :QWORD,:QWORD
ExIsProcessorFeaturePresent PROTO :QWORD
ExIsResourceAcquiredExclusiveLite PROTO :QWORD
ExIsResourceAcquiredSharedLite PROTO :QWORD
ExLocalTimeToSystemTime PROTO :QWORD,:QWORD
ExNotifyBootDeviceRemoval PROTO :QWORD
ExNotifyCallback PROTO :QWORD,:QWORD,:QWORD
ExQueryFastCacheAppOrigin PROTO :QWORD,:QWORD
ExQueryFastCacheDevLicense PROTO 
ExQueryPoolBlockSize PROTO :QWORD,:QWORD
ExQueryTimerResolution PROTO :QWORD,:QWORD,:QWORD
ExQueryWnfStateData PROTO :QWORD,:QWORD,:QWORD,:QWORD
ExQueueWorkItem PROTO :QWORD,:QWORD
ExRaiseAccessViolation PROTO 
ExRaiseDatatypeMisalignment PROTO 
ExRaiseException PROTO :QWORD
ExRaiseHardError PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ExRaiseStatus PROTO :QWORD
ExReInitializeRundownProtection PROTO :QWORD
ExReInitializeRundownProtectionCacheAware PROTO :QWORD
ExRegisterBootDevice PROTO :QWORD,:QWORD
ExRegisterCallback PROTO :QWORD,:QWORD,:QWORD
ExRegisterExtension PROTO :QWORD,:QWORD,:QWORD
ExReinitializeResourceLite PROTO :QWORD
ExReleaseCacheAwarePushLockExclusive PROTO :QWORD
ExReleaseCacheAwarePushLockExclusiveEx PROTO :QWORD,:QWORD
ExReleaseCacheAwarePushLockSharedEx PROTO :QWORD,:QWORD
ExReleaseFastMutexUnsafe PROTO :QWORD
ExReleaseFastMutexUnsafeAndLeaveCriticalRegion PROTO :QWORD
ExReleasePushLockEx PROTO :QWORD,:QWORD
ExReleasePushLockExclusiveEx PROTO :QWORD,:QWORD
ExReleasePushLockSharedEx PROTO :QWORD,:QWORD
ExReleaseResourceAndLeaveCriticalRegion PROTO :QWORD
ExReleaseResourceAndLeavePriorityRegion PROTO :QWORD
ExReleaseResourceForThreadLite PROTO :QWORD,:QWORD
ExReleaseResourceLite PROTO :QWORD
ExReleaseRundownProtection PROTO :QWORD
ExReleaseRundownProtectionCacheAware PROTO :QWORD
ExReleaseRundownProtectionCacheAwareEx PROTO :QWORD,:QWORD
ExReleaseRundownProtectionEx PROTO :QWORD,:QWORD
ExReleaseSpinLockExclusive PROTO :QWORD,:QWORD
ExReleaseSpinLockExclusiveFromDpcLevel PROTO :QWORD
ExReleaseSpinLockShared PROTO :QWORD,:QWORD
ExReleaseSpinLockSharedFromDpcLevel PROTO :QWORD
ExRundownCompleted PROTO :QWORD
ExRundownCompletedCacheAware PROTO :QWORD
ExSemaphoreObjectType PROTO C :VARARG
ExSetFirmwareEnvironmentVariable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ExSetLicenseTamperState PROTO :QWORD
ExSetResourceOwnerPointer PROTO :QWORD,:QWORD
ExSetResourceOwnerPointerEx PROTO :QWORD,:QWORD,:QWORD
ExSetTimer PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ExSetTimerResolution PROTO :QWORD,:QWORD
ExSizeOfRundownProtectionCacheAware PROTO 
ExSubscribeWnfStateChange PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ExSystemExceptionFilter PROTO 
ExSystemTimeToLocalTime PROTO :QWORD,:QWORD
ExTimedWaitForUnblockPushLock PROTO :QWORD,:QWORD,:QWORD
ExTryAcquirePushLockExclusiveEx PROTO :QWORD,:QWORD
ExTryAcquirePushLockSharedEx PROTO :QWORD,:QWORD
ExTryConvertPushLockSharedToExclusiveEx PROTO :QWORD,:QWORD
ExTryConvertSharedSpinLockExclusive PROTO :QWORD
ExTryQueueWorkItem PROTO :QWORD,:QWORD
ExTryToAcquireResourceExclusiveLite PROTO :QWORD
ExUnblockOnAddressPushLockEx PROTO :QWORD,:QWORD
ExUnblockPushLockEx PROTO :QWORD,:QWORD
ExUnregisterCallback PROTO :QWORD
ExUnregisterExtension PROTO :QWORD
ExUnsubscribeWnfStateChange PROTO :QWORD
ExUuidCreate PROTO :QWORD
ExVerifySuite PROTO :QWORD
ExWaitForRundownProtectionRelease PROTO :QWORD
ExWaitForRundownProtectionReleaseCacheAware PROTO :QWORD
ExWaitForUnblockPushLock PROTO :QWORD,:QWORD
ExWindowStationObjectType PROTO C :VARARG
ExfAcquirePushLockExclusive PROTO :QWORD
ExfAcquirePushLockShared PROTO :QWORD
ExfInterlockedAddUlong PROTO :QWORD,:QWORD,:QWORD
ExfInterlockedCompareExchange64 PROTO :QWORD,:QWORD,:QWORD
ExfInterlockedInsertHeadList PROTO :QWORD,:QWORD,:QWORD
ExfInterlockedInsertTailList PROTO :QWORD,:QWORD,:QWORD
ExfInterlockedPopEntryList PROTO :QWORD,:QWORD
ExfInterlockedPushEntryList PROTO :QWORD,:QWORD,:QWORD
ExfInterlockedRemoveHeadList PROTO :QWORD,:QWORD
ExfReleasePushLock PROTO :QWORD
ExfReleasePushLockExclusive PROTO :QWORD
ExfReleasePushLockShared PROTO :QWORD
ExfTryAcquirePushLockShared PROTO :QWORD
ExfTryToWakePushLock PROTO :QWORD
ExfUnblockPushLock PROTO :QWORD,:QWORD
Exfi386InterlockedDecrementLong PROTO :QWORD
Exfi386InterlockedExchangeUlong PROTO :QWORD,:QWORD
Exfi386InterlockedIncrementLong PROTO :QWORD
Exi386InterlockedDecrementLong PROTO :QWORD,:QWORD
Exi386InterlockedExchangeUlong PROTO :QWORD,:QWORD,:QWORD
Exi386InterlockedIncrementLong PROTO :QWORD,:QWORD
FirstEntrySList PROTO :QWORD
FsRtlAcknowledgeEcp PROTO :QWORD
FsRtlAcquireEofLock PROTO :QWORD
FsRtlAcquireFileExclusive PROTO :QWORD
FsRtlAcquireHeaderMutex PROTO :QWORD
FsRtlAddBaseMcbEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlAddBaseMcbEntryEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlAddLargeMcbEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlAddMcbEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlAddToTunnelCache PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlAllocateExtraCreateParameter PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlAllocateExtraCreateParameterFromLookasideList PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlAllocateExtraCreateParameterList PROTO :QWORD,:QWORD
FsRtlAllocateFileLock PROTO :QWORD,:QWORD
FsRtlAllocatePool PROTO :QWORD,:QWORD
FsRtlAllocatePoolWithQuota PROTO :QWORD,:QWORD
FsRtlAllocatePoolWithQuotaTag PROTO :QWORD,:QWORD,:QWORD
FsRtlAllocatePoolWithTag PROTO :QWORD,:QWORD,:QWORD
FsRtlAllocateResource PROTO 
FsRtlAreNamesEqual PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlAreThereCurrentOrInProgressFileLocks PROTO :QWORD
FsRtlAreThereWaitingFileLocks PROTO :QWORD
FsRtlAreVolumeStartupApplicationsComplete PROTO 
FsRtlBalanceReads PROTO :QWORD
FsRtlCancellableWaitForMultipleObjects PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlCancellableWaitForSingleObject PROTO :QWORD,:QWORD,:QWORD
FsRtlChangeBackingFileObject PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlCheckLockForOplockRequest PROTO :QWORD,:QWORD
FsRtlCheckLockForReadAccess PROTO :QWORD,:QWORD
FsRtlCheckLockForWriteAccess PROTO :QWORD,:QWORD
FsRtlCheckOplock PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlCheckOplockEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlCheckUpperOplock PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlCopyRead PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlCopyWrite PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlCreateSectionForDataScan PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlCurrentBatchOplock PROTO :QWORD
FsRtlCurrentOplock PROTO :QWORD
FsRtlCurrentOplockH PROTO :QWORD
FsRtlDeleteExtraCreateParameterLookasideList PROTO :QWORD,:QWORD
FsRtlDeleteKeyFromTunnelCache PROTO :QWORD,:QWORD,:QWORD
FsRtlDeleteTunnelCache PROTO :QWORD
FsRtlDeregisterUncProvider PROTO :QWORD
FsRtlDismountComplete PROTO :QWORD,:QWORD
FsRtlDissectDbcs PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlDissectName PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlDoesDbcsContainWildCards PROTO :QWORD
FsRtlDoesNameContainWildCards PROTO :QWORD
FsRtlFastCheckLockForRead PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlFastCheckLockForWrite PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlFastUnlockAll PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlFastUnlockAllByKey PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlFastUnlockSingle PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlFindExtraCreateParameter PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlFindInTunnelCache PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlFreeExtraCreateParameter PROTO :QWORD
FsRtlFreeExtraCreateParameterList PROTO :QWORD
FsRtlFreeFileLock PROTO :QWORD
FsRtlGetEcpListFromIrp PROTO :QWORD,:QWORD
FsRtlGetFileNameInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlGetFileSize PROTO :QWORD,:QWORD
FsRtlGetIoAtEof PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlGetNextBaseMcbEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlGetNextExtraCreateParameter PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlGetNextFileLock PROTO :QWORD,:QWORD
FsRtlGetNextLargeMcbEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlGetNextMcbEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlGetSectorSizeInformation PROTO :QWORD,:QWORD
FsRtlGetSupportedFeatures PROTO :QWORD,:QWORD
FsRtlGetVirtualDiskNestingLevel PROTO :QWORD,:QWORD,:QWORD
FsRtlHeatInit PROTO :QWORD,:QWORD,:QWORD
FsRtlHeatLogIo PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlHeatLogTierMove PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlHeatUninit PROTO :QWORD,:QWORD
FsRtlIncrementCcFastMdlReadWait PROTO 
FsRtlIncrementCcFastReadNoWait PROTO 
FsRtlIncrementCcFastReadNotPossible PROTO 
FsRtlIncrementCcFastReadResourceMiss PROTO 
FsRtlIncrementCcFastReadWait PROTO 
FsRtlInitExtraCreateParameterLookasideList PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlInitializeBaseMcb PROTO :QWORD,:QWORD
FsRtlInitializeBaseMcbEx PROTO :QWORD,:QWORD,:QWORD
FsRtlInitializeEofLock PROTO :QWORD,:QWORD
FsRtlInitializeExtraCreateParameter PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlInitializeExtraCreateParameterList PROTO :QWORD
FsRtlInitializeFileLock PROTO :QWORD,:QWORD,:QWORD
FsRtlInitializeLargeMcb PROTO :QWORD,:QWORD
FsRtlInitializeMcb PROTO :QWORD,:QWORD
FsRtlInitializeOplock PROTO :QWORD
FsRtlInitializeTunnelCache PROTO :QWORD
FsRtlInsertExtraCreateParameter PROTO :QWORD,:QWORD
FsRtlInsertPerFileContext PROTO :QWORD,:QWORD
FsRtlInsertPerFileObjectContext PROTO :QWORD,:QWORD
FsRtlInsertPerStreamContext PROTO :QWORD,:QWORD
FsRtlInsertReservedPerFileContext PROTO :QWORD,:QWORD
FsRtlInsertReservedPerStreamContext PROTO :QWORD,:QWORD
FsRtlIsDbcsInExpression PROTO :QWORD,:QWORD
FsRtlIsEcpAcknowledged PROTO :QWORD
FsRtlIsEcpFromUserMode PROTO :QWORD
FsRtlIsFatDbcsLegal PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlIsHpfsDbcsLegal PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlIsNameInExpression PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlIsNtstatusExpected PROTO :QWORD
FsRtlIsPagingFile PROTO :QWORD
FsRtlIsSystemPagingFile PROTO :QWORD
FsRtlIsTotalDeviceFailure PROTO :QWORD
FsRtlIssueDeviceIoControl PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlKernelFsControlFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlLegalAnsiCharacterArray PROTO C :VARARG
FsRtlLogCcFlushError PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlLookupBaseMcbEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlLookupLargeMcbEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlLookupLastBaseMcbEntry PROTO :QWORD,:QWORD,:QWORD
FsRtlLookupLastBaseMcbEntryAndIndex PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlLookupLastLargeMcbEntry PROTO :QWORD,:QWORD,:QWORD
FsRtlLookupLastLargeMcbEntryAndIndex PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlLookupLastMcbEntry PROTO :QWORD,:QWORD,:QWORD
FsRtlLookupMcbEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlLookupPerFileContext PROTO :QWORD,:QWORD,:QWORD
FsRtlLookupPerFileObjectContext PROTO :QWORD,:QWORD,:QWORD
FsRtlLookupPerStreamContextInternal PROTO :QWORD,:QWORD,:QWORD
FsRtlLookupReservedPerFileContext PROTO :QWORD,:QWORD,:QWORD
FsRtlLookupReservedPerStreamContext PROTO :QWORD,:QWORD,:QWORD
FsRtlMdlRead PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlMdlReadComplete PROTO :QWORD,:QWORD
FsRtlMdlReadCompleteDev PROTO :QWORD,:QWORD,:QWORD
FsRtlMdlReadDev PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlMdlReadEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlMdlWriteComplete PROTO :QWORD,:QWORD,:QWORD
FsRtlMdlWriteCompleteDev PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlMupGetProviderIdFromName PROTO :QWORD,:QWORD
FsRtlMupGetProviderInfoFromFileObject PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlNormalizeNtstatus PROTO :QWORD,:QWORD
FsRtlNotifyChangeDirectory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlNotifyCleanup PROTO :QWORD,:QWORD,:QWORD
FsRtlNotifyCleanupAll PROTO :QWORD,:QWORD
FsRtlNotifyFilterChangeDirectory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlNotifyFilterReportChange PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlNotifyFullChangeDirectory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlNotifyFullReportChange PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlNotifyInitializeSync PROTO :QWORD
FsRtlNotifyReportChange PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlNotifyUninitializeSync PROTO :QWORD
FsRtlNotifyVolumeEvent PROTO :QWORD,:QWORD
FsRtlNotifyVolumeEventEx PROTO :QWORD,:QWORD,:QWORD
FsRtlNumberOfRunsInBaseMcb PROTO :QWORD
FsRtlNumberOfRunsInLargeMcb PROTO :QWORD
FsRtlNumberOfRunsInMcb PROTO :QWORD
FsRtlOplockBreakH PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlOplockBreakToNone PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlOplockBreakToNoneEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlOplockFsctrl PROTO :QWORD,:QWORD,:QWORD
FsRtlOplockFsctrlEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlOplockIsFastIoPossible PROTO :QWORD
FsRtlOplockIsSharedRequest PROTO :QWORD
FsRtlOplockKeysEqual PROTO :QWORD,:QWORD
FsRtlPostPagingFileStackOverflow PROTO :QWORD,:QWORD,:QWORD
FsRtlPostStackOverflow PROTO :QWORD,:QWORD,:QWORD
FsRtlPrepareMdlWrite PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlPrepareMdlWriteDev PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlPrepareMdlWriteEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlPrepareToReuseEcp PROTO :QWORD
FsRtlPrivateLock PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlProcessFileLock PROTO :QWORD,:QWORD,:QWORD
FsRtlQueryCachedVdl PROTO :QWORD,:QWORD
FsRtlQueryKernelEaFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlQueryMaximumVirtualDiskNestingLevel PROTO 
FsRtlRegisterFileSystemFilterCallbacks PROTO :QWORD,:QWORD
FsRtlRegisterFltMgrCalls PROTO :QWORD
FsRtlRegisterMupCalls PROTO :QWORD
FsRtlRegisterUncProvider PROTO :QWORD,:QWORD,:QWORD
FsRtlRegisterUncProviderEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlReleaseEofLock PROTO :QWORD
FsRtlReleaseFile PROTO :QWORD
FsRtlReleaseFileNameInformation PROTO :QWORD
FsRtlReleaseHeaderMutex PROTO :QWORD
FsRtlRemoveBaseMcbEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlRemoveDotsFromPath PROTO :QWORD,:QWORD,:QWORD
FsRtlRemoveExtraCreateParameter PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlRemoveLargeMcbEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlRemoveMcbEntry PROTO :QWORD,:QWORD,:QWORD
FsRtlRemovePerFileContext PROTO :QWORD,:QWORD,:QWORD
FsRtlRemovePerFileObjectContext PROTO :QWORD,:QWORD,:QWORD
FsRtlRemovePerStreamContext PROTO :QWORD,:QWORD,:QWORD
FsRtlRemoveReservedPerFileContext PROTO :QWORD,:QWORD,:QWORD
FsRtlRemoveReservedPerStreamContext PROTO :QWORD,:QWORD,:QWORD
FsRtlResetBaseMcb PROTO :QWORD
FsRtlResetLargeMcb PROTO :QWORD,:QWORD
FsRtlSendModernAppTermination PROTO :QWORD,:QWORD,:QWORD
FsRtlSetEcpListIntoIrp PROTO :QWORD,:QWORD
FsRtlSetKernelEaFile PROTO :QWORD,:QWORD,:QWORD
FsRtlSplitBaseMcb PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlSplitLargeMcb PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlSyncVolumes PROTO :QWORD,:QWORD,:QWORD
FsRtlTeardownPerFileContexts PROTO :QWORD
FsRtlTeardownPerStreamContexts PROTO :QWORD
FsRtlTruncateBaseMcb PROTO :QWORD,:QWORD,:QWORD
FsRtlTruncateLargeMcb PROTO :QWORD,:QWORD,:QWORD
FsRtlTruncateMcb PROTO :QWORD,:QWORD
FsRtlTryToAcquireHeaderMutex PROTO :QWORD
FsRtlUninitializeBaseMcb PROTO :QWORD
FsRtlUninitializeFileLock PROTO :QWORD
FsRtlUninitializeLargeMcb PROTO :QWORD
FsRtlUninitializeMcb PROTO :QWORD
FsRtlUninitializeOplock PROTO :QWORD
FsRtlUpdateDiskCounters PROTO :QWORD,:QWORD,:QWORD,:QWORD
FsRtlUpperOplockFsctrl PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FsRtlValidateReparsePointBuffer PROTO :QWORD,:QWORD
HalDispatchTable PROTO C :VARARG
HalExamineMBR PROTO :QWORD,:QWORD,:QWORD,:QWORD
HalPrivateDispatchTable PROTO C :VARARG
HeadlessDispatch PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HvlGetLpIndexFromApicId PROTO :QWORD
HvlQueryActiveHypervisorProcessorCount PROTO :QWORD
HvlQueryActiveProcessors PROTO :QWORD,:QWORD
HvlQueryConnection PROTO :QWORD
HvlQueryHypervisorProcessorNodeNumber PROTO :QWORD,:QWORD
HvlQueryNumaDistance PROTO :QWORD,:QWORD,:QWORD
HvlQueryProcessorTopology PROTO :QWORD,:QWORD,:QWORD,:QWORD
HvlQueryProcessorTopologyCount PROTO :QWORD,:QWORD
HvlQueryProcessorTopologyHighestId PROTO :QWORD,:QWORD
HvlRegisterInterruptCallback PROTO :QWORD,:QWORD,:QWORD
HvlRegisterWheaErrorNotification PROTO :QWORD
HvlUnregisterInterruptCallback PROTO :QWORD,:QWORD
HvlUnregisterWheaErrorNotification PROTO :QWORD
InbvAcquireDisplayOwnership PROTO 
InbvCheckDisplayOwnership PROTO 
InbvDisplayString PROTO :QWORD
InbvEnableBootDriver PROTO :QWORD
InbvEnableDisplayString PROTO :QWORD
InbvInstallDisplayStringFilter PROTO :QWORD
InbvIsBootDriverInstalled PROTO 
InbvNotifyDisplayOwnershipChange PROTO :QWORD,:QWORD
InbvNotifyDisplayOwnershipLost PROTO :QWORD
InbvResetDisplay PROTO 
InbvSetScrollRegion PROTO :QWORD,:QWORD,:QWORD,:QWORD
InbvSetTextColor PROTO :QWORD
InbvSolidColorFill PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
InitSafeBootMode PROTO C :VARARG
InterlockedCompareExchange PROTO :QWORD,:QWORD,:QWORD
InterlockedDecrement PROTO :QWORD
InterlockedExchange PROTO :QWORD,:QWORD
InterlockedExchangeAdd PROTO :QWORD,:QWORD
InterlockedIncrement PROTO :QWORD
InterlockedPopEntrySList PROTO :QWORD
InterlockedPushEntrySList PROTO :QWORD,:QWORD
InterlockedPushListSList PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoAcquireCancelSpinLock PROTO :QWORD
IoAcquireRemoveLockEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoAcquireVpbSpinLock PROTO :QWORD
IoAdapterObjectType PROTO C :VARARG
IoAdjustStackSizeForRedirection PROTO :QWORD,:QWORD,:QWORD
IoAllocateAdapterChannel PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoAllocateController PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoAllocateDriverObjectExtension PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoAllocateErrorLogEntry PROTO :QWORD,:QWORD
IoAllocateIrp PROTO :QWORD,:QWORD
IoAllocateMdl PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoAllocateMiniCompletionPacket PROTO :QWORD,:QWORD
IoAllocateSfioStreamIdentifier PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoAllocateWorkItem PROTO :QWORD
IoApplyPriorityInfoThread PROTO :QWORD,:QWORD,:QWORD
IoAssignResources PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoAttachDevice PROTO :QWORD,:QWORD,:QWORD
IoAttachDeviceByPointer PROTO :QWORD,:QWORD
IoAttachDeviceToDeviceStack PROTO :QWORD,:QWORD
IoAttachDeviceToDeviceStackSafe PROTO :QWORD,:QWORD,:QWORD
IoBoostThreadIo PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoBuildAsynchronousFsdRequest PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoBuildDeviceIoControlRequest PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoBuildPartialMdl PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoBuildSynchronousFsdRequest PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoCallDriver PROTO :QWORD,:QWORD
IoCancelFileOpen PROTO :QWORD,:QWORD
IoCancelIrp PROTO :QWORD
IoCheckDesiredAccess PROTO :QWORD,:QWORD
IoCheckEaBufferValidity PROTO :QWORD,:QWORD,:QWORD
IoCheckFunctionAccess PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoCheckQuerySetFileInformation PROTO :QWORD,:QWORD,:QWORD
IoCheckQuerySetVolumeInformation PROTO :QWORD,:QWORD,:QWORD
IoCheckQuotaBufferValidity PROTO :QWORD,:QWORD,:QWORD
IoCheckShareAccess PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoCheckShareAccessEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoClearActivityIdThread PROTO :QWORD
IoClearDependency PROTO :QWORD,:QWORD
IoClearIrpExtraCreateParameter PROTO :QWORD
IoCompleteRequest PROTO :QWORD,:QWORD
IoCompletionObjectType PROTO C :VARARG
IoConnectInterrupt PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoConnectInterruptEx PROTO :QWORD
IoConvertFileHandleToKernelHandle PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoCopyDeviceObjectHint PROTO :QWORD,:QWORD
IoCreateArcName PROTO :QWORD
IoCreateController PROTO :QWORD
IoCreateDevice PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoCreateDisk PROTO :QWORD,:QWORD
IoCreateDriver PROTO :QWORD,:QWORD
IoCreateFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoCreateFileEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoCreateFileSpecifyDeviceObjectHint PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoCreateNotificationEvent PROTO :QWORD,:QWORD
IoCreateStreamFileObject PROTO :QWORD,:QWORD
IoCreateStreamFileObjectEx2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoCreateStreamFileObjectEx PROTO :QWORD,:QWORD,:QWORD
IoCreateStreamFileObjectLite PROTO :QWORD,:QWORD
IoCreateSymbolicLink PROTO :QWORD,:QWORD
IoCreateSynchronizationEvent PROTO :QWORD,:QWORD
IoCreateSystemThread PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoCreateUnprotectedSymbolicLink PROTO :QWORD,:QWORD
IoCsqInitialize PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoCsqInitializeEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoCsqInsertIrp PROTO :QWORD,:QWORD,:QWORD
IoCsqInsertIrpEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoCsqRemoveIrp PROTO :QWORD,:QWORD
IoCsqRemoveNextIrp PROTO :QWORD,:QWORD
IoDecrementKeepAliveCount PROTO :QWORD,:QWORD
IoDeleteAllDependencyRelations PROTO :QWORD
IoDeleteController PROTO :QWORD
IoDeleteDevice PROTO :QWORD
IoDeleteDriver PROTO :QWORD
IoDeleteSymbolicLink PROTO :QWORD
IoDetachDevice PROTO :QWORD
IoDeviceHandlerObjectSize PROTO C :VARARG
IoDeviceHandlerObjectType PROTO C :VARARG
IoDeviceObjectType PROTO C :VARARG
IoDisconnectInterrupt PROTO :QWORD
IoDisconnectInterruptEx PROTO :QWORD
IoDriverObjectType PROTO C :VARARG
IoDuplicateDependency PROTO :QWORD,:QWORD
IoEnqueueIrp PROTO :QWORD
IoEnumerateDeviceObjectList PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoEnumerateRegisteredFiltersList PROTO :QWORD,:QWORD,:QWORD
IoFastQueryNetworkAttributes PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoFileObjectType PROTO C :VARARG
IoForwardAndCatchIrp PROTO :QWORD,:QWORD
IoForwardIrpSynchronously PROTO :QWORD,:QWORD
IoFreeController PROTO :QWORD
IoFreeErrorLogEntry PROTO :QWORD
IoFreeIrp PROTO :QWORD
IoFreeMdl PROTO :QWORD
IoFreeMiniCompletionPacket PROTO :QWORD
IoFreeSfioStreamIdentifier PROTO :QWORD,:QWORD
IoFreeWorkItem PROTO :QWORD
IoGetActivityIdIrp PROTO :QWORD,:QWORD
IoGetActivityIdThread PROTO 
IoGetAffinityInterrupt PROTO :QWORD,:QWORD
IoGetAttachedDevice PROTO :QWORD
IoGetAttachedDeviceReference PROTO :QWORD
IoGetBaseFileSystemDeviceObject PROTO :QWORD
IoGetBootDiskInformation PROTO :QWORD,:QWORD
IoGetBootDiskInformationLite PROTO :QWORD
IoGetConfigurationInformation PROTO 
IoGetContainerInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoGetCurrentProcess PROTO 
IoGetDeviceAttachmentBaseRef PROTO :QWORD
IoGetDeviceInterfaceAlias PROTO :QWORD,:QWORD,:QWORD
IoGetDeviceInterfacePropertyData PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoGetDeviceInterfaces PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoGetDeviceNumaNode PROTO :QWORD,:QWORD
IoGetDeviceObjectPointer PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoGetDeviceProperty PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoGetDevicePropertyData PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoGetDeviceToVerify PROTO :QWORD
IoGetDiskDeviceObject PROTO :QWORD,:QWORD
IoGetDmaAdapter PROTO :QWORD,:QWORD,:QWORD
IoGetDriverObjectExtension PROTO :QWORD,:QWORD
IoGetFileObjectGenericMapping PROTO 
IoGetGenericIrpExtension PROTO :QWORD,:QWORD,:QWORD
IoGetInitialStack PROTO 
IoGetInitiatorProcess PROTO :QWORD
IoGetIoPriorityHint PROTO :QWORD
IoGetIrpExtraCreateParameter PROTO :QWORD,:QWORD
IoGetLowerDeviceObject PROTO :QWORD
IoGetOplockKeyContext PROTO :QWORD
IoGetOplockKeyContextEx PROTO :QWORD
IoGetPagingIoPriority PROTO :QWORD
IoGetRelatedDeviceObject PROTO :QWORD
IoGetRequestorProcess PROTO :QWORD
IoGetRequestorProcessId PROTO :QWORD
IoGetRequestorSessionId PROTO :QWORD,:QWORD
IoGetSfioStreamIdentifier PROTO :QWORD,:QWORD
IoGetStackLimits PROTO :QWORD,:QWORD
IoGetSymlinkSupportInformation PROTO :QWORD,:QWORD
IoGetTopLevelIrp PROTO 
IoGetTransactionParameterBlock PROTO :QWORD
IoIncrementKeepAliveCount PROTO :QWORD,:QWORD
IoInitializeIrp PROTO :QWORD,:QWORD,:QWORD
IoInitializeMiniCompletionPacket PROTO :QWORD,:QWORD,:QWORD
IoInitializeRemoveLockEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoInitializeTimer PROTO :QWORD,:QWORD,:QWORD
IoInitializeWorkItem PROTO :QWORD,:QWORD
IoInvalidateDeviceRelations PROTO :QWORD,:QWORD
IoInvalidateDeviceState PROTO :QWORD
IoIsActivityTracingEnabled PROTO 
IoIsFileObjectIgnoringSharing PROTO :QWORD
IoIsFileOriginRemote PROTO :QWORD
IoIsOperationSynchronous PROTO :QWORD
IoIsSystemThread PROTO :QWORD
IoIsValidIrpStatus PROTO :QWORD
IoIsValidNameGraftingBuffer PROTO :QWORD,:QWORD
IoIsWdmVersionAvailable PROTO :QWORD,:QWORD
IoMakeAssociatedIrp PROTO :QWORD,:QWORD
IoOpenDeviceInterfaceRegistryKey PROTO :QWORD,:QWORD,:QWORD
IoOpenDeviceRegistryKey PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoPageRead PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoPropagateActivityIdToThread PROTO :QWORD,:QWORD,:QWORD
IoPropagateIrpExtension PROTO :QWORD,:QWORD,:QWORD
IoQueryDeviceDescription PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoQueryFileDosDeviceName PROTO :QWORD,:QWORD
IoQueryFileInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoQueryFullDriverPath PROTO :QWORD,:QWORD
IoQueryVolumeInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoQueueThreadIrp PROTO :QWORD
IoQueueWorkItem PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoQueueWorkItemEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoQueueWorkItemToNode PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoRaiseHardError PROTO :QWORD,:QWORD,:QWORD
IoRaiseInformationalHardError PROTO :QWORD,:QWORD,:QWORD
IoReadDiskSignature PROTO :QWORD,:QWORD,:QWORD
IoReadOperationCount PROTO C :VARARG
IoReadPartitionTable PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoReadPartitionTableEx PROTO :QWORD,:QWORD
IoReadTransferCount PROTO C :VARARG
IoRegisterBootDriverCallback PROTO :QWORD,:QWORD
IoRegisterBootDriverReinitialization PROTO :QWORD,:QWORD,:QWORD
IoRegisterContainerNotification PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoRegisterDeviceInterface PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoRegisterDriverReinitialization PROTO :QWORD,:QWORD,:QWORD
IoRegisterFileSystem PROTO :QWORD
IoRegisterFsRegistrationChange PROTO :QWORD,:QWORD
IoRegisterFsRegistrationChangeMountAware PROTO :QWORD,:QWORD,:QWORD
IoRegisterIoTracking PROTO :QWORD,:QWORD
IoRegisterLastChanceShutdownNotification PROTO :QWORD
IoRegisterPlugPlayNotification PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoRegisterPriorityCallback PROTO :QWORD,:QWORD
IoRegisterShutdownNotification PROTO :QWORD
IoReleaseCancelSpinLock PROTO :QWORD
IoReleaseRemoveLockAndWaitEx PROTO :QWORD,:QWORD,:QWORD
IoReleaseRemoveLockEx PROTO :QWORD,:QWORD,:QWORD
IoReleaseVpbSpinLock PROTO :QWORD
IoRemoveShareAccess PROTO :QWORD,:QWORD
IoReplaceFileObjectName PROTO :QWORD,:QWORD,:QWORD
IoReplacePartitionUnit PROTO :QWORD,:QWORD,:QWORD
IoReportDetectedDevice PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoReportHalResourceUsage PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoReportInterruptActive PROTO :QWORD
IoReportInterruptInactive PROTO :QWORD
IoReportResourceForDetection PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoReportResourceUsage PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoReportRootDevice PROTO :QWORD
IoReportTargetDeviceChange PROTO :QWORD,:QWORD
IoReportTargetDeviceChangeAsynchronous PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoRequestDeviceEject PROTO :QWORD
IoRequestDeviceEjectEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoReserveDependency PROTO :QWORD,:QWORD,:QWORD
IoResolveDependency PROTO :QWORD,:QWORD
IoRetrievePriorityInfo PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoReuseIrp PROTO :QWORD,:QWORD
IoSetActivityIdIrp PROTO :QWORD,:QWORD
IoSetActivityIdThread PROTO :QWORD
IoSetCompletionRoutineEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoSetDependency PROTO :QWORD,:QWORD,:QWORD
IoSetDeviceInterfacePropertyData PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoSetDeviceInterfaceState PROTO :QWORD,:QWORD
IoSetDevicePropertyData PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoSetDeviceToVerify PROTO :QWORD,:QWORD
IoSetFileObjectIgnoreSharing PROTO :QWORD
IoSetFileOrigin PROTO :QWORD,:QWORD
IoSetGenericIrpExtension PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoSetHardErrorOrVerifyDevice PROTO :QWORD,:QWORD
IoSetInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoSetIoCompletion PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoSetIoCompletionEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoSetIoPriorityHint PROTO :QWORD,:QWORD
IoSetIoPriorityHintIntoFileObject PROTO :QWORD,:QWORD
IoSetIoPriorityHintIntoThread PROTO :QWORD,:QWORD
IoSetIrpExtraCreateParameter PROTO :QWORD,:QWORD
IoSetMasterIrpStatus PROTO :QWORD,:QWORD
IoSetPartitionInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoSetPartitionInformationEx PROTO :QWORD,:QWORD,:QWORD
IoSetShareAccess PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoSetShareAccessEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoSetStartIoAttributes PROTO :QWORD,:QWORD,:QWORD
IoSetSystemPartition PROTO :QWORD
IoSetThreadHardErrorMode PROTO :QWORD
IoSetTopLevelIrp PROTO :QWORD
IoSizeofGenericIrpExtension PROTO 
IoSizeofWorkItem PROTO 
IoStartNextPacket PROTO :QWORD,:QWORD
IoStartNextPacketByKey PROTO :QWORD,:QWORD,:QWORD
IoStartPacket PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoStartTimer PROTO :QWORD
IoStatisticsLock PROTO C :VARARG
IoStopTimer PROTO :QWORD
IoSynchronousCallDriver PROTO :QWORD,:QWORD
IoSynchronousInvalidateDeviceRelations PROTO :QWORD,:QWORD
IoSynchronousPageWrite PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoTestDependency PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoThreadToProcess PROTO :QWORD
IoTransferActivityId PROTO :QWORD,:QWORD
IoTranslateBusAddress PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoTryQueueWorkItem PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoUninitializeWorkItem PROTO :QWORD
IoUnregisterBootDriverCallback PROTO :QWORD
IoUnregisterContainerNotification PROTO :QWORD
IoUnregisterFileSystem PROTO :QWORD
IoUnregisterFsRegistrationChange PROTO :QWORD,:QWORD
IoUnregisterIoTracking PROTO :QWORD
IoUnregisterPlugPlayNotification PROTO :QWORD
IoUnregisterPlugPlayNotificationEx PROTO :QWORD
IoUnregisterPriorityCallback PROTO :QWORD
IoUnregisterShutdownNotification PROTO :QWORD
IoUpdateShareAccess PROTO :QWORD,:QWORD
IoValidateDeviceIoControlAccess PROTO :QWORD,:QWORD
IoVerifyPartitionTable PROTO :QWORD,:QWORD
IoVerifyVolume PROTO :QWORD,:QWORD
IoVolumeDeviceToDosName PROTO :QWORD,:QWORD
IoVolumeDeviceToGuid PROTO :QWORD,:QWORD
IoVolumeDeviceToGuidPath PROTO :QWORD,:QWORD
IoWMIAllocateInstanceIds PROTO :QWORD,:QWORD,:QWORD
IoWMIDeviceObjectToInstanceName PROTO :QWORD,:QWORD,:QWORD
IoWMIExecuteMethod PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoWMIHandleToInstanceName PROTO :QWORD,:QWORD,:QWORD
IoWMIOpenBlock PROTO :QWORD,:QWORD,:QWORD
IoWMIQueryAllData PROTO :QWORD,:QWORD,:QWORD
IoWMIQueryAllDataMultiple PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoWMIQuerySingleInstance PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoWMIQuerySingleInstanceMultiple PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoWMIRegistrationControl PROTO :QWORD,:QWORD
IoWMISetNotificationCallback PROTO :QWORD,:QWORD,:QWORD
IoWMISetSingleInstance PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoWMISetSingleItem PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoWMISuggestInstanceName PROTO :QWORD,:QWORD,:QWORD,:QWORD
IoWMIWriteEvent PROTO :QWORD
IoWithinStackLimits PROTO :QWORD,:QWORD
IoWriteErrorLogEntry PROTO :QWORD
IoWriteOperationCount PROTO C :VARARG
IoWritePartitionTable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IoWritePartitionTableEx PROTO :QWORD,:QWORD
IoWriteTransferCount PROTO C :VARARG
IofCallDriver PROTO :QWORD,:QWORD
IofCompleteRequest PROTO :QWORD,:QWORD
KdChangeOption PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KdDebuggerEnabled PROTO C :VARARG
KdDebuggerNotPresent PROTO C :VARARG
KdDeregisterPowerHandler PROTO :QWORD
KdDisableDebugger PROTO 
KdEnableDebugger PROTO 
KdEnteredDebugger PROTO C :VARARG
KdPollBreakIn PROTO 
KdPowerTransition PROTO :QWORD
KdRefreshDebuggerNotPresent PROTO 
KdRegisterPowerHandler PROTO :QWORD,:QWORD,:QWORD
KdSystemDebugControl PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
Ke386IoSetAccessProcess PROTO :QWORD,:QWORD
Ke386QueryIoAccessMap PROTO :QWORD,:QWORD
Ke386SetIoAccessMap PROTO :QWORD,:QWORD
KeAcquireGuardedMutex PROTO :QWORD
KeAcquireGuardedMutexUnsafe PROTO :QWORD
KeAcquireInStackQueuedSpinLockAtDpcLevel PROTO :QWORD,:QWORD
KeAcquireInStackQueuedSpinLockForDpc PROTO :QWORD,:QWORD
KeAcquireInterruptSpinLock PROTO :QWORD
KeAcquireSpinLockAtDpcLevel PROTO :QWORD
KeAcquireSpinLockForDpc PROTO :QWORD
KeAddGroupAffinityEx PROTO :QWORD,:QWORD,:QWORD
KeAddProcessorAffinityEx PROTO :QWORD,:QWORD
KeAddProcessorGroupAffinity PROTO :QWORD,:QWORD
KeAddSystemServiceTable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeAlertThread PROTO :QWORD,:QWORD
KeAllocateCalloutStack PROTO :QWORD
KeAllocateCalloutStackEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
KeAndAffinityEx PROTO :QWORD,:QWORD,:QWORD
KeAndGroupAffinityEx PROTO :QWORD,:QWORD,:QWORD
KeAreAllApcsDisabled PROTO 
KeAreApcsDisabled PROTO 
KeAttachProcess PROTO :QWORD
KeBugCheck PROTO :QWORD
KeBugCheckEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeCancelTimer PROTO :QWORD
KeCapturePersistentThreadState PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeCheckProcessorAffinityEx PROTO :QWORD,:QWORD
KeCheckProcessorGroupAffinity PROTO :QWORD,:QWORD
KeClearEvent PROTO :QWORD
KeComplementAffinityEx PROTO :QWORD,:QWORD
KeCopyAffinityEx PROTO :QWORD,:QWORD
KeCountSetBitsAffinityEx PROTO :QWORD
KeCountSetBitsGroupAffinity PROTO :QWORD
KeDelayExecutionThread PROTO :QWORD,:QWORD,:QWORD
KeDeregisterBugCheckCallback PROTO :QWORD
KeDeregisterBugCheckReasonCallback PROTO :QWORD
KeDeregisterNmiCallback PROTO :QWORD
KeDeregisterProcessorChangeCallback PROTO :QWORD
KeDetachProcess PROTO 
KeDispatchSecondaryInterrupt PROTO :QWORD,:QWORD
KeEnterCriticalRegion PROTO 
KeEnterGuardedRegion PROTO 
KeEnterKernelDebugger PROTO 
KeEnumerateNextProcessor PROTO :QWORD,:QWORD
KeExpandKernelStackAndCallout PROTO :QWORD,:QWORD,:QWORD
KeExpandKernelStackAndCalloutEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeFindConfigurationEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD
KeFindConfigurationNextEntry PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeFindFirstSetLeftAffinityEx PROTO :QWORD
KeFindFirstSetLeftGroupAffinity PROTO :QWORD
KeFindFirstSetRightAffinityEx PROTO :QWORD
KeFindFirstSetRightGroupAffinity PROTO :QWORD
KeFirstGroupAffinityEx PROTO :QWORD,:QWORD
KeFlushEntireTb PROTO :QWORD,:QWORD
KeFlushQueuedDpcs PROTO 
KeFreeCalloutStack PROTO :QWORD
KeGenericCallDpc PROTO :QWORD,:QWORD
KeGetCurrentNodeNumber PROTO 
KeGetCurrentProcessorNumberEx PROTO :QWORD
KeGetCurrentThread PROTO 
KeGetPreviousMode PROTO 
KeGetProcessorIndexFromNumber PROTO :QWORD
KeGetProcessorNumberFromIndex PROTO :QWORD,:QWORD
KeGetRecommendedSharedDataAlignment PROTO 
KeGetXSaveFeatureFlags PROTO 
KeHwPolicyLocateResource PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeI386MachineType PROTO C :VARARG
KeInitializeAffinityEx PROTO :QWORD
KeInitializeApc PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeInitializeCrashDumpHeader PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeInitializeDeviceQueue PROTO :QWORD
KeInitializeDpc PROTO :QWORD,:QWORD,:QWORD
KeInitializeEnumerationContext PROTO :QWORD,:QWORD
KeInitializeEnumerationContextFromGroup PROTO :QWORD,:QWORD
KeInitializeEvent PROTO :QWORD,:QWORD,:QWORD
KeInitializeGuardedMutex PROTO :QWORD
KeInitializeInterrupt PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeInitializeMutant PROTO :QWORD,:QWORD
KeInitializeMutex PROTO :QWORD,:QWORD
KeInitializeQueue PROTO :QWORD,:QWORD
KeInitializeSecondaryInterruptServices PROTO :QWORD
KeInitializeSemaphore PROTO :QWORD,:QWORD,:QWORD
KeInitializeSpinLock PROTO :QWORD
KeInitializeThreadedDpc PROTO :QWORD,:QWORD,:QWORD
KeInitializeTimer PROTO :QWORD
KeInitializeTimerEx PROTO :QWORD,:QWORD
KeInsertByKeyDeviceQueue PROTO :QWORD,:QWORD,:QWORD
KeInsertDeviceQueue PROTO :QWORD,:QWORD
KeInsertHeadQueue PROTO :QWORD,:QWORD
KeInsertQueue PROTO :QWORD,:QWORD
KeInsertQueueApc PROTO :QWORD,:QWORD,:QWORD,:QWORD
KeInsertQueueDpc PROTO :QWORD,:QWORD,:QWORD
KeInterlockedClearProcessorAffinityEx PROTO :QWORD,:QWORD
KeInterlockedSetProcessorAffinityEx PROTO :QWORD,:QWORD
KeInvalidateAllCaches PROTO 
KeInvalidateRangeAllCaches PROTO :QWORD,:QWORD
KeIpiGenericCall PROTO :QWORD,:QWORD
KeIsAttachedProcess PROTO 
KeIsEmptyAffinityEx PROTO :QWORD
KeIsEqualAffinityEx PROTO :QWORD,:QWORD
KeIsExecutingDpc PROTO 
KeIsSingleGroupAffinityEx PROTO :QWORD,:QWORD
KeIsSubsetAffinityEx PROTO :QWORD,:QWORD
KeIsWaitListEmpty PROTO :QWORD
KeLeaveCriticalRegion PROTO 
KeLeaveGuardedRegion PROTO 
KeLoaderBlock PROTO C :VARARG
KeNumberProcessors PROTO C :VARARG
KeOrAffinityEx PROTO :QWORD,:QWORD,:QWORD
KePollFreezeExecution PROTO 
KeProcessorGroupAffinity PROTO :QWORD,:QWORD
KeProfileInterruptWithSource PROTO :QWORD,:QWORD
KePulseEvent PROTO :QWORD,:QWORD,:QWORD
KeQueryActiveGroupCount PROTO 
KeQueryActiveProcessorAffinity PROTO :QWORD
KeQueryActiveProcessorCount PROTO :QWORD
KeQueryActiveProcessorCountEx PROTO :QWORD
KeQueryActiveProcessors PROTO 
KeQueryDpcWatchdogInformation PROTO :QWORD
KeQueryEffectivePriorityThread PROTO :QWORD
KeQueryGroupAffinity PROTO :QWORD
KeQueryGroupAffinityEx PROTO :QWORD,:QWORD
KeQueryHardwareCounterConfiguration PROTO :QWORD,:QWORD,:QWORD
KeQueryHighestNodeNumber PROTO 
KeQueryInterruptTime PROTO 
KeQueryInterruptTimePrecise PROTO :QWORD
KeQueryLogicalProcessorRelationship PROTO :QWORD,:QWORD,:QWORD,:QWORD
KeQueryMaximumGroupCount PROTO 
KeQueryMaximumProcessorCount PROTO 
KeQueryMaximumProcessorCountEx PROTO :QWORD
KeQueryNodeActiveAffinity PROTO :QWORD,:QWORD,:QWORD
KeQueryNodeMaximumProcessorCount PROTO :QWORD
KeQueryPriorityThread PROTO :QWORD
KeQueryRuntimeThread PROTO :QWORD,:QWORD
KeQuerySystemTime PROTO :QWORD
KeQuerySystemTimePrecise PROTO :QWORD
KeQueryTickCount PROTO :QWORD
KeQueryTimeIncrement PROTO 
KeQueryTotalCycleTimeThread PROTO :QWORD,:QWORD
KeQueryUnbiasedInterruptTime PROTO 
KeRaiseUserException PROTO :QWORD
KeReadStateEvent PROTO :QWORD
KeReadStateMutant PROTO :QWORD
KeReadStateMutex PROTO :QWORD
KeReadStateQueue PROTO :QWORD
KeReadStateSemaphore PROTO :QWORD
KeReadStateTimer PROTO :QWORD
KeRegisterBugCheckCallback PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeRegisterBugCheckReasonCallback PROTO :QWORD,:QWORD,:QWORD,:QWORD
KeRegisterNmiCallback PROTO :QWORD,:QWORD
KeRegisterProcessorChangeCallback PROTO :QWORD,:QWORD,:QWORD
KeReleaseGuardedMutex PROTO :QWORD
KeReleaseGuardedMutexUnsafe PROTO :QWORD
KeReleaseInStackQueuedSpinLockForDpc PROTO :QWORD
KeReleaseInStackQueuedSpinLockFromDpcLevel PROTO :QWORD
KeReleaseInterruptSpinLock PROTO :QWORD,:QWORD
KeReleaseMutant PROTO :QWORD,:QWORD,:QWORD,:QWORD
KeReleaseMutex PROTO :QWORD,:QWORD
KeReleaseSemaphore PROTO :QWORD,:QWORD,:QWORD,:QWORD
KeReleaseSpinLockForDpc PROTO :QWORD,:QWORD
KeReleaseSpinLockFromDpcLevel PROTO :QWORD
KeRemoveByKeyDeviceQueue PROTO :QWORD,:QWORD
KeRemoveByKeyDeviceQueueIfBusy PROTO :QWORD,:QWORD
KeRemoveDeviceQueue PROTO :QWORD
KeRemoveEntryDeviceQueue PROTO :QWORD,:QWORD
KeRemoveGroupAffinityEx PROTO :QWORD,:QWORD,:QWORD
KeRemoveProcessorAffinityEx PROTO :QWORD,:QWORD
KeRemoveProcessorGroupAffinity PROTO :QWORD,:QWORD
KeRemoveQueue PROTO :QWORD,:QWORD,:QWORD
KeRemoveQueueDpc PROTO :QWORD
KeRemoveQueueDpcEx PROTO :QWORD,:QWORD
KeRemoveQueueEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeRemoveSystemServiceTable PROTO :QWORD
KeResetEvent PROTO :QWORD
KeRestoreExtendedProcessorState PROTO :QWORD
KeRestoreFloatingPointState PROTO :QWORD
KeRevertToUserAffinityThread PROTO 
KeRevertToUserAffinityThreadEx PROTO :QWORD
KeRevertToUserGroupAffinityThread PROTO :QWORD
KeRundownQueue PROTO :QWORD
KeSaveExtendedProcessorState PROTO :QWORD,:QWORD,:QWORD
KeSaveFloatingPointState PROTO :QWORD
KeSaveStateForHibernate PROTO C :VARARG
KeServiceDescriptorTable PROTO C :VARARG
KeSetActualBasePriorityThread PROTO :QWORD,:QWORD
KeSetBasePriorityThread PROTO :QWORD,:QWORD
KeSetCoalescableTimer PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeSetDmaIoCoherency PROTO :QWORD
KeSetEvent PROTO :QWORD,:QWORD,:QWORD
KeSetEventBoostPriority PROTO :QWORD,:QWORD
KeSetHardwareCounterConfiguration PROTO :QWORD,:QWORD
KeSetIdealProcessorThread PROTO :QWORD,:QWORD
KeSetImportanceDpc PROTO :QWORD,:QWORD
KeSetKernelStackSwapEnable PROTO :QWORD
KeSetPriorityThread PROTO :QWORD,:QWORD
KeSetProfileIrql PROTO :QWORD
KeSetSystemAffinityThread PROTO :QWORD
KeSetSystemAffinityThreadEx PROTO :QWORD
KeSetSystemGroupAffinityThread PROTO :QWORD,:QWORD
KeSetTargetProcessorDpc PROTO :QWORD,:QWORD
KeSetTargetProcessorDpcEx PROTO :QWORD,:QWORD
KeSetTimer PROTO :QWORD,:QWORD,:QWORD,:QWORD
KeSetTimerEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeSignalCallDpcDone PROTO :QWORD
KeSignalCallDpcSynchronize PROTO :QWORD
KeStackAttachProcess PROTO :QWORD,:QWORD
KeStartDynamicProcessor PROTO :QWORD,:QWORD,:QWORD,:QWORD
KeSubtractAffinityEx PROTO :QWORD,:QWORD,:QWORD
KeSynchronizeExecution PROTO :QWORD,:QWORD,:QWORD
KeTestAlertThread PROTO :QWORD
KeTestSpinLock PROTO :QWORD
KeTickCount PROTO C :VARARG
KeTryToAcquireGuardedMutex PROTO :QWORD
KeTryToAcquireSpinLockAtDpcLevel PROTO :QWORD
KeUnstackDetachProcess PROTO :QWORD
KeUserModeCallback PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeWaitForMultipleObjects PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeWaitForMutexObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KeWaitForSingleObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KefAcquireSpinLockAtDpcLevel PROTO :QWORD
KefReleaseSpinLockFromDpcLevel PROTO :QWORD
KiAcquireSpinLock PROTO :QWORD
KiBugCheckData PROTO C :VARARG
KiCheckForSListAddress PROTO :QWORD
KiDeliverApc PROTO :QWORD,:QWORD,:QWORD
KiDispatchInterrupt PROTO :QWORD
KiIpiServiceRoutine PROTO :QWORD,:QWORD
KiReleaseSpinLock PROTO :QWORD
KiUnexpectedInterrupt PROTO C :VARARG
KitLogFeatureUsage PROTO :QWORD,:QWORD,:QWORD
KseQueryDeviceData PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
KseQueryDeviceDataList PROTO :QWORD,:QWORD,:QWORD,:QWORD
KseQueryDeviceFlags PROTO :QWORD,:QWORD,:QWORD
KseRegisterShim PROTO :QWORD,:QWORD,:QWORD
KseRegisterShimEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
KseSetDeviceFlags PROTO :QWORD,:QWORD,:QWORD,:QWORD
KseUnregisterShim PROTO :QWORD,:QWORD,:QWORD
LdrAccessResource PROTO :QWORD,:QWORD,:QWORD,:QWORD
LdrEnumResources PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LdrFindResourceDirectory_U PROTO :QWORD,:QWORD,:QWORD,:QWORD
LdrFindResourceEx_U PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LdrFindResource_U PROTO :QWORD,:QWORD,:QWORD,:QWORD
LdrResFindResource PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LdrResFindResourceDirectory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LdrResSearchResource PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LpcPortObjectType PROTO C :VARARG
LpcReplyWaitReplyPort PROTO :QWORD,:QWORD,:QWORD
LpcRequestPort PROTO :QWORD,:QWORD
LpcRequestWaitReplyPort PROTO :QWORD,:QWORD,:QWORD
LpcRequestWaitReplyPortEx PROTO :QWORD,:QWORD,:QWORD
LpcSendWaitReceivePort PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LsaCallAuthenticationPackage PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LsaDeregisterLogonProcess PROTO :QWORD
LsaFreeReturnBuffer PROTO :QWORD
LsaLogonUser PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LsaLookupAuthenticationPackage PROTO :QWORD,:QWORD,:QWORD
LsaRegisterLogonProcess PROTO :QWORD,:QWORD,:QWORD
Mm64BitPhysicalAddress PROTO C :VARARG
MmAddPhysicalMemory PROTO :QWORD,:QWORD
MmAddVerifierThunks PROTO :QWORD,:QWORD
MmAdjustWorkingSetSize PROTO :QWORD,:QWORD,:QWORD,:QWORD
MmAdvanceMdl PROTO :QWORD,:QWORD
MmAllocateContiguousMemory PROTO :QWORD,:QWORD,:QWORD
MmAllocateContiguousMemorySpecifyCache PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmAllocateContiguousMemorySpecifyCacheNode PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmAllocateContiguousNodeMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmAllocateMappingAddress PROTO :QWORD,:QWORD
MmAllocateMdlForIoSpace PROTO :QWORD,:QWORD,:QWORD
MmAllocateNodePagesForMdlEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmAllocateNonCachedMemory PROTO :QWORD
MmAllocatePagesForMdl PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmAllocatePagesForMdlEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmAreMdlPagesCached PROTO :QWORD
MmBadPointer PROTO C :VARARG
MmBuildMdlForNonPagedPool PROTO :QWORD
MmCanFileBeTruncated PROTO :QWORD,:QWORD
MmCommitSessionMappedView PROTO :QWORD,:QWORD
MmCopyMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmCopyVirtualMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmCreateMdl PROTO :QWORD,:QWORD,:QWORD
MmCreateMirror PROTO 
MmCreateSection PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmDisableModifiedWriteOfSection PROTO :QWORD
MmDoesFileHaveUserWritableReferences PROTO :QWORD
MmFlushImageSection PROTO :QWORD,:QWORD
MmForceSectionClosed PROTO :QWORD,:QWORD
MmFreeContiguousMemory PROTO :QWORD
MmFreeContiguousMemorySpecifyCache PROTO :QWORD,:QWORD,:QWORD
MmFreeMappingAddress PROTO :QWORD,:QWORD
MmFreeNonCachedMemory PROTO :QWORD,:QWORD
MmFreePagesFromMdl PROTO :QWORD
MmGetCacheAttribute PROTO :QWORD,:QWORD,:QWORD
MmGetMaximumFileSectionSize PROTO 
MmGetPhysicalAddress PROTO :QWORD
MmGetPhysicalMemoryRanges PROTO 
MmGetSystemRoutineAddress PROTO :QWORD
MmGetVirtualForPhysical PROTO :QWORD,:QWORD
MmHighestUserAddress PROTO C :VARARG
MmIsAddressValid PROTO :QWORD
MmIsDriverSuspectForVerifier PROTO :QWORD
MmIsDriverVerifying PROTO :QWORD
MmIsDriverVerifyingByAddress PROTO :QWORD
MmIsIoSpaceActive PROTO :QWORD,:QWORD,:QWORD
MmIsNonPagedSystemAddressValid PROTO :QWORD
MmIsRecursiveIoFault PROTO 
MmIsThisAnNtAsSystem PROTO 
MmIsVerifierEnabled PROTO :QWORD
MmLockPagableDataSection PROTO :QWORD
MmLockPagableImageSection PROTO :QWORD
MmLockPagableSectionByHandle PROTO :QWORD
MmMapIoSpace PROTO :QWORD,:QWORD,:QWORD,:QWORD
MmMapLockedPages PROTO :QWORD,:QWORD
MmMapLockedPagesSpecifyCache PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmMapLockedPagesWithReservedMapping PROTO :QWORD,:QWORD,:QWORD,:QWORD
MmMapMemoryDumpMdl PROTO :QWORD
MmMapUserAddressesToPage PROTO :QWORD,:QWORD,:QWORD
MmMapVideoDisplay PROTO :QWORD,:QWORD,:QWORD,:QWORD
MmMapViewInSessionSpace PROTO :QWORD,:QWORD,:QWORD
MmMapViewInSessionSpaceEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmMapViewInSystemSpace PROTO :QWORD,:QWORD,:QWORD
MmMapViewInSystemSpaceEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmMapViewOfSection PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmMarkPhysicalMemoryAsBad PROTO :QWORD,:QWORD
MmMarkPhysicalMemoryAsGood PROTO :QWORD,:QWORD
MmMdlPageContentsState PROTO :QWORD,:QWORD
MmMdlPagesAreZero PROTO :QWORD
MmPageEntireDriver PROTO :QWORD
MmPrefetchPages PROTO :QWORD,:QWORD
MmPrefetchVirtualAddresses PROTO :QWORD
MmProbeAndLockPages PROTO :QWORD,:QWORD,:QWORD
MmProbeAndLockProcessPages PROTO :QWORD,:QWORD,:QWORD,:QWORD
MmProbeAndLockSelectedPages PROTO :QWORD,:QWORD,:QWORD,:QWORD
MmProtectMdlSystemAddress PROTO :QWORD,:QWORD
MmQuerySystemSize PROTO 
MmRemovePhysicalMemory PROTO :QWORD,:QWORD
MmResetDriverPaging PROTO :QWORD
MmRotatePhysicalView PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmSectionObjectType PROTO C :VARARG
MmSecureVirtualMemory PROTO :QWORD,:QWORD,:QWORD
MmSetAddressRangeModified PROTO :QWORD,:QWORD
MmSetBankedSection PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MmSizeOfMdl PROTO :QWORD,:QWORD
MmSystemRangeStart PROTO C :VARARG
MmTrimAllSystemPagableMemory PROTO :QWORD
MmUnlockPagableImageSection PROTO :QWORD
MmUnlockPages PROTO :QWORD
MmUnmapIoSpace PROTO :QWORD,:QWORD
MmUnmapLockedPages PROTO :QWORD,:QWORD
MmUnmapReservedMapping PROTO :QWORD,:QWORD,:QWORD
MmUnmapVideoDisplay PROTO :QWORD,:QWORD
MmUnmapViewInSessionSpace PROTO :QWORD
MmUnmapViewInSystemSpace PROTO :QWORD
MmUnmapViewOfSection PROTO :QWORD,:QWORD
MmUnsecureVirtualMemory PROTO :QWORD
MmUserProbeAddress PROTO C :VARARG
NlsAnsiCodePage PROTO C :VARARG
NlsLeadByteInfo PROTO C :VARARG
NlsMbCodePageTag PROTO C :VARARG
NlsMbOemCodePageTag PROTO C :VARARG
NlsOemCodePage PROTO C :VARARG
NlsOemLeadByteInfo PROTO C :VARARG
NtAddAtom PROTO :QWORD,:QWORD,:QWORD
NtAdjustPrivilegesToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtAllocateLocallyUniqueId PROTO :QWORD
NtAllocateUuids PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtAllocateVirtualMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtBuildNumber PROTO C :VARARG
NtClose PROTO :QWORD
NtCommitComplete PROTO :QWORD,:QWORD
NtCommitEnlistment PROTO :QWORD,:QWORD
NtCommitTransaction PROTO :QWORD,:QWORD
NtConnectPort PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtCreateEnlistment PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtCreateEvent PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtCreateFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtCreateResourceManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtCreateSection PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtCreateTransaction PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtCreateTransactionManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtDeleteAtom PROTO :QWORD
NtDeleteFile PROTO :QWORD
NtDeviceIoControlFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtDuplicateObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtDuplicateToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtEnumerateTransactionObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtFindAtom PROTO :QWORD,:QWORD,:QWORD
NtFreeVirtualMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtFreezeTransactions PROTO :QWORD,:QWORD
NtFsControlFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtGetEnvironmentVariableEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtGetNotificationResourceManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtGlobalFlag PROTO C :VARARG
NtLockFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtMakePermanentObject PROTO :QWORD
NtMapViewOfSection PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtNotifyChangeDirectoryFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtOpenEnlistment PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtOpenFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtOpenProcess PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtOpenProcessToken PROTO :QWORD,:QWORD,:QWORD
NtOpenProcessTokenEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtOpenResourceManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtOpenThread PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtOpenThreadToken PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtOpenThreadTokenEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtOpenTransaction PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtOpenTransactionManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtPrePrepareComplete PROTO :QWORD,:QWORD
NtPrePrepareEnlistment PROTO :QWORD,:QWORD
NtPrepareComplete PROTO :QWORD,:QWORD
NtPrepareEnlistment PROTO :QWORD,:QWORD
NtPropagationComplete PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtPropagationFailed PROTO :QWORD,:QWORD,:QWORD
NtQueryDirectoryFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQueryEaFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQueryEnvironmentVariableInfoEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtQueryInformationAtom PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQueryInformationEnlistment PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQueryInformationFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQueryInformationProcess PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQueryInformationResourceManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQueryInformationThread PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQueryInformationToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQueryInformationTransaction PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQueryInformationTransactionManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQueryQuotaInformationFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQuerySecurityAttributesToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQuerySecurityObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQuerySystemInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtQuerySystemInformationEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtQueryVolumeInformationFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtReadFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtReadOnlyEnlistment PROTO :QWORD,:QWORD
NtRecoverEnlistment PROTO :QWORD,:QWORD
NtRecoverResourceManager PROTO :QWORD
NtRecoverTransactionManager PROTO :QWORD
NtRequestPort PROTO :QWORD,:QWORD
NtRequestWaitReplyPort PROTO :QWORD,:QWORD,:QWORD
NtRollbackComplete PROTO :QWORD,:QWORD
NtRollbackEnlistment PROTO :QWORD,:QWORD
NtRollbackTransaction PROTO :QWORD,:QWORD
NtSetCachedSigningLevel PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtSetEaFile PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtSetEvent PROTO :QWORD,:QWORD
NtSetInformationEnlistment PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtSetInformationFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtSetInformationProcess PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtSetInformationResourceManager PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtSetInformationThread PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtSetInformationToken PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtSetInformationTransaction PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtSetInformationVirtualMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtSetQuotaInformationFile PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtSetSecurityObject PROTO :QWORD,:QWORD,:QWORD
NtSetVolumeInformationFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtShutdownSystem PROTO :QWORD
NtThawTransactions PROTO 
NtTraceControl PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtTraceEvent PROTO :QWORD,:QWORD,:QWORD,:QWORD
NtUnlockFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
NtVdmControl PROTO :QWORD,:QWORD
NtWaitForSingleObject PROTO :QWORD,:QWORD,:QWORD
NtWriteFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObAssignSecurity PROTO :QWORD,:QWORD,:QWORD,:QWORD
ObCheckCreateObjectAccess PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObCheckObjectAccess PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObCloseHandle PROTO :QWORD,:QWORD
ObCreateObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObCreateObjectType PROTO :QWORD,:QWORD,:QWORD,:QWORD
ObDeleteCapturedInsertInfo PROTO :QWORD
ObDereferenceObject PROTO :QWORD
ObDereferenceObjectDeferDelete PROTO :QWORD
ObDereferenceObjectDeferDeleteWithTag PROTO :QWORD,:QWORD
ObDereferenceSecurityDescriptor PROTO :QWORD,:QWORD
ObDuplicateObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObFindHandleForObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObGetFilterVersion PROTO 
ObGetObjectSecurity PROTO :QWORD,:QWORD,:QWORD
ObGetObjectType PROTO :QWORD
ObInsertObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObIsDosDeviceLocallyMapped PROTO :QWORD,:QWORD
ObIsKernelHandle PROTO :QWORD
ObLogSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD
ObMakeTemporaryObject PROTO :QWORD
ObOpenObjectByName PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObOpenObjectByPointer PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObOpenObjectByPointerWithTag PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObQueryNameInfo PROTO :QWORD
ObQueryNameString PROTO :QWORD,:QWORD,:QWORD,:QWORD
ObQueryObjectAuditingByHandle PROTO :QWORD,:QWORD
ObReferenceObjectByHandle PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObReferenceObjectByHandleWithTag PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObReferenceObjectByName PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObReferenceObjectByPointer PROTO :QWORD,:QWORD,:QWORD,:QWORD
ObReferenceObjectByPointerWithTag PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObReferenceObjectSafe PROTO :QWORD
ObReferenceObjectSafeWithTag PROTO :QWORD,:QWORD
ObReferenceSecurityDescriptor PROTO :QWORD,:QWORD
ObRegisterCallbacks PROTO :QWORD,:QWORD
ObReleaseObjectSecurity PROTO :QWORD,:QWORD
ObSetHandleAttributes PROTO :QWORD,:QWORD,:QWORD
ObSetSecurityDescriptorInfo PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObSetSecurityObjectByPointer PROTO :QWORD,:QWORD,:QWORD
ObUnRegisterCallbacks PROTO :QWORD
ObWaitForMultipleObjects PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObWaitForSingleObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ObfDereferenceObject PROTO :QWORD
ObfDereferenceObjectWithTag PROTO :QWORD,:QWORD
ObfReferenceObject PROTO :QWORD
ObfReferenceObjectWithTag PROTO :QWORD,:QWORD
POGOBuffer PROTO C :VARARG
PcwAddInstance PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PcwCloseInstance PROTO :QWORD
PcwCreateInstance PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PcwRegister PROTO :QWORD,:QWORD
PcwUnregister PROTO :QWORD
PfFileInfoNotify PROTO :QWORD
PfxFindPrefix PROTO :QWORD,:QWORD
PfxInitialize PROTO :QWORD
PfxInsertPrefix PROTO :QWORD,:QWORD,:QWORD
PfxRemovePrefix PROTO :QWORD,:QWORD
PoCallDriver PROTO :QWORD,:QWORD
PoCancelDeviceNotify PROTO :QWORD
PoClearPowerRequest PROTO :QWORD,:QWORD
PoCreatePowerRequest PROTO :QWORD,:QWORD,:QWORD
PoDeletePowerRequest PROTO :QWORD
PoDisableSleepStates PROTO :QWORD,:QWORD,:QWORD
PoEndDeviceBusy PROTO :QWORD
PoFxActivateComponent PROTO :QWORD,:QWORD,:QWORD
PoFxCompleteDevicePowerNotRequired PROTO :QWORD
PoFxCompleteIdleCondition PROTO :QWORD,:QWORD
PoFxCompleteIdleState PROTO :QWORD,:QWORD
PoFxIdleComponent PROTO :QWORD,:QWORD,:QWORD
PoFxNotifySurprisePowerOn PROTO :QWORD
PoFxPowerControl PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PoFxPowerOnCrashdumpDevice PROTO :QWORD,:QWORD
PoFxProcessorNotification PROTO :QWORD,:QWORD,:QWORD
PoFxRegisterCoreDevice PROTO :QWORD,:QWORD,:QWORD
PoFxRegisterCrashdumpDevice PROTO :QWORD
PoFxRegisterDevice PROTO :QWORD,:QWORD,:QWORD
PoFxRegisterPlugin PROTO :QWORD,:QWORD
PoFxRegisterPluginEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
PoFxRegisterPrimaryDevice PROTO :QWORD,:QWORD,:QWORD
PoFxReportDevicePoweredOn PROTO :QWORD
PoFxSetComponentLatency PROTO :QWORD,:QWORD,:QWORD,:QWORD
PoFxSetComponentResidency PROTO :QWORD,:QWORD,:QWORD,:QWORD
PoFxSetComponentWake PROTO :QWORD,:QWORD,:QWORD
PoFxSetDeviceIdleTimeout PROTO :QWORD,:QWORD,:QWORD
PoFxStartDevicePowerManagement PROTO :QWORD
PoFxUnregisterDevice PROTO :QWORD
PoGetSystemWake PROTO :QWORD
PoLatencySensitivityHint PROTO :QWORD
PoNotifyVSyncChange PROTO :QWORD
PoQueryWatchdogTime PROTO :QWORD,:QWORD
PoQueueShutdownWorkItem PROTO :QWORD
PoReenableSleepStates PROTO :QWORD
PoRegisterCoalescingCallback PROTO :QWORD,:QWORD,:QWORD,:QWORD
PoRegisterDeviceForIdleDetection PROTO :QWORD,:QWORD,:QWORD,:QWORD
PoRegisterDeviceNotify PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PoRegisterPowerSettingCallback PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PoRegisterSystemState PROTO :QWORD,:QWORD
PoRequestPowerIrp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PoRequestShutdownEvent PROTO :QWORD
PoSetDeviceBusyEx PROTO :QWORD
PoSetFixedWakeSource PROTO :QWORD
PoSetHiberRange PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PoSetPowerRequest PROTO :QWORD,:QWORD
PoSetPowerState PROTO :QWORD,:QWORD,:QWORD
PoSetSystemState PROTO :QWORD
PoSetSystemWake PROTO :QWORD
PoSetUserPresent PROTO :QWORD
PoShutdownBugCheck PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PoStartDeviceBusy PROTO :QWORD
PoStartNextPowerIrp PROTO :QWORD
PoUnregisterCoalescingCallback PROTO :QWORD
PoUnregisterPowerSettingCallback PROTO :QWORD
PoUnregisterSystemState PROTO :QWORD
PoUserShutdownCancelled PROTO 
PoUserShutdownInitiated PROTO 
ProbeForRead PROTO :QWORD,:QWORD,:QWORD
ProbeForWrite PROTO :QWORD,:QWORD,:QWORD
PsAcquireProcessExitSynchronization PROTO :QWORD
PsAssignImpersonationToken PROTO :QWORD,:QWORD
PsCaptureUserProcessParameters PROTO :QWORD,:QWORD
PsChargePoolQuota PROTO :QWORD,:QWORD,:QWORD
PsChargeProcessNonPagedPoolQuota PROTO :QWORD,:QWORD
PsChargeProcessPagedPoolQuota PROTO :QWORD,:QWORD
PsChargeProcessPoolQuota PROTO :QWORD,:QWORD,:QWORD
PsChargeProcessWakeCounter PROTO :QWORD,:QWORD,:QWORD,:QWORD
PsCreateSystemThread PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PsCreateSystemThreadEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PsDereferenceImpersonationToken PROTO :QWORD
PsDereferenceKernelStack PROTO :QWORD
PsDereferencePrimaryToken PROTO :QWORD
PsDisableImpersonation PROTO :QWORD,:QWORD
PsEnterPriorityRegion PROTO 
PsEstablishWin32Callouts PROTO :QWORD
PsGetContextThread PROTO :QWORD,:QWORD,:QWORD
PsGetCurrentProcess PROTO 
PsGetCurrentProcessId PROTO 
PsGetCurrentProcessSessionId PROTO 
PsGetCurrentProcessWin32Process PROTO 
PsGetCurrentThread PROTO 
PsGetCurrentThreadId PROTO 
PsGetCurrentThreadPreviousMode PROTO 
PsGetCurrentThreadProcess PROTO 
PsGetCurrentThreadProcessId PROTO 
PsGetCurrentThreadStackBase PROTO 
PsGetCurrentThreadStackLimit PROTO 
PsGetCurrentThreadTeb PROTO 
PsGetCurrentThreadWin32Thread PROTO 
PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion PROTO :QWORD
PsGetJobLock PROTO :QWORD
PsGetJobSessionId PROTO :QWORD
PsGetJobUIRestrictionsClass PROTO :QWORD
PsGetProcessCommonJob PROTO :QWORD,:QWORD
PsGetProcessCreateTimeQuadPart PROTO :QWORD
PsGetProcessDebugPort PROTO :QWORD
PsGetProcessExitProcessCalled PROTO :QWORD
PsGetProcessExitStatus PROTO :QWORD
PsGetProcessExitTime PROTO 
PsGetProcessId PROTO :QWORD
PsGetProcessImageFileName PROTO :QWORD
PsGetProcessInheritedFromUniqueProcessId PROTO :QWORD
PsGetProcessJob PROTO :QWORD
PsGetProcessPeb PROTO :QWORD
PsGetProcessPriorityClass PROTO :QWORD
PsGetProcessProtection PROTO :QWORD
PsGetProcessSectionBaseAddress PROTO :QWORD
PsGetProcessSecurityPort PROTO :QWORD
PsGetProcessSessionId PROTO :QWORD
PsGetProcessSessionIdEx PROTO :QWORD
PsGetProcessSignatureLevel PROTO :QWORD,:QWORD
PsGetProcessWin32Process PROTO :QWORD
PsGetProcessWin32WindowStation PROTO :QWORD
PsGetThreadExitStatus PROTO :QWORD
PsGetThreadFreezeCount PROTO :QWORD
PsGetThreadHardErrorsAreDisabled PROTO :QWORD
PsGetThreadId PROTO :QWORD
PsGetThreadProcess PROTO :QWORD
PsGetThreadProcessId PROTO :QWORD
PsGetThreadSessionId PROTO :QWORD
PsGetThreadTeb PROTO :QWORD
PsGetThreadWin32Thread PROTO :QWORD
PsGetVersion PROTO :QWORD,:QWORD,:QWORD,:QWORD
PsImpersonateClient PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PsInitialSystemProcess PROTO C :VARARG
PsIsCurrentThreadPrefetching PROTO 
PsIsDiskCountersEnabled PROTO 
PsIsProcessBeingDebugged PROTO :QWORD
PsIsProtectedProcess PROTO :QWORD
PsIsProtectedProcessLight PROTO :QWORD
PsIsSystemProcess PROTO :QWORD
PsIsSystemThread PROTO :QWORD
PsIsThreadImpersonating PROTO :QWORD
PsIsThreadTerminating PROTO :QWORD
PsJobType PROTO C :VARARG
PsLeavePriorityRegion PROTO 
PsLookupProcessByProcessId PROTO :QWORD,:QWORD
PsLookupProcessThreadByCid PROTO :QWORD,:QWORD,:QWORD
PsLookupThreadByThreadId PROTO :QWORD,:QWORD
PsProcessType PROTO C :VARARG
PsQueryProcessAttributesByToken PROTO :QWORD,:QWORD,:QWORD
PsQueryProcessExceptionFlags PROTO :QWORD,:QWORD,:QWORD
PsQueryTotalCycleTimeProcess PROTO :QWORD,:QWORD
PsReferenceImpersonationToken PROTO :QWORD,:QWORD,:QWORD,:QWORD
PsReferenceKernelStack PROTO :QWORD
PsReferencePrimaryToken PROTO :QWORD
PsReferenceProcessFilePointer PROTO :QWORD,:QWORD
PsReleaseProcessExitSynchronization PROTO :QWORD
PsReleaseProcessWakeCounter PROTO :QWORD,:QWORD
PsRemoveCreateThreadNotifyRoutine PROTO :QWORD
PsRemoveLoadImageNotifyRoutine PROTO :QWORD
PsRestoreImpersonation PROTO :QWORD,:QWORD
PsResumeProcess PROTO :QWORD
PsReturnPoolQuota PROTO :QWORD,:QWORD,:QWORD
PsReturnProcessNonPagedPoolQuota PROTO :QWORD,:QWORD
PsReturnProcessPagedPoolQuota PROTO :QWORD,:QWORD
PsRevertThreadToSelf PROTO :QWORD
PsRevertToSelf PROTO 
PsSetContextThread PROTO :QWORD,:QWORD,:QWORD
PsSetCreateProcessNotifyRoutine PROTO :QWORD,:QWORD
PsSetCreateProcessNotifyRoutineEx PROTO :QWORD,:QWORD
PsSetCreateThreadNotifyRoutine PROTO :QWORD
PsSetCurrentThreadPrefetching PROTO :QWORD
PsSetLegoNotifyRoutine PROTO :QWORD
PsSetLoadImageNotifyRoutine PROTO :QWORD
PsSetProcessPriorityByClass PROTO :QWORD,:QWORD
PsSetProcessPriorityClass PROTO :QWORD,:QWORD
PsSetProcessSecurityPort PROTO :QWORD,:QWORD
PsSetProcessWin32Process PROTO :QWORD,:QWORD,:QWORD
PsSetProcessWindowStation PROTO :QWORD,:QWORD
PsSetThreadHardErrorsAreDisabled PROTO :QWORD,:QWORD
PsSetThreadWin32Thread PROTO :QWORD,:QWORD,:QWORD
PsSuspendProcess PROTO :QWORD
PsTerminateSystemThread PROTO :QWORD
PsThreadType PROTO C :VARARG
PsUILanguageComitted PROTO C :VARARG
PsUpdateDiskCounters PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PsWrapApcWow64Thread PROTO :QWORD,:QWORD
READ_REGISTER_BUFFER_UCHAR PROTO :QWORD,:QWORD,:QWORD
READ_REGISTER_BUFFER_ULONG PROTO :QWORD,:QWORD,:QWORD
READ_REGISTER_BUFFER_USHORT PROTO :QWORD,:QWORD,:QWORD
READ_REGISTER_UCHAR PROTO :QWORD
READ_REGISTER_ULONG PROTO :QWORD
READ_REGISTER_USHORT PROTO :QWORD
RtlAbsoluteToSelfRelativeSD PROTO :QWORD,:QWORD,:QWORD
RtlAddAccessAllowedAce PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlAddAccessAllowedAceEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlAddAce PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlAddAtomToAtomTable PROTO :QWORD,:QWORD,:QWORD
RtlAddAtomToAtomTableEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlAddRange PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlAddResourceAttributeAce PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlAllocateHeap PROTO :QWORD,:QWORD,:QWORD
RtlAnsiCharToUnicodeChar PROTO :QWORD
RtlAnsiStringToUnicodeSize PROTO :QWORD
RtlAnsiStringToUnicodeString PROTO :QWORD,:QWORD,:QWORD
RtlAppendAsciizToString PROTO :QWORD,:QWORD
RtlAppendStringToString PROTO :QWORD,:QWORD
RtlAppendUnicodeStringToString PROTO :QWORD,:QWORD
RtlAppendUnicodeToString PROTO :QWORD,:QWORD
RtlAreAllAccessesGranted PROTO :QWORD,:QWORD
RtlAreAnyAccessesGranted PROTO :QWORD,:QWORD
RtlAreBitsClear PROTO :QWORD,:QWORD,:QWORD
RtlAreBitsSet PROTO :QWORD,:QWORD,:QWORD
RtlAssert PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlAvlInsertNodeEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlAvlRemoveNode PROTO :QWORD,:QWORD
RtlCaptureContext PROTO :QWORD
RtlCaptureStackBackTrace PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlCharToInteger PROTO :QWORD,:QWORD,:QWORD
RtlCheckPortableOperatingSystem PROTO :QWORD
RtlCheckRegistryKey PROTO :QWORD,:QWORD
RtlCheckTokenCapability PROTO :QWORD,:QWORD,:QWORD
RtlCheckTokenMembership PROTO :QWORD,:QWORD,:QWORD
RtlCheckTokenMembershipEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlClearAllBits PROTO :QWORD
RtlClearBit PROTO :QWORD,:QWORD
RtlClearBits PROTO :QWORD,:QWORD,:QWORD
RtlCmDecodeMemIoResource PROTO :QWORD,:QWORD
RtlCmEncodeMemIoResource PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlCompareAltitudes PROTO :QWORD,:QWORD
RtlCompareMemory PROTO :QWORD,:QWORD,:QWORD
RtlCompareMemoryUlong PROTO :QWORD,:QWORD,:QWORD
RtlCompareString PROTO :QWORD,:QWORD,:QWORD
RtlCompareUnicodeString PROTO :QWORD,:QWORD,:QWORD
RtlCompareUnicodeStrings PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlCompressBuffer PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlCompressChunks PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlComputeCrc32 PROTO :QWORD,:QWORD,:QWORD
RtlContractHashTable PROTO :QWORD
RtlConvertLongToLargeInteger PROTO :QWORD
RtlConvertSidToUnicodeString PROTO :QWORD,:QWORD,:QWORD
RtlConvertUlongToLargeInteger PROTO :QWORD
RtlCopyBitMap PROTO :QWORD,:QWORD,:QWORD
RtlCopyLuid PROTO :QWORD,:QWORD
RtlCopyLuidAndAttributesArray PROTO :QWORD,:QWORD,:QWORD
RtlCopyRangeList PROTO :QWORD,:QWORD
RtlCopySid PROTO :QWORD,:QWORD,:QWORD
RtlCopySidAndAttributesArray PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlCopyString PROTO :QWORD,:QWORD
RtlCopyUnicodeString PROTO :QWORD,:QWORD
RtlCrc32 PROTO :QWORD,:QWORD,:QWORD
RtlCrc64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlCreateAcl PROTO :QWORD,:QWORD,:QWORD
RtlCreateAtomTable PROTO :QWORD,:QWORD
RtlCreateAtomTableEx PROTO :QWORD,:QWORD,:QWORD
RtlCreateHashTable PROTO :QWORD,:QWORD,:QWORD
RtlCreateHashTableEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlCreateHeap PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlCreateRegistryKey PROTO :QWORD,:QWORD
RtlCreateSecurityDescriptor PROTO :QWORD,:QWORD
RtlCreateSystemVolumeInformationFolder PROTO :QWORD
RtlCreateUnicodeString PROTO :QWORD,:QWORD
RtlCreateUserThread PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlCultureNameToLCID PROTO :QWORD,:QWORD
RtlCustomCPToUnicodeN PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlDecompressBuffer PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlDecompressBufferEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlDecompressChunks PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlDecompressFragment PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlDelete PROTO :QWORD
RtlDeleteAce PROTO :QWORD,:QWORD
RtlDeleteAtomFromAtomTable PROTO :QWORD,:QWORD
RtlDeleteElementGenericTable PROTO :QWORD,:QWORD
RtlDeleteElementGenericTableAvl PROTO :QWORD,:QWORD
RtlDeleteElementGenericTableAvlEx PROTO :QWORD,:QWORD
RtlDeleteHashTable PROTO :QWORD
RtlDeleteNoSplay PROTO :QWORD,:QWORD
RtlDeleteOwnersRanges PROTO :QWORD,:QWORD
RtlDeleteRange PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlDeleteRegistryValue PROTO :QWORD,:QWORD,:QWORD
RtlDescribeChunk PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlDestroyAtomTable PROTO :QWORD
RtlDestroyHeap PROTO :QWORD
RtlDowncaseUnicodeChar PROTO :QWORD
RtlDowncaseUnicodeString PROTO :QWORD,:QWORD,:QWORD
RtlDuplicateUnicodeString PROTO :QWORD,:QWORD,:QWORD
RtlEmptyAtomTable PROTO :QWORD,:QWORD
RtlEndEnumerationHashTable PROTO :QWORD,:QWORD
RtlEndWeakEnumerationHashTable PROTO :QWORD,:QWORD
RtlEnlargedIntegerMultiply PROTO :QWORD,:QWORD
RtlEnlargedUnsignedDivide PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlEnlargedUnsignedMultiply PROTO :QWORD,:QWORD
RtlEnumerateEntryHashTable PROTO :QWORD,:QWORD
RtlEnumerateGenericTable PROTO :QWORD,:QWORD
RtlEnumerateGenericTableAvl PROTO :QWORD,:QWORD
RtlEnumerateGenericTableLikeADirectory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlEnumerateGenericTableWithoutSplaying PROTO :QWORD,:QWORD
RtlEnumerateGenericTableWithoutSplayingAvl PROTO :QWORD,:QWORD
RtlEqualLuid PROTO :QWORD,:QWORD
RtlEqualSid PROTO :QWORD,:QWORD
RtlEqualString PROTO :QWORD,:QWORD,:QWORD
RtlEqualUnicodeString PROTO :QWORD,:QWORD,:QWORD
RtlEqualWnfChangeStamps PROTO :QWORD,:QWORD
RtlEthernetAddressToStringA PROTO :QWORD,:QWORD
RtlEthernetAddressToString equ <RtlEthernetAddressToStringA>

RtlEthernetAddressToStringW PROTO :QWORD,:QWORD
RtlEthernetStringToAddressA PROTO :QWORD,:QWORD,:QWORD
RtlEthernetStringToAddress equ <RtlEthernetStringToAddressA>

RtlEthernetStringToAddressW PROTO :QWORD,:QWORD,:QWORD
RtlExpandHashTable PROTO :QWORD
RtlExtendedIntegerMultiply PROTO :QWORD,:QWORD,:QWORD
RtlExtendedLargeIntegerDivide PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlExtendedMagicDivide PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlExtractBitMap PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlFillMemory PROTO :QWORD,:QWORD,:QWORD
RtlFillMemoryUlong PROTO :QWORD,:QWORD,:QWORD
RtlFillMemoryUlonglong PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlFindAceByType PROTO :QWORD,:QWORD,:QWORD
RtlFindClearBits PROTO :QWORD,:QWORD,:QWORD
RtlFindClearBitsAndSet PROTO :QWORD,:QWORD,:QWORD
RtlFindClearRuns PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlFindClosestEncodableLength PROTO :QWORD,:QWORD,:QWORD
RtlFindFirstRunClear PROTO :QWORD,:QWORD
RtlFindLastBackwardRunClear PROTO :QWORD,:QWORD,:QWORD
RtlFindLeastSignificantBit PROTO :QWORD,:QWORD
RtlFindLongestRunClear PROTO :QWORD,:QWORD
RtlFindMessage PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlFindMostSignificantBit PROTO :QWORD,:QWORD
RtlFindNextForwardRunClear PROTO :QWORD,:QWORD,:QWORD
RtlFindRange PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlFindSetBits PROTO :QWORD,:QWORD,:QWORD
RtlFindSetBitsAndClear PROTO :QWORD,:QWORD,:QWORD
RtlFindUnicodePrefix PROTO :QWORD,:QWORD,:QWORD
RtlFormatCurrentUserKeyPath PROTO :QWORD
RtlFormatMessage PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlFreeAnsiString PROTO :QWORD
RtlFreeHeap PROTO :QWORD,:QWORD,:QWORD
RtlFreeOemString PROTO :QWORD
RtlFreeRangeList PROTO :QWORD
RtlFreeUnicodeString PROTO :QWORD
RtlGUIDFromString PROTO :QWORD,:QWORD
RtlGenerate8dot3Name PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlGenerateClass5Guid PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlGetAce PROTO :QWORD,:QWORD,:QWORD
RtlGetAppContainerNamedObjectPath PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlGetAppContainerParent PROTO :QWORD,:QWORD
RtlGetAppContainerSidType PROTO :QWORD,:QWORD
RtlGetCallersAddress PROTO :QWORD,:QWORD
RtlGetCompressionWorkSpaceSize PROTO :QWORD,:QWORD,:QWORD
RtlGetDaclSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlGetDefaultCodePage PROTO :QWORD,:QWORD
RtlGetElementGenericTable PROTO :QWORD,:QWORD
RtlGetElementGenericTableAvl PROTO :QWORD,:QWORD
RtlGetEnabledExtendedFeatures PROTO :QWORD,:QWORD
RtlGetFirstRange PROTO :QWORD,:QWORD,:QWORD
RtlGetGroupSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD
RtlGetIntegerAtom PROTO :QWORD,:QWORD
RtlGetLastRange PROTO :QWORD,:QWORD,:QWORD
RtlGetNextEntryHashTable PROTO :QWORD,:QWORD
RtlGetNextRange PROTO :QWORD,:QWORD,:QWORD
RtlGetNtGlobalFlags PROTO 
RtlGetOwnerSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD
RtlGetProductInfo PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlGetSaclSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlGetSetBootStatusData PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlGetThreadLangIdByIndex PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlGetVersion PROTO :QWORD
RtlHashUnicodeString PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIdnToAscii PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlIdnToNameprepUnicode PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlIdnToUnicode PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlImageDirectoryEntryToData PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlImageNtHeader PROTO :QWORD
RtlImageNtHeaderEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlInitAnsiString PROTO :QWORD,:QWORD
RtlInitAnsiStringEx PROTO :QWORD,:QWORD
RtlInitCodePageTable PROTO :QWORD,:QWORD
RtlInitEnumerationHashTable PROTO :QWORD,:QWORD
RtlInitString PROTO :QWORD,:QWORD
RtlInitUnicodeString PROTO :QWORD,:PTR
RtlInitUnicodeStringEx PROTO :PTR,:QWORD
RtlInitWeakEnumerationHashTable PROTO :QWORD,:QWORD
RtlInitializeBitMap PROTO :QWORD,:QWORD,:QWORD
RtlInitializeGenericTable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlInitializeGenericTableAvl PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlInitializeRangeList PROTO :QWORD
RtlInitializeSid PROTO :QWORD,:QWORD,:QWORD
RtlInitializeUnicodePrefix PROTO :QWORD
RtlInsertElementGenericTable PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlInsertElementGenericTableAvl PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlInsertElementGenericTableFull PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlInsertElementGenericTableFullAvl PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlInsertEntryHashTable PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlInsertUnicodePrefix PROTO :QWORD,:QWORD,:QWORD
RtlInt64ToUnicodeString PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIntegerToChar PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIntegerToUnicode PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIntegerToUnicodeString PROTO :QWORD,:QWORD,:QWORD
RtlInterlockedClearBitRun PROTO :QWORD,:QWORD,:QWORD
RtlInterlockedSetBitRun PROTO :QWORD,:QWORD,:QWORD
RtlInterlockedSetClearRun PROTO :QWORD,:QWORD,:QWORD
RtlInvertRangeList PROTO :QWORD,:QWORD
RtlInvertRangeListEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlIoDecodeMemIoResource PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIoEncodeMemIoResource PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlIpv4AddressToStringA PROTO :QWORD,:QWORD
RtlIpv4AddressToString equ <RtlIpv4AddressToStringA>

RtlIpv4AddressToStringExA PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIpv4AddressToStringEx equ <RtlIpv4AddressToStringExA>

RtlIpv4AddressToStringExW PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIpv4AddressToStringW PROTO :QWORD,:QWORD
RtlIpv4StringToAddressA PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIpv4StringToAddress equ <RtlIpv4StringToAddressA>

RtlIpv4StringToAddressExA PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIpv4StringToAddressEx equ <RtlIpv4StringToAddressExA>

RtlIpv4StringToAddressExW PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIpv4StringToAddressW PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIpv6AddressToStringA PROTO :QWORD,:QWORD
RtlIpv6AddressToString equ <RtlIpv6AddressToStringA>

RtlIpv6AddressToStringExA PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlIpv6AddressToStringEx equ <RtlIpv6AddressToStringExA>

RtlIpv6AddressToStringExW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlIpv6AddressToStringW PROTO :QWORD,:QWORD
RtlIpv6StringToAddressA PROTO :QWORD,:QWORD,:QWORD
RtlIpv6StringToAddress equ <RtlIpv6StringToAddressA>

RtlIpv6StringToAddressExA PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIpv6StringToAddressEx equ <RtlIpv6StringToAddressExA>

RtlIpv6StringToAddressExW PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIpv6StringToAddressW PROTO :QWORD,:QWORD,:QWORD
RtlIsGenericTableEmpty PROTO :QWORD
RtlIsGenericTableEmptyAvl PROTO :QWORD
RtlIsNameLegalDOS8Dot3 PROTO :QWORD,:QWORD,:QWORD
RtlIsNormalizedString PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlIsNtDdiVersionAvailable PROTO :QWORD
RtlIsRangeAvailable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlIsServicePackVersionInstalled PROTO :QWORD
RtlIsUntrustedObject PROTO :QWORD,:QWORD,:QWORD
RtlIsValidOemCharacter PROTO :QWORD
RtlLCIDToCultureName PROTO :QWORD,:QWORD
RtlLargeIntegerAdd PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlLargeIntegerArithmeticShift PROTO :QWORD,:QWORD,:QWORD
RtlLargeIntegerDivide PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlLargeIntegerNegate PROTO :QWORD,:QWORD
RtlLargeIntegerShiftLeft PROTO :QWORD,:QWORD,:QWORD
RtlLargeIntegerShiftRight PROTO :QWORD,:QWORD,:QWORD
RtlLargeIntegerSubtract PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlLengthRequiredSid PROTO :QWORD
RtlLengthSecurityDescriptor PROTO :QWORD
RtlLengthSid PROTO :QWORD
RtlLoadString PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlLocalTimeToSystemTime PROTO :QWORD,:QWORD
RtlLockBootStatusData PROTO :QWORD
RtlLookupAtomInAtomTable PROTO :QWORD,:QWORD,:QWORD
RtlLookupElementGenericTable PROTO :QWORD,:QWORD
RtlLookupElementGenericTableAvl PROTO :QWORD,:QWORD
RtlLookupElementGenericTableFull PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlLookupElementGenericTableFullAvl PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlLookupEntryHashTable PROTO :QWORD,:QWORD,:QWORD
RtlLookupFirstMatchingElementGenericTableAvl PROTO :QWORD,:QWORD,:QWORD
RtlMapGenericMask PROTO :QWORD,:QWORD
RtlMapSecurityErrorToNtStatus PROTO :QWORD
RtlMergeRangeLists PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlMoveMemory PROTO :QWORD,:QWORD,:QWORD
RtlMultiByteToUnicodeN PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlMultiByteToUnicodeSize PROTO :QWORD,:QWORD,:QWORD
RtlNextUnicodePrefix PROTO :QWORD,:QWORD
RtlNormalizeString PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlNtStatusToDosError PROTO :QWORD
RtlNtStatusToDosErrorNoTeb PROTO :QWORD
RtlNumberGenericTableElements PROTO :QWORD
RtlNumberGenericTableElementsAvl PROTO :QWORD
RtlNumberOfClearBits PROTO :QWORD
RtlNumberOfClearBitsInRange PROTO :QWORD,:QWORD,:QWORD
RtlNumberOfSetBits PROTO :QWORD
RtlNumberOfSetBitsInRange PROTO :QWORD,:QWORD,:QWORD
RtlNumberOfSetBitsUlongPtr PROTO :QWORD
RtlOemStringToCountedUnicodeString PROTO :QWORD,:QWORD,:QWORD
RtlOemStringToUnicodeSize PROTO :QWORD
RtlOemStringToUnicodeString PROTO :QWORD,:QWORD,:QWORD
RtlOemToUnicodeN PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlOpenCurrentUser PROTO :QWORD,:QWORD
RtlOwnerAcesPresent PROTO :QWORD
RtlPinAtomInAtomTable PROTO :QWORD,:QWORD
RtlPrefetchMemoryNonTemporal PROTO :QWORD,:QWORD
RtlPrefixString PROTO :QWORD,:QWORD,:QWORD
RtlPrefixUnicodeString PROTO :QWORD,:QWORD,:QWORD
RtlQueryAtomInAtomTable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlQueryDynamicTimeZoneInformation PROTO :QWORD
RtlQueryElevationFlags PROTO :QWORD
RtlQueryInformationAcl PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlQueryModuleInformation PROTO :QWORD,:QWORD,:QWORD
RtlQueryPackageIdentity PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlQueryRegistryValues PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlQueryRegistryValuesEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlQueryTimeZoneInformation PROTO :QWORD
RtlQueryValidationRunlevel PROTO :QWORD
RtlRaiseException PROTO :QWORD
RtlRandom PROTO :QWORD
RtlRandomEx PROTO :QWORD
RtlRbInsertNodeEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlRbRemoveNode PROTO :QWORD,:QWORD
RtlRealPredecessor PROTO :QWORD
RtlRealSuccessor PROTO :QWORD
RtlRemoveEntryHashTable PROTO :QWORD,:QWORD,:QWORD
RtlRemoveUnicodePrefix PROTO :QWORD,:QWORD
RtlReplaceSidInSd PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlReserveChunk PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlRunOnceBeginInitialize PROTO :QWORD,:QWORD,:QWORD
RtlRunOnceComplete PROTO :QWORD,:QWORD,:QWORD
RtlRunOnceExecuteOnce PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlRunOnceInitialize PROTO :QWORD
RtlSecondsSince1970ToTime PROTO :QWORD,:QWORD
RtlSecondsSince1980ToTime PROTO :QWORD,:QWORD
RtlSelfRelativeToAbsoluteSD2 PROTO :QWORD,:QWORD
RtlSelfRelativeToAbsoluteSD PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlSetAllBits PROTO :QWORD
RtlSetBit PROTO :QWORD,:QWORD
RtlSetBits PROTO :QWORD,:QWORD,:QWORD
RtlSetControlSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD
RtlSetDaclSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlSetDynamicTimeZoneInformation PROTO :QWORD
RtlSetGroupSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD
RtlSetOwnerSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD
RtlSetPortableOperatingSystem PROTO :QWORD
RtlSetSaclSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlSetTimeZoneInformation PROTO :QWORD
RtlSidHashInitialize PROTO :QWORD,:QWORD,:QWORD
RtlSidHashLookup PROTO :QWORD,:QWORD
RtlSizeHeap PROTO :QWORD,:QWORD,:QWORD
RtlSplay PROTO :QWORD
RtlStringFromGUID PROTO :QWORD,:QWORD
RtlSubAuthorityCountSid PROTO :QWORD
RtlSubAuthoritySid PROTO :QWORD,:QWORD
RtlSubtreePredecessor PROTO :QWORD
RtlSubtreeSuccessor PROTO :QWORD
RtlSystemTimeToLocalTime PROTO :QWORD,:QWORD
RtlTestBit PROTO :QWORD,:QWORD
RtlTimeFieldsToTime PROTO :QWORD,:QWORD
RtlTimeToElapsedTimeFields PROTO :QWORD,:QWORD
RtlTimeToSecondsSince1970 PROTO :QWORD,:QWORD
RtlTimeToSecondsSince1980 PROTO :QWORD,:QWORD
RtlTimeToTimeFields PROTO :QWORD,:QWORD
RtlTraceDatabaseAdd PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlTraceDatabaseCreate PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlTraceDatabaseDestroy PROTO :QWORD
RtlTraceDatabaseEnumerate PROTO :QWORD,:QWORD,:QWORD
RtlTraceDatabaseFind PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlTraceDatabaseLock PROTO :QWORD
RtlTraceDatabaseUnlock PROTO :QWORD
RtlTraceDatabaseValidate PROTO :QWORD
RtlUTF8ToUnicodeN PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlUlongByteSwap PROTO :QWORD
RtlUlonglongByteSwap PROTO :QWORD,:QWORD
RtlUnicodeStringToAnsiSize PROTO :QWORD
RtlUnicodeStringToAnsiString PROTO :QWORD,:QWORD,:QWORD
RtlUnicodeStringToCountedOemString PROTO :QWORD,:QWORD,:QWORD
RtlUnicodeStringToInteger PROTO :QWORD,:QWORD,:QWORD
RtlUnicodeStringToOemSize PROTO :QWORD
RtlUnicodeStringToOemString PROTO :QWORD,:QWORD,:QWORD
RtlUnicodeToCustomCPN PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlUnicodeToMultiByteN PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlUnicodeToMultiByteSize PROTO :QWORD,:QWORD,:QWORD
RtlUnicodeToOemN PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlUnicodeToUTF8N PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlUnlockBootStatusData PROTO :QWORD
RtlUnwind PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlUpcaseUnicodeChar PROTO :QWORD
RtlUpcaseUnicodeString PROTO :QWORD,:QWORD,:QWORD
RtlUpcaseUnicodeStringToAnsiString PROTO :QWORD,:QWORD,:QWORD
RtlUpcaseUnicodeStringToCountedOemString PROTO :QWORD,:QWORD,:QWORD
RtlUpcaseUnicodeStringToOemString PROTO :QWORD,:QWORD,:QWORD
RtlUpcaseUnicodeToCustomCPN PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlUpcaseUnicodeToMultiByteN PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlUpcaseUnicodeToOemN PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlUpperChar PROTO :QWORD
RtlUpperString PROTO :QWORD,:QWORD
RtlUshortByteSwap PROTO :QWORD
RtlValidRelativeSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD
RtlValidSecurityDescriptor PROTO :QWORD
RtlValidSid PROTO :QWORD
RtlValidateUnicodeString PROTO :QWORD,:QWORD
RtlVerifyVersionInfo PROTO :QWORD,:QWORD,:QWORD,:QWORD
RtlVolumeDeviceToDosName PROTO :QWORD,:QWORD
RtlWalkFrameChain PROTO :QWORD,:QWORD,:QWORD
RtlWeaklyEnumerateEntryHashTable PROTO :QWORD,:QWORD
RtlWriteRegistryValue PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RtlZeroHeap PROTO :QWORD,:QWORD
RtlZeroMemory PROTO :QWORD,:QWORD
RtlxAnsiStringToUnicodeSize PROTO :QWORD
RtlxOemStringToUnicodeSize PROTO :QWORD
RtlxUnicodeStringToAnsiSize PROTO :QWORD
RtlxUnicodeStringToOemSize PROTO :QWORD
SeAccessCheck PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeAccessCheckEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeAccessCheckFromState PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeAccessCheckFromStateEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeAccessCheckWithHint PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeAdjustAccessStateForTrustLabel PROTO :QWORD,:QWORD,:QWORD
SeAppendPrivileges PROTO :QWORD,:QWORD
SeAssignSecurity PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeAssignSecurityEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeAuditHardLinkCreation PROTO :QWORD,:QWORD,:QWORD
SeAuditHardLinkCreationWithTransaction PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeAuditTransactionStateChange PROTO :QWORD,:QWORD,:QWORD
SeAuditingAnyFileEventsWithContext PROTO :QWORD,:QWORD
SeAuditingAnyFileEventsWithContextEx PROTO :QWORD,:QWORD,:QWORD
SeAuditingFileEvents PROTO :QWORD,:QWORD
SeAuditingFileEventsWithContext PROTO :QWORD,:QWORD,:QWORD
SeAuditingFileEventsWithContextEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeAuditingFileOrGlobalEvents PROTO :QWORD,:QWORD,:QWORD
SeAuditingHardLinkEvents PROTO :QWORD,:QWORD
SeAuditingHardLinkEventsWithContext PROTO :QWORD,:QWORD,:QWORD
SeAuditingWithTokenForSubcategory PROTO :QWORD,:QWORD
SeCaptureSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeCaptureSubjectContext PROTO :QWORD
SeCaptureSubjectContextEx PROTO :QWORD,:QWORD,:QWORD
SeCloseObjectAuditAlarm PROTO :QWORD,:QWORD,:QWORD
SeCloseObjectAuditAlarmForNonObObject PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeComputeAutoInheritByObjectType PROTO :QWORD,:QWORD,:QWORD
SeCreateAccessState PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeCreateAccessStateEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeCreateClientSecurity PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeCreateClientSecurityEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeCreateClientSecurityFromSubjectContext PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeCreateClientSecurityFromSubjectContextEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeDeassignSecurity PROTO :QWORD
SeDeleteAccessState PROTO :QWORD
SeDeleteObjectAuditAlarm PROTO :QWORD,:QWORD
SeDeleteObjectAuditAlarmWithTransaction PROTO :QWORD,:QWORD,:QWORD
SeExamineSacl PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeExports PROTO C :VARARG
SeFilterToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeFreePrivileges PROTO :QWORD
SeGetCachedSigningLevel PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeGetLinkedToken PROTO :QWORD,:QWORD,:QWORD
SeGetLogonSessionToken PROTO :QWORD,:QWORD,:QWORD
SeImpersonateClient PROTO :QWORD,:QWORD
SeImpersonateClientEx PROTO :QWORD,:QWORD
SeIsParentOfChildAppContainer PROTO :QWORD,:QWORD,:QWORD
SeLocateProcessImageName PROTO :QWORD,:QWORD
SeLockSubjectContext PROTO :QWORD
SeMarkLogonSessionForTerminationNotification PROTO :QWORD
SeOpenObjectAuditAlarm PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeOpenObjectAuditAlarmForNonObObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeOpenObjectAuditAlarmWithTransaction PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeOpenObjectForDeleteAuditAlarm PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeOpenObjectForDeleteAuditAlarmWithTransaction PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SePrivilegeCheck PROTO :QWORD,:QWORD,:QWORD
SePrivilegeObjectAuditAlarm PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SePublicDefaultDacl PROTO C :VARARG
SeQueryAuthenticationIdToken PROTO :QWORD,:QWORD
SeQueryInformationToken PROTO :QWORD,:QWORD,:QWORD
SeQuerySecureBootPolicyValue PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeQuerySecurityAttributesToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeQuerySecurityDescriptorInfo PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeQuerySessionIdToken PROTO :QWORD,:QWORD
SeRegisterImageVerificationCallback PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeRegisterLogonSessionTerminatedRoutine PROTO :QWORD
SeReleaseSecurityDescriptor PROTO :QWORD,:QWORD,:QWORD
SeReleaseSubjectContext PROTO :QWORD
SeReportSecurityEvent PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeReportSecurityEventWithSubCategory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeSecurityAttributePresent PROTO :QWORD,:QWORD
SeSetAccessStateGenericMapping PROTO :QWORD,:QWORD
SeSetAuditParameter PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeSetSecurityAttributesToken PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeSetSecurityDescriptorInfo PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeSetSecurityDescriptorInfoEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeShouldCheckForAccessRightsFromParent PROTO :QWORD,:QWORD,:QWORD
SeSinglePrivilegeCheck PROTO :QWORD,:QWORD,:QWORD
SeSrpAccessCheck PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SeSystemDefaultDacl PROTO C :VARARG
SeSystemDefaultSd PROTO C :VARARG
SeTokenFromAccessInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD
SeTokenImpersonationLevel PROTO :QWORD
SeTokenIsAdmin PROTO :QWORD
SeTokenIsRestricted PROTO :QWORD
SeTokenIsWriteRestricted PROTO :QWORD
SeTokenObjectType PROTO C :VARARG
SeTokenType PROTO :QWORD
SeUnlockSubjectContext PROTO :QWORD
SeUnregisterImageVerificationCallback PROTO :QWORD
SeUnregisterLogonSessionTerminatedRoutine PROTO :QWORD
SeValidSecurityDescriptor PROTO :QWORD,:QWORD
TmCancelPropagationRequest PROTO :QWORD
TmCommitComplete PROTO :QWORD,:QWORD
TmCommitEnlistment PROTO :QWORD,:QWORD
TmCommitTransaction PROTO :QWORD,:QWORD
TmCreateEnlistment PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
TmCurrentTransaction PROTO :QWORD
TmDereferenceEnlistmentKey PROTO :QWORD,:QWORD
TmEnableCallbacks PROTO :QWORD,:QWORD,:QWORD
TmEndPropagationRequest PROTO :QWORD
TmEnlistmentObjectType PROTO C :VARARG
TmFreezeTransactions PROTO :QWORD,:QWORD,:QWORD
TmGetTransactionId PROTO :QWORD,:QWORD
TmInitSystem PROTO :QWORD,:QWORD,:QWORD,:QWORD
TmInitSystemPhase2 PROTO 
TmInitializeTransactionManager PROTO :QWORD,:QWORD,:QWORD,:QWORD
TmIsKTMCommitCoordinator PROTO :QWORD
TmIsTransactionActive PROTO :QWORD
TmPrePrepareComplete PROTO :QWORD,:QWORD
TmPrePrepareEnlistment PROTO :QWORD,:QWORD
TmPrepareComplete PROTO :QWORD,:QWORD
TmPrepareEnlistment PROTO :QWORD,:QWORD
TmPropagationComplete PROTO :QWORD,:QWORD,:QWORD,:QWORD
TmPropagationFailed PROTO :QWORD,:QWORD,:QWORD
TmReadOnlyEnlistment PROTO :QWORD,:QWORD
TmRecoverEnlistment PROTO :QWORD,:QWORD
TmRecoverResourceManager PROTO :QWORD
TmRecoverTransactionManager PROTO :QWORD,:QWORD
TmReferenceEnlistmentKey PROTO :QWORD,:QWORD
TmRenameTransactionManager PROTO :QWORD,:QWORD
TmRequestOutcomeEnlistment PROTO :QWORD,:QWORD
TmResourceManagerObjectType PROTO C :VARARG
TmRollbackComplete PROTO :QWORD,:QWORD
TmRollbackEnlistment PROTO :QWORD,:QWORD
TmRollbackTransaction PROTO :QWORD,:QWORD
TmSetCurrentTransaction PROTO :QWORD
TmSinglePhaseReject PROTO :QWORD,:QWORD
TmThawTransactions PROTO 
TmTransactionManagerObjectType PROTO C :VARARG
TmTransactionObjectType PROTO C :VARARG
VerSetConditionMask PROTO :QWORD,:QWORD,:QWORD,:QWORD
VfFailDeviceNode PROTO C :VARARG
VfFailDriver PROTO C :VARARG
VfFailSystemBIOS PROTO C :VARARG
VfInsertContext PROTO :QWORD
VfIsVerificationEnabled PROTO :QWORD,:QWORD
VfQueryDeviceContext PROTO :QWORD,:QWORD
VfQueryDispatchTable PROTO :QWORD,:QWORD
VfQueryDriverContext PROTO :QWORD,:QWORD
VfQueryIrpContext PROTO :QWORD,:QWORD
VfQueryThreadContext PROTO :QWORD,:QWORD
VfRemoveContext PROTO :QWORD
WRITE_REGISTER_BUFFER_UCHAR PROTO :QWORD,:QWORD,:QWORD
WRITE_REGISTER_BUFFER_ULONG PROTO :QWORD,:QWORD,:QWORD
WRITE_REGISTER_BUFFER_USHORT PROTO :QWORD,:QWORD,:QWORD
WRITE_REGISTER_UCHAR PROTO :QWORD,:QWORD
WRITE_REGISTER_ULONG PROTO :QWORD,:QWORD
WRITE_REGISTER_USHORT PROTO :QWORD,:QWORD
WheaAddErrorSource PROTO :QWORD,:QWORD
WheaConfigureErrorSource PROTO :QWORD,:QWORD
WheaGetErrorSource PROTO :QWORD
WheaInitializeRecordHeader PROTO :QWORD
WheaReportHwError PROTO :QWORD
WmiGetClock PROTO :QWORD,:QWORD
WmiQueryTraceInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
WmiTraceMessage PROTO C :VARARG
WmiTraceMessageVa PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
XIPDispatch PROTO :QWORD,:QWORD,:QWORD
ZwAccessCheckAndAuditAlarm PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwAddBootEntry PROTO :QWORD,:QWORD
ZwAddDriverEntry PROTO :QWORD,:QWORD
ZwAdjustPrivilegesToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwAlertThread PROTO :QWORD
ZwAllocateLocallyUniqueId PROTO :QWORD
ZwAllocateVirtualMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwAlpcAcceptConnectPort PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwAlpcCancelMessage PROTO :QWORD,:QWORD,:QWORD
ZwAlpcConnectPort PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwAlpcConnectPortEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwAlpcCreatePort PROTO :QWORD,:QWORD,:QWORD
ZwAlpcCreatePortSection PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwAlpcCreateResourceReserve PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwAlpcCreateSectionView PROTO :QWORD,:QWORD,:QWORD
ZwAlpcCreateSecurityContext PROTO :QWORD,:QWORD,:QWORD
ZwAlpcDeletePortSection PROTO :QWORD,:QWORD,:QWORD
ZwAlpcDeleteResourceReserve PROTO :QWORD,:QWORD,:QWORD
ZwAlpcDeleteSectionView PROTO :QWORD,:QWORD,:QWORD
ZwAlpcDeleteSecurityContext PROTO :QWORD,:QWORD,:QWORD
ZwAlpcDisconnectPort PROTO :QWORD,:QWORD
ZwAlpcQueryInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwAlpcSendWaitReceivePort PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwAlpcSetInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwAssignProcessToJobObject PROTO :QWORD,:QWORD
ZwAssociateWaitCompletionPacket PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwCancelIoFile PROTO :QWORD,:QWORD
ZwCancelIoFileEx PROTO :QWORD,:QWORD,:QWORD
ZwCancelTimer PROTO :QWORD,:QWORD
ZwClearEvent PROTO :QWORD
ZwClose PROTO :QWORD
ZwCloseObjectAuditAlarm PROTO :QWORD,:QWORD,:QWORD
ZwCommitComplete PROTO :QWORD,:QWORD
ZwCommitEnlistment PROTO :QWORD,:QWORD
ZwCommitTransaction PROTO :QWORD,:QWORD
ZwConnectPort PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwCreateDirectoryObject PROTO :QWORD,:QWORD,:QWORD
ZwCreateEnlistment PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwCreateEvent PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwCreateFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwCreateIoCompletion PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwCreateJobObject PROTO :QWORD,:QWORD,:QWORD
ZwCreateKey PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwCreateKeyTransacted PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwCreateResourceManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwCreateSection PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwCreateSymbolicLinkObject PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwCreateTimer PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwCreateTransaction PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwCreateTransactionManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwCreateUserProcess PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwCreateWaitCompletionPacket PROTO :QWORD,:QWORD,:QWORD
ZwCreateWnfStateName PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwDeleteBootEntry PROTO :QWORD
ZwDeleteDriverEntry PROTO :QWORD
ZwDeleteFile PROTO :QWORD
ZwDeleteKey PROTO :QWORD
ZwDeleteValueKey PROTO :QWORD,:QWORD
ZwDeleteWnfStateData PROTO :QWORD,:QWORD
ZwDeleteWnfStateName PROTO :QWORD
ZwDeviceIoControlFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwDisplayString PROTO :QWORD
ZwDuplicateObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwDuplicateToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwEnumerateBootEntries PROTO :QWORD,:QWORD
ZwEnumerateDriverEntries PROTO :QWORD,:QWORD
ZwEnumerateKey PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwEnumerateTransactionObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwEnumerateValueKey PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwFlushBuffersFile PROTO :QWORD,:QWORD
ZwFlushBuffersFileEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwFlushInstructionCache PROTO :QWORD,:QWORD,:QWORD
ZwFlushKey PROTO :QWORD
ZwFlushVirtualMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwFreeVirtualMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwFsControlFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwGetNotificationResourceManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwImpersonateAnonymousToken PROTO :QWORD
ZwInitiatePowerAction PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwIsProcessInJob PROTO :QWORD,:QWORD
ZwLoadDriver PROTO :QWORD
ZwLoadKey PROTO :QWORD,:QWORD
ZwLoadKeyEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwLockFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwLockProductActivationKeys PROTO :QWORD,:QWORD
ZwLockVirtualMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwMakeTemporaryObject PROTO :QWORD
ZwMapViewOfSection PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwModifyBootEntry PROTO :QWORD
ZwModifyDriverEntry PROTO :QWORD
ZwNotifyChangeKey PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwNotifyChangeSession PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwOpenDirectoryObject PROTO :QWORD,:QWORD,:QWORD
ZwOpenEnlistment PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwOpenEvent PROTO :QWORD,:QWORD,:QWORD
ZwOpenFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwOpenJobObject PROTO :QWORD,:QWORD,:QWORD
ZwOpenKey PROTO :QWORD,:QWORD,:QWORD
ZwOpenKeyEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwOpenKeyTransacted PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwOpenKeyTransactedEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwOpenProcess PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwOpenProcessToken PROTO :QWORD,:QWORD,:QWORD
ZwOpenProcessTokenEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwOpenResourceManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwOpenSection PROTO :QWORD,:QWORD,:QWORD
ZwOpenSession PROTO :QWORD,:QWORD,:QWORD
ZwOpenSymbolicLinkObject PROTO :QWORD,:QWORD,:QWORD
ZwOpenThread PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwOpenThreadToken PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwOpenThreadTokenEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwOpenTimer PROTO :QWORD,:QWORD,:QWORD
ZwOpenTransaction PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwOpenTransactionManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwPowerInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwPrePrepareComplete PROTO :QWORD,:QWORD
ZwPrePrepareEnlistment PROTO :QWORD,:QWORD
ZwPrepareComplete PROTO :QWORD,:QWORD
ZwPrepareEnlistment PROTO :QWORD,:QWORD
ZwPropagationComplete PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwPropagationFailed PROTO :QWORD,:QWORD,:QWORD
ZwProtectVirtualMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwPulseEvent PROTO :QWORD,:QWORD
ZwQueryBootEntryOrder PROTO :QWORD,:QWORD
ZwQueryBootOptions PROTO :QWORD,:QWORD
ZwQueryDefaultLocale PROTO :QWORD,:QWORD
ZwQueryDefaultUILanguage PROTO :QWORD
ZwQueryDirectoryFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryDirectoryObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryDriverEntryOrder PROTO :QWORD,:QWORD
ZwQueryEaFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryFullAttributesFile PROTO :QWORD,:QWORD
ZwQueryInformationEnlistment PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryInformationFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryInformationJobObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryInformationProcess PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryInformationResourceManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryInformationThread PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryInformationToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryInformationTransaction PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryInformationTransactionManager PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryInstallUILanguage PROTO :QWORD
ZwQueryKey PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryLicenseValue PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryQuotaInformationFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQuerySection PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQuerySecurityAttributesToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQuerySecurityObject PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQuerySymbolicLinkObject PROTO :QWORD,:QWORD,:QWORD
ZwQuerySystemEnvironmentValueEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQuerySystemInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwQuerySystemInformationEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryValueKey PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryVirtualMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryVolumeInformationFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryWnfStateData PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwQueryWnfStateNameInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwReadFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwReadOnlyEnlistment PROTO :QWORD,:QWORD
ZwRecoverEnlistment PROTO :QWORD,:QWORD
ZwRecoverResourceManager PROTO :QWORD
ZwRecoverTransactionManager PROTO :QWORD
ZwRemoveIoCompletion PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwRemoveIoCompletionEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwRenameKey PROTO :QWORD,:QWORD
ZwReplaceKey PROTO :QWORD,:QWORD,:QWORD
ZwRequestPort PROTO :QWORD,:QWORD
ZwRequestWaitReplyPort PROTO :QWORD,:QWORD,:QWORD
ZwResetEvent PROTO :QWORD,:QWORD
ZwRestoreKey PROTO :QWORD,:QWORD,:QWORD
ZwRollbackComplete PROTO :QWORD,:QWORD
ZwRollbackEnlistment PROTO :QWORD,:QWORD
ZwRollbackTransaction PROTO :QWORD,:QWORD
ZwSaveKey PROTO :QWORD,:QWORD
ZwSaveKeyEx PROTO :QWORD,:QWORD,:QWORD
ZwSecureConnectPort PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwSetBootEntryOrder PROTO :QWORD,:QWORD
ZwSetBootOptions PROTO :QWORD,:QWORD
ZwSetCachedSigningLevel PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwSetDefaultLocale PROTO :QWORD,:QWORD
ZwSetDefaultUILanguage PROTO :QWORD
ZwSetDriverEntryOrder PROTO :QWORD,:QWORD
ZwSetEaFile PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwSetEvent PROTO :QWORD,:QWORD
ZwSetInformationEnlistment PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwSetInformationFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwSetInformationJobObject PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwSetInformationKey PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwSetInformationObject PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwSetInformationProcess PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwSetInformationResourceManager PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwSetInformationThread PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwSetInformationToken PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwSetInformationTransaction PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwSetInformationVirtualMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwSetQuotaInformationFile PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwSetSecurityObject PROTO :QWORD,:QWORD,:QWORD
ZwSetSystemEnvironmentValueEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwSetSystemInformation PROTO :QWORD,:QWORD,:QWORD
ZwSetSystemTime PROTO :QWORD,:QWORD
ZwSetTimer PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwSetTimerEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwSetValueKey PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwSetVolumeInformationFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwTerminateJobObject PROTO :QWORD,:QWORD
ZwTerminateProcess PROTO :QWORD,:QWORD
ZwTraceEvent PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwTranslateFilePath PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwUnloadDriver PROTO :QWORD
ZwUnloadKey PROTO :QWORD
ZwUnloadKeyEx PROTO :QWORD,:QWORD
ZwUnlockFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwUnlockVirtualMemory PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZwUnmapViewOfSection PROTO :QWORD,:QWORD
ZwUpdateWnfStateData PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwWaitForMultipleObjects PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwWaitForSingleObject PROTO :QWORD,:QWORD,:QWORD
ZwWriteFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZwYieldExecution PROTO 
_CIcos PROTO C :VARARG
_CIsin PROTO C :VARARG
_CIsqrt PROTO C :VARARG
_EH4_CallFilterFunc PROTO :QWORD,:QWORD
_EH4_GlobalUnwind PROTO :QWORD
_EH4_LocalUnwind PROTO :QWORD,:QWORD,:QWORD,:QWORD
_EH4_TransferToHandler PROTO :QWORD,:QWORD
_NLG_Call PROTO C :VARARG
_NLG_Destination PROTO C :VARARG
_NLG_Dispatch PROTO C :VARARG
_NLG_Dispatch2 PROTO C :VARARG
_NLG_Notify PROTO C :VARARG
_NLG_Notify1 PROTO C :VARARG
_NLG_Return2 PROTO C :VARARG
_SEH_epilog PROTO C :VARARG
_SEH_epilog4 PROTO C :VARARG
_SEH_epilog4_GS PROTO C :VARARG
_SEH_prolog PROTO C :VARARG
_SEH_prolog4 PROTO C :VARARG
_SEH_prolog4_GS PROTO C :VARARG
__except_validate_context_record PROTO C :VARARG
__except_validate_jump_buffer PROTO C :VARARG
__guard_check_icall_fptr PROTO C :VARARG
_abnormal_termination PROTO C :VARARG
_alldiv PROTO C :VARARG
_alldvrm PROTO C :VARARG
_allmul PROTO C :VARARG
_alloca_probe PROTO C :VARARG
_alloca_probe_16 PROTO C :VARARG
_alloca_probe_8 PROTO C :VARARG
_allrem PROTO C :VARARG
_allshl PROTO C :VARARG
_allshr PROTO C :VARARG
_aulldiv PROTO C :VARARG
_aulldvrm PROTO C :VARARG
_aullrem PROTO C :VARARG
_aullshr PROTO C :VARARG
_chkstk PROTO C :VARARG
_except_handler2 PROTO C :VARARG
_except_handler3 PROTO C :VARARG
_except_handler4 PROTO C :VARARG
_except_list PROTO C :VARARG
_global_unwind2 PROTO C :VARARG
_guard_check_icall PROTO :QWORD
_guard_check_icall_nop PROTO :QWORD
_guard_icall_checks_enforced PROTO C :VARARG
_i64toa_s PROTO C :VARARG
_i64tow_s PROTO C :VARARG
_invalid_parameter PROTO C :VARARG
_itoa PROTO C :VARARG
_itoa_s PROTO C :VARARG
_itow PROTO C :VARARG
_itow_s PROTO C :VARARG
_load_config_used PROTO C :VARARG
_local_unwind2 PROTO C :VARARG
_local_unwind4 PROTO C :VARARG
_ltoa_s PROTO C :VARARG
_ltow_s PROTO C :VARARG
_makepath_s PROTO C :VARARG
_purecall PROTO C :VARARG
_seh_longjmp_unwind4 PROTO :QWORD
_snprintf PROTO C :VARARG
_snprintf_s PROTO C :VARARG
_snscanf_s PROTO C :VARARG
_snwprintf PROTO C :VARARG
_snwprintf_s PROTO C :VARARG
_snwscanf_s PROTO C :VARARG
_splitpath_s PROTO C :VARARG
_stricmp PROTO C :VARARG
_strlwr PROTO C :VARARG
_strnicmp PROTO C :VARARG
_strnset PROTO C :VARARG
_strnset_s PROTO C :VARARG
_strrev PROTO C :VARARG
_strset PROTO C :VARARG
_strset_s PROTO C :VARARG
_strtoui64 PROTO C :VARARG
_strupr PROTO C :VARARG
_swprintf PROTO C :VARARG
_ui64toa_s PROTO C :VARARG
_ui64tow_s PROTO C :VARARG
_ultoa_s PROTO C :VARARG
_ultow_s PROTO C :VARARG
_vsnprintf PROTO C :VARARG
_vsnprintf_s PROTO C :VARARG
_vsnwprintf PROTO C :VARARG
_vsnwprintf_s PROTO C :VARARG
_vswprintf PROTO C :VARARG
_wcsicmp PROTO C :VARARG
_wcslwr PROTO C :VARARG
_wcsnicmp PROTO C :VARARG
_wcsnset PROTO C :VARARG
_wcsnset_s PROTO C :VARARG
_wcsrev PROTO C :VARARG
_wcsset_s PROTO C :VARARG
_wcsupr PROTO C :VARARG
_wmakepath_s PROTO C :VARARG
_wsplitpath_s PROTO C :VARARG
_wtoi PROTO C :VARARG
_wtol PROTO C :VARARG
atoi PROTO C :VARARG
atol PROTO C :VARARG
bsearch PROTO C :VARARG
bsearch_s PROTO C :VARARG
isdigit PROTO C :VARARG
islower PROTO C :VARARG
isprint PROTO C :VARARG
isspace PROTO C :VARARG
isupper PROTO C :VARARG
isxdigit PROTO C :VARARG
mbstowcs PROTO C :VARARG
mbtowc PROTO C :VARARG
memchr PROTO C :VARARG
memcmp PROTO C :VARARG
memcpy PROTO C :VARARG
memcpy_s PROTO C :VARARG
memmove PROTO C :VARARG
memmove_s PROTO C :VARARG
memset PROTO C :VARARG
psMUITest PROTO C :VARARG
qsort PROTO C :VARARG
rand PROTO C :VARARG
sprintf PROTO C :VARARG
sprintf_s PROTO C :VARARG
srand PROTO C :VARARG
sscanf_s PROTO C :VARARG
strcat PROTO C :VARARG
strcat_s PROTO C :VARARG
strchr PROTO C :VARARG
strcmp PROTO C :VARARG
strcpy PROTO C :VARARG
strcpy_s PROTO C :VARARG
strlen PROTO C :VARARG
strncat PROTO C :VARARG
strncat_s PROTO C :VARARG
strncmp PROTO C :VARARG
strncpy PROTO C :VARARG
strncpy_s PROTO C :VARARG
strnlen PROTO C :VARARG
strrchr PROTO C :VARARG
strspn PROTO C :VARARG
strstr PROTO C :VARARG
strtok_s PROTO C :VARARG
swprintf PROTO C :VARARG
swprintf_s PROTO C :VARARG
swscanf_s PROTO C :VARARG
tolower PROTO C :VARARG
toupper PROTO C :VARARG
towlower PROTO C :VARARG
towupper PROTO C :VARARG
vDbgPrintEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
vDbgPrintExWithPrefix PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
vsprintf PROTO C :VARARG
vsprintf_s PROTO C :VARARG
vswprintf_s PROTO C :VARARG
wcscat PROTO C :VARARG
wcscat_s PROTO C :VARARG
wcschr PROTO C :VARARG
wcscmp PROTO C :VARARG
wcscpy PROTO C :VARARG
wcscpy_s PROTO C :VARARG
wcscspn PROTO C :VARARG
wcslen PROTO C :VARARG
wcsncat PROTO C :VARARG
wcsncat_s PROTO C :VARARG
wcsncmp PROTO C :VARARG
wcsncpy PROTO C :VARARG
wcsncpy_s PROTO C :VARARG
wcsnlen PROTO C :VARARG
wcsrchr PROTO C :VARARG
wcsspn PROTO C :VARARG
wcsstr PROTO C :VARARG
wcstombs PROTO C :VARARG
wcstoul PROTO C :VARARG
wctomb PROTO C :VARARG
