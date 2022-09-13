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

typedef uint32_t SYSArgID;
typedef uint32_t SYSArgType;

typedef struct SYSArgDataBlock SYSArgDataBlock;
typedef struct SYSCallerInfo SYSCallerInfo;
typedef struct SYSDeserializeArg SYSDeserializeArg;
typedef struct SYSStandardArgs SYSStandardArgs;
typedef struct SYSStandardArgsIn SYSStandardArgsIn;
typedef struct SYSStandardArgsOut SYSStandardArgsOut;

typedef void (*SYSDeserializeCallback)(SYSDeserializeArg *arg, void *userptr);

typedef enum SYSArgIDEnum
{
   SYS_ARG_ID_ANCHOR    = 0x64,
   SYS_ARG_ID_RESULT    = 0x65,
   SYS_ARG_ID_URL       = 0xc8,
   SYS_ARG_ID_MIV_DATA  = 0x12c,
   SYS_ARG_ID_JOIN_PID  = 0x190,
} SYSArgIDEnum;

typedef enum SYSArgTypeEnum
{
   SYS_ARG_TYPE_UINT32 = 0x1,
   SYS_ARG_TYPE_UINT64 = 0x2,
   SYS_ARG_TYPE_DATA   = 0x3,
   SYS_ARG_TYPE_STRING = 0x4,
} SYSArgTypeEnum;

struct SYSArgDataBlock
{
   SYSArgID id;
   SYSArgType type;
   union 
   {
      uint32_t uint32;
      uint64_t uint64;
      struct 
      {
         void *ptr;
         uint32_t size;
      } data;
      struct 
      {
         const char *ptr;
         uint32_t size;
      } string;
   };
};
WUT_CHECK_SIZE(SYSArgDataBlock, 0x10);

struct SYSCallerInfo
{
   uint32_t upid;
   WUT_PADDING_BYTES(0x4);
   uint64_t titleID;
};
WUT_CHECK_SIZE(SYSCallerInfo, 0x10);

struct SYSDeserializeArg
{
   const char *argName;
   uint32_t size;
   void *data;
};
WUT_CHECK_SIZE(SYSDeserializeArg, 0xC);

struct SYSStandardArgs
{
   void *anchorData;
   uint32_t anchorSize;
   void *resultData;
   uint32_t resultSize;
};
WUT_CHECK_SIZE(SYSStandardArgs, 0x10);

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
                           SYSStandardArgs *standardArg);

int32_t
SYSGetArguments(SYSArgDataBlock *args,
                SYSCallerInfo *callerInfo);

#ifdef __cplusplus
}
#endif

/** @} */
