#include "window.h"

namespace meriant { namespace graphics {
    
    bool Window::m_Keys[MAX_KEYS];
    bool Window::m_MouseButtons[MAX_BUTTONS];
    double Window::mx;
    double Window:: my;
    
    
    void window_resize(GLFWwindow *window, int width, int height);
    //void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    
   Window::Window(const char *title, int width, int height) {
       m_Title = title;
       m_Width = width;
       m_Height = height;
       if (!init()) {
           glfwTerminate();
       }
       
       for (int i = 0; i < MAX_KEYS; i++) {
           m_Keys[i] = false;
       }
       
       for (int i = 0; i < MAX_BUTTONS; i++) {
           m_MouseButtons[i] = false;
       }
       
   } 
   
   Window::~Window() {
       glfwTerminate();
   }
   
   bool Window::init() {

       
       m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
       if (!m_Window) {
           std::cout << "Failed to create GLFW window!" << std::endl;
           return false;
       }
       glfwMakeContextCurrent(m_Window);
       glfwSetWindowUserPointer(m_Window, this);
       glfwSetWindowSizeCallback(m_Window, window_resize);
       glfwSetKeyCallback(m_Window, key_callback);
       
        if(!glfwInit()) {
            std::cout << "Failed to initialize GLFW!" << std::endl;
            return false;
        }
       
       return true;
   }
   
   bool Window::isKeyPressed(unsigned int keycode) {
       //TODO: Log this!
       if(keycode >= MAX_KEYS)
           return false;
       
       return m_Keys[keycode];
   }
   
   void Window::clear() const {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   }
   
   void Window::update() {
       glfwPollEvents();
       //glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
       glfwSwapBuffers(m_Window);
   }
   
   bool Window::closed() const {
       return glfwWindowShouldClose(m_Window);
   }
   
   void window_resize(GLFWwindow *window, int width, int height) {
       glViewport(0,0, width, height);
   }
   
   void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
       Window* win = (Window*)glfwGetWindowUserPointer(window);
       win->m_Keys[key] = action != GLFW_RELEASE;
   }

} }