;========================================================================
; Windows Driver Framework (WDF) for UASM x64
; 
; Converted from wdfxxxxxxx.h to asm format 
; for KMDF64 by fearless
;    
;========================================================================

include wdfdriverentry.inc
include wdfldr.inc


;-------------------------------------------------------------------------
; wdftypes.h
;-------------------------------------------------------------------------
WDFAPI equ <>

WDF_TRI_STATE typedef SDWORD
WdfFalse EQU FALSE 
WdfTrue EQU TRUE 
WdfUseDefault EQU 2 

PWDF_TRI_STATE typedef ptr WDF_TRI_STATE

WDFCONTEXT typedef PVOID
PWDFDEVICE_INIT typedef ptr WDFDEVICE_INIT
;PINTERFACE typedef QWORD
PWDF_OBJECT_ATTRIBUTES typedef ptr WDF_OBJECT_ATTRIBUTES

DEVICE_RELATION_TYPE typedef SDWORD
DEVICE_POWER_STATE typedef SDWORD
SYSTEM_POWER_STATE typedef SDWORD
DEVICE_REGISTRY_PROPERTY typedef SDWORD
KINTERRUPT_MODE typedef SDWORD

WDF_NO_OBJECT_ATTRIBUTES equ <( NULL )>
WDF_NO_EVENT_CALLBACK equ <( NULL )>
WDF_NO_HANDLE equ <( NULL )>
WDF_NO_CONTEXT equ <( NULL )>
WDF_NO_SEND_OPTIONS equ <( NULL )>

IFNDEF size_t
size_t TYPEDEF QWORD
ENDIF

IFNDEF POINTER_ALIGNMENT
POINTER_ALIGNMENT TYPEDEF POINTER
ENDIF



USBD_STATUS TYPEDEF LONG

PULONG_PTR TYPEDEF POINTER

LPGUID typedef PTR GUID
LPCGUID typedef PTR GUID

WDFOBJECT typedef HANDLE
PWDFOBJECT typedef ptr HANDLE
WDFDRIVER typedef HANDLE
WDFDEVICE typedef HANDLE
WDFWMIPROVIDER typedef HANDLE
WDFWMIINSTANCE typedef HANDLE
WDFQUEUE typedef HANDLE
WDFREQUEST typedef HANDLE
WDFFILEOBJECT typedef HANDLE
WDFDPC typedef HANDLE
WDFTIMER typedef HANDLE
WDFWORKITEM typedef HANDLE
WDFINTERRUPT typedef HANDLE
WDFWAITLOCK typedef HANDLE
WDFSPINLOCK typedef HANDLE
WDFMEMORY typedef HANDLE
WDFLOOKASIDE typedef HANDLE
WDFIOTARGET typedef HANDLE
WDFUSBDEVICE typedef HANDLE
WDFUSBINTERFACE typedef HANDLE
WDFUSBPIPE typedef HANDLE
WDFDMAENABLER typedef HANDLE
WDFDMATRANSACTION typedef HANDLE
WDFCOMMONBUFFER typedef HANDLE
WDFKEY typedef HANDLE
WDFSTRING typedef HANDLE
WDFCOLLECTION typedef HANDLE
WDFCHILDLIST typedef HANDLE
WDFIORESREQLIST typedef HANDLE
WDFIORESLIST typedef HANDLE
WDFCMRESLIST typedef HANDLE


;-------------------------------------------------------------------------
; wdfglobals.h
;-------------------------------------------------------------------------
WDF_DRIVER_GLOBALS_NAME_LEN equ 32
WDF_DRIVER_GLOBALS struct
    Driver WDFDRIVER ?
    DriverFlags DWORD ?
    DriverTag DWORD ?
    DriverName CHAR WDF_DRIVER_GLOBALS_NAME_LEN dup (?)
    DisplaceDriverUnload BOOLEAN ?
WDF_DRIVER_GLOBALS ends

PWDF_DRIVER_GLOBALS typedef ptr WDF_DRIVER_GLOBALS


;-------------------------------------------------------------------------
; wdffuncenum.h
;-------------------------------------------------------------------------
WDFFUNCENUM typedef SDWORD
WdfChildListCreateTableIndex EQU 0 
WdfChildListGetDeviceTableIndex EQU 1 
WdfChildListRetrievePdoTableIndex EQU 2 
WdfChildListRetrieveAddressDescriptionTableIndex EQU 3 
WdfChildListBeginScanTableIndex EQU 4 
WdfChildListEndScanTableIndex EQU 5 
WdfChildListBeginIterationTableIndex EQU 6 
WdfChildListRetrieveNextDeviceTableIndex EQU 7 
WdfChildListEndIterationTableIndex EQU 8 
WdfChildListAddOrUpdateChildDescriptionAsPresentTableIndex EQU 9 
WdfChildListUpdateChildDescriptionAsMissingTableIndex EQU 10 
WdfChildListUpdateAllChildDescriptionsAsPresentTableIndex EQU 11 
WdfChildListRequestChildEjectTableIndex EQU 12 
WdfCollectionCreateTableIndex EQU 13 
WdfCollectionGetCountTableIndex EQU 14 
WdfCollectionAddTableIndex EQU 15 
WdfCollectionRemoveTableIndex EQU 16 
WdfCollectionRemoveItemTableIndex EQU 17 
WdfCollectionGetItemTableIndex EQU 18 
WdfCollectionGetFirstItemTableIndex EQU 19 
WdfCollectionGetLastItemTableIndex EQU 20 
WdfCommonBufferCreateTableIndex EQU 21 
WdfCommonBufferGetAlignedVirtualAddressTableIndex EQU 22 
WdfCommonBufferGetAlignedLogicalAddressTableIndex EQU 23 
WdfCommonBufferGetLengthTableIndex EQU 24 
WdfControlDeviceInitAllocateTableIndex EQU 25 
WdfControlDeviceInitSetShutdownNotificationTableIndex EQU 26 
WdfControlFinishInitializingTableIndex EQU 27 
WdfDeviceGetDeviceStateTableIndex EQU 28 
WdfDeviceSetDeviceStateTableIndex EQU 29 
WdfWdmDeviceGetWdfDeviceHandleTableIndex EQU 30 
WdfDeviceWdmGetDeviceObjectTableIndex EQU 31 
WdfDeviceWdmGetAttachedDeviceTableIndex EQU 32 
WdfDeviceWdmGetPhysicalDeviceTableIndex EQU 33 
WdfDeviceWdmDispatchPreprocessedIrpTableIndex EQU 34 
WdfDeviceAddDependentUsageDeviceObjectTableIndex EQU 35 
WdfDeviceAddRemovalRelationsPhysicalDeviceTableIndex EQU 36 
WdfDeviceRemoveRemovalRelationsPhysicalDeviceTableIndex EQU 37 
WdfDeviceClearRemovalRelationsDevicesTableIndex EQU 38 
WdfDeviceGetDriverTableIndex EQU 39 
WdfDeviceRetrieveDeviceNameTableIndex EQU 40 
WdfDeviceAssignMofResourceNameTableIndex EQU 41 
WdfDeviceGetIoTargetTableIndex EQU 42 
WdfDeviceGetDevicePnpStateTableIndex EQU 43 
WdfDeviceGetDevicePowerStateTableIndex EQU 44 
WdfDeviceGetDevicePowerPolicyStateTableIndex EQU 45 
WdfDeviceAssignS0IdleSettingsTableIndex EQU 46 
WdfDeviceAssignSxWakeSettingsTableIndex EQU 47 
WdfDeviceOpenRegistryKeyTableIndex EQU 48 
WdfDeviceSetSpecialFileSupportTableIndex EQU 49 
WdfDeviceSetCharacteristicsTableIndex EQU 50 
WdfDeviceGetCharacteristicsTableIndex EQU 51 
WdfDeviceGetAlignmentRequirementTableIndex EQU 52 
WdfDeviceSetAlignmentRequirementTableIndex EQU 53 
WdfDeviceInitFreeTableIndex EQU 54 
WdfDeviceInitSetPnpPowerEventCallbacksTableIndex EQU 55 
WdfDeviceInitSetPowerPolicyEventCallbacksTableIndex EQU 56 
WdfDeviceInitSetPowerPolicyOwnershipTableIndex EQU 57 
WdfDeviceInitRegisterPnpStateChangeCallbackTableIndex EQU 58 
WdfDeviceInitRegisterPowerStateChangeCallbackTableIndex EQU 59 
WdfDeviceInitRegisterPowerPolicyStateChangeCallbackTableIndex EQU 60 
WdfDeviceInitSetIoTypeTableIndex EQU 61 
WdfDeviceInitSetExclusiveTableIndex EQU 62 
WdfDeviceInitSetPowerNotPageableTableIndex EQU 63 
WdfDeviceInitSetPowerPageableTableIndex EQU 64 
WdfDeviceInitSetPowerInrushTableIndex EQU 65 
WdfDeviceInitSetDeviceTypeTableIndex EQU 66 
WdfDeviceInitAssignNameTableIndex EQU 67 
WdfDeviceInitAssignSDDLStringTableIndex EQU 68 
WdfDeviceInitSetDeviceClassTableIndex EQU 69 
WdfDeviceInitSetCharacteristicsTableIndex EQU 70 
WdfDeviceInitSetFileObjectConfigTableIndex EQU 71 
WdfDeviceInitSetRequestAttributesTableIndex EQU 72 
WdfDeviceInitAssignWdmIrpPreprocessCallbackTableIndex EQU 73 
WdfDeviceInitSetIoInCallerContextCallbackTableIndex EQU 74 
WdfDeviceCreateTableIndex EQU 75 
WdfDeviceSetStaticStopRemoveTableIndex EQU 76 
WdfDeviceCreateDeviceInterfaceTableIndex EQU 77 
WdfDeviceSetDeviceInterfaceStateTableIndex EQU 78 
WdfDeviceRetrieveDeviceInterfaceStringTableIndex EQU 79 
WdfDeviceCreateSymbolicLinkTableIndex EQU 80 
WdfDeviceQueryPropertyTableIndex EQU 81 
WdfDeviceAllocAndQueryPropertyTableIndex EQU 82 
WdfDeviceSetPnpCapabilitiesTableIndex EQU 83 
WdfDeviceSetPowerCapabilitiesTableIndex EQU 84 
WdfDeviceSetBusInformationForChildrenTableIndex EQU 85 
WdfDeviceIndicateWakeStatusTableIndex EQU 86 
WdfDeviceSetFailedTableIndex EQU 87 
WdfDeviceStopIdleTableIndex EQU 88 
WdfDeviceResumeIdleTableIndex EQU 89 
WdfDeviceGetFileObjectTableIndex EQU 90 
WdfDeviceEnqueueRequestTableIndex EQU 91 
WdfDeviceGetDefaultQueueTableIndex EQU 92 
WdfDeviceConfigureRequestDispatchingTableIndex EQU 93 
WdfDmaEnablerCreateTableIndex EQU 94 
WdfDmaEnablerGetMaximumLengthTableIndex EQU 95 
WdfDmaEnablerGetMaximumScatterGatherElementsTableIndex EQU 96 
WdfDmaEnablerSetMaximumScatterGatherElementsTableIndex EQU 97 
WdfDmaTransactionCreateTableIndex EQU 98 
WdfDmaTransactionInitializeTableIndex EQU 99 
WdfDmaTransactionInitializeUsingRequestTableIndex EQU 100 
WdfDmaTransactionExecuteTableIndex EQU 101 
WdfDmaTransactionReleaseTableIndex EQU 102 
WdfDmaTransactionDmaCompletedTableIndex EQU 103 
WdfDmaTransactionDmaCompletedWithLengthTableIndex EQU 104 
WdfDmaTransactionDmaCompletedFinalTableIndex EQU 105 
WdfDmaTransactionGetBytesTransferredTableIndex EQU 106 
WdfDmaTransactionSetMaximumLengthTableIndex EQU 107 
WdfDmaTransactionGetRequestTableIndex EQU 108 
WdfDmaTransactionGetCurrentDmaTransferLengthTableIndex EQU 109 
WdfDmaTransactionGetDeviceTableIndex EQU 110 
WdfDpcCreateTableIndex EQU 111 
WdfDpcEnqueueTableIndex EQU 112 
WdfDpcCancelTableIndex EQU 113 
WdfDpcGetParentObjectTableIndex EQU 114 
WdfDpcWdmGetDpcTableIndex EQU 115 
WdfDriverCreateTableIndex EQU 116 
WdfDriverGetRegistryPathTableIndex EQU 117 
WdfDriverWdmGetDriverObjectTableIndex EQU 118 
WdfDriverOpenParametersRegistryKeyTableIndex EQU 119 
WdfWdmDriverGetWdfDriverHandleTableIndex EQU 120 
WdfDriverRegisterTraceInfoTableIndex EQU 121 
WdfDriverRetrieveVersionStringTableIndex EQU 122 
WdfDriverIsVersionAvailableTableIndex EQU 123 
WdfFdoInitWdmGetPhysicalDeviceTableIndex EQU 124 
WdfFdoInitOpenRegistryKeyTableIndex EQU 125 
WdfFdoInitQueryPropertyTableIndex EQU 126 
WdfFdoInitAllocAndQueryPropertyTableIndex EQU 127 
WdfFdoInitSetEventCallbacksTableIndex EQU 128 
WdfFdoInitSetFilterTableIndex EQU 129 
WdfFdoInitSetDefaultChildListConfigTableIndex EQU 130 
WdfFdoQueryForInterfaceTableIndex EQU 131 
WdfFdoGetDefaultChildListTableIndex EQU 132 
WdfFdoAddStaticChildTableIndex EQU 133 
WdfFdoLockStaticChildListForIterationTableIndex EQU 134 
WdfFdoRetrieveNextStaticChildTableIndex EQU 135 
WdfFdoUnlockStaticChildListFromIterationTableIndex EQU 136 
WdfFileObjectGetFileNameTableIndex EQU 137 
WdfFileObjectGetFlagsTableIndex EQU 138 
WdfFileObjectGetDeviceTableIndex EQU 139 
WdfFileObjectWdmGetFileObjectTableIndex EQU 140 
WdfInterruptCreateTableIndex EQU 141 
WdfInterruptQueueDpcForIsrTableIndex EQU 142 
WdfInterruptSynchronizeTableIndex EQU 143 
WdfInterruptAcquireLockTableIndex EQU 144 
WdfInterruptReleaseLockTableIndex EQU 145 
WdfInterruptEnableTableIndex EQU 146 
WdfInterruptDisableTableIndex EQU 147 
WdfInterruptWdmGetInterruptTableIndex EQU 148 
WdfInterruptGetInfoTableIndex EQU 149 
WdfInterruptSetPolicyTableIndex EQU 150 
WdfInterruptGetDeviceTableIndex EQU 151 
WdfIoQueueCreateTableIndex EQU 152 
WdfIoQueueGetStateTableIndex EQU 153 
WdfIoQueueStartTableIndex EQU 154 
WdfIoQueueStopTableIndex EQU 155 
WdfIoQueueStopSynchronouslyTableIndex EQU 156 
WdfIoQueueGetDeviceTableIndex EQU 157 
WdfIoQueueRetrieveNextRequestTableIndex EQU 158 
WdfIoQueueRetrieveRequestByFileObjectTableIndex EQU 159 
WdfIoQueueFindRequestTableIndex EQU 160 
WdfIoQueueRetrieveFoundRequestTableIndex EQU 161 
WdfIoQueueDrainSynchronouslyTableIndex EQU 162 
WdfIoQueueDrainTableIndex EQU 163 
WdfIoQueuePurgeSynchronouslyTableIndex EQU 164 
WdfIoQueuePurgeTableIndex EQU 165 
WdfIoQueueReadyNotifyTableIndex EQU 166 
WdfIoTargetCreateTableIndex EQU 167 
WdfIoTargetOpenTableIndex EQU 168 
WdfIoTargetCloseForQueryRemoveTableIndex EQU 169 
WdfIoTargetCloseTableIndex EQU 170 
WdfIoTargetStartTableIndex EQU 171 
WdfIoTargetStopTableIndex EQU 172 
WdfIoTargetGetStateTableIndex EQU 173 
WdfIoTargetGetDeviceTableIndex EQU 174 
WdfIoTargetQueryTargetPropertyTableIndex EQU 175 
WdfIoTargetAllocAndQueryTargetPropertyTableIndex EQU 176 
WdfIoTargetQueryForInterfaceTableIndex EQU 177 
WdfIoTargetWdmGetTargetDeviceObjectTableIndex EQU 178 
WdfIoTargetWdmGetTargetPhysicalDeviceTableIndex EQU 179 
WdfIoTargetWdmGetTargetFileObjectTableIndex EQU 180 
WdfIoTargetWdmGetTargetFileHandleTableIndex EQU 181 
WdfIoTargetSendReadSynchronouslyTableIndex EQU 182 
WdfIoTargetFormatRequestForReadTableIndex EQU 183 
WdfIoTargetSendWriteSynchronouslyTableIndex EQU 184 
WdfIoTargetFormatRequestForWriteTableIndex EQU 185 
WdfIoTargetSendIoctlSynchronouslyTableIndex EQU 186 
WdfIoTargetFormatRequestForIoctlTableIndex EQU 187 
WdfIoTargetSendInternalIoctlSynchronouslyTableIndex EQU 188 
WdfIoTargetFormatRequestForInternalIoctlTableIndex EQU 189 
WdfIoTargetSendInternalIoctlOthersSynchronouslyTableIndex EQU 190 
WdfIoTargetFormatRequestForInternalIoctlOthersTableIndex EQU 191 
WdfMemoryCreateTableIndex EQU 192 
WdfMemoryCreatePreallocatedTableIndex EQU 193 
WdfMemoryGetBufferTableIndex EQU 194 
WdfMemoryAssignBufferTableIndex EQU 195 
WdfMemoryCopyToBufferTableIndex EQU 196 
WdfMemoryCopyFromBufferTableIndex EQU 197 
WdfLookasideListCreateTableIndex EQU 198 
WdfMemoryCreateFromLookasideTableIndex EQU 199 
WdfDeviceMiniportCreateTableIndex EQU 200 
WdfDriverMiniportUnloadTableIndex EQU 201 
WdfObjectGetTypedContextWorkerTableIndex EQU 202 
WdfObjectAllocateContextTableIndex EQU 203 
WdfObjectContextGetObjectTableIndex EQU 204 
WdfObjectReferenceActualTableIndex EQU 205 
WdfObjectDereferenceActualTableIndex EQU 206 
WdfObjectCreateTableIndex EQU 207 
WdfObjectDeleteTableIndex EQU 208 
WdfObjectQueryTableIndex EQU 209 
WdfPdoInitAllocateTableIndex EQU 210 
WdfPdoInitSetEventCallbacksTableIndex EQU 211 
WdfPdoInitAssignDeviceIDTableIndex EQU 212 
WdfPdoInitAssignInstanceIDTableIndex EQU 213 
WdfPdoInitAddHardwareIDTableIndex EQU 214 
WdfPdoInitAddCompatibleIDTableIndex EQU 215 
WdfPdoInitAddDeviceTextTableIndex EQU 216 
WdfPdoInitSetDefaultLocaleTableIndex EQU 217 
WdfPdoInitAssignRawDeviceTableIndex EQU 218 
WdfPdoMarkMissingTableIndex EQU 219 
WdfPdoRequestEjectTableIndex EQU 220 
WdfPdoGetParentTableIndex EQU 221 
WdfPdoRetrieveIdentificationDescriptionTableIndex EQU 222 
WdfPdoRetrieveAddressDescriptionTableIndex EQU 223 
WdfPdoUpdateAddressDescriptionTableIndex EQU 224 
WdfPdoAddEjectionRelationsPhysicalDeviceTableIndex EQU 225 
WdfPdoRemoveEjectionRelationsPhysicalDeviceTableIndex EQU 226 
WdfPdoClearEjectionRelationsDevicesTableIndex EQU 227 
WdfDeviceAddQueryInterfaceTableIndex EQU 228 
WdfRegistryOpenKeyTableIndex EQU 229 
WdfRegistryCreateKeyTableIndex EQU 230 
WdfRegistryCloseTableIndex EQU 231 
WdfRegistryWdmGetHandleTableIndex EQU 232 
WdfRegistryRemoveKeyTableIndex EQU 233 
WdfRegistryRemoveValueTableIndex EQU 234 
WdfRegistryQueryValueTableIndex EQU 235 
WdfRegistryQueryMemoryTableIndex EQU 236 
WdfRegistryQueryMultiStringTableIndex EQU 237 
WdfRegistryQueryUnicodeStringTableIndex EQU 238 
WdfRegistryQueryStringTableIndex EQU 239 
WdfRegistryQueryULongTableIndex EQU 240 
WdfRegistryAssignValueTableIndex EQU 241 
WdfRegistryAssignMemoryTableIndex EQU 242 
WdfRegistryAssignMultiStringTableIndex EQU 243 
WdfRegistryAssignUnicodeStringTableIndex EQU 244 
WdfRegistryAssignStringTableIndex EQU 245 
WdfRegistryAssignULongTableIndex EQU 246 
WdfRequestCreateTableIndex EQU 247 
WdfRequestCreateFromIrpTableIndex EQU 248 
WdfRequestReuseTableIndex EQU 249 
WdfRequestChangeTargetTableIndex EQU 250 
WdfRequestFormatRequestUsingCurrentTypeTableIndex EQU 251 
WdfRequestWdmFormatUsingStackLocationTableIndex EQU 252 
WdfRequestSendTableIndex EQU 253 
WdfRequestGetStatusTableIndex EQU 254 
WdfRequestMarkCancelableTableIndex EQU 255 
WdfRequestUnmarkCancelableTableIndex EQU 256 
WdfRequestIsCanceledTableIndex EQU 257 
WdfRequestCancelSentRequestTableIndex EQU 258 
WdfRequestIsFrom32BitProcessTableIndex EQU 259 
WdfRequestSetCompletionRoutineTableIndex EQU 260 
WdfRequestGetCompletionParamsTableIndex EQU 261 
WdfRequestAllocateTimerTableIndex EQU 262 
WdfRequestCompleteTableIndex EQU 263 
WdfRequestCompleteWithPriorityBoostTableIndex EQU 264 
WdfRequestCompleteWithInformationTableIndex EQU 265 
WdfRequestGetParametersTableIndex EQU 266 
WdfRequestRetrieveInputMemoryTableIndex EQU 267 
WdfRequestRetrieveOutputMemoryTableIndex EQU 268 
WdfRequestRetrieveInputBufferTableIndex EQU 269 
WdfRequestRetrieveOutputBufferTableIndex EQU 270 
WdfRequestRetrieveInputWdmMdlTableIndex EQU 271 
WdfRequestRetrieveOutputWdmMdlTableIndex EQU 272 
WdfRequestRetrieveUnsafeUserInputBufferTableIndex EQU 273 
WdfRequestRetrieveUnsafeUserOutputBufferTableIndex EQU 274 
WdfRequestSetInformationTableIndex EQU 275 
WdfRequestGetInformationTableIndex EQU 276 
WdfRequestGetFileObjectTableIndex EQU 277 
WdfRequestProbeAndLockUserBufferForReadTableIndex EQU 278 
WdfRequestProbeAndLockUserBufferForWriteTableIndex EQU 279 
WdfRequestGetRequestorModeTableIndex EQU 280 
WdfRequestForwardToIoQueueTableIndex EQU 281 
WdfRequestGetIoQueueTableIndex EQU 282 
WdfRequestRequeueTableIndex EQU 283 
WdfRequestStopAcknowledgeTableIndex EQU 284 
WdfRequestWdmGetIrpTableIndex EQU 285 
WdfIoResourceRequirementsListSetSlotNumberTableIndex EQU 286 
WdfIoResourceRequirementsListSetInterfaceTypeTableIndex EQU 287 
WdfIoResourceRequirementsListAppendIoResListTableIndex EQU 288 
WdfIoResourceRequirementsListInsertIoResListTableIndex EQU 289 
WdfIoResourceRequirementsListGetCountTableIndex EQU 290 
WdfIoResourceRequirementsListGetIoResListTableIndex EQU 291 
WdfIoResourceRequirementsListRemoveTableIndex EQU 292 
WdfIoResourceRequirementsListRemoveByIoResListTableIndex EQU 293 
WdfIoResourceListCreateTableIndex EQU 294 
WdfIoResourceListAppendDescriptorTableIndex EQU 295 
WdfIoResourceListInsertDescriptorTableIndex EQU 296 
WdfIoResourceListUpdateDescriptorTableIndex EQU 297 
WdfIoResourceListGetCountTableIndex EQU 298 
WdfIoResourceListGetDescriptorTableIndex EQU 299 
WdfIoResourceListRemoveTableIndex EQU 300 
WdfIoResourceListRemoveByDescriptorTableIndex EQU 301 
WdfCmResourceListAppendDescriptorTableIndex EQU 302 
WdfCmResourceListInsertDescriptorTableIndex EQU 303 
WdfCmResourceListGetCountTableIndex EQU 304 
WdfCmResourceListGetDescriptorTableIndex EQU 305 
WdfCmResourceListRemoveTableIndex EQU 306 
WdfCmResourceListRemoveByDescriptorTableIndex EQU 307 
WdfStringCreateTableIndex EQU 308 
WdfStringGetUnicodeStringTableIndex EQU 309 
WdfObjectAcquireLockTableIndex EQU 310 
WdfObjectReleaseLockTableIndex EQU 311 
WdfWaitLockCreateTableIndex EQU 312 
WdfWaitLockAcquireTableIndex EQU 313 
WdfWaitLockReleaseTableIndex EQU 314 
WdfSpinLockCreateTableIndex EQU 315 
WdfSpinLockAcquireTableIndex EQU 316 
WdfSpinLockReleaseTableIndex EQU 317 
WdfTimerCreateTableIndex EQU 318 
WdfTimerStartTableIndex EQU 319 
WdfTimerStopTableIndex EQU 320 
WdfTimerGetParentObjectTableIndex EQU 321 
WdfUsbTargetDeviceCreateTableIndex EQU 322 
WdfUsbTargetDeviceRetrieveInformationTableIndex EQU 323 
WdfUsbTargetDeviceGetDeviceDescriptorTableIndex EQU 324 
WdfUsbTargetDeviceRetrieveConfigDescriptorTableIndex EQU 325 
WdfUsbTargetDeviceQueryStringTableIndex EQU 326 
WdfUsbTargetDeviceAllocAndQueryStringTableIndex EQU 327 
WdfUsbTargetDeviceFormatRequestForStringTableIndex EQU 328 
WdfUsbTargetDeviceGetNumInterfacesTableIndex EQU 329 
WdfUsbTargetDeviceSelectConfigTableIndex EQU 330 
WdfUsbTargetDeviceWdmGetConfigurationHandleTableIndex EQU 331 
WdfUsbTargetDeviceRetrieveCurrentFrameNumberTableIndex EQU 332 
WdfUsbTargetDeviceSendControlTransferSynchronouslyTableIndex EQU 333 
WdfUsbTargetDeviceFormatRequestForControlTransferTableIndex EQU 334 
WdfUsbTargetDeviceIsConnectedSynchronousTableIndex EQU 335 
WdfUsbTargetDeviceResetPortSynchronouslyTableIndex EQU 336 
WdfUsbTargetDeviceCyclePortSynchronouslyTableIndex EQU 337 
WdfUsbTargetDeviceFormatRequestForCyclePortTableIndex EQU 338 
WdfUsbTargetDeviceSendUrbSynchronouslyTableIndex EQU 339 
WdfUsbTargetDeviceFormatRequestForUrbTableIndex EQU 340 
WdfUsbTargetPipeGetInformationTableIndex EQU 341 
WdfUsbTargetPipeIsInEndpointTableIndex EQU 342 
WdfUsbTargetPipeIsOutEndpointTableIndex EQU 343 
WdfUsbTargetPipeGetTypeTableIndex EQU 344 
WdfUsbTargetPipeSetNoMaximumPacketSizeCheckTableIndex EQU 345 
WdfUsbTargetPipeWriteSynchronouslyTableIndex EQU 346 
WdfUsbTargetPipeFormatRequestForWriteTableIndex EQU 347 
WdfUsbTargetPipeReadSynchronouslyTableIndex EQU 348 
WdfUsbTargetPipeFormatRequestForReadTableIndex EQU 349 
WdfUsbTargetPipeConfigContinuousReaderTableIndex EQU 350 
WdfUsbTargetPipeAbortSynchronouslyTableIndex EQU 351 
WdfUsbTargetPipeFormatRequestForAbortTableIndex EQU 352 
WdfUsbTargetPipeResetSynchronouslyTableIndex EQU 353 
WdfUsbTargetPipeFormatRequestForResetTableIndex EQU 354 
WdfUsbTargetPipeSendUrbSynchronouslyTableIndex EQU 355 
WdfUsbTargetPipeFormatRequestForUrbTableIndex EQU 356 
WdfUsbInterfaceGetInterfaceNumberTableIndex EQU 357 
WdfUsbInterfaceGetNumEndpointsTableIndex EQU 358 
WdfUsbInterfaceGetDescriptorTableIndex EQU 359 
WdfUsbInterfaceSelectSettingTableIndex EQU 360 
WdfUsbInterfaceGetEndpointInformationTableIndex EQU 361 
WdfUsbTargetDeviceGetInterfaceTableIndex EQU 362 
WdfUsbInterfaceGetConfiguredSettingIndexTableIndex EQU 363 
WdfUsbInterfaceGetNumConfiguredPipesTableIndex EQU 364 
WdfUsbInterfaceGetConfiguredPipeTableIndex EQU 365 
WdfUsbTargetPipeWdmGetPipeHandleTableIndex EQU 366 
WdfVerifierDbgBreakPointTableIndex EQU 367 
WdfVerifierKeBugCheckTableIndex EQU 368 
WdfWmiProviderCreateTableIndex EQU 369 
WdfWmiProviderGetDeviceTableIndex EQU 370 
WdfWmiProviderIsEnabledTableIndex EQU 371 
WdfWmiProviderGetTracingHandleTableIndex EQU 372 
WdfWmiInstanceCreateTableIndex EQU 373 
WdfWmiInstanceRegisterTableIndex EQU 374 
WdfWmiInstanceDeregisterTableIndex EQU 375 
WdfWmiInstanceGetDeviceTableIndex EQU 376 
WdfWmiInstanceGetProviderTableIndex EQU 377 
WdfWmiInstanceFireEventTableIndex EQU 378 
WdfWorkItemCreateTableIndex EQU 379 
WdfWorkItemEnqueueTableIndex EQU 380 
WdfWorkItemGetParentObjectTableIndex EQU 381 
WdfWorkItemFlushTableIndex EQU 382 
WdfCommonBufferCreateWithConfigTableIndex EQU 383 
WdfDmaEnablerGetFragmentLengthTableIndex EQU 384 
WdfDmaEnablerWdmGetDmaAdapterTableIndex EQU 385 
WdfUsbInterfaceGetNumSettingsTableIndex EQU 386 
WdfDeviceRemoveDependentUsageDeviceObjectTableIndex EQU 387 
WdfDeviceGetSystemPowerActionTableIndex EQU 388 
WdfInterruptSetExtendedPolicyTableIndex EQU 389 
WdfIoQueueAssignForwardProgressPolicyTableIndex EQU 390 
WdfPdoInitAssignContainerIDTableIndex EQU 391 
WdfPdoInitAllowForwardingRequestToParentTableIndex EQU 392 
WdfRequestMarkCancelableExTableIndex EQU 393 
WdfRequestIsReservedTableIndex EQU 394 
WdfRequestForwardToParentDeviceIoQueueTableIndex EQU 395 
WdfFunctionTableNumEntries EQU 396 


;-------------------------------------------------------------------------
; wdfstatus.h
;-------------------------------------------------------------------------
FACILITY_DRIVER_FRAMEWORK equ 20h
STATUS_SEVERITY_WARNING equ 2h
STATUS_SEVERITY_SUCCESS equ 0h
STATUS_SEVERITY_INFORMATIONAL equ 1h
STATUS_SEVERITY_ERROR equ 3h
STATUS_WDF_QUEUED equ ( ( NTSTATUS ) 40200000h )
STATUS_WDF_POSTED equ ( ( NTSTATUS ) 40200002h )
STATUS_WDF_NO_PACKAGE equ ( ( NTSTATUS ) 0C0200200h )
STATUS_WDF_INTERNAL_ERROR equ ( ( NTSTATUS ) 0C0200201h )
STATUS_WDF_PAUSED equ ( ( NTSTATUS ) 0C0200203h )
STATUS_WDF_BUSY equ ( ( NTSTATUS ) 0C0200204h )
STATUS_WDF_IO_TIMEOUT_NOT_SENT equ ( ( NTSTATUS ) 0C0200205h )
STATUS_WDF_DEVICE_REMOVED_NOT_SENT equ ( ( NTSTATUS ) 0C0200206h )
STATUS_WDF_REQUEST_ALREADY_PENDING equ ( ( NTSTATUS ) 0C0200207h )
STATUS_WDF_REQUEST_INVALID_STATE equ ( ( NTSTATUS ) 0C0200208h )
STATUS_WDF_OBJECT_ATTRIBUTES_INVALID equ ( ( NTSTATUS ) 0C0200209h )
STATUS_WDF_TOO_FRAGMENTED equ ( ( NTSTATUS ) 0C020020Ah )
STATUS_WDF_NO_CALLBACK equ ( ( NTSTATUS ) 0C020020Bh )
STATUS_WDF_INCOMPATIBLE_EXECUTION_LEVEL equ ( ( NTSTATUS ) 0C020020Ch )
STATUS_WDF_PARENT_ALREADY_ASSIGNED equ ( ( NTSTATUS ) 0C020020Dh )
STATUS_WDF_PARENT_IS_SELF equ ( ( NTSTATUS ) 0C020020Eh )
STATUS_WDF_PARENT_ASSIGNMENT_NOT_ALLOWED equ ( ( NTSTATUS ) 0C020020Fh )
STATUS_WDF_SYNCHRONIZATION_SCOPE_INVALID equ ( ( NTSTATUS ) 0C0200210h )
STATUS_WDF_EXECUTION_LEVEL_INVALID equ ( ( NTSTATUS ) 0C0200211h )
STATUS_WDF_PARENT_NOT_SPECIFIED equ ( ( NTSTATUS ) 0C0200212h )


;-------------------------------------------------------------------------
; wdfverifier.h
;-------------------------------------------------------------------------
proto_PFN_WDFVERIFIERDBGBREAKPOINT typedef proto fastcall :PWDF_DRIVER_GLOBALS
PFN_WDFVERIFIERDBGBREAKPOINT typedef ptr proto_PFN_WDFVERIFIERDBGBREAKPOINT
WdfVerifierDbgBreakPoint proto fastcall
proto_PFN_WDFVERIFIERKEBUGCHECK typedef proto fastcall :PWDF_DRIVER_GLOBALS, :DWORD, :ULONG_PTR, :ULONG_PTR, :ULONG_PTR, :ULONG_PTR
PFN_WDFVERIFIERKEBUGCHECK typedef ptr proto_PFN_WDFVERIFIERKEBUGCHECK
WdfVerifierKeBugCheck proto fastcall :DWORD, :ULONG_PTR, :ULONG_PTR, :ULONG_PTR, :ULONG_PTR


;-------------------------------------------------------------------------
; wdfobject.h
;-------------------------------------------------------------------------
WDF_EXECUTION_LEVEL typedef SDWORD
WdfExecutionLevelInvalid EQU 00h 
WdfExecutionLevelInheritFromParent EQU 1
WdfExecutionLevelPassive EQU 2
WdfExecutionLevelDispatch EQU 3

WDF_SYNCHRONIZATION_SCOPE typedef SDWORD
WdfSynchronizationScopeInvalid EQU 00h 
WdfSynchronizationScopeInheritFromParent EQU 1
WdfSynchronizationScopeDevice EQU 2
WdfSynchronizationScopeQueue EQU 3
WdfSynchronizationScopeNone EQU 4

EVT_WDF_OBJECT_CONTEXT_CLEANUP typedef proto stdcall :WDFOBJECT
PFN_WDF_OBJECT_CONTEXT_CLEANUP typedef ptr EVT_WDF_OBJECT_CONTEXT_CLEANUP
EVT_WDF_OBJECT_CONTEXT_DESTROY typedef proto stdcall :WDFOBJECT
PFN_WDF_OBJECT_CONTEXT_DESTROY typedef ptr EVT_WDF_OBJECT_CONTEXT_DESTROY
PCWDF_OBJECT_CONTEXT_TYPE_INFO typedef ptr _WDF_OBJECT_CONTEXT_TYPE_INFO

WDF_OBJECT_ATTRIBUTES struct
    Size_ DWORD ?
    EvtCleanupCallback PFN_WDF_OBJECT_CONTEXT_CLEANUP ?
    EvtDestroyCallback PFN_WDF_OBJECT_CONTEXT_DESTROY ?
    ExecutionLevel WDF_EXECUTION_LEVEL ?
    SynchronizationScope WDF_SYNCHRONIZATION_SCOPE ?
    ParentObject WDFOBJECT ?
    ContextSizeOverride size_t ?
    ContextTypeInfo PCWDF_OBJECT_CONTEXT_TYPE_INFO ?
WDF_OBJECT_ATTRIBUTES ends

PWDF_OBJECT_ATTRIBUTES typedef ptr WDF_OBJECT_ATTRIBUTES

WDF_OBJECT_ATTRIBUTES_INIT proto fastcall :PWDF_OBJECT_ATTRIBUTES

proto_PFN_GET_UNIQUE_CONTEXT_TYPE typedef proto c 
PFN_GET_UNIQUE_CONTEXT_TYPE typedef ptr proto_PFN_GET_UNIQUE_CONTEXT_TYPE
WDF_OBJECT_CONTEXT_TYPE_INFO struct
    Size_ DWORD ?
    ContextName PCHAR ?
    ContextSize size_t ?
    UniqueType PCWDF_OBJECT_CONTEXT_TYPE_INFO ?
    EvtDriverGetUniqueContextType PFN_GET_UNIQUE_CONTEXT_TYPE ?
WDF_OBJECT_CONTEXT_TYPE_INFO ends

PWDF_OBJECT_CONTEXT_TYPE_INFO typedef ptr WDF_OBJECT_CONTEXT_TYPE_INFO

WDF_TYPE_INIT_BASE_SECTION_NAME equ <".kmdftypeinit",0>
WDF_TYPE_INIT_SECTION_NAME equ <".kmdftypeinit$b",0>
ifndef WDF_TYPE_DEFAULT_SECTION_NAME
  WDF_TYPE_DEFAULT_SECTION_NAME equ <".data",0>
endif

proto_PFN_WDFOBJECTGETTYPEDCONTEXTWORKER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFOBJECT, :PCWDF_OBJECT_CONTEXT_TYPE_INFO
PFN_WDFOBJECTGETTYPEDCONTEXTWORKER typedef ptr proto_PFN_WDFOBJECTGETTYPEDCONTEXTWORKER
WdfObjectGetTypedContextWorker proto fastcall :WDFOBJECT, :PCWDF_OBJECT_CONTEXT_TYPE_INFO
proto_PFN_WDFOBJECTALLOCATECONTEXT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFOBJECT, :PWDF_OBJECT_ATTRIBUTES, :ptr PVOID
PFN_WDFOBJECTALLOCATECONTEXT typedef ptr proto_PFN_WDFOBJECTALLOCATECONTEXT
WdfObjectAllocateContext proto fastcall :WDFOBJECT, :PWDF_OBJECT_ATTRIBUTES, :ptr PVOID
proto_PFN_WDFOBJECTCONTEXTGETOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PVOID
PFN_WDFOBJECTCONTEXTGETOBJECT typedef ptr proto_PFN_WDFOBJECTCONTEXTGETOBJECT
WdfObjectContextGetObject proto fastcall :PVOID
proto_PFN_WDFOBJECTREFERENCEACTUAL typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFOBJECT, :PVOID, :SDWORD, :PCHAR
PFN_WDFOBJECTREFERENCEACTUAL typedef ptr proto_PFN_WDFOBJECTREFERENCEACTUAL
WdfObjectReferenceActual proto fastcall :WDFOBJECT, :PVOID, :SDWORD, :PCHAR
proto_PFN_WDFOBJECTDEREFERENCEACTUAL typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFOBJECT, :PVOID, :SDWORD, :PCHAR
PFN_WDFOBJECTDEREFERENCEACTUAL typedef ptr proto_PFN_WDFOBJECTDEREFERENCEACTUAL
WdfObjectDereferenceActual proto fastcall :WDFOBJECT, :PVOID, :SDWORD, :PCHAR
proto_PFN_WDFOBJECTCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFOBJECT
PFN_WDFOBJECTCREATE typedef ptr proto_PFN_WDFOBJECTCREATE
WdfObjectCreate proto fastcall :PWDF_OBJECT_ATTRIBUTES, :ptr WDFOBJECT
proto_PFN_WDFOBJECTDELETE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFOBJECT
PFN_WDFOBJECTDELETE typedef ptr proto_PFN_WDFOBJECTDELETE
WdfObjectDelete proto fastcall :WDFOBJECT
proto_PFN_WDFOBJECTQUERY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFOBJECT, :ptr GUID, :DWORD, :PVOID
PFN_WDFOBJECTQUERY typedef ptr proto_PFN_WDFOBJECTQUERY
WdfObjectQuery proto fastcall :WDFOBJECT, :ptr GUID, :DWORD, :PVOID


;-------------------------------------------------------------------------
; wdfsync.h
;-------------------------------------------------------------------------
proto_PFN_WDFOBJECTACQUIRELOCK typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFOBJECT
PFN_WDFOBJECTACQUIRELOCK typedef ptr proto_PFN_WDFOBJECTACQUIRELOCK
WdfObjectAcquireLock proto fastcall :WDFOBJECT
proto_PFN_WDFOBJECTRELEASELOCK typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFOBJECT
PFN_WDFOBJECTRELEASELOCK typedef ptr proto_PFN_WDFOBJECTRELEASELOCK
WdfObjectReleaseLock proto fastcall :WDFOBJECT
proto_PFN_WDFWAITLOCKCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFWAITLOCK
PFN_WDFWAITLOCKCREATE typedef ptr proto_PFN_WDFWAITLOCKCREATE
WdfWaitLockCreate proto fastcall :PWDF_OBJECT_ATTRIBUTES, :ptr WDFWAITLOCK
proto_PFN_WDFWAITLOCKACQUIRE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWAITLOCK, :PLONGLONG
PFN_WDFWAITLOCKACQUIRE typedef ptr proto_PFN_WDFWAITLOCKACQUIRE
WdfWaitLockAcquire proto fastcall :WDFWAITLOCK, :PLONGLONG
proto_PFN_WDFWAITLOCKRELEASE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWAITLOCK
PFN_WDFWAITLOCKRELEASE typedef ptr proto_PFN_WDFWAITLOCKRELEASE
WdfWaitLockRelease proto fastcall :WDFWAITLOCK
proto_PFN_WDFSPINLOCKCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFSPINLOCK
PFN_WDFSPINLOCKCREATE typedef ptr proto_PFN_WDFSPINLOCKCREATE
WdfSpinLockCreate proto fastcall :PWDF_OBJECT_ATTRIBUTES, :ptr WDFSPINLOCK
proto_PFN_WDFSPINLOCKACQUIRE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFSPINLOCK
PFN_WDFSPINLOCKACQUIRE typedef ptr proto_PFN_WDFSPINLOCKACQUIRE
WdfSpinLockAcquire proto fastcall :WDFSPINLOCK
proto_PFN_WDFSPINLOCKRELEASE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFSPINLOCK
PFN_WDFSPINLOCKRELEASE typedef ptr proto_PFN_WDFSPINLOCKRELEASE
WdfSpinLockRelease proto fastcall :WDFSPINLOCK


;-------------------------------------------------------------------------
; wdfcore.h
;-------------------------------------------------------------------------
WDF_TIMEOUT_TO_SEC equ ( 1 * 10 * 1000 * 1000 )
WDF_TIMEOUT_TO_MS equ ( 1 * 10 * 1000 )
WDF_TIMEOUT_TO_US equ ( 1 * 10 )
WDF_REL_TIMEOUT_IN_SEC proto fastcall :QWORD
WDF_ABS_TIMEOUT_IN_SEC proto fastcall :QWORD
WDF_REL_TIMEOUT_IN_MS proto fastcall :QWORD
WDF_ABS_TIMEOUT_IN_MS proto fastcall :QWORD
WDF_REL_TIMEOUT_IN_US proto fastcall :QWORD
WDF_ABS_TIMEOUT_IN_US proto fastcall :QWORD
WDF_ALIGN_SIZE_DOWN proto fastcall :size_t, :size_t
WDF_ALIGN_SIZE_UP proto fastcall :size_t, :size_t


;-------------------------------------------------------------------------
; wdfdriver.h
;-------------------------------------------------------------------------
WDF_DRIVER_INIT_FLAGS typedef SDWORD
WdfDriverInitNonPnpDriver EQU 00000001h 
WdfDriverInitNoDispatchOverride EQU 00000002h 
WdfVerifyOn EQU 00000004h 
WdfVerifierOn EQU 00000008h 

WDF_TRACE_ID equ <( 'TRAC' )>
EVT_WDF_DRIVER_DEVICE_ADD typedef proto stdcall :WDFDRIVER,:PWDFDEVICE_INIT
PFN_WDF_DRIVER_DEVICE_ADD typedef ptr EVT_WDF_DRIVER_DEVICE_ADD
EVT_WDF_DRIVER_UNLOAD typedef proto stdcall :WDFDRIVER
PFN_WDF_DRIVER_UNLOAD typedef ptr EVT_WDF_DRIVER_UNLOAD
EVT_WDF_TRACE_CALLBACK typedef proto stdcall :BYTE,:PVOID,:DWORD,:PVOID,:PVOID,:PULONG
PFN_WDF_TRACE_CALLBACK typedef ptr EVT_WDF_TRACE_CALLBACK
WDF_DRIVER_CONFIG struct
    Size_ DWORD ?
    EvtDriverDeviceAdd PFN_WDF_DRIVER_DEVICE_ADD ?
    EvtDriverUnload PFN_WDF_DRIVER_UNLOAD ?
    DriverInitFlags DWORD ?
    DriverPoolTag DWORD ?
WDF_DRIVER_CONFIG ends

PWDF_DRIVER_CONFIG typedef ptr WDF_DRIVER_CONFIG

WDF_DRIVER_CONFIG_INIT proto fastcall :PWDF_DRIVER_CONFIG, :PFN_WDF_DRIVER_DEVICE_ADD
WDF_DRIVER_VERSION_AVAILABLE_PARAMS struct
    Size_ DWORD ?
    MajorVersion DWORD ?
    MinorVersion DWORD ?
WDF_DRIVER_VERSION_AVAILABLE_PARAMS ends

PWDF_DRIVER_VERSION_AVAILABLE_PARAMS typedef ptr WDF_DRIVER_VERSION_AVAILABLE_PARAMS

WDF_DRIVER_VERSION_AVAILABLE_PARAMS_INIT proto fastcall :PWDF_DRIVER_VERSION_AVAILABLE_PARAMS, :DWORD, :DWORD
WdfGetDriver proto fastcall
proto_PFN_WDFDRIVERCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PDRIVER_OBJECT, :PCUNICODE_STRING, :PWDF_OBJECT_ATTRIBUTES, :PWDF_DRIVER_CONFIG, :ptr WDFDRIVER
PFN_WDFDRIVERCREATE typedef ptr proto_PFN_WDFDRIVERCREATE
WdfDriverCreate proto fastcall :PDRIVER_OBJECT, :PCUNICODE_STRING, :PWDF_OBJECT_ATTRIBUTES, :PWDF_DRIVER_CONFIG, :ptr WDFDRIVER
proto_PFN_WDFDRIVERGETREGISTRYPATH typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDRIVER
PFN_WDFDRIVERGETREGISTRYPATH typedef ptr proto_PFN_WDFDRIVERGETREGISTRYPATH
WdfDriverGetRegistryPath proto fastcall :WDFDRIVER
proto_PFN_WDFDRIVERWDMGETDRIVEROBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDRIVER
PFN_WDFDRIVERWDMGETDRIVEROBJECT typedef ptr proto_PFN_WDFDRIVERWDMGETDRIVEROBJECT
WdfDriverWdmGetDriverObject proto fastcall :WDFDRIVER
proto_PFN_WDFDRIVEROPENPARAMETERSREGISTRYKEY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDRIVER, :ACCESS_MASK, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFKEY
PFN_WDFDRIVEROPENPARAMETERSREGISTRYKEY typedef ptr proto_PFN_WDFDRIVEROPENPARAMETERSREGISTRYKEY
WdfDriverOpenParametersRegistryKey proto fastcall :WDFDRIVER, :ACCESS_MASK, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFKEY
proto_PFN_WDFWDMDRIVERGETWDFDRIVERHANDLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PDRIVER_OBJECT
PFN_WDFWDMDRIVERGETWDFDRIVERHANDLE typedef ptr proto_PFN_WDFWDMDRIVERGETWDFDRIVERHANDLE
WdfWdmDriverGetWdfDriverHandle proto fastcall :PDRIVER_OBJECT
proto_PFN_WDFDRIVERREGISTERTRACEINFO typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PDRIVER_OBJECT, :PFN_WDF_TRACE_CALLBACK, :PVOID
PFN_WDFDRIVERREGISTERTRACEINFO typedef ptr proto_PFN_WDFDRIVERREGISTERTRACEINFO
WdfDriverRegisterTraceInfo proto fastcall :PDRIVER_OBJECT, :PFN_WDF_TRACE_CALLBACK, :PVOID
proto_PFN_WDFDRIVERRETRIEVEVERSIONSTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDRIVER, :WDFSTRING
PFN_WDFDRIVERRETRIEVEVERSIONSTRING typedef ptr proto_PFN_WDFDRIVERRETRIEVEVERSIONSTRING
WdfDriverRetrieveVersionString proto fastcall :WDFDRIVER, :WDFSTRING
proto_PFN_WDFDRIVERISVERSIONAVAILABLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDRIVER, :PWDF_DRIVER_VERSION_AVAILABLE_PARAMS
PFN_WDFDRIVERISVERSIONAVAILABLE typedef ptr proto_PFN_WDFDRIVERISVERSIONAVAILABLE
WdfDriverIsVersionAvailable proto fastcall :WDFDRIVER, :PWDF_DRIVER_VERSION_AVAILABLE_PARAMS


;-------------------------------------------------------------------------
; wdfqueryinterface.h
;-------------------------------------------------------------------------
EVT_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST typedef proto stdcall :WDFDEVICE,:LPGUID,:PINTERFACE,:PVOID
PFN_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST typedef ptr EVT_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST
WDF_QUERY_INTERFACE_CONFIG struct
    Size_ DWORD ?
    Interface PINTERFACE ?
    InterfaceType POINTER ?
    SendQueryToParentStack BOOLEAN ?
    EvtDeviceProcessQueryInterfaceRequest PFN_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST ?
    ImportInterface BOOLEAN ?
WDF_QUERY_INTERFACE_CONFIG ends

PWDF_QUERY_INTERFACE_CONFIG typedef ptr WDF_QUERY_INTERFACE_CONFIG

WDF_QUERY_INTERFACE_CONFIG_INIT proto fastcall :PWDF_QUERY_INTERFACE_CONFIG, :PINTERFACE, :ptr GUID, :PFN_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST
proto_PFN_WDFDEVICEADDQUERYINTERFACE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_QUERY_INTERFACE_CONFIG
PFN_WDFDEVICEADDQUERYINTERFACE typedef ptr proto_PFN_WDFDEVICEADDQUERYINTERFACE
WdfDeviceAddQueryInterface proto fastcall :WDFDEVICE, :PWDF_QUERY_INTERFACE_CONFIG
WdfDeviceInterfaceReferenceNoOp proto fastcall :PVOID
WdfDeviceInterfaceDereferenceNoOp proto fastcall :PVOID


;-------------------------------------------------------------------------
; wdfmemory.h
;-------------------------------------------------------------------------
WDF_MEMORY_DESCRIPTOR_TYPE typedef SDWORD
WdfMemoryDescriptorTypeInvalid EQU 0 
WdfMemoryDescriptorTypeBuffer EQU 1
WdfMemoryDescriptorTypeMdl EQU 2
WdfMemoryDescriptorTypeHandle EQU 3

WDFMEMORY_OFFSET struct
    BufferOffset size_t ?
    BufferLength size_t ?
WDFMEMORY_OFFSET ends

PWDFMEMORY_OFFSET typedef ptr WDFMEMORY_OFFSET

WDF_MEMORY_DESCRIPTOR struct
    Type_ WDF_MEMORY_DESCRIPTOR_TYPE ?
    union u
        struct BufferType
            Buffer PVOID ?
            Length_ DWORD ?
        ends
        struct MdlType
            Mdl PMDL ?
            BufferLength DWORD ?
        ends
        struct HandleType
            Memory WDFMEMORY ?
            Offsets PWDFMEMORY_OFFSET ?
        ends
    ends
WDF_MEMORY_DESCRIPTOR ends

PWDF_MEMORY_DESCRIPTOR typedef ptr WDF_MEMORY_DESCRIPTOR

WDF_MEMORY_DESCRIPTOR_INIT_BUFFER proto fastcall :PWDF_MEMORY_DESCRIPTOR, :PVOID, :DWORD
WDF_MEMORY_DESCRIPTOR_INIT_MDL proto fastcall :PWDF_MEMORY_DESCRIPTOR, :PMDL, :DWORD
WDF_MEMORY_DESCRIPTOR_INIT_HANDLE proto fastcall :PWDF_MEMORY_DESCRIPTOR, :WDFMEMORY, :PWDFMEMORY_OFFSET
proto_PFN_WDFMEMORYCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDF_OBJECT_ATTRIBUTES, :POOL_TYPE, :DWORD, :size_t, :ptr WDFMEMORY, :ptr PVOID
PFN_WDFMEMORYCREATE typedef ptr proto_PFN_WDFMEMORYCREATE
WdfMemoryCreate proto fastcall :PWDF_OBJECT_ATTRIBUTES, :POOL_TYPE, :DWORD, :size_t, :ptr WDFMEMORY, :ptr PVOID
proto_PFN_WDFMEMORYCREATEPREALLOCATED typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDF_OBJECT_ATTRIBUTES, :PVOID, :size_t, :ptr WDFMEMORY
PFN_WDFMEMORYCREATEPREALLOCATED typedef ptr proto_PFN_WDFMEMORYCREATEPREALLOCATED
WdfMemoryCreatePreallocated proto fastcall :PWDF_OBJECT_ATTRIBUTES, :PVOID, :size_t, :ptr WDFMEMORY
proto_PFN_WDFMEMORYGETBUFFER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFMEMORY, :ptr size_t
PFN_WDFMEMORYGETBUFFER typedef ptr proto_PFN_WDFMEMORYGETBUFFER
WdfMemoryGetBuffer proto fastcall :WDFMEMORY, :ptr size_t
proto_PFN_WDFMEMORYASSIGNBUFFER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFMEMORY, :PVOID, :size_t
PFN_WDFMEMORYASSIGNBUFFER typedef ptr proto_PFN_WDFMEMORYASSIGNBUFFER
WdfMemoryAssignBuffer proto fastcall :WDFMEMORY, :PVOID, :size_t
proto_PFN_WDFMEMORYCOPYTOBUFFER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFMEMORY, :size_t, :PVOID, :size_t
PFN_WDFMEMORYCOPYTOBUFFER typedef ptr proto_PFN_WDFMEMORYCOPYTOBUFFER
WdfMemoryCopyToBuffer proto fastcall :WDFMEMORY, :size_t, :PVOID, :size_t
proto_PFN_WDFMEMORYCOPYFROMBUFFER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFMEMORY, :size_t, :PVOID, :size_t
PFN_WDFMEMORYCOPYFROMBUFFER typedef ptr proto_PFN_WDFMEMORYCOPYFROMBUFFER
WdfMemoryCopyFromBuffer proto fastcall :WDFMEMORY, :size_t, :PVOID, :size_t
proto_PFN_WDFLOOKASIDELISTCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDF_OBJECT_ATTRIBUTES, :size_t, :POOL_TYPE, :PWDF_OBJECT_ATTRIBUTES, :DWORD, :ptr WDFLOOKASIDE
PFN_WDFLOOKASIDELISTCREATE typedef ptr proto_PFN_WDFLOOKASIDELISTCREATE
WdfLookasideListCreate proto fastcall :PWDF_OBJECT_ATTRIBUTES, :size_t, :POOL_TYPE, :PWDF_OBJECT_ATTRIBUTES, :DWORD, :ptr WDFLOOKASIDE
proto_PFN_WDFMEMORYCREATEFROMLOOKASIDE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFLOOKASIDE, :ptr WDFMEMORY
PFN_WDFMEMORYCREATEFROMLOOKASIDE typedef ptr proto_PFN_WDFMEMORYCREATEFROMLOOKASIDE
WdfMemoryCreateFromLookaside proto fastcall :WDFLOOKASIDE, :ptr WDFMEMORY


;-------------------------------------------------------------------------
; Childlist - wdfchildlist.h
;-------------------------------------------------------------------------

WDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS typedef SDWORD
WdfChildListRetrieveDeviceUndefined EQU 0 
WdfChildListRetrieveDeviceSuccess EQU 1
WdfChildListRetrieveDeviceNotYetCreated EQU 2
WdfChildListRetrieveDeviceNoSuchDevice EQU 3

PWDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS typedef ptr WDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS

WDF_RETRIEVE_CHILD_FLAGS typedef SDWORD
WdfRetrieveUnspecified EQU 0000h 
WdfRetrievePresentChildren EQU 0001h 
WdfRetrieveMissingChildren EQU 0002h 
WdfRetrievePendingChildren EQU 0004h 
WdfRetrieveAddedChildren EQU ( WdfRetrievePresentChildren or WdfRetrievePendingChildren ) 
WdfRetrieveAllChildren EQU ( WdfRetrievePresentChildren or WdfRetrievePendingChildren or WdfRetrieveMissingChildren ) 

WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER struct
    IdentificationDescriptionSize DWORD ?
WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER ends

PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER typedef ptr WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER

WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT proto fastcall :PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER, :DWORD
WDF_CHILD_ADDRESS_DESCRIPTION_HEADER struct
    AddressDescriptionSize DWORD ?
WDF_CHILD_ADDRESS_DESCRIPTION_HEADER ends

PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER typedef ptr WDF_CHILD_ADDRESS_DESCRIPTION_HEADER

WDF_CHILD_ADDRESS_DESCRIPTION_HEADER_INIT proto fastcall :PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER, :DWORD
EVT_WDF_CHILD_LIST_CREATE_DEVICE typedef proto stdcall :WDFCHILDLIST,:PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER,:PWDFDEVICE_INIT
PFN_WDF_CHILD_LIST_CREATE_DEVICE typedef ptr EVT_WDF_CHILD_LIST_CREATE_DEVICE
EVT_WDF_CHILD_LIST_SCAN_FOR_CHILDREN typedef proto stdcall :WDFCHILDLIST
PFN_WDF_CHILD_LIST_SCAN_FOR_CHILDREN typedef ptr EVT_WDF_CHILD_LIST_SCAN_FOR_CHILDREN
EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY typedef proto stdcall :WDFCHILDLIST,:PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER,:PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER
PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY typedef ptr EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY
EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_DUPLICATE typedef proto stdcall :WDFCHILDLIST,:PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER,:PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER
PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_DUPLICATE typedef ptr EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_DUPLICATE
EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE typedef proto stdcall :WDFCHILDLIST,:PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER,:PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER
PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE typedef ptr EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE
EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP typedef proto stdcall :WDFCHILDLIST,:PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER
PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP typedef ptr EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP
EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY typedef proto stdcall :WDFCHILDLIST,:PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER,:PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER
PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY typedef ptr EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY
EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_DUPLICATE typedef proto stdcall :WDFCHILDLIST,:PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER,:PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER
PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_DUPLICATE typedef ptr EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_DUPLICATE
EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP typedef proto stdcall :WDFCHILDLIST,:PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER
PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP typedef ptr EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP
EVT_WDF_CHILD_LIST_DEVICE_REENUMERATED typedef proto stdcall :WDFCHILDLIST,:WDFDEVICE,:PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER,:PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER
PFN_WDF_CHILD_LIST_DEVICE_REENUMERATED typedef ptr EVT_WDF_CHILD_LIST_DEVICE_REENUMERATED
WDF_CHILD_RETRIEVE_INFO struct
    Size_ DWORD ?
    IdentificationDescription PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER ?
    AddressDescription PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER ?
    Status WDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS ?
    EvtChildListIdentificationDescriptionCompare PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE ?
WDF_CHILD_RETRIEVE_INFO ends

PWDF_CHILD_RETRIEVE_INFO typedef ptr WDF_CHILD_RETRIEVE_INFO

WDF_CHILD_RETRIEVE_INFO_INIT proto fastcall :PWDF_CHILD_RETRIEVE_INFO, :PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER
WDF_CHILD_LIST_CONFIG struct
    Size_ DWORD ?
    IdentificationDescriptionSize DWORD ?
    AddressDescriptionSize DWORD ?
    EvtChildListCreateDevice PFN_WDF_CHILD_LIST_CREATE_DEVICE ?
    EvtChildListScanForChildren PFN_WDF_CHILD_LIST_SCAN_FOR_CHILDREN ?
    EvtChildListIdentificationDescriptionCopy PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY ?
    EvtChildListIdentificationDescriptionDuplicate PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_DUPLICATE ?
    EvtChildListIdentificationDescriptionCleanup PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP ?
    EvtChildListIdentificationDescriptionCompare PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE ?
    EvtChildListAddressDescriptionCopy PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY ?
    EvtChildListAddressDescriptionDuplicate PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_DUPLICATE ?
    EvtChildListAddressDescriptionCleanup PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP ?
    EvtChildListDeviceReenumerated PFN_WDF_CHILD_LIST_DEVICE_REENUMERATED ?
WDF_CHILD_LIST_CONFIG ends

PWDF_CHILD_LIST_CONFIG typedef ptr WDF_CHILD_LIST_CONFIG

WDF_CHILD_LIST_CONFIG_INIT proto fastcall :PWDF_CHILD_LIST_CONFIG, :DWORD, :PFN_WDF_CHILD_LIST_CREATE_DEVICE
WDF_CHILD_LIST_ITERATOR struct
    Size_ DWORD ?
    Flags DWORD ?
    Reserved PVOID 4 dup (?)
WDF_CHILD_LIST_ITERATOR ends

PWDF_CHILD_LIST_ITERATOR typedef ptr WDF_CHILD_LIST_ITERATOR

WDF_CHILD_LIST_ITERATOR_INIT proto fastcall :PWDF_CHILD_LIST_ITERATOR, :DWORD
proto_PFN_WDFCHILDLISTCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_CHILD_LIST_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFCHILDLIST
PFN_WDFCHILDLISTCREATE typedef ptr proto_PFN_WDFCHILDLISTCREATE
WdfChildListCreate proto fastcall :WDFDEVICE, :PWDF_CHILD_LIST_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFCHILDLIST
proto_PFN_WDFCHILDLISTGETDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCHILDLIST
PFN_WDFCHILDLISTGETDEVICE typedef ptr proto_PFN_WDFCHILDLISTGETDEVICE
WdfChildListGetDevice proto fastcall :WDFCHILDLIST
proto_PFN_WDFCHILDLISTRETRIEVEPDO typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCHILDLIST, :PWDF_CHILD_RETRIEVE_INFO
PFN_WDFCHILDLISTRETRIEVEPDO typedef ptr proto_PFN_WDFCHILDLISTRETRIEVEPDO
WdfChildListRetrievePdo proto fastcall :WDFCHILDLIST, :PWDF_CHILD_RETRIEVE_INFO
proto_PFN_WDFCHILDLISTRETRIEVEADDRESSDESCRIPTION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCHILDLIST, :PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER, :PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER
PFN_WDFCHILDLISTRETRIEVEADDRESSDESCRIPTION typedef ptr proto_PFN_WDFCHILDLISTRETRIEVEADDRESSDESCRIPTION
WdfChildListRetrieveAddressDescription proto fastcall :WDFCHILDLIST, :PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER, :PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER
proto_PFN_WDFCHILDLISTBEGINSCAN typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCHILDLIST
PFN_WDFCHILDLISTBEGINSCAN typedef ptr proto_PFN_WDFCHILDLISTBEGINSCAN
WdfChildListBeginScan proto fastcall :WDFCHILDLIST
proto_PFN_WDFCHILDLISTENDSCAN typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCHILDLIST
PFN_WDFCHILDLISTENDSCAN typedef ptr proto_PFN_WDFCHILDLISTENDSCAN
WdfChildListEndScan proto fastcall :WDFCHILDLIST
proto_PFN_WDFCHILDLISTBEGINITERATION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCHILDLIST, :PWDF_CHILD_LIST_ITERATOR
PFN_WDFCHILDLISTBEGINITERATION typedef ptr proto_PFN_WDFCHILDLISTBEGINITERATION
WdfChildListBeginIteration proto fastcall :WDFCHILDLIST, :PWDF_CHILD_LIST_ITERATOR
proto_PFN_WDFCHILDLISTRETRIEVENEXTDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCHILDLIST, :PWDF_CHILD_LIST_ITERATOR, :ptr WDFDEVICE, :PWDF_CHILD_RETRIEVE_INFO
PFN_WDFCHILDLISTRETRIEVENEXTDEVICE typedef ptr proto_PFN_WDFCHILDLISTRETRIEVENEXTDEVICE
WdfChildListRetrieveNextDevice proto fastcall :WDFCHILDLIST, :PWDF_CHILD_LIST_ITERATOR, :ptr WDFDEVICE, :PWDF_CHILD_RETRIEVE_INFO
proto_PFN_WDFCHILDLISTENDITERATION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCHILDLIST, :PWDF_CHILD_LIST_ITERATOR
PFN_WDFCHILDLISTENDITERATION typedef ptr proto_PFN_WDFCHILDLISTENDITERATION
WdfChildListEndIteration proto fastcall :WDFCHILDLIST, :PWDF_CHILD_LIST_ITERATOR
proto_PFN_WDFCHILDLISTADDORUPDATECHILDDESCRIPTIONASPRESENT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCHILDLIST, :PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER, :PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER
PFN_WDFCHILDLISTADDORUPDATECHILDDESCRIPTIONASPRESENT typedef ptr proto_PFN_WDFCHILDLISTADDORUPDATECHILDDESCRIPTIONASPRESENT
WdfChildListAddOrUpdateChildDescriptionAsPresent proto fastcall :WDFCHILDLIST, :PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER, :PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER
proto_PFN_WDFCHILDLISTUPDATECHILDDESCRIPTIONASMISSING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCHILDLIST, :PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER
PFN_WDFCHILDLISTUPDATECHILDDESCRIPTIONASMISSING typedef ptr proto_PFN_WDFCHILDLISTUPDATECHILDDESCRIPTIONASMISSING
WdfChildListUpdateChildDescriptionAsMissing proto fastcall :WDFCHILDLIST, :PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER
proto_PFN_WDFCHILDLISTUPDATEALLCHILDDESCRIPTIONSASPRESENT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCHILDLIST
PFN_WDFCHILDLISTUPDATEALLCHILDDESCRIPTIONSASPRESENT typedef ptr proto_PFN_WDFCHILDLISTUPDATEALLCHILDDESCRIPTIONSASPRESENT
WdfChildListUpdateAllChildDescriptionsAsPresent proto fastcall :WDFCHILDLIST
proto_PFN_WDFCHILDLISTREQUESTCHILDEJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCHILDLIST, :PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER
PFN_WDFCHILDLISTREQUESTCHILDEJECT typedef ptr proto_PFN_WDFCHILDLISTREQUESTCHILDEJECT
WdfChildListRequestChildEject proto fastcall :WDFCHILDLIST, :PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER


;-------------------------------------------------------------------------
; wdffileobject.h
;-------------------------------------------------------------------------
proto_PFN_WDFFILEOBJECTGETFILENAME typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFFILEOBJECT
PFN_WDFFILEOBJECTGETFILENAME typedef ptr proto_PFN_WDFFILEOBJECTGETFILENAME
WdfFileObjectGetFileName proto fastcall :WDFFILEOBJECT
proto_PFN_WDFFILEOBJECTGETFLAGS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFFILEOBJECT
PFN_WDFFILEOBJECTGETFLAGS typedef ptr proto_PFN_WDFFILEOBJECTGETFLAGS
WdfFileObjectGetFlags proto fastcall :WDFFILEOBJECT
proto_PFN_WDFFILEOBJECTGETDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFFILEOBJECT
PFN_WDFFILEOBJECTGETDEVICE typedef ptr proto_PFN_WDFFILEOBJECTGETDEVICE
WdfFileObjectGetDevice proto fastcall :WDFFILEOBJECT
proto_PFN_WDFFILEOBJECTWDMGETFILEOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFFILEOBJECT
PFN_WDFFILEOBJECTWDMGETFILEOBJECT typedef ptr proto_PFN_WDFFILEOBJECTWDMGETFILEOBJECT
WdfFileObjectWdmGetFileObject proto fastcall :WDFFILEOBJECT


;-------------------------------------------------------------------------
; wdfdevice.h
;-------------------------------------------------------------------------
WDF_DEVICE_STATE_FLAGS typedef SDWORD
WdfDevStateNP EQU 8000h 

WDF_DEVICE_PNP_STATE typedef SDWORD
WdfDevStatePnpInvalid EQU 00h 
WdfDevStatePnpObjectCreated EQU 100h 
WdfDevStatePnpCheckForDevicePresence EQU 101h 
WdfDevStatePnpEjectFailed EQU 102h 
WdfDevStatePnpEjectHardware EQU 103h 
WdfDevStatePnpEjectedWaitingForRemove EQU 104h 
WdfDevStatePnpInit EQU 105h 
WdfDevStatePnpInitStarting EQU 106h 
WdfDevStatePnpInitSurpriseRemoved EQU 107h 
WdfDevStatePnpHardwareAvailable EQU 108h 
WdfDevStatePnpEnableInterfaces EQU 109h 
WdfDevStatePnpHardwareAvailablePowerPolicyFailed EQU 10Ah 
WdfDevStatePnpQueryRemoveAskDriver EQU 10Bh 
WdfDevStatePnpQueryRemovePending EQU 10Ch 
WdfDevStatePnpQueryRemoveStaticCheck EQU 10Dh 
WdfDevStatePnpQueriedRemoving EQU 10Eh 
WdfDevStatePnpQueryStopAskDriver EQU 10Fh 
WdfDevStatePnpQueryStopPending EQU 110h 
WdfDevStatePnpQueryStopStaticCheck EQU 111h 
WdfDevStatePnpQueryCanceled EQU 112h 
WdfDevStatePnpRemoved EQU 113h 
WdfDevStatePnpPdoRemoved EQU 114h 
WdfDevStatePnpRemovedPdoWait EQU 115h 
WdfDevStatePnpRemovedPdoSurpriseRemoved EQU 116h 
WdfDevStatePnpRemovingDisableInterfaces EQU 117h 
WdfDevStatePnpRestarting EQU 118h 
WdfDevStatePnpStarted EQU 119h 
WdfDevStatePnpStartedCancelStop EQU 11Ah 
WdfDevStatePnpStartedCancelRemove EQU 11Bh 
WdfDevStatePnpStartedRemoving EQU 11Ch 
WdfDevStatePnpStartingFromStopped EQU 11Dh 
WdfDevStatePnpStopped EQU 11Eh 
WdfDevStatePnpStoppedWaitForStartCompletion EQU 11Fh 
WdfDevStatePnpStartedStopping EQU 120h 
WdfDevStatePnpSurpriseRemove EQU 121h 
WdfDevStatePnpInitQueryRemove EQU 122h 
WdfDevStatePnpInitQueryRemoveCanceled EQU 123h 
WdfDevStatePnpFdoRemoved EQU 124h 
WdfDevStatePnpRemovedWaitForChildren EQU 125h 
WdfDevStatePnpQueriedSurpriseRemove EQU 126h 
WdfDevStatePnpSurpriseRemoveIoStarted EQU 127h 
WdfDevStatePnpFailedPowerDown EQU 128h 
WdfDevStatePnpFailedIoStarting EQU 129h 
WdfDevStatePnpFailedOwnHardware EQU 12Ah 
WdfDevStatePnpFailed EQU 12Bh 
WdfDevStatePnpFailedSurpriseRemoved EQU 12Ch 
WdfDevStatePnpFailedStarted EQU 12Dh 
WdfDevStatePnpFailedWaitForRemove EQU 12Eh 
WdfDevStatePnpFailedInit EQU 12Fh 
WdfDevStatePnpPdoInitFailed EQU 130h 
WdfDevStatePnpRestart EQU 131h 
WdfDevStatePnpRestartReleaseHardware EQU 132h 
WdfDevStatePnpRestartHardwareAvailable EQU 133h 
WdfDevStatePnpPdoRestart EQU 134h 
WdfDevStatePnpFinal EQU 135h 
WdfDevStatePnpRemovedChildrenRemoved EQU 136h 
WdfDevStatePnpQueryRemoveEnsureDeviceAwake EQU 137h 
WdfDevStatePnpQueryStopEnsureDeviceAwake EQU 138h 
WdfDevStatePnpNull EQU 139h 

PWDF_DEVICE_PNP_STATE typedef ptr WDF_DEVICE_PNP_STATE

WDF_DEVICE_POWER_STATE typedef SDWORD
WdfDevStatePowerInvalid EQU 00h 
WdfDevStatePowerObjectCreated EQU 300h 
WdfDevStatePowerCheckDeviceType EQU 301h 
WdfDevStatePowerCheckDeviceTypeNP EQU 302h or WdfDevStateNP 
WdfDevStatePowerCheckParentState EQU 303h 
WdfDevStatePowerCheckParentStateNP EQU 304h or WdfDevStateNP 
WdfDevStatePowerEnablingWakeAtBus EQU 305h 
WdfDevStatePowerEnablingWakeAtBusNP EQU 306h or WdfDevStateNP 
WdfDevStatePowerD0 EQU 307h 
WdfDevStatePowerD0NP EQU 308h or WdfDevStateNP 
WdfDevStatePowerD0BusWakeOwner EQU 309h 
WdfDevStatePowerD0BusWakeOwnerNP EQU 30Ah or WdfDevStateNP 
WdfDevStatePowerD0ArmedForWake EQU 30Bh 
WdfDevStatePowerD0ArmedForWakeNP EQU 30Ch or WdfDevStateNP 
WdfDevStatePowerD0DisarmingWakeAtBus EQU 30Dh 
WdfDevStatePowerD0DisarmingWakeAtBusNP EQU 30Eh or WdfDevStateNP 
WdfDevStatePowerD0Starting EQU 30Fh 
WdfDevStatePowerD0StartingConnectInterrupt EQU 310h 
WdfDevStatePowerD0StartingDmaEnable EQU 311h 
WdfDevStatePowerD0StartingStartSelfManagedIo EQU 312h 
WdfDevStatePowerDecideD0State EQU 313h 
WdfDevStatePowerGotoD3Stopped EQU 314h 
WdfDevStatePowerStopped EQU 315h 
WdfDevStatePowerStartingCheckDeviceType EQU 316h 
WdfDevStatePowerStartingChild EQU 317h 
WdfDevStatePowerDxDisablingWakeAtBus EQU 318h 
WdfDevStatePowerDxDisablingWakeAtBusNP EQU 319h or WdfDevStateNP 
WdfDevStatePowerGotoDx EQU 31Ah 
WdfDevStatePowerGotoDxNP EQU 31Bh or WdfDevStateNP 
WdfDevStatePowerGotoDxIoStopped EQU 31Ch 
WdfDevStatePowerGotoDxIoStoppedNP EQU 31Dh or WdfDevStateNP 
WdfDevStatePowerGotoDxNPFailed EQU 31Eh or WdfDevStateNP 
WdfDevStatePowerDx EQU 31Fh 
WdfDevStatePowerDxNP EQU 320h or WdfDevStateNP 
WdfDevStatePowerGotoDxArmedForWake EQU 321h 
WdfDevStatePowerGotoDxArmedForWakeNP EQU 322h or WdfDevStateNP 
WdfDevStatePowerGotoDxIoStoppedArmedForWake EQU 323h 
WdfDevStatePowerGotoDxIoStoppedArmedForWakeNP EQU 324h or WdfDevStateNP 
WdfDevStatePowerDxArmedForWake EQU 325h 
WdfDevStatePowerDxArmedForWakeNP EQU 326h or WdfDevStateNP 
WdfDevStatePowerCheckParentStateArmedForWake EQU 327h 
WdfDevStatePowerCheckParentStateArmedForWakeNP EQU 328h or WdfDevStateNP 
WdfDevStatePowerWaitForParentArmedForWake EQU 329h 
WdfDevStatePowerWaitForParentArmedForWakeNP EQU 32Ah or WdfDevStateNP 
WdfDevStatePowerStartSelfManagedIo EQU 32Bh 
WdfDevStatePowerStartSelfManagedIoNP EQU 32Ch or WdfDevStateNP 
WdfDevStatePowerStartSelfManagedIoFailed EQU 32Dh 
WdfDevStatePowerStartSelfManagedIoFailedNP EQU 32Eh or WdfDevStateNP 
WdfDevStatePowerWaitForParent EQU 32Fh 
WdfDevStatePowerWaitForParentNP EQU 330h or WdfDevStateNP 
WdfDevStatePowerWakePending EQU 331h 
WdfDevStatePowerWakePendingNP EQU 332h or WdfDevStateNP 
WdfDevStatePowerWaking EQU 333h 
WdfDevStatePowerWakingNP EQU 334h or WdfDevStateNP 
WdfDevStatePowerWakingConnectInterrupt EQU 335h 
WdfDevStatePowerWakingConnectInterruptNP EQU 336h or WdfDevStateNP 
WdfDevStatePowerWakingConnectInterruptFailed EQU 337h 
WdfDevStatePowerWakingConnectInterruptFailedNP EQU 338h or WdfDevStateNP 
WdfDevStatePowerWakingDmaEnable EQU 339h 
WdfDevStatePowerWakingDmaEnableNP EQU 33Ah or WdfDevStateNP 
WdfDevStatePowerWakingDmaEnableFailed EQU 33Bh 
WdfDevStatePowerWakingDmaEnableFailedNP EQU 33Ch or WdfDevStateNP 
WdfDevStatePowerReportPowerUpFailedDerefParent EQU 33Dh 
WdfDevStatePowerReportPowerUpFailed EQU 33Eh 
WdfDevStatePowerPowerFailedPowerDown EQU 33Fh 
WdfDevStatePowerReportPowerDownFailed EQU 340h 
WdfDevStatePowerInitialConnectInterruptFailed EQU 341h 
WdfDevStatePowerInitialDmaEnableFailed EQU 342h 
WdfDevStatePowerInitialSelfManagedIoFailed EQU 343h 
WdfDevStatePowerInitialPowerUpFailedDerefParent EQU 344h 
WdfDevStatePowerInitialPowerUpFailed EQU 345h 
WdfDevStatePowerDxStoppedDisarmWake EQU 346h 
WdfDevStatePowerDxStoppedDisarmWakeNP EQU 347h or WdfDevStateNP 
WdfDevStatePowerGotoDxStoppedDisableInterruptNP EQU 348h or WdfDevStateNP 
WdfDevStatePowerGotoDxStopped EQU 349h 
WdfDevStatePowerDxStopped EQU 34Ah 
WdfDevStatePowerGotoStopped EQU 34Bh 
WdfDevStatePowerStoppedCompleteDx EQU 34Ch 
WdfDevStatePowerDxStoppedDecideDxState EQU 34Dh 
WdfDevStatePowerDxStoppedArmForWake EQU 34Eh 
WdfDevStatePowerDxStoppedArmForWakeNP EQU 34Fh or WdfDevStateNP 
WdfDevStatePowerFinalPowerDownFailed EQU 350h 
WdfDevStatePowerFinal EQU 351h 
WdfDevStatePowerNull EQU 352h 

PWDF_DEVICE_POWER_STATE typedef ptr WDF_DEVICE_POWER_STATE

WDF_DEVICE_POWER_POLICY_STATE typedef SDWORD
WdfDevStatePwrPolInvalid EQU 00h 
WdfDevStatePwrPolObjectCreated EQU 500h 
WdfDevStatePwrPolStarting EQU 501h 
WdfDevStatePwrPolStartingSucceeded EQU 502h 
WdfDevStatePwrPolStartingFailed EQU 503h 
WdfDevStatePwrPolStartingDecideS0Wake EQU 504h 
WdfDevStatePwrPolStartedIdleCapable EQU 505h 
WdfDevStatePwrPolTimerExpiredNoWake EQU 506h 
WdfDevStatePwrPolTimerExpiredNoWakeCompletePowerDown EQU 507h 
WdfDevStatePwrPolWaitingUnarmed EQU 508h 
WdfDevStatePwrPolWaitingUnarmedQueryIdle EQU 509h 
WdfDevStatePwrPolS0NoWakePowerUp EQU 50Ah 
WdfDevStatePwrPolS0NoWakeCompletePowerUp EQU 50Bh 
WdfDevStatePwrPolSystemSleepFromDeviceWaitingUnarmed EQU 50Ch 
WdfDevStatePwrPolSystemSleepNeedWake EQU 50Dh 
WdfDevStatePwrPolSystemSleepNeedWakeCompletePowerUp EQU 50Eh 
WdfDevStatePwrPolSystemSleepPowerRequestFailed EQU 50Fh 
WdfDevStatePwrPolCheckPowerPageable EQU 510h 
WdfDevStatePwrPolSleepingWakeWakeArrived EQU 511h 
WdfDevStatePwrPolSleepingWakeRevertArmWake EQU 512h 
WdfDevStatePwrPolSystemAsleepWakeArmed EQU 513h 
WdfDevStatePwrPolSystemWakeDeviceWakeEnabled EQU 514h 
WdfDevStatePwrPolSystemWakeDeviceWakeEnabledWakeCanceled EQU 515h 
WdfDevStatePwrPolSystemWakeDeviceWakeDisarm EQU 516h 
WdfDevStatePwrPolSystemWakeDeviceWakeTriggered EQU 517h 
WdfDevStatePwrPolSystemWakeDeviceWakeTriggeredS0 EQU 518h 
WdfDevStatePwrPolSystemWakeDeviceWokeDisarm EQU 519h 
WdfDevStatePwrPolSleepingWakeWakeArrivedNP EQU 51Ah or WdfDevStateNP 
WdfDevStatePwrPolSleepingWakeRevertArmWakeNP EQU 51Bh or WdfDevStateNP 
WdfDevStatePwrPolSleepingWakePowerDownFailed EQU 51Ch 
WdfDevStatePwrPolSleepingWakePowerDownFailedWakeCanceled EQU 51Dh 
WdfDevStatePwrPolSystemAsleepWakeArmedNP EQU 51Eh or WdfDevStateNP 
WdfDevStatePwrPolSystemWakeDeviceWakeEnabledNP EQU 51Fh or WdfDevStateNP 
WdfDevStatePwrPolSystemWakeDeviceWakeEnabledWakeCanceledNP EQU 520h or WdfDevStateNP 
WdfDevStatePwrPolSystemWakeDeviceWakeDisarmNP EQU 521h or WdfDevStateNP 
WdfDevStatePwrPolSystemWakeDeviceWakeTriggeredNP EQU 522h or WdfDevStateNP 
WdfDevStatePwrPolSystemWakeDeviceWakeTriggeredS0NP EQU 523h or WdfDevStateNP 
WdfDevStatePwrPolSystemWakeDeviceWokeDisarmNP EQU 524h or WdfDevStateNP 
WdfDevStatePwrPolSystemWakeDeviceWakeCompletePowerUp EQU 525h 
WdfDevStatePwrPolSleeping EQU 526h 
WdfDevStatePwrPolSleepingNoWakePowerDown EQU 527h 
WdfDevStatePwrPolSleepingNoWakeCompletePowerDown EQU 528h 
WdfDevStatePwrPolSleepingNoWakeDxRequestFailed EQU 529h 
WdfDevStatePwrPolSleepingWakePowerDown EQU 52Ah 
WdfDevStatePwrPolSleepingSendWake EQU 52Bh 
WdfDevStatePwrPolSystemAsleepNoWake EQU 52Ch 
WdfDevStatePwrPolSystemWakeDeviceWakeDisabled EQU 52Dh 
WdfDevStatePwrPolSystemWakeDeviceToD0 EQU 52Eh 
WdfDevStatePwrPolSystemWakeDeviceToD0CompletePowerUp EQU 52Fh 
WdfDevStatePwrPolSystemWakeQueryIdle EQU 530h 
WdfDevStatePwrPolStartedWakeCapable EQU 531h 
WdfDevStatePwrPolTimerExpiredDecideUsbSS EQU 532h 
WdfDevStatePwrPolTimerExpiredWakeCapablePowerDown EQU 533h 
WdfDevStatePwrPolTimerExpiredWakeCapableSendWake EQU 534h 
WdfDevStatePwrPolTimerExpiredWakeCapableUsbSS EQU 535h 
WdfDevStatePwrPolTimerExpiredWakeCapableWakeArrived EQU 536h 
WdfDevStatePwrPolTimerExpiredWakeCapableCancelWake EQU 537h 
WdfDevStatePwrPolTimerExpiredWakeCapableWakeCanceled EQU 538h 
WdfDevStatePwrPolTimerExpiredWakeCapableCleanup EQU 539h 
WdfDevStatePwrPolTimerExpiredWakeCapableDxAllocFailed EQU 53Ah 
WdfDevStatePwrPolTimerExpiredWakeCompletedPowerDown EQU 53Bh 
WdfDevStatePwrPolTimerExpiredWakeCompletedPowerUp EQU 53Ch 
WdfDevStatePwrPolWaitingArmedUsbSS EQU 53Dh 
WdfDevStatePwrPolWaitingArmed EQU 53Eh 
WdfDevStatePwrPolWaitingArmedQueryIdle EQU 53Fh 
WdfDevStatePwrPolIoPresentArmed EQU 540h 
WdfDevStatePwrPolIoPresentArmedWakeCanceled EQU 541h 
WdfDevStatePwrPolS0WakeDisarm EQU 542h 
WdfDevStatePwrPolS0WakeCompletePowerUp EQU 543h 
WdfDevStatePwrPolTimerExpiredWakeSucceeded EQU 544h 
WdfDevStatePwrPolTimerExpiredWakeCompletedDisarm EQU 545h 
WdfDevStatePwrPolTimerExpiredWakeCapableWakeSucceeded EQU 546h 
WdfDevStatePwrPolTimerExpiredWakeCapableWakeFailed EQU 547h 
WdfDevStatePwrPolWakeFailedUsbSS EQU 548h 
WdfDevStatePwrPolTimerExpiredWakeCapablePowerDownFailedCancelWake EQU 549h 
WdfDevStatePwrPolTimerExpiredWakeCapablePowerDownFailedWakeCanceled EQU 54Ah 
WdfDevStatePwrPolTimerExpiredWakeCapablePowerDownFailedUsbSS EQU 54Bh 
WdfDevStatePwrPolCancelingWakeForSystemSleep EQU 54Ch 
WdfDevStatePwrPolCancelingWakeForSystemSleepWakeCanceled EQU 54Dh 
WdfDevStatePwrPolDisarmingWakeForSystemSleepCompletePowerUp EQU 54Eh 
WdfDevStatePwrPolPowerUpForSystemSleepFailed EQU 54Fh 
WdfDevStatePwrPolWokeFromS0UsbSS EQU 550h 
WdfDevStatePwrPolWokeFromS0 EQU 551h 
WdfDevStatePwrPolWokeFromS0NotifyDriver EQU 552h 
WdfDevStatePwrPolStoppingResetDevice EQU 553h 
WdfDevStatePwrPolStoppingResetDeviceCompletePowerUp EQU 554h 
WdfDevStatePwrPolStoppingResetDeviceFailed EQU 555h 
WdfDevStatePwrPolStoppingD0 EQU 556h 
WdfDevStatePwrPolStoppingD0Failed EQU 557h 
WdfDevStatePwrPolStoppingDisarmWake EQU 558h 
WdfDevStatePwrPolStoppingDisarmWakeCancelWake EQU 559h 
WdfDevStatePwrPolStoppingDisarmWakeWakeCanceled EQU 55Ah 
WdfDevStatePwrPolStopping EQU 55Bh 
WdfDevStatePwrPolStoppingFailed EQU 55Ch 
WdfDevStatePwrPolStoppingSendStatus EQU 55Dh 
WdfDevStatePwrPolStoppingCancelTimer EQU 55Eh 
WdfDevStatePwrPolStoppingWaitForIdleTimeout EQU 55Fh 
WdfDevStatePwrPolStoppingCancelUsbSS EQU 560h 
WdfDevStatePwrPolStoppingWaitForUsbSSCompletion EQU 561h 
WdfDevStatePwrPolStoppingCancelWake EQU 562h 
WdfDevStatePwrPolStopped EQU 563h 
WdfDevStatePwrPolCancelUsbSS EQU 564h 
WdfDevStatePwrPolStarted EQU 565h 
WdfDevStatePwrPolStartedCancelTimer EQU 566h 
WdfDevStatePwrPolStartedWaitForIdleTimeout EQU 567h 
WdfDevStatePwrPolStartedWakeCapableCancelTimerForSleep EQU 568h 
WdfDevStatePwrPolStartedWakeCapableWaitForIdleTimeout EQU 569h 
WdfDevStatePwrPolStartedWakeCapableSleepingUsbSS EQU 56Ah 
WdfDevStatePwrPolStartedIdleCapableCancelTimerForSleep EQU 56Bh 
WdfDevStatePwrPolStartedIdleCapableWaitForIdleTimeout EQU 56Ch 
WdfDevStatePwrPolDeviceD0PowerRequestFailed EQU 56Dh 
WdfDevStatePwrPolDevicePowerRequestFailed EQU 56Eh 
WdfDevStatePwrPolGotoDx EQU 56Fh 
WdfDevStatePwrPolGotoDxInDx EQU 570h 
WdfDevStatePwrPolDx EQU 571h 
WdfDevStatePwrPolGotoD0 EQU 572h 
WdfDevStatePwrPolGotoD0InD0 EQU 573h 
WdfDevStatePwrPolFinal EQU 574h 
WdfDevStatePwrPolSleepingPowerDownNotProcessed EQU 575h 
WdfDevStatePwrPolTimerExpiredWakeCapablePowerDownNotProcessed EQU 576h 
WdfDevStatePwrPolTimerExpiredNoWakePowerDownNotProcessed EQU 577h 
WdfDevStatePwrPolTimerExpiredNoWakePoweredDownDisableIdleTimer EQU 578h 
WdfDevStatePwrPolStoppingWaitingForImplicitPowerDown EQU 579h 
WdfDevStatePwrPolStoppingPoweringUp EQU 57Ah 
WdfDevStatePwrPolStoppingPoweringDown EQU 57Bh 
WdfDevStatePwrPolPowerUpForSystemSleepNotSeen EQU 57Ch 
WdfDevStatePwrPolWaitingArmedStoppingCancelUsbSS EQU 57Dh 
WdfDevStatePwrPolWaitingArmedWakeFailedCancelUsbSS EQU 57Eh 
WdfDevStatePwrPolWaitingArmedIoPresentCancelUsbSS EQU 57Fh 
WdfDevStatePwrPolWaitingArmedWakeSucceededCancelUsbSS EQU 580h 
WdfDevStatePwrPolCancelingUsbSSForSystemSleep EQU 581h 
WdfDevStatePwrPolStoppingD0CancelUsbSS EQU 582h 
WdfDevStatePwrPolNull EQU 583h 

PWDF_DEVICE_POWER_POLICY_STATE typedef ptr WDF_DEVICE_POWER_POLICY_STATE

WDF_STATE_NOTIFICATION_TYPE typedef SDWORD
StateNotificationInvalid EQU 0000h 
StateNotificationEnterState EQU 0001h 
StateNotificationPostProcessState EQU 0002h 
StateNotificationLeaveState EQU 0004h 
StateNotificationAllStates EQU StateNotificationEnterState or StateNotificationPostProcessState or StateNotificationLeaveState 

WDF_POWER_POLICY_S0_IDLE_CAPABILITIES typedef SDWORD
IdleCapsInvalid EQU 0 
IdleCannotWakeFromS0 EQU 1
IdleCanWakeFromS0 EQU 2
IdleUsbSelectiveSuspend EQU 3

WDF_POWER_POLICY_S0_IDLE_USER_CONTROL typedef SDWORD
IdleUserControlInvalid EQU 0 
IdleDoNotAllowUserControl EQU 1
IdleAllowUserControl EQU 2

WDF_POWER_POLICY_IDLE_TIMEOUT_CONSTANTS typedef SDWORD
IdleTimeoutDefaultConstant EQU 0 

WDF_POWER_POLICY_SX_WAKE_USER_CONTROL typedef SDWORD
WakeUserControlInvalid EQU 0 
WakeDoNotAllowUserControl EQU 1
WakeAllowUserControl EQU 2

WDF_POWER_DEVICE_STATE typedef SDWORD
WdfPowerDeviceInvalid EQU 0 
WdfPowerDeviceD0 EQU 1
WdfPowerDeviceD1 EQU 2
WdfPowerDeviceD2 EQU 3
WdfPowerDeviceD3 EQU 4
WdfPowerDeviceD3Final EQU 5
WdfPowerDevicePrepareForHibernation EQU 6
WdfPowerDeviceMaximum EQU 7

PWDF_POWER_DEVICE_STATE typedef ptr WDF_POWER_DEVICE_STATE

WDF_SPECIAL_FILE_TYPE typedef SDWORD
WdfSpecialFileUndefined EQU 0 
WdfSpecialFilePaging EQU 1 
WdfSpecialFileHibernation EQU 2
WdfSpecialFileDump EQU 3
WdfSpecialFileMax EQU 4

PWDF_SPECIAL_FILE_TYPE typedef ptr WDF_SPECIAL_FILE_TYPE

WDF_DEVICE_IO_TYPE typedef SDWORD
WdfDeviceIoUndefined EQU 0 
WdfDeviceIoNeither EQU 1
WdfDeviceIoBuffered EQU 2
WdfDeviceIoDirect EQU 3

PWDF_DEVICE_IO_TYPE typedef ptr WDF_DEVICE_IO_TYPE

WDF_FILEOBJECT_CLASS typedef SDWORD
WdfFileObjectInvalid EQU 0 
WdfFileObjectNotRequired EQU 1 
WdfFileObjectWdfCanUseFsContext EQU 2 
WdfFileObjectWdfCanUseFsContext2 EQU 3 
WdfFileObjectWdfCannotUseFsContexts EQU 4 
WdfFileObjectCanBeOptional EQU 80000000h 

PWDF_FILEOBJECT_CLASS typedef ptr WDF_FILEOBJECT_CLASS

WDF_DEVICE_FAILED_ACTION typedef SDWORD
WdfDeviceFailedUndefined EQU 0 
WdfDeviceFailedAttemptRestart EQU 1
WdfDeviceFailedNoRestart EQU 2

WDF_S0_IDLE_ENABLED_VALUE_NAME equ <L("IdleInWorkingState",0)>
WDF_SX_WAKE_ENABLED_VALUE_NAME equ <L("WakeFromSleepState",0)>
WDF_S0_IDLE_DEFAULT_VALUE_NAME equ <L("WdfDefaultIdleInWorkingState",0)>
WDF_SX_WAKE_DEFAULT_VALUE_NAME equ <L("WdfDefaultWakeFromSleepState",0)>
WDF_REQUEST_TYPE typedef SDWORD
EVT_WDF_DEVICE_FILE_CREATE typedef proto stdcall :WDFDEVICE,:WDFREQUEST,:WDFFILEOBJECT
PFN_WDF_DEVICE_FILE_CREATE typedef ptr EVT_WDF_DEVICE_FILE_CREATE
EVT_WDF_FILE_CLOSE typedef proto stdcall :WDFFILEOBJECT
PFN_WDF_FILE_CLOSE typedef ptr EVT_WDF_FILE_CLOSE
EVT_WDF_FILE_CLEANUP typedef proto stdcall :WDFFILEOBJECT
PFN_WDF_FILE_CLEANUP typedef ptr EVT_WDF_FILE_CLEANUP
WDF_FILEOBJECT_CONFIG struct
    Size_ DWORD ?
    EvtDeviceFileCreate PFN_WDF_DEVICE_FILE_CREATE ?
    EvtFileClose PFN_WDF_FILE_CLOSE ?
    EvtFileCleanup PFN_WDF_FILE_CLEANUP ?
    AutoForwardCleanupClose WDF_TRI_STATE ?
    FileObjectClass WDF_FILEOBJECT_CLASS ?
WDF_FILEOBJECT_CONFIG ends

PWDF_FILEOBJECT_CONFIG typedef ptr WDF_FILEOBJECT_CONFIG

WDF_FILEOBJECT_CONFIG_INIT proto fastcall :PWDF_FILEOBJECT_CONFIG, :PFN_WDF_DEVICE_FILE_CREATE, :PFN_WDF_FILE_CLOSE, :PFN_WDF_FILE_CLEANUP
WDF_DEVICE_PNP_NOTIFICATION_DATA struct
    Type_ WDF_STATE_NOTIFICATION_TYPE ?
    union Data
        struct EnterState
            CurrentState WDF_DEVICE_PNP_STATE ?
            NewState WDF_DEVICE_PNP_STATE ?
        ends
        struct PostProcessState
            CurrentState WDF_DEVICE_PNP_STATE ?
        ends
        struct LeaveState
            CurrentState WDF_DEVICE_PNP_STATE ?
            NewState WDF_DEVICE_PNP_STATE ?
        ends
    ends
WDF_DEVICE_PNP_NOTIFICATION_DATA ends

PCWDF_DEVICE_PNP_NOTIFICATION_DATA typedef ptr WDF_DEVICE_PNP_NOTIFICATION_DATA
WDF_DEVICE_POWER_NOTIFICATION_DATA struct
    Type_ WDF_STATE_NOTIFICATION_TYPE ?
    union Data
        struct EnterState
            CurrentState WDF_DEVICE_POWER_STATE ?
            NewState WDF_DEVICE_POWER_STATE ?
        ends
        struct PostProcessState
            CurrentState WDF_DEVICE_POWER_STATE ?
        ends
        struct LeaveState
            CurrentState WDF_DEVICE_POWER_STATE ?
            NewState WDF_DEVICE_POWER_STATE ?
        ends
    ends
WDF_DEVICE_POWER_NOTIFICATION_DATA ends

PCWDF_DEVICE_POWER_NOTIFICATION_DATA typedef ptr WDF_DEVICE_POWER_NOTIFICATION_DATA
WDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA struct
    Type_ WDF_STATE_NOTIFICATION_TYPE ?
    union Data
        struct EnterState
            CurrentState WDF_DEVICE_POWER_POLICY_STATE ?
            NewState WDF_DEVICE_POWER_POLICY_STATE ?
        ends
        struct PostProcessState
            CurrentState WDF_DEVICE_POWER_POLICY_STATE ?
        ends
        struct LeaveState
            CurrentState WDF_DEVICE_POWER_POLICY_STATE ?
            NewState WDF_DEVICE_POWER_POLICY_STATE ?
        ends
    ends
WDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA ends

PCWDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA typedef ptr WDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA
EVT_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION typedef proto stdcall :WDFDEVICE,:PCWDF_DEVICE_PNP_NOTIFICATION_DATA
PFN_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION typedef ptr EVT_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION
EVT_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION typedef proto stdcall :WDFDEVICE,:PCWDF_DEVICE_POWER_NOTIFICATION_DATA
PFN_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION typedef ptr EVT_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION
EVT_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION typedef proto stdcall :WDFDEVICE,:PCWDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA
PFN_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION typedef ptr EVT_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION
IdleTimeoutDefaultValue equ <( IdleTimeoutDefaultConstant )>
EVT_WDF_DEVICE_D0_ENTRY typedef proto stdcall :WDFDEVICE,:WDF_POWER_DEVICE_STATE
PFN_WDF_DEVICE_D0_ENTRY typedef ptr EVT_WDF_DEVICE_D0_ENTRY
EVT_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED typedef proto stdcall :WDFDEVICE,:WDF_POWER_DEVICE_STATE
PFN_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED typedef ptr EVT_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED
EVT_WDF_DEVICE_D0_EXIT typedef proto stdcall :WDFDEVICE,:WDF_POWER_DEVICE_STATE
PFN_WDF_DEVICE_D0_EXIT typedef ptr EVT_WDF_DEVICE_D0_EXIT
EVT_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED typedef proto stdcall :WDFDEVICE,:WDF_POWER_DEVICE_STATE
PFN_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED typedef ptr EVT_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED
EVT_WDF_DEVICE_PREPARE_HARDWARE typedef proto stdcall :WDFDEVICE,:WDFCMRESLIST,:WDFCMRESLIST
PFN_WDF_DEVICE_PREPARE_HARDWARE typedef ptr EVT_WDF_DEVICE_PREPARE_HARDWARE
EVT_WDF_DEVICE_RELEASE_HARDWARE typedef proto stdcall :WDFDEVICE,:WDFCMRESLIST
PFN_WDF_DEVICE_RELEASE_HARDWARE typedef ptr EVT_WDF_DEVICE_RELEASE_HARDWARE
EVT_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP typedef ptr EVT_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP
EVT_WDF_DEVICE_SELF_MANAGED_IO_FLUSH typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_SELF_MANAGED_IO_FLUSH typedef ptr EVT_WDF_DEVICE_SELF_MANAGED_IO_FLUSH
EVT_WDF_DEVICE_SELF_MANAGED_IO_INIT typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_SELF_MANAGED_IO_INIT typedef ptr EVT_WDF_DEVICE_SELF_MANAGED_IO_INIT
EVT_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND typedef ptr EVT_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND
EVT_WDF_DEVICE_SELF_MANAGED_IO_RESTART typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_SELF_MANAGED_IO_RESTART typedef ptr EVT_WDF_DEVICE_SELF_MANAGED_IO_RESTART
EVT_WDF_DEVICE_QUERY_STOP typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_QUERY_STOP typedef ptr EVT_WDF_DEVICE_QUERY_STOP
EVT_WDF_DEVICE_QUERY_REMOVE typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_QUERY_REMOVE typedef ptr EVT_WDF_DEVICE_QUERY_REMOVE
EVT_WDF_DEVICE_SURPRISE_REMOVAL typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_SURPRISE_REMOVAL typedef ptr EVT_WDF_DEVICE_SURPRISE_REMOVAL
EVT_WDF_DEVICE_USAGE_NOTIFICATION typedef proto stdcall :WDFDEVICE,:WDF_SPECIAL_FILE_TYPE,:BOOLEAN
PFN_WDF_DEVICE_USAGE_NOTIFICATION typedef ptr EVT_WDF_DEVICE_USAGE_NOTIFICATION
EVT_WDF_DEVICE_RELATIONS_QUERY typedef proto stdcall :WDFDEVICE,:DEVICE_RELATION_TYPE
PFN_WDF_DEVICE_RELATIONS_QUERY typedef ptr EVT_WDF_DEVICE_RELATIONS_QUERY
EVT_WDF_DEVICE_ARM_WAKE_FROM_S0 typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_ARM_WAKE_FROM_S0 typedef ptr EVT_WDF_DEVICE_ARM_WAKE_FROM_S0
EVT_WDF_DEVICE_ARM_WAKE_FROM_SX typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_ARM_WAKE_FROM_SX typedef ptr EVT_WDF_DEVICE_ARM_WAKE_FROM_SX
EVT_WDF_DEVICE_ARM_WAKE_FROM_SX_WITH_REASON typedef proto stdcall :WDFDEVICE,:BOOLEAN,:BOOLEAN
PFN_WDF_DEVICE_ARM_WAKE_FROM_SX_WITH_REASON typedef ptr EVT_WDF_DEVICE_ARM_WAKE_FROM_SX_WITH_REASON
EVT_WDF_DEVICE_DISARM_WAKE_FROM_S0 typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_DISARM_WAKE_FROM_S0 typedef ptr EVT_WDF_DEVICE_DISARM_WAKE_FROM_S0
EVT_WDF_DEVICE_DISARM_WAKE_FROM_SX typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_DISARM_WAKE_FROM_SX typedef ptr EVT_WDF_DEVICE_DISARM_WAKE_FROM_SX
EVT_WDF_DEVICE_WAKE_FROM_S0_TRIGGERED typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_WAKE_FROM_S0_TRIGGERED typedef ptr EVT_WDF_DEVICE_WAKE_FROM_S0_TRIGGERED
EVT_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED typedef ptr EVT_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED
WDF_PNPPOWER_EVENT_CALLBACKS struct
    Size_ DWORD ?
    EvtDeviceD0Entry PFN_WDF_DEVICE_D0_ENTRY ?
    EvtDeviceD0EntryPostInterruptsEnabled PFN_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED ?
    EvtDeviceD0Exit PFN_WDF_DEVICE_D0_EXIT ?
    EvtDeviceD0ExitPreInterruptsDisabled PFN_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED ?
    EvtDevicePrepareHardware PFN_WDF_DEVICE_PREPARE_HARDWARE ?
    EvtDeviceReleaseHardware PFN_WDF_DEVICE_RELEASE_HARDWARE ?
    EvtDeviceSelfManagedIoCleanup PFN_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP ?
    EvtDeviceSelfManagedIoFlush PFN_WDF_DEVICE_SELF_MANAGED_IO_FLUSH ?
    EvtDeviceSelfManagedIoInit PFN_WDF_DEVICE_SELF_MANAGED_IO_INIT ?
    EvtDeviceSelfManagedIoSuspend PFN_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND ?
    EvtDeviceSelfManagedIoRestart PFN_WDF_DEVICE_SELF_MANAGED_IO_RESTART ?
    EvtDeviceSurpriseRemoval PFN_WDF_DEVICE_SURPRISE_REMOVAL ?
    EvtDeviceQueryRemove PFN_WDF_DEVICE_QUERY_REMOVE ?
    EvtDeviceQueryStop PFN_WDF_DEVICE_QUERY_STOP ?
    EvtDeviceUsageNotification PFN_WDF_DEVICE_USAGE_NOTIFICATION ?
    EvtDeviceRelationsQuery PFN_WDF_DEVICE_RELATIONS_QUERY ?
WDF_PNPPOWER_EVENT_CALLBACKS ends

PWDF_PNPPOWER_EVENT_CALLBACKS typedef ptr WDF_PNPPOWER_EVENT_CALLBACKS

WDF_POWER_POLICY_EVENT_CALLBACKS struct
    Size_ DWORD ?
    EvtDeviceArmWakeFromS0 PFN_WDF_DEVICE_ARM_WAKE_FROM_S0 ?
    EvtDeviceDisarmWakeFromS0 PFN_WDF_DEVICE_DISARM_WAKE_FROM_S0 ?
    EvtDeviceWakeFromS0Triggered PFN_WDF_DEVICE_WAKE_FROM_S0_TRIGGERED ?
    EvtDeviceArmWakeFromSx PFN_WDF_DEVICE_ARM_WAKE_FROM_SX ?
    EvtDeviceDisarmWakeFromSx PFN_WDF_DEVICE_DISARM_WAKE_FROM_SX ?
    EvtDeviceWakeFromSxTriggered PFN_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED ?
    EvtDeviceArmWakeFromSxWithReason PFN_WDF_DEVICE_ARM_WAKE_FROM_SX_WITH_REASON ?
WDF_POWER_POLICY_EVENT_CALLBACKS ends

PWDF_POWER_POLICY_EVENT_CALLBACKS typedef ptr WDF_POWER_POLICY_EVENT_CALLBACKS

WDF_POWER_POLICY_EVENT_CALLBACKS_INIT proto fastcall :PWDF_POWER_POLICY_EVENT_CALLBACKS
WDF_PNPPOWER_EVENT_CALLBACKS_INIT proto fastcall :PWDF_PNPPOWER_EVENT_CALLBACKS
WdfDevStateNormalize proto fastcall :DWORD
WdfDevStateIsNP proto fastcall :DWORD
WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS struct
    Size_ DWORD ?
    IdleCaps WDF_POWER_POLICY_S0_IDLE_CAPABILITIES ?
    DxState DEVICE_POWER_STATE ?
    IdleTimeout DWORD ?
    UserControlOfIdleSettings WDF_POWER_POLICY_S0_IDLE_USER_CONTROL ?
    Enabled WDF_TRI_STATE ?
    PowerUpIdleDeviceOnSystemWake WDF_TRI_STATE ?
WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS ends

PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS typedef ptr WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS

WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT proto fastcall :PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS, :WDF_POWER_POLICY_S0_IDLE_CAPABILITIES
WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS struct
    Size_ DWORD ?
    DxState DEVICE_POWER_STATE ?
    UserControlOfWakeSettings WDF_POWER_POLICY_SX_WAKE_USER_CONTROL ?
    Enabled WDF_TRI_STATE ?
    ArmForWakeIfChildrenAreArmedForWake BOOLEAN ?
    IndicateChildWakeOnParentWake BOOLEAN ?
WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS ends

PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS typedef ptr WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS

WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT proto fastcall :PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS
WDF_DEVICE_STATE struct
    Size_ DWORD ?
    Disabled WDF_TRI_STATE ?
    DontDisplayInUI WDF_TRI_STATE ?
    Failed WDF_TRI_STATE ?
    NotDisableable WDF_TRI_STATE ?
    Removed WDF_TRI_STATE ?
    ResourcesChanged WDF_TRI_STATE ?
WDF_DEVICE_STATE ends

PWDF_DEVICE_STATE typedef ptr WDF_DEVICE_STATE

WDF_DEVICE_STATE_INIT proto fastcall :PWDF_DEVICE_STATE
WDF_DEVICE_PNP_CAPABILITIES struct
    Size_ DWORD ?
    LockSupported WDF_TRI_STATE ?
    EjectSupported WDF_TRI_STATE ?
    Removable WDF_TRI_STATE ?
    DockDevice WDF_TRI_STATE ?
    UniqueID WDF_TRI_STATE ?
    SilentInstall WDF_TRI_STATE ?
    SurpriseRemovalOK WDF_TRI_STATE ?
    HardwareDisabled WDF_TRI_STATE ?
    NoDisplayInUI WDF_TRI_STATE ?
    Address DWORD ?
    UINumber DWORD ?
WDF_DEVICE_PNP_CAPABILITIES ends

PWDF_DEVICE_PNP_CAPABILITIES typedef ptr WDF_DEVICE_PNP_CAPABILITIES

IFNDEF PowerSystemMaximum
PowerSystemMaximum EQU 7
ENDIF

WDF_DEVICE_PNP_CAPABILITIES_INIT proto fastcall :PWDF_DEVICE_PNP_CAPABILITIES
WDF_DEVICE_POWER_CAPABILITIES struct
    Size_ DWORD ?
    DeviceD1 WDF_TRI_STATE ?
    DeviceD2 WDF_TRI_STATE ?
    WakeFromD0 WDF_TRI_STATE ?
    WakeFromD1 WDF_TRI_STATE ?
    WakeFromD2 WDF_TRI_STATE ?
    WakeFromD3 WDF_TRI_STATE ?
    DeviceState DEVICE_POWER_STATE PowerSystemMaximum dup (?)
    DeviceWake DEVICE_POWER_STATE ?
    SystemWake SYSTEM_POWER_STATE ?
    D1Latency DWORD ?
    D2Latency DWORD ?
    D3Latency DWORD ?
    IdealDxStateForSx DEVICE_POWER_STATE ?
WDF_DEVICE_POWER_CAPABILITIES ends

PWDF_DEVICE_POWER_CAPABILITIES typedef ptr WDF_DEVICE_POWER_CAPABILITIES

PNP_BUS_INFORMATION STRUCT
  BusTypeGuid GUID <>
  LegacyBusType INTERFACE_TYPE ? 
  BusNumber ULONG ?
PNP_BUS_INFORMATION ENDS
PPNP_BUS_INFORMATION TYPEDEF PTR PNP_BUS_INFORMATION


WDF_DEVICE_POWER_CAPABILITIES_INIT proto fastcall :PWDF_DEVICE_POWER_CAPABILITIES
EVT_WDFDEVICE_WDM_IRP_PREPROCESS typedef proto stdcall :WDFDEVICE,:PIRP
PFN_WDFDEVICE_WDM_IRP_PREPROCESS typedef ptr EVT_WDFDEVICE_WDM_IRP_PREPROCESS
EVT_WDF_IO_IN_CALLER_CONTEXT typedef proto stdcall :WDFDEVICE,:WDFREQUEST
PFN_WDF_IO_IN_CALLER_CONTEXT typedef ptr EVT_WDF_IO_IN_CALLER_CONTEXT
proto_PFN_WDFDEVICEGETDEVICESTATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_DEVICE_STATE
PFN_WDFDEVICEGETDEVICESTATE typedef ptr proto_PFN_WDFDEVICEGETDEVICESTATE
WdfDeviceGetDeviceState proto fastcall :WDFDEVICE, :PWDF_DEVICE_STATE
proto_PFN_WDFDEVICESETDEVICESTATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_DEVICE_STATE
PFN_WDFDEVICESETDEVICESTATE typedef ptr proto_PFN_WDFDEVICESETDEVICESTATE
WdfDeviceSetDeviceState proto fastcall :WDFDEVICE, :PWDF_DEVICE_STATE
proto_PFN_WDFWDMDEVICEGETWDFDEVICEHANDLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PDEVICE_OBJECT
PFN_WDFWDMDEVICEGETWDFDEVICEHANDLE typedef ptr proto_PFN_WDFWDMDEVICEGETWDFDEVICEHANDLE
WdfWdmDeviceGetWdfDeviceHandle proto fastcall :PDEVICE_OBJECT
proto_PFN_WDFDEVICEWDMGETDEVICEOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICEWDMGETDEVICEOBJECT typedef ptr proto_PFN_WDFDEVICEWDMGETDEVICEOBJECT
WdfDeviceWdmGetDeviceObject proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICEWDMGETATTACHEDDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICEWDMGETATTACHEDDEVICE typedef ptr proto_PFN_WDFDEVICEWDMGETATTACHEDDEVICE
WdfDeviceWdmGetAttachedDevice proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICEWDMGETPHYSICALDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICEWDMGETPHYSICALDEVICE typedef ptr proto_PFN_WDFDEVICEWDMGETPHYSICALDEVICE
WdfDeviceWdmGetPhysicalDevice proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICEWDMDISPATCHPREPROCESSEDIRP typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PIRP
PFN_WDFDEVICEWDMDISPATCHPREPROCESSEDIRP typedef ptr proto_PFN_WDFDEVICEWDMDISPATCHPREPROCESSEDIRP
WdfDeviceWdmDispatchPreprocessedIrp proto fastcall :WDFDEVICE, :PIRP
proto_PFN_WDFDEVICEADDDEPENDENTUSAGEDEVICEOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PDEVICE_OBJECT
PFN_WDFDEVICEADDDEPENDENTUSAGEDEVICEOBJECT typedef ptr proto_PFN_WDFDEVICEADDDEPENDENTUSAGEDEVICEOBJECT
WdfDeviceAddDependentUsageDeviceObject proto fastcall :WDFDEVICE, :PDEVICE_OBJECT
proto_PFN_WDFDEVICEREMOVEDEPENDENTUSAGEDEVICEOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PDEVICE_OBJECT
PFN_WDFDEVICEREMOVEDEPENDENTUSAGEDEVICEOBJECT typedef ptr proto_PFN_WDFDEVICEREMOVEDEPENDENTUSAGEDEVICEOBJECT
WdfDeviceRemoveDependentUsageDeviceObject proto fastcall :WDFDEVICE, :PDEVICE_OBJECT
proto_PFN_WDFDEVICEADDREMOVALRELATIONSPHYSICALDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PDEVICE_OBJECT
PFN_WDFDEVICEADDREMOVALRELATIONSPHYSICALDEVICE typedef ptr proto_PFN_WDFDEVICEADDREMOVALRELATIONSPHYSICALDEVICE
WdfDeviceAddRemovalRelationsPhysicalDevice proto fastcall :WDFDEVICE, :PDEVICE_OBJECT
proto_PFN_WDFDEVICEREMOVEREMOVALRELATIONSPHYSICALDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PDEVICE_OBJECT
PFN_WDFDEVICEREMOVEREMOVALRELATIONSPHYSICALDEVICE typedef ptr proto_PFN_WDFDEVICEREMOVEREMOVALRELATIONSPHYSICALDEVICE
WdfDeviceRemoveRemovalRelationsPhysicalDevice proto fastcall :WDFDEVICE, :PDEVICE_OBJECT
proto_PFN_WDFDEVICECLEARREMOVALRELATIONSDEVICES typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICECLEARREMOVALRELATIONSDEVICES typedef ptr proto_PFN_WDFDEVICECLEARREMOVALRELATIONSDEVICES
WdfDeviceClearRemovalRelationsDevices proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICEGETDRIVER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICEGETDRIVER typedef ptr proto_PFN_WDFDEVICEGETDRIVER
WdfDeviceGetDriver proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICERETRIEVEDEVICENAME typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :WDFSTRING
PFN_WDFDEVICERETRIEVEDEVICENAME typedef ptr proto_PFN_WDFDEVICERETRIEVEDEVICENAME
WdfDeviceRetrieveDeviceName proto fastcall :WDFDEVICE, :WDFSTRING
proto_PFN_WDFDEVICEASSIGNMOFRESOURCENAME typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PCUNICODE_STRING
PFN_WDFDEVICEASSIGNMOFRESOURCENAME typedef ptr proto_PFN_WDFDEVICEASSIGNMOFRESOURCENAME
WdfDeviceAssignMofResourceName proto fastcall :WDFDEVICE, :PCUNICODE_STRING
proto_PFN_WDFDEVICEGETIOTARGET typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICEGETIOTARGET typedef ptr proto_PFN_WDFDEVICEGETIOTARGET
WdfDeviceGetIoTarget proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICEGETDEVICEPNPSTATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICEGETDEVICEPNPSTATE typedef ptr proto_PFN_WDFDEVICEGETDEVICEPNPSTATE
WdfDeviceGetDevicePnpState proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICEGETDEVICEPOWERSTATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICEGETDEVICEPOWERSTATE typedef ptr proto_PFN_WDFDEVICEGETDEVICEPOWERSTATE
WdfDeviceGetDevicePowerState proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICEGETDEVICEPOWERPOLICYSTATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICEGETDEVICEPOWERPOLICYSTATE typedef ptr proto_PFN_WDFDEVICEGETDEVICEPOWERPOLICYSTATE
WdfDeviceGetDevicePowerPolicyState proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICEASSIGNS0IDLESETTINGS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS
PFN_WDFDEVICEASSIGNS0IDLESETTINGS typedef ptr proto_PFN_WDFDEVICEASSIGNS0IDLESETTINGS
WdfDeviceAssignS0IdleSettings proto fastcall :WDFDEVICE, :PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS
proto_PFN_WDFDEVICEASSIGNSXWAKESETTINGS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS
PFN_WDFDEVICEASSIGNSXWAKESETTINGS typedef ptr proto_PFN_WDFDEVICEASSIGNSXWAKESETTINGS
WdfDeviceAssignSxWakeSettings proto fastcall :WDFDEVICE, :PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS
proto_PFN_WDFDEVICEOPENREGISTRYKEY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :DWORD, :ACCESS_MASK, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFKEY
PFN_WDFDEVICEOPENREGISTRYKEY typedef ptr proto_PFN_WDFDEVICEOPENREGISTRYKEY
WdfDeviceOpenRegistryKey proto fastcall :WDFDEVICE, :DWORD, :ACCESS_MASK, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFKEY
proto_PFN_WDFDEVICESETSPECIALFILESUPPORT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :WDF_SPECIAL_FILE_TYPE, :BOOLEAN
PFN_WDFDEVICESETSPECIALFILESUPPORT typedef ptr proto_PFN_WDFDEVICESETSPECIALFILESUPPORT
WdfDeviceSetSpecialFileSupport proto fastcall :WDFDEVICE, :WDF_SPECIAL_FILE_TYPE, :BOOLEAN
proto_PFN_WDFDEVICESETCHARACTERISTICS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :DWORD
PFN_WDFDEVICESETCHARACTERISTICS typedef ptr proto_PFN_WDFDEVICESETCHARACTERISTICS
WdfDeviceSetCharacteristics proto fastcall :WDFDEVICE, :DWORD
proto_PFN_WDFDEVICEGETCHARACTERISTICS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICEGETCHARACTERISTICS typedef ptr proto_PFN_WDFDEVICEGETCHARACTERISTICS
WdfDeviceGetCharacteristics proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICEGETALIGNMENTREQUIREMENT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICEGETALIGNMENTREQUIREMENT typedef ptr proto_PFN_WDFDEVICEGETALIGNMENTREQUIREMENT
WdfDeviceGetAlignmentRequirement proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICESETALIGNMENTREQUIREMENT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :DWORD
PFN_WDFDEVICESETALIGNMENTREQUIREMENT typedef ptr proto_PFN_WDFDEVICESETALIGNMENTREQUIREMENT
WdfDeviceSetAlignmentRequirement proto fastcall :WDFDEVICE, :DWORD
proto_PFN_WDFDEVICEINITFREE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT
PFN_WDFDEVICEINITFREE typedef ptr proto_PFN_WDFDEVICEINITFREE
WdfDeviceInitFree proto fastcall :PWDFDEVICE_INIT
proto_PFN_WDFDEVICEINITSETPNPPOWEREVENTCALLBACKS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PWDF_PNPPOWER_EVENT_CALLBACKS
PFN_WDFDEVICEINITSETPNPPOWEREVENTCALLBACKS typedef ptr proto_PFN_WDFDEVICEINITSETPNPPOWEREVENTCALLBACKS
WdfDeviceInitSetPnpPowerEventCallbacks proto fastcall :PWDFDEVICE_INIT, :PWDF_PNPPOWER_EVENT_CALLBACKS
proto_PFN_WDFDEVICEINITSETPOWERPOLICYEVENTCALLBACKS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PWDF_POWER_POLICY_EVENT_CALLBACKS
PFN_WDFDEVICEINITSETPOWERPOLICYEVENTCALLBACKS typedef ptr proto_PFN_WDFDEVICEINITSETPOWERPOLICYEVENTCALLBACKS
WdfDeviceInitSetPowerPolicyEventCallbacks proto fastcall :PWDFDEVICE_INIT, :PWDF_POWER_POLICY_EVENT_CALLBACKS
proto_PFN_WDFDEVICEINITSETPOWERPOLICYOWNERSHIP typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :BOOLEAN
PFN_WDFDEVICEINITSETPOWERPOLICYOWNERSHIP typedef ptr proto_PFN_WDFDEVICEINITSETPOWERPOLICYOWNERSHIP
WdfDeviceInitSetPowerPolicyOwnership proto fastcall :PWDFDEVICE_INIT, :BOOLEAN
proto_PFN_WDFDEVICEINITREGISTERPNPSTATECHANGECALLBACK typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :WDF_DEVICE_PNP_STATE, :PFN_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION, :DWORD
PFN_WDFDEVICEINITREGISTERPNPSTATECHANGECALLBACK typedef ptr proto_PFN_WDFDEVICEINITREGISTERPNPSTATECHANGECALLBACK
WdfDeviceInitRegisterPnpStateChangeCallback proto fastcall :PWDFDEVICE_INIT, :WDF_DEVICE_PNP_STATE, :PFN_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION, :DWORD
proto_PFN_WDFDEVICEINITREGISTERPOWERSTATECHANGECALLBACK typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :WDF_DEVICE_POWER_STATE, :PFN_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION, :DWORD
PFN_WDFDEVICEINITREGISTERPOWERSTATECHANGECALLBACK typedef ptr proto_PFN_WDFDEVICEINITREGISTERPOWERSTATECHANGECALLBACK
WdfDeviceInitRegisterPowerStateChangeCallback proto fastcall :PWDFDEVICE_INIT, :WDF_DEVICE_POWER_STATE, :PFN_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION, :DWORD
proto_PFN_WDFDEVICEINITREGISTERPOWERPOLICYSTATECHANGECALLBACK typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :WDF_DEVICE_POWER_POLICY_STATE, :PFN_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION, :DWORD
PFN_WDFDEVICEINITREGISTERPOWERPOLICYSTATECHANGECALLBACK typedef ptr proto_PFN_WDFDEVICEINITREGISTERPOWERPOLICYSTATECHANGECALLBACK
WdfDeviceInitRegisterPowerPolicyStateChangeCallback proto fastcall :PWDFDEVICE_INIT, :WDF_DEVICE_POWER_POLICY_STATE, :PFN_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION, :DWORD
proto_PFN_WDFDEVICEINITSETIOTYPE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :WDF_DEVICE_IO_TYPE
PFN_WDFDEVICEINITSETIOTYPE typedef ptr proto_PFN_WDFDEVICEINITSETIOTYPE
WdfDeviceInitSetIoType proto fastcall :PWDFDEVICE_INIT, :WDF_DEVICE_IO_TYPE
proto_PFN_WDFDEVICEINITSETEXCLUSIVE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :BOOLEAN
PFN_WDFDEVICEINITSETEXCLUSIVE typedef ptr proto_PFN_WDFDEVICEINITSETEXCLUSIVE
WdfDeviceInitSetExclusive proto fastcall :PWDFDEVICE_INIT, :BOOLEAN
proto_PFN_WDFDEVICEINITSETPOWERNOTPAGEABLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT
PFN_WDFDEVICEINITSETPOWERNOTPAGEABLE typedef ptr proto_PFN_WDFDEVICEINITSETPOWERNOTPAGEABLE
WdfDeviceInitSetPowerNotPageable proto fastcall :PWDFDEVICE_INIT
proto_PFN_WDFDEVICEINITSETPOWERPAGEABLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT
PFN_WDFDEVICEINITSETPOWERPAGEABLE typedef ptr proto_PFN_WDFDEVICEINITSETPOWERPAGEABLE
WdfDeviceInitSetPowerPageable proto fastcall :PWDFDEVICE_INIT
proto_PFN_WDFDEVICEINITSETPOWERINRUSH typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT
PFN_WDFDEVICEINITSETPOWERINRUSH typedef ptr proto_PFN_WDFDEVICEINITSETPOWERINRUSH
WdfDeviceInitSetPowerInrush proto fastcall :PWDFDEVICE_INIT
proto_PFN_WDFDEVICEINITSETDEVICETYPE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :DEVICE_TYPE
PFN_WDFDEVICEINITSETDEVICETYPE typedef ptr proto_PFN_WDFDEVICEINITSETDEVICETYPE
WdfDeviceInitSetDeviceType proto fastcall :PWDFDEVICE_INIT, :DEVICE_TYPE
proto_PFN_WDFDEVICEINITASSIGNNAME typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PCUNICODE_STRING
PFN_WDFDEVICEINITASSIGNNAME typedef ptr proto_PFN_WDFDEVICEINITASSIGNNAME
WdfDeviceInitAssignName proto fastcall :PWDFDEVICE_INIT, :PCUNICODE_STRING
proto_PFN_WDFDEVICEINITASSIGNSDDLSTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PCUNICODE_STRING
PFN_WDFDEVICEINITASSIGNSDDLSTRING typedef ptr proto_PFN_WDFDEVICEINITASSIGNSDDLSTRING
WdfDeviceInitAssignSDDLString proto fastcall :PWDFDEVICE_INIT, :PCUNICODE_STRING
proto_PFN_WDFDEVICEINITSETDEVICECLASS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :ptr GUID
PFN_WDFDEVICEINITSETDEVICECLASS typedef ptr proto_PFN_WDFDEVICEINITSETDEVICECLASS
WdfDeviceInitSetDeviceClass proto fastcall :PWDFDEVICE_INIT, :ptr GUID
proto_PFN_WDFDEVICEINITSETCHARACTERISTICS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :DWORD, :BOOLEAN
PFN_WDFDEVICEINITSETCHARACTERISTICS typedef ptr proto_PFN_WDFDEVICEINITSETCHARACTERISTICS
WdfDeviceInitSetCharacteristics proto fastcall :PWDFDEVICE_INIT, :DWORD, :BOOLEAN
proto_PFN_WDFDEVICEINITSETFILEOBJECTCONFIG typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PWDF_FILEOBJECT_CONFIG, :PWDF_OBJECT_ATTRIBUTES
PFN_WDFDEVICEINITSETFILEOBJECTCONFIG typedef ptr proto_PFN_WDFDEVICEINITSETFILEOBJECTCONFIG
WdfDeviceInitSetFileObjectConfig proto fastcall :PWDFDEVICE_INIT, :PWDF_FILEOBJECT_CONFIG, :PWDF_OBJECT_ATTRIBUTES
proto_PFN_WDFDEVICEINITSETREQUESTATTRIBUTES typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PWDF_OBJECT_ATTRIBUTES
PFN_WDFDEVICEINITSETREQUESTATTRIBUTES typedef ptr proto_PFN_WDFDEVICEINITSETREQUESTATTRIBUTES
WdfDeviceInitSetRequestAttributes proto fastcall :PWDFDEVICE_INIT, :PWDF_OBJECT_ATTRIBUTES
proto_PFN_WDFDEVICEINITASSIGNWDMIRPPREPROCESSCALLBACK typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PFN_WDFDEVICE_WDM_IRP_PREPROCESS, :BYTE, :PUCHAR, :DWORD
PFN_WDFDEVICEINITASSIGNWDMIRPPREPROCESSCALLBACK typedef ptr proto_PFN_WDFDEVICEINITASSIGNWDMIRPPREPROCESSCALLBACK
WdfDeviceInitAssignWdmIrpPreprocessCallback proto fastcall :PWDFDEVICE_INIT, :PFN_WDFDEVICE_WDM_IRP_PREPROCESS, :BYTE, :PUCHAR, :DWORD
proto_PFN_WDFDEVICEINITSETIOINCALLERCONTEXTCALLBACK typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PFN_WDF_IO_IN_CALLER_CONTEXT
PFN_WDFDEVICEINITSETIOINCALLERCONTEXTCALLBACK typedef ptr proto_PFN_WDFDEVICEINITSETIOINCALLERCONTEXTCALLBACK
WdfDeviceInitSetIoInCallerContextCallback proto fastcall :PWDFDEVICE_INIT, :PFN_WDF_IO_IN_CALLER_CONTEXT
proto_PFN_WDFDEVICECREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :ptr PWDFDEVICE_INIT, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFDEVICE
PFN_WDFDEVICECREATE typedef ptr proto_PFN_WDFDEVICECREATE
WdfDeviceCreate proto fastcall :ptr PWDFDEVICE_INIT, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFDEVICE
proto_PFN_WDFDEVICESETSTATICSTOPREMOVE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :BOOLEAN
PFN_WDFDEVICESETSTATICSTOPREMOVE typedef ptr proto_PFN_WDFDEVICESETSTATICSTOPREMOVE
WdfDeviceSetStaticStopRemove proto fastcall :WDFDEVICE, :BOOLEAN
proto_PFN_WDFDEVICECREATEDEVICEINTERFACE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :ptr GUID, :PCUNICODE_STRING
PFN_WDFDEVICECREATEDEVICEINTERFACE typedef ptr proto_PFN_WDFDEVICECREATEDEVICEINTERFACE
WdfDeviceCreateDeviceInterface proto fastcall :WDFDEVICE, :ptr GUID, :PCUNICODE_STRING
proto_PFN_WDFDEVICESETDEVICEINTERFACESTATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :ptr GUID, :PCUNICODE_STRING, :BOOLEAN
PFN_WDFDEVICESETDEVICEINTERFACESTATE typedef ptr proto_PFN_WDFDEVICESETDEVICEINTERFACESTATE
WdfDeviceSetDeviceInterfaceState proto fastcall :WDFDEVICE, :ptr GUID, :PCUNICODE_STRING, :BOOLEAN
proto_PFN_WDFDEVICERETRIEVEDEVICEINTERFACESTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :ptr GUID, :PCUNICODE_STRING, :WDFSTRING
PFN_WDFDEVICERETRIEVEDEVICEINTERFACESTRING typedef ptr proto_PFN_WDFDEVICERETRIEVEDEVICEINTERFACESTRING
WdfDeviceRetrieveDeviceInterfaceString proto fastcall :WDFDEVICE, :ptr GUID, :PCUNICODE_STRING, :WDFSTRING
proto_PFN_WDFDEVICECREATESYMBOLICLINK typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PCUNICODE_STRING
PFN_WDFDEVICECREATESYMBOLICLINK typedef ptr proto_PFN_WDFDEVICECREATESYMBOLICLINK
WdfDeviceCreateSymbolicLink proto fastcall :WDFDEVICE, :PCUNICODE_STRING
proto_PFN_WDFDEVICEQUERYPROPERTY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :DEVICE_REGISTRY_PROPERTY, :DWORD, :PVOID, :PULONG
PFN_WDFDEVICEQUERYPROPERTY typedef ptr proto_PFN_WDFDEVICEQUERYPROPERTY
WdfDeviceQueryProperty proto fastcall :WDFDEVICE, :DEVICE_REGISTRY_PROPERTY, :DWORD, :PVOID, :PULONG
proto_PFN_WDFDEVICEALLOCANDQUERYPROPERTY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :DEVICE_REGISTRY_PROPERTY, :POOL_TYPE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFMEMORY
PFN_WDFDEVICEALLOCANDQUERYPROPERTY typedef ptr proto_PFN_WDFDEVICEALLOCANDQUERYPROPERTY
WdfDeviceAllocAndQueryProperty proto fastcall :WDFDEVICE, :DEVICE_REGISTRY_PROPERTY, :POOL_TYPE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFMEMORY
proto_PFN_WDFDEVICESETPNPCAPABILITIES typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_DEVICE_PNP_CAPABILITIES
PFN_WDFDEVICESETPNPCAPABILITIES typedef ptr proto_PFN_WDFDEVICESETPNPCAPABILITIES
WdfDeviceSetPnpCapabilities proto fastcall :WDFDEVICE, :PWDF_DEVICE_PNP_CAPABILITIES
proto_PFN_WDFDEVICESETPOWERCAPABILITIES typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_DEVICE_POWER_CAPABILITIES
PFN_WDFDEVICESETPOWERCAPABILITIES typedef ptr proto_PFN_WDFDEVICESETPOWERCAPABILITIES
WdfDeviceSetPowerCapabilities proto fastcall :WDFDEVICE, :PWDF_DEVICE_POWER_CAPABILITIES
proto_PFN_WDFDEVICESETBUSINFORMATIONFORCHILDREN typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PPNP_BUS_INFORMATION
PFN_WDFDEVICESETBUSINFORMATIONFORCHILDREN typedef ptr proto_PFN_WDFDEVICESETBUSINFORMATIONFORCHILDREN
WdfDeviceSetBusInformationForChildren proto fastcall :WDFDEVICE, :PPNP_BUS_INFORMATION
proto_PFN_WDFDEVICEINDICATEWAKESTATUS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :NTSTATUS
PFN_WDFDEVICEINDICATEWAKESTATUS typedef ptr proto_PFN_WDFDEVICEINDICATEWAKESTATUS
WdfDeviceIndicateWakeStatus proto fastcall :WDFDEVICE, :NTSTATUS
proto_PFN_WDFDEVICESETFAILED typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :WDF_DEVICE_FAILED_ACTION
PFN_WDFDEVICESETFAILED typedef ptr proto_PFN_WDFDEVICESETFAILED
WdfDeviceSetFailed proto fastcall :WDFDEVICE, :WDF_DEVICE_FAILED_ACTION
proto_PFN_WDFDEVICESTOPIDLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :BOOLEAN
PFN_WDFDEVICESTOPIDLE typedef ptr proto_PFN_WDFDEVICESTOPIDLE
WdfDeviceStopIdle proto fastcall :WDFDEVICE, :BOOLEAN
proto_PFN_WDFDEVICERESUMEIDLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICERESUMEIDLE typedef ptr proto_PFN_WDFDEVICERESUMEIDLE
WdfDeviceResumeIdle proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICEGETFILEOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PFILE_OBJECT
PFN_WDFDEVICEGETFILEOBJECT typedef ptr proto_PFN_WDFDEVICEGETFILEOBJECT
WdfDeviceGetFileObject proto fastcall :WDFDEVICE, :PFILE_OBJECT
proto_PFN_WDFDEVICEENQUEUEREQUEST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :WDFREQUEST
PFN_WDFDEVICEENQUEUEREQUEST typedef ptr proto_PFN_WDFDEVICEENQUEUEREQUEST
WdfDeviceEnqueueRequest proto fastcall :WDFDEVICE, :WDFREQUEST
proto_PFN_WDFDEVICEGETDEFAULTQUEUE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICEGETDEFAULTQUEUE typedef ptr proto_PFN_WDFDEVICEGETDEFAULTQUEUE
WdfDeviceGetDefaultQueue proto fastcall :WDFDEVICE
proto_PFN_WDFDEVICECONFIGUREREQUESTDISPATCHING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :WDFQUEUE, :WDF_REQUEST_TYPE
PFN_WDFDEVICECONFIGUREREQUESTDISPATCHING typedef ptr proto_PFN_WDFDEVICECONFIGUREREQUESTDISPATCHING
WdfDeviceConfigureRequestDispatching proto fastcall :WDFDEVICE, :WDFQUEUE, :WDF_REQUEST_TYPE
proto_PFN_WDFDEVICEGETSYSTEMPOWERACTION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFDEVICEGETSYSTEMPOWERACTION typedef ptr proto_PFN_WDFDEVICEGETSYSTEMPOWERACTION
WdfDeviceGetSystemPowerAction proto fastcall :WDFDEVICE


;-------------------------------------------------------------------------
; wdfcollection.h
;-------------------------------------------------------------------------
proto_PFN_WDFCOLLECTIONCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFCOLLECTION
PFN_WDFCOLLECTIONCREATE typedef ptr proto_PFN_WDFCOLLECTIONCREATE
WdfCollectionCreate proto fastcall :PWDF_OBJECT_ATTRIBUTES, :ptr WDFCOLLECTION
proto_PFN_WDFCOLLECTIONGETCOUNT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCOLLECTION
PFN_WDFCOLLECTIONGETCOUNT typedef ptr proto_PFN_WDFCOLLECTIONGETCOUNT
WdfCollectionGetCount proto fastcall :WDFCOLLECTION
proto_PFN_WDFCOLLECTIONADD typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCOLLECTION, :WDFOBJECT
PFN_WDFCOLLECTIONADD typedef ptr proto_PFN_WDFCOLLECTIONADD
WdfCollectionAdd proto fastcall :WDFCOLLECTION, :WDFOBJECT
proto_PFN_WDFCOLLECTIONREMOVE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCOLLECTION, :WDFOBJECT
PFN_WDFCOLLECTIONREMOVE typedef ptr proto_PFN_WDFCOLLECTIONREMOVE
WdfCollectionRemove proto fastcall :WDFCOLLECTION, :WDFOBJECT
proto_PFN_WDFCOLLECTIONREMOVEITEM typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCOLLECTION, :DWORD
PFN_WDFCOLLECTIONREMOVEITEM typedef ptr proto_PFN_WDFCOLLECTIONREMOVEITEM
WdfCollectionRemoveItem proto fastcall :WDFCOLLECTION, :DWORD
proto_PFN_WDFCOLLECTIONGETITEM typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCOLLECTION, :DWORD
PFN_WDFCOLLECTIONGETITEM typedef ptr proto_PFN_WDFCOLLECTIONGETITEM
WdfCollectionGetItem proto fastcall :WDFCOLLECTION, :DWORD
proto_PFN_WDFCOLLECTIONGETFIRSTITEM typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCOLLECTION
PFN_WDFCOLLECTIONGETFIRSTITEM typedef ptr proto_PFN_WDFCOLLECTIONGETFIRSTITEM
WdfCollectionGetFirstItem proto fastcall :WDFCOLLECTION
proto_PFN_WDFCOLLECTIONGETLASTITEM typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCOLLECTION
PFN_WDFCOLLECTIONGETLASTITEM typedef ptr proto_PFN_WDFCOLLECTIONGETLASTITEM
WdfCollectionGetLastItem proto fastcall :WDFCOLLECTION


;-------------------------------------------------------------------------
; wdfdpc.h
;-------------------------------------------------------------------------
EVT_WDF_DPC typedef proto stdcall :WDFDPC
PFN_WDF_DPC typedef ptr EVT_WDF_DPC
WDF_DPC_CONFIG struct
    Size_ DWORD ?
    EvtDpcFunc PFN_WDF_DPC ?
    AutomaticSerialization BOOLEAN ?
WDF_DPC_CONFIG ends

PWDF_DPC_CONFIG typedef ptr WDF_DPC_CONFIG

WDF_DPC_CONFIG_INIT proto fastcall :PWDF_DPC_CONFIG, :PFN_WDF_DPC
proto_PFN_WDFDPCCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDF_DPC_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFDPC
PFN_WDFDPCCREATE typedef ptr proto_PFN_WDFDPCCREATE
WdfDpcCreate proto fastcall :PWDF_DPC_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFDPC
proto_PFN_WDFDPCENQUEUE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDPC
PFN_WDFDPCENQUEUE typedef ptr proto_PFN_WDFDPCENQUEUE
WdfDpcEnqueue proto fastcall :WDFDPC
proto_PFN_WDFDPCCANCEL typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDPC, :BOOLEAN
PFN_WDFDPCCANCEL typedef ptr proto_PFN_WDFDPCCANCEL
WdfDpcCancel proto fastcall :WDFDPC, :BOOLEAN
proto_PFN_WDFDPCGETPARENTOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDPC
PFN_WDFDPCGETPARENTOBJECT typedef ptr proto_PFN_WDFDPCGETPARENTOBJECT
WdfDpcGetParentObject proto fastcall :WDFDPC
proto_PFN_WDFDPCWDMGETDPC typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDPC
PFN_WDFDPCWDMGETDPC typedef ptr proto_PFN_WDFDPCWDMGETDPC
WdfDpcWdmGetDpc proto fastcall :WDFDPC


;-------------------------------------------------------------------------
; wdftimer.h
;-------------------------------------------------------------------------
EVT_WDF_TIMER typedef proto stdcall :WDFTIMER
PFN_WDF_TIMER typedef ptr EVT_WDF_TIMER
WDF_TIMER_CONFIG struct
    Size_ DWORD ?
    EvtTimerFunc PFN_WDF_TIMER ?
    Period DWORD ?
    AutomaticSerialization BOOLEAN ?
    TolerableDelay DWORD ?
WDF_TIMER_CONFIG ends

PWDF_TIMER_CONFIG typedef ptr WDF_TIMER_CONFIG

WDF_TIMER_CONFIG_INIT proto fastcall :PWDF_TIMER_CONFIG, :PFN_WDF_TIMER
WDF_TIMER_CONFIG_INIT_PERIODIC proto fastcall :PWDF_TIMER_CONFIG, :PFN_WDF_TIMER, :SDWORD
proto_PFN_WDFTIMERCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDF_TIMER_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFTIMER
PFN_WDFTIMERCREATE typedef ptr proto_PFN_WDFTIMERCREATE
WdfTimerCreate proto fastcall :PWDF_TIMER_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFTIMER
proto_PFN_WDFTIMERSTART typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFTIMER, :QWORD
PFN_WDFTIMERSTART typedef ptr proto_PFN_WDFTIMERSTART
WdfTimerStart proto fastcall :WDFTIMER, :QWORD
proto_PFN_WDFTIMERSTOP typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFTIMER, :BOOLEAN
PFN_WDFTIMERSTOP typedef ptr proto_PFN_WDFTIMERSTOP
WdfTimerStop proto fastcall :WDFTIMER, :BOOLEAN
proto_PFN_WDFTIMERGETPARENTOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFTIMER
PFN_WDFTIMERGETPARENTOBJECT typedef ptr proto_PFN_WDFTIMERGETPARENTOBJECT
WdfTimerGetParentObject proto fastcall :WDFTIMER


;-------------------------------------------------------------------------
; wdfworkitem.h
;-------------------------------------------------------------------------
EVT_WDF_WORKITEM typedef proto stdcall :WDFWORKITEM
PFN_WDF_WORKITEM typedef ptr EVT_WDF_WORKITEM
WDF_WORKITEM_CONFIG struct
  Size_ DWORD ?
  EvtWorkItemFunc PFN_WDF_WORKITEM ?
  AutomaticSerialization BOOLEAN ?
WDF_WORKITEM_CONFIG ends

PWDF_WORKITEM_CONFIG typedef ptr WDF_WORKITEM_CONFIG

WDF_WORKITEM_CONFIG_INIT proto fastcall :PWDF_WORKITEM_CONFIG, :PFN_WDF_WORKITEM
proto_PFN_WDFWORKITEMCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDF_WORKITEM_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFWORKITEM
PFN_WDFWORKITEMCREATE typedef ptr proto_PFN_WDFWORKITEMCREATE
WdfWorkItemCreate proto fastcall :PWDF_WORKITEM_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFWORKITEM
proto_PFN_WDFWORKITEMENQUEUE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWORKITEM
PFN_WDFWORKITEMENQUEUE typedef ptr proto_PFN_WDFWORKITEMENQUEUE
WdfWorkItemEnqueue proto fastcall :WDFWORKITEM
proto_PFN_WDFWORKITEMGETPARENTOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWORKITEM
PFN_WDFWORKITEMGETPARENTOBJECT typedef ptr proto_PFN_WDFWORKITEMGETPARENTOBJECT
WdfWorkItemGetParentObject proto fastcall :WDFWORKITEM
proto_PFN_WDFWORKITEMFLUSH typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWORKITEM
PFN_WDFWORKITEMFLUSH typedef ptr proto_PFN_WDFWORKITEMFLUSH
WdfWorkItemFlush proto fastcall :WDFWORKITEM


;-------------------------------------------------------------------------
; wdfinterrupt.h
;-------------------------------------------------------------------------
WDF_INTERRUPT_POLARITY typedef SDWORD
WdfInterruptPolarityUnknown EQU 0 
WdfInterruptActiveHigh EQU 1
WdfInterruptActiveLow EQU 2

PWDF_INTERRUPT_POLARITY typedef ptr WDF_INTERRUPT_POLARITY

WDF_INTERRUPT_POLICY typedef SDWORD
WdfIrqPolicyMachineDefault EQU 0 
WdfIrqPolicyAllCloseProcessors EQU 1
WdfIrqPolicyOneCloseProcessor EQU 2
WdfIrqPolicyAllProcessorsInMachine EQU 3
WdfIrqPolicySpecifiedProcessors EQU 4
WdfIrqPolicySpreadMessagesAcrossAllProcessors EQU 5

PWDF_INTERRUPT_POLICY typedef ptr WDF_INTERRUPT_POLICY

WDF_INTERRUPT_PRIORITY typedef SDWORD
WdfIrqPriorityUndefined EQU 0 
WdfIrqPriorityLow EQU 1
WdfIrqPriorityNormal EQU 2
WdfIrqPriorityHigh EQU 3

PWDF_INTERRUPT_PRIORITY typedef ptr WDF_INTERRUPT_PRIORITY

EVT_WDF_INTERRUPT_ISR typedef proto stdcall :WDFINTERRUPT,:DWORD
PFN_WDF_INTERRUPT_ISR typedef ptr EVT_WDF_INTERRUPT_ISR
EVT_WDF_INTERRUPT_SYNCHRONIZE typedef proto stdcall :WDFINTERRUPT,:WDFCONTEXT
PFN_WDF_INTERRUPT_SYNCHRONIZE typedef ptr EVT_WDF_INTERRUPT_SYNCHRONIZE
EVT_WDF_INTERRUPT_DPC typedef proto stdcall :WDFINTERRUPT,:WDFOBJECT
PFN_WDF_INTERRUPT_DPC typedef ptr EVT_WDF_INTERRUPT_DPC
EVT_WDF_INTERRUPT_ENABLE typedef proto stdcall :WDFINTERRUPT,:WDFDEVICE
PFN_WDF_INTERRUPT_ENABLE typedef ptr EVT_WDF_INTERRUPT_ENABLE
EVT_WDF_INTERRUPT_DISABLE typedef proto stdcall :WDFINTERRUPT,:WDFDEVICE
PFN_WDF_INTERRUPT_DISABLE typedef ptr EVT_WDF_INTERRUPT_DISABLE
WDF_INTERRUPT_CONFIG struct
    Size_ DWORD ?
    SpinLock WDFSPINLOCK ?
    ShareVector WDF_TRI_STATE ?
    FloatingSave BOOLEAN ?
    AutomaticSerialization BOOLEAN ?
    EvtInterruptIsr PFN_WDF_INTERRUPT_ISR ?
    EvtInterruptDpc PFN_WDF_INTERRUPT_DPC ?
    EvtInterruptEnable PFN_WDF_INTERRUPT_ENABLE ?
    EvtInterruptDisable PFN_WDF_INTERRUPT_DISABLE ?
WDF_INTERRUPT_CONFIG ends

PWDF_INTERRUPT_CONFIG typedef ptr WDF_INTERRUPT_CONFIG

WDF_INTERRUPT_CONFIG_INIT proto fastcall :PWDF_INTERRUPT_CONFIG, :PFN_WDF_INTERRUPT_ISR, :PFN_WDF_INTERRUPT_DPC
WDF_INTERRUPT_INFO struct
    Size_ DWORD ?
    Reserved1 ULONG64 ?
    TargetProcessorSet KAFFINITY ?
    Reserved2 DWORD ?
    MessageNumber DWORD ?
    Vector DWORD ?
    Irql KIRQL ?
    Mode KINTERRUPT_MODE ?
    Polarity WDF_INTERRUPT_POLARITY ?
    MessageSignaled BOOLEAN ?
    ShareDisposition BYTE ?
    Group_ WORD ?
WDF_INTERRUPT_INFO ends

PWDF_INTERRUPT_INFO typedef ptr WDF_INTERRUPT_INFO

WDF_INTERRUPT_INFO_INIT proto fastcall :PWDF_INTERRUPT_INFO
WDF_INTERRUPT_EXTENDED_POLICY struct
    Size_ DWORD ?
    Policy WDF_INTERRUPT_POLICY ?
    Priority WDF_INTERRUPT_PRIORITY ?
    TargetProcessorSetAndGroup GROUP_AFFINITY <>
WDF_INTERRUPT_EXTENDED_POLICY ends

PWDF_INTERRUPT_EXTENDED_POLICY typedef ptr WDF_INTERRUPT_EXTENDED_POLICY

WDF_INTERRUPT_EXTENDED_POLICY_INIT proto fastcall :PWDF_INTERRUPT_EXTENDED_POLICY
proto_PFN_WDFINTERRUPTCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_INTERRUPT_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFINTERRUPT
PFN_WDFINTERRUPTCREATE typedef ptr proto_PFN_WDFINTERRUPTCREATE
WdfInterruptCreate proto fastcall :WDFDEVICE, :PWDF_INTERRUPT_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFINTERRUPT
proto_PFN_WDFINTERRUPTQUEUEDPCFORISR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFINTERRUPT
PFN_WDFINTERRUPTQUEUEDPCFORISR typedef ptr proto_PFN_WDFINTERRUPTQUEUEDPCFORISR
WdfInterruptQueueDpcForIsr proto fastcall :WDFINTERRUPT
proto_PFN_WDFINTERRUPTSYNCHRONIZE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFINTERRUPT, :PFN_WDF_INTERRUPT_SYNCHRONIZE, :WDFCONTEXT
PFN_WDFINTERRUPTSYNCHRONIZE typedef ptr proto_PFN_WDFINTERRUPTSYNCHRONIZE
WdfInterruptSynchronize proto fastcall :WDFINTERRUPT, :PFN_WDF_INTERRUPT_SYNCHRONIZE, :WDFCONTEXT
proto_PFN_WDFINTERRUPTACQUIRELOCK typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFINTERRUPT
PFN_WDFINTERRUPTACQUIRELOCK typedef ptr proto_PFN_WDFINTERRUPTACQUIRELOCK
WdfInterruptAcquireLock proto fastcall :WDFINTERRUPT
proto_PFN_WDFINTERRUPTRELEASELOCK typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFINTERRUPT
PFN_WDFINTERRUPTRELEASELOCK typedef ptr proto_PFN_WDFINTERRUPTRELEASELOCK
WdfInterruptReleaseLock proto fastcall :WDFINTERRUPT
proto_PFN_WDFINTERRUPTENABLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFINTERRUPT
PFN_WDFINTERRUPTENABLE typedef ptr proto_PFN_WDFINTERRUPTENABLE
WdfInterruptEnable proto fastcall :WDFINTERRUPT
proto_PFN_WDFINTERRUPTDISABLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFINTERRUPT
PFN_WDFINTERRUPTDISABLE typedef ptr proto_PFN_WDFINTERRUPTDISABLE
WdfInterruptDisable proto fastcall :WDFINTERRUPT
proto_PFN_WDFINTERRUPTWDMGETINTERRUPT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFINTERRUPT
PFN_WDFINTERRUPTWDMGETINTERRUPT typedef ptr proto_PFN_WDFINTERRUPTWDMGETINTERRUPT
WdfInterruptWdmGetInterrupt proto fastcall :WDFINTERRUPT
proto_PFN_WDFINTERRUPTGETINFO typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFINTERRUPT, :PWDF_INTERRUPT_INFO
PFN_WDFINTERRUPTGETINFO typedef ptr proto_PFN_WDFINTERRUPTGETINFO
WdfInterruptGetInfo proto fastcall :WDFINTERRUPT, :PWDF_INTERRUPT_INFO
proto_PFN_WDFINTERRUPTSETPOLICY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFINTERRUPT, :WDF_INTERRUPT_POLICY, :WDF_INTERRUPT_PRIORITY, :KAFFINITY
PFN_WDFINTERRUPTSETPOLICY typedef ptr proto_PFN_WDFINTERRUPTSETPOLICY
WdfInterruptSetPolicy proto fastcall :WDFINTERRUPT, :WDF_INTERRUPT_POLICY, :WDF_INTERRUPT_PRIORITY, :KAFFINITY
proto_PFN_WDFINTERRUPTSETEXTENDEDPOLICY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFINTERRUPT, :PWDF_INTERRUPT_EXTENDED_POLICY
PFN_WDFINTERRUPTSETEXTENDEDPOLICY typedef ptr proto_PFN_WDFINTERRUPTSETEXTENDEDPOLICY
WdfInterruptSetExtendedPolicy proto fastcall :WDFINTERRUPT, :PWDF_INTERRUPT_EXTENDED_POLICY
proto_PFN_WDFINTERRUPTGETDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFINTERRUPT
PFN_WDFINTERRUPTGETDEVICE typedef ptr proto_PFN_WDFINTERRUPTGETDEVICE
WdfInterruptGetDevice proto fastcall :WDFINTERRUPT


;-------------------------------------------------------------------------
; wdfresource.h
;-------------------------------------------------------------------------
WDF_INSERT_AT_END equ - 1
proto_PFN_WDFIORESOURCEREQUIREMENTSLISTSETSLOTNUMBER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESREQLIST, :DWORD
PFN_WDFIORESOURCEREQUIREMENTSLISTSETSLOTNUMBER typedef ptr proto_PFN_WDFIORESOURCEREQUIREMENTSLISTSETSLOTNUMBER
WdfIoResourceRequirementsListSetSlotNumber proto fastcall :WDFIORESREQLIST, :DWORD
proto_PFN_WDFIORESOURCEREQUIREMENTSLISTSETINTERFACETYPE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESREQLIST, :INTERFACE_TYPE
PFN_WDFIORESOURCEREQUIREMENTSLISTSETINTERFACETYPE typedef ptr proto_PFN_WDFIORESOURCEREQUIREMENTSLISTSETINTERFACETYPE
WdfIoResourceRequirementsListSetInterfaceType proto fastcall :WDFIORESREQLIST, :INTERFACE_TYPE
proto_PFN_WDFIORESOURCEREQUIREMENTSLISTAPPENDIORESLIST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESREQLIST, :WDFIORESLIST
PFN_WDFIORESOURCEREQUIREMENTSLISTAPPENDIORESLIST typedef ptr proto_PFN_WDFIORESOURCEREQUIREMENTSLISTAPPENDIORESLIST
WdfIoResourceRequirementsListAppendIoResList proto fastcall :WDFIORESREQLIST, :WDFIORESLIST
proto_PFN_WDFIORESOURCEREQUIREMENTSLISTINSERTIORESLIST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESREQLIST, :WDFIORESLIST, :DWORD
PFN_WDFIORESOURCEREQUIREMENTSLISTINSERTIORESLIST typedef ptr proto_PFN_WDFIORESOURCEREQUIREMENTSLISTINSERTIORESLIST
WdfIoResourceRequirementsListInsertIoResList proto fastcall :WDFIORESREQLIST, :WDFIORESLIST, :DWORD
proto_PFN_WDFIORESOURCEREQUIREMENTSLISTGETCOUNT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESREQLIST
PFN_WDFIORESOURCEREQUIREMENTSLISTGETCOUNT typedef ptr proto_PFN_WDFIORESOURCEREQUIREMENTSLISTGETCOUNT
WdfIoResourceRequirementsListGetCount proto fastcall :WDFIORESREQLIST
proto_PFN_WDFIORESOURCEREQUIREMENTSLISTGETIORESLIST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESREQLIST, :DWORD
PFN_WDFIORESOURCEREQUIREMENTSLISTGETIORESLIST typedef ptr proto_PFN_WDFIORESOURCEREQUIREMENTSLISTGETIORESLIST
WdfIoResourceRequirementsListGetIoResList proto fastcall :WDFIORESREQLIST, :DWORD
proto_PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESREQLIST, :DWORD
PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVE typedef ptr proto_PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVE
WdfIoResourceRequirementsListRemove proto fastcall :WDFIORESREQLIST, :DWORD
proto_PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVEBYIORESLIST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESREQLIST, :WDFIORESLIST
PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVEBYIORESLIST typedef ptr proto_PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVEBYIORESLIST
WdfIoResourceRequirementsListRemoveByIoResList proto fastcall :WDFIORESREQLIST, :WDFIORESLIST
proto_PFN_WDFIORESOURCELISTCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESREQLIST, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFIORESLIST
PFN_WDFIORESOURCELISTCREATE typedef ptr proto_PFN_WDFIORESOURCELISTCREATE
WdfIoResourceListCreate proto fastcall :WDFIORESREQLIST, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFIORESLIST
proto_PFN_WDFIORESOURCELISTAPPENDDESCRIPTOR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESLIST, :PIO_RESOURCE_DESCRIPTOR
PFN_WDFIORESOURCELISTAPPENDDESCRIPTOR typedef ptr proto_PFN_WDFIORESOURCELISTAPPENDDESCRIPTOR
WdfIoResourceListAppendDescriptor proto fastcall :WDFIORESLIST, :PIO_RESOURCE_DESCRIPTOR
proto_PFN_WDFIORESOURCELISTINSERTDESCRIPTOR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESLIST, :PIO_RESOURCE_DESCRIPTOR, :DWORD
PFN_WDFIORESOURCELISTINSERTDESCRIPTOR typedef ptr proto_PFN_WDFIORESOURCELISTINSERTDESCRIPTOR
WdfIoResourceListInsertDescriptor proto fastcall :WDFIORESLIST, :PIO_RESOURCE_DESCRIPTOR, :DWORD
proto_PFN_WDFIORESOURCELISTUPDATEDESCRIPTOR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESLIST, :PIO_RESOURCE_DESCRIPTOR, :DWORD
PFN_WDFIORESOURCELISTUPDATEDESCRIPTOR typedef ptr proto_PFN_WDFIORESOURCELISTUPDATEDESCRIPTOR
WdfIoResourceListUpdateDescriptor proto fastcall :WDFIORESLIST, :PIO_RESOURCE_DESCRIPTOR, :DWORD
proto_PFN_WDFIORESOURCELISTGETCOUNT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESLIST
PFN_WDFIORESOURCELISTGETCOUNT typedef ptr proto_PFN_WDFIORESOURCELISTGETCOUNT
WdfIoResourceListGetCount proto fastcall :WDFIORESLIST
proto_PFN_WDFIORESOURCELISTGETDESCRIPTOR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESLIST, :DWORD
PFN_WDFIORESOURCELISTGETDESCRIPTOR typedef ptr proto_PFN_WDFIORESOURCELISTGETDESCRIPTOR
WdfIoResourceListGetDescriptor proto fastcall :WDFIORESLIST, :DWORD
proto_PFN_WDFIORESOURCELISTREMOVE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESLIST, :DWORD
PFN_WDFIORESOURCELISTREMOVE typedef ptr proto_PFN_WDFIORESOURCELISTREMOVE
WdfIoResourceListRemove proto fastcall :WDFIORESLIST, :DWORD
proto_PFN_WDFIORESOURCELISTREMOVEBYDESCRIPTOR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIORESLIST, :PIO_RESOURCE_DESCRIPTOR
PFN_WDFIORESOURCELISTREMOVEBYDESCRIPTOR typedef ptr proto_PFN_WDFIORESOURCELISTREMOVEBYDESCRIPTOR
WdfIoResourceListRemoveByDescriptor proto fastcall :WDFIORESLIST, :PIO_RESOURCE_DESCRIPTOR
proto_PFN_WDFCMRESOURCELISTAPPENDDESCRIPTOR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCMRESLIST, :PCM_PARTIAL_RESOURCE_DESCRIPTOR
PFN_WDFCMRESOURCELISTAPPENDDESCRIPTOR typedef ptr proto_PFN_WDFCMRESOURCELISTAPPENDDESCRIPTOR
WdfCmResourceListAppendDescriptor proto fastcall :WDFCMRESLIST, :PCM_PARTIAL_RESOURCE_DESCRIPTOR
proto_PFN_WDFCMRESOURCELISTINSERTDESCRIPTOR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCMRESLIST, :PCM_PARTIAL_RESOURCE_DESCRIPTOR, :DWORD
PFN_WDFCMRESOURCELISTINSERTDESCRIPTOR typedef ptr proto_PFN_WDFCMRESOURCELISTINSERTDESCRIPTOR
WdfCmResourceListInsertDescriptor proto fastcall :WDFCMRESLIST, :PCM_PARTIAL_RESOURCE_DESCRIPTOR, :DWORD
proto_PFN_WDFCMRESOURCELISTGETCOUNT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCMRESLIST
PFN_WDFCMRESOURCELISTGETCOUNT typedef ptr proto_PFN_WDFCMRESOURCELISTGETCOUNT
WdfCmResourceListGetCount proto fastcall :WDFCMRESLIST
proto_PFN_WDFCMRESOURCELISTGETDESCRIPTOR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCMRESLIST, :DWORD
PFN_WDFCMRESOURCELISTGETDESCRIPTOR typedef ptr proto_PFN_WDFCMRESOURCELISTGETDESCRIPTOR
WdfCmResourceListGetDescriptor proto fastcall :WDFCMRESLIST, :DWORD
proto_PFN_WDFCMRESOURCELISTREMOVE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCMRESLIST, :DWORD
PFN_WDFCMRESOURCELISTREMOVE typedef ptr proto_PFN_WDFCMRESOURCELISTREMOVE
WdfCmResourceListRemove proto fastcall :WDFCMRESLIST, :DWORD
proto_PFN_WDFCMRESOURCELISTREMOVEBYDESCRIPTOR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCMRESLIST, :PCM_PARTIAL_RESOURCE_DESCRIPTOR
PFN_WDFCMRESOURCELISTREMOVEBYDESCRIPTOR typedef ptr proto_PFN_WDFCMRESOURCELISTREMOVEBYDESCRIPTOR
WdfCmResourceListRemoveByDescriptor proto fastcall :WDFCMRESLIST, :PCM_PARTIAL_RESOURCE_DESCRIPTOR


;-------------------------------------------------------------------------
; wdfrequest.h
;-------------------------------------------------------------------------
WDF_REQUEST_TYPE typedef SDWORD
WdfRequestTypeCreate EQU 0h 
WdfRequestTypeCreateNamedPipe EQU 1h 
WdfRequestTypeClose EQU 2h 
WdfRequestTypeRead EQU 3h 
WdfRequestTypeWrite EQU 4h 
WdfRequestTypeQueryInformation EQU 5h 
WdfRequestTypeSetInformation EQU 6h 
WdfRequestTypeQueryEA EQU 7h 
WdfRequestTypeSetEA EQU 8h 
WdfRequestTypeFlushBuffers EQU 9h 
WdfRequestTypeQueryVolumeInformation EQU 0ah 
WdfRequestTypeSetVolumeInformation EQU 0bh 
WdfRequestTypeDirectoryControl EQU 0ch 
WdfRequestTypeFileSystemControl EQU 0dh 
WdfRequestTypeDeviceControl EQU 0eh 
WdfRequestTypeDeviceControlInternal EQU 0fh 
WdfRequestTypeShutdown EQU 10h 
WdfRequestTypeLockControl EQU 11h 
WdfRequestTypeCleanup EQU 12h 
WdfRequestTypeCreateMailSlot EQU 13h 
WdfRequestTypeQuerySecurity EQU 14h 
WdfRequestTypeSetSecurity EQU 15h 
WdfRequestTypePower EQU 16h 
WdfRequestTypeSystemControl EQU 17h 
WdfRequestTypeDeviceChange EQU 18h 
WdfRequestTypeQueryQuota EQU 19h 
WdfRequestTypeSetQuota EQU 1Ah 
WdfRequestTypePnp EQU 1Bh 
WdfRequestTypeOther EQU 1Ch 
WdfRequestTypeUsb EQU 40h 
WdfRequestTypeNoFormat EQU 0FFh 
WdfRequestTypeMax EQU 1

WDF_REQUEST_REUSE_FLAGS typedef SDWORD
WDF_REQUEST_REUSE_NO_FLAGS EQU 00000000h 
WDF_REQUEST_REUSE_SET_NEW_IRP EQU 00000001h 

WDF_REQUEST_STOP_ACTION_FLAGS typedef SDWORD
WdfRequestStopActionInvalid EQU 0 
WdfRequestStopActionSuspend EQU 01h 
WdfRequestStopActionPurge EQU 2h 
WdfRequestStopRequestCancelable EQU 10000000h 

WDF_REQUEST_SEND_OPTIONS_FLAGS typedef SDWORD
WDF_REQUEST_SEND_OPTION_TIMEOUT EQU 0000001h 
WDF_REQUEST_SEND_OPTION_SYNCHRONOUS EQU 0000002h 
WDF_REQUEST_SEND_OPTION_IGNORE_TARGET_STATE EQU 0000004h 
WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET EQU 0000008h 

IFNDEF IO_SECURITY_CONTEXT
IO_SECURITY_CONTEXT STRUCT
    SecurityQos PSECURITY_QUALITY_OF_SERVICE ?
    AccessState PACCESS_STATE ?
    DesiredAccess ACCESS_MASK ?
    FullCreateOptions DWORD ?
IO_SECURITY_CONTEXT ENDS
ENDIF
PIO_SECURITY_CONTEXT typedef ptr IO_SECURITY_CONTEXT


EVT_WDF_REQUEST_CANCEL typedef proto stdcall :WDFREQUEST
PFN_WDF_REQUEST_CANCEL typedef ptr EVT_WDF_REQUEST_CANCEL
WDF_REQUEST_PARAMETERS struct
    Size_ WORD ?
    MinorFunction BYTE ?
    Type_ WDF_REQUEST_TYPE ?
    union Parameters
        struct Create
            SecurityContext PIO_SECURITY_CONTEXT ?
            Options DWORD ?
            FileAttributes POINTER_ALIGNMENT ?
            ShareAccess WORD ?
            EaLength POINTER_ALIGNMENT ?
        ends
        struct Read
            Length_ size_t ?
            Key POINTER_ALIGNMENT ?
            DeviceOffset QWORD ?
        ends
        struct Write
            Length_ size_t ?
            Key POINTER_ALIGNMENT ?
            DeviceOffset QWORD ?
        ends
        struct DeviceIoControl
            OutputBufferLength size_t ?
            InputBufferLength POINTER_ALIGNMENT ?
            IoControlCode POINTER_ALIGNMENT ?
            Type3InputBuffer PVOID ?
        ends
        struct Others
            Arg1 PVOID ?
            Arg2 PVOID ?
            IoControlCode POINTER_ALIGNMENT ?
            Arg4 PVOID ?
        ends
    ends
WDF_REQUEST_PARAMETERS ends

PWDF_REQUEST_PARAMETERS typedef ptr WDF_REQUEST_PARAMETERS

WDF_REQUEST_PARAMETERS_INIT proto fastcall :PWDF_REQUEST_PARAMETERS

WDF_REQUEST_COMPLETION_PARAMS struct
    Size_ DWORD ?
    Type_ WDF_REQUEST_TYPE ?
    IoStatus IO_STATUS_BLOCK <>
    union Parameters
        struct Write
            Buffer WDFMEMORY ?
            Length_ size_t ?
            Offset_ size_t ?
        ends
        struct Read
            Buffer WDFMEMORY ?
            Length_ size_t ?
            Offset_ size_t ?
        ends
        struct Ioctl
            IoControlCode DWORD ?
            struct Input
                Buffer WDFMEMORY ?
                Offset_ size_t ?
            ends
            struct Output
                Buffer WDFMEMORY ?
                Offset_ size_t ?
                Length_ size_t ?
            ends
        ends
        struct Others
            union Argument1
                Ptr_ PVOID ?
                Value ULONG_PTR ?
            ends
            union Argument2
                Ptr_ PVOID ?
                Value ULONG_PTR ?
            ends
            union Argument3
                Ptr_ PVOID ?
                Value ULONG_PTR ?
            ends
            union Argument4
                Ptr_ PVOID ?
                Value ULONG_PTR ?
            ends
        ends
        struct Usb
            Completion QWORD ?;PWDF_USB_REQUEST_COMPLETION_PARAMS ?
        ends
    ends
WDF_REQUEST_COMPLETION_PARAMS ends

PWDF_REQUEST_COMPLETION_PARAMS typedef ptr WDF_REQUEST_COMPLETION_PARAMS

WDF_REQUEST_COMPLETION_PARAMS_INIT proto fastcall :PWDF_REQUEST_COMPLETION_PARAMS
EVT_WDF_REQUEST_COMPLETION_ROUTINE typedef proto stdcall :WDFREQUEST,:WDFIOTARGET,:PWDF_REQUEST_COMPLETION_PARAMS,:WDFCONTEXT
PFN_WDF_REQUEST_COMPLETION_ROUTINE typedef ptr EVT_WDF_REQUEST_COMPLETION_ROUTINE
WDF_REQUEST_REUSE_PARAMS struct
    Size_ DWORD ?
    Flags DWORD ?
    Status NTSTATUS ?
    NewIrp PIRP ?
WDF_REQUEST_REUSE_PARAMS ends

PWDF_REQUEST_REUSE_PARAMS typedef ptr WDF_REQUEST_REUSE_PARAMS

WDF_REQUEST_REUSE_PARAMS_INIT proto fastcall :PWDF_REQUEST_REUSE_PARAMS, :DWORD, :NTSTATUS
WDF_REQUEST_REUSE_PARAMS_SET_NEW_IRP proto fastcall :PWDF_REQUEST_REUSE_PARAMS, :PIRP
WDF_REQUEST_SEND_OPTIONS struct
    Size_ DWORD ?
    Flags DWORD ?
    Timeout QWORD ?
WDF_REQUEST_SEND_OPTIONS ends

PWDF_REQUEST_SEND_OPTIONS typedef ptr WDF_REQUEST_SEND_OPTIONS

WDF_REQUEST_SEND_OPTIONS_INIT proto fastcall :PWDF_REQUEST_SEND_OPTIONS, :DWORD
WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT proto fastcall :PWDF_REQUEST_SEND_OPTIONS, :QWORD
WDF_REQUEST_FORWARD_OPTIONS_FLAGS typedef SDWORD
WDF_REQUEST_FORWARD_OPTION_SEND_AND_FORGET EQU 0000001h 

WDF_REQUEST_FORWARD_OPTIONS struct
    Size_ DWORD ?
    Flags DWORD ?
WDF_REQUEST_FORWARD_OPTIONS ends

PWDF_REQUEST_FORWARD_OPTIONS typedef ptr WDF_REQUEST_FORWARD_OPTIONS

WDF_REQUEST_FORWARD_OPTIONS_INIT proto fastcall :PWDF_REQUEST_FORWARD_OPTIONS
proto_PFN_WDFREQUESTCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDF_OBJECT_ATTRIBUTES, :WDFIOTARGET, :ptr WDFREQUEST
PFN_WDFREQUESTCREATE typedef ptr proto_PFN_WDFREQUESTCREATE
WdfRequestCreate proto fastcall :PWDF_OBJECT_ATTRIBUTES, :WDFIOTARGET, :ptr WDFREQUEST
proto_PFN_WDFREQUESTCREATEFROMIRP typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDF_OBJECT_ATTRIBUTES, :PIRP, :BOOLEAN, :ptr WDFREQUEST
PFN_WDFREQUESTCREATEFROMIRP typedef ptr proto_PFN_WDFREQUESTCREATEFROMIRP
WdfRequestCreateFromIrp proto fastcall :PWDF_OBJECT_ATTRIBUTES, :PIRP, :BOOLEAN, :ptr WDFREQUEST
proto_PFN_WDFREQUESTREUSE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :PWDF_REQUEST_REUSE_PARAMS
PFN_WDFREQUESTREUSE typedef ptr proto_PFN_WDFREQUESTREUSE
WdfRequestReuse proto fastcall :WDFREQUEST, :PWDF_REQUEST_REUSE_PARAMS
proto_PFN_WDFREQUESTCHANGETARGET typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :WDFIOTARGET
PFN_WDFREQUESTCHANGETARGET typedef ptr proto_PFN_WDFREQUESTCHANGETARGET
WdfRequestChangeTarget proto fastcall :WDFREQUEST, :WDFIOTARGET
proto_PFN_WDFREQUESTFORMATREQUESTUSINGCURRENTTYPE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTFORMATREQUESTUSINGCURRENTTYPE typedef ptr proto_PFN_WDFREQUESTFORMATREQUESTUSINGCURRENTTYPE
WdfRequestFormatRequestUsingCurrentType proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTWDMFORMATUSINGSTACKLOCATION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :PIO_STACK_LOCATION
PFN_WDFREQUESTWDMFORMATUSINGSTACKLOCATION typedef ptr proto_PFN_WDFREQUESTWDMFORMATUSINGSTACKLOCATION
WdfRequestWdmFormatUsingStackLocation proto fastcall :WDFREQUEST, :PIO_STACK_LOCATION
proto_PFN_WDFREQUESTSEND typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :WDFIOTARGET, :PWDF_REQUEST_SEND_OPTIONS
PFN_WDFREQUESTSEND typedef ptr proto_PFN_WDFREQUESTSEND
WdfRequestSend proto fastcall :WDFREQUEST, :WDFIOTARGET, :PWDF_REQUEST_SEND_OPTIONS
proto_PFN_WDFREQUESTGETSTATUS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTGETSTATUS typedef ptr proto_PFN_WDFREQUESTGETSTATUS
WdfRequestGetStatus proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTMARKCANCELABLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :PFN_WDF_REQUEST_CANCEL
PFN_WDFREQUESTMARKCANCELABLE typedef ptr proto_PFN_WDFREQUESTMARKCANCELABLE
WdfRequestMarkCancelable proto fastcall :WDFREQUEST, :PFN_WDF_REQUEST_CANCEL
proto_PFN_WDFREQUESTMARKCANCELABLEEX typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :PFN_WDF_REQUEST_CANCEL
PFN_WDFREQUESTMARKCANCELABLEEX typedef ptr proto_PFN_WDFREQUESTMARKCANCELABLEEX
WdfRequestMarkCancelableEx proto fastcall :WDFREQUEST, :PFN_WDF_REQUEST_CANCEL
proto_PFN_WDFREQUESTUNMARKCANCELABLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTUNMARKCANCELABLE typedef ptr proto_PFN_WDFREQUESTUNMARKCANCELABLE
WdfRequestUnmarkCancelable proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTISCANCELED typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTISCANCELED typedef ptr proto_PFN_WDFREQUESTISCANCELED
WdfRequestIsCanceled proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTCANCELSENTREQUEST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTCANCELSENTREQUEST typedef ptr proto_PFN_WDFREQUESTCANCELSENTREQUEST
WdfRequestCancelSentRequest proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTISFROM32BITPROCESS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTISFROM32BITPROCESS typedef ptr proto_PFN_WDFREQUESTISFROM32BITPROCESS
WdfRequestIsFrom32BitProcess proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTSETCOMPLETIONROUTINE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :PFN_WDF_REQUEST_COMPLETION_ROUTINE, :WDFCONTEXT
PFN_WDFREQUESTSETCOMPLETIONROUTINE typedef ptr proto_PFN_WDFREQUESTSETCOMPLETIONROUTINE
WdfRequestSetCompletionRoutine proto fastcall :WDFREQUEST, :PFN_WDF_REQUEST_COMPLETION_ROUTINE, :WDFCONTEXT
proto_PFN_WDFREQUESTGETCOMPLETIONPARAMS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :PWDF_REQUEST_COMPLETION_PARAMS
PFN_WDFREQUESTGETCOMPLETIONPARAMS typedef ptr proto_PFN_WDFREQUESTGETCOMPLETIONPARAMS
WdfRequestGetCompletionParams proto fastcall :WDFREQUEST, :PWDF_REQUEST_COMPLETION_PARAMS
proto_PFN_WDFREQUESTALLOCATETIMER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTALLOCATETIMER typedef ptr proto_PFN_WDFREQUESTALLOCATETIMER
WdfRequestAllocateTimer proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTCOMPLETE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :NTSTATUS
PFN_WDFREQUESTCOMPLETE typedef ptr proto_PFN_WDFREQUESTCOMPLETE
WdfRequestComplete proto fastcall :WDFREQUEST, :NTSTATUS
proto_PFN_WDFREQUESTCOMPLETEWITHPRIORITYBOOST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :NTSTATUS, :CCHAR
PFN_WDFREQUESTCOMPLETEWITHPRIORITYBOOST typedef ptr proto_PFN_WDFREQUESTCOMPLETEWITHPRIORITYBOOST
WdfRequestCompleteWithPriorityBoost proto fastcall :WDFREQUEST, :NTSTATUS, :CCHAR
proto_PFN_WDFREQUESTCOMPLETEWITHINFORMATION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :NTSTATUS, :ULONG_PTR
PFN_WDFREQUESTCOMPLETEWITHINFORMATION typedef ptr proto_PFN_WDFREQUESTCOMPLETEWITHINFORMATION
WdfRequestCompleteWithInformation proto fastcall :WDFREQUEST, :NTSTATUS, :ULONG_PTR
proto_PFN_WDFREQUESTGETPARAMETERS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :PWDF_REQUEST_PARAMETERS
PFN_WDFREQUESTGETPARAMETERS typedef ptr proto_PFN_WDFREQUESTGETPARAMETERS
WdfRequestGetParameters proto fastcall :WDFREQUEST, :PWDF_REQUEST_PARAMETERS
proto_PFN_WDFREQUESTRETRIEVEINPUTMEMORY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :ptr WDFMEMORY
PFN_WDFREQUESTRETRIEVEINPUTMEMORY typedef ptr proto_PFN_WDFREQUESTRETRIEVEINPUTMEMORY
WdfRequestRetrieveInputMemory proto fastcall :WDFREQUEST, :ptr WDFMEMORY
proto_PFN_WDFREQUESTRETRIEVEOUTPUTMEMORY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :ptr WDFMEMORY
PFN_WDFREQUESTRETRIEVEOUTPUTMEMORY typedef ptr proto_PFN_WDFREQUESTRETRIEVEOUTPUTMEMORY
WdfRequestRetrieveOutputMemory proto fastcall :WDFREQUEST, :ptr WDFMEMORY
proto_PFN_WDFREQUESTRETRIEVEINPUTBUFFER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :size_t, :ptr PVOID, :ptr size_t
PFN_WDFREQUESTRETRIEVEINPUTBUFFER typedef ptr proto_PFN_WDFREQUESTRETRIEVEINPUTBUFFER
WdfRequestRetrieveInputBuffer proto fastcall :WDFREQUEST, :size_t, :ptr PVOID, :ptr size_t
proto_PFN_WDFREQUESTRETRIEVEOUTPUTBUFFER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :size_t, :ptr PVOID, :ptr size_t
PFN_WDFREQUESTRETRIEVEOUTPUTBUFFER typedef ptr proto_PFN_WDFREQUESTRETRIEVEOUTPUTBUFFER
WdfRequestRetrieveOutputBuffer proto fastcall :WDFREQUEST, :size_t, :ptr PVOID, :ptr size_t
proto_PFN_WDFREQUESTRETRIEVEINPUTWDMMDL typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :ptr PMDL
PFN_WDFREQUESTRETRIEVEINPUTWDMMDL typedef ptr proto_PFN_WDFREQUESTRETRIEVEINPUTWDMMDL
WdfRequestRetrieveInputWdmMdl proto fastcall :WDFREQUEST, :ptr PMDL
proto_PFN_WDFREQUESTRETRIEVEOUTPUTWDMMDL typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :ptr PMDL
PFN_WDFREQUESTRETRIEVEOUTPUTWDMMDL typedef ptr proto_PFN_WDFREQUESTRETRIEVEOUTPUTWDMMDL
WdfRequestRetrieveOutputWdmMdl proto fastcall :WDFREQUEST, :ptr PMDL
proto_PFN_WDFREQUESTRETRIEVEUNSAFEUSERINPUTBUFFER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :size_t, :ptr PVOID, :ptr size_t
PFN_WDFREQUESTRETRIEVEUNSAFEUSERINPUTBUFFER typedef ptr proto_PFN_WDFREQUESTRETRIEVEUNSAFEUSERINPUTBUFFER
WdfRequestRetrieveUnsafeUserInputBuffer proto fastcall :WDFREQUEST, :size_t, :ptr PVOID, :ptr size_t
proto_PFN_WDFREQUESTRETRIEVEUNSAFEUSEROUTPUTBUFFER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :size_t, :ptr PVOID, :ptr size_t
PFN_WDFREQUESTRETRIEVEUNSAFEUSEROUTPUTBUFFER typedef ptr proto_PFN_WDFREQUESTRETRIEVEUNSAFEUSEROUTPUTBUFFER
WdfRequestRetrieveUnsafeUserOutputBuffer proto fastcall :WDFREQUEST, :size_t, :ptr PVOID, :ptr size_t
proto_PFN_WDFREQUESTSETINFORMATION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :ULONG_PTR
PFN_WDFREQUESTSETINFORMATION typedef ptr proto_PFN_WDFREQUESTSETINFORMATION
WdfRequestSetInformation proto fastcall :WDFREQUEST, :ULONG_PTR
proto_PFN_WDFREQUESTGETINFORMATION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTGETINFORMATION typedef ptr proto_PFN_WDFREQUESTGETINFORMATION
WdfRequestGetInformation proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTGETFILEOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTGETFILEOBJECT typedef ptr proto_PFN_WDFREQUESTGETFILEOBJECT
WdfRequestGetFileObject proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTPROBEANDLOCKUSERBUFFERFORREAD typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :PVOID, :size_t, :ptr WDFMEMORY
PFN_WDFREQUESTPROBEANDLOCKUSERBUFFERFORREAD typedef ptr proto_PFN_WDFREQUESTPROBEANDLOCKUSERBUFFERFORREAD
WdfRequestProbeAndLockUserBufferForRead proto fastcall :WDFREQUEST, :PVOID, :size_t, :ptr WDFMEMORY
proto_PFN_WDFREQUESTPROBEANDLOCKUSERBUFFERFORWRITE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :PVOID, :size_t, :ptr WDFMEMORY
PFN_WDFREQUESTPROBEANDLOCKUSERBUFFERFORWRITE typedef ptr proto_PFN_WDFREQUESTPROBEANDLOCKUSERBUFFERFORWRITE
WdfRequestProbeAndLockUserBufferForWrite proto fastcall :WDFREQUEST, :PVOID, :size_t, :ptr WDFMEMORY
proto_PFN_WDFREQUESTGETREQUESTORMODE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTGETREQUESTORMODE typedef ptr proto_PFN_WDFREQUESTGETREQUESTORMODE
WdfRequestGetRequestorMode proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTFORWARDTOIOQUEUE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :WDFQUEUE
PFN_WDFREQUESTFORWARDTOIOQUEUE typedef ptr proto_PFN_WDFREQUESTFORWARDTOIOQUEUE
WdfRequestForwardToIoQueue proto fastcall :WDFREQUEST, :WDFQUEUE
proto_PFN_WDFREQUESTGETIOQUEUE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTGETIOQUEUE typedef ptr proto_PFN_WDFREQUESTGETIOQUEUE
WdfRequestGetIoQueue proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTREQUEUE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTREQUEUE typedef ptr proto_PFN_WDFREQUESTREQUEUE
WdfRequestRequeue proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTSTOPACKNOWLEDGE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :BOOLEAN
PFN_WDFREQUESTSTOPACKNOWLEDGE typedef ptr proto_PFN_WDFREQUESTSTOPACKNOWLEDGE
WdfRequestStopAcknowledge proto fastcall :WDFREQUEST, :BOOLEAN
proto_PFN_WDFREQUESTWDMGETIRP typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTWDMGETIRP typedef ptr proto_PFN_WDFREQUESTWDMGETIRP
WdfRequestWdmGetIrp proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTISRESERVED typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST
PFN_WDFREQUESTISRESERVED typedef ptr proto_PFN_WDFREQUESTISRESERVED
WdfRequestIsReserved proto fastcall :WDFREQUEST
proto_PFN_WDFREQUESTFORWARDTOPARENTDEVICEIOQUEUE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFREQUEST, :WDFQUEUE, :PWDF_REQUEST_FORWARD_OPTIONS
PFN_WDFREQUESTFORWARDTOPARENTDEVICEIOQUEUE typedef ptr proto_PFN_WDFREQUESTFORWARDTOPARENTDEVICEIOQUEUE
WdfRequestForwardToParentDeviceIoQueue proto fastcall :WDFREQUEST, :WDFQUEUE, :PWDF_REQUEST_FORWARD_OPTIONS


;-------------------------------------------------------------------------
; wdfiotarget.h
;-------------------------------------------------------------------------
WDF_IO_TARGET_STATE typedef SDWORD
WdfIoTargetStateUndefined EQU 0 
WdfIoTargetStarted EQU 1
WdfIoTargetStopped EQU 2
WdfIoTargetClosedForQueryRemove EQU 3
WdfIoTargetClosed EQU 4
WdfIoTargetDeleted EQU 5

PWDF_IO_TARGET_STATE typedef ptr WDF_IO_TARGET_STATE

WDF_IO_TARGET_OPEN_TYPE typedef SDWORD
WdfIoTargetOpenUndefined EQU 0 
WdfIoTargetOpenUseExistingDevice EQU 1 
WdfIoTargetOpenByName EQU 2 
WdfIoTargetOpenReopen EQU 3 

WDF_IO_TARGET_SENT_IO_ACTION typedef SDWORD
WdfIoTargetSentIoUndefined EQU 0 
WdfIoTargetCancelSentIo EQU 1
WdfIoTargetWaitForSentIoToComplete EQU 2
WdfIoTargetLeaveSentIoPending EQU 3

EVT_WDF_IO_TARGET_QUERY_REMOVE typedef proto stdcall :WDFIOTARGET
PFN_WDF_IO_TARGET_QUERY_REMOVE typedef ptr EVT_WDF_IO_TARGET_QUERY_REMOVE
EVT_WDF_IO_TARGET_REMOVE_CANCELED typedef proto stdcall :WDFIOTARGET
PFN_WDF_IO_TARGET_REMOVE_CANCELED typedef ptr EVT_WDF_IO_TARGET_REMOVE_CANCELED
EVT_WDF_IO_TARGET_REMOVE_COMPLETE typedef proto stdcall :WDFIOTARGET
PFN_WDF_IO_TARGET_REMOVE_COMPLETE typedef ptr EVT_WDF_IO_TARGET_REMOVE_COMPLETE
WDF_IO_TARGET_OPEN_PARAMS struct
    Size_ DWORD ?
    Type_ WDF_IO_TARGET_OPEN_TYPE ?
    EvtIoTargetQueryRemove PFN_WDF_IO_TARGET_QUERY_REMOVE ?
    EvtIoTargetRemoveCanceled PFN_WDF_IO_TARGET_REMOVE_CANCELED ?
    EvtIoTargetRemoveComplete PFN_WDF_IO_TARGET_REMOVE_COMPLETE ?
    TargetDeviceObject PDEVICE_OBJECT ?
    TargetFileObject PFILE_OBJECT ?
    TargetDeviceName UNICODE_STRING <>
    DesiredAccess ACCESS_MASK ?
    ShareAccess DWORD ?
    FileAttributes DWORD ?
    CreateDisposition DWORD ?
    CreateOptions DWORD ?
    EaBuffer PVOID ?
    EaBufferLength DWORD ?
    AllocationSize PLONGLONG ?
    FileInformation DWORD ?
WDF_IO_TARGET_OPEN_PARAMS ends

PWDF_IO_TARGET_OPEN_PARAMS typedef ptr WDF_IO_TARGET_OPEN_PARAMS

WDF_IO_TARGET_OPEN_PARAMS_INIT_EXISTING_DEVICE proto fastcall :PWDF_IO_TARGET_OPEN_PARAMS, :PDEVICE_OBJECT
WDF_IO_TARGET_OPEN_PARAMS_INIT_CREATE_BY_NAME proto fastcall :PWDF_IO_TARGET_OPEN_PARAMS, :PCUNICODE_STRING, :ACCESS_MASK
WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME proto fastcall :PWDF_IO_TARGET_OPEN_PARAMS, :PCUNICODE_STRING, :ACCESS_MASK
WDF_IO_TARGET_OPEN_PARAMS_INIT_REOPEN proto fastcall :PWDF_IO_TARGET_OPEN_PARAMS
proto_PFN_WDFIOTARGETCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFIOTARGET
PFN_WDFIOTARGETCREATE typedef ptr proto_PFN_WDFIOTARGETCREATE
WdfIoTargetCreate proto fastcall :WDFDEVICE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFIOTARGET
proto_PFN_WDFIOTARGETOPEN typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :PWDF_IO_TARGET_OPEN_PARAMS
PFN_WDFIOTARGETOPEN typedef ptr proto_PFN_WDFIOTARGETOPEN
WdfIoTargetOpen proto fastcall :WDFIOTARGET, :PWDF_IO_TARGET_OPEN_PARAMS
proto_PFN_WDFIOTARGETCLOSEFORQUERYREMOVE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET
PFN_WDFIOTARGETCLOSEFORQUERYREMOVE typedef ptr proto_PFN_WDFIOTARGETCLOSEFORQUERYREMOVE
WdfIoTargetCloseForQueryRemove proto fastcall :WDFIOTARGET
proto_PFN_WDFIOTARGETCLOSE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET
PFN_WDFIOTARGETCLOSE typedef ptr proto_PFN_WDFIOTARGETCLOSE
WdfIoTargetClose proto fastcall :WDFIOTARGET
proto_PFN_WDFIOTARGETSTART typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET
PFN_WDFIOTARGETSTART typedef ptr proto_PFN_WDFIOTARGETSTART
WdfIoTargetStart proto fastcall :WDFIOTARGET
proto_PFN_WDFIOTARGETSTOP typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :WDF_IO_TARGET_SENT_IO_ACTION
PFN_WDFIOTARGETSTOP typedef ptr proto_PFN_WDFIOTARGETSTOP
WdfIoTargetStop proto fastcall :WDFIOTARGET, :WDF_IO_TARGET_SENT_IO_ACTION
proto_PFN_WDFIOTARGETGETSTATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET
PFN_WDFIOTARGETGETSTATE typedef ptr proto_PFN_WDFIOTARGETGETSTATE
WdfIoTargetGetState proto fastcall :WDFIOTARGET
proto_PFN_WDFIOTARGETGETDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET
PFN_WDFIOTARGETGETDEVICE typedef ptr proto_PFN_WDFIOTARGETGETDEVICE
WdfIoTargetGetDevice proto fastcall :WDFIOTARGET
proto_PFN_WDFIOTARGETQUERYTARGETPROPERTY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :DEVICE_REGISTRY_PROPERTY, :DWORD, :PVOID, :PULONG
PFN_WDFIOTARGETQUERYTARGETPROPERTY typedef ptr proto_PFN_WDFIOTARGETQUERYTARGETPROPERTY
WdfIoTargetQueryTargetProperty proto fastcall :WDFIOTARGET, :DEVICE_REGISTRY_PROPERTY, :DWORD, :PVOID, :PULONG
proto_PFN_WDFIOTARGETALLOCANDQUERYTARGETPROPERTY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :DEVICE_REGISTRY_PROPERTY, :POOL_TYPE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFMEMORY
PFN_WDFIOTARGETALLOCANDQUERYTARGETPROPERTY typedef ptr proto_PFN_WDFIOTARGETALLOCANDQUERYTARGETPROPERTY
WdfIoTargetAllocAndQueryTargetProperty proto fastcall :WDFIOTARGET, :DEVICE_REGISTRY_PROPERTY, :POOL_TYPE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFMEMORY
proto_PFN_WDFIOTARGETQUERYFORINTERFACE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :LPCGUID, :PINTERFACE, :WORD, :WORD, :PVOID
PFN_WDFIOTARGETQUERYFORINTERFACE typedef ptr proto_PFN_WDFIOTARGETQUERYFORINTERFACE
WdfIoTargetQueryForInterface proto fastcall :WDFIOTARGET, :LPCGUID, :PINTERFACE, :WORD, :WORD, :PVOID
proto_PFN_WDFIOTARGETWDMGETTARGETDEVICEOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET
PFN_WDFIOTARGETWDMGETTARGETDEVICEOBJECT typedef ptr proto_PFN_WDFIOTARGETWDMGETTARGETDEVICEOBJECT
WdfIoTargetWdmGetTargetDeviceObject proto fastcall :WDFIOTARGET
proto_PFN_WDFIOTARGETWDMGETTARGETPHYSICALDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET
PFN_WDFIOTARGETWDMGETTARGETPHYSICALDEVICE typedef ptr proto_PFN_WDFIOTARGETWDMGETTARGETPHYSICALDEVICE
WdfIoTargetWdmGetTargetPhysicalDevice proto fastcall :WDFIOTARGET
proto_PFN_WDFIOTARGETWDMGETTARGETFILEOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET
PFN_WDFIOTARGETWDMGETTARGETFILEOBJECT typedef ptr proto_PFN_WDFIOTARGETWDMGETTARGETFILEOBJECT
WdfIoTargetWdmGetTargetFileObject proto fastcall :WDFIOTARGET
proto_PFN_WDFIOTARGETWDMGETTARGETFILEHANDLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET
PFN_WDFIOTARGETWDMGETTARGETFILEHANDLE typedef ptr proto_PFN_WDFIOTARGETWDMGETTARGETFILEHANDLE
WdfIoTargetWdmGetTargetFileHandle proto fastcall :WDFIOTARGET
proto_PFN_WDFIOTARGETSENDREADSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :WDFREQUEST, :PWDF_MEMORY_DESCRIPTOR, :PLONGLONG, :PWDF_REQUEST_SEND_OPTIONS, :PULONG_PTR
PFN_WDFIOTARGETSENDREADSYNCHRONOUSLY typedef ptr proto_PFN_WDFIOTARGETSENDREADSYNCHRONOUSLY
WdfIoTargetSendReadSynchronously proto fastcall :WDFIOTARGET, :WDFREQUEST, :PWDF_MEMORY_DESCRIPTOR, :PLONGLONG, :PWDF_REQUEST_SEND_OPTIONS, :PULONG_PTR
proto_PFN_WDFIOTARGETFORMATREQUESTFORREAD typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET, :PLONGLONG
PFN_WDFIOTARGETFORMATREQUESTFORREAD typedef ptr proto_PFN_WDFIOTARGETFORMATREQUESTFORREAD
WdfIoTargetFormatRequestForRead proto fastcall :WDFIOTARGET, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET, :PLONGLONG
proto_PFN_WDFIOTARGETSENDWRITESYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :WDFREQUEST, :PWDF_MEMORY_DESCRIPTOR, :PLONGLONG, :PWDF_REQUEST_SEND_OPTIONS, :PULONG_PTR
PFN_WDFIOTARGETSENDWRITESYNCHRONOUSLY typedef ptr proto_PFN_WDFIOTARGETSENDWRITESYNCHRONOUSLY
WdfIoTargetSendWriteSynchronously proto fastcall :WDFIOTARGET, :WDFREQUEST, :PWDF_MEMORY_DESCRIPTOR, :PLONGLONG, :PWDF_REQUEST_SEND_OPTIONS, :PULONG_PTR
proto_PFN_WDFIOTARGETFORMATREQUESTFORWRITE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET, :PLONGLONG
PFN_WDFIOTARGETFORMATREQUESTFORWRITE typedef ptr proto_PFN_WDFIOTARGETFORMATREQUESTFORWRITE
WdfIoTargetFormatRequestForWrite proto fastcall :WDFIOTARGET, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET, :PLONGLONG
proto_PFN_WDFIOTARGETSENDIOCTLSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :WDFREQUEST, :DWORD, :PWDF_MEMORY_DESCRIPTOR, :PWDF_MEMORY_DESCRIPTOR, :PWDF_REQUEST_SEND_OPTIONS, :PULONG_PTR
PFN_WDFIOTARGETSENDIOCTLSYNCHRONOUSLY typedef ptr proto_PFN_WDFIOTARGETSENDIOCTLSYNCHRONOUSLY
WdfIoTargetSendIoctlSynchronously proto fastcall :WDFIOTARGET, :WDFREQUEST, :DWORD, :PWDF_MEMORY_DESCRIPTOR, :PWDF_MEMORY_DESCRIPTOR, :PWDF_REQUEST_SEND_OPTIONS, :PULONG_PTR
proto_PFN_WDFIOTARGETFORMATREQUESTFORIOCTL typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :WDFREQUEST, :DWORD, :WDFMEMORY, :PWDFMEMORY_OFFSET, :WDFMEMORY, :PWDFMEMORY_OFFSET
PFN_WDFIOTARGETFORMATREQUESTFORIOCTL typedef ptr proto_PFN_WDFIOTARGETFORMATREQUESTFORIOCTL
WdfIoTargetFormatRequestForIoctl proto fastcall :WDFIOTARGET, :WDFREQUEST, :DWORD, :WDFMEMORY, :PWDFMEMORY_OFFSET, :WDFMEMORY, :PWDFMEMORY_OFFSET
proto_PFN_WDFIOTARGETSENDINTERNALIOCTLSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :WDFREQUEST, :DWORD, :PWDF_MEMORY_DESCRIPTOR, :PWDF_MEMORY_DESCRIPTOR, :PWDF_REQUEST_SEND_OPTIONS, :PULONG_PTR
PFN_WDFIOTARGETSENDINTERNALIOCTLSYNCHRONOUSLY typedef ptr proto_PFN_WDFIOTARGETSENDINTERNALIOCTLSYNCHRONOUSLY
WdfIoTargetSendInternalIoctlSynchronously proto fastcall :WDFIOTARGET, :WDFREQUEST, :DWORD, :PWDF_MEMORY_DESCRIPTOR, :PWDF_MEMORY_DESCRIPTOR, :PWDF_REQUEST_SEND_OPTIONS, :PULONG_PTR
proto_PFN_WDFIOTARGETFORMATREQUESTFORINTERNALIOCTL typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :WDFREQUEST, :DWORD, :WDFMEMORY, :PWDFMEMORY_OFFSET, :WDFMEMORY, :PWDFMEMORY_OFFSET
PFN_WDFIOTARGETFORMATREQUESTFORINTERNALIOCTL typedef ptr proto_PFN_WDFIOTARGETFORMATREQUESTFORINTERNALIOCTL
WdfIoTargetFormatRequestForInternalIoctl proto fastcall :WDFIOTARGET, :WDFREQUEST, :DWORD, :WDFMEMORY, :PWDFMEMORY_OFFSET, :WDFMEMORY, :PWDFMEMORY_OFFSET
proto_PFN_WDFIOTARGETSENDINTERNALIOCTLOTHERSSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :WDFREQUEST, :DWORD, :PWDF_MEMORY_DESCRIPTOR, :PWDF_MEMORY_DESCRIPTOR, :PWDF_MEMORY_DESCRIPTOR, :PWDF_REQUEST_SEND_OPTIONS, :PULONG_PTR
PFN_WDFIOTARGETSENDINTERNALIOCTLOTHERSSYNCHRONOUSLY typedef ptr proto_PFN_WDFIOTARGETSENDINTERNALIOCTLOTHERSSYNCHRONOUSLY
WdfIoTargetSendInternalIoctlOthersSynchronously proto fastcall :WDFIOTARGET, :WDFREQUEST, :DWORD, :PWDF_MEMORY_DESCRIPTOR, :PWDF_MEMORY_DESCRIPTOR, :PWDF_MEMORY_DESCRIPTOR, :PWDF_REQUEST_SEND_OPTIONS, :PULONG_PTR
proto_PFN_WDFIOTARGETFORMATREQUESTFORINTERNALIOCTLOTHERS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFIOTARGET, :WDFREQUEST, :DWORD, :WDFMEMORY, :PWDFMEMORY_OFFSET, :WDFMEMORY, :PWDFMEMORY_OFFSET, :WDFMEMORY, :PWDFMEMORY_OFFSET
PFN_WDFIOTARGETFORMATREQUESTFORINTERNALIOCTLOTHERS typedef ptr proto_PFN_WDFIOTARGETFORMATREQUESTFORINTERNALIOCTLOTHERS
WdfIoTargetFormatRequestForInternalIoctlOthers proto fastcall :WDFIOTARGET, :WDFREQUEST, :DWORD, :WDFMEMORY, :PWDFMEMORY_OFFSET, :WDFMEMORY, :PWDFMEMORY_OFFSET, :WDFMEMORY, :PWDFMEMORY_OFFSET


;-------------------------------------------------------------------------
; wdfio.h
;-------------------------------------------------------------------------
WDF_IO_QUEUE_DISPATCH_TYPE typedef SDWORD
WdfIoQueueDispatchInvalid EQU 0 
WdfIoQueueDispatchSequential EQU 1
WdfIoQueueDispatchParallel EQU 2
WdfIoQueueDispatchManual EQU 3
WdfIoQueueDispatchMax EQU 4

WDF_IO_QUEUE_STATE typedef SDWORD
WdfIoQueueAcceptRequests EQU 01h 
WdfIoQueueDispatchRequests EQU 02h 
WdfIoQueueNoRequests EQU 04h 
WdfIoQueueDriverNoRequests EQU 08h 
WdfIoQueuePnpHeld EQU 10h 

WDF_IO_QUEUE_IDLE proto fastcall :WDF_IO_QUEUE_STATE
WDF_IO_QUEUE_READY proto fastcall :WDF_IO_QUEUE_STATE
WDF_IO_QUEUE_STOPPED proto fastcall :WDF_IO_QUEUE_STATE
WDF_IO_QUEUE_DRAINED proto fastcall :WDF_IO_QUEUE_STATE
WDF_IO_QUEUE_PURGED proto fastcall :WDF_IO_QUEUE_STATE
EVT_WDF_IO_QUEUE_IO_DEFAULT typedef proto stdcall :WDFQUEUE,:WDFREQUEST
PFN_WDF_IO_QUEUE_IO_DEFAULT typedef ptr EVT_WDF_IO_QUEUE_IO_DEFAULT
EVT_WDF_IO_QUEUE_IO_STOP typedef proto stdcall :WDFQUEUE,:WDFREQUEST,:DWORD
PFN_WDF_IO_QUEUE_IO_STOP typedef ptr EVT_WDF_IO_QUEUE_IO_STOP
EVT_WDF_IO_QUEUE_IO_RESUME typedef proto stdcall :WDFQUEUE,:WDFREQUEST
PFN_WDF_IO_QUEUE_IO_RESUME typedef ptr EVT_WDF_IO_QUEUE_IO_RESUME
EVT_WDF_IO_QUEUE_IO_READ typedef proto stdcall :WDFQUEUE,:WDFREQUEST,:size_t
PFN_WDF_IO_QUEUE_IO_READ typedef ptr EVT_WDF_IO_QUEUE_IO_READ
EVT_WDF_IO_QUEUE_IO_WRITE typedef proto stdcall :WDFQUEUE,:WDFREQUEST,:size_t
PFN_WDF_IO_QUEUE_IO_WRITE typedef ptr EVT_WDF_IO_QUEUE_IO_WRITE
EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL typedef proto stdcall :WDFQUEUE,:WDFREQUEST,:size_t,:size_t,:DWORD
PFN_WDF_IO_QUEUE_IO_DEVICE_CONTROL typedef ptr EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL
EVT_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL typedef proto stdcall :WDFQUEUE,:WDFREQUEST,:size_t,:size_t,:DWORD
PFN_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL typedef ptr EVT_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL
EVT_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE typedef proto stdcall :WDFQUEUE,:WDFREQUEST
PFN_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE typedef ptr EVT_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE
EVT_WDF_IO_QUEUE_STATE typedef proto stdcall :WDFQUEUE,:WDFCONTEXT
PFN_WDF_IO_QUEUE_STATE typedef ptr EVT_WDF_IO_QUEUE_STATE
WDF_IO_QUEUE_CONFIG struct
    Size_ DWORD ?
    DispatchType WDF_IO_QUEUE_DISPATCH_TYPE ?
    PowerManaged WDF_TRI_STATE ?
    AllowZeroLengthRequests BOOLEAN ?
    DefaultQueue BOOLEAN ?
    EvtIoDefault PFN_WDF_IO_QUEUE_IO_DEFAULT ?
    EvtIoRead PFN_WDF_IO_QUEUE_IO_READ ?
    EvtIoWrite PFN_WDF_IO_QUEUE_IO_WRITE ?
    EvtIoDeviceControl PFN_WDF_IO_QUEUE_IO_DEVICE_CONTROL ?
    EvtIoInternalDeviceControl PFN_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL ?
    EvtIoStop PFN_WDF_IO_QUEUE_IO_STOP ?
    EvtIoResume PFN_WDF_IO_QUEUE_IO_RESUME ?
    EvtIoCanceledOnQueue PFN_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE ?
    union Settings
        struct Parallel
            NumberOfPresentedRequests DWORD ?
        ends
    ends
WDF_IO_QUEUE_CONFIG ends

PWDF_IO_QUEUE_CONFIG typedef ptr WDF_IO_QUEUE_CONFIG

WDF_IO_QUEUE_CONFIG_INIT proto fastcall :PWDF_IO_QUEUE_CONFIG, :WDF_IO_QUEUE_DISPATCH_TYPE
WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE proto fastcall :PWDF_IO_QUEUE_CONFIG, :WDF_IO_QUEUE_DISPATCH_TYPE
WDF_IO_FORWARD_PROGRESS_ACTION typedef SDWORD
WdfIoForwardProgressActionInvalid EQU 0h 
WdfIoForwardProgressActionFailRequest EQU 1
WdfIoForwardProgressActionUseReservedRequest EQU 2

WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY typedef SDWORD
WdfIoForwardProgressInvalidPolicy EQU 0h 
WdfIoForwardProgressReservedPolicyAlwaysUseReservedRequest EQU 1
WdfIoForwardProgressReservedPolicyUseExamine EQU 2
WdfIoForwardProgressReservedPolicyPagingIO EQU 3

EVT_WDF_IO_ALLOCATE_RESOURCES_FOR_RESERVED_REQUEST typedef proto stdcall :WDFQUEUE,:WDFREQUEST
PFN_WDF_IO_ALLOCATE_RESOURCES_FOR_RESERVED_REQUEST typedef ptr EVT_WDF_IO_ALLOCATE_RESOURCES_FOR_RESERVED_REQUEST
EVT_WDF_IO_ALLOCATE_REQUEST_RESOURCES typedef proto stdcall :WDFQUEUE,:WDFREQUEST
PFN_WDF_IO_ALLOCATE_REQUEST_RESOURCES typedef ptr EVT_WDF_IO_ALLOCATE_REQUEST_RESOURCES
EVT_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS typedef proto stdcall :WDFQUEUE,:PIRP
PFN_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS typedef ptr EVT_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS
WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY_SETTINGS struct
    union Policy
        struct ExaminePolicy
            EvtIoWdmIrpForForwardProgress PFN_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS ?
        ends
    ends
WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY_SETTINGS ends

WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY struct
    Size_ DWORD ?
    TotalForwardProgressRequests DWORD ?
    ForwardProgressReservedPolicy WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY ?
    ForwardProgressReservePolicySettings WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY_SETTINGS <>
    EvtIoAllocateResourcesForReservedRequest PFN_WDF_IO_ALLOCATE_RESOURCES_FOR_RESERVED_REQUEST ?
    EvtIoAllocateRequestResources PFN_WDF_IO_ALLOCATE_REQUEST_RESOURCES ?
WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY ends

PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY typedef ptr WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY

WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_DEFAULT_INIT proto fastcall :PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY, :DWORD
WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_EXAMINE_INIT proto fastcall :PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY, :DWORD, :PFN_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS
WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_PAGINGIO_INIT proto fastcall :PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY, :DWORD
proto_PFN_WDFIOQUEUECREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_IO_QUEUE_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFQUEUE
PFN_WDFIOQUEUECREATE typedef ptr proto_PFN_WDFIOQUEUECREATE
WdfIoQueueCreate proto fastcall :WDFDEVICE, :PWDF_IO_QUEUE_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFQUEUE
proto_PFN_WDFIOQUEUEGETSTATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE, :PULONG, :PULONG
PFN_WDFIOQUEUEGETSTATE typedef ptr proto_PFN_WDFIOQUEUEGETSTATE
WdfIoQueueGetState proto fastcall :WDFQUEUE, :PULONG, :PULONG
proto_PFN_WDFIOQUEUESTART typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE
PFN_WDFIOQUEUESTART typedef ptr proto_PFN_WDFIOQUEUESTART
WdfIoQueueStart proto fastcall :WDFQUEUE
proto_PFN_WDFIOQUEUESTOP typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE, :PFN_WDF_IO_QUEUE_STATE, :WDFCONTEXT
PFN_WDFIOQUEUESTOP typedef ptr proto_PFN_WDFIOQUEUESTOP
WdfIoQueueStop proto fastcall :WDFQUEUE, :PFN_WDF_IO_QUEUE_STATE, :WDFCONTEXT
proto_PFN_WDFIOQUEUESTOPSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE
PFN_WDFIOQUEUESTOPSYNCHRONOUSLY typedef ptr proto_PFN_WDFIOQUEUESTOPSYNCHRONOUSLY
WdfIoQueueStopSynchronously proto fastcall :WDFQUEUE
proto_PFN_WDFIOQUEUEGETDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE
PFN_WDFIOQUEUEGETDEVICE typedef ptr proto_PFN_WDFIOQUEUEGETDEVICE
WdfIoQueueGetDevice proto fastcall :WDFQUEUE
proto_PFN_WDFIOQUEUERETRIEVENEXTREQUEST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE, :ptr WDFREQUEST
PFN_WDFIOQUEUERETRIEVENEXTREQUEST typedef ptr proto_PFN_WDFIOQUEUERETRIEVENEXTREQUEST
WdfIoQueueRetrieveNextRequest proto fastcall :WDFQUEUE, :ptr WDFREQUEST
proto_PFN_WDFIOQUEUERETRIEVEREQUESTBYFILEOBJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE, :WDFFILEOBJECT, :ptr WDFREQUEST
PFN_WDFIOQUEUERETRIEVEREQUESTBYFILEOBJECT typedef ptr proto_PFN_WDFIOQUEUERETRIEVEREQUESTBYFILEOBJECT
WdfIoQueueRetrieveRequestByFileObject proto fastcall :WDFQUEUE, :WDFFILEOBJECT, :ptr WDFREQUEST
proto_PFN_WDFIOQUEUEFINDREQUEST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE, :WDFREQUEST, :WDFFILEOBJECT, :PWDF_REQUEST_PARAMETERS, :ptr WDFREQUEST
PFN_WDFIOQUEUEFINDREQUEST typedef ptr proto_PFN_WDFIOQUEUEFINDREQUEST
WdfIoQueueFindRequest proto fastcall :WDFQUEUE, :WDFREQUEST, :WDFFILEOBJECT, :PWDF_REQUEST_PARAMETERS, :ptr WDFREQUEST
proto_PFN_WDFIOQUEUERETRIEVEFOUNDREQUEST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE, :WDFREQUEST, :ptr WDFREQUEST
PFN_WDFIOQUEUERETRIEVEFOUNDREQUEST typedef ptr proto_PFN_WDFIOQUEUERETRIEVEFOUNDREQUEST
WdfIoQueueRetrieveFoundRequest proto fastcall :WDFQUEUE, :WDFREQUEST, :ptr WDFREQUEST
proto_PFN_WDFIOQUEUEDRAINSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE
PFN_WDFIOQUEUEDRAINSYNCHRONOUSLY typedef ptr proto_PFN_WDFIOQUEUEDRAINSYNCHRONOUSLY
WdfIoQueueDrainSynchronously proto fastcall :WDFQUEUE
proto_PFN_WDFIOQUEUEDRAIN typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE, :PFN_WDF_IO_QUEUE_STATE, :WDFCONTEXT
PFN_WDFIOQUEUEDRAIN typedef ptr proto_PFN_WDFIOQUEUEDRAIN
WdfIoQueueDrain proto fastcall :WDFQUEUE, :PFN_WDF_IO_QUEUE_STATE, :WDFCONTEXT
proto_PFN_WDFIOQUEUEPURGESYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE
PFN_WDFIOQUEUEPURGESYNCHRONOUSLY typedef ptr proto_PFN_WDFIOQUEUEPURGESYNCHRONOUSLY
WdfIoQueuePurgeSynchronously proto fastcall :WDFQUEUE
proto_PFN_WDFIOQUEUEPURGE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE, :PFN_WDF_IO_QUEUE_STATE, :WDFCONTEXT
PFN_WDFIOQUEUEPURGE typedef ptr proto_PFN_WDFIOQUEUEPURGE
WdfIoQueuePurge proto fastcall :WDFQUEUE, :PFN_WDF_IO_QUEUE_STATE, :WDFCONTEXT
proto_PFN_WDFIOQUEUEREADYNOTIFY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE, :PFN_WDF_IO_QUEUE_STATE, :WDFCONTEXT
PFN_WDFIOQUEUEREADYNOTIFY typedef ptr proto_PFN_WDFIOQUEUEREADYNOTIFY
WdfIoQueueReadyNotify proto fastcall :WDFQUEUE, :PFN_WDF_IO_QUEUE_STATE, :WDFCONTEXT
proto_PFN_WDFIOQUEUEASSIGNFORWARDPROGRESSPOLICY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFQUEUE, :PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY
PFN_WDFIOQUEUEASSIGNFORWARDPROGRESSPOLICY typedef ptr proto_PFN_WDFIOQUEUEASSIGNFORWARDPROGRESSPOLICY
WdfIoQueueAssignForwardProgressPolicy proto fastcall :WDFQUEUE, :PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY


;-------------------------------------------------------------------------
; wdffdo.h
;-------------------------------------------------------------------------
EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS typedef proto stdcall :WDFDEVICE,:WDFIORESREQLIST
PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS typedef ptr EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS
EVT_WDF_DEVICE_REMOVE_ADDED_RESOURCES typedef proto stdcall :WDFDEVICE,:WDFCMRESLIST,:WDFCMRESLIST
PFN_WDF_DEVICE_REMOVE_ADDED_RESOURCES typedef ptr EVT_WDF_DEVICE_REMOVE_ADDED_RESOURCES
WDF_FDO_EVENT_CALLBACKS struct
    Size_ DWORD ?
    EvtDeviceFilterAddResourceRequirements PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS ?
    EvtDeviceFilterRemoveResourceRequirements PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS ?
    EvtDeviceRemoveAddedResources PFN_WDF_DEVICE_REMOVE_ADDED_RESOURCES ?
WDF_FDO_EVENT_CALLBACKS ends

PWDF_FDO_EVENT_CALLBACKS typedef ptr WDF_FDO_EVENT_CALLBACKS

WDF_FDO_EVENT_CALLBACKS_INIT proto fastcall :PWDF_FDO_EVENT_CALLBACKS
proto_PFN_WDFFDOINITWDMGETPHYSICALDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT
PFN_WDFFDOINITWDMGETPHYSICALDEVICE typedef ptr proto_PFN_WDFFDOINITWDMGETPHYSICALDEVICE
WdfFdoInitWdmGetPhysicalDevice proto fastcall :PWDFDEVICE_INIT
proto_PFN_WDFFDOINITOPENREGISTRYKEY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :DWORD, :ACCESS_MASK, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFKEY
PFN_WDFFDOINITOPENREGISTRYKEY typedef ptr proto_PFN_WDFFDOINITOPENREGISTRYKEY
WdfFdoInitOpenRegistryKey proto fastcall :PWDFDEVICE_INIT, :DWORD, :ACCESS_MASK, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFKEY
proto_PFN_WDFFDOINITQUERYPROPERTY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :DEVICE_REGISTRY_PROPERTY, :DWORD, :PVOID, :PULONG
PFN_WDFFDOINITQUERYPROPERTY typedef ptr proto_PFN_WDFFDOINITQUERYPROPERTY
WdfFdoInitQueryProperty proto fastcall :PWDFDEVICE_INIT, :DEVICE_REGISTRY_PROPERTY, :DWORD, :PVOID, :PULONG
proto_PFN_WDFFDOINITALLOCANDQUERYPROPERTY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :DEVICE_REGISTRY_PROPERTY, :POOL_TYPE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFMEMORY
PFN_WDFFDOINITALLOCANDQUERYPROPERTY typedef ptr proto_PFN_WDFFDOINITALLOCANDQUERYPROPERTY
WdfFdoInitAllocAndQueryProperty proto fastcall :PWDFDEVICE_INIT, :DEVICE_REGISTRY_PROPERTY, :POOL_TYPE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFMEMORY
proto_PFN_WDFFDOINITSETEVENTCALLBACKS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PWDF_FDO_EVENT_CALLBACKS
PFN_WDFFDOINITSETEVENTCALLBACKS typedef ptr proto_PFN_WDFFDOINITSETEVENTCALLBACKS
WdfFdoInitSetEventCallbacks proto fastcall :PWDFDEVICE_INIT, :PWDF_FDO_EVENT_CALLBACKS
proto_PFN_WDFFDOINITSETFILTER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT
PFN_WDFFDOINITSETFILTER typedef ptr proto_PFN_WDFFDOINITSETFILTER
WdfFdoInitSetFilter proto fastcall :PWDFDEVICE_INIT
proto_PFN_WDFFDOINITSETDEFAULTCHILDLISTCONFIG typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PWDF_CHILD_LIST_CONFIG, :PWDF_OBJECT_ATTRIBUTES
PFN_WDFFDOINITSETDEFAULTCHILDLISTCONFIG typedef ptr proto_PFN_WDFFDOINITSETDEFAULTCHILDLISTCONFIG
WdfFdoInitSetDefaultChildListConfig proto fastcall :PWDFDEVICE_INIT, :PWDF_CHILD_LIST_CONFIG, :PWDF_OBJECT_ATTRIBUTES
proto_PFN_WDFFDOQUERYFORINTERFACE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :LPCGUID, :PINTERFACE, :WORD, :WORD, :PVOID
PFN_WDFFDOQUERYFORINTERFACE typedef ptr proto_PFN_WDFFDOQUERYFORINTERFACE
WdfFdoQueryForInterface proto fastcall :WDFDEVICE, :LPCGUID, :PINTERFACE, :WORD, :WORD, :PVOID
proto_PFN_WDFFDOGETDEFAULTCHILDLIST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFFDOGETDEFAULTCHILDLIST typedef ptr proto_PFN_WDFFDOGETDEFAULTCHILDLIST
WdfFdoGetDefaultChildList proto fastcall :WDFDEVICE
proto_PFN_WDFFDOADDSTATICCHILD typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :WDFDEVICE
PFN_WDFFDOADDSTATICCHILD typedef ptr proto_PFN_WDFFDOADDSTATICCHILD
WdfFdoAddStaticChild proto fastcall :WDFDEVICE, :WDFDEVICE
proto_PFN_WDFFDOLOCKSTATICCHILDLISTFORITERATION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFFDOLOCKSTATICCHILDLISTFORITERATION typedef ptr proto_PFN_WDFFDOLOCKSTATICCHILDLISTFORITERATION
WdfFdoLockStaticChildListForIteration proto fastcall :WDFDEVICE
proto_PFN_WDFFDORETRIEVENEXTSTATICCHILD typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :WDFDEVICE, :DWORD
PFN_WDFFDORETRIEVENEXTSTATICCHILD typedef ptr proto_PFN_WDFFDORETRIEVENEXTSTATICCHILD
WdfFdoRetrieveNextStaticChild proto fastcall :WDFDEVICE, :WDFDEVICE, :DWORD
proto_PFN_WDFFDOUNLOCKSTATICCHILDLISTFROMITERATION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFFDOUNLOCKSTATICCHILDLISTFROMITERATION typedef ptr proto_PFN_WDFFDOUNLOCKSTATICCHILDLISTFROMITERATION
WdfFdoUnlockStaticChildListFromIteration proto fastcall :WDFDEVICE


;-------------------------------------------------------------------------
; wdfpdo.h
;-------------------------------------------------------------------------
EVT_WDF_DEVICE_RESOURCES_QUERY typedef proto stdcall :WDFDEVICE,:WDFCMRESLIST
PFN_WDF_DEVICE_RESOURCES_QUERY typedef ptr EVT_WDF_DEVICE_RESOURCES_QUERY
EVT_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY typedef proto stdcall :WDFDEVICE,:WDFIORESREQLIST
PFN_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY typedef ptr EVT_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY
EVT_WDF_DEVICE_EJECT typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_EJECT typedef ptr EVT_WDF_DEVICE_EJECT
EVT_WDF_DEVICE_SET_LOCK typedef proto stdcall :WDFDEVICE,:BOOLEAN
PFN_WDF_DEVICE_SET_LOCK typedef ptr EVT_WDF_DEVICE_SET_LOCK
EVT_WDF_DEVICE_ENABLE_WAKE_AT_BUS typedef proto stdcall :WDFDEVICE,:SYSTEM_POWER_STATE
PFN_WDF_DEVICE_ENABLE_WAKE_AT_BUS typedef ptr EVT_WDF_DEVICE_ENABLE_WAKE_AT_BUS
EVT_WDF_DEVICE_DISABLE_WAKE_AT_BUS typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_DISABLE_WAKE_AT_BUS typedef ptr EVT_WDF_DEVICE_DISABLE_WAKE_AT_BUS
WDF_PDO_EVENT_CALLBACKS struct
    Size_ DWORD ?
    EvtDeviceResourcesQuery PFN_WDF_DEVICE_RESOURCES_QUERY ?
    EvtDeviceResourceRequirementsQuery PFN_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY ?
    EvtDeviceEject PFN_WDF_DEVICE_EJECT ?
    EvtDeviceSetLock PFN_WDF_DEVICE_SET_LOCK ?
    EvtDeviceEnableWakeAtBus PFN_WDF_DEVICE_ENABLE_WAKE_AT_BUS ?
    EvtDeviceDisableWakeAtBus PFN_WDF_DEVICE_DISABLE_WAKE_AT_BUS ?
WDF_PDO_EVENT_CALLBACKS ends

PWDF_PDO_EVENT_CALLBACKS typedef ptr WDF_PDO_EVENT_CALLBACKS

WDF_PDO_EVENT_CALLBACKS_INIT proto fastcall :PWDF_PDO_EVENT_CALLBACKS
proto_PFN_WDFPDOINITALLOCATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFPDOINITALLOCATE typedef ptr proto_PFN_WDFPDOINITALLOCATE
WdfPdoInitAllocate proto fastcall :WDFDEVICE
proto_PFN_WDFPDOINITSETEVENTCALLBACKS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PWDF_PDO_EVENT_CALLBACKS
PFN_WDFPDOINITSETEVENTCALLBACKS typedef ptr proto_PFN_WDFPDOINITSETEVENTCALLBACKS
WdfPdoInitSetEventCallbacks proto fastcall :PWDFDEVICE_INIT, :PWDF_PDO_EVENT_CALLBACKS
proto_PFN_WDFPDOINITASSIGNDEVICEID typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PCUNICODE_STRING
PFN_WDFPDOINITASSIGNDEVICEID typedef ptr proto_PFN_WDFPDOINITASSIGNDEVICEID
WdfPdoInitAssignDeviceID proto fastcall :PWDFDEVICE_INIT, :PCUNICODE_STRING
proto_PFN_WDFPDOINITASSIGNINSTANCEID typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PCUNICODE_STRING
PFN_WDFPDOINITASSIGNINSTANCEID typedef ptr proto_PFN_WDFPDOINITASSIGNINSTANCEID
WdfPdoInitAssignInstanceID proto fastcall :PWDFDEVICE_INIT, :PCUNICODE_STRING
proto_PFN_WDFPDOINITADDHARDWAREID typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PCUNICODE_STRING
PFN_WDFPDOINITADDHARDWAREID typedef ptr proto_PFN_WDFPDOINITADDHARDWAREID
WdfPdoInitAddHardwareID proto fastcall :PWDFDEVICE_INIT, :PCUNICODE_STRING
proto_PFN_WDFPDOINITADDCOMPATIBLEID typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PCUNICODE_STRING
PFN_WDFPDOINITADDCOMPATIBLEID typedef ptr proto_PFN_WDFPDOINITADDCOMPATIBLEID
WdfPdoInitAddCompatibleID proto fastcall :PWDFDEVICE_INIT, :PCUNICODE_STRING
proto_PFN_WDFPDOINITASSIGNCONTAINERID typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PCUNICODE_STRING
PFN_WDFPDOINITASSIGNCONTAINERID typedef ptr proto_PFN_WDFPDOINITASSIGNCONTAINERID
WdfPdoInitAssignContainerID proto fastcall :PWDFDEVICE_INIT, :PCUNICODE_STRING
proto_PFN_WDFPDOINITADDDEVICETEXT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PCUNICODE_STRING, :PCUNICODE_STRING, :LCID
PFN_WDFPDOINITADDDEVICETEXT typedef ptr proto_PFN_WDFPDOINITADDDEVICETEXT
WdfPdoInitAddDeviceText proto fastcall :PWDFDEVICE_INIT, :PCUNICODE_STRING, :PCUNICODE_STRING, :LCID
proto_PFN_WDFPDOINITSETDEFAULTLOCALE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :LCID
PFN_WDFPDOINITSETDEFAULTLOCALE typedef ptr proto_PFN_WDFPDOINITSETDEFAULTLOCALE
WdfPdoInitSetDefaultLocale proto fastcall :PWDFDEVICE_INIT, :LCID
proto_PFN_WDFPDOINITASSIGNRAWDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :ptr GUID
PFN_WDFPDOINITASSIGNRAWDEVICE typedef ptr proto_PFN_WDFPDOINITASSIGNRAWDEVICE
WdfPdoInitAssignRawDevice proto fastcall :PWDFDEVICE_INIT, :ptr GUID
proto_PFN_WDFPDOINITALLOWFORWARDINGREQUESTTOPARENT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT
PFN_WDFPDOINITALLOWFORWARDINGREQUESTTOPARENT typedef ptr proto_PFN_WDFPDOINITALLOWFORWARDINGREQUESTTOPARENT
WdfPdoInitAllowForwardingRequestToParent proto fastcall :PWDFDEVICE_INIT
proto_PFN_WDFPDOMARKMISSING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFPDOMARKMISSING typedef ptr proto_PFN_WDFPDOMARKMISSING
WdfPdoMarkMissing proto fastcall :WDFDEVICE
proto_PFN_WDFPDOREQUESTEJECT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFPDOREQUESTEJECT typedef ptr proto_PFN_WDFPDOREQUESTEJECT
WdfPdoRequestEject proto fastcall :WDFDEVICE
proto_PFN_WDFPDOGETPARENT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFPDOGETPARENT typedef ptr proto_PFN_WDFPDOGETPARENT
WdfPdoGetParent proto fastcall :WDFDEVICE
proto_PFN_WDFPDORETRIEVEIDENTIFICATIONDESCRIPTION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER
PFN_WDFPDORETRIEVEIDENTIFICATIONDESCRIPTION typedef ptr proto_PFN_WDFPDORETRIEVEIDENTIFICATIONDESCRIPTION
WdfPdoRetrieveIdentificationDescription proto fastcall :WDFDEVICE, :PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER
proto_PFN_WDFPDORETRIEVEADDRESSDESCRIPTION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER
PFN_WDFPDORETRIEVEADDRESSDESCRIPTION typedef ptr proto_PFN_WDFPDORETRIEVEADDRESSDESCRIPTION
WdfPdoRetrieveAddressDescription proto fastcall :WDFDEVICE, :PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER
proto_PFN_WDFPDOUPDATEADDRESSDESCRIPTION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER
PFN_WDFPDOUPDATEADDRESSDESCRIPTION typedef ptr proto_PFN_WDFPDOUPDATEADDRESSDESCRIPTION
WdfPdoUpdateAddressDescription proto fastcall :WDFDEVICE, :PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER
proto_PFN_WDFPDOADDEJECTIONRELATIONSPHYSICALDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PDEVICE_OBJECT
PFN_WDFPDOADDEJECTIONRELATIONSPHYSICALDEVICE typedef ptr proto_PFN_WDFPDOADDEJECTIONRELATIONSPHYSICALDEVICE
WdfPdoAddEjectionRelationsPhysicalDevice proto fastcall :WDFDEVICE, :PDEVICE_OBJECT
proto_PFN_WDFPDOREMOVEEJECTIONRELATIONSPHYSICALDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PDEVICE_OBJECT
PFN_WDFPDOREMOVEEJECTIONRELATIONSPHYSICALDEVICE typedef ptr proto_PFN_WDFPDOREMOVEEJECTIONRELATIONSPHYSICALDEVICE
WdfPdoRemoveEjectionRelationsPhysicalDevice proto fastcall :WDFDEVICE, :PDEVICE_OBJECT
proto_PFN_WDFPDOCLEAREJECTIONRELATIONSDEVICES typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFPDOCLEAREJECTIONRELATIONSDEVICES typedef ptr proto_PFN_WDFPDOCLEAREJECTIONRELATIONSDEVICES
WdfPdoClearEjectionRelationsDevices proto fastcall :WDFDEVICE


;-------------------------------------------------------------------------
; wdfcontrol.h
;-------------------------------------------------------------------------
EVT_WDF_DEVICE_SHUTDOWN_NOTIFICATION typedef proto stdcall :WDFDEVICE
PFN_WDF_DEVICE_SHUTDOWN_NOTIFICATION typedef ptr EVT_WDF_DEVICE_SHUTDOWN_NOTIFICATION
WDF_DEVICE_SHUTDOWN_FLAGS typedef SDWORD
WdfDeviceShutdown EQU 01h 
WdfDeviceLastChanceShutdown EQU 02h 

proto_PFN_WDFCONTROLDEVICEINITALLOCATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDRIVER, :ptr UNICODE_STRING
PFN_WDFCONTROLDEVICEINITALLOCATE typedef ptr proto_PFN_WDFCONTROLDEVICEINITALLOCATE
WdfControlDeviceInitAllocate proto fastcall :WDFDRIVER, :ptr UNICODE_STRING
proto_PFN_WDFCONTROLDEVICEINITSETSHUTDOWNNOTIFICATION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PWDFDEVICE_INIT, :PFN_WDF_DEVICE_SHUTDOWN_NOTIFICATION, :BYTE
PFN_WDFCONTROLDEVICEINITSETSHUTDOWNNOTIFICATION typedef ptr proto_PFN_WDFCONTROLDEVICEINITSETSHUTDOWNNOTIFICATION
WdfControlDeviceInitSetShutdownNotification proto fastcall :PWDFDEVICE_INIT, :PFN_WDF_DEVICE_SHUTDOWN_NOTIFICATION, :BYTE
proto_PFN_WDFCONTROLFINISHINITIALIZING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE
PFN_WDFCONTROLFINISHINITIALIZING typedef ptr proto_PFN_WDFCONTROLFINISHINITIALIZING
WdfControlFinishInitializing proto fastcall :WDFDEVICE


;-------------------------------------------------------------------------
; wdfwmi.h
;-------------------------------------------------------------------------
WDF_WMI_PROVIDER_CONTROL typedef SDWORD
WdfWmiControlInvalid EQU 0 
WdfWmiEventControl EQU 1
WdfWmiInstanceControl EQU 2

WDF_WMI_PROVIDER_FLAGS typedef SDWORD
WdfWmiProviderEventOnly EQU 0001h 
WdfWmiProviderExpensive EQU 0002h 
WdfWmiProviderTracing EQU 0004h 
WdfWmiProviderValidFlags EQU WdfWmiProviderEventOnly or WdfWmiProviderExpensive or WdfWmiProviderTracing 

EVT_WDF_WMI_INSTANCE_QUERY_INSTANCE typedef proto stdcall :WDFWMIINSTANCE,:DWORD,:PVOID,:PULONG
PFN_WDF_WMI_INSTANCE_QUERY_INSTANCE typedef ptr EVT_WDF_WMI_INSTANCE_QUERY_INSTANCE
EVT_WDF_WMI_INSTANCE_SET_INSTANCE typedef proto stdcall :WDFWMIINSTANCE,:DWORD,:PVOID
PFN_WDF_WMI_INSTANCE_SET_INSTANCE typedef ptr EVT_WDF_WMI_INSTANCE_SET_INSTANCE
EVT_WDF_WMI_INSTANCE_SET_ITEM typedef proto stdcall :WDFWMIINSTANCE,:DWORD,:DWORD,:PVOID
PFN_WDF_WMI_INSTANCE_SET_ITEM typedef ptr EVT_WDF_WMI_INSTANCE_SET_ITEM
EVT_WDF_WMI_INSTANCE_EXECUTE_METHOD typedef proto stdcall :WDFWMIINSTANCE,:DWORD,:DWORD,:DWORD,:PVOID,:PULONG
PFN_WDF_WMI_INSTANCE_EXECUTE_METHOD typedef ptr EVT_WDF_WMI_INSTANCE_EXECUTE_METHOD
EVT_WDF_WMI_PROVIDER_FUNCTION_CONTROL typedef proto stdcall :WDFWMIPROVIDER,:WDF_WMI_PROVIDER_CONTROL,:BOOLEAN
PFN_WDF_WMI_PROVIDER_FUNCTION_CONTROL typedef ptr EVT_WDF_WMI_PROVIDER_FUNCTION_CONTROL
WDF_WMI_PROVIDER_CONFIG struct
  Size_ DWORD ?
  Guid GUID <>
  Flags DWORD ?
  MinInstanceBufferSize DWORD ?
  EvtWmiProviderFunctionControl PFN_WDF_WMI_PROVIDER_FUNCTION_CONTROL ?
WDF_WMI_PROVIDER_CONFIG ends

PWDF_WMI_PROVIDER_CONFIG typedef ptr WDF_WMI_PROVIDER_CONFIG

WDF_WMI_PROVIDER_CONFIG_INIT proto fastcall :PWDF_WMI_PROVIDER_CONFIG, :ptr GUID
WDF_WMI_INSTANCE_CONFIG struct
  Size_ DWORD ?
  Provider WDFWMIPROVIDER ?
  ProviderConfig PWDF_WMI_PROVIDER_CONFIG ?
  UseContextForQuery BOOLEAN ?
  Register BOOLEAN ?
  EvtWmiInstanceQueryInstance PFN_WDF_WMI_INSTANCE_QUERY_INSTANCE ?
  EvtWmiInstanceSetInstance PFN_WDF_WMI_INSTANCE_SET_INSTANCE ?
  EvtWmiInstanceSetItem PFN_WDF_WMI_INSTANCE_SET_ITEM ?
  EvtWmiInstanceExecuteMethod PFN_WDF_WMI_INSTANCE_EXECUTE_METHOD ?
WDF_WMI_INSTANCE_CONFIG ends

PWDF_WMI_INSTANCE_CONFIG typedef ptr WDF_WMI_INSTANCE_CONFIG

WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER proto fastcall :PWDF_WMI_INSTANCE_CONFIG, :WDFWMIPROVIDER
WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER_CONFIG proto fastcall :PWDF_WMI_INSTANCE_CONFIG, :PWDF_WMI_PROVIDER_CONFIG
WDF_WMI_BUFFER_APPEND_STRING proto fastcall :PVOID, :DWORD, :PCUNICODE_STRING, :PULONG
proto_PFN_WDFWMIPROVIDERCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_WMI_PROVIDER_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFWMIPROVIDER
PFN_WDFWMIPROVIDERCREATE typedef ptr proto_PFN_WDFWMIPROVIDERCREATE
WdfWmiProviderCreate proto fastcall :WDFDEVICE, :PWDF_WMI_PROVIDER_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFWMIPROVIDER
proto_PFN_WDFWMIPROVIDERGETDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWMIPROVIDER
PFN_WDFWMIPROVIDERGETDEVICE typedef ptr proto_PFN_WDFWMIPROVIDERGETDEVICE
WdfWmiProviderGetDevice proto fastcall :WDFWMIPROVIDER
proto_PFN_WDFWMIPROVIDERISENABLED typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWMIPROVIDER, :WDF_WMI_PROVIDER_CONTROL
PFN_WDFWMIPROVIDERISENABLED typedef ptr proto_PFN_WDFWMIPROVIDERISENABLED
WdfWmiProviderIsEnabled proto fastcall :WDFWMIPROVIDER, :WDF_WMI_PROVIDER_CONTROL
proto_PFN_WDFWMIPROVIDERGETTRACINGHANDLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWMIPROVIDER
PFN_WDFWMIPROVIDERGETTRACINGHANDLE typedef ptr proto_PFN_WDFWMIPROVIDERGETTRACINGHANDLE
WdfWmiProviderGetTracingHandle proto fastcall :WDFWMIPROVIDER
proto_PFN_WDFWMIINSTANCECREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_WMI_INSTANCE_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFWMIINSTANCE
PFN_WDFWMIINSTANCECREATE typedef ptr proto_PFN_WDFWMIINSTANCECREATE
WdfWmiInstanceCreate proto fastcall :WDFDEVICE, :PWDF_WMI_INSTANCE_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFWMIINSTANCE
proto_PFN_WDFWMIINSTANCEREGISTER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWMIINSTANCE
PFN_WDFWMIINSTANCEREGISTER typedef ptr proto_PFN_WDFWMIINSTANCEREGISTER
WdfWmiInstanceRegister proto fastcall :WDFWMIINSTANCE
proto_PFN_WDFWMIINSTANCEDEREGISTER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWMIINSTANCE
PFN_WDFWMIINSTANCEDEREGISTER typedef ptr proto_PFN_WDFWMIINSTANCEDEREGISTER
WdfWmiInstanceDeregister proto fastcall :WDFWMIINSTANCE
proto_PFN_WDFWMIINSTANCEGETDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWMIINSTANCE
PFN_WDFWMIINSTANCEGETDEVICE typedef ptr proto_PFN_WDFWMIINSTANCEGETDEVICE
WdfWmiInstanceGetDevice proto fastcall :WDFWMIINSTANCE
proto_PFN_WDFWMIINSTANCEGETPROVIDER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWMIINSTANCE
PFN_WDFWMIINSTANCEGETPROVIDER typedef ptr proto_PFN_WDFWMIINSTANCEGETPROVIDER
WdfWmiInstanceGetProvider proto fastcall :WDFWMIINSTANCE
proto_PFN_WDFWMIINSTANCEFIREEVENT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFWMIINSTANCE, :DWORD, :PVOID
PFN_WDFWMIINSTANCEFIREEVENT typedef ptr proto_PFN_WDFWMIINSTANCEFIREEVENT
WdfWmiInstanceFireEvent proto fastcall :WDFWMIINSTANCE, :DWORD, :PVOID


;-------------------------------------------------------------------------
; wdfstring.h
;-------------------------------------------------------------------------
proto_PFN_WDFSTRINGCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :PCUNICODE_STRING, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFSTRING
PFN_WDFSTRINGCREATE typedef ptr proto_PFN_WDFSTRINGCREATE
WdfStringCreate proto fastcall :PCUNICODE_STRING, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFSTRING
proto_PFN_WDFSTRINGGETUNICODESTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFSTRING, :PUNICODE_STRING
PFN_WDFSTRINGGETUNICODESTRING typedef ptr proto_PFN_WDFSTRINGGETUNICODESTRING
WdfStringGetUnicodeString proto fastcall :WDFSTRING, :PUNICODE_STRING


;-------------------------------------------------------------------------
; wdfregistry.h
;-------------------------------------------------------------------------
proto_PFN_WDFREGISTRYOPENKEY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :ACCESS_MASK, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFKEY
PFN_WDFREGISTRYOPENKEY typedef ptr proto_PFN_WDFREGISTRYOPENKEY
WdfRegistryOpenKey proto fastcall :WDFKEY, :PCUNICODE_STRING, :ACCESS_MASK, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFKEY
proto_PFN_WDFREGISTRYCREATEKEY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :ACCESS_MASK, :DWORD, :PULONG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFKEY
PFN_WDFREGISTRYCREATEKEY typedef ptr proto_PFN_WDFREGISTRYCREATEKEY
WdfRegistryCreateKey proto fastcall :WDFKEY, :PCUNICODE_STRING, :ACCESS_MASK, :DWORD, :PULONG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFKEY
proto_PFN_WDFREGISTRYCLOSE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY
PFN_WDFREGISTRYCLOSE typedef ptr proto_PFN_WDFREGISTRYCLOSE
WdfRegistryClose proto fastcall :WDFKEY
proto_PFN_WDFREGISTRYWDMGETHANDLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY
PFN_WDFREGISTRYWDMGETHANDLE typedef ptr proto_PFN_WDFREGISTRYWDMGETHANDLE
WdfRegistryWdmGetHandle proto fastcall :WDFKEY
proto_PFN_WDFREGISTRYREMOVEKEY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY
PFN_WDFREGISTRYREMOVEKEY typedef ptr proto_PFN_WDFREGISTRYREMOVEKEY
WdfRegistryRemoveKey proto fastcall :WDFKEY
proto_PFN_WDFREGISTRYREMOVEVALUE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING
PFN_WDFREGISTRYREMOVEVALUE typedef ptr proto_PFN_WDFREGISTRYREMOVEVALUE
WdfRegistryRemoveValue proto fastcall :WDFKEY, :PCUNICODE_STRING
proto_PFN_WDFREGISTRYQUERYVALUE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :DWORD, :PVOID, :PULONG, :PULONG
PFN_WDFREGISTRYQUERYVALUE typedef ptr proto_PFN_WDFREGISTRYQUERYVALUE
WdfRegistryQueryValue proto fastcall :WDFKEY, :PCUNICODE_STRING, :DWORD, :PVOID, :PULONG, :PULONG
proto_PFN_WDFREGISTRYQUERYMEMORY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :POOL_TYPE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFMEMORY, :PULONG
PFN_WDFREGISTRYQUERYMEMORY typedef ptr proto_PFN_WDFREGISTRYQUERYMEMORY
WdfRegistryQueryMemory proto fastcall :WDFKEY, :PCUNICODE_STRING, :POOL_TYPE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFMEMORY, :PULONG
proto_PFN_WDFREGISTRYQUERYMULTISTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :PWDF_OBJECT_ATTRIBUTES, :WDFCOLLECTION
PFN_WDFREGISTRYQUERYMULTISTRING typedef ptr proto_PFN_WDFREGISTRYQUERYMULTISTRING
WdfRegistryQueryMultiString proto fastcall :WDFKEY, :PCUNICODE_STRING, :PWDF_OBJECT_ATTRIBUTES, :WDFCOLLECTION
proto_PFN_WDFREGISTRYQUERYUNICODESTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :PUSHORT, :PUNICODE_STRING
PFN_WDFREGISTRYQUERYUNICODESTRING typedef ptr proto_PFN_WDFREGISTRYQUERYUNICODESTRING
WdfRegistryQueryUnicodeString proto fastcall :WDFKEY, :PCUNICODE_STRING, :PUSHORT, :PUNICODE_STRING
proto_PFN_WDFREGISTRYQUERYSTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :WDFSTRING
PFN_WDFREGISTRYQUERYSTRING typedef ptr proto_PFN_WDFREGISTRYQUERYSTRING
WdfRegistryQueryString proto fastcall :WDFKEY, :PCUNICODE_STRING, :WDFSTRING
proto_PFN_WDFREGISTRYQUERYULONG typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :PULONG
PFN_WDFREGISTRYQUERYULONG typedef ptr proto_PFN_WDFREGISTRYQUERYULONG
WdfRegistryQueryULong proto fastcall :WDFKEY, :PCUNICODE_STRING, :PULONG
proto_PFN_WDFREGISTRYASSIGNVALUE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :DWORD, :DWORD, :PVOID
PFN_WDFREGISTRYASSIGNVALUE typedef ptr proto_PFN_WDFREGISTRYASSIGNVALUE
WdfRegistryAssignValue proto fastcall :WDFKEY, :PCUNICODE_STRING, :DWORD, :DWORD, :PVOID
proto_PFN_WDFREGISTRYASSIGNMEMORY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :DWORD, :WDFMEMORY, :PWDFMEMORY_OFFSET
PFN_WDFREGISTRYASSIGNMEMORY typedef ptr proto_PFN_WDFREGISTRYASSIGNMEMORY
WdfRegistryAssignMemory proto fastcall :WDFKEY, :PCUNICODE_STRING, :DWORD, :WDFMEMORY, :PWDFMEMORY_OFFSET
proto_PFN_WDFREGISTRYASSIGNMULTISTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :WDFCOLLECTION
PFN_WDFREGISTRYASSIGNMULTISTRING typedef ptr proto_PFN_WDFREGISTRYASSIGNMULTISTRING
WdfRegistryAssignMultiString proto fastcall :WDFKEY, :PCUNICODE_STRING, :WDFCOLLECTION
proto_PFN_WDFREGISTRYASSIGNUNICODESTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :PCUNICODE_STRING
PFN_WDFREGISTRYASSIGNUNICODESTRING typedef ptr proto_PFN_WDFREGISTRYASSIGNUNICODESTRING
WdfRegistryAssignUnicodeString proto fastcall :WDFKEY, :PCUNICODE_STRING, :PCUNICODE_STRING
proto_PFN_WDFREGISTRYASSIGNSTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :WDFSTRING
PFN_WDFREGISTRYASSIGNSTRING typedef ptr proto_PFN_WDFREGISTRYASSIGNSTRING
WdfRegistryAssignString proto fastcall :WDFKEY, :PCUNICODE_STRING, :WDFSTRING
proto_PFN_WDFREGISTRYASSIGNULONG typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFKEY, :PCUNICODE_STRING, :DWORD
PFN_WDFREGISTRYASSIGNULONG typedef ptr proto_PFN_WDFREGISTRYASSIGNULONG
WdfRegistryAssignULong proto fastcall :WDFKEY, :PCUNICODE_STRING, :DWORD


;-------------------------------------------------------------------------
; wdfdmaenabler.h
;-------------------------------------------------------------------------
WDF_DMA_PROFILE typedef SDWORD
WdfDmaProfileInvalid EQU 0 
WdfDmaProfilePacket EQU 1
WdfDmaProfileScatterGather EQU 2
WdfDmaProfilePacket64 EQU 3
WdfDmaProfileScatterGather64 EQU 4
WdfDmaProfileScatterGatherDuplex EQU 5
WdfDmaProfileScatterGather64Duplex EQU 6

WDF_DMA_DIRECTION typedef SDWORD
WdfDmaDirectionReadFromDevice EQU FALSE 
WdfDmaDirectionWriteToDevice EQU TRUE 

EVT_WDF_DMA_ENABLER_FILL typedef proto stdcall :WDFDMAENABLER
PFN_WDF_DMA_ENABLER_FILL typedef ptr EVT_WDF_DMA_ENABLER_FILL
EVT_WDF_DMA_ENABLER_FLUSH typedef proto stdcall :WDFDMAENABLER
PFN_WDF_DMA_ENABLER_FLUSH typedef ptr EVT_WDF_DMA_ENABLER_FLUSH
EVT_WDF_DMA_ENABLER_ENABLE typedef proto stdcall :WDFDMAENABLER
PFN_WDF_DMA_ENABLER_ENABLE typedef ptr EVT_WDF_DMA_ENABLER_ENABLE
EVT_WDF_DMA_ENABLER_DISABLE typedef proto stdcall :WDFDMAENABLER
PFN_WDF_DMA_ENABLER_DISABLE typedef ptr EVT_WDF_DMA_ENABLER_DISABLE
EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_START typedef proto stdcall :WDFDMAENABLER
PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_START typedef ptr EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_START
EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP typedef proto stdcall :WDFDMAENABLER
PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP typedef ptr EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP
WDF_DMA_ENABLER_UNLIMITED_FRAGMENTS equ - 1
WDF_DMA_ENABLER_CONFIG struct
    Size_ DWORD ?
    Profile WDF_DMA_PROFILE ?
    MaximumLength size_t ?
    EvtDmaEnablerFill PFN_WDF_DMA_ENABLER_FILL ?
    EvtDmaEnablerFlush PFN_WDF_DMA_ENABLER_FLUSH ?
    EvtDmaEnablerDisable PFN_WDF_DMA_ENABLER_DISABLE ?
    EvtDmaEnablerEnable PFN_WDF_DMA_ENABLER_ENABLE ?
    EvtDmaEnablerSelfManagedIoStart PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_START ?
    EvtDmaEnablerSelfManagedIoStop PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP ?
WDF_DMA_ENABLER_CONFIG ends

PWDF_DMA_ENABLER_CONFIG typedef ptr WDF_DMA_ENABLER_CONFIG

WDF_DMA_ENABLER_CONFIG_INIT proto fastcall :PWDF_DMA_ENABLER_CONFIG, :WDF_DMA_PROFILE, :size_t
proto_PFN_WDFDMAENABLERCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_DMA_ENABLER_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFDMAENABLER
PFN_WDFDMAENABLERCREATE typedef ptr proto_PFN_WDFDMAENABLERCREATE
WdfDmaEnablerCreate proto fastcall :WDFDEVICE, :PWDF_DMA_ENABLER_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFDMAENABLER
proto_PFN_WDFDMAENABLERGETMAXIMUMLENGTH typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMAENABLER
PFN_WDFDMAENABLERGETMAXIMUMLENGTH typedef ptr proto_PFN_WDFDMAENABLERGETMAXIMUMLENGTH
WdfDmaEnablerGetMaximumLength proto fastcall :WDFDMAENABLER
proto_PFN_WDFDMAENABLERGETMAXIMUMSCATTERGATHERELEMENTS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMAENABLER
PFN_WDFDMAENABLERGETMAXIMUMSCATTERGATHERELEMENTS typedef ptr proto_PFN_WDFDMAENABLERGETMAXIMUMSCATTERGATHERELEMENTS
WdfDmaEnablerGetMaximumScatterGatherElements proto fastcall :WDFDMAENABLER
proto_PFN_WDFDMAENABLERSETMAXIMUMSCATTERGATHERELEMENTS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMAENABLER, :size_t
PFN_WDFDMAENABLERSETMAXIMUMSCATTERGATHERELEMENTS typedef ptr proto_PFN_WDFDMAENABLERSETMAXIMUMSCATTERGATHERELEMENTS
WdfDmaEnablerSetMaximumScatterGatherElements proto fastcall :WDFDMAENABLER, :size_t
proto_PFN_WDFDMAENABLERGETFRAGMENTLENGTH typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMAENABLER, :WDF_DMA_DIRECTION
PFN_WDFDMAENABLERGETFRAGMENTLENGTH typedef ptr proto_PFN_WDFDMAENABLERGETFRAGMENTLENGTH
WdfDmaEnablerGetFragmentLength proto fastcall :WDFDMAENABLER, :WDF_DMA_DIRECTION
proto_PFN_WDFDMAENABLERWDMGETDMAADAPTER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMAENABLER, :WDF_DMA_DIRECTION
PFN_WDFDMAENABLERWDMGETDMAADAPTER typedef ptr proto_PFN_WDFDMAENABLERWDMGETDMAADAPTER
WdfDmaEnablerWdmGetDmaAdapter proto fastcall :WDFDMAENABLER, :WDF_DMA_DIRECTION


;-------------------------------------------------------------------------
; wdfdmatransaction.h
;-------------------------------------------------------------------------
IFNDEF SCATTER_GATHER_ELEMENT
SCATTER_GATHER_ELEMENT STRUCT
    Address PHYSICAL_ADDRESS <>
    Length_ DWORD ?
    Reserved ULONG_PTR ?
SCATTER_GATHER_ELEMENT ends
ENDIF
PSCATTER_GATHER_ELEMENT typedef ptr SCATTER_GATHER_ELEMENT

IFNDEF SCATTER_GATHER_LIST
SCATTER_GATHER_LIST STRUCT
    NumberOfElements DWORD ?
    Reserved ULONG_PTR ?
    Elements SCATTER_GATHER_ELEMENT 0 dup (<>)
SCATTER_GATHER_LIST ENDS
ENDIF
PSCATTER_GATHER_LIST typedef ptr SCATTER_GATHER_LIST

EVT_WDF_PROGRAM_DMA typedef proto stdcall :WDFDMATRANSACTION,:WDFDEVICE,:WDFCONTEXT,:WDF_DMA_DIRECTION,:PSCATTER_GATHER_LIST
PFN_WDF_PROGRAM_DMA typedef ptr EVT_WDF_PROGRAM_DMA
proto_PFN_WDFDMATRANSACTIONCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMAENABLER, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFDMATRANSACTION
PFN_WDFDMATRANSACTIONCREATE typedef ptr proto_PFN_WDFDMATRANSACTIONCREATE
WdfDmaTransactionCreate proto fastcall :WDFDMAENABLER, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFDMATRANSACTION
proto_PFN_WDFDMATRANSACTIONINITIALIZE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMATRANSACTION, :PFN_WDF_PROGRAM_DMA, :WDF_DMA_DIRECTION, :PMDL, :PVOID, :size_t
PFN_WDFDMATRANSACTIONINITIALIZE typedef ptr proto_PFN_WDFDMATRANSACTIONINITIALIZE
WdfDmaTransactionInitialize proto fastcall :WDFDMATRANSACTION, :PFN_WDF_PROGRAM_DMA, :WDF_DMA_DIRECTION, :PMDL, :PVOID, :size_t
proto_PFN_WDFDMATRANSACTIONINITIALIZEUSINGREQUEST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMATRANSACTION, :WDFREQUEST, :PFN_WDF_PROGRAM_DMA, :WDF_DMA_DIRECTION
PFN_WDFDMATRANSACTIONINITIALIZEUSINGREQUEST typedef ptr proto_PFN_WDFDMATRANSACTIONINITIALIZEUSINGREQUEST
WdfDmaTransactionInitializeUsingRequest proto fastcall :WDFDMATRANSACTION, :WDFREQUEST, :PFN_WDF_PROGRAM_DMA, :WDF_DMA_DIRECTION
proto_PFN_WDFDMATRANSACTIONEXECUTE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMATRANSACTION, :WDFCONTEXT
PFN_WDFDMATRANSACTIONEXECUTE typedef ptr proto_PFN_WDFDMATRANSACTIONEXECUTE
WdfDmaTransactionExecute proto fastcall :WDFDMATRANSACTION, :WDFCONTEXT
proto_PFN_WDFDMATRANSACTIONRELEASE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMATRANSACTION
PFN_WDFDMATRANSACTIONRELEASE typedef ptr proto_PFN_WDFDMATRANSACTIONRELEASE
WdfDmaTransactionRelease proto fastcall :WDFDMATRANSACTION
proto_PFN_WDFDMATRANSACTIONDMACOMPLETED typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMATRANSACTION, :ptr NTSTATUS
PFN_WDFDMATRANSACTIONDMACOMPLETED typedef ptr proto_PFN_WDFDMATRANSACTIONDMACOMPLETED
WdfDmaTransactionDmaCompleted proto fastcall :WDFDMATRANSACTION, :ptr NTSTATUS
proto_PFN_WDFDMATRANSACTIONDMACOMPLETEDWITHLENGTH typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMATRANSACTION, :size_t, :ptr NTSTATUS
PFN_WDFDMATRANSACTIONDMACOMPLETEDWITHLENGTH typedef ptr proto_PFN_WDFDMATRANSACTIONDMACOMPLETEDWITHLENGTH
WdfDmaTransactionDmaCompletedWithLength proto fastcall :WDFDMATRANSACTION, :size_t, :ptr NTSTATUS
proto_PFN_WDFDMATRANSACTIONDMACOMPLETEDFINAL typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMATRANSACTION, :size_t, :ptr NTSTATUS
PFN_WDFDMATRANSACTIONDMACOMPLETEDFINAL typedef ptr proto_PFN_WDFDMATRANSACTIONDMACOMPLETEDFINAL
WdfDmaTransactionDmaCompletedFinal proto fastcall :WDFDMATRANSACTION, :size_t, :ptr NTSTATUS
proto_PFN_WDFDMATRANSACTIONGETBYTESTRANSFERRED typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMATRANSACTION
PFN_WDFDMATRANSACTIONGETBYTESTRANSFERRED typedef ptr proto_PFN_WDFDMATRANSACTIONGETBYTESTRANSFERRED
WdfDmaTransactionGetBytesTransferred proto fastcall :WDFDMATRANSACTION
proto_PFN_WDFDMATRANSACTIONSETMAXIMUMLENGTH typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMATRANSACTION, :size_t
PFN_WDFDMATRANSACTIONSETMAXIMUMLENGTH typedef ptr proto_PFN_WDFDMATRANSACTIONSETMAXIMUMLENGTH
WdfDmaTransactionSetMaximumLength proto fastcall :WDFDMATRANSACTION, :size_t
proto_PFN_WDFDMATRANSACTIONGETREQUEST typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMATRANSACTION
PFN_WDFDMATRANSACTIONGETREQUEST typedef ptr proto_PFN_WDFDMATRANSACTIONGETREQUEST
WdfDmaTransactionGetRequest proto fastcall :WDFDMATRANSACTION
proto_PFN_WDFDMATRANSACTIONGETCURRENTDMATRANSFERLENGTH typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMATRANSACTION
PFN_WDFDMATRANSACTIONGETCURRENTDMATRANSFERLENGTH typedef ptr proto_PFN_WDFDMATRANSACTIONGETCURRENTDMATRANSFERLENGTH
WdfDmaTransactionGetCurrentDmaTransferLength proto fastcall :WDFDMATRANSACTION
proto_PFN_WDFDMATRANSACTIONGETDEVICE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMATRANSACTION
PFN_WDFDMATRANSACTIONGETDEVICE typedef ptr proto_PFN_WDFDMATRANSACTIONGETDEVICE
WdfDmaTransactionGetDevice proto fastcall :WDFDMATRANSACTION


;-------------------------------------------------------------------------
; wdfcommonbuffer.h
;-------------------------------------------------------------------------

WDF_COMMON_BUFFER_CONFIG struct
    Size_ DWORD ?
    AlignmentRequirement DWORD ?
WDF_COMMON_BUFFER_CONFIG ends

PWDF_COMMON_BUFFER_CONFIG typedef ptr WDF_COMMON_BUFFER_CONFIG

WDF_COMMON_BUFFER_CONFIG_INIT proto fastcall :PWDF_COMMON_BUFFER_CONFIG, :DWORD
proto_PFN_WDFCOMMONBUFFERCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMAENABLER, :size_t, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFCOMMONBUFFER
PFN_WDFCOMMONBUFFERCREATE typedef ptr proto_PFN_WDFCOMMONBUFFERCREATE
WdfCommonBufferCreate proto fastcall :WDFDMAENABLER, :size_t, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFCOMMONBUFFER
proto_PFN_WDFCOMMONBUFFERCREATEWITHCONFIG typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDMAENABLER, :size_t, :PWDF_COMMON_BUFFER_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFCOMMONBUFFER
PFN_WDFCOMMONBUFFERCREATEWITHCONFIG typedef ptr proto_PFN_WDFCOMMONBUFFERCREATEWITHCONFIG
WdfCommonBufferCreateWithConfig proto fastcall :WDFDMAENABLER, :size_t, :PWDF_COMMON_BUFFER_CONFIG, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFCOMMONBUFFER
proto_PFN_WDFCOMMONBUFFERGETALIGNEDVIRTUALADDRESS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCOMMONBUFFER
PFN_WDFCOMMONBUFFERGETALIGNEDVIRTUALADDRESS typedef ptr proto_PFN_WDFCOMMONBUFFERGETALIGNEDVIRTUALADDRESS
WdfCommonBufferGetAlignedVirtualAddress proto fastcall :WDFCOMMONBUFFER
proto_PFN_WDFCOMMONBUFFERGETALIGNEDLOGICALADDRESS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCOMMONBUFFER
PFN_WDFCOMMONBUFFERGETALIGNEDLOGICALADDRESS typedef ptr proto_PFN_WDFCOMMONBUFFERGETALIGNEDLOGICALADDRESS
WdfCommonBufferGetAlignedLogicalAddress proto fastcall :WDFCOMMONBUFFER
proto_PFN_WDFCOMMONBUFFERGETLENGTH typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFCOMMONBUFFER
PFN_WDFCOMMONBUFFERGETLENGTH typedef ptr proto_PFN_WDFCOMMONBUFFERGETLENGTH
WdfCommonBufferGetLength proto fastcall :WDFCOMMONBUFFER


;-------------------------------------------------------------------------
; Bugcodes - wdfbugcodes.h
;-------------------------------------------------------------------------
WDF_BUGCHECK_CODES typedef SDWORD
WDF_POWER_ROUTINE_TIMED_OUT EQU 1h 
WDF_RECURSIVE_LOCK EQU 2h 
WDF_VERIFIER_FATAL_ERROR EQU 3h 
WDF_REQUIRED_PARAMETER_IS_NULL EQU 4h 
WDF_INVALID_HANDLE EQU 5h 
WDF_REQUEST_FATAL_ERROR EQU 6h 
WDF_OBJECT_ERROR EQU 7h 
WDF_DMA_FATAL_ERROR EQU 8h 
WDF_INVALID_INTERRUPT EQU 9h 
WDF_QUEUE_FATAL_ERROR EQU 0Ah 
WDF_INVALID_LOCK_OPERATION EQU 0Bh 
WDF_PNP_FATAL_ERROR EQU 0Ch 
WDF_POWER_MULTIPLE_PPO EQU 0Dh 
WDF_VERIFIER_IRQL_MISMATCH EQU 0Eh 
WDF_VERIFIER_CRITICAL_REGION_MISMATCH EQU 0Fh 

WDF_REQUEST_FATAL_ERROR_CODES typedef SDWORD
WDF_REQUEST_FATAL_ERROR_NO_MORE_STACK_LOCATIONS EQU 1h 
WDF_REQUEST_FATAL_ERROR_NULL_IRP EQU 2h 
WDF_REQUEST_FATAL_ERROR_REQUEST_ALREADY_SENT EQU 3h 
WDF_REQUEST_FATAL_ERROR_INFORMATION_LENGTH_MISMATCH EQU 4h 

WDF_POWER_ROUTINE_TIMED_OUT_DATA struct
    PowerState WDF_DEVICE_POWER_STATE ?
    PowerPolicyState WDF_DEVICE_POWER_POLICY_STATE ?
    DeviceObject PDEVICE_OBJECT ?
    Device WDFDEVICE ?
    TimedOutThread PKTHREAD ?
WDF_POWER_ROUTINE_TIMED_OUT_DATA ends

WDF_REQUEST_FATAL_ERROR_INFORMATION_LENGTH_MISMATCH_DATA struct
    Request WDFREQUEST ?
    Irp_ PIRP ?
    OutputBufferLength DWORD ?
    Information ULONG_PTR ?
    MajorFunction BYTE ?
WDF_REQUEST_FATAL_ERROR_INFORMATION_LENGTH_MISMATCH_DATA ends

PWDF_REQUEST_FATAL_ERROR_INFORMATION_LENGTH_MISMATCH_DATA typedef ptr WDF_REQUEST_FATAL_ERROR_INFORMATION_LENGTH_MISMATCH_DATA

WDF_QUEUE_FATAL_ERROR_DATA struct
    Queue WDFQUEUE ?
    Request WDFREQUEST ?
    Status NTSTATUS ?
WDF_QUEUE_FATAL_ERROR_DATA ends

PWDF_QUEUE_FATAL_ERROR_DATA typedef ptr WDF_QUEUE_FATAL_ERROR_DATA


;-------------------------------------------------------------------------
; wdfroletypes.h
;-------------------------------------------------------------------------
EVT_WDF_DEVICE_CONTEXT_CLEANUP typedef EVT_WDF_OBJECT_CONTEXT_CLEANUP
EVT_WDF_DEVICE_CONTEXT_DESTROY typedef EVT_WDF_OBJECT_CONTEXT_DESTROY
EVT_WDF_IO_QUEUE_CONTEXT_CLEANUP_CALLBACK typedef EVT_WDF_OBJECT_CONTEXT_CLEANUP
EVT_WDF_IO_QUEUE_CONTEXT_DESTROY_CALLBACK typedef EVT_WDF_OBJECT_CONTEXT_DESTROY
EVT_WDF_FILE_CONTEXT_CLEANUP_CALLBACK typedef EVT_WDF_OBJECT_CONTEXT_CLEANUP
EVT_WDF_FILE_CONTEXT_DESTROY_CALLBACK typedef EVT_WDF_OBJECT_CONTEXT_DESTROY


;-------------------------------------------------------------------------
; wdfinstaller.h
;-------------------------------------------------------------------------
WDF_COINSTALLER_INSTALL_OPTIONS struct
    Size_ DWORD ?
    ShowRebootPrompt BOOL ?
WDF_COINSTALLER_INSTALL_OPTIONS ends

PWDF_COINSTALLER_INSTALL_OPTIONS typedef ptr WDF_COINSTALLER_INSTALL_OPTIONS

WDF_COINSTALLER_INSTALL_OPTIONS_INIT proto fastcall :PWDF_COINSTALLER_INSTALL_OPTIONS
WdfPreDeviceInstall proto stdcall :LPWSTR, :LPWSTR
proto_PFN_WDFPREDEVICEINSTALL typedef proto stdcall :LPWSTR, :LPWSTR
PFN_WDFPREDEVICEINSTALL typedef ptr proto_PFN_WDFPREDEVICEINSTALL
WdfPreDeviceInstallEx proto stdcall :LPWSTR, :LPWSTR, :PWDF_COINSTALLER_INSTALL_OPTIONS
proto_PFN_WDFPREDEVICEINSTALLEX typedef proto stdcall :LPWSTR, :LPWSTR, :PWDF_COINSTALLER_INSTALL_OPTIONS
PFN_WDFPREDEVICEINSTALLEX typedef ptr proto_PFN_WDFPREDEVICEINSTALLEX
WdfPostDeviceInstall proto stdcall :LPWSTR, :LPWSTR
proto_PFN_WDFPOSTDEVICEINSTALL typedef proto stdcall :LPWSTR, :LPWSTR
PFN_WDFPOSTDEVICEINSTALL typedef ptr proto_PFN_WDFPOSTDEVICEINSTALL
WdfPreDeviceRemove proto stdcall :LPWSTR, :LPWSTR
proto_PFN_WDFPREDEVICEREMOVE typedef proto stdcall :LPWSTR, :LPWSTR
PFN_WDFPREDEVICEREMOVE typedef ptr proto_PFN_WDFPREDEVICEREMOVE
WdfPostDeviceRemove proto stdcall :LPWSTR, :LPWSTR
proto_PFN_WDFPOSTDEVICEREMOVE typedef proto stdcall :LPWSTR, :LPWSTR
PFN_WDFPOSTDEVICEREMOVE typedef ptr proto_PFN_WDFPOSTDEVICEREMOVE


;-------------------------------------------------------------------------
; wdfminiport.h
;-------------------------------------------------------------------------
proto_PFN_WDFDEVICEMINIPORTCREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDRIVER, :PWDF_OBJECT_ATTRIBUTES, :PDEVICE_OBJECT, :PDEVICE_OBJECT, :PDEVICE_OBJECT, :ptr WDFDEVICE
PFN_WDFDEVICEMINIPORTCREATE typedef ptr proto_PFN_WDFDEVICEMINIPORTCREATE
WdfDeviceMiniportCreate proto fastcall :WDFDRIVER, :PWDF_OBJECT_ATTRIBUTES, :PDEVICE_OBJECT, :PDEVICE_OBJECT, :PDEVICE_OBJECT, :ptr WDFDEVICE
proto_PFN_WDFDRIVERMINIPORTUNLOAD typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDRIVER
PFN_WDFDRIVERMINIPORTUNLOAD typedef ptr proto_PFN_WDFDRIVERMINIPORTUNLOAD
WdfDriverMiniportUnload proto fastcall :WDFDRIVER


;-------------------------------------------------------------------------
; wdfusb.h
;-------------------------------------------------------------------------
ifndef BMREQUEST_HOST_TO_DEVICE
  BMREQUEST_HOST_TO_DEVICE equ 0
endif
ifndef BMREQUEST_DEVICE_TO_HOST
  BMREQUEST_DEVICE_TO_HOST equ 1
endif
ifndef BMREQUEST_STANDARD
  BMREQUEST_STANDARD equ 0
endif
ifndef BMREQUEST_CLASS
  BMREQUEST_CLASS equ 1
endif
ifndef BMREQUEST_VENDOR
  BMREQUEST_VENDOR equ 2
endif
ifndef BMREQUEST_TO_DEVICE
  BMREQUEST_TO_DEVICE equ 0
endif
ifndef BMREQUEST_TO_INTERFACE
  BMREQUEST_TO_INTERFACE equ 1
endif
ifndef BMREQUEST_TO_ENDPOINT
  BMREQUEST_TO_ENDPOINT equ 2
endif
ifndef BMREQUEST_TO_OTHER
  BMREQUEST_TO_OTHER equ 3
endif
WDF_USB_REQUEST_TYPE typedef SDWORD
WdfUsbRequestTypeInvalid EQU 0 
WdfUsbRequestTypeNoFormat EQU 1
WdfUsbRequestTypeDeviceString EQU 2
WdfUsbRequestTypeDeviceControlTransfer EQU 3
WdfUsbRequestTypeDeviceUrb EQU 4
WdfUsbRequestTypePipeWrite EQU 5
WdfUsbRequestTypePipeRead EQU 6
WdfUsbRequestTypePipeAbort EQU 7
WdfUsbRequestTypePipeReset EQU 8
WdfUsbRequestTypePipeUrb EQU 9

PWDF_USB_REQUEST_TYPE typedef ptr WDF_USB_REQUEST_TYPE

WDF_USB_BMREQUEST_DIRECTION typedef SDWORD
BmRequestHostToDevice EQU BMREQUEST_HOST_TO_DEVICE 
BmRequestDeviceToHost EQU BMREQUEST_DEVICE_TO_HOST 

WDF_USB_BMREQUEST_TYPE typedef SDWORD
BmRequestStandard EQU BMREQUEST_STANDARD 
BmRequestClass EQU BMREQUEST_CLASS 
BmRequestVendor EQU BMREQUEST_VENDOR 

WDF_USB_BMREQUEST_RECIPIENT typedef SDWORD
BmRequestToDevice EQU BMREQUEST_TO_DEVICE 
BmRequestToInterface EQU BMREQUEST_TO_INTERFACE 
BmRequestToEndpoint EQU BMREQUEST_TO_ENDPOINT 
BmRequestToOther EQU BMREQUEST_TO_OTHER 

WDF_USB_PIPE_TYPE typedef SDWORD
WdfUsbPipeTypeInvalid EQU 0 
WdfUsbPipeTypeControl EQU 1
WdfUsbPipeTypeIsochronous EQU 2
WdfUsbPipeTypeBulk EQU 3
WdfUsbPipeTypeInterrupt EQU 4

WdfUsbTargetDeviceSelectConfigType typedef SDWORD
WdfUsbTargetDeviceSelectConfigTypeInvalid EQU 0 
WdfUsbTargetDeviceSelectConfigTypeDeconfig EQU 1 
WdfUsbTargetDeviceSelectConfigTypeSingleInterface EQU 2 
WdfUsbTargetDeviceSelectConfigTypeMultiInterface EQU 3 
WdfUsbTargetDeviceSelectConfigTypeInterfacesPairs EQU 4 
WdfUsbTargetDeviceSelectConfigTypeInterfacesDescriptor EQU 5 
WdfUsbTargetDeviceSelectConfigTypeUrb EQU 6 

WdfUsbTargetDeviceSelectSettingType typedef SDWORD
WdfUsbInterfaceSelectSettingTypeDescriptor EQU 10h 
WdfUsbInterfaceSelectSettingTypeSetting EQU 11h 
WdfUsbInterfaceSelectSettingTypeUrb EQU 12h 

WDF_USB_DEVICE_TRAITS typedef SDWORD
WDF_USB_DEVICE_TRAIT_SELF_POWERED EQU 00000001h 
WDF_USB_DEVICE_TRAIT_REMOTE_WAKE_CAPABLE EQU 00000002h 
WDF_USB_DEVICE_TRAIT_AT_HIGH_SPEED EQU 00000004h 

WDF_USB_CONTROL_SETUP_PACKET union
  struct Packet
    union bm
      struct Request
        Request_??0 record Recipient_??0:2, Reservedreq_??0:3, Type_??0:2, Dir_??0:1
        Request_??0 <>
      ends
      Byte_ BYTE ?
    ends
    bRequest BYTE ?
    union wValue
      struct Bytes
        LowByte BYTE ?
        HiByte BYTE ?
      ends
      Value WORD ?
    ends
    union wIndex
      struct Bytes
        LowByte BYTE ?
        HiByte BYTE ?
      ends
      Value WORD ?
    ends
    wLength WORD ?
  ends
  struct Generic
    Bytes BYTE 8 dup (?)
  ends
WDF_USB_CONTROL_SETUP_PACKET ends

PWDF_USB_CONTROL_SETUP_PACKET typedef ptr WDF_USB_CONTROL_SETUP_PACKET

WDF_USB_CONTROL_SETUP_PACKET_INIT proto fastcall :PWDF_USB_CONTROL_SETUP_PACKET, :WDF_USB_BMREQUEST_DIRECTION, :WDF_USB_BMREQUEST_RECIPIENT, :BYTE, :WORD, :WORD
WDF_USB_CONTROL_SETUP_PACKET_INIT_CLASS proto fastcall :PWDF_USB_CONTROL_SETUP_PACKET, :WDF_USB_BMREQUEST_DIRECTION, :WDF_USB_BMREQUEST_RECIPIENT, :BYTE, :WORD, :WORD
WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR proto fastcall :PWDF_USB_CONTROL_SETUP_PACKET, :WDF_USB_BMREQUEST_DIRECTION, :WDF_USB_BMREQUEST_RECIPIENT, :BYTE, :WORD, :WORD
WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE proto fastcall :PWDF_USB_CONTROL_SETUP_PACKET, :WDF_USB_BMREQUEST_RECIPIENT, :WORD, :WORD, :BOOLEAN
WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS proto fastcall :PWDF_USB_CONTROL_SETUP_PACKET, :WDF_USB_BMREQUEST_RECIPIENT, :WORD
WDF_USB_REQUEST_COMPLETION_PARAMS struct
  UsbdStatus USBD_STATUS ?
  Type_ WDF_USB_REQUEST_TYPE ?
  union Parameters
    struct DeviceString
      Buffer WDFMEMORY ?
      LangID WORD ?
      StringIndex BYTE ?
      RequiredSize BYTE ?
    ends
    struct DeviceControlTransfer
      Buffer WDFMEMORY ?
      SetupPacket WDF_USB_CONTROL_SETUP_PACKET <>
      Length_ DWORD ?
    ends
    struct DeviceUrb
      Buffer WDFMEMORY ?
    ends
    struct PipeWrite
      Buffer WDFMEMORY ?
      Length_ size_t ?
      Offset_ size_t ?
    ends
    struct PipeRead
      Buffer WDFMEMORY ?
      Length_ size_t ?
      Offset_ size_t ?
    ends
    struct PipeUrb
      Buffer WDFMEMORY ?
    ends
  ends
WDF_USB_REQUEST_COMPLETION_PARAMS ends

PWDF_USB_REQUEST_COMPLETION_PARAMS typedef ptr WDF_USB_REQUEST_COMPLETION_PARAMS

EVT_WDF_USB_READER_COMPLETION_ROUTINE typedef proto stdcall :WDFUSBPIPE,:WDFMEMORY,:size_t,:WDFCONTEXT
PFN_WDF_USB_READER_COMPLETION_ROUTINE typedef ptr EVT_WDF_USB_READER_COMPLETION_ROUTINE
EVT_WDF_USB_READERS_FAILED typedef proto stdcall :WDFUSBPIPE,:NTSTATUS,:USBD_STATUS
PFN_WDF_USB_READERS_FAILED typedef ptr EVT_WDF_USB_READERS_FAILED
WDF_USB_CONTINUOUS_READER_CONFIG struct
  Size_ DWORD ?
  TransferLength size_t ?
  HeaderLength size_t ?
  TrailerLength size_t ?
  NumPendingReads BYTE ?
  BufferAttributes PWDF_OBJECT_ATTRIBUTES ?
  EvtUsbTargetPipeReadComplete PFN_WDF_USB_READER_COMPLETION_ROUTINE ?
  EvtUsbTargetPipeReadCompleteContext WDFCONTEXT ?
  EvtUsbTargetPipeReadersFailed PFN_WDF_USB_READERS_FAILED ?
WDF_USB_CONTINUOUS_READER_CONFIG ends

PWDF_USB_CONTINUOUS_READER_CONFIG typedef ptr WDF_USB_CONTINUOUS_READER_CONFIG

WDF_USB_CONTINUOUS_READER_CONFIG_INIT proto fastcall :PWDF_USB_CONTINUOUS_READER_CONFIG, :PFN_WDF_USB_READER_COMPLETION_ROUTINE, :WDFCONTEXT, :size_t
WdfUsbTargetDeviceGetIoTarget proto fastcall :WDFUSBDEVICE

USBD_VERSION_INFORMATION STRUCT
    USBDI_Version ULONG ?
    Supported_USB_Version ULONG ?
USBD_VERSION_INFORMATION ENDS
PUSBD_VERSION_INFORMATION TYPEDEF PTR USBD_VERSION_INFORMATION

WDF_USB_DEVICE_INFORMATION struct
  Size_ DWORD ?
  UsbdVersionInformation USBD_VERSION_INFORMATION <>
  HcdPortCapabilities DWORD ?
  Traits DWORD ?
WDF_USB_DEVICE_INFORMATION ends

PWDF_USB_DEVICE_INFORMATION typedef ptr WDF_USB_DEVICE_INFORMATION

WDF_USB_DEVICE_INFORMATION_INIT proto fastcall :PWDF_USB_DEVICE_INFORMATION
WDF_USB_INTERFACE_SETTING_PAIR struct
  UsbInterface WDFUSBINTERFACE ?
  SettingIndex BYTE ?
WDF_USB_INTERFACE_SETTING_PAIR ends

PWDF_USB_INTERFACE_SETTING_PAIR typedef ptr WDF_USB_INTERFACE_SETTING_PAIR

USB_INTERFACE_DESCRIPTOR STRUCT
    bLength UCHAR ?
    bDescriptorType UCHAR ?
    bInterfaceNumber UCHAR ?
    bAlternateSetting UCHAR ?
    bNumEndpoints UCHAR ?
    bInterfaceClass UCHAR ?
    bInterfaceSubClass UCHAR ?
    bInterfaceProtocol UCHAR ?
    iInterface UCHAR ?
USB_INTERFACE_DESCRIPTOR ENDS
PUSB_INTERFACE_DESCRIPTOR TYPEDEF PTR USB_INTERFACE_DESCRIPTOR

USB_CONFIGURATION_DESCRIPTOR STRUCT
    bLength UCHAR ?
    bDescriptorType UCHAR ?
    wTotalLength USHORT ?
    bNumInterfaces UCHAR ?
    bConfigurationValue UCHAR ?
    iConfiguration UCHAR ?
    bmAttributes UCHAR ?
    MaxPower UCHAR ?
USB_CONFIGURATION_DESCRIPTOR ENDS
PUSB_CONFIGURATION_DESCRIPTOR TYPEDEF PTR USB_CONFIGURATION_DESCRIPTOR

URB_HEADER STRUCT
    Length_ USHORT ?
    Function USHORT ?
    Status USBD_STATUS ?
    UsbdDeviceHandle PVOID ?
    UsbdFlags ULONG ?
URB_HEADER ENDS


USBD_PIPE_HANDLE typedef PVOID
USBD_PIPE_TYPE typedef DWORD
USBD_CONFIGURATION_HANDLE typedef PVOID
USBD_INTERFACE_HANDLE typedef PVOID

URB_PIPE_REQUEST STRUCT
    Hdr URB_HEADER <>
    PipeHandle USBD_PIPE_HANDLE ?
    Reserved ULONG ?
URB_PIPE_REQUEST ENDS

URB_GET_CURRENT_FRAME_NUMBER STRUCT
    Hdr URB_HEADER <>
    FrameNumber ULONG ?
URB_GET_CURRENT_FRAME_NUMBER ENDS

URB_HCD_AREA STRUCT
    Reserved8 PVOID 8 DUP (?)
URB_HCD_AREA ENDS

URB_CONTROL_TRANSFER STRUCT
    Hdr URB_HEADER <>
    PipeHandle USBD_PIPE_HANDLE ?
    TransferFlags ULONG ?
    TransferBufferLength ULONG ?
    TransferBuffer PVOID ?
    TransferBufferMDL PMDL ?
    UrbLink POINTER ?
    hca URB_HCD_AREA <>
    SetupPacket UCHAR 8 DUP (?)
URB_CONTROL_TRANSFER ENDS

URB_CONTROL_FEATURE_REQUEST STRUCT
    Hdr URB_HEADER <>
    Reserved PVOID ?
    Reserved2 ULONG ?
    Reserved3 ULONG ?
    Reserved4 PVOID ?
    Reserved5 PMDL ?
    UrbLink POINTER ?
    hca URB_HCD_AREA <>
    Reserved0 USHORT ?
    FeatureSelector USHORT ?
    Index USHORT ?
    Reserved1 USHORT ?
URB_CONTROL_FEATURE_REQUEST ENDS

URB_CONTROL_GET_STATUS_REQUEST STRUCT
    Hdr URB_HEADER <>
    Reserved PVOID ?
    Reserved0 ULONG ?
    TransferBufferLength ULONG ?
    TransferBuffer PVOID ?
    TransferBufferMDL PMDL ?
    UrbLink POINTER ?
    hca URB_HCD_AREA <>
    Reserved1 UCHAR 4 DUP (?)
    Index USHORT ?
    Reserved2 USHORT ?
URB_CONTROL_GET_STATUS_REQUEST ENDS


URB_CONTROL_DESCRIPTOR_REQUEST STRUCT
    Hdr URB_HEADER <>
    Reserved PVOID ?
    Reserved0 ULONG ?
    TransferBufferLength ULONG ?
    TransferBuffer PVOID ?
    TransferBufferMDL PMDL ?
    UrbLink POINTER ?
    hca URB_HCD_AREA <>
    Reserved1 USHORT ?
    Index UCHAR ?
    DescriptorType UCHAR ?
    LanguageId USHORT ?
    Reserved2 USHORT ?
URB_CONTROL_DESCRIPTOR_REQUEST ENDS

URB_CONTROL_TRANSFER_EX STRUCT
    Hdr URB_HEADER <>
    PipeHandle USBD_PIPE_HANDLE ?
    TransferFlags ULONG ?
    TransferBufferLength ULONG ?
    TransferBuffer PVOID ?
    TransferBufferMDL PMDL ?
    Timeout ULONG ?
    Pad ULONG ?
    hca URB_HCD_AREA <>
    SetupPacket UCHAR 8 DUP (?)
URB_CONTROL_TRANSFER_EX ENDS


URB_CONTROL_VENDOR_OR_CLASS_REQUEST STRUCT
    Hdr URB_HEADER <>
    Reserved PVOID ?
    TransferFlags ULONG ?
    TransferBufferLength ULONG ?
    TransferBuffer PVOID ?
    TransferBufferMDL PMDL ?
    UrbLink POINTER ?
    hca URB_HCD_AREA <>
    RequestTypeReservedBits UCHAR ?
    Request UCHAR ?
    Value_ USHORT ?
    Index USHORT ?
    Reserved1 USHORT ?
URB_CONTROL_VENDOR_OR_CLASS_REQUEST ENDS

URB_CONTROL_GET_INTERFACE_REQUEST STRUCT
    Hdr URB_HEADER <>
    Reserved PVOID ?
    Reserved0 ULONG ?
    TransferBufferLength ULONG ?
    TransferBuffer PVOID ?
    TransferBufferMDL PMDL ?
    UrbLink POINTER ?
    hca URB_HCD_AREA <>
    Reserved1 UCHAR 4 DUP (?)
    Interface USHORT ?
    Reserved2 USHORT ?
URB_CONTROL_GET_INTERFACE_REQUEST ENDS

URB_CONTROL_GET_CONFIGURATION_REQUEST STRUCT
    Hdr URB_HEADER <>
    Reserved PVOID ?
    Reserved0 ULONG ?
    TransferBufferLength ULONG ?
    TransferBuffer PVOID ?
    TransferBufferMDL PMDL ?
    UrbLink POINTER ?
    hca URB_HCD_AREA <>
    Reserved1 UCHAR 8 DUP (?)
URB_CONTROL_GET_CONFIGURATION_REQUEST ENDS

URB_OS_FEATURE_DESCRIPTOR_REQUEST STRUCT
    Hdr URB_HEADER <>
    Reserved PVOID ?
    Reserved0 ULONG ?
    TransferBufferLength ULONG ?
    TransferBuffer PVOID ?
    TransferBufferMDL PMDL ?
    UrbLink POINTER ?
    hca URB_HCD_AREA <>
    Recipient UCHAR ?
    InterfaceNumber UCHAR ?
    MS_PageIndex UCHAR ?
    MS_FeatureDescriptorIndex USHORT ?
    Reserved3 USHORT ?
URB_OS_FEATURE_DESCRIPTOR_REQUEST ENDS

USBD_STREAM_INFORMATION STRUCT
    PipeHandle USBD_PIPE_HANDLE ?
    StreamID ULONG ?
    MaximumTransferSize ULONG ?
    PipeFlags ULONG ?
USBD_STREAM_INFORMATION ENDS
PUSBD_STREAM_INFORMATION TYPEDEF PTR USBD_STREAM_INFORMATION

URB_OPEN_STATIC_STREAMS STRUCT
    Hdr URB_HEADER <>
    PipeHandle USBD_PIPE_HANDLE ?
    NumberOfStreams ULONG ?
    StreamInfoVersion USHORT ?
    StreamInfoSize USHORT ?
    Streams PUSBD_STREAM_INFORMATION ?
URB_OPEN_STATIC_STREAMS ENDS


URB_BULK_OR_INTERRUPT_TRANSFER STRUCT
    Hdr URB_HEADER <>
    PipeHandle USBD_PIPE_HANDLE ?
    TransferFlags ULONG ?
    TransferBufferLength ULONG ?
    TransferBuffer PVOID ?
    TransferBufferMDL PMDL ?
    UrbLink POINTER ?
    hca URB_HCD_AREA <>
URB_BULK_OR_INTERRUPT_TRANSFER ENDS


URB_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS STRUCT
    Hdr URB_HEADER <>
    PipeHandle USBD_PIPE_HANDLE ?
    MaximumSendPathDelayInMilliSeconds ULONG ?
    MaximumCompletionPathDelayInMilliSeconds ULONG ?
URB_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS ENDS

USBD_ISO_PACKET_DESCRIPTOR STRUCT
    Offset_ ULONG ?
    Length_ ULONG ?
    Status USBD_STATUS ?
USBD_ISO_PACKET_DESCRIPTOR ENDS
PUSBD_ISO_PACKET_DESCRIPTOR TYPEDEF PTR USBD_ISO_PACKET_DESCRIPTOR

URB_ISOCH_TRANSFER STRUCT
    Hdr URB_HEADER <>
    PipeHandle USBD_PIPE_HANDLE ?
    TransferFlags ULONG ?
    TransferBufferLength ULONG ?
    TransferBuffer PVOID ?
    TransferBufferMDL PMDL ?
    UrbLink POINTER ?
    hca URB_HCD_AREA <>
    StartFrame ULONG ?
    NumberOfPackets ULONG ?
    ErrorCount ULONG ?
    IsoPacket USBD_ISO_PACKET_DESCRIPTOR 1 DUP (<>)
URB_ISOCH_TRANSFER ENDS

USBD_PIPE_INFORMATION STRUCT
  MaximumPacketSize USHORT ?
  EndpointAddress UCHAR ?
  Interval UCHAR ?
  PipeType USBD_PIPE_TYPE ?
  PipeHandle USBD_PIPE_HANDLE ?
  MaximumTransferSize ULONG ?
  PipeFlags ULONG ?
USBD_PIPE_INFORMATION ENDS
PUSBD_PIPE_INFORMATION TYPEDEF PTR USBD_PIPE_INFORMATION

USBD_INTERFACE_INFORMATION STRUCT
    Length_ USHORT ?
    InterfaceNumber UCHAR ?
    AlternateSetting UCHAR ?
    Class_ UCHAR ?
    SubClass UCHAR ?
    Protocol UCHAR ?
    Reserved UCHAR ?
    InterfaceHandle USBD_INTERFACE_HANDLE ?
    NumberOfPipes ULONG ?
    Pipes USBD_PIPE_INFORMATION 1 DUP (<>)
USBD_INTERFACE_INFORMATION ENDS 
PUSBD_INTERFACE_INFORMATION TYPEDEF PTR USBD_INTERFACE_INFORMATION

URB_FRAME_LENGTH_CONTROL STRUCT
    Hdr URB_HEADER <>
URB_FRAME_LENGTH_CONTROL ENDS

URB_GET_FRAME_LENGTH STRUCT
    Hdr URB_HEADER <>
    FrameLength ULONG ?
    FrameNumber ULONG ?
URB_GET_FRAME_LENGTH ENDS

URB_SET_FRAME_LENGTH STRUCT
    Hdr URB_HEADER <>
    FrameLengthDelta LONG ?
URB_SET_FRAME_LENGTH ENDS

URB_SELECT_CONFIGURATION STRUCT
    Hdr URB_HEADER <>
    ConfigurationDescriptor PUSB_CONFIGURATION_DESCRIPTOR ?
    ConfigurationHandle USBD_CONFIGURATION_HANDLE ?
    Interface USBD_INTERFACE_INFORMATION <>
URB_SELECT_CONFIGURATION ENDS

URB_SELECT_INTERFACE STRUCT
    Hdr URB_HEADER <>
    ConfigurationHandle USBD_CONFIGURATION_HANDLE ?
    Interface USBD_INTERFACE_INFORMATION <>
URB_SELECT_INTERFACE ENDS

URB STRUCT
    UNION
    UrbHeader URB_HEADER <>
    UrbSelectInterface URB_SELECT_INTERFACE <>
    UrbSelectConfiguration URB_SELECT_CONFIGURATION <>
    UrbPipeRequest URB_PIPE_REQUEST <>
    UrbFrameLengthControl URB_FRAME_LENGTH_CONTROL <>
    UrbGetFrameLength URB_GET_FRAME_LENGTH <>
    UrbSetFrameLength URB_SET_FRAME_LENGTH <>
    UrbGetCurrentFrameNumber URB_GET_CURRENT_FRAME_NUMBER <>
    UrbControlTransfer URB_CONTROL_TRANSFER <>
    UrbControlTransferEx URB_CONTROL_TRANSFER_EX <>
    UrbBulkOrInterruptTransfer URB_BULK_OR_INTERRUPT_TRANSFER <>
    UrbIsochronousTransfer URB_ISOCH_TRANSFER <>
    UrbControlDescriptorRequest URB_CONTROL_DESCRIPTOR_REQUEST <>
    UrbControlGetStatusRequest URB_CONTROL_GET_STATUS_REQUEST <>
    UrbControlFeatureRequest URB_CONTROL_FEATURE_REQUEST <>
    UrbControlVendorClassRequest URB_CONTROL_VENDOR_OR_CLASS_REQUEST <>
    UrbControlGetInterfaceRequest URB_CONTROL_GET_INTERFACE_REQUEST <>
    UrbControlGetConfigurationRequest URB_CONTROL_GET_CONFIGURATION_REQUEST <>
    UrbOSFeatureDescriptorRequest URB_OS_FEATURE_DESCRIPTOR_REQUEST <>
    UrbOpenStaticStreams URB_OPEN_STATIC_STREAMS <>
    UrbGetIsochPipeTransferPathDelays URB_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS <>
    ENDS
URB ENDS

PURB TYPEDEF PTR URB

USB_DEVICE_DESCRIPTOR STRUCT
  bLength UCHAR ?
  bDescriptorType UCHAR ?
  bcdUSB USHORT ?
  bDeviceClass UCHAR ?
  bDeviceSubClass UCHAR ?
  bDeviceProtocol UCHAR ?
  bMaxPacketSize0 UCHAR ?
  idVendor USHORT ?
  idProduct USHORT ?
  bcdDevice USHORT ?
  iManufacturer UCHAR ?
  iProduct UCHAR ?
  iSerialNumber UCHAR ?
  bNumConfigurations UCHAR ?
USB_DEVICE_DESCRIPTOR ENDS
PUSB_DEVICE_DESCRIPTOR TYPEDEF PTR USB_DEVICE_DESCRIPTOR

WDF_USB_DEVICE_SELECT_CONFIG_PARAMS struct
  Size_ DWORD ?
  Type_ WdfUsbTargetDeviceSelectConfigType ?
  union Types
    struct Descriptor
      ConfigurationDescriptor PUSB_CONFIGURATION_DESCRIPTOR ?
      InterfaceDescriptors POINTER ?
      NumInterfaceDescriptors DWORD ?
    ends
    struct Urb
      Urb PURB ?
    ends
    struct SingleInterface
      NumberConfiguredPipes BYTE ?
      ConfiguredUsbInterface WDFUSBINTERFACE ?
    ends
    struct MultiInterface
      NumberInterfaces BYTE ?
      Pairs PWDF_USB_INTERFACE_SETTING_PAIR ?
      NumberOfConfiguredInterfaces BYTE ?
    ends
  ends
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS ends

PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS typedef ptr WDF_USB_DEVICE_SELECT_CONFIG_PARAMS

WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE proto fastcall :PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES proto fastcall :PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS, :BYTE, :PWDF_USB_INTERFACE_SETTING_PAIR
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_INTERFACES_DESCRIPTORS proto fastcall :PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS, :PUSB_CONFIGURATION_DESCRIPTOR, :ptr PUSB_INTERFACE_DESCRIPTOR, :DWORD
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_URB proto fastcall :PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS, :PURB
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_DECONFIG proto fastcall :PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS
WDF_USB_INTERFACE_SELECT_SETTING_PARAMS struct
  Size_ DWORD ?
  Type_ WdfUsbTargetDeviceSelectSettingType ?
  union Types
    struct Descriptor
      InterfaceDescriptor PUSB_INTERFACE_DESCRIPTOR ?
    ends
    struct Interface
      SettingIndex BYTE ?
    ends
    struct Urb
      Urb PURB ?
    ends
  ends
WDF_USB_INTERFACE_SELECT_SETTING_PARAMS ends

PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS typedef ptr WDF_USB_INTERFACE_SELECT_SETTING_PARAMS

WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_DESCRIPTOR proto fastcall :PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS, :PUSB_INTERFACE_DESCRIPTOR
WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_URB proto fastcall :PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS, :PURB
WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING proto fastcall :PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS, :BYTE
WdfUsbTargetPipeGetIoTarget proto fastcall :WDFUSBPIPE
WDF_USB_PIPE_INFORMATION struct
  Size_ DWORD ?
  MaximumPacketSize DWORD ?
  EndpointAddress BYTE ?
  Interval BYTE ?
  SettingIndex BYTE ?
  PipeType WDF_USB_PIPE_TYPE ?
  MaximumTransferSize DWORD ?
WDF_USB_PIPE_INFORMATION ends

PWDF_USB_PIPE_INFORMATION typedef ptr WDF_USB_PIPE_INFORMATION

WDF_USB_PIPE_INFORMATION_INIT proto fastcall :PWDF_USB_PIPE_INFORMATION
WDF_USB_PIPE_DIRECTION_IN proto fastcall :BYTE
WDF_USB_PIPE_DIRECTION_OUT proto fastcall :BYTE
proto_PFN_WDFUSBTARGETDEVICECREATE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFDEVICE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFUSBDEVICE
PFN_WDFUSBTARGETDEVICECREATE typedef ptr proto_PFN_WDFUSBTARGETDEVICECREATE
WdfUsbTargetDeviceCreate proto fastcall :WDFDEVICE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFUSBDEVICE
proto_PFN_WDFUSBTARGETDEVICERETRIEVEINFORMATION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :PWDF_USB_DEVICE_INFORMATION
PFN_WDFUSBTARGETDEVICERETRIEVEINFORMATION typedef ptr proto_PFN_WDFUSBTARGETDEVICERETRIEVEINFORMATION
WdfUsbTargetDeviceRetrieveInformation proto fastcall :WDFUSBDEVICE, :PWDF_USB_DEVICE_INFORMATION
proto_PFN_WDFUSBTARGETDEVICEGETDEVICEDESCRIPTOR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :PUSB_DEVICE_DESCRIPTOR
PFN_WDFUSBTARGETDEVICEGETDEVICEDESCRIPTOR typedef ptr proto_PFN_WDFUSBTARGETDEVICEGETDEVICEDESCRIPTOR
WdfUsbTargetDeviceGetDeviceDescriptor proto fastcall :WDFUSBDEVICE, :PUSB_DEVICE_DESCRIPTOR
proto_PFN_WDFUSBTARGETDEVICERETRIEVECONFIGDESCRIPTOR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :PVOID, :PUSHORT
PFN_WDFUSBTARGETDEVICERETRIEVECONFIGDESCRIPTOR typedef ptr proto_PFN_WDFUSBTARGETDEVICERETRIEVECONFIGDESCRIPTOR
WdfUsbTargetDeviceRetrieveConfigDescriptor proto fastcall :WDFUSBDEVICE, :PVOID, :PUSHORT
proto_PFN_WDFUSBTARGETDEVICEQUERYSTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS, :PUSHORT, :PUSHORT, :BYTE, :WORD
PFN_WDFUSBTARGETDEVICEQUERYSTRING typedef ptr proto_PFN_WDFUSBTARGETDEVICEQUERYSTRING
WdfUsbTargetDeviceQueryString proto fastcall :WDFUSBDEVICE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS, :PUSHORT, :PUSHORT, :BYTE, :WORD
proto_PFN_WDFUSBTARGETDEVICEALLOCANDQUERYSTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFMEMORY, :PUSHORT, :BYTE, :WORD
PFN_WDFUSBTARGETDEVICEALLOCANDQUERYSTRING typedef ptr proto_PFN_WDFUSBTARGETDEVICEALLOCANDQUERYSTRING
WdfUsbTargetDeviceAllocAndQueryString proto fastcall :WDFUSBDEVICE, :PWDF_OBJECT_ATTRIBUTES, :ptr WDFMEMORY, :PUSHORT, :BYTE, :WORD
proto_PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORSTRING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET, :BYTE, :WORD
PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORSTRING typedef ptr proto_PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORSTRING
WdfUsbTargetDeviceFormatRequestForString proto fastcall :WDFUSBDEVICE, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET, :BYTE, :WORD
proto_PFN_WDFUSBTARGETDEVICEGETNUMINTERFACES typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE
PFN_WDFUSBTARGETDEVICEGETNUMINTERFACES typedef ptr proto_PFN_WDFUSBTARGETDEVICEGETNUMINTERFACES
WdfUsbTargetDeviceGetNumInterfaces proto fastcall :WDFUSBDEVICE
proto_PFN_WDFUSBTARGETDEVICESELECTCONFIG typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :PWDF_OBJECT_ATTRIBUTES, :PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS
PFN_WDFUSBTARGETDEVICESELECTCONFIG typedef ptr proto_PFN_WDFUSBTARGETDEVICESELECTCONFIG
WdfUsbTargetDeviceSelectConfig proto fastcall :WDFUSBDEVICE, :PWDF_OBJECT_ATTRIBUTES, :PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS
proto_PFN_WDFUSBTARGETDEVICEWDMGETCONFIGURATIONHANDLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE
PFN_WDFUSBTARGETDEVICEWDMGETCONFIGURATIONHANDLE typedef ptr proto_PFN_WDFUSBTARGETDEVICEWDMGETCONFIGURATIONHANDLE
WdfUsbTargetDeviceWdmGetConfigurationHandle proto fastcall :WDFUSBDEVICE
proto_PFN_WDFUSBTARGETDEVICERETRIEVECURRENTFRAMENUMBER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :PULONG
PFN_WDFUSBTARGETDEVICERETRIEVECURRENTFRAMENUMBER typedef ptr proto_PFN_WDFUSBTARGETDEVICERETRIEVECURRENTFRAMENUMBER
WdfUsbTargetDeviceRetrieveCurrentFrameNumber proto fastcall :WDFUSBDEVICE, :PULONG
proto_PFN_WDFUSBTARGETDEVICESENDCONTROLTRANSFERSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS, :PWDF_USB_CONTROL_SETUP_PACKET, :PWDF_MEMORY_DESCRIPTOR, :PULONG
PFN_WDFUSBTARGETDEVICESENDCONTROLTRANSFERSYNCHRONOUSLY typedef ptr proto_PFN_WDFUSBTARGETDEVICESENDCONTROLTRANSFERSYNCHRONOUSLY
WdfUsbTargetDeviceSendControlTransferSynchronously proto fastcall :WDFUSBDEVICE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS, :PWDF_USB_CONTROL_SETUP_PACKET, :PWDF_MEMORY_DESCRIPTOR, :PULONG
proto_PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORCONTROLTRANSFER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :WDFREQUEST, :PWDF_USB_CONTROL_SETUP_PACKET, :WDFMEMORY, :PWDFMEMORY_OFFSET
PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORCONTROLTRANSFER typedef ptr proto_PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORCONTROLTRANSFER
WdfUsbTargetDeviceFormatRequestForControlTransfer proto fastcall :WDFUSBDEVICE, :WDFREQUEST, :PWDF_USB_CONTROL_SETUP_PACKET, :WDFMEMORY, :PWDFMEMORY_OFFSET
proto_PFN_WDFUSBTARGETDEVICEISCONNECTEDSYNCHRONOUS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE
PFN_WDFUSBTARGETDEVICEISCONNECTEDSYNCHRONOUS typedef ptr proto_PFN_WDFUSBTARGETDEVICEISCONNECTEDSYNCHRONOUS
WdfUsbTargetDeviceIsConnectedSynchronous proto fastcall :WDFUSBDEVICE
proto_PFN_WDFUSBTARGETDEVICERESETPORTSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE
PFN_WDFUSBTARGETDEVICERESETPORTSYNCHRONOUSLY typedef ptr proto_PFN_WDFUSBTARGETDEVICERESETPORTSYNCHRONOUSLY
WdfUsbTargetDeviceResetPortSynchronously proto fastcall :WDFUSBDEVICE
proto_PFN_WDFUSBTARGETDEVICECYCLEPORTSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE
PFN_WDFUSBTARGETDEVICECYCLEPORTSYNCHRONOUSLY typedef ptr proto_PFN_WDFUSBTARGETDEVICECYCLEPORTSYNCHRONOUSLY
WdfUsbTargetDeviceCyclePortSynchronously proto fastcall :WDFUSBDEVICE
proto_PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORCYCLEPORT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :WDFREQUEST
PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORCYCLEPORT typedef ptr proto_PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORCYCLEPORT
WdfUsbTargetDeviceFormatRequestForCyclePort proto fastcall :WDFUSBDEVICE, :WDFREQUEST
proto_PFN_WDFUSBTARGETDEVICESENDURBSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS, :PURB
PFN_WDFUSBTARGETDEVICESENDURBSYNCHRONOUSLY typedef ptr proto_PFN_WDFUSBTARGETDEVICESENDURBSYNCHRONOUSLY
WdfUsbTargetDeviceSendUrbSynchronously proto fastcall :WDFUSBDEVICE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS, :PURB
proto_PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORURB typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET
PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORURB typedef ptr proto_PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORURB
WdfUsbTargetDeviceFormatRequestForUrb proto fastcall :WDFUSBDEVICE, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET
proto_PFN_WDFUSBTARGETPIPEGETINFORMATION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE, :PWDF_USB_PIPE_INFORMATION
PFN_WDFUSBTARGETPIPEGETINFORMATION typedef ptr proto_PFN_WDFUSBTARGETPIPEGETINFORMATION
WdfUsbTargetPipeGetInformation proto fastcall :WDFUSBPIPE, :PWDF_USB_PIPE_INFORMATION
proto_PFN_WDFUSBTARGETPIPEISINENDPOINT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE
PFN_WDFUSBTARGETPIPEISINENDPOINT typedef ptr proto_PFN_WDFUSBTARGETPIPEISINENDPOINT
WdfUsbTargetPipeIsInEndpoint proto fastcall :WDFUSBPIPE
proto_PFN_WDFUSBTARGETPIPEISOUTENDPOINT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE
PFN_WDFUSBTARGETPIPEISOUTENDPOINT typedef ptr proto_PFN_WDFUSBTARGETPIPEISOUTENDPOINT
WdfUsbTargetPipeIsOutEndpoint proto fastcall :WDFUSBPIPE
proto_PFN_WDFUSBTARGETPIPEGETTYPE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE
PFN_WDFUSBTARGETPIPEGETTYPE typedef ptr proto_PFN_WDFUSBTARGETPIPEGETTYPE
WdfUsbTargetPipeGetType proto fastcall :WDFUSBPIPE
proto_PFN_WDFUSBTARGETPIPESETNOMAXIMUMPACKETSIZECHECK typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE
PFN_WDFUSBTARGETPIPESETNOMAXIMUMPACKETSIZECHECK typedef ptr proto_PFN_WDFUSBTARGETPIPESETNOMAXIMUMPACKETSIZECHECK
WdfUsbTargetPipeSetNoMaximumPacketSizeCheck proto fastcall :WDFUSBPIPE
proto_PFN_WDFUSBTARGETPIPEWRITESYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS, :PWDF_MEMORY_DESCRIPTOR, :PULONG
PFN_WDFUSBTARGETPIPEWRITESYNCHRONOUSLY typedef ptr proto_PFN_WDFUSBTARGETPIPEWRITESYNCHRONOUSLY
WdfUsbTargetPipeWriteSynchronously proto fastcall :WDFUSBPIPE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS, :PWDF_MEMORY_DESCRIPTOR, :PULONG
proto_PFN_WDFUSBTARGETPIPEFORMATREQUESTFORWRITE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET
PFN_WDFUSBTARGETPIPEFORMATREQUESTFORWRITE typedef ptr proto_PFN_WDFUSBTARGETPIPEFORMATREQUESTFORWRITE
WdfUsbTargetPipeFormatRequestForWrite proto fastcall :WDFUSBPIPE, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET
proto_PFN_WDFUSBTARGETPIPEREADSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS, :PWDF_MEMORY_DESCRIPTOR, :PULONG
PFN_WDFUSBTARGETPIPEREADSYNCHRONOUSLY typedef ptr proto_PFN_WDFUSBTARGETPIPEREADSYNCHRONOUSLY
WdfUsbTargetPipeReadSynchronously proto fastcall :WDFUSBPIPE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS, :PWDF_MEMORY_DESCRIPTOR, :PULONG
proto_PFN_WDFUSBTARGETPIPEFORMATREQUESTFORREAD typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET
PFN_WDFUSBTARGETPIPEFORMATREQUESTFORREAD typedef ptr proto_PFN_WDFUSBTARGETPIPEFORMATREQUESTFORREAD
WdfUsbTargetPipeFormatRequestForRead proto fastcall :WDFUSBPIPE, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET
proto_PFN_WDFUSBTARGETPIPECONFIGCONTINUOUSREADER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE, :PWDF_USB_CONTINUOUS_READER_CONFIG
PFN_WDFUSBTARGETPIPECONFIGCONTINUOUSREADER typedef ptr proto_PFN_WDFUSBTARGETPIPECONFIGCONTINUOUSREADER
WdfUsbTargetPipeConfigContinuousReader proto fastcall :WDFUSBPIPE, :PWDF_USB_CONTINUOUS_READER_CONFIG
proto_PFN_WDFUSBTARGETPIPEABORTSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS
PFN_WDFUSBTARGETPIPEABORTSYNCHRONOUSLY typedef ptr proto_PFN_WDFUSBTARGETPIPEABORTSYNCHRONOUSLY
WdfUsbTargetPipeAbortSynchronously proto fastcall :WDFUSBPIPE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS
proto_PFN_WDFUSBTARGETPIPEFORMATREQUESTFORABORT typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE, :WDFREQUEST
PFN_WDFUSBTARGETPIPEFORMATREQUESTFORABORT typedef ptr proto_PFN_WDFUSBTARGETPIPEFORMATREQUESTFORABORT
WdfUsbTargetPipeFormatRequestForAbort proto fastcall :WDFUSBPIPE, :WDFREQUEST
proto_PFN_WDFUSBTARGETPIPERESETSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS
PFN_WDFUSBTARGETPIPERESETSYNCHRONOUSLY typedef ptr proto_PFN_WDFUSBTARGETPIPERESETSYNCHRONOUSLY
WdfUsbTargetPipeResetSynchronously proto fastcall :WDFUSBPIPE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS
proto_PFN_WDFUSBTARGETPIPEFORMATREQUESTFORRESET typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE, :WDFREQUEST
PFN_WDFUSBTARGETPIPEFORMATREQUESTFORRESET typedef ptr proto_PFN_WDFUSBTARGETPIPEFORMATREQUESTFORRESET
WdfUsbTargetPipeFormatRequestForReset proto fastcall :WDFUSBPIPE, :WDFREQUEST
proto_PFN_WDFUSBTARGETPIPESENDURBSYNCHRONOUSLY typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS, :PURB
PFN_WDFUSBTARGETPIPESENDURBSYNCHRONOUSLY typedef ptr proto_PFN_WDFUSBTARGETPIPESENDURBSYNCHRONOUSLY
WdfUsbTargetPipeSendUrbSynchronously proto fastcall :WDFUSBPIPE, :WDFREQUEST, :PWDF_REQUEST_SEND_OPTIONS, :PURB
proto_PFN_WDFUSBTARGETPIPEFORMATREQUESTFORURB typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET
PFN_WDFUSBTARGETPIPEFORMATREQUESTFORURB typedef ptr proto_PFN_WDFUSBTARGETPIPEFORMATREQUESTFORURB
WdfUsbTargetPipeFormatRequestForUrb proto fastcall :WDFUSBPIPE, :WDFREQUEST, :WDFMEMORY, :PWDFMEMORY_OFFSET
proto_PFN_WDFUSBINTERFACEGETINTERFACENUMBER typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBINTERFACE
PFN_WDFUSBINTERFACEGETINTERFACENUMBER typedef ptr proto_PFN_WDFUSBINTERFACEGETINTERFACENUMBER
WdfUsbInterfaceGetInterfaceNumber proto fastcall :WDFUSBINTERFACE
proto_PFN_WDFUSBINTERFACEGETNUMENDPOINTS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBINTERFACE, :BYTE
PFN_WDFUSBINTERFACEGETNUMENDPOINTS typedef ptr proto_PFN_WDFUSBINTERFACEGETNUMENDPOINTS
WdfUsbInterfaceGetNumEndpoints proto fastcall :WDFUSBINTERFACE, :BYTE
proto_PFN_WDFUSBINTERFACEGETDESCRIPTOR typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBINTERFACE, :BYTE, :PUSB_INTERFACE_DESCRIPTOR
PFN_WDFUSBINTERFACEGETDESCRIPTOR typedef ptr proto_PFN_WDFUSBINTERFACEGETDESCRIPTOR
WdfUsbInterfaceGetDescriptor proto fastcall :WDFUSBINTERFACE, :BYTE, :PUSB_INTERFACE_DESCRIPTOR
proto_PFN_WDFUSBINTERFACEGETNUMSETTINGS typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBINTERFACE
PFN_WDFUSBINTERFACEGETNUMSETTINGS typedef ptr proto_PFN_WDFUSBINTERFACEGETNUMSETTINGS
WdfUsbInterfaceGetNumSettings proto fastcall :WDFUSBINTERFACE
proto_PFN_WDFUSBINTERFACESELECTSETTING typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBINTERFACE, :PWDF_OBJECT_ATTRIBUTES, :PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS
PFN_WDFUSBINTERFACESELECTSETTING typedef ptr proto_PFN_WDFUSBINTERFACESELECTSETTING
WdfUsbInterfaceSelectSetting proto fastcall :WDFUSBINTERFACE, :PWDF_OBJECT_ATTRIBUTES, :PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS
proto_PFN_WDFUSBINTERFACEGETENDPOINTINFORMATION typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBINTERFACE, :BYTE, :BYTE, :PWDF_USB_PIPE_INFORMATION
PFN_WDFUSBINTERFACEGETENDPOINTINFORMATION typedef ptr proto_PFN_WDFUSBINTERFACEGETENDPOINTINFORMATION
WdfUsbInterfaceGetEndpointInformation proto fastcall :WDFUSBINTERFACE, :BYTE, :BYTE, :PWDF_USB_PIPE_INFORMATION
proto_PFN_WDFUSBTARGETDEVICEGETINTERFACE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBDEVICE, :BYTE
PFN_WDFUSBTARGETDEVICEGETINTERFACE typedef ptr proto_PFN_WDFUSBTARGETDEVICEGETINTERFACE
WdfUsbTargetDeviceGetInterface proto fastcall :WDFUSBDEVICE, :BYTE
proto_PFN_WDFUSBINTERFACEGETCONFIGUREDSETTINGINDEX typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBINTERFACE
PFN_WDFUSBINTERFACEGETCONFIGUREDSETTINGINDEX typedef ptr proto_PFN_WDFUSBINTERFACEGETCONFIGUREDSETTINGINDEX
WdfUsbInterfaceGetConfiguredSettingIndex proto fastcall :WDFUSBINTERFACE
proto_PFN_WDFUSBINTERFACEGETNUMCONFIGUREDPIPES typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBINTERFACE
PFN_WDFUSBINTERFACEGETNUMCONFIGUREDPIPES typedef ptr proto_PFN_WDFUSBINTERFACEGETNUMCONFIGUREDPIPES
WdfUsbInterfaceGetNumConfiguredPipes proto fastcall :WDFUSBINTERFACE
proto_PFN_WDFUSBINTERFACEGETCONFIGUREDPIPE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBINTERFACE, :BYTE, :PWDF_USB_PIPE_INFORMATION
PFN_WDFUSBINTERFACEGETCONFIGUREDPIPE typedef ptr proto_PFN_WDFUSBINTERFACEGETCONFIGUREDPIPE
WdfUsbInterfaceGetConfiguredPipe proto fastcall :WDFUSBINTERFACE, :BYTE, :PWDF_USB_PIPE_INFORMATION
proto_PFN_WDFUSBTARGETPIPEWDMGETPIPEHANDLE typedef proto fastcall :PWDF_DRIVER_GLOBALS, :WDFUSBPIPE
PFN_WDFUSBTARGETPIPEWDMGETPIPEHANDLE typedef ptr proto_PFN_WDFUSBTARGETPIPEWDMGETPIPEHANDLE
WdfUsbTargetPipeWdmGetPipeHandle proto fastcall :WDFUSBPIPE

