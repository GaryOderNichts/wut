#include <avm/drc.h>
#include <coreinit/alarm.h>
#include <coreinit/atomic.h>
#include <coreinit/atomic64.h>
#include <coreinit/bsp.h>
#include <coreinit/cache.h>
#include <coreinit/codegen.h>
#include <coreinit/condition.h>
#include <coreinit/context.h>
#include <coreinit/core.h>
#include <coreinit/coroutine.h>
#include <coreinit/cosreport.h>
#include <coreinit/debug.h>
#include <coreinit/dynload.h>
#include <coreinit/energysaver.h>
#include <coreinit/event.h>
#include <coreinit/exception.h>
#include <coreinit/exit.h>
#include <coreinit/fastcondition.h>
#include <coreinit/fastmutex.h>
#include <coreinit/fiber.h>
#include <coreinit/filesystem.h>
#include <coreinit/foreground.h>
#include <coreinit/internal.h>
#include <coreinit/ios.h>
#include <coreinit/mcp.h>
#include <coreinit/memblockheap.h>
#include <coreinit/memdefaultheap.h>
#include <coreinit/memexpheap.h>
#include <coreinit/memfrmheap.h>
#include <coreinit/memheap.h>
#include <coreinit/memlist.h>
#include <coreinit/memory.h>
#include <coreinit/memorymap.h>
#include <coreinit/memunitheap.h>
#include <coreinit/messagequeue.h>
#include <coreinit/mutex.h>
#include <coreinit/rendezvous.h>
#include <coreinit/screen.h>
#include <coreinit/semaphore.h>
#include <coreinit/spinlock.h>
#include <coreinit/systeminfo.h>
#include <coreinit/taskqueue.h>
#include <coreinit/thread.h>
#include <coreinit/threadqueue.h>
#include <coreinit/time.h>
#include <coreinit/title.h>
#include <coreinit/userconfig.h>
#include <dmae/mem.h>
#include <dmae/sync.h>
#include <gx2/clear.h>
#include <gx2/context.h>
#include <gx2/debug.h>
#include <gx2/display.h>
#include <gx2/displaylist.h>
#include <gx2/draw.h>
#include <gx2/enum.h>
#include <gx2/event.h>
#include <gx2/mem.h>
#include <gx2/registers.h>
#include <gx2/sampler.h>
#include <gx2/shaders.h>
#include <gx2/state.h>
#include <gx2/surface.h>
#include <gx2/swap.h>
#include <gx2/temp.h>
#include <gx2/tessellation.h>
#include <gx2/texture.h>
#include <gx2/utils.h>
#include <gx2r/buffer.h>
#include <gx2r/displaylist.h>
#include <gx2r/draw.h>
#include <gx2r/mem.h>
#include <gx2r/resource.h>
#include <gx2r/surface.h>
#include <h264/stream.h>
#include <h264/decode.h>
#include <nn/ac/ac_c.h>
#include <nn/ac/ac_cpp.h>
#include <nn/acp/device.h>
#include <nn/acp/nn_acp_types.h>
#include <nn/acp/result.h>
#include <nn/acp/save.h>
#include <nn/acp/title.h>
#include <nn/act/client_cpp.h>
#include <nn/ffl/miidata.h>
#include <nn/pdm/pdm_c.h>
#include <nn/pdm/pdm_cpp.h>
#include <nn/swkbd/swkbd_cpp.h>
#include <nn/ac.h>
#include <nn/acp.h>
#include <nn/act.h>
#include <nn/result.h>
#include <nn/pdm.h>
#include <nn/swkbd.h>
#include <nsyshid/hid.h>
#include <nsysnet/_socket.h>
#include <nsysnet/nssl.h>
#include <nsysuhs/uhs.h>
#include <padscore/kpad.h>
#include <padscore/wpad.h>
#include <proc_ui/procui.h>
#include <sndcore2/core.h>
#include <sndcore2/device.h>
#include <sndcore2/drcvs.h>
#include <sndcore2/result.h>
#include <sndcore2/voice.h>
#include <swkbd/rpl_interface.h>
#include <sysapp/launch.h>
#include <sysapp/switch.h>
#include <sysapp/title.h>
#include <vpad/input.h>
#include <wut.h>
#include <wut_structsize.h>
#include <wut_types.h>
