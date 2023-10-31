#include "common/window.h"
#include "graphics/device.h"
#include <iostream>

#include "sokol_gfx.h"

#include <memory>

int main(int argc, char const *argv[])
{
    octo::Scope<octo::Window> window = octo::Window::Create({"Title", 1280, 720});
    octo::Scope<octo::GraphicsDevice> device = octo::GraphicsDevice::Create(window->GetNativeHandle());

    sg_pass_action passAction = {};
    passAction.colors[0].clear_value = (sg_color){0.2f, 0.2f, 0.3f, 1.0f};
    passAction.colors[0].load_action = SG_LOADACTION_CLEAR;

    sg_pass_desc;
    
    while (!window->ShouldClose())
    {
        sg_begin_default_pass(passAction, 1280, 720);
        sg_end_pass();

        device->Flush();

        window->Update();
        device->Present();
    }
    return 0;
}
