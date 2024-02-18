#include "Renderer.h"

void Renderer::prepare(){
    glClear(GL_COLOR_BUFFER_BIT);
    //glClearColor(1,0,0,1);
}

void Renderer::render(RawModel model){
    glBindVertexArray(model.get_vaoID());
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, model.get_vertexCount());
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}
