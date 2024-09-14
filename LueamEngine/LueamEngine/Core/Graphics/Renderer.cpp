#include "glad/glad.h"
#include "glfw/glfw3.h";
#include "Renderer.h"

Renderer::Renderer() {
	glfwInit();
}

Renderer::~Renderer() {
	glfwTerminate();
}

void Renderer::draw_line(Vector2 start, Vector2 end) {
    
}


void Renderer::draw_buffer(VertexBuffer& buffer)
{
    unsigned int vao = buffer.buffer;
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, buffer.vertex_count);
    glBindVertexArray(0);
}