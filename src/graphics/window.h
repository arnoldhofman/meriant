#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace meriant { namespace graphics {
    
#define MAX_KEYS    1024
#define MAX_BUTTONS 32

    class Window {
    private:
        friend struct GLFWwindow;
        
        const char *m_Title;
        int m_Width, m_Height;
        GLFWwindow *m_Window;
        bool m_Closed;
        
        static bool m_Keys[MAX_KEYS];
        static bool m_MouseButtons[MAX_BUTTONS];
        static double mx, my;
    public:
        Window(const char *name, int width, int height);
        ~Window();
        bool closed() const;
        void clear() const;
        void update();
    
        inline int getWidth() const { return m_Width; }
        inline int getHeight() const { return m_Height; }
        
        static bool isKeyPressed(unsigned int keycode);
        static bool isMouseButtonPressen(unsigned int keycode);
    private:
        bool init();
        friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);    
    };
} }