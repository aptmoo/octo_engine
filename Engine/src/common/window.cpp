#include "window.h"
#include "linux/linuxwindow.h"

namespace octo
{
    Scope<Window> Window::Create(const WindowDesc& desc)
    {
        return MakeScope<LinuxWindow>(desc);
    }
} // namespace octo
