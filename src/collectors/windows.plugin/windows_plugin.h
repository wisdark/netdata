// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef NETDATA_WINDOWS_PLUGIN_H
#define NETDATA_WINDOWS_PLUGIN_H

#include "daemon/common.h"

#define PLUGIN_WINDOWS_NAME "windows.plugin"

// https://learn.microsoft.com/es-es/windows/win32/sysinfo/kernel-objects?redirectedfrom=MSDN
// 2^24
#define WINDOWS_MAX_KERNEL_OBJECT 16777216

void *win_plugin_main(void *ptr);

extern char windows_shared_buffer[8192];

int do_GetSystemUptime(int update_every, usec_t dt);
int do_GetSystemRAM(int update_every, usec_t dt);
int do_GetSystemCPU(int update_every, usec_t dt);
int do_PerflibStorage(int update_every, usec_t dt);
int do_PerflibNetwork(int update_every, usec_t dt);
int do_PerflibProcesses(int update_every, usec_t dt);
int do_PerflibProcessor(int update_every, usec_t dt);
int do_PerflibMemory(int update_every, usec_t dt);
int do_PerflibObjects(int update_every, usec_t dt);
int do_PerflibThermalZone(int update_every, usec_t dt);
int do_PerflibWebService(int update_every, usec_t dt);
int do_PerflibMSSQL(int update_every, usec_t dt);
int do_PerflibNetFramework(int update_every, usec_t dt);

enum PERFLIB_PRIO {
    PRIO_WEBSITE_IIS_REQUESTS_RATE = 21000, // PRIO selected, because APPS is using 20YYY
    PRIO_WEBSITE_IIS_REQUESTS_BY_TYPE_RATE,
    PRIO_WEBSITE_IIS_TRAFFIC,
    PRIO_WEBSITE_IIS_FTP_FILE_TRANSFER_RATE,
    PRIO_WEBSITE_IIS_ACTIVE_CONNECTIONS_COUNT,
    PRIO_WEBSITE_IIS_CONNECTIONS_ATTEMP,
    PRIO_WEBSITE_IIS_USERS,
    PRIO_WEBSITE_IIS_ISAPI_EXT_REQUEST_COUNT,
    PRIO_WEBSITE_IIS_ISAPI_EXT_REQUEST_RATE,
    PRIO_WEBSITE_IIS_ERRORS_RATE,
    PRIO_WEBSITE_IIS_LOGON_ATTEMPTS,
    PRIO_WEBSITE_IIS_UPTIME,

    PRIO_MSSQL_USER_CONNECTIONS,

    PRIO_MSSQL_DATABASE_TRANSACTIONS,
    PRIO_MSSQL_DATABASE_ACTIVE_TRANSACTIONS,
    PRIO_MSSQL_DATABASE_WRITE_TRANSACTIONS,
    PRIO_MSSQL_DATABASE_BACKUP_RESTORE_OPERATIONS,
    PRIO_MSSQL_DATABASE_LOG_FLUSHES,
    PRIO_MSSQL_DATABASE_LOG_FLUSHED,

    PRIO_MSSQL_DATABASE_DATA_FILE_SIZE,

    PRIO_MSSQL_STATS_BATCH_REQUEST,
    PRIO_MSSQL_STATS_COMPILATIONS,
    PRIO_MSSQL_STATS_RECOMPILATIONS,
    PRIO_MSSQL_STATS_AUTO_PARAMETRIZATION,
    PRIO_MSSQL_STATS_SAFE_AUTO_PARAMETRIZATION,

    PRIO_MSSQL_BLOCKED_PROCESSES,

    PRIO_MSSQL_BUFF_CACHE_HIT_RATIO,
    PRIO_MSSQL_BUFF_MAN_IOPS,
    PRIO_MSSQL_BUFF_CHECKPOINT_PAGES,
    PRIO_MSSQL_BUFF_METHODS_PAGE_SPLIT,
    PRIO_MSSQL_BUFF_PAGE_LIFE_EXPECTANCY,

    PRIO_MSSQL_MEMMGR_CONNECTION_MEMORY_BYTES,
    PRIO_MSSQL_MEMMGR_TOTAL_SERVER,
    PRIO_MSSQL_MEMMGR_EXTERNAL_BENEFIT_OF_MEMORY,
    PRIO_MSSQL_MEMMGR_PENDING_MEMORY_GRANTS,

    PRIO_MSSQL_LOCKS_WAIT,
    PRIO_MSSQL_LOCKS_DEADLOCK,

    PRIO_MSSQL_SQL_ERRORS,

    PRIO_NETFRAMEWORK_CLR_EXCEPTION_THROWN,
    PRIO_NETFRAMEWORK_CLR_EXCEPTION_FILTERS,
    PRIO_NETFRAMEWORK_CLR_EXCEPTION_FINALLYS,
    PRIO_NETFRAMEWORK_CLR_EXCEPTION_THROW_TO_CATCH_DEPTH,

    PRIO_NETFRAMEWORK_CLR_INTEROP_CCW,
    PRIO_NETFRAMEWORK_CLR_INTEROP_MARSHALLING,
    PRIO_NETFRAMEWORK_CLR_INTEROP_STUBS_CREATED,

    PRIO_NETFRAMEWORK_CLR_JIT_METHODS,
    PRIO_NETFRAMEWORK_CLR_JIT_TIME,
    PRIO_NETFRAMEWORK_CLR_JIT_STANDARD_FAILURES,
    PRIO_NETFRAMEWORK_CLR_JIT_IL_BYTES,

    PRIO_NETFRAMEWORK_CLR_LOADING_HEAP_SIZE,
    PRIO_NETFRAMEWORK_CLR_LOADING_APP_DOMAINS_LOADED,
    PRIO_NETFRAMEWORK_CLR_LOADING_APP_DOMAINS_UNLOADED,
    PRIO_NETFRAMEWORK_CLR_LOADING_ASSEMBLIES_LOADED,
    PRIO_NETFRAMEWORK_CLR_LOADING_CLASSES_LOADED,
    PRIO_NETFRAMEWORK_CLR_LOADING_CLASS_LOAD_FAILURE
};

int do_PerflibHyperV(int update_every, usec_t dt);

#endif //NETDATA_WINDOWS_PLUGIN_H