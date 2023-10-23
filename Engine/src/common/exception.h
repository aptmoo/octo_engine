/*
Shitty exceptions
TODO: Is this good at all?
*/
#ifndef COMMON_EXCEPTION_H
#define COMMON_EXCEPTION_H
#include <string>
#include <stdexcept>

namespace octo
{
    /**
     * @brief Macro to quickly define a exception.
     * Inherits std::runtime_exception.
     * 
     */
    #define DECLARE_EXCEPTION(TYPENAME) \
        struct TYPENAME : std::runtime_error \
        {   \
            TYPENAME(const std::string& message) : std::runtime_error{message} {}\
        }   \

    // Window and graphics exceptions
    DECLARE_EXCEPTION(APIInitException);
    DECLARE_EXCEPTION(WindowAPIInitException);
    DECLARE_EXCEPTION(GraphicsAPIInitException);

} // namespace octo


#endif