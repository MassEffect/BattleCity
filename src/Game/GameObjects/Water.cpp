#include "Water.h"
#include "../../Renderer/Sprite.h"
#include "../../Resources/ResourceManager.h"

Water::Water(const glm::vec2& position, const glm::vec2& size, const float rotation)
                    : IGameObject(position, size, rotation)
                    , m_sprite(ResourceManager::getSprite("water"))
                    , m_spriteAnimator(m_sprite)
                    , m_blockOffsets       {
                                                glm::vec2(0, m_size.y / 2),
                                                glm::vec2(m_size.x / 2, m_size.y / 2),
                                                glm::vec2(0, 0),
                                                glm::vec2(m_size.x / 2, 0)
                                          }
{

};

void Water::renderBlock(const EBlockLocation eBlockLocation)const
{
    m_sprite -> render(m_position + m_blockOffsets[static_cast<size_t>(eBlockLocation)], m_size / 2.0f, m_rotation, m_spriteAnimator.getCurrentFrame());
};

void Water::render()const
{
    renderBlock(EBlockLocation::TopLeft);
    renderBlock(EBlockLocation::TopRight);
    renderBlock(EBlockLocation::BottomLeft);
    renderBlock(EBlockLocation::BottomRight);
};

void Water::update(const uint64_t delta)
{
    m_spriteAnimator.update(delta);
};
