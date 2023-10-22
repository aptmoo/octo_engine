#include "common/window.h"

int main(int argc, char const *argv[])
{
    octo::Scope<octo::Window> window = octo::Window::Create({"Title", 1280, 720});

    while (!window->ShouldClose())
    {
        window->Update();
    }
    
    return 0;
}
