#pragma once
#include <array>
#include "IGameObject.h"
#include <memory>

namespace RenderEngine
{
    class Sprite;
};

class Trees : public IGameObject
{
    public:
            enum class EBlockLocation
            {
                TopLeft,
                TopRight,
                BottomLeft,
                BottomRight
            };

            Trees(const glm::vec2& position, const glm::vec2& size, const float rotation);
            virtual void render()const override;

    private:
            void renderBlock(const EBlockLocation eBlockLocation)const;

            std::array<glm::vec2, 4> m_blockOffsets;
            std::shared_ptr<RenderEngine::Sprite> m_sprite;
};
