// PROJECT REKON - plugin minimo de prueba.
// Estructura copiada de fliprate_remover (GoldHEN_Plugins_Repository).
// SIN VERIFICAR: no se ha compilado ni probado en consola.
// Solo escribe lineas en el log; no engancha nada ni toca el juego.

#include <Common.h>
#include "plugin_common.h"

attr_public const char *g_pluginName = "rekon";
attr_public const char *g_pluginDesc = "PROJECT REKON - plugin de prueba";
attr_public const char *g_pluginAuth = "PROJECT REKON";
attr_public u32 g_pluginVersion = 0x00000100; // 1.00

s32 attr_public plugin_load(s32 argc, const char* argv[]) {
    final_printf("[REKON] <%s\\Ver.0x%08x> %s\n", g_pluginName, g_pluginVersion, __func__);
    boot_ver();
    final_printf("[REKON] plugin cargado correctamente\n");
    return 0;
}

s32 attr_public plugin_unload(s32 argc, const char* argv[]) {
    final_printf("[REKON] <%s\\Ver.0x%08x> %s\n", g_pluginName, g_pluginVersion, __func__);
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
