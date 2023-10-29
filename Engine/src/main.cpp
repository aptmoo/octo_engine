#include "common/window.h"
#include "graphics/device.h"
#include <iostream>

#include "sokol_gfx.h"

#include <memory>

int main(int argc, char const *argv[])
{
    octo::Scope<octo::Window> window = octo::Window::Create({"Title", 1280, 720});
    octo::Scope<octo::GraphicsDevice> device = octo::GraphicsDevice::Create(window->GetNativeHandle());
    
    while (!window->ShouldClose())
    {

        window->Update();
        device->Present();
    }
    return 0;
}
