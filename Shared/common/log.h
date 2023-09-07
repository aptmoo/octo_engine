#ifndef LOGGER_H
#define LOGGER_H
#include "spdlog/spdlog.h"

#include "common/types.h"

namespace name
{
    class Logger
    {   

    private:
        Ref<spdlog::logger> s_EngineLogger;
    };
} // namespace name

#endif