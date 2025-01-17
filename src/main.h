#ifndef ZYPPERMAIN_H_
#define ZYPPERMAIN_H_

#include <libintl.h>

// ===== exit codes ======

#define ZYPPER_EXIT_OK                     0

// errors
#define ZYPPER_EXIT_ERR_BUG                1 // undetermined error
#define ZYPPER_EXIT_ERR_SYNTAX             2 // syntax error, e.g. zypper instal, zypper in --unknown option
#define ZYPPER_EXIT_ERR_INVALID_ARGS       3 // invalid arguments given, e.g. zypper source-add httttps://asdf.net
#define ZYPPER_EXIT_ERR_ZYPP               4 // error indicated from within libzypp, e.g. God = getZYpp() threw an exception
#define ZYPPER_EXIT_ERR_PRIVILEGES         5 // unsufficient privileges for the operation
#define ZYPPER_EXIT_NO_REPOS               6 // no repositories defined
#define ZYPPER_EXIT_ZYPP_LOCKED            7 // libzypp is locked, e.g. packagekit is running
#define ZYPPER_EXIT_ERR_COMMIT             8 // an error occurred during commit.

// info
#define ZYPPER_EXIT_INF_UPDATE_NEEDED      100 // update needed
#define ZYPPER_EXIT_INF_SEC_UPDATE_NEEDED  101 // security update needed
#define ZYPPER_EXIT_INF_REBOOT_NEEDED      102 // reboot needed after install/upgrade
#define ZYPPER_EXIT_INF_RESTART_NEEDED     103 // restart of package manager itself needed
#define ZYPPER_EXIT_INF_CAP_NOT_FOUND      104 // given capability not found (for install/remove)
#define ZYPPER_EXIT_ON_SIGNAL              105 // SIGINT or SIGTERM received	(HOW CAN THIS BE 'info'?)
#define ZYPPER_EXIT_INF_REPOS_SKIPPED      106 // some repos have been skipped due to refresh errors
#define ZYPPER_EXIT_INF_RPM_SCRIPT_FAILED  107 // some rpm %post configuration script failed

// undefine _, N_ and PL_ macros from libzypp
#ifdef _
#undef _
#endif
#define _(MSG) ::gettext(MSG)

#ifdef N_
#undef N_
#endif
#define N_(MSG) MSG

#ifdef PL_
#undef PL_
#endif
#define PL_(MSG1,MSG2,N) ::ngettext(MSG1,MSG2,N)

// libzypp logger settings
#define ZYPPER_LOG "/var/log/zypper.log"
#undef  ZYPP_BASE_LOGGER_LOGGROUP
#define ZYPP_BASE_LOGGER_LOGGROUP "zypper"

#endif /*ZYPPERMAIN_H_*/
