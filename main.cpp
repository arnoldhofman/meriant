#include "src/graphics/window.h"


int main() {
    using namespace meriant;
    using namespace graphics;
    
    Window window("meriant", 800, 600);
    glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
    
    std::cout << glGetString(GL_VERSION) << std::endl;
    
    while (!window.closed()) {  
        window.clear();
        std::cout << window.isKeyPressed(GLFW_KEY_A) << std::endl;
#if 1
        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
#endif
        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
        window.update();
    }
    
    //std::cin.get();
    return 0;
}