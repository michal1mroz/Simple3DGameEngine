#include "Renderer.h"

void Renderer::prepare(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,0,0,1);
}

void Renderer::render(RawModel model){
    glBindVertexArray(model.get_vaoID());
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, model.get_vertexCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}
