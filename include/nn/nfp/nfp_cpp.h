#pragma once
#include <wut.h>
#include <nn/result.h>
#include <nn/ffl/miidata.h>
#include <coreinit/event.h>

/**
 * \defgroup nn_nfp
 * \ingroup nn_nfp
 * Nintendo Figurine (amiibo) Platform library (see nn::nfp)
 * @{
 */

#ifdef __cplusplus

namespace nn {

namespace nfp {

enum ErrorDescription { // nn::Result::GetDescription
   INVALID_STATE           = 0x06400,
   INVALID_PARAM           = 0x03780,
   NO_REGISTER_INFO        = 0x10900,
   APP_AREA_TAGID_MISMATCH = 0x11d00,
   NO_BACKUPENTRY          = 0x0e580,
   INVALID_ALIGNMENT       = 0x03800,
   NO_BACKUP_SAVEDATA      = 0x38880,
   APP_AREA_ALREADY_EXISTS = 0x10e00,
   APP_AREA_ID_MISMATCH    = 0x11300,
   NO_APP_AREA             = 0x10400,
};

enum class NfpState : uint32_t
{
   Uninitialized  = 0,
   Initialized    = 1,
   Searching      = 2,
   Found          = 3,
   Removed        = 4,
   Mounted        = 5,
   Unknown6       = 6,
   MountedROM     = 7,
};

struct Date
{
   uint16_t year;
   uint8_t month;
   uint8_t day;
};
WUT_CHECK_SIZE(Date, 0x4);

struct WUT_PACKED ApplicationAreaCreateInfo
{
   uint32_t id;
   void* data;
   uint32_t size;
   //! reserved bytes, must be set to 0
   uint8_t reserved[0x30];
};
WUT_CHECK_SIZE(ApplicationAreaCreateInfo, 0x3C);

struct WUT_PACKED TagId
{
   uint8_t lenght;
   uint8_t id[10];
};
WUT_CHECK_SIZE(TagId, 0xB);

struct WUT_PACKED TagInfo
{
   TagId id;
   uint8_t reserved0[0x15]; // reserved
   uint8_t protocol;
   uint8_t tag_type;
   uint8_t reserved1[0x32]; // reserved
};
WUT_CHECK_SIZE(TagInfo, 0x54);

struct WUT_PACKED CommonInfo
{
   Date last_write_date;
   uint16_t write_counter;
   uint16_t game_character_id;
   uint8_t character_variant;
   uint8_t series;
   uint16_t model_number;
   uint8_t figure_type;
   uint8_t unk;
   uint16_t application_area_size;
   uint8_t reserved[0x30]; // reserved
};
WUT_CHECK_SIZE(CommonInfo, 0x40);

struct WUT_PACKED RegisterInfo
{
   FFLStoreData mii;
   uint16_t amiibo_name[11];
   uint8_t flags;
   uint8_t country_code;
   Date first_write_date;
   uint8_t reserved[0x2c]; // reserved
};
WUT_CHECK_SIZE(RegisterInfo, 0xA8);

struct WUT_PACKED ReadOnlyInfo
{
   uint16_t game_character_id;
   uint8_t character_variant;
   uint8_t series;
   uint16_t model_number;
   uint8_t figure_type;
   uint8_t reserved[0x2f]; // reserved
};
WUT_CHECK_SIZE(ReadOnlyInfo, 0x36);

// seems to be the same as ReadOnlyInfo
// maybe left over from an older library version?
using RomInfo = ReadOnlyInfo;
WUT_CHECK_SIZE(RomInfo, 0x36);

struct WUT_PACKED RegisterInfoSet
{
   FFLStoreData mii;
   uint16_t amiibo_name[11];
   uint8_t flags;
   //! reserved bytes, must be 0
   uint8_t reserved[0x2d];
};
WUT_CHECK_SIZE(RegisterInfoSet, 0xA4);

struct WUT_PACKED AdminInfo
{
   uint64_t titleId;
   uint32_t appAreaId;
   uint16_t updateCount;
   uint8_t flags;
   uint8_t version;
   uint8_t platform;
   uint8_t reserved[0x2f]; // reserved
};
WUT_CHECK_SIZE(AdminInfo, 0x40);

NfpState
GetNfpState()
   asm("GetNfpState__Q2_2nn3nfpFv");

nn::Result
Initialize()
   asm("Initialize__Q2_2nn3nfpFv");

nn::Result
Finalize()
   asm("Finalize__Q2_2nn3nfpFv");

nn::Result
AntennaCheck()
   asm("AntennaCheck__Q2_2nn3nfpFv");

nn::Result
SetActivateEvent(OSEvent* event)
   asm("SetActivateEvent__Q2_2nn3nfpFP7OSEvent");

nn::Result
SetDeactivateEvent(OSEvent* event)
   asm("SetDeactivateEvent__Q2_2nn3nfpFP7OSEvent");

nn::Result
StartDetection()
   asm("StartDetection__Q2_2nn3nfpFv");

nn::Result
StopDetection(void)
   asm("StopDetection__Q2_2nn3nfpFv");

nn::Result
Mount()
   asm("Mount__Q2_2nn3nfpFv");

nn::Result
MountReadOnly()
   asm("MountReadOnly__Q2_2nn3nfpFv");

nn::Result
MountRom()
   asm("MountRom__Q2_2nn3nfpFv");

nn::Result
Flush()
   asm("Flush__Q2_2nn3nfpFv");

nn::Result
Unmount(void)
   asm("Unmount__Q2_2nn3nfpFv");

bool
IsExistApplicationArea()
   asm("IsExistApplicationArea__Q2_2nn3nfpFv");

nn::Result
InitializeCreateInfo(ApplicationAreaCreateInfo* info)
   asm("InitializeCreateInfo__Q2_2nn3nfpFPQ3_2nn3nfp25ApplicationAreaCreateInfo");

nn::Result
CreateApplicationArea(ApplicationAreaCreateInfo const& createInfo)
   asm("CreateApplicationArea__Q2_2nn3nfpFRCQ3_2nn3nfp25ApplicationAreaCreateInfo");

nn::Result
OpenApplicationArea(uint32_t id)
   asm("OpenApplicationArea__Q2_2nn3nfpFUi");

nn::Result
DeleteApplicationArea()
   asm("DeleteApplicationArea__Q2_2nn3nfpFv");

nn::Result
WriteApplicationArea(void const* data, uint32_t size, TagId const& id)
   asm("WriteApplicationArea__Q2_2nn3nfpFPCvUiRCQ3_2nn3nfp5TagId");

nn::Result
ReadApplicationArea(void* outData, uint32_t size)
   asm("ReadApplicationArea__Q2_2nn3nfpFPvUi");

nn::Result
InitializeRegisterInfoSet(RegisterInfoSet* infoSet)
   asm("InitializeRegisterInfoSet__Q2_2nn3nfpFPQ3_2nn3nfp15RegisterInfoSet");

nn::Result
SetNfpRegisterInfo(RegisterInfoSet const& info)
   asm("SetNfpRegisterInfo__Q2_2nn3nfpFRCQ3_2nn3nfp15RegisterInfoSet");

nn::Result
GetNfpRegisterInfo(RegisterInfo* outInfo)
   asm("GetNfpRegisterInfo__Q2_2nn3nfpFPQ3_2nn3nfp12RegisterInfo");

nn::Result
DeleteNfpRegisterInfo()
   asm("DeleteNfpRegisterInfo__Q2_2nn3nfpFv");

nn::Result
GetNfpCommonInfo(CommonInfo* outInfo)
   asm("GetNfpCommonInfo__Q2_2nn3nfpFPQ3_2nn3nfp10CommonInfo");

nn::Result
GetNfpReadOnlyInfo(ReadOnlyInfo* outInfo)
   asm("GetNfpReadOnlyInfo__Q2_2nn3nfpFPQ3_2nn3nfp12ReadOnlyInfo");

nn::Result
GetNfpRomInfo(RomInfo* outInfo)
   asm("GetNfpRomInfo__Q2_2nn3nfpFPQ3_2nn3nfp7RomInfo");

nn::Result
GetTagInfo(TagInfo* outInfo)
   asm("GetTagInfo__Q2_2nn3nfpFPQ3_2nn3nfp7TagInfo");

} //namespace nfp

} //namespace nn

#endif

/** @} */
