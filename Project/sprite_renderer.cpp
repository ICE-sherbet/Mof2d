#include "sprite_renderer.h"

sprite_renderer::sprite_renderer(const LPCMofChar path)
{
	texture_load(path);
}

sprite_renderer::sprite_renderer(LPTexture texture): lp_texture_(texture)
{
	set_image_rect(CRectangle(Vector2 (0,0), size()));
    grid_split(1,1);
}
sprite_renderer::sprite_renderer()
{

}
sprite_renderer& sprite_renderer::texture_load(const LPCMofChar path)
{
	if (lp_texture_ == nullptr)lp_texture_ = new CTexture;
	if(!lp_texture_->Load(path))
	{
		if(lp_texture_->GetTexture()==nullptr)
		{
			return *this;

		}
	}
	return *this;
}

CRectangle sprite_renderer::image_rect() const
{
	return image_rect_;
}

sprite_renderer& sprite_renderer::set_image_rect(const CRectangle& image_rect)
{
	image_rect_ = image_rect - size() * getPivot();
	return *this;
}

sprite_renderer& sprite_renderer::grid_split(int sx, int sy)
{
	rect_list_ = std::vector<CRectangle>(0);
	int width = lp_texture_->GetWidth() / sx;
	int height = lp_texture_->GetHeight() / sy;
	for (int y = 0; y < sy; y++) {
		for (int x = 0; x < sx; x++) {
			rect_list_.emplace_back(width * x, height * y, width * (x+1), height * (y + 1));
		}
	}

    set_size(Vector2(width,height));
    set_image_rect(CRectangle(Vector2 (0,0), size()));
	return *this;
}

void sprite_renderer::start()
{
	position_ = parent_->get_component<position>()->get_position_addres();
}

void sprite_renderer::render()
{
	if(rect_list_.size()<=index || index < 0 || !is_show_)return;
	lp_texture_->Render(image_rect() + *position_,rect_list_[index]);
}

Vector2 sprite_renderer::size() {
    return size_;
}

sprite_renderer& sprite_renderer::texture_load(LPTexture texture) {
    lp_texture_ = texture;
    grid_split(1,1);
	return *this;
}

const Vector2 &sprite_renderer::getPivot() const {
    return pivot_;
}

sprite_renderer& sprite_renderer::setPivot(const Vector2 &pivot) {
    pivot_ = pivot;
	return *this;
}

sprite_renderer::~sprite_renderer() {
    lp_texture_->Release();
}

sprite_renderer &sprite_renderer::set_size(Vector2 vec) {
    size_ = vec;
    return *this;
}

void sprite_renderer::next_sprite() {
    index++;
    index %= rect_list_.size();
    rect_list_[index];
}
