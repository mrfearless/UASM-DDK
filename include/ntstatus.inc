;========================================================================
; Constant definitions for the NTSTATUS values.
; 
; Converted from ntstatus.h of Windows Kit 8.1 to asm format 
; for KMDF64 by fearless
;    
;========================================================================


;========================================================================
;
; Standard Success values
;
;
;========================================================================


;
; The success status codes 0 - 63 are reserved for wait completion status.
; FacilityCodes 0x5 - 0xF have been allocated by various drivers.
;
STATUS_WAIT_0                           EQU 000000000h

;
;  Values are 32 bit values laid out as follows:
;
;   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
;   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
;  +---+-+-+-----------------------+-------------------------------+
;  |Sev|C|R|     Facility          |               Code            |
;  +---+-+-+-----------------------+-------------------------------+
;
;  where
;
;      Sev - is the severity code
;
;          00 - Success
;          01 - Informational
;          10 - Warning
;          11 - Error
;
;      C - is the Customer code flag
;
;      R - is a reserved bit
;
;      Facility - is the facility code
;
;      Code - is the facility's status code
;
;
; Define the facility codes
;
FACILITY_VOLSNAP                 EQU 050h
FACILITY_VOLMGR                  EQU 038h
FACILITY_VIRTUALIZATION          EQU 037h
FACILITY_VIDEO                   EQU 01Bh
FACILITY_USB_ERROR_CODE          EQU 010h
FACILITY_TRANSACTION             EQU 019h
FACILITY_TPM                     EQU 029h
FACILITY_TERMINAL_SERVER         EQU 0Ah
FACILITY_SXS_ERROR_CODE          EQU 015h
FACILITY_NTSSPI                  EQU 09h
FACILITY_SPACES                  EQU 0E7h
FACILITY_SHARED_VHDX             EQU 05Ch
FACILITY_SECUREBOOT              EQU 043h
FACILITY_SDBUS                   EQU 051h
FACILITY_RPC_STUBS               EQU 03h
FACILITY_RPC_RUNTIME             EQU 02h
FACILITY_RESUME_KEY_FILTER       EQU 040h
FACILITY_RDBSS                   EQU 041h
FACILITY_NTWIN32                 EQU 07h
FACILITY_WIN32K_NTUSER           EQU 03Eh
FACILITY_WIN32K_NTGDI            EQU 03Fh
FACILITY_NDIS_ERROR_CODE         EQU 023h
FACILTIY_MUI_ERROR_CODE          EQU 0Bh
FACILITY_MONITOR                 EQU 01Dh
FACILITY_MAXIMUM_VALUE           EQU 0E8h
FACILITY_IPSEC                   EQU 036h
FACILITY_IO_ERROR_CODE           EQU 04h
FACILITY_INTERIX                 EQU 099h
FACILITY_HYPERVISOR              EQU 035h
FACILITY_HID_ERROR_CODE          EQU 011h
FACILITY_GRAPHICS_KERNEL         EQU 01Eh
FACILITY_FWP_ERROR_CODE          EQU 022h
FACILITY_FVE_ERROR_CODE          EQU 021h
FACILITY_FIREWIRE_ERROR_CODE     EQU 012h
FACILITY_FILTER_MANAGER          EQU 01Ch
FACILITY_DRIVER_FRAMEWORK        EQU 020h
FACILITY_DEBUGGER                EQU 01h
FACILITY_COMMONLOG               EQU 01Ah
FACILITY_CODCLASS_ERROR_CODE     EQU 06h
FACILITY_CLUSTER_ERROR_CODE      EQU 013h
FACILITY_NTCERT                  EQU 08h
FACILITY_BTH_ATT                 EQU 042h
FACILITY_BCD_ERROR_CODE          EQU 039h
FACILITY_AUDIO_KERNEL            EQU 044h
FACILITY_ACPI_ERROR_CODE         EQU 014h


;
; Define the severity codes
;
STATUS_SEVERITY_WARNING          EQU 02h
STATUS_SEVERITY_SUCCESS          EQU 00h
STATUS_SEVERITY_INFORMATIONAL    EQU 01h
STATUS_SEVERITY_ERROR            EQU 03h


;
; MessageId: STATUS_SUCCESS
;
; MessageText:
;
;  STATUS_SUCCESS
;
STATUS_SUCCESS                   EQU 000000000h

;
; MessageId: STATUS_WAIT_1
;
; MessageText:
;
;  STATUS_WAIT_1
;
STATUS_WAIT_1                    EQU 000000001h

;
; MessageId: STATUS_WAIT_2
;
; MessageText:
;
;  STATUS_WAIT_2
;
STATUS_WAIT_2                    EQU 000000002h

;
; MessageId: STATUS_WAIT_3
;
; MessageText:
;
;  STATUS_WAIT_3
;
STATUS_WAIT_3                    EQU 000000003h

;
; MessageId: STATUS_WAIT_63
;
; MessageText:
;
;  STATUS_WAIT_63
;
STATUS_WAIT_63                   EQU 00000003Fh


;
; The success status codes 128 - 191 are reserved for wait completion
; status with an abandoned mutant object.
;
STATUS_ABANDONED                        EQU 000000080h

;
; MessageId: STATUS_ABANDONED_WAIT_0
;
; MessageText:
;
;  STATUS_ABANDONED_WAIT_0
;
STATUS_ABANDONED_WAIT_0          EQU 000000080h

;
; MessageId: STATUS_ABANDONED_WAIT_63
;
; MessageText:
;
;  STATUS_ABANDONED_WAIT_63
;
STATUS_ABANDONED_WAIT_63         EQU 0000000BFh


;
; The success status codes 256, 257, 258, and 258 are reserved for
; User APC, Kernel APC, Alerted, and Timeout.
;
;
; MessageId: STATUS_USER_APC
;
; MessageText:
;
;  STATUS_USER_APC
;
STATUS_USER_APC                  EQU 0000000C0h

;
; MessageId: STATUS_KERNEL_APC
;
; MessageText:
;
;  STATUS_KERNEL_APC
;
STATUS_KERNEL_APC                EQU 000000100h

;
; MessageId: STATUS_ALERTED
;
; MessageText:
;
;  STATUS_ALERTED
;
STATUS_ALERTED                   EQU 000000101h

;
; MessageId: STATUS_TIMEOUT
;
; MessageText:
;
;  STATUS_TIMEOUT
;
STATUS_TIMEOUT                   EQU 000000102h

;
; MessageId: STATUS_PENDING
;
; MessageText:
;
; The operation that was requested is pending completion.
;
STATUS_PENDING                   EQU 000000103h

;
; MessageId: STATUS_REPARSE
;
; MessageText:
;
; A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
;
STATUS_REPARSE                   EQU 000000104h

;
; MessageId: STATUS_MORE_ENTRIES
;
; MessageText:
;
; Returned by enumeration APIs to indicate more information is available to successive calls.
;
STATUS_MORE_ENTRIES              EQU 000000105h

;
; MessageId: STATUS_NOT_ALL_ASSIGNED
;
; MessageText:
;
; Indicates not all privileges or groups referenced are assigned to the caller.
; This allows, for example, all privileges to be disabled without having to know exactly which privileges are assigned.
;
STATUS_NOT_ALL_ASSIGNED          EQU 000000106h

;
; MessageId: STATUS_SOME_NOT_MAPPED
;
; MessageText:
;
; Some of the information to be translated has not been translated.
;
STATUS_SOME_NOT_MAPPED           EQU 000000107h

;
; MessageId: STATUS_OPLOCK_BREAK_IN_PROGRESS
;
; MessageText:
;
; An open/create operation completed while an oplock break is underway.
;
STATUS_OPLOCK_BREAK_IN_PROGRESS  EQU 000000108h

;
; MessageId: STATUS_VOLUME_MOUNTED
;
; MessageText:
;
; A new volume has been mounted by a file system.
;
STATUS_VOLUME_MOUNTED            EQU 000000109h

;
; MessageId: STATUS_RXACT_COMMITTED
;
; MessageText:
;
; This success level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted. The commit has now been completed.
;
STATUS_RXACT_COMMITTED           EQU 00000010Ah

;
; MessageId: STATUS_NOTIFY_CLEANUP
;
; MessageText:
;
; This indicates that a notify change request has been completed due to closing the handle which made the notify change request.
;
STATUS_NOTIFY_CLEANUP            EQU 00000010Bh

;
; MessageId: STATUS_NOTIFY_ENUM_DIR
;
; MessageText:
;
; This indicates that a notify change request is being completed and that the information is not being returned in the caller's buffer.
; The caller now needs to enumerate the files to find the changes.
;
STATUS_NOTIFY_ENUM_DIR           EQU 00000010Ch

;
; MessageId: STATUS_NO_QUOTAS_FOR_ACCOUNT
;
; MessageText:
;
; {No Quotas}
; No system quota limits are specifically set for this account.
;
STATUS_NO_QUOTAS_FOR_ACCOUNT     EQU 00000010Dh

;
; MessageId: STATUS_PRIMARY_TRANSPORT_CONNECT_FAILED
;
; MessageText:
;
; {Connect Failure on Primary Transport}
; An attempt was made to connect to the remote server %hs on the primary transport, but the connection failed.
; The computer WAS able to connect on a secondary transport.
;
STATUS_PRIMARY_TRANSPORT_CONNECT_FAILED EQU 00000010Eh

;
; MessageId: STATUS_PAGE_FAULT_TRANSITION
;
; MessageText:
;
; Page fault was a transition fault.
;
STATUS_PAGE_FAULT_TRANSITION     EQU 000000110h

;
; MessageId: STATUS_PAGE_FAULT_DEMAND_ZERO
;
; MessageText:
;
; Page fault was a demand zero fault.
;
STATUS_PAGE_FAULT_DEMAND_ZERO    EQU 000000111h

;
; MessageId: STATUS_PAGE_FAULT_COPY_ON_WRITE
;
; MessageText:
;
; Page fault was a demand zero fault.
;
STATUS_PAGE_FAULT_COPY_ON_WRITE  EQU 000000112h

;
; MessageId: STATUS_PAGE_FAULT_GUARD_PAGE
;
; MessageText:
;
; Page fault was a demand zero fault.
;
STATUS_PAGE_FAULT_GUARD_PAGE     EQU 000000113h

;
; MessageId: STATUS_PAGE_FAULT_PAGING_FILE
;
; MessageText:
;
; Page fault was satisfied by reading from a secondary storage device.
;
STATUS_PAGE_FAULT_PAGING_FILE    EQU 000000114h

;
; MessageId: STATUS_CACHE_PAGE_LOCKED
;
; MessageText:
;
; Cached page was locked during operation.
;
STATUS_CACHE_PAGE_LOCKED         EQU 000000115h

;
; MessageId: STATUS_CRASH_DUMP
;
; MessageText:
;
; Crash dump exists in paging file.
;
STATUS_CRASH_DUMP                EQU 000000116h

;
; MessageId: STATUS_BUFFER_ALL_ZEROS
;
; MessageText:
;
; Specified buffer contains all zeros.
;
STATUS_BUFFER_ALL_ZEROS          EQU 000000117h

;
; MessageId: STATUS_REPARSE_OBJECT
;
; MessageText:
;
; A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
;
STATUS_REPARSE_OBJECT            EQU 000000118h

;
; MessageId: STATUS_RESOURCE_REQUIREMENTS_CHANGED
;
; MessageText:
;
; The device has succeeded a query-stop and its resource requirements have changed.
;
STATUS_RESOURCE_REQUIREMENTS_CHANGED EQU 000000119h

;
; MessageId: STATUS_TRANSLATION_COMPLETE
;
; MessageText:
;
; The translator has translated these resources into the global space and no further translations should be performed.
;
STATUS_TRANSLATION_COMPLETE      EQU 000000120h

;
; MessageId: STATUS_DS_MEMBERSHIP_EVALUATED_LOCALLY
;
; MessageText:
;
; The directory service evaluated group memberships locally, as it was unable to contact a global catalog server.
;
STATUS_DS_MEMBERSHIP_EVALUATED_LOCALLY EQU 000000121h

;
; MessageId: STATUS_NOTHING_TO_TERMINATE
;
; MessageText:
;
; A process being terminated has no threads to terminate.
;
STATUS_NOTHING_TO_TERMINATE      EQU 000000122h

;
; MessageId: STATUS_PROCESS_NOT_IN_JOB
;
; MessageText:
;
; The specified process is not part of a job.
;
STATUS_PROCESS_NOT_IN_JOB        EQU 000000123h

;
; MessageId: STATUS_PROCESS_IN_JOB
;
; MessageText:
;
; The specified process is part of a job.
;
STATUS_PROCESS_IN_JOB            EQU 000000124h

;
; MessageId: STATUS_VOLSNAP_HIBERNATE_READY
;
; MessageText:
;
; {Volume Shadow Copy Service}
; The system is now ready for hibernation.
;
STATUS_VOLSNAP_HIBERNATE_READY   EQU 000000125h

;
; MessageId: STATUS_FSFILTER_OP_COMPLETED_SUCCESSFULLY
;
; MessageText:
;
; A file system or file system filter driver has successfully completed an FsFilter operation.
;
STATUS_FSFILTER_OP_COMPLETED_SUCCESSFULLY EQU 000000126h

;
; MessageId: STATUS_INTERRUPT_VECTOR_ALREADY_CONNECTED
;
; MessageText:
;
; The specified interrupt vector was already connected.
;
STATUS_INTERRUPT_VECTOR_ALREADY_CONNECTED EQU 000000127h

;
; MessageId: STATUS_INTERRUPT_STILL_CONNECTED
;
; MessageText:
;
; The specified interrupt vector is still connected.
;
STATUS_INTERRUPT_STILL_CONNECTED EQU 000000128h

;
; MessageId: STATUS_PROCESS_CLONED
;
; MessageText:
;
; The current process is a cloned process.
;
STATUS_PROCESS_CLONED            EQU 000000129h

;
; MessageId: STATUS_FILE_LOCKED_WITH_ONLY_READERS
;
; MessageText:
;
; The file was locked and all users of the file can only read.
;
STATUS_FILE_LOCKED_WITH_ONLY_READERS EQU 00000012Ah

;
; MessageId: STATUS_FILE_LOCKED_WITH_WRITERS
;
; MessageText:
;
; The file was locked and at least one user of the file can write.
;
STATUS_FILE_LOCKED_WITH_WRITERS  EQU 00000012Bh

;
; MessageId: STATUS_VALID_IMAGE_HASH
;
; MessageText:
;
; The file image hash is valid.
;
STATUS_VALID_IMAGE_HASH          EQU 00000012Ch

;
; MessageId: STATUS_VALID_CATALOG_HASH
;
; MessageText:
;
; The file catalog hash is valid.
;
STATUS_VALID_CATALOG_HASH        EQU 00000012Dh

;
; MessageId: STATUS_RESOURCEMANAGER_READ_ONLY
;
; MessageText:
;
; The specified ResourceManager made no changes or updates to the resource under this transaction.
;
STATUS_RESOURCEMANAGER_READ_ONLY EQU 000000202h

;
; MessageId: STATUS_RING_PREVIOUSLY_EMPTY
;
; MessageText:
;
; The specified ring buffer was empty before the packet was successfully inserted.
;
STATUS_RING_PREVIOUSLY_EMPTY     EQU 000000210h

;
; MessageId: STATUS_RING_PREVIOUSLY_FULL
;
; MessageText:
;
; The specified ring buffer was full before the packet was successfully removed.
;
STATUS_RING_PREVIOUSLY_FULL      EQU 000000211h

;
; MessageId: STATUS_RING_PREVIOUSLY_ABOVE_QUOTA
;
; MessageText:
;
; The specified ring buffer has dropped below its quota of outstanding transactions.
;
STATUS_RING_PREVIOUSLY_ABOVE_QUOTA EQU 000000212h

;
; MessageId: STATUS_RING_NEWLY_EMPTY
;
; MessageText:
;
; The specified ring buffer has, with the removal of the current packet, now become empty.
;
STATUS_RING_NEWLY_EMPTY          EQU 000000213h

;
; MessageId: STATUS_RING_SIGNAL_OPPOSITE_ENDPOINT
;
; MessageText:
;
; The specified ring buffer was either previously empty or previously full which implies that the caller should signal the opposite endpoint.
;
STATUS_RING_SIGNAL_OPPOSITE_ENDPOINT EQU 000000214h

;
; MessageId: STATUS_OPLOCK_SWITCHED_TO_NEW_HANDLE
;
; MessageText:
;
; The oplock that was associated with this handle is now associated with a different handle.
;
STATUS_OPLOCK_SWITCHED_TO_NEW_HANDLE EQU 000000215h

;
; MessageId: STATUS_OPLOCK_HANDLE_CLOSED
;
; MessageText:
;
; The handle with which this oplock was associated has been closed.  The oplock is now broken.
;
STATUS_OPLOCK_HANDLE_CLOSED      EQU 000000216h

;
; MessageId: STATUS_WAIT_FOR_OPLOCK
;
; MessageText:
;
; An operation is blocked waiting for an oplock.
;
STATUS_WAIT_FOR_OPLOCK           EQU 000000367h

;
; MessageId: DBG_EXCEPTION_HANDLED
;
; MessageText:
;
; Debugger handled exception
;
DBG_EXCEPTION_HANDLED            EQU 000010001h

;
; MessageId: DBG_CONTINUE
;
; MessageText:
;
; Debugger continued
;
DBG_CONTINUE                     EQU 000010002h

;
; MessageId: STATUS_FLT_IO_COMPLETE
;
; MessageText:
;
; The IO was completed by a filter.
;
STATUS_FLT_IO_COMPLETE           EQU 0001C0001h

;========================================================================
;
; Standard Information values
;
;========================================================================

;
; MessageId: STATUS_OBJECT_NAME_EXISTS
;
; MessageText:
;
; {Object Exists}
; An attempt was made to create an object and the object name already existed.
;
STATUS_OBJECT_NAME_EXISTS        EQU 040000000h

;
; MessageId: STATUS_THREAD_WAS_SUSPENDED
;
; MessageText:
;
; {Thread Suspended}
; A thread termination occurred while the thread was suspended. The thread was resumed, and termination proceeded.
;
STATUS_THREAD_WAS_SUSPENDED      EQU 040000001h

;
; MessageId: STATUS_WORKING_SET_LIMIT_RANGE
;
; MessageText:
;
; {Working Set Range Error}
; An attempt was made to set the working set minimum or maximum to values which are outside of the allowable range.
;
STATUS_WORKING_SET_LIMIT_RANGE   EQU 040000002h

;
; MessageId: STATUS_IMAGE_NOT_AT_BASE
;
; MessageText:
;
; {Image Relocated}
; An image file could not be mapped at the address specified in the image file. Local fixups must be performed on this image.
;
STATUS_IMAGE_NOT_AT_BASE         EQU 040000003h

;
; MessageId: STATUS_RXACT_STATE_CREATED
;
; MessageText:
;
; This informational level status indicates that a specified registry sub-tree transaction state did not yet exist and had to be created.
;
STATUS_RXACT_STATE_CREATED       EQU 040000004h

;
; MessageId: STATUS_SEGMENT_NOTIFICATION
;
; MessageText:
;
; {Segment Load}
; A virtual DOS machine (VDM) is loading, unloading, or moving an MS-DOS or Win16 program segment image.
; An exception is raised so a debugger can load, unload or track symbols and breakpoints within these 16-bit segments.
;
STATUS_SEGMENT_NOTIFICATION      EQU 040000005h

;
; MessageId: STATUS_LOCAL_USER_SESSION_KEY
;
; MessageText:
;
; {Local Session Key}
; A user session key was requested for a local RPC connection. The session key returned is a constant value and not unique to this connection.
;
STATUS_LOCAL_USER_SESSION_KEY    EQU 040000006h

;
; MessageId: STATUS_BAD_CURRENT_DIRECTORY
;
; MessageText:
;
; {Invalid Current Directory}
; The process cannot switch to the startup current directory %hs.
; Select OK to set current directory to %hs, or select CANCEL to exit.
;
STATUS_BAD_CURRENT_DIRECTORY     EQU 040000007h

;
; MessageId: STATUS_SERIAL_MORE_WRITES
;
; MessageText:
;
; {Serial IOCTL Complete}
; A serial I/O operation was completed by another write to a serial port.
; (The IOCTL_SERIAL_XOFF_COUNTER reached zero.)
;
STATUS_SERIAL_MORE_WRITES        EQU 040000008h

;
; MessageId: STATUS_REGISTRY_RECOVERED
;
; MessageText:
;
; {Registry Recovery}
; One of the files containing the system's Registry data had to be recovered by use of a log or alternate copy. The recovery was successful.
;
STATUS_REGISTRY_RECOVERED        EQU 040000009h

;
; MessageId: STATUS_FT_READ_RECOVERY_FROM_BACKUP
;
; MessageText:
;
; {Redundant Read}
; To satisfy a read request, the NT fault-tolerant file system successfully read the requested data from a redundant copy.
; This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was unable to reassign the failing area of the device.
;
STATUS_FT_READ_RECOVERY_FROM_BACKUP EQU 04000000Ah

;
; MessageId: STATUS_FT_WRITE_RECOVERY
;
; MessageText:
;
; {Redundant Write}
; To satisfy a write request, the NT fault-tolerant file system successfully wrote a redundant copy of the information.
; This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was not able to reassign the failing area of the device.
;
STATUS_FT_WRITE_RECOVERY         EQU 04000000Bh

;
; MessageId: STATUS_SERIAL_COUNTER_TIMEOUT
;
; MessageText:
;
; {Serial IOCTL Timeout}
; A serial I/O operation completed because the time-out period expired. (The IOCTL_SERIAL_XOFF_COUNTER had not reached zero.)
;
STATUS_SERIAL_COUNTER_TIMEOUT    EQU 04000000Ch

;
; MessageId: STATUS_NULL_LM_PASSWORD
;
; MessageText:
;
; {Password Too Complex}
; The Windows password is too complex to be converted to a LAN Manager password. The LAN Manager password returned is a NULL string.
;
STATUS_NULL_LM_PASSWORD          EQU 04000000Dh

;
; MessageId: STATUS_IMAGE_MACHINE_TYPE_MISMATCH
;
; MessageText:
;
; {Machine Type Mismatch}
; The image file %hs is valid, but is for a machine type other than the current machine. Select OK to continue, or CANCEL to fail the DLL load.
;
STATUS_IMAGE_MACHINE_TYPE_MISMATCH EQU 04000000Eh

;
; MessageId: STATUS_RECEIVE_PARTIAL
;
; MessageText:
;
; {Partial Data Received}
; The network transport returned partial data to its client. The remaining data will be sent later.
;
STATUS_RECEIVE_PARTIAL           EQU 04000000Fh

;
; MessageId: STATUS_RECEIVE_EXPEDITED
;
; MessageText:
;
; {Expedited Data Received}
; The network transport returned data to its client that was marked as expedited by the remote system.
;
STATUS_RECEIVE_EXPEDITED         EQU 040000010h

;
; MessageId: STATUS_RECEIVE_PARTIAL_EXPEDITED
;
; MessageText:
;
; {Partial Expedited Data Received}
; The network transport returned partial data to its client and this data was marked as expedited by the remote system. The remaining data will be sent later.
;
STATUS_RECEIVE_PARTIAL_EXPEDITED EQU 040000011h

;
; MessageId: STATUS_EVENT_DONE
;
; MessageText:
;
; {TDI Event Done}
; The TDI indication has completed successfully.
;
STATUS_EVENT_DONE                EQU 040000012h

;
; MessageId: STATUS_EVENT_PENDING
;
; MessageText:
;
; {TDI Event Pending}
; The TDI indication has entered the pending state.
;
STATUS_EVENT_PENDING             EQU 040000013h

;
; MessageId: STATUS_CHECKING_FILE_SYSTEM
;
; MessageText:
;
; Checking file system on %wZ
;
STATUS_CHECKING_FILE_SYSTEM      EQU 040000014h

;
; MessageId: STATUS_FATAL_APP_EXIT
;
; MessageText:
;
; {Fatal Application Exit}
; %hs
;
STATUS_FATAL_APP_EXIT            EQU 040000015h

;
; MessageId: STATUS_PREDEFINED_HANDLE
;
; MessageText:
;
; The specified registry key is referenced by a predefined handle.
;
STATUS_PREDEFINED_HANDLE         EQU 040000016h

;
; MessageId: STATUS_WAS_UNLOCKED
;
; MessageText:
;
; {Page Unlocked}
; The page protection of a locked page was changed to 'No Access' and the page was unlocked from memory and from the process.
;
STATUS_WAS_UNLOCKED              EQU 040000017h

;
; MessageId: STATUS_SERVICE_NOTIFICATION
;
; MessageText:
;
; %hs
;
STATUS_SERVICE_NOTIFICATION      EQU 040000018h

;
; MessageId: STATUS_WAS_LOCKED
;
; MessageText:
;
; {Page Locked}
; One of the pages to lock was already locked.
;
STATUS_WAS_LOCKED                EQU 040000019h

;
; MessageId: STATUS_LOG_HARD_ERROR
;
; MessageText:
;
; Application popup: %1 : %2
;
STATUS_LOG_HARD_ERROR            EQU 04000001Ah

;
; MessageId: STATUS_ALREADY_WIN32
;
; MessageText:
;
;  STATUS_ALREADY_WIN32
;
STATUS_ALREADY_WIN32             EQU 04000001Bh

;
; MessageId: STATUS_WX86_UNSIMULATE
;
; MessageText:
;
; Exception status code used by Win32 x86 emulation subsystem.
;
STATUS_WX86_UNSIMULATE           EQU 04000001Ch

;
; MessageId: STATUS_WX86_CONTINUE
;
; MessageText:
;
; Exception status code used by Win32 x86 emulation subsystem.
;
STATUS_WX86_CONTINUE             EQU 04000001Dh

;
; MessageId: STATUS_WX86_SINGLE_STEP
;
; MessageText:
;
; Exception status code used by Win32 x86 emulation subsystem.
;
STATUS_WX86_SINGLE_STEP          EQU 04000001Eh

;
; MessageId: STATUS_WX86_BREAKPOINT
;
; MessageText:
;
; Exception status code used by Win32 x86 emulation subsystem.
;
STATUS_WX86_BREAKPOINT           EQU 04000001Fh

;
; MessageId: STATUS_WX86_EXCEPTION_CONTINUE
;
; MessageText:
;
; Exception status code used by Win32 x86 emulation subsystem.
;
STATUS_WX86_EXCEPTION_CONTINUE   EQU 040000020h

;
; MessageId: STATUS_WX86_EXCEPTION_LASTCHANCE
;
; MessageText:
;
; Exception status code used by Win32 x86 emulation subsystem.
;
STATUS_WX86_EXCEPTION_LASTCHANCE EQU 040000021h

;
; MessageId: STATUS_WX86_EXCEPTION_CHAIN
;
; MessageText:
;
; Exception status code used by Win32 x86 emulation subsystem.
;
STATUS_WX86_EXCEPTION_CHAIN      EQU 040000022h

;
; MessageId: STATUS_IMAGE_MACHINE_TYPE_MISMATCH_EXE
;
; MessageText:
;
; {Machine Type Mismatch}
; The image file %hs is valid, but is for a machine type other than the current machine.
;
STATUS_IMAGE_MACHINE_TYPE_MISMATCH_EXE EQU 040000023h

;
; MessageId: STATUS_NO_YIELD_PERFORMED
;
; MessageText:
;
; A yield execution was performed and no thread was available to run.
;
STATUS_NO_YIELD_PERFORMED        EQU 040000024h

;
; MessageId: STATUS_TIMER_RESUME_IGNORED
;
; MessageText:
;
; The resumable flag to a timer API was ignored.
;
STATUS_TIMER_RESUME_IGNORED      EQU 040000025h

;
; MessageId: STATUS_ARBITRATION_UNHANDLED
;
; MessageText:
;
; The arbiter has deferred arbitration of these resources to its parent
;
STATUS_ARBITRATION_UNHANDLED     EQU 040000026h

;
; MessageId: STATUS_CARDBUS_NOT_SUPPORTED
;
; MessageText:
;
; The device "%hs" has detected a CardBus card in its slot, but the firmware on this system is not configured to allow the CardBus controller to be run in CardBus mode.
; The operating system will currently accept only 16-bit (R2) pc-cards on this controller.
;
STATUS_CARDBUS_NOT_SUPPORTED     EQU 040000027h

;
; MessageId: STATUS_WX86_CREATEWX86TIB
;
; MessageText:
;
; Exception status code used by Win32 x86 emulation subsystem.
;
STATUS_WX86_CREATEWX86TIB        EQU 040000028h

;
; MessageId: STATUS_MP_PROCESSOR_MISMATCH
;
; MessageText:
;
; The CPUs in this multiprocessor system are not all the same revision level. To use all processors the operating system restricts itself to the features of the least capable processor in the system. Should problems occur with this system, contact the CPU manufacturer to see if this mix of processors is supported.
;
STATUS_MP_PROCESSOR_MISMATCH     EQU 040000029h

;
; MessageId: STATUS_HIBERNATED
;
; MessageText:
;
; The system was put into hibernation.
;
STATUS_HIBERNATED                EQU 04000002Ah    

;
; MessageId: STATUS_RESUME_HIBERNATION
;
; MessageText:
;
; The system was resumed from hibernation.
;
STATUS_RESUME_HIBERNATION        EQU 04000002Bh    

;
; MessageId: STATUS_FIRMWARE_UPDATED
;
; MessageText:
;
; Windows has detected that the system firmware (BIOS) was updated [previous firmware date = %2, current firmware date %3].
;
STATUS_FIRMWARE_UPDATED          EQU 04000002Ch

;
; MessageId: STATUS_DRIVERS_LEAKING_LOCKED_PAGES
;
; MessageText:
;
; A device driver is leaking locked I/O pages causing system degradation. The system has automatically enabled tracking code in order to try and catch the culprit.
;
STATUS_DRIVERS_LEAKING_LOCKED_PAGES EQU 04000002Dh

;
; MessageId: STATUS_MESSAGE_RETRIEVED
;
; MessageText:
;
; The ALPC message being canceled has already been retrieved from the queue on the other side.
;
STATUS_MESSAGE_RETRIEVED         EQU 04000002Eh

;
; MessageId: STATUS_SYSTEM_POWERSTATE_TRANSITION
;
; MessageText:
;
; The system power state is transitioning from %2 to %3.
;
STATUS_SYSTEM_POWERSTATE_TRANSITION EQU 04000002Fh    

;
; MessageId: STATUS_ALPC_CHECK_COMPLETION_LIST
;
; MessageText:
;
; The receive operation was successful. Check the ALPC completion list for the received message.
;
STATUS_ALPC_CHECK_COMPLETION_LIST EQU 040000030h

;
; MessageId: STATUS_SYSTEM_POWERSTATE_COMPLEX_TRANSITION
;
; MessageText:
;
; The system power state is transitioning from %2 to %3 but could enter %4.
;
STATUS_SYSTEM_POWERSTATE_COMPLEX_TRANSITION EQU 040000031h    

;
; MessageId: STATUS_ACCESS_AUDIT_BY_POLICY
;
; MessageText:
;
; Access to %1 is monitored by policy rule %2.
;
STATUS_ACCESS_AUDIT_BY_POLICY    EQU 040000032h    

;
; MessageId: STATUS_ABANDON_HIBERFILE
;
; MessageText:
;
; A valid hibernation file has been invalidated and should be abandoned.
;
STATUS_ABANDON_HIBERFILE         EQU 040000033h

;
; MessageId: STATUS_BIZRULES_NOT_ENABLED
;
; MessageText:
;
; Business rule scripts are disabled for the calling application.
;
STATUS_BIZRULES_NOT_ENABLED      EQU 040000034h

;
; MessageId: STATUS_FT_READ_FROM_COPY
;
; MessageText:
;
; The specified copy of the requested data was successfully read.
;
STATUS_FT_READ_FROM_COPY         EQU 040000035h

;
; MessageId: STATUS_IMAGE_AT_DIFFERENT_BASE
;
; MessageText:
;
; {Image Relocated}
; An image file was mapped at a different address from the one specified in the image file but fixups will still be automatically performed on the image.
;
STATUS_IMAGE_AT_DIFFERENT_BASE   EQU 040000036h

;
; MessageId: DBG_REPLY_LATER
;
; MessageText:
;
; Debugger will reply later.
;
DBG_REPLY_LATER                  EQU 040010001h

;
; MessageId: DBG_UNABLE_TO_PROVIDE_HANDLE
;
; MessageText:
;
; Debugger cannot provide handle.
;
DBG_UNABLE_TO_PROVIDE_HANDLE     EQU 040010002h

;
; MessageId: DBG_TERMINATE_THREAD
;
; MessageText:
;
; Debugger terminated thread.
;
DBG_TERMINATE_THREAD             EQU 040010003h

;
; MessageId: DBG_TERMINATE_PROCESS
;
; MessageText:
;
; Debugger terminated process.
;
DBG_TERMINATE_PROCESS            EQU 040010004h

;
; MessageId: DBG_CONTROL_C
;
; MessageText:
;
; Debugger got control C.
;
DBG_CONTROL_C                    EQU 040010005h

;
; MessageId: DBG_PRINTEXCEPTION_C
;
; MessageText:
;
; Debugger printed exception on control C.
;
DBG_PRINTEXCEPTION_C             EQU 040010006h

;
; MessageId: DBG_RIPEXCEPTION
;
; MessageText:
;
; Debugger received RIP exception.
;
DBG_RIPEXCEPTION                 EQU 040010007h

;
; MessageId: DBG_CONTROL_BREAK
;
; MessageText:
;
; Debugger received control break.
;
DBG_CONTROL_BREAK                EQU 040010008h

;
; MessageId: DBG_COMMAND_EXCEPTION
;
; MessageText:
;
; Debugger command communication exception.
;
DBG_COMMAND_EXCEPTION            EQU 040010009h

;
; MessageId: STATUS_HEURISTIC_DAMAGE_POSSIBLE
;
; MessageText:
;
; The attempt to commit the Transaction completed, but it is possible that some portion of the transaction tree did not commit successfully due to heuristics.  Therefore it is possible that some data modified in the transaction may not have committed, resulting in transactional inconsistency.  If possible, check the consistency of the associated data.
;
STATUS_HEURISTIC_DAMAGE_POSSIBLE EQU 040190001h



;========================================================================
;
; Standard Warning values
;
;
; Note:  Do NOT use the value 0x80000000L, as this is a non-portable value
;        for the NT_SUCCESS macro. Warning values start with a code of 1.
;
;========================================================================

;
; MessageId: STATUS_GUARD_PAGE_VIOLATION
;
; MessageText:
;
; {EXCEPTION}
; Guard Page Exception
; A page of memory that marks the end of a data structure, such as a stack or an array, has been accessed.
;
STATUS_GUARD_PAGE_VIOLATION      EQU 080000001h

;
; MessageId: STATUS_DATATYPE_MISALIGNMENT
;
; MessageText:
;
; {EXCEPTION}
; Alignment Fault
; A datatype misalignment was detected in a load or store instruction.
;
STATUS_DATATYPE_MISALIGNMENT     EQU 080000002h

;
; MessageId: STATUS_BREAKPOINT
;
; MessageText:
;
; {EXCEPTION}
; Breakpoint
; A breakpoint has been reached.
;
STATUS_BREAKPOINT                EQU 080000003h

;
; MessageId: STATUS_SINGLE_STEP
;
; MessageText:
;
; {EXCEPTION}
; Single Step
; A single step or trace operation has just been completed.
;
STATUS_SINGLE_STEP               EQU 080000004h

;
; MessageId: STATUS_BUFFER_OVERFLOW
;
; MessageText:
;
; {Buffer Overflow}
; The data was too large to fit into the specified buffer.
;
STATUS_BUFFER_OVERFLOW           EQU 080000005h

;
; MessageId: STATUS_NO_MORE_FILES
;
; MessageText:
;
; {No More Files}
; No more files were found which match the file specification.
;
STATUS_NO_MORE_FILES             EQU 080000006h

;
; MessageId: STATUS_WAKE_SYSTEM_DEBUGGER
;
; MessageText:
;
; {Kernel Debugger Awakened}
; the system debugger was awakened by an interrupt.
;
STATUS_WAKE_SYSTEM_DEBUGGER      EQU 080000007h

;
; MessageId: STATUS_HANDLES_CLOSED
;
; MessageText:
;
; {Handles Closed}
; Handles to objects have been automatically closed as a result of the requested operation.
;
STATUS_HANDLES_CLOSED            EQU 08000000Ah

;
; MessageId: STATUS_NO_INHERITANCE
;
; MessageText:
;
; {Non-Inheritable ACL}
; An access control list (ACh contains no components that can be inherited.
;
STATUS_NO_INHERITANCE            EQU 08000000Bh

;
; MessageId: STATUS_GUID_SUBSTITUTION_MADE
;
; MessageText:
;
; {GUID Substitution}
; During the translation of a global identifier (GUID) to a Windows security ID (SID), no administratively-defined GUID prefix was found. A substitute prefix was used, which will not compromise system security. However, this may provide a more restrictive access than intended.
;
STATUS_GUID_SUBSTITUTION_MADE    EQU 08000000Ch

;
; MessageId: STATUS_PARTIAL_COPY
;
; MessageText:
;
; {Partial Copy}
; Due to protection conflicts not all the requested bytes could be copied.
;
STATUS_PARTIAL_COPY              EQU 08000000Dh

;
; MessageId: STATUS_DEVICE_PAPER_EMPTY
;
; MessageText:
;
; {Out of Paper}
; The printer is out of paper.
;
STATUS_DEVICE_PAPER_EMPTY        EQU 08000000Eh

;
; MessageId: STATUS_DEVICE_POWERED_OFF
;
; MessageText:
;
; {Device Power Is Off}
; The printer power has been turned off.
;
STATUS_DEVICE_POWERED_OFF        EQU 08000000Fh

;
; MessageId: STATUS_DEVICE_OFF_LINE
;
; MessageText:
;
; {Device Offline}
; The printer has been taken offline.
;
STATUS_DEVICE_OFF_LINE           EQU 080000010h

;
; MessageId: STATUS_DEVICE_BUSY
;
; MessageText:
;
; {Device Busy}
; The device is currently busy.
;
STATUS_DEVICE_BUSY               EQU 080000011h

;
; MessageId: STATUS_NO_MORE_EAS
;
; MessageText:
;
; {No More EAs}
; No more extended attributes (EAs) were found for the file.
;
STATUS_NO_MORE_EAS               EQU 080000012h

;
; MessageId: STATUS_INVALID_EA_NAME
;
; MessageText:
;
; {Illegal EA}
; The specified extended attribute (EA) name contains at least one illegal character.
;
STATUS_INVALID_EA_NAME           EQU 080000013h

;
; MessageId: STATUS_EA_LIST_INCONSISTENT
;
; MessageText:
;
; {Inconsistent EA List}
; The extended attribute (EA) list is inconsistent.
;
STATUS_EA_LIST_INCONSISTENT      EQU 080000014h

;
; MessageId: STATUS_INVALID_EA_FLAG
;
; MessageText:
;
; {Invalid EA Flag}
; An invalid extended attribute (EA) flag was set.
;
STATUS_INVALID_EA_FLAG           EQU 080000015h

;
; MessageId: STATUS_VERIFY_REQUIRED
;
; MessageText:
;
; {Verifying Disk}
; The media has changed and a verify operation is in progress so no reads or writes may be performed to the device, except those used in the verify operation.
;
STATUS_VERIFY_REQUIRED           EQU 080000016h

;
; MessageId: STATUS_EXTRANEOUS_INFORMATION
;
; MessageText:
;
; {Too Much Information}
; The specified access control list (ACh contained more information than was expected.
;
STATUS_EXTRANEOUS_INFORMATION    EQU 080000017h

;
; MessageId: STATUS_RXACT_COMMIT_NECESSARY
;
; MessageText:
;
; This warning level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted.
; The commit has NOT been completed, but has not been rolled back either (so it may still be committed if desired).
;
STATUS_RXACT_COMMIT_NECESSARY    EQU 080000018h

;
; MessageId: STATUS_NO_MORE_ENTRIES
;
; MessageText:
;
; {No More Entries}
; No more entries are available from an enumeration operation.
;
STATUS_NO_MORE_ENTRIES           EQU 08000001Ah

;
; MessageId: STATUS_FILEMARK_DETECTED
;
; MessageText:
;
; {Filemark Found}
; A filemark was detected.
;
STATUS_FILEMARK_DETECTED         EQU 08000001Bh

;
; MessageId: STATUS_MEDIA_CHANGED
;
; MessageText:
;
; {Media Changed}
; The media may have changed.
;
STATUS_MEDIA_CHANGED             EQU 08000001Ch

;
; MessageId: STATUS_BUS_RESET
;
; MessageText:
;
; {I/O Bus Reset}
; An I/O bus reset was detected.
;
STATUS_BUS_RESET                 EQU 08000001Dh

;
; MessageId: STATUS_END_OF_MEDIA
;
; MessageText:
;
; {End of Media}
; The end of the media was encountered.
;
STATUS_END_OF_MEDIA              EQU 08000001Eh

;
; MessageId: STATUS_BEGINNING_OF_MEDIA
;
; MessageText:
;
; Beginning of tape or partition has been detected.
;
STATUS_BEGINNING_OF_MEDIA        EQU 08000001Fh

;
; MessageId: STATUS_MEDIA_CHECK
;
; MessageText:
;
; {Media Changed}
; The media may have changed.
;
STATUS_MEDIA_CHECK               EQU 080000020h

;
; MessageId: STATUS_SETMARK_DETECTED
;
; MessageText:
;
; A tape access reached a setmark.
;
STATUS_SETMARK_DETECTED          EQU 080000021h

;
; MessageId: STATUS_NO_DATA_DETECTED
;
; MessageText:
;
; During a tape access, the end of the data written is reached.
;
STATUS_NO_DATA_DETECTED          EQU 080000022h

;
; MessageId: STATUS_REDIRECTOR_HAS_OPEN_HANDLES
;
; MessageText:
;
; The redirector is in use and cannot be unloaded.
;
STATUS_REDIRECTOR_HAS_OPEN_HANDLES EQU 080000023h

;
; MessageId: STATUS_SERVER_HAS_OPEN_HANDLES
;
; MessageText:
;
; The server is in use and cannot be unloaded.
;
STATUS_SERVER_HAS_OPEN_HANDLES   EQU 080000024h

;
; MessageId: STATUS_ALREADY_DISCONNECTED
;
; MessageText:
;
; The specified connection has already been disconnected.
;
STATUS_ALREADY_DISCONNECTED      EQU 080000025h

;
; MessageId: STATUS_LONGJUMP
;
; MessageText:
;
; A long jump has been executed.
;
STATUS_LONGJUMP                  EQU 080000026h

;
; MessageId: STATUS_CLEANER_CARTRIDGE_INSTALLED
;
; MessageText:
;
; A cleaner cartridge is present in the tape library.
;
STATUS_CLEANER_CARTRIDGE_INSTALLED EQU 080000027h

;
; MessageId: STATUS_PLUGPLAY_QUERY_VETOED
;
; MessageText:
;
; The Plug and Play query operation was not successful.
;
STATUS_PLUGPLAY_QUERY_VETOED     EQU 080000028h

;
; MessageId: STATUS_UNWIND_CONSOLIDATE
;
; MessageText:
;
; A frame consolidation has been executed.
;
STATUS_UNWIND_CONSOLIDATE        EQU 080000029h

;
; MessageId: STATUS_REGISTRY_HIVE_RECOVERED
;
; MessageText:
;
; {Registry Hive Recovered}
; Registry hive (file):
; %hs
; was corrupted and it has been recovered. Some data might have been lost.
;
STATUS_REGISTRY_HIVE_RECOVERED   EQU 08000002Ah

;
; MessageId: STATUS_DLL_MIGHT_BE_INSECURE
;
; MessageText:
;
; The application is attempting to run executable code from the module %hs. This may be insecure. An alternative, %hs, is available. Should the application use the secure module %hs?
;
STATUS_DLL_MIGHT_BE_INSECURE     EQU 08000002Bh

;
; MessageId: STATUS_DLL_MIGHT_BE_INCOMPATIBLE
;
; MessageText:
;
; The application is loading executable code from the module %hs. This is secure, but may be incompatible with previous releases of the operating system. An alternative, %hs, is available. Should the application use the secure module %hs?
;
STATUS_DLL_MIGHT_BE_INCOMPATIBLE EQU 08000002Ch

;
; MessageId: STATUS_STOPPED_ON_SYMLINK
;
; MessageText:
;
; The create operation stopped after reaching a symbolic link.
;
STATUS_STOPPED_ON_SYMLINK        EQU 08000002Dh

;
; MessageId: STATUS_CANNOT_GRANT_REQUESTED_OPLOCK
;
; MessageText:
;
; An oplock of the requested level cannot be granted.  An oplock of a lower level may be available.
;
STATUS_CANNOT_GRANT_REQUESTED_OPLOCK EQU 08000002Eh

;
; MessageId: STATUS_NO_ACE_CONDITION
;
; MessageText:
;
; {No ACE Condition}
; The specified access control entry (ACE) does not contain a condition.
;
STATUS_NO_ACE_CONDITION          EQU 08000002Fh

;
; MessageId: STATUS_DEVICE_SUPPORT_IN_PROGRESS
;
; MessageText:
;
; {Support Being Determined}
; Device's command support detection is in progress.
;
STATUS_DEVICE_SUPPORT_IN_PROGRESS EQU 080000030h

;
; MessageId: DBG_EXCEPTION_NOT_HANDLED
;
; MessageText:
;
; Debugger did not handle the exception.
;
DBG_EXCEPTION_NOT_HANDLED        EQU 080010001h

;
; MessageId: STATUS_CLUSTER_NODE_ALREADY_UP
;
; MessageText:
;
; The cluster node is already up.
;
STATUS_CLUSTER_NODE_ALREADY_UP   EQU 080130001h

;
; MessageId: STATUS_CLUSTER_NODE_ALREADY_DOWN
;
; MessageText:
;
; The cluster node is already down.
;
STATUS_CLUSTER_NODE_ALREADY_DOWN EQU 080130002h

;
; MessageId: STATUS_CLUSTER_NETWORK_ALREADY_ONLINE
;
; MessageText:
;
; The cluster network is already online.
;
STATUS_CLUSTER_NETWORK_ALREADY_ONLINE EQU 080130003h

;
; MessageId: STATUS_CLUSTER_NETWORK_ALREADY_OFFLINE
;
; MessageText:
;
; The cluster network is already offline.
;
STATUS_CLUSTER_NETWORK_ALREADY_OFFLINE EQU 080130004h

;
; MessageId: STATUS_CLUSTER_NODE_ALREADY_MEMBER
;
; MessageText:
;
; The cluster node is already a member of the cluster.
;
STATUS_CLUSTER_NODE_ALREADY_MEMBER EQU 080130005h

;
; MessageId: STATUS_FLT_BUFFER_TOO_SMALL
;
; MessageText:
;
; {Buffer too small}
; The buffer is too small to contain the entry. No information has been written to the buffer.
;
STATUS_FLT_BUFFER_TOO_SMALL      EQU 0801C0001h

;
; MessageId: STATUS_FVE_PARTIAL_METADATA
;
; MessageText:
;
; Volume Metadata read or write is incomplete.
;
STATUS_FVE_PARTIAL_METADATA      EQU 080210001h

;
; MessageId: STATUS_FVE_TRANSIENT_STATE
;
; MessageText:
;
; BitLocker encryption keys were ignored because the volume was in a transient state.
;
STATUS_FVE_TRANSIENT_STATE       EQU 080210002h



;========================================================================
;
;  Standard Error values
;
;========================================================================

;
; MessageId: STATUS_UNSUCCESSFUL
;
; MessageText:
;
; {Operation Failed}
; The requested operation was unsuccessful.
;
STATUS_UNSUCCESSFUL              EQU 0C0000001h

;
; MessageId: STATUS_NOT_IMPLEMENTED
;
; MessageText:
;
; {Not Implemented}
; The requested operation is not implemented.
;
STATUS_NOT_IMPLEMENTED           EQU 0C0000002h

;
; MessageId: STATUS_INVALID_INFO_CLASS
;
; MessageText:
;
; {Invalid Parameter}
; The specified information class is not a valid information class for the specified object.
;
STATUS_INVALID_INFO_CLASS        EQU 0C0000003h    ; ntsubauth

;
; MessageId: STATUS_INFO_LENGTH_MISMATCH
;
; MessageText:
;
; The specified information record length does not match the length required for the specified information class.
;
STATUS_INFO_LENGTH_MISMATCH      EQU 0C0000004h

;
; MessageId: STATUS_ACCESS_VIOLATION
;
; MessageText:
;
; The instruction at 0x%08lx referenced memory at 0x%08lx. The memory could not be %s.
;
STATUS_ACCESS_VIOLATION          EQU 0C0000005h

;
; MessageId: STATUS_IN_PAGE_ERROR
;
; MessageText:
;
; The instruction at 0x%p referenced memory at 0x%p. The required data was not placed into memory because of an I/O error status of 0x%x.
;
STATUS_IN_PAGE_ERROR             EQU 0C0000006h

;
; MessageId: STATUS_PAGEFILE_QUOTA
;
; MessageText:
;
; The pagefile quota for the process has been exhausted.
;
STATUS_PAGEFILE_QUOTA            EQU 0C0000007h

;
; MessageId: STATUS_INVALID_HANDLE
;
; MessageText:
;
; An invalid HANDLE was specified.
;
STATUS_INVALID_HANDLE            EQU 0C0000008h

;
; MessageId: STATUS_BAD_INITIAL_STACK
;
; MessageText:
;
; An invalid initial stack was specified in a call to NtCreateThread.
;
STATUS_BAD_INITIAL_STACK         EQU 0C0000009h

;
; MessageId: STATUS_BAD_INITIAL_PC
;
; MessageText:
;
; An invalid initial start address was specified in a call to NtCreateThread.
;
STATUS_BAD_INITIAL_PC            EQU 0C000000Ah

;
; MessageId: STATUS_INVALID_CID
;
; MessageText:
;
; An invalid Client ID was specified.
;
STATUS_INVALID_CID               EQU 0C000000Bh

;
; MessageId: STATUS_TIMER_NOT_CANCELED
;
; MessageText:
;
; An attempt was made to cancel or set a timer that has an associated APC and the subject thread is not the thread that originally set the timer with an associated APC routine.
;
STATUS_TIMER_NOT_CANCELED        EQU 0C000000Ch

;
; MessageId: STATUS_INVALID_PARAMETER
;
; MessageText:
;
; An invalid parameter was passed to a service or function.
;
STATUS_INVALID_PARAMETER         EQU 0C000000Dh

;
; MessageId: STATUS_NO_SUCH_DEVICE
;
; MessageText:
;
; A device which does not exist was specified.
;
STATUS_NO_SUCH_DEVICE            EQU 0C000000Eh

;
; MessageId: STATUS_NO_SUCH_FILE
;
; MessageText:
;
; {File Not Found}
; The file %hs does not exist.
;
STATUS_NO_SUCH_FILE              EQU 0C000000Fh

;
; MessageId: STATUS_INVALID_DEVICE_REQUEST
;
; MessageText:
;
; The specified request is not a valid operation for the target device.
;
STATUS_INVALID_DEVICE_REQUEST    EQU 0C0000010h

;
; MessageId: STATUS_END_OF_FILE
;
; MessageText:
;
; The end-of-file marker has been reached. There is no valid data in the file beyond this marker.
;
STATUS_END_OF_FILE               EQU 0C0000011h

;
; MessageId: STATUS_WRONG_VOLUME
;
; MessageText:
;
; {Wrong Volume}
; The wrong volume is in the drive.
; Please insert volume %hs into drive %hs.
;
STATUS_WRONG_VOLUME              EQU 0C0000012h

;
; MessageId: STATUS_NO_MEDIA_IN_DEVICE
;
; MessageText:
;
; {No Disk}
; There is no disk in the drive.
; Please insert a disk into drive %hs.
;
STATUS_NO_MEDIA_IN_DEVICE        EQU 0C0000013h

;
; MessageId: STATUS_UNRECOGNIZED_MEDIA
;
; MessageText:
;
; {Unknown Disk Format}
; The disk in drive %hs is not formatted properly.
; Please check the disk, and reformat if necessary.
;
STATUS_UNRECOGNIZED_MEDIA        EQU 0C0000014h

;
; MessageId: STATUS_NONEXISTENT_SECTOR
;
; MessageText:
;
; {Sector Not Found}
; The specified sector does not exist.
;
STATUS_NONEXISTENT_SECTOR        EQU 0C0000015h

;
; MessageId: STATUS_MORE_PROCESSING_REQUIRED
;
; MessageText:
;
; {Still Busy}
; The specified I/O request packet (IRP) cannot be disposed of because the I/O operation is not complete.
;
STATUS_MORE_PROCESSING_REQUIRED  EQU 0C0000016h

;
; MessageId: STATUS_NO_MEMORY
;
; MessageText:
;
; {Not Enough Quota}
; Not enough virtual memory or paging file quota is available to complete the specified operation.
;
STATUS_NO_MEMORY                 EQU 0C0000017h

;
; MessageId: STATUS_CONFLICTING_ADDRESSES
;
; MessageText:
;
; {Conflicting Address Range}
; The specified address range conflicts with the address space.
;
STATUS_CONFLICTING_ADDRESSES     EQU 0C0000018h

;
; MessageId: STATUS_NOT_MAPPED_VIEW
;
; MessageText:
;
; Address range to unmap is not a mapped view.
;
STATUS_NOT_MAPPED_VIEW           EQU 0C0000019h

;
; MessageId: STATUS_UNABLE_TO_FREE_VM
;
; MessageText:
;
; Virtual memory cannot be freed.
;
STATUS_UNABLE_TO_FREE_VM         EQU 0C000001Ah

;
; MessageId: STATUS_UNABLE_TO_DELETE_SECTION
;
; MessageText:
;
; Specified section cannot be deleted.
;
STATUS_UNABLE_TO_DELETE_SECTION  EQU 0C000001Bh

;
; MessageId: STATUS_INVALID_SYSTEM_SERVICE
;
; MessageText:
;
; An invalid system service was specified in a system service call.
;
STATUS_INVALID_SYSTEM_SERVICE    EQU 0C000001Ch

;
; MessageId: STATUS_ILLEGAL_INSTRUCTION
;
; MessageText:
;
; {EXCEPTION}
; Illegal Instruction
; An attempt was made to execute an illegal instruction.
;
STATUS_ILLEGAL_INSTRUCTION       EQU 0C000001Dh

;
; MessageId: STATUS_INVALID_LOCK_SEQUENCE
;
; MessageText:
;
; {Invalid Lock Sequence}
; An attempt was made to execute an invalid lock sequence.
;
STATUS_INVALID_LOCK_SEQUENCE     EQU 0C000001Eh

;
; MessageId: STATUS_INVALID_VIEW_SIZE
;
; MessageText:
;
; {Invalid Mapping}
; An attempt was made to create a view for a section which is bigger than the section.
;
STATUS_INVALID_VIEW_SIZE         EQU 0C000001Fh

;
; MessageId: STATUS_INVALID_FILE_FOR_SECTION
;
; MessageText:
;
; {Bad File}
; The attributes of the specified mapping file for a section of memory cannot be read.
;
STATUS_INVALID_FILE_FOR_SECTION  EQU 0C0000020h

;
; MessageId: STATUS_ALREADY_COMMITTED
;
; MessageText:
;
; {Already Committed}
; The specified address range is already committed.
;
STATUS_ALREADY_COMMITTED         EQU 0C0000021h

;
; MessageId: STATUS_ACCESS_DENIED
;
; MessageText:
;
; {Access Denied}
; A process has requested access to an object, but has not been granted those access rights.
;
STATUS_ACCESS_DENIED             EQU 0C0000022h

;
; MessageId: STATUS_BUFFER_TOO_SMALL
;
; MessageText:
;
; {Buffer Too Small}
; The buffer is too small to contain the entry. No information has been written to the buffer.
;
STATUS_BUFFER_TOO_SMALL          EQU 0C0000023h

;
; MessageId: STATUS_OBJECT_TYPE_MISMATCH
;
; MessageText:
;
; {Wrong Type}
; There is a mismatch between the type of object required by the requested operation and the type of object that is specified in the request.
;
STATUS_OBJECT_TYPE_MISMATCH      EQU 0C0000024h

;
; MessageId: STATUS_NONCONTINUABLE_EXCEPTION
;
; MessageText:
;
; {EXCEPTION}
; Cannot Continue
; Windows cannot continue from this exception.
;
STATUS_NONCONTINUABLE_EXCEPTION  EQU 0C0000025h

;
; MessageId: STATUS_INVALID_DISPOSITION
;
; MessageText:
;
; An invalid exception disposition was returned by an exception handler.
;
STATUS_INVALID_DISPOSITION       EQU 0C0000026h

;
; MessageId: STATUS_UNWIND
;
; MessageText:
;
; Unwind exception code.
;
STATUS_UNWIND                    EQU 0C0000027h

;
; MessageId: STATUS_BAD_STACK
;
; MessageText:
;
; An invalid or unaligned stack was encountered during an unwind operation.
;
STATUS_BAD_STACK                 EQU 0C0000028h

;
; MessageId: STATUS_INVALID_UNWIND_TARGET
;
; MessageText:
;
; An invalid unwind target was encountered during an unwind operation.
;
STATUS_INVALID_UNWIND_TARGET     EQU 0C0000029h

;
; MessageId: STATUS_NOT_LOCKED
;
; MessageText:
;
; An attempt was made to unlock a page of memory which was not locked.
;
STATUS_NOT_LOCKED                EQU 0C000002Ah

;
; MessageId: STATUS_PARITY_ERROR
;
; MessageText:
;
; Device parity error on I/O operation.
;
STATUS_PARITY_ERROR              EQU 0C000002Bh

;
; MessageId: STATUS_UNABLE_TO_DECOMMIT_VM
;
; MessageText:
;
; An attempt was made to decommit uncommitted virtual memory.
;
STATUS_UNABLE_TO_DECOMMIT_VM     EQU 0C000002Ch

;
; MessageId: STATUS_NOT_COMMITTED
;
; MessageText:
;
; An attempt was made to change the attributes on memory that has not been committed.
;
STATUS_NOT_COMMITTED             EQU 0C000002Dh

;
; MessageId: STATUS_INVALID_PORT_ATTRIBUTES
;
; MessageText:
;
; Invalid Object Attributes specified to NtCreatePort or invalid Port Attributes specified to NtConnectPort
;
STATUS_INVALID_PORT_ATTRIBUTES   EQU 0C000002Eh

;
; MessageId: STATUS_PORT_MESSAGE_TOO_LONG
;
; MessageText:
;
; Length of message passed to NtRequestPort or NtRequestWaitReplyPort was longer than the maximum message allowed by the port.
;
STATUS_PORT_MESSAGE_TOO_LONG     EQU 0C000002Fh

;
; MessageId: STATUS_INVALID_PARAMETER_MIX
;
; MessageText:
;
; An invalid combination of parameters was specified.
;
STATUS_INVALID_PARAMETER_MIX     EQU 0C0000030h

;
; MessageId: STATUS_INVALID_QUOTA_LOWER
;
; MessageText:
;
; An attempt was made to lower a quota limit below the current usage.
;
STATUS_INVALID_QUOTA_LOWER       EQU 0C0000031h

;
; MessageId: STATUS_DISK_CORRUPT_ERROR
;
; MessageText:
;
; {Corrupt Disk}
; The file system structure on the disk is corrupt and unusable.
; Please run the Chkdsk utility on the volume %hs.
;
STATUS_DISK_CORRUPT_ERROR        EQU 0C0000032h

;
; MessageId: STATUS_OBJECT_NAME_INVALID
;
; MessageText:
;
; Object Name invalid.
;
STATUS_OBJECT_NAME_INVALID       EQU 0C0000033h

;
; MessageId: STATUS_OBJECT_NAME_NOT_FOUND
;
; MessageText:
;
; Object Name not found.
;
STATUS_OBJECT_NAME_NOT_FOUND     EQU 0C0000034h

;
; MessageId: STATUS_OBJECT_NAME_COLLISION
;
; MessageText:
;
; Object Name already exists.
;
STATUS_OBJECT_NAME_COLLISION     EQU 0C0000035h

;
; MessageId: STATUS_PORT_DISCONNECTED
;
; MessageText:
;
; Attempt to send a message to a disconnected communication port.
;
STATUS_PORT_DISCONNECTED         EQU 0C0000037h

;
; MessageId: STATUS_DEVICE_ALREADY_ATTACHED
;
; MessageText:
;
; An attempt was made to attach to a device that was already attached to another device.
;
STATUS_DEVICE_ALREADY_ATTACHED   EQU 0C0000038h

;
; MessageId: STATUS_OBJECT_PATH_INVALID
;
; MessageText:
;
; Object Path Component was not a directory object.
;
STATUS_OBJECT_PATH_INVALID       EQU 0C0000039h

;
; MessageId: STATUS_OBJECT_PATH_NOT_FOUND
;
; MessageText:
;
; {Path Not Found}
; The path %hs does not exist.
;
STATUS_OBJECT_PATH_NOT_FOUND     EQU 0C000003Ah

;
; MessageId: STATUS_OBJECT_PATH_SYNTAX_BAD
;
; MessageText:
;
; Object Path Component was not a directory object.
;
STATUS_OBJECT_PATH_SYNTAX_BAD    EQU 0C000003Bh

;
; MessageId: STATUS_DATA_OVERRUN
;
; MessageText:
;
; {Data Overrun}
; A data overrun error occurred.
;
STATUS_DATA_OVERRUN              EQU 0C000003Ch

;
; MessageId: STATUS_DATA_LATE_ERROR
;
; MessageText:
;
; {Data Late}
; A data late error occurred.
;
STATUS_DATA_LATE_ERROR           EQU 0C000003Dh

;
; MessageId: STATUS_DATA_ERROR
;
; MessageText:
;
; {Data Error}
; An error in reading or writing data occurred.
;
STATUS_DATA_ERROR                EQU 0C000003Eh

;
; MessageId: STATUS_CRC_ERROR
;
; MessageText:
;
; {Bad CRC}
; A cyclic redundancy check (CRC) checksum error occurred.
;
STATUS_CRC_ERROR                 EQU 0C000003Fh

;
; MessageId: STATUS_SECTION_TOO_BIG
;
; MessageText:
;
; {Section Too Large}
; The specified section is too big to map the file.
;
STATUS_SECTION_TOO_BIG           EQU 0C0000040h

;
; MessageId: STATUS_PORT_CONNECTION_REFUSED
;
; MessageText:
;
; The NtConnectPort request is refused.
;
STATUS_PORT_CONNECTION_REFUSED   EQU 0C0000041h

;
; MessageId: STATUS_INVALID_PORT_HANDLE
;
; MessageText:
;
; The type of port handle is invalid for the operation requested.
;
STATUS_INVALID_PORT_HANDLE       EQU 0C0000042h

;
; MessageId: STATUS_SHARING_VIOLATION
;
; MessageText:
;
; A file cannot be opened because the share access flags are incompatible.
;
STATUS_SHARING_VIOLATION         EQU 0C0000043h

;
; MessageId: STATUS_QUOTA_EXCEEDED
;
; MessageText:
;
; Insufficient quota exists to complete the operation
;
STATUS_QUOTA_EXCEEDED            EQU 0C0000044h

;
; MessageId: STATUS_INVALID_PAGE_PROTECTION
;
; MessageText:
;
; The specified page protection was not valid.
;
STATUS_INVALID_PAGE_PROTECTION   EQU 0C0000045h

;
; MessageId: STATUS_MUTANT_NOT_OWNED
;
; MessageText:
;
; An attempt to release a mutant object was made by a thread that was not the owner of the mutant object.
;
STATUS_MUTANT_NOT_OWNED          EQU 0C0000046h

;
; MessageId: STATUS_SEMAPHORE_LIMIT_EXCEEDED
;
; MessageText:
;
; An attempt was made to release a semaphore such that its maximum count would have been exceeded.
;
STATUS_SEMAPHORE_LIMIT_EXCEEDED  EQU 0C0000047h

;
; MessageId: STATUS_PORT_ALREADY_SET
;
; MessageText:
;
; An attempt to set a process's DebugPort or ExceptionPort was made, but a port already exists in the process or an attempt to set a file's CompletionPort made, but a port was already set in the file or an attempt to set an ALPC port's associated completion port was made, but it is already set.
;
STATUS_PORT_ALREADY_SET          EQU 0C0000048h

;
; MessageId: STATUS_SECTION_NOT_IMAGE
;
; MessageText:
;
; An attempt was made to query image information on a section which does not map an image.
;
STATUS_SECTION_NOT_IMAGE         EQU 0C0000049h

;
; MessageId: STATUS_SUSPEND_COUNT_EXCEEDED
;
; MessageText:
;
; An attempt was made to suspend a thread whose suspend count was at its maximum.
;
STATUS_SUSPEND_COUNT_EXCEEDED    EQU 0C000004Ah

;
; MessageId: STATUS_THREAD_IS_TERMINATING
;
; MessageText:
;
; An attempt was made to access a thread that has begun termination.
;
STATUS_THREAD_IS_TERMINATING     EQU 0C000004Bh

;
; MessageId: STATUS_BAD_WORKING_SET_LIMIT
;
; MessageText:
;
; An attempt was made to set the working set limit to an invalid value (minimum greater than maximum, etc).
;
STATUS_BAD_WORKING_SET_LIMIT     EQU 0C000004Ch

;
; MessageId: STATUS_INCOMPATIBLE_FILE_MAP
;
; MessageText:
;
; A section was created to map a file which is not compatible to an already existing section which maps the same file.
;
STATUS_INCOMPATIBLE_FILE_MAP     EQU 0C000004Dh

;
; MessageId: STATUS_SECTION_PROTECTION
;
; MessageText:
;
; A view to a section specifies a protection which is incompatible with the initial view's protection.
;
STATUS_SECTION_PROTECTION        EQU 0C000004Eh

;
; MessageId: STATUS_EAS_NOT_SUPPORTED
;
; MessageText:
;
; An operation involving EAs failed because the file system does not support EAs.
;
STATUS_EAS_NOT_SUPPORTED         EQU 0C000004Fh

;
; MessageId: STATUS_EA_TOO_LARGE
;
; MessageText:
;
; An EA operation failed because EA set is too large.
;
STATUS_EA_TOO_LARGE              EQU 0C0000050h

;
; MessageId: STATUS_NONEXISTENT_EA_ENTRY
;
; MessageText:
;
; An EA operation failed because the name or EA index is invalid.
;
STATUS_NONEXISTENT_EA_ENTRY      EQU 0C0000051h

;
; MessageId: STATUS_NO_EAS_ON_FILE
;
; MessageText:
;
; The file for which EAs were requested has no EAs.
;
STATUS_NO_EAS_ON_FILE            EQU 0C0000052h

;
; MessageId: STATUS_EA_CORRUPT_ERROR
;
; MessageText:
;
; The EA is corrupt and non-readable.
;
STATUS_EA_CORRUPT_ERROR          EQU 0C0000053h

;
; MessageId: STATUS_FILE_LOCK_CONFLICT
;
; MessageText:
;
; A requested read/write cannot be granted due to a conflicting file lock.
;
STATUS_FILE_LOCK_CONFLICT        EQU 0C0000054h

;
; MessageId: STATUS_LOCK_NOT_GRANTED
;
; MessageText:
;
; A requested file lock cannot be granted due to other existing locks.
;
STATUS_LOCK_NOT_GRANTED          EQU 0C0000055h

;
; MessageId: STATUS_DELETE_PENDING
;
; MessageText:
;
; A non close operation has been requested of a file object with a delete pending.
;
STATUS_DELETE_PENDING            EQU 0C0000056h

;
; MessageId: STATUS_CTL_FILE_NOT_SUPPORTED
;
; MessageText:
;
; An attempt was made to set the control attribute on a file. This attribute is not supported in the target file system.
;
STATUS_CTL_FILE_NOT_SUPPORTED    EQU 0C0000057h

;
; MessageId: STATUS_UNKNOWN_REVISION
;
; MessageText:
;
; Indicates a revision number encountered or specified is not one known by the service. It may be a more recent revision than the service is aware of.
;
STATUS_UNKNOWN_REVISION          EQU 0C0000058h

;
; MessageId: STATUS_REVISION_MISMATCH
;
; MessageText:
;
; Indicates two revision levels are incompatible.
;
STATUS_REVISION_MISMATCH         EQU 0C0000059h

;
; MessageId: STATUS_INVALID_OWNER
;
; MessageText:
;
; Indicates a particular Security ID may not be assigned as the owner of an object.
;
STATUS_INVALID_OWNER             EQU 0C000005Ah

;
; MessageId: STATUS_INVALID_PRIMARY_GROUP
;
; MessageText:
;
; Indicates a particular Security ID may not be assigned as the primary group of an object.
;
STATUS_INVALID_PRIMARY_GROUP     EQU 0C000005Bh

;
; MessageId: STATUS_NO_IMPERSONATION_TOKEN
;
; MessageText:
;
; An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client.
;
STATUS_NO_IMPERSONATION_TOKEN    EQU 0C000005Ch

;
; MessageId: STATUS_CANT_DISABLE_MANDATORY
;
; MessageText:
;
; A mandatory group may not be disabled.
;
STATUS_CANT_DISABLE_MANDATORY    EQU 0C000005Dh

;
; MessageId: STATUS_NO_LOGON_SERVERS
;
; MessageText:
;
; There are currently no logon servers available to service the logon request.
;
STATUS_NO_LOGON_SERVERS          EQU 0C000005Eh

;
; MessageId: STATUS_NO_SUCH_LOGON_SESSION
;
; MessageText:
;
; A specified logon session does not exist. It may already have been terminated.
;
STATUS_NO_SUCH_LOGON_SESSION     EQU 0C000005Fh

;
; MessageId: STATUS_NO_SUCH_PRIVILEGE
;
; MessageText:
;
; A specified privilege does not exist.
;
STATUS_NO_SUCH_PRIVILEGE         EQU 0C0000060h

;
; MessageId: STATUS_PRIVILEGE_NOT_HELD
;
; MessageText:
;
; A required privilege is not held by the client.
;
STATUS_PRIVILEGE_NOT_HELD        EQU 0C0000061h

;
; MessageId: STATUS_INVALID_ACCOUNT_NAME
;
; MessageText:
;
; The name provided is not a properly formed account name.
;
STATUS_INVALID_ACCOUNT_NAME      EQU 0C0000062h

;
; MessageId: STATUS_USER_EXISTS
;
; MessageText:
;
; The specified account already exists.
;
STATUS_USER_EXISTS               EQU 0C0000063h

;
; MessageId: STATUS_NO_SUCH_USER
;
; MessageText:
;
; The specified account does not exist.
;
STATUS_NO_SUCH_USER              EQU 0C0000064h

;
; MessageId: STATUS_GROUP_EXISTS
;
; MessageText:
;
; The specified group already exists.
;
STATUS_GROUP_EXISTS              EQU 0C0000065h

;
; MessageId: STATUS_NO_SUCH_GROUP
;
; MessageText:
;
; The specified group does not exist.
;
STATUS_NO_SUCH_GROUP             EQU 0C0000066h

;
; MessageId: STATUS_MEMBER_IN_GROUP
;
; MessageText:
;
; The specified user account is already in the specified group account. Also used to indicate a group cannot be deleted because it contains a member.
;
STATUS_MEMBER_IN_GROUP           EQU 0C0000067h

;
; MessageId: STATUS_MEMBER_NOT_IN_GROUP
;
; MessageText:
;
; The specified user account is not a member of the specified group account.
;
STATUS_MEMBER_NOT_IN_GROUP       EQU 0C0000068h

;
; MessageId: STATUS_LAST_ADMIN
;
; MessageText:
;
; Indicates the requested operation would disable, delete or could prevent logon for an administration account.
; This is not allowed to prevent creating a situation in which the system cannot be administrated.
;
STATUS_LAST_ADMIN                EQU 0C0000069h

;
; MessageId: STATUS_WRONG_PASSWORD
;
; MessageText:
;
; When trying to update a password, this return status indicates that the value provided as the current password is not correct.
;
STATUS_WRONG_PASSWORD            EQU 0C000006Ah

;
; MessageId: STATUS_ILL_FORMED_PASSWORD
;
; MessageText:
;
; When trying to update a password, this return status indicates that the value provided for the new password contains values that are not allowed in passwords.
;
STATUS_ILL_FORMED_PASSWORD       EQU 0C000006Bh

;
; MessageId: STATUS_PASSWORD_RESTRICTION
;
; MessageText:
;
; When trying to update a password, this status indicates that some password update rule has been violated. For example, the password may not meet length criteria.
;
STATUS_PASSWORD_RESTRICTION      EQU 0C000006Ch

;
; MessageId: STATUS_LOGON_FAILURE
;
; MessageText:
;
; The attempted logon is invalid. This is either due to a bad username or authentication information.
;
STATUS_LOGON_FAILURE             EQU 0C000006Dh

;
; MessageId: STATUS_ACCOUNT_RESTRICTION
;
; MessageText:
;
; Indicates a referenced user name and authentication information are valid, but some user account restriction has prevented successful authentication (such as time-of-day restrictions).
;
STATUS_ACCOUNT_RESTRICTION       EQU 0C000006Eh

;
; MessageId: STATUS_INVALID_LOGON_HOURS
;
; MessageText:
;
; The user account has time restrictions and may not be logged onto at this time.
;
STATUS_INVALID_LOGON_HOURS       EQU 0C000006Fh

;
; MessageId: STATUS_INVALID_WORKSTATION
;
; MessageText:
;
; The user account is restricted such that it may not be used to log on from the source workstation.
;
STATUS_INVALID_WORKSTATION       EQU 0C0000070h

;
; MessageId: STATUS_PASSWORD_EXPIRED
;
; MessageText:
;
; The user account's password has expired.
;
STATUS_PASSWORD_EXPIRED          EQU 0C0000071h

;
; MessageId: STATUS_ACCOUNT_DISABLED
;
; MessageText:
;
; The referenced account is currently disabled and may not be logged on to.
;
STATUS_ACCOUNT_DISABLED          EQU 0C0000072h

;
; MessageId: STATUS_NONE_MAPPED
;
; MessageText:
;
; None of the information to be translated has been translated.
;
STATUS_NONE_MAPPED               EQU 0C0000073h

;
; MessageId: STATUS_TOO_MANY_LUIDS_REQUESTED
;
; MessageText:
;
; The number of LUIDs requested may not be allocated with a single allocation.
;
STATUS_TOO_MANY_LUIDS_REQUESTED  EQU 0C0000074h

;
; MessageId: STATUS_LUIDS_EXHAUSTED
;
; MessageText:
;
; Indicates there are no more LUIDs to allocate.
;
STATUS_LUIDS_EXHAUSTED           EQU 0C0000075h

;
; MessageId: STATUS_INVALID_SUB_AUTHORITY
;
; MessageText:
;
; Indicates the sub-authority value is invalid for the particular use.
;
STATUS_INVALID_SUB_AUTHORITY     EQU 0C0000076h

;
; MessageId: STATUS_INVALID_ACL
;
; MessageText:
;
; Indicates the ACL structure is not valid.
;
STATUS_INVALID_ACL               EQU 0C0000077h

;
; MessageId: STATUS_INVALID_SID
;
; MessageText:
;
; Indicates the SID structure is not valid.
;
STATUS_INVALID_SID               EQU 0C0000078h

;
; MessageId: STATUS_INVALID_SECURITY_DESCR
;
; MessageText:
;
; Indicates the SECURITY_DESCRIPTOR structure is not valid.
;
STATUS_INVALID_SECURITY_DESCR    EQU 0C0000079h

;
; MessageId: STATUS_PROCEDURE_NOT_FOUND
;
; MessageText:
;
; Indicates the specified procedure address cannot be found in the DLL.
;
STATUS_PROCEDURE_NOT_FOUND       EQU 0C000007Ah

;
; MessageId: STATUS_INVALID_IMAGE_FORMAT
;
; MessageText:
;
; {Bad Image}
; %hs is either not designed to run on Windows or it contains an error. Try installing the program again using the original installation media or contact your system administrator or the software vendor for support. Error status 0x%08lx.
;
STATUS_INVALID_IMAGE_FORMAT      EQU 0C000007Bh

;
; MessageId: STATUS_NO_TOKEN
;
; MessageText:
;
; An attempt was made to reference a token that doesn't exist.
; This is typically done by referencing the token associated with a thread when the thread is not impersonating a client.
;
STATUS_NO_TOKEN                  EQU 0C000007Ch

;
; MessageId: STATUS_BAD_INHERITANCE_ACL
;
; MessageText:
;
; Indicates that an attempt to build either an inherited ACL or ACE was not successful.
; This can be caused by a number of things. One of the more probable causes is the replacement of a CreatorId with an SID that didn't fit into the ACE or ACL.
;
STATUS_BAD_INHERITANCE_ACL       EQU 0C000007Dh

;
; MessageId: STATUS_RANGE_NOT_LOCKED
;
; MessageText:
;
; The range specified in NtUnlockFile was not locked.
;
STATUS_RANGE_NOT_LOCKED          EQU 0C000007Eh

;
; MessageId: STATUS_DISK_FULL
;
; MessageText:
;
; An operation failed because the disk was full.
; If this is a thinly provisioned volume the physical storage backing this volume has been exhausted.
;
STATUS_DISK_FULL                 EQU 0C000007Fh

;
; MessageId: STATUS_SERVER_DISABLED
;
; MessageText:
;
; The GUID allocation server is [already] disabled at the moment.
;
STATUS_SERVER_DISABLED           EQU 0C0000080h

;
; MessageId: STATUS_SERVER_NOT_DISABLED
;
; MessageText:
;
; The GUID allocation server is [already] enabled at the moment.
;
STATUS_SERVER_NOT_DISABLED       EQU 0C0000081h

;
; MessageId: STATUS_TOO_MANY_GUIDS_REQUESTED
;
; MessageText:
;
; Too many GUIDs were requested from the allocation server at once.
;
STATUS_TOO_MANY_GUIDS_REQUESTED  EQU 0C0000082h

;
; MessageId: STATUS_GUIDS_EXHAUSTED
;
; MessageText:
;
; The GUIDs could not be allocated because the Authority Agent was exhausted.
;
STATUS_GUIDS_EXHAUSTED           EQU 0C0000083h

;
; MessageId: STATUS_INVALID_ID_AUTHORITY
;
; MessageText:
;
; The value provided was an invalid value for an identifier authority.
;
STATUS_INVALID_ID_AUTHORITY      EQU 0C0000084h

;
; MessageId: STATUS_AGENTS_EXHAUSTED
;
; MessageText:
;
; There are no more authority agent values available for the given identifier authority value.
;
STATUS_AGENTS_EXHAUSTED          EQU 0C0000085h

;
; MessageId: STATUS_INVALID_VOLUME_LABEL
;
; MessageText:
;
; An invalid volume label has been specified.
;
STATUS_INVALID_VOLUME_LABEL      EQU 0C0000086h

;
; MessageId: STATUS_SECTION_NOT_EXTENDED
;
; MessageText:
;
; A mapped section could not be extended.
;
STATUS_SECTION_NOT_EXTENDED      EQU 0C0000087h

;
; MessageId: STATUS_NOT_MAPPED_DATA
;
; MessageText:
;
; Specified section to flush does not map a data file.
;
STATUS_NOT_MAPPED_DATA           EQU 0C0000088h

;
; MessageId: STATUS_RESOURCE_DATA_NOT_FOUND
;
; MessageText:
;
; Indicates the specified image file did not contain a resource section.
;
STATUS_RESOURCE_DATA_NOT_FOUND   EQU 0C0000089h

;
; MessageId: STATUS_RESOURCE_TYPE_NOT_FOUND
;
; MessageText:
;
; Indicates the specified resource type cannot be found in the image file.
;
STATUS_RESOURCE_TYPE_NOT_FOUND   EQU 0C000008Ah

;
; MessageId: STATUS_RESOURCE_NAME_NOT_FOUND
;
; MessageText:
;
; Indicates the specified resource name cannot be found in the image file.
;
STATUS_RESOURCE_NAME_NOT_FOUND   EQU 0C000008Bh

;
; MessageId: STATUS_ARRAY_BOUNDS_EXCEEDED
;
; MessageText:
;
; {EXCEPTION}
; Array bounds exceeded.
;
STATUS_ARRAY_BOUNDS_EXCEEDED     EQU 0C000008Ch

;
; MessageId: STATUS_FLOAT_DENORMAL_OPERAND
;
; MessageText:
;
; {EXCEPTION}
; Floating-point denormal operand.
;
STATUS_FLOAT_DENORMAL_OPERAND    EQU 0C000008Dh

;
; MessageId: STATUS_FLOAT_DIVIDE_BY_ZERO
;
; MessageText:
;
; {EXCEPTION}
; Floating-point division by zero.
;
STATUS_FLOAT_DIVIDE_BY_ZERO      EQU 0C000008Eh

;
; MessageId: STATUS_FLOAT_INEXACT_RESULT
;
; MessageText:
;
; {EXCEPTION}
; Floating-point inexact result.
;
STATUS_FLOAT_INEXACT_RESULT      EQU 0C000008Fh

;
; MessageId: STATUS_FLOAT_INVALID_OPERATION
;
; MessageText:
;
; {EXCEPTION}
; Floating-point invalid operation.
;
STATUS_FLOAT_INVALID_OPERATION   EQU 0C0000090h

;
; MessageId: STATUS_FLOAT_OVERFLOW
;
; MessageText:
;
; {EXCEPTION}
; Floating-point overflow.
;
STATUS_FLOAT_OVERFLOW            EQU 0C0000091h

;
; MessageId: STATUS_FLOAT_STACK_CHECK
;
; MessageText:
;
; {EXCEPTION}
; Floating-point stack check.
;
STATUS_FLOAT_STACK_CHECK         EQU 0C0000092h

;
; MessageId: STATUS_FLOAT_UNDERFLOW
;
; MessageText:
;
; {EXCEPTION}
; Floating-point underflow.
;
STATUS_FLOAT_UNDERFLOW           EQU 0C0000093h

;
; MessageId: STATUS_INTEGER_DIVIDE_BY_ZERO
;
; MessageText:
;
; {EXCEPTION}
; Integer division by zero.
;
STATUS_INTEGER_DIVIDE_BY_ZERO    EQU 0C0000094h

;
; MessageId: STATUS_INTEGER_OVERFLOW
;
; MessageText:
;
; {EXCEPTION}
; Integer overflow.
;
STATUS_INTEGER_OVERFLOW          EQU 0C0000095h

;
; MessageId: STATUS_PRIVILEGED_INSTRUCTION
;
; MessageText:
;
; {EXCEPTION}
; Privileged instruction.
;
STATUS_PRIVILEGED_INSTRUCTION    EQU 0C0000096h

;
; MessageId: STATUS_TOO_MANY_PAGING_FILES
;
; MessageText:
;
; An attempt was made to install more paging files than the system supports.
;
STATUS_TOO_MANY_PAGING_FILES     EQU 0C0000097h

;
; MessageId: STATUS_FILE_INVALID
;
; MessageText:
;
; The volume for a file has been externally altered such that the opened file is no longer valid.
;
STATUS_FILE_INVALID              EQU 0C0000098h

;
; MessageId: STATUS_ALLOTTED_SPACE_EXCEEDED
;
; MessageText:
;
; When a block of memory is allotted for future updates, such as the memory allocated to hold discretionary access control and primary group information, successive updates may exceed the amount of memory originally allotted.
; Since quota may already have been charged to several processes which have handles to the object, it is not reasonable to alter the size of the allocated memory.
; Instead, a request that requires more memory than has been allotted must fail and the STATUS_ALLOTED_SPACE_EXCEEDED error returned.
;
STATUS_ALLOTTED_SPACE_EXCEEDED   EQU 0C0000099h

;
; MessageId: STATUS_INSUFFICIENT_RESOURCES
;
; MessageText:
;
; Insufficient system resources exist to complete the API.
;
STATUS_INSUFFICIENT_RESOURCES    EQU 0C000009Ah

;
; MessageId: STATUS_DFS_EXIT_PATH_FOUND
;
; MessageText:
;
; An attempt has been made to open a DFS exit path control file.
;
STATUS_DFS_EXIT_PATH_FOUND       EQU 0C000009Bh

;
; MessageId: STATUS_DEVICE_DATA_ERROR
;
; MessageText:
;
;  STATUS_DEVICE_DATA_ERROR
;
STATUS_DEVICE_DATA_ERROR         EQU 0C000009Ch

;
; MessageId: STATUS_DEVICE_NOT_CONNECTED
;
; MessageText:
;
;  STATUS_DEVICE_NOT_CONNECTED
;
STATUS_DEVICE_NOT_CONNECTED      EQU 0C000009Dh

;
; MessageId: STATUS_DEVICE_POWER_FAILURE
;
; MessageText:
;
;  STATUS_DEVICE_POWER_FAILURE
;
STATUS_DEVICE_POWER_FAILURE      EQU 0C000009Eh

;
; MessageId: STATUS_FREE_VM_NOT_AT_BASE
;
; MessageText:
;
; Virtual memory cannot be freed as base address is not the base of the region and a region size of zero was specified.
;
STATUS_FREE_VM_NOT_AT_BASE       EQU 0C000009Fh

;
; MessageId: STATUS_MEMORY_NOT_ALLOCATED
;
; MessageText:
;
; An attempt was made to free virtual memory which is not allocated.
;
STATUS_MEMORY_NOT_ALLOCATED      EQU 0C00000A0h

;
; MessageId: STATUS_WORKING_SET_QUOTA
;
; MessageText:
;
; The working set is not big enough to allow the requested pages to be locked.
;
STATUS_WORKING_SET_QUOTA         EQU 0C00000A1h

;
; MessageId: STATUS_MEDIA_WRITE_PROTECTED
;
; MessageText:
;
; {Write Protect Error}
; The disk cannot be written to because it is write protected. Please remove the write protection from the volume %hs in drive %hs.
;
STATUS_MEDIA_WRITE_PROTECTED     EQU 0C00000A2h

;
; MessageId: STATUS_DEVICE_NOT_READY
;
; MessageText:
;
; {Drive Not Ready}
; The drive is not ready for use; its door may be open. Please check drive %hs and make sure that a disk is inserted and that the drive door is closed.
;
STATUS_DEVICE_NOT_READY          EQU 0C00000A3h

;
; MessageId: STATUS_INVALID_GROUP_ATTRIBUTES
;
; MessageText:
;
; The specified attributes are invalid, or incompatible with the attributes for the group as a whole.
;
STATUS_INVALID_GROUP_ATTRIBUTES  EQU 0C00000A4h

;
; MessageId: STATUS_BAD_IMPERSONATION_LEVEL
;
; MessageText:
;
; A specified impersonation level is invalid.
; Also used to indicate a required impersonation level was not provided.
;
STATUS_BAD_IMPERSONATION_LEVEL   EQU 0C00000A5h

;
; MessageId: STATUS_CANT_OPEN_ANONYMOUS
;
; MessageText:
;
; An attempt was made to open an Anonymous level token.
; Anonymous tokens may not be opened.
;
STATUS_CANT_OPEN_ANONYMOUS       EQU 0C00000A6h

;
; MessageId: STATUS_BAD_VALIDATION_CLASS
;
; MessageText:
;
; The validation information class requested was invalid.
;
STATUS_BAD_VALIDATION_CLASS      EQU 0C00000A7h

;
; MessageId: STATUS_BAD_TOKEN_TYPE
;
; MessageText:
;
; The type of a token object is inappropriate for its attempted use.
;
STATUS_BAD_TOKEN_TYPE            EQU 0C00000A8h

;
; MessageId: STATUS_BAD_MASTER_BOOT_RECORD
;
; MessageText:
;
; The type of a token object is inappropriate for its attempted use.
;
STATUS_BAD_MASTER_BOOT_RECORD    EQU 0C00000A9h

;
; MessageId: STATUS_INSTRUCTION_MISALIGNMENT
;
; MessageText:
;
; An attempt was made to execute an instruction at an unaligned address and the host system does not support unaligned instruction references.
;
STATUS_INSTRUCTION_MISALIGNMENT  EQU 0C00000AAh

;
; MessageId: STATUS_INSTANCE_NOT_AVAILABLE
;
; MessageText:
;
; The maximum named pipe instance count has been reached.
;
STATUS_INSTANCE_NOT_AVAILABLE    EQU 0C00000ABh

;
; MessageId: STATUS_PIPE_NOT_AVAILABLE
;
; MessageText:
;
; An instance of a named pipe cannot be found in the listening state.
;
STATUS_PIPE_NOT_AVAILABLE        EQU 0C00000ACh

;
; MessageId: STATUS_INVALID_PIPE_STATE
;
; MessageText:
;
; The named pipe is not in the connected or closing state.
;
STATUS_INVALID_PIPE_STATE        EQU 0C00000ADh

;
; MessageId: STATUS_PIPE_BUSY
;
; MessageText:
;
; The specified pipe is set to complete operations and there are current I/O operations queued so it cannot be changed to queue operations.
;
STATUS_PIPE_BUSY                 EQU 0C00000AEh

;
; MessageId: STATUS_ILLEGAL_FUNCTION
;
; MessageText:
;
; The specified handle is not open to the server end of the named pipe.
;
STATUS_ILLEGAL_FUNCTION          EQU 0C00000AFh

;
; MessageId: STATUS_PIPE_DISCONNECTED
;
; MessageText:
;
; The specified named pipe is in the disconnected state.
;
STATUS_PIPE_DISCONNECTED         EQU 0C00000B0h

;
; MessageId: STATUS_PIPE_CLOSING
;
; MessageText:
;
; The specified named pipe is in the closing state.
;
STATUS_PIPE_CLOSING              EQU 0C00000B1h

;
; MessageId: STATUS_PIPE_CONNECTED
;
; MessageText:
;
; The specified named pipe is in the connected state.
;
STATUS_PIPE_CONNECTED            EQU 0C00000B2h

;
; MessageId: STATUS_PIPE_LISTENING
;
; MessageText:
;
; The specified named pipe is in the listening state.
;
STATUS_PIPE_LISTENING            EQU 0C00000B3h

;
; MessageId: STATUS_INVALID_READ_MODE
;
; MessageText:
;
; The specified named pipe is not in message mode.
;
STATUS_INVALID_READ_MODE         EQU 0C00000B4h

;
; MessageId: STATUS_IO_TIMEOUT
;
; MessageText:
;
; {Device Timeout}
; The specified I/O operation on %hs was not completed before the time-out period expired.
;
STATUS_IO_TIMEOUT                EQU 0C00000B5h

;
; MessageId: STATUS_FILE_FORCED_CLOSED
;
; MessageText:
;
; The specified file has been closed by another process.
;
STATUS_FILE_FORCED_CLOSED        EQU 0C00000B6h

;
; MessageId: STATUS_PROFILING_NOT_STARTED
;
; MessageText:
;
; Profiling not started.
;
STATUS_PROFILING_NOT_STARTED     EQU 0C00000B7h

;
; MessageId: STATUS_PROFILING_NOT_STOPPED
;
; MessageText:
;
; Profiling not stopped.
;
STATUS_PROFILING_NOT_STOPPED     EQU 0C00000B8h

;
; MessageId: STATUS_COULD_NOT_INTERPRET
;
; MessageText:
;
; The passed ACL did not contain the minimum required information.
;
STATUS_COULD_NOT_INTERPRET       EQU 0C00000B9h

;
; MessageId: STATUS_FILE_IS_A_DIRECTORY
;
; MessageText:
;
; The file that was specified as a target is a directory and the caller specified that it could be anything but a directory.
;
STATUS_FILE_IS_A_DIRECTORY       EQU 0C00000BAh

;
; Network specific errors.
;
;
;
; MessageId: STATUS_NOT_SUPPORTED
;
; MessageText:
;
; The request is not supported.
;
STATUS_NOT_SUPPORTED             EQU 0C00000BBh

;
; MessageId: STATUS_REMOTE_NOT_LISTENING
;
; MessageText:
;
; This remote computer is not listening.
;
STATUS_REMOTE_NOT_LISTENING      EQU 0C00000BCh

;
; MessageId: STATUS_DUPLICATE_NAME
;
; MessageText:
;
; A duplicate name exists on the network.
;
STATUS_DUPLICATE_NAME            EQU 0C00000BDh

;
; MessageId: STATUS_BAD_NETWORK_PATH
;
; MessageText:
;
; The network path cannot be located.
;
STATUS_BAD_NETWORK_PATH          EQU 0C00000BEh

;
; MessageId: STATUS_NETWORK_BUSY
;
; MessageText:
;
; The network is busy.
;
STATUS_NETWORK_BUSY              EQU 0C00000BFh

;
; MessageId: STATUS_DEVICE_DOES_NOT_EXIST
;
; MessageText:
;
; This device does not exist.
;
STATUS_DEVICE_DOES_NOT_EXIST     EQU 0C00000C0h

;
; MessageId: STATUS_TOO_MANY_COMMANDS
;
; MessageText:
;
; The network BIOS command limit has been reached.
;
STATUS_TOO_MANY_COMMANDS         EQU 0C00000C1h

;
; MessageId: STATUS_ADAPTER_HARDWARE_ERROR
;
; MessageText:
;
; An I/O adapter hardware error has occurred.
;
STATUS_ADAPTER_HARDWARE_ERROR    EQU 0C00000C2h

;
; MessageId: STATUS_INVALID_NETWORK_RESPONSE
;
; MessageText:
;
; The network responded incorrectly.
;
STATUS_INVALID_NETWORK_RESPONSE  EQU 0C00000C3h

;
; MessageId: STATUS_UNEXPECTED_NETWORK_ERROR
;
; MessageText:
;
; An unexpected network error occurred.
;
STATUS_UNEXPECTED_NETWORK_ERROR  EQU 0C00000C4h

;
; MessageId: STATUS_BAD_REMOTE_ADAPTER
;
; MessageText:
;
; The remote adapter is not compatible.
;
STATUS_BAD_REMOTE_ADAPTER        EQU 0C00000C5h

;
; MessageId: STATUS_PRINT_QUEUE_FULL
;
; MessageText:
;
; The printer queue is full.
;
STATUS_PRINT_QUEUE_FULL          EQU 0C00000C6h

;
; MessageId: STATUS_NO_SPOOL_SPACE
;
; MessageText:
;
; Space to store the file waiting to be printed is not available on the server.
;
STATUS_NO_SPOOL_SPACE            EQU 0C00000C7h

;
; MessageId: STATUS_PRINT_CANCELLED
;
; MessageText:
;
; The requested print file has been canceled.
;
STATUS_PRINT_CANCELLED           EQU 0C00000C8h

;
; MessageId: STATUS_NETWORK_NAME_DELETED
;
; MessageText:
;
; The network name was deleted.
;
STATUS_NETWORK_NAME_DELETED      EQU 0C00000C9h

;
; MessageId: STATUS_NETWORK_ACCESS_DENIED
;
; MessageText:
;
; Network access is denied.
;
STATUS_NETWORK_ACCESS_DENIED     EQU 0C00000CAh

;
; MessageId: STATUS_BAD_DEVICE_TYPE
;
; MessageText:
;
; {Incorrect Network Resource Type}
; The specified device type (LPT, for example) conflicts with the actual device type on the remote resource.
;
STATUS_BAD_DEVICE_TYPE           EQU 0C00000CBh

;
; MessageId: STATUS_BAD_NETWORK_NAME
;
; MessageText:
;
; {Network Name Not Found}
; The specified share name cannot be found on the remote server.
;
STATUS_BAD_NETWORK_NAME          EQU 0C00000CCh

;
; MessageId: STATUS_TOO_MANY_NAMES
;
; MessageText:
;
; The name limit for the local computer network adapter card was exceeded.
;
STATUS_TOO_MANY_NAMES            EQU 0C00000CDh

;
; MessageId: STATUS_TOO_MANY_SESSIONS
;
; MessageText:
;
; The network BIOS session limit was exceeded.
;
STATUS_TOO_MANY_SESSIONS         EQU 0C00000CEh

;
; MessageId: STATUS_SHARING_PAUSED
;
; MessageText:
;
; File sharing has been temporarily paused.
;
STATUS_SHARING_PAUSED            EQU 0C00000CFh

;
; MessageId: STATUS_REQUEST_NOT_ACCEPTED
;
; MessageText:
;
; No more connections can be made to this remote computer at this time because there are already as many connections as the computer can accept.
;
STATUS_REQUEST_NOT_ACCEPTED      EQU 0C00000D0h

;
; MessageId: STATUS_REDIRECTOR_PAUSED
;
; MessageText:
;
; Print or disk redirection is temporarily paused.
;
STATUS_REDIRECTOR_PAUSED         EQU 0C00000D1h

;
; MessageId: STATUS_NET_WRITE_FAULT
;
; MessageText:
;
; A network data fault occurred.
;
STATUS_NET_WRITE_FAULT           EQU 0C00000D2h

;
; MessageId: STATUS_PROFILING_AT_LIMIT
;
; MessageText:
;
; The number of active profiling objects is at the maximum and no more may be started.
;
STATUS_PROFILING_AT_LIMIT        EQU 0C00000D3h

;
; MessageId: STATUS_NOT_SAME_DEVICE
;
; MessageText:
;
; {Incorrect Volume}
; The target file of a rename request is located on a different device than the source of the rename request.
;
STATUS_NOT_SAME_DEVICE           EQU 0C00000D4h

;
; MessageId: STATUS_FILE_RENAMED
;
; MessageText:
;
; The file specified has been renamed and thus cannot be modified.
;
STATUS_FILE_RENAMED              EQU 0C00000D5h

;
; MessageId: STATUS_VIRTUAL_CIRCUIT_CLOSED
;
; MessageText:
;
; {Network Request Timeout}
; The session with a remote server has been disconnected because the time-out interval for a request has expired.
;
STATUS_VIRTUAL_CIRCUIT_CLOSED    EQU 0C00000D6h

;
; MessageId: STATUS_NO_SECURITY_ON_OBJECT
;
; MessageText:
;
; Indicates an attempt was made to operate on the security of an object that does not have security associated with it.
;
STATUS_NO_SECURITY_ON_OBJECT     EQU 0C00000D7h

;
; MessageId: STATUS_CANT_WAIT
;
; MessageText:
;
; Used to indicate that an operation cannot continue without blocking for I/O.
;
STATUS_CANT_WAIT                 EQU 0C00000D8h

;
; MessageId: STATUS_PIPE_EMPTY
;
; MessageText:
;
; Used to indicate that a read operation was done on an empty pipe.
;
STATUS_PIPE_EMPTY                EQU 0C00000D9h

;
; MessageId: STATUS_CANT_ACCESS_DOMAIN_INFO
;
; MessageText:
;
; Configuration information could not be read from the domain controller, either because the machine is unavailable, or access has been denied.
;
STATUS_CANT_ACCESS_DOMAIN_INFO   EQU 0C00000DAh

;
; MessageId: STATUS_CANT_TERMINATE_SELF
;
; MessageText:
;
; Indicates that a thread attempted to terminate itself by default (called NtTerminateThread with NULh and it was the last thread in the current process.
;
STATUS_CANT_TERMINATE_SELF       EQU 0C00000DBh

;
; MessageId: STATUS_INVALID_SERVER_STATE
;
; MessageText:
;
; Indicates the Sam Server was in the wrong state to perform the desired operation.
;
STATUS_INVALID_SERVER_STATE      EQU 0C00000DCh

;
; MessageId: STATUS_INVALID_DOMAIN_STATE
;
; MessageText:
;
; Indicates the Domain was in the wrong state to perform the desired operation.
;
STATUS_INVALID_DOMAIN_STATE      EQU 0C00000DDh

;
; MessageId: STATUS_INVALID_DOMAIN_ROLE
;
; MessageText:
;
; This operation is only allowed for the Primary Domain Controller of the domain.
;
STATUS_INVALID_DOMAIN_ROLE       EQU 0C00000DEh

;
; MessageId: STATUS_NO_SUCH_DOMAIN
;
; MessageText:
;
; The specified Domain did not exist.
;
STATUS_NO_SUCH_DOMAIN            EQU 0C00000DFh

;
; MessageId: STATUS_DOMAIN_EXISTS
;
; MessageText:
;
; The specified Domain already exists.
;
STATUS_DOMAIN_EXISTS             EQU 0C00000E0h

;
; MessageId: STATUS_DOMAIN_LIMIT_EXCEEDED
;
; MessageText:
;
; An attempt was made to exceed the limit on the number of domains per server for this release.
;
STATUS_DOMAIN_LIMIT_EXCEEDED     EQU 0C00000E1h

;
; MessageId: STATUS_OPLOCK_NOT_GRANTED
;
; MessageText:
;
; Error status returned when oplock request is denied.
;
STATUS_OPLOCK_NOT_GRANTED        EQU 0C00000E2h

;
; MessageId: STATUS_INVALID_OPLOCK_PROTOCOL
;
; MessageText:
;
; Error status returned when an invalid oplock acknowledgment is received by a file system.
;
STATUS_INVALID_OPLOCK_PROTOCOL   EQU 0C00000E3h

;
; MessageId: STATUS_INTERNAL_DB_CORRUPTION
;
; MessageText:
;
; This error indicates that the requested operation cannot be completed due to a catastrophic media failure or on-disk data structure corruption.
;
STATUS_INTERNAL_DB_CORRUPTION    EQU 0C00000E4h

;
; MessageId: STATUS_INTERNAL_ERROR
;
; MessageText:
;
; An internal error occurred.
;
STATUS_INTERNAL_ERROR            EQU 0C00000E5h

;
; MessageId: STATUS_GENERIC_NOT_MAPPED
;
; MessageText:
;
; Indicates generic access types were contained in an access mask which should already be mapped to non-generic access types.
;
STATUS_GENERIC_NOT_MAPPED        EQU 0C00000E6h

;
; MessageId: STATUS_BAD_DESCRIPTOR_FORMAT
;
; MessageText:
;
; Indicates a security descriptor is not in the necessary format (absolute or self-relative).
;
STATUS_BAD_DESCRIPTOR_FORMAT     EQU 0C00000E7h

;
; Status codes raised by the Cache Manager which must be considered as
; "expected" by its callers.
;
;
; MessageId: STATUS_INVALID_USER_BUFFER
;
; MessageText:
;
; An access to a user buffer failed at an "expected" point in time. This code is defined since the caller does not want to accept STATUS_ACCESS_VIOLATION in its filter.
;
STATUS_INVALID_USER_BUFFER       EQU 0C00000E8h

;
; MessageId: STATUS_UNEXPECTED_IO_ERROR
;
; MessageText:
;
; If an I/O error is returned which is not defined in the standard FsRtl filter, it is converted to the following error which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
;
STATUS_UNEXPECTED_IO_ERROR       EQU 0C00000E9h

;
; MessageId: STATUS_UNEXPECTED_MM_CREATE_ERR
;
; MessageText:
;
; If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
;
STATUS_UNEXPECTED_MM_CREATE_ERR  EQU 0C00000EAh

;
; MessageId: STATUS_UNEXPECTED_MM_MAP_ERROR
;
; MessageText:
;
; If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
;
STATUS_UNEXPECTED_MM_MAP_ERROR   EQU 0C00000EBh

;
; MessageId: STATUS_UNEXPECTED_MM_EXTEND_ERR
;
; MessageText:
;
; If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
;
STATUS_UNEXPECTED_MM_EXTEND_ERR  EQU 0C00000ECh

;
; MessageId: STATUS_NOT_LOGON_PROCESS
;
; MessageText:
;
; The requested action is restricted for use by logon processes only. The calling process has not registered as a logon process.
;
STATUS_NOT_LOGON_PROCESS         EQU 0C00000EDh

;
; MessageId: STATUS_LOGON_SESSION_EXISTS
;
; MessageText:
;
; An attempt has been made to start a new session manager or LSA logon session with an ID that is already in use.
;
STATUS_LOGON_SESSION_EXISTS      EQU 0C00000EEh

;
; MessageId: STATUS_INVALID_PARAMETER_1
;
; MessageText:
;
; An invalid parameter was passed to a service or function as the first argument.
;
STATUS_INVALID_PARAMETER_1       EQU 0C00000EFh

;
; MessageId: STATUS_INVALID_PARAMETER_2
;
; MessageText:
;
; An invalid parameter was passed to a service or function as the second argument.
;
STATUS_INVALID_PARAMETER_2       EQU 0C00000F0h

;
; MessageId: STATUS_INVALID_PARAMETER_3
;
; MessageText:
;
; An invalid parameter was passed to a service or function as the third argument.
;
STATUS_INVALID_PARAMETER_3       EQU 0C00000F1h

;
; MessageId: STATUS_INVALID_PARAMETER_4
;
; MessageText:
;
; An invalid parameter was passed to a service or function as the fourth argument.
;
STATUS_INVALID_PARAMETER_4       EQU 0C00000F2h

;
; MessageId: STATUS_INVALID_PARAMETER_5
;
; MessageText:
;
; An invalid parameter was passed to a service or function as the fifth argument.
;
STATUS_INVALID_PARAMETER_5       EQU 0C00000F3h

;
; MessageId: STATUS_INVALID_PARAMETER_6
;
; MessageText:
;
; An invalid parameter was passed to a service or function as the sixth argument.
;
STATUS_INVALID_PARAMETER_6       EQU 0C00000F4h

;
; MessageId: STATUS_INVALID_PARAMETER_7
;
; MessageText:
;
; An invalid parameter was passed to a service or function as the seventh argument.
;
STATUS_INVALID_PARAMETER_7       EQU 0C00000F5h

;
; MessageId: STATUS_INVALID_PARAMETER_8
;
; MessageText:
;
; An invalid parameter was passed to a service or function as the eighth argument.
;
STATUS_INVALID_PARAMETER_8       EQU 0C00000F6h

;
; MessageId: STATUS_INVALID_PARAMETER_9
;
; MessageText:
;
; An invalid parameter was passed to a service or function as the ninth argument.
;
STATUS_INVALID_PARAMETER_9       EQU 0C00000F7h

;
; MessageId: STATUS_INVALID_PARAMETER_10
;
; MessageText:
;
; An invalid parameter was passed to a service or function as the tenth argument.
;
STATUS_INVALID_PARAMETER_10      EQU 0C00000F8h

;
; MessageId: STATUS_INVALID_PARAMETER_11
;
; MessageText:
;
; An invalid parameter was passed to a service or function as the eleventh argument.
;
STATUS_INVALID_PARAMETER_11      EQU 0C00000F9h

;
; MessageId: STATUS_INVALID_PARAMETER_12
;
; MessageText:
;
; An invalid parameter was passed to a service or function as the twelfth argument.
;
STATUS_INVALID_PARAMETER_12      EQU 0C00000FAh

;
; MessageId: STATUS_REDIRECTOR_NOT_STARTED
;
; MessageText:
;
; An attempt was made to access a network file, but the network software was not yet started.
;
STATUS_REDIRECTOR_NOT_STARTED    EQU 0C00000FBh

;
; MessageId: STATUS_REDIRECTOR_STARTED
;
; MessageText:
;
; An attempt was made to start the redirector, but the redirector has already been started.
;
STATUS_REDIRECTOR_STARTED        EQU 0C00000FCh

;
; MessageId: STATUS_STACK_OVERFLOW
;
; MessageText:
;
; A new guard page for the stack cannot be created.
;
STATUS_STACK_OVERFLOW            EQU 0C00000FDh

;
; MessageId: STATUS_NO_SUCH_PACKAGE
;
; MessageText:
;
; A specified authentication package is unknown.
;
STATUS_NO_SUCH_PACKAGE           EQU 0C00000FEh

;
; MessageId: STATUS_BAD_FUNCTION_TABLE
;
; MessageText:
;
; A malformed function table was encountered during an unwind operation.
;
STATUS_BAD_FUNCTION_TABLE        EQU 0C00000FFh

;
; MessageId: STATUS_VARIABLE_NOT_FOUND
;
; MessageText:
;
; Indicates the specified environment variable name was not found in the specified environment block.
;
STATUS_VARIABLE_NOT_FOUND        EQU 0C0000100h

;
; MessageId: STATUS_DIRECTORY_NOT_EMPTY
;
; MessageText:
;
; Indicates that the directory trying to be deleted is not empty.
;
STATUS_DIRECTORY_NOT_EMPTY       EQU 0C0000101h

;
; MessageId: STATUS_FILE_CORRUPT_ERROR
;
; MessageText:
;
; {Corrupt File}
; The file or directory %hs is corrupt and unreadable.
; Please run the Chkdsk utility.
;
STATUS_FILE_CORRUPT_ERROR        EQU 0C0000102h

;
; MessageId: STATUS_NOT_A_DIRECTORY
;
; MessageText:
;
; A requested opened file is not a directory.
;
STATUS_NOT_A_DIRECTORY           EQU 0C0000103h

;
; MessageId: STATUS_BAD_LOGON_SESSION_STATE
;
; MessageText:
;
; The logon session is not in a state that is consistent with the requested operation.
;
STATUS_BAD_LOGON_SESSION_STATE   EQU 0C0000104h

;
; MessageId: STATUS_LOGON_SESSION_COLLISION
;
; MessageText:
;
; An internal LSA error has occurred. An authentication package has requested the creation of a Logon Session but the ID of an already existing Logon Session has been specified.
;
STATUS_LOGON_SESSION_COLLISION   EQU 0C0000105h

;
; MessageId: STATUS_NAME_TOO_LONG
;
; MessageText:
;
; A specified name string is too long for its intended use.
;
STATUS_NAME_TOO_LONG             EQU 0C0000106h

;
; MessageId: STATUS_FILES_OPEN
;
; MessageText:
;
; The user attempted to force close the files on a redirected drive, but there were opened files on the drive, and the user did not specify a sufficient level of force.
;
STATUS_FILES_OPEN                EQU 0C0000107h

;
; MessageId: STATUS_CONNECTION_IN_USE
;
; MessageText:
;
; The user attempted to force close the files on a redirected drive, but there were opened directories on the drive, and the user did not specify a sufficient level of force.
;
STATUS_CONNECTION_IN_USE         EQU 0C0000108h

;
; MessageId: STATUS_MESSAGE_NOT_FOUND
;
; MessageText:
;
; RtlFindMessage could not locate the requested message ID in the message table resource.
;
STATUS_MESSAGE_NOT_FOUND         EQU 0C0000109h

;
; MessageId: STATUS_PROCESS_IS_TERMINATING
;
; MessageText:
;
; An attempt was made to access an exiting process.
;
STATUS_PROCESS_IS_TERMINATING    EQU 0C000010Ah

;
; MessageId: STATUS_INVALID_LOGON_TYPE
;
; MessageText:
;
; Indicates an invalid value has been provided for the LogonType requested.
;
STATUS_INVALID_LOGON_TYPE        EQU 0C000010Bh

;
; MessageId: STATUS_NO_GUID_TRANSLATION
;
; MessageText:
;
; Indicates that an attempt was made to assign protection to a file system file or directory and one of the SIDs in the security descriptor could not be translated into a GUID that could be stored by the file system.
; This causes the protection attempt to fail, which may cause a file creation attempt to fail.
;
STATUS_NO_GUID_TRANSLATION       EQU 0C000010Ch

;
; MessageId: STATUS_CANNOT_IMPERSONATE
;
; MessageText:
;
; Indicates that an attempt has been made to impersonate via a named pipe that has not yet been read from.
;
STATUS_CANNOT_IMPERSONATE        EQU 0C000010Dh

;
; MessageId: STATUS_IMAGE_ALREADY_LOADED
;
; MessageText:
;
; Indicates that the specified image is already loaded.
;
STATUS_IMAGE_ALREADY_LOADED      EQU 0C000010Eh


;
; ============================================================
; NOTE: The following ABIOS error code should be reserved on
;       non ABIOS kernel. Eventually, I will remove the ifdef
;       ABIOS.
; ============================================================
;
;
; MessageId: STATUS_ABIOS_NOT_PRESENT
;
; MessageText:
;
;  STATUS_ABIOS_NOT_PRESENT
;
STATUS_ABIOS_NOT_PRESENT         EQU 0C000010Fh

;
; MessageId: STATUS_ABIOS_LID_NOT_EXIST
;
; MessageText:
;
;  STATUS_ABIOS_LID_NOT_EXIST
;
STATUS_ABIOS_LID_NOT_EXIST       EQU 0C0000110h

;
; MessageId: STATUS_ABIOS_LID_ALREADY_OWNED
;
; MessageText:
;
;  STATUS_ABIOS_LID_ALREADY_OWNED
;
STATUS_ABIOS_LID_ALREADY_OWNED   EQU 0C0000111h

;
; MessageId: STATUS_ABIOS_NOT_LID_OWNER
;
; MessageText:
;
;  STATUS_ABIOS_NOT_LID_OWNER
;
STATUS_ABIOS_NOT_LID_OWNER       EQU 0C0000112h

;
; MessageId: STATUS_ABIOS_INVALID_COMMAND
;
; MessageText:
;
;  STATUS_ABIOS_INVALID_COMMAND
;
STATUS_ABIOS_INVALID_COMMAND     EQU 0C0000113h

;
; MessageId: STATUS_ABIOS_INVALID_LID
;
; MessageText:
;
;  STATUS_ABIOS_INVALID_LID
;
STATUS_ABIOS_INVALID_LID         EQU 0C0000114h

;
; MessageId: STATUS_ABIOS_SELECTOR_NOT_AVAILABLE
;
; MessageText:
;
;  STATUS_ABIOS_SELECTOR_NOT_AVAILABLE
;
STATUS_ABIOS_SELECTOR_NOT_AVAILABLE EQU 0C0000115h

;
; MessageId: STATUS_ABIOS_INVALID_SELECTOR
;
; MessageText:
;
;  STATUS_ABIOS_INVALID_SELECTOR
;
STATUS_ABIOS_INVALID_SELECTOR    EQU 0C0000116h

;
; MessageId: STATUS_NO_LDT
;
; MessageText:
;
; Indicates that an attempt was made to change the size of the LDT for a process that has no LDT.
;
STATUS_NO_LDT                    EQU 0C0000117h

;
; MessageId: STATUS_INVALID_LDT_SIZE
;
; MessageText:
;
; Indicates that an attempt was made to grow an LDT by setting its size, or that the size was not an even number of selectors.
;
STATUS_INVALID_LDT_SIZE          EQU 0C0000118h

;
; MessageId: STATUS_INVALID_LDT_OFFSET
;
; MessageText:
;
; Indicates that the starting value for the LDT information was not an integral multiple of the selector size.
;
STATUS_INVALID_LDT_OFFSET        EQU 0C0000119h

;
; MessageId: STATUS_INVALID_LDT_DESCRIPTOR
;
; MessageText:
;
; Indicates that the user supplied an invalid descriptor when trying to set up Ldt descriptors.
;
STATUS_INVALID_LDT_DESCRIPTOR    EQU 0C000011Ah

;
; MessageId: STATUS_INVALID_IMAGE_NE_FORMAT
;
; MessageText:
;
; The specified image file did not have the correct format. It appears to be NE format.
;
STATUS_INVALID_IMAGE_NE_FORMAT   EQU 0C000011Bh

;
; MessageId: STATUS_RXACT_INVALID_STATE
;
; MessageText:
;
; Indicates that the transaction state of a registry sub-tree is incompatible with the requested operation. For example, a request has been made to start a new transaction with one already in progress, or a request has been made to apply a transaction when one is not currently in progress.
;
STATUS_RXACT_INVALID_STATE       EQU 0C000011Ch

;
; MessageId: STATUS_RXACT_COMMIT_FAILURE
;
; MessageText:
;
; Indicates an error has occurred during a registry transaction commit. The database has been left in an unknown, but probably inconsistent, state. The state of the registry transaction is left as COMMITTING.
;
STATUS_RXACT_COMMIT_FAILURE      EQU 0C000011Dh

;
; MessageId: STATUS_MAPPED_FILE_SIZE_ZERO
;
; MessageText:
;
; An attempt was made to map a file of size zero with the maximum size specified as zero.
;
STATUS_MAPPED_FILE_SIZE_ZERO     EQU 0C000011Eh

;
; MessageId: STATUS_TOO_MANY_OPENED_FILES
;
; MessageText:
;
; Too many files are opened on a remote server.
; This error should only be returned by the Windows redirector on a remote drive.
;
STATUS_TOO_MANY_OPENED_FILES     EQU 0C000011Fh

;
; MessageId: STATUS_CANCELLED
;
; MessageText:
;
; The I/O request was canceled.
;
STATUS_CANCELLED                 EQU 0C0000120h

;
; MessageId: STATUS_CANNOT_DELETE
;
; MessageText:
;
; An attempt has been made to remove a file or directory that cannot be deleted.
;
STATUS_CANNOT_DELETE             EQU 0C0000121h

;
; MessageId: STATUS_INVALID_COMPUTER_NAME
;
; MessageText:
;
; Indicates a name specified as a remote computer name is syntactically invalid.
;
STATUS_INVALID_COMPUTER_NAME     EQU 0C0000122h

;
; MessageId: STATUS_FILE_DELETED
;
; MessageText:
;
; An I/O request other than close was performed on a file after it has been deleted, which can only happen to a request which did not complete before the last handle was closed via NtClose.
;
STATUS_FILE_DELETED              EQU 0C0000123h

;
; MessageId: STATUS_SPECIAL_ACCOUNT
;
; MessageText:
;
; Indicates an operation has been attempted on a built-in (speciah SAM account which is incompatible with built-in accounts. For example, built-in accounts cannot be deleted.
;
STATUS_SPECIAL_ACCOUNT           EQU 0C0000124h

;
; MessageId: STATUS_SPECIAL_GROUP
;
; MessageText:
;
; The operation requested may not be performed on the specified group because it is a built-in special group.
;
STATUS_SPECIAL_GROUP             EQU 0C0000125h

;
; MessageId: STATUS_SPECIAL_USER
;
; MessageText:
;
; The operation requested may not be performed on the specified user because it is a built-in special user.
;
STATUS_SPECIAL_USER              EQU 0C0000126h

;
; MessageId: STATUS_MEMBERS_PRIMARY_GROUP
;
; MessageText:
;
; Indicates a member cannot be removed from a group because the group is currently the member's primary group.
;
STATUS_MEMBERS_PRIMARY_GROUP     EQU 0C0000127h

;
; MessageId: STATUS_FILE_CLOSED
;
; MessageText:
;
; An I/O request other than close and several other special case operations was attempted using a file object that had already been closed.
;
STATUS_FILE_CLOSED               EQU 0C0000128h

;
; MessageId: STATUS_TOO_MANY_THREADS
;
; MessageText:
;
; Indicates a process has too many threads to perform the requested action. For example, assignment of a primary token may only be performed when a process has zero or one threads.
;
STATUS_TOO_MANY_THREADS          EQU 0C0000129h

;
; MessageId: STATUS_THREAD_NOT_IN_PROCESS
;
; MessageText:
;
; An attempt was made to operate on a thread within a specific process, but the thread specified is not in the process specified.
;
STATUS_THREAD_NOT_IN_PROCESS     EQU 0C000012Ah

;
; MessageId: STATUS_TOKEN_ALREADY_IN_USE
;
; MessageText:
;
; An attempt was made to establish a token for use as a primary token but the token is already in use. A token can only be the primary token of one process at a time.
;
STATUS_TOKEN_ALREADY_IN_USE      EQU 0C000012Bh

;
; MessageId: STATUS_PAGEFILE_QUOTA_EXCEEDED
;
; MessageText:
;
; Page file quota was exceeded.
;
STATUS_PAGEFILE_QUOTA_EXCEEDED   EQU 0C000012Ch

;
; MessageId: STATUS_COMMITMENT_LIMIT
;
; MessageText:
;
; {Out of Virtual Memory}
; Your system is low on virtual memory. To ensure that Windows runs properly, increase the size of your virtual memory paging file. For more information, see Help.
;
STATUS_COMMITMENT_LIMIT          EQU 0C000012Dh

;
; MessageId: STATUS_INVALID_IMAGE_LE_FORMAT
;
; MessageText:
;
; The specified image file did not have the correct format, it appears to be LE format.
;
STATUS_INVALID_IMAGE_LE_FORMAT   EQU 0C000012Eh

;
; MessageId: STATUS_INVALID_IMAGE_NOT_MZ
;
; MessageText:
;
; The specified image file did not have the correct format, it did not have an initial MZ.
;
STATUS_INVALID_IMAGE_NOT_MZ      EQU 0C000012Fh

;
; MessageId: STATUS_INVALID_IMAGE_PROTECT
;
; MessageText:
;
; The specified image file did not have the correct format, it did not have a proper e_lfarlc in the MZ header.
;
STATUS_INVALID_IMAGE_PROTECT     EQU 0C0000130h

;
; MessageId: STATUS_INVALID_IMAGE_WIN_16
;
; MessageText:
;
; The specified image file did not have the correct format, it appears to be a 16-bit Windows image.
;
STATUS_INVALID_IMAGE_WIN_16      EQU 0C0000131h

;
; MessageId: STATUS_LOGON_SERVER_CONFLICT
;
; MessageText:
;
; The Netlogon service cannot start because another Netlogon service running in the domain conflicts with the specified role.
;
STATUS_LOGON_SERVER_CONFLICT     EQU 0C0000132h

;
; MessageId: STATUS_TIME_DIFFERENCE_AT_DC
;
; MessageText:
;
; The time at the Primary Domain Controller is different than the time at the Backup Domain Controller or member server by too large an amount.
;
STATUS_TIME_DIFFERENCE_AT_DC     EQU 0C0000133h

;
; MessageId: STATUS_SYNCHRONIZATION_REQUIRED
;
; MessageText:
;
; The SAM database on a Windows Server is significantly out of synchronization with the copy on the Domain Controller. A complete synchronization is required.
;
STATUS_SYNCHRONIZATION_REQUIRED  EQU 0C0000134h

;
; MessageId: STATUS_DLL_NOT_FOUND
;
; MessageText:
;
; The program can't start because %hs is missing from your computer. Try reinstalling the program to fix this problem.
;
STATUS_DLL_NOT_FOUND             EQU 0C0000135h

;
; MessageId: STATUS_OPEN_FAILED
;
; MessageText:
;
; The NtCreateFile API failed. This error should never be returned to an application, it is a place holder for the Windows Lan Manager Redirector to use in its internal error mapping routines.
;
STATUS_OPEN_FAILED               EQU 0C0000136h

;
; MessageId: STATUS_IO_PRIVILEGE_FAILED
;
; MessageText:
;
; {Privilege Failed}
; The I/O permissions for the process could not be changed.
;
STATUS_IO_PRIVILEGE_FAILED       EQU 0C0000137h

;
; MessageId: STATUS_ORDINAL_NOT_FOUND
;
; MessageText:
;
; {Ordinal Not Found}
; The ordinal %ld could not be located in the dynamic link library %hs.
;
STATUS_ORDINAL_NOT_FOUND         EQU 0C0000138h

;
; MessageId: STATUS_ENTRYPOINT_NOT_FOUND
;
; MessageText:
;
; {Entry Point Not Found}
; The procedure entry point %hs could not be located in the dynamic link library %hs.
;
STATUS_ENTRYPOINT_NOT_FOUND      EQU 0C0000139h

;
; MessageId: STATUS_CONTROL_C_EXIT
;
; MessageText:
;
; {Application Exit by CTRL+C}
; The application terminated as a result of a CTRL+C.
;
STATUS_CONTROL_C_EXIT            EQU 0C000013Ah

;
; MessageId: STATUS_LOCAL_DISCONNECT
;
; MessageText:
;
; {Virtual Circuit Closed}
; The network transport on your computer has closed a network connection. There may or may not be I/O requests outstanding.
;
STATUS_LOCAL_DISCONNECT          EQU 0C000013Bh

;
; MessageId: STATUS_REMOTE_DISCONNECT
;
; MessageText:
;
; {Virtual Circuit Closed}
; The network transport on a remote computer has closed a network connection. There may or may not be I/O requests outstanding.
;
STATUS_REMOTE_DISCONNECT         EQU 0C000013Ch

;
; MessageId: STATUS_REMOTE_RESOURCES
;
; MessageText:
;
; {Insufficient Resources on Remote Computer}
; The remote computer has insufficient resources to complete the network request. For instance, there may not be enough memory available on the remote computer to carry out the request at this time.
;
STATUS_REMOTE_RESOURCES          EQU 0C000013Dh

;
; MessageId: STATUS_LINK_FAILED
;
; MessageText:
;
; {Virtual Circuit Closed}
; An existing connection (virtual circuit) has been broken at the remote computer. There is probably something wrong with the network software protocol or the network hardware on the remote computer.
;
STATUS_LINK_FAILED               EQU 0C000013Eh

;
; MessageId: STATUS_LINK_TIMEOUT
;
; MessageText:
;
; {Virtual Circuit Closed}
; The network transport on your computer has closed a network connection because it had to wait too long for a response from the remote computer.
;
STATUS_LINK_TIMEOUT              EQU 0C000013Fh

;
; MessageId: STATUS_INVALID_CONNECTION
;
; MessageText:
;
; The connection handle given to the transport was invalid.
;
STATUS_INVALID_CONNECTION        EQU 0C0000140h

;
; MessageId: STATUS_INVALID_ADDRESS
;
; MessageText:
;
; The address handle given to the transport was invalid.
;
STATUS_INVALID_ADDRESS           EQU 0C0000141h

;
; MessageId: STATUS_DLL_INIT_FAILED
;
; MessageText:
;
; {DLL Initialization Failed}
; Initialization of the dynamic link library %hs failed. The process is terminating abnormally.
;
STATUS_DLL_INIT_FAILED           EQU 0C0000142h

;
; MessageId: STATUS_MISSING_SYSTEMFILE
;
; MessageText:
;
; {Missing System File}
; The required system file %hs is bad or missing.
;
STATUS_MISSING_SYSTEMFILE        EQU 0C0000143h

;
; MessageId: STATUS_UNHANDLED_EXCEPTION
;
; MessageText:
;
; {Application Error}
; The exception %s (0x%08lx) occurred in the application at location 0x%08lx.
;
STATUS_UNHANDLED_EXCEPTION       EQU 0C0000144h

;
; MessageId: STATUS_APP_INIT_FAILURE
;
; MessageText:
;
; {Application Error}
; The application was unable to start correctly (0x%lx). Click OK to close the application.
;
STATUS_APP_INIT_FAILURE          EQU 0C0000145h

;
; MessageId: STATUS_PAGEFILE_CREATE_FAILED
;
; MessageText:
;
; {Unable to Create Paging File}
; The creation of the paging file %hs failed (%lx). The requested size was %ld.
;
STATUS_PAGEFILE_CREATE_FAILED    EQU 0C0000146h

;
; MessageId: STATUS_NO_PAGEFILE
;
; MessageText:
;
; {No Paging File Specified}
; No paging file was specified in the system configuration.
;
STATUS_NO_PAGEFILE               EQU 0C0000147h

;
; MessageId: STATUS_INVALID_LEVEL
;
; MessageText:
;
; {Incorrect System Call Level}
; An invalid level was passed into the specified system call.
;
STATUS_INVALID_LEVEL             EQU 0C0000148h

;
; MessageId: STATUS_WRONG_PASSWORD_CORE
;
; MessageText:
;
; {Incorrect Password to LAN Manager Server}
; You specified an incorrect password to a LAN Manager 2.x or MS-NET server.
;
STATUS_WRONG_PASSWORD_CORE       EQU 0C0000149h

;
; MessageId: STATUS_ILLEGAL_FLOAT_CONTEXT
;
; MessageText:
;
; {EXCEPTION}
; A real-mode application issued a floating-point instruction and floating-point hardware is not present.
;
STATUS_ILLEGAL_FLOAT_CONTEXT     EQU 0C000014Ah

;
; MessageId: STATUS_PIPE_BROKEN
;
; MessageText:
;
; The pipe operation has failed because the other end of the pipe has been closed.
;
STATUS_PIPE_BROKEN               EQU 0C000014Bh

;
; MessageId: STATUS_REGISTRY_CORRUPT
;
; MessageText:
;
; {The Registry Is Corrupt}
; The structure of one of the files that contains Registry data is corrupt, or the image of the file in memory is corrupt, or the file could not be recovered because the alternate copy or log was absent or corrupt.
;
STATUS_REGISTRY_CORRUPT          EQU 0C000014Ch

;
; MessageId: STATUS_REGISTRY_IO_FAILED
;
; MessageText:
;
; An I/O operation initiated by the Registry failed unrecoverably. The Registry could not read in, or write out, or flush, one of the files that contain the system's image of the Registry.
;
STATUS_REGISTRY_IO_FAILED        EQU 0C000014Dh

;
; MessageId: STATUS_NO_EVENT_PAIR
;
; MessageText:
;
; An event pair synchronization operation was performed using the thread specific client/server event pair object, but no event pair object was associated with the thread.
;
STATUS_NO_EVENT_PAIR             EQU 0C000014Eh

;
; MessageId: STATUS_UNRECOGNIZED_VOLUME
;
; MessageText:
;
; The volume does not contain a recognized file system. Please make sure that all required file system drivers are loaded and that the volume is not corrupt.
;
STATUS_UNRECOGNIZED_VOLUME       EQU 0C000014Fh

;
; MessageId: STATUS_SERIAL_NO_DEVICE_INITED
;
; MessageText:
;
; No serial device was successfully initialized. The serial driver will unload.
;
STATUS_SERIAL_NO_DEVICE_INITED   EQU 0C0000150h

;
; MessageId: STATUS_NO_SUCH_ALIAS
;
; MessageText:
;
; The specified local group does not exist.
;
STATUS_NO_SUCH_ALIAS             EQU 0C0000151h

;
; MessageId: STATUS_MEMBER_NOT_IN_ALIAS
;
; MessageText:
;
; The specified account name is not a member of the group.
;
STATUS_MEMBER_NOT_IN_ALIAS       EQU 0C0000152h

;
; MessageId: STATUS_MEMBER_IN_ALIAS
;
; MessageText:
;
; The specified account name is already a member of the group.
;
STATUS_MEMBER_IN_ALIAS           EQU 0C0000153h

;
; MessageId: STATUS_ALIAS_EXISTS
;
; MessageText:
;
; The specified local group already exists.
;
STATUS_ALIAS_EXISTS              EQU 0C0000154h

;
; MessageId: STATUS_LOGON_NOT_GRANTED
;
; MessageText:
;
; A requested type of logon (e.g., Interactive, Network, Service) is not granted by the target system's local security policy.
; Please ask the system administrator to grant the necessary form of logon.
;
STATUS_LOGON_NOT_GRANTED         EQU 0C0000155h

;
; MessageId: STATUS_TOO_MANY_SECRETS
;
; MessageText:
;
; The maximum number of secrets that may be stored in a single system has been exceeded. The length and number of secrets is limited to satisfy United States State Department export restrictions.
;
STATUS_TOO_MANY_SECRETS          EQU 0C0000156h

;
; MessageId: STATUS_SECRET_TOO_LONG
;
; MessageText:
;
; The length of a secret exceeds the maximum length allowed. The length and number of secrets is limited to satisfy United States State Department export restrictions.
;
STATUS_SECRET_TOO_LONG           EQU 0C0000157h

;
; MessageId: STATUS_INTERNAL_DB_ERROR
;
; MessageText:
;
; The Local Security Authority (LSA) database contains an internal inconsistency.
;
STATUS_INTERNAL_DB_ERROR         EQU 0C0000158h

;
; MessageId: STATUS_FULLSCREEN_MODE
;
; MessageText:
;
; The requested operation cannot be performed in fullscreen mode.
;
STATUS_FULLSCREEN_MODE           EQU 0C0000159h

;
; MessageId: STATUS_TOO_MANY_CONTEXT_IDS
;
; MessageText:
;
; During a logon attempt, the user's security context accumulated too many security IDs. This is a very unusual situation. Remove the user from some global or local groups to reduce the number of security ids to incorporate into the security context.
;
STATUS_TOO_MANY_CONTEXT_IDS      EQU 0C000015Ah

;
; MessageId: STATUS_LOGON_TYPE_NOT_GRANTED
;
; MessageText:
;
; A user has requested a type of logon (e.g., interactive or network) that has not been granted. An administrator has control over who may logon interactively and through the network.
;
STATUS_LOGON_TYPE_NOT_GRANTED    EQU 0C000015Bh

;
; MessageId: STATUS_NOT_REGISTRY_FILE
;
; MessageText:
;
; The system has attempted to load or restore a file into the registry, and the specified file is not in the format of a registry file.
;
STATUS_NOT_REGISTRY_FILE         EQU 0C000015Ch

;
; MessageId: STATUS_NT_CROSS_ENCRYPTION_REQUIRED
;
; MessageText:
;
; An attempt was made to change a user password in the security account manager without providing the necessary Windows cross-encrypted password.
;
STATUS_NT_CROSS_ENCRYPTION_REQUIRED EQU 0C000015Dh

;
; MessageId: STATUS_DOMAIN_CTRLR_CONFIG_ERROR
;
; MessageText:
;
; A Windows Server has an incorrect configuration.
;
STATUS_DOMAIN_CTRLR_CONFIG_ERROR EQU 0C000015Eh

;
; MessageId: STATUS_FT_MISSING_MEMBER
;
; MessageText:
;
; An attempt was made to explicitly access the secondary copy of information via a device control to the Fault Tolerance driver and the secondary copy is not present in the system.
;
STATUS_FT_MISSING_MEMBER         EQU 0C000015Fh

;
; MessageId: STATUS_ILL_FORMED_SERVICE_ENTRY
;
; MessageText:
;
; A configuration registry node representing a driver service entry was ill-formed and did not contain required value entries.
;
STATUS_ILL_FORMED_SERVICE_ENTRY  EQU 0C0000160h

;
; MessageId: STATUS_ILLEGAL_CHARACTER
;
; MessageText:
;
; An illegal character was encountered. For a multi-byte character set this includes a lead byte without a succeeding trail byte. For the Unicode character set this includes the characters 0xFFFF and 0xFFFE.
;
STATUS_ILLEGAL_CHARACTER         EQU 0C0000161h

;
; MessageId: STATUS_UNMAPPABLE_CHARACTER
;
; MessageText:
;
; No mapping for the Unicode character exists in the target multi-byte code page.
;
STATUS_UNMAPPABLE_CHARACTER      EQU 0C0000162h

;
; MessageId: STATUS_UNDEFINED_CHARACTER
;
; MessageText:
;
; The Unicode character is not defined in the Unicode character set installed on the system.
;
STATUS_UNDEFINED_CHARACTER       EQU 0C0000163h

;
; MessageId: STATUS_FLOPPY_VOLUME
;
; MessageText:
;
; The paging file cannot be created on a floppy diskette.
;
STATUS_FLOPPY_VOLUME             EQU 0C0000164h

;
; MessageId: STATUS_FLOPPY_ID_MARK_NOT_FOUND
;
; MessageText:
;
; {Floppy Disk Error}
; While accessing a floppy disk, an ID address mark was not found.
;
STATUS_FLOPPY_ID_MARK_NOT_FOUND  EQU 0C0000165h

;
; MessageId: STATUS_FLOPPY_WRONG_CYLINDER
;
; MessageText:
;
; {Floppy Disk Error}
; While accessing a floppy disk, the track address from the sector ID field was found to be different than the track address maintained by the controller.
;
STATUS_FLOPPY_WRONG_CYLINDER     EQU 0C0000166h

;
; MessageId: STATUS_FLOPPY_UNKNOWN_ERROR
;
; MessageText:
;
; {Floppy Disk Error}
; The floppy disk controller reported an error that is not recognized by the floppy disk driver.
;
STATUS_FLOPPY_UNKNOWN_ERROR      EQU 0C0000167h

;
; MessageId: STATUS_FLOPPY_BAD_REGISTERS
;
; MessageText:
;
; {Floppy Disk Error}
; While accessing a floppy-disk, the controller returned inconsistent results via its registers.
;
STATUS_FLOPPY_BAD_REGISTERS      EQU 0C0000168h

;
; MessageId: STATUS_DISK_RECALIBRATE_FAILED
;
; MessageText:
;
; {Hard Disk Error}
; While accessing the hard disk, a recalibrate operation failed, even after retries.
;
STATUS_DISK_RECALIBRATE_FAILED   EQU 0C0000169h

;
; MessageId: STATUS_DISK_OPERATION_FAILED
;
; MessageText:
;
; {Hard Disk Error}
; While accessing the hard disk, a disk operation failed even after retries.
;
STATUS_DISK_OPERATION_FAILED     EQU 0C000016Ah

;
; MessageId: STATUS_DISK_RESET_FAILED
;
; MessageText:
;
; {Hard Disk Error}
; While accessing the hard disk, a disk controller reset was needed, but even that failed.
;
STATUS_DISK_RESET_FAILED         EQU 0C000016Bh

;
; MessageId: STATUS_SHARED_IRQ_BUSY
;
; MessageText:
;
; An attempt was made to open a device that was sharing an IRQ with other devices.
; At least one other device that uses that IRQ was already opened.
; Two concurrent opens of devices that share an IRQ and only work via interrupts is not supported for the particular bus type that the devices use.
;
STATUS_SHARED_IRQ_BUSY           EQU 0C000016Ch

;
; MessageId: STATUS_FT_ORPHANING
;
; MessageText:
;
; {FT Orphaning}
; A disk that is part of a fault-tolerant volume can no longer be accessed.
;
STATUS_FT_ORPHANING              EQU 0C000016Dh

;
; MessageId: STATUS_BIOS_FAILED_TO_CONNECT_INTERRUPT
;
; MessageText:
;
; The system bios failed to connect a system interrupt to the device or bus for which the device is connected.
;
STATUS_BIOS_FAILED_TO_CONNECT_INTERRUPT EQU 0C000016Eh

;
; MessageId: STATUS_PARTITION_FAILURE
;
; MessageText:
;
; Tape could not be partitioned.
;
STATUS_PARTITION_FAILURE         EQU 0C0000172h

;
; MessageId: STATUS_INVALID_BLOCK_LENGTH
;
; MessageText:
;
; When accessing a new tape of a multivolume partition, the current blocksize is incorrect.
;
STATUS_INVALID_BLOCK_LENGTH      EQU 0C0000173h

;
; MessageId: STATUS_DEVICE_NOT_PARTITIONED
;
; MessageText:
;
; Tape partition information could not be found when loading a tape.
;
STATUS_DEVICE_NOT_PARTITIONED    EQU 0C0000174h

;
; MessageId: STATUS_UNABLE_TO_LOCK_MEDIA
;
; MessageText:
;
; Attempt to lock the eject media mechanism fails.
;
STATUS_UNABLE_TO_LOCK_MEDIA      EQU 0C0000175h

;
; MessageId: STATUS_UNABLE_TO_UNLOAD_MEDIA
;
; MessageText:
;
; Unload media fails.
;
STATUS_UNABLE_TO_UNLOAD_MEDIA    EQU 0C0000176h

;
; MessageId: STATUS_EOM_OVERFLOW
;
; MessageText:
;
; Physical end of tape was detected.
;
STATUS_EOM_OVERFLOW              EQU 0C0000177h

;
; MessageId: STATUS_NO_MEDIA
;
; MessageText:
;
; {No Media}
; There is no media in the drive. Please insert media into drive %hs.
;
STATUS_NO_MEDIA                  EQU 0C0000178h

;
; MessageId: STATUS_NO_SUCH_MEMBER
;
; MessageText:
;
; A member could not be added to or removed from the local group because the member does not exist.
;
STATUS_NO_SUCH_MEMBER            EQU 0C000017Ah

;
; MessageId: STATUS_INVALID_MEMBER
;
; MessageText:
;
; A new member could not be added to a local group because the member has the wrong account type.
;
STATUS_INVALID_MEMBER            EQU 0C000017Bh

;
; MessageId: STATUS_KEY_DELETED
;
; MessageText:
;
; Illegal operation attempted on a registry key which has been marked for deletion.
;
STATUS_KEY_DELETED               EQU 0C000017Ch

;
; MessageId: STATUS_NO_LOG_SPACE
;
; MessageText:
;
; System could not allocate required space in a registry log.
;
STATUS_NO_LOG_SPACE              EQU 0C000017Dh

;
; MessageId: STATUS_TOO_MANY_SIDS
;
; MessageText:
;
; Too many Sids have been specified.
;
STATUS_TOO_MANY_SIDS             EQU 0C000017Eh

;
; MessageId: STATUS_LM_CROSS_ENCRYPTION_REQUIRED
;
; MessageText:
;
; An attempt was made to change a user password in the security account manager without providing the necessary LM cross-encrypted password.
;
STATUS_LM_CROSS_ENCRYPTION_REQUIRED EQU 0C000017Fh

;
; MessageId: STATUS_KEY_HAS_CHILDREN
;
; MessageText:
;
; An attempt was made to create a symbolic link in a registry key that already has subkeys or values.
;
STATUS_KEY_HAS_CHILDREN          EQU 0C0000180h

;
; MessageId: STATUS_CHILD_MUST_BE_VOLATILE
;
; MessageText:
;
; An attempt was made to create a Stable subkey under a Volatile parent key.
;
STATUS_CHILD_MUST_BE_VOLATILE    EQU 0C0000181h

;
; MessageId: STATUS_DEVICE_CONFIGURATION_ERROR
;
; MessageText:
;
; The I/O device is configured incorrectly or the configuration parameters to the driver are incorrect.
;
STATUS_DEVICE_CONFIGURATION_ERROR EQU 0C0000182h

;
; MessageId: STATUS_DRIVER_INTERNAL_ERROR
;
; MessageText:
;
; An error was detected between two drivers or within an I/O driver.
;
STATUS_DRIVER_INTERNAL_ERROR     EQU 0C0000183h

;
; MessageId: STATUS_INVALID_DEVICE_STATE
;
; MessageText:
;
; The device is not in a valid state to perform this request.
;
STATUS_INVALID_DEVICE_STATE      EQU 0C0000184h

;
; MessageId: STATUS_IO_DEVICE_ERROR
;
; MessageText:
;
; The I/O device reported an I/O error.
;
STATUS_IO_DEVICE_ERROR           EQU 0C0000185h

;
; MessageId: STATUS_DEVICE_PROTOCOL_ERROR
;
; MessageText:
;
; A protocol error was detected between the driver and the device.
;
STATUS_DEVICE_PROTOCOL_ERROR     EQU 0C0000186h

;
; MessageId: STATUS_BACKUP_CONTROLLER
;
; MessageText:
;
; This operation is only allowed for the Primary Domain Controller of the domain.
;
STATUS_BACKUP_CONTROLLER         EQU 0C0000187h

;
; MessageId: STATUS_LOG_FILE_FULL
;
; MessageText:
;
; Log file space is insufficient to support this operation.
;
STATUS_LOG_FILE_FULL             EQU 0C0000188h

;
; MessageId: STATUS_TOO_LATE
;
; MessageText:
;
; A write operation was attempted to a volume after it was dismounted.
;
STATUS_TOO_LATE                  EQU 0C0000189h

;
; MessageId: STATUS_NO_TRUST_LSA_SECRET
;
; MessageText:
;
; The workstation does not have a trust secret for the primary domain in the local LSA database.
;
STATUS_NO_TRUST_LSA_SECRET       EQU 0C000018Ah

;
; MessageId: STATUS_NO_TRUST_SAM_ACCOUNT
;
; MessageText:
;
; The SAM database on the Windows Server does not have a computer account for this workstation trust relationship.
;
STATUS_NO_TRUST_SAM_ACCOUNT      EQU 0C000018Bh

;
; MessageId: STATUS_TRUSTED_DOMAIN_FAILURE
;
; MessageText:
;
; The logon request failed because the trust relationship between the primary domain and the trusted domain failed.
;
STATUS_TRUSTED_DOMAIN_FAILURE    EQU 0C000018Ch

;
; MessageId: STATUS_TRUSTED_RELATIONSHIP_FAILURE
;
; MessageText:
;
; The logon request failed because the trust relationship between this workstation and the primary domain failed.
;
STATUS_TRUSTED_RELATIONSHIP_FAILURE EQU 0C000018Dh

;
; MessageId: STATUS_EVENTLOG_FILE_CORRUPT
;
; MessageText:
;
; The Eventlog log file is corrupt.
;
STATUS_EVENTLOG_FILE_CORRUPT     EQU 0C000018Eh

;
; MessageId: STATUS_EVENTLOG_CANT_START
;
; MessageText:
;
; No Eventlog log file could be opened. The Eventlog service did not start.
;
STATUS_EVENTLOG_CANT_START       EQU 0C000018Fh

;
; MessageId: STATUS_TRUST_FAILURE
;
; MessageText:
;
; The network logon failed. This may be because the validation authority can't be reached.
;
STATUS_TRUST_FAILURE             EQU 0C0000190h

;
; MessageId: STATUS_MUTANT_LIMIT_EXCEEDED
;
; MessageText:
;
; An attempt was made to acquire a mutant such that its maximum count would have been exceeded.
;
STATUS_MUTANT_LIMIT_EXCEEDED     EQU 0C0000191h

;
; MessageId: STATUS_NETLOGON_NOT_STARTED
;
; MessageText:
;
; An attempt was made to logon, but the netlogon service was not started.
;
STATUS_NETLOGON_NOT_STARTED      EQU 0C0000192h

;
; MessageId: STATUS_ACCOUNT_EXPIRED
;
; MessageText:
;
; The user's account has expired.
;
STATUS_ACCOUNT_EXPIRED           EQU 0C0000193h    ; ntsubauth

;
; MessageId: STATUS_POSSIBLE_DEADLOCK
;
; MessageText:
;
; {EXCEPTION}
; Possible deadlock condition.
;
STATUS_POSSIBLE_DEADLOCK         EQU 0C0000194h

;
; MessageId: STATUS_NETWORK_CREDENTIAL_CONFLICT
;
; MessageText:
;
; Multiple connections to a server or shared resource by the same user, using more than one user name, are not allowed. Disconnect all previous connections to the server or shared resource and try again.
;
STATUS_NETWORK_CREDENTIAL_CONFLICT EQU 0C0000195h

;
; MessageId: STATUS_REMOTE_SESSION_LIMIT
;
; MessageText:
;
; An attempt was made to establish a session to a network server, but there are already too many sessions established to that server.
;
STATUS_REMOTE_SESSION_LIMIT      EQU 0C0000196h

;
; MessageId: STATUS_EVENTLOG_FILE_CHANGED
;
; MessageText:
;
; The log file has changed between reads.
;
STATUS_EVENTLOG_FILE_CHANGED     EQU 0C0000197h

;
; MessageId: STATUS_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT
;
; MessageText:
;
; The account used is an Interdomain Trust account. Use your global user account or local user account to access this server.
;
STATUS_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT EQU 0C0000198h

;
; MessageId: STATUS_NOLOGON_WORKSTATION_TRUST_ACCOUNT
;
; MessageText:
;
; The account used is a Computer Account. Use your global user account or local user account to access this server.
;
STATUS_NOLOGON_WORKSTATION_TRUST_ACCOUNT EQU 0C0000199h

;
; MessageId: STATUS_NOLOGON_SERVER_TRUST_ACCOUNT
;
; MessageText:
;
; The account used is an Server Trust account. Use your global user account or local user account to access this server.
;
STATUS_NOLOGON_SERVER_TRUST_ACCOUNT EQU 0C000019Ah

;
; MessageId: STATUS_DOMAIN_TRUST_INCONSISTENT
;
; MessageText:
;
; The name or SID of the domain specified is inconsistent with the trust information for that domain.
;
STATUS_DOMAIN_TRUST_INCONSISTENT EQU 0C000019Bh

;
; MessageId: STATUS_FS_DRIVER_REQUIRED
;
; MessageText:
;
; A volume has been accessed for which a file system driver is required that has not yet been loaded.
;
STATUS_FS_DRIVER_REQUIRED        EQU 0C000019Ch

;
; MessageId: STATUS_IMAGE_ALREADY_LOADED_AS_DLL
;
; MessageText:
;
; Indicates that the specified image is already loaded as a DLL.
;
STATUS_IMAGE_ALREADY_LOADED_AS_DLL EQU 0C000019Dh

;
; MessageId: STATUS_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING
;
; MessageText:
;
; Short name settings may not be changed on this volume due to the global registry setting.
;
STATUS_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING EQU 0C000019Eh

;
; MessageId: STATUS_SHORT_NAMES_NOT_ENABLED_ON_VOLUME
;
; MessageText:
;
; Short names are not enabled on this volume.
;
STATUS_SHORT_NAMES_NOT_ENABLED_ON_VOLUME EQU 0C000019Fh

;
; MessageId: STATUS_SECURITY_STREAM_IS_INCONSISTENT
;
; MessageText:
;
; The security stream for the given volume is in an inconsistent state.
; Please run CHKDSK on the volume.
;
STATUS_SECURITY_STREAM_IS_INCONSISTENT EQU 0C00001A0h

;
; MessageId: STATUS_INVALID_LOCK_RANGE
;
; MessageText:
;
; A requested file lock operation cannot be processed due to an invalid byte range.
;
STATUS_INVALID_LOCK_RANGE        EQU 0C00001A1h

;
; MessageId: STATUS_INVALID_ACE_CONDITION
;
; MessageText:
;
; {Invalid ACE Condition}
; The specified access control entry (ACE) contains an invalid condition.
;
STATUS_INVALID_ACE_CONDITION     EQU 0C00001A2h

;
; MessageId: STATUS_IMAGE_SUBSYSTEM_NOT_PRESENT
;
; MessageText:
;
; The subsystem needed to support the image type is not present.
;
STATUS_IMAGE_SUBSYSTEM_NOT_PRESENT EQU 0C00001A3h

;
; MessageId: STATUS_NOTIFICATION_GUID_ALREADY_DEFINED
;
; MessageText:
;
; {Invalid ACE Condition}
; The specified file already has a notification GUID associated with it.
;
STATUS_NOTIFICATION_GUID_ALREADY_DEFINED EQU 0C00001A4h

;
; MessageId: STATUS_INVALID_EXCEPTION_HANDLER
;
; MessageText:
;
; An invalid exception handler routine has been detected.
;
STATUS_INVALID_EXCEPTION_HANDLER EQU 0C00001A5h

;
; MessageId: STATUS_DUPLICATE_PRIVILEGES
;
; MessageText:
;
; Duplicate privileges were specified for the token.
;
STATUS_DUPLICATE_PRIVILEGES      EQU 0C00001A6h

;
; MessageId: STATUS_NOT_ALLOWED_ON_SYSTEM_FILE
;
; MessageText:
;
; Requested action not allowed on a file system internal file.
;
STATUS_NOT_ALLOWED_ON_SYSTEM_FILE EQU 0C00001A7h

;
; MessageId: STATUS_REPAIR_NEEDED
;
; MessageText:
;
; A portion of the file system requires repair.
;
STATUS_REPAIR_NEEDED             EQU 0C00001A8h

;
; MessageId: STATUS_QUOTA_NOT_ENABLED
;
; MessageText:
;
; Quota support is not enabled on the system.
;
STATUS_QUOTA_NOT_ENABLED         EQU 0C00001A9h

;
; MessageId: STATUS_NO_APPLICATION_PACKAGE
;
; MessageText:
;
; The operation failed because the application is not part of an application package.
;
STATUS_NO_APPLICATION_PACKAGE    EQU 0C00001AAh

;
;  Available range of NTSTATUS codes
;
;
; MessageId: STATUS_NETWORK_OPEN_RESTRICTION
;
; MessageText:
;
; A remote open failed because the network open restrictions were not satisfied.
;
STATUS_NETWORK_OPEN_RESTRICTION  EQU 0C0000201h

;
; MessageId: STATUS_NO_USER_SESSION_KEY
;
; MessageText:
;
; There is no user session key for the specified logon session.
;
STATUS_NO_USER_SESSION_KEY       EQU 0C0000202h

;
; MessageId: STATUS_USER_SESSION_DELETED
;
; MessageText:
;
; The remote user session has been deleted.
;
STATUS_USER_SESSION_DELETED      EQU 0C0000203h

;
; MessageId: STATUS_RESOURCE_LANG_NOT_FOUND
;
; MessageText:
;
; Indicates the specified resource language ID cannot be found in the
; image file.
;
STATUS_RESOURCE_LANG_NOT_FOUND   EQU 0C0000204h

;
; MessageId: STATUS_INSUFF_SERVER_RESOURCES
;
; MessageText:
;
; Insufficient server resources exist to complete the request.
;
STATUS_INSUFF_SERVER_RESOURCES   EQU 0C0000205h

;
; MessageId: STATUS_INVALID_BUFFER_SIZE
;
; MessageText:
;
; The size of the buffer is invalid for the specified operation.
;
STATUS_INVALID_BUFFER_SIZE       EQU 0C0000206h

;
; MessageId: STATUS_INVALID_ADDRESS_COMPONENT
;
; MessageText:
;
; The transport rejected the network address specified as invalid.
;
STATUS_INVALID_ADDRESS_COMPONENT EQU 0C0000207h

;
; MessageId: STATUS_INVALID_ADDRESS_WILDCARD
;
; MessageText:
;
; The transport rejected the network address specified due to an invalid use of a wildcard.
;
STATUS_INVALID_ADDRESS_WILDCARD  EQU 0C0000208h

;
; MessageId: STATUS_TOO_MANY_ADDRESSES
;
; MessageText:
;
; The transport address could not be opened because all the available addresses are in use.
;
STATUS_TOO_MANY_ADDRESSES        EQU 0C0000209h

;
; MessageId: STATUS_ADDRESS_ALREADY_EXISTS
;
; MessageText:
;
; The transport address could not be opened because it already exists.
;
STATUS_ADDRESS_ALREADY_EXISTS    EQU 0C000020Ah

;
; MessageId: STATUS_ADDRESS_CLOSED
;
; MessageText:
;
; The transport address is now closed.
;
STATUS_ADDRESS_CLOSED            EQU 0C000020Bh

;
; MessageId: STATUS_CONNECTION_DISCONNECTED
;
; MessageText:
;
; The transport connection is now disconnected.
;
STATUS_CONNECTION_DISCONNECTED   EQU 0C000020Ch

;
; MessageId: STATUS_CONNECTION_RESET
;
; MessageText:
;
; The transport connection has been reset.
;
STATUS_CONNECTION_RESET          EQU 0C000020Dh

;
; MessageId: STATUS_TOO_MANY_NODES
;
; MessageText:
;
; The transport cannot dynamically acquire any more nodes.
;
STATUS_TOO_MANY_NODES            EQU 0C000020Eh

;
; MessageId: STATUS_TRANSACTION_ABORTED
;
; MessageText:
;
; The transport aborted a pending transaction.
;
STATUS_TRANSACTION_ABORTED       EQU 0C000020Fh

;
; MessageId: STATUS_TRANSACTION_TIMED_OUT
;
; MessageText:
;
; The transport timed out a request waiting for a response.
;
STATUS_TRANSACTION_TIMED_OUT     EQU 0C0000210h

;
; MessageId: STATUS_TRANSACTION_NO_RELEASE
;
; MessageText:
;
; The transport did not receive a release for a pending response.
;
STATUS_TRANSACTION_NO_RELEASE    EQU 0C0000211h

;
; MessageId: STATUS_TRANSACTION_NO_MATCH
;
; MessageText:
;
; The transport did not find a transaction matching the specific token.
;
STATUS_TRANSACTION_NO_MATCH      EQU 0C0000212h

;
; MessageId: STATUS_TRANSACTION_RESPONDED
;
; MessageText:
;
; The transport had previously responded to a transaction request.
;
STATUS_TRANSACTION_RESPONDED     EQU 0C0000213h

;
; MessageId: STATUS_TRANSACTION_INVALID_ID
;
; MessageText:
;
; The transport does not recognized the transaction request identifier specified.
;
STATUS_TRANSACTION_INVALID_ID    EQU 0C0000214h

;
; MessageId: STATUS_TRANSACTION_INVALID_TYPE
;
; MessageText:
;
; The transport does not recognize the transaction request type specified.
;
STATUS_TRANSACTION_INVALID_TYPE  EQU 0C0000215h

;
; MessageId: STATUS_NOT_SERVER_SESSION
;
; MessageText:
;
; The transport can only process the specified request on the server side of a session.
;
STATUS_NOT_SERVER_SESSION        EQU 0C0000216h

;
; MessageId: STATUS_NOT_CLIENT_SESSION
;
; MessageText:
;
; The transport can only process the specified request on the client side of a session.
;
STATUS_NOT_CLIENT_SESSION        EQU 0C0000217h

;
; MessageId: STATUS_CANNOT_LOAD_REGISTRY_FILE
;
; MessageText:
;
; {Registry File Failure}
; The registry cannot load the hive (file):
; %hs
; or its log or alternate.
; It is corrupt, absent, or not writable.
;
STATUS_CANNOT_LOAD_REGISTRY_FILE EQU 0C0000218h

;
; MessageId: STATUS_DEBUG_ATTACH_FAILED
;
; MessageText:
;
; {Unexpected Failure in DebugActiveProcess}
; An unexpected failure occurred while processing a DebugActiveProcess API request. You may choose OK to terminate the process, or Cancel to ignore the error.
;
STATUS_DEBUG_ATTACH_FAILED       EQU 0C0000219h

;
; MessageId: STATUS_SYSTEM_PROCESS_TERMINATED
;
; MessageText:
;
; {Fatal System Error}
; The %hs system process terminated unexpectedly with a status of 0x%08x (0x%08x 0x%08x).
; The system has been shut down.
;
STATUS_SYSTEM_PROCESS_TERMINATED EQU 0C000021Ah

;
; MessageId: STATUS_DATA_NOT_ACCEPTED
;
; MessageText:
;
; {Data Not Accepted}
; The TDI client could not handle the data received during an indication.
;
STATUS_DATA_NOT_ACCEPTED         EQU 0C000021Bh

;
; MessageId: STATUS_NO_BROWSER_SERVERS_FOUND
;
; MessageText:
;
; {Unable to Retrieve Browser Server List}
; The list of servers for this workgroup is not currently available.
;
STATUS_NO_BROWSER_SERVERS_FOUND  EQU 0C000021Ch

;
; MessageId: STATUS_VDM_HARD_ERROR
;
; MessageText:
;
; NTVDM encountered a hard error.
;
STATUS_VDM_HARD_ERROR            EQU 0C000021Dh

;
; MessageId: STATUS_DRIVER_CANCEL_TIMEOUT
;
; MessageText:
;
; {Cancel Timeout}
; The driver %hs failed to complete a cancelled I/O request in the allotted time.
;
STATUS_DRIVER_CANCEL_TIMEOUT     EQU 0C000021Eh

;
; MessageId: STATUS_REPLY_MESSAGE_MISMATCH
;
; MessageText:
;
; {Reply Message Mismatch}
; An attempt was made to reply to an LPC message, but the thread specified by the client ID in the message was not waiting on that message.
;
STATUS_REPLY_MESSAGE_MISMATCH    EQU 0C000021Fh

;
; MessageId: STATUS_MAPPED_ALIGNMENT
;
; MessageText:
;
; {Mapped View Alignment Incorrect}
; An attempt was made to map a view of a file, but either the specified base address or the offset into the file were not aligned on the proper allocation granularity.
;
STATUS_MAPPED_ALIGNMENT          EQU 0C0000220h

;
; MessageId: STATUS_IMAGE_CHECKSUM_MISMATCH
;
; MessageText:
;
; {Bad Image Checksum}
; The image %hs is possibly corrupt. The header checksum does not match the computed checksum.
;
STATUS_IMAGE_CHECKSUM_MISMATCH   EQU 0C0000221h

;
; MessageId: STATUS_LOST_WRITEBEHIND_DATA
;
; MessageText:
;
; {Delayed Write Failed}
; Windows was unable to save all the data for the file %hs. The data has been lost. This error may be caused by a failure of your computer hardware or network connection. Please try to save this file elsewhere.
;
STATUS_LOST_WRITEBEHIND_DATA     EQU 0C0000222h

;
; MessageId: STATUS_CLIENT_SERVER_PARAMETERS_INVALID
;
; MessageText:
;
; The parameter(s) passed to the server in the client/server shared memory window were invalid. Too much data may have been put in the shared memory window.
;
STATUS_CLIENT_SERVER_PARAMETERS_INVALID EQU 0C0000223h

;
; MessageId: STATUS_PASSWORD_MUST_CHANGE
;
; MessageText:
;
; The user's password must be changed before signing in.
;
STATUS_PASSWORD_MUST_CHANGE      EQU 0C0000224h    ; ntsubauth

;
; MessageId: STATUS_NOT_FOUND
;
; MessageText:
;
; The object was not found.
;
STATUS_NOT_FOUND                 EQU 0C0000225h

;
; MessageId: STATUS_NOT_TINY_STREAM
;
; MessageText:
;
; The stream is not a tiny stream.
;
STATUS_NOT_TINY_STREAM           EQU 0C0000226h

;
; MessageId: STATUS_RECOVERY_FAILURE
;
; MessageText:
;
; A transaction recover failed.
;
STATUS_RECOVERY_FAILURE          EQU 0C0000227h

;
; MessageId: STATUS_STACK_OVERFLOW_READ
;
; MessageText:
;
; The request must be handled by the stack overflow code.
;
STATUS_STACK_OVERFLOW_READ       EQU 0C0000228h

;
; MessageId: STATUS_FAIL_CHECK
;
; MessageText:
;
; A consistency check failed.
;
STATUS_FAIL_CHECK                EQU 0C0000229h

;
; MessageId: STATUS_DUPLICATE_OBJECTID
;
; MessageText:
;
; The attempt to insert the ID in the index failed because the ID is already in the index.
;
STATUS_DUPLICATE_OBJECTID        EQU 0C000022Ah

;
; MessageId: STATUS_OBJECTID_EXISTS
;
; MessageText:
;
; The attempt to set the object's ID failed because the object already has an ID.
;
STATUS_OBJECTID_EXISTS           EQU 0C000022Bh

;
; MessageId: STATUS_CONVERT_TO_LARGE
;
; MessageText:
;
; Internal OFS status codes indicating how an allocation operation is handled. Either it is retried after the containing onode is moved or the extent stream is converted to a large stream.
;
STATUS_CONVERT_TO_LARGE          EQU 0C000022Ch

;
; MessageId: STATUS_RETRY
;
; MessageText:
;
; The request needs to be retried.
;
STATUS_RETRY                     EQU 0C000022Dh

;
; MessageId: STATUS_FOUND_OUT_OF_SCOPE
;
; MessageText:
;
; The attempt to find the object found an object matching by ID on the volume but it is out of the scope of the handle used for the operation.
;
STATUS_FOUND_OUT_OF_SCOPE        EQU 0C000022Eh

;
; MessageId: STATUS_ALLOCATE_BUCKET
;
; MessageText:
;
; The bucket array must be grown. Retry transaction after doing so.
;
STATUS_ALLOCATE_BUCKET           EQU 0C000022Fh

;
; MessageId: STATUS_PROPSET_NOT_FOUND
;
; MessageText:
;
; The property set specified does not exist on the object.
;
STATUS_PROPSET_NOT_FOUND         EQU 0C0000230h

;
; MessageId: STATUS_MARSHALL_OVERFLOW
;
; MessageText:
;
; The user/kernel marshalling buffer has overflowed.
;
STATUS_MARSHALL_OVERFLOW         EQU 0C0000231h

;
; MessageId: STATUS_INVALID_VARIANT
;
; MessageText:
;
; The supplied variant structure contains invalid data.
;
STATUS_INVALID_VARIANT           EQU 0C0000232h

;
; MessageId: STATUS_DOMAIN_CONTROLLER_NOT_FOUND
;
; MessageText:
;
; Could not find a domain controller for this domain.
;
STATUS_DOMAIN_CONTROLLER_NOT_FOUND EQU 0C0000233h

;
; MessageId: STATUS_ACCOUNT_LOCKED_OUT
;
; MessageText:
;
; The user account has been automatically locked because too many invalid logon attempts or password change attempts have been requested.
;
STATUS_ACCOUNT_LOCKED_OUT        EQU 0C0000234h    ; ntsubauth

;
; MessageId: STATUS_HANDLE_NOT_CLOSABLE
;
; MessageText:
;
; NtClose was called on a handle that was protected from close via NtSetInformationObject.
;
STATUS_HANDLE_NOT_CLOSABLE       EQU 0C0000235h

;
; MessageId: STATUS_CONNECTION_REFUSED
;
; MessageText:
;
; The transport connection attempt was refused by the remote system.
;
STATUS_CONNECTION_REFUSED        EQU 0C0000236h

;
; MessageId: STATUS_GRACEFUL_DISCONNECT
;
; MessageText:
;
; The transport connection was gracefully closed.
;
STATUS_GRACEFUL_DISCONNECT       EQU 0C0000237h

;
; MessageId: STATUS_ADDRESS_ALREADY_ASSOCIATED
;
; MessageText:
;
; The transport endpoint already has an address associated with it.
;
STATUS_ADDRESS_ALREADY_ASSOCIATED EQU 0C0000238h

;
; MessageId: STATUS_ADDRESS_NOT_ASSOCIATED
;
; MessageText:
;
; An address has not yet been associated with the transport endpoint.
;
STATUS_ADDRESS_NOT_ASSOCIATED    EQU 0C0000239h

;
; MessageId: STATUS_CONNECTION_INVALID
;
; MessageText:
;
; An operation was attempted on a nonexistent transport connection.
;
STATUS_CONNECTION_INVALID        EQU 0C000023Ah

;
; MessageId: STATUS_CONNECTION_ACTIVE
;
; MessageText:
;
; An invalid operation was attempted on an active transport connection.
;
STATUS_CONNECTION_ACTIVE         EQU 0C000023Bh

;
; MessageId: STATUS_NETWORK_UNREACHABLE
;
; MessageText:
;
; The remote network is not reachable by the transport.
;
STATUS_NETWORK_UNREACHABLE       EQU 0C000023Ch

;
; MessageId: STATUS_HOST_UNREACHABLE
;
; MessageText:
;
; The remote system is not reachable by the transport.
;
STATUS_HOST_UNREACHABLE          EQU 0C000023Dh

;
; MessageId: STATUS_PROTOCOL_UNREACHABLE
;
; MessageText:
;
; The remote system does not support the transport protocol.
;
STATUS_PROTOCOL_UNREACHABLE      EQU 0C000023Eh

;
; MessageId: STATUS_PORT_UNREACHABLE
;
; MessageText:
;
; No service is operating at the destination port of the transport on the remote system.
;
STATUS_PORT_UNREACHABLE          EQU 0C000023Fh

;
; MessageId: STATUS_REQUEST_ABORTED
;
; MessageText:
;
; The request was aborted.
;
STATUS_REQUEST_ABORTED           EQU 0C0000240h

;
; MessageId: STATUS_CONNECTION_ABORTED
;
; MessageText:
;
; The transport connection was aborted by the local system.
;
STATUS_CONNECTION_ABORTED        EQU 0C0000241h

;
; MessageId: STATUS_BAD_COMPRESSION_BUFFER
;
; MessageText:
;
; The specified buffer contains ill-formed data.
;
STATUS_BAD_COMPRESSION_BUFFER    EQU 0C0000242h

;
; MessageId: STATUS_USER_MAPPED_FILE
;
; MessageText:
;
; The requested operation cannot be performed on a file with a user mapped section open.
;
STATUS_USER_MAPPED_FILE          EQU 0C0000243h

;
; MessageId: STATUS_AUDIT_FAILED
;
; MessageText:
;
; {Audit Failed}
; An attempt to generate a security audit failed.
;
STATUS_AUDIT_FAILED              EQU 0C0000244h

;
; MessageId: STATUS_TIMER_RESOLUTION_NOT_SET
;
; MessageText:
;
; The timer resolution was not previously set by the current process.
;
STATUS_TIMER_RESOLUTION_NOT_SET  EQU 0C0000245h

;
; MessageId: STATUS_CONNECTION_COUNT_LIMIT
;
; MessageText:
;
; A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached.
;
STATUS_CONNECTION_COUNT_LIMIT    EQU 0C0000246h

;
; MessageId: STATUS_LOGIN_TIME_RESTRICTION
;
; MessageText:
;
; Attempting to login during an unauthorized time of day for this account.
;
STATUS_LOGIN_TIME_RESTRICTION    EQU 0C0000247h

;
; MessageId: STATUS_LOGIN_WKSTA_RESTRICTION
;
; MessageText:
;
; The account is not authorized to login from this station.
;
STATUS_LOGIN_WKSTA_RESTRICTION   EQU 0C0000248h

;
; MessageId: STATUS_IMAGE_MP_UP_MISMATCH
;
; MessageText:
;
; {UP/MP Image Mismatch}
; The image %hs has been modified for use on a uniprocessor system, but you are running it on a multiprocessor machine.
; Please reinstall the image file.
;
STATUS_IMAGE_MP_UP_MISMATCH      EQU 0C0000249h

;
; MessageId: STATUS_INSUFFICIENT_LOGON_INFO
;
; MessageText:
;
; There is insufficient account information to log you on.
;
STATUS_INSUFFICIENT_LOGON_INFO   EQU 0C0000250h

;
; MessageId: STATUS_BAD_DLL_ENTRYPOINT
;
; MessageText:
;
; {Invalid DLL Entrypoint}
; The dynamic link library %hs is not written correctly. The stack pointer has been left in an inconsistent state. The entrypoint should be declared as WINAPI or STDCALL. Select YES to fail the DLL load. Select NO to continue execution. Selecting NO may cause the application to operate incorrectly.
;
STATUS_BAD_DLL_ENTRYPOINT        EQU 0C0000251h

;
; MessageId: STATUS_BAD_SERVICE_ENTRYPOINT
;
; MessageText:
;
; {Invalid Service Callback Entrypoint}
; The %hs service is not written correctly. The stack pointer has been left in an inconsistent state. The callback entrypoint should be declared as WINAPI or STDCALL. Selecting OK will cause the service to continue operation. However, the service process may operate incorrectly.
;
STATUS_BAD_SERVICE_ENTRYPOINT    EQU 0C0000252h

;
; MessageId: STATUS_LPC_REPLY_LOST
;
; MessageText:
;
; The server received the messages but did not send a reply.
;
STATUS_LPC_REPLY_LOST            EQU 0C0000253h

;
; MessageId: STATUS_IP_ADDRESS_CONFLICT1
;
; MessageText:
;
; There is an IP address conflict with another system on the network
;
STATUS_IP_ADDRESS_CONFLICT1      EQU 0C0000254h

;
; MessageId: STATUS_IP_ADDRESS_CONFLICT2
;
; MessageText:
;
; There is an IP address conflict with another system on the network
;
STATUS_IP_ADDRESS_CONFLICT2      EQU 0C0000255h

;
; MessageId: STATUS_REGISTRY_QUOTA_LIMIT
;
; MessageText:
;
; {Low On Registry Space}
; The system has reached the maximum size allowed for the system part of the registry. Additional storage requests will be ignored.
;
STATUS_REGISTRY_QUOTA_LIMIT      EQU 0C0000256h

;
; MessageId: STATUS_PATH_NOT_COVERED
;
; MessageText:
;
; The contacted server does not support the indicated part of the DFS namespace.
;
STATUS_PATH_NOT_COVERED          EQU 0C0000257h

;
; MessageId: STATUS_NO_CALLBACK_ACTIVE
;
; MessageText:
;
; A callback return system service cannot be executed when no callback is active.
;
STATUS_NO_CALLBACK_ACTIVE        EQU 0C0000258h

;
; MessageId: STATUS_LICENSE_QUOTA_EXCEEDED
;
; MessageText:
;
; The service being accessed is licensed for a particular number of connections. No more connections can be made to the service at this time because there are already as many connections as the service can accept.
;
STATUS_LICENSE_QUOTA_EXCEEDED    EQU 0C0000259h

;
; MessageId: STATUS_PWD_TOO_SHORT
;
; MessageText:
;
; The password provided is too short to meet the policy of your user account. Please choose a longer password.
;
STATUS_PWD_TOO_SHORT             EQU 0C000025Ah

;
; MessageId: STATUS_PWD_TOO_RECENT
;
; MessageText:
;
; The policy of your user account does not allow you to change passwords too frequently. This is done to prevent users from changing back to a familiar, but potentially discovered, password. If you feel your password has been compromised then please contact your administrator immediately to have a new one assigned.
;
STATUS_PWD_TOO_RECENT            EQU 0C000025Bh

;
; MessageId: STATUS_PWD_HISTORY_CONFLICT
;
; MessageText:
;
; You have attempted to change your password to one that you have used in the past. The policy of your user account does not allow this. Please select a password that you have not previously used.
;
STATUS_PWD_HISTORY_CONFLICT      EQU 0C000025Ch

;
; MessageId: STATUS_PLUGPLAY_NO_DEVICE
;
; MessageText:
;
; You have attempted to load a legacy device driver while its device instance had been disabled.
;
STATUS_PLUGPLAY_NO_DEVICE        EQU 0C000025Eh

;
; MessageId: STATUS_UNSUPPORTED_COMPRESSION
;
; MessageText:
;
; The specified compression format is unsupported.
;
STATUS_UNSUPPORTED_COMPRESSION   EQU 0C000025Fh

;
; MessageId: STATUS_INVALID_HW_PROFILE
;
; MessageText:
;
; The specified hardware profile configuration is invalid.
;
STATUS_INVALID_HW_PROFILE        EQU 0C0000260h

;
; MessageId: STATUS_INVALID_PLUGPLAY_DEVICE_PATH
;
; MessageText:
;
; The specified Plug and Play registry device path is invalid.
;
STATUS_INVALID_PLUGPLAY_DEVICE_PATH EQU 0C0000261h

;
; MessageId: STATUS_DRIVER_ORDINAL_NOT_FOUND
;
; MessageText:
;
; {Driver Entry Point Not Found}
; The %hs device driver could not locate the ordinal %ld in driver %hs.
;
STATUS_DRIVER_ORDINAL_NOT_FOUND  EQU 0C0000262h

;
; MessageId: STATUS_DRIVER_ENTRYPOINT_NOT_FOUND
;
; MessageText:
;
; {Driver Entry Point Not Found}
; The %hs device driver could not locate the entry point %hs in driver %hs.
;
STATUS_DRIVER_ENTRYPOINT_NOT_FOUND EQU 0C0000263h

;
; MessageId: STATUS_RESOURCE_NOT_OWNED
;
; MessageText:
;
; {Application Error}
; The application attempted to release a resource it did not own. Click OK to terminate the application.
;
STATUS_RESOURCE_NOT_OWNED        EQU 0C0000264h

;
; MessageId: STATUS_TOO_MANY_LINKS
;
; MessageText:
;
; An attempt was made to create more links on a file than the file system supports.
;
STATUS_TOO_MANY_LINKS            EQU 0C0000265h

;
; MessageId: STATUS_QUOTA_LIST_INCONSISTENT
;
; MessageText:
;
; The specified quota list is internally inconsistent with its descriptor.
;
STATUS_QUOTA_LIST_INCONSISTENT   EQU 0C0000266h

;
; MessageId: STATUS_FILE_IS_OFFLINE
;
; MessageText:
;
; The specified file has been relocated to offline storage.
;
STATUS_FILE_IS_OFFLINE           EQU 0C0000267h

;
; MessageId: STATUS_EVALUATION_EXPIRATION
;
; MessageText:
;
; {Windows Evaluation Notification}
; The evaluation period for this installation of Windows has expired. This system will shutdown in 1 hour. To restore access to this installation of Windows, please upgrade this installation using a licensed distribution of this product.
;
STATUS_EVALUATION_EXPIRATION     EQU 0C0000268h

;
; MessageId: STATUS_ILLEGAL_DLL_RELOCATION
;
; MessageText:
;
; {Illegal System DLL Relocation}
; The system DLL %hs was relocated in memory. The application will not run properly. The relocation occurred because the DLL %hs occupied an address range reserved for Windows system DLLs. The vendor supplying the DLL should be contacted for a new DLL.
;
STATUS_ILLEGAL_DLL_RELOCATION    EQU 0C0000269h

;
; MessageId: STATUS_LICENSE_VIOLATION
;
; MessageText:
;
; {License Violation}
; The system has detected tampering with your registered product type. This is a violation of your software license. Tampering with product type is not permitted.
;
STATUS_LICENSE_VIOLATION         EQU 0C000026Ah

;
; MessageId: STATUS_DLL_INIT_FAILED_LOGOFF
;
; MessageText:
;
; {DLL Initialization Failed}
; The application failed to initialize because the window station is shutting down.
;
STATUS_DLL_INIT_FAILED_LOGOFF    EQU 0C000026Bh

;
; MessageId: STATUS_DRIVER_UNABLE_TO_LOAD
;
; MessageText:
;
; {Unable to Load Device Driver}
; %hs device driver could not be loaded.
; Error Status was 0x%x
;
STATUS_DRIVER_UNABLE_TO_LOAD     EQU 0C000026Ch

;
; MessageId: STATUS_DFS_UNAVAILABLE
;
; MessageText:
;
; DFS is unavailable on the contacted server.
;
STATUS_DFS_UNAVAILABLE           EQU 0C000026Dh

;
; MessageId: STATUS_VOLUME_DISMOUNTED
;
; MessageText:
;
; An operation was attempted to a volume after it was dismounted.
;
STATUS_VOLUME_DISMOUNTED         EQU 0C000026Eh

;
; MessageId: STATUS_WX86_INTERNAL_ERROR
;
; MessageText:
;
; An internal error occurred in the Win32 x86 emulation subsystem.
;
STATUS_WX86_INTERNAL_ERROR       EQU 0C000026Fh

;
; MessageId: STATUS_WX86_FLOAT_STACK_CHECK
;
; MessageText:
;
; Win32 x86 emulation subsystem Floating-point stack check.
;
STATUS_WX86_FLOAT_STACK_CHECK    EQU 0C0000270h

;
; MessageId: STATUS_VALIDATE_CONTINUE
;
; MessageText:
;
; The validation process needs to continue on to the next step.
;
STATUS_VALIDATE_CONTINUE         EQU 0C0000271h

;
; MessageId: STATUS_NO_MATCH
;
; MessageText:
;
; There was no match for the specified key in the index.
;
STATUS_NO_MATCH                  EQU 0C0000272h

;
; MessageId: STATUS_NO_MORE_MATCHES
;
; MessageText:
;
; There are no more matches for the current index enumeration.
;
STATUS_NO_MORE_MATCHES           EQU 0C0000273h

;
; MessageId: STATUS_NOT_A_REPARSE_POINT
;
; MessageText:
;
; The NTFS file or directory is not a reparse point.
;
STATUS_NOT_A_REPARSE_POINT       EQU 0C0000275h

;
; MessageId: STATUS_IO_REPARSE_TAG_INVALID
;
; MessageText:
;
; The Windows I/O reparse tag passed for the NTFS reparse point is invalid.
;
STATUS_IO_REPARSE_TAG_INVALID    EQU 0C0000276h

;
; MessageId: STATUS_IO_REPARSE_TAG_MISMATCH
;
; MessageText:
;
; The Windows I/O reparse tag does not match the one present in the NTFS reparse point.
;
STATUS_IO_REPARSE_TAG_MISMATCH   EQU 0C0000277h

;
; MessageId: STATUS_IO_REPARSE_DATA_INVALID
;
; MessageText:
;
; The user data passed for the NTFS reparse point is invalid.
;
STATUS_IO_REPARSE_DATA_INVALID   EQU 0C0000278h

;
; MessageId: STATUS_IO_REPARSE_TAG_NOT_HANDLED
;
; MessageText:
;
; The layered file system driver for this IO tag did not handle it when needed.
;
STATUS_IO_REPARSE_TAG_NOT_HANDLED EQU 0C0000279h

;
; MessageId: STATUS_PWD_TOO_LONG
;
; MessageText:
;
; The password provided is too long to meet the policy of your user account. Please choose a shorter password.
;
STATUS_PWD_TOO_LONG              EQU 0C000027Ah

;
; MessageId: STATUS_STOWED_EXCEPTION
;
; MessageText:
;
; An application-internal exception has occurred.
;
STATUS_STOWED_EXCEPTION          EQU 0C000027Bh

;
; MessageId: STATUS_REPARSE_POINT_NOT_RESOLVED
;
; MessageText:
;
; The NTFS symbolic link could not be resolved even though the initial file name is valid.
;
STATUS_REPARSE_POINT_NOT_RESOLVED EQU 0C0000280h

;
; MessageId: STATUS_DIRECTORY_IS_A_REPARSE_POINT
;
; MessageText:
;
; The NTFS directory is a reparse point.
;
STATUS_DIRECTORY_IS_A_REPARSE_POINT EQU 0C0000281h

;
; MessageId: STATUS_RANGE_LIST_CONFLICT
;
; MessageText:
;
; The range could not be added to the range list because of a conflict.
;
STATUS_RANGE_LIST_CONFLICT       EQU 0C0000282h

;
; MessageId: STATUS_SOURCE_ELEMENT_EMPTY
;
; MessageText:
;
; The specified medium changer source element contains no media.
;
STATUS_SOURCE_ELEMENT_EMPTY      EQU 0C0000283h

;
; MessageId: STATUS_DESTINATION_ELEMENT_FULL
;
; MessageText:
;
; The specified medium changer destination element already contains media.
;
STATUS_DESTINATION_ELEMENT_FULL  EQU 0C0000284h

;
; MessageId: STATUS_ILLEGAL_ELEMENT_ADDRESS
;
; MessageText:
;
; The specified medium changer element does not exist.
;
STATUS_ILLEGAL_ELEMENT_ADDRESS   EQU 0C0000285h

;
; MessageId: STATUS_MAGAZINE_NOT_PRESENT
;
; MessageText:
;
; The specified element is contained within a magazine that is no longer present.
;
STATUS_MAGAZINE_NOT_PRESENT      EQU 0C0000286h

;
; MessageId: STATUS_REINITIALIZATION_NEEDED
;
; MessageText:
;
; The device requires reinitialization due to hardware errors.
;
STATUS_REINITIALIZATION_NEEDED   EQU 0C0000287h

;
; MessageId: STATUS_DEVICE_REQUIRES_CLEANING
;
; MessageText:
;
; The device has indicated that cleaning is necessary.
;
STATUS_DEVICE_REQUIRES_CLEANING  EQU 080000288h

;
; MessageId: STATUS_DEVICE_DOOR_OPEN
;
; MessageText:
;
; The device has indicated that its door is open. Further operations require it closed and secured.
;
STATUS_DEVICE_DOOR_OPEN          EQU 080000289h

;
; MessageId: STATUS_ENCRYPTION_FAILED
;
; MessageText:
;
; The file encryption attempt failed.
;
STATUS_ENCRYPTION_FAILED         EQU 0C000028Ah

;
; MessageId: STATUS_DECRYPTION_FAILED
;
; MessageText:
;
; The file decryption attempt failed.
;
STATUS_DECRYPTION_FAILED         EQU 0C000028Bh

;
; MessageId: STATUS_RANGE_NOT_FOUND
;
; MessageText:
;
; The specified range could not be found in the range list.
;
STATUS_RANGE_NOT_FOUND           EQU 0C000028Ch

;
; MessageId: STATUS_NO_RECOVERY_POLICY
;
; MessageText:
;
; There is no encryption recovery policy configured for this system.
;
STATUS_NO_RECOVERY_POLICY        EQU 0C000028Dh

;
; MessageId: STATUS_NO_EFS
;
; MessageText:
;
; The required encryption driver is not loaded for this system.
;
STATUS_NO_EFS                    EQU 0C000028Eh

;
; MessageId: STATUS_WRONG_EFS
;
; MessageText:
;
; The file was encrypted with a different encryption driver than is currently loaded.
;
STATUS_WRONG_EFS                 EQU 0C000028Fh

;
; MessageId: STATUS_NO_USER_KEYS
;
; MessageText:
;
; There are no EFS keys defined for the user.
;
STATUS_NO_USER_KEYS              EQU 0C0000290h

;
; MessageId: STATUS_FILE_NOT_ENCRYPTED
;
; MessageText:
;
; The specified file is not encrypted.
;
STATUS_FILE_NOT_ENCRYPTED        EQU 0C0000291h

;
; MessageId: STATUS_NOT_EXPORT_FORMAT
;
; MessageText:
;
; The specified file is not in the defined EFS export format.
;
STATUS_NOT_EXPORT_FORMAT         EQU 0C0000292h

;
; MessageId: STATUS_FILE_ENCRYPTED
;
; MessageText:
;
; The specified file is encrypted and the user does not have the ability to decrypt it.
;
STATUS_FILE_ENCRYPTED            EQU 0C0000293h

;
; MessageId: STATUS_WAKE_SYSTEM
;
; MessageText:
;
; The system has awoken
;
STATUS_WAKE_SYSTEM               EQU 040000294h

;
; MessageId: STATUS_WMI_GUID_NOT_FOUND
;
; MessageText:
;
; The guid passed was not recognized as valid by a WMI data provider.
;
STATUS_WMI_GUID_NOT_FOUND        EQU 0C0000295h

;
; MessageId: STATUS_WMI_INSTANCE_NOT_FOUND
;
; MessageText:
;
; The instance name passed was not recognized as valid by a WMI data provider.
;
STATUS_WMI_INSTANCE_NOT_FOUND    EQU 0C0000296h

;
; MessageId: STATUS_WMI_ITEMID_NOT_FOUND
;
; MessageText:
;
; The data item id passed was not recognized as valid by a WMI data provider.
;
STATUS_WMI_ITEMID_NOT_FOUND      EQU 0C0000297h

;
; MessageId: STATUS_WMI_TRY_AGAIN
;
; MessageText:
;
; The WMI request could not be completed and should be retried.
;
STATUS_WMI_TRY_AGAIN             EQU 0C0000298h

;
; MessageId: STATUS_SHARED_POLICY
;
; MessageText:
;
; The policy object is shared and can only be modified at the root
;
STATUS_SHARED_POLICY             EQU 0C0000299h

;
; MessageId: STATUS_POLICY_OBJECT_NOT_FOUND
;
; MessageText:
;
; The policy object does not exist when it should
;
STATUS_POLICY_OBJECT_NOT_FOUND   EQU 0C000029Ah

;
; MessageId: STATUS_POLICY_ONLY_IN_DS
;
; MessageText:
;
; The requested policy information only lives in the Ds
;
STATUS_POLICY_ONLY_IN_DS         EQU 0C000029Bh

;
; MessageId: STATUS_VOLUME_NOT_UPGRADED
;
; MessageText:
;
; The volume must be upgraded to enable this feature
;
STATUS_VOLUME_NOT_UPGRADED       EQU 0C000029Ch

;
; MessageId: STATUS_REMOTE_STORAGE_NOT_ACTIVE
;
; MessageText:
;
; The remote storage service is not operational at this time.
;
STATUS_REMOTE_STORAGE_NOT_ACTIVE EQU 0C000029Dh

;
; MessageId: STATUS_REMOTE_STORAGE_MEDIA_ERROR
;
; MessageText:
;
; The remote storage service encountered a media error.
;
STATUS_REMOTE_STORAGE_MEDIA_ERROR EQU 0C000029Eh

;
; MessageId: STATUS_NO_TRACKING_SERVICE
;
; MessageText:
;
; The tracking (workstation) service is not running.
;
STATUS_NO_TRACKING_SERVICE       EQU 0C000029Fh

;
; MessageId: STATUS_SERVER_SID_MISMATCH
;
; MessageText:
;
; The server process is running under a SID different than that required by client.
;
STATUS_SERVER_SID_MISMATCH       EQU 0C00002A0h

;
; Directory Service specific Errors
;
;
; MessageId: STATUS_DS_NO_ATTRIBUTE_OR_VALUE
;
; MessageText:
;
; The specified directory service attribute or value does not exist.
;
STATUS_DS_NO_ATTRIBUTE_OR_VALUE  EQU 0C00002A1h

;
; MessageId: STATUS_DS_INVALID_ATTRIBUTE_SYNTAX
;
; MessageText:
;
; The attribute syntax specified to the directory service is invalid.
;
STATUS_DS_INVALID_ATTRIBUTE_SYNTAX EQU 0C00002A2h

;
; MessageId: STATUS_DS_ATTRIBUTE_TYPE_UNDEFINED
;
; MessageText:
;
; The attribute type specified to the directory service is not defined.
;
STATUS_DS_ATTRIBUTE_TYPE_UNDEFINED EQU 0C00002A3h

;
; MessageId: STATUS_DS_ATTRIBUTE_OR_VALUE_EXISTS
;
; MessageText:
;
; The specified directory service attribute or value already exists.
;
STATUS_DS_ATTRIBUTE_OR_VALUE_EXISTS EQU 0C00002A4h

;
; MessageId: STATUS_DS_BUSY
;
; MessageText:
;
; The directory service is busy.
;
STATUS_DS_BUSY                   EQU 0C00002A5h

;
; MessageId: STATUS_DS_UNAVAILABLE
;
; MessageText:
;
; The directory service is not available.
;
STATUS_DS_UNAVAILABLE            EQU 0C00002A6h

;
; MessageId: STATUS_DS_NO_RIDS_ALLOCATED
;
; MessageText:
;
; The directory service was unable to allocate a relative identifier.
;
STATUS_DS_NO_RIDS_ALLOCATED      EQU 0C00002A7h

;
; MessageId: STATUS_DS_NO_MORE_RIDS
;
; MessageText:
;
; The directory service has exhausted the pool of relative identifiers.
;
STATUS_DS_NO_MORE_RIDS           EQU 0C00002A8h

;
; MessageId: STATUS_DS_INCORRECT_ROLE_OWNER
;
; MessageText:
;
; The requested operation could not be performed because the directory service is not the master for that type of operation.
;
STATUS_DS_INCORRECT_ROLE_OWNER   EQU 0C00002A9h

;
; MessageId: STATUS_DS_RIDMGR_INIT_ERROR
;
; MessageText:
;
; The directory service was unable to initialize the subsystem that allocates relative identifiers.
;
STATUS_DS_RIDMGR_INIT_ERROR      EQU 0C00002AAh

;
; MessageId: STATUS_DS_OBJ_CLASS_VIOLATION
;
; MessageText:
;
; The requested operation did not satisfy one or more constraints associated with the class of the object.
;
STATUS_DS_OBJ_CLASS_VIOLATION    EQU 0C00002ABh

;
; MessageId: STATUS_DS_CANT_ON_NON_LEAF
;
; MessageText:
;
; The directory service can perform the requested operation only on a leaf object.
;
STATUS_DS_CANT_ON_NON_LEAF       EQU 0C00002ACh

;
; MessageId: STATUS_DS_CANT_ON_RDN
;
; MessageText:
;
; The directory service cannot perform the requested operation on the Relatively Defined Name (RDN) attribute of an object.
;
STATUS_DS_CANT_ON_RDN            EQU 0C00002ADh

;
; MessageId: STATUS_DS_CANT_MOD_OBJ_CLASS
;
; MessageText:
;
; The directory service detected an attempt to modify the object class of an object.
;
STATUS_DS_CANT_MOD_OBJ_CLASS     EQU 0C00002AEh

;
; MessageId: STATUS_DS_CROSS_DOM_MOVE_FAILED
;
; MessageText:
;
; An error occurred while performing a cross domain move operation.
;
STATUS_DS_CROSS_DOM_MOVE_FAILED  EQU 0C00002AFh

;
; MessageId: STATUS_DS_GC_NOT_AVAILABLE
;
; MessageText:
;
; Unable to Contact the Global Catalog Server.
;
STATUS_DS_GC_NOT_AVAILABLE       EQU 0C00002B0h

;
; MessageId: STATUS_DIRECTORY_SERVICE_REQUIRED
;
; MessageText:
;
; The requested operation requires a directory service, and none was available.
;
STATUS_DIRECTORY_SERVICE_REQUIRED EQU 0C00002B1h

;
; MessageId: STATUS_REPARSE_ATTRIBUTE_CONFLICT
;
; MessageText:
;
; The reparse attribute cannot be set as it is incompatible with an existing attribute.
;
STATUS_REPARSE_ATTRIBUTE_CONFLICT EQU 0C00002B2h

;
; MessageId: STATUS_CANT_ENABLE_DENY_ONLY
;
; MessageText:
;
; A group marked use for deny only cannot be enabled.
;
STATUS_CANT_ENABLE_DENY_ONLY     EQU 0C00002B3h

;
; MessageId: STATUS_FLOAT_MULTIPLE_FAULTS
;
; MessageText:
;
; {EXCEPTION}
; Multiple floating point faults.
;
STATUS_FLOAT_MULTIPLE_FAULTS     EQU 0C00002B4h

;
; MessageId: STATUS_FLOAT_MULTIPLE_TRAPS
;
; MessageText:
;
; {EXCEPTION}
; Multiple floating point traps.
;
STATUS_FLOAT_MULTIPLE_TRAPS      EQU 0C00002B5h

;
; MessageId: STATUS_DEVICE_REMOVED
;
; MessageText:
;
; The device has been removed.
;
STATUS_DEVICE_REMOVED            EQU 0C00002B6h

;
; MessageId: STATUS_JOURNAL_DELETE_IN_PROGRESS
;
; MessageText:
;
; The volume change journal is being deleted.
;
STATUS_JOURNAL_DELETE_IN_PROGRESS EQU 0C00002B7h

;
; MessageId: STATUS_JOURNAL_NOT_ACTIVE
;
; MessageText:
;
; The volume change journal is not active.
;
STATUS_JOURNAL_NOT_ACTIVE        EQU 0C00002B8h

;
; MessageId: STATUS_NOINTERFACE
;
; MessageText:
;
; The requested interface is not supported.
;
STATUS_NOINTERFACE               EQU 0C00002B9h

;
; MessageId: STATUS_DS_RIDMGR_DISABLED
;
; MessageText:
;
; The directory service detected the subsystem that allocates relative identifiers is disabled. This can occur as a protective mechanism when the system determines a significant portion of relative identifiers (RIDs) have been exhausted. Please see http:;go.microsoft.com/fwlink/?LinkId=228610 for recommended diagnostic steps and the procedure to re-enable account creation.
;
STATUS_DS_RIDMGR_DISABLED        EQU 0C00002BAh

;
; MessageId: STATUS_DS_ADMIN_LIMIT_EXCEEDED
;
; MessageText:
;
; A directory service resource limit has been exceeded.
;
STATUS_DS_ADMIN_LIMIT_EXCEEDED   EQU 0C00002C1h

;
; MessageId: STATUS_DRIVER_FAILED_SLEEP
;
; MessageText:
;
; {System Standby Failed}
; The driver %hs does not support standby mode. Updating this driver may allow the system to go to standby mode.
;
STATUS_DRIVER_FAILED_SLEEP       EQU 0C00002C2h

;
; MessageId: STATUS_MUTUAL_AUTHENTICATION_FAILED
;
; MessageText:
;
; Mutual Authentication failed. The server's password is out of date at the domain controller.
;
STATUS_MUTUAL_AUTHENTICATION_FAILED EQU 0C00002C3h

;
; MessageId: STATUS_CORRUPT_SYSTEM_FILE
;
; MessageText:
;
; The system file %1 has become corrupt and has been replaced.
;
STATUS_CORRUPT_SYSTEM_FILE       EQU 0C00002C4h

;
; MessageId: STATUS_DATATYPE_MISALIGNMENT_ERROR
;
; MessageText:
;
; {EXCEPTION}
; Alignment Error
; A datatype misalignment error was detected in a load or store instruction.
;
STATUS_DATATYPE_MISALIGNMENT_ERROR EQU 0C00002C5h    

;
; MessageId: STATUS_WMI_READ_ONLY
;
; MessageText:
;
; The WMI data item or data block is read only.
;
STATUS_WMI_READ_ONLY             EQU 0C00002C6h

;
; MessageId: STATUS_WMI_SET_FAILURE
;
; MessageText:
;
; The WMI data item or data block could not be changed.
;
STATUS_WMI_SET_FAILURE           EQU 0C00002C7h

;
; MessageId: STATUS_COMMITMENT_MINIMUM
;
; MessageText:
;
; {Virtual Memory Minimum Too Low}
; Your system is low on virtual memory. Windows is increasing the size of your virtual memory paging file. During this process, memory requests for some applications may be denied. For more information, see Help.
;
STATUS_COMMITMENT_MINIMUM        EQU 0C00002C8h

;
; MessageId: STATUS_REG_NAT_CONSUMPTION
;
; MessageText:
;
; {EXCEPTION}
; Register NaT consumption faults.
; A NaT value is consumed on a non speculative instruction.
;
STATUS_REG_NAT_CONSUMPTION       EQU 0C00002C9h

;
; MessageId: STATUS_TRANSPORT_FULL
;
; MessageText:
;
; The medium changer's transport element contains media, which is causing the operation to fail.
;
STATUS_TRANSPORT_FULL            EQU 0C00002CAh

;
; MessageId: STATUS_DS_SAM_INIT_FAILURE
;
; MessageText:
;
; Security Accounts Manager initialization failed because of the following error:
; %hs
; Error Status: 0x%x.
; Please shutdown this system and reboot into Directory Services Restore Mode, check the event log for more detailed information.
;
STATUS_DS_SAM_INIT_FAILURE       EQU 0C00002CBh

;
; MessageId: STATUS_ONLY_IF_CONNECTED
;
; MessageText:
;
; This operation is supported only when you are connected to the server.
;
STATUS_ONLY_IF_CONNECTED         EQU 0C00002CCh

;
; MessageId: STATUS_DS_SENSITIVE_GROUP_VIOLATION
;
; MessageText:
;
; Only an administrator can modify the membership list of an administrative group.
;
STATUS_DS_SENSITIVE_GROUP_VIOLATION EQU 0C00002CDh

;
; MessageId: STATUS_PNP_RESTART_ENUMERATION
;
; MessageText:
;
; A device was removed so enumeration must be restarted.
;
STATUS_PNP_RESTART_ENUMERATION   EQU 0C00002CEh

;
; MessageId: STATUS_JOURNAL_ENTRY_DELETED
;
; MessageText:
;
; The journal entry has been deleted from the journal.
;
STATUS_JOURNAL_ENTRY_DELETED     EQU 0C00002CFh

;
; MessageId: STATUS_DS_CANT_MOD_PRIMARYGROUPID
;
; MessageText:
;
; Cannot change the primary group ID of a domain controller account.
;
STATUS_DS_CANT_MOD_PRIMARYGROUPID EQU 0C00002D0h

;
; MessageId: STATUS_SYSTEM_IMAGE_BAD_SIGNATURE
;
; MessageText:
;
; {Fatal System Error}
; The system image %s is not properly signed. The file has been replaced with the signed file. The system has been shut down.
;
STATUS_SYSTEM_IMAGE_BAD_SIGNATURE EQU 0C00002D1h

;
; MessageId: STATUS_PNP_REBOOT_REQUIRED
;
; MessageText:
;
; Device will not start without a reboot.
;
STATUS_PNP_REBOOT_REQUIRED       EQU 0C00002D2h

;
; MessageId: STATUS_POWER_STATE_INVALID
;
; MessageText:
;
; Current device power state cannot support this request.
;
STATUS_POWER_STATE_INVALID       EQU 0C00002D3h

;
; MessageId: STATUS_DS_INVALID_GROUP_TYPE
;
; MessageText:
;
; The specified group type is invalid.
;
STATUS_DS_INVALID_GROUP_TYPE     EQU 0C00002D4h

;
; MessageId: STATUS_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN
;
; MessageText:
;
; In mixed domain no nesting of global group if group is security enabled.
;
STATUS_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN EQU 0C00002D5h

;
; MessageId: STATUS_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN
;
; MessageText:
;
; In mixed domain, cannot nest local groups with other local groups, if the group is security enabled.
;
STATUS_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN EQU 0C00002D6h

;
; MessageId: STATUS_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER
;
; MessageText:
;
; A global group cannot have a local group as a member.
;
STATUS_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER EQU 0C00002D7h

;
; MessageId: STATUS_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER
;
; MessageText:
;
; A global group cannot have a universal group as a member.
;
STATUS_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER EQU 0C00002D8h

;
; MessageId: STATUS_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER
;
; MessageText:
;
; A universal group cannot have a local group as a member.
;
STATUS_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER EQU 0C00002D9h

;
; MessageId: STATUS_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER
;
; MessageText:
;
; A global group cannot have a cross domain member.
;
STATUS_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER EQU 0C00002DAh

;
; MessageId: STATUS_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER
;
; MessageText:
;
; A local group cannot have another cross domain local group as a member.
;
STATUS_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER EQU 0C00002DBh

;
; MessageId: STATUS_DS_HAVE_PRIMARY_MEMBERS
;
; MessageText:
;
; Cannot change to security disabled group because of having primary members in this group.
;
STATUS_DS_HAVE_PRIMARY_MEMBERS   EQU 0C00002DCh

;
; MessageId: STATUS_WMI_NOT_SUPPORTED
;
; MessageText:
;
; The WMI operation is not supported by the data block or method.
;
STATUS_WMI_NOT_SUPPORTED         EQU 0C00002DDh

;
; MessageId: STATUS_INSUFFICIENT_POWER
;
; MessageText:
;
; There is not enough power to complete the requested operation.
;
STATUS_INSUFFICIENT_POWER        EQU 0C00002DEh

;
; MessageId: STATUS_SAM_NEED_BOOTKEY_PASSWORD
;
; MessageText:
;
; Security Account Manager needs to get the boot password.
;
STATUS_SAM_NEED_BOOTKEY_PASSWORD EQU 0C00002DFh

;
; MessageId: STATUS_SAM_NEED_BOOTKEY_FLOPPY
;
; MessageText:
;
; Security Account Manager needs to get the boot key from floppy disk.
;
STATUS_SAM_NEED_BOOTKEY_FLOPPY   EQU 0C00002E0h

;
; MessageId: STATUS_DS_CANT_START
;
; MessageText:
;
; Directory Service cannot start.
;
STATUS_DS_CANT_START             EQU 0C00002E1h

;
; MessageId: STATUS_DS_INIT_FAILURE
;
; MessageText:
;
; Directory Services could not start because of the following error:
; %hs
; Error Status: 0x%x.
; Please shutdown this system and reboot into Directory Services Restore Mode, check the event log for more detailed information.
;
STATUS_DS_INIT_FAILURE           EQU 0C00002E2h

;
; MessageId: STATUS_SAM_INIT_FAILURE
;
; MessageText:
;
; Security Accounts Manager initialization failed because of the following error:
; %hs
; Error Status: 0x%x.
; Please click OK to shutdown this system and reboot into Safe Mode, check the event log for more detailed information.
;
STATUS_SAM_INIT_FAILURE          EQU 0C00002E3h

;
; MessageId: STATUS_DS_GC_REQUIRED
;
; MessageText:
;
; The requested operation can be performed only on a global catalog server.
;
STATUS_DS_GC_REQUIRED            EQU 0C00002E4h

;
; MessageId: STATUS_DS_LOCAL_MEMBER_OF_LOCAL_ONLY
;
; MessageText:
;
; A local group can only be a member of other local groups in the same domain.
;
STATUS_DS_LOCAL_MEMBER_OF_LOCAL_ONLY EQU 0C00002E5h

;
; MessageId: STATUS_DS_NO_FPO_IN_UNIVERSAL_GROUPS
;
; MessageText:
;
; Foreign security principals cannot be members of universal groups.
;
STATUS_DS_NO_FPO_IN_UNIVERSAL_GROUPS EQU 0C00002E6h

;
; MessageId: STATUS_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED
;
; MessageText:
;
; Your computer could not be joined to the domain. You have exceeded the maximum number of computer accounts you are allowed to create in this domain. Contact your system administrator to have this limit reset or increased.
;
STATUS_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED EQU 0C00002E7h

;
; MessageId: STATUS_MULTIPLE_FAULT_VIOLATION
;
; MessageText:
;
;  STATUS_MULTIPLE_FAULT_VIOLATION
;
STATUS_MULTIPLE_FAULT_VIOLATION  EQU 0C00002E8h

;
; MessageId: STATUS_CURRENT_DOMAIN_NOT_ALLOWED
;
; MessageText:
;
; This operation cannot be performed on the current domain.
;
STATUS_CURRENT_DOMAIN_NOT_ALLOWED EQU 0C00002E9h

;
; MessageId: STATUS_CANNOT_MAKE
;
; MessageText:
;
; The directory or file cannot be created.
;
STATUS_CANNOT_MAKE               EQU 0C00002EAh

;
; MessageId: STATUS_SYSTEM_SHUTDOWN
;
; MessageText:
;
; The system is in the process of shutting down.
;
STATUS_SYSTEM_SHUTDOWN           EQU 0C00002EBh

;
; MessageId: STATUS_DS_INIT_FAILURE_CONSOLE
;
; MessageText:
;
; Directory Services could not start because of the following error:
; %hs
; Error Status: 0x%x.
; Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.
;
STATUS_DS_INIT_FAILURE_CONSOLE   EQU 0C00002ECh

;
; MessageId: STATUS_DS_SAM_INIT_FAILURE_CONSOLE
;
; MessageText:
;
; Security Accounts Manager initialization failed because of the following error:
; %hs
; Error Status: 0x%x.
; Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.
;
STATUS_DS_SAM_INIT_FAILURE_CONSOLE EQU 0C00002EDh

;
; MessageId: STATUS_UNFINISHED_CONTEXT_DELETED
;
; MessageText:
;
; A security context was deleted before the context was completed. This is considered a logon failure.
;
STATUS_UNFINISHED_CONTEXT_DELETED EQU 0C00002EEh

;
; MessageId: STATUS_NO_TGT_REPLY
;
; MessageText:
;
; The client is trying to negotiate a context and the server requires user-to-user but didn't send a TGT reply.
;
STATUS_NO_TGT_REPLY              EQU 0C00002EFh

;
; MessageId: STATUS_OBJECTID_NOT_FOUND
;
; MessageText:
;
; An object ID was not found in the file.
;
STATUS_OBJECTID_NOT_FOUND        EQU 0C00002F0h

;
; MessageId: STATUS_NO_IP_ADDRESSES
;
; MessageText:
;
; Unable to accomplish the requested task because the local machine does not have any IP addresses.
;
STATUS_NO_IP_ADDRESSES           EQU 0C00002F1h

;
; MessageId: STATUS_WRONG_CREDENTIAL_HANDLE
;
; MessageText:
;
; The supplied credential handle does not match the credential associated with the security context.
;
STATUS_WRONG_CREDENTIAL_HANDLE   EQU 0C00002F2h

;
; MessageId: STATUS_CRYPTO_SYSTEM_INVALID
;
; MessageText:
;
; The crypto system or checksum function is invalid because a required function is unavailable.
;
STATUS_CRYPTO_SYSTEM_INVALID     EQU 0C00002F3h

;
; MessageId: STATUS_MAX_REFERRALS_EXCEEDED
;
; MessageText:
;
; The number of maximum ticket referrals has been exceeded.
;
STATUS_MAX_REFERRALS_EXCEEDED    EQU 0C00002F4h

;
; MessageId: STATUS_MUST_BE_KDC
;
; MessageText:
;
; The local machine must be a Kerberos KDC (domain controller) and it is not.
;
STATUS_MUST_BE_KDC               EQU 0C00002F5h

;
; MessageId: STATUS_STRONG_CRYPTO_NOT_SUPPORTED
;
; MessageText:
;
; The other end of the security negotiation is requires strong crypto but it is not supported on the local machine.
;
STATUS_STRONG_CRYPTO_NOT_SUPPORTED EQU 0C00002F6h

;
; MessageId: STATUS_TOO_MANY_PRINCIPALS
;
; MessageText:
;
; The KDC reply contained more than one principal name.
;
STATUS_TOO_MANY_PRINCIPALS       EQU 0C00002F7h

;
; MessageId: STATUS_NO_PA_DATA
;
; MessageText:
;
; Expected to find PA data for a hint of what etype to use, but it was not found.
;
STATUS_NO_PA_DATA                EQU 0C00002F8h

;
; MessageId: STATUS_PKINIT_NAME_MISMATCH
;
; MessageText:
;
; The client certificate does not contain a valid UPN, or does not match the client name in the logon request. Please contact your administrator.
;
STATUS_PKINIT_NAME_MISMATCH      EQU 0C00002F9h

;
; MessageId: STATUS_SMARTCARD_LOGON_REQUIRED
;
; MessageText:
;
; Smartcard logon is required and was not used.
;
STATUS_SMARTCARD_LOGON_REQUIRED  EQU 0C00002FAh

;
; MessageId: STATUS_KDC_INVALID_REQUEST
;
; MessageText:
;
; An invalid request was sent to the KDC.
;
STATUS_KDC_INVALID_REQUEST       EQU 0C00002FBh

;
; MessageId: STATUS_KDC_UNABLE_TO_REFER
;
; MessageText:
;
; The KDC was unable to generate a referral for the service requested.
;
STATUS_KDC_UNABLE_TO_REFER       EQU 0C00002FCh

;
; MessageId: STATUS_KDC_UNKNOWN_ETYPE
;
; MessageText:
;
; The encryption type requested is not supported by the KDC.
;
STATUS_KDC_UNKNOWN_ETYPE         EQU 0C00002FDh

;
; MessageId: STATUS_SHUTDOWN_IN_PROGRESS
;
; MessageText:
;
; A system shutdown is in progress.
;
STATUS_SHUTDOWN_IN_PROGRESS      EQU 0C00002FEh

;
; MessageId: STATUS_SERVER_SHUTDOWN_IN_PROGRESS
;
; MessageText:
;
; The server machine is shutting down.
;
STATUS_SERVER_SHUTDOWN_IN_PROGRESS EQU 0C00002FFh

;
; MessageId: STATUS_NOT_SUPPORTED_ON_SBS
;
; MessageText:
;
; This operation is not supported on a computer running Windows Server 2003 for Small Business Server
;
STATUS_NOT_SUPPORTED_ON_SBS      EQU 0C0000300h

;
; MessageId: STATUS_WMI_GUID_DISCONNECTED
;
; MessageText:
;
; The WMI GUID is no longer available
;
STATUS_WMI_GUID_DISCONNECTED     EQU 0C0000301h

;
; MessageId: STATUS_WMI_ALREADY_DISABLED
;
; MessageText:
;
; Collection or events for the WMI GUID is already disabled.
;
STATUS_WMI_ALREADY_DISABLED      EQU 0C0000302h

;
; MessageId: STATUS_WMI_ALREADY_ENABLED
;
; MessageText:
;
; Collection or events for the WMI GUID is already enabled.
;
STATUS_WMI_ALREADY_ENABLED       EQU 0C0000303h

;
; MessageId: STATUS_MFT_TOO_FRAGMENTED
;
; MessageText:
;
; The Master File Table on the volume is too fragmented to complete this operation.
;
STATUS_MFT_TOO_FRAGMENTED        EQU 0C0000304h

;
; MessageId: STATUS_COPY_PROTECTION_FAILURE
;
; MessageText:
;
; Copy protection failure.
;
STATUS_COPY_PROTECTION_FAILURE   EQU 0C0000305h

;
; MessageId: STATUS_CSS_AUTHENTICATION_FAILURE
;
; MessageText:
;
; Copy protection error - DVD CSS Authentication failed.
;
STATUS_CSS_AUTHENTICATION_FAILURE EQU 0C0000306h

;
; MessageId: STATUS_CSS_KEY_NOT_PRESENT
;
; MessageText:
;
; Copy protection error - The given sector does not contain a valid key.
;
STATUS_CSS_KEY_NOT_PRESENT       EQU 0C0000307h

;
; MessageId: STATUS_CSS_KEY_NOT_ESTABLISHED
;
; MessageText:
;
; Copy protection error - DVD session key not established.
;
STATUS_CSS_KEY_NOT_ESTABLISHED   EQU 0C0000308h

;
; MessageId: STATUS_CSS_SCRAMBLED_SECTOR
;
; MessageText:
;
; Copy protection error - The read failed because the sector is encrypted.
;
STATUS_CSS_SCRAMBLED_SECTOR      EQU 0C0000309h

;
; MessageId: STATUS_CSS_REGION_MISMATCH
;
; MessageText:
;
; Copy protection error - The given DVD's region does not correspond to the
; region setting of the drive.
;
STATUS_CSS_REGION_MISMATCH       EQU 0C000030Ah

;
; MessageId: STATUS_CSS_RESETS_EXHAUSTED
;
; MessageText:
;
; Copy protection error - The drive's region setting may be permanent.
;
STATUS_CSS_RESETS_EXHAUSTED      EQU 0C000030Bh

;
; MessageId: STATUS_PASSWORD_CHANGE_REQUIRED
;
; MessageText:
;
; EAS policy requires that the user change their password before this operation can be performed.
;
STATUS_PASSWORD_CHANGE_REQUIRED  EQU 0C000030Ch

;
;
; MessageId's 0x030c - 0x031f (inclusive) are reserved for future **STORAGE**
; copy protection errors.
;
;

;
; MessageId: STATUS_PKINIT_FAILURE
;
; MessageText:
;
; The Kerberos protocol encountered an error while validating the KDC certificate during smartcard Logon. There is more information in the system event log.
;
STATUS_PKINIT_FAILURE            EQU 0C0000320h

;
; MessageId: STATUS_SMARTCARD_SUBSYSTEM_FAILURE
;
; MessageText:
;
; The Kerberos protocol encountered an error while attempting to utilize the smartcard subsystem.
;
STATUS_SMARTCARD_SUBSYSTEM_FAILURE EQU 0C0000321h

;
; MessageId: STATUS_NO_KERB_KEY
;
; MessageText:
;
; The target server does not have acceptable Kerberos credentials.
;
STATUS_NO_KERB_KEY               EQU 0C0000322h

;
;
; MessageId's 0x0323 - 0x034f (inclusive) are reserved for other future copy
; protection errors.
;

;
;
; MessageId: STATUS_HOST_DOWN
;
; MessageText:
;
; The transport determined that the remote system is down.
;
STATUS_HOST_DOWN                 EQU 0C0000350h

;
; MessageId: STATUS_UNSUPPORTED_PREAUTH
;
; MessageText:
;
; An unsupported preauthentication mechanism was presented to the Kerberos package.
;
STATUS_UNSUPPORTED_PREAUTH       EQU 0C0000351h

;
; MessageId: STATUS_EFS_ALG_BLOB_TOO_BIG
;
; MessageText:
;
; The encryption algorithm used on the source file needs a bigger key buffer than the one used on the destination file.
;
STATUS_EFS_ALG_BLOB_TOO_BIG      EQU 0C0000352h

;
; MessageId: STATUS_PORT_NOT_SET
;
; MessageText:
;
; An attempt to remove a process's DebugPort was made, but a port was not already associated with the process.
;
STATUS_PORT_NOT_SET              EQU 0C0000353h

;
; MessageId: STATUS_DEBUGGER_INACTIVE
;
; MessageText:
;
; Debugger Inactive: Windows may have been started without kernel debugging enabled.
;
STATUS_DEBUGGER_INACTIVE         EQU 0C0000354h

;
; MessageId: STATUS_DS_VERSION_CHECK_FAILURE
;
; MessageText:
;
; This version of Windows is not compatible with the behavior version of directory forest, domain or domain controller.
;
STATUS_DS_VERSION_CHECK_FAILURE  EQU 0C0000355h

;
; MessageId: STATUS_AUDITING_DISABLED
;
; MessageText:
;
; The specified event is currently not being audited.
;
STATUS_AUDITING_DISABLED         EQU 0C0000356h

;
; MessageId: STATUS_PRENT4_MACHINE_ACCOUNT
;
; MessageText:
;
; The machine account was created pre-NT4. The account needs to be recreated.
;
STATUS_PRENT4_MACHINE_ACCOUNT    EQU 0C0000357h

;
; MessageId: STATUS_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER
;
; MessageText:
;
; A account group cannot have a universal group as a member.
;
STATUS_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER EQU 0C0000358h

;
; MessageId: STATUS_INVALID_IMAGE_WIN_32
;
; MessageText:
;
; The specified image file did not have the correct format, it appears to be a 32-bit Windows image.
;
STATUS_INVALID_IMAGE_WIN_32      EQU 0C0000359h

;
; MessageId: STATUS_INVALID_IMAGE_WIN_64
;
; MessageText:
;
; The specified image file did not have the correct format, it appears to be a 64-bit Windows image.
;
STATUS_INVALID_IMAGE_WIN_64      EQU 0C000035Ah

;
; MessageId: STATUS_BAD_BINDINGS
;
; MessageText:
;
; Client's supplied SSPI channel bindings were incorrect.
;
STATUS_BAD_BINDINGS              EQU 0C000035Bh

;
; MessageId: STATUS_NETWORK_SESSION_EXPIRED
;
; MessageText:
;
; The client's session has expired, so the client must reauthenticate to continue accessing the remote resources.
;
STATUS_NETWORK_SESSION_EXPIRED   EQU 0C000035Ch

;
; MessageId: STATUS_APPHELP_BLOCK
;
; MessageText:
;
; AppHelp dialog canceled thus preventing the application from starting.
;
STATUS_APPHELP_BLOCK             EQU 0C000035Dh

;
; MessageId: STATUS_ALL_SIDS_FILTERED
;
; MessageText:
;
; The SID filtering operation removed all SIDs.
;
STATUS_ALL_SIDS_FILTERED         EQU 0C000035Eh

;
; MessageId: STATUS_NOT_SAFE_MODE_DRIVER
;
; MessageText:
;
; The driver was not loaded because the system is booting into safe mode.
;
STATUS_NOT_SAFE_MODE_DRIVER      EQU 0C000035Fh

;
; MessageId: STATUS_ACCESS_DISABLED_BY_POLICY_DEFAULT
;
; MessageText:
;
; Access to %1 has been restricted by your Administrator by the default software restriction policy level.
;
STATUS_ACCESS_DISABLED_BY_POLICY_DEFAULT EQU 0C0000361h

;
; MessageId: STATUS_ACCESS_DISABLED_BY_POLICY_PATH
;
; MessageText:
;
; Access to %1 has been restricted by your Administrator by location with policy rule %2 placed on path %3
;
STATUS_ACCESS_DISABLED_BY_POLICY_PATH EQU 0C0000362h

;
; MessageId: STATUS_ACCESS_DISABLED_BY_POLICY_PUBLISHER
;
; MessageText:
;
; Access to %1 has been restricted by your Administrator by software publisher policy.
;
STATUS_ACCESS_DISABLED_BY_POLICY_PUBLISHER EQU 0C0000363h

;
; MessageId: STATUS_ACCESS_DISABLED_BY_POLICY_OTHER
;
; MessageText:
;
; Access to %1 has been restricted by your Administrator by policy rule %2.
;
STATUS_ACCESS_DISABLED_BY_POLICY_OTHER EQU 0C0000364h

;
; MessageId: STATUS_FAILED_DRIVER_ENTRY
;
; MessageText:
;
; The driver was not loaded because it failed its initialization call.
;
STATUS_FAILED_DRIVER_ENTRY       EQU 0C0000365h

;
; MessageId: STATUS_DEVICE_ENUMERATION_ERROR
;
; MessageText:
;
; The "%hs" encountered an error while applying power or reading the device configuration. This may be caused by a failure of your hardware or by a poor connection.
;
STATUS_DEVICE_ENUMERATION_ERROR  EQU 0C0000366h

;
; MessageId: STATUS_MOUNT_POINT_NOT_RESOLVED
;
; MessageText:
;
; The create operation failed because the name contained at least one mount point which resolves to a volume to which the specified device object is not attached.
;
STATUS_MOUNT_POINT_NOT_RESOLVED  EQU 0C0000368h

;
; MessageId: STATUS_INVALID_DEVICE_OBJECT_PARAMETER
;
; MessageText:
;
; The device object parameter is either not a valid device object or is not attached to the volume specified by the file name.
;
STATUS_INVALID_DEVICE_OBJECT_PARAMETER EQU 0C0000369h

;
; MessageId: STATUS_MCA_OCCURED
;
; MessageText:
;
; A Machine Check Error has occurred. Please check the system eventlog for additional information.
;
STATUS_MCA_OCCURED               EQU 0C000036Ah

;
; MessageId: STATUS_DRIVER_BLOCKED_CRITICAL
;
; MessageText:
;
; Driver %2 has been blocked from loading.
;
STATUS_DRIVER_BLOCKED_CRITICAL   EQU 0C000036Bh

;
; MessageId: STATUS_DRIVER_BLOCKED
;
; MessageText:
;
; Driver %2 has been blocked from loading.
;
STATUS_DRIVER_BLOCKED            EQU 0C000036Ch

;
; MessageId: STATUS_DRIVER_DATABASE_ERROR
;
; MessageText:
;
; There was error [%2] processing the driver database.
;
STATUS_DRIVER_DATABASE_ERROR     EQU 0C000036Dh

;
; MessageId: STATUS_SYSTEM_HIVE_TOO_LARGE
;
; MessageText:
;
; System hive size has exceeded its limit.
;
STATUS_SYSTEM_HIVE_TOO_LARGE     EQU 0C000036Eh

;
; MessageId: STATUS_INVALID_IMPORT_OF_NON_DLL
;
; MessageText:
;
; A dynamic link library (DLh referenced a module that was neither a DLL nor the process's executable image.
;
STATUS_INVALID_IMPORT_OF_NON_DLL EQU 0C000036Fh

;
; MessageId: STATUS_DS_SHUTTING_DOWN
;
; MessageText:
;
; The Directory Service is shutting down.
;
STATUS_DS_SHUTTING_DOWN          EQU 040000370h

;
; MessageId: STATUS_NO_SECRETS
;
; MessageText:
;
; The local account store does not contain secret material for the specified account.
;
STATUS_NO_SECRETS                EQU 0C0000371h

;
; MessageId: STATUS_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY
;
; MessageText:
;
; Access to %1 has been restricted by your Administrator by policy rule %2.
;
STATUS_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY EQU 0C0000372h    

;
; MessageId: STATUS_FAILED_STACK_SWITCH
;
; MessageText:
;
; The system was not able to allocate enough memory to perform a stack switch.
;
STATUS_FAILED_STACK_SWITCH       EQU 0C0000373h

;
; MessageId: STATUS_HEAP_CORRUPTION
;
; MessageText:
;
; A heap has been corrupted.
;
STATUS_HEAP_CORRUPTION           EQU 0C0000374h

;
; MessageId: STATUS_SMARTCARD_WRONG_PIN
;
; MessageText:
;
; An incorrect PIN was presented to the smart card
;
STATUS_SMARTCARD_WRONG_PIN       EQU 0C0000380h

;
; MessageId: STATUS_SMARTCARD_CARD_BLOCKED
;
; MessageText:
;
; The smart card is blocked
;
STATUS_SMARTCARD_CARD_BLOCKED    EQU 0C0000381h

;
; MessageId: STATUS_SMARTCARD_CARD_NOT_AUTHENTICATED
;
; MessageText:
;
; No PIN was presented to the smart card
;
STATUS_SMARTCARD_CARD_NOT_AUTHENTICATED EQU 0C0000382h

;
; MessageId: STATUS_SMARTCARD_NO_CARD
;
; MessageText:
;
; No smart card available
;
STATUS_SMARTCARD_NO_CARD         EQU 0C0000383h

;
; MessageId: STATUS_SMARTCARD_NO_KEY_CONTAINER
;
; MessageText:
;
; The requested key container does not exist on the smart card
;
STATUS_SMARTCARD_NO_KEY_CONTAINER EQU 0C0000384h

;
; MessageId: STATUS_SMARTCARD_NO_CERTIFICATE
;
; MessageText:
;
; The requested certificate does not exist on the smart card
;
STATUS_SMARTCARD_NO_CERTIFICATE  EQU 0C0000385h

;
; MessageId: STATUS_SMARTCARD_NO_KEYSET
;
; MessageText:
;
; The requested keyset does not exist
;
STATUS_SMARTCARD_NO_KEYSET       EQU 0C0000386h

;
; MessageId: STATUS_SMARTCARD_IO_ERROR
;
; MessageText:
;
; A communication error with the smart card has been detected.
;
STATUS_SMARTCARD_IO_ERROR        EQU 0C0000387h

;
; MessageId: STATUS_DOWNGRADE_DETECTED
;
; MessageText:
;
; The system cannot contact a domain controller to service the authentication request. Please try again later.
;
STATUS_DOWNGRADE_DETECTED        EQU 0C0000388h

;
; MessageId: STATUS_SMARTCARD_CERT_REVOKED
;
; MessageText:
;
; The smartcard certificate used for authentication has been revoked. Please contact your system administrator. There may be additional information in the event log.
;
STATUS_SMARTCARD_CERT_REVOKED    EQU 0C0000389h

;
; MessageId: STATUS_ISSUING_CA_UNTRUSTED
;
; MessageText:
;
; An untrusted certificate authority was detected while processing the smartcard certificate used for authentication. Please contact your system administrator.
;
STATUS_ISSUING_CA_UNTRUSTED      EQU 0C000038Ah

;
; MessageId: STATUS_REVOCATION_OFFLINE_C
;
; MessageText:
;
; The revocation status of the smartcard certificate used for authentication could not be determined. Please contact your system administrator.
;
STATUS_REVOCATION_OFFLINE_C      EQU 0C000038Bh

;
; MessageId: STATUS_PKINIT_CLIENT_FAILURE
;
; MessageText:
;
; The smartcard certificate used for authentication was not trusted. Please contact your system administrator.
;
STATUS_PKINIT_CLIENT_FAILURE     EQU 0C000038Ch

;
; MessageId: STATUS_SMARTCARD_CERT_EXPIRED
;
; MessageText:
;
; The smartcard certificate used for authentication has expired. Please
; contact your system administrator.
;
STATUS_SMARTCARD_CERT_EXPIRED    EQU 0C000038Dh

;
; MessageId: STATUS_DRIVER_FAILED_PRIOR_UNLOAD
;
; MessageText:
;
; The driver could not be loaded because a previous version of the driver is still in memory.
;
STATUS_DRIVER_FAILED_PRIOR_UNLOAD EQU 0C000038Eh

;
; MessageId: STATUS_SMARTCARD_SILENT_CONTEXT
;
; MessageText:
;
; The smartcard provider could not perform the action since the context was acquired as silent.
;
STATUS_SMARTCARD_SILENT_CONTEXT  EQU 0C000038Fh

; MessageId up to 0x400 is reserved for smart cards */
;
; MessageId: STATUS_PER_USER_TRUST_QUOTA_EXCEEDED
;
; MessageText:
;
; The current user's delegated trust creation quota has been exceeded.
;
STATUS_PER_USER_TRUST_QUOTA_EXCEEDED EQU 0C0000401h

;
; MessageId: STATUS_ALL_USER_TRUST_QUOTA_EXCEEDED
;
; MessageText:
;
; The total delegated trust creation quota has been exceeded.
;
STATUS_ALL_USER_TRUST_QUOTA_EXCEEDED EQU 0C0000402h

;
; MessageId: STATUS_USER_DELETE_TRUST_QUOTA_EXCEEDED
;
; MessageText:
;
; The current user's delegated trust deletion quota has been exceeded.
;
STATUS_USER_DELETE_TRUST_QUOTA_EXCEEDED EQU 0C0000403h

;
; MessageId: STATUS_DS_NAME_NOT_UNIQUE
;
; MessageText:
;
; The requested name already exists as a unique identifier.
;
STATUS_DS_NAME_NOT_UNIQUE        EQU 0C0000404h

;
; MessageId: STATUS_DS_DUPLICATE_ID_FOUND
;
; MessageText:
;
; The requested object has a non-unique identifier and cannot be retrieved.
;
STATUS_DS_DUPLICATE_ID_FOUND     EQU 0C0000405h

;
; MessageId: STATUS_DS_GROUP_CONVERSION_ERROR
;
; MessageText:
;
; The group cannot be converted due to attribute restrictions on the requested group type.
;
STATUS_DS_GROUP_CONVERSION_ERROR EQU 0C0000406h

;
; MessageId: STATUS_VOLSNAP_PREPARE_HIBERNATE
;
; MessageText:
;
; {Volume Shadow Copy Service}
; Please wait while the Volume Shadow Copy Service prepares volume %hs for hibernation.
;
STATUS_VOLSNAP_PREPARE_HIBERNATE EQU 0C0000407h

;
; MessageId: STATUS_USER2USER_REQUIRED
;
; MessageText:
;
; Kerberos sub-protocol User2User is required.
;
STATUS_USER2USER_REQUIRED        EQU 0C0000408h

;
; MessageId: STATUS_STACK_BUFFER_OVERRUN
;
; MessageText:
;
; The system detected an overrun of a stack-based buffer in this application. This overrun could potentially allow a malicious user to gain control of this application.
;
STATUS_STACK_BUFFER_OVERRUN      EQU 0C0000409h

;
; MessageId: STATUS_NO_S4U_PROT_SUPPORT
;
; MessageText:
;
; The Kerberos subsystem encountered an error. A service for user protocol request was made against a domain controller which does not support service for user.
;
STATUS_NO_S4U_PROT_SUPPORT       EQU 0C000040Ah

;
; MessageId: STATUS_CROSSREALM_DELEGATION_FAILURE
;
; MessageText:
;
; An attempt was made by this server to make a Kerberos constrained delegation request for a target outside of the server's realm. This is not supported, and indicates a misconfiguration on this server's allowed to delegate to list. Please contact your administrator.
;
STATUS_CROSSREALM_DELEGATION_FAILURE EQU 0C000040Bh

;
; MessageId: STATUS_REVOCATION_OFFLINE_KDC
;
; MessageText:
;
; The revocation status of the domain controller certificate used for smartcard authentication could not be determined. There is additional information in the system event log. Please contact your system administrator.
;
STATUS_REVOCATION_OFFLINE_KDC    EQU 0C000040Ch

;
; MessageId: STATUS_ISSUING_CA_UNTRUSTED_KDC
;
; MessageText:
;
; An untrusted certificate authority was detected while processing the domain controller certificate used for authentication. There is additional information in the system event log. Please contact your system administrator.
;
STATUS_ISSUING_CA_UNTRUSTED_KDC  EQU 0C000040Dh

;
; MessageId: STATUS_KDC_CERT_EXPIRED
;
; MessageText:
;
; The domain controller certificate used for smartcard logon has expired. Please contact your system administrator with the contents of your system event log.
;
STATUS_KDC_CERT_EXPIRED          EQU 0C000040Eh

;
; MessageId: STATUS_KDC_CERT_REVOKED
;
; MessageText:
;
; The domain controller certificate used for smartcard logon has been revoked. Please contact your system administrator with the contents of your system event log.
;
STATUS_KDC_CERT_REVOKED          EQU 0C000040Fh

;
; MessageId: STATUS_PARAMETER_QUOTA_EXCEEDED
;
; MessageText:
;
; Data present in one of the parameters is more than the function can operate on.
;
STATUS_PARAMETER_QUOTA_EXCEEDED  EQU 0C0000410h

;
; MessageId: STATUS_HIBERNATION_FAILURE
;
; MessageText:
;
; The system has failed to hibernate (The error code is %hs). Hibernation will be disabled until the system is restarted.
;
STATUS_HIBERNATION_FAILURE       EQU 0C0000411h

;
; MessageId: STATUS_DELAY_LOAD_FAILED
;
; MessageText:
;
; An attempt to delay-load a .dll or get a function address in a delay-loaded .dll failed.
;
STATUS_DELAY_LOAD_FAILED         EQU 0C0000412h

;
; MessageId: STATUS_AUTHENTICATION_FIREWALL_FAILED
;
; MessageText:
;
; Logon Failure: The machine you are logging onto is protected by an authentication firewall. The specified account is not allowed to authenticate to the machine.
;
STATUS_AUTHENTICATION_FIREWALL_FAILED EQU 0C0000413h

;
; MessageId: STATUS_VDM_DISALLOWED
;
; MessageText:
;
; %hs is a 16-bit application. You do not have permissions to execute 16-bit applications. Check your permissions with your system administrator.
;
STATUS_VDM_DISALLOWED            EQU 0C0000414h

;
; MessageId: STATUS_HUNG_DISPLAY_DRIVER_THREAD
;
; MessageText:
;
; {Display Driver Stopped Responding}
; The %hs display driver has stopped working normally. Save your work and reboot the system to restore full display functionality. The next time you reboot the machine a dialog will be displayed giving you a chance to report this failure to Microsoft.
;
STATUS_HUNG_DISPLAY_DRIVER_THREAD EQU 0C0000415h

;
; MessageId: STATUS_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE
;
; MessageText:
;
; The Desktop heap encountered an error while allocating session memory. There is more information in the system event log.
;
STATUS_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE EQU 0C0000416h

;
; MessageId: STATUS_INVALID_CRUNTIME_PARAMETER
;
; MessageText:
;
; An invalid parameter was passed to a C runtime function.
;
STATUS_INVALID_CRUNTIME_PARAMETER EQU 0C0000417h

;
; MessageId: STATUS_NTLM_BLOCKED
;
; MessageText:
;
; The authentication failed since NTLM was blocked.
;
STATUS_NTLM_BLOCKED              EQU 0C0000418h

;
; MessageId: STATUS_DS_SRC_SID_EXISTS_IN_FOREST
;
; MessageText:
;
; The source object's SID already exists in destination forest.
;
STATUS_DS_SRC_SID_EXISTS_IN_FOREST EQU 0C0000419h

;
; MessageId: STATUS_DS_DOMAIN_NAME_EXISTS_IN_FOREST
;
; MessageText:
;
; The domain name of the trusted domain already exists in the forest.
;
STATUS_DS_DOMAIN_NAME_EXISTS_IN_FOREST EQU 0C000041Ah

;
; MessageId: STATUS_DS_FLAT_NAME_EXISTS_IN_FOREST
;
; MessageText:
;
; The flat name of the trusted domain already exists in the forest.
;
STATUS_DS_FLAT_NAME_EXISTS_IN_FOREST EQU 0C000041Bh

;
; MessageId: STATUS_INVALID_USER_PRINCIPAL_NAME
;
; MessageText:
;
; The User Principal Name (UPN) is invalid.
;
STATUS_INVALID_USER_PRINCIPAL_NAME EQU 0C000041Ch

;
; MessageId: STATUS_FATAL_USER_CALLBACK_EXCEPTION
;
; MessageText:
;
; An unhandled exception was encountered during a user callback.
;
STATUS_FATAL_USER_CALLBACK_EXCEPTION EQU 0C000041Dh

;
; MessageId: STATUS_ASSERTION_FAILURE
;
; MessageText:
;
; An assertion failure has occurred.
;
STATUS_ASSERTION_FAILURE         EQU 0C0000420h

;
; MessageId: STATUS_VERIFIER_STOP
;
; MessageText:
;
; Application verifier has found an error in the current process.
;
STATUS_VERIFIER_STOP             EQU 0C0000421h

;
; MessageId: STATUS_CALLBACK_POP_STACK
;
; MessageText:
;
; An exception has occurred in a user mode callback and the kernel callback frame should be removed.
;
STATUS_CALLBACK_POP_STACK        EQU 0C0000423h

;
; MessageId: STATUS_INCOMPATIBLE_DRIVER_BLOCKED
;
; MessageText:
;
; %2 has been blocked from loading due to incompatibility with this system. Please contact your software vendor for a compatible version of the driver.
;
STATUS_INCOMPATIBLE_DRIVER_BLOCKED EQU 0C0000424h

;
; MessageId: STATUS_HIVE_UNLOADED
;
; MessageText:
;
; Illegal operation attempted on a registry key which has already been unloaded.
;
STATUS_HIVE_UNLOADED             EQU 0C0000425h

;
; MessageId: STATUS_COMPRESSION_DISABLED
;
; MessageText:
;
; Compression is disabled for this volume.
;
STATUS_COMPRESSION_DISABLED      EQU 0C0000426h

;
; MessageId: STATUS_FILE_SYSTEM_LIMITATION
;
; MessageText:
;
; The requested operation could not be completed due to a file system limitation
;
STATUS_FILE_SYSTEM_LIMITATION    EQU 0C0000427h

;
; MessageId: STATUS_INVALID_IMAGE_HASH
;
; MessageText:
;
; Windows cannot verify the digital signature for this file. A recent hardware or software change might have installed a file that is signed incorrectly or damaged, or that might be malicious software from an unknown source.
;
STATUS_INVALID_IMAGE_HASH        EQU 0C0000428h

;
; MessageId: STATUS_NOT_CAPABLE
;
; MessageText:
;
; The implementation is not capable of performing the request.
;
STATUS_NOT_CAPABLE               EQU 0C0000429h

;
; MessageId: STATUS_REQUEST_OUT_OF_SEQUENCE
;
; MessageText:
;
; The requested operation is out of order with respect to other operations.
;
STATUS_REQUEST_OUT_OF_SEQUENCE   EQU 0C000042Ah

;
; MessageId: STATUS_IMPLEMENTATION_LIMIT
;
; MessageText:
;
; An operation attempted to exceed an implementation-defined limit.
;
STATUS_IMPLEMENTATION_LIMIT      EQU 0C000042Bh

;
; MessageId: STATUS_ELEVATION_REQUIRED
;
; MessageText:
;
; The requested operation requires elevation.
;
STATUS_ELEVATION_REQUIRED        EQU 0C000042Ch

;
; MessageId: STATUS_NO_SECURITY_CONTEXT
;
; MessageText:
;
; The required security context does not exist.
;
STATUS_NO_SECURITY_CONTEXT       EQU 0C000042Dh

;
; MessageId 0x042E is reserved and used in isolation lib as
;
; MessageId=0x042E Facility=System Severity=ERROR SymbolicName=STATUS_VERSION_PARSE_ERROR
; Language=English
; A version number could not be parsed.
; .
;
; MessageId: STATUS_PKU2U_CERT_FAILURE
;
; MessageText:
;
; The PKU2U protocol encountered an error while attempting to utilize the associated certificates.
;
STATUS_PKU2U_CERT_FAILURE        EQU 0C000042Fh

;
; MessageId: STATUS_BEYOND_VDL
;
; MessageText:
;
; The operation was attempted beyond the valid data length of the file.
;
STATUS_BEYOND_VDL                EQU 0C0000432h

;
; MessageId: STATUS_ENCOUNTERED_WRITE_IN_PROGRESS
;
; MessageText:
;
; The attempted write operation encountered a write already in progress for some portion of the range.
;
STATUS_ENCOUNTERED_WRITE_IN_PROGRESS EQU 0C0000433h

;
; MessageId: STATUS_PTE_CHANGED
;
; MessageText:
;
; The page fault mappings changed in the middle of processing a fault so the operation must be retried.
;
STATUS_PTE_CHANGED               EQU 0C0000434h

;
; MessageId: STATUS_PURGE_FAILED
;
; MessageText:
;
; The attempt to purge this file from memory failed to purge some or all the data from memory.
;
STATUS_PURGE_FAILED              EQU 0C0000435h

;
; MessageId: STATUS_CRED_REQUIRES_CONFIRMATION
;
; MessageText:
;
; The requested credential requires confirmation.
;
STATUS_CRED_REQUIRES_CONFIRMATION EQU 0C0000440h

;
; MessageId: STATUS_CS_ENCRYPTION_INVALID_SERVER_RESPONSE
;
; MessageText:
;
; The remote server sent an invalid response for a file being opened with Client Side Encryption.
;
STATUS_CS_ENCRYPTION_INVALID_SERVER_RESPONSE EQU 0C0000441h

;
; MessageId: STATUS_CS_ENCRYPTION_UNSUPPORTED_SERVER
;
; MessageText:
;
; Client Side Encryption is not supported by the remote server even though it claims to support it.
;
STATUS_CS_ENCRYPTION_UNSUPPORTED_SERVER EQU 0C0000442h

;
; MessageId: STATUS_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE
;
; MessageText:
;
; File is encrypted and should be opened in Client Side Encryption mode.
;
STATUS_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE EQU 0C0000443h

;
; MessageId: STATUS_CS_ENCRYPTION_NEW_ENCRYPTED_FILE
;
; MessageText:
;
; A new encrypted file is being created and a $EFS needs to be provided.
;
STATUS_CS_ENCRYPTION_NEW_ENCRYPTED_FILE EQU 0C0000444h

;
; MessageId: STATUS_CS_ENCRYPTION_FILE_NOT_CSE
;
; MessageText:
;
; The SMB client requested a CSE FSCTL on a non-CSE file.
;
STATUS_CS_ENCRYPTION_FILE_NOT_CSE EQU 0C0000445h

;
; MessageId: STATUS_INVALID_LABEL
;
; MessageText:
;
; Indicates a particular Security ID may not be assigned as the label of an object.
;
STATUS_INVALID_LABEL             EQU 0C0000446h

;
; MessageId: STATUS_DRIVER_PROCESS_TERMINATED
;
; MessageText:
;
; The process hosting the driver for this device has terminated.
;
STATUS_DRIVER_PROCESS_TERMINATED EQU 0C0000450h

;
; MessageId: STATUS_AMBIGUOUS_SYSTEM_DEVICE
;
; MessageText:
;
; The requested system device cannot be identified due to multiple indistinguishable devices potentially matching the identification criteria.
;
STATUS_AMBIGUOUS_SYSTEM_DEVICE   EQU 0C0000451h

;
; MessageId: STATUS_SYSTEM_DEVICE_NOT_FOUND
;
; MessageText:
;
; The requested system device cannot be found.
;
STATUS_SYSTEM_DEVICE_NOT_FOUND   EQU 0C0000452h

;
; MessageId: STATUS_RESTART_BOOT_APPLICATION
;
; MessageText:
;
; This boot application must be restarted.
;
STATUS_RESTART_BOOT_APPLICATION  EQU 0C0000453h

;
; MessageId: STATUS_INSUFFICIENT_NVRAM_RESOURCES
;
; MessageText:
;
; Insufficient NVRAM resources exist to complete the API.  A reboot might be required.
;
STATUS_INSUFFICIENT_NVRAM_RESOURCES EQU 0C0000454h    

;
; MessageId: STATUS_INVALID_SESSION
;
; MessageText:
;
; The specified session is invalid.
;
STATUS_INVALID_SESSION           EQU 0C0000455h

;
; MessageId: STATUS_THREAD_ALREADY_IN_SESSION
;
; MessageText:
;
; The specified thread is already in a session.
;
STATUS_THREAD_ALREADY_IN_SESSION EQU 0C0000456h

;
; MessageId: STATUS_THREAD_NOT_IN_SESSION
;
; MessageText:
;
; The specified thread is not in a session.
;
STATUS_THREAD_NOT_IN_SESSION     EQU 0C0000457h

;
; MessageId: STATUS_INVALID_WEIGHT
;
; MessageText:
;
; The specified weight is invalid.
;
STATUS_INVALID_WEIGHT            EQU 0C0000458h

;
; MessageId: STATUS_REQUEST_PAUSED
;
; MessageText:
;
; The operation was paused.
;
STATUS_REQUEST_PAUSED            EQU 0C0000459h

;
; MessageId: STATUS_NO_RANGES_PROCESSED
;
; MessageText:
;
; No ranges for the specified operation were able to be processed.
;
STATUS_NO_RANGES_PROCESSED       EQU 0C0000460h

;
; MessageId: STATUS_DISK_RESOURCES_EXHAUSTED
;
; MessageText:
;
; The physical resources of this disk have been exhausted.
;
STATUS_DISK_RESOURCES_EXHAUSTED  EQU 0C0000461h

;
; MessageId: STATUS_NEEDS_REMEDIATION
;
; MessageText:
;
; The application cannot be started. Try reinstalling the application to fix the problem.
;
STATUS_NEEDS_REMEDIATION         EQU 0C0000462h

;
; MessageId: STATUS_DEVICE_FEATURE_NOT_SUPPORTED
;
; MessageText:
;
; {Device Feature Not Supported}
; The device does not support the command feature.
;
STATUS_DEVICE_FEATURE_NOT_SUPPORTED EQU 0C0000463h

;
; MessageId: STATUS_DEVICE_UNREACHABLE
;
; MessageText:
;
; {Source/Destination device unreachable}
; The device is unreachable.
;
STATUS_DEVICE_UNREACHABLE        EQU 0C0000464h

;
; MessageId: STATUS_INVALID_TOKEN
;
; MessageText:
;
; {Invalid Proxy Data Token}
; The token representing the data is invalid.
;
STATUS_INVALID_TOKEN             EQU 0C0000465h

;
; MessageId: STATUS_SERVER_UNAVAILABLE
;
; MessageText:
;
; The file server is temporarily unavailable.
;
STATUS_SERVER_UNAVAILABLE        EQU 0C0000466h

;
; MessageId: STATUS_FILE_NOT_AVAILABLE
;
; MessageText:
;
; The file is temporarily unavailable.
;
STATUS_FILE_NOT_AVAILABLE        EQU 0C0000467h

;
; MessageId: STATUS_DEVICE_INSUFFICIENT_RESOURCES
;
; MessageText:
;
; {Device Insufficient Resources}
; The target device has insufficient resources to complete the operation.
;
STATUS_DEVICE_INSUFFICIENT_RESOURCES EQU 0C0000468h

;
; MessageId: STATUS_PACKAGE_UPDATING
;
; MessageText:
;
; The application cannot be started because it is currently updating.
;
STATUS_PACKAGE_UPDATING          EQU 0C0000469h

;
; MessageId: STATUS_NOT_READ_FROM_COPY
;
; MessageText:
;
; The specified copy of the requested data could not be read.
;
STATUS_NOT_READ_FROM_COPY        EQU 0C000046Ah

;
; MessageId: STATUS_FT_WRITE_FAILURE
;
; MessageText:
;
; The specified data could not be written to any of the copies.
;
STATUS_FT_WRITE_FAILURE          EQU 0C000046Bh

;
; MessageId: STATUS_FT_DI_SCAN_REQUIRED
;
; MessageText:
;
; One or more copies of data on this device may be out of sync. No writes may be performed until a data integrity scan is completed.
;
STATUS_FT_DI_SCAN_REQUIRED       EQU 0C000046Ch

;
; MessageId: STATUS_OBJECT_NOT_EXTERNALLY_BACKED
;
; MessageText:
;
; This object is not externally backed by any provider.
;
STATUS_OBJECT_NOT_EXTERNALLY_BACKED EQU 0C000046Dh

;
; MessageId: STATUS_EXTERNAL_BACKING_PROVIDER_UNKNOWN
;
; MessageText:
;
; The external backing provider is not recognized.
;
STATUS_EXTERNAL_BACKING_PROVIDER_UNKNOWN EQU 0C000046Eh


;     **** New SYSTEM error codes can be inserted here ****

;
; MessageId: STATUS_DATA_CHECKSUM_ERROR
;
; MessageText:
;
; A data integrity checksum error occurred. Data in the file stream is corrupt.
;
STATUS_DATA_CHECKSUM_ERROR       EQU 0C0000470h

;
; MessageId: STATUS_INTERMIXED_KERNEL_EA_OPERATION
;
; MessageText:
;
; An attempt was made to modify both a KERNEL and normal Extended Attribute (EA) in the same operation.
;
STATUS_INTERMIXED_KERNEL_EA_OPERATION EQU 0C0000471h

;
; MessageId: STATUS_TRIM_READ_ZERO_NOT_SUPPORTED
;
; MessageText:
;
; {LogicalBlockProvisioningReadZero Not Supported}
; The target device does not support read returning zeros from trimmed/unmapped blocks.
;
STATUS_TRIM_READ_ZERO_NOT_SUPPORTED EQU 0C0000472h

;
; MessageId: STATUS_TOO_MANY_SEGMENT_DESCRIPTORS
;
; MessageText:
;
; {Maximum Segment Descriptors Exceeded}
; The command specified a number of descriptors that exceeded the maximum supported by the device.
;
STATUS_TOO_MANY_SEGMENT_DESCRIPTORS EQU 0C0000473h

;
; MessageId: STATUS_INVALID_OFFSET_ALIGNMENT
;
; MessageText:
;
; {Alignment Violation}
; The command specified a data offset that does not align to the device's granularity/alignment.
;
STATUS_INVALID_OFFSET_ALIGNMENT  EQU 0C0000474h

;
; MessageId: STATUS_INVALID_FIELD_IN_PARAMETER_LIST
;
; MessageText:
;
; {Invalid Field In Parameter List}
; The command specified an invalid field in its parameter list.
;
STATUS_INVALID_FIELD_IN_PARAMETER_LIST EQU 0C0000475h

;
; MessageId: STATUS_OPERATION_IN_PROGRESS
;
; MessageText:
;
; {Operation In Progress}
; An operation is currently in progress with the device.
;
STATUS_OPERATION_IN_PROGRESS     EQU 0C0000476h

;
; MessageId: STATUS_INVALID_INITIATOR_TARGET_PATH
;
; MessageText:
;
; {Invalid I_T Nexus}
; An attempt was made to send down the command via an invalid path to the target device.
;
STATUS_INVALID_INITIATOR_TARGET_PATH EQU 0C0000477h

;
; MessageId: STATUS_SCRUB_DATA_DISABLED
;
; MessageText:
;
; Scrub is disabled on the specified file.
;
STATUS_SCRUB_DATA_DISABLED       EQU 0C0000478h

;
; MessageId: STATUS_NOT_REDUNDANT_STORAGE
;
; MessageText:
;
; The storage device does not provide redundancy.
;
STATUS_NOT_REDUNDANT_STORAGE     EQU 0C0000479h

;
; MessageId: STATUS_RESIDENT_FILE_NOT_SUPPORTED
;
; MessageText:
;
; An operation is not supported on a resident file.
;
STATUS_RESIDENT_FILE_NOT_SUPPORTED EQU 0C000047Ah

;
; MessageId: STATUS_COMPRESSED_FILE_NOT_SUPPORTED
;
; MessageText:
;
; An operation is not supported on a compressed file.
;
STATUS_COMPRESSED_FILE_NOT_SUPPORTED EQU 0C000047Bh

;
; MessageId: STATUS_DIRECTORY_NOT_SUPPORTED
;
; MessageText:
;
; An operation is not supported on a directory.
;
STATUS_DIRECTORY_NOT_SUPPORTED   EQU 0C000047Ch

;
; MessageId: STATUS_IO_OPERATION_TIMEOUT
;
; MessageText:
;
; {IO Operation Timeout}
; The specified I/O operation failed to complete within the expected time period.
;
STATUS_IO_OPERATION_TIMEOUT      EQU 0C000047Dh

;
; MessageId: STATUS_SYSTEM_NEEDS_REMEDIATION
;
; MessageText:
;
; An error in a system binary was detected. Try refreshing the PC to fix the problem.
;
STATUS_SYSTEM_NEEDS_REMEDIATION  EQU 0C000047Eh

;
; MessageId: STATUS_APPX_INTEGRITY_FAILURE_CLR_NGEN
;
; MessageText:
;
; A corrupted CLR NGEN binary was detected on the system.
;
STATUS_APPX_INTEGRITY_FAILURE_CLR_NGEN EQU 0C000047Fh

;
; MessageId: STATUS_SHARE_UNAVAILABLE
;
; MessageText:
;
; The share is temporarily unavailable.
;
STATUS_SHARE_UNAVAILABLE         EQU 0C0000480h

;
; MessageId: STATUS_APISET_NOT_HOSTED
;
; MessageText:
;
; The target dll was not found because the apiset %hs is not hosted.
;
STATUS_APISET_NOT_HOSTED         EQU 0C0000481h

;
; MessageId: STATUS_APISET_NOT_PRESENT
;
; MessageText:
;
; The API set extension contains a host for a non-existent API set.
;
STATUS_APISET_NOT_PRESENT        EQU 0C0000482h

;
; MessageId: STATUS_DEVICE_HARDWARE_ERROR
;
; MessageText:
;
; The request failed due to a fatal device hardware error.
;
STATUS_DEVICE_HARDWARE_ERROR     EQU 0C0000483h


;     **** New SYSTEM error codes can be inserted here ****

;
; MessageId: STATUS_INVALID_TASK_NAME
;
; MessageText:
;
; The specified task name is invalid.
;
STATUS_INVALID_TASK_NAME         EQU 0C0000500h

;
; MessageId: STATUS_INVALID_TASK_INDEX
;
; MessageText:
;
; The specified task index is invalid.
;
STATUS_INVALID_TASK_INDEX        EQU 0C0000501h

;
; MessageId: STATUS_THREAD_ALREADY_IN_TASK
;
; MessageText:
;
; The specified thread is already joining a task.
;
STATUS_THREAD_ALREADY_IN_TASK    EQU 0C0000502h

;
; MessageId: STATUS_CALLBACK_BYPASS
;
; MessageText:
;
; A callback has requested to bypass native code.
;
STATUS_CALLBACK_BYPASS           EQU 0C0000503h

;
; MessageId: STATUS_UNDEFINED_SCOPE
;
; MessageText:
;
; The Central Access Policy specified is not defined on the target machine.
;
STATUS_UNDEFINED_SCOPE           EQU 0C0000504h

;
; MessageId: STATUS_INVALID_CAP
;
; MessageText:
;
; The Central Access Policy obtained from Active Directory is invalid.
;
STATUS_INVALID_CAP               EQU 0C0000505h

;
; MessageId: STATUS_NOT_GUI_PROCESS
;
; MessageText:
;
; Unable to finish the requested operation because the specified process is not a GUI process.
;
STATUS_NOT_GUI_PROCESS           EQU 0C0000506h


;     **** New SYSTEM error codes can be inserted here ****

;
; MessageId: STATUS_FAIL_FAST_EXCEPTION
;
; MessageText:
;
; {Fail Fast Exception}
; A fail fast exception occurred. Exception handlers will not be invoked and the process will be terminated immediately.
;
STATUS_FAIL_FAST_EXCEPTION       EQU 0C0000602h

;
; MessageId: STATUS_IMAGE_CERT_REVOKED
;
; MessageText:
;
; Windows cannot verify the digital signature for this file. The signing certificate for this file has been revoked.
;
STATUS_IMAGE_CERT_REVOKED        EQU 0C0000603h

;
; MessageId: STATUS_DYNAMIC_CODE_BLOCKED
;
; MessageText:
;
; The operation was blocked as the process prohibits dynamic code generation.
;
STATUS_DYNAMIC_CODE_BLOCKED      EQU 0C0000604h

;
; MessageId: STATUS_PORT_CLOSED
;
; MessageText:
;
; The ALPC port is closed.
;
STATUS_PORT_CLOSED               EQU 0C0000700h

;
; MessageId: STATUS_MESSAGE_LOST
;
; MessageText:
;
; The ALPC message requested is no longer available.
;
STATUS_MESSAGE_LOST              EQU 0C0000701h

;
; MessageId: STATUS_INVALID_MESSAGE
;
; MessageText:
;
; The ALPC message supplied is invalid.
;
STATUS_INVALID_MESSAGE           EQU 0C0000702h

;
; MessageId: STATUS_REQUEST_CANCELED
;
; MessageText:
;
; The ALPC message has been canceled.
;
STATUS_REQUEST_CANCELED          EQU 0C0000703h

;
; MessageId: STATUS_RECURSIVE_DISPATCH
;
; MessageText:
;
; Invalid recursive dispatch attempt.
;
STATUS_RECURSIVE_DISPATCH        EQU 0C0000704h

;
; MessageId: STATUS_LPC_RECEIVE_BUFFER_EXPECTED
;
; MessageText:
;
; No receive buffer has been supplied in a synchrounus request.
;
STATUS_LPC_RECEIVE_BUFFER_EXPECTED EQU 0C0000705h

;
; MessageId: STATUS_LPC_INVALID_CONNECTION_USAGE
;
; MessageText:
;
; The connection port is used in an invalid context.
;
STATUS_LPC_INVALID_CONNECTION_USAGE EQU 0C0000706h

;
; MessageId: STATUS_LPC_REQUESTS_NOT_ALLOWED
;
; MessageText:
;
; The ALPC port does not accept new request messages.
;
STATUS_LPC_REQUESTS_NOT_ALLOWED  EQU 0C0000707h

;
; MessageId: STATUS_RESOURCE_IN_USE
;
; MessageText:
;
; The resource requested is already in use.
;
STATUS_RESOURCE_IN_USE           EQU 0C0000708h

;
; MessageId: STATUS_HARDWARE_MEMORY_ERROR
;
; MessageText:
;
; The hardware has reported an uncorrectable memory error.
;
STATUS_HARDWARE_MEMORY_ERROR     EQU 0C0000709h

;
; MessageId: STATUS_THREADPOOL_HANDLE_EXCEPTION
;
; MessageText:
;
; Status 0x%08x was returned, waiting on handle 0x%x for wait 0x%p, in waiter 0x%p.
;
STATUS_THREADPOOL_HANDLE_EXCEPTION EQU 0C000070Ah

;
; MessageId: STATUS_THREADPOOL_SET_EVENT_ON_COMPLETION_FAILED
;
; MessageText:
;
; After a callback to 0x%p(0x%p), a completion call to SetEvent(0x%p) failed with status 0x%08x.
;
STATUS_THREADPOOL_SET_EVENT_ON_COMPLETION_FAILED EQU 0C000070Bh

;
; MessageId: STATUS_THREADPOOL_RELEASE_SEMAPHORE_ON_COMPLETION_FAILED
;
; MessageText:
;
; After a callback to 0x%p(0x%p), a completion call to ReleaseSemaphore(0x%p, %d) failed with status 0x%08x.
;
STATUS_THREADPOOL_RELEASE_SEMAPHORE_ON_COMPLETION_FAILED EQU 0C000070Ch

;
; MessageId: STATUS_THREADPOOL_RELEASE_MUTEX_ON_COMPLETION_FAILED
;
; MessageText:
;
; After a callback to 0x%p(0x%p), a completion call to ReleaseMutex(%p) failed with status 0x%08x.
;
STATUS_THREADPOOL_RELEASE_MUTEX_ON_COMPLETION_FAILED EQU 0C000070Dh

;
; MessageId: STATUS_THREADPOOL_FREE_LIBRARY_ON_COMPLETION_FAILED
;
; MessageText:
;
; After a callback to 0x%p(0x%p), an completion call to FreeLibrary(%p) failed with status 0x%08x.
;
STATUS_THREADPOOL_FREE_LIBRARY_ON_COMPLETION_FAILED EQU 0C000070Eh

;
; MessageId: STATUS_THREADPOOL_RELEASED_DURING_OPERATION
;
; MessageText:
;
; The threadpool 0x%p was released while a thread was posting a callback to 0x%p(0x%p) to it.
;
STATUS_THREADPOOL_RELEASED_DURING_OPERATION EQU 0C000070Fh

;
; MessageId: STATUS_CALLBACK_RETURNED_WHILE_IMPERSONATING
;
; MessageText:
;
; A threadpool worker thread is impersonating a client, after a callback to 0x%p(0x%p).
; This is unexpected, indicating that the callback is missing a call to revert the impersonation.
;
STATUS_CALLBACK_RETURNED_WHILE_IMPERSONATING EQU 0C0000710h

;
; MessageId: STATUS_APC_RETURNED_WHILE_IMPERSONATING
;
; MessageText:
;
; A threadpool worker thread is impersonating a client, after executing an APC.
; This is unexpected, indicating that the APC is missing a call to revert the impersonation.
;
STATUS_APC_RETURNED_WHILE_IMPERSONATING EQU 0C0000711h

;
; MessageId: STATUS_PROCESS_IS_PROTECTED
;
; MessageText:
;
; Either the target process, or the target thread's containing process, is a protected process.
;
STATUS_PROCESS_IS_PROTECTED      EQU 0C0000712h

;
; MessageId: STATUS_MCA_EXCEPTION
;
; MessageText:
;
; A Thread is getting dispatched with MCA EXCEPTION because of MCA.
;
STATUS_MCA_EXCEPTION             EQU 0C0000713h

;
; MessageId: STATUS_CERTIFICATE_MAPPING_NOT_UNIQUE
;
; MessageText:
;
; The client certificate account mapping is not unique.
;
STATUS_CERTIFICATE_MAPPING_NOT_UNIQUE EQU 0C0000714h

;
; MessageId: STATUS_SYMLINK_CLASS_DISABLED
;
; MessageText:
;
; The symbolic link cannot be followed because its type is disabled.
;
STATUS_SYMLINK_CLASS_DISABLED    EQU 0C0000715h

;
; MessageId: STATUS_INVALID_IDN_NORMALIZATION
;
; MessageText:
;
; Indicates that the specified string is not valid for IDN normalization.
;
STATUS_INVALID_IDN_NORMALIZATION EQU 0C0000716h

;
; MessageId: STATUS_NO_UNICODE_TRANSLATION
;
; MessageText:
;
; No mapping for the Unicode character exists in the target multi-byte code page.
;
STATUS_NO_UNICODE_TRANSLATION    EQU 0C0000717h

;
; MessageId: STATUS_ALREADY_REGISTERED
;
; MessageText:
;
; The provided callback is already registered.
;
STATUS_ALREADY_REGISTERED        EQU 0C0000718h

;
; MessageId: STATUS_CONTEXT_MISMATCH
;
; MessageText:
;
; The provided context did not match the target.
;
STATUS_CONTEXT_MISMATCH          EQU 0C0000719h

;
; MessageId: STATUS_PORT_ALREADY_HAS_COMPLETION_LIST
;
; MessageText:
;
; The specified port already has a completion list.
;
STATUS_PORT_ALREADY_HAS_COMPLETION_LIST EQU 0C000071Ah

;
; MessageId: STATUS_CALLBACK_RETURNED_THREAD_PRIORITY
;
; MessageText:
;
; A threadpool worker thread enter a callback at thread base priority 0x%x and exited at priority 0x%x.
; This is unexpected, indicating that the callback missed restoring the priority.
;
STATUS_CALLBACK_RETURNED_THREAD_PRIORITY EQU 0C000071Bh

;
; MessageId: STATUS_INVALID_THREAD
;
; MessageText:
;
; An invalid thread, handle %p, is specified for this operation. Possibly, a threadpool worker thread was specified.
;
STATUS_INVALID_THREAD            EQU 0C000071Ch

;
; MessageId: STATUS_CALLBACK_RETURNED_TRANSACTION
;
; MessageText:
;
; A threadpool worker thread enter a callback, which left transaction state.
; This is unexpected, indicating that the callback missed clearing the transaction.
;
STATUS_CALLBACK_RETURNED_TRANSACTION EQU 0C000071Dh

;
; MessageId: STATUS_CALLBACK_RETURNED_LDR_LOCK
;
; MessageText:
;
; A threadpool worker thread enter a callback, which left the loader lock held.
; This is unexpected, indicating that the callback missed releasing the lock.
;
STATUS_CALLBACK_RETURNED_LDR_LOCK EQU 0C000071Eh

;
; MessageId: STATUS_CALLBACK_RETURNED_LANG
;
; MessageText:
;
; A threadpool worker thread enter a callback, which left with preferred languages set.
; This is unexpected, indicating that the callback missed clearing them.
;
STATUS_CALLBACK_RETURNED_LANG    EQU 0C000071Fh

;
; MessageId: STATUS_CALLBACK_RETURNED_PRI_BACK
;
; MessageText:
;
; A threadpool worker thread enter a callback, which left with background priorities set.
; This is unexpected, indicating that the callback missed restoring the original priorities.
;
STATUS_CALLBACK_RETURNED_PRI_BACK EQU 0C0000720h

;
; MessageId: STATUS_CALLBACK_RETURNED_THREAD_AFFINITY
;
; MessageText:
;
; A threadpool worker thread enter a callback at thread affinity %p and exited at affinity %p.
; This is unexpected, indicating that the callback missed restoring the priority.
;
STATUS_CALLBACK_RETURNED_THREAD_AFFINITY EQU 0C0000721h

;
; MessageId: STATUS_DISK_REPAIR_DISABLED
;
; MessageText:
;
; The attempted operation required self healing to be enabled.
;
STATUS_DISK_REPAIR_DISABLED      EQU 0C0000800h

;
; MessageId: STATUS_DS_DOMAIN_RENAME_IN_PROGRESS
;
; MessageText:
;
; The Directory Service cannot perform the requested operation because a domain rename operation is in progress.
;
STATUS_DS_DOMAIN_RENAME_IN_PROGRESS EQU 0C0000801h

;
; MessageId: STATUS_DISK_QUOTA_EXCEEDED
;
; MessageText:
;
; The requested file operation failed because the storage quota was exceeded.
; To free up disk space, move files to a different location or delete unnecessary files. For more information, contact your system administrator.
;
STATUS_DISK_QUOTA_EXCEEDED       EQU 0C0000802h

;
; MessageId: STATUS_DATA_LOST_REPAIR
;
; MessageText:
;
; Windows discovered a corruption in the file "%hs".
; This file has now been repaired.
; Please check if any data in the file was lost because of the corruption.
;
STATUS_DATA_LOST_REPAIR          EQU 080000803h

;
; MessageId: STATUS_CONTENT_BLOCKED
;
; MessageText:
;
; The requested file operation failed because the storage policy blocks that type of file. For more information, contact your system administrator.
;
STATUS_CONTENT_BLOCKED           EQU 0C0000804h

;
; MessageId: STATUS_BAD_CLUSTERS
;
; MessageText:
;
; The operation could not be completed due to bad clusters on disk.
;
STATUS_BAD_CLUSTERS              EQU 0C0000805h

;
; MessageId: STATUS_VOLUME_DIRTY
;
; MessageText:
;
; The operation could not be completed because the volume is dirty. Please run chkdsk and try again.
;
STATUS_VOLUME_DIRTY              EQU 0C0000806h

;
; MessageId: STATUS_DISK_REPAIR_REDIRECTED
;
; MessageText:
;
; The volume repair could not be performed while it is online.
; Please schedule to take the volume offline so that it can be repaired.
;
STATUS_DISK_REPAIR_REDIRECTED    EQU 040000807h

;
; MessageId: STATUS_DISK_REPAIR_UNSUCCESSFUL
;
; MessageText:
;
; The volume repair was not successful.
;
STATUS_DISK_REPAIR_UNSUCCESSFUL  EQU 0C0000808h

;
; MessageId: STATUS_CORRUPT_LOG_OVERFULL
;
; MessageText:
;
; One of the volume corruption logs is full. Further corruptions that may be detected won't be logged.
;
STATUS_CORRUPT_LOG_OVERFULL      EQU 0C0000809h

;
; MessageId: STATUS_CORRUPT_LOG_CORRUPTED
;
; MessageText:
;
; One of the volume corruption logs is internally corrupted and needs to be recreated. The volume may contain undetected corruptions and must be scanned.
;
STATUS_CORRUPT_LOG_CORRUPTED     EQU 0C000080Ah

;
; MessageId: STATUS_CORRUPT_LOG_UNAVAILABLE
;
; MessageText:
;
; One of the volume corruption logs is unavailable for being operated on.
;
STATUS_CORRUPT_LOG_UNAVAILABLE   EQU 0C000080Bh

;
; MessageId: STATUS_CORRUPT_LOG_DELETED_FULL
;
; MessageText:
;
; One of the volume corruption logs was deleted while still having corruption records in them. The volume contains detected corruptions and must be scanned.
;
STATUS_CORRUPT_LOG_DELETED_FULL  EQU 0C000080Ch

;
; MessageId: STATUS_CORRUPT_LOG_CLEARED
;
; MessageText:
;
; One of the volume corruption logs was cleared by chkdsk and no longer contains real corruptions.
;
STATUS_CORRUPT_LOG_CLEARED       EQU 0C000080Dh

;
; MessageId: STATUS_ORPHAN_NAME_EXHAUSTED
;
; MessageText:
;
; Orphaned files exist on the volume but could not be recovered because no more new names could be created in the recovery directory. Files must be moved from the recovery directory.
;
STATUS_ORPHAN_NAME_EXHAUSTED     EQU 0C000080Eh

;
; MessageId: STATUS_PROACTIVE_SCAN_IN_PROGRESS
;
; MessageText:
;
; The operation could not be completed because an instance of Proactive Scanner is currently running.
;
STATUS_PROACTIVE_SCAN_IN_PROGRESS EQU 0C000080Fh

;
; MessageId: STATUS_ENCRYPTED_IO_NOT_POSSIBLE
;
; MessageText:
;
; The read or write operation to an encrypted file could not be completed because the file has not been opened for data access.
;
STATUS_ENCRYPTED_IO_NOT_POSSIBLE EQU 0C0000810h

;
; MessageId: STATUS_CORRUPT_LOG_UPLEVEL_RECORDS
;
; MessageText:
;
; One of the volume corruption logs comes from a newer version of Windows and contains corruption records. The log will be emptied and reset to the current version, and the volume health state will be updated accordingly.
;
STATUS_CORRUPT_LOG_UPLEVEL_RECORDS EQU 0C0000811h

;
; MessageId: STATUS_FILE_CHECKED_OUT
;
; MessageText:
;
; This file is checked out or locked for editing by another user.
;
STATUS_FILE_CHECKED_OUT          EQU 0C0000901h

;
; MessageId: STATUS_CHECKOUT_REQUIRED
;
; MessageText:
;
; The file must be checked out before saving changes.
;
STATUS_CHECKOUT_REQUIRED         EQU 0C0000902h

;
; MessageId: STATUS_BAD_FILE_TYPE
;
; MessageText:
;
; The file type being saved or retrieved has been blocked.
;
STATUS_BAD_FILE_TYPE             EQU 0C0000903h

;
; MessageId: STATUS_FILE_TOO_LARGE
;
; MessageText:
;
; The file size exceeds the limit allowed and cannot be saved.
;
STATUS_FILE_TOO_LARGE            EQU 0C0000904h

;
; MessageId: STATUS_FORMS_AUTH_REQUIRED
;
; MessageText:
;
; Access Denied. Before opening files in this location, you must first browse to the web site and select the option to login automatically.
;
STATUS_FORMS_AUTH_REQUIRED       EQU 0C0000905h

;
; MessageId: STATUS_VIRUS_INFECTED
;
; MessageText:
;
; Operation did not complete successfully because the file contains a virus or potentially unwanted software.
;
STATUS_VIRUS_INFECTED            EQU 0C0000906h

;
; MessageId: STATUS_VIRUS_DELETED
;
; MessageText:
;
; This file contains a virus or potentially unwanted software and cannot be opened. Due to the nature of this virus or potentially unwanted software, the file has been removed from this location.
;
STATUS_VIRUS_DELETED             EQU 0C0000907h

;
; MessageId: STATUS_BAD_MCFG_TABLE
;
; MessageText:
;
; The resources required for this device conflict with the MCFG table.
;
STATUS_BAD_MCFG_TABLE            EQU 0C0000908h

;
; MessageId: STATUS_CANNOT_BREAK_OPLOCK
;
; MessageText:
;
; The operation did not complete successfully because it would cause an oplock to be broken. The caller has requested that existing oplocks not be broken.
;
STATUS_CANNOT_BREAK_OPLOCK       EQU 0C0000909h

;
; MessageId: STATUS_BAD_KEY
;
; MessageText:
;
; Bad key.
;
STATUS_BAD_KEY                   EQU 0C000090Ah

;
; MessageId: STATUS_BAD_DATA
;
; MessageText:
;
; Bad data.
;
STATUS_BAD_DATA                  EQU 0C000090Bh

;
; MessageId: STATUS_NO_KEY
;
; MessageText:
;
; Key does not exist.
;
STATUS_NO_KEY                    EQU 0C000090Ch

;
; MessageId: STATUS_FILE_HANDLE_REVOKED
;
; MessageText:
;
; Access to the specified file handle has been revoked.
;
STATUS_FILE_HANDLE_REVOKED       EQU 0C0000910h

;
; MessageId: STATUS_WOW_ASSERTION
;
; MessageText:
;
; WOW Assertion Error.
;
STATUS_WOW_ASSERTION             EQU 0C0009898h

;
; MessageId: STATUS_INVALID_SIGNATURE
;
; MessageText:
;
; The cryptographic signature is invalid.
;
STATUS_INVALID_SIGNATURE         EQU 0C000A000h

;
; MessageId: STATUS_HMAC_NOT_SUPPORTED
;
; MessageText:
;
; The cryptographic provider does not support HMAC.
;
STATUS_HMAC_NOT_SUPPORTED        EQU 0C000A001h

;
; MessageId: STATUS_AUTH_TAG_MISMATCH
;
; MessageText:
;
; The computed authentication tag did not match the input authentication tag.
;
STATUS_AUTH_TAG_MISMATCH         EQU 0C000A002h

;
; MessageId: STATUS_INVALID_STATE_TRANSITION
;
; MessageText:
;
; The requested state transition is invalid and cannot be performed.
;
STATUS_INVALID_STATE_TRANSITION  EQU 0C000A003h

;
; MessageId: STATUS_INVALID_KERNEL_INFO_VERSION
;
; MessageText:
;
; The supplied kernel information version is invalid.
;
STATUS_INVALID_KERNEL_INFO_VERSION EQU 0C000A004h

;
; MessageId: STATUS_INVALID_PEP_INFO_VERSION
;
; MessageText:
;
; The supplied PEP information version is invalid.
;
STATUS_INVALID_PEP_INFO_VERSION  EQU 0C000A005h

;
;
; MessageId's 0xa010 - 0xa07f (inclusive) are reserved for TCPIP errors.
;
;

;
; MessageId: STATUS_IPSEC_QUEUE_OVERFLOW
;
; MessageText:
;
; The IPSEC queue overflowed.
;
STATUS_IPSEC_QUEUE_OVERFLOW      EQU 0C000A010h

;
; MessageId: STATUS_ND_QUEUE_OVERFLOW
;
; MessageText:
;
; The neighbor discovery queue overflowed.
;
STATUS_ND_QUEUE_OVERFLOW         EQU 0C000A011h

;
; MessageId: STATUS_HOPLIMIT_EXCEEDED
;
; MessageText:
;
; An ICMP hop limit exceeded error was received.
;
STATUS_HOPLIMIT_EXCEEDED         EQU 0C000A012h

;
; MessageId: STATUS_PROTOCOL_NOT_SUPPORTED
;
; MessageText:
;
; The protocol is not installed on the local machine.
;
STATUS_PROTOCOL_NOT_SUPPORTED    EQU 0C000A013h

;
; MessageId: STATUS_FASTPATH_REJECTED
;
; MessageText:
;
; An operation or data has been rejected while on the network fast path.
;
STATUS_FASTPATH_REJECTED         EQU 0C000A014h

;
;
; MessageId's 0xa014 - 0xa07f (inclusive) are reserved for TCPIP errors.
;
;

;
; MessageId: STATUS_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED
;
; MessageText:
;
; {Delayed Write Failed}
; Windows was unable to save all the data for the file %hs; the data has been lost.
; This error may be caused by network connectivity issues. Please try to save this file elsewhere.
;
STATUS_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED EQU 0C000A080h

;
; MessageId: STATUS_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR
;
; MessageText:
;
; {Delayed Write Failed}
; Windows was unable to save all the data for the file %hs; the data has been lost.
; This error was returned by the server on which the file exists. Please try to save this file elsewhere.
;
STATUS_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR EQU 0C000A081h

;
; MessageId: STATUS_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR
;
; MessageText:
;
; {Delayed Write Failed}
; Windows was unable to save all the data for the file %hs; the data has been lost.
; This error may be caused if the device has been removed or the media is write-protected.
;
STATUS_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR EQU 0C000A082h

;
; MessageId: STATUS_XML_PARSE_ERROR
;
; MessageText:
;
; Windows was unable to parse the requested XML data.
;
STATUS_XML_PARSE_ERROR           EQU 0C000A083h

;
; MessageId: STATUS_XMLDSIG_ERROR
;
; MessageText:
;
; An error was encountered while processing an XML digital signature.
;
STATUS_XMLDSIG_ERROR             EQU 0C000A084h

;
; MessageId: STATUS_WRONG_COMPARTMENT
;
; MessageText:
;
; Indicates that the caller made the connection request in the wrong routing compartment.
;
STATUS_WRONG_COMPARTMENT         EQU 0C000A085h

;
; MessageId: STATUS_AUTHIP_FAILURE
;
; MessageText:
;
; Indicates that there was an AuthIP failure when attempting to connect to the remote host.
;
STATUS_AUTHIP_FAILURE            EQU 0C000A086h

;
; MessageId: STATUS_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS
;
; MessageText:
;
; OID mapped groups cannot have members.
;
STATUS_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS EQU 0C000A087h

;
; MessageId: STATUS_DS_OID_NOT_FOUND
;
; MessageText:
;
; The specified OID cannot be found.
;
STATUS_DS_OID_NOT_FOUND          EQU 0C000A088h

;
; MessageId: STATUS_INCORRECT_ACCOUNT_TYPE
;
; MessageText:
;
; The system is not authoritative for the specified account and therefore cannot complete the operation. Please retry the operation using the provider associated with this account. If this is an online provider please use the provider's online site.
;
STATUS_INCORRECT_ACCOUNT_TYPE    EQU 0C000A089h

;
;
; MessageId's 0xa100 - 0xa120 (inclusive) are for the SMB Hash Generation Service.
;
;

;
; MessageId: STATUS_HASH_NOT_SUPPORTED
;
; MessageText:
;
; Hash generation for the specified version and hash type is not enabled on server.
;
STATUS_HASH_NOT_SUPPORTED        EQU 0C000A100h

;
; MessageId: STATUS_HASH_NOT_PRESENT
;
; MessageText:
;
; The hash requests is not present or not up to date with the current file contents.
;
STATUS_HASH_NOT_PRESENT          EQU 0C000A101h

;
;
; MessageId's 0xa121 - 0xa140 (inclusive) are for GPIO (General Purpose I/O) controller related errors.
;
;

;
; MessageId: STATUS_SECONDARY_IC_PROVIDER_NOT_REGISTERED
;
; MessageText:
;
; The secondary interrupt controller instance that manages the specified interrupt is not registered.
;
STATUS_SECONDARY_IC_PROVIDER_NOT_REGISTERED EQU 0C000A121h

;
; MessageId: STATUS_GPIO_CLIENT_INFORMATION_INVALID
;
; MessageText:
;
; The information supplied by the GPIO client driver is invalid.
;
STATUS_GPIO_CLIENT_INFORMATION_INVALID EQU 0C000A122h

;
; MessageId: STATUS_GPIO_VERSION_NOT_SUPPORTED
;
; MessageText:
;
; The version specified by the GPIO client driver is not supported.
;
STATUS_GPIO_VERSION_NOT_SUPPORTED EQU 0C000A123h

;
; MessageId: STATUS_GPIO_INVALID_REGISTRATION_PACKET
;
; MessageText:
;
; The registration packet supplied by the GPIO client driver is not valid.
;
STATUS_GPIO_INVALID_REGISTRATION_PACKET EQU 0C000A124h

;
; MessageId: STATUS_GPIO_OPERATION_DENIED
;
; MessageText:
;
; The requested operation is not suppported for the specified handle.
;
STATUS_GPIO_OPERATION_DENIED     EQU 0C000A125h

;
; MessageId: STATUS_GPIO_INCOMPATIBLE_CONNECT_MODE
;
; MessageText:
;
; The requested connect mode conflicts with an existing mode on one or more of the specified pins.
;
STATUS_GPIO_INCOMPATIBLE_CONNECT_MODE EQU 0C000A126h

;
; MessageId: STATUS_GPIO_INTERRUPT_ALREADY_UNMASKED
;
; MessageText:
;
; The interrupt requested to be unmasked is not masked.
;
STATUS_GPIO_INTERRUPT_ALREADY_UNMASKED EQU 08000A127h

;
;
; MessageId's 0xa141 - 0xa160 (inclusive) are for run levels support.
;
;

;
; MessageId: STATUS_CANNOT_SWITCH_RUNLEVEL
;
; MessageText:
;
; The requested run level switch cannot be completed successfully since
; one or more services refused to stop or restart.
;
STATUS_CANNOT_SWITCH_RUNLEVEL    EQU 0C000A141h

;
; MessageId: STATUS_INVALID_RUNLEVEL_SETTING
;
; MessageText:
;
; The service has an invalid run level setting. The run level for a service
; must not be higher than the run level of its dependent services.
;
STATUS_INVALID_RUNLEVEL_SETTING  EQU 0C000A142h

;
; MessageId: STATUS_RUNLEVEL_SWITCH_TIMEOUT
;
; MessageText:
;
; The requested run level switch cannot be completed successfully since
; one or more services will not stop or restart within the specified timeout.
;
STATUS_RUNLEVEL_SWITCH_TIMEOUT   EQU 0C000A143h

;
; MessageId: STATUS_SERVICES_FAILED_AUTOSTART
;
; MessageText:
;
; One or more services failed to start during the service startup phase of a run level switch.
;
STATUS_SERVICES_FAILED_AUTOSTART EQU 04000A144h

;
; MessageId: STATUS_RUNLEVEL_SWITCH_AGENT_TIMEOUT
;
; MessageText:
;
; A run level switch agent did not respond within the specified timeout.
;
STATUS_RUNLEVEL_SWITCH_AGENT_TIMEOUT EQU 0C000A145h

;
; MessageId: STATUS_RUNLEVEL_SWITCH_IN_PROGRESS
;
; MessageText:
;
; A run level switch is currently in progress.
;
STATUS_RUNLEVEL_SWITCH_IN_PROGRESS EQU 0C000A146h

;
;
; MessageId's 0xa200 - 0xa280 (inclusive) are reserved for app container specific messages.
;
;

;
; MessageId: STATUS_NOT_APPCONTAINER
;
; MessageText:
;
; This operation is only valid in the context of an app container.
;
STATUS_NOT_APPCONTAINER          EQU 0C000A200h

;
; MessageId: STATUS_NOT_SUPPORTED_IN_APPCONTAINER
;
; MessageText:
;
; This functionality is not supported in the context of an app container.
;
STATUS_NOT_SUPPORTED_IN_APPCONTAINER EQU 0C000A201h

;
; MessageId: STATUS_INVALID_PACKAGE_SID_LENGTH
;
; MessageText:
;
; The length of the SID supplied is not a valid length for app container SIDs.
;
STATUS_INVALID_PACKAGE_SID_LENGTH EQU 0C000A202h

;
;
; MessageId's 0xa281 - 0xa2a0 (inclusive) are reserved for Fast Cache specific messages.
;
;

;
; MessageId: STATUS_APP_DATA_NOT_FOUND
;
; MessageText:
;
; Fast Cache data not found.
;
STATUS_APP_DATA_NOT_FOUND        EQU 0C000A281h

;
; MessageId: STATUS_APP_DATA_EXPIRED
;
; MessageText:
;
; Fast Cache data expired.
;
STATUS_APP_DATA_EXPIRED          EQU 0C000A282h

;
; MessageId: STATUS_APP_DATA_CORRUPT
;
; MessageText:
;
; Fast Cache data corrupt.
;
STATUS_APP_DATA_CORRUPT          EQU 0C000A283h

;
; MessageId: STATUS_APP_DATA_LIMIT_EXCEEDED
;
; MessageText:
;
; Fast Cache data has exceeded its max size and cannot be updated.
;
STATUS_APP_DATA_LIMIT_EXCEEDED   EQU 0C000A284h

;
; MessageId: STATUS_APP_DATA_REBOOT_REQUIRED
;
; MessageText:
;
; Fast Cache has been ReArmed and requires a reboot until it can be updated.
;
STATUS_APP_DATA_REBOOT_REQUIRED  EQU 0C000A285h

;
;
; MessageId's 0xa2a1 - 0xa300 (inclusive) are for File System Filters Supported Features specific messages.
;
;

;
; MessageId: STATUS_OFFLOAD_READ_FLT_NOT_SUPPORTED
;
; MessageText:
;
; The copy offload read operation is not supported by a filter.
;
STATUS_OFFLOAD_READ_FLT_NOT_SUPPORTED EQU 0C000A2A1h

;
; MessageId: STATUS_OFFLOAD_WRITE_FLT_NOT_SUPPORTED
;
; MessageText:
;
; The copy offload write operation is not supported by a filter.
;
STATUS_OFFLOAD_WRITE_FLT_NOT_SUPPORTED EQU 0C000A2A2h

;
; MessageId: STATUS_OFFLOAD_READ_FILE_NOT_SUPPORTED
;
; MessageText:
;
; The copy offload read operation is not supported for the file.
;
STATUS_OFFLOAD_READ_FILE_NOT_SUPPORTED EQU 0C000A2A3h

;
; MessageId: STATUS_OFFLOAD_WRITE_FILE_NOT_SUPPORTED
;
; MessageText:
;
; The copy offload write operation is not supported for the file.
;
STATUS_OFFLOAD_WRITE_FILE_NOT_SUPPORTED EQU 0C000A2A4h


;
;  Debugger error values
;

;
; MessageId: DBG_NO_STATE_CHANGE
;
; MessageText:
;
; Debugger did not perform a state change.
;
DBG_NO_STATE_CHANGE              EQU 0C0010001h

;
; MessageId: DBG_APP_NOT_IDLE
;
; MessageText:
;
; Debugger has found the application is not idle.
;
DBG_APP_NOT_IDLE                 EQU 0C0010002h


;
;  RPC error values
;

;
; MessageId: RPC_NT_INVALID_STRING_BINDING
;
; MessageText:
;
; The string binding is invalid.
;
RPC_NT_INVALID_STRING_BINDING    EQU 0C0020001h

;
; MessageId: RPC_NT_WRONG_KIND_OF_BINDING
;
; MessageText:
;
; The binding handle is not the correct type.
;
RPC_NT_WRONG_KIND_OF_BINDING     EQU 0C0020002h

;
; MessageId: RPC_NT_INVALID_BINDING
;
; MessageText:
;
; The binding handle is invalid.
;
RPC_NT_INVALID_BINDING           EQU 0C0020003h

;
; MessageId: RPC_NT_PROTSEQ_NOT_SUPPORTED
;
; MessageText:
;
; The RPC protocol sequence is not supported.
;
RPC_NT_PROTSEQ_NOT_SUPPORTED     EQU 0C0020004h

;
; MessageId: RPC_NT_INVALID_RPC_PROTSEQ
;
; MessageText:
;
; The RPC protocol sequence is invalid.
;
RPC_NT_INVALID_RPC_PROTSEQ       EQU 0C0020005h

;
; MessageId: RPC_NT_INVALID_STRING_UUID
;
; MessageText:
;
; The string UUID is invalid.
;
RPC_NT_INVALID_STRING_UUID       EQU 0C0020006h

;
; MessageId: RPC_NT_INVALID_ENDPOINT_FORMAT
;
; MessageText:
;
; The endpoint format is invalid.
;
RPC_NT_INVALID_ENDPOINT_FORMAT   EQU 0C0020007h

;
; MessageId: RPC_NT_INVALID_NET_ADDR
;
; MessageText:
;
; The network address is invalid.
;
RPC_NT_INVALID_NET_ADDR          EQU 0C0020008h

;
; MessageId: RPC_NT_NO_ENDPOINT_FOUND
;
; MessageText:
;
; No endpoint was found.
;
RPC_NT_NO_ENDPOINT_FOUND         EQU 0C0020009h

;
; MessageId: RPC_NT_INVALID_TIMEOUT
;
; MessageText:
;
; The timeout value is invalid.
;
RPC_NT_INVALID_TIMEOUT           EQU 0C002000Ah

;
; MessageId: RPC_NT_OBJECT_NOT_FOUND
;
; MessageText:
;
; The object UUID was not found.
;
RPC_NT_OBJECT_NOT_FOUND          EQU 0C002000Bh

;
; MessageId: RPC_NT_ALREADY_REGISTERED
;
; MessageText:
;
; The object UUID has already been registered.
;
RPC_NT_ALREADY_REGISTERED        EQU 0C002000Ch

;
; MessageId: RPC_NT_TYPE_ALREADY_REGISTERED
;
; MessageText:
;
; The type UUID has already been registered.
;
RPC_NT_TYPE_ALREADY_REGISTERED   EQU 0C002000Dh

;
; MessageId: RPC_NT_ALREADY_LISTENING
;
; MessageText:
;
; The RPC server is already listening.
;
RPC_NT_ALREADY_LISTENING         EQU 0C002000Eh

;
; MessageId: RPC_NT_NO_PROTSEQS_REGISTERED
;
; MessageText:
;
; No protocol sequences have been registered.
;
RPC_NT_NO_PROTSEQS_REGISTERED    EQU 0C002000Fh

;
; MessageId: RPC_NT_NOT_LISTENING
;
; MessageText:
;
; The RPC server is not listening.
;
RPC_NT_NOT_LISTENING             EQU 0C0020010h

;
; MessageId: RPC_NT_UNKNOWN_MGR_TYPE
;
; MessageText:
;
; The manager type is unknown.
;
RPC_NT_UNKNOWN_MGR_TYPE          EQU 0C0020011h

;
; MessageId: RPC_NT_UNKNOWN_IF
;
; MessageText:
;
; The interface is unknown.
;
RPC_NT_UNKNOWN_IF                EQU 0C0020012h

;
; MessageId: RPC_NT_NO_BINDINGS
;
; MessageText:
;
; There are no bindings.
;
RPC_NT_NO_BINDINGS               EQU 0C0020013h

;
; MessageId: RPC_NT_NO_PROTSEQS
;
; MessageText:
;
; There are no protocol sequences.
;
RPC_NT_NO_PROTSEQS               EQU 0C0020014h

;
; MessageId: RPC_NT_CANT_CREATE_ENDPOINT
;
; MessageText:
;
; The endpoint cannot be created.
;
RPC_NT_CANT_CREATE_ENDPOINT      EQU 0C0020015h

;
; MessageId: RPC_NT_OUT_OF_RESOURCES
;
; MessageText:
;
; Not enough resources are available to complete this operation.
;
RPC_NT_OUT_OF_RESOURCES          EQU 0C0020016h

;
; MessageId: RPC_NT_SERVER_UNAVAILABLE
;
; MessageText:
;
; The RPC server is unavailable.
;
RPC_NT_SERVER_UNAVAILABLE        EQU 0C0020017h

;
; MessageId: RPC_NT_SERVER_TOO_BUSY
;
; MessageText:
;
; The RPC server is too busy to complete this operation.
;
RPC_NT_SERVER_TOO_BUSY           EQU 0C0020018h

;
; MessageId: RPC_NT_INVALID_NETWORK_OPTIONS
;
; MessageText:
;
; The network options are invalid.
;
RPC_NT_INVALID_NETWORK_OPTIONS   EQU 0C0020019h

;
; MessageId: RPC_NT_NO_CALL_ACTIVE
;
; MessageText:
;
; There are no remote procedure calls active on this thread.
;
RPC_NT_NO_CALL_ACTIVE            EQU 0C002001Ah

;
; MessageId: RPC_NT_CALL_FAILED
;
; MessageText:
;
; The remote procedure call failed.
;
RPC_NT_CALL_FAILED               EQU 0C002001Bh

;
; MessageId: RPC_NT_CALL_FAILED_DNE
;
; MessageText:
;
; The remote procedure call failed and did not execute.
;
RPC_NT_CALL_FAILED_DNE           EQU 0C002001Ch

;
; MessageId: RPC_NT_PROTOCOL_ERROR
;
; MessageText:
;
; An RPC protocol error occurred.
;
RPC_NT_PROTOCOL_ERROR            EQU 0C002001Dh

;
; MessageId: RPC_NT_UNSUPPORTED_TRANS_SYN
;
; MessageText:
;
; The transfer syntax is not supported by the RPC server.
;
RPC_NT_UNSUPPORTED_TRANS_SYN     EQU 0C002001Fh

;
; MessageId: RPC_NT_UNSUPPORTED_TYPE
;
; MessageText:
;
; The type UUID is not supported.
;
RPC_NT_UNSUPPORTED_TYPE          EQU 0C0020021h

;
; MessageId: RPC_NT_INVALID_TAG
;
; MessageText:
;
; The tag is invalid.
;
RPC_NT_INVALID_TAG               EQU 0C0020022h

;
; MessageId: RPC_NT_INVALID_BOUND
;
; MessageText:
;
; The array bounds are invalid.
;
RPC_NT_INVALID_BOUND             EQU 0C0020023h

;
; MessageId: RPC_NT_NO_ENTRY_NAME
;
; MessageText:
;
; The binding does not contain an entry name.
;
RPC_NT_NO_ENTRY_NAME             EQU 0C0020024h

;
; MessageId: RPC_NT_INVALID_NAME_SYNTAX
;
; MessageText:
;
; The name syntax is invalid.
;
RPC_NT_INVALID_NAME_SYNTAX       EQU 0C0020025h

;
; MessageId: RPC_NT_UNSUPPORTED_NAME_SYNTAX
;
; MessageText:
;
; The name syntax is not supported.
;
RPC_NT_UNSUPPORTED_NAME_SYNTAX   EQU 0C0020026h

;
; MessageId: RPC_NT_UUID_NO_ADDRESS
;
; MessageText:
;
; No network address is available to use to construct a UUID.
;
RPC_NT_UUID_NO_ADDRESS           EQU 0C0020028h

;
; MessageId: RPC_NT_DUPLICATE_ENDPOINT
;
; MessageText:
;
; The endpoint is a duplicate.
;
RPC_NT_DUPLICATE_ENDPOINT        EQU 0C0020029h

;
; MessageId: RPC_NT_UNKNOWN_AUTHN_TYPE
;
; MessageText:
;
; The authentication type is unknown.
;
RPC_NT_UNKNOWN_AUTHN_TYPE        EQU 0C002002Ah

;
; MessageId: RPC_NT_MAX_CALLS_TOO_SMALL
;
; MessageText:
;
; The maximum number of calls is too small.
;
RPC_NT_MAX_CALLS_TOO_SMALL       EQU 0C002002Bh

;
; MessageId: RPC_NT_STRING_TOO_LONG
;
; MessageText:
;
; The string is too long.
;
RPC_NT_STRING_TOO_LONG           EQU 0C002002Ch

;
; MessageId: RPC_NT_PROTSEQ_NOT_FOUND
;
; MessageText:
;
; The RPC protocol sequence was not found.
;
RPC_NT_PROTSEQ_NOT_FOUND         EQU 0C002002Dh

;
; MessageId: RPC_NT_PROCNUM_OUT_OF_RANGE
;
; MessageText:
;
; The procedure number is out of range.
;
RPC_NT_PROCNUM_OUT_OF_RANGE      EQU 0C002002Eh

;
; MessageId: RPC_NT_BINDING_HAS_NO_AUTH
;
; MessageText:
;
; The binding does not contain any authentication information.
;
RPC_NT_BINDING_HAS_NO_AUTH       EQU 0C002002Fh

;
; MessageId: RPC_NT_UNKNOWN_AUTHN_SERVICE
;
; MessageText:
;
; The authentication service is unknown.
;
RPC_NT_UNKNOWN_AUTHN_SERVICE     EQU 0C0020030h

;
; MessageId: RPC_NT_UNKNOWN_AUTHN_LEVEL
;
; MessageText:
;
; The authentication level is unknown.
;
RPC_NT_UNKNOWN_AUTHN_LEVEL       EQU 0C0020031h

;
; MessageId: RPC_NT_INVALID_AUTH_IDENTITY
;
; MessageText:
;
; The security context is invalid.
;
RPC_NT_INVALID_AUTH_IDENTITY     EQU 0C0020032h

;
; MessageId: RPC_NT_UNKNOWN_AUTHZ_SERVICE
;
; MessageText:
;
; The authorization service is unknown.
;
RPC_NT_UNKNOWN_AUTHZ_SERVICE     EQU 0C0020033h

;
; MessageId: EPT_NT_INVALID_ENTRY
;
; MessageText:
;
; The entry is invalid.
;
EPT_NT_INVALID_ENTRY             EQU 0C0020034h

;
; MessageId: EPT_NT_CANT_PERFORM_OP
;
; MessageText:
;
; The operation cannot be performed.
;
EPT_NT_CANT_PERFORM_OP           EQU 0C0020035h

;
; MessageId: EPT_NT_NOT_REGISTERED
;
; MessageText:
;
; There are no more endpoints available from the endpoint mapper.
;
EPT_NT_NOT_REGISTERED            EQU 0C0020036h

;
; MessageId: RPC_NT_NOTHING_TO_EXPORT
;
; MessageText:
;
; No interfaces have been exported.
;
RPC_NT_NOTHING_TO_EXPORT         EQU 0C0020037h

;
; MessageId: RPC_NT_INCOMPLETE_NAME
;
; MessageText:
;
; The entry name is incomplete.
;
RPC_NT_INCOMPLETE_NAME           EQU 0C0020038h

;
; MessageId: RPC_NT_INVALID_VERS_OPTION
;
; MessageText:
;
; The version option is invalid.
;
RPC_NT_INVALID_VERS_OPTION       EQU 0C0020039h

;
; MessageId: RPC_NT_NO_MORE_MEMBERS
;
; MessageText:
;
; There are no more members.
;
RPC_NT_NO_MORE_MEMBERS           EQU 0C002003Ah

;
; MessageId: RPC_NT_NOT_ALL_OBJS_UNEXPORTED
;
; MessageText:
;
; There is nothing to unexport.
;
RPC_NT_NOT_ALL_OBJS_UNEXPORTED   EQU 0C002003Bh

;
; MessageId: RPC_NT_INTERFACE_NOT_FOUND
;
; MessageText:
;
; The interface was not found.
;
RPC_NT_INTERFACE_NOT_FOUND       EQU 0C002003Ch

;
; MessageId: RPC_NT_ENTRY_ALREADY_EXISTS
;
; MessageText:
;
; The entry already exists.
;
RPC_NT_ENTRY_ALREADY_EXISTS      EQU 0C002003Dh

;
; MessageId: RPC_NT_ENTRY_NOT_FOUND
;
; MessageText:
;
; The entry is not found.
;
RPC_NT_ENTRY_NOT_FOUND           EQU 0C002003Eh

;
; MessageId: RPC_NT_NAME_SERVICE_UNAVAILABLE
;
; MessageText:
;
; The name service is unavailable.
;
RPC_NT_NAME_SERVICE_UNAVAILABLE  EQU 0C002003Fh

;
; MessageId: RPC_NT_INVALID_NAF_ID
;
; MessageText:
;
; The network address family is invalid.
;
RPC_NT_INVALID_NAF_ID            EQU 0C0020040h

;
; MessageId: RPC_NT_CANNOT_SUPPORT
;
; MessageText:
;
; The requested operation is not supported.
;
RPC_NT_CANNOT_SUPPORT            EQU 0C0020041h

;
; MessageId: RPC_NT_NO_CONTEXT_AVAILABLE
;
; MessageText:
;
; No security context is available to allow impersonation.
;
RPC_NT_NO_CONTEXT_AVAILABLE      EQU 0C0020042h

;
; MessageId: RPC_NT_INTERNAL_ERROR
;
; MessageText:
;
; An internal error occurred in RPC.
;
RPC_NT_INTERNAL_ERROR            EQU 0C0020043h

;
; MessageId: RPC_NT_ZERO_DIVIDE
;
; MessageText:
;
; The RPC server attempted an integer divide by zero.
;
RPC_NT_ZERO_DIVIDE               EQU 0C0020044h

;
; MessageId: RPC_NT_ADDRESS_ERROR
;
; MessageText:
;
; An addressing error occurred in the RPC server.
;
RPC_NT_ADDRESS_ERROR             EQU 0C0020045h

;
; MessageId: RPC_NT_FP_DIV_ZERO
;
; MessageText:
;
; A floating point operation at the RPC server caused a divide by zero.
;
RPC_NT_FP_DIV_ZERO               EQU 0C0020046h

;
; MessageId: RPC_NT_FP_UNDERFLOW
;
; MessageText:
;
; A floating point underflow occurred at the RPC server.
;
RPC_NT_FP_UNDERFLOW              EQU 0C0020047h

;
; MessageId: RPC_NT_FP_OVERFLOW
;
; MessageText:
;
; A floating point overflow occurred at the RPC server.
;
RPC_NT_FP_OVERFLOW               EQU 0C0020048h

;
; MessageId: RPC_NT_NO_MORE_ENTRIES
;
; MessageText:
;
; The list of RPC servers available for auto-handle binding has been exhausted.
;
RPC_NT_NO_MORE_ENTRIES           EQU 0C0030001h

;
; MessageId: RPC_NT_SS_CHAR_TRANS_OPEN_FAIL
;
; MessageText:
;
; The file designated by DCERPCCHARTRANS cannot be opened.
;
RPC_NT_SS_CHAR_TRANS_OPEN_FAIL   EQU 0C0030002h

;
; MessageId: RPC_NT_SS_CHAR_TRANS_SHORT_FILE
;
; MessageText:
;
; The file containing the character translation table has fewer than 512 bytes.
;
RPC_NT_SS_CHAR_TRANS_SHORT_FILE  EQU 0C0030003h

;
; MessageId: RPC_NT_SS_IN_NULL_CONTEXT
;
; MessageText:
;
; A null context handle is passed as an [in] parameter.
;
RPC_NT_SS_IN_NULL_CONTEXT        EQU 0C0030004h

;
; MessageId: RPC_NT_SS_CONTEXT_MISMATCH
;
; MessageText:
;
; The context handle does not match any known context handles.
;
RPC_NT_SS_CONTEXT_MISMATCH       EQU 0C0030005h

;
; MessageId: RPC_NT_SS_CONTEXT_DAMAGED
;
; MessageText:
;
; The context handle changed during a call.
;
RPC_NT_SS_CONTEXT_DAMAGED        EQU 0C0030006h

;
; MessageId: RPC_NT_SS_HANDLES_MISMATCH
;
; MessageText:
;
; The binding handles passed to a remote procedure call do not match.
;
RPC_NT_SS_HANDLES_MISMATCH       EQU 0C0030007h

;
; MessageId: RPC_NT_SS_CANNOT_GET_CALL_HANDLE
;
; MessageText:
;
; The stub is unable to get the call handle.
;
RPC_NT_SS_CANNOT_GET_CALL_HANDLE EQU 0C0030008h

;
; MessageId: RPC_NT_NULL_REF_POINTER
;
; MessageText:
;
; A null reference pointer was passed to the stub.
;
RPC_NT_NULL_REF_POINTER          EQU 0C0030009h

;
; MessageId: RPC_NT_ENUM_VALUE_OUT_OF_RANGE
;
; MessageText:
;
; The enumeration value is out of range.
;
RPC_NT_ENUM_VALUE_OUT_OF_RANGE   EQU 0C003000Ah

;
; MessageId: RPC_NT_BYTE_COUNT_TOO_SMALL
;
; MessageText:
;
; The byte count is too small.
;
RPC_NT_BYTE_COUNT_TOO_SMALL      EQU 0C003000Bh

;
; MessageId: RPC_NT_BAD_STUB_DATA
;
; MessageText:
;
; The stub received bad data.
;
RPC_NT_BAD_STUB_DATA             EQU 0C003000Ch

;
; MessageId: RPC_NT_CALL_IN_PROGRESS
;
; MessageText:
;
; A remote procedure call is already in progress for this thread.
;
RPC_NT_CALL_IN_PROGRESS          EQU 0C0020049h

;
; MessageId: RPC_NT_NO_MORE_BINDINGS
;
; MessageText:
;
; There are no more bindings.
;
RPC_NT_NO_MORE_BINDINGS          EQU 0C002004Ah

;
; MessageId: RPC_NT_GROUP_MEMBER_NOT_FOUND
;
; MessageText:
;
; The group member was not found.
;
RPC_NT_GROUP_MEMBER_NOT_FOUND    EQU 0C002004Bh

;
; MessageId: EPT_NT_CANT_CREATE
;
; MessageText:
;
; The endpoint mapper database entry could not be created.
;
EPT_NT_CANT_CREATE               EQU 0C002004Ch

;
; MessageId: RPC_NT_INVALID_OBJECT
;
; MessageText:
;
; The object UUID is the nil UUID.
;
RPC_NT_INVALID_OBJECT            EQU 0C002004Dh

;
; MessageId: RPC_NT_NO_INTERFACES
;
; MessageText:
;
; No interfaces have been registered.
;
RPC_NT_NO_INTERFACES             EQU 0C002004Fh

;
; MessageId: RPC_NT_CALL_CANCELLED
;
; MessageText:
;
; The remote procedure call was cancelled.
;
RPC_NT_CALL_CANCELLED            EQU 0C0020050h

;
; MessageId: RPC_NT_BINDING_INCOMPLETE
;
; MessageText:
;
; The binding handle does not contain all required information.
;
RPC_NT_BINDING_INCOMPLETE        EQU 0C0020051h

;
; MessageId: RPC_NT_COMM_FAILURE
;
; MessageText:
;
; A communications failure occurred during a remote procedure call.
;
RPC_NT_COMM_FAILURE              EQU 0C0020052h

;
; MessageId: RPC_NT_UNSUPPORTED_AUTHN_LEVEL
;
; MessageText:
;
; The requested authentication level is not supported.
;
RPC_NT_UNSUPPORTED_AUTHN_LEVEL   EQU 0C0020053h

;
; MessageId: RPC_NT_NO_PRINC_NAME
;
; MessageText:
;
; No principal name registered.
;
RPC_NT_NO_PRINC_NAME             EQU 0C0020054h

;
; MessageId: RPC_NT_NOT_RPC_ERROR
;
; MessageText:
;
; The error specified is not a valid Windows RPC error code.
;
RPC_NT_NOT_RPC_ERROR             EQU 0C0020055h

;
; MessageId: RPC_NT_UUID_LOCAL_ONLY
;
; MessageText:
;
; A UUID that is valid only on this computer has been allocated.
;
RPC_NT_UUID_LOCAL_ONLY           EQU 040020056h

;
; MessageId: RPC_NT_SEC_PKG_ERROR
;
; MessageText:
;
; A security package specific error occurred.
;
RPC_NT_SEC_PKG_ERROR             EQU 0C0020057h

;
; MessageId: RPC_NT_NOT_CANCELLED
;
; MessageText:
;
; Thread is not cancelled.
;
RPC_NT_NOT_CANCELLED             EQU 0C0020058h

;
; MessageId: RPC_NT_INVALID_ES_ACTION
;
; MessageText:
;
; Invalid operation on the encoding/decoding handle.
;
RPC_NT_INVALID_ES_ACTION         EQU 0C0030059h

;
; MessageId: RPC_NT_WRONG_ES_VERSION
;
; MessageText:
;
; Incompatible version of the serializing package.
;
RPC_NT_WRONG_ES_VERSION          EQU 0C003005Ah

;
; MessageId: RPC_NT_WRONG_STUB_VERSION
;
; MessageText:
;
; Incompatible version of the RPC stub.
;
RPC_NT_WRONG_STUB_VERSION        EQU 0C003005Bh

;
; MessageId: RPC_NT_INVALID_PIPE_OBJECT
;
; MessageText:
;
; The RPC pipe object is invalid or corrupted.
;
RPC_NT_INVALID_PIPE_OBJECT       EQU 0C003005Ch

;
; MessageId: RPC_NT_INVALID_PIPE_OPERATION
;
; MessageText:
;
; An invalid operation was attempted on an RPC pipe object.
;
RPC_NT_INVALID_PIPE_OPERATION    EQU 0C003005Dh

;
; MessageId: RPC_NT_WRONG_PIPE_VERSION
;
; MessageText:
;
; Unsupported RPC pipe version.
;
RPC_NT_WRONG_PIPE_VERSION        EQU 0C003005Eh

;
; MessageId: RPC_NT_PIPE_CLOSED
;
; MessageText:
;
; The RPC pipe object has already been closed.
;
RPC_NT_PIPE_CLOSED               EQU 0C003005Fh

;
; MessageId: RPC_NT_PIPE_DISCIPLINE_ERROR
;
; MessageText:
;
; The RPC call completed before all pipes were processed.
;
RPC_NT_PIPE_DISCIPLINE_ERROR     EQU 0C0030060h

;
; MessageId: RPC_NT_PIPE_EMPTY
;
; MessageText:
;
; No more data is available from the RPC pipe.
;
RPC_NT_PIPE_EMPTY                EQU 0C0030061h

;
; MessageId: RPC_NT_INVALID_ASYNC_HANDLE
;
; MessageText:
;
; Invalid asynchronous remote procedure call handle.
;
RPC_NT_INVALID_ASYNC_HANDLE      EQU 0C0020062h

;
; MessageId: RPC_NT_INVALID_ASYNC_CALL
;
; MessageText:
;
; Invalid asynchronous RPC call handle for this operation.
;
RPC_NT_INVALID_ASYNC_CALL        EQU 0C0020063h

;
; MessageId: RPC_NT_PROXY_ACCESS_DENIED
;
; MessageText:
;
; Access to the HTTP proxy is denied.
;
RPC_NT_PROXY_ACCESS_DENIED       EQU 0C0020064h

;
; MessageId: RPC_NT_COOKIE_AUTH_FAILED
;
; MessageText:
;
; HTTP proxy server rejected the connection because the cookie authentication failed.
;
RPC_NT_COOKIE_AUTH_FAILED        EQU 0C0020065h

;
; MessageId: RPC_NT_SEND_INCOMPLETE
;
; MessageText:
;
; Some data remains to be sent in the request buffer.
;
RPC_NT_SEND_INCOMPLETE           EQU 0400200AFh


;
;  ACPI error values
;

;
; MessageId: STATUS_ACPI_INVALID_OPCODE
;
; MessageText:
;
; An attempt was made to run an invalid AML opcode
;
STATUS_ACPI_INVALID_OPCODE       EQU 0C0140001h

;
; MessageId: STATUS_ACPI_STACK_OVERFLOW
;
; MessageText:
;
; The AML Interpreter Stack has overflowed
;
STATUS_ACPI_STACK_OVERFLOW       EQU 0C0140002h

;
; MessageId: STATUS_ACPI_ASSERT_FAILED
;
; MessageText:
;
; An inconsistent state has occurred
;
STATUS_ACPI_ASSERT_FAILED        EQU 0C0140003h

;
; MessageId: STATUS_ACPI_INVALID_INDEX
;
; MessageText:
;
; An attempt was made to access an array outside of its bounds
;
STATUS_ACPI_INVALID_INDEX        EQU 0C0140004h

;
; MessageId: STATUS_ACPI_INVALID_ARGUMENT
;
; MessageText:
;
; A required argument was not specified
;
STATUS_ACPI_INVALID_ARGUMENT     EQU 0C0140005h

;
; MessageId: STATUS_ACPI_FATAL
;
; MessageText:
;
; A fatal error has occurred
;
STATUS_ACPI_FATAL                EQU 0C0140006h

;
; MessageId: STATUS_ACPI_INVALID_SUPERNAME
;
; MessageText:
;
; An invalid SuperName was specified
;
STATUS_ACPI_INVALID_SUPERNAME    EQU 0C0140007h

;
; MessageId: STATUS_ACPI_INVALID_ARGTYPE
;
; MessageText:
;
; An argument with an incorrect type was specified
;
STATUS_ACPI_INVALID_ARGTYPE      EQU 0C0140008h

;
; MessageId: STATUS_ACPI_INVALID_OBJTYPE
;
; MessageText:
;
; An object with an incorrect type was specified
;
STATUS_ACPI_INVALID_OBJTYPE      EQU 0C0140009h

;
; MessageId: STATUS_ACPI_INVALID_TARGETTYPE
;
; MessageText:
;
; A target with an incorrect type was specified
;
STATUS_ACPI_INVALID_TARGETTYPE   EQU 0C014000Ah

;
; MessageId: STATUS_ACPI_INCORRECT_ARGUMENT_COUNT
;
; MessageText:
;
; An incorrect number of arguments were specified
;
STATUS_ACPI_INCORRECT_ARGUMENT_COUNT EQU 0C014000Bh

;
; MessageId: STATUS_ACPI_ADDRESS_NOT_MAPPED
;
; MessageText:
;
; An address failed to translate
;
STATUS_ACPI_ADDRESS_NOT_MAPPED   EQU 0C014000Ch

;
; MessageId: STATUS_ACPI_INVALID_EVENTTYPE
;
; MessageText:
;
; An incorrect event type was specified
;
STATUS_ACPI_INVALID_EVENTTYPE    EQU 0C014000Dh

;
; MessageId: STATUS_ACPI_HANDLER_COLLISION
;
; MessageText:
;
; A handler for the target already exists
;
STATUS_ACPI_HANDLER_COLLISION    EQU 0C014000Eh

;
; MessageId: STATUS_ACPI_INVALID_DATA
;
; MessageText:
;
; Invalid data for the target was specified
;
STATUS_ACPI_INVALID_DATA         EQU 0C014000Fh

;
; MessageId: STATUS_ACPI_INVALID_REGION
;
; MessageText:
;
; An invalid region for the target was specified
;
STATUS_ACPI_INVALID_REGION       EQU 0C0140010h

;
; MessageId: STATUS_ACPI_INVALID_ACCESS_SIZE
;
; MessageText:
;
; An attempt was made to access a field outside of the defined range
;
STATUS_ACPI_INVALID_ACCESS_SIZE  EQU 0C0140011h

;
; MessageId: STATUS_ACPI_ACQUIRE_GLOBAL_LOCK
;
; MessageText:
;
; The Global system lock could not be acquired
;
STATUS_ACPI_ACQUIRE_GLOBAL_LOCK  EQU 0C0140012h

;
; MessageId: STATUS_ACPI_ALREADY_INITIALIZED
;
; MessageText:
;
; An attempt was made to reinitialize the ACPI subsystem
;
STATUS_ACPI_ALREADY_INITIALIZED  EQU 0C0140013h

;
; MessageId: STATUS_ACPI_NOT_INITIALIZED
;
; MessageText:
;
; The ACPI subsystem has not been initialized
;
STATUS_ACPI_NOT_INITIALIZED      EQU 0C0140014h

;
; MessageId: STATUS_ACPI_INVALID_MUTEX_LEVEL
;
; MessageText:
;
; An incorrect mutex was specified
;
STATUS_ACPI_INVALID_MUTEX_LEVEL  EQU 0C0140015h

;
; MessageId: STATUS_ACPI_MUTEX_NOT_OWNED
;
; MessageText:
;
; The mutex is not currently owned
;
STATUS_ACPI_MUTEX_NOT_OWNED      EQU 0C0140016h

;
; MessageId: STATUS_ACPI_MUTEX_NOT_OWNER
;
; MessageText:
;
; An attempt was made to access the mutex by a process that was not the owner
;
STATUS_ACPI_MUTEX_NOT_OWNER      EQU 0C0140017h

;
; MessageId: STATUS_ACPI_RS_ACCESS
;
; MessageText:
;
; An error occurred during an access to Region Space
;
STATUS_ACPI_RS_ACCESS            EQU 0C0140018h

;
; MessageId: STATUS_ACPI_INVALID_TABLE
;
; MessageText:
;
; An attempt was made to use an incorrect table
;
STATUS_ACPI_INVALID_TABLE        EQU 0C0140019h

;
; MessageId: STATUS_ACPI_REG_HANDLER_FAILED
;
; MessageText:
;
; The registration of an ACPI event failed
;
STATUS_ACPI_REG_HANDLER_FAILED   EQU 0C0140020h

;
; MessageId: STATUS_ACPI_POWER_REQUEST_FAILED
;
; MessageText:
;
; An ACPI Power Object failed to transition state
;
STATUS_ACPI_POWER_REQUEST_FAILED EQU 0C0140021h

;
; Terminal Server specific Errors
;
;
; MessageId: STATUS_CTX_WINSTATION_NAME_INVALID
;
; MessageText:
;
; Session name %1 is invalid.
;
STATUS_CTX_WINSTATION_NAME_INVALID EQU 0C00A0001h

;
; MessageId: STATUS_CTX_INVALID_PD
;
; MessageText:
;
; The protocol driver %1 is invalid.
;
STATUS_CTX_INVALID_PD            EQU 0C00A0002h

;
; MessageId: STATUS_CTX_PD_NOT_FOUND
;
; MessageText:
;
; The protocol driver %1 was not found in the system path.
;
STATUS_CTX_PD_NOT_FOUND          EQU 0C00A0003h

;
; MessageId: STATUS_CTX_CDM_CONNECT
;
; MessageText:
;
; The Client Drive Mapping Service Has Connected on Terminal Connection.
;
STATUS_CTX_CDM_CONNECT           EQU 0400A0004h

;
; MessageId: STATUS_CTX_CDM_DISCONNECT
;
; MessageText:
;
; The Client Drive Mapping Service Has Disconnected on Terminal Connection.
;
STATUS_CTX_CDM_DISCONNECT        EQU 0400A0005h

;
; MessageId: STATUS_CTX_CLOSE_PENDING
;
; MessageText:
;
; A close operation is pending on the Terminal Connection.
;
STATUS_CTX_CLOSE_PENDING         EQU 0C00A0006h

;
; MessageId: STATUS_CTX_NO_OUTBUF
;
; MessageText:
;
; There are no free output buffers available.
;
STATUS_CTX_NO_OUTBUF             EQU 0C00A0007h

;
; MessageId: STATUS_CTX_MODEM_INF_NOT_FOUND
;
; MessageText:
;
; The MODEM.INF file was not found.
;
STATUS_CTX_MODEM_INF_NOT_FOUND   EQU 0C00A0008h

;
; MessageId: STATUS_CTX_INVALID_MODEMNAME
;
; MessageText:
;
; The modem (%1) was not found in MODEM.INF.
;
STATUS_CTX_INVALID_MODEMNAME     EQU 0C00A0009h

;
; MessageId: STATUS_CTX_RESPONSE_ERROR
;
; MessageText:
;
; The modem did not accept the command sent to it.
; Verify the configured modem name matches the attached modem.
;
STATUS_CTX_RESPONSE_ERROR        EQU 0C00A000Ah

;
; MessageId: STATUS_CTX_MODEM_RESPONSE_TIMEOUT
;
; MessageText:
;
; The modem did not respond to the command sent to it.
; Verify the modem is properly cabled and powered on.
;
STATUS_CTX_MODEM_RESPONSE_TIMEOUT EQU 0C00A000Bh

;
; MessageId: STATUS_CTX_MODEM_RESPONSE_NO_CARRIER
;
; MessageText:
;
; Carrier detect has failed or carrier has been dropped due to disconnect.
;
STATUS_CTX_MODEM_RESPONSE_NO_CARRIER EQU 0C00A000Ch

;
; MessageId: STATUS_CTX_MODEM_RESPONSE_NO_DIALTONE
;
; MessageText:
;
; Dial tone not detected within required time.
; Verify phone cable is properly attached and functional.
;
STATUS_CTX_MODEM_RESPONSE_NO_DIALTONE EQU 0C00A000Dh

;
; MessageId: STATUS_CTX_MODEM_RESPONSE_BUSY
;
; MessageText:
;
; Busy signal detected at remote site on callback.
;
STATUS_CTX_MODEM_RESPONSE_BUSY   EQU 0C00A000Eh

;
; MessageId: STATUS_CTX_MODEM_RESPONSE_VOICE
;
; MessageText:
;
; Voice detected at remote site on callback.
;
STATUS_CTX_MODEM_RESPONSE_VOICE  EQU 0C00A000Fh

;
; MessageId: STATUS_CTX_TD_ERROR
;
; MessageText:
;
; Transport driver error
;
STATUS_CTX_TD_ERROR              EQU 0C00A0010h

;
; MessageId: STATUS_CTX_LICENSE_CLIENT_INVALID
;
; MessageText:
;
; The client you are using is not licensed to use this system. Your logon request is denied.
;
STATUS_CTX_LICENSE_CLIENT_INVALID EQU 0C00A0012h

;
; MessageId: STATUS_CTX_LICENSE_NOT_AVAILABLE
;
; MessageText:
;
; The system has reached its licensed logon limit.
; Please try again later.
;
STATUS_CTX_LICENSE_NOT_AVAILABLE EQU 0C00A0013h

;
; MessageId: STATUS_CTX_LICENSE_EXPIRED
;
; MessageText:
;
; The system license has expired. Your logon request is denied.
;
STATUS_CTX_LICENSE_EXPIRED       EQU 0C00A0014h

;
; MessageId: STATUS_CTX_WINSTATION_NOT_FOUND
;
; MessageText:
;
; The specified session cannot be found.
;
STATUS_CTX_WINSTATION_NOT_FOUND  EQU 0C00A0015h

;
; MessageId: STATUS_CTX_WINSTATION_NAME_COLLISION
;
; MessageText:
;
; The specified session name is already in use.
;
STATUS_CTX_WINSTATION_NAME_COLLISION EQU 0C00A0016h

;
; MessageId: STATUS_CTX_WINSTATION_BUSY
;
; MessageText:
;
; The task you are trying to do can't be completed because Remote Desktop Services is currently busy. Please try again in a few minutes. Other users should still be able to log on.
;
STATUS_CTX_WINSTATION_BUSY       EQU 0C00A0017h

;
; MessageId: STATUS_CTX_BAD_VIDEO_MODE
;
; MessageText:
;
; An attempt has been made to connect to a session whose video mode is not supported by the current client.
;
STATUS_CTX_BAD_VIDEO_MODE        EQU 0C00A0018h

;
; MessageId: STATUS_CTX_GRAPHICS_INVALID
;
; MessageText:
;
; The application attempted to enable DOS graphics mode.
; DOS graphics mode is not supported.
;
STATUS_CTX_GRAPHICS_INVALID      EQU 0C00A0022h

;
; MessageId: STATUS_CTX_NOT_CONSOLE
;
; MessageText:
;
; The requested operation can be performed only on the system console.
; This is most often the result of a driver or system DLL requiring direct console access.
;
STATUS_CTX_NOT_CONSOLE           EQU 0C00A0024h

;
; MessageId: STATUS_CTX_CLIENT_QUERY_TIMEOUT
;
; MessageText:
;
; The client failed to respond to the server connect message.
;
STATUS_CTX_CLIENT_QUERY_TIMEOUT  EQU 0C00A0026h

;
; MessageId: STATUS_CTX_CONSOLE_DISCONNECT
;
; MessageText:
;
; Disconnecting the console session is not supported.
;
STATUS_CTX_CONSOLE_DISCONNECT    EQU 0C00A0027h

;
; MessageId: STATUS_CTX_CONSOLE_CONNECT
;
; MessageText:
;
; Reconnecting a disconnected session to the console is not supported.
;
STATUS_CTX_CONSOLE_CONNECT       EQU 0C00A0028h

;
; MessageId: STATUS_CTX_SHADOW_DENIED
;
; MessageText:
;
; The request to control another session remotely was denied.
;
STATUS_CTX_SHADOW_DENIED         EQU 0C00A002Ah

;
; MessageId: STATUS_CTX_WINSTATION_ACCESS_DENIED
;
; MessageText:
;
; A process has requested access to a session, but has not been granted those access rights.
;
STATUS_CTX_WINSTATION_ACCESS_DENIED EQU 0C00A002Bh

;
; MessageId: STATUS_CTX_INVALID_WD
;
; MessageText:
;
; The Terminal Connection driver %1 is invalid.
;
STATUS_CTX_INVALID_WD            EQU 0C00A002Eh

;
; MessageId: STATUS_CTX_WD_NOT_FOUND
;
; MessageText:
;
; The Terminal Connection driver %1 was not found in the system path.
;
STATUS_CTX_WD_NOT_FOUND          EQU 0C00A002Fh

;
; MessageId: STATUS_CTX_SHADOW_INVALID
;
; MessageText:
;
; The requested session cannot be controlled remotely.
; You cannot control your own session, a session that is trying to control your session,
; a session that has no user logged on, nor control other sessions from the console.
;
STATUS_CTX_SHADOW_INVALID        EQU 0C00A0030h

;
; MessageId: STATUS_CTX_SHADOW_DISABLED
;
; MessageText:
;
; The requested session is not configured to allow remote control.
;
STATUS_CTX_SHADOW_DISABLED       EQU 0C00A0031h

;
; MessageId: STATUS_RDP_PROTOCOL_ERROR
;
; MessageText:
;
; The RDP protocol component %2 detected an error in the protocol stream and has disconnected the client.
;
STATUS_RDP_PROTOCOL_ERROR        EQU 0C00A0032h

;
; MessageId: STATUS_CTX_CLIENT_LICENSE_NOT_SET
;
; MessageText:
;
; Your request to connect to this Terminal server has been rejected.
; Your Terminal Server Client license number has not been entered for this copy of the Terminal Client.
; Please call your system administrator for help in entering a valid, unique license number for this Terminal Server Client.
; Click OK to continue.
;
STATUS_CTX_CLIENT_LICENSE_NOT_SET EQU 0C00A0033h

;
; MessageId: STATUS_CTX_CLIENT_LICENSE_IN_USE
;
; MessageText:
;
; Your request to connect to this Terminal server has been rejected.
; Your Terminal Server Client license number is currently being used by another user.
; Please call your system administrator to obtain a new copy of the Terminal Server Client with a valid, unique license number.
; Click OK to continue.
;
STATUS_CTX_CLIENT_LICENSE_IN_USE EQU 0C00A0034h

;
; MessageId: STATUS_CTX_SHADOW_ENDED_BY_MODE_CHANGE
;
; MessageText:
;
; The remote control of the console was terminated because the display mode was changed. Changing the display mode in a remote control session is not supported.
;
STATUS_CTX_SHADOW_ENDED_BY_MODE_CHANGE EQU 0C00A0035h

;
; MessageId: STATUS_CTX_SHADOW_NOT_RUNNING
;
; MessageText:
;
; Remote control could not be terminated because the specified session is not currently being remotely controlled.
;
STATUS_CTX_SHADOW_NOT_RUNNING    EQU 0C00A0036h

;
; MessageId: STATUS_CTX_LOGON_DISABLED
;
; MessageText:
;
; Your interactive logon privilege has been disabled.
; Please contact your system administrator.
;
STATUS_CTX_LOGON_DISABLED        EQU 0C00A0037h

;
; MessageId: STATUS_CTX_SECURITY_LAYER_ERROR
;
; MessageText:
;
; The Terminal Server security layer detected an error in the protocol stream and has disconnected the client.
; Client IP: %2.
;
STATUS_CTX_SECURITY_LAYER_ERROR  EQU 0C00A0038h

;
; MessageId: STATUS_TS_INCOMPATIBLE_SESSIONS
;
; MessageText:
;
; The target session is incompatible with the current session.
;
STATUS_TS_INCOMPATIBLE_SESSIONS  EQU 0C00A0039h

;
; MessageId: STATUS_TS_VIDEO_SUBSYSTEM_ERROR
;
; MessageText:
;
; Windows can't connect to your session because a problem occurred in the Windows video subsystem. Try connecting again later, or contact the server administrator for assistance.
;
STATUS_TS_VIDEO_SUBSYSTEM_ERROR  EQU 0C00A003Ah


;
;  IO error values
;

;
; MessageId: STATUS_PNP_BAD_MPS_TABLE
;
; MessageText:
;
; A device is missing in the system BIOS MPS table. This device will not be used.
; Please contact your system vendor for system BIOS update.
;
STATUS_PNP_BAD_MPS_TABLE         EQU 0C0040035h

;
; MessageId: STATUS_PNP_TRANSLATION_FAILED
;
; MessageText:
;
; A translator failed to translate resources.
;
STATUS_PNP_TRANSLATION_FAILED    EQU 0C0040036h

;
; MessageId: STATUS_PNP_IRQ_TRANSLATION_FAILED
;
; MessageText:
;
; A IRQ translator failed to translate resources.
;
STATUS_PNP_IRQ_TRANSLATION_FAILED EQU 0C0040037h

;
; MessageId: STATUS_PNP_INVALID_ID
;
; MessageText:
;
; Driver %2 returned invalid ID for a child device (%3).
;
STATUS_PNP_INVALID_ID            EQU 0C0040038h

;
; MessageId: STATUS_IO_REISSUE_AS_CACHED
;
; MessageText:
;
; Reissue the given operation as a cached IO operation
;
STATUS_IO_REISSUE_AS_CACHED      EQU 0C0040039h


;
;  MUI error values
;

;
; MessageId: STATUS_MUI_FILE_NOT_FOUND
;
; MessageText:
;
; The resource loader failed to find MUI file.
;
STATUS_MUI_FILE_NOT_FOUND        EQU 0C00B0001h

;
; MessageId: STATUS_MUI_INVALID_FILE
;
; MessageText:
;
; The resource loader failed to load MUI file because the file fail to pass validation.
;
STATUS_MUI_INVALID_FILE          EQU 0C00B0002h

;
; MessageId: STATUS_MUI_INVALID_RC_CONFIG
;
; MessageText:
;
; The RC Manifest is corrupted with garbage data or unsupported version or missing required item.
;
STATUS_MUI_INVALID_RC_CONFIG     EQU 0C00B0003h

;
; MessageId: STATUS_MUI_INVALID_LOCALE_NAME
;
; MessageText:
;
; The RC Manifest has invalid culture name.
;
STATUS_MUI_INVALID_LOCALE_NAME   EQU 0C00B0004h

;
; MessageId: STATUS_MUI_INVALID_ULTIMATEFALLBACK_NAME
;
; MessageText:
;
; The RC Manifest has invalid ultimatefallback name.
;
STATUS_MUI_INVALID_ULTIMATEFALLBACK_NAME EQU 0C00B0005h

;
; MessageId: STATUS_MUI_FILE_NOT_LOADED
;
; MessageText:
;
; The resource loader cache doesn't have loaded MUI entry.
;
STATUS_MUI_FILE_NOT_LOADED       EQU 0C00B0006h

;
; MessageId: STATUS_RESOURCE_ENUM_USER_STOP
;
; MessageText:
;
; User stopped resource enumeration.
;
STATUS_RESOURCE_ENUM_USER_STOP   EQU 0C00B0007h


;
;  Filter Manager error values
;

;
;  Translation macro for converting:
;     HRESULT --> NTSTATUS
;

;FILTER_FLT_NTSTATUS_FROM_HRESULT(x) ((NTSTATUS) (((x) & 0xC0007FFF) | (FACILITY_FILTER_MANAGER << 16) | 0x40000000))

;
; MessageId: STATUS_FLT_NO_HANDLER_DEFINED
;
; MessageText:
;
; A handler was not defined by the filter for this operation.
;
STATUS_FLT_NO_HANDLER_DEFINED    EQU 0C01C0001h

;
; MessageId: STATUS_FLT_CONTEXT_ALREADY_DEFINED
;
; MessageText:
;
; A context is already defined for this object.
;
STATUS_FLT_CONTEXT_ALREADY_DEFINED EQU 0C01C0002h

;
; MessageId: STATUS_FLT_INVALID_ASYNCHRONOUS_REQUEST
;
; MessageText:
;
; Asynchronous requests are not valid for this operation.
;
STATUS_FLT_INVALID_ASYNCHRONOUS_REQUEST EQU 0C01C0003h

;
; MessageId: STATUS_FLT_DISALLOW_FAST_IO
;
; MessageText:
;
; Internal error code used by the filter manager to determine if a fastio operation should be forced down the IRP path. Mini-filters should never return this value.
;
STATUS_FLT_DISALLOW_FAST_IO      EQU 0C01C0004h

;
; MessageId: STATUS_FLT_INVALID_NAME_REQUEST
;
; MessageText:
;
; An invalid name request was made. The name requested cannot be retrieved at this time.
;
STATUS_FLT_INVALID_NAME_REQUEST  EQU 0C01C0005h

;
; MessageId: STATUS_FLT_NOT_SAFE_TO_POST_OPERATION
;
; MessageText:
;
; Posting this operation to a worker thread for further processing is not safe at this time because it could lead to a system deadlock.
;
STATUS_FLT_NOT_SAFE_TO_POST_OPERATION EQU 0C01C0006h

;
; MessageId: STATUS_FLT_NOT_INITIALIZED
;
; MessageText:
;
; The Filter Manager was not initialized when a filter tried to register. Make sure that the Filter Manager is getting loaded as a driver.
;
STATUS_FLT_NOT_INITIALIZED       EQU 0C01C0007h

;
; MessageId: STATUS_FLT_FILTER_NOT_READY
;
; MessageText:
;
; The filter is not ready for attachment to volumes because it has not finished initializing (FltStartFiltering has not been called).
;
STATUS_FLT_FILTER_NOT_READY      EQU 0C01C0008h

;
; MessageId: STATUS_FLT_POST_OPERATION_CLEANUP
;
; MessageText:
;
; The filter must cleanup any operation specific context at this time because it is being removed from the system before the operation is completed by the lower drivers.
;
STATUS_FLT_POST_OPERATION_CLEANUP EQU 0C01C0009h

;
; MessageId: STATUS_FLT_INTERNAL_ERROR
;
; MessageText:
;
; The Filter Manager had an internal error from which it cannot recover, therefore the operation has been failed. This is usually the result of a filter returning an invalid value from a pre-operation callback.
;
STATUS_FLT_INTERNAL_ERROR        EQU 0C01C000Ah

;
; MessageId: STATUS_FLT_DELETING_OBJECT
;
; MessageText:
;
; The object specified for this action is in the process of being deleted, therefore the action requested cannot be completed at this time.
;
STATUS_FLT_DELETING_OBJECT       EQU 0C01C000Bh

;
; MessageId: STATUS_FLT_MUST_BE_NONPAGED_POOL
;
; MessageText:
;
; Non-paged pool must be used for this type of context.
;
STATUS_FLT_MUST_BE_NONPAGED_POOL EQU 0C01C000Ch

;
; MessageId: STATUS_FLT_DUPLICATE_ENTRY
;
; MessageText:
;
; A duplicate handler definition has been provided for an operation.
;
STATUS_FLT_DUPLICATE_ENTRY       EQU 0C01C000Dh

;
; MessageId: STATUS_FLT_CBDQ_DISABLED
;
; MessageText:
;
; The callback data queue has been disabled.
;
STATUS_FLT_CBDQ_DISABLED         EQU 0C01C000Eh

;
; MessageId: STATUS_FLT_DO_NOT_ATTACH
;
; MessageText:
;
; Do not attach the filter to the volume at this time.
;
STATUS_FLT_DO_NOT_ATTACH         EQU 0C01C000Fh

;
; MessageId: STATUS_FLT_DO_NOT_DETACH
;
; MessageText:
;
; Do not detach the filter from the volume at this time.
;
STATUS_FLT_DO_NOT_DETACH         EQU 0C01C0010h

;
; MessageId: STATUS_FLT_INSTANCE_ALTITUDE_COLLISION
;
; MessageText:
;
; An instance already exists at this altitude on the volume specified.
;
STATUS_FLT_INSTANCE_ALTITUDE_COLLISION EQU 0C01C0011h

;
; MessageId: STATUS_FLT_INSTANCE_NAME_COLLISION
;
; MessageText:
;
; An instance already exists with this name on the volume specified.
;
STATUS_FLT_INSTANCE_NAME_COLLISION EQU 0C01C0012h

;
; MessageId: STATUS_FLT_FILTER_NOT_FOUND
;
; MessageText:
;
; The system could not find the filter specified.
;
STATUS_FLT_FILTER_NOT_FOUND      EQU 0C01C0013h

;
; MessageId: STATUS_FLT_VOLUME_NOT_FOUND
;
; MessageText:
;
; The system could not find the volume specified.
;
STATUS_FLT_VOLUME_NOT_FOUND      EQU 0C01C0014h

;
; MessageId: STATUS_FLT_INSTANCE_NOT_FOUND
;
; MessageText:
;
; The system could not find the instance specified.
;
STATUS_FLT_INSTANCE_NOT_FOUND    EQU 0C01C0015h

;
; MessageId: STATUS_FLT_CONTEXT_ALLOCATION_NOT_FOUND
;
; MessageText:
;
; No registered context allocation definition was found for the given request.
;
STATUS_FLT_CONTEXT_ALLOCATION_NOT_FOUND EQU 0C01C0016h

;
; MessageId: STATUS_FLT_INVALID_CONTEXT_REGISTRATION
;
; MessageText:
;
; An invalid parameter was specified during context registration.
;
STATUS_FLT_INVALID_CONTEXT_REGISTRATION EQU 0C01C0017h

;
; MessageId: STATUS_FLT_NAME_CACHE_MISS
;
; MessageText:
;
; The name requested was not found in Filter Manager's name cache and could not be retrieved from the file system.
;
STATUS_FLT_NAME_CACHE_MISS       EQU 0C01C0018h

;
; MessageId: STATUS_FLT_NO_DEVICE_OBJECT
;
; MessageText:
;
; The requested device object does not exist for the given volume.
;
STATUS_FLT_NO_DEVICE_OBJECT      EQU 0C01C0019h

;
; MessageId: STATUS_FLT_VOLUME_ALREADY_MOUNTED
;
; MessageText:
;
; The specified volume is already mounted.
;
STATUS_FLT_VOLUME_ALREADY_MOUNTED EQU 0C01C001Ah

;
; MessageId: STATUS_FLT_ALREADY_ENLISTED
;
; MessageText:
;
; The specified Transaction Context is already enlisted in a transaction
;
STATUS_FLT_ALREADY_ENLISTED      EQU 0C01C001Bh

;
; MessageId: STATUS_FLT_CONTEXT_ALREADY_LINKED
;
; MessageText:
;
; The specifiec context is already attached to another object
;
STATUS_FLT_CONTEXT_ALREADY_LINKED EQU 0C01C001Ch

;
; MessageId: STATUS_FLT_NO_WAITER_FOR_REPLY
;
; MessageText:
;
; No waiter is present for the filter's reply to this message.
;
STATUS_FLT_NO_WAITER_FOR_REPLY   EQU 0C01C0020h

;
; MessageId: STATUS_FLT_REGISTRATION_BUSY
;
; MessageText:
;
; The filesystem database resource is in use. Registration cannot complete at this time.
;
STATUS_FLT_REGISTRATION_BUSY     EQU 0C01C0023h


;
;  Side-by-side (SXS) error values
;

;
; MessageId: STATUS_SXS_SECTION_NOT_FOUND
;
; MessageText:
;
; The requested section is not present in the activation context.
;
STATUS_SXS_SECTION_NOT_FOUND     EQU 0C0150001h

;
; MessageId: STATUS_SXS_CANT_GEN_ACTCTX
;
; MessageText:
;
; Windows was not able to process the application binding information.
; Please refer to your System Event Log for further information.
;
STATUS_SXS_CANT_GEN_ACTCTX       EQU 0C0150002h

;
; MessageId: STATUS_SXS_INVALID_ACTCTXDATA_FORMAT
;
; MessageText:
;
; The application binding data format is invalid.
;
STATUS_SXS_INVALID_ACTCTXDATA_FORMAT EQU 0C0150003h

;
; MessageId: STATUS_SXS_ASSEMBLY_NOT_FOUND
;
; MessageText:
;
; The referenced assembly is not installed on your system.
;
STATUS_SXS_ASSEMBLY_NOT_FOUND    EQU 0C0150004h

;
; MessageId: STATUS_SXS_MANIFEST_FORMAT_ERROR
;
; MessageText:
;
; The manifest file does not begin with the required tag and format information.
;
STATUS_SXS_MANIFEST_FORMAT_ERROR EQU 0C0150005h

;
; MessageId: STATUS_SXS_MANIFEST_PARSE_ERROR
;
; MessageText:
;
; The manifest file contains one or more syntax errors.
;
STATUS_SXS_MANIFEST_PARSE_ERROR  EQU 0C0150006h

;
; MessageId: STATUS_SXS_ACTIVATION_CONTEXT_DISABLED
;
; MessageText:
;
; The application attempted to activate a disabled activation context.
;
STATUS_SXS_ACTIVATION_CONTEXT_DISABLED EQU 0C0150007h

;
; MessageId: STATUS_SXS_KEY_NOT_FOUND
;
; MessageText:
;
; The requested lookup key was not found in any active activation context.
;
STATUS_SXS_KEY_NOT_FOUND         EQU 0C0150008h

;
; MessageId: STATUS_SXS_VERSION_CONFLICT
;
; MessageText:
;
; A component version required by the application conflicts with another component version already active.
;
STATUS_SXS_VERSION_CONFLICT      EQU 0C0150009h

;
; MessageId: STATUS_SXS_WRONG_SECTION_TYPE
;
; MessageText:
;
; The type requested activation context section does not match the query API used.
;
STATUS_SXS_WRONG_SECTION_TYPE    EQU 0C015000Ah

;
; MessageId: STATUS_SXS_THREAD_QUERIES_DISABLED
;
; MessageText:
;
; Lack of system resources has required isolated activation to be disabled for the current thread of execution.
;
STATUS_SXS_THREAD_QUERIES_DISABLED EQU 0C015000Bh

;
; MessageId: STATUS_SXS_ASSEMBLY_MISSING
;
; MessageText:
;
; The referenced assembly could not be found.
;
STATUS_SXS_ASSEMBLY_MISSING      EQU 0C015000Ch

;
; MessageId: STATUS_SXS_RELEASE_ACTIVATION_CONTEXT
;
; MessageText:
;
; A kernel mode component is releasing a reference on an activation context.
;
STATUS_SXS_RELEASE_ACTIVATION_CONTEXT EQU 04015000Dh

;
; MessageId: STATUS_SXS_PROCESS_DEFAULT_ALREADY_SET
;
; MessageText:
;
; An attempt to set the process default activation context failed because the process default activation context was already set.
;
STATUS_SXS_PROCESS_DEFAULT_ALREADY_SET EQU 0C015000Eh


;
; MessageId: STATUS_SXS_EARLY_DEACTIVATION
;
; MessageText:
;
; The activation context being deactivated is not the most recently activated one.
;
STATUS_SXS_EARLY_DEACTIVATION    EQU 0C015000Fh

;
; MessageId: STATUS_SXS_INVALID_DEACTIVATION
;
; MessageText:
;
; The activation context being deactivated is not active for the current thread of execution.
;
STATUS_SXS_INVALID_DEACTIVATION  EQU 0C0150010h


;
; MessageId: STATUS_SXS_MULTIPLE_DEACTIVATION
;
; MessageText:
;
; The activation context being deactivated has already been deactivated.
;
STATUS_SXS_MULTIPLE_DEACTIVATION EQU 0C0150011h

;
; MessageId: STATUS_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY
;
; MessageText:
;
; The activation context of system default assembly could not be generated.
;
STATUS_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY EQU 0C0150012h

;
; MessageId: STATUS_SXS_PROCESS_TERMINATION_REQUESTED
;
; MessageText:
;
; A component used by the isolation facility has requested to terminate the process.
;
STATUS_SXS_PROCESS_TERMINATION_REQUESTED EQU 0C0150013h

;
; MessageId: STATUS_SXS_CORRUPT_ACTIVATION_STACK
;
; MessageText:
;
; The activation context activation stack for the running thread of execution is corrupt.
;
STATUS_SXS_CORRUPT_ACTIVATION_STACK EQU 0C0150014h

;
; MessageId: STATUS_SXS_CORRUPTION
;
; MessageText:
;
; The application isolation metadata for this process or thread has become corrupt.
;
STATUS_SXS_CORRUPTION            EQU 0C0150015h

;
; MessageId: STATUS_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE
;
; MessageText:
;
; The value of an attribute in an identity is not within the legal range.
;
STATUS_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE EQU 0C0150016h

;
; MessageId: STATUS_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME
;
; MessageText:
;
; The name of an attribute in an identity is not within the legal range.
;
STATUS_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME EQU 0C0150017h

;
; MessageId: STATUS_SXS_IDENTITY_DUPLICATE_ATTRIBUTE
;
; MessageText:
;
; An identity contains two definitions for the same attribute.
;
STATUS_SXS_IDENTITY_DUPLICATE_ATTRIBUTE EQU 0C0150018h

;
; MessageId: STATUS_SXS_IDENTITY_PARSE_ERROR
;
; MessageText:
;
; The identity string is malformed. This may be due to a trailing comma, more than two unnamed attributes, missing attribute name or missing attribute value.
;
STATUS_SXS_IDENTITY_PARSE_ERROR  EQU 0C0150019h

;
; MessageId: STATUS_SXS_COMPONENT_STORE_CORRUPT
;
; MessageText:
;
; The component store has been corrupted.
;
STATUS_SXS_COMPONENT_STORE_CORRUPT EQU 0C015001Ah

;
; MessageId: STATUS_SXS_FILE_HASH_MISMATCH
;
; MessageText:
;
; A component's file does not match the verification information present in the component manifest.
;
STATUS_SXS_FILE_HASH_MISMATCH    EQU 0C015001Bh

;
; MessageId: STATUS_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT
;
; MessageText:
;
; The identities of the manifests are identical but their contents are different.
;
STATUS_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT EQU 0C015001Ch

;
; MessageId: STATUS_SXS_IDENTITIES_DIFFERENT
;
; MessageText:
;
; The component identities are different.
;
STATUS_SXS_IDENTITIES_DIFFERENT  EQU 0C015001Dh

;
; MessageId: STATUS_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT
;
; MessageText:
;
; The assembly is not a deployment.
;
STATUS_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT EQU 0C015001Eh

;
; MessageId: STATUS_SXS_FILE_NOT_PART_OF_ASSEMBLY
;
; MessageText:
;
; The file is not a part of the assembly.
;
STATUS_SXS_FILE_NOT_PART_OF_ASSEMBLY EQU 0C015001Fh

;
; MessageId: STATUS_ADVANCED_INSTALLER_FAILED
;
; MessageText:
;
; An advanced installer failed during setup or servicing.
;
STATUS_ADVANCED_INSTALLER_FAILED EQU 0C0150020h

;
; MessageId: STATUS_XML_ENCODING_MISMATCH
;
; MessageText:
;
; The character encoding in the XML declaration did not match the encoding used in the document.
;
STATUS_XML_ENCODING_MISMATCH     EQU 0C0150021h

;
; MessageId: STATUS_SXS_MANIFEST_TOO_BIG
;
; MessageText:
;
; The size of the manifest exceeds the maximum allowed.
;
STATUS_SXS_MANIFEST_TOO_BIG      EQU 0C0150022h

;
; MessageId: STATUS_SXS_SETTING_NOT_REGISTERED
;
; MessageText:
;
; The setting is not registered.
;
STATUS_SXS_SETTING_NOT_REGISTERED EQU 0C0150023h

;
; MessageId: STATUS_SXS_TRANSACTION_CLOSURE_INCOMPLETE
;
; MessageText:
;
; One or more required members of the transaction are not present.
;
STATUS_SXS_TRANSACTION_CLOSURE_INCOMPLETE EQU 0C0150024h

;
; MessageId: STATUS_SMI_PRIMITIVE_INSTALLER_FAILED
;
; MessageText:
;
; The SMI primitive installer failed during setup or servicing.
;
STATUS_SMI_PRIMITIVE_INSTALLER_FAILED EQU 0C0150025h

;
; MessageId: STATUS_GENERIC_COMMAND_FAILED
;
; MessageText:
;
; A generic command executable returned a result that indicates failure.
;
STATUS_GENERIC_COMMAND_FAILED    EQU 0C0150026h

;
; MessageId: STATUS_SXS_FILE_HASH_MISSING
;
; MessageText:
;
; A component is missing file verification information in its manifest.
;
STATUS_SXS_FILE_HASH_MISSING     EQU 0C0150027h


;
;  Cluster error values
;

;
; MessageId: STATUS_CLUSTER_INVALID_NODE
;
; MessageText:
;
; The cluster node is not valid.
;
STATUS_CLUSTER_INVALID_NODE      EQU 0C0130001h

;
; MessageId: STATUS_CLUSTER_NODE_EXISTS
;
; MessageText:
;
; The cluster node already exists.
;
STATUS_CLUSTER_NODE_EXISTS       EQU 0C0130002h

;
; MessageId: STATUS_CLUSTER_JOIN_IN_PROGRESS
;
; MessageText:
;
; A node is in the process of joining the cluster.
;
STATUS_CLUSTER_JOIN_IN_PROGRESS  EQU 0C0130003h

;
; MessageId: STATUS_CLUSTER_NODE_NOT_FOUND
;
; MessageText:
;
; The cluster node was not found.
;
STATUS_CLUSTER_NODE_NOT_FOUND    EQU 0C0130004h

;
; MessageId: STATUS_CLUSTER_LOCAL_NODE_NOT_FOUND
;
; MessageText:
;
; The cluster local node information was not found.
;
STATUS_CLUSTER_LOCAL_NODE_NOT_FOUND EQU 0C0130005h

;
; MessageId: STATUS_CLUSTER_NETWORK_EXISTS
;
; MessageText:
;
; The cluster network already exists.
;
STATUS_CLUSTER_NETWORK_EXISTS    EQU 0C0130006h

;
; MessageId: STATUS_CLUSTER_NETWORK_NOT_FOUND
;
; MessageText:
;
; The cluster network was not found.
;
STATUS_CLUSTER_NETWORK_NOT_FOUND EQU 0C0130007h

;
; MessageId: STATUS_CLUSTER_NETINTERFACE_EXISTS
;
; MessageText:
;
; The cluster network interface already exists.
;
STATUS_CLUSTER_NETINTERFACE_EXISTS EQU 0C0130008h

;
; MessageId: STATUS_CLUSTER_NETINTERFACE_NOT_FOUND
;
; MessageText:
;
; The cluster network interface was not found.
;
STATUS_CLUSTER_NETINTERFACE_NOT_FOUND EQU 0C0130009h

;
; MessageId: STATUS_CLUSTER_INVALID_REQUEST
;
; MessageText:
;
; The cluster request is not valid for this object.
;
STATUS_CLUSTER_INVALID_REQUEST   EQU 0C013000Ah

;
; MessageId: STATUS_CLUSTER_INVALID_NETWORK_PROVIDER
;
; MessageText:
;
; The cluster network provider is not valid.
;
STATUS_CLUSTER_INVALID_NETWORK_PROVIDER EQU 0C013000Bh

;
; MessageId: STATUS_CLUSTER_NODE_DOWN
;
; MessageText:
;
; The cluster node is down.
;
STATUS_CLUSTER_NODE_DOWN         EQU 0C013000Ch

;
; MessageId: STATUS_CLUSTER_NODE_UNREACHABLE
;
; MessageText:
;
; The cluster node is not reachable.
;
STATUS_CLUSTER_NODE_UNREACHABLE  EQU 0C013000Dh

;
; MessageId: STATUS_CLUSTER_NODE_NOT_MEMBER
;
; MessageText:
;
; The cluster node is not a member of the cluster.
;
STATUS_CLUSTER_NODE_NOT_MEMBER   EQU 0C013000Eh

;
; MessageId: STATUS_CLUSTER_JOIN_NOT_IN_PROGRESS
;
; MessageText:
;
; A cluster join operation is not in progress.
;
STATUS_CLUSTER_JOIN_NOT_IN_PROGRESS EQU 0C013000Fh

;
; MessageId: STATUS_CLUSTER_INVALID_NETWORK
;
; MessageText:
;
; The cluster network is not valid.
;
STATUS_CLUSTER_INVALID_NETWORK   EQU 0C0130010h

;
; MessageId: STATUS_CLUSTER_NO_NET_ADAPTERS
;
; MessageText:
;
; No network adapters are available.
;
STATUS_CLUSTER_NO_NET_ADAPTERS   EQU 0C0130011h

;
; MessageId: STATUS_CLUSTER_NODE_UP
;
; MessageText:
;
; The cluster node is up.
;
STATUS_CLUSTER_NODE_UP           EQU 0C0130012h

;
; MessageId: STATUS_CLUSTER_NODE_PAUSED
;
; MessageText:
;
; The cluster node is paused.
;
STATUS_CLUSTER_NODE_PAUSED       EQU 0C0130013h

;
; MessageId: STATUS_CLUSTER_NODE_NOT_PAUSED
;
; MessageText:
;
; The cluster node is not paused.
;
STATUS_CLUSTER_NODE_NOT_PAUSED   EQU 0C0130014h

;
; MessageId: STATUS_CLUSTER_NO_SECURITY_CONTEXT
;
; MessageText:
;
; No cluster security context is available.
;
STATUS_CLUSTER_NO_SECURITY_CONTEXT EQU 0C0130015h

;
; MessageId: STATUS_CLUSTER_NETWORK_NOT_INTERNAL
;
; MessageText:
;
; The cluster network is not configured for internal cluster communication.
;
STATUS_CLUSTER_NETWORK_NOT_INTERNAL EQU 0C0130016h

;
; MessageId: STATUS_CLUSTER_POISONED
;
; MessageText:
;
; The cluster node has been poisoned.
;
STATUS_CLUSTER_POISONED          EQU 0C0130017h

;
; MessageId: STATUS_CLUSTER_NON_CSV_PATH
;
; MessageText:
;
; The path does not belong to a cluster shared volume.
;
STATUS_CLUSTER_NON_CSV_PATH      EQU 0C0130018h

;
; MessageId: STATUS_CLUSTER_CSV_VOLUME_NOT_LOCAL
;
; MessageText:
;
; The cluster shared volume is not locally mounted.
;
STATUS_CLUSTER_CSV_VOLUME_NOT_LOCAL EQU 0C0130019h

;
; MessageId: STATUS_CLUSTER_CSV_READ_OPLOCK_BREAK_IN_PROGRESS
;
; MessageText:
;
; The operation has failed because read oplock break is in progress.
;
STATUS_CLUSTER_CSV_READ_OPLOCK_BREAK_IN_PROGRESS EQU 0C0130020h

;
; MessageId: STATUS_CLUSTER_CSV_AUTO_PAUSE_ERROR
;
; MessageText:
;
; The operation has failed. CSVFS has to pause and refresh information.
;
STATUS_CLUSTER_CSV_AUTO_PAUSE_ERROR EQU 0C0130021h

;
; MessageId: STATUS_CLUSTER_CSV_REDIRECTED
;
; MessageText:
;
; The operation has failed. CSVFS does not allow block i/o in redirected mode.
;
STATUS_CLUSTER_CSV_REDIRECTED    EQU 0C0130022h

;
; MessageId: STATUS_CLUSTER_CSV_NOT_REDIRECTED
;
; MessageText:
;
; The operation has failed. CSVFS is not in redirected mode.
;
STATUS_CLUSTER_CSV_NOT_REDIRECTED EQU 0C0130023h

;
; MessageId: STATUS_CLUSTER_CSV_VOLUME_DRAINING
;
; MessageText:
;
; CSVFS is failing operation because it is in draining state.
;
STATUS_CLUSTER_CSV_VOLUME_DRAINING EQU 0C0130024h

;
; MessageId: STATUS_CLUSTER_CSV_SNAPSHOT_CREATION_IN_PROGRESS
;
; MessageText:
;
; The operation has failed because snapshot creation is in progress.
;
STATUS_CLUSTER_CSV_SNAPSHOT_CREATION_IN_PROGRESS EQU 0C0130025h

;
; MessageId: STATUS_CLUSTER_CSV_VOLUME_DRAINING_SUCCEEDED_DOWNLEVEL
;
; MessageText:
;
; The operation has succeeded on the down level file system, but CSV is failing it because it is in draining state.
;
STATUS_CLUSTER_CSV_VOLUME_DRAINING_SUCCEEDED_DOWNLEVEL EQU 0C0130026h


;
;  Transaction Manager error values
;

;
; MessageId: STATUS_TRANSACTIONAL_CONFLICT
;
; MessageText:
;
; The function attempted to use a name that is reserved for use by another transaction.
;
STATUS_TRANSACTIONAL_CONFLICT    EQU 0C0190001h

;
; MessageId: STATUS_INVALID_TRANSACTION
;
; MessageText:
;
; The transaction handle associated with this operation is not valid.
;
STATUS_INVALID_TRANSACTION       EQU 0C0190002h

;
; MessageId: STATUS_TRANSACTION_NOT_ACTIVE
;
; MessageText:
;
; The requested operation was made in the context of a transaction that is no longer active.
;
STATUS_TRANSACTION_NOT_ACTIVE    EQU 0C0190003h

;
; MessageId: STATUS_TM_INITIALIZATION_FAILED
;
; MessageText:
;
; The Transaction Manager was unable to be successfully initialized. Transacted operations are not supported.
;
STATUS_TM_INITIALIZATION_FAILED  EQU 0C0190004h

;
; MessageId: STATUS_RM_NOT_ACTIVE
;
; MessageText:
;
; Transaction support within the specified resource manager is not started or was shut down due to an error.
;
STATUS_RM_NOT_ACTIVE             EQU 0C0190005h

;
; MessageId: STATUS_RM_METADATA_CORRUPT
;
; MessageText:
;
; The metadata of the RM has been corrupted. The RM will not function.
;
STATUS_RM_METADATA_CORRUPT       EQU 0C0190006h

;
; MessageId: STATUS_TRANSACTION_NOT_JOINED
;
; MessageText:
;
; The resource manager has attempted to prepare a transaction that it has not successfully joined.
;
STATUS_TRANSACTION_NOT_JOINED    EQU 0C0190007h

;
; MessageId: STATUS_DIRECTORY_NOT_RM
;
; MessageText:
;
; The specified directory does not contain a file system resource manager.
;
STATUS_DIRECTORY_NOT_RM          EQU 0C0190008h

;
; MessageId: STATUS_COULD_NOT_RESIZE_LOG
;
; MessageText:
;
; The log could not be set to the requested size.
;
STATUS_COULD_NOT_RESIZE_LOG      EQU 080190009h

;
; MessageId: STATUS_TRANSACTIONS_UNSUPPORTED_REMOTE
;
; MessageText:
;
; The remote server or share does not support transacted file operations.
;
STATUS_TRANSACTIONS_UNSUPPORTED_REMOTE EQU 0C019000Ah

;
; MessageId: STATUS_LOG_RESIZE_INVALID_SIZE
;
; MessageText:
;
; The requested log size for the file system resource manager is invalid.
;
STATUS_LOG_RESIZE_INVALID_SIZE   EQU 0C019000Bh

;
; MessageId: STATUS_REMOTE_FILE_VERSION_MISMATCH
;
; MessageText:
;
; The remote server sent mismatching version number or Fid for a file opened with transactions.
;
STATUS_REMOTE_FILE_VERSION_MISMATCH EQU 0C019000Ch

;
; MessageId: STATUS_CRM_PROTOCOL_ALREADY_EXISTS
;
; MessageText:
;
; The RM tried to register a protocol that already exists.
;
STATUS_CRM_PROTOCOL_ALREADY_EXISTS EQU 0C019000Fh

;
; MessageId: STATUS_TRANSACTION_PROPAGATION_FAILED
;
; MessageText:
;
; The attempt to propagate the Transaction failed.
;
STATUS_TRANSACTION_PROPAGATION_FAILED EQU 0C0190010h

;
; MessageId: STATUS_CRM_PROTOCOL_NOT_FOUND
;
; MessageText:
;
; The requested propagation protocol was not registered as a CRM.
;
STATUS_CRM_PROTOCOL_NOT_FOUND    EQU 0C0190011h

;
; MessageId: STATUS_TRANSACTION_SUPERIOR_EXISTS
;
; MessageText:
;
; The Transaction object already has a superior enlistment, and the caller attempted an operation that would have created a new superior. Only a single superior enlistment is allowed.
;
STATUS_TRANSACTION_SUPERIOR_EXISTS EQU 0C0190012h

;
; MessageId: STATUS_TRANSACTION_REQUEST_NOT_VALID
;
; MessageText:
;
; The requested operation is not valid on the Transaction object in its current state.
;
STATUS_TRANSACTION_REQUEST_NOT_VALID EQU 0C0190013h

;
; MessageId: STATUS_TRANSACTION_NOT_REQUESTED
;
; MessageText:
;
; The caller has called a response API, but the response is not expected because the TM did not issue the corresponding request to the caller.
;
STATUS_TRANSACTION_NOT_REQUESTED EQU 0C0190014h

;
; MessageId: STATUS_TRANSACTION_ALREADY_ABORTED
;
; MessageText:
;
; It is too late to perform the requested operation, since the Transaction has already been aborted.
;
STATUS_TRANSACTION_ALREADY_ABORTED EQU 0C0190015h

;
; MessageId: STATUS_TRANSACTION_ALREADY_COMMITTED
;
; MessageText:
;
; It is too late to perform the requested operation, since the Transaction has already been committed.
;
STATUS_TRANSACTION_ALREADY_COMMITTED EQU 0C0190016h

;
; MessageId: STATUS_TRANSACTION_INVALID_MARSHALL_BUFFER
;
; MessageText:
;
; The buffer passed in to NtPushTransaction or NtPullTransaction is not in a valid format.
;
STATUS_TRANSACTION_INVALID_MARSHALL_BUFFER EQU 0C0190017h

;
; MessageId: STATUS_CURRENT_TRANSACTION_NOT_VALID
;
; MessageText:
;
; The current transaction context associated with the thread is not a valid handle to a transaction object.
;
STATUS_CURRENT_TRANSACTION_NOT_VALID EQU 0C0190018h

;
; MessageId: STATUS_LOG_GROWTH_FAILED
;
; MessageText:
;
; An attempt to create space in the transactional resource manager's log failed. The failure status has been recorded in the event log.
;
STATUS_LOG_GROWTH_FAILED         EQU 0C0190019h

;
; MessageId: STATUS_OBJECT_NO_LONGER_EXISTS
;
; MessageText:
;
; The object (file, stream, link) corresponding to the handle has been deleted by a transaction savepoint rollback.
;
STATUS_OBJECT_NO_LONGER_EXISTS   EQU 0C0190021h

;
; MessageId: STATUS_STREAM_MINIVERSION_NOT_FOUND
;
; MessageText:
;
; The specified file miniversion was not found for this transacted file open.
;
STATUS_STREAM_MINIVERSION_NOT_FOUND EQU 0C0190022h

;
; MessageId: STATUS_STREAM_MINIVERSION_NOT_VALID
;
; MessageText:
;
; The specified file miniversion was found but has been invalidated. Most likely cause is a transaction savepoint rollback.
;
STATUS_STREAM_MINIVERSION_NOT_VALID EQU 0C0190023h

;
; MessageId: STATUS_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION
;
; MessageText:
;
; A miniversion may only be opened in the context of the transaction that created it.
;
STATUS_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION EQU 0C0190024h

;
; MessageId: STATUS_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT
;
; MessageText:
;
; It is not possible to open a miniversion with modify access.
;
STATUS_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT EQU 0C0190025h

;
; MessageId: STATUS_CANT_CREATE_MORE_STREAM_MINIVERSIONS
;
; MessageText:
;
; It is not possible to create any more miniversions for this stream.
;
STATUS_CANT_CREATE_MORE_STREAM_MINIVERSIONS EQU 0C0190026h

;
; MessageId: STATUS_HANDLE_NO_LONGER_VALID
;
; MessageText:
;
; The handle has been invalidated by a transaction. The most likely cause is the presence of memory mapping on a file or an open handle when the transaction ended or rolled back to savepoint.
;
STATUS_HANDLE_NO_LONGER_VALID    EQU 0C0190028h

;
; MessageId: STATUS_NO_TXF_METADATA
;
; MessageText:
;
; There is no transaction metadata on the file.
;
STATUS_NO_TXF_METADATA           EQU 080190029h

;
; MessageId: STATUS_LOG_CORRUPTION_DETECTED
;
; MessageText:
;
; The log data is corrupt.
;
STATUS_LOG_CORRUPTION_DETECTED   EQU 0C0190030h

;
; MessageId: STATUS_CANT_RECOVER_WITH_HANDLE_OPEN
;
; MessageText:
;
; The file can't be recovered because there is a handle still open on it.
;
STATUS_CANT_RECOVER_WITH_HANDLE_OPEN EQU 080190031h

;
; MessageId: STATUS_RM_DISCONNECTED
;
; MessageText:
;
; The transaction outcome is unavailable because the resource manager responsible for it has disconnected.
;
STATUS_RM_DISCONNECTED           EQU 0C0190032h

;
; MessageId: STATUS_ENLISTMENT_NOT_SUPERIOR
;
; MessageText:
;
; The request was rejected because the enlistment in question is not a superior enlistment.
;
STATUS_ENLISTMENT_NOT_SUPERIOR   EQU 0C0190033h

;
; MessageId: STATUS_RECOVERY_NOT_NEEDED
;
; MessageText:
;
; The transactional resource manager is already consistent. Recovery is not needed.
;
STATUS_RECOVERY_NOT_NEEDED       EQU 040190034h

;
; MessageId: STATUS_RM_ALREADY_STARTED
;
; MessageText:
;
; The transactional resource manager has already been started.
;
STATUS_RM_ALREADY_STARTED        EQU 040190035h

;
; MessageId: STATUS_FILE_IDENTITY_NOT_PERSISTENT
;
; MessageText:
;
; The file cannot be opened transactionally, because its identity depends on the outcome of an unresolved transaction.
;
STATUS_FILE_IDENTITY_NOT_PERSISTENT EQU 0C0190036h

;
; MessageId: STATUS_CANT_BREAK_TRANSACTIONAL_DEPENDENCY
;
; MessageText:
;
; The operation cannot be performed because another transaction is depending on the fact that this property will not change.
;
STATUS_CANT_BREAK_TRANSACTIONAL_DEPENDENCY EQU 0C0190037h

;
; MessageId: STATUS_CANT_CROSS_RM_BOUNDARY
;
; MessageText:
;
; The operation would involve a single file with two transactional resource managers and is therefore not allowed.
;
STATUS_CANT_CROSS_RM_BOUNDARY    EQU 0C0190038h

;
; MessageId: STATUS_TXF_DIR_NOT_EMPTY
;
; MessageText:
;
; The $Txf directory must be empty for this operation to succeed.
;
STATUS_TXF_DIR_NOT_EMPTY         EQU 0C0190039h

;
; MessageId: STATUS_INDOUBT_TRANSACTIONS_EXIST
;
; MessageText:
;
; The operation would leave a transactional resource manager in an inconsistent state and is therefore not allowed.
;
STATUS_INDOUBT_TRANSACTIONS_EXIST EQU 0C019003Ah

;
; MessageId: STATUS_TM_VOLATILE
;
; MessageText:
;
; The operation could not be completed because the transaction manager does not have a log.
;
STATUS_TM_VOLATILE               EQU 0C019003Bh

;
; MessageId: STATUS_ROLLBACK_TIMER_EXPIRED
;
; MessageText:
;
; A rollback could not be scheduled because a previously scheduled rollback has already executed or been queued for execution.
;
STATUS_ROLLBACK_TIMER_EXPIRED    EQU 0C019003Ch

;
; MessageId: STATUS_TXF_ATTRIBUTE_CORRUPT
;
; MessageText:
;
; The transactional metadata attribute on the file or directory %hs is corrupt and unreadable.
;
STATUS_TXF_ATTRIBUTE_CORRUPT     EQU 0C019003Dh

;
; MessageId: STATUS_EFS_NOT_ALLOWED_IN_TRANSACTION
;
; MessageText:
;
; The encryption operation could not be completed because a transaction is active.
;
STATUS_EFS_NOT_ALLOWED_IN_TRANSACTION EQU 0C019003Eh

;
; MessageId: STATUS_TRANSACTIONAL_OPEN_NOT_ALLOWED
;
; MessageText:
;
; This object is not allowed to be opened in a transaction.
;
STATUS_TRANSACTIONAL_OPEN_NOT_ALLOWED EQU 0C019003Fh

;
; MessageId: STATUS_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE
;
; MessageText:
;
; Memory mapping (creating a mapped section) a remote file under a transaction is not supported.
;
STATUS_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE EQU 0C0190040h

;
; MessageId: STATUS_TXF_METADATA_ALREADY_PRESENT
;
; MessageText:
;
; Transaction metadata is already present on this file and cannot be superseded.
;
STATUS_TXF_METADATA_ALREADY_PRESENT EQU 080190041h

;
; MessageId: STATUS_TRANSACTION_SCOPE_CALLBACKS_NOT_SET
;
; MessageText:
;
; A transaction scope could not be entered because the scope handler has not been initialized.
;
STATUS_TRANSACTION_SCOPE_CALLBACKS_NOT_SET EQU 080190042h

;
; MessageId: STATUS_TRANSACTION_REQUIRED_PROMOTION
;
; MessageText:
;
; Promotion was required in order to allow the resource manager to enlist, but the transaction was set to disallow it.
;
STATUS_TRANSACTION_REQUIRED_PROMOTION EQU 0C0190043h

;
; MessageId: STATUS_CANNOT_EXECUTE_FILE_IN_TRANSACTION
;
; MessageText:
;
; This file is open for modification in an unresolved transaction and may be opened for execute only by a transacted reader.
;
STATUS_CANNOT_EXECUTE_FILE_IN_TRANSACTION EQU 0C0190044h

;
; MessageId: STATUS_TRANSACTIONS_NOT_FROZEN
;
; MessageText:
;
; The request to thaw frozen transactions was ignored because transactions had not previously been frozen.
;
STATUS_TRANSACTIONS_NOT_FROZEN   EQU 0C0190045h

;
; MessageId: STATUS_TRANSACTION_FREEZE_IN_PROGRESS
;
; MessageText:
;
; Transactions cannot be frozen because a freeze is already in progress.
;
STATUS_TRANSACTION_FREEZE_IN_PROGRESS EQU 0C0190046h

;
; MessageId: STATUS_NOT_SNAPSHOT_VOLUME
;
; MessageText:
;
; The target volume is not a snapshot volume. This operation is only valid on a volume mounted as a snapshot.
;
STATUS_NOT_SNAPSHOT_VOLUME       EQU 0C0190047h

;
; MessageId: STATUS_NO_SAVEPOINT_WITH_OPEN_FILES
;
; MessageText:
;
; The savepoint operation failed because files are open on the transaction. This is not permitted.
;
STATUS_NO_SAVEPOINT_WITH_OPEN_FILES EQU 0C0190048h

;
; MessageId: STATUS_SPARSE_NOT_ALLOWED_IN_TRANSACTION
;
; MessageText:
;
; The sparse operation could not be completed because a transaction is active on the file.
;
STATUS_SPARSE_NOT_ALLOWED_IN_TRANSACTION EQU 0C0190049h

;
; MessageId: STATUS_TM_IDENTITY_MISMATCH
;
; MessageText:
;
; The call to create a TransactionManager object failed because the Tm Identity stored in the logfile does not match the Tm Identity that was passed in as an argument.
;
STATUS_TM_IDENTITY_MISMATCH      EQU 0C019004Ah

;
; MessageId: STATUS_FLOATED_SECTION
;
; MessageText:
;
; I/O was attempted on a section object that has been floated as a result of a transaction ending. There is no valid data.
;
STATUS_FLOATED_SECTION           EQU 0C019004Bh

;
; MessageId: STATUS_CANNOT_ACCEPT_TRANSACTED_WORK
;
; MessageText:
;
; The transactional resource manager cannot currently accept transacted work due to a transient condition such as low resources.
;
STATUS_CANNOT_ACCEPT_TRANSACTED_WORK EQU 0C019004Ch

;
; MessageId: STATUS_CANNOT_ABORT_TRANSACTIONS
;
; MessageText:
;
; The transactional resource manager had too many tranactions outstanding that could not be aborted. The transactional resource manger has been shut down.
;
STATUS_CANNOT_ABORT_TRANSACTIONS EQU 0C019004Dh

;
; MessageId: STATUS_TRANSACTION_NOT_FOUND
;
; MessageText:
;
; The specified Transaction was unable to be opened, because it was not found.
;
STATUS_TRANSACTION_NOT_FOUND     EQU 0C019004Eh

;
; MessageId: STATUS_RESOURCEMANAGER_NOT_FOUND
;
; MessageText:
;
; The specified ResourceManager was unable to be opened, because it was not found.
;
STATUS_RESOURCEMANAGER_NOT_FOUND EQU 0C019004Fh

;
; MessageId: STATUS_ENLISTMENT_NOT_FOUND
;
; MessageText:
;
; The specified Enlistment was unable to be opened, because it was not found.
;
STATUS_ENLISTMENT_NOT_FOUND      EQU 0C0190050h

;
; MessageId: STATUS_TRANSACTIONMANAGER_NOT_FOUND
;
; MessageText:
;
; The specified TransactionManager was unable to be opened, because it was not found.
;
STATUS_TRANSACTIONMANAGER_NOT_FOUND EQU 0C0190051h

;
; MessageId: STATUS_TRANSACTIONMANAGER_NOT_ONLINE
;
; MessageText:
;
; The object specified could not be created or opened, because its associated TransactionManager is not online.  The TransactionManager must be brought fully Online by calling RecoverTransactionManager to recover to the end of its LogFile before objects in its Transaction or ResourceManager namespaces can be opened.  In addition, errors in writing records to its LogFile can cause a TransactionManager to go offline.
;
STATUS_TRANSACTIONMANAGER_NOT_ONLINE EQU 0C0190052h

;
; MessageId: STATUS_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION
;
; MessageText:
;
; The specified TransactionManager was unable to create the objects contained in its logfile in the Ob namespace. Therefore, the TransactionManager was unable to recover.
;
STATUS_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION EQU 0C0190053h

;
; MessageId: STATUS_TRANSACTION_NOT_ROOT
;
; MessageText:
;
; The call to create a superior Enlistment on this Transaction object could not be completed, because the Transaction object specified for the enlistment is a subordinate branch of the Transaction. Only the root of the Transaction can be enlisted on as a superior.
;
STATUS_TRANSACTION_NOT_ROOT      EQU 0C0190054h

;
; MessageId: STATUS_TRANSACTION_OBJECT_EXPIRED
;
; MessageText:
;
; Because the associated transaction manager or resource manager has been closed, the handle is no longer valid.
;
STATUS_TRANSACTION_OBJECT_EXPIRED EQU 0C0190055h

;
; MessageId: STATUS_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION
;
; MessageText:
;
; The compression operation could not be completed because a transaction is active on the file.
;
STATUS_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION EQU 0C0190056h

;
; MessageId: STATUS_TRANSACTION_RESPONSE_NOT_ENLISTED
;
; MessageText:
;
; The specified operation could not be performed on this Superior enlistment, because the enlistment was not created with the corresponding completion response in the NotificationMask.
;
STATUS_TRANSACTION_RESPONSE_NOT_ENLISTED EQU 0C0190057h

;
; MessageId: STATUS_TRANSACTION_RECORD_TOO_LONG
;
; MessageText:
;
; The specified operation could not be performed, because the record that would be logged was too long. This can occur because of two conditions:  either there are too many Enlistments on this Transaction, or the combined RecoveryInformation being logged on behalf of those Enlistments is too long.
;
STATUS_TRANSACTION_RECORD_TOO_LONG EQU 0C0190058h

;
; MessageId: STATUS_NO_LINK_TRACKING_IN_TRANSACTION
;
; MessageText:
;
; The link tracking operation could not be completed because a transaction is active.
;
STATUS_NO_LINK_TRACKING_IN_TRANSACTION EQU 0C0190059h

;
; MessageId: STATUS_OPERATION_NOT_SUPPORTED_IN_TRANSACTION
;
; MessageText:
;
; This operation cannot be performed in a transaction.
;
STATUS_OPERATION_NOT_SUPPORTED_IN_TRANSACTION EQU 0C019005Ah

;
; MessageId: STATUS_TRANSACTION_INTEGRITY_VIOLATED
;
; MessageText:
;
; The kernel transaction manager had to abort or forget the transaction because it blocked forward progress.
;
STATUS_TRANSACTION_INTEGRITY_VIOLATED EQU 0C019005Bh

;
; MessageId: STATUS_TRANSACTIONMANAGER_IDENTITY_MISMATCH
;
; MessageText:
;
; The TransactionManager identity that was supplied did not match the one recorded in the TransactionManager's log file.
;
STATUS_TRANSACTIONMANAGER_IDENTITY_MISMATCH EQU 0C019005Ch

;
; MessageId: STATUS_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT
;
; MessageText:
;
; This snapshot operation cannot continue because a transactional resource manager cannot be frozen in its current state.  Please try again.
;
STATUS_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT EQU 0C019005Dh

;
; MessageId: STATUS_TRANSACTION_MUST_WRITETHROUGH
;
; MessageText:
;
; The transaction cannot be enlisted on with the specified EnlistmentMask, because the transaction has already completed the PrePrepare phase.  In order to ensure correctness, the ResourceManager must switch to a write-through mode and cease caching data within this transaction.  Enlisting for only subsequent transaction phases may still succeed.
;
STATUS_TRANSACTION_MUST_WRITETHROUGH EQU 0C019005Eh

;
; MessageId: STATUS_TRANSACTION_NO_SUPERIOR
;
; MessageText:
;
; The transaction does not have a superior enlistment.
;
STATUS_TRANSACTION_NO_SUPERIOR   EQU 0C019005Fh

;
; MessageId: STATUS_EXPIRED_HANDLE
;
; MessageText:
;
; The handle is no longer properly associated with its transaction.  It may have been opened in a transactional resource manager that was subsequently forced to restart.  Please close the handle and open a new one.
;
STATUS_EXPIRED_HANDLE            EQU 0C0190060h

;
; MessageId: STATUS_TRANSACTION_NOT_ENLISTED
;
; MessageText:
;
; The specified operation could not be performed because the resource manager is not enlisted in the transaction.
;
STATUS_TRANSACTION_NOT_ENLISTED  EQU 0C0190061h


;
;  CLFS (common log file system) error values
;

;
; MessageId: STATUS_LOG_SECTOR_INVALID
;
; MessageText:
;
; Log service found an invalid log sector.
;
STATUS_LOG_SECTOR_INVALID        EQU 0C01A0001h

;
; MessageId: STATUS_LOG_SECTOR_PARITY_INVALID
;
; MessageText:
;
; Log service encountered a log sector with invalid block parity.
;
STATUS_LOG_SECTOR_PARITY_INVALID EQU 0C01A0002h

;
; MessageId: STATUS_LOG_SECTOR_REMAPPED
;
; MessageText:
;
; Log service encountered a remapped log sector.
;
STATUS_LOG_SECTOR_REMAPPED       EQU 0C01A0003h

;
; MessageId: STATUS_LOG_BLOCK_INCOMPLETE
;
; MessageText:
;
; Log service encountered a partial or incomplete log block.
;
STATUS_LOG_BLOCK_INCOMPLETE      EQU 0C01A0004h

;
; MessageId: STATUS_LOG_INVALID_RANGE
;
; MessageText:
;
; Log service encountered an attempt access data outside the active log range.
;
STATUS_LOG_INVALID_RANGE         EQU 0C01A0005h

;
; MessageId: STATUS_LOG_BLOCKS_EXHAUSTED
;
; MessageText:
;
; Log service user log marshalling buffers are exhausted.
;
STATUS_LOG_BLOCKS_EXHAUSTED      EQU 0C01A0006h

;
; MessageId: STATUS_LOG_READ_CONTEXT_INVALID
;
; MessageText:
;
; Log service encountered an attempt read from a marshalling area with an invalid read context.
;
STATUS_LOG_READ_CONTEXT_INVALID  EQU 0C01A0007h

;
; MessageId: STATUS_LOG_RESTART_INVALID
;
; MessageText:
;
; Log service encountered an invalid log restart area.
;
STATUS_LOG_RESTART_INVALID       EQU 0C01A0008h

;
; MessageId: STATUS_LOG_BLOCK_VERSION
;
; MessageText:
;
; Log service encountered an invalid log block version.
;
STATUS_LOG_BLOCK_VERSION         EQU 0C01A0009h

;
; MessageId: STATUS_LOG_BLOCK_INVALID
;
; MessageText:
;
; Log service encountered an invalid log block.
;
STATUS_LOG_BLOCK_INVALID         EQU 0C01A000Ah

;
; MessageId: STATUS_LOG_READ_MODE_INVALID
;
; MessageText:
;
; Log service encountered an attempt to read the log with an invalid read mode.
;
STATUS_LOG_READ_MODE_INVALID     EQU 0C01A000Bh

;
; MessageId: STATUS_LOG_NO_RESTART
;
; MessageText:
;
; Log service encountered a log stream with no restart area.
;
STATUS_LOG_NO_RESTART            EQU 0401A000Ch

;
; MessageId: STATUS_LOG_METADATA_CORRUPT
;
; MessageText:
;
; Log service encountered a corrupted metadata file.
;
STATUS_LOG_METADATA_CORRUPT      EQU 0C01A000Dh

;
; MessageId: STATUS_LOG_METADATA_INVALID
;
; MessageText:
;
; Log service encountered a metadata file that could not be created by the log file system.
;
STATUS_LOG_METADATA_INVALID      EQU 0C01A000Eh

;
; MessageId: STATUS_LOG_METADATA_INCONSISTENT
;
; MessageText:
;
; Log service encountered a metadata file with inconsistent data.
;
STATUS_LOG_METADATA_INCONSISTENT EQU 0C01A000Fh

;
; MessageId: STATUS_LOG_RESERVATION_INVALID
;
; MessageText:
;
; Log service encountered an attempt to erroneously allocate or dispose reservation space.
;
STATUS_LOG_RESERVATION_INVALID   EQU 0C01A0010h

;
; MessageId: STATUS_LOG_CANT_DELETE
;
; MessageText:
;
; Log service cannot delete log file or file system container.
;
STATUS_LOG_CANT_DELETE           EQU 0C01A0011h

;
; MessageId: STATUS_LOG_CONTAINER_LIMIT_EXCEEDED
;
; MessageText:
;
; Log service has reached the maximum allowable containers allocated to a log file.
;
STATUS_LOG_CONTAINER_LIMIT_EXCEEDED EQU 0C01A0012h

;
; MessageId: STATUS_LOG_START_OF_LOG
;
; MessageText:
;
; Log service has attempted to read or write backwards past the start of the log.
;
STATUS_LOG_START_OF_LOG          EQU 0C01A0013h

;
; MessageId: STATUS_LOG_POLICY_ALREADY_INSTALLED
;
; MessageText:
;
; Log policy could not be installed because a policy of the same type is already present.
;
STATUS_LOG_POLICY_ALREADY_INSTALLED EQU 0C01A0014h

;
; MessageId: STATUS_LOG_POLICY_NOT_INSTALLED
;
; MessageText:
;
; Log policy in question was not installed at the time of the request.
;
STATUS_LOG_POLICY_NOT_INSTALLED  EQU 0C01A0015h

;
; MessageId: STATUS_LOG_POLICY_INVALID
;
; MessageText:
;
; The installed set of policies on the log is invalid.
;
STATUS_LOG_POLICY_INVALID        EQU 0C01A0016h

;
; MessageId: STATUS_LOG_POLICY_CONFLICT
;
; MessageText:
;
; A policy on the log in question prevented the operation from completing.
;
STATUS_LOG_POLICY_CONFLICT       EQU 0C01A0017h

;
; MessageId: STATUS_LOG_PINNED_ARCHIVE_TAIL
;
; MessageText:
;
; Log space cannot be reclaimed because the log is pinned by the archive tail.
;
STATUS_LOG_PINNED_ARCHIVE_TAIL   EQU 0C01A0018h

;
; MessageId: STATUS_LOG_RECORD_NONEXISTENT
;
; MessageText:
;
; Log record is not a record in the log file.
;
STATUS_LOG_RECORD_NONEXISTENT    EQU 0C01A0019h

;
; MessageId: STATUS_LOG_RECORDS_RESERVED_INVALID
;
; MessageText:
;
; Number of reserved log records or the adjustment of the number of reserved log records is invalid.
;
STATUS_LOG_RECORDS_RESERVED_INVALID EQU 0C01A001Ah

;
; MessageId: STATUS_LOG_SPACE_RESERVED_INVALID
;
; MessageText:
;
; Reserved log space or the adjustment of the log space is invalid.
;
STATUS_LOG_SPACE_RESERVED_INVALID EQU 0C01A001Bh

;
; MessageId: STATUS_LOG_TAIL_INVALID
;
; MessageText:
;
; A new or existing archive tail or base of the active log is invalid.
;
STATUS_LOG_TAIL_INVALID          EQU 0C01A001Ch

;
; MessageId: STATUS_LOG_FULL
;
; MessageText:
;
; Log space is exhausted.
;
STATUS_LOG_FULL                  EQU 0C01A001Dh

;
; MessageId: STATUS_LOG_MULTIPLEXED
;
; MessageText:
;
; Log is multiplexed, no direct writes to the physical log is allowed.
;
STATUS_LOG_MULTIPLEXED           EQU 0C01A001Eh

;
; MessageId: STATUS_LOG_DEDICATED
;
; MessageText:
;
; The operation failed because the log is a dedicated log.
;
STATUS_LOG_DEDICATED             EQU 0C01A001Fh

;
; MessageId: STATUS_LOG_ARCHIVE_NOT_IN_PROGRESS
;
; MessageText:
;
; The operation requires an archive context.
;
STATUS_LOG_ARCHIVE_NOT_IN_PROGRESS EQU 0C01A0020h

;
; MessageId: STATUS_LOG_ARCHIVE_IN_PROGRESS
;
; MessageText:
;
; Log archival is in progress.
;
STATUS_LOG_ARCHIVE_IN_PROGRESS   EQU 0C01A0021h

;
; MessageId: STATUS_LOG_EPHEMERAL
;
; MessageText:
;
; The operation requires a non-ephemeral log, but the log is ephemeral.
;
STATUS_LOG_EPHEMERAL             EQU 0C01A0022h

;
; MessageId: STATUS_LOG_NOT_ENOUGH_CONTAINERS
;
; MessageText:
;
; The log must have at least two containers before it can be read from or written to.
;
STATUS_LOG_NOT_ENOUGH_CONTAINERS EQU 0C01A0023h

;
; MessageId: STATUS_LOG_CLIENT_ALREADY_REGISTERED
;
; MessageText:
;
; A log client has already registered on the stream.
;
STATUS_LOG_CLIENT_ALREADY_REGISTERED EQU 0C01A0024h

;
; MessageId: STATUS_LOG_CLIENT_NOT_REGISTERED
;
; MessageText:
;
; A log client has not been registered on the stream.
;
STATUS_LOG_CLIENT_NOT_REGISTERED EQU 0C01A0025h

;
; MessageId: STATUS_LOG_FULL_HANDLER_IN_PROGRESS
;
; MessageText:
;
; A request has already been made to handle the log full condition.
;
STATUS_LOG_FULL_HANDLER_IN_PROGRESS EQU 0C01A0026h

;
; MessageId: STATUS_LOG_CONTAINER_READ_FAILED
;
; MessageText:
;
; Log service encountered an error when attempting to read from a log container.
;
STATUS_LOG_CONTAINER_READ_FAILED EQU 0C01A0027h

;
; MessageId: STATUS_LOG_CONTAINER_WRITE_FAILED
;
; MessageText:
;
; Log service encountered an error when attempting to write to a log container.
;
STATUS_LOG_CONTAINER_WRITE_FAILED EQU 0C01A0028h

;
; MessageId: STATUS_LOG_CONTAINER_OPEN_FAILED
;
; MessageText:
;
; Log service encountered an error when attempting open a log container.
;
STATUS_LOG_CONTAINER_OPEN_FAILED EQU 0C01A0029h

;
; MessageId: STATUS_LOG_CONTAINER_STATE_INVALID
;
; MessageText:
;
; Log service encountered an invalid container state when attempting a requested action.
;
STATUS_LOG_CONTAINER_STATE_INVALID EQU 0C01A002Ah

;
; MessageId: STATUS_LOG_STATE_INVALID
;
; MessageText:
;
; Log service is not in the correct state to perform a requested action.
;
STATUS_LOG_STATE_INVALID         EQU 0C01A002Bh

;
; MessageId: STATUS_LOG_PINNED
;
; MessageText:
;
; Log space cannot be reclaimed because the log is pinned.
;
STATUS_LOG_PINNED                EQU 0C01A002Ch

;
; MessageId: STATUS_LOG_METADATA_FLUSH_FAILED
;
; MessageText:
;
; Log metadata flush failed.
;
STATUS_LOG_METADATA_FLUSH_FAILED EQU 0C01A002Dh

;
; MessageId: STATUS_LOG_INCONSISTENT_SECURITY
;
; MessageText:
;
; Security on the log and its containers is inconsistent.
;
STATUS_LOG_INCONSISTENT_SECURITY EQU 0C01A002Eh

;
; MessageId: STATUS_LOG_APPENDED_FLUSH_FAILED
;
; MessageText:
;
; Records were appended to the log or reservation changes were made, but the log could not be flushed.
;
STATUS_LOG_APPENDED_FLUSH_FAILED EQU 0C01A002Fh

;
; MessageId: STATUS_LOG_PINNED_RESERVATION
;
; MessageText:
;
; The log is pinned due to reservation consuming most of the log space. Free some reserved records to make space available.
;
STATUS_LOG_PINNED_RESERVATION    EQU 0C01A0030h


;
; XDDM Video Facility Error codes (videoprt.sys)
;

;
; MessageId: STATUS_VIDEO_HUNG_DISPLAY_DRIVER_THREAD
;
; MessageText:
;
; {Display Driver Stopped Responding}
; The %hs display driver has stopped working normally. Save your work and reboot the system to restore full display functionality. The next time you reboot the machine a dialog will be displayed giving you a chance to upload data about this failure to Microsoft.
;
STATUS_VIDEO_HUNG_DISPLAY_DRIVER_THREAD EQU 0C01B00EAh

;
; MessageId: STATUS_VIDEO_HUNG_DISPLAY_DRIVER_THREAD_RECOVERED
;
; MessageText:
;
; {Display Driver Stopped Responding and recovered}
; The %hs display driver has stopped working normally. The recovery had been performed.
;
STATUS_VIDEO_HUNG_DISPLAY_DRIVER_THREAD_RECOVERED EQU 0801B00EBh

;
; MessageId: STATUS_VIDEO_DRIVER_DEBUG_REPORT_REQUEST
;
; MessageText:
;
; {Display Driver Recovered From Failure}
; The %hs display driver has detected and recovered from a failure. Some graphical operations may have failed. The next time you reboot the machine a dialog will be displayed giving you a chance to upload data about this failure to Microsoft.
;
STATUS_VIDEO_DRIVER_DEBUG_REPORT_REQUEST EQU 0401B00ECh


;
; Monitor Facility Error codes (monitor.sys)
;

;
; MessageId: STATUS_MONITOR_NO_DESCRIPTOR
;
; MessageText:
;
; Monitor descriptor could not be obtained.
;
STATUS_MONITOR_NO_DESCRIPTOR     EQU 0C01D0001h

;
; MessageId: STATUS_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT
;
; MessageText:
;
; Format of the obtained monitor descriptor is not supported by this release.
;
STATUS_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT EQU 0C01D0002h

;
; MessageId: STATUS_MONITOR_INVALID_DESCRIPTOR_CHECKSUM
;
; MessageText:
;
; Checksum of the obtained monitor descriptor is invalid.
;
STATUS_MONITOR_INVALID_DESCRIPTOR_CHECKSUM EQU 0C01D0003h

;
; MessageId: STATUS_MONITOR_INVALID_STANDARD_TIMING_BLOCK
;
; MessageText:
;
; Monitor descriptor contains an invalid standard timing block.
;
STATUS_MONITOR_INVALID_STANDARD_TIMING_BLOCK EQU 0C01D0004h

;
; MessageId: STATUS_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED
;
; MessageText:
;
; WMI data block registration failed for one of the MSMonitorClass WMI subclasses.
;
STATUS_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED EQU 0C01D0005h

;
; MessageId: STATUS_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK
;
; MessageText:
;
; Provided monitor descriptor block is either corrupted or does not contain monitor's detailed serial number.
;
STATUS_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK EQU 0C01D0006h

;
; MessageId: STATUS_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK
;
; MessageText:
;
; Provided monitor descriptor block is either corrupted or does not contain monitor's user friendly name.
;
STATUS_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK EQU 0C01D0007h

;
; MessageId: STATUS_MONITOR_NO_MORE_DESCRIPTOR_DATA
;
; MessageText:
;
; There is no monitor descriptor data at the specified (offset, size) region.
;
STATUS_MONITOR_NO_MORE_DESCRIPTOR_DATA EQU 0C01D0008h

;
; MessageId: STATUS_MONITOR_INVALID_DETAILED_TIMING_BLOCK
;
; MessageText:
;
; Monitor descriptor contains an invalid detailed timing block.
;
STATUS_MONITOR_INVALID_DETAILED_TIMING_BLOCK EQU 0C01D0009h

;
; MessageId: STATUS_MONITOR_INVALID_MANUFACTURE_DATE
;
; MessageText:
;
; Monitor descriptor contains invalid manufacture date.
;
STATUS_MONITOR_INVALID_MANUFACTURE_DATE EQU 0C01D000Ah


;
; Graphics Facility Error codes (dxg.sys, dxgkrnl.sys)
;

;
;   Common Windows Graphics Kernel Subsystem status codes {0x0000..0x00ff}
;
;
; MessageId: STATUS_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER
;
; MessageText:
;
; Exclusive mode ownership is needed to create unmanaged primary allocation.
;
STATUS_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER EQU 0C01E0000h

;
; MessageId: STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER
;
; MessageText:
;
; The driver needs more DMA buffer space in order to complete the requested operation.
;
STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER EQU 0C01E0001h

;
; MessageId: STATUS_GRAPHICS_INVALID_DISPLAY_ADAPTER
;
; MessageText:
;
; Specified display adapter handle is invalid.
;
STATUS_GRAPHICS_INVALID_DISPLAY_ADAPTER EQU 0C01E0002h

;
; MessageId: STATUS_GRAPHICS_ADAPTER_WAS_RESET
;
; MessageText:
;
; Specified display adapter and all of its state has been reset.
;
STATUS_GRAPHICS_ADAPTER_WAS_RESET EQU 0C01E0003h

;
; MessageId: STATUS_GRAPHICS_INVALID_DRIVER_MODEL
;
; MessageText:
;
; The driver stack doesn't match the expected driver model.
;
STATUS_GRAPHICS_INVALID_DRIVER_MODEL EQU 0C01E0004h

;
; MessageId: STATUS_GRAPHICS_PRESENT_MODE_CHANGED
;
; MessageText:
;
; Present happened but ended up into the changed desktop mode
;
STATUS_GRAPHICS_PRESENT_MODE_CHANGED EQU 0C01E0005h

;
; MessageId: STATUS_GRAPHICS_PRESENT_OCCLUDED
;
; MessageText:
;
; Nothing to present due to desktop occlusion
;
STATUS_GRAPHICS_PRESENT_OCCLUDED EQU 0C01E0006h

;
; MessageId: STATUS_GRAPHICS_PRESENT_DENIED
;
; MessageText:
;
; Not able to present due to denial of desktop access
;
STATUS_GRAPHICS_PRESENT_DENIED   EQU 0C01E0007h

;
; MessageId: STATUS_GRAPHICS_CANNOTCOLORCONVERT
;
; MessageText:
;
; Not able to present with color convertion
;
STATUS_GRAPHICS_CANNOTCOLORCONVERT EQU 0C01E0008h

;
; MessageId: STATUS_GRAPHICS_DRIVER_MISMATCH
;
; MessageText:
;
; The kernel driver detected a version mismatch between it and the user mode driver.
;
STATUS_GRAPHICS_DRIVER_MISMATCH  EQU 0C01E0009h

;
; MessageId: STATUS_GRAPHICS_PARTIAL_DATA_POPULATED
;
; MessageText:
;
; Specified buffer is not big enough to contain entire requested dataset. Partial data populated upto the size of the buffer. Caller needs to provide buffer of size as specified in the partially populated buffer's content (interface specific).
;
STATUS_GRAPHICS_PARTIAL_DATA_POPULATED EQU 0401E000Ah

;
; MessageId: STATUS_GRAPHICS_PRESENT_REDIRECTION_DISABLED
;
; MessageText:
;
; Present redirection is disabled (desktop windowing management subsystem is off).
;
STATUS_GRAPHICS_PRESENT_REDIRECTION_DISABLED EQU 0C01E000Bh

;
; MessageId: STATUS_GRAPHICS_PRESENT_UNOCCLUDED
;
; MessageText:
;
; Previous exclusive VidPn source owner has released its ownership
;
STATUS_GRAPHICS_PRESENT_UNOCCLUDED EQU 0C01E000Ch

;
; MessageId: STATUS_GRAPHICS_WINDOWDC_NOT_AVAILABLE
;
; MessageText:
;
; Window DC is not available for presentation
;
STATUS_GRAPHICS_WINDOWDC_NOT_AVAILABLE EQU 0C01E000Dh

;
; MessageId: STATUS_GRAPHICS_WINDOWLESS_PRESENT_DISABLED
;
; MessageText:
;
; Windowless present is disabled (desktop windowing management subsystem is off).
;
STATUS_GRAPHICS_WINDOWLESS_PRESENT_DISABLED EQU 0C01E000Eh

;
;   Video Memory Manager (VidMM) specific status codes {0x0100..0x01ff}
;
;
; MessageId: STATUS_GRAPHICS_NO_VIDEO_MEMORY
;
; MessageText:
;
; Not enough video memory available to complete the operation.
;
STATUS_GRAPHICS_NO_VIDEO_MEMORY  EQU 0C01E0100h

;
; MessageId: STATUS_GRAPHICS_CANT_LOCK_MEMORY
;
; MessageText:
;
; Couldn't probe and lock the underlying memory of an allocation.
;
STATUS_GRAPHICS_CANT_LOCK_MEMORY EQU 0C01E0101h

;
; MessageId: STATUS_GRAPHICS_ALLOCATION_BUSY
;
; MessageText:
;
; The allocation is currently busy.
;
STATUS_GRAPHICS_ALLOCATION_BUSY  EQU 0C01E0102h

;
; MessageId: STATUS_GRAPHICS_TOO_MANY_REFERENCES
;
; MessageText:
;
; An object being referenced has already reached the maximum reference count and can't be referenced any further.
;
STATUS_GRAPHICS_TOO_MANY_REFERENCES EQU 0C01E0103h

;
; MessageId: STATUS_GRAPHICS_TRY_AGAIN_LATER
;
; MessageText:
;
; A problem couldn't be solved due to some currently existing condition. The problem should be tried again later.
;
STATUS_GRAPHICS_TRY_AGAIN_LATER  EQU 0C01E0104h

;
; MessageId: STATUS_GRAPHICS_TRY_AGAIN_NOW
;
; MessageText:
;
; A problem couldn't be solved due to some currently existing condition. The problem should be tried again immediately.
;
STATUS_GRAPHICS_TRY_AGAIN_NOW    EQU 0C01E0105h

;
; MessageId: STATUS_GRAPHICS_ALLOCATION_INVALID
;
; MessageText:
;
; The allocation is invalid.
;
STATUS_GRAPHICS_ALLOCATION_INVALID EQU 0C01E0106h

;
; MessageId: STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE
;
; MessageText:
;
; No more unswizzling aperture are currently available.
;
STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE EQU 0C01E0107h

;
; MessageId: STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED
;
; MessageText:
;
; The current allocation can't be unswizzled by an aperture.
;
STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED EQU 0C01E0108h

;
; MessageId: STATUS_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION
;
; MessageText:
;
; The request failed because a pinned allocation can't be evicted.
;
STATUS_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION EQU 0C01E0109h

;
; MessageId: STATUS_GRAPHICS_INVALID_ALLOCATION_USAGE
;
; MessageText:
;
; The allocation can't be used from its current segment location for the specified operation.
;
STATUS_GRAPHICS_INVALID_ALLOCATION_USAGE EQU 0C01E0110h

;
; MessageId: STATUS_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION
;
; MessageText:
;
; A locked allocation can't be used in the current command buffer.
;
STATUS_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION EQU 0C01E0111h

;
; MessageId: STATUS_GRAPHICS_ALLOCATION_CLOSED
;
; MessageText:
;
; The allocation being referenced has been closed permanently.
;
STATUS_GRAPHICS_ALLOCATION_CLOSED EQU 0C01E0112h

;
; MessageId: STATUS_GRAPHICS_INVALID_ALLOCATION_INSTANCE
;
; MessageText:
;
; An invalid allocation instance is being referenced.
;
STATUS_GRAPHICS_INVALID_ALLOCATION_INSTANCE EQU 0C01E0113h

;
; MessageId: STATUS_GRAPHICS_INVALID_ALLOCATION_HANDLE
;
; MessageText:
;
; An invalid allocation handle is being referenced.
;
STATUS_GRAPHICS_INVALID_ALLOCATION_HANDLE EQU 0C01E0114h

;
; MessageId: STATUS_GRAPHICS_WRONG_ALLOCATION_DEVICE
;
; MessageText:
;
; The allocation being referenced doesn't belong to the current device.
;
STATUS_GRAPHICS_WRONG_ALLOCATION_DEVICE EQU 0C01E0115h

;
; MessageId: STATUS_GRAPHICS_ALLOCATION_CONTENT_LOST
;
; MessageText:
;
; The specified allocation lost its content.
;
STATUS_GRAPHICS_ALLOCATION_CONTENT_LOST EQU 0C01E0116h

;
;   Video GPU Scheduler (VidSch) specific status codes {0x0200..0x02ff}
;
;
; MessageId: STATUS_GRAPHICS_GPU_EXCEPTION_ON_DEVICE
;
; MessageText:
;
; GPU exception is detected on the given device. The device is not able to be scheduled.
;
STATUS_GRAPHICS_GPU_EXCEPTION_ON_DEVICE EQU 0C01E0200h

;
; MessageId: STATUS_GRAPHICS_SKIP_ALLOCATION_PREPARATION
;
; MessageText:
;
; Skip preparation of allocations referenced by the DMA buffer.
;
STATUS_GRAPHICS_SKIP_ALLOCATION_PREPARATION EQU 0401E0201h

;
;   Video Present Network Management (VidPNMgr) specific status codes {0x0300..0x03ff}
;
;
; MessageId: STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY
;
; MessageText:
;
; Specified VidPN topology is invalid.
;
STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY EQU 0C01E0300h

;
; MessageId: STATUS_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED
;
; MessageText:
;
; Specified VidPN topology is valid but is not supported by this model of the display adapter.
;
STATUS_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED EQU 0C01E0301h

;
; MessageId: STATUS_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED
;
; MessageText:
;
; Specified VidPN topology is valid but is not supported by the display adapter at this time, due to current allocation of its resources.
;
STATUS_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED EQU 0C01E0302h

;
; MessageId: STATUS_GRAPHICS_INVALID_VIDPN
;
; MessageText:
;
; Specified VidPN handle is invalid.
;
STATUS_GRAPHICS_INVALID_VIDPN    EQU 0C01E0303h

;
; MessageId: STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE
;
; MessageText:
;
; Specified video present source is invalid.
;
STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE EQU 0C01E0304h

;
; MessageId: STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET
;
; MessageText:
;
; Specified video present target is invalid.
;
STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET EQU 0C01E0305h

;
; MessageId: STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED
;
; MessageText:
;
; Specified VidPN modality is not supported (e.g. at least two of the pinned modes are not cofunctionah.
;
STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED EQU 0C01E0306h

;
; MessageId: STATUS_GRAPHICS_MODE_NOT_PINNED
;
; MessageText:
;
; No mode is pinned on the specified VidPN source/target.
;
STATUS_GRAPHICS_MODE_NOT_PINNED  EQU 0401E0307h

;
; MessageId: STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET
;
; MessageText:
;
; Specified VidPN source mode set is invalid.
;
STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET EQU 0C01E0308h

;
; MessageId: STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET
;
; MessageText:
;
; Specified VidPN target mode set is invalid.
;
STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET EQU 0C01E0309h

;
; MessageId: STATUS_GRAPHICS_INVALID_FREQUENCY
;
; MessageText:
;
; Specified video signal frequency is invalid.
;
STATUS_GRAPHICS_INVALID_FREQUENCY EQU 0C01E030Ah

;
; MessageId: STATUS_GRAPHICS_INVALID_ACTIVE_REGION
;
; MessageText:
;
; Specified video signal active region is invalid.
;
STATUS_GRAPHICS_INVALID_ACTIVE_REGION EQU 0C01E030Bh

;
; MessageId: STATUS_GRAPHICS_INVALID_TOTAL_REGION
;
; MessageText:
;
; Specified video signal total region is invalid.
;
STATUS_GRAPHICS_INVALID_TOTAL_REGION EQU 0C01E030Ch

;
; MessageId: STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE
;
; MessageText:
;
; Specified video present source mode is invalid.
;
STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE EQU 0C01E0310h

;
; MessageId: STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE
;
; MessageText:
;
; Specified video present target mode is invalid.
;
STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE EQU 0C01E0311h

;
; MessageId: STATUS_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET
;
; MessageText:
;
; Pinned mode must remain in the set on VidPN's cofunctional modality enumeration.
;
STATUS_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET EQU 0C01E0312h

;
; MessageId: STATUS_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY
;
; MessageText:
;
; Specified video present path is already in VidPN's topology.
;
STATUS_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY EQU 0C01E0313h

;
; MessageId: STATUS_GRAPHICS_MODE_ALREADY_IN_MODESET
;
; MessageText:
;
; Specified mode is already in the mode set.
;
STATUS_GRAPHICS_MODE_ALREADY_IN_MODESET EQU 0C01E0314h

;
; MessageId: STATUS_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET
;
; MessageText:
;
; Specified video present source set is invalid.
;
STATUS_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET EQU 0C01E0315h

;
; MessageId: STATUS_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET
;
; MessageText:
;
; Specified video present target set is invalid.
;
STATUS_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET EQU 0C01E0316h

;
; MessageId: STATUS_GRAPHICS_SOURCE_ALREADY_IN_SET
;
; MessageText:
;
; Specified video present source is already in the video present source set.
;
STATUS_GRAPHICS_SOURCE_ALREADY_IN_SET EQU 0C01E0317h

;
; MessageId: STATUS_GRAPHICS_TARGET_ALREADY_IN_SET
;
; MessageText:
;
; Specified video present target is already in the video present target set.
;
STATUS_GRAPHICS_TARGET_ALREADY_IN_SET EQU 0C01E0318h

;
; MessageId: STATUS_GRAPHICS_INVALID_VIDPN_PRESENT_PATH
;
; MessageText:
;
; Specified VidPN present path is invalid.
;
STATUS_GRAPHICS_INVALID_VIDPN_PRESENT_PATH EQU 0C01E0319h

;
; MessageId: STATUS_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY
;
; MessageText:
;
; Miniport has no recommendation for augmentation of the specified VidPN's topology.
;
STATUS_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY EQU 0C01E031Ah

;
; MessageId: STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET
;
; MessageText:
;
; Specified monitor frequency range set is invalid.
;
STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET EQU 0C01E031Bh

;
; MessageId: STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE
;
; MessageText:
;
; Specified monitor frequency range is invalid.
;
STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE EQU 0C01E031Ch

;
; MessageId: STATUS_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET
;
; MessageText:
;
; Specified frequency range is not in the specified monitor frequency range set.
;
STATUS_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET EQU 0C01E031Dh

;
; MessageId: STATUS_GRAPHICS_NO_PREFERRED_MODE
;
; MessageText:
;
; Specified mode set does not specify preference for one of its modes.
;
STATUS_GRAPHICS_NO_PREFERRED_MODE EQU 0401E031Eh

;
; MessageId: STATUS_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET
;
; MessageText:
;
; Specified frequency range is already in the specified monitor frequency range set.
;
STATUS_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET EQU 0C01E031Fh

;
; MessageId: STATUS_GRAPHICS_STALE_MODESET
;
; MessageText:
;
; Specified mode set is stale. Please reacquire the new mode set.
;
STATUS_GRAPHICS_STALE_MODESET    EQU 0C01E0320h

;
; MessageId: STATUS_GRAPHICS_INVALID_MONITOR_SOURCEMODESET
;
; MessageText:
;
; Specified monitor source mode set is invalid.
;
STATUS_GRAPHICS_INVALID_MONITOR_SOURCEMODESET EQU 0C01E0321h

;
; MessageId: STATUS_GRAPHICS_INVALID_MONITOR_SOURCE_MODE
;
; MessageText:
;
; Specified monitor source mode is invalid.
;
STATUS_GRAPHICS_INVALID_MONITOR_SOURCE_MODE EQU 0C01E0322h

;
; MessageId: STATUS_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN
;
; MessageText:
;
; Miniport does not have any recommendation regarding the request to provide a functional VidPN given the current display adapter configuration.
;
STATUS_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN EQU 0C01E0323h

;
; MessageId: STATUS_GRAPHICS_MODE_ID_MUST_BE_UNIQUE
;
; MessageText:
;
; ID of the specified mode is already used by another mode in the set.
;
STATUS_GRAPHICS_MODE_ID_MUST_BE_UNIQUE EQU 0C01E0324h

;
; MessageId: STATUS_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION
;
; MessageText:
;
; System failed to determine a mode that is supported by both the display adapter and the monitor connected to it.
;
STATUS_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION EQU 0C01E0325h

;
; MessageId: STATUS_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES
;
; MessageText:
;
; Number of video present targets must be greater than or equal to the number of video present sources.
;
STATUS_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES EQU 0C01E0326h

;
; MessageId: STATUS_GRAPHICS_PATH_NOT_IN_TOPOLOGY
;
; MessageText:
;
; Specified present path is not in VidPN's topology.
;
STATUS_GRAPHICS_PATH_NOT_IN_TOPOLOGY EQU 0C01E0327h

;
; MessageId: STATUS_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE
;
; MessageText:
;
; Display adapter must have at least one video present source.
;
STATUS_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE EQU 0C01E0328h

;
; MessageId: STATUS_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET
;
; MessageText:
;
; Display adapter must have at least one video present target.
;
STATUS_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET EQU 0C01E0329h

;
; MessageId: STATUS_GRAPHICS_INVALID_MONITORDESCRIPTORSET
;
; MessageText:
;
; Specified monitor descriptor set is invalid.
;
STATUS_GRAPHICS_INVALID_MONITORDESCRIPTORSET EQU 0C01E032Ah

;
; MessageId: STATUS_GRAPHICS_INVALID_MONITORDESCRIPTOR
;
; MessageText:
;
; Specified monitor descriptor is invalid.
;
STATUS_GRAPHICS_INVALID_MONITORDESCRIPTOR EQU 0C01E032Bh

;
; MessageId: STATUS_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET
;
; MessageText:
;
; Specified descriptor is not in the specified monitor descriptor set.
;
STATUS_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET EQU 0C01E032Ch

;
; MessageId: STATUS_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET
;
; MessageText:
;
; Specified descriptor is already in the specified monitor descriptor set.
;
STATUS_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET EQU 0C01E032Dh

;
; MessageId: STATUS_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE
;
; MessageText:
;
; ID of the specified monitor descriptor is already used by another descriptor in the set.
;
STATUS_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE EQU 0C01E032Eh

;
; MessageId: STATUS_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE
;
; MessageText:
;
; Specified video present target subset type is invalid.
;
STATUS_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE EQU 0C01E032Fh

;
; MessageId: STATUS_GRAPHICS_RESOURCES_NOT_RELATED
;
; MessageText:
;
; Two or more of the specified resources are not related to each other, as defined by the interface semantics.
;
STATUS_GRAPHICS_RESOURCES_NOT_RELATED EQU 0C01E0330h

;
; MessageId: STATUS_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE
;
; MessageText:
;
; ID of the specified video present source is already used by another source in the set.
;
STATUS_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE EQU 0C01E0331h

;
; MessageId: STATUS_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE
;
; MessageText:
;
; ID of the specified video present target is already used by another target in the set.
;
STATUS_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE EQU 0C01E0332h

;
; MessageId: STATUS_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET
;
; MessageText:
;
; Specified VidPN source cannot be used because there is no available VidPN target to connect it to.
;
STATUS_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET EQU 0C01E0333h

;
; MessageId: STATUS_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER
;
; MessageText:
;
; Newly arrived monitor could not be associated with a display adapter.
;
STATUS_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER EQU 0C01E0334h

;
; MessageId: STATUS_GRAPHICS_NO_VIDPNMGR
;
; MessageText:
;
; Display adapter in question does not have an associated VidPN manager.
;
STATUS_GRAPHICS_NO_VIDPNMGR      EQU 0C01E0335h

;
; MessageId: STATUS_GRAPHICS_NO_ACTIVE_VIDPN
;
; MessageText:
;
; VidPN manager of the display adapter in question does not have an active VidPN.
;
STATUS_GRAPHICS_NO_ACTIVE_VIDPN  EQU 0C01E0336h

;
; MessageId: STATUS_GRAPHICS_STALE_VIDPN_TOPOLOGY
;
; MessageText:
;
; Specified VidPN topology is stale. Please reacquire the new topology.
;
STATUS_GRAPHICS_STALE_VIDPN_TOPOLOGY EQU 0C01E0337h

;
; MessageId: STATUS_GRAPHICS_MONITOR_NOT_CONNECTED
;
; MessageText:
;
; There is no monitor connected on the specified video present target.
;
STATUS_GRAPHICS_MONITOR_NOT_CONNECTED EQU 0C01E0338h

;
; MessageId: STATUS_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY
;
; MessageText:
;
; Specified source is not part of the specified VidPN's topology.
;
STATUS_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY EQU 0C01E0339h

;
; MessageId: STATUS_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE
;
; MessageText:
;
; Specified primary surface size is invalid.
;
STATUS_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE EQU 0C01E033Ah

;
; MessageId: STATUS_GRAPHICS_INVALID_VISIBLEREGION_SIZE
;
; MessageText:
;
; Specified visible region size is invalid.
;
STATUS_GRAPHICS_INVALID_VISIBLEREGION_SIZE EQU 0C01E033Bh

;
; MessageId: STATUS_GRAPHICS_INVALID_STRIDE
;
; MessageText:
;
; Specified stride is invalid.
;
STATUS_GRAPHICS_INVALID_STRIDE   EQU 0C01E033Ch

;
; MessageId: STATUS_GRAPHICS_INVALID_PIXELFORMAT
;
; MessageText:
;
; Specified pixel format is invalid.
;
STATUS_GRAPHICS_INVALID_PIXELFORMAT EQU 0C01E033Dh

;
; MessageId: STATUS_GRAPHICS_INVALID_COLORBASIS
;
; MessageText:
;
; Specified color basis is invalid.
;
STATUS_GRAPHICS_INVALID_COLORBASIS EQU 0C01E033Eh

;
; MessageId: STATUS_GRAPHICS_INVALID_PIXELVALUEACCESSMODE
;
; MessageText:
;
; Specified pixel value access mode is invalid.
;
STATUS_GRAPHICS_INVALID_PIXELVALUEACCESSMODE EQU 0C01E033Fh

;
; MessageId: STATUS_GRAPHICS_TARGET_NOT_IN_TOPOLOGY
;
; MessageText:
;
; Specified target is not part of the specified VidPN's topology.
;
STATUS_GRAPHICS_TARGET_NOT_IN_TOPOLOGY EQU 0C01E0340h

;
; MessageId: STATUS_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT
;
; MessageText:
;
; Failed to acquire display mode management interface.
;
STATUS_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT EQU 0C01E0341h

;
; MessageId: STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE
;
; MessageText:
;
; Specified VidPN source is already owned by a DMM client and cannot be used until that client releases it.
;
STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE EQU 0C01E0342h

;
; MessageId: STATUS_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN
;
; MessageText:
;
; Specified VidPN is active and cannot be accessed.
;
STATUS_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN EQU 0C01E0343h

;
; MessageId: STATUS_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL
;
; MessageText:
;
; Specified VidPN present path importance ordinal is invalid.
;
STATUS_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL EQU 0C01E0344h

;
; MessageId: STATUS_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION
;
; MessageText:
;
; Specified VidPN present path content geometry transformation is invalid.
;
STATUS_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION EQU 0C01E0345h

;
; MessageId: STATUS_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED
;
; MessageText:
;
; Specified content geometry transformation is not supported on the respective VidPN present path.
;
STATUS_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED EQU 0C01E0346h

;
; MessageId: STATUS_GRAPHICS_INVALID_GAMMA_RAMP
;
; MessageText:
;
; Specified gamma ramp is invalid.
;
STATUS_GRAPHICS_INVALID_GAMMA_RAMP EQU 0C01E0347h

;
; MessageId: STATUS_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED
;
; MessageText:
;
; Specified gamma ramp is not supported on the respective VidPN present path.
;
STATUS_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED EQU 0C01E0348h

;
; MessageId: STATUS_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED
;
; MessageText:
;
; Multi-sampling is not supported on the respective VidPN present path.
;
STATUS_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED EQU 0C01E0349h

;
; MessageId: STATUS_GRAPHICS_MODE_NOT_IN_MODESET
;
; MessageText:
;
; Specified mode is not in the specified mode set.
;
STATUS_GRAPHICS_MODE_NOT_IN_MODESET EQU 0C01E034Ah

;
; MessageId: STATUS_GRAPHICS_DATASET_IS_EMPTY
;
; MessageText:
;
; Specified data set (e.g. mode set, frequency range set, descriptor set, topology, etc.) is empty.
;
STATUS_GRAPHICS_DATASET_IS_EMPTY EQU 0401E034Bh

;
; MessageId: STATUS_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET
;
; MessageText:
;
; Specified data set (e.g. mode set, frequency range set, descriptor set, topology, etc.) does not contain any more elements.
;
STATUS_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET EQU 0401E034Ch

;
; MessageId: STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON
;
; MessageText:
;
; Specified VidPN topology recommendation reason is invalid.
;
STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON EQU 0C01E034Dh

;
; MessageId: STATUS_GRAPHICS_INVALID_PATH_CONTENT_TYPE
;
; MessageText:
;
; Specified VidPN present path content type is invalid.
;
STATUS_GRAPHICS_INVALID_PATH_CONTENT_TYPE EQU 0C01E034Eh

;
; MessageId: STATUS_GRAPHICS_INVALID_COPYPROTECTION_TYPE
;
; MessageText:
;
; Specified VidPN present path copy protection type is invalid.
;
STATUS_GRAPHICS_INVALID_COPYPROTECTION_TYPE EQU 0C01E034Fh

;
; MessageId: STATUS_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS
;
; MessageText:
;
; No more than one unassigned mode set can exist at any given time for a given VidPN source/target.
;
STATUS_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS EQU 0C01E0350h

;
; MessageId: STATUS_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_PINNED
;
; MessageText:
;
; Specified content transformation is not pinned on the specified VidPN present path.
;
STATUS_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_PINNED EQU 0401E0351h

;
; MessageId: STATUS_GRAPHICS_INVALID_SCANLINE_ORDERING
;
; MessageText:
;
; Specified scanline ordering type is invalid.
;
STATUS_GRAPHICS_INVALID_SCANLINE_ORDERING EQU 0C01E0352h

;
; MessageId: STATUS_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED
;
; MessageText:
;
; Topology changes are not allowed for the specified VidPN.
;
STATUS_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED EQU 0C01E0353h

;
; MessageId: STATUS_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS
;
; MessageText:
;
; All available importance ordinals are already used in specified topology.
;
STATUS_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS EQU 0C01E0354h

;
; MessageId: STATUS_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT
;
; MessageText:
;
; Specified primary surface has a different private format attribute than the current primary surface
;
STATUS_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT EQU 0C01E0355h

;
; MessageId: STATUS_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM
;
; MessageText:
;
; Specified mode pruning algorithm is invalid
;
STATUS_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM EQU 0C01E0356h

;
; MessageId: STATUS_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN
;
; MessageText:
;
; Specified monitor capability origin is invalid.
;
STATUS_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN EQU 0C01E0357h

;
; MessageId: STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT
;
; MessageText:
;
; Specified monitor frequency range constraint is invalid.
;
STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT EQU 0C01E0358h

;
; MessageId: STATUS_GRAPHICS_MAX_NUM_PATHS_REACHED
;
; MessageText:
;
; Maximum supported number of present paths has been reached.
;
STATUS_GRAPHICS_MAX_NUM_PATHS_REACHED EQU 0C01E0359h

;
; MessageId: STATUS_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION
;
; MessageText:
;
; Miniport requested that augmentation be cancelled for the specified source of the specified VidPN's topology.
;
STATUS_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION EQU 0C01E035Ah

;
; MessageId: STATUS_GRAPHICS_INVALID_CLIENT_TYPE
;
; MessageText:
;
; Specified client type was not recognized.
;
STATUS_GRAPHICS_INVALID_CLIENT_TYPE EQU 0C01E035Bh

;
; MessageId: STATUS_GRAPHICS_CLIENTVIDPN_NOT_SET
;
; MessageText:
;
; Client VidPN is not set on this adapter (e.g. no user mode initiated mode changes took place on this adapter yet).
;
STATUS_GRAPHICS_CLIENTVIDPN_NOT_SET EQU 0C01E035Ch

;
;   Port specific status codes {0x0400..0x04ff}
;
;
; MessageId: STATUS_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED
;
; MessageText:
;
; Specified display adapter child device already has an external device connected to it.
;
STATUS_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED EQU 0C01E0400h    

;
; MessageId: STATUS_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED
;
; MessageText:
;
; Specified display adapter child device does not support descriptor exposure.
;
STATUS_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED EQU 0C01E0401h    

;
; MessageId: STATUS_GRAPHICS_UNKNOWN_CHILD_STATUS
;
; MessageText:
;
; Child device presence was not reliably detected.
;
STATUS_GRAPHICS_UNKNOWN_CHILD_STATUS EQU 0401E042Fh

;
; MessageId: STATUS_GRAPHICS_NOT_A_LINKED_ADAPTER
;
; MessageText:
;
; The display adapter is not linked to any other adapters.
;
STATUS_GRAPHICS_NOT_A_LINKED_ADAPTER EQU 0C01E0430h

;
; MessageId: STATUS_GRAPHICS_LEADLINK_NOT_ENUMERATED
;
; MessageText:
;
; Lead adapter in a linked configuration was not enumerated yet.
;
STATUS_GRAPHICS_LEADLINK_NOT_ENUMERATED EQU 0C01E0431h

;
; MessageId: STATUS_GRAPHICS_CHAINLINKS_NOT_ENUMERATED
;
; MessageText:
;
; Some chain adapters in a linked configuration were not enumerated yet.
;
STATUS_GRAPHICS_CHAINLINKS_NOT_ENUMERATED EQU 0C01E0432h

;
; MessageId: STATUS_GRAPHICS_ADAPTER_CHAIN_NOT_READY
;
; MessageText:
;
; The chain of linked adapters is not ready to start because of an unknown failure.
;
STATUS_GRAPHICS_ADAPTER_CHAIN_NOT_READY EQU 0C01E0433h

;
; MessageId: STATUS_GRAPHICS_CHAINLINKS_NOT_STARTED
;
; MessageText:
;
; An attempt was made to start a lead link display adapter when the chain links were not started yet.
;
STATUS_GRAPHICS_CHAINLINKS_NOT_STARTED EQU 0C01E0434h

;
; MessageId: STATUS_GRAPHICS_CHAINLINKS_NOT_POWERED_ON
;
; MessageText:
;
; An attempt was made to power up a lead link display adapter when the chain links were powered down.
;
STATUS_GRAPHICS_CHAINLINKS_NOT_POWERED_ON EQU 0C01E0435h

;
; MessageId: STATUS_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE
;
; MessageText:
;
; The adapter link was found to be in an inconsistent state. Not all adapters are in an expected PNP/Power state.
;
STATUS_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE EQU 0C01E0436h

;
; MessageId: STATUS_GRAPHICS_LEADLINK_START_DEFERRED
;
; MessageText:
;
; Starting the leadlink adapter has been deferred temporarily.
;
STATUS_GRAPHICS_LEADLINK_START_DEFERRED EQU 0401E0437h

;
; MessageId: STATUS_GRAPHICS_NOT_POST_DEVICE_DRIVER
;
; MessageText:
;
; The driver trying to start is not the same as the driver for the POSTed display adapter.
;
STATUS_GRAPHICS_NOT_POST_DEVICE_DRIVER EQU 0C01E0438h

;
; MessageId: STATUS_GRAPHICS_POLLING_TOO_FREQUENTLY
;
; MessageText:
;
; The display adapter is being polled for children too frequently at the same polling level.
;
STATUS_GRAPHICS_POLLING_TOO_FREQUENTLY EQU 0401E0439h

;
; MessageId: STATUS_GRAPHICS_START_DEFERRED
;
; MessageText:
;
; Starting the adapter has been deferred temporarily.
;
STATUS_GRAPHICS_START_DEFERRED   EQU 0401E043Ah

;
; MessageId: STATUS_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED
;
; MessageText:
;
; An operation is being attempted that requires the display adapter to be in a quiescent state.
;
STATUS_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED EQU 0C01E043Bh

;
;   OPM, PVP and UAB status codes {0x0500..0x057F}
;
;
; MessageId: STATUS_GRAPHICS_OPM_NOT_SUPPORTED
;
; MessageText:
;
; The driver does not support OPM.
;
STATUS_GRAPHICS_OPM_NOT_SUPPORTED EQU 0C01E0500h    

;
; MessageId: STATUS_GRAPHICS_COPP_NOT_SUPPORTED
;
; MessageText:
;
; The driver does not support COPP.
;
STATUS_GRAPHICS_COPP_NOT_SUPPORTED EQU 0C01E0501h    

;
; MessageId: STATUS_GRAPHICS_UAB_NOT_SUPPORTED
;
; MessageText:
;
; The driver does not support UAB.
;
STATUS_GRAPHICS_UAB_NOT_SUPPORTED EQU 0C01E0502h    

;
; MessageId: STATUS_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS
;
; MessageText:
;
; The specified encrypted parameters are invalid.
;
STATUS_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS EQU 0C01E0503h    

;
; MessageId: STATUS_GRAPHICS_OPM_NO_PROTECTED_OUTPUTS_EXIST
;
; MessageText:
;
; The GDI display device passed to this function does not have any active protected outputs.
;
STATUS_GRAPHICS_OPM_NO_PROTECTED_OUTPUTS_EXIST EQU 0C01E0505h

;
; MessageId: STATUS_GRAPHICS_OPM_INTERNAL_ERROR
;
; MessageText:
;
; An internal error caused an operation to fail.
;
STATUS_GRAPHICS_OPM_INTERNAL_ERROR EQU 0C01E050Bh

;
; MessageId: STATUS_GRAPHICS_OPM_INVALID_HANDLE
;
; MessageText:
;
; The function failed because the caller passed in an invalid OPM user mode handle.
;
STATUS_GRAPHICS_OPM_INVALID_HANDLE EQU 0C01E050Ch

;
; MessageId: STATUS_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH
;
; MessageText:
;
; A certificate could not be returned because the certificate buffer passed to the function was too small.
;
STATUS_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH EQU 0C01E050Eh

;
; MessageId: STATUS_GRAPHICS_OPM_SPANNING_MODE_ENABLED
;
; MessageText:
;
; The DxgkDdiOpmCreateProtectedOutput function could not create a protected output because the Video Present Target is in spanning mode.
;
STATUS_GRAPHICS_OPM_SPANNING_MODE_ENABLED EQU 0C01E050Fh

;
; MessageId: STATUS_GRAPHICS_OPM_THEATER_MODE_ENABLED
;
; MessageText:
;
; The DxgkDdiOpmCreateProtectedOutput function could not create a protected output because the Video Present Target is in theater mode.
;
STATUS_GRAPHICS_OPM_THEATER_MODE_ENABLED EQU 0C01E0510h

;
; MessageId: STATUS_GRAPHICS_PVP_HFS_FAILED
;
; MessageText:
;
; The function failed because the display adapter's Hardware Functionality Scan failed to validate the graphics hardware.
;
STATUS_GRAPHICS_PVP_HFS_FAILED   EQU 0C01E0511h

;
; MessageId: STATUS_GRAPHICS_OPM_INVALID_SRM
;
; MessageText:
;
; The HDCP System Renewability Message passed to this function did not comply with section 5 of the HDCP 1.1 specification.
;
STATUS_GRAPHICS_OPM_INVALID_SRM  EQU 0C01E0512h

;
; MessageId: STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP
;
; MessageText:
;
; The protected output cannot enable the High-bandwidth Digital Content Protection (HDCP) System because it does not support HDCP.
;
STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP EQU 0C01E0513h

;
; MessageId: STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP
;
; MessageText:
;
; The protected output cannot enable Analogue Copy Protection (ACP) because it does not support ACP.
;
STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP EQU 0C01E0514h

;
; MessageId: STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA
;
; MessageText:
;
; The protected output cannot enable the Content Generation Management System Analogue (CGMS-A) protection technology because it does not support CGMS-A.
;
STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA EQU 0C01E0515h

;
; MessageId: STATUS_GRAPHICS_OPM_HDCP_SRM_NEVER_SET
;
; MessageText:
;
; The DxgkDdiOPMGetInformation function cannot return the version of the SRM being used because the application never successfully passed an SRM to the protected output.
;
STATUS_GRAPHICS_OPM_HDCP_SRM_NEVER_SET EQU 0C01E0516h

;
; MessageId: STATUS_GRAPHICS_OPM_RESOLUTION_TOO_HIGH
;
; MessageText:
;
; The DxgkDdiOPMConfigureProtectedOutput function cannot enable the specified output protection technology because the output's screen resolution is too high.
;
STATUS_GRAPHICS_OPM_RESOLUTION_TOO_HIGH EQU 0C01E0517h

;
; MessageId: STATUS_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE
;
; MessageText:
;
; The DxgkDdiOPMConfigureProtectedOutput function cannot enable HDCP because the display adapter's HDCP hardware is already being used by other physical outputs.
;
STATUS_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE EQU 0C01E0518h

;
; MessageId: STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_NO_LONGER_EXISTS
;
; MessageText:
;
; The operating system asynchronously destroyed this OPM protected output because the operating system's state changed. This error typically occurs because the monitor PDO associated with this protected output was removed, the monitor PDO associated with this protected output was stopped, or the protected output's session became a non-console session.
;
STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_NO_LONGER_EXISTS EQU 0C01E051Ah

;
; MessageId: STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS
;
; MessageText:
;
; Either the DxgkDdiOPMGetCOPPCompatibleInformation, DxgkDdiOPMGetInformation, or DxgkDdiOPMConfigureProtectedOutput function failed. This error is returned when the caller tries to use a COPP specific command while the protected output has OPM semantics only.
;
STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS EQU 0C01E051Ch

;
; MessageId: STATUS_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST
;
; MessageText:
;
; The DxgkDdiOPMGetInformation and DxgkDdiOPMGetCOPPCompatibleInformation functions return this error code if the passed in sequence number is not the expected sequence number or the passed in OMAC value is invalid.
;
STATUS_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST EQU 0C01E051Dh

;
; MessageId: STATUS_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR
;
; MessageText:
;
; The function failed because an unexpected error occurred inside of a display driver.
;
STATUS_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR EQU 0C01E051Eh

;
; MessageId: STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS
;
; MessageText:
;
; Either the DxgkDdiOPMGetCOPPCompatibleInformation, DxgkDdiOPMGetInformation, or DxgkDdiOPMConfigureProtectedOutput function failed. This error is returned when the caller tries to use an OPM specific command while the protected output has COPP semantics only.
;
STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS EQU 0C01E051Fh

;
; MessageId: STATUS_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED
;
; MessageText:
;
; The DxgkDdiOPMGetCOPPCompatibleInformation and DxgkDdiOPMConfigureProtectedOutput functions return this error if the display driver does not support the DXGKMDT_OPM_GET_ACP_AND_CGMSA_SIGNALING and DXGKMDT_OPM_SET_ACP_AND_CGMSA_SIGNALING GUIDs.
;
STATUS_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED EQU 0C01E0520h

;
; MessageId: STATUS_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST
;
; MessageText:
;
; The DxgkDdiOPMConfigureProtectedOutput function returns this error code if the passed in sequence number is not the expected sequence number or the passed in OMAC value is invalid.
;
STATUS_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST EQU 0C01E0521h

;
;   Monitor Configuration API status codes {0x0580..0x05DF}
;
;
; MessageId: STATUS_GRAPHICS_I2C_NOT_SUPPORTED
;
; MessageText:
;
; The monitor connected to the specified video output does not have an I2C bus.
;
STATUS_GRAPHICS_I2C_NOT_SUPPORTED EQU 0C01E0580h    

;
; MessageId: STATUS_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST
;
; MessageText:
;
; No device on the I2C bus has the specified address.
;
STATUS_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST EQU 0C01E0581h    

;
; MessageId: STATUS_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA
;
; MessageText:
;
; An error occurred while transmitting data to the device on the I2C bus.
;
STATUS_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA EQU 0C01E0582h    

;
; MessageId: STATUS_GRAPHICS_I2C_ERROR_RECEIVING_DATA
;
; MessageText:
;
; An error occurred while receiving data from the device on the I2C bus.
;
STATUS_GRAPHICS_I2C_ERROR_RECEIVING_DATA EQU 0C01E0583h    

;
; MessageId: STATUS_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED
;
; MessageText:
;
; The monitor does not support the specified VCP code.
;
STATUS_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED EQU 0C01E0584h    

;
; MessageId: STATUS_GRAPHICS_DDCCI_INVALID_DATA
;
; MessageText:
;
; The data received from the monitor is invalid.
;
STATUS_GRAPHICS_DDCCI_INVALID_DATA EQU 0C01E0585h    

;
; MessageId: STATUS_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE
;
; MessageText:
;
; The function failed because a monitor returned an invalid Timing Status byte when the operating system used the DDC/CI Get Timing Report & Timing Message command to get a timing report from a monitor.
;
STATUS_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE EQU 0C01E0586h

;
; MessageId: STATUS_GRAPHICS_DDCCI_INVALID_CAPABILITIES_STRING
;
; MessageText:
;
; A monitor returned a DDC/CI capabilities string which did not comply with the ACCESS.bus 3.0, DDC/CI 1.1, or MCCS 2 Revision 1 specification.
;
STATUS_GRAPHICS_DDCCI_INVALID_CAPABILITIES_STRING EQU 0C01E0587h

;
; MessageId: STATUS_GRAPHICS_MCA_INTERNAL_ERROR
;
; MessageText:
;
; An internal error caused an operation to fail.
;
STATUS_GRAPHICS_MCA_INTERNAL_ERROR EQU 0C01E0588h

;
; MessageId: STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND
;
; MessageText:
;
; An operation failed because a DDC/CI message had an invalid value in its command field.
;
STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND EQU 0C01E0589h

;
; MessageId: STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH
;
; MessageText:
;
; An error occurred because the field length of a DDC/CI message contained an invalid value.
;
STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH EQU 0C01E058Ah

;
; MessageId: STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM
;
; MessageText:
;
; An error occurred because the checksum field in a DDC/CI message did not match the message's computed checksum value. This error implies that the data was corrupted while it was being transmitted from a monitor to a computer.
;
STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM EQU 0C01E058Bh

;
; MessageId: STATUS_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE
;
; MessageText:
;
; This function failed because an invalid monitor handle was passed to it.
;
STATUS_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE EQU 0C01E058Ch

;
; MessageId: STATUS_GRAPHICS_MONITOR_NO_LONGER_EXISTS
;
; MessageText:
;
; The operating system asynchronously destroyed the monitor which corresponds to this handle because the operating system's state changed. This error typically occurs because the monitor PDO associated with this handle was removed, the monitor PDO associated with this handle was stopped, or a display mode change occurred. A display mode change occurs when windows sends a WM_DISPLAYCHANGE windows message to applications.
;
STATUS_GRAPHICS_MONITOR_NO_LONGER_EXISTS EQU 0C01E058Dh

;
;   OPM, UAB, PVP and DDC/CI shared status codes {0x25E0..0x25FF}
;
;
; MessageId: STATUS_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED
;
; MessageText:
;
; This function can only be used if a program is running in the local console session. It cannot be used if a program is running on a remote desktop session or on a terminal server session.
;
STATUS_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED EQU 0C01E05E0h

;
; MessageId: STATUS_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME
;
; MessageText:
;
; This function cannot find an actual GDI display device which corresponds to the specified GDI display device name.
;
STATUS_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME EQU 0C01E05E1h

;
; MessageId: STATUS_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP
;
; MessageText:
;
; The function failed because the specified GDI display device was not attached to the Windows desktop.
;
STATUS_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP EQU 0C01E05E2h

;
; MessageId: STATUS_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED
;
; MessageText:
;
; This function does not support GDI mirroring display devices because GDI mirroring display devices do not have any physical monitors associated with them.
;
STATUS_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED EQU 0C01E05E3h

;
; MessageId: STATUS_GRAPHICS_INVALID_POINTER
;
; MessageText:
;
; The function failed because an invalid pointer parameter was passed to it. A pointer parameter is invalid if it is NULL, it points to an invalid address, it points to a kernel mode address or it is not correctly aligned.
;
STATUS_GRAPHICS_INVALID_POINTER  EQU 0C01E05E4h

;
; MessageId: STATUS_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE
;
; MessageText:
;
; This function failed because the GDI device passed to it did not have any monitors associated with it.
;
STATUS_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE EQU 0C01E05E5h

;
; MessageId: STATUS_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL
;
; MessageText:
;
; An array passed to the function cannot hold all of the data that the function must copy into the array.
;
STATUS_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL EQU 0C01E05E6h

;
; MessageId: STATUS_GRAPHICS_INTERNAL_ERROR
;
; MessageText:
;
; An internal error caused an operation to fail.
;
STATUS_GRAPHICS_INTERNAL_ERROR   EQU 0C01E05E7h

;
; MessageId: STATUS_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS
;
; MessageText:
;
; The function failed because the current session is changing its type. This function cannot be called when the current session is changing its type. There are currently three types of sessions: console, disconnected and remote.
;
STATUS_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS EQU 0C01E05E8h


;
; Full Volume Encryption Error codes (fvevol.sys)
;

;
; MessageId: STATUS_FVE_LOCKED_VOLUME
;
; MessageText:
;
; This volume is locked by BitLocker Drive Encryption.
;
STATUS_FVE_LOCKED_VOLUME         EQU 0C0210000h

;
; MessageId: STATUS_FVE_NOT_ENCRYPTED
;
; MessageText:
;
; The volume is not encrypted, no key is available.
;
STATUS_FVE_NOT_ENCRYPTED         EQU 0C0210001h

;
; MessageId: STATUS_FVE_BAD_INFORMATION
;
; MessageText:
;
; The control block for the encrypted volume is not valid.
;
STATUS_FVE_BAD_INFORMATION       EQU 0C0210002h

;
; MessageId: STATUS_FVE_TOO_SMALL
;
; MessageText:
;
; The volume cannot be encrypted because it does not have enough free space.
;
STATUS_FVE_TOO_SMALL             EQU 0C0210003h

;
; MessageId: STATUS_FVE_FAILED_WRONG_FS
;
; MessageText:
;
; The volume cannot be encrypted because the file system is not supported.
;
STATUS_FVE_FAILED_WRONG_FS       EQU 0C0210004h

;
; MessageId: STATUS_FVE_BAD_PARTITION_SIZE
;
; MessageText:
;
; The file system size is larger than the partition size in the partition table.
;
STATUS_FVE_BAD_PARTITION_SIZE    EQU 0C0210005h

;
; MessageId: STATUS_FVE_FS_NOT_EXTENDED
;
; MessageText:
;
; The file system does not extend to the end of the volume.
;
STATUS_FVE_FS_NOT_EXTENDED       EQU 0C0210006h

;
; MessageId: STATUS_FVE_FS_MOUNTED
;
; MessageText:
;
; This operation cannot be performed while a file system is mounted on the volume.
;
STATUS_FVE_FS_MOUNTED            EQU 0C0210007h

;
; MessageId: STATUS_FVE_NO_LICENSE
;
; MessageText:
;
; BitLocker Drive Encryption is not included with this version of Windows.
;
STATUS_FVE_NO_LICENSE            EQU 0C0210008h

;
; MessageId: STATUS_FVE_ACTION_NOT_ALLOWED
;
; MessageText:
;
; Requested action not allowed in the current volume state.
;
STATUS_FVE_ACTION_NOT_ALLOWED    EQU 0C0210009h

;
; MessageId: STATUS_FVE_BAD_DATA
;
; MessageText:
;
; Data supplied is malformed.
;
STATUS_FVE_BAD_DATA              EQU 0C021000Ah

;
; MessageId: STATUS_FVE_VOLUME_NOT_BOUND
;
; MessageText:
;
; The volume is not bound to the system.
;
STATUS_FVE_VOLUME_NOT_BOUND      EQU 0C021000Bh

;
; MessageId: STATUS_FVE_NOT_DATA_VOLUME
;
; MessageText:
;
; That volume is not a data volume.
;
STATUS_FVE_NOT_DATA_VOLUME       EQU 0C021000Ch

;
; MessageId: STATUS_FVE_CONV_READ_ERROR
;
; MessageText:
;
; A read operation failed while converting the volume.
;
STATUS_FVE_CONV_READ_ERROR       EQU 0C021000Dh

;
; MessageId: STATUS_FVE_CONV_WRITE_ERROR
;
; MessageText:
;
; A write operation failed while converting the volume.
;
STATUS_FVE_CONV_WRITE_ERROR      EQU 0C021000Eh

;
; MessageId: STATUS_FVE_OVERLAPPED_UPDATE
;
; MessageText:
;
; The control block for the encrypted volume was updated by another thread. Try again.
;
STATUS_FVE_OVERLAPPED_UPDATE     EQU 0C021000Fh

;
; MessageId: STATUS_FVE_FAILED_SECTOR_SIZE
;
; MessageText:
;
; The encryption algorithm does not support the sector size of that volume.
;
STATUS_FVE_FAILED_SECTOR_SIZE    EQU 0C0210010h

;
; MessageId: STATUS_FVE_FAILED_AUTHENTICATION
;
; MessageText:
;
; BitLocker recovery authentication failed.
;
STATUS_FVE_FAILED_AUTHENTICATION EQU 0C0210011h

;
; MessageId: STATUS_FVE_NOT_OS_VOLUME
;
; MessageText:
;
; That volume is not the OS volume.
;
STATUS_FVE_NOT_OS_VOLUME         EQU 0C0210012h

;
; MessageId: STATUS_FVE_KEYFILE_NOT_FOUND
;
; MessageText:
;
; The BitLocker startup key or recovery password could not be read from external media.
;
STATUS_FVE_KEYFILE_NOT_FOUND     EQU 0C0210013h

;
; MessageId: STATUS_FVE_KEYFILE_INVALID
;
; MessageText:
;
; The BitLocker startup key or recovery password file is corrupt or invalid.
;
STATUS_FVE_KEYFILE_INVALID       EQU 0C0210014h

;
; MessageId: STATUS_FVE_KEYFILE_NO_VMK
;
; MessageText:
;
; The BitLocker encryption key could not be obtained from the startup key or recovery password.
;
STATUS_FVE_KEYFILE_NO_VMK        EQU 0C0210015h

;
; MessageId: STATUS_FVE_TPM_DISABLED
;
; MessageText:
;
; The Trusted Platform Module (TPM) is disabled.
;
STATUS_FVE_TPM_DISABLED          EQU 0C0210016h

;
; MessageId: STATUS_FVE_TPM_SRK_AUTH_NOT_ZERO
;
; MessageText:
;
; The authorization data for the Storage Root Key (SRK) of the Trusted Platform Module (TPM) is not zero.
;
STATUS_FVE_TPM_SRK_AUTH_NOT_ZERO EQU 0C0210017h

;
; MessageId: STATUS_FVE_TPM_INVALID_PCR
;
; MessageText:
;
; The system boot information changed or the Trusted Platform Module (TPM) locked out access to BitLocker encryption keys until the computer is restarted.
;
STATUS_FVE_TPM_INVALID_PCR       EQU 0C0210018h

;
; MessageId: STATUS_FVE_TPM_NO_VMK
;
; MessageText:
;
; The BitLocker encryption key could not be obtained from the Trusted Platform Module (TPM).
;
STATUS_FVE_TPM_NO_VMK            EQU 0C0210019h

;
; MessageId: STATUS_FVE_PIN_INVALID
;
; MessageText:
;
; The BitLocker encryption key could not be obtained from the Trusted Platform Module (TPM) and PIN.
;
STATUS_FVE_PIN_INVALID           EQU 0C021001Ah

;
; MessageId: STATUS_FVE_AUTH_INVALID_APPLICATION
;
; MessageText:
;
; A boot application hash does not match the hash computed when BitLocker was turned on.
;
STATUS_FVE_AUTH_INVALID_APPLICATION EQU 0C021001Bh

;
; MessageId: STATUS_FVE_AUTH_INVALID_CONFIG
;
; MessageText:
;
; The Boot Configuration Data (BCD) settings are not supported or have changed since BitLocker was enabled.
;
STATUS_FVE_AUTH_INVALID_CONFIG   EQU 0C021001Ch

;
; MessageId: STATUS_FVE_DEBUGGER_ENABLED
;
; MessageText:
;
; Boot debugging is enabled. Run bcdedit to turn it off.
;
STATUS_FVE_DEBUGGER_ENABLED      EQU 0C021001Dh

;
; MessageId: STATUS_FVE_DRY_RUN_FAILED
;
; MessageText:
;
; The BitLocker encryption key could not be obtained.
;
STATUS_FVE_DRY_RUN_FAILED        EQU 0C021001Eh

;
; MessageId: STATUS_FVE_BAD_METADATA_POINTER
;
; MessageText:
;
; The metadata disk region pointer is incorrect.
;
STATUS_FVE_BAD_METADATA_POINTER  EQU 0C021001Fh

;
; MessageId: STATUS_FVE_OLD_METADATA_COPY
;
; MessageText:
;
; The backup copy of the metadata is out of date.
;
STATUS_FVE_OLD_METADATA_COPY     EQU 0C0210020h

;
; MessageId: STATUS_FVE_REBOOT_REQUIRED
;
; MessageText:
;
; No action was taken as a system reboot is required.
;
STATUS_FVE_REBOOT_REQUIRED       EQU 0C0210021h

;
; MessageId: STATUS_FVE_RAW_ACCESS
;
; MessageText:
;
; No action was taken as BitLocker Drive Encryption is in RAW access mode.
;
STATUS_FVE_RAW_ACCESS            EQU 0C0210022h

;
; MessageId: STATUS_FVE_RAW_BLOCKED
;
; MessageText:
;
; BitLocker Drive Encryption cannot enter raw access mode for this volume.
;
STATUS_FVE_RAW_BLOCKED           EQU 0C0210023h

;
; MessageId: STATUS_FVE_NO_AUTOUNLOCK_MASTER_KEY
;
; MessageText:
;
; The auto-unlock master key was not available from the operating system volume. Retry the operation using the BitLocker WMI interface.
;
STATUS_FVE_NO_AUTOUNLOCK_MASTER_KEY EQU 0C0210024h

;
; MessageId: STATUS_FVE_MOR_FAILED
;
; MessageText:
;
; The system firmware failed to enable clearing of system memory on reboot.
;
STATUS_FVE_MOR_FAILED            EQU 0C0210025h

;
; MessageId: STATUS_FVE_NO_FEATURE_LICENSE
;
; MessageText:
;
; This feature of BitLocker Drive Encryption is not included with this version of Windows.
;
STATUS_FVE_NO_FEATURE_LICENSE    EQU 0C0210026h

;
; MessageId: STATUS_FVE_POLICY_USER_DISABLE_RDV_NOT_ALLOWED
;
; MessageText:
;
; Group policy does not permit turning off BitLocker Drive Encryption on roaming data volumes.
;
STATUS_FVE_POLICY_USER_DISABLE_RDV_NOT_ALLOWED EQU 0C0210027h

;
; MessageId: STATUS_FVE_CONV_RECOVERY_FAILED
;
; MessageText:
;
; Bitlocker Drive Encryption failed to recover from aborted conversion. This could be due to either all conversion logs being corrupted or the media being write-protected.
;
STATUS_FVE_CONV_RECOVERY_FAILED  EQU 0C0210028h

;
; MessageId: STATUS_FVE_VIRTUALIZED_SPACE_TOO_BIG
;
; MessageText:
;
; The requested virtualization size is too big.
;
STATUS_FVE_VIRTUALIZED_SPACE_TOO_BIG EQU 0C0210029h

;
; MessageId: STATUS_FVE_INVALID_DATUM_TYPE
;
; MessageText:
;
; The management information stored on the drive contained an unknown type. If you are using an old version of Windows, try accessing the drive from the latest version.
;
STATUS_FVE_INVALID_DATUM_TYPE    EQU 0C021002Ah

;
; MessageId: STATUS_FVE_VOLUME_TOO_SMALL
;
; MessageText:
;
; The drive is too small to be protected using BitLocker Drive Encryption.
;
STATUS_FVE_VOLUME_TOO_SMALL      EQU 0C0210030h

;
; MessageId: STATUS_FVE_ENH_PIN_INVALID
;
; MessageText:
;
; The BitLocker encryption key could not be obtained from the Trusted Platform Module (TPM) and enhanced PIN. Try using a PIN containing only numerals.
;
STATUS_FVE_ENH_PIN_INVALID       EQU 0C0210031h

;
; MessageId: STATUS_FVE_FULL_ENCRYPTION_NOT_ALLOWED_ON_TP_STORAGE
;
; MessageText:
;
; BitLocker Drive Encryption only supports Used Space Only encryption on thin provisioned storage.
;
STATUS_FVE_FULL_ENCRYPTION_NOT_ALLOWED_ON_TP_STORAGE EQU 0C0210032h

;
; MessageId: STATUS_FVE_WIPE_NOT_ALLOWED_ON_TP_STORAGE
;
; MessageText:
;
; BitLocker Drive Encryption does not support wiping free space on thin provisioned storage.
;
STATUS_FVE_WIPE_NOT_ALLOWED_ON_TP_STORAGE EQU 0C0210033h

;
; MessageId: STATUS_FVE_NOT_ALLOWED_ON_CSV_STACK
;
; MessageText:
;
; This command can only be performed from the coordinator node for the specified CSV volume.
;
STATUS_FVE_NOT_ALLOWED_ON_CSV_STACK EQU 0C0210034h

;
; MessageId: STATUS_FVE_NOT_ALLOWED_ON_CLUSTER
;
; MessageText:
;
; This command cannot be performed on a volume when it is part of a cluster.
;
STATUS_FVE_NOT_ALLOWED_ON_CLUSTER EQU 0C0210035h

;
; MessageId: STATUS_FVE_NOT_ALLOWED_TO_UPGRADE_WHILE_CONVERTING
;
; MessageText:
;
; BitLocker cannot be upgraded during disk encryption or decryption.
;
STATUS_FVE_NOT_ALLOWED_TO_UPGRADE_WHILE_CONVERTING EQU 0C0210036h

;
; MessageId: STATUS_FVE_WIPE_CANCEL_NOT_APPLICABLE
;
; MessageText:
;
; Wipe of free space is not currently taking place.
;
STATUS_FVE_WIPE_CANCEL_NOT_APPLICABLE EQU 0C0210037h

;
; MessageId: STATUS_FVE_EDRIVE_DRY_RUN_FAILED
;
; MessageText:
;
; Your computer doesn't support BitLocker hardware-based encryption. Check with your computer manufacturer for firmware updates.
;
STATUS_FVE_EDRIVE_DRY_RUN_FAILED EQU 0C0210038h

;
; MessageId: STATUS_FVE_SECUREBOOT_DISABLED
;
; MessageText:
;
; Secure Boot has been disabled. Either Secure Boot must be re-enabled, or BitLocker must be suspended for Windows to start normally.
;
STATUS_FVE_SECUREBOOT_DISABLED   EQU 0C0210039h

;
; MessageId: STATUS_FVE_SECUREBOOT_CONFIG_CHANGE
;
; MessageText:
;
; Secure Boot policy has unexpectedly changed.
;
STATUS_FVE_SECUREBOOT_CONFIG_CHANGE EQU 0C021003Ah

;
; MessageId: STATUS_FVE_DEVICE_LOCKEDOUT
;
; MessageText:
;
; Device Lock has been triggered due to too many incorrect password attempts.
;
STATUS_FVE_DEVICE_LOCKEDOUT      EQU 0C021003Bh

;
; MessageId: STATUS_FVE_VOLUME_EXTEND_PREVENTS_EOW_DECRYPT
;
; MessageText:
;
; Device encryption removal is blocked due to volume being extended beyond its original size.
;
STATUS_FVE_VOLUME_EXTEND_PREVENTS_EOW_DECRYPT EQU 0C021003Ch

;
; MessageId: STATUS_FVE_NOT_DE_VOLUME
;
; MessageText:
;
; This action isn't supported because this drive isn't automatically managed with device encryption.
;
STATUS_FVE_NOT_DE_VOLUME         EQU 0C021003Dh

;
; MessageId: STATUS_FVE_PROTECTION_DISABLED
;
; MessageText:
;
; BitLocker Drive Encryption has been suspended on this drive. All BitLocker key protectors configured for this drive are effectively disabled, and the drive will be automatically unlocked using an unencrypted (clear) key.
;
STATUS_FVE_PROTECTION_DISABLED   EQU 0C021003Eh

;
; MessageId: STATUS_FVE_PROTECTION_CANNOT_BE_DISABLED
;
; MessageText:
;
; BitLocker can't be suspended on this drive until the next restart.
;
STATUS_FVE_PROTECTION_CANNOT_BE_DISABLED EQU 0C021003Fh


;
; FWP error codes (fwpkclnt.sys)
;

;
; MessageId: STATUS_FWP_CALLOUT_NOT_FOUND
;
; MessageText:
;
; The callout does not exist.
;
STATUS_FWP_CALLOUT_NOT_FOUND     EQU 0C0220001h

;
; MessageId: STATUS_FWP_CONDITION_NOT_FOUND
;
; MessageText:
;
; The filter condition does not exist.
;
STATUS_FWP_CONDITION_NOT_FOUND   EQU 0C0220002h

;
; MessageId: STATUS_FWP_FILTER_NOT_FOUND
;
; MessageText:
;
; The filter does not exist.
;
STATUS_FWP_FILTER_NOT_FOUND      EQU 0C0220003h

;
; MessageId: STATUS_FWP_LAYER_NOT_FOUND
;
; MessageText:
;
; The layer does not exist.
;
STATUS_FWP_LAYER_NOT_FOUND       EQU 0C0220004h

;
; MessageId: STATUS_FWP_PROVIDER_NOT_FOUND
;
; MessageText:
;
; The provider does not exist.
;
STATUS_FWP_PROVIDER_NOT_FOUND    EQU 0C0220005h

;
; MessageId: STATUS_FWP_PROVIDER_CONTEXT_NOT_FOUND
;
; MessageText:
;
; The provider context does not exist.
;
STATUS_FWP_PROVIDER_CONTEXT_NOT_FOUND EQU 0C0220006h

;
; MessageId: STATUS_FWP_SUBLAYER_NOT_FOUND
;
; MessageText:
;
; The sublayer does not exist.
;
STATUS_FWP_SUBLAYER_NOT_FOUND    EQU 0C0220007h

;
; MessageId: STATUS_FWP_NOT_FOUND
;
; MessageText:
;
; The object does not exist.
;
STATUS_FWP_NOT_FOUND             EQU 0C0220008h

;
; MessageId: STATUS_FWP_ALREADY_EXISTS
;
; MessageText:
;
; An object with that GUID or LUID already exists.
;
STATUS_FWP_ALREADY_EXISTS        EQU 0C0220009h

;
; MessageId: STATUS_FWP_IN_USE
;
; MessageText:
;
; The object is referenced by other objects so cannot be deleted.
;
STATUS_FWP_IN_USE                EQU 0C022000Ah

;
; MessageId: STATUS_FWP_DYNAMIC_SESSION_IN_PROGRESS
;
; MessageText:
;
; The call is not allowed from within a dynamic session.
;
STATUS_FWP_DYNAMIC_SESSION_IN_PROGRESS EQU 0C022000Bh

;
; MessageId: STATUS_FWP_WRONG_SESSION
;
; MessageText:
;
; The call was made from the wrong session so cannot be completed.
;
STATUS_FWP_WRONG_SESSION         EQU 0C022000Ch

;
; MessageId: STATUS_FWP_NO_TXN_IN_PROGRESS
;
; MessageText:
;
; The call must be made from within an explicit transaction.
;
STATUS_FWP_NO_TXN_IN_PROGRESS    EQU 0C022000Dh

;
; MessageId: STATUS_FWP_TXN_IN_PROGRESS
;
; MessageText:
;
; The call is not allowed from within an explicit transaction.
;
STATUS_FWP_TXN_IN_PROGRESS       EQU 0C022000Eh

;
; MessageId: STATUS_FWP_TXN_ABORTED
;
; MessageText:
;
; The explicit transaction has been forcibly cancelled.
;
STATUS_FWP_TXN_ABORTED           EQU 0C022000Fh

;
; MessageId: STATUS_FWP_SESSION_ABORTED
;
; MessageText:
;
; The session has been cancelled.
;
STATUS_FWP_SESSION_ABORTED       EQU 0C0220010h

;
; MessageId: STATUS_FWP_INCOMPATIBLE_TXN
;
; MessageText:
;
; The call is not allowed from within a read-only transaction.
;
STATUS_FWP_INCOMPATIBLE_TXN      EQU 0C0220011h

;
; MessageId: STATUS_FWP_TIMEOUT
;
; MessageText:
;
; The call timed out while waiting to acquire the transaction lock.
;
STATUS_FWP_TIMEOUT               EQU 0C0220012h

;
; MessageId: STATUS_FWP_NET_EVENTS_DISABLED
;
; MessageText:
;
; Collection of network diagnostic events is disabled.
;
STATUS_FWP_NET_EVENTS_DISABLED   EQU 0C0220013h

;
; MessageId: STATUS_FWP_INCOMPATIBLE_LAYER
;
; MessageText:
;
; The operation is not supported by the specified layer.
;
STATUS_FWP_INCOMPATIBLE_LAYER    EQU 0C0220014h

;
; MessageId: STATUS_FWP_KM_CLIENTS_ONLY
;
; MessageText:
;
; The call is allowed for kernel-mode callers only.
;
STATUS_FWP_KM_CLIENTS_ONLY       EQU 0C0220015h

;
; MessageId: STATUS_FWP_LIFETIME_MISMATCH
;
; MessageText:
;
; The call tried to associate two objects with incompatible lifetimes.
;
STATUS_FWP_LIFETIME_MISMATCH     EQU 0C0220016h

;
; MessageId: STATUS_FWP_BUILTIN_OBJECT
;
; MessageText:
;
; The object is built in so cannot be deleted.
;
STATUS_FWP_BUILTIN_OBJECT        EQU 0C0220017h

;
; MessageId: STATUS_FWP_TOO_MANY_CALLOUTS
;
; MessageText:
;
; The maximum number of callouts has been reached.
;
STATUS_FWP_TOO_MANY_CALLOUTS     EQU 0C0220018h

;
; MessageId: STATUS_FWP_NOTIFICATION_DROPPED
;
; MessageText:
;
; A notification could not be delivered because a message queue is at its maximum capacity.
;
STATUS_FWP_NOTIFICATION_DROPPED  EQU 0C0220019h

;
; MessageId: STATUS_FWP_TRAFFIC_MISMATCH
;
; MessageText:
;
; The traffic parameters do not match those for the security association context.
;
STATUS_FWP_TRAFFIC_MISMATCH      EQU 0C022001Ah

;
; MessageId: STATUS_FWP_INCOMPATIBLE_SA_STATE
;
; MessageText:
;
; The call is not allowed for the current security association state.
;
STATUS_FWP_INCOMPATIBLE_SA_STATE EQU 0C022001Bh

;
; MessageId: STATUS_FWP_NULL_POINTER
;
; MessageText:
;
; A required pointer is null.
;
STATUS_FWP_NULL_POINTER          EQU 0C022001Ch

;
; MessageId: STATUS_FWP_INVALID_ENUMERATOR
;
; MessageText:
;
; An enumerator is not valid.
;
STATUS_FWP_INVALID_ENUMERATOR    EQU 0C022001Dh

;
; MessageId: STATUS_FWP_INVALID_FLAGS
;
; MessageText:
;
; The flags field contains an invalid value.
;
STATUS_FWP_INVALID_FLAGS         EQU 0C022001Eh

;
; MessageId: STATUS_FWP_INVALID_NET_MASK
;
; MessageText:
;
; A network mask is not valid.
;
STATUS_FWP_INVALID_NET_MASK      EQU 0C022001Fh

;
; MessageId: STATUS_FWP_INVALID_RANGE
;
; MessageText:
;
; An FWP_RANGE is not valid.
;
STATUS_FWP_INVALID_RANGE         EQU 0C0220020h

;
; MessageId: STATUS_FWP_INVALID_INTERVAL
;
; MessageText:
;
; The time interval is not valid.
;
STATUS_FWP_INVALID_INTERVAL      EQU 0C0220021h

;
; MessageId: STATUS_FWP_ZERO_LENGTH_ARRAY
;
; MessageText:
;
; An array that must contain at least one element is zero length.
;
STATUS_FWP_ZERO_LENGTH_ARRAY     EQU 0C0220022h

;
; MessageId: STATUS_FWP_NULL_DISPLAY_NAME
;
; MessageText:
;
; The displayData.name field cannot be null.
;
STATUS_FWP_NULL_DISPLAY_NAME     EQU 0C0220023h

;
; MessageId: STATUS_FWP_INVALID_ACTION_TYPE
;
; MessageText:
;
; The action type is not one of the allowed action types for a filter.
;
STATUS_FWP_INVALID_ACTION_TYPE   EQU 0C0220024h

;
; MessageId: STATUS_FWP_INVALID_WEIGHT
;
; MessageText:
;
; The filter weight is not valid.
;
STATUS_FWP_INVALID_WEIGHT        EQU 0C0220025h

;
; MessageId: STATUS_FWP_MATCH_TYPE_MISMATCH
;
; MessageText:
;
; A filter condition contains a match type that is not compatible with the operands.
;
STATUS_FWP_MATCH_TYPE_MISMATCH   EQU 0C0220026h

;
; MessageId: STATUS_FWP_TYPE_MISMATCH
;
; MessageText:
;
; An FWP_VALUE or FWPM_CONDITION_VALUE is of the wrong type.
;
STATUS_FWP_TYPE_MISMATCH         EQU 0C0220027h

;
; MessageId: STATUS_FWP_OUT_OF_BOUNDS
;
; MessageText:
;
; An integer value is outside the allowed range.
;
STATUS_FWP_OUT_OF_BOUNDS         EQU 0C0220028h

;
; MessageId: STATUS_FWP_RESERVED
;
; MessageText:
;
; A reserved field is non-zero.
;
STATUS_FWP_RESERVED              EQU 0C0220029h

;
; MessageId: STATUS_FWP_DUPLICATE_CONDITION
;
; MessageText:
;
; A filter cannot contain multiple conditions operating on a single field.
;
STATUS_FWP_DUPLICATE_CONDITION   EQU 0C022002Ah

;
; MessageId: STATUS_FWP_DUPLICATE_KEYMOD
;
; MessageText:
;
; A policy cannot contain the same keying module more than once.
;
STATUS_FWP_DUPLICATE_KEYMOD      EQU 0C022002Bh

;
; MessageId: STATUS_FWP_ACTION_INCOMPATIBLE_WITH_LAYER
;
; MessageText:
;
; The action type is not compatible with the layer.
;
STATUS_FWP_ACTION_INCOMPATIBLE_WITH_LAYER EQU 0C022002Ch

;
; MessageId: STATUS_FWP_ACTION_INCOMPATIBLE_WITH_SUBLAYER
;
; MessageText:
;
; The action type is not compatible with the sublayer.
;
STATUS_FWP_ACTION_INCOMPATIBLE_WITH_SUBLAYER EQU 0C022002Dh

;
; MessageId: STATUS_FWP_CONTEXT_INCOMPATIBLE_WITH_LAYER
;
; MessageText:
;
; The raw context or the provider context is not compatible with the layer.
;
STATUS_FWP_CONTEXT_INCOMPATIBLE_WITH_LAYER EQU 0C022002Eh

;
; MessageId: STATUS_FWP_CONTEXT_INCOMPATIBLE_WITH_CALLOUT
;
; MessageText:
;
; The raw context or the provider context is not compatible with the callout.
;
STATUS_FWP_CONTEXT_INCOMPATIBLE_WITH_CALLOUT EQU 0C022002Fh

;
; MessageId: STATUS_FWP_INCOMPATIBLE_AUTH_METHOD
;
; MessageText:
;
; The authentication method is not compatible with the policy type.
;
STATUS_FWP_INCOMPATIBLE_AUTH_METHOD EQU 0C0220030h

;
; MessageId: STATUS_FWP_INCOMPATIBLE_DH_GROUP
;
; MessageText:
;
; The Diffie-Hellman group is not compatible with the policy type.
;
STATUS_FWP_INCOMPATIBLE_DH_GROUP EQU 0C0220031h

;
; MessageId: STATUS_FWP_EM_NOT_SUPPORTED
;
; MessageText:
;
; An IKE policy cannot contain an Extended Mode policy.
;
STATUS_FWP_EM_NOT_SUPPORTED      EQU 0C0220032h

;
; MessageId: STATUS_FWP_NEVER_MATCH
;
; MessageText:
;
; The enumeration template or subscription will never match any objects.
;
STATUS_FWP_NEVER_MATCH           EQU 0C0220033h

;
; MessageId: STATUS_FWP_PROVIDER_CONTEXT_MISMATCH
;
; MessageText:
;
; The provider context is of the wrong type.
;
STATUS_FWP_PROVIDER_CONTEXT_MISMATCH EQU 0C0220034h

;
; MessageId: STATUS_FWP_INVALID_PARAMETER
;
; MessageText:
;
; The parameter is incorrect.
;
STATUS_FWP_INVALID_PARAMETER     EQU 0C0220035h

;
; MessageId: STATUS_FWP_TOO_MANY_SUBLAYERS
;
; MessageText:
;
; The maximum number of sublayers has been reached.
;
STATUS_FWP_TOO_MANY_SUBLAYERS    EQU 0C0220036h

;
; MessageId: STATUS_FWP_CALLOUT_NOTIFICATION_FAILED
;
; MessageText:
;
; The notification function for a callout returned an error.
;
STATUS_FWP_CALLOUT_NOTIFICATION_FAILED EQU 0C0220037h

;
; MessageId: STATUS_FWP_INVALID_AUTH_TRANSFORM
;
; MessageText:
;
; The IPsec authentication transform is not valid.
;
STATUS_FWP_INVALID_AUTH_TRANSFORM EQU 0C0220038h

;
; MessageId: STATUS_FWP_INVALID_CIPHER_TRANSFORM
;
; MessageText:
;
; The IPsec cipher transform is not valid.
;
STATUS_FWP_INVALID_CIPHER_TRANSFORM EQU 0C0220039h

;
; MessageId: STATUS_FWP_INCOMPATIBLE_CIPHER_TRANSFORM
;
; MessageText:
;
; The IPsec cipher transform is not compatible with the policy.
;
STATUS_FWP_INCOMPATIBLE_CIPHER_TRANSFORM EQU 0C022003Ah

;
; MessageId: STATUS_FWP_INVALID_TRANSFORM_COMBINATION
;
; MessageText:
;
; The combination of IPsec transform types is not valid.
;
STATUS_FWP_INVALID_TRANSFORM_COMBINATION EQU 0C022003Bh

;
; MessageId: STATUS_FWP_DUPLICATE_AUTH_METHOD
;
; MessageText:
;
; A policy cannot contain the same auth method more than once.
;
STATUS_FWP_DUPLICATE_AUTH_METHOD EQU 0C022003Ch

;
; MessageId: STATUS_FWP_INVALID_TUNNEL_ENDPOINT
;
; MessageText:
;
; A tunnel endpoint configuration is invalid.
;
STATUS_FWP_INVALID_TUNNEL_ENDPOINT EQU 0C022003Dh

;
; MessageId: STATUS_FWP_L2_DRIVER_NOT_READY
;
; MessageText:
;
; The WFP MAC Layers are not ready.
;
STATUS_FWP_L2_DRIVER_NOT_READY   EQU 0C022003Eh

;
; MessageId: STATUS_FWP_KEY_DICTATOR_ALREADY_REGISTERED
;
; MessageText:
;
; A key manager capable of key dictation is already registered
;
STATUS_FWP_KEY_DICTATOR_ALREADY_REGISTERED EQU 0C022003Fh

;
; MessageId: STATUS_FWP_KEY_DICTATION_INVALID_KEYING_MATERIAL
;
; MessageText:
;
; A key manager dictated invalid keys
;
STATUS_FWP_KEY_DICTATION_INVALID_KEYING_MATERIAL EQU 0C0220040h

;
; MessageId: STATUS_FWP_CONNECTIONS_DISABLED
;
; MessageText:
;
; The BFE IPsec Connection Tracking is disabled.
;
STATUS_FWP_CONNECTIONS_DISABLED  EQU 0C0220041h

;
; MessageId: STATUS_FWP_INVALID_DNS_NAME
;
; MessageText:
;
; The DNS name is invalid.
;
STATUS_FWP_INVALID_DNS_NAME      EQU 0C0220042h

;
; MessageId: STATUS_FWP_STILL_ON
;
; MessageText:
;
; The engine option is still enabled due to other configuration settings.
;
STATUS_FWP_STILL_ON              EQU 0C0220043h

;
; MessageId: STATUS_FWP_IKEEXT_NOT_RUNNING
;
; MessageText:
;
; The IKEEXT service is not running.  This service only runs when there is IPsec policy applied to the machine.
;
STATUS_FWP_IKEEXT_NOT_RUNNING    EQU 0C0220044h

;
; MessageId: STATUS_FWP_TCPIP_NOT_READY
;
; MessageText:
;
; The TCP/IP stack is not ready.
;
STATUS_FWP_TCPIP_NOT_READY       EQU 0C0220100h

;
; MessageId: STATUS_FWP_INJECT_HANDLE_CLOSING
;
; MessageText:
;
; The injection handle is being closed by another thread.
;
STATUS_FWP_INJECT_HANDLE_CLOSING EQU 0C0220101h

;
; MessageId: STATUS_FWP_INJECT_HANDLE_STALE
;
; MessageText:
;
; The injection handle is stale.
;
STATUS_FWP_INJECT_HANDLE_STALE   EQU 0C0220102h

;
; MessageId: STATUS_FWP_CANNOT_PEND
;
; MessageText:
;
; The classify cannot be pended.
;
STATUS_FWP_CANNOT_PEND           EQU 0C0220103h

;
; MessageId: STATUS_FWP_DROP_NOICMP
;
; MessageText:
;
; The packet should be dropped, no ICMP should be sent.
;
STATUS_FWP_DROP_NOICMP           EQU 0C0220104h


;
; NDIS error codes (ndis.sys)
;

;
; MessageId: STATUS_NDIS_CLOSING
;
; MessageText:
;
; The binding to the network interface is being closed.
;
STATUS_NDIS_CLOSING              EQU 0C0230002h

;
; MessageId: STATUS_NDIS_BAD_VERSION
;
; MessageText:
;
; An invalid version was specified.
;
STATUS_NDIS_BAD_VERSION          EQU 0C0230004h

;
; MessageId: STATUS_NDIS_BAD_CHARACTERISTICS
;
; MessageText:
;
; An invalid characteristics table was used.
;
STATUS_NDIS_BAD_CHARACTERISTICS  EQU 0C0230005h

;
; MessageId: STATUS_NDIS_ADAPTER_NOT_FOUND
;
; MessageText:
;
; Failed to find the network interface or network interface is not ready.
;
STATUS_NDIS_ADAPTER_NOT_FOUND    EQU 0C0230006h

;
; MessageId: STATUS_NDIS_OPEN_FAILED
;
; MessageText:
;
; Failed to open the network interface.
;
STATUS_NDIS_OPEN_FAILED          EQU 0C0230007h

;
; MessageId: STATUS_NDIS_DEVICE_FAILED
;
; MessageText:
;
; Network interface has encountered an internal unrecoverable failure.
;
STATUS_NDIS_DEVICE_FAILED        EQU 0C0230008h

;
; MessageId: STATUS_NDIS_MULTICAST_FULL
;
; MessageText:
;
; The multicast list on the network interface is full.
;
STATUS_NDIS_MULTICAST_FULL       EQU 0C0230009h

;
; MessageId: STATUS_NDIS_MULTICAST_EXISTS
;
; MessageText:
;
; An attempt was made to add a duplicate multicast address to the list.
;
STATUS_NDIS_MULTICAST_EXISTS     EQU 0C023000Ah

;
; MessageId: STATUS_NDIS_MULTICAST_NOT_FOUND
;
; MessageText:
;
; At attempt was made to remove a multicast address that was never added.
;
STATUS_NDIS_MULTICAST_NOT_FOUND  EQU 0C023000Bh

;
; MessageId: STATUS_NDIS_REQUEST_ABORTED
;
; MessageText:
;
; Netowork interface aborted the request.
;
STATUS_NDIS_REQUEST_ABORTED      EQU 0C023000Ch

;
; MessageId: STATUS_NDIS_RESET_IN_PROGRESS
;
; MessageText:
;
; Network interface can not process the request because it is being reset.
;
STATUS_NDIS_RESET_IN_PROGRESS    EQU 0C023000Dh

;
; MessageId: STATUS_NDIS_NOT_SUPPORTED
;
; MessageText:
;
; Netword interface does not support this request.
;
STATUS_NDIS_NOT_SUPPORTED        EQU 0C02300BBh

;
; MessageId: STATUS_NDIS_INVALID_PACKET
;
; MessageText:
;
; An attempt was made to send an invalid packet on a network interface.
;
STATUS_NDIS_INVALID_PACKET       EQU 0C023000Fh

;
; MessageId: STATUS_NDIS_ADAPTER_NOT_READY
;
; MessageText:
;
; Network interface is not ready to complete this operation.
;
STATUS_NDIS_ADAPTER_NOT_READY    EQU 0C0230011h

;
; MessageId: STATUS_NDIS_INVALID_LENGTH
;
; MessageText:
;
; The length of the buffer submitted for this operation is not valid.
;
STATUS_NDIS_INVALID_LENGTH       EQU 0C0230014h

;
; MessageId: STATUS_NDIS_INVALID_DATA
;
; MessageText:
;
; The data used for this operation is not valid.
;
STATUS_NDIS_INVALID_DATA         EQU 0C0230015h

;
; MessageId: STATUS_NDIS_BUFFER_TOO_SHORT
;
; MessageText:
;
; The length of buffer submitted for this operation is too small.
;
STATUS_NDIS_BUFFER_TOO_SHORT     EQU 0C0230016h

;
; MessageId: STATUS_NDIS_INVALID_OID
;
; MessageText:
;
; Network interface does not support this OID (Object Identifier)
;
STATUS_NDIS_INVALID_OID          EQU 0C0230017h

;
; MessageId: STATUS_NDIS_ADAPTER_REMOVED
;
; MessageText:
;
; The network interface has been removed.
;
STATUS_NDIS_ADAPTER_REMOVED      EQU 0C0230018h

;
; MessageId: STATUS_NDIS_UNSUPPORTED_MEDIA
;
; MessageText:
;
; Network interface does not support this media type.
;
STATUS_NDIS_UNSUPPORTED_MEDIA    EQU 0C0230019h

;
; MessageId: STATUS_NDIS_GROUP_ADDRESS_IN_USE
;
; MessageText:
;
; An attempt was made to remove a token ring group address that is in use by other components.
;
STATUS_NDIS_GROUP_ADDRESS_IN_USE EQU 0C023001Ah

;
; MessageId: STATUS_NDIS_FILE_NOT_FOUND
;
; MessageText:
;
; An attempt was made to map a file that can not be found.
;
STATUS_NDIS_FILE_NOT_FOUND       EQU 0C023001Bh

;
; MessageId: STATUS_NDIS_ERROR_READING_FILE
;
; MessageText:
;
; An error occurred while NDIS tried to map the file.
;
STATUS_NDIS_ERROR_READING_FILE   EQU 0C023001Ch

;
; MessageId: STATUS_NDIS_ALREADY_MAPPED
;
; MessageText:
;
; An attempt was made to map a file that is alreay mapped.
;
STATUS_NDIS_ALREADY_MAPPED       EQU 0C023001Dh

;
; MessageId: STATUS_NDIS_RESOURCE_CONFLICT
;
; MessageText:
;
; An attempt to allocate a hardware resource failed because the resource is used by another component.
;
STATUS_NDIS_RESOURCE_CONFLICT    EQU 0C023001Eh

;
; MessageId: STATUS_NDIS_MEDIA_DISCONNECTED
;
; MessageText:
;
; The I/O operation failed because network media is disconnected or wireless access point is out of range.
;
STATUS_NDIS_MEDIA_DISCONNECTED   EQU 0C023001Fh

;
; MessageId: STATUS_NDIS_INVALID_ADDRESS
;
; MessageText:
;
; The network address used in the request is invalid.
;
STATUS_NDIS_INVALID_ADDRESS      EQU 0C0230022h

;
; MessageId: STATUS_NDIS_INVALID_DEVICE_REQUEST
;
; MessageText:
;
; The specified request is not a valid operation for the target device.
;
STATUS_NDIS_INVALID_DEVICE_REQUEST EQU 0C0230010h

;
; MessageId: STATUS_NDIS_PAUSED
;
; MessageText:
;
; The offload operation on the network interface has been paused.
;
STATUS_NDIS_PAUSED               EQU 0C023002Ah

;
; MessageId: STATUS_NDIS_INTERFACE_NOT_FOUND
;
; MessageText:
;
; Network interface was not found.
;
STATUS_NDIS_INTERFACE_NOT_FOUND  EQU 0C023002Bh

;
; MessageId: STATUS_NDIS_UNSUPPORTED_REVISION
;
; MessageText:
;
; The revision number specified in the structure is not supported.
;
STATUS_NDIS_UNSUPPORTED_REVISION EQU 0C023002Ch

;
; MessageId: STATUS_NDIS_INVALID_PORT
;
; MessageText:
;
; The specified port does not exist on this network interface.
;
STATUS_NDIS_INVALID_PORT         EQU 0C023002Dh

;
; MessageId: STATUS_NDIS_INVALID_PORT_STATE
;
; MessageText:
;
; The current state of the specified port on this network interface does not support the requested operation.
;
STATUS_NDIS_INVALID_PORT_STATE   EQU 0C023002Eh

;
; MessageId: STATUS_NDIS_LOW_POWER_STATE
;
; MessageText:
;
; The miniport adapter is in lower power state.
;
STATUS_NDIS_LOW_POWER_STATE      EQU 0C023002Fh

;
; MessageId: STATUS_NDIS_REINIT_REQUIRED
;
; MessageText:
;
; This operation requires the miniport adapter to be reinitialized.
;
STATUS_NDIS_REINIT_REQUIRED      EQU 0C0230030h


;
; NDIS error codes (802.11 wireless LAN)
;

;
; MessageId: STATUS_NDIS_DOT11_AUTO_CONFIG_ENABLED
;
; MessageText:
;
; The wireless local area network interface is in auto configuration mode and doesn't support the requested parameter change operation.
;
STATUS_NDIS_DOT11_AUTO_CONFIG_ENABLED EQU 0C0232000h

;
; MessageId: STATUS_NDIS_DOT11_MEDIA_IN_USE
;
; MessageText:
;
; The wireless local area network interface is busy and can not perform the requested operation.
;
STATUS_NDIS_DOT11_MEDIA_IN_USE   EQU 0C0232001h

;
; MessageId: STATUS_NDIS_DOT11_POWER_STATE_INVALID
;
; MessageText:
;
; The wireless local area network interface is powered down and doesn't support the requested operation.
;
STATUS_NDIS_DOT11_POWER_STATE_INVALID EQU 0C0232002h

;
; MessageId: STATUS_NDIS_PM_WOL_PATTERN_LIST_FULL
;
; MessageText:
;
; The list of wake on LAN patterns is full.
;
STATUS_NDIS_PM_WOL_PATTERN_LIST_FULL EQU 0C0232003h

;
; MessageId: STATUS_NDIS_PM_PROTOCOL_OFFLOAD_LIST_FULL
;
; MessageText:
;
; The list of low power protocol offloads is full.
;
STATUS_NDIS_PM_PROTOCOL_OFFLOAD_LIST_FULL EQU 0C0232004h

;
; NDIS informational codes(ndis.sys)
;

;
; MessageId: STATUS_NDIS_INDICATION_REQUIRED
;
; MessageText:
;
; The request will be completed later by NDIS status indication.
;
STATUS_NDIS_INDICATION_REQUIRED  EQU 040230001h

;
; NDIS Chimney Offload codes (ndis.sys)
;

;
; MessageId: STATUS_NDIS_OFFLOAD_POLICY
;
; MessageText:
;
; The TCP connection is not offloadable because of a local policy setting.
;
STATUS_NDIS_OFFLOAD_POLICY       EQU 0C023100Fh

;
; MessageId: STATUS_NDIS_OFFLOAD_CONNECTION_REJECTED
;
; MessageText:
;
; The TCP connection is not offloadable by the Chimney offload target.
;
STATUS_NDIS_OFFLOAD_CONNECTION_REJECTED EQU 0C0231012h

;
; MessageId: STATUS_NDIS_OFFLOAD_PATH_REJECTED
;
; MessageText:
;
; The IP Path object is not in an offloadable state.
;
STATUS_NDIS_OFFLOAD_PATH_REJECTED EQU 0C0231013h

;
; TPM hardware errors {0x0000..0x003ff}
;
;
; MessageId: STATUS_TPM_ERROR_MASK
;
; MessageText:
;
; This is an error mask to convert TPM hardware errors to win errors.
;
STATUS_TPM_ERROR_MASK            EQU 0C0290000h

;
; MessageId: STATUS_TPM_AUTHFAIL
;
; MessageText:
;
; Authentication failed.
;
STATUS_TPM_AUTHFAIL              EQU 0C0290001h

;
; MessageId: STATUS_TPM_BADINDEX
;
; MessageText:
;
; The index to a PCR, DIR or other register is incorrect.
;
STATUS_TPM_BADINDEX              EQU 0C0290002h

;
; MessageId: STATUS_TPM_BAD_PARAMETER
;
; MessageText:
;
; One or more parameter is bad.
;
STATUS_TPM_BAD_PARAMETER         EQU 0C0290003h

;
; MessageId: STATUS_TPM_AUDITFAILURE
;
; MessageText:
;
; An operation completed successfully but the auditing of that operation failed.
;
STATUS_TPM_AUDITFAILURE          EQU 0C0290004h

;
; MessageId: STATUS_TPM_CLEAR_DISABLED
;
; MessageText:
;
; The clear disable flag is set and all clear operations now require physical access.
;
STATUS_TPM_CLEAR_DISABLED        EQU 0C0290005h

;
; MessageId: STATUS_TPM_DEACTIVATED
;
; MessageText:
;
; Activate the Trusted Platform Module (TPM).
;
STATUS_TPM_DEACTIVATED           EQU 0C0290006h

;
; MessageId: STATUS_TPM_DISABLED
;
; MessageText:
;
; Enable the Trusted Platform Module (TPM).
;
STATUS_TPM_DISABLED              EQU 0C0290007h

;
; MessageId: STATUS_TPM_DISABLED_CMD
;
; MessageText:
;
; The target command has been disabled.
;
STATUS_TPM_DISABLED_CMD          EQU 0C0290008h

;
; MessageId: STATUS_TPM_FAIL
;
; MessageText:
;
; The operation failed.
;
STATUS_TPM_FAIL                  EQU 0C0290009h

;
; MessageId: STATUS_TPM_BAD_ORDINAL
;
; MessageText:
;
; The ordinal was unknown or inconsistent.
;
STATUS_TPM_BAD_ORDINAL           EQU 0C029000Ah

;
; MessageId: STATUS_TPM_INSTALL_DISABLED
;
; MessageText:
;
; The ability to install an owner is disabled.
;
STATUS_TPM_INSTALL_DISABLED      EQU 0C029000Bh

;
; MessageId: STATUS_TPM_INVALID_KEYHANDLE
;
; MessageText:
;
; The key handle cannot be interpreted.
;
STATUS_TPM_INVALID_KEYHANDLE     EQU 0C029000Ch

;
; MessageId: STATUS_TPM_KEYNOTFOUND
;
; MessageText:
;
; The key handle points to an invalid key.
;
STATUS_TPM_KEYNOTFOUND           EQU 0C029000Dh

;
; MessageId: STATUS_TPM_INAPPROPRIATE_ENC
;
; MessageText:
;
; Unacceptable encryption scheme.
;
STATUS_TPM_INAPPROPRIATE_ENC     EQU 0C029000Eh

;
; MessageId: STATUS_TPM_MIGRATEFAIL
;
; MessageText:
;
; Migration authorization failed.
;
STATUS_TPM_MIGRATEFAIL           EQU 0C029000Fh

;
; MessageId: STATUS_TPM_INVALID_PCR_INFO
;
; MessageText:
;
; PCR information could not be interpreted.
;
STATUS_TPM_INVALID_PCR_INFO      EQU 0C0290010h

;
; MessageId: STATUS_TPM_NOSPACE
;
; MessageText:
;
; No room to load key.
;
STATUS_TPM_NOSPACE               EQU 0C0290011h

;
; MessageId: STATUS_TPM_NOSRK
;
; MessageText:
;
; There is no Storage Root Key (SRK) set.
;
STATUS_TPM_NOSRK                 EQU 0C0290012h

;
; MessageId: STATUS_TPM_NOTSEALED_BLOB
;
; MessageText:
;
; An encrypted blob is invalid or was not created by this TPM.
;
STATUS_TPM_NOTSEALED_BLOB        EQU 0C0290013h

;
; MessageId: STATUS_TPM_OWNER_SET
;
; MessageText:
;
; The Trusted Platform Module (TPM) already has an owner.
;
STATUS_TPM_OWNER_SET             EQU 0C0290014h

;
; MessageId: STATUS_TPM_RESOURCES
;
; MessageText:
;
; The TPM has insufficient internal resources to perform the requested action.
;
STATUS_TPM_RESOURCES             EQU 0C0290015h

;
; MessageId: STATUS_TPM_SHORTRANDOM
;
; MessageText:
;
; A random string was too short.
;
STATUS_TPM_SHORTRANDOM           EQU 0C0290016h

;
; MessageId: STATUS_TPM_SIZE
;
; MessageText:
;
; The TPM does not have the space to perform the operation.
;
STATUS_TPM_SIZE                  EQU 0C0290017h

;
; MessageId: STATUS_TPM_WRONGPCRVAL
;
; MessageText:
;
; The named PCR value does not match the current PCR value.
;
STATUS_TPM_WRONGPCRVAL           EQU 0C0290018h

;
; MessageId: STATUS_TPM_BAD_PARAM_SIZE
;
; MessageText:
;
; The paramSize argument to the command has the incorrect value .
;
STATUS_TPM_BAD_PARAM_SIZE        EQU 0C0290019h

;
; MessageId: STATUS_TPM_SHA_THREAD
;
; MessageText:
;
; There is no existing SHA-1 thread.
;
STATUS_TPM_SHA_THREAD            EQU 0C029001Ah

;
; MessageId: STATUS_TPM_SHA_ERROR
;
; MessageText:
;
; The calculation is unable to proceed because the existing SHA-1 thread has already encountered an error.
;
STATUS_TPM_SHA_ERROR             EQU 0C029001Bh

;
; MessageId: STATUS_TPM_FAILEDSELFTEST
;
; MessageText:
;
; The TPM hardware device reported a failure during its internal self test. Try restarting the computer to resolve the problem. If the problem continues, you might need to replace your TPM hardware or motherboard.
;
STATUS_TPM_FAILEDSELFTEST        EQU 0C029001Ch

;
; MessageId: STATUS_TPM_AUTH2FAIL
;
; MessageText:
;
; The authorization for the second key in a 2 key function failed authorization.
;
STATUS_TPM_AUTH2FAIL             EQU 0C029001Dh

;
; MessageId: STATUS_TPM_BADTAG
;
; MessageText:
;
; The tag value sent to for a command is invalid.
;
STATUS_TPM_BADTAG                EQU 0C029001Eh

;
; MessageId: STATUS_TPM_IOERROR
;
; MessageText:
;
; An IO error occurred transmitting information to the TPM.
;
STATUS_TPM_IOERROR               EQU 0C029001Fh

;
; MessageId: STATUS_TPM_ENCRYPT_ERROR
;
; MessageText:
;
; The encryption process had a problem.
;
STATUS_TPM_ENCRYPT_ERROR         EQU 0C0290020h

;
; MessageId: STATUS_TPM_DECRYPT_ERROR
;
; MessageText:
;
; The decryption process did not complete.
;
STATUS_TPM_DECRYPT_ERROR         EQU 0C0290021h

;
; MessageId: STATUS_TPM_INVALID_AUTHHANDLE
;
; MessageText:
;
; An invalid handle was used.
;
STATUS_TPM_INVALID_AUTHHANDLE    EQU 0C0290022h

;
; MessageId: STATUS_TPM_NO_ENDORSEMENT
;
; MessageText:
;
; The TPM does not have an Endorsement Key (EK) installed.
;
STATUS_TPM_NO_ENDORSEMENT        EQU 0C0290023h

;
; MessageId: STATUS_TPM_INVALID_KEYUSAGE
;
; MessageText:
;
; The usage of a key is not allowed.
;
STATUS_TPM_INVALID_KEYUSAGE      EQU 0C0290024h

;
; MessageId: STATUS_TPM_WRONG_ENTITYTYPE
;
; MessageText:
;
; The submitted entity type is not allowed.
;
STATUS_TPM_WRONG_ENTITYTYPE      EQU 0C0290025h

;
; MessageId: STATUS_TPM_INVALID_POSTINIT
;
; MessageText:
;
; The command was received in the wrong sequence relative to TPM_Init and a subsequent TPM_Startup.
;
STATUS_TPM_INVALID_POSTINIT      EQU 0C0290026h

;
; MessageId: STATUS_TPM_INAPPROPRIATE_SIG
;
; MessageText:
;
; Signed data cannot include additional DER information.
;
STATUS_TPM_INAPPROPRIATE_SIG     EQU 0C0290027h

;
; MessageId: STATUS_TPM_BAD_KEY_PROPERTY
;
; MessageText:
;
; The key properties in TPM_KEY_PARMs are not supported by this TPM.
;
STATUS_TPM_BAD_KEY_PROPERTY      EQU 0C0290028h

;
; MessageId: STATUS_TPM_BAD_MIGRATION
;
; MessageText:
;
; The migration properties of this key are incorrect.
;
STATUS_TPM_BAD_MIGRATION         EQU 0C0290029h

;
; MessageId: STATUS_TPM_BAD_SCHEME
;
; MessageText:
;
; The signature or encryption scheme for this key is incorrect or not permitted in this situation.
;
STATUS_TPM_BAD_SCHEME            EQU 0C029002Ah

;
; MessageId: STATUS_TPM_BAD_DATASIZE
;
; MessageText:
;
; The size of the data (or blob) parameter is bad or inconsistent with the referenced key.
;
STATUS_TPM_BAD_DATASIZE          EQU 0C029002Bh

;
; MessageId: STATUS_TPM_BAD_MODE
;
; MessageText:
;
; A mode parameter is bad, such as capArea or subCapArea for TPM_GetCapability, phsicalPresence parameter for TPM_PhysicalPresence, or migrationType for TPM_CreateMigrationBlob.
;
STATUS_TPM_BAD_MODE              EQU 0C029002Ch

;
; MessageId: STATUS_TPM_BAD_PRESENCE
;
; MessageText:
;
; Either the physicalPresence or physicalPresenceLock bits have the wrong value.
;
STATUS_TPM_BAD_PRESENCE          EQU 0C029002Dh

;
; MessageId: STATUS_TPM_BAD_VERSION
;
; MessageText:
;
; The TPM cannot perform this version of the capability.
;
STATUS_TPM_BAD_VERSION           EQU 0C029002Eh

;
; MessageId: STATUS_TPM_NO_WRAP_TRANSPORT
;
; MessageText:
;
; The TPM does not allow for wrapped transport sessions.
;
STATUS_TPM_NO_WRAP_TRANSPORT     EQU 0C029002Fh

;
; MessageId: STATUS_TPM_AUDITFAIL_UNSUCCESSFUL
;
; MessageText:
;
; TPM audit construction failed and the underlying command was returning a failure code also.
;
STATUS_TPM_AUDITFAIL_UNSUCCESSFUL EQU 0C0290030h

;
; MessageId: STATUS_TPM_AUDITFAIL_SUCCESSFUL
;
; MessageText:
;
; TPM audit construction failed and the underlying command was returning success.
;
STATUS_TPM_AUDITFAIL_SUCCESSFUL  EQU 0C0290031h

;
; MessageId: STATUS_TPM_NOTRESETABLE
;
; MessageText:
;
; Attempt to reset a PCR register that does not have the resettable attribute.
;
STATUS_TPM_NOTRESETABLE          EQU 0C0290032h

;
; MessageId: STATUS_TPM_NOTLOCAL
;
; MessageText:
;
; Attempt to reset a PCR register that requires locality and locality modifier not part of command transport.
;
STATUS_TPM_NOTLOCAL              EQU 0C0290033h

;
; MessageId: STATUS_TPM_BAD_TYPE
;
; MessageText:
;
; Make identity blob not properly typed.
;
STATUS_TPM_BAD_TYPE              EQU 0C0290034h

;
; MessageId: STATUS_TPM_INVALID_RESOURCE
;
; MessageText:
;
; When saving context identified resource type does not match actual resource.
;
STATUS_TPM_INVALID_RESOURCE      EQU 0C0290035h

;
; MessageId: STATUS_TPM_NOTFIPS
;
; MessageText:
;
; The TPM is attempting to execute a command only available when in FIPS mode.
;
STATUS_TPM_NOTFIPS               EQU 0C0290036h

;
; MessageId: STATUS_TPM_INVALID_FAMILY
;
; MessageText:
;
; The command is attempting to use an invalid family ID.
;
STATUS_TPM_INVALID_FAMILY        EQU 0C0290037h

;
; MessageId: STATUS_TPM_NO_NV_PERMISSION
;
; MessageText:
;
; The permission to manipulate the NV storage is not available.
;
STATUS_TPM_NO_NV_PERMISSION      EQU 0C0290038h

;
; MessageId: STATUS_TPM_REQUIRES_SIGN
;
; MessageText:
;
; The operation requires a signed command.
;
STATUS_TPM_REQUIRES_SIGN         EQU 0C0290039h

;
; MessageId: STATUS_TPM_KEY_NOTSUPPORTED
;
; MessageText:
;
; Wrong operation to load an NV key.
;
STATUS_TPM_KEY_NOTSUPPORTED      EQU 0C029003Ah

;
; MessageId: STATUS_TPM_AUTH_CONFLICT
;
; MessageText:
;
; NV_LoadKey blob requires both owner and blob authorization.
;
STATUS_TPM_AUTH_CONFLICT         EQU 0C029003Bh

;
; MessageId: STATUS_TPM_AREA_LOCKED
;
; MessageText:
;
; The NV area is locked and not writtable.
;
STATUS_TPM_AREA_LOCKED           EQU 0C029003Ch

;
; MessageId: STATUS_TPM_BAD_LOCALITY
;
; MessageText:
;
; The locality is incorrect for the attempted operation.
;
STATUS_TPM_BAD_LOCALITY          EQU 0C029003Dh

;
; MessageId: STATUS_TPM_READ_ONLY
;
; MessageText:
;
; The NV area is read only and can't be written to.
;
STATUS_TPM_READ_ONLY             EQU 0C029003Eh

;
; MessageId: STATUS_TPM_PER_NOWRITE
;
; MessageText:
;
; There is no protection on the write to the NV area.
;
STATUS_TPM_PER_NOWRITE           EQU 0C029003Fh

;
; MessageId: STATUS_TPM_FAMILYCOUNT
;
; MessageText:
;
; The family count value does not match.
;
STATUS_TPM_FAMILYCOUNT           EQU 0C0290040h

;
; MessageId: STATUS_TPM_WRITE_LOCKED
;
; MessageText:
;
; The NV area has already been written to.
;
STATUS_TPM_WRITE_LOCKED          EQU 0C0290041h

;
; MessageId: STATUS_TPM_BAD_ATTRIBUTES
;
; MessageText:
;
; The NV area attributes conflict.
;
STATUS_TPM_BAD_ATTRIBUTES        EQU 0C0290042h

;
; MessageId: STATUS_TPM_INVALID_STRUCTURE
;
; MessageText:
;
; The structure tag and version are invalid or inconsistent.
;
STATUS_TPM_INVALID_STRUCTURE     EQU 0C0290043h

;
; MessageId: STATUS_TPM_KEY_OWNER_CONTROL
;
; MessageText:
;
; The key is under control of the TPM Owner and can only be evicted by the TPM Owner.
;
STATUS_TPM_KEY_OWNER_CONTROL     EQU 0C0290044h

;
; MessageId: STATUS_TPM_BAD_COUNTER
;
; MessageText:
;
; The counter handle is incorrect.
;
STATUS_TPM_BAD_COUNTER           EQU 0C0290045h

;
; MessageId: STATUS_TPM_NOT_FULLWRITE
;
; MessageText:
;
; The write is not a complete write of the area.
;
STATUS_TPM_NOT_FULLWRITE         EQU 0C0290046h

;
; MessageId: STATUS_TPM_CONTEXT_GAP
;
; MessageText:
;
; The gap between saved context counts is too large.
;
STATUS_TPM_CONTEXT_GAP           EQU 0C0290047h

;
; MessageId: STATUS_TPM_MAXNVWRITES
;
; MessageText:
;
; The maximum number of NV writes without an owner has been exceeded.
;
STATUS_TPM_MAXNVWRITES           EQU 0C0290048h

;
; MessageId: STATUS_TPM_NOOPERATOR
;
; MessageText:
;
; No operator AuthData value is set.
;
STATUS_TPM_NOOPERATOR            EQU 0C0290049h

;
; MessageId: STATUS_TPM_RESOURCEMISSING
;
; MessageText:
;
; The resource pointed to by context is not loaded.
;
STATUS_TPM_RESOURCEMISSING       EQU 0C029004Ah

;
; MessageId: STATUS_TPM_DELEGATE_LOCK
;
; MessageText:
;
; The delegate administration is locked.
;
STATUS_TPM_DELEGATE_LOCK         EQU 0C029004Bh

;
; MessageId: STATUS_TPM_DELEGATE_FAMILY
;
; MessageText:
;
; Attempt to manage a family other then the delegated family.
;
STATUS_TPM_DELEGATE_FAMILY       EQU 0C029004Ch

;
; MessageId: STATUS_TPM_DELEGATE_ADMIN
;
; MessageText:
;
; Delegation table management not enabled.
;
STATUS_TPM_DELEGATE_ADMIN        EQU 0C029004Dh

;
; MessageId: STATUS_TPM_TRANSPORT_NOTEXCLUSIVE
;
; MessageText:
;
; There was a command executed outside of an exclusive transport session.
;
STATUS_TPM_TRANSPORT_NOTEXCLUSIVE EQU 0C029004Eh

;
; MessageId: STATUS_TPM_OWNER_CONTROL
;
; MessageText:
;
; Attempt to context save a owner evict controlled key.
;
STATUS_TPM_OWNER_CONTROL         EQU 0C029004Fh

;
; MessageId: STATUS_TPM_DAA_RESOURCES
;
; MessageText:
;
; The DAA command has no resources availble to execute the command.
;
STATUS_TPM_DAA_RESOURCES         EQU 0C0290050h

;
; MessageId: STATUS_TPM_DAA_INPUT_DATA0
;
; MessageText:
;
; The consistency check on DAA parameter inputData0 has failed.
;
STATUS_TPM_DAA_INPUT_DATA0       EQU 0C0290051h

;
; MessageId: STATUS_TPM_DAA_INPUT_DATA1
;
; MessageText:
;
; The consistency check on DAA parameter inputData1 has failed.
;
STATUS_TPM_DAA_INPUT_DATA1       EQU 0C0290052h

;
; MessageId: STATUS_TPM_DAA_ISSUER_SETTINGS
;
; MessageText:
;
; The consistency check on DAA_issuerSettings has failed.
;
STATUS_TPM_DAA_ISSUER_SETTINGS   EQU 0C0290053h

;
; MessageId: STATUS_TPM_DAA_TPM_SETTINGS
;
; MessageText:
;
; The consistency check on DAA_tpmSpecific has failed.
;
STATUS_TPM_DAA_TPM_SETTINGS      EQU 0C0290054h

;
; MessageId: STATUS_TPM_DAA_STAGE
;
; MessageText:
;
; The atomic process indicated by the submitted DAA command is not the expected process.
;
STATUS_TPM_DAA_STAGE             EQU 0C0290055h

;
; MessageId: STATUS_TPM_DAA_ISSUER_VALIDITY
;
; MessageText:
;
; The issuer's validity check has detected an inconsistency.
;
STATUS_TPM_DAA_ISSUER_VALIDITY   EQU 0C0290056h

;
; MessageId: STATUS_TPM_DAA_WRONG_W
;
; MessageText:
;
; The consistency check on w has failed.
;
STATUS_TPM_DAA_WRONG_W           EQU 0C0290057h

;
; MessageId: STATUS_TPM_BAD_HANDLE
;
; MessageText:
;
; The handle is incorrect.
;
STATUS_TPM_BAD_HANDLE            EQU 0C0290058h

;
; MessageId: STATUS_TPM_BAD_DELEGATE
;
; MessageText:
;
; Delegation is not correct.
;
STATUS_TPM_BAD_DELEGATE          EQU 0C0290059h

;
; MessageId: STATUS_TPM_BADCONTEXT
;
; MessageText:
;
; The context blob is invalid.
;
STATUS_TPM_BADCONTEXT            EQU 0C029005Ah

;
; MessageId: STATUS_TPM_TOOMANYCONTEXTS
;
; MessageText:
;
; Too many contexts held by the TPM.
;
STATUS_TPM_TOOMANYCONTEXTS       EQU 0C029005Bh

;
; MessageId: STATUS_TPM_MA_TICKET_SIGNATURE
;
; MessageText:
;
; Migration authority signature validation failure.
;
STATUS_TPM_MA_TICKET_SIGNATURE   EQU 0C029005Ch

;
; MessageId: STATUS_TPM_MA_DESTINATION
;
; MessageText:
;
; Migration destination not authenticated.
;
STATUS_TPM_MA_DESTINATION        EQU 0C029005Dh

;
; MessageId: STATUS_TPM_MA_SOURCE
;
; MessageText:
;
; Migration source incorrect.
;
STATUS_TPM_MA_SOURCE             EQU 0C029005Eh

;
; MessageId: STATUS_TPM_MA_AUTHORITY
;
; MessageText:
;
; Incorrect migration authority.
;
STATUS_TPM_MA_AUTHORITY          EQU 0C029005Fh

;
; MessageId: STATUS_TPM_PERMANENTEK
;
; MessageText:
;
; Attempt to revoke the EK and the EK is not revocable.
;
STATUS_TPM_PERMANENTEK           EQU 0C0290061h

;
; MessageId: STATUS_TPM_BAD_SIGNATURE
;
; MessageText:
;
; Bad signature of CMK ticket.
;
STATUS_TPM_BAD_SIGNATURE         EQU 0C0290062h

;
; MessageId: STATUS_TPM_NOCONTEXTSPACE
;
; MessageText:
;
; There is no room in the context list for additional contexts.
;
STATUS_TPM_NOCONTEXTSPACE        EQU 0C0290063h

;
; TPM vendor specific hardware errors {0x0400..0x04ff}
;
;
; MessageId: STATUS_TPM_COMMAND_BLOCKED
;
; MessageText:
;
; The command was blocked.
;
STATUS_TPM_COMMAND_BLOCKED       EQU 0C0290400h

;
; MessageId: STATUS_TPM_INVALID_HANDLE
;
; MessageText:
;
; The specified handle was not found.
;
STATUS_TPM_INVALID_HANDLE        EQU 0C0290401h

;
; MessageId: STATUS_TPM_DUPLICATE_VHANDLE
;
; MessageText:
;
; The TPM returned a duplicate handle and the command needs to be resubmitted.
;
STATUS_TPM_DUPLICATE_VHANDLE     EQU 0C0290402h

;
; MessageId: STATUS_TPM_EMBEDDED_COMMAND_BLOCKED
;
; MessageText:
;
; The command within the transport was blocked.
;
STATUS_TPM_EMBEDDED_COMMAND_BLOCKED EQU 0C0290403h

;
; MessageId: STATUS_TPM_EMBEDDED_COMMAND_UNSUPPORTED
;
; MessageText:
;
; The command within the transport is not supported.
;
STATUS_TPM_EMBEDDED_COMMAND_UNSUPPORTED EQU 0C0290404h

;
; TPM non-fatal hardware errors {0x0800..0x08ff}
;
;
; MessageId: STATUS_TPM_RETRY
;
; MessageText:
;
; The TPM is too busy to respond to the command immediately, but the command could be resubmitted at a later time.
;
STATUS_TPM_RETRY                 EQU 0C0290800h

;
; MessageId: STATUS_TPM_NEEDS_SELFTEST
;
; MessageText:
;
; SelfTestFull has not been run.
;
STATUS_TPM_NEEDS_SELFTEST        EQU 0C0290801h

;
; MessageId: STATUS_TPM_DOING_SELFTEST
;
; MessageText:
;
; The TPM is currently executing a full selftest.
;
STATUS_TPM_DOING_SELFTEST        EQU 0C0290802h

;
; MessageId: STATUS_TPM_DEFEND_LOCK_RUNNING
;
; MessageText:
;
; The TPM is defending against dictionary attacks and is in a time-out period.
;
STATUS_TPM_DEFEND_LOCK_RUNNING   EQU 0C0290803h


;
; TPM software Error codes (tpm.sys)
;

;
; MessageId: STATUS_TPM_COMMAND_CANCELED
;
; MessageText:
;
; The command was cancelled.
;
STATUS_TPM_COMMAND_CANCELED      EQU 0C0291001h

;
; MessageId: STATUS_TPM_TOO_MANY_CONTEXTS
;
; MessageText:
;
; A new TPM context could not be created because there are too many open contexts.
;
STATUS_TPM_TOO_MANY_CONTEXTS     EQU 0C0291002h

;
; MessageId: STATUS_TPM_NOT_FOUND
;
; MessageText:
;
; TPM driver is not compatible with the version of TPM found on the system.
;
STATUS_TPM_NOT_FOUND             EQU 0C0291003h

;
; MessageId: STATUS_TPM_ACCESS_DENIED
;
; MessageText:
;
; The caller does not have the appropriate rights to perform the requested operation.
;
STATUS_TPM_ACCESS_DENIED         EQU 0C0291004h

;
; MessageId: STATUS_TPM_INSUFFICIENT_BUFFER
;
; MessageText:
;
; The caller does not have the appropriate rights to perform the requested operation.
;
STATUS_TPM_INSUFFICIENT_BUFFER   EQU 0C0291005h

;
; MessageId: STATUS_TPM_PPI_FUNCTION_UNSUPPORTED
;
; MessageText:
;
; The Physical Presence Interface of this firmware does not support the requested method.
;
STATUS_TPM_PPI_FUNCTION_UNSUPPORTED EQU 0C0291006h


;
; Platform Crypto Provider Error Codes (PCPTPM12.dll and future platform crypto providers)
;

;
; MessageId: STATUS_PCP_ERROR_MASK
;
; MessageText:
;
; This is an error mask to convert Platform Crypto Provider errors to win errors.
;
STATUS_PCP_ERROR_MASK            EQU 0C0292000h

;
; MessageId: STATUS_PCP_DEVICE_NOT_READY
;
; MessageText:
;
; The Platform Crypto Device is currently not ready. It needs to be fully provisioned to be operational.
;
STATUS_PCP_DEVICE_NOT_READY      EQU 0C0292001h

;
; MessageId: STATUS_PCP_INVALID_HANDLE
;
; MessageText:
;
; The handle provided to the Platform Crypto Provider is invalid.
;
STATUS_PCP_INVALID_HANDLE        EQU 0C0292002h

;
; MessageId: STATUS_PCP_INVALID_PARAMETER
;
; MessageText:
;
; A parameter provided to the Platform Crypto Provider is invalid.
;
STATUS_PCP_INVALID_PARAMETER     EQU 0C0292003h

;
; MessageId: STATUS_PCP_FLAG_NOT_SUPPORTED
;
; MessageText:
;
; A provided flag to the Platform Crypto Provider is not supported.
;
STATUS_PCP_FLAG_NOT_SUPPORTED    EQU 0C0292004h

;
; MessageId: STATUS_PCP_NOT_SUPPORTED
;
; MessageText:
;
; The requested operation is not supported by this Platform Crypto Provider.
;
STATUS_PCP_NOT_SUPPORTED         EQU 0C0292005h

;
; MessageId: STATUS_PCP_BUFFER_TOO_SMALL
;
; MessageText:
;
; The buffer is too small to contain all data. No information has been written to the buffer.
;
STATUS_PCP_BUFFER_TOO_SMALL      EQU 0C0292006h

;
; MessageId: STATUS_PCP_INTERNAL_ERROR
;
; MessageText:
;
; An unexpected internal error has occurred in the Platform Crypto Provider.
;
STATUS_PCP_INTERNAL_ERROR        EQU 0C0292007h

;
; MessageId: STATUS_PCP_AUTHENTICATION_FAILED
;
; MessageText:
;
; The authorization to use a provider object has failed.
;
STATUS_PCP_AUTHENTICATION_FAILED EQU 0C0292008h

;
; MessageId: STATUS_PCP_AUTHENTICATION_IGNORED
;
; MessageText:
;
; The Platform Crypto Device has ignored the authorization for the provider object, to mitigate against a dictionary attack.
;
STATUS_PCP_AUTHENTICATION_IGNORED EQU 0C0292009h

;
; MessageId: STATUS_PCP_POLICY_NOT_FOUND
;
; MessageText:
;
; The referenced policy was not found.
;
STATUS_PCP_POLICY_NOT_FOUND      EQU 0C029200Ah

;
; MessageId: STATUS_PCP_PROFILE_NOT_FOUND
;
; MessageText:
;
; The referenced profile was not found.
;
STATUS_PCP_PROFILE_NOT_FOUND     EQU 0C029200Bh

;
; MessageId: STATUS_PCP_VALIDATION_FAILED
;
; MessageText:
;
; The validation was not succesful.
;
STATUS_PCP_VALIDATION_FAILED     EQU 0C029200Ch

;
; MessageId: STATUS_PCP_DEVICE_NOT_FOUND
;
; MessageText:
;
; A Platform Crypto Device was not found.  Operations that require a Platform Crypto Device will not be submitted.
;
STATUS_PCP_DEVICE_NOT_FOUND      EQU 0C029200Dh

;
; Hypervisor error codes - changes to these codes must be reflected in HvStatus.h
;

;
; MessageId: STATUS_HV_INVALID_HYPERCALL_CODE
;
; MessageText:
;
; The hypervisor does not support the operation because the specified hypercall code is not supported.
;
STATUS_HV_INVALID_HYPERCALL_CODE EQU 0C0350002h

;
; MessageId: STATUS_HV_INVALID_HYPERCALL_INPUT
;
; MessageText:
;
; The hypervisor does not support the operation because the encoding for the hypercall input register is not supported.
;
STATUS_HV_INVALID_HYPERCALL_INPUT EQU 0C0350003h

;
; MessageId: STATUS_HV_INVALID_ALIGNMENT
;
; MessageText:
;
; The hypervisor could not perform the operation because a parameter has an invalid alignment.
;
STATUS_HV_INVALID_ALIGNMENT      EQU 0C0350004h

;
; MessageId: STATUS_HV_INVALID_PARAMETER
;
; MessageText:
;
; The hypervisor could not perform the operation because an invalid parameter was specified.
;
STATUS_HV_INVALID_PARAMETER      EQU 0C0350005h

;
; MessageId: STATUS_HV_ACCESS_DENIED
;
; MessageText:
;
; Access to the specified object was denied.
;
STATUS_HV_ACCESS_DENIED          EQU 0C0350006h

;
; MessageId: STATUS_HV_INVALID_PARTITION_STATE
;
; MessageText:
;
; The hypervisor could not perform the operation because the partition is entering or in an invalid state.
;
STATUS_HV_INVALID_PARTITION_STATE EQU 0C0350007h

;
; MessageId: STATUS_HV_OPERATION_DENIED
;
; MessageText:
;
; The operation is not allowed in the current state.
;
STATUS_HV_OPERATION_DENIED       EQU 0C0350008h

;
; MessageId: STATUS_HV_UNKNOWN_PROPERTY
;
; MessageText:
;
; The hypervisor does not recognize the specified partition property.
;
STATUS_HV_UNKNOWN_PROPERTY       EQU 0C0350009h

;
; MessageId: STATUS_HV_PROPERTY_VALUE_OUT_OF_RANGE
;
; MessageText:
;
; The specified value of a partition property is out of range or violates an invariant.
;
STATUS_HV_PROPERTY_VALUE_OUT_OF_RANGE EQU 0C035000Ah

;
; MessageId: STATUS_HV_INSUFFICIENT_MEMORY
;
; MessageText:
;
; There is not enough memory in the hypervisor pool to complete the operation.
;
STATUS_HV_INSUFFICIENT_MEMORY    EQU 0C035000Bh

;
; MessageId: STATUS_HV_PARTITION_TOO_DEEP
;
; MessageText:
;
; The maximum partition depth has been exceeded for the partition hierarchy.
;
STATUS_HV_PARTITION_TOO_DEEP     EQU 0C035000Ch

;
; MessageId: STATUS_HV_INVALID_PARTITION_ID
;
; MessageText:
;
; A partition with the specified partition Id does not exist.
;
STATUS_HV_INVALID_PARTITION_ID   EQU 0C035000Dh

;
; MessageId: STATUS_HV_INVALID_VP_INDEX
;
; MessageText:
;
; The hypervisor could not perform the operation because the specified VP index is invalid.
;
STATUS_HV_INVALID_VP_INDEX       EQU 0C035000Eh

;
; MessageId: STATUS_HV_INVALID_PORT_ID
;
; MessageText:
;
; The hypervisor could not perform the operation because the specified port identifier is invalid.
;
STATUS_HV_INVALID_PORT_ID        EQU 0C0350011h

;
; MessageId: STATUS_HV_INVALID_CONNECTION_ID
;
; MessageText:
;
; The hypervisor could not perform the operation because the specified connection identifier is invalid.
;
STATUS_HV_INVALID_CONNECTION_ID  EQU 0C0350012h

;
; MessageId: STATUS_HV_INSUFFICIENT_BUFFERS
;
; MessageText:
;
; Not enough buffers were supplied to send a message.
;
STATUS_HV_INSUFFICIENT_BUFFERS   EQU 0C0350013h

;
; MessageId: STATUS_HV_NOT_ACKNOWLEDGED
;
; MessageText:
;
; The previous virtual interrupt has not been acknowledged.
;
STATUS_HV_NOT_ACKNOWLEDGED       EQU 0C0350014h

;
; MessageId: STATUS_HV_ACKNOWLEDGED
;
; MessageText:
;
; The previous virtual interrupt has already been acknowledged.
;
STATUS_HV_ACKNOWLEDGED           EQU 0C0350016h

;
; MessageId: STATUS_HV_INVALID_SAVE_RESTORE_STATE
;
; MessageText:
;
; The indicated partition is not in a valid state for saving or restoring.
;
STATUS_HV_INVALID_SAVE_RESTORE_STATE EQU 0C0350017h

;
; MessageId: STATUS_HV_INVALID_SYNIC_STATE
;
; MessageText:
;
; The hypervisor could not complete the operation because a required feature of the synthetic interrupt controller (SynIC) was disabled.
;
STATUS_HV_INVALID_SYNIC_STATE    EQU 0C0350018h

;
; MessageId: STATUS_HV_OBJECT_IN_USE
;
; MessageText:
;
; The hypervisor could not perform the operation because the object or value was either already in use or being used for a purpose that would not permit completing the operation.
;
STATUS_HV_OBJECT_IN_USE          EQU 0C0350019h

;
; MessageId: STATUS_HV_INVALID_PROXIMITY_DOMAIN_INFO
;
; MessageText:
;
; The proximity domain information is invalid.
;
STATUS_HV_INVALID_PROXIMITY_DOMAIN_INFO EQU 0C035001Ah

;
; MessageId: STATUS_HV_NO_DATA
;
; MessageText:
;
; An attempt to retrieve debugging data failed because none was available.
;
STATUS_HV_NO_DATA                EQU 0C035001Bh

;
; MessageId: STATUS_HV_INACTIVE
;
; MessageText:
;
; The physical connection being used for debugging has not recorded any receive activity since the last operation.
;
STATUS_HV_INACTIVE               EQU 0C035001Ch

;
; MessageId: STATUS_HV_NO_RESOURCES
;
; MessageText:
;
; There are not enough resources to complete the operation.
;
STATUS_HV_NO_RESOURCES           EQU 0C035001Dh

;
; MessageId: STATUS_HV_FEATURE_UNAVAILABLE
;
; MessageText:
;
; A hypervisor feature is not available to the user.
;
STATUS_HV_FEATURE_UNAVAILABLE    EQU 0C035001Eh

;
; MessageId: STATUS_HV_INSUFFICIENT_BUFFER
;
; MessageText:
;
; The specified buffer was too small to contain all of the requested data.
;
STATUS_HV_INSUFFICIENT_BUFFER    EQU 0C0350033h

;
; MessageId: STATUS_HV_INSUFFICIENT_DEVICE_DOMAINS
;
; MessageText:
;
; The maximum number of domains supported by the platform I/O remapping hardware is currently in use. No domains are available to assign this device to this partition.
;
STATUS_HV_INSUFFICIENT_DEVICE_DOMAINS EQU 0C0350038h

;
; MessageId: STATUS_HV_INVALID_LP_INDEX
;
; MessageText:
;
; The hypervisor could not perform the operation because the specified LP index is invalid.
;
STATUS_HV_INVALID_LP_INDEX       EQU 0C0350041h

;
; MessageId: STATUS_HV_NOT_PRESENT
;
; MessageText:
;
; No hypervisor is present on this system.
;
STATUS_HV_NOT_PRESENT            EQU 0C0351000h

;
; Virtualization status codes - these codes are used by the Virtualization Infrustructure Driver (VID) and other components
;                               of the virtualization stack.
;
;
; Errors:
;

;
; MessageId: STATUS_VID_DUPLICATE_HANDLER
;
; MessageText:
;
; The handler for the virtualization infrastructure driver is already registered. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_DUPLICATE_HANDLER     EQU 0C0370001h

;
; MessageId: STATUS_VID_TOO_MANY_HANDLERS
;
; MessageText:
;
; The number of registered handlers for the virtualization infrastructure driver exceeded the maximum. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_TOO_MANY_HANDLERS     EQU 0C0370002h

;
; MessageId: STATUS_VID_QUEUE_FULL
;
; MessageText:
;
; The message queue for the virtualization infrastructure driver is full and cannot accept new messages. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_QUEUE_FULL            EQU 0C0370003h

;
; MessageId: STATUS_VID_HANDLER_NOT_PRESENT
;
; MessageText:
;
; No handler exists to handle the message for the virtualization infrastructure driver. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_HANDLER_NOT_PRESENT   EQU 0C0370004h

;
; MessageId: STATUS_VID_INVALID_OBJECT_NAME
;
; MessageText:
;
; The name of the partition or message queue for the virtualization infrastructure driver is invalid. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_INVALID_OBJECT_NAME   EQU 0C0370005h

;
; MessageId: STATUS_VID_PARTITION_NAME_TOO_LONG
;
; MessageText:
;
; The partition name of the virtualization infrastructure driver exceeds the maximum.
;
STATUS_VID_PARTITION_NAME_TOO_LONG EQU 0C0370006h

;
; MessageId: STATUS_VID_MESSAGE_QUEUE_NAME_TOO_LONG
;
; MessageText:
;
; The message queue name of the virtualization infrastructure driver exceeds the maximum.
;
STATUS_VID_MESSAGE_QUEUE_NAME_TOO_LONG EQU 0C0370007h

;
; MessageId: STATUS_VID_PARTITION_ALREADY_EXISTS
;
; MessageText:
;
; Cannot create the partition for the virtualization infrastructure driver because another partition with the same name already exists.
;
STATUS_VID_PARTITION_ALREADY_EXISTS EQU 0C0370008h

;
; MessageId: STATUS_VID_PARTITION_DOES_NOT_EXIST
;
; MessageText:
;
; The virtualization infrastructure driver has encountered an error. The requested partition does not exist. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_PARTITION_DOES_NOT_EXIST EQU 0C0370009h

;
; MessageId: STATUS_VID_PARTITION_NAME_NOT_FOUND
;
; MessageText:
;
; The virtualization infrastructure driver has encountered an error. Could not find the requested partition. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_PARTITION_NAME_NOT_FOUND EQU 0C037000Ah

;
; MessageId: STATUS_VID_MESSAGE_QUEUE_ALREADY_EXISTS
;
; MessageText:
;
; A message queue with the same name already exists for the virtualization infrastructure driver.
;
STATUS_VID_MESSAGE_QUEUE_ALREADY_EXISTS EQU 0C037000Bh

;
; MessageId: STATUS_VID_EXCEEDED_MBP_ENTRY_MAP_LIMIT
;
; MessageText:
;
; The memory block page for the virtualization infrastructure driver cannot be mapped because the page map limit has been reached. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_EXCEEDED_MBP_ENTRY_MAP_LIMIT EQU 0C037000Ch

;
; MessageId: STATUS_VID_MB_STILL_REFERENCED
;
; MessageText:
;
; The memory block for the virtualization infrastructure driver is still being used and cannot be destroyed.
;
STATUS_VID_MB_STILL_REFERENCED   EQU 0C037000Dh

;
; MessageId: STATUS_VID_CHILD_GPA_PAGE_SET_CORRUPTED
;
; MessageText:
;
; Cannot unlock the page array for the guest operating system memory address because it does not match a previous lock request. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_CHILD_GPA_PAGE_SET_CORRUPTED EQU 0C037000Eh

;
; MessageId: STATUS_VID_INVALID_NUMA_SETTINGS
;
; MessageText:
;
; The non-uniform memory access (NUMA) node settings do not match the system NUMA topology. In order to start the virtual machine, you will need to modify the NUMA configuration.
;
STATUS_VID_INVALID_NUMA_SETTINGS EQU 0C037000Fh

;
; MessageId: STATUS_VID_INVALID_NUMA_NODE_INDEX
;
; MessageText:
;
; The non-uniform memory access (NUMA) node index does not match a valid index in the system NUMA topology.
;
STATUS_VID_INVALID_NUMA_NODE_INDEX EQU 0C0370010h

;
; MessageId: STATUS_VID_NOTIFICATION_QUEUE_ALREADY_ASSOCIATED
;
; MessageText:
;
; The memory block for the virtualization infrastructure driver is already associated with a message queue.
;
STATUS_VID_NOTIFICATION_QUEUE_ALREADY_ASSOCIATED EQU 0C0370011h

;
; MessageId: STATUS_VID_INVALID_MEMORY_BLOCK_HANDLE
;
; MessageText:
;
; The handle is not a valid memory block handle for the virtualization infrastructure driver.
;
STATUS_VID_INVALID_MEMORY_BLOCK_HANDLE EQU 0C0370012h

;
; MessageId: STATUS_VID_PAGE_RANGE_OVERFLOW
;
; MessageText:
;
; The request exceeded the memory block page limit for the virtualization infrastructure driver. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_PAGE_RANGE_OVERFLOW   EQU 0C0370013h

;
; MessageId: STATUS_VID_INVALID_MESSAGE_QUEUE_HANDLE
;
; MessageText:
;
; The handle is not a valid message queue handle for the virtualization infrastructure driver.
;
STATUS_VID_INVALID_MESSAGE_QUEUE_HANDLE EQU 0C0370014h

;
; MessageId: STATUS_VID_INVALID_GPA_RANGE_HANDLE
;
; MessageText:
;
; The handle is not a valid page range handle for the virtualization infrastructure driver.
;
STATUS_VID_INVALID_GPA_RANGE_HANDLE EQU 0C0370015h

;
; MessageId: STATUS_VID_NO_MEMORY_BLOCK_NOTIFICATION_QUEUE
;
; MessageText:
;
; Cannot install client notifications because no message queue for the virtualization infrastructure driver is associated with the memory block.
;
STATUS_VID_NO_MEMORY_BLOCK_NOTIFICATION_QUEUE EQU 0C0370016h

;
; MessageId: STATUS_VID_MEMORY_BLOCK_LOCK_COUNT_EXCEEDED
;
; MessageText:
;
; The request to lock or map a memory block page failed because the virtualization infrastructure driver memory block limit has been reached. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_MEMORY_BLOCK_LOCK_COUNT_EXCEEDED EQU 0C0370017h

;
; MessageId: STATUS_VID_INVALID_PPM_HANDLE
;
; MessageText:
;
; The handle is not a valid parent partition mapping handle for the virtualization infrastructure driver.
;
STATUS_VID_INVALID_PPM_HANDLE    EQU 0C0370018h

;
; MessageId: STATUS_VID_MBPS_ARE_LOCKED
;
; MessageText:
;
; Notifications cannot be created on the memory block because it is use.
;
STATUS_VID_MBPS_ARE_LOCKED       EQU 0C0370019h

;
; MessageId: STATUS_VID_MESSAGE_QUEUE_CLOSED
;
; MessageText:
;
; The message queue for the virtualization infrastructure driver has been closed. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_MESSAGE_QUEUE_CLOSED  EQU 0C037001Ah

;
; MessageId: STATUS_VID_VIRTUAL_PROCESSOR_LIMIT_EXCEEDED
;
; MessageText:
;
; Cannot add a virtual processor to the partition because the maximum has been reached.
;
STATUS_VID_VIRTUAL_PROCESSOR_LIMIT_EXCEEDED EQU 0C037001Bh

;
; MessageId: STATUS_VID_STOP_PENDING
;
; MessageText:
;
; Cannot stop the virtual processor immediately because of a pending intercept.
;
STATUS_VID_STOP_PENDING          EQU 0C037001Ch

;
; MessageId: STATUS_VID_INVALID_PROCESSOR_STATE
;
; MessageText:
;
; Invalid state for the virtual processor. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_INVALID_PROCESSOR_STATE EQU 0C037001Dh

;
; MessageId: STATUS_VID_EXCEEDED_KM_CONTEXT_COUNT_LIMIT
;
; MessageText:
;
; The maximum number of kernel mode clients for the virtualization infrastructure driver has been reached. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_EXCEEDED_KM_CONTEXT_COUNT_LIMIT EQU 0C037001Eh

;
; MessageId: STATUS_VID_KM_INTERFACE_ALREADY_INITIALIZED
;
; MessageText:
;
; This kernel mode interface for the virtualization infrastructure driver has already been initialized. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_KM_INTERFACE_ALREADY_INITIALIZED EQU 0C037001Fh

;
; MessageId: STATUS_VID_MB_PROPERTY_ALREADY_SET_RESET
;
; MessageText:
;
; Cannot set or reset the memory block property more than once for the virtualization infrastructure driver. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_MB_PROPERTY_ALREADY_SET_RESET EQU 0C0370020h

;
; MessageId: STATUS_VID_MMIO_RANGE_DESTROYED
;
; MessageText:
;
; The memory mapped I/O for this page range no longer exists. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_MMIO_RANGE_DESTROYED  EQU 0C0370021h

;
; MessageId: STATUS_VID_INVALID_CHILD_GPA_PAGE_SET
;
; MessageText:
;
; The lock or unlock request uses an invalid guest operating system memory address. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_INVALID_CHILD_GPA_PAGE_SET EQU 0C0370022h

;
; MessageId: STATUS_VID_RESERVE_PAGE_SET_IS_BEING_USED
;
; MessageText:
;
; Cannot destroy or reuse the reserve page set for the virtualization infrastructure driver because it is in use. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_RESERVE_PAGE_SET_IS_BEING_USED EQU 0C0370023h

;
; MessageId: STATUS_VID_RESERVE_PAGE_SET_TOO_SMALL
;
; MessageText:
;
; The reserve page set for the virtualization infrastructure driver is too small to use in the lock request. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_RESERVE_PAGE_SET_TOO_SMALL EQU 0C0370024h

;
; MessageId: STATUS_VID_MBP_ALREADY_LOCKED_USING_RESERVED_PAGE
;
; MessageText:
;
; Cannot lock or map the memory block page for the virtualization infrastructure driver because it has already been locked using a reserve page set page. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_MBP_ALREADY_LOCKED_USING_RESERVED_PAGE EQU 0C0370025h

;
; MessageId: STATUS_VID_MBP_COUNT_EXCEEDED_LIMIT
;
; MessageText:
;
; Cannot create the memory block for the virtualization infrastructure driver because the requested number of pages exceeded the limit. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.
;
STATUS_VID_MBP_COUNT_EXCEEDED_LIMIT EQU 0C0370026h

;
; MessageId: STATUS_VID_SAVED_STATE_CORRUPT
;
; MessageText:
;
; Cannot restore this virtual machine because the saved state data cannot be read. Delete the saved state data and then try to start the virtual machine.
;
STATUS_VID_SAVED_STATE_CORRUPT   EQU 0C0370027h

;
; MessageId: STATUS_VID_SAVED_STATE_UNRECOGNIZED_ITEM
;
; MessageText:
;
; Cannot restore this virtual machine because an item read from the saved state data is not recognized. Delete the saved state data and then try to start the virtual machine.
;
STATUS_VID_SAVED_STATE_UNRECOGNIZED_ITEM EQU 0C0370028h

;
; MessageId: STATUS_VID_SAVED_STATE_INCOMPATIBLE
;
; MessageText:
;
; Cannot restore this virtual machine to the saved state because of hypervisor incompatibility. Delete the saved state data and then try to start the virtual machine.
;
STATUS_VID_SAVED_STATE_INCOMPATIBLE EQU 0C0370029h

;
; Warnings:
;
;
; MessageId: STATUS_VID_REMOTE_NODE_PARENT_GPA_PAGES_USED
;
; MessageText:
;
; A virtual machine is running with its memory allocated across multiple NUMA nodes. This does not indicate a problem unless the performance of your virtual machine is unusually slow. If you are experiencing performance problems, you may need to modify the NUMA configuration.
;
STATUS_VID_REMOTE_NODE_PARENT_GPA_PAGES_USED EQU 080370001h


;
; IPSEC error codes (tcpip.sys)
;

;
; MessageId: STATUS_IPSEC_BAD_SPI
;
; MessageText:
;
; The SPI in the packet does not match a valid IPsec SA.
;
STATUS_IPSEC_BAD_SPI             EQU 0C0360001h

;
; MessageId: STATUS_IPSEC_SA_LIFETIME_EXPIRED
;
; MessageText:
;
; Packet was received on an IPsec SA whose lifetime has expired.
;
STATUS_IPSEC_SA_LIFETIME_EXPIRED EQU 0C0360002h

;
; MessageId: STATUS_IPSEC_WRONG_SA
;
; MessageText:
;
; Packet was received on an IPsec SA that does not match the packet characteristics.
;
STATUS_IPSEC_WRONG_SA            EQU 0C0360003h

;
; MessageId: STATUS_IPSEC_REPLAY_CHECK_FAILED
;
; MessageText:
;
; Packet sequence number replay check failed.
;
STATUS_IPSEC_REPLAY_CHECK_FAILED EQU 0C0360004h

;
; MessageId: STATUS_IPSEC_INVALID_PACKET
;
; MessageText:
;
; IPsec header and/or trailer in the packet is invalid.
;
STATUS_IPSEC_INVALID_PACKET      EQU 0C0360005h

;
; MessageId: STATUS_IPSEC_INTEGRITY_CHECK_FAILED
;
; MessageText:
;
; IPsec integrity check failed.
;
STATUS_IPSEC_INTEGRITY_CHECK_FAILED EQU 0C0360006h

;
; MessageId: STATUS_IPSEC_CLEAR_TEXT_DROP
;
; MessageText:
;
; IPsec dropped a clear text packet.
;
STATUS_IPSEC_CLEAR_TEXT_DROP     EQU 0C0360007h

;
; MessageId: STATUS_IPSEC_AUTH_FIREWALL_DROP
;
; MessageText:
;
; IPsec dropped an incoming ESP packet in authenticated firewall mode. This drop is benign.
;
STATUS_IPSEC_AUTH_FIREWALL_DROP  EQU 0C0360008h

;
; MessageId: STATUS_IPSEC_THROTTLE_DROP
;
; MessageText:
;
; IPsec dropped a packet due to DoS throttling.
;
STATUS_IPSEC_THROTTLE_DROP       EQU 0C0360009h

;
; MessageId: STATUS_IPSEC_DOSP_BLOCK
;
; MessageText:
;
; IPsec DoS Protection matched an explicit block rule.
;
STATUS_IPSEC_DOSP_BLOCK          EQU 0C0368000h

;
; MessageId: STATUS_IPSEC_DOSP_RECEIVED_MULTICAST
;
; MessageText:
;
; IPsec DoS Protection received an IPsec specific multicast packet which is not allowed.
;
STATUS_IPSEC_DOSP_RECEIVED_MULTICAST EQU 0C0368001h

;
; MessageId: STATUS_IPSEC_DOSP_INVALID_PACKET
;
; MessageText:
;
; IPsec DoS Protection received an incorrectly formatted packet.
;
STATUS_IPSEC_DOSP_INVALID_PACKET EQU 0C0368002h

;
; MessageId: STATUS_IPSEC_DOSP_STATE_LOOKUP_FAILED
;
; MessageText:
;
; IPsec DoS Protection failed to look up state.
;
STATUS_IPSEC_DOSP_STATE_LOOKUP_FAILED EQU 0C0368003h

;
; MessageId: STATUS_IPSEC_DOSP_MAX_ENTRIES
;
; MessageText:
;
; IPsec DoS Protection failed to create state because the maximum number of entries allowed by policy has been reached.
;
STATUS_IPSEC_DOSP_MAX_ENTRIES    EQU 0C0368004h

;
; MessageId: STATUS_IPSEC_DOSP_KEYMOD_NOT_ALLOWED
;
; MessageText:
;
; IPsec DoS Protection received an IPsec negotiation packet for a keying module which is not allowed by policy.
;
STATUS_IPSEC_DOSP_KEYMOD_NOT_ALLOWED EQU 0C0368005h

;
; MessageId: STATUS_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES
;
; MessageText:
;
; IPsec DoS Protection failed to create a per internal IP rate limit queue because the maximum number of queues allowed by policy has been reached.
;
STATUS_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES EQU 0C0368006h


;
; Volume manager status codes (volmgr.sys and volmgrx.sys)
;

;
; WARNINGS
;
;
; MessageId: STATUS_VOLMGR_INCOMPLETE_REGENERATION
;
; MessageText:
;
; The regeneration operation was not able to copy all data from the active plexes due to bad sectors.
;
STATUS_VOLMGR_INCOMPLETE_REGENERATION EQU 080380001h

;
; MessageId: STATUS_VOLMGR_INCOMPLETE_DISK_MIGRATION
;
; MessageText:
;
; One or more disks were not fully migrated to the target pack. They may or may not require reimport after fixing the hardware problems.
;
STATUS_VOLMGR_INCOMPLETE_DISK_MIGRATION EQU 080380002h

;
; ERRORS
;
;
; MessageId: STATUS_VOLMGR_DATABASE_FULL
;
; MessageText:
;
; The configuration database is full.
;
STATUS_VOLMGR_DATABASE_FULL      EQU 0C0380001h

;
; MessageId: STATUS_VOLMGR_DISK_CONFIGURATION_CORRUPTED
;
; MessageText:
;
; The configuration data on the disk is corrupted.
;
STATUS_VOLMGR_DISK_CONFIGURATION_CORRUPTED EQU 0C0380002h

;
; MessageId: STATUS_VOLMGR_DISK_CONFIGURATION_NOT_IN_SYNC
;
; MessageText:
;
; The configuration on the disk is not insync with the in-memory configuration.
;
STATUS_VOLMGR_DISK_CONFIGURATION_NOT_IN_SYNC EQU 0C0380003h

;
; MessageId: STATUS_VOLMGR_PACK_CONFIG_UPDATE_FAILED
;
; MessageText:
;
; A majority of disks failed to be updated with the new configuration.
;
STATUS_VOLMGR_PACK_CONFIG_UPDATE_FAILED EQU 0C0380004h

;
; MessageId: STATUS_VOLMGR_DISK_CONTAINS_NON_SIMPLE_VOLUME
;
; MessageText:
;
; The disk contains non-simple volumes.
;
STATUS_VOLMGR_DISK_CONTAINS_NON_SIMPLE_VOLUME EQU 0C0380005h

;
; MessageId: STATUS_VOLMGR_DISK_DUPLICATE
;
; MessageText:
;
; The same disk was specified more than once in the migration list.
;
STATUS_VOLMGR_DISK_DUPLICATE     EQU 0C0380006h

;
; MessageId: STATUS_VOLMGR_DISK_DYNAMIC
;
; MessageText:
;
; The disk is already dynamic.
;
STATUS_VOLMGR_DISK_DYNAMIC       EQU 0C0380007h

;
; MessageId: STATUS_VOLMGR_DISK_ID_INVALID
;
; MessageText:
;
; The specified disk id is invalid. There are no disks with the specified disk id.
;
STATUS_VOLMGR_DISK_ID_INVALID    EQU 0C0380008h

;
; MessageId: STATUS_VOLMGR_DISK_INVALID
;
; MessageText:
;
; The specified disk is an invalid disk. Operation cannot complete on an invalid disk.
;
STATUS_VOLMGR_DISK_INVALID       EQU 0C0380009h

;
; MessageId: STATUS_VOLMGR_DISK_LAST_VOTER
;
; MessageText:
;
; The specified disk(s) cannot be removed since it is the last remaining voter.
;
STATUS_VOLMGR_DISK_LAST_VOTER    EQU 0C038000Ah

;
; MessageId: STATUS_VOLMGR_DISK_LAYOUT_INVALID
;
; MessageText:
;
; The specified disk has an invalid disk layout.
;
STATUS_VOLMGR_DISK_LAYOUT_INVALID EQU 0C038000Bh

;
; MessageId: STATUS_VOLMGR_DISK_LAYOUT_NON_BASIC_BETWEEN_BASIC_PARTITIONS
;
; MessageText:
;
; The disk layout contains non-basic partitions which appear after basic paritions. This is an invalid disk layout.
;
STATUS_VOLMGR_DISK_LAYOUT_NON_BASIC_BETWEEN_BASIC_PARTITIONS EQU 0C038000Ch

;
; MessageId: STATUS_VOLMGR_DISK_LAYOUT_NOT_CYLINDER_ALIGNED
;
; MessageText:
;
; The disk layout contains partitions which are not cylinder aligned.
;
STATUS_VOLMGR_DISK_LAYOUT_NOT_CYLINDER_ALIGNED EQU 0C038000Dh

;
; MessageId: STATUS_VOLMGR_DISK_LAYOUT_PARTITIONS_TOO_SMALL
;
; MessageText:
;
; The disk layout contains partitions which are samller than the minimum size.
;
STATUS_VOLMGR_DISK_LAYOUT_PARTITIONS_TOO_SMALL EQU 0C038000Eh

;
; MessageId: STATUS_VOLMGR_DISK_LAYOUT_PRIMARY_BETWEEN_LOGICAL_PARTITIONS
;
; MessageText:
;
; The disk layout contains primary partitions in between logical drives. This is an invalid disk layout.
;
STATUS_VOLMGR_DISK_LAYOUT_PRIMARY_BETWEEN_LOGICAL_PARTITIONS EQU 0C038000Fh

;
; MessageId: STATUS_VOLMGR_DISK_LAYOUT_TOO_MANY_PARTITIONS
;
; MessageText:
;
; The disk layout contains more than the maximum number of supported partitions.
;
STATUS_VOLMGR_DISK_LAYOUT_TOO_MANY_PARTITIONS EQU 0C0380010h

;
; MessageId: STATUS_VOLMGR_DISK_MISSING
;
; MessageText:
;
; The specified disk is missing. The operation cannot complete on a missing disk.
;
STATUS_VOLMGR_DISK_MISSING       EQU 0C0380011h

;
; MessageId: STATUS_VOLMGR_DISK_NOT_EMPTY
;
; MessageText:
;
; The specified disk is not empty.
;
STATUS_VOLMGR_DISK_NOT_EMPTY     EQU 0C0380012h

;
; MessageId: STATUS_VOLMGR_DISK_NOT_ENOUGH_SPACE
;
; MessageText:
;
; There is not enough usable space for this operation.
;
STATUS_VOLMGR_DISK_NOT_ENOUGH_SPACE EQU 0C0380013h

;
; MessageId: STATUS_VOLMGR_DISK_REVECTORING_FAILED
;
; MessageText:
;
; The force revectoring of bad sectors failed.
;
STATUS_VOLMGR_DISK_REVECTORING_FAILED EQU 0C0380014h

;
; MessageId: STATUS_VOLMGR_DISK_SECTOR_SIZE_INVALID
;
; MessageText:
;
; The specified disk has an invalid sector size.
;
STATUS_VOLMGR_DISK_SECTOR_SIZE_INVALID EQU 0C0380015h

;
; MessageId: STATUS_VOLMGR_DISK_SET_NOT_CONTAINED
;
; MessageText:
;
; The specified disk set contains volumes which exist on disks outside of the set.
;
STATUS_VOLMGR_DISK_SET_NOT_CONTAINED EQU 0C0380016h

;
; MessageId: STATUS_VOLMGR_DISK_USED_BY_MULTIPLE_MEMBERS
;
; MessageText:
;
; A disk in the volume layout provides extents to more than one member of a plex.
;
STATUS_VOLMGR_DISK_USED_BY_MULTIPLE_MEMBERS EQU 0C0380017h

;
; MessageId: STATUS_VOLMGR_DISK_USED_BY_MULTIPLE_PLEXES
;
; MessageText:
;
; A disk in the volume layout provides extents to more than one plex.
;
STATUS_VOLMGR_DISK_USED_BY_MULTIPLE_PLEXES EQU 0C0380018h

;
; MessageId: STATUS_VOLMGR_DYNAMIC_DISK_NOT_SUPPORTED
;
; MessageText:
;
; Dynamic disks are not supported on this system.
;
STATUS_VOLMGR_DYNAMIC_DISK_NOT_SUPPORTED EQU 0C0380019h

;
; MessageId: STATUS_VOLMGR_EXTENT_ALREADY_USED
;
; MessageText:
;
; The specified extent is already used by other volumes.
;
STATUS_VOLMGR_EXTENT_ALREADY_USED EQU 0C038001Ah

;
; MessageId: STATUS_VOLMGR_EXTENT_NOT_CONTIGUOUS
;
; MessageText:
;
; The specified volume is retained and can only be extended into a contiguous extent. The specified extent to grow the volume is not contiguous with the specified volume.
;
STATUS_VOLMGR_EXTENT_NOT_CONTIGUOUS EQU 0C038001Bh

;
; MessageId: STATUS_VOLMGR_EXTENT_NOT_IN_PUBLIC_REGION
;
; MessageText:
;
; The specified volume extent is not within the public region of the disk.
;
STATUS_VOLMGR_EXTENT_NOT_IN_PUBLIC_REGION EQU 0C038001Ch

;
; MessageId: STATUS_VOLMGR_EXTENT_NOT_SECTOR_ALIGNED
;
; MessageText:
;
; The specifed volume extent is not sector aligned.
;
STATUS_VOLMGR_EXTENT_NOT_SECTOR_ALIGNED EQU 0C038001Dh

;
; MessageId: STATUS_VOLMGR_EXTENT_OVERLAPS_EBR_PARTITION
;
; MessageText:
;
; The specified parition overlaps an EBR (the first track of an extended partition on a MBR disks).
;
STATUS_VOLMGR_EXTENT_OVERLAPS_EBR_PARTITION EQU 0C038001Eh

;
; MessageId: STATUS_VOLMGR_EXTENT_VOLUME_LENGTHS_DO_NOT_MATCH
;
; MessageText:
;
; The specified extent lengths cannot be used to construct a volume with specified length.
;
STATUS_VOLMGR_EXTENT_VOLUME_LENGTHS_DO_NOT_MATCH EQU 0C038001Fh

;
; MessageId: STATUS_VOLMGR_FAULT_TOLERANT_NOT_SUPPORTED
;
; MessageText:
;
; The system does not support fault tolerant volumes.
;
STATUS_VOLMGR_FAULT_TOLERANT_NOT_SUPPORTED EQU 0C0380020h

;
; MessageId: STATUS_VOLMGR_INTERLEAVE_LENGTH_INVALID
;
; MessageText:
;
; The specified interleave length is invalid.
;
STATUS_VOLMGR_INTERLEAVE_LENGTH_INVALID EQU 0C0380021h

;
; MessageId: STATUS_VOLMGR_MAXIMUM_REGISTERED_USERS
;
; MessageText:
;
; There is already a maximum number of registered users.
;
STATUS_VOLMGR_MAXIMUM_REGISTERED_USERS EQU 0C0380022h

;
; MessageId: STATUS_VOLMGR_MEMBER_IN_SYNC
;
; MessageText:
;
; The specified member is already in-sync with the other active members. It does not need to be regenerated.
;
STATUS_VOLMGR_MEMBER_IN_SYNC     EQU 0C0380023h

;
; MessageId: STATUS_VOLMGR_MEMBER_INDEX_DUPLICATE
;
; MessageText:
;
; The same member index was specified more than once.
;
STATUS_VOLMGR_MEMBER_INDEX_DUPLICATE EQU 0C0380024h

;
; MessageId: STATUS_VOLMGR_MEMBER_INDEX_INVALID
;
; MessageText:
;
; The specified member index is greater or equal than the number of members in the volume plex.
;
STATUS_VOLMGR_MEMBER_INDEX_INVALID EQU 0C0380025h

;
; MessageId: STATUS_VOLMGR_MEMBER_MISSING
;
; MessageText:
;
; The specified member is missing. It cannot be regenerated.
;
STATUS_VOLMGR_MEMBER_MISSING     EQU 0C0380026h

;
; MessageId: STATUS_VOLMGR_MEMBER_NOT_DETACHED
;
; MessageText:
;
; The specified member is not detached. Cannot replace a member which is not detached.
;
STATUS_VOLMGR_MEMBER_NOT_DETACHED EQU 0C0380027h

;
; MessageId: STATUS_VOLMGR_MEMBER_REGENERATING
;
; MessageText:
;
; The specified member is already regenerating.
;
STATUS_VOLMGR_MEMBER_REGENERATING EQU 0C0380028h

;
; MessageId: STATUS_VOLMGR_ALL_DISKS_FAILED
;
; MessageText:
;
; All disks belonging to the pack failed.
;
STATUS_VOLMGR_ALL_DISKS_FAILED   EQU 0C0380029h

;
; MessageId: STATUS_VOLMGR_NO_REGISTERED_USERS
;
; MessageText:
;
; There are currently no registered users for notifications. The task number is irrelevant unless there are registered users.
;
STATUS_VOLMGR_NO_REGISTERED_USERS EQU 0C038002Ah

;
; MessageId: STATUS_VOLMGR_NO_SUCH_USER
;
; MessageText:
;
; The specified notification user does not exist. Failed to unregister user for notifications.
;
STATUS_VOLMGR_NO_SUCH_USER       EQU 0C038002Bh

;
; MessageId: STATUS_VOLMGR_NOTIFICATION_RESET
;
; MessageText:
;
; The notifications have been reset. Notifications for the current user are invalid. Unregister and re-register for notifications.
;
STATUS_VOLMGR_NOTIFICATION_RESET EQU 0C038002Ch

;
; MessageId: STATUS_VOLMGR_NUMBER_OF_MEMBERS_INVALID
;
; MessageText:
;
; The specified number of members is invalid.
;
STATUS_VOLMGR_NUMBER_OF_MEMBERS_INVALID EQU 0C038002Dh

;
; MessageId: STATUS_VOLMGR_NUMBER_OF_PLEXES_INVALID
;
; MessageText:
;
; The specified number of plexes is invalid.
;
STATUS_VOLMGR_NUMBER_OF_PLEXES_INVALID EQU 0C038002Eh

;
; MessageId: STATUS_VOLMGR_PACK_DUPLICATE
;
; MessageText:
;
; The specified source and target packs are identical.
;
STATUS_VOLMGR_PACK_DUPLICATE     EQU 0C038002Fh

;
; MessageId: STATUS_VOLMGR_PACK_ID_INVALID
;
; MessageText:
;
; The specified pack id is invalid. There are no packs with the specified pack id.
;
STATUS_VOLMGR_PACK_ID_INVALID    EQU 0C0380030h

;
; MessageId: STATUS_VOLMGR_PACK_INVALID
;
; MessageText:
;
; The specified pack is the invalid pack. The operation cannot complete with the invalid pack.
;
STATUS_VOLMGR_PACK_INVALID       EQU 0C0380031h

;
; MessageId: STATUS_VOLMGR_PACK_NAME_INVALID
;
; MessageText:
;
; The specified pack name is invalid.
;
STATUS_VOLMGR_PACK_NAME_INVALID  EQU 0C0380032h

;
; MessageId: STATUS_VOLMGR_PACK_OFFLINE
;
; MessageText:
;
; The specified pack is offline.
;
STATUS_VOLMGR_PACK_OFFLINE       EQU 0C0380033h

;
; MessageId: STATUS_VOLMGR_PACK_HAS_QUORUM
;
; MessageText:
;
; The specified pack already has a quorum of healthy disks.
;
STATUS_VOLMGR_PACK_HAS_QUORUM    EQU 0C0380034h

;
; MessageId: STATUS_VOLMGR_PACK_WITHOUT_QUORUM
;
; MessageText:
;
; The pack does not have a quorum of healthy disks.
;
STATUS_VOLMGR_PACK_WITHOUT_QUORUM EQU 0C0380035h

;
; MessageId: STATUS_VOLMGR_PARTITION_STYLE_INVALID
;
; MessageText:
;
; The specified disk has an unsupported partition style. Only MBR and GPT partition styles are supported.
;
STATUS_VOLMGR_PARTITION_STYLE_INVALID EQU 0C0380036h

;
; MessageId: STATUS_VOLMGR_PARTITION_UPDATE_FAILED
;
; MessageText:
;
; Failed to update the disk's partition layout.
;
STATUS_VOLMGR_PARTITION_UPDATE_FAILED EQU 0C0380037h

;
; MessageId: STATUS_VOLMGR_PLEX_IN_SYNC
;
; MessageText:
;
; The specified plex is already in-sync with the other active plexes. It does not need to be regenerated.
;
STATUS_VOLMGR_PLEX_IN_SYNC       EQU 0C0380038h

;
; MessageId: STATUS_VOLMGR_PLEX_INDEX_DUPLICATE
;
; MessageText:
;
; The same plex index was specified more than once.
;
STATUS_VOLMGR_PLEX_INDEX_DUPLICATE EQU 0C0380039h

;
; MessageId: STATUS_VOLMGR_PLEX_INDEX_INVALID
;
; MessageText:
;
; The specified plex index is greater or equal than the number of plexes in the volume.
;
STATUS_VOLMGR_PLEX_INDEX_INVALID EQU 0C038003Ah

;
; MessageId: STATUS_VOLMGR_PLEX_LAST_ACTIVE
;
; MessageText:
;
; The specified plex is the last active plex in the volume. The plex cannot be removed or else the volume will go offline.
;
STATUS_VOLMGR_PLEX_LAST_ACTIVE   EQU 0C038003Bh

;
; MessageId: STATUS_VOLMGR_PLEX_MISSING
;
; MessageText:
;
; The specified plex is missing.
;
STATUS_VOLMGR_PLEX_MISSING       EQU 0C038003Ch

;
; MessageId: STATUS_VOLMGR_PLEX_REGENERATING
;
; MessageText:
;
; The specified plex is currently regenerating.
;
STATUS_VOLMGR_PLEX_REGENERATING  EQU 0C038003Dh

;
; MessageId: STATUS_VOLMGR_PLEX_TYPE_INVALID
;
; MessageText:
;
; The specified plex type is invalid.
;
STATUS_VOLMGR_PLEX_TYPE_INVALID  EQU 0C038003Eh

;
; MessageId: STATUS_VOLMGR_PLEX_NOT_RAID5
;
; MessageText:
;
; The operation is only supported on RAID-5 plexes.
;
STATUS_VOLMGR_PLEX_NOT_RAID5     EQU 0C038003Fh

;
; MessageId: STATUS_VOLMGR_PLEX_NOT_SIMPLE
;
; MessageText:
;
; The operation is only supported on simple plexes.
;
STATUS_VOLMGR_PLEX_NOT_SIMPLE    EQU 0C0380040h

;
; MessageId: STATUS_VOLMGR_STRUCTURE_SIZE_INVALID
;
; MessageText:
;
; The Size fields in the VM_VOLUME_LAYOUT input structure are incorrectly set.
;
STATUS_VOLMGR_STRUCTURE_SIZE_INVALID EQU 0C0380041h

;
; MessageId: STATUS_VOLMGR_TOO_MANY_NOTIFICATION_REQUESTS
;
; MessageText:
;
; There is already a pending request for notifications. Wait for the existing request to return before requesting for more notifications.
;
STATUS_VOLMGR_TOO_MANY_NOTIFICATION_REQUESTS EQU 0C0380042h

;
; MessageId: STATUS_VOLMGR_TRANSACTION_IN_PROGRESS
;
; MessageText:
;
; There is currently a transaction in process.
;
STATUS_VOLMGR_TRANSACTION_IN_PROGRESS EQU 0C0380043h

;
; MessageId: STATUS_VOLMGR_UNEXPECTED_DISK_LAYOUT_CHANGE
;
; MessageText:
;
; An unexpected layout change occurred outside of the volume manager.
;
STATUS_VOLMGR_UNEXPECTED_DISK_LAYOUT_CHANGE EQU 0C0380044h

;
; MessageId: STATUS_VOLMGR_VOLUME_CONTAINS_MISSING_DISK
;
; MessageText:
;
; The specified volume contains a missing disk.
;
STATUS_VOLMGR_VOLUME_CONTAINS_MISSING_DISK EQU 0C0380045h

;
; MessageId: STATUS_VOLMGR_VOLUME_ID_INVALID
;
; MessageText:
;
; The specified volume id is invalid. There are no volumes with the specified volume id.
;
STATUS_VOLMGR_VOLUME_ID_INVALID  EQU 0C0380046h

;
; MessageId: STATUS_VOLMGR_VOLUME_LENGTH_INVALID
;
; MessageText:
;
; The specified volume length is invalid.
;
STATUS_VOLMGR_VOLUME_LENGTH_INVALID EQU 0C0380047h

;
; MessageId: STATUS_VOLMGR_VOLUME_LENGTH_NOT_SECTOR_SIZE_MULTIPLE
;
; MessageText:
;
; The specified size for the volume is not a multiple of the sector size.
;
STATUS_VOLMGR_VOLUME_LENGTH_NOT_SECTOR_SIZE_MULTIPLE EQU 0C0380048h

;
; MessageId: STATUS_VOLMGR_VOLUME_NOT_MIRRORED
;
; MessageText:
;
; The operation is only supported on mirrored volumes.
;
STATUS_VOLMGR_VOLUME_NOT_MIRRORED EQU 0C0380049h

;
; MessageId: STATUS_VOLMGR_VOLUME_NOT_RETAINED
;
; MessageText:
;
; The specified volume does not have a retain partition.
;
STATUS_VOLMGR_VOLUME_NOT_RETAINED EQU 0C038004Ah

;
; MessageId: STATUS_VOLMGR_VOLUME_OFFLINE
;
; MessageText:
;
; The specified volume is offline.
;
STATUS_VOLMGR_VOLUME_OFFLINE     EQU 0C038004Bh

;
; MessageId: STATUS_VOLMGR_VOLUME_RETAINED
;
; MessageText:
;
; The specified volume already has a retain partition.
;
STATUS_VOLMGR_VOLUME_RETAINED    EQU 0C038004Ch

;
; MessageId: STATUS_VOLMGR_NUMBER_OF_EXTENTS_INVALID
;
; MessageText:
;
; The specified number of extents is invalid.
;
STATUS_VOLMGR_NUMBER_OF_EXTENTS_INVALID EQU 0C038004Dh

;
; MessageId: STATUS_VOLMGR_DIFFERENT_SECTOR_SIZE
;
; MessageText:
;
; All disks participating to the volume must have the same sector size.
;
STATUS_VOLMGR_DIFFERENT_SECTOR_SIZE EQU 0C038004Eh

;
; MessageId: STATUS_VOLMGR_BAD_BOOT_DISK
;
; MessageText:
;
; The boot disk experienced failures.
;
STATUS_VOLMGR_BAD_BOOT_DISK      EQU 0C038004Fh

;
; MessageId: STATUS_VOLMGR_PACK_CONFIG_OFFLINE
;
; MessageText:
;
; The configuration of the pack is offline.
;
STATUS_VOLMGR_PACK_CONFIG_OFFLINE EQU 0C0380050h

;
; MessageId: STATUS_VOLMGR_PACK_CONFIG_ONLINE
;
; MessageText:
;
; The configuration of the pack is online.
;
STATUS_VOLMGR_PACK_CONFIG_ONLINE EQU 0C0380051h

;
; MessageId: STATUS_VOLMGR_NOT_PRIMARY_PACK
;
; MessageText:
;
; The specified pack is not the primary pack.
;
STATUS_VOLMGR_NOT_PRIMARY_PACK   EQU 0C0380052h

;
; MessageId: STATUS_VOLMGR_PACK_LOG_UPDATE_FAILED
;
; MessageText:
;
; All disks failed to be updated with the new content of the log.
;
STATUS_VOLMGR_PACK_LOG_UPDATE_FAILED EQU 0C0380053h

;
; MessageId: STATUS_VOLMGR_NUMBER_OF_DISKS_IN_PLEX_INVALID
;
; MessageText:
;
; The specified number of disks in a plex is invalid.
;
STATUS_VOLMGR_NUMBER_OF_DISKS_IN_PLEX_INVALID EQU 0C0380054h

;
; MessageId: STATUS_VOLMGR_NUMBER_OF_DISKS_IN_MEMBER_INVALID
;
; MessageText:
;
; The specified number of disks in a plex member is invalid.
;
STATUS_VOLMGR_NUMBER_OF_DISKS_IN_MEMBER_INVALID EQU 0C0380055h

;
; MessageId: STATUS_VOLMGR_VOLUME_MIRRORED
;
; MessageText:
;
; The operation is not supported on mirrored volumes.
;
STATUS_VOLMGR_VOLUME_MIRRORED    EQU 0C0380056h

;
; MessageId: STATUS_VOLMGR_PLEX_NOT_SIMPLE_SPANNED
;
; MessageText:
;
; The operation is only supported on simple and spanned plexes.
;
STATUS_VOLMGR_PLEX_NOT_SIMPLE_SPANNED EQU 0C0380057h

;
; MessageId: STATUS_VOLMGR_NO_VALID_LOG_COPIES
;
; MessageText:
;
; The pack has no valid log copies.
;
STATUS_VOLMGR_NO_VALID_LOG_COPIES EQU 0C0380058h

;
; MessageId: STATUS_VOLMGR_PRIMARY_PACK_PRESENT
;
; MessageText:
;
; A primary pack is already present.
;
STATUS_VOLMGR_PRIMARY_PACK_PRESENT EQU 0C0380059h

;
; MessageId: STATUS_VOLMGR_NUMBER_OF_DISKS_INVALID
;
; MessageText:
;
; The specified number of disks is invalid.
;
STATUS_VOLMGR_NUMBER_OF_DISKS_INVALID EQU 0C038005Ah

;
; MessageId: STATUS_VOLMGR_MIRROR_NOT_SUPPORTED
;
; MessageText:
;
; The system does not support mirrored volumes.
;
STATUS_VOLMGR_MIRROR_NOT_SUPPORTED EQU 0C038005Bh

;
; MessageId: STATUS_VOLMGR_RAID5_NOT_SUPPORTED
;
; MessageText:
;
; The system does not support RAID-5 volumes.
;
STATUS_VOLMGR_RAID5_NOT_SUPPORTED EQU 0C038005Ch

;
; Boot Code Data (BCD) status codes
;

;
; MessageId: STATUS_BCD_NOT_ALL_ENTRIES_IMPORTED
;
; MessageText:
;
; Some BCD entries were not imported correctly from the BCD store.
;
STATUS_BCD_NOT_ALL_ENTRIES_IMPORTED EQU 080390001h

;
; MessageId: STATUS_BCD_TOO_MANY_ELEMENTS
;
; MessageText:
;
; Entries enumerated have exceeded the allowed threshold.
;
STATUS_BCD_TOO_MANY_ELEMENTS     EQU 0C0390002h

;
; MessageId: STATUS_BCD_NOT_ALL_ENTRIES_SYNCHRONIZED
;
; MessageText:
;
; Some BCD entries were not synchronized correctly with the firmware.
;
STATUS_BCD_NOT_ALL_ENTRIES_SYNCHRONIZED EQU 080390003h


;
; vhdparser error codes (vhdparser.sys)
;

;
; MessageId: STATUS_VHD_DRIVE_FOOTER_MISSING
;
; MessageText:
;
; The virtual hard disk is corrupted. The virtual hard disk drive footer is missing.
;
STATUS_VHD_DRIVE_FOOTER_MISSING  EQU 0C03A0001h

;
; MessageId: STATUS_VHD_DRIVE_FOOTER_CHECKSUM_MISMATCH
;
; MessageText:
;
; The virtual hard disk is corrupted. The virtual hard disk drive footer checksum does not match the on-disk checksum.
;
STATUS_VHD_DRIVE_FOOTER_CHECKSUM_MISMATCH EQU 0C03A0002h

;
; MessageId: STATUS_VHD_DRIVE_FOOTER_CORRUPT
;
; MessageText:
;
; The virtual hard disk is corrupted. The virtual hard disk drive footer in the virtual hard disk is corrupted.
;
STATUS_VHD_DRIVE_FOOTER_CORRUPT  EQU 0C03A0003h

;
; MessageId: STATUS_VHD_FORMAT_UNKNOWN
;
; MessageText:
;
; The system does not recognize the file format of this virtual hard disk.
;
STATUS_VHD_FORMAT_UNKNOWN        EQU 0C03A0004h

;
; MessageId: STATUS_VHD_FORMAT_UNSUPPORTED_VERSION
;
; MessageText:
;
; The version does not support this version of the file format.
;
STATUS_VHD_FORMAT_UNSUPPORTED_VERSION EQU 0C03A0005h

;
; MessageId: STATUS_VHD_SPARSE_HEADER_CHECKSUM_MISMATCH
;
; MessageText:
;
; The virtual hard disk is corrupted. The sparse header checksum does not match the on-disk checksum.
;
STATUS_VHD_SPARSE_HEADER_CHECKSUM_MISMATCH EQU 0C03A0006h

;
; MessageId: STATUS_VHD_SPARSE_HEADER_UNSUPPORTED_VERSION
;
; MessageText:
;
; The system does not support this version of the virtual hard disk.This version of the sparse header is not supported.
;
STATUS_VHD_SPARSE_HEADER_UNSUPPORTED_VERSION EQU 0C03A0007h

;
; MessageId: STATUS_VHD_SPARSE_HEADER_CORRUPT
;
; MessageText:
;
; The virtual hard disk is corrupted. The sparse header in the virtual hard disk is corrupt.
;
STATUS_VHD_SPARSE_HEADER_CORRUPT EQU 0C03A0008h

;
; MessageId: STATUS_VHD_BLOCK_ALLOCATION_FAILURE
;
; MessageText:
;
; Failed to write to the virtual hard disk failed because the system failed to allocate a new block in the virtual hard disk.
;
STATUS_VHD_BLOCK_ALLOCATION_FAILURE EQU 0C03A0009h

;
; MessageId: STATUS_VHD_BLOCK_ALLOCATION_TABLE_CORRUPT
;
; MessageText:
;
; The virtual hard disk is corrupted. The block allocation table in the virtual hard disk is corrupt.
;
STATUS_VHD_BLOCK_ALLOCATION_TABLE_CORRUPT EQU 0C03A000Ah

;
; MessageId: STATUS_VHD_INVALID_BLOCK_SIZE
;
; MessageText:
;
; The system does not support this version of the virtual hard disk. The block size is invalid.
;
STATUS_VHD_INVALID_BLOCK_SIZE    EQU 0C03A000Bh

;
; MessageId: STATUS_VHD_BITMAP_MISMATCH
;
; MessageText:
;
; The virtual hard disk is corrupted. The block bitmap does not match with the block data present in the virtual hard disk.
;
STATUS_VHD_BITMAP_MISMATCH       EQU 0C03A000Ch

;
; MessageId: STATUS_VHD_PARENT_VHD_NOT_FOUND
;
; MessageText:
;
; The chain of virtual hard disks is broken. The system cannot locate the parent virtual hard disk for the differencing disk.
;
STATUS_VHD_PARENT_VHD_NOT_FOUND  EQU 0C03A000Dh

;
; MessageId: STATUS_VHD_CHILD_PARENT_ID_MISMATCH
;
; MessageText:
;
; The chain of virtual hard disks is corrupted. There is a mismatch in the identifiers of the parent virtual hard disk and differencing disk.
;
STATUS_VHD_CHILD_PARENT_ID_MISMATCH EQU 0C03A000Eh

;
; MessageId: STATUS_VHD_CHILD_PARENT_TIMESTAMP_MISMATCH
;
; MessageText:
;
; The chain of virtual hard disks is corrupted. The time stamp of the parent virtual hard disk does not match the time stamp of the differencing disk.
;
STATUS_VHD_CHILD_PARENT_TIMESTAMP_MISMATCH EQU 0C03A000Fh

;
; MessageId: STATUS_VHD_METADATA_READ_FAILURE
;
; MessageText:
;
; Failed to read the metadata of the virtual hard disk.
;
STATUS_VHD_METADATA_READ_FAILURE EQU 0C03A0010h

;
; MessageId: STATUS_VHD_METADATA_WRITE_FAILURE
;
; MessageText:
;
; Failed to write to the metadata of the virtual hard disk.
;
STATUS_VHD_METADATA_WRITE_FAILURE EQU 0C03A0011h

;
; MessageId: STATUS_VHD_INVALID_SIZE
;
; MessageText:
;
; The size of the virtual hard disk is not valid.
;
STATUS_VHD_INVALID_SIZE          EQU 0C03A0012h

;
; MessageId: STATUS_VHD_INVALID_FILE_SIZE
;
; MessageText:
;
; The file size of this virtual hard disk is not valid.
;
STATUS_VHD_INVALID_FILE_SIZE     EQU 0C03A0013h

;
; MessageId: STATUS_VIRTDISK_PROVIDER_NOT_FOUND
;
; MessageText:
;
; A virtual disk support provider for the specified file was not found.
;
STATUS_VIRTDISK_PROVIDER_NOT_FOUND EQU 0C03A0014h

;
; MessageId: STATUS_VIRTDISK_NOT_VIRTUAL_DISK
;
; MessageText:
;
; The specified disk is not a virtual disk.
;
STATUS_VIRTDISK_NOT_VIRTUAL_DISK EQU 0C03A0015h

;
; MessageId: STATUS_VHD_PARENT_VHD_ACCESS_DENIED
;
; MessageText:
;
; The chain of virtual hard disks is inaccessible. The process has not been granted access rights to the parent virtual hard disk for the differencing disk.
;
STATUS_VHD_PARENT_VHD_ACCESS_DENIED EQU 0C03A0016h

;
; MessageId: STATUS_VHD_CHILD_PARENT_SIZE_MISMATCH
;
; MessageText:
;
; The chain of virtual hard disks is corrupted. There is a mismatch in the virtual sizes of the parent virtual hard disk and differencing disk.
;
STATUS_VHD_CHILD_PARENT_SIZE_MISMATCH EQU 0C03A0017h

;
; MessageId: STATUS_VHD_DIFFERENCING_CHAIN_CYCLE_DETECTED
;
; MessageText:
;
; The chain of virtual hard disks is corrupted. A differencing disk is indicated in its own parent chain.
;
STATUS_VHD_DIFFERENCING_CHAIN_CYCLE_DETECTED EQU 0C03A0018h

;
; MessageId: STATUS_VHD_DIFFERENCING_CHAIN_ERROR_IN_PARENT
;
; MessageText:
;
; The chain of virtual hard disks is inaccessible. There was an error opening a virtual hard disk further up the chain.
;
STATUS_VHD_DIFFERENCING_CHAIN_ERROR_IN_PARENT EQU 0C03A0019h

;
; MessageId: STATUS_VIRTUAL_DISK_LIMITATION
;
; MessageText:
;
; The requested operation could not be completed due to a virtual disk system limitation.  On NTFS, virtual hard disk files must be uncompressed and unencrypted. On ReFS, virtual hard disk files must not have the integrity bit set.
;
STATUS_VIRTUAL_DISK_LIMITATION   EQU 0C03A001Ah

;
; MessageId: STATUS_VHD_INVALID_TYPE
;
; MessageText:
;
; The requested operation cannot be performed on a virtual disk of this type.
;
STATUS_VHD_INVALID_TYPE          EQU 0C03A001Bh

;
; MessageId: STATUS_VHD_INVALID_STATE
;
; MessageText:
;
; The requested operation cannot be performed on the virtual disk in its current state.
;
STATUS_VHD_INVALID_STATE         EQU 0C03A001Ch

;
; MessageId: STATUS_VIRTDISK_UNSUPPORTED_DISK_SECTOR_SIZE
;
; MessageText:
;
; The sector size of the physical disk on which the virtual disk resides is not supported.
;
STATUS_VIRTDISK_UNSUPPORTED_DISK_SECTOR_SIZE EQU 0C03A001Dh

;
; MessageId: STATUS_VIRTDISK_DISK_ALREADY_OWNED
;
; MessageText:
;
; The disk is already owned by a different owner.
;
STATUS_VIRTDISK_DISK_ALREADY_OWNED EQU 0C03A001Eh

;
; MessageId: STATUS_VIRTDISK_DISK_ONLINE_AND_WRITABLE
;
; MessageText:
;
; The disk must be offline or read-only.
;
STATUS_VIRTDISK_DISK_ONLINE_AND_WRITABLE EQU 0C03A001Fh

;
; MessageId: STATUS_CTLOG_TRACKING_NOT_INITIALIZED
;
; MessageText:
;
; Change Tracking is not initialized for this virtual disk.
;
STATUS_CTLOG_TRACKING_NOT_INITIALIZED EQU 0C03A0020h

;
; MessageId: STATUS_CTLOG_LOGFILE_SIZE_EXCEEDED_MAXSIZE
;
; MessageText:
;
; Size of change tracking file exceeded the maximum size limit.
;
STATUS_CTLOG_LOGFILE_SIZE_EXCEEDED_MAXSIZE EQU 0C03A0021h

;
; MessageId: STATUS_CTLOG_VHD_CHANGED_OFFLINE
;
; MessageText:
;
; VHD file is changed due to compaction, expansion, or offline updates.
;
STATUS_CTLOG_VHD_CHANGED_OFFLINE EQU 0C03A0022h

;
; MessageId: STATUS_CTLOG_INVALID_TRACKING_STATE
;
; MessageText:
;
; Change Tracking for the virtual disk is not in a valid state to perform this request.  Change tracking could be discontinued or already in the requested state.
;
STATUS_CTLOG_INVALID_TRACKING_STATE EQU 0C03A0023h

;
; MessageId: STATUS_CTLOG_INCONSISTENT_TRACKING_FILE
;
; MessageText:
;
; Change Tracking file for the virtual disk is not in a valid state.
;
STATUS_CTLOG_INCONSISTENT_TRACKING_FILE EQU 0C03A0024h

;
; MessageId: STATUS_VHD_METADATA_FULL
;
; MessageText:
;
; There is not enough space in the virtual disk file for the provided metadata item.
;
STATUS_VHD_METADATA_FULL         EQU 0C03A0028h


;
; Vhd warnings.
;

;
; MessageId: STATUS_QUERY_STORAGE_ERROR
;
; MessageText:
;
; The virtualization storage subsystem has generated an error.
;
STATUS_QUERY_STORAGE_ERROR       EQU 0803A0001h


;
; Resume Key Filter (RKF) error codes.
;
;
; MessageId: STATUS_RKF_KEY_NOT_FOUND
;
; MessageText:
;
; The Resume Key Filter could not find the resume key supplied for the operation.
;
STATUS_RKF_KEY_NOT_FOUND         EQU 0C0400001h

;
; MessageId: STATUS_RKF_DUPLICATE_KEY
;
; MessageText:
;
; The Resume Key Filter found an existing resume key that matches the one supplied for the handle.
;
STATUS_RKF_DUPLICATE_KEY         EQU 0C0400002h

;
; MessageId: STATUS_RKF_BLOB_FULL
;
; MessageText:
;
; The Resume Key Filter data blob attached to the handle is full. No more space is available.
;
STATUS_RKF_BLOB_FULL             EQU 0C0400003h

;
; MessageId: STATUS_RKF_STORE_FULL
;
; MessageText:
;
; The Resume Key Filter handle store is full. No more resume handles can be accepted.
;
STATUS_RKF_STORE_FULL            EQU 0C0400004h

;
; MessageId: STATUS_RKF_FILE_BLOCKED
;
; MessageText:
;
; The Resume Key Filter failed the operation because the file is temporarily blocked pending the resume of existing handles on the file.
;
STATUS_RKF_FILE_BLOCKED          EQU 0C0400005h

;
; MessageId: STATUS_RKF_ACTIVE_KEY
;
; MessageText:
;
; The Resume Key Filter found an existing resume key that matches the one supplied on a handle that's active/open. The operation requires an inactive/closed handle.
;
STATUS_RKF_ACTIVE_KEY            EQU 0C0400006h


;
; RDBSS / MiniRdr internal error codes.
;
;
; MessageId: STATUS_RDBSS_RESTART_OPERATION
;
; MessageText:
;
; The operation must be restarted by RDBSS.
;
STATUS_RDBSS_RESTART_OPERATION   EQU 0C0410001h

;
; MessageId: STATUS_RDBSS_CONTINUE_OPERATION
;
; MessageText:
;
; The operation must continue processing.
;
STATUS_RDBSS_CONTINUE_OPERATION  EQU 0C0410002h

;
; MessageId: STATUS_RDBSS_POST_OPERATION
;
; MessageText:
;
; The operation must be posted to a thread to be retried at passive IRQL.
;
STATUS_RDBSS_POST_OPERATION      EQU 0C0410003h

;
; Bluetooth Attribute Protocol Warnings
;

;
; MessageId: STATUS_BTH_ATT_INVALID_HANDLE
;
; MessageText:
;
; The attribute handle given was not valid on this server.
;
STATUS_BTH_ATT_INVALID_HANDLE    EQU 0C0420001h

;
; MessageId: STATUS_BTH_ATT_READ_NOT_PERMITTED
;
; MessageText:
;
; The attribute cannot be read.
;
STATUS_BTH_ATT_READ_NOT_PERMITTED EQU 0C0420002h

;
; MessageId: STATUS_BTH_ATT_WRITE_NOT_PERMITTED
;
; MessageText:
;
; The attribute cannot be written.
;
STATUS_BTH_ATT_WRITE_NOT_PERMITTED EQU 0C0420003h

;
; MessageId: STATUS_BTH_ATT_INVALID_PDU
;
; MessageText:
;
; The attribute PDU was invalid.
;
STATUS_BTH_ATT_INVALID_PDU       EQU 0C0420004h

;
; MessageId: STATUS_BTH_ATT_INSUFFICIENT_AUTHENTICATION
;
; MessageText:
;
; The attribute requires authentication before it can be read or written.
;
STATUS_BTH_ATT_INSUFFICIENT_AUTHENTICATION EQU 0C0420005h

;
; MessageId: STATUS_BTH_ATT_REQUEST_NOT_SUPPORTED
;
; MessageText:
;
; Attribute server does not support the request received from the client.
;
STATUS_BTH_ATT_REQUEST_NOT_SUPPORTED EQU 0C0420006h

;
; MessageId: STATUS_BTH_ATT_INVALID_OFFSET
;
; MessageText:
;
; Offset specified was past the end of the attribute.
;
STATUS_BTH_ATT_INVALID_OFFSET    EQU 0C0420007h

;
; MessageId: STATUS_BTH_ATT_INSUFFICIENT_AUTHORIZATION
;
; MessageText:
;
; The attribute requires authorization before it can be read or written.
;
STATUS_BTH_ATT_INSUFFICIENT_AUTHORIZATION EQU 0C0420008h

;
; MessageId: STATUS_BTH_ATT_PREPARE_QUEUE_FULL
;
; MessageText:
;
; Too many prepare writes have been queued.
;
STATUS_BTH_ATT_PREPARE_QUEUE_FULL EQU 0C0420009h

;
; MessageId: STATUS_BTH_ATT_ATTRIBUTE_NOT_FOUND
;
; MessageText:
;
; No attribute found within the given attribute handle range.
;
STATUS_BTH_ATT_ATTRIBUTE_NOT_FOUND EQU 0C042000Ah

;
; MessageId: STATUS_BTH_ATT_ATTRIBUTE_NOT_LONG
;
; MessageText:
;
; The attribute cannot be read or written using the Read Blob Request.
;
STATUS_BTH_ATT_ATTRIBUTE_NOT_LONG EQU 0C042000Bh

;
; MessageId: STATUS_BTH_ATT_INSUFFICIENT_ENCRYPTION_KEY_SIZE
;
; MessageText:
;
; The Encryption Key Size used for encrypting this link is insufficient.
;
STATUS_BTH_ATT_INSUFFICIENT_ENCRYPTION_KEY_SIZE EQU 0C042000Ch

;
; MessageId: STATUS_BTH_ATT_INVALID_ATTRIBUTE_VALUE_LENGTH
;
; MessageText:
;
; The attribute value length is invalid for the operation.
;
STATUS_BTH_ATT_INVALID_ATTRIBUTE_VALUE_LENGTH EQU 0C042000Dh

;
; MessageId: STATUS_BTH_ATT_UNLIKELY
;
; MessageText:
;
; The attribute request that was requested has encountered an error that was unlikely, and therefore could not be completed as requested.
;
STATUS_BTH_ATT_UNLIKELY          EQU 0C042000Eh

;
; MessageId: STATUS_BTH_ATT_INSUFFICIENT_ENCRYPTION
;
; MessageText:
;
; The attribute requires encryption before it can be read or written.
;
STATUS_BTH_ATT_INSUFFICIENT_ENCRYPTION EQU 0C042000Fh

;
; MessageId: STATUS_BTH_ATT_UNSUPPORTED_GROUP_TYPE
;
; MessageText:
;
; The attribute type is not a supported grouping attribute as defined by a higher layer specification.
;
STATUS_BTH_ATT_UNSUPPORTED_GROUP_TYPE EQU 0C0420010h

;
; MessageId: STATUS_BTH_ATT_INSUFFICIENT_RESOURCES
;
; MessageText:
;
; Insufficient Resources to complete the request.
;
STATUS_BTH_ATT_INSUFFICIENT_RESOURCES EQU 0C0420011h

;
; MessageId: STATUS_BTH_ATT_UNKNOWN_ERROR
;
; MessageText:
;
; An error that lies in the reserved range has been received.
;
STATUS_BTH_ATT_UNKNOWN_ERROR     EQU 0C0421000h

;
; Secure Boot error messages.
;
;
; MessageId: STATUS_SECUREBOOT_ROLLBACK_DETECTED
;
; MessageText:
;
; Secure Boot detected that rollback of protected data has been attempted.
;
STATUS_SECUREBOOT_ROLLBACK_DETECTED EQU 0C0430001h

;
; MessageId: STATUS_SECUREBOOT_POLICY_VIOLATION
;
; MessageText:
;
; The value is protected by Secure Boot policy and cannot be modified or deleted.
;
STATUS_SECUREBOOT_POLICY_VIOLATION EQU 0C0430002h

;
; MessageId: STATUS_SECUREBOOT_INVALID_POLICY
;
; MessageText:
;
; The Secure Boot policy is invalid.
;
STATUS_SECUREBOOT_INVALID_POLICY EQU 0C0430003h

;
; MessageId: STATUS_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND
;
; MessageText:
;
; A new Secure Boot policy did not contain the current publisher on its update list.
;
STATUS_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND EQU 0C0430004h

;
; MessageId: STATUS_SECUREBOOT_POLICY_NOT_SIGNED
;
; MessageText:
;
; The Secure Boot policy is either not signed or is signed by a non-trusted signer.
;
STATUS_SECUREBOOT_POLICY_NOT_SIGNED EQU 0C0430005h

;
; MessageId: STATUS_SECUREBOOT_NOT_ENABLED
;
; MessageText:
;
; Secure Boot is not enabled on this machine.
;
STATUS_SECUREBOOT_NOT_ENABLED    EQU 080430006h

;
; MessageId: STATUS_SECUREBOOT_FILE_REPLACED
;
; MessageText:
;
; Secure Boot requires that certain files and drivers are not replaced by other files or drivers.
;
STATUS_SECUREBOOT_FILE_REPLACED  EQU 0C0430007h

;
; Audio error messages.
;
;
; MessageId: STATUS_AUDIO_ENGINE_NODE_NOT_FOUND
;
; MessageText:
;
; PortCls could not find an audio engine node exposed by a miniport driver claiming support for IMiniportAudioEngineNode.
;
STATUS_AUDIO_ENGINE_NODE_NOT_FOUND EQU 0C0440001h

;
; MessageId: STATUS_HDAUDIO_EMPTY_CONNECTION_LIST
;
; MessageText:
;
; HD Audio widget encountered an unexpected empty connection list.
;
STATUS_HDAUDIO_EMPTY_CONNECTION_LIST EQU 0C0440002h

;
; MessageId: STATUS_HDAUDIO_CONNECTION_LIST_NOT_SUPPORTED
;
; MessageText:
;
; HD Audio widget does not support the connection list parameter.
;
STATUS_HDAUDIO_CONNECTION_LIST_NOT_SUPPORTED EQU 0C0440003h

;
; MessageId: STATUS_HDAUDIO_NO_LOGICAL_DEVICES_CREATED
;
; MessageText:
;
; No HD Audio subdevices were successfully created.
;
STATUS_HDAUDIO_NO_LOGICAL_DEVICES_CREATED EQU 0C0440004h

;
; MessageId: STATUS_HDAUDIO_NULL_LINKED_LIST_ENTRY
;
; MessageText:
;
; An unexpected NULL pointer was encountered in a linked list.
;
STATUS_HDAUDIO_NULL_LINKED_LIST_ENTRY EQU 0C0440005h

;
; Spaceport status codes (spaceport.sys)
;
;
; MessageId: STATUS_SPACES_RESILIENCY_TYPE_INVALID
;
; MessageText:
;
; The specified resiliency type is not valid.
;
STATUS_SPACES_RESILIENCY_TYPE_INVALID EQU 0C0E70003h

;
; MessageId: STATUS_SPACES_DRIVE_SECTOR_SIZE_INVALID
;
; MessageText:
;
; The sector size of the physical disk is not supported by the storage pool.
;
STATUS_SPACES_DRIVE_SECTOR_SIZE_INVALID EQU 0C0E70004h

;
; MessageId: STATUS_SPACES_INTERLEAVE_LENGTH_INVALID
;
; MessageText:
;
; The value for interleave length is outside of the supported range of values.
;
STATUS_SPACES_INTERLEAVE_LENGTH_INVALID EQU 0C0E70009h

;
; MessageId: STATUS_SPACES_NUMBER_OF_COLUMNS_INVALID
;
; MessageText:
;
; The number of columns specified is outside of the supported range of values.
;
STATUS_SPACES_NUMBER_OF_COLUMNS_INVALID EQU 0C0E7000Ah

;
; MessageId: STATUS_SPACES_NOT_ENOUGH_DRIVES
;
; MessageText:
;
; There were not enough physical disks to complete the requested operation.
;
STATUS_SPACES_NOT_ENOUGH_DRIVES  EQU 0C0E7000Bh

;
; Volsnap status codes (volsnap.sys)
;
;
; MessageId: STATUS_VOLSNAP_BOOTFILE_NOT_VALID
;
; MessageText:
;
; The bootfile is too small to support persistent snapshots.
;
STATUS_VOLSNAP_BOOTFILE_NOT_VALID EQU 0C0500003h

;
; Sdbus status codes (sdbus.sys)
;
;
; MessageId: STATUS_IO_PREEMPTED
;
; MessageText:
;
; The operation was preempted by a higher priority operation. It must be resumed later.
;
STATUS_IO_PREEMPTED              EQU 0C0510001h

;
; Shared VHDX status codes (svhdxflt.sys)
;
;
; MessageId: STATUS_SVHDX_ERROR_STORED
;
; MessageText:
;
; The proper error code with sense data was stored on server side.
;
STATUS_SVHDX_ERROR_STORED        EQU 0C05C0000h

;
; MessageId: STATUS_SVHDX_ERROR_NOT_AVAILABLE
;
; MessageText:
;
; The requested error data is not available on the server.
;
STATUS_SVHDX_ERROR_NOT_AVAILABLE EQU 0C05CFF00h

;
; MessageId: STATUS_SVHDX_UNIT_ATTENTION_AVAILABLE
;
; MessageText:
;
; Unit Attention data is available for the initiator to query.
;
STATUS_SVHDX_UNIT_ATTENTION_AVAILABLE EQU 0C05CFF01h

;
; MessageId: STATUS_SVHDX_UNIT_ATTENTION_CAPACITY_DATA_CHANGED
;
; MessageText:
;
; The data capacity of the device has changed, resulting in a Unit Attention condition.
;
STATUS_SVHDX_UNIT_ATTENTION_CAPACITY_DATA_CHANGED EQU 0C05CFF02h

;
; MessageId: STATUS_SVHDX_UNIT_ATTENTION_RESERVATIONS_PREEMPTED
;
; MessageText:
;
; A previous operation resulted in this initiator's reservations being preempted, resulting in a Unit Attention condition.
;
STATUS_SVHDX_UNIT_ATTENTION_RESERVATIONS_PREEMPTED EQU 0C05CFF03h

;
; MessageId: STATUS_SVHDX_UNIT_ATTENTION_RESERVATIONS_RELEASED
;
; MessageText:
;
; A previous operation resulted in this initiator's reservations being released, resulting in a Unit Attention condition.
;
STATUS_SVHDX_UNIT_ATTENTION_RESERVATIONS_RELEASED EQU 0C05CFF04h

;
; MessageId: STATUS_SVHDX_UNIT_ATTENTION_REGISTRATIONS_PREEMPTED
;
; MessageText:
;
; A previous operation resulted in this initiator's registrations being preempted, resulting in a Unit Attention condition.
;
STATUS_SVHDX_UNIT_ATTENTION_REGISTRATIONS_PREEMPTED EQU 0C05CFF05h

;
; MessageId: STATUS_SVHDX_UNIT_ATTENTION_OPERATING_DEFINITION_CHANGED
;
; MessageText:
;
; The data storage format of the device has changed, resulting in a Unit Attention condition.
;
STATUS_SVHDX_UNIT_ATTENTION_OPERATING_DEFINITION_CHANGED EQU 0C05CFF06h

;
; MessageId: STATUS_SVHDX_RESERVATION_CONFLICT
;
; MessageText:
;
; The current initiator is not allowed to perform the SCSI command because of a reservation conflict.
;
STATUS_SVHDX_RESERVATION_CONFLICT EQU 0C05CFF07h

;
; MessageId: STATUS_SVHDX_WRONG_FILE_TYPE
;
; MessageText:
;
; Multiple virtual machines sharing a virtual hard disk is supported only on Fixed or Dynamic VHDX format virtual hard disks.
;
STATUS_SVHDX_WRONG_FILE_TYPE     EQU 0C05CFF08h

;
; MessageId: STATUS_SVHDX_VERSION_MISMATCH
;
; MessageText:
;
; The server version does not match the requested version.
;
STATUS_SVHDX_VERSION_MISMATCH    EQU 0C05CFF09h

;
; MessageId: STATUS_VHD_SHARED
;
; MessageText:
;
; The requested operation cannot be performed on the virtual disk as it is currently used in shared mode.
;
STATUS_VHD_SHARED                EQU 0C05CFF0Ah

;
; Map a WIN32 error value into an NTSTATUS
; Note: This assumes that WIN32 errors fall in the range -32k to 32k.
;

;__NTSTATUS_FROM_WIN32(x) ((NTSTATUS)(x) <= 0 ? ((NTSTATUS)(x)) : ((NTSTATUS) (((x) & 0x0000FFFF) | (FACILITY_NTWIN32 << 16) | ERROR_SEVERITY_ERROR)))
;__inline NTSTATUS_FROM_WIN32(long x) { return x <= 0 ? (NTSTATUS)x : (NTSTATUS) (((x) & 0x0000FFFF) | (FACILITY_NTWIN32 << 16) | ERROR_SEVERITY_ERROR);}
;NTSTATUS_FROM_WIN32(x) __NTSTATUS_FROM_WIN32(x)


ifndef _BUGCODES_
  _BUGCODES_ equ <>
  HARDWARE_PROFILE_UNDOCKED_STRING equ 40010001h
  HARDWARE_PROFILE_DOCKED_STRING equ 40010002h
  HARDWARE_PROFILE_UNKNOWN_STRING equ 40010003h
  WINDOWS_NT_BANNER equ 4000007Eh
  WINDOWS_NT_CSD_STRING equ 40000087h
  WINDOWS_NT_INFO_STRING equ 40000088h
  WINDOWS_NT_MP_STRING equ 40000089h
  THREAD_TERMINATE_HELD_MUTEX equ 4000008Ah
  WINDOWS_NT_INFO_STRING_PLURAL equ 4000009Dh
  WINDOWS_NT_RC_STRING equ 4000009Eh
  APC_INDEX_MISMATCH equ 00000001h
  DEVICE_QUEUE_NOT_BUSY equ 00000002h
  INVALID_AFFINITY_SET equ 00000003h
  INVALID_DATA_ACCESS_TRAP equ 00000004h
  INVALID_PROCESS_ATTACH_ATTEMPT equ 00000005h
  INVALID_PROCESS_DETACH_ATTEMPT equ 00000006h
  INVALID_SOFTWARE_INTERRUPT equ 00000007h
  IRQL_NOT_DISPATCH_LEVEL equ 00000008h
  IRQL_NOT_GREATER_OR_EQUAL equ 00000009h
  IRQL_NOT_LESS_OR_EQUAL equ 0000000Ah
  NO_EXCEPTION_HANDLING_SUPPORT equ 0000000Bh
  MAXIMUM_WAIT_OBJECTS_EXCEEDED equ 0000000Ch
  MUTEX_LEVEL_NUMBER_VIOLATION equ 0000000Dh
  NO_USER_MODE_CONTEXT equ 0000000Eh
  SPIN_LOCK_ALREADY_OWNED equ 0000000Fh
  SPIN_LOCK_NOT_OWNED equ 00000010h
  THREAD_NOT_MUTEX_OWNER equ 00000011h
  TRAP_CAUSE_UNKNOWN equ 00000012h
  EMPTY_THREAD_REAPER_LIST equ 00000013h
  CREATE_DELETE_LOCK_NOT_LOCKED equ 00000014h
  LAST_CHANCE_CALLED_FROM_KMODE equ 00000015h
  CID_HANDLE_CREATION equ 00000016h
  CID_HANDLE_DELETION equ 00000017h
  REFERENCE_BY_POINTER equ 00000018h
  BAD_POOL_HEADER equ 00000019h
  MEMORY_MANAGEMENT equ 0000001Ah
  PFN_SHARE_COUNT equ 0000001Bh
  PFN_REFERENCE_COUNT equ 0000001Ch
  NO_SPIN_LOCK_AVAILABLE equ 0000001Dh
  KMODE_EXCEPTION_NOT_HANDLED equ 0000001Eh
  SHARED_RESOURCE_CONV_ERROR equ 0000001Fh
  KERNEL_APC_PENDING_DURING_EXIT equ 00000020h
  QUOTA_UNDERFLOW equ 00000021h
  FILE_SYSTEM equ 00000022h
  FAT_FILE_SYSTEM equ 00000023h
  NTFS_FILE_SYSTEM equ 00000024h
  NPFS_FILE_SYSTEM equ 00000025h
  CDFS_FILE_SYSTEM equ 00000026h
  RDR_FILE_SYSTEM equ 00000027h
  CORRUPT_ACCESS_TOKEN equ 00000028h
  SECURITY_SYSTEM equ 00000029h
  INCONSISTENT_IRP equ 0000002Ah
  PANIC_STACK_SWITCH equ 0000002Bh
  PORT_DRIVER_INTERNAL equ 0000002Ch
  SCSI_DISK_DRIVER_INTERNAL equ 0000002Dh
  DATA_BUS_ERROR equ 0000002Eh
  INSTRUCTION_BUS_ERROR equ 0000002Fh
  SET_OF_INVALID_CONTEXT equ 00000030h
  PHASE0_INITIALIZATION_FAILED equ 00000031h
  PHASE1_INITIALIZATION_FAILED equ 00000032h
  UNEXPECTED_INITIALIZATION_CALL equ 00000033h
  CACHE_MANAGER equ 00000034h
  NO_MORE_IRP_STACK_LOCATIONS equ 00000035h
  DEVICE_REFERENCE_COUNT_NOT_ZERO equ 00000036h
  FLOPPY_INTERNAL_ERROR equ 00000037h
  SERIAL_DRIVER_INTERNAL equ 00000038h
  SYSTEM_EXIT_OWNED_MUTEX equ 00000039h
  SYSTEM_UNWIND_PREVIOUS_USER equ 0000003Ah
  SYSTEM_SERVICE_EXCEPTION equ 0000003Bh
  INTERRUPT_UNWIND_ATTEMPTED equ 0000003Ch
  INTERRUPT_EXCEPTION_NOT_HANDLED equ 0000003Dh
  MULTIPROCESSOR_CONFIGURATION_NOT_SUPPORTED equ 0000003Eh
  NO_MORE_SYSTEM_PTES equ 0000003Fh
  TARGET_MDL_TOO_SMALL equ 00000040h
  MUST_SUCCEED_POOL_EMPTY equ 00000041h
  ATDISK_DRIVER_INTERNAL equ 00000042h
  NO_SUCH_PARTITION equ 00000043h
  MULTIPLE_IRP_COMPLETE_REQUESTS equ 00000044h
  INSUFFICIENT_SYSTEM_MAP_REGS equ 00000045h
  DEREF_UNKNOWN_LOGON_SESSION equ 00000046h
  REF_UNKNOWN_LOGON_SESSION equ 00000047h
  CANCEL_STATE_IN_COMPLETED_IRP equ 00000048h
  PAGE_FAULT_WITH_INTERRUPTS_OFF equ 00000049h
  IRQL_GT_ZERO_AT_SYSTEM_SERVICE equ 0000004Ah
  STREAMS_INTERNAL_ERROR equ 0000004Bh
  FATAL_UNHANDLED_HARD_ERROR equ 0000004Ch
  NO_PAGES_AVAILABLE equ 0000004Dh
  PFN_LIST_CORRUPT equ 0000004Eh
  NDIS_INTERNAL_ERROR equ 0000004Fh
  PAGE_FAULT_IN_NONPAGED_AREA equ 00000050h
  PAGE_FAULT_IN_NONPAGED_AREA_M equ 10000050h
  REGISTRY_ERROR equ 00000051h
  MAILSLOT_FILE_SYSTEM equ 00000052h
  NO_BOOT_DEVICE equ 00000053h
  LM_SERVER_INTERNAL_ERROR equ 00000054h
  DATA_COHERENCY_EXCEPTION equ 00000055h
  INSTRUCTION_COHERENCY_EXCEPTION equ 00000056h
  XNS_INTERNAL_ERROR equ 00000057h
  VOLMGRX_INTERNAL_ERROR equ 00000058h
  PINBALL_FILE_SYSTEM equ 00000059h
  CRITICAL_SERVICE_FAILED equ 0000005Ah
  SET_ENV_VAR_FAILED equ 0000005Bh
  HAL_INITIALIZATION_FAILED equ 0000005Ch
  UNSUPPORTED_PROCESSOR equ 0000005Dh
  OBJECT_INITIALIZATION_FAILED equ 0000005Eh
  SECURITY_INITIALIZATION_FAILED equ 0000005Fh
  PROCESS_INITIALIZATION_FAILED equ 00000060h
  HAL1_INITIALIZATION_FAILED equ 00000061h
  OBJECT1_INITIALIZATION_FAILED equ 00000062h
  SECURITY1_INITIALIZATION_FAILED equ 00000063h
  SYMBOLIC_INITIALIZATION_FAILED equ 00000064h
  MEMORY1_INITIALIZATION_FAILED equ 00000065h
  CACHE_INITIALIZATION_FAILED equ 00000066h
  CONFIG_INITIALIZATION_FAILED equ 00000067h
  FILE_INITIALIZATION_FAILED equ 00000068h
  IO1_INITIALIZATION_FAILED equ 00000069h
  LPC_INITIALIZATION_FAILED equ 0000006Ah
  PROCESS1_INITIALIZATION_FAILED equ 0000006Bh
  REFMON_INITIALIZATION_FAILED equ 0000006Ch
  SESSION1_INITIALIZATION_FAILED equ 0000006Dh
  SESSION2_INITIALIZATION_FAILED equ 0000006Eh
  SESSION3_INITIALIZATION_FAILED equ 0000006Fh
  SESSION4_INITIALIZATION_FAILED equ 00000070h
  SESSION5_INITIALIZATION_FAILED equ 00000071h
  ASSIGN_DRIVE_LETTERS_FAILED equ 00000072h
  CONFIG_LIST_FAILED equ 00000073h
  BAD_SYSTEM_CONFIG_INFO equ 00000074h
  CANNOT_WRITE_CONFIGURATION equ 00000075h
  PROCESS_HAS_LOCKED_PAGES equ 00000076h
  KERNEL_STACK_INPAGE_ERROR equ 00000077h
  PHASE0_EXCEPTION equ 00000078h
  MISMATCHED_HAL equ 00000079h
  KERNEL_DATA_INPAGE_ERROR equ 0000007Ah
  INACCESSIBLE_BOOT_DEVICE equ 0000007Bh
  BUGCODE_NDIS_DRIVER equ 0000007Ch
  INSTALL_MORE_MEMORY equ 0000007Dh
  SYSTEM_THREAD_EXCEPTION_NOT_HANDLED equ 0000007Eh
  SYSTEM_THREAD_EXCEPTION_NOT_HANDLED_M equ 1000007Eh
  UNEXPECTED_KERNEL_MODE_TRAP equ 0000007Fh
  UNEXPECTED_KERNEL_MODE_TRAP_M equ 1000007Fh
  NMI_HARDWARE_FAILURE equ 00000080h
  SPIN_LOCK_INIT_FAILURE equ 00000081h
  DFS_FILE_SYSTEM equ 00000082h
  OFS_FILE_SYSTEM equ 00000083h
  RECOM_DRIVER equ 00000084h
  SETUP_FAILURE equ 00000085h
  AUDIT_FAILURE equ 00000086h
  MBR_CHECKSUM_MISMATCH equ 0000008Bh
  KERNEL_MODE_EXCEPTION_NOT_HANDLED equ 0000008Eh
  KERNEL_MODE_EXCEPTION_NOT_HANDLED_M equ 1000008Eh
  PP0_INITIALIZATION_FAILED equ 0000008Fh
  PP1_INITIALIZATION_FAILED equ 00000090h
  WIN32K_INIT_OR_RIT_FAILURE equ 00000091h
  UP_DRIVER_ON_MP_SYSTEM equ 00000092h
  INVALID_KERNEL_HANDLE equ 00000093h
  KERNEL_STACK_LOCKED_AT_EXIT equ 00000094h
  PNP_INTERNAL_ERROR equ 00000095h
  INVALID_WORK_QUEUE_ITEM equ 00000096h
  BOUND_IMAGE_UNSUPPORTED equ 00000097h
  END_OF_NT_EVALUATION_PERIOD equ 00000098h
  INVALID_REGION_OR_SEGMENT equ 00000099h
  SYSTEM_LICENSE_VIOLATION equ 0000009Ah
  UDFS_FILE_SYSTEM equ 0000009Bh
  MACHINE_CHECK_EXCEPTION equ 0000009Ch
  USER_MODE_HEALTH_MONITOR equ 0000009Eh
  DRIVER_POWER_STATE_FAILURE equ 0000009Fh
  INTERNAL_POWER_ERROR equ 000000A0h
  PCI_BUS_DRIVER_INTERNAL equ 000000A1h
  MEMORY_IMAGE_CORRUPT equ 000000A2h
  ACPI_DRIVER_INTERNAL equ 000000A3h
  CNSS_FILE_SYSTEM_FILTER equ 000000A4h
  ACPI_BIOS_ERROR equ 000000A5h
  FP_EMULATION_ERROR equ 000000A6h
  BAD_EXHANDLE equ 000000A7h
  BOOTING_IN_SAFEMODE_MINIMAL equ 000000A8h
  BOOTING_IN_SAFEMODE_NETWORK equ 000000A9h
  BOOTING_IN_SAFEMODE_DSREPAIR equ 000000AAh
  SESSION_HAS_VALID_POOL_ON_EXIT equ 000000ABh
  HAL_MEMORY_ALLOCATION equ 000000ACh
  VIDEO_DRIVER_DEBUG_REPORT_REQUEST equ 400000ADh
  BGI_DETECTED_VIOLATION equ 000000B1h
  VIDEO_DRIVER_INIT_FAILURE equ 000000B4h
  BOOTLOG_LOADED equ 000000B5h
  BOOTLOG_NOT_LOADED equ 000000B6h
  BOOTLOG_ENABLED equ 000000B7h
  ATTEMPTED_SWITCH_FROM_DPC equ 000000B8h
  CHIPSET_DETECTED_ERROR equ 000000B9h
  SESSION_HAS_VALID_VIEWS_ON_EXIT equ 000000BAh
  NETWORK_BOOT_INITIALIZATION_FAILED equ 000000BBh
  NETWORK_BOOT_DUPLICATE_ADDRESS equ 000000BCh
  INVALID_HIBERNATED_STATE equ 000000BDh
  ATTEMPTED_WRITE_TO_READONLY_MEMORY equ 000000BEh
  MUTEX_ALREADY_OWNED equ 000000BFh
  PCI_CONFIG_SPACE_ACCESS_FAILURE equ 000000C0h
  SPECIAL_POOL_DETECTED_MEMORY_CORRUPTION equ 000000C1h
  BAD_POOL_CALLER equ 000000C2h
  SYSTEM_IMAGE_BAD_SIGNATURE equ 000000C3h
  DRIVER_VERIFIER_DETECTED_VIOLATION equ 000000C4h
  DRIVER_CORRUPTED_EXPOOL equ 000000C5h
  DRIVER_CAUGHT_MODIFYING_FREED_POOL equ 000000C6h
  TIMER_OR_DPC_INVALID equ 000000C7h
  IRQL_UNEXPECTED_VALUE equ 000000C8h
  DRIVER_VERIFIER_IOMANAGER_VIOLATION equ 000000C9h
  PNP_DETECTED_FATAL_ERROR equ 000000CAh
  DRIVER_LEFT_LOCKED_PAGES_IN_PROCESS equ 000000CBh
  PAGE_FAULT_IN_FREED_SPECIAL_POOL equ 000000CCh
  PAGE_FAULT_BEYOND_END_OF_ALLOCATION equ 000000CDh
  DRIVER_UNLOADED_WITHOUT_CANCELLING_PENDING_OPERATIONS equ 000000CEh
  TERMINAL_SERVER_DRIVER_MADE_INCORRECT_MEMORY_REFERENCE equ 000000CFh
  DRIVER_CORRUPTED_MMPOOL equ 000000D0h
  DRIVER_IRQL_NOT_LESS_OR_EQUAL equ 000000D1h
  BUGCODE_ID_DRIVER equ 000000D2h
  DRIVER_PORTION_MUST_BE_NONPAGED equ 000000D3h
  SYSTEM_SCAN_AT_RAISED_IRQL_CAUGHT_IMPROPER_DRIVER_UNLOAD equ 000000D4h
  DRIVER_PAGE_FAULT_IN_FREED_SPECIAL_POOL equ 000000D5h
  DRIVER_PAGE_FAULT_BEYOND_END_OF_ALLOCATION equ 000000D6h
  DRIVER_PAGE_FAULT_BEYOND_END_OF_ALLOCATION_M equ 100000D6h
  DRIVER_UNMAPPING_INVALID_VIEW equ 000000D7h
  DRIVER_USED_EXCESSIVE_PTES equ 000000D8h
  LOCKED_PAGES_TRACKER_CORRUPTION equ 000000D9h
  SYSTEM_PTE_MISUSE equ 000000DAh
  DRIVER_CORRUPTED_SYSPTES equ 000000DBh
  DRIVER_INVALID_STACK_ACCESS equ 000000DCh
  POOL_CORRUPTION_IN_FILE_AREA equ 000000DEh
  IMPERSONATING_WORKER_THREAD equ 000000DFh
  ACPI_BIOS_FATAL_ERROR equ 000000E0h
  WORKER_THREAD_RETURNED_AT_BAD_IRQL equ 000000E1h
  MANUALLY_INITIATED_CRASH equ 000000E2h
  RESOURCE_NOT_OWNED equ 000000E3h
  WORKER_INVALID equ 000000E4h
  POWER_FAILURE_SIMULATE equ 000000E5h
  DRIVER_VERIFIER_DMA_VIOLATION equ 000000E6h
  INVALID_FLOATING_POINT_STATE equ 000000E7h
  INVALID_CANCEL_OF_FILE_OPEN equ 000000E8h
  ACTIVE_EX_WORKER_THREAD_TERMINATION equ 000000E9h
  THREAD_STUCK_IN_DEVICE_DRIVER equ 000000EAh
  THREAD_STUCK_IN_DEVICE_DRIVER_M equ 100000EAh
  DIRTY_MAPPED_PAGES_CONGESTION equ 000000EBh
  SESSION_HAS_VALID_SPECIAL_POOL_ON_EXIT equ 000000ECh
  UNMOUNTABLE_BOOT_VOLUME equ 000000EDh
  CRITICAL_PROCESS_DIED equ 000000EFh
  SCSI_VERIFIER_DETECTED_VIOLATION equ 000000F1h
  HARDWARE_INTERRUPT_STORM equ 000000F2h
  DISORDERLY_SHUTDOWN equ 000000F3h
  CRITICAL_OBJECT_TERMINATION equ 000000F4h
  FLTMGR_FILE_SYSTEM equ 000000F5h
  PCI_VERIFIER_DETECTED_VIOLATION equ 000000F6h
  DRIVER_OVERRAN_STACK_BUFFER equ 000000F7h
  RAMDISK_BOOT_INITIALIZATION_FAILED equ 000000F8h
  DRIVER_RETURNED_STATUS_REPARSE_FOR_VOLUME_OPEN equ 000000F9h
  HTTP_DRIVER_CORRUPTED equ 000000FAh
  RECURSIVE_MACHINE_CHECK equ 000000FBh
  ATTEMPTED_EXECUTE_OF_NOEXECUTE_MEMORY equ 000000FCh
  DIRTY_NOWRITE_PAGES_CONGESTION equ 000000FDh
  BUGCODE_USB_DRIVER equ 000000FEh
  BC_BLUETOOTH_VERIFIER_FAULT equ 00000BFEh
  BC_BTHMINI_VERIFIER_FAULT equ 00000BFFh
  RESERVE_QUEUE_OVERFLOW equ 000000FFh
  LOADER_BLOCK_MISMATCH equ 00000100h
  CLOCK_WATCHDOG_TIMEOUT equ 00000101h
  DPC_WATCHDOG_TIMEOUT equ 00000102h
  MUP_FILE_SYSTEM equ 00000103h
  AGP_INVALID_ACCESS equ 00000104h
  AGP_GART_CORRUPTION equ 00000105h
  AGP_ILLEGALLY_REPROGRAMMED equ 00000106h
  KERNEL_EXPAND_STACK_ACTIVE equ 00000107h
  THIRD_PARTY_FILE_SYSTEM_FAILURE equ 00000108h
  CRITICAL_STRUCTURE_CORRUPTION equ 00000109h
  APP_TAGGING_INITIALIZATION_FAILED equ 0000010Ah
  DFSC_FILE_SYSTEM equ 0000010Bh
  FSRTL_EXTRA_CREATE_PARAMETER_VIOLATION equ 0000010Ch
  WDF_VIOLATION equ 0000010Dh
  VIDEO_MEMORY_MANAGEMENT_INTERNAL equ 0000010Eh
  DRIVER_INVALID_CRUNTIME_PARAMETER equ 00000110h
  RECURSIVE_NMI equ 00000111h
  MSRPC_STATE_VIOLATION equ 00000112h
  VIDEO_DXGKRNL_FATAL_ERROR equ 00000113h
  VIDEO_SHADOW_DRIVER_FATAL_ERROR equ 00000114h
  AGP_INTERNAL equ 00000115h
  VIDEO_TDR_FAILURE equ 00000116h
  VIDEO_TDR_TIMEOUT_DETECTED equ 00000117h
  NTHV_GUEST_ERROR equ 00000118h
  VIDEO_SCHEDULER_INTERNAL_ERROR equ 00000119h
  EM_INITIALIZATION_ERROR equ 0000011Ah
  DRIVER_RETURNED_HOLDING_CANCEL_LOCK equ 0000011Bh
  ATTEMPTED_WRITE_TO_CM_PROTECTED_STORAGE equ 0000011Ch
  EVENT_TRACING_FATAL_ERROR equ 0000011Dh
  TOO_MANY_RECURSIVE_FAULTS equ 0000011Eh
  INVALID_DRIVER_HANDLE equ 0000011Fh
  BITLOCKER_FATAL_ERROR equ 00000120h
  DRIVER_VIOLATION equ 00000121h
  WHEA_INTERNAL_ERROR equ 00000122h
  CRYPTO_SELF_TEST_FAILURE equ 00000123h
  WHEA_UNCORRECTABLE_ERROR equ 00000124h
  NMR_INVALID_STATE equ 00000125h
  NETIO_INVALID_POOL_CALLER equ 00000126h
  PAGE_NOT_ZERO equ 00000127h
  WORKER_THREAD_RETURNED_WITH_BAD_IO_PRIORITY equ 00000128h
  WORKER_THREAD_RETURNED_WITH_BAD_PAGING_IO_PRIORITY equ 00000129h
  MUI_NO_VALID_SYSTEM_LANGUAGE equ 0000012Ah
  FAULTY_HARDWARE_CORRUPTED_PAGE equ 0000012Bh
  EXFAT_FILE_SYSTEM equ 0000012Ch
  VOLSNAP_OVERLAPPED_TABLE_ACCESS equ 0000012Dh
  INVALID_MDL_RANGE equ 0000012Eh
  VHD_BOOT_INITIALIZATION_FAILED equ 0000012Fh
  DYNAMIC_ADD_PROCESSOR_MISMATCH equ 00000130h
  INVALID_EXTENDED_PROCESSOR_STATE equ 00000131h
  RESOURCE_OWNER_POINTER_INVALID equ 00000132h
  DPC_WATCHDOG_VIOLATION equ 00000133h
  DRIVE_EXTENDER equ 00000134h
  REGISTRY_FILTER_DRIVER_EXCEPTION equ 00000135h
  VHD_BOOT_HOST_VOLUME_NOT_ENOUGH_SPACE equ 00000136h
  WIN32K_HANDLE_MANAGER equ 00000137h
  GPIO_CONTROLLER_DRIVER_ERROR equ 00000138h
  KERNEL_SECURITY_CHECK_FAILURE equ 00000139h
  KERNEL_MODE_HEAP_CORRUPTION equ 0000013Ah
  PASSIVE_INTERRUPT_ERROR equ 0000013Bh
  INVALID_IO_BOOST_STATE equ 0000013Ch
  CRITICAL_INITIALIZATION_FAILURE equ 0000013Dh
  STORAGE_DEVICE_ABNORMALITY_DETECTED equ 00000140h
  VIDEO_ENGINE_TIMEOUT_DETECTED equ 00000141h
  VIDEO_TDR_APPLICATION_BLOCKED equ 00000142h
  PROCESSOR_DRIVER_INTERNAL equ 00000143h
  BUGCODE_USB3_DRIVER equ 00000144h
  SECURE_BOOT_VIOLATION equ 00000145h
  NDIS_NET_BUFFER_LIST_INFO_ILLEGALLY_TRANSFERRED equ 00000146h
  ABNORMAL_RESET_DETECTED equ 00000147h
  IO_OBJECT_INVALID equ 00000148h
  REFS_FILE_SYSTEM equ 00000149h
  KERNEL_WMI_INTERNAL equ 0000014Ah
  SOC_SUBSYSTEM_FAILURE equ 0000014Bh
  FATAL_ABNORMAL_RESET_ERROR equ 0000014Ch
  EXCEPTION_SCOPE_INVALID equ 0000014Dh
  SOC_CRITICAL_DEVICE_REMOVED equ 0000014Eh
  PDC_WATCHDOG_TIMEOUT equ 0000014Fh
  TCPIP_AOAC_NIC_ACTIVE_REFERENCE_LEAK equ 00000150h
  UNSUPPORTED_INSTRUCTION_MODE equ 00000151h
  INVALID_PUSH_LOCK_FLAGS equ 00000152h
  KERNEL_LOCK_ENTRY_LEAKED_ON_THREAD_TERMINATION equ 00000153h
  UNEXPECTED_STORE_EXCEPTION equ 00000154h
  OS_DATA_TAMPERING equ 00000155h
  WINSOCK_DETECTED_HUNG_CLOSESOCKET_LIVEDUMP equ 00000156h
  KERNEL_THREAD_PRIORITY_FLOOR_VIOLATION equ 00000157h
  ILLEGAL_IOMMU_PAGE_FAULT equ 00000158h
  HAL_ILLEGAL_IOMMU_PAGE_FAULT equ 00000159h
  SDBUS_INTERNAL_ERROR equ 0000015Ah
  WORKER_THREAD_RETURNED_WITH_SYSTEM_PAGE_PRIORITY_ACTIVE equ 0000015Bh
  PDC_WATCHDOG_TIMEOUT_LIVEDUMP equ 0000015Ch
  SOC_SUBSYSTEM_FAILURE_LIVEDUMP equ 0000015Dh
  BUGCODE_NDIS_DRIVER_LIVE_DUMP equ 0000015Eh
  CONNECTED_STANDBY_WATCHDOG_TIMEOUT_LIVEDUMP equ 0000015Fh
  WIN32K_ATOMIC_CHECK_FAILURE equ 00000160h
  LIVE_SYSTEM_DUMP equ 00000161h
  KERNEL_AUTO_BOOST_INVALID_LOCK_RELEASE equ 00000162h
  WORKER_THREAD_TEST_CONDITION equ 00000163h
  CLUSTER_CSV_STATUS_IO_TIMEOUT_LIVEDUMP equ 00000164h
  CLUSTER_CSV_SNAPSHOT_DEVICE_INFO_TIMEOUT_LIVEDUMP equ 00000166h
  CLUSTER_CSV_STATE_TRANSITION_TIMEOUT_LIVEDUMP equ 00000167h
  CLUSTER_CSV_VOLUME_ARRIVAL_LIVEDUMP equ 00000168h
  CLUSTER_CSV_VOLUME_REMOVAL_LIVEDUMP equ 00000169h
  CLUSTER_CSV_STATE_TRANSITION_INTERVAL_TIMEOUT_LIVEDUMP equ 00000174h
  WIN32K_PRERELEASE_FREE_ASSERT equ 00000187h
  XBOX_360_SYSTEM_CRASH equ 00000360h
  XBOX_360_SYSTEM_CRASH_RESERVED equ 00000420h
  HYPERVISOR_ERROR equ 00020001h
  WINLOGON_FATAL_ERROR equ 0C000021Ah
  MANUALLY_INITIATED_CRASH1 equ 0DEADDEADh
endif
