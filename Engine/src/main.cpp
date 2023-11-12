#include "common/window.h"
#include "graphics/device.h"
#include <iostream>

#include "sokol_gfx.h"

#include <memory>

int main(int argc, char const *argv[])
{
    octo::Scope<octo::Window> window = octo::Window::Create({"Title", 1280, 720});
    octo::Scope<octo::GraphicsDevice> device = octo::GraphicsDevice::Create(window->GetNativeHandle());

    const float vertices[] = {
        // positions            // colors
        0.0f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f};

    sg_buffer_desc vbufDesc = {};
    vbufDesc.data = SG_RANGE_REF(vertices);
    sg_buffer vbuf = sg_make_buffer(vbufDesc);

    /* a shader */

    sg_shader_desc shdDesc = {};
    shdDesc.vs.source =
        "#version 330\n"
        "layout(location=0) in vec4 position;\n"
        "layout(location=1) in vec4 color0;\n"
        "out vec4 color;\n"
        "void main() {\n"
        "  gl_Position = position;\n"
        "  color = color0;\n"
        "}\n";

    shdDesc.fs.source =
        "#version 330\n"
        "in vec4 color;\n"
        "out vec4 frag_color;\n"
        "void main() {\n"
        "  frag_color = color;\n"
        "}\n";

    sg_shader shd = sg_make_shader(shdDesc);

    sg_pipeline_desc pipDesc = {};
    pipDesc.shader = shd;
    pipDesc.layout.attrs[0].format = SG_VERTEXFORMAT_FLOAT3;
    pipDesc.layout.attrs[1].format = SG_VERTEXFORMAT_FLOAT4;

    /* a pipeline state object (default render states are fine for triangle) */
    sg_pipeline pip = sg_make_pipeline(pipDesc);

    /* resource bindings */
    sg_bindings bind = {};
    bind.vertex_buffers[0] = vbuf;

    /* default pass action (clear to grey) */
    sg_pass_action passAction = {0};

    while (!window->ShouldClose())
    {
        sg_begin_default_pass(passAction, 1280, 720);
        sg_apply_pipeline(pip);
        sg_apply_bindings(&bind);
        sg_draw(0, 3, 1);
        sg_end_pass();

        device->Flush();

        window->Update();
        device->Present();
    }
    return 0;
}
