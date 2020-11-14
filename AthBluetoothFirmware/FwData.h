//
//  FwData.h
//  AthBluetoothFirmware
//
//  Created by qcwap on 2020/8/12.
//

#ifndef FwData_h
#define FwData_h

#include <string.h>
#include <libkern/c++/OSData.h>

struct FwDesc {
    const char *name;
    const unsigned char *var;
    const unsigned int size;
};

#define IWL_FW(fw_name, fw_var, fw_size) \
    .name = fw_name, .var = fw_var, .size = fw_size


extern const struct FwDesc fwList[];
extern const int fwNumber;

static inline OSData *getFWDescByName(const char* name) {
    for (int i = 0; i < fwNumber; i++) {
        if (strcmp(fwList[i].name, name) == 0) {
            FwDesc desc = fwList[i];
            return OSData::withBytes(desc.var, desc.size);
        }
    }
    return NULL;
}

#endif /* FwData_h */
