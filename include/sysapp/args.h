#pragma once
#include <wut.h>

/**
 * \defgroup sysapp_args SYSAPP Arguments
 * \ingroup sysapp
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SYSArg SYSArg;
typedef struct SYSDeserializeArg SYSDeserializeArg;
typedef struct SYSArgDataBlock SYSArgDataBlock;
typedef struct SYSStandardArg SYSStandardArg;
typedef struct SYSStandardArgsIn SYSStandardArgsIn;

typedef void (*SYSDeserializeCallback)(SYSDeserializeArg *arg, void *userptr);

struct SYSDeserializeArg
{
   const char *argName;
   uint32_t size;
   void *data;
};
WUT_CHECK_SIZE(SYSDeserializeArg, 0xC);

struct SYSArgDataBlock
{
   uint32_t unk0;
   uint32_t unk1;
   uint32_t size;
   void *data;
};
WUT_CHECK_SIZE(SYSArgDataBlock, 0x10);

struct SYSStandardArg
{
   uint32_t anchorSize;
   void *anchorData;
   uint32_t resultSize;
   void *resultData;
};
WUT_CHECK_SIZE(SYSStandardArg, 0x10);

struct SYSStandardArgsIn
{
   const char* argString;
   uint32_t size;
};
WUT_CHECK_SIZE(SYSStandardArgsIn, 0x8);

struct SYSStandardArgsOut
{
   const void* data;
   uint32_t size;
};
WUT_CHECK_SIZE(SYSStandardArgsOut, 0x8);

void
SYSClearSysArgs();

int32_t
_SYSSerializeStandardArgsIn(SYSStandardArgsIn* arg);

int32_t
SYSSerializeSysArgs(const char *argName,
                    const void *data,
                    uint32_t size);

int32_t
SYSDeserializeSysArgs(SYSDeserializeCallback callback,
                      void *userArg);

int32_t
_SYSDirectlyReturnToCaller(SYSStandardArgsOut *arg);

BOOL
_SYSDeserializeStandardArg(SYSDeserializeArg *deserializeArg,
                           SYSStandardArg *standardArg);

#ifdef __cplusplus
}
#endif

/** @} */
