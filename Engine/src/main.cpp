#include "common/window.h"
#include "graphics/device.h"

int main(int argc, char const *argv[])
{
    octo::Scope<octo::Window> window = octo::Window::Create({"Title", 1280, 720});
    octo::Scope<octo::GraphicsDevice> device = octo::GraphicsDevice::Create(window->GetNativeHandle());

    while (!window->ShouldClose())
    {
        device->Clear(1.0f, 0.5f, 0.0f);

        window->Update();
        device->Present();
    }
    return 0;
}
