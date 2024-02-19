#include "Renderer.h"

void Renderer::prepare(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,0,0,1);
}

void Renderer::render(TexturedModel texturedModel){
    RawModel model = texturedModel.get_model();
    glBindVertexArray(model.get_vaoID());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texturedModel.get_texture().get_texture_id());
    glDrawElements(GL_TRIANGLES, model.get_vertexCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}
