#include "TexturedModel.h"

TexturedModel::TexturedModel(){
    Loader loader;
    RawModel model = OBJParser::load_obj_model("place_holder/cube.obj", loader);
	ModelTexture texture(loader.load_texture("Solid_white.png"));
    this->rawModel = model;
    this->texture = texture;
}

TexturedModel::TexturedModel(RawModel model, ModelTexture texture) :
    rawModel(model), texture(texture) {}

RawModel TexturedModel::get_model() const{
    return this->rawModel;
}

ModelTexture TexturedModel::get_texture() const{
    return this->texture;
}
/*
template<>
struct std::hash<TexturedModel>{
    std::size_t operator()(const TexturedModel& obj) const{
        std::size_t h1 = std::hash<unsigned int>()(obj.get_model().get_vaoID());
        std::size_t h2 = std::hash<unsigned int>()(obj.get_texture().get_texture_id());
        return h1 ^ (h2 << 1);
    }
};*/


bool TexturedModel::operator==(const TexturedModel& other) const{
    return (this->get_model().get_vaoID() == other.get_model().get_vaoID()) &&
            (this->get_texture().get_texture_id() == other.get_texture().get_texture_id());
}

size_t TexturedModelHash::operator()(const TexturedModel& model) const{
    size_t h1 = std::hash<int>()(model.get_model().get_vaoID());
    size_t h2 = std::hash<int>()(model.get_texture().get_texture_id());
    return h1 ^ (h2 << 1);
}