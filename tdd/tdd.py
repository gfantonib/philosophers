#!/usr/bin/env python3

from validarg_dir.validarg import validarg
from storedata_dir.storedata import storedata
from initphilo_dir.initphilo import initphilo
from initfork_dir.initfork import initfork

exit_status = 0

print("validarg")
exit_status = validarg(exit_status)
print("\nstoredata")
exit_status = storedata(exit_status)
print("\ninitphilo")
exit_status = initphilo(exit_status)
print("\ninitfork")
exit_status = initfork(exit_status)

exit(exit_status)


