// PROJECT REKON - prueba de enganche a sceVideoOutSubmitFlip.
// Estructura copiada de fliprate_remover y force_30_fps (GoldHEN_Plugins).
// SIN VERIFICAR en consola. Cuenta fotogramas y avisa una sola vez.

#include <Common.h>
#include <orbis/VideoOut.h>
#include "plugin_common.h"

attr_public const char *g_pluginName = "rekon";
attr_public const char *g_pluginDesc = "PROJECT REKON - prueba de hook de video";
attr_public const char *g_pluginAuth = "PROJECT REKON";
attr_public u32 g_pluginVersion = 0x00000200; // 2.00

HOOK_INIT(sceVideoOutSubmitFlip);

static u32 g_frames = 0;
static u32 g_notified = 0;

s32 sceVideoOutSubmitFlip_hook(s32 handle, s32 bufferIndex, u32 flipMode, s64 flipArg)
{
    // Primero se llama a la funcion original, para que el juego siga mostrando imagen.
    s32 ret = HOOK_CONTINUE(sceVideoOutSubmitFlip,
                            s32 (*)(s32, s32, u32, s64),
                            handle, bufferIndex, flipMode, flipArg);
    g_frames++;
    if (!g_notified && g_frames >= 600) {
        g_notified = 1;
        Notify(TEX_ICON_SYSTEM, "REKON: enganche OK (%u fotogramas)", g_frames);
    }
    return ret;
}

s32 attr_public plugin_load(s32 argc, const char* argv[]) {
    final_printf("[REKON] <%s\\Ver.0x%08x> %s\n", g_pluginName, g_pluginVersion, __func__);
    boot_ver();
    HOOK32(sceVideoOutSubmitFlip);
    return 0;
}

s32 attr_public plugin_unload(s32 argc, const char* argv[]) {
    final_printf("[REKON] <%s\\Ver.0x%08x> %s\n", g_pluginName, g_pluginVersion, __func__);
    UNHOOK(sceVideoOutSubmitFlip);
    return 0;
}

s32 attr_module_hidden module_start(s64 argc, const void *args)
{
    return 0;
}

s32 attr_module_hidden module_stop(s64 argc, const void *args)
{
    return 0;
}
