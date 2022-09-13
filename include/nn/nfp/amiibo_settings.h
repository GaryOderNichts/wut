#pragma once
#include <wut.h>
#include <nn/nfp/nfp_cpp.h>
#include <sysapp/args.h>

/**
 * \defgroup nn_nfp Amiibo Settings
 * \ingroup nn_nfp
 * Amiibo Settings applet related functionality (see nn::nfp)
 * @{
 */

#ifdef __cplusplus

namespace nn {

namespace nfp {

struct AmiiboSettingsArgsIn
{
    uint32_t mode;
    TagInfo tag_info;
    bool is_registered;
    uint8_t padding[3];
    RegisterInfo register_info;
    CommonInfo common_info;
    uint8_t reserved[0x20];
};
WUT_CHECK_SIZE(AmiiboSettingsArgsIn, 0x164);

struct AmiiboSettingsArgs
{
    SYSStandardArgs standardArg;
    AmiiboSettingsArgsIn argsIn;
};
WUT_CHECK_SIZE(AmiiboSettingsArgs, 0x174);

struct AmiiboSettingsResult
{
    int32_t result;
    TagInfo tag_info;
    RegisterInfo register_info;
    CommonInfo common_info;
    uint8_t reserved[0x20];
};
WUT_CHECK_SIZE(AmiiboSettingsResult, 0x160);

} //namespace nfp

} //namespace nn

#endif

/** @} */
