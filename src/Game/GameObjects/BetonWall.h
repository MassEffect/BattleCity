#pragma once
#include <array>
#include "IGameObject.h"
#include <memory>

namespace RenderEngine
{
    class Sprite;
};

class BetonWall : public IGameObject
{
    public:
            enum class EBetonWallType : uint8_t
            {
                All,
                Top,
                Bottom,
                Left,
                Right,
                TopLeft,
                TopRight,
                BottomLeft,
                BottomRight
            };

            enum class EBlockState : uint8_t
            {
                Enable = 0,
				Destroyed
            };

            enum class EBlockLocation : uint8_t
            {
                TopLeft,
                TopRight,
                BottomLeft,
                BottomRight
            };

            BetonWall(const EBetonWallType eBetonWallType, const glm::vec2& position, const glm::vec2& size, const float rotation, const float layer);
            virtual void render()const override;
            virtual void update(const double delta) override;

    private:
            void renderBlock(const EBlockLocation eBlockLocation)const;

            std::array<glm::vec2, 4> m_blockOffsets;
            std::array<EBlockState, 4> m_eCurrentBlockState;
            std::shared_ptr<RenderEngine::Sprite> m_sprite;
};
