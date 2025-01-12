#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <raylib.h>

namespace dvt {

class texture
{
public:
    texture(const char* filename, int x, int y, Color color);
    void draw();
    void destroy();
    Texture2D id;
private:
    int x, y;
    Color color;
};

}

#endif // TEXTURE_HPP
