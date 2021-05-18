#pragma once

#include <builder/load/scene/scene_builder.h>
#include <loader/base_loader.h>

namespace Load {
    class BaseSceneLoader : public BaseLoader {
    public:
        virtual std::shared_ptr<Object> load(const std::shared_ptr<SceneBuilder> &builder) = 0;

    protected:
        virtual void load_models(std::shared_ptr<SceneBuilder> builder) = 0;
        virtual void load_cameras(std::shared_ptr<SceneBuilder> builder) = 0;
    };
}// namespace Load